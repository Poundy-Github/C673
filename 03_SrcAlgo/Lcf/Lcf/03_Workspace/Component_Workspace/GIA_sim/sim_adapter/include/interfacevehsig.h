/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_vdy

  MODULNAME:            interfacevehsig

  DESCRIPTION:          veh sig input types

  AUTHOR:               -

  CREATION DATE:        15.13.2012

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: interfacevehsig.h  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:27CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/include/project.pj
  CHANGES:              Revision 1.10.1.1 2016/02/04 10:01:10CET Mani, Yugesh (uidj6870) 
  CHANGES:              New Velocity monitoring based on new minimum and maximum velocity signals
  CHANGES:              for ARS4D1 and ARS4D2
  CHANGES:              Revision 1.10 2014/12/12 11:28:02CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              - for ARS: const SpeedUnit_t SR_RTE_OUTPUT_COUNTRY_SPEED_LIMIT_UNIT_RECOG_INT_MAX = (2147483647)
  CHANGES:              - Added comments -  berndtt1 [Dec 12, 2014 11:33:32 AM CET]
  CHANGES:              Change Package : 221167:44 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.9 2014/09/29 14:28:08CEST Sorge-EXT, Sven (uidg3181) 
  CHANGES:              Added VehSigV10 and merged VehSigV9 from Branch
  CHANGES:              --- Added comments ---  uidg3181 [Sep 29, 2014 2:28:09 PM CEST]
  CHANGES:              Change Package : 241126:2 http://mks-psad:7002/im/viewissue?selection=241126
  CHANGES:              Revision 1.8.1.1 2014/06/27 10:13:52CEST Manea, Gabriela (ManeaG) 
  CHANGES:              Updated win new VehSig  structure version for SRR300
  CHANGES:              --- Added comments ---  ManeaG [Jun 27, 2014 10:13:52 AM CEST]
  CHANGES:              Change Package : 212023:2 http://mks-psad:7002/im/viewissue?selection=212023
  CHANGES:              Revision 1.8 2014/01/28 15:38:55CET Wolter, Frank (wolterf) 
  CHANGES:              Added VehSig V8
  CHANGES:              --- Added comments ---  wolterf [Jan 28, 2014 3:38:55 PM CET]
  CHANGES:              Change Package : 208447:1 http://mks-psad:7002/im/viewissue?selection=208447
  CHANGES:              Revision 1.7 2013/07/24 13:25:14CEST Mueller, Reik (muellerr5) 
  CHANGES:              - added VehSigV7 according to RTE update (SW_COMMON_03.04.00_INT-14)
  CHANGES:              --- Added comments ---  muellerr5 [Jul 24, 2013 1:25:14 PM CEST]
  CHANGES:              Change Package : 184575:2 http://mks-psad:7002/im/viewissue?selection=184575
  CHANGES:              Revision 1.6 2013/03/08 11:02:02CET Spruck, Jochen (spruckj) 
  CHANGES:              Update veh par and veh sig adapter, add trail signal, ignition switch, wheel width and front axle to road data
  CHANGES:              --- Added comments ---  spruckj [Mar 8, 2013 11:02:03 AM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.5 2013/02/06 12:59:36CET Spruck, Jochen (spruckj) 
  CHANGES:              Add vdy offsets adapter to semo adapter, and use const vars instead of defines in interface namespaces
  CHANGES:              --- Added comments ---  spruckj [Feb 6, 2013 12:59:37 PM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.4 2013/01/18 09:02:40CET Spruck, Jochen (spruckj) 
  CHANGES:              move typedefs inside namespace
  CHANGES:              --- Added comments ---  spruckj [Jan 18, 2013 9:02:40 AM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.3 2013/01/18 08:29:46CET Spruck, Jochen (spruckj) 
  CHANGES:              move typedefs inside namespaces
  CHANGES:              --- Added comments ---  spruckj [Jan 18, 2013 8:29:46 AM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.2 2013/01/16 13:06:09CET Spruck, Jochen (spruckj) 
  CHANGES:              Rename namespaces, because of conflicts
  CHANGES:              --- Added comments ---  spruckj [Jan 16, 2013 1:06:09 PM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.1 2013/01/16 11:34:47CET Spruck, Jochen (spruckj) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/MFC400/06_Algorithm/04_Engineering/03_Workspace/algo/vdy_sim/vdy_adapter/include/project.pj
  **************************************************************************** */
#ifndef interfacevehsig_h__
#define interfacevehsig_h__

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

namespace VDY_SIG_300 {
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


/* ---------------- veh sig V1 interfaces ------------- */
// VehSig V1
namespace VehSigV1 {
  /* ----------------------- VehSig data types -------------------------*/

  typedef uint8 LongDirState_t             /* @min: 0 @max:2 @values: enum { VDY_LONG_DIR_RWD=2,VDY_LONG_DIR_VOID=0,VDY_LONG_DIR_FWD=1,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 ActGearPos_t               /* VDY_SIN_POS_GEAR @min: 0 @max:3 @values: enum { ACT_GEAR_POS_NEUTRAL=0,ACT_GEAR_POS_FORWARD=2,ACT_GEAR_POS_PARKING=1,ACT_GEAR_POS_REVERSE=3,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 ParkBrakeState_t           /* VDY_SIN_POS_PBRK @min: 0 @max:1 @values: enum { STAT_ACTIVE=1,STAT_INACTIVE=0,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 VehLongMotStateExt_t       /* VDY_SIN_POS_VMOT @min: 0 @max:2 @values: enum { VDY_VEH_MOT_STATE_ROLLING=0,VDY_VEH_MOT_STATE_SECURE_STST=2,VDY_VEH_MOT_STATE_FAST_STST=1,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 WiperState_t               /* Wiper blades activity @min: 0 @max:1 @values: enum { WIPER_STATE_INACTIVE=1,WIPER_STATE_ACTIVE=0,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 TurnSignal_t               /* Turn signal switch state @min: 0 @max:3 @values: enum { TURN_SIG_UNKNOWN=3,TURN_SIG_RIGHT=1,TURN_SIG_NEUTRAL=2,TURN_SIG_LEFT=0,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 TransmissionGear_t         /* Indicates current used gear position @min: 0 @max:10 @values: enum { DYN_GEAR_PARK_GEAR=10,DYN_GEAR_SIXTH_GEAR=6,DYN_GEAR_FIRST_GEAR=1,DYN_GEAR_FIFTH_GEAR=5,DYN_GEAR_SECOND_GEAR=2,DYN_GEAR_EIGHTH_GEAR=8,DYN_GEAR_NEUTRAL_GEAR=0,DYN_GEAR_THIRD_GEAR=3,DYN_GEAR_REVERSE_GEAR=9,DYN_GEAR_SEVENTH_GEAR=7,DYN_GEAR_FOURTH_GEAR=4,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;

  typedef uint32                    	State_array_t_0[2];          /* State of the vehicle input signals @name: Status @values: struct VDYInSignalState @min:-2.86 @max:2.86 */	/* [Satisfies_rte sws 1189] */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 YawRate;                             /* Yaw rate signal */
    float32 LatAccel;                            /* Lateral acceleration sensor signal */
    float32 LongAccel;                           /* Longitudinal acceleration sensor signal */
    float32 StWheelAngle;                        /* Steering wheel angle signal */
    float32 VehVelocityExt;                      /* External provided longitudinal velocity */
    float32 VehLongAccelExt;                     /* External longitudinal vehicle acceleration */
    float32 CurveC0Ext;                          /* External provided curvature 1/R */
    float32 CurveC1Ext;                          /* External provided curvature change d/ds 1/R */
    float32 SideSlipAngle;                       /* External proveded side slip angle */
    float32 WhlVelFrLeft;                        /* Wheel circumferential velocity front left */
    float32 WhlVelFrRight;                       /* Wheel circumferential velocity front right */
    float32 WhlVelReLeft;                        /* Wheel circumferential velocity rear left */
    float32 WhlVelReRight;                       /* Wheel circumferential velocity rear right */
    float32 RearStAngle;                         /* Rear axle steering wheel angle */
  } UncSignals_t;			/* Uncertainty of external signals */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t_0 State;                               /* State of the vehicle input signals @name: Status @values: struct VDYInSignalState @min:-2.86 @max:2.86 */
    float32 YawRate;                             /* VDY_SIN_POS_YWR @min:-2.86 @max:2.86 */
    float32 YawRateTemp;                         /* VDY_SIN_POS_YWR_TEMP @min:-2.86 @max:2.86 */
    float32 StWheelAngle;                        /* VDY_SIN_POS_SWA */
    float32 LatAccel;                            /* VDY_SIN_POS_LATA */
    float32 WhlVelFrLeft;                        /* VDY_SIN_POS_WVEL_FL */
    float32 WhlVelFrRight;                       /* VDY_SIN_POS_WVEL_FR */
    float32 WhlVelReLeft;                        /* VDY_SIN_POS_WVEL_RL */
    float32 WhlVelReRight;                       /* VDY_SIN_POS_WVEL_RR */
    float32 YawRateInt;                          /* VDY_SIN_POS_YWRINT @min:-2.86 @max:2.86 */
    float32 YawRateIntTemp;                      /* VDY_SIN_POS_YWRINT_TEMP @min:-2.86 @max:2.86 */
    float32 LongAccel;                           /* VDY_SIN_POS_LONGA */
    float32 RearWhlAngle;                        /* VDY_SIN_POS_RSTA */
    float32 VehVelocityExt;                      /* VDY_SIN_POS_VEHVEL_EXT */
    float32 VehLongAccelExt;                     /* VDY_SIN_POS_VEHACL_EXT */
    LongDirState_t WhlDirFrLeft;                        /* VDY_SIN_POS_WDIR_FL */
    LongDirState_t WhlDirFrRight;                       /* VDY_SIN_POS_WDIR_FR */
    LongDirState_t WhlDirReLeft;                        /* VDY_SIN_POS_WDIR_RL */
    LongDirState_t WhlDirReRight;                       /* VDY_SIN_POS_WDIR_RR */
    uint8 WhlTicksDevFrLeft;                   /* VDY_SIN_POS_WTCKS_FL */
    uint8 WhlTicksDevFrRight;                  /* VDY_SIN_POS_WTCKS_FR */
    uint8 WhlTicksDevReLeft;                   /* VDY_SIN_POS_WTCKS_RL */
    uint8 WhlTicksDevReRight;                  /* VDY_SIN_POS_WTCKS_RR */
    ActGearPos_t ActGearPos;                          /* VDY_SIN_POS_GEAR */
    uint16 BrakeActLevel;                       /* VDY_SIN_POS_BRAKE */
    ParkBrakeState_t ParkBrakeState;                      /* VDY_SIN_POS_PBRK */
    LongDirState_t VehLongDirExt;                       /* VDY_SIN_POS_VDIR */
    VehLongMotStateExt_t VehLongMotStateExt;                  /* VDY_SIN_POS_VMOT */
    float32 CurveC0Ext;                          /* VDY_SIN_POS_CRV */
    float32 CurveC1Ext;                          /* VDY_SIN_POS_SSA */
    float32 SideSlipAngleExt;                    /* VDY_SIN_SIZE_DW */
    UncSignals_t Unc;                                 /* Uncertainty of external signals */
  } VehSigMain_t;			/* Main Vehicle dynacmis sensor signals */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 EnvTemp;                             /* Ambient environmental temperature */
    WiperState_t WiperState;                          /* Wiper blades activity */
    TurnSignal_t TurnSignal;                          /* Turn signal switch state */
    float32 RoadWhlAngFr;                        /* Steering angle (road wheel) at front axle @min:-25.0 @max:25.0 */
    float32 RoadWhlAngRe;                        /* Steering angle (road wheel) at rear axle @min:-25.0 @max:25.0 */
    float32 Odometer;                            /* Total driven distance @min:-25.0 @max:25.0 */
  } VehSigAdd_t;			/* Additional Vehicle dynacmis sensor signals */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    TransmissionGear_t ActualGear;                          /* Indicates current used gear position */
    TransmissionGear_t TargetGear;                          /* When a gear shift is in progress, this shows the targeted gear, otherwise it is equal to the Actual Gear */
  } PowerTrain_t;			

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    boolean ABSCtrl;                             /* Attenuation of secondary surface (two-way) @min:0.0 @max:1.0 */
    boolean TCSCtrl;                             /* Test @min:0.0 @max:1.0 */
  } Brake_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;                     /* Number of used Version @min:0.0 @max:16277215.0 */
    VehSigMain_t VehSigMain;                          /* Main Vehicle dynacmis sensor signals */
    VehSigAdd_t VehSigAdd;                           /* Additional Vehicle dynacmis sensor signals */
    PowerTrain_t PowerTrain;                          
    Brake_t Brake;                               /* Sensor specific parameters */
  } VehSig_t;			/* Main Vehicle dynacmis sensor signals @vaddr:VDY_MEAS_ID_VEH_SIG @cycleid:vdy_cycle_id @vname:VehSig */
}

/* ---------------- veh sig V2 interfaces ------------- */
// VehSig V2
namespace VehSigV2 {

  /* ----------------------- VehSig data types -------------------------*/

  typedef uint8 LongDirState_t             /* @min: 0 @max:2 @values: enum { VDY_LONG_DIR_RWD=2,VDY_LONG_DIR_VOID=0,VDY_LONG_DIR_FWD=1,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 ActGearPos_t               /* VDY_SIN_POS_GEAR @min: 0 @max:3 @values: enum { ACT_GEAR_POS_NEUTRAL=0,ACT_GEAR_POS_FORWARD=2,ACT_GEAR_POS_PARKING=1,ACT_GEAR_POS_REVERSE=3,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 ParkBrakeState_t           /* VDY_SIN_POS_PBRK @min: 0 @max:1 @values: enum { STAT_ACTIVE=1,STAT_INACTIVE=0,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 VehLongMotStateExt_t       /* VDY_SIN_POS_VMOT @min: 0 @max:2 @values: enum { VDY_VEH_MOT_STATE_ROLLING=0,VDY_VEH_MOT_STATE_SECURE_STST=2,VDY_VEH_MOT_STATE_FAST_STST=1,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 WiperState_t               /* Wiper blades activity @min: 0 @max:1 @values: enum { WIPER_STATE_INACTIVE=1,WIPER_STATE_ACTIVE=0,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 TurnSignal_t               /* Turn signal switch state @min: 0 @max:3 @values: enum { TURN_SIG_UNKNOWN=3,TURN_SIG_RIGHT=1,TURN_SIG_NEUTRAL=2,TURN_SIG_LEFT=0,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 TransmissionGear_t         /* Indicates current used gear position @min: 0 @max:10 @values: enum { DYN_GEAR_PARK_GEAR=10,DYN_GEAR_SIXTH_GEAR=6,DYN_GEAR_FIRST_GEAR=1,DYN_GEAR_FIFTH_GEAR=5,DYN_GEAR_SECOND_GEAR=2,DYN_GEAR_EIGHTH_GEAR=8,DYN_GEAR_NEUTRAL_GEAR=0,DYN_GEAR_THIRD_GEAR=3,DYN_GEAR_REVERSE_GEAR=9,DYN_GEAR_SEVENTH_GEAR=7,DYN_GEAR_FOURTH_GEAR=4,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;

  typedef uint32                    	State_array_t_0[2];          /* State of the vehicle input signals @name: Status @values: struct VDYInSignalState @min:-2.86 @max:2.86 */	/* [Satisfies_rte sws 1189] */


  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t_0 State;                               /* State of the vehicle input signals @name: Status @values: struct VDYInSignalState @min:-2.86 @max:2.86 */
    float32 YawRate;                             /* VDY_SIN_POS_YWR @min:-2.86 @max:2.86 */
    float32 YawRateTemp;                         /* VDY_SIN_POS_YWR_TEMP @min:-2.86 @max:2.86 */
    float32 StWheelAngle;                        /* VDY_SIN_POS_SWA */
    float32 LatAccel;                            /* VDY_SIN_POS_LATA */
    float32 WhlVelFrLeft;                        /* VDY_SIN_POS_WVEL_FL */
    float32 WhlVelFrRight;                       /* VDY_SIN_POS_WVEL_FR */
    float32 WhlVelReLeft;                        /* VDY_SIN_POS_WVEL_RL */
    float32 WhlVelReRight;                       /* VDY_SIN_POS_WVEL_RR */
    float32 YawRateInt;                          /* VDY_SIN_POS_YWRINT @min:-2.86 @max:2.86 */
    float32 YawRateIntTemp;                      /* VDY_SIN_POS_YWRINT_TEMP @min:-2.86 @max:2.86 */
    float32 LongAccel;                           /* VDY_SIN_POS_LONGA */
    float32 RearWhlAngle;                        /* VDY_SIN_POS_RSTA */
    float32 VehVelocityExt;                      /* VDY_SIN_POS_VEHVEL_EXT */
    float32 VehLongAccelExt;                     /* VDY_SIN_POS_VEHACL_EXT */
    LongDirState_t WhlDirFrLeft;                        /* VDY_SIN_POS_WDIR_FL */
    LongDirState_t WhlDirFrRight;                       /* VDY_SIN_POS_WDIR_FR */
    LongDirState_t WhlDirReLeft;                        /* VDY_SIN_POS_WDIR_RL */
    LongDirState_t WhlDirReRight;                       /* VDY_SIN_POS_WDIR_RR */
    uint8 WhlTicksDevFrLeft;                   /* VDY_SIN_POS_WTCKS_FL */
    uint8 WhlTicksDevFrRight;                  /* VDY_SIN_POS_WTCKS_FR */
    uint8 WhlTicksDevReLeft;                   /* VDY_SIN_POS_WTCKS_RL */
    uint8 WhlTicksDevReRight;                  /* VDY_SIN_POS_WTCKS_RR */
    ActGearPos_t ActGearPos;                          /* VDY_SIN_POS_GEAR */
    uint16 BrakeActLevel;                       /* VDY_SIN_POS_BRAKE */
    ParkBrakeState_t ParkBrakeState;                      /* VDY_SIN_POS_PBRK */
    LongDirState_t VehLongDirExt;                       /* VDY_SIN_POS_VDIR */
    VehLongMotStateExt_t VehLongMotStateExt;                  /* VDY_SIN_POS_VMOT */
    float32 CurveC0Ext;                          /* VDY_SIN_POS_CRV */
    float32 CurveC1Ext;                          /* VDY_SIN_POS_SSA */
    float32 SideSlipAngleExt;                    /* VDY_SIN_SIZE_DW */
  } VehSigMain_t;			/* Main Vehicle dynacmis sensor signals */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 EnvTemp;                             /* Ambient environmental temperature */
    WiperState_t WiperState;                          /* Wiper blades activity */
    TurnSignal_t TurnSignal;                          /* Turn signal switch state */
    float32 RoadWhlAngFr;                        /* Steering angle (road wheel) at front axle @min:-25.0 @max:25.0 */
    float32 RoadWhlAngRe;                        /* Steering angle (road wheel) at rear axle @min:-25.0 @max:25.0 */
    float32 Odometer;                            /* Total driven distance @min:-25.0 @max:25.0 */
  } VehSigAdd_t;			/* Additional Vehicle dynacmis sensor signals */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    TransmissionGear_t ActualGear;                          /* Indicates current used gear position */
    TransmissionGear_t TargetGear;                          /* When a gear shift is in progress, this shows the targeted gear, otherwise it is equal to the Actual Gear */
  } PowerTrain_t;			

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    boolean ABSCtrl;                             /* Attenuation of secondary surface (two-way) @min:0.0 @max:1.0 */
    boolean TCSCtrl;                             /* Test @min:0.0 @max:1.0 */
  } Brake_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;                     /* Number of used Version @min:0.0 @max:16277215.0 */
    VehSigMain_t VehSigMain;                          /* Main Vehicle dynacmis sensor signals */
    VehSigAdd_t VehSigAdd;                           /* Additional Vehicle dynacmis sensor signals */
    PowerTrain_t PowerTrain;                          
    Brake_t Brake;                               /* Sensor specific parameters */
  } VehSig_t;			/* Main Vehicle dynacmis sensor signals @vaddr:VDY_MEAS_ID_VEH_SIG @cycleid:vdy_cycle_id @vname:VehSig */
}

namespace VehSigV4 
{
  /* ----------------------- VehSig data types -------------------------*/

  typedef uint8 LongDirState_t             /* @min: 0 @max:2 @values: enum { VDY_LONG_DIR_RWD=2,VDY_LONG_DIR_VOID=0,VDY_LONG_DIR_FWD=1,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 ActGearPos_t               /* VDY_SIN_POS_GEAR @min: 0 @max:3 @values: enum { ACT_GEAR_POS_NEUTRAL=0,ACT_GEAR_POS_FORWARD=2,ACT_GEAR_POS_PARKING=1,ACT_GEAR_POS_REVERSE=3,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 ParkBrakeState_t           /* VDY_SIN_POS_PBRK @min: 0 @max:1 @values: enum { STAT_ACTIVE=1,STAT_INACTIVE=0,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 VehLongMotStateExt_t       /* VDY_SIN_POS_VMOT @min: 0 @max:2 @values: enum { VDY_VEH_MOT_STATE_ROLLING=0,VDY_VEH_MOT_STATE_SECURE_STST=2,VDY_VEH_MOT_STATE_FAST_STST=1,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 WiperState_t               /* Wiper blades activity @min: 0 @max:1 @values: enum { WIPER_STATE_INACTIVE=1,WIPER_STATE_ACTIVE=0,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 TurnSignal_t               /* Turn signal switch state @min: 0 @max:3 @values: enum { TURN_SIG_UNKNOWN=3,TURN_SIG_RIGHT=1,TURN_SIG_NEUTRAL=2,TURN_SIG_LEFT=0,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;
  typedef uint8 TransmissionGear_t         /* Indicates current used gear position @min: 0 @max:10 @values: enum { DYN_GEAR_PARK_GEAR=10,DYN_GEAR_SIXTH_GEAR=6,DYN_GEAR_FIRST_GEAR=1,DYN_GEAR_FIFTH_GEAR=5,DYN_GEAR_SECOND_GEAR=2,DYN_GEAR_EIGHTH_GEAR=8,DYN_GEAR_NEUTRAL_GEAR=0,DYN_GEAR_THIRD_GEAR=3,DYN_GEAR_REVERSE_GEAR=9,DYN_GEAR_SEVENTH_GEAR=7,DYN_GEAR_FOURTH_GEAR=4,} */			/* [Satisfies_rte sws 1180], [Satisfies_rte sws 1265] */;

  typedef uint32       State_array_t[2];            /* State of the vehicle input signals @name: Status @values: struct VDYInSignalState @min:-2.86 @max:2.86 */	/* [Satisfies_rte sws 1189] */


  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t State;                               /* State of the vehicle input signals @name: Status @values: struct VDYInSignalState @min:-2.86 @max:2.86 */
    float32 YawRate;                             /* VDY_SIN_POS_YWR @min:-2.86 @max:2.86 */
    float32 YawRateTemp;                         /* VDY_SIN_POS_YWR_TEMP @min:-2.86 @max:2.86 */
    float32 StWheelAngle;                        /* VDY_SIN_POS_SWA */
    float32 LatAccel;                            /* VDY_SIN_POS_LATA */
    float32 WhlVelFrLeft;                        /* VDY_SIN_POS_WVEL_FL */
    float32 WhlVelFrRight;                       /* VDY_SIN_POS_WVEL_FR */
    float32 WhlVelReLeft;                        /* VDY_SIN_POS_WVEL_RL */
    float32 WhlVelReRight;                       /* VDY_SIN_POS_WVEL_RR */
    float32 YawRateInt;                          /* VDY_SIN_POS_YWRINT @min:-2.86 @max:2.86 */
    float32 YawRateIntTemp;                      /* VDY_SIN_POS_YWRINT_TEMP @min:-2.86 @max:2.86 */
    float32 LongAccel;                           /* VDY_SIN_POS_LONGA */
    float32 RearWhlAngle;                        /* VDY_SIN_POS_RSTA */
    float32 VehVelocityExt;                      /* VDY_SIN_POS_VEHVEL_EXT */
    float32 VehLongAccelExt;                     /* VDY_SIN_POS_VEHACL_EXT */
    LongDirState_t WhlDirFrLeft;                        /* VDY_SIN_POS_WDIR_FL */
    LongDirState_t WhlDirFrRight;                       /* VDY_SIN_POS_WDIR_FR */
    LongDirState_t WhlDirReLeft;                        /* VDY_SIN_POS_WDIR_RL */
    LongDirState_t WhlDirReRight;                       /* VDY_SIN_POS_WDIR_RR */
    uint8 WhlTicksDevFrLeft;                   /* VDY_SIN_POS_WTCKS_FL */
    uint8 WhlTicksDevFrRight;                  /* VDY_SIN_POS_WTCKS_FR */
    uint8 WhlTicksDevReLeft;                   /* VDY_SIN_POS_WTCKS_RL */
    uint8 WhlTicksDevReRight;                  /* VDY_SIN_POS_WTCKS_RR */
    ActGearPos_t ActGearPos;                          /* VDY_SIN_POS_GEAR */
    uint16 BrakeActLevel;                       /* VDY_SIN_POS_BRAKE */
    ParkBrakeState_t ParkBrakeState;                      /* VDY_SIN_POS_PBRK */
    LongDirState_t VehLongDirExt;                       /* VDY_SIN_POS_VDIR */
    VehLongMotStateExt_t VehLongMotStateExt;                  /* VDY_SIN_POS_VMOT */
    float32 CurveC0Ext;                          /* VDY_SIN_POS_CRV */
    float32 CurveC1Ext;                          /* VDY_SIN_POS_SSA */
    float32 SideSlipAngleExt;                    /* VDY_SIN_SIZE_DW */
  } VehSigMain_t;			/* Main Vehicle dynacmis sensor signals */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    float32 EnvTemp;                             /* Ambient environmental temperature */
    WiperState_t WiperState;                          /* Wiper blades activity */
    TurnSignal_t TurnSignal;                          /* Turn signal switch state */
    float32 RoadWhlAngFr;                        /* Steering angle (road wheel) at front axle @min:-25.0 @max:25.0 */
    float32 RoadWhlAngRe;                        /* Steering angle (road wheel) at rear axle @min:-25.0 @max:25.0 */
    float32 Odometer;                            /* Total driven distance @min:-25.0 @max:25.0 */
    boolean b_BlockageDisabled;                  /* The BLOCKED feature is used to enable or disable blockage during run time.  Default value == 0. @min:0.0 @max:1.0 */
  } VehSigAdd_t;			/* Additional Vehicle dynacmis sensor signals */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    TransmissionGear_t ActualGear;                          /* Indicates current used gear position */
    TransmissionGear_t TargetGear;                          /* When a gear shift is in progress, this shows the targeted gear, otherwise it is equal to the Actual Gear */
  } PowerTrain_t;			

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    boolean ABSCtrl;                             /* Attenuation of secondary surface (two-way) @min:0.0 @max:1.0 */
    boolean TCSCtrl;                             /* Test @min:0.0 @max:1.0 */
  } Brake_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    uint32 uiVersionNumber;                     /* Number of used Version @min:0.0 @max:16277215.0 */
    VehSigMain_t VehSigMain;                          /* Main Vehicle dynacmis sensor signals */
    VehSigAdd_t VehSigAdd;                           /* Additional Vehicle dynacmis sensor signals */
    PowerTrain_t PowerTrain;                          
    Brake_t Brake;                               /* Sensor specific parameters */
  } VehSig_t;			/* Main Vehicle dynacmis sensor signals @vaddr:VDY_MEAS_ID_VEH_SIG @cycleid:vdy_cycle_id @vname:VehSig */



}

namespace VehSigV5
{
  typedef uint8 bool8                     			/* [Satisfies_rte sws 1188] */;

  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 @resolution:1.0 */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef sint8 ActGearPos_t              /* VDY_SIN_POS_GEAR @min: 0 @max:3 @values: enum { ACT_GEAR_POS_NEUTRAL=0,ACT_GEAR_POS_FORWARD=2,ACT_GEAR_POS_PARKING=1,ACT_GEAR_POS_REVERSE=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 LongDirState_t            /* @min: 0 @max:2 @values: enum { VDY_LONG_DIR_RWD=2,VDY_LONG_DIR_VOID=0,VDY_LONG_DIR_FWD=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 ParkBrakeState_t          /* VDY_SIN_POS_PBRK @min: 0 @max:1 @values: enum { STAT_ACTIVE=1,STAT_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint32 SigAddState_t             /* @min: 0 @max:1000000 @values: enum { VEH_SIG_ADD_KICK_DOWN=26,VEH_SIG_ADD_SPEEDO_SPEED=34,VEH_SIG_ADD_WIPER_STATE=2,VEH_SIG_ADD_WIPER_WASHER_FRONT=8,VEH_SIG_ADD_BRAKE_PEDAL_PRESSED=28,VEH_SIG_ADD_DRIVER_TIRED=30,VEH_SIG_ADD_SPEED_UNIT=32,VEH_SIG_ADD_ROAD_WHL_ANG_RE=20,VEH_SIG_ADD_ODOMETER=22,VEH_SIG_ADD_FOG_LAMP_REAR=16,VEH_SIG_ADD_RAIN_SENSOR=10,VEH_SIG_ADD_DUMMY=1000000,VEH_SIG_ADD_WIPER_OUT_PARK_POS=6,VEH_SIG_ADD_TURN_SIGNAL=12,VEH_SIG_ADD_GAS_PEDAL_POS=24,VEH_SIG_ADD_ROAD_WHL_ANG_FR=19,VEH_SIG_ADD_ENV_TEMP=0,VEH_SIG_ADD_FOG_LAMP_FRONT=14,VEH_SIG_ADD_WIPER_STAGE=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 SpeedUnit_t               /* ENUM speedmeter speed unit @min: 0 @max:2 @values: enum { VEH_SIG_ADD_SPEEDO_UNIT_MPH=2,VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN=0,VEH_SIG_ADD_SPEEDO_UNIT_KMH=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 TransmissionGear_t        /* Indicates current used gear position @min: 0 @max:10 @values: enum { DYN_GEAR_PARK_GEAR=10,DYN_GEAR_SIXTH_GEAR=6,DYN_GEAR_FIRST_GEAR=1,DYN_GEAR_FIFTH_GEAR=5,DYN_GEAR_SECOND_GEAR=2,DYN_GEAR_EIGHTH_GEAR=8,DYN_GEAR_NEUTRAL_GEAR=0,DYN_GEAR_THIRD_GEAR=3,DYN_GEAR_REVERSE_GEAR=9,DYN_GEAR_SEVENTH_GEAR=7,DYN_GEAR_FOURTH_GEAR=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 TurnSignal_t              /* Turn signal switch state @min: 0 @max:2 @values: enum { VEH_SIG_ADD_TURN_SIG_NEUTRAL=2,VEH_SIG_ADD_TURN_SIG_UNKNOWN=0,VEH_SIG_ADD_TURN_SIG_RIGHT=2,VEH_SIG_ADD_TURN_SIG_LEFT=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 VehLongMotStateExt_t      /* VDY_SIN_POS_VMOT @min: 0 @max:2 @values: enum { VDY_VEH_MOT_STATE_ROLLING=0,VDY_VEH_MOT_STATE_SECURE_STST=2,VDY_VEH_MOT_STATE_FAST_STST=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 WiperStage_t              /* Wiper switch position @min: 0 @max:6 @values: enum { VEH_SIG_ADD_WIPER_INTERVAL1=1,VEH_SIG_ADD_WIPER_INTERVAL2=2,VEH_SIG_ADD_WIPER_INTERVAL3=3,VEH_SIG_ADD_WIPER_INTERVAL4=4,VEH_SIG_ADD_WIPER_OFF=0,VEH_SIG_ADD_WIPER_STAGE1=5,VEH_SIG_ADD_WIPER_STAGE2=6,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 WiperState_t              /* Wiper blades activity @min: 0 @max:1 @values: enum { VEH_SIG_ADD_WIPER_STATE_ACTIVE=1,VEH_SIG_ADD_WIPER_STATE_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 WiperWasherFrontState_t   /* Tip-wipe / washer state @min: 0 @max:2 @values: enum { VEH_SIG_ADD_WWS_WASH=2,VEH_SIG_ADD_WWS_TIPWIPE=1,VEH_SIG_ADD_WWS_IDLE=0,} */	/* [Satisfies_rte sws 1188] */;

  /* typedef AlgoSignalState_t */
  const AlgoSignalState_t AL_SIG_STATE_INIT    = (0);
  const AlgoSignalState_t AL_SIG_STATE_OK      = (1);
  const AlgoSignalState_t AL_SIG_STATE_INVALID = (2);

  /* typedef TurnSignal_t */
  static TurnSignal_t VEH_SIG_ADD_TURN_SIG_UNKNOWN  = (0);
  static TurnSignal_t VEH_SIG_ADD_TURN_SIG_LEFT     = (1);
  static TurnSignal_t VEH_SIG_ADD_TURN_SIG_NEUTRAL  = (2);
  static TurnSignal_t VEH_SIG_ADD_TURN_SIG_RIGHT    = (2);

  /* typedef SigAddState_t */
  const SigAddState_t VEH_SIG_ADD_ENV_TEMP  = (0);
  const SigAddState_t VEH_SIG_ADD_WIPER_STATE  = (2);
  const SigAddState_t VEH_SIG_ADD_WIPER_STAGE  = (4);
  const SigAddState_t VEH_SIG_ADD_WIPER_OUT_PARK_POS  = (6);
  const SigAddState_t VEH_SIG_ADD_WIPER_WASHER_FRONT  = (8);
  const SigAddState_t VEH_SIG_ADD_RAIN_SENSOR  = (10);
  const SigAddState_t VEH_SIG_ADD_TURN_SIGNAL  = (12);
  const SigAddState_t VEH_SIG_ADD_FOG_LAMP_FRONT  = (14);
  const SigAddState_t VEH_SIG_ADD_FOG_LAMP_REAR  = (16);
  const SigAddState_t VEH_SIG_ADD_ROAD_WHL_ANG_FR  = (19);
  const SigAddState_t VEH_SIG_ADD_ROAD_WHL_ANG_RE  = (20);
  const SigAddState_t VEH_SIG_ADD_ODOMETER  = (22);
  const SigAddState_t VEH_SIG_ADD_GAS_PEDAL_POS  = (24);
  const SigAddState_t VEH_SIG_ADD_KICK_DOWN  = (26);
  const SigAddState_t VEH_SIG_ADD_BRAKE_PEDAL_PRESSED  = (28);
  const SigAddState_t VEH_SIG_ADD_DRIVER_TIRED  = (30);
  const SigAddState_t VEH_SIG_ADD_SPEED_UNIT  = (32);
  const SigAddState_t VEH_SIG_ADD_SPEEDO_SPEED  = (34);
  const SigAddState_t VEH_SIG_ADD_DUMMY  = (1000000);

  /* typedef WiperState_t */
  const WiperState_t VEH_SIG_ADD_WIPER_STATE_INACTIVE  = (0);
  const WiperState_t VEH_SIG_ADD_WIPER_STATE_ACTIVE  = (1);

  /* typedef WiperStage_t */
  const WiperStage_t VEH_SIG_ADD_WIPER_OFF  = (0);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL1  = (1);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL2  = (2);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL3  = (3);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL4  = (4);
  const WiperStage_t VEH_SIG_ADD_WIPER_STAGE1  = (5);
  const WiperStage_t VEH_SIG_ADD_WIPER_STAGE2  = (6);

  /* typedef WiperWasherFrontState_t */
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_IDLE  = (0);
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_TIPWIPE  = (1);
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_WASH  = (2);

  /* typedef SpeedUnit_t */
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN  = (0);
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_KMH  = (1);
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_MPH  = (2);

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    bool8 ABSCtrl;
    bool8 TCSCtrl;
  } Brake_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    TransmissionGear_t ActualGear;
    TransmissionGear_t TargetGear;
  } PowerTrain_t;			

  typedef uint32                    	State_array_t_0[2];/* State of the vehicle input signals @name: Status @values: struct VDYInSignalState @min:-2.86 @max:2.86 */	/* [Satisfies_rte sws 1189] */
  /* State of the vehicle input signals @name: Status @values: struct VDYInSignalState @min:-2.86 @max:2.86 */			/* [Satisfies_rte_sws_1189] */
  typedef SigAddState_t             	State_array_t_1[2];/* State of the add vehicle input signals @name: Status @values: struct VehSignalAddState */	/* [Satisfies_rte sws 1189] */
  /* State of the add vehicle input signals @name: Status @values: struct VehSignalAddState */			/* [Satisfies_rte_sws_1189] */
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
    SignalHeader_t sSignalHeader;
    VehSigMain_t VehSigMain;
    VehSigAdd_t VehSigAdd;
    PowerTrain_t PowerTrain;
    Brake_t Brake;
  } VehSig_t;			/* Main Vehicle dynacmis sensor signals @vaddr:VDY_MEAS_ID_VEH_SIG @cycleid:vdy_cycle_id @vname:VehSig */
}

namespace VehSigV6
{
/*
- Add missing states for added additional signals, trailer con and ign switch
- Add trun signal both to turn signal enum 
- Add TrailerConnection to additional signals 
- Add IgnitionSwitch to additional signals
*/

  typedef uint8 bool8                     			/* [Satisfies_rte sws 1188] */;

  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 @resolution:1.0 */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef sint8 ActGearPos_t              /* VDY_SIN_POS_GEAR @min: 0 @max:3 @values: enum { ACT_GEAR_POS_NEUTRAL=0,ACT_GEAR_POS_FORWARD=2,ACT_GEAR_POS_PARKING=1,ACT_GEAR_POS_REVERSE=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 IgnitionSwitch_t          /* Ignition lockI, gnition off, Ignition accessory (15r) , Ignition on (15) , Ignition start (50) @min: 0 @max:5 @values: enum { VEH_SIG_ADD_IGN_ON=4,VEH_SIG_ADD_IGN_START=5,VEH_SIG_ADD_IGN_LOCK=0,VEH_SIG_ADD_IGN_OFF=1,VEH_SIG_ADD_IGN_ACC=2,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 LongDirState_t            /* @min: 0 @max:2 @values: enum { VDY_LONG_DIR_RWD=2,VDY_LONG_DIR_VOID=0,VDY_LONG_DIR_FWD=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 ParkBrakeState_t          /* VDY_SIN_POS_PBRK @min: 0 @max:1 @values: enum { STAT_ACTIVE=1,STAT_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint32 SigAddState_t             /* @min: 0 @max:1000000 @values: enum { VEH_SIG_ADD_KICK_DOWN=26,VEH_SIG_ADD_SPEEDO_SPEED=34,VEH_SIG_ADD_WIPER_STATE=2,VEH_SIG_ADD_WIPER_WASHER_FRONT=8,VEH_SIG_ADD_BRAKE_PEDAL_PRESSED=28,VEH_SIG_ADD_DRIVER_TIRED=30,VEH_SIG_ADD_SPEED_UNIT=32,VEH_SIG_ADD_ROAD_WHL_ANG_RE=20,VEH_SIG_ADD_ODOMETER=22,VEH_SIG_ADD_FOG_LAMP_REAR=16,VEH_SIG_ADD_RAIN_SENSOR=10,VEH_SIG_ADD_DUMMY=1000000,VEH_SIG_ADD_WIPER_OUT_PARK_POS=6,VEH_SIG_ADD_TURN_SIGNAL=12,VEH_SIG_ADD_GAS_PEDAL_POS=24,VEH_SIG_ADD_ROAD_WHL_ANG_FR=19,VEH_SIG_ADD_ENV_TEMP=0,VEH_SIG_ADD_FOG_LAMP_FRONT=14,VEH_SIG_ADD_WIPER_STAGE=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 SigMainState_t            /* @min: 0 @max:1000000 @values: enum { VDY_SIN_POS_YWR_TEMP=2,VDY_SIN_POS_YWRINT_TEMP=18,VDY_SIN_POS_WTCKS_RL=40,VDY_SIN_POS_WVEL_FL=8,VDY_SIN_POS_VMOT=52,VDY_SIN_POS_WVEL_FR=10,VDY_SIN_POS_MAX=1000000,VDY_SIN_POS_SSA=58,VDY_SIN_POS_WTCKS_RR=42,VDY_SIN_POS_BRAKE=46,VDY_SIN_POS_VDIR=50,VDY_SIN_POS_DUMMY=54,VDY_SIN_POS_LATA=6,VDY_SIN_POS_PBRK=48,VDY_SIN_POS_YWRINT=16,VDY_SIN_POS_LONGA=20,VDY_SIN_POS_WDIR_RR=34,VDY_SIN_POS_YWR=0,VDY_SIN_POS_VEHACL_EXT=26,VDY_SIN_POS_WDIR_RL=32,VDY_SIN_POS_GEAR=44,VDY_SIN_POS_WDIR_FL=28,VDY_SIN_POS_SWA=4,VDY_SIN_POS_RSTA=22,VDY_SIN_POS_VEHVEL_EXT=24,VDY_SIN_POS_CRV=56,VDY_SIN_POS_WTCKS_FR=38,VDY_SIN_POS_WVEL_RR=14,VDY_SIN_POS_WVEL_RL=12,VDY_SIN_POS_WTCKS_FL=36,VDY_SIN_POS_WDIR_FR=30,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 SpeedUnit_t               /* ENUM speedmeter speed unit @min: 0 @max:2 @values: enum { VEH_SIG_ADD_SPEEDO_UNIT_MPH=2,VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN=0,VEH_SIG_ADD_SPEEDO_UNIT_KMH=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 TrailerConnection_t       /* No trailer detected, Trailer detected, not defined,
                                          Trailer signal is not available @min: 0 @max:3 @values: enum { VEH_SIG_ADD_TRLR_OK=1,VEH_SIG_ADD_TRLR_NDEF2=2,VEH_SIG_ADD_TRLR_NO_DETECT=0,VEH_SIG_ADD_TRLR_SNA=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 TransmissionGear_t        /* Indicates current used gear position @min: 0 @max:10 @values: enum { DYN_GEAR_PARK_GEAR=10,DYN_GEAR_SIXTH_GEAR=6,DYN_GEAR_FIRST_GEAR=1,DYN_GEAR_FIFTH_GEAR=5,DYN_GEAR_SECOND_GEAR=2,DYN_GEAR_EIGHTH_GEAR=8,DYN_GEAR_NEUTRAL_GEAR=0,DYN_GEAR_THIRD_GEAR=3,DYN_GEAR_REVERSE_GEAR=9,DYN_GEAR_SEVENTH_GEAR=7,DYN_GEAR_FOURTH_GEAR=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 TurnSignal_t              /* Turn signal switch state @min: 0 @max:2 @values: enum { VEH_SIG_ADD_TURN_SIG_NEUTRAL=2,VEH_SIG_ADD_TURN_SIG_UNKNOWN=0,VEH_SIG_ADD_TURN_SIG_RIGHT=2,VEH_SIG_ADD_TURN_SIG_LEFT=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 VehLongMotStateExt_t      /* VDY_SIN_POS_VMOT @min: 0 @max:2 @values: enum { VDY_VEH_MOT_STATE_ROLLING=0,VDY_VEH_MOT_STATE_SECURE_STST=2,VDY_VEH_MOT_STATE_FAST_STST=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 WiperStage_t              /* Wiper switch position @min: 0 @max:6 @values: enum { VEH_SIG_ADD_WIPER_INTERVAL1=1,VEH_SIG_ADD_WIPER_INTERVAL2=2,VEH_SIG_ADD_WIPER_INTERVAL3=3,VEH_SIG_ADD_WIPER_INTERVAL4=4,VEH_SIG_ADD_WIPER_OFF=0,VEH_SIG_ADD_WIPER_STAGE1=5,VEH_SIG_ADD_WIPER_STAGE2=6,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 WiperState_t              /* Wiper blades activity @min: 0 @max:1 @values: enum { VEH_SIG_ADD_WIPER_STATE_ACTIVE=1,VEH_SIG_ADD_WIPER_STATE_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef sint8 WiperWasherFrontState_t   /* Tip-wipe / washer state @min: 0 @max:2 @values: enum { VEH_SIG_ADD_WWS_WASH=2,VEH_SIG_ADD_WWS_TIPWIPE=1,VEH_SIG_ADD_WWS_IDLE=0,} */	/* [Satisfies_rte sws 1188] */;

  /* typedef SigMainState_t */
  const SigMainState_t VDY_SIN_POS_YWR  = (0);
  const SigMainState_t VDY_SIN_POS_YWR_TEMP  = (2);
  const SigMainState_t VDY_SIN_POS_SWA  = (4);
  const SigMainState_t VDY_SIN_POS_LATA  = (6);
  const SigMainState_t VDY_SIN_POS_WVEL_FL  = (8);
  const SigMainState_t VDY_SIN_POS_WVEL_FR  = (10);
  const SigMainState_t VDY_SIN_POS_WVEL_RL  = (12);
  const SigMainState_t VDY_SIN_POS_WVEL_RR  = (14);
  const SigMainState_t VDY_SIN_POS_YWRINT  = (16);
  const SigMainState_t VDY_SIN_POS_YWRINT_TEMP  = (18);
  const SigMainState_t VDY_SIN_POS_LONGA  = (20);
  const SigMainState_t VDY_SIN_POS_RSTA  = (22);
  const SigMainState_t VDY_SIN_POS_VEHVEL_EXT  = (24);
  const SigMainState_t VDY_SIN_POS_VEHACL_EXT  = (26);
  const SigMainState_t VDY_SIN_POS_WDIR_FL  = (28);
  const SigMainState_t VDY_SIN_POS_WDIR_FR  = (30);
  const SigMainState_t VDY_SIN_POS_WDIR_RL  = (32);
  const SigMainState_t VDY_SIN_POS_WDIR_RR  = (34);
  const SigMainState_t VDY_SIN_POS_WTCKS_FL  = (36);
  const SigMainState_t VDY_SIN_POS_WTCKS_FR  = (38);
  const SigMainState_t VDY_SIN_POS_WTCKS_RL  = (40);
  const SigMainState_t VDY_SIN_POS_WTCKS_RR  = (42);
  const SigMainState_t VDY_SIN_POS_GEAR  = (44);
  const SigMainState_t VDY_SIN_POS_BRAKE  = (46);
  const SigMainState_t VDY_SIN_POS_PBRK  = (48);
  const SigMainState_t VDY_SIN_POS_VDIR  = (50);
  const SigMainState_t VDY_SIN_POS_VMOT  = (52);
  const SigMainState_t VDY_SIN_POS_DUMMY  = (54);
  const SigMainState_t VDY_SIN_POS_CRV  = (56);
  const SigMainState_t VDY_SIN_POS_SSA  = (58);
  const SigMainState_t VDY_SIN_POS_MAX  = (1000000);

  /* typedef ActGearPos_t */
  const ActGearPos_t ACT_GEAR_POS_NEUTRAL  = (0);
  const ActGearPos_t ACT_GEAR_POS_PARKING  = (1);
  const ActGearPos_t ACT_GEAR_POS_FORWARD  = (2);
  const ActGearPos_t ACT_GEAR_POS_REVERSE  = (3);

  /* typedef ParkBrakeState_t */
  const ParkBrakeState_t STAT_INACTIVE  = (0);
  const ParkBrakeState_t STAT_ACTIVE  = (1);

  /* typedef VehLongMotStateExt_t */
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_ROLLING  = (0);
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_FAST_STST  = (1);
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_SECURE_STST  = (2);

  /* typedef SigAddState_t */
  const SigAddState_t VEH_SIG_ADD_ENV_TEMP  = (0);
  const SigAddState_t VEH_SIG_ADD_WIPER_STATE  = (2);
  const SigAddState_t VEH_SIG_ADD_WIPER_STAGE  = (4);
  const SigAddState_t VEH_SIG_ADD_WIPER_OUT_PARK_POS  = (6);
  const SigAddState_t VEH_SIG_ADD_WIPER_WASHER_FRONT  = (8);
  const SigAddState_t VEH_SIG_ADD_RAIN_SENSOR  = (10);
  const SigAddState_t VEH_SIG_ADD_TURN_SIGNAL  = (12);
  const SigAddState_t VEH_SIG_ADD_FOG_LAMP_FRONT  = (14);
  const SigAddState_t VEH_SIG_ADD_FOG_LAMP_REAR  = (16);
  const SigAddState_t VEH_SIG_ADD_ROAD_WHL_ANG_FR  = (19);
  const SigAddState_t VEH_SIG_ADD_ROAD_WHL_ANG_RE  = (20);
  const SigAddState_t VEH_SIG_ADD_ODOMETER  = (22);
  const SigAddState_t VEH_SIG_ADD_GAS_PEDAL_POS  = (24);
  const SigAddState_t VEH_SIG_ADD_KICK_DOWN  = (26);
  const SigAddState_t VEH_SIG_ADD_BRAKE_PEDAL_PRESSED  = (28);
  const SigAddState_t VEH_SIG_ADD_DRIVER_TIRED  = (30);
  const SigAddState_t VEH_SIG_ADD_SPEED_UNIT  = (32);
  const SigAddState_t VEH_SIG_ADD_SPEEDO_SPEED  = (34);
  const SigAddState_t VEH_SIG_ADD_TRAILER_CON  = (36);
  const SigAddState_t VEH_SIG_ADD_IGN_SWITCH  = (38);
  const SigAddState_t VEH_SIG_ADD_DUMMY  = (1000000);

  /* typedef WiperState_t */
  const WiperState_t VEH_SIG_ADD_WIPER_STATE_INACTIVE  = (0);
  const WiperState_t VEH_SIG_ADD_WIPER_STATE_ACTIVE  = (1);

  /* typedef WiperStage_t */
  const WiperStage_t VEH_SIG_ADD_WIPER_OFF  = (0);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL1  = (1);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL2  = (2);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL3  = (3);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL4  = (4);
  const WiperStage_t VEH_SIG_ADD_WIPER_STAGE1  = (5);
  const WiperStage_t VEH_SIG_ADD_WIPER_STAGE2  = (6);

  /* typedef WiperWasherFrontState_t */
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_IDLE  = (0);
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_TIPWIPE  = (1);
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_WASH  = (2);

  /* typedef TurnSignal_t */
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_UNKNOWN  = (0);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_LEFT  = (1);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_RIGHT  = (2);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_NEUTRAL  = (3);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_BOTH  = (4);

  /* typedef SpeedUnit_t */
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN  = (0);
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_KMH  = (1);
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_MPH  = (2);

  /* typedef TrailerConnection_t */
  const TrailerConnection_t VEH_SIG_ADD_TRLR_NO_DETECT  = (0);
  const TrailerConnection_t VEH_SIG_ADD_TRLR_OK  = (1);
  const TrailerConnection_t VEH_SIG_ADD_TRLR_NDEF2  = (2);
  const TrailerConnection_t VEH_SIG_ADD_TRLR_SNA  = (3);

  /* typedef IgnitionSwitch_t */
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_LOCK  = (0);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_OFF  = (1);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_ACC  = (2);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_ON  = (4);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_START  = (5);

  /* typedef TransmissionGear_t */
  const TransmissionGear_t DYN_GEAR_NEUTRAL_GEAR  = (0);
  const TransmissionGear_t DYN_GEAR_FIRST_GEAR  = (1);
  const TransmissionGear_t DYN_GEAR_SECOND_GEAR  = (2);
  const TransmissionGear_t DYN_GEAR_THIRD_GEAR  = (3);
  const TransmissionGear_t DYN_GEAR_FOURTH_GEAR  = (4);
  const TransmissionGear_t DYN_GEAR_FIFTH_GEAR  = (5);
  const TransmissionGear_t DYN_GEAR_SIXTH_GEAR  = (6);
  const TransmissionGear_t DYN_GEAR_SEVENTH_GEAR  = (7);
  const TransmissionGear_t DYN_GEAR_EIGHTH_GEAR  = (8);
  const TransmissionGear_t DYN_GEAR_REVERSE_GEAR  = (9);
  const TransmissionGear_t DYN_GEAR_PARK_GEAR  = (10);

  /* typedef LongDirState_t */
  const LongDirState_t VDY_LONG_DIR_VOID  = (0);
  const LongDirState_t VDY_LONG_DIR_FWD  = (1);
  const LongDirState_t VDY_LONG_DIR_RWD  = (2);

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    bool8 ABSCtrl;
    bool8 TCSCtrl;
  } Brake_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    TransmissionGear_t ActualGear;
    TransmissionGear_t TargetGear;
  } PowerTrain_t;			

  typedef SigMainState_t            	State_array_t_0[2];/* State of the vehicle input signals @name: Status @values: struct VDYInSignalState */	/* [Satisfies_rte sws 1189] */
  /* State of the vehicle input signals @name: Status @values: struct VDYInSignalState */			/* [Satisfies_rte_sws_1189] */
  typedef SigAddState_t             	State_array_t_1[2];/* State of the add vehicle input signals @name: Status @values: struct VehSignalAddState */	/* [Satisfies_rte sws 1189] */
  /* State of the add vehicle input signals @name: Status @values: struct VehSignalAddState */			/* [Satisfies_rte_sws_1189] */
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
    SignalHeader_t sSignalHeader;
    VehSigMain_t VehSigMain;
    VehSigAdd_t VehSigAdd;
    PowerTrain_t PowerTrain;
    Brake_t Brake;
  } VehSig_t;			/* Main Vehicle dynacmis sensor signals @vaddr:0x20300050 @vaddr_defs: VDY_MEAS_ID_VEH_SIG @cycleid:vdy_cycle_id @vname:VehSig */
}

namespace VehSigV7
{
  typedef uint8 bool8                     			/* [Satisfies_rte sws 1188] */;

  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint32 SigMainState_t            /* @min: 0 @max:1000000 @values: enum { VDY_SIN_POS_YWR_TEMP=2,VDY_SIN_POS_YWRINT_TEMP=18,VDY_SIN_POS_WTCKS_RL=40,VDY_SIN_POS_WVEL_FL=8,VDY_SIN_POS_VMOT=52,VDY_SIN_POS_WVEL_FR=10,VDY_SIN_POS_MAX=1000000,VDY_SIN_POS_SSA=58,VDY_SIN_POS_WTCKS_RR=42,VDY_SIN_POS_BRAKE=46,VDY_SIN_POS_VDIR=50,VDY_SIN_POS_DUMMY=54,VDY_SIN_POS_LATA=6,VDY_SIN_POS_PBRK=48,VDY_SIN_POS_YWRINT=16,VDY_SIN_POS_LONGA=20,VDY_SIN_POS_WDIR_RR=34,VDY_SIN_POS_YWR=0,VDY_SIN_POS_VEHACL_EXT=26,VDY_SIN_POS_WDIR_RL=32,VDY_SIN_POS_GEAR=44,VDY_SIN_POS_WDIR_FL=28,VDY_SIN_POS_SWA=4,VDY_SIN_POS_RSTA=22,VDY_SIN_POS_VEHVEL_EXT=24,VDY_SIN_POS_CRV=56,VDY_SIN_POS_WTCKS_FR=38,VDY_SIN_POS_WVEL_RR=14,VDY_SIN_POS_WVEL_RL=12,VDY_SIN_POS_WTCKS_FL=36,VDY_SIN_POS_WDIR_FR=30,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 LongDirState_t            /* @min: 0 @max:2 @values: enum { VDY_LONG_DIR_RWD=2,VDY_LONG_DIR_VOID=0,VDY_LONG_DIR_FWD=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 ActGearPos_t              /* VDY_SIN_POS_GEAR @min: 0 @max:3 @values: enum { ACT_GEAR_POS_NEUTRAL=0,ACT_GEAR_POS_FORWARD=2,ACT_GEAR_POS_PARKING=1,ACT_GEAR_POS_REVERSE=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 ParkBrakeState_t          /* VDY_SIN_POS_PBRK @min: 0 @max:1 @values: enum { STAT_ACTIVE=1,STAT_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 VehLongMotStateExt_t      /* VDY_SIN_POS_VMOT @min: 0 @max:2 @values: enum { VDY_VEH_MOT_STATE_ROLLING=0,VDY_VEH_MOT_STATE_SECURE_STST=2,VDY_VEH_MOT_STATE_FAST_STST=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint32 SigAddState_t             /* @min: 0 @max:1000000 @values: enum { VEH_SIG_ADD_KICK_DOWN=26,VEH_SIG_ADD_SPEEDO_SPEED=34,VEH_SIG_ADD_WIPER_STATE=2,VEH_SIG_ADD_WIPER_WASHER_FRONT=8,VEH_SIG_ADD_TRAILER_CON=36,VEH_SIG_ADD_BRAKE_PEDAL_PRESSED=28,VEH_SIG_ADD_DRIVER_TIRED=30,VEH_SIG_ADD_SPEED_UNIT=32,VEH_SIG_ADD_ROAD_WHL_ANG_RE=20,VEH_SIG_ADD_ODOMETER=22,VEH_SIG_ADD_FOG_LAMP_REAR=16,VEH_SIG_ADD_RAIN_SENSOR=10,VEH_SIG_ADD_DUMMY=1000000,VEH_SIG_ADD_WIPER_OUT_PARK_POS=6,VEH_SIG_ADD_TURN_SIGNAL=12,VEH_SIG_ADD_GAS_PEDAL_POS=24,VEH_SIG_ADD_ROAD_WHL_ANG_FR=19,VEH_SIG_ADD_IGN_SWITCH=38,VEH_SIG_ADD_ENV_TEMP=0,VEH_SIG_ADD_FOG_LAMP_FRONT=14,VEH_SIG_ADD_WIPER_STAGE=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 WiperState_t              /* Wiper blades activity @min: 0 @max:1 @values: enum { VEH_SIG_ADD_WIPER_STATE_ACTIVE=1,VEH_SIG_ADD_WIPER_STATE_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 WiperStage_t              /* Wiper switch position @min: 0 @max:6 @values: enum { VEH_SIG_ADD_WIPER_INTERVAL1=1,VEH_SIG_ADD_WIPER_INTERVAL2=2,VEH_SIG_ADD_WIPER_INTERVAL3=3,VEH_SIG_ADD_WIPER_INTERVAL4=4,VEH_SIG_ADD_WIPER_OFF=0,VEH_SIG_ADD_WIPER_STAGE1=5,VEH_SIG_ADD_WIPER_STAGE2=6,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 WiperWasherFrontState_t   /* Tip-wipe / washer state @min: 0 @max:2 @values: enum { VEH_SIG_ADD_WWS_WASH=2,VEH_SIG_ADD_WWS_TIPWIPE=1,VEH_SIG_ADD_WWS_IDLE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 TurnSignal_t              /* Turn signal switch state @min: 0 @max:4 @values: enum { VEH_SIG_ADD_TURN_SIG_NEUTRAL=3,VEH_SIG_ADD_TURN_SIG_UNKNOWN=0,VEH_SIG_ADD_TURN_SIG_RIGHT=2,VEH_SIG_ADD_TURN_SIG_LEFT=1,VEH_SIG_ADD_TURN_SIG_BOTH=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 SpeedUnit_t               /* ENUM speedmeter speed unit @min: 0 @max:2 @values: enum { VEH_SIG_ADD_SPEEDO_UNIT_MPH=2,VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN=0,VEH_SIG_ADD_SPEEDO_UNIT_KMH=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 TrailerConnection_t       /* No trailer detected, Trailer detected, not defined, Trailer signal is not available @min: 0 @max:3 @values: enum { VEH_SIG_ADD_TRLR_OK=1,VEH_SIG_ADD_TRLR_NDEF2=2,VEH_SIG_ADD_TRLR_NO_DETECT=0,VEH_SIG_ADD_TRLR_SNA=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 IgnitionSwitch_t          /* Ignition lockI, gnition off, Ignition accessory (15r) , Ignition on (15) , Ignition start (50) @min: 0 @max:5 @values: enum { VEH_SIG_ADD_IGN_ON=4,VEH_SIG_ADD_IGN_START=5,VEH_SIG_ADD_IGN_LOCK=0,VEH_SIG_ADD_IGN_OFF=1,VEH_SIG_ADD_IGN_ACC=2,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint8 TransmissionGear_t        /* Indicates current used gear position @min: 0 @max:12 @values: enum { DYN_GEAR_PARK_GEAR=11,DYN_GEAR_SIXTH_GEAR=6,DYN_GEAR_FIRST_GEAR=1,DYN_GEAR_FIFTH_GEAR=5,DYN_GEAR_SECOND_GEAR=2,DYN_GEAR_EIGHTH_GEAR=8,DYN_GEAR_NEUTRAL_GEAR=0,DYN_GEAR_POWER_FREE=12,DYN_GEAR_THIRD_GEAR=3,DYN_GEAR_REVERSE_GEAR=10,DYN_GEAR_SEVENTH_GEAR=7,DYN_GEAR_NINTH_GEAR=9,DYN_GEAR_FOURTH_GEAR=4,} */	/* [Satisfies_rte sws 1188] */;

  typedef SigMainState_t            	State_array_t_0[2];/* State of the vehicle input signals @name: Status @values: struct VDYInSignalState */	/* [Satisfies_rte sws 1189] */
  typedef SigAddState_t             	State_array_t_1[2];/* State of the add vehicle input signals @name: Status @values: struct VehSignalAddState */	/* [Satisfies_rte sws 1189] */

  /* typedef SigMainState_t */
  const SigMainState_t VDY_SIN_POS_YWR         = (0);
  const SigMainState_t VDY_SIN_POS_YWR_TEMP    = (2);
  const SigMainState_t VDY_SIN_POS_SWA         = (4);
  const SigMainState_t VDY_SIN_POS_LATA        = (6);
  const SigMainState_t VDY_SIN_POS_WVEL_FL     = (8);
  const SigMainState_t VDY_SIN_POS_WVEL_FR     = (10);
  const SigMainState_t VDY_SIN_POS_WVEL_RL     = (12);
  const SigMainState_t VDY_SIN_POS_WVEL_RR     = (14);
  const SigMainState_t VDY_SIN_POS_YWRINT      = (16);
  const SigMainState_t VDY_SIN_POS_YWRINT_TEMP = (18);
  const SigMainState_t VDY_SIN_POS_LONGA       = (20);
  const SigMainState_t VDY_SIN_POS_RSTA        = (22);
  const SigMainState_t VDY_SIN_POS_VEHVEL_EXT  = (24);
  const SigMainState_t VDY_SIN_POS_VEHACL_EXT  = (26);
  const SigMainState_t VDY_SIN_POS_WDIR_FL     = (28);
  const SigMainState_t VDY_SIN_POS_WDIR_FR     = (30);
  const SigMainState_t VDY_SIN_POS_WDIR_RL     = (32);
  const SigMainState_t VDY_SIN_POS_WDIR_RR     = (34);
  const SigMainState_t VDY_SIN_POS_WTCKS_FL    = (36);
  const SigMainState_t VDY_SIN_POS_WTCKS_FR    = (38);
  const SigMainState_t VDY_SIN_POS_WTCKS_RL    = (40);
  const SigMainState_t VDY_SIN_POS_WTCKS_RR    = (42);
  const SigMainState_t VDY_SIN_POS_GEAR        = (44);
  const SigMainState_t VDY_SIN_POS_BRAKE       = (46);
  const SigMainState_t VDY_SIN_POS_PBRK        = (48);
  const SigMainState_t VDY_SIN_POS_VDIR        = (50);
  const SigMainState_t VDY_SIN_POS_VMOT        = (52);
  const SigMainState_t VDY_SIN_POS_DUMMY       = (54);
  const SigMainState_t VDY_SIN_POS_CRV         = (56);
  const SigMainState_t VDY_SIN_POS_SSA         = (58);
  const SigMainState_t VDY_SIN_POS_MAX         = (1000000);

  /* typedef LongDirState_t */
  const LongDirState_t VDY_LONG_DIR_VOID = (0);
  const LongDirState_t VDY_LONG_DIR_FWD  = (1);
  const LongDirState_t VDY_LONG_DIR_RWD  = (2);

  /* typedef ActGearPos_t */
  const ActGearPos_t ACT_GEAR_POS_NEUTRAL = (0);
  const ActGearPos_t ACT_GEAR_POS_PARKING = (1);
  const ActGearPos_t ACT_GEAR_POS_FORWARD = (2);
  const ActGearPos_t ACT_GEAR_POS_REVERSE = (3);

  /* typedef ParkBrakeState_t */
  const ParkBrakeState_t STAT_INACTIVE = (0);
  const ParkBrakeState_t STAT_ACTIVE   = (1);

  /* typedef VehLongMotStateExt_t */
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_ROLLING     = (0);
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_FAST_STST   = (1);
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_SECURE_STST = (2);

  /* typedef SigAddState_t */
  const SigAddState_t VEH_SIG_ADD_ENV_TEMP            = (0);
  const SigAddState_t VEH_SIG_ADD_WIPER_STATE         = (2);
  const SigAddState_t VEH_SIG_ADD_WIPER_STAGE         = (4);
  const SigAddState_t VEH_SIG_ADD_WIPER_OUT_PARK_POS  = (6);
  const SigAddState_t VEH_SIG_ADD_WIPER_WASHER_FRONT  = (8);
  const SigAddState_t VEH_SIG_ADD_RAIN_SENSOR         = (10);
  const SigAddState_t VEH_SIG_ADD_TURN_SIGNAL         = (12);
  const SigAddState_t VEH_SIG_ADD_FOG_LAMP_FRONT      = (14);
  const SigAddState_t VEH_SIG_ADD_FOG_LAMP_REAR       = (16);
  const SigAddState_t VEH_SIG_ADD_ROAD_WHL_ANG_FR     = (19);
  const SigAddState_t VEH_SIG_ADD_ROAD_WHL_ANG_RE     = (20);
  const SigAddState_t VEH_SIG_ADD_ODOMETER            = (22);
  const SigAddState_t VEH_SIG_ADD_GAS_PEDAL_POS       = (24);
  const SigAddState_t VEH_SIG_ADD_KICK_DOWN           = (26);
  const SigAddState_t VEH_SIG_ADD_BRAKE_PEDAL_PRESSED = (28);
  const SigAddState_t VEH_SIG_ADD_DRIVER_TIRED        = (30);
  const SigAddState_t VEH_SIG_ADD_SPEED_UNIT          = (32);
  const SigAddState_t VEH_SIG_ADD_SPEEDO_SPEED        = (34);
  const SigAddState_t VEH_SIG_ADD_TRAILER_CON         = (36);
  const SigAddState_t VEH_SIG_ADD_IGN_SWITCH          = (38);
  const SigAddState_t VEH_SIG_ADD_DUMMY               = (1000000);

  /* typedef WiperState_t */
  const WiperState_t VEH_SIG_ADD_WIPER_STATE_INACTIVE = (0);
  const WiperState_t VEH_SIG_ADD_WIPER_STATE_ACTIVE   = (1);

  /* typedef WiperStage_t */
  const WiperStage_t VEH_SIG_ADD_WIPER_OFF       = (0);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL1 = (1);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL2 = (2);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL3 = (3);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL4 = (4);
  const WiperStage_t VEH_SIG_ADD_WIPER_STAGE1    = (5);
  const WiperStage_t VEH_SIG_ADD_WIPER_STAGE2    = (6);

  /* typedef WiperWasherFrontState_t */
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_IDLE    = (0);
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_TIPWIPE = (1);
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_WASH    = (2);

  /* typedef TurnSignal_t */
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_UNKNOWN = (0);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_LEFT    = (1);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_RIGHT   = (2);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_NEUTRAL = (3);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_BOTH    = (4);

  /* typedef SpeedUnit_t */
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN = (0);
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_KMH     = (1);
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_MPH     = (2);

  /* typedef TrailerConnection_t */
  const TrailerConnection_t VEH_SIG_ADD_TRLR_NO_DETECT = (0);
  const TrailerConnection_t VEH_SIG_ADD_TRLR_OK        = (1);
  const TrailerConnection_t VEH_SIG_ADD_TRLR_NDEF2     = (2);
  const TrailerConnection_t VEH_SIG_ADD_TRLR_SNA       = (3);

  /* typedef IgnitionSwitch_t */
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_LOCK   = (0);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_OFF    = (1);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_ACC    = (2);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_ON     = (4);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_START  = (5);

  /* typedef TransmissionGear_t */
  const TransmissionGear_t DYN_GEAR_NEUTRAL_GEAR = (0);
  const TransmissionGear_t DYN_GEAR_FIRST_GEAR   = (1);
  const TransmissionGear_t DYN_GEAR_SECOND_GEAR  = (2);
  const TransmissionGear_t DYN_GEAR_THIRD_GEAR   = (3);
  const TransmissionGear_t DYN_GEAR_FOURTH_GEAR  = (4);
  const TransmissionGear_t DYN_GEAR_FIFTH_GEAR   = (5);
  const TransmissionGear_t DYN_GEAR_SIXTH_GEAR   = (6);
  const TransmissionGear_t DYN_GEAR_SEVENTH_GEAR = (7);
  const TransmissionGear_t DYN_GEAR_EIGHTH_GEAR  = (8);
  const TransmissionGear_t DYN_GEAR_NINTH_GEAR   = (9);
  const TransmissionGear_t DYN_GEAR_REVERSE_GEAR = (10);
  const TransmissionGear_t DYN_GEAR_PARK_GEAR    = (11);
  const TransmissionGear_t DYN_GEAR_POWER_FREE   = (12);

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  AlgoDataTimeStamp_t uiTimeStamp;
 	  AlgoCycleCounter_t uiMeasurementCounter;
 	  AlgoCycleCounter_t uiCycleCounter;
 	  AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

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
	  TransmissionGear_t ActualGear;
 	  TransmissionGear_t TargetGear;
 	  bool8 EngineRunning;
  } PowerTrain_t;			

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  bool8 ABSCtrl;
 	  bool8 TCSCtrl;
  } Brake_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  AlgoInterfaceVersionNumber_t uiVersionNumber;
 	  SignalHeader_t sSignalHeader;
 	  VehSigMain_t VehSigMain;
 	  VehSigAdd_t VehSigAdd;
 	  PowerTrain_t PowerTrain;
 	  Brake_t Brake;
  } VehSig_t;			/* Main Vehicle dynacmis sensor signals @vaddr:0x20300050 @vaddr_defs: VDY_MEAS_ID_VEH_SIG @cycleid:vdy_cycle_id @vname:VehSig */
}

namespace VehSigV8
{
  /*! External interface states version 8 and higher */
  const uint8 VEH_SIG_IO_STATE_VALID = 0U;
  const uint8 VEH_SIG_IO_STATE_INVALID = 1U;
  const uint8 VEH_SIG_IO_STATE_NOTAVAIL = 2U;
  const uint8 VEH_SIG_IO_STATE_DECREASED = 3U;
  const uint8 VEH_SIG_IO_STATE_SUBSTITUE = 4U;
  const uint8 VEH_SIG_IO_STATE_INIT = 15U;
  const uint8 VEH_SIG_IO_STATE_MAX = 255U;

  typedef uint8 bool8                     			/* [Satisfies_rte sws 1188] */;

  typedef unsigned char VDYIoStateTypes_t         /* vdy io states @min: 0 @max:255 @values: enum { VDY_IO_STATE_VALID=0,VDY_IO_STATE_SUBSTITUE=4,VDY_IO_STATE_INIT=15,VDY_IO_STATE_DECREASED=3,VDY_IO_STATE_INVALID=1,VDY_IO_STATE_NOTAVAIL=2,VDY_IO_STATE_MAX=255,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint8 LongDirState_t            /* @min: 0 @max:2 @values: enum { VDY_LONG_DIR_RWD=2,VDY_LONG_DIR_VOID=0,VDY_LONG_DIR_FWD=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 ActGearPos_t              /* VDY_SIN_POS_GEAR @min: 0 @max:3 @values: enum { ACT_GEAR_POS_NEUTRAL=0,ACT_GEAR_POS_FORWARD=2,ACT_GEAR_POS_PARKING=1,ACT_GEAR_POS_REVERSE=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 ParkBrakeState_t          /* VDY_SIN_POS_PBRK @min: 0 @max:1 @values: enum { STAT_ACTIVE=1,STAT_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 VehLongMotStateExt_t      /* VDY_SIN_POS_VMOT @min: 0 @max:2 @values: enum { VDY_VEH_MOT_STATE_ROLLING=0,VDY_VEH_MOT_STATE_SECURE_STST=2,VDY_VEH_MOT_STATE_FAST_STST=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint8 WiperState_t              /* Wiper blades activity @min: 0 @max:1 @values: enum { VEH_SIG_ADD_WIPER_STATE_ACTIVE=1,VEH_SIG_ADD_WIPER_STATE_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 WiperStage_t              /* Wiper switch position @min: 0 @max:6 @values: enum { VEH_SIG_ADD_WIPER_INTERVAL1=1,VEH_SIG_ADD_WIPER_INTERVAL2=2,VEH_SIG_ADD_WIPER_INTERVAL3=3,VEH_SIG_ADD_WIPER_INTERVAL4=4,VEH_SIG_ADD_WIPER_OFF=0,VEH_SIG_ADD_WIPER_STAGE1=5,VEH_SIG_ADD_WIPER_STAGE2=6,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 WiperWasherFrontState_t   /* Tip-wipe / washer state @min: 0 @max:2 @values: enum { VEH_SIG_ADD_WWS_WASH=2,VEH_SIG_ADD_WWS_TIPWIPE=1,VEH_SIG_ADD_WWS_IDLE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 TurnSignal_t              /* Turn signal switch state @min: 0 @max:4 @values: enum { VEH_SIG_ADD_TURN_SIG_NEUTRAL=3,VEH_SIG_ADD_TURN_SIG_UNKNOWN=0,VEH_SIG_ADD_TURN_SIG_RIGHT=2,VEH_SIG_ADD_TURN_SIG_LEFT=1,VEH_SIG_ADD_TURN_SIG_BOTH=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 SpeedUnit_t               /* ENUM speedmeter speed unit @min: 0 @max:2 @values: enum { VEH_SIG_ADD_SPEEDO_UNIT_MPH=2,VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN=0,VEH_SIG_ADD_SPEEDO_UNIT_KMH=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 TrailerConnection_t       /* No trailer detected, Trailer detected, not defined, Trailer signal is not available @min: 0 @max:3 @values: enum { VEH_SIG_ADD_TRLR_OK=1,VEH_SIG_ADD_TRLR_NDEF2=2,VEH_SIG_ADD_TRLR_NO_DETECT=0,VEH_SIG_ADD_TRLR_SNA=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 IgnitionSwitch_t          /* Ignition lockI, gnition off, Ignition accessory (15r) , Ignition on (15) , Ignition start (50) @min: 0 @max:5 @values: enum { VEH_SIG_ADD_IGN_ON=4,VEH_SIG_ADD_IGN_START=5,VEH_SIG_ADD_IGN_LOCK=0,VEH_SIG_ADD_IGN_OFF=1,VEH_SIG_ADD_IGN_ACC=2,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint8 TransmissionGear_t        /* Indicates current used gear position @min: 0 @max:12 @values: enum { DYN_GEAR_PARK_GEAR=11,DYN_GEAR_SIXTH_GEAR=6,DYN_GEAR_FIRST_GEAR=1,DYN_GEAR_FIFTH_GEAR=5,DYN_GEAR_SECOND_GEAR=2,DYN_GEAR_EIGHTH_GEAR=8,DYN_GEAR_NEUTRAL_GEAR=0,DYN_GEAR_POWER_FREE=12,DYN_GEAR_THIRD_GEAR=3,DYN_GEAR_REVERSE_GEAR=10,DYN_GEAR_SEVENTH_GEAR=7,DYN_GEAR_NINTH_GEAR=9,DYN_GEAR_FOURTH_GEAR=4,} */	/* [Satisfies_rte sws 1188] */;

  /* typedef SigMainState_t */
  const VDYIoStateTypes_t VDY_SIN_POS_YWR         = (0);
  const VDYIoStateTypes_t VDY_SIN_POS_YWR_TEMP    = (1);
  const VDYIoStateTypes_t VDY_SIN_POS_SWA         = (2);
  const VDYIoStateTypes_t VDY_SIN_POS_LATA        = (3);
  const VDYIoStateTypes_t VDY_SIN_POS_WVEL_FL     = (4);
  const VDYIoStateTypes_t VDY_SIN_POS_WVEL_FR     = (5);
  const VDYIoStateTypes_t VDY_SIN_POS_WVEL_RL     = (6);
  const VDYIoStateTypes_t VDY_SIN_POS_WVEL_RR     = (7);
  const VDYIoStateTypes_t VDY_SIN_POS_YWRINT      = (8);
  const VDYIoStateTypes_t VDY_SIN_POS_YWRINT_TEMP = (9);
  const VDYIoStateTypes_t VDY_SIN_POS_LONGA       = (10);
  const VDYIoStateTypes_t VDY_SIN_POS_RSTA        = (11);
  const VDYIoStateTypes_t VDY_SIN_POS_VEHVEL_EXT  = (12);
  const VDYIoStateTypes_t VDY_SIN_POS_VEHACL_EXT  = (13);
  const VDYIoStateTypes_t VDY_SIN_POS_WDIR_FL     = (14);
  const VDYIoStateTypes_t VDY_SIN_POS_WDIR_FR     = (15);
  const VDYIoStateTypes_t VDY_SIN_POS_WDIR_RL     = (16);
  const VDYIoStateTypes_t VDY_SIN_POS_WDIR_RR     = (17);
  const VDYIoStateTypes_t VDY_SIN_POS_WTCKS_FL    = (18);
  const VDYIoStateTypes_t VDY_SIN_POS_WTCKS_FR    = (19);
  const VDYIoStateTypes_t VDY_SIN_POS_WTCKS_RL    = (20);
  const VDYIoStateTypes_t VDY_SIN_POS_WTCKS_RR    = (21);
  const VDYIoStateTypes_t VDY_SIN_POS_GEAR        = (22);
  const VDYIoStateTypes_t VDY_SIN_POS_BRAKE       = (23);
  const VDYIoStateTypes_t VDY_SIN_POS_PBRK        = (24);
  const VDYIoStateTypes_t VDY_SIN_POS_VDIR        = (25);
  const VDYIoStateTypes_t VDY_SIN_POS_VMOT        = (26);
  const VDYIoStateTypes_t VDY_SIN_POS_DUMMY       = (27);
  const VDYIoStateTypes_t VDY_SIN_POS_CRV         = (28);
  const VDYIoStateTypes_t VDY_SIN_POS_SSA         = (29);
  const VDYIoStateTypes_t VDY_SIN_POS_MAX         = (32);

  /* typedef LongDirState_t */
  const LongDirState_t VDY_LONG_DIR_VOID = (0);
  const LongDirState_t VDY_LONG_DIR_FWD  = (1);
  const LongDirState_t VDY_LONG_DIR_RWD  = (2);

  /* typedef ActGearPos_t */
  const ActGearPos_t ACT_GEAR_POS_NEUTRAL = (0);
  const ActGearPos_t ACT_GEAR_POS_PARKING = (1);
  const ActGearPos_t ACT_GEAR_POS_FORWARD = (2);
  const ActGearPos_t ACT_GEAR_POS_REVERSE = (3);

  /* typedef ParkBrakeState_t */
  const ParkBrakeState_t STAT_INACTIVE = (0);
  const ParkBrakeState_t STAT_ACTIVE   = (1);

  /* typedef VehLongMotStateExt_t */
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_ROLLING     = (0);
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_FAST_STST   = (1);
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_SECURE_STST = (2);

  /* typedef SigAddState_t */
  const VDYIoStateTypes_t VEH_SIG_ADD_ENV_TEMP            = (0);
  const VDYIoStateTypes_t VEH_SIG_ADD_WIPER_STATE         = (1);
  const VDYIoStateTypes_t VEH_SIG_ADD_WIPER_STAGE         = (2);
  const VDYIoStateTypes_t VEH_SIG_ADD_WIPER_OUT_PARK_POS  = (3);
  const VDYIoStateTypes_t VEH_SIG_ADD_WIPER_WASHER_FRONT  = (4);
  const VDYIoStateTypes_t VEH_SIG_ADD_RAIN_SENSOR         = (5);
  const VDYIoStateTypes_t VEH_SIG_ADD_TURN_SIGNAL         = (6);
  const VDYIoStateTypes_t VEH_SIG_ADD_FOG_LAMP_FRONT      = (7);
  const VDYIoStateTypes_t VEH_SIG_ADD_FOG_LAMP_REAR       = (8);
  const VDYIoStateTypes_t VEH_SIG_ADD_ROAD_WHL_ANG_FR     = (9);
  const VDYIoStateTypes_t VEH_SIG_ADD_ROAD_WHL_ANG_RE     = (10);
  const VDYIoStateTypes_t VEH_SIG_ADD_ODOMETER            = (11);
  const VDYIoStateTypes_t VEH_SIG_ADD_GAS_PEDAL_POS       = (12);
  const VDYIoStateTypes_t VEH_SIG_ADD_KICK_DOWN           = (13);
  const VDYIoStateTypes_t VEH_SIG_ADD_BRAKE_PEDAL_PRESSED = (14);
  const VDYIoStateTypes_t VEH_SIG_ADD_DRIVER_TIRED        = (15);
  const VDYIoStateTypes_t VEH_SIG_ADD_SPEED_UNIT          = (16);
  const VDYIoStateTypes_t VEH_SIG_ADD_SPEEDO_SPEED        = (17);
  const VDYIoStateTypes_t VEH_SIG_ADD_TRAILER_CON         = (18);
  const VDYIoStateTypes_t VEH_SIG_ADD_IGN_SWITCH          = (19);
  const VDYIoStateTypes_t VEH_SIG_ADD_MAX                 = (20);

  /* typedef WiperState_t */
  const WiperState_t VEH_SIG_ADD_WIPER_STATE_INACTIVE = (0);
  const WiperState_t VEH_SIG_ADD_WIPER_STATE_ACTIVE   = (1);

  /* typedef WiperStage_t */
  const WiperStage_t VEH_SIG_ADD_WIPER_OFF       = (0);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL1 = (1);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL2 = (2);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL3 = (3);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL4 = (4);
  const WiperStage_t VEH_SIG_ADD_WIPER_STAGE1    = (5);
  const WiperStage_t VEH_SIG_ADD_WIPER_STAGE2    = (6);

  /* typedef WiperWasherFrontState_t */
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_IDLE    = (0);
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_TIPWIPE = (1);
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_WASH    = (2);

  /* typedef TurnSignal_t */
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_UNKNOWN = (0);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_LEFT    = (1);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_RIGHT   = (2);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_NEUTRAL = (3);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_BOTH    = (4);

  /* typedef SpeedUnit_t */
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN = (0);
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_KMH     = (1);
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_MPH     = (2);

  /* typedef TrailerConnection_t */
  const TrailerConnection_t VEH_SIG_ADD_TRLR_NO_DETECT = (0);
  const TrailerConnection_t VEH_SIG_ADD_TRLR_OK        = (1);
  const TrailerConnection_t VEH_SIG_ADD_TRLR_NDEF2     = (2);
  const TrailerConnection_t VEH_SIG_ADD_TRLR_SNA       = (3);

  /* typedef VehSigBrakeStatePos_t */
  const VDYIoStateTypes_t VEH_SIG_BRAKE_ABS            = (0);
  const VDYIoStateTypes_t VEH_SIG_BRAKE_TSC	           = (1);
  const VDYIoStateTypes_t VEH_SIG_BRAKE_MAX	           = (2);

  /* typedef IgnitionSwitch_t */
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_LOCK   = (0);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_OFF    = (1);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_ACC    = (2);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_ON     = (4);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_START  = (5);

  /* typedef VehSigPowertrainStatePos_t */
  const VDYIoStateTypes_t VEH_SIG_POWERTRAIN_ACTUALGEAR	    = (0);
  const VDYIoStateTypes_t VEH_SIG_POWERTRAIN_TARGETGEAR	    = (1);
  const VDYIoStateTypes_t VEH_SIG_POWERTRAIN_ENGINE_RUNNING	= (2);
  const VDYIoStateTypes_t VEH_SIG_POWERTRAIN_MAX	          = (3);

  /* typedef TransmissionGear_t */
  const TransmissionGear_t DYN_GEAR_NEUTRAL_GEAR = (0);
  const TransmissionGear_t DYN_GEAR_FIRST_GEAR   = (1);
  const TransmissionGear_t DYN_GEAR_SECOND_GEAR  = (2);
  const TransmissionGear_t DYN_GEAR_THIRD_GEAR   = (3);
  const TransmissionGear_t DYN_GEAR_FOURTH_GEAR  = (4);
  const TransmissionGear_t DYN_GEAR_FIFTH_GEAR   = (5);
  const TransmissionGear_t DYN_GEAR_SIXTH_GEAR   = (6);
  const TransmissionGear_t DYN_GEAR_SEVENTH_GEAR = (7);
  const TransmissionGear_t DYN_GEAR_EIGHTH_GEAR  = (8);
  const TransmissionGear_t DYN_GEAR_NINTH_GEAR   = (9);
  const TransmissionGear_t DYN_GEAR_REVERSE_GEAR = (10);
  const TransmissionGear_t DYN_GEAR_PARK_GEAR    = (11);
  const TransmissionGear_t DYN_GEAR_POWER_FREE   = (12);
  
  typedef VDYIoStateTypes_t State_array_t_0[VDY_SIN_POS_MAX];/* State of the vehicle input signals @name: Status @values: struct VDYInSignalState */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t State_array_t_1[VEH_SIG_ADD_MAX];/* State of the add vehicle input signals @name: Status @values: struct VehSignalAddState */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t State_array_t_2[VEH_SIG_POWERTRAIN_MAX];/* State of the powertrain vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigPowertrainStatePos_t */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t State_array_t_3[VEH_SIG_BRAKE_MAX];/* State of the brake vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigBrakeStatePos_t */	/* [Satisfies_rte sws 1189] */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  AlgoDataTimeStamp_t uiTimeStamp;
 	  AlgoCycleCounter_t uiMeasurementCounter;
 	  AlgoCycleCounter_t uiCycleCounter;
 	  AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  TransmissionGear_t ActualGear;
 	  TransmissionGear_t TargetGear;
 	  boolean EngineRunning;
 	  State_array_t_2 State;
  } PowerTrain_t;			

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  boolean ABSCtrl;
 	  boolean TCSCtrl;
 	  State_array_t_3 State;
  } Brake_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  State_array_t_1 State;
 	  float EnvTemp;
 	  WiperState_t WiperState;
 	  WiperStage_t WiperStage;
 	  boolean WiperOutParkPos;
 	  WiperWasherFrontState_t WiperWasherFrontState;
 	  boolean RainSensor;
 	  TurnSignal_t TurnSignal;
 	  boolean FogLampFront;
 	  boolean FogLampRear;
 	  float RoadWhlAngFr;
 	  float RoadWhlAngRe;
 	  float Odometer;
 	  float GasPedalPos;
 	  boolean KickDown;
 	  boolean BrakePedalPressed;
 	  boolean DriverTired;
 	  SpeedUnit_t SpeedUnit;
 	  float SpeedoSpeed;
 	  TrailerConnection_t TrailerConnection;
 	  IgnitionSwitch_t IgnitionSwitch;
  } VehSigAdd_t;			/* Additional Vehicle dynacmis sensor signals */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  State_array_t_0 State;
 	  float YawRate;
 	  float YawRateTemp;
 	  float StWheelAngle;
 	  float LatAccel;
 	  float WhlVelFrLeft;
 	  float WhlVelFrRight;
 	  float WhlVelReLeft;
 	  float WhlVelReRight;
 	  float YawRateInt;
 	  float YawRateIntTemp;
 	  float LongAccel;
 	  float RearWhlAngle;
 	  float VehVelocityExt;
 	  float VehLongAccelExt;
 	  LongDirState_t WhlDirFrLeft;
 	  LongDirState_t WhlDirFrRight;
 	  LongDirState_t WhlDirReLeft;
 	  LongDirState_t WhlDirReRight;
 	  unsigned char WhlTicksDevFrLeft;
 	  unsigned char WhlTicksDevFrRight;
 	  unsigned char WhlTicksDevReLeft;
 	  unsigned char WhlTicksDevReRight;
 	  ActGearPos_t ActGearPos;
 	  unsigned short BrakeActLevel;
 	  ParkBrakeState_t ParkBrakeState;
 	  LongDirState_t VehLongDirExt;
 	  VehLongMotStateExt_t VehLongMotStateExt;
 	  float CurveC0Ext;
 	  float CurveC1Ext;
 	  float SideSlipAngleExt;
  } VehSigMain_t;			/* Main Vehicle dynamics sensor signals */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
	  AlgoInterfaceVersionNumber_t uiVersionNumber;
 	  SignalHeader_t sSigHeader;
 	  VehSigMain_t VehSigMain;
 	  VehSigAdd_t VehSigAdd;
 	  PowerTrain_t PowerTrain;
 	  Brake_t Brake;
  } VehSig_t;			/* Main Vehicle dynamics sensor signals @vaddr:0x20300050 @vaddr_defs: VDY_MEAS_ID_VEH_SIG @cycleid:vdy_in_cycle_id @vname:VehSig */
}



namespace VehSigV9
{
  /*! External interface states version 8 and higher */
  const uint8 VEH_SIG_IO_STATE_VALID = 0U;
  const uint8 VEH_SIG_IO_STATE_INVALID = 1U;
  const uint8 VEH_SIG_IO_STATE_NOTAVAIL = 2U;
  const uint8 VEH_SIG_IO_STATE_DECREASED = 3U;
  const uint8 VEH_SIG_IO_STATE_SUBSTITUE = 4U;
  const uint8 VDY_IO_STATE_INPLAUSIBLE   = 5U;
  const uint8 VEH_SIG_IO_STATE_INIT = 15U;
  const uint8 VEH_SIG_IO_STATE_MAX = 255U;

  typedef uint8 bool8                     			/* [Satisfies_rte sws 1188] */;

  typedef unsigned char VDYIoStateTypes_t         /* vdy io states @min: 0 @max:255 @values: enum { VDY_IO_STATE_VALID=0,VDY_IO_STATE_SUBSTITUE=4,VDY_IO_STATE_INIT=15,VDY_IO_STATE_DECREASED=3,VDY_IO_STATE_INVALID=1,VDY_IO_STATE_NOTAVAIL=2,VDY_IO_STATE_INPLAUSIBLE=5,VDY_IO_STATE_MAX=255,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint8 LongDirState_t            /* @min: 0 @max:2 @values: enum { VDY_LONG_DIR_RWD=2,VDY_LONG_DIR_VOID=0,VDY_LONG_DIR_FWD=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 ActGearPos_t              /* VDY_SIN_POS_GEAR @min: 0 @max:3 @values: enum { ACT_GEAR_POS_NEUTRAL=0,ACT_GEAR_POS_FORWARD=2,ACT_GEAR_POS_PARKING=1,ACT_GEAR_POS_REVERSE=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 ParkBrakeState_t          /* VDY_SIN_POS_PBRK @min: 0 @max:1 @values: enum { STAT_ACTIVE=1,STAT_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 VehLongMotStateExt_t      /* VDY_SIN_POS_VMOT @min: 0 @max:2 @values: enum { VDY_VEH_MOT_STATE_ROLLING=0,VDY_VEH_MOT_STATE_SECURE_STST=2,VDY_VEH_MOT_STATE_FAST_STST=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint8 WiperState_t              /* Wiper blades activity @min: 0 @max:1 @values: enum { VEH_SIG_ADD_WIPER_STATE_ACTIVE=1,VEH_SIG_ADD_WIPER_STATE_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 WiperStage_t              /* Wiper switch position @min: 0 @max:6 @values: enum { VEH_SIG_ADD_WIPER_INTERVAL1=1,VEH_SIG_ADD_WIPER_INTERVAL2=2,VEH_SIG_ADD_WIPER_INTERVAL3=3,VEH_SIG_ADD_WIPER_INTERVAL4=4,VEH_SIG_ADD_WIPER_OFF=0,VEH_SIG_ADD_WIPER_STAGE1=5,VEH_SIG_ADD_WIPER_STAGE2=6,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 WiperWasherFrontState_t   /* Tip-wipe / washer state @min: 0 @max:2 @values: enum { VEH_SIG_ADD_WWS_WASH=2,VEH_SIG_ADD_WWS_TIPWIPE=1,VEH_SIG_ADD_WWS_IDLE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 TurnSignal_t              /* Turn signal switch state @min: 0 @max:4 @values: enum { VEH_SIG_ADD_TURN_SIG_NEUTRAL=3,VEH_SIG_ADD_TURN_SIG_UNKNOWN=0,VEH_SIG_ADD_TURN_SIG_RIGHT=2,VEH_SIG_ADD_TURN_SIG_LEFT=1,VEH_SIG_ADD_TURN_SIG_BOTH=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 SpeedUnit_t               /* ENUM speedmeter speed unit @min: 0 @max:2 @values: enum { VEH_SIG_ADD_SPEEDO_UNIT_MPH=2,VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN=0,VEH_SIG_ADD_SPEEDO_UNIT_KMH=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 VDYTrailerConnection_t    /* @min: 0 @max:3 @values: enum { VEH_SIG_ADD_TRLR_OK=1,VEH_SIG_ADD_TRLR_NDEF2=2,VEH_SIG_ADD_TRLR_NO_DETECT=0,VEH_SIG_ADD_TRLR_SNA=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 IgnitionSwitch_t          /* Ignition lockI, gnition off, Ignition accessory (15r) , Ignition on (15) , Ignition start (50) @min: 0 @max:5 @values: enum { VEH_SIG_ADD_IGN_ON=4,VEH_SIG_ADD_IGN_START=5,VEH_SIG_ADD_IGN_LOCK=0,VEH_SIG_ADD_IGN_OFF=1,VEH_SIG_ADD_IGN_ACC=2,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint8 TransmissionGear_t        /* Indicates current used gear position @min: 0 @max:12 @values: enum { DYN_GEAR_PARK_GEAR=11,DYN_GEAR_SIXTH_GEAR=6,DYN_GEAR_FIRST_GEAR=1,DYN_GEAR_FIFTH_GEAR=5,DYN_GEAR_SECOND_GEAR=2,DYN_GEAR_EIGHTH_GEAR=8,DYN_GEAR_NEUTRAL_GEAR=0,DYN_GEAR_POWER_FREE=12,DYN_GEAR_THIRD_GEAR=3,DYN_GEAR_REVERSE_GEAR=10,DYN_GEAR_SEVENTH_GEAR=7,DYN_GEAR_NINTH_GEAR=9,DYN_GEAR_FOURTH_GEAR=4,} */	/* [Satisfies_rte sws 1188] */;

  /* typedef SigMainState_t */
  const VDYIoStateTypes_t VDY_SIN_POS_YWR         = (0);
  const VDYIoStateTypes_t VDY_SIN_POS_YWR_TEMP    = (1);
  const VDYIoStateTypes_t VDY_SIN_POS_SWA         = (2);
  const VDYIoStateTypes_t VDY_SIN_POS_LATA        = (3);
  const VDYIoStateTypes_t VDY_SIN_POS_WVEL_FL     = (4);
  const VDYIoStateTypes_t VDY_SIN_POS_WVEL_FR     = (5);
  const VDYIoStateTypes_t VDY_SIN_POS_WVEL_RL     = (6);
  const VDYIoStateTypes_t VDY_SIN_POS_WVEL_RR     = (7);
  const VDYIoStateTypes_t VDY_SIN_POS_YWRINT      = (8);
  const VDYIoStateTypes_t VDY_SIN_POS_YWRINT_TEMP = (9);
  const VDYIoStateTypes_t VDY_SIN_POS_LONGA       = (10);
  const VDYIoStateTypes_t VDY_SIN_POS_RSTA        = (11);
  const VDYIoStateTypes_t VDY_SIN_POS_VEHVEL_EXT  = (12);
  const VDYIoStateTypes_t VDY_SIN_POS_VEHACL_EXT  = (13);
  const VDYIoStateTypes_t VDY_SIN_POS_WDIR_FL     = (14);
  const VDYIoStateTypes_t VDY_SIN_POS_WDIR_FR     = (15);
  const VDYIoStateTypes_t VDY_SIN_POS_WDIR_RL     = (16);
  const VDYIoStateTypes_t VDY_SIN_POS_WDIR_RR     = (17);
  const VDYIoStateTypes_t VDY_SIN_POS_WTCKS_FL    = (18);
  const VDYIoStateTypes_t VDY_SIN_POS_WTCKS_FR    = (19);
  const VDYIoStateTypes_t VDY_SIN_POS_WTCKS_RL    = (20);
  const VDYIoStateTypes_t VDY_SIN_POS_WTCKS_RR    = (21);
  const VDYIoStateTypes_t VDY_SIN_POS_GEAR        = (22);
  const VDYIoStateTypes_t VDY_SIN_POS_BRAKE       = (23);
  const VDYIoStateTypes_t VDY_SIN_POS_PBRK        = (24);
  const VDYIoStateTypes_t VDY_SIN_POS_VDIR        = (25);
  const VDYIoStateTypes_t VDY_SIN_POS_VMOT        = (26);
  const VDYIoStateTypes_t VDY_SIN_POS_DUMMY       = (27);
  const VDYIoStateTypes_t VDY_SIN_POS_CRV         = (28);
  const VDYIoStateTypes_t VDY_SIN_POS_SSA         = (29);
  const VDYIoStateTypes_t VDY_SIN_POS_MAX         = (32);

  /* typedef LongDirState_t */
  const LongDirState_t VDY_LONG_DIR_VOID = (0);
  const LongDirState_t VDY_LONG_DIR_FWD  = (1);
  const LongDirState_t VDY_LONG_DIR_RWD  = (2);

  /* typedef ActGearPos_t */
  const ActGearPos_t ACT_GEAR_POS_NEUTRAL = (0);
  const ActGearPos_t ACT_GEAR_POS_PARKING = (1);
  const ActGearPos_t ACT_GEAR_POS_FORWARD = (2);
  const ActGearPos_t ACT_GEAR_POS_REVERSE = (3);

  /* typedef ParkBrakeState_t */
  const ParkBrakeState_t STAT_INACTIVE = (0);
  const ParkBrakeState_t STAT_ACTIVE   = (1);

  /* typedef VehLongMotStateExt_t */
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_ROLLING     = (0);
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_FAST_STST   = (1);
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_SECURE_STST = (2);

  /* typedef SigAddState_t */
  const VDYIoStateTypes_t VEH_SIG_ADD_ENV_TEMP            = (0);
  const VDYIoStateTypes_t VEH_SIG_ADD_WIPER_STATE         = (1);
  const VDYIoStateTypes_t VEH_SIG_ADD_WIPER_STAGE         = (2);
  const VDYIoStateTypes_t VEH_SIG_ADD_WIPER_OUT_PARK_POS  = (3);
  const VDYIoStateTypes_t VEH_SIG_ADD_WIPER_WASHER_FRONT  = (4);
  const VDYIoStateTypes_t VEH_SIG_ADD_RAIN_SENSOR         = (5);
  const VDYIoStateTypes_t VEH_SIG_ADD_TURN_SIGNAL         = (6);
  const VDYIoStateTypes_t VEH_SIG_ADD_FOG_LAMP_FRONT      = (7);
  const VDYIoStateTypes_t VEH_SIG_ADD_FOG_LAMP_REAR       = (8);
  const VDYIoStateTypes_t VEH_SIG_ADD_ROAD_WHL_ANG_FR     = (9);
  const VDYIoStateTypes_t VEH_SIG_ADD_ROAD_WHL_ANG_RE     = (10);
  const VDYIoStateTypes_t VEH_SIG_ADD_ODOMETER            = (11);
  const VDYIoStateTypes_t VEH_SIG_ADD_GAS_PEDAL_POS       = (12);
  const VDYIoStateTypes_t VEH_SIG_ADD_KICK_DOWN           = (13);
  const VDYIoStateTypes_t VEH_SIG_ADD_BRAKE_PEDAL_PRESSED = (14);
  const VDYIoStateTypes_t VEH_SIG_ADD_DRIVER_TIRED        = (15);
  const VDYIoStateTypes_t VEH_SIG_ADD_SPEED_UNIT          = (16);
  const VDYIoStateTypes_t VEH_SIG_ADD_SPEEDO_SPEED        = (17);
  const VDYIoStateTypes_t VEH_SIG_ADD_TRAILER_CON         = (18);
  const VDYIoStateTypes_t VEH_SIG_ADD_IGN_SWITCH          = (19);
  const VDYIoStateTypes_t VEH_SIG_ADD_MAX                 = (28);

  /* typedef WiperState_t */
  const WiperState_t VEH_SIG_ADD_WIPER_STATE_INACTIVE = (0);
  const WiperState_t VEH_SIG_ADD_WIPER_STATE_ACTIVE   = (1);

  /* typedef WiperStage_t */
  const WiperStage_t VEH_SIG_ADD_WIPER_OFF       = (0);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL1 = (1);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL2 = (2);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL3 = (3);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL4 = (4);
  const WiperStage_t VEH_SIG_ADD_WIPER_STAGE1    = (5);
  const WiperStage_t VEH_SIG_ADD_WIPER_STAGE2    = (6);

  /* typedef WiperWasherFrontState_t */
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_IDLE    = (0);
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_TIPWIPE = (1);
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_WASH    = (2);

  /* typedef TurnSignal_t */
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_UNKNOWN = (0);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_LEFT    = (1);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_RIGHT   = (2);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_NEUTRAL = (3);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_BOTH    = (4);

  /* typedef SpeedUnit_t */
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN = (0);
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_KMH     = (1);
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_MPH     = (2);

  /* typedef VDYTrailerConnection_t */
  const VDYTrailerConnection_t VEH_SIG_ADD_TRLR_NO_DETECT = (0);
  const VDYTrailerConnection_t VEH_SIG_ADD_TRLR_OK        = (1);
  const VDYTrailerConnection_t VEH_SIG_ADD_TRLR_NDEF2     = (2);
  const VDYTrailerConnection_t VEH_SIG_ADD_TRLR_SNA       = (3);

  /* typedef VehSigBrakeStatePos_t */
  const VDYIoStateTypes_t VEH_SIG_BRAKE_ABS            = (0);
  const VDYIoStateTypes_t VEH_SIG_BRAKE_TSC	           = (1);
  const VDYIoStateTypes_t VEH_SIG_BRAKE_MAX	           = (2);

  /* typedef IgnitionSwitch_t */
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_LOCK   = (0);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_OFF    = (1);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_ACC    = (2);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_ON     = (4);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_START  = (5);

  /* typedef VehSigPowertrainStatePos_t */
  const VDYIoStateTypes_t VEH_SIG_POWERTRAIN_ACTUALGEAR	    = (0);
  const VDYIoStateTypes_t VEH_SIG_POWERTRAIN_TARGETGEAR	    = (1);
  const VDYIoStateTypes_t VEH_SIG_POWERTRAIN_ENGINE_RUNNING	= (2);
  const VDYIoStateTypes_t VEH_SIG_POWERTRAIN_MAX	          = (4);

  /* typedef TransmissionGear_t */
  const TransmissionGear_t DYN_GEAR_NEUTRAL_GEAR = (0);
  const TransmissionGear_t DYN_GEAR_FIRST_GEAR   = (1);
  const TransmissionGear_t DYN_GEAR_SECOND_GEAR  = (2);
  const TransmissionGear_t DYN_GEAR_THIRD_GEAR   = (3);
  const TransmissionGear_t DYN_GEAR_FOURTH_GEAR  = (4);
  const TransmissionGear_t DYN_GEAR_FIFTH_GEAR   = (5);
  const TransmissionGear_t DYN_GEAR_SIXTH_GEAR   = (6);
  const TransmissionGear_t DYN_GEAR_SEVENTH_GEAR = (7);
  const TransmissionGear_t DYN_GEAR_EIGHTH_GEAR  = (8);
  const TransmissionGear_t DYN_GEAR_NINTH_GEAR   = (9);
  const TransmissionGear_t DYN_GEAR_REVERSE_GEAR = (10);
  const TransmissionGear_t DYN_GEAR_PARK_GEAR    = (11);
  const TransmissionGear_t DYN_GEAR_POWER_FREE   = (12);


  typedef VDYIoStateTypes_t         	State_array_t_1[VDY_SIN_POS_MAX];/* State of the main vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigMainStatePos_t */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t         	State_array_t_2[VEH_SIG_ADD_MAX];/* State of the add vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigAddStatePos_t */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t         	State_array_t_3[VEH_SIG_POWERTRAIN_MAX];/* State of the powertrain vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigPowertrainStatePos_t */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t         	State_array_t_4[VEH_SIG_BRAKE_MAX];/* State of the brake vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigBrakeStatePos_t */	/* [Satisfies_rte sws 1189] */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    TransmissionGear_t ActualGear;
    TransmissionGear_t TargetGear;
    boolean EngineRunning;
    unsigned char FillByte;
    State_array_t_3 State;
  } PowerTrain_t;	

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    boolean ABSCtrl;
    boolean TCSCtrl;
    State_array_t_4 State;
  } Brake_t;			/* Sensor specific parameters */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t_2 State;
    float EnvTemp;
    WiperState_t WiperState;
    WiperStage_t WiperStage;
    boolean WiperOutParkPos;
    WiperWasherFrontState_t WiperWasherFrontState;
    boolean RainSensor;
    TurnSignal_t TurnSignal;
    boolean FogLampFront;
    boolean FogLampRear;
    float RoadWhlAngFr;
    float RoadWhlAngRe;
    float Odometer;
    float GasPedalPos;
    boolean KickDown;
    boolean BrakePedalPressed;
    boolean DriverTired;
    SpeedUnit_t SpeedUnit;
    float SpeedoSpeed;
    VDYTrailerConnection_t TrailerConnection;
    VDYTrailerConnection_t TrailerConnBeforeShutDown;
    unsigned char TrailerLengthInput;
    unsigned char ParkAidDet_L;
    unsigned char ParkAidDet_CL;
    unsigned char ParkAidDet_CR;
    unsigned char ParkAidDet_R;
    IgnitionSwitch_t IgnitionSwitch;
  } VehSigAdd_t;			/* Additional Vehicle dynacmis sensor signals */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    State_array_t_1 State;
    float YawRate;
    float YawRateTemp;
    float StWheelAngle;
    float LatAccel;
    float WhlVelFrLeft;
    float WhlVelFrRight;
    float WhlVelReLeft;
    float WhlVelReRight;
    float YawRateInt;
    float YawRateIntTemp;
    float LongAccel;
    float RearWhlAngle;
    float VehVelocityExt;
    float VehLongAccelExt;
    LongDirState_t WhlDirFrLeft;
    LongDirState_t WhlDirFrRight;
    LongDirState_t WhlDirReLeft;
    LongDirState_t WhlDirReRight;
    unsigned char WhlTicksDevFrLeft;
    unsigned char WhlTicksDevFrRight;
    unsigned char WhlTicksDevReLeft;
    unsigned char WhlTicksDevReRight;
    ActGearPos_t ActGearPos;
    unsigned short BrakeActLevel;
    ParkBrakeState_t ParkBrakeState;
    LongDirState_t VehLongDirExt;
    VehLongMotStateExt_t VehLongMotStateExt;
    float CurveC0Ext;
    float CurveC1Ext;
    float SideSlipAngleExt;
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

}

namespace VehSigV10
{
  /*! External interface states version 8 and higher */
  const uint8 VEH_SIG_IO_STATE_VALID = 0U;
  const uint8 VEH_SIG_IO_STATE_INVALID = 1U;
  const uint8 VEH_SIG_IO_STATE_NOTAVAIL = 2U;
  const uint8 VEH_SIG_IO_STATE_DECREASED = 3U;
  const uint8 VEH_SIG_IO_STATE_SUBSTITUE = 4U;
  const uint8 VDY_IO_STATE_INPLAUSIBLE   = 5U;
  const uint8 VEH_SIG_IO_STATE_INIT = 15U;
  const uint8 VEH_SIG_IO_STATE_MAX = 255U;

  typedef uint8 bool8                     			/* [Satisfies_rte sws 1188] */;

  typedef uint8 VDYIoStateTypes_t         /* vdy io states @min: 0 @max:255 @values: enum { VDY_IO_STATE_VALID=0,VDY_IO_STATE_SUBSTITUE=4,VDY_IO_STATE_INIT=15,VDY_IO_STATE_DECREASED=3,VDY_IO_STATE_INVALID=1,VDY_IO_STATE_NOTAVAIL=2,VDY_IO_STATE_INPLAUSIBLE=5,VDY_IO_STATE_MAX=255,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint8 LongDirState_t            /* @min: 0 @max:2 @values: enum { VDY_LONG_DIR_RWD=2,VDY_LONG_DIR_VOID=0,VDY_LONG_DIR_FWD=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 ActGearPos_t              /* VDY_SIN_POS_GEAR @min: 0 @max:3 @values: enum { ACT_GEAR_POS_NEUTRAL=0,ACT_GEAR_POS_FORWARD=2,ACT_GEAR_POS_PARKING=1,ACT_GEAR_POS_REVERSE=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 ParkBrakeState_t          /* VDY_SIN_POS_PBRK @min: 0 @max:1 @values: enum { STAT_ACTIVE=1,STAT_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 VehLongMotStateExt_t      /* VDY_SIN_POS_VMOT @min: 0 @max:2 @values: enum { VDY_VEH_MOT_STATE_ROLLING=0,VDY_VEH_MOT_STATE_SECURE_STST=2,VDY_VEH_MOT_STATE_FAST_STST=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint8 WiperState_t              /* Wiper blades activity @min: 0 @max:1 @values: enum { VEH_SIG_ADD_WIPER_STATE_ACTIVE=1,VEH_SIG_ADD_WIPER_STATE_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 WiperStage_t              /* Wiper switch position @min: 0 @max:6 @values: enum { VEH_SIG_ADD_WIPER_INTERVAL1=1,VEH_SIG_ADD_WIPER_INTERVAL2=2,VEH_SIG_ADD_WIPER_INTERVAL3=3,VEH_SIG_ADD_WIPER_INTERVAL4=4,VEH_SIG_ADD_WIPER_OFF=0,VEH_SIG_ADD_WIPER_STAGE1=5,VEH_SIG_ADD_WIPER_STAGE2=6,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 WiperWasherFrontState_t   /* Tip-wipe / washer state @min: 0 @max:2 @values: enum { VEH_SIG_ADD_WWS_WASH=2,VEH_SIG_ADD_WWS_TIPWIPE=1,VEH_SIG_ADD_WWS_IDLE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 TurnSignal_t              /* Turn signal switch state @min: 0 @max:4 @values: enum { VEH_SIG_ADD_TURN_SIG_NEUTRAL=3,VEH_SIG_ADD_TURN_SIG_UNKNOWN=0,VEH_SIG_ADD_TURN_SIG_RIGHT=2,VEH_SIG_ADD_TURN_SIG_LEFT=1,VEH_SIG_ADD_TURN_SIG_BOTH=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 SpeedUnit_t               /* ENUM speedmeter speed unit @min: 0 @max:2 @values: enum { VEH_SIG_ADD_SPEEDO_UNIT_MPH=2,VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN=0,VEH_SIG_ADD_SPEEDO_UNIT_KMH=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 VDYTrailerConnection_t    /* @min: 0 @max:3 @values: enum { VEH_SIG_ADD_TRLR_OK=1,VEH_SIG_ADD_TRLR_NDEF2=2,VEH_SIG_ADD_TRLR_NO_DETECT=0,VEH_SIG_ADD_TRLR_SNA=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 IgnitionSwitch_t          /* Ignition lockI, gnition off, Ignition accessory (15r) , Ignition on (15) , Ignition start (50) @min: 0 @max:5 @values: enum { VEH_SIG_ADD_IGN_ON=4,VEH_SIG_ADD_IGN_START=5,VEH_SIG_ADD_IGN_LOCK=0,VEH_SIG_ADD_IGN_OFF=1,VEH_SIG_ADD_IGN_ACC=2,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 eSuspensionSystem_t       /* Availability of active suspension:
  0: no active suspension available
  1: active suspension available @min: 0 @max:1 @values: enum { VEH_SIG_ADD_ACTIVE_SUSPENSION=1,VEH_SIG_ADD_NO_ACTIVE_SUSPENSION=0,} */	/* [Satisfies_rte sws 1188] */;
  
  typedef uint8 eHeightLevel_t            /* Height adjustment value the car:
  0: no height level available
  1: height level normal
  2: height level low
  3: height level high @min: 0 @max:4 @values: enum { VEH_SIG_ADD_HEIGHT_LVL_HIGH=4,VEH_SIG_ADD_HEIGHT_LVL_LOW=2,VEH_SIG_ADD_NO_HEIGHT_LVL=0,VEH_SIG_ADD_HEIGHT_LVL_NORMAL=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint8 TransmissionGear_t        /* Indicates current used gear position @min: 0 @max:12 @values: enum { DYN_GEAR_PARK_GEAR=11,DYN_GEAR_SIXTH_GEAR=6,DYN_GEAR_FIRST_GEAR=1,DYN_GEAR_FIFTH_GEAR=5,DYN_GEAR_SECOND_GEAR=2,DYN_GEAR_EIGHTH_GEAR=8,DYN_GEAR_NEUTRAL_GEAR=0,DYN_GEAR_POWER_FREE=12,DYN_GEAR_THIRD_GEAR=3,DYN_GEAR_REVERSE_GEAR=10,DYN_GEAR_SEVENTH_GEAR=7,DYN_GEAR_NINTH_GEAR=9,DYN_GEAR_FOURTH_GEAR=4,} */	/* [Satisfies_rte sws 1188] */;

  /* typedef SigMainState_t */
  const VDYIoStateTypes_t VDY_SIN_POS_YWR         = (0);
  const VDYIoStateTypes_t VDY_SIN_POS_YWR_TEMP    = (1);
  const VDYIoStateTypes_t VDY_SIN_POS_SWA         = (2);
  const VDYIoStateTypes_t VDY_SIN_POS_LATA        = (3);
  const VDYIoStateTypes_t VDY_SIN_POS_WVEL_FL     = (4);
  const VDYIoStateTypes_t VDY_SIN_POS_WVEL_FR     = (5);
  const VDYIoStateTypes_t VDY_SIN_POS_WVEL_RL     = (6);
  const VDYIoStateTypes_t VDY_SIN_POS_WVEL_RR     = (7);
  const VDYIoStateTypes_t VDY_SIN_POS_YWRINT      = (8);
  const VDYIoStateTypes_t VDY_SIN_POS_YWRINT_TEMP = (9);
  const VDYIoStateTypes_t VDY_SIN_POS_LONGA       = (10);
  const VDYIoStateTypes_t VDY_SIN_POS_RSTA        = (11);
  const VDYIoStateTypes_t VDY_SIN_POS_VEHVEL_EXT  = (12);
  const VDYIoStateTypes_t VDY_SIN_POS_VEHACL_EXT  = (13);
  const VDYIoStateTypes_t VDY_SIN_POS_WDIR_FL     = (14);
  const VDYIoStateTypes_t VDY_SIN_POS_WDIR_FR     = (15);
  const VDYIoStateTypes_t VDY_SIN_POS_WDIR_RL     = (16);
  const VDYIoStateTypes_t VDY_SIN_POS_WDIR_RR     = (17);
  const VDYIoStateTypes_t VDY_SIN_POS_WTCKS_FL    = (18);
  const VDYIoStateTypes_t VDY_SIN_POS_WTCKS_FR    = (19);
  const VDYIoStateTypes_t VDY_SIN_POS_WTCKS_RL    = (20);
  const VDYIoStateTypes_t VDY_SIN_POS_WTCKS_RR    = (21);
  const VDYIoStateTypes_t VDY_SIN_POS_GEAR        = (22);
  const VDYIoStateTypes_t VDY_SIN_POS_BRAKE       = (23);
  const VDYIoStateTypes_t VDY_SIN_POS_PBRK        = (24);
  const VDYIoStateTypes_t VDY_SIN_POS_VDIR        = (25);
  const VDYIoStateTypes_t VDY_SIN_POS_VMOT        = (26);
  const VDYIoStateTypes_t VDY_SIN_POS_DUMMY       = (27);
  const VDYIoStateTypes_t VDY_SIN_POS_CRV         = (28);
  const VDYIoStateTypes_t VDY_SIN_POS_SSA         = (29);
  const VDYIoStateTypes_t VDY_SIN_POS_MAX         = (32);

  /* typedef LongDirState_t */
  const LongDirState_t VDY_LONG_DIR_VOID = (0);
  const LongDirState_t VDY_LONG_DIR_FWD  = (1);
  const LongDirState_t VDY_LONG_DIR_RWD  = (2);

  /* typedef ActGearPos_t */
  const ActGearPos_t ACT_GEAR_POS_NEUTRAL = (0);
  const ActGearPos_t ACT_GEAR_POS_PARKING = (1);
  const ActGearPos_t ACT_GEAR_POS_FORWARD = (2);
  const ActGearPos_t ACT_GEAR_POS_REVERSE = (3);

  /* typedef ParkBrakeState_t */
  const ParkBrakeState_t STAT_INACTIVE = (0);
  const ParkBrakeState_t STAT_ACTIVE   = (1);

  /* typedef VehLongMotStateExt_t */
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_ROLLING     = (0);
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_FAST_STST   = (1);
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_SECURE_STST = (2);

  /* typedef SigAddState_t */
  const VDYIoStateTypes_t VEH_SIG_ADD_ENV_TEMP                  = (0);
  const VDYIoStateTypes_t VEH_SIG_ADD_WIPER_STATE               = (1);
  const VDYIoStateTypes_t VEH_SIG_ADD_WIPER_STAGE               = (2);
  const VDYIoStateTypes_t VEH_SIG_ADD_WIPER_OUT_PARK_POS        = (3);
  const VDYIoStateTypes_t VEH_SIG_ADD_WIPER_WASHER_FRONT        = (4);
  const VDYIoStateTypes_t VEH_SIG_ADD_RAIN_SENSOR               = (5);
  const VDYIoStateTypes_t VEH_SIG_ADD_TURN_SIGNAL               = (6);
  const VDYIoStateTypes_t VEH_SIG_ADD_FOG_LAMP_FRONT            = (7);
  const VDYIoStateTypes_t VEH_SIG_ADD_FOG_LAMP_REAR             = (8);
  const VDYIoStateTypes_t VEH_SIG_ADD_ROAD_WHL_ANG_FR           = (9);
  const VDYIoStateTypes_t VEH_SIG_ADD_ROAD_WHL_ANG_RE           = (10);
  const VDYIoStateTypes_t VEH_SIG_ADD_ODOMETER                  = (11);
  const VDYIoStateTypes_t VEH_SIG_ADD_GAS_PEDAL_POS             = (12);
  const VDYIoStateTypes_t VEH_SIG_ADD_KICK_DOWN                 = (13);
  const VDYIoStateTypes_t VEH_SIG_ADD_BRAKE_PEDAL_PRESSED       = (14);
  const VDYIoStateTypes_t VEH_SIG_ADD_DRIVER_TIRED              = (15);
  const VDYIoStateTypes_t VEH_SIG_ADD_SPEED_UNIT                = (16);
  const VDYIoStateTypes_t VEH_SIG_ADD_SPEEDO_SPEED              = (17);
  const VDYIoStateTypes_t VEH_SIG_ADD_TRAILER_CON               = (18);
  const VDYIoStateTypes_t VEH_SIG_ADD_TRAILER_CON_BEF_SHUTDOWN  = (19);
  const VDYIoStateTypes_t VEH_SIG_ADD_TRAILER_LENGTH_INPUT      = (20);
  const VDYIoStateTypes_t VEH_SIG_ADD_PARK_AID_DET_L            = (21);
  const VDYIoStateTypes_t VEH_SIG_ADD_PARK_AID_DET_CL           = (22);
  const VDYIoStateTypes_t VEH_SIG_ADD_PARK_AID_DET_CR           = (23);
  const VDYIoStateTypes_t VEH_SIG_ADD_PARK_AID_DET_R            = (24);
  const VDYIoStateTypes_t VEH_SIG_ADD_IGN_SWITCH                = (25);
  const VDYIoStateTypes_t VEH_SIG_ADD_HEIGHT_LEVEL              = (26);
  const VDYIoStateTypes_t VEH_SIG_ADD_WHEEL_HEIGHT_LEVEL        = (27);
  const VDYIoStateTypes_t VEH_SIG_ADD_MAX                       = (28);

  /* typedef WiperState_t */
  const WiperState_t VEH_SIG_ADD_WIPER_STATE_INACTIVE = (0);
  const WiperState_t VEH_SIG_ADD_WIPER_STATE_ACTIVE   = (1);

  /* typedef WiperStage_t */
  const WiperStage_t VEH_SIG_ADD_WIPER_OFF       = (0);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL1 = (1);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL2 = (2);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL3 = (3);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL4 = (4);
  const WiperStage_t VEH_SIG_ADD_WIPER_STAGE1    = (5);
  const WiperStage_t VEH_SIG_ADD_WIPER_STAGE2    = (6);

  /* typedef WiperWasherFrontState_t */
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_IDLE    = (0);
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_TIPWIPE = (1);
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_WASH    = (2);

  /* typedef TurnSignal_t */
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_UNKNOWN = (0);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_LEFT    = (1);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_RIGHT   = (2);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_NEUTRAL = (3);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_BOTH    = (4);

  /* typedef SpeedUnit_t */
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN                      = (0);
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_KMH                          = (1);
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_MPH                          = (2);
//#if !ARS_SWITCH
//  const SpeedUnit_t SR_RTE_OUTPUT_COUNTRY_SPEED_LIMIT_UNIT_RECOG_INT_MAX = (2147483647);
//#endif

  /* typedef VDYTrailerConnection_t */
  const VDYTrailerConnection_t VEH_SIG_ADD_TRLR_NO_DETECT = (0);
  const VDYTrailerConnection_t VEH_SIG_ADD_TRLR_OK        = (1);
  const VDYTrailerConnection_t VEH_SIG_ADD_TRLR_NDEF2     = (2);
  const VDYTrailerConnection_t VEH_SIG_ADD_TRLR_SNA       = (3);

  /* typedef VehSigBrakeStatePos_t */
  const VDYIoStateTypes_t VEH_SIG_BRAKE_ABS            = (0);
  const VDYIoStateTypes_t VEH_SIG_BRAKE_TSC	           = (1);
  const VDYIoStateTypes_t VEH_SIG_BRAKE_MAX	           = (2);

  /* typedef IgnitionSwitch_t */
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_LOCK   = (0);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_OFF    = (1);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_ACC    = (2);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_ON     = (4);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_START  = (5);

  /* typedef VehSigPowertrainStatePos_t */
  const VDYIoStateTypes_t VEH_SIG_POWERTRAIN_ACTUALGEAR	    = (0);
  const VDYIoStateTypes_t VEH_SIG_POWERTRAIN_TARGETGEAR	    = (1);
  const VDYIoStateTypes_t VEH_SIG_POWERTRAIN_ENGINE_RUNNING	= (2);
  const VDYIoStateTypes_t VEH_SIG_POWERTRAIN_MAX	          = (4);

  /* typedef TransmissionGear_t */
  const TransmissionGear_t DYN_GEAR_NEUTRAL_GEAR  = (0);
  const TransmissionGear_t DYN_GEAR_FIRST_GEAR    = (1);
  const TransmissionGear_t DYN_GEAR_SECOND_GEAR   = (2);
  const TransmissionGear_t DYN_GEAR_THIRD_GEAR    = (3);
  const TransmissionGear_t DYN_GEAR_FOURTH_GEAR   = (4);
  const TransmissionGear_t DYN_GEAR_FIFTH_GEAR    = (5);
  const TransmissionGear_t DYN_GEAR_SIXTH_GEAR    = (6);
  const TransmissionGear_t DYN_GEAR_SEVENTH_GEAR  = (7);
  const TransmissionGear_t DYN_GEAR_EIGHTH_GEAR   = (8);
  const TransmissionGear_t DYN_GEAR_NINTH_GEAR    = (9);
  const TransmissionGear_t DYN_GEAR_REVERSE_GEAR  = (10);
  const TransmissionGear_t DYN_GEAR_PARK_GEAR     = (11);
  const TransmissionGear_t DYN_GEAR_POWER_FREE    = (12);
  const TransmissionGear_t DYN_GEAR_POWER_INVALID = (255);


  typedef VDYIoStateTypes_t         	State_array_t_3[2];/* State of the brake vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigBrakeStatePos_t */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t         	State_array_t_2[4];/* State of the powertrain vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigPowertrainStatePos_t */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t         	State_array_t_0[32];/* State of the main vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigMainStatePos_t */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t         	State_array_t_1[28];/* State of the add vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigAddStatePos_t */	/* [Satisfies_rte sws 1189] */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    TransmissionGear_t ActualGear;
    TransmissionGear_t TargetGear;
    bool8 EngineRunning;
    uint8 FillByte;
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
    sint16 FrontLeft;
    sint16 FrontRight;
    sint16 RearLeft;
    sint16 RearRight;
  } WheelHeightLevel_t;			/* Height level of each wheel */

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
    VDYTrailerConnection_t TrailerConnection;
    VDYTrailerConnection_t TrailerConnBeforeShutDown;
    uint8 TrailerLengthInput;
    uint8 ParkAidDet_L;
    uint8 ParkAidDet_CL;
    uint8 ParkAidDet_CR;
    uint8 ParkAidDet_R;
    IgnitionSwitch_t IgnitionSwitch;
    eSuspensionSystem_t eSuspensionSystem;
    eHeightLevel_t eHeightLevel;
    WheelHeightLevel_t WheelHeightLevel;
    sint16 AlignmentByte1;
    sint16 AlignmentByte2;
  } VehSigAdd_t;			/* Additional Vehicle dynacmis sensor signals */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoInterfaceVersionNumber_t uiVersionNumber;
    SignalHeader_t sSigHeader;
    VehSigMain_t VehSigMain;
    VehSigAdd_t VehSigAdd;
    PowerTrain_t PowerTrain;
    Brake_t Brake;
  } VehSig_t;			/* Main Vehicle dynacmis sensor signals @vaddr:0x20300050 @vaddr_defs: VDY_MEAS_ID_VEH_SIG @cycleid:vdy_in_cycle_id @vname:VehSig */

}

namespace VehSigV11
{
  /*! External interface states version 8 and higher */
  const uint8 VEH_SIG_IO_STATE_VALID = 0U;
  const uint8 VEH_SIG_IO_STATE_INVALID = 1U;
  const uint8 VEH_SIG_IO_STATE_NOTAVAIL = 2U;
  const uint8 VEH_SIG_IO_STATE_DECREASED = 3U;
  const uint8 VEH_SIG_IO_STATE_SUBSTITUE = 4U;
  const uint8 VDY_IO_STATE_INPLAUSIBLE   = 5U;
  const uint8 VEH_SIG_IO_STATE_INIT = 15U;
  const uint8 VEH_SIG_IO_STATE_MAX = 255U;

  typedef uint8 bool8                     			/* [Satisfies_rte sws 1188] */;

  typedef uint8 VDYIoStateTypes_t         /* vdy io states @min: 0 @max:255 @values: enum { VDY_IO_STATE_VALID=0,VDY_IO_STATE_SUBSTITUE=4,VDY_IO_STATE_INIT=15,VDY_IO_STATE_DECREASED=3,VDY_IO_STATE_INVALID=1,VDY_IO_STATE_NOTAVAIL=2,VDY_IO_STATE_INPLAUSIBLE=5,VDY_IO_STATE_MAX=255,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint32 AlgoInterfaceVersionNumber_t /* Algo interface version nummbers @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint32 AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef uint16 AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint8 LongDirState_t            /* @min: 0 @max:2 @values: enum { VDY_LONG_DIR_RWD=2,VDY_LONG_DIR_VOID=0,VDY_LONG_DIR_FWD=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 ActGearPos_t              /* VDY_SIN_POS_GEAR @min: 0 @max:3 @values: enum { ACT_GEAR_POS_NEUTRAL=0,ACT_GEAR_POS_FORWARD=2,ACT_GEAR_POS_PARKING=1,ACT_GEAR_POS_REVERSE=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 ParkBrakeState_t          /* VDY_SIN_POS_PBRK @min: 0 @max:1 @values: enum { STAT_ACTIVE=1,STAT_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 VehLongMotStateExt_t      /* VDY_SIN_POS_VMOT @min: 0 @max:2 @values: enum { VDY_VEH_MOT_STATE_ROLLING=0,VDY_VEH_MOT_STATE_SECURE_STST=2,VDY_VEH_MOT_STATE_FAST_STST=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint8 WiperState_t              /* Wiper blades activity @min: 0 @max:1 @values: enum { VEH_SIG_ADD_WIPER_STATE_ACTIVE=1,VEH_SIG_ADD_WIPER_STATE_INACTIVE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 WiperStage_t              /* Wiper switch position @min: 0 @max:6 @values: enum { VEH_SIG_ADD_WIPER_INTERVAL1=1,VEH_SIG_ADD_WIPER_INTERVAL2=2,VEH_SIG_ADD_WIPER_INTERVAL3=3,VEH_SIG_ADD_WIPER_INTERVAL4=4,VEH_SIG_ADD_WIPER_OFF=0,VEH_SIG_ADD_WIPER_STAGE1=5,VEH_SIG_ADD_WIPER_STAGE2=6,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 WiperWasherFrontState_t   /* Tip-wipe / washer state @min: 0 @max:2 @values: enum { VEH_SIG_ADD_WWS_WASH=2,VEH_SIG_ADD_WWS_TIPWIPE=1,VEH_SIG_ADD_WWS_IDLE=0,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 TurnSignal_t              /* Turn signal switch state @min: 0 @max:4 @values: enum { VEH_SIG_ADD_TURN_SIG_NEUTRAL=3,VEH_SIG_ADD_TURN_SIG_UNKNOWN=0,VEH_SIG_ADD_TURN_SIG_RIGHT=2,VEH_SIG_ADD_TURN_SIG_LEFT=1,VEH_SIG_ADD_TURN_SIG_BOTH=4,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 SpeedUnit_t               /* ENUM speedmeter speed unit @min: 0 @max:2 @values: enum { VEH_SIG_ADD_SPEEDO_UNIT_MPH=2,VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN=0,VEH_SIG_ADD_SPEEDO_UNIT_KMH=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 VDYTrailerConnection_t    /* @min: 0 @max:3 @values: enum { VEH_SIG_ADD_TRLR_OK=1,VEH_SIG_ADD_TRLR_NDEF2=2,VEH_SIG_ADD_TRLR_NO_DETECT=0,VEH_SIG_ADD_TRLR_SNA=3,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 IgnitionSwitch_t          /* Ignition lockI, gnition off, Ignition accessory (15r) , Ignition on (15) , Ignition start (50) @min: 0 @max:5 @values: enum { VEH_SIG_ADD_IGN_ON=4,VEH_SIG_ADD_IGN_START=5,VEH_SIG_ADD_IGN_LOCK=0,VEH_SIG_ADD_IGN_OFF=1,VEH_SIG_ADD_IGN_ACC=2,} */	/* [Satisfies_rte sws 1188] */;
  typedef uint8 eSuspensionSystem_t       /* Availability of active suspension:
  0: no active suspension available
  1: active suspension available @min: 0 @max:1 @values: enum { VEH_SIG_ADD_ACTIVE_SUSPENSION=1,VEH_SIG_ADD_NO_ACTIVE_SUSPENSION=0,} */	/* [Satisfies_rte sws 1188] */;
  
  typedef uint8 eHeightLevel_t            /* Height adjustment value the car:
  0: no height level available
  1: height level normal
  2: height level low
  3: height level high @min: 0 @max:4 @values: enum { VEH_SIG_ADD_HEIGHT_LVL_HIGH=4,VEH_SIG_ADD_HEIGHT_LVL_LOW=2,VEH_SIG_ADD_NO_HEIGHT_LVL=0,VEH_SIG_ADD_HEIGHT_LVL_NORMAL=1,} */	/* [Satisfies_rte sws 1188] */;

  typedef uint8 TransmissionGear_t        /* Indicates current used gear position @min: 0 @max:12 @values: enum { DYN_GEAR_PARK_GEAR=11,DYN_GEAR_SIXTH_GEAR=6,DYN_GEAR_FIRST_GEAR=1,DYN_GEAR_FIFTH_GEAR=5,DYN_GEAR_SECOND_GEAR=2,DYN_GEAR_EIGHTH_GEAR=8,DYN_GEAR_NEUTRAL_GEAR=0,DYN_GEAR_POWER_FREE=12,DYN_GEAR_THIRD_GEAR=3,DYN_GEAR_REVERSE_GEAR=10,DYN_GEAR_SEVENTH_GEAR=7,DYN_GEAR_NINTH_GEAR=9,DYN_GEAR_FOURTH_GEAR=4,} */	/* [Satisfies_rte sws 1188] */;

  /* typedef SigMainState_t */
  const VDYIoStateTypes_t VDY_SIN_POS_YWR         = (0);
  const VDYIoStateTypes_t VDY_SIN_POS_YWR_TEMP    = (1);
  const VDYIoStateTypes_t VDY_SIN_POS_SWA         = (2);
  const VDYIoStateTypes_t VDY_SIN_POS_LATA        = (3);
  const VDYIoStateTypes_t VDY_SIN_POS_WVEL_FL     = (4);
  const VDYIoStateTypes_t VDY_SIN_POS_WVEL_FR     = (5);
  const VDYIoStateTypes_t VDY_SIN_POS_WVEL_RL     = (6);
  const VDYIoStateTypes_t VDY_SIN_POS_WVEL_RR     = (7);
  const VDYIoStateTypes_t VDY_SIN_POS_YWRINT      = (8);
  const VDYIoStateTypes_t VDY_SIN_POS_YWRINT_TEMP = (9);
  const VDYIoStateTypes_t VDY_SIN_POS_LONGA       = (10);
  const VDYIoStateTypes_t VDY_SIN_POS_RSTA        = (11);
  const VDYIoStateTypes_t VDY_SIN_POS_VEHVEL_EXT  = (12);
  const VDYIoStateTypes_t VDY_SIN_POS_VEHACL_EXT  = (13);
  const VDYIoStateTypes_t VDY_SIN_POS_WDIR_FL     = (14);
  const VDYIoStateTypes_t VDY_SIN_POS_WDIR_FR     = (15);
  const VDYIoStateTypes_t VDY_SIN_POS_WDIR_RL     = (16);
  const VDYIoStateTypes_t VDY_SIN_POS_WDIR_RR     = (17);
  const VDYIoStateTypes_t VDY_SIN_POS_WTCKS_FL    = (18);
  const VDYIoStateTypes_t VDY_SIN_POS_WTCKS_FR    = (19);
  const VDYIoStateTypes_t VDY_SIN_POS_WTCKS_RL    = (20);
  const VDYIoStateTypes_t VDY_SIN_POS_WTCKS_RR    = (21);
  const VDYIoStateTypes_t VDY_SIN_POS_GEAR        = (22);
  const VDYIoStateTypes_t VDY_SIN_POS_BRAKE       = (23);
  const VDYIoStateTypes_t VDY_SIN_POS_PBRK        = (24);
  const VDYIoStateTypes_t VDY_SIN_POS_VDIR        = (25);
  const VDYIoStateTypes_t VDY_SIN_POS_VMOT        = (26);
  const VDYIoStateTypes_t VDY_SIN_POS_DUMMY       = (27);
  const VDYIoStateTypes_t VDY_SIN_POS_CRV         = (28);
  const VDYIoStateTypes_t VDY_SIN_POS_SSA         = (29);
  const VDYIoStateTypes_t VDY_SIN_POS_VEHVEL_MIN  = (30);
  const VDYIoStateTypes_t VDY_SIN_POS_VEHVEL_MAX  = (31);
  const VDYIoStateTypes_t VDY_SIN_POS_MAX         = (32);

  /* typedef LongDirState_t */
  const LongDirState_t VDY_LONG_DIR_VOID = (0);
  const LongDirState_t VDY_LONG_DIR_FWD  = (1);
  const LongDirState_t VDY_LONG_DIR_RWD  = (2);

  /* typedef ActGearPos_t */
  const ActGearPos_t ACT_GEAR_POS_NEUTRAL = (0);
  const ActGearPos_t ACT_GEAR_POS_PARKING = (1);
  const ActGearPos_t ACT_GEAR_POS_FORWARD = (2);
  const ActGearPos_t ACT_GEAR_POS_REVERSE = (3);

  /* typedef ParkBrakeState_t */
  const ParkBrakeState_t STAT_INACTIVE = (0);
  const ParkBrakeState_t STAT_ACTIVE   = (1);

  /* typedef VehLongMotStateExt_t */
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_ROLLING     = (0);
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_FAST_STST   = (1);
  const VehLongMotStateExt_t VDY_VEH_MOT_STATE_SECURE_STST = (2);

  /* typedef SigAddState_t */
  const VDYIoStateTypes_t VEH_SIG_ADD_ENV_TEMP                  = (0);
  const VDYIoStateTypes_t VEH_SIG_ADD_WIPER_STATE               = (1);
  const VDYIoStateTypes_t VEH_SIG_ADD_WIPER_STAGE               = (2);
  const VDYIoStateTypes_t VEH_SIG_ADD_WIPER_OUT_PARK_POS        = (3);
  const VDYIoStateTypes_t VEH_SIG_ADD_WIPER_WASHER_FRONT        = (4);
  const VDYIoStateTypes_t VEH_SIG_ADD_RAIN_SENSOR               = (5);
  const VDYIoStateTypes_t VEH_SIG_ADD_TURN_SIGNAL               = (6);
  const VDYIoStateTypes_t VEH_SIG_ADD_FOG_LAMP_FRONT            = (7);
  const VDYIoStateTypes_t VEH_SIG_ADD_FOG_LAMP_REAR             = (8);
  const VDYIoStateTypes_t VEH_SIG_ADD_ROAD_WHL_ANG_FR           = (9);
  const VDYIoStateTypes_t VEH_SIG_ADD_ROAD_WHL_ANG_RE           = (10);
  const VDYIoStateTypes_t VEH_SIG_ADD_ODOMETER                  = (11);
  const VDYIoStateTypes_t VEH_SIG_ADD_GAS_PEDAL_POS             = (12);
  const VDYIoStateTypes_t VEH_SIG_ADD_KICK_DOWN                 = (13);
  const VDYIoStateTypes_t VEH_SIG_ADD_BRAKE_PEDAL_PRESSED       = (14);
  const VDYIoStateTypes_t VEH_SIG_ADD_DRIVER_TIRED              = (15);
  const VDYIoStateTypes_t VEH_SIG_ADD_SPEED_UNIT                = (16);
  const VDYIoStateTypes_t VEH_SIG_ADD_SPEEDO_SPEED              = (17);
  const VDYIoStateTypes_t VEH_SIG_ADD_TRAILER_CON               = (18);
  const VDYIoStateTypes_t VEH_SIG_ADD_TRAILER_CON_BEF_SHUTDOWN  = (19);
  const VDYIoStateTypes_t VEH_SIG_ADD_TRAILER_LENGTH_INPUT      = (20);
  const VDYIoStateTypes_t VEH_SIG_ADD_PARK_AID_DET_L            = (21);
  const VDYIoStateTypes_t VEH_SIG_ADD_PARK_AID_DET_CL           = (22);
  const VDYIoStateTypes_t VEH_SIG_ADD_PARK_AID_DET_CR           = (23);
  const VDYIoStateTypes_t VEH_SIG_ADD_PARK_AID_DET_R            = (24);
  const VDYIoStateTypes_t VEH_SIG_ADD_IGN_SWITCH                = (25);
  const VDYIoStateTypes_t VEH_SIG_ADD_HEIGHT_LEVEL              = (26);
  const VDYIoStateTypes_t VEH_SIG_ADD_WHEEL_HEIGHT_LEVEL        = (27);
  const VDYIoStateTypes_t VEH_SIG_ADD_MAX                       = (28);

  /* typedef WiperState_t */
  const WiperState_t VEH_SIG_ADD_WIPER_STATE_INACTIVE = (0);
  const WiperState_t VEH_SIG_ADD_WIPER_STATE_ACTIVE   = (1);

  /* typedef WiperStage_t */
  const WiperStage_t VEH_SIG_ADD_WIPER_OFF       = (0);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL1 = (1);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL2 = (2);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL3 = (3);
  const WiperStage_t VEH_SIG_ADD_WIPER_INTERVAL4 = (4);
  const WiperStage_t VEH_SIG_ADD_WIPER_STAGE1    = (5);
  const WiperStage_t VEH_SIG_ADD_WIPER_STAGE2    = (6);

  /* typedef WiperWasherFrontState_t */
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_IDLE    = (0);
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_TIPWIPE = (1);
  const WiperWasherFrontState_t VEH_SIG_ADD_WWS_WASH    = (2);

  /* typedef TurnSignal_t */
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_UNKNOWN = (0);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_LEFT    = (1);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_RIGHT   = (2);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_NEUTRAL = (3);
  const TurnSignal_t VEH_SIG_ADD_TURN_SIG_BOTH    = (4);

  /* typedef SpeedUnit_t */
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_UNKNOWN                      = (0);
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_KMH                          = (1);
  const SpeedUnit_t VEH_SIG_ADD_SPEEDO_UNIT_MPH                          = (2);

  /* typedef VDYTrailerConnection_t */
  const VDYTrailerConnection_t VEH_SIG_ADD_TRLR_NO_DETECT = (0);
  const VDYTrailerConnection_t VEH_SIG_ADD_TRLR_OK        = (1);
  const VDYTrailerConnection_t VEH_SIG_ADD_TRLR_NDEF2     = (2);
  const VDYTrailerConnection_t VEH_SIG_ADD_TRLR_SNA       = (3);

  /* typedef VehSigBrakeStatePos_t */
  const VDYIoStateTypes_t VEH_SIG_BRAKE_ABS            = (0);
  const VDYIoStateTypes_t VEH_SIG_BRAKE_TSC	           = (1);
  const VDYIoStateTypes_t VEH_SIG_BRAKE_MAX	           = (2);

  /* typedef IgnitionSwitch_t */
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_LOCK   = (0);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_OFF    = (1);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_ACC    = (2);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_ON     = (4);
  const IgnitionSwitch_t VEH_SIG_ADD_IGN_START  = (5);

  /* typedef VehSigPowertrainStatePos_t */
  const VDYIoStateTypes_t VEH_SIG_POWERTRAIN_ACTUALGEAR	    = (0);
  const VDYIoStateTypes_t VEH_SIG_POWERTRAIN_TARGETGEAR	    = (1);
  const VDYIoStateTypes_t VEH_SIG_POWERTRAIN_ENGINE_RUNNING	= (2);
  const VDYIoStateTypes_t VEH_SIG_POWERTRAIN_MAX	          = (4);

  /* typedef TransmissionGear_t */
  const TransmissionGear_t DYN_GEAR_NEUTRAL_GEAR  = (0);
  const TransmissionGear_t DYN_GEAR_FIRST_GEAR    = (1);
  const TransmissionGear_t DYN_GEAR_SECOND_GEAR   = (2);
  const TransmissionGear_t DYN_GEAR_THIRD_GEAR    = (3);
  const TransmissionGear_t DYN_GEAR_FOURTH_GEAR   = (4);
  const TransmissionGear_t DYN_GEAR_FIFTH_GEAR    = (5);
  const TransmissionGear_t DYN_GEAR_SIXTH_GEAR    = (6);
  const TransmissionGear_t DYN_GEAR_SEVENTH_GEAR  = (7);
  const TransmissionGear_t DYN_GEAR_EIGHTH_GEAR   = (8);
  const TransmissionGear_t DYN_GEAR_NINTH_GEAR    = (9);
  const TransmissionGear_t DYN_GEAR_REVERSE_GEAR  = (10);
  const TransmissionGear_t DYN_GEAR_PARK_GEAR     = (11);
  const TransmissionGear_t DYN_GEAR_POWER_FREE    = (12);
  const TransmissionGear_t DYN_GEAR_POWER_INVALID = (255);


  typedef VDYIoStateTypes_t         	State_array_t_3[2];/* State of the brake vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigBrakeStatePos_t */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t         	State_array_t_2[4];/* State of the powertrain vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigPowertrainStatePos_t */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t         	State_array_t_0[32];/* State of the main vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigMainStatePos_t */	/* [Satisfies_rte sws 1189] */
  typedef VDYIoStateTypes_t         	State_array_t_1[28];/* State of the add vehicle input signals as enum values of VDYIoStateTypes_t with the index VehSigAddStatePos_t */	/* [Satisfies_rte sws 1189] */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;			/* Common header for all structured data types */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    TransmissionGear_t ActualGear;
    TransmissionGear_t TargetGear;
    bool8 EngineRunning;
    uint8 FillByte;
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
    sint16 FrontLeft;
    sint16 FrontRight;
    sint16 RearLeft;
    sint16 RearRight;
  } WheelHeightLevel_t;			/* Height level of each wheel */

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
	float32 VehVelocityExtMin;
 	float32 VehVelocityExtMax;
  } VehSigMain_t;			/* Main Vehicle dynacmis sensor signals */

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
    VDYTrailerConnection_t TrailerConnection;
    VDYTrailerConnection_t TrailerConnBeforeShutDown;
    uint8 TrailerLengthInput;
    uint8 ParkAidDet_L;
    uint8 ParkAidDet_CL;
    uint8 ParkAidDet_CR;
    uint8 ParkAidDet_R;
    IgnitionSwitch_t IgnitionSwitch;
    eSuspensionSystem_t eSuspensionSystem;
    eHeightLevel_t eHeightLevel;
    WheelHeightLevel_t WheelHeightLevel;
    sint16 AlignmentByte1;
    sint16 AlignmentByte2;
  } VehSigAdd_t;			/* Additional Vehicle dynacmis sensor signals */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoInterfaceVersionNumber_t uiVersionNumber;
    SignalHeader_t sSigHeader;
    VehSigMain_t VehSigMain;
    VehSigAdd_t VehSigAdd;
    PowerTrain_t PowerTrain;
    Brake_t Brake;
  } VehSig_t;			/* Main Vehicle dynacmis sensor signals @vaddr:0x20300050 @vaddr_defs: VDY_MEAS_ID_VEH_SIG @cycleid:vdy_in_cycle_id @vname:VehSig */

}

#endif // interfacevehsig_h__
