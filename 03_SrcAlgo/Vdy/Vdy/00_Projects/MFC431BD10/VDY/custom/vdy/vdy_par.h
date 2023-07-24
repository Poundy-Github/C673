/*! \file ********************************************************************

  @defgroup VdyParametersH VDY Parameters Declaration

  @{

  $Company:			Continental AG $

  $Component:		VDY (Vehicle Dynamics Observer) $

  $Module:			vdy_par.h $

  @brief			Vehicle Dynamics parameter declaration
  
  $Descripion:		$

  $Revision: 1.1 $

  CHANGES:
  ---*/ /*---

*****************************************************************************/

/* ###Suggested TCI Code Review###:It is legacy code of ARS301 , alreay reviewed and working fine without any critical issue " */
/* PRQA S 3412,3410 EOF */

#ifndef VDYPAR_INCLUDED
#define VDYPAR_INCLUDED
/*** START OF SINGLE INCLUDE SECTION ****************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/

#ifndef VDY_THREE
#define VDY_THREE		(3)		/// Symbolic constant signed 3
#endif

/// Parameter definition for Simulink skip const declaration 
#if defined(SIM_SIMULINK) || defined(MATLAB_MEX_FILE)
#define VDY_CONST 
#else
#define VDY_CONST const 
#endif

#ifdef VDY_DEF_CONST 
/// Parameter definition skip declaration 
#  define VDY_DECL_CONST(type_, name_)
#else
/// Parameter decleration for referencing 
#  define VDY_DECL_CONST(type_, name_)   extern VDY_CONST type_ name_;
#endif

/// Number of bybass cycles in case of non-valid sensor input signals 
#define VDY_PAR_BACKUP_CNTR_FREEZE_MAX    VDYParBckpCntrFrzMax_c
VDY_DECL_CONST(sint32, VDYParBckpCntrFrzMax_c)

/// Quality threshold for uncalibrated steering wheel angle sensor 
#define VDY_PAR_YW_Q_THRLD_SWA_UC         VDYParYwQThrSwaUc_c
VDY_DECL_CONST(fQuality_t, VDYParYwQThrSwaUc_c)

/* Einfluss von Cache-Offset (Overlay) an wirksamen Offset 0 -> kein Einfluss 
   max. Wert sollte <= 0.5 sein, und THRLD_SWA_CAL < THRLD_SWA_UC */

/// Quality threshold for calibrated steering wheel angle sensor 
#define VDY_PAR_YW_Q_THRLD_SWA_CAL        VDYParYwQThrSwaCal_c
VDY_DECL_CONST(fQuality_t, VDYParYwQThrSwaCal_c)

/// Steering wheel angle repeat reinit histo counter max to releas a dem event 
#define VDY_PAR_ERR_SWA_REINIT        VDYParErrSwaReInit_c
VDY_DECL_CONST(uint8, VDYParErrSwaReInit_c)

/// [m/s]  Ego velocity threshold in km/h to indicate course estimation error 
#define VDY_PAR_ERR_CALC_VEH_SPEED_THRHLD VDYParErrVehVelThr_c 
VDY_DECL_CONST(fVelocity_t,VDYParErrVehVelThr_c)

/// [s] Averaging time for fast standstill calibration 
#define VDY_PAR_YWR_STST_CAL_TIME_MIN    VDYParYwrStstCalTimeMin_c
VDY_DECL_CONST(fTime_t, VDYParYwrStstCalTimeMin_c)

/// [s] Averaging time for normal, secure standstill calibration  
#define VDY_PAR_YWR_STST_CAL_TIME_NORM   VDYParYwrStstCalTimeNorm_c
VDY_DECL_CONST(fTime_t, VDYParYwrStstCalTimeNorm_c)

/// [s] Filter time constant for input filter of yaw rate sensor signal  
#define VDY_PAR_YWR_YAWRATE_FT    VDYParYwrYwRtFilT_c
VDY_DECL_CONST(fTime_t, VDYParYwrYwRtFilT_c)

/// [s] Filter time constant for external velocity differentiator  
#define VDY_PAR_VEL_DIFF_FT    VDYParVelDiffFilT_c
VDY_DECL_CONST(fTime_t, VDYParVelDiffFilT_c)

/// [(m/s)^2] Velocity variance in case of external conditioned velocity  
#define VDY_PAR_VEL_EXT_UNC    VDYParVelExtUnc_c
VDY_DECL_CONST(fVariance_t, VDYParVelExtUnc_c)

/// [(m/s^2)^2] Acceleration variance in case of external conditioned acceleration 
#define VDY_PAR_ACCEL_EXT_UNC    VDYParAccelExtUnc_c
VDY_DECL_CONST(fVariance_t, VDYParAccelExtUnc_c)

/// [(1/m)^2] Curvature variance in case of external conditioned curvature 
#define VDY_PAR_CRV_EXT_UNC    VDYparCrvExtUnc_c
VDY_DECL_CONST(fVariance_t, VDYparCrvExtUnc_c)

/// [(rad/s)^2] Yaw rate variance in case of external conditioned yaw rate 
#define VDY_PAR_YWR_EXT_UNC    VDYparYwrExtUnc_c
VDY_DECL_CONST(fVariance_t, VDYparYwrExtUnc_c)

/// [(rad/s)^2] Side slip angle  variance in case of external conditioned yaw rate 
#define VDY_PAR_SSA_EXT_UNC    VDYparSsaExtUnc_c
VDY_DECL_CONST(fVariance_t, VDYparSsaExtUnc_c)

/// [(rad)^2] Steer wheel angle variance in case of external conditioned 
#define VDY_PAR_SWA_EXT_UNC    VDYparSwaExtUnc_c
VDY_DECL_CONST(fVariance_t, VDYparSwaExtUnc_c)

/// [(rad)^2] Rear wheel angle variance in case of external conditioned 
#define VDY_PAR_RWA_EXT_UNC    VDYparRwaExtUnc_c
VDY_DECL_CONST(fVariance_t, VDYparRwaExtUnc_c)

/// [(rad/(m/s^2))^2] Default understeer gradient variance if it is not present 
#define VDY_PAR_SSG_EXT_UNC    VDYParSsgExtUnc_c
VDY_DECL_CONST(fVariance_t, VDYParSsgExtUnc_c)

/// [1] Minimum motion state confidence for standstill yaw rate calibration 
#define VDY_PAR_YWR_STST_CONF_MIN  VDYParYwrStstConfMin_c
VDY_DECL_CONST(fConfidence_t, VDYParYwrStstConfMin_c)

/// [1] Maximum permitted deviation of correction factor +/- 
#define VDY_PAR_VCOR_ABS_DEV  VDYParVcorAbsDev_c
VDY_DECL_CONST(float32, VDYParVcorAbsDev_c)

/// [s^2/m^2] Maximum permitted velocity dependence (k1) of correction factor = k0 + k1 * v^2 
#define VDY_PAR_VCOR_VEL_DEP_MAX VDYParVcorVelDepMax_c
VDY_DECL_CONST(float32, VDYParVcorVelDepMax_c)

/// [s^2/m^2] Manimum permitted velocity dependence (k1) of correction factor = k0 + k1 * v^2 
#define VDY_PAR_VCOR_VEL_DEP_MIN VDYParVcorVelDepMin_c
VDY_DECL_CONST(float32, VDYParVcorVelDepMin_c)

/// [1] Maximum occurences of ambiguous distriubtions 
#define VDY_PAR_VCOR_THRHD_CNT_MEAS_ERR  VDYParVcorThrhdCntMeasErr_c
VDY_DECL_CONST(uint32, VDYParVcorThrhdCntMeasErr_c)

/// [1] Maximum occurences of measured correction factors out of range 
#define VDY_PAR_VCOR_THRHD_CNT_RANGE_ERR  VDYParVcorThrhdCntRangeErr_c
VDY_DECL_CONST(uint32, VDYParVcorThrhdCntRangeErr_c)

/// [1] Maximum of permitted cycles with external velocity deviation 
#define VDY_PAR_VMON_CYCLE_OUT VDYParVmonCyleOut_c
VDY_DECL_CONST(uint32, VDYParVmonCyleOut_c)

/// [1] Maximum of permitted cycles with external velocity deviation 
#define VDY_PAR_VMON_CYCLE_OUT_LT VDYParVmonCyleOutLt_c
VDY_DECL_CONST(uint32, VDYParVmonCyleOutLt_c)

/// [rad] Steering wheel offset range(+/-) max. 14 deg */
#define VDY_PAR_SWA_OFFSET_LIMIT_MAX VDYParSwaOffsetLimitMax_c
VDY_DECL_CONST(fAngle_t, VDYParSwaOffsetLimitMax_c)

/// [rad] YawRate offset range(+/-) max. 2.86rad/s */
#define VDY_PAR_YWR_OFFSET_LIMIT_MAX VDYParYwrOffsetLimitMax_c
VDY_DECL_CONST(fYawRate_t, VDYParYwrOffsetLimitMax_c)

/// [s] Filter time constant of raw yaw rate offset */
#define VDY_PAR_RAW_YAW_RATE_OFFSET_FT VDYParRawYawRateOffsetFT_c
VDY_DECL_CONST(fYawRate_t, VDYParRawYawRateOffsetFT_c)

/// [deg] ACC event (yaw rate offset not ok for ACC) is set if difference between alignment offset and vdy offset is above
#define VDY_PAR_ACC_YAW_RATE_OFFS_ERROR VDYParACCYawRateOffsError_c
VDY_DECL_CONST(fYawRate_t, VDYParACCYawRateOffsError_c)

/// [deg] ACC event (yaw rate offset not ok for ACC) is set if difference between alignment offset and vdy offset is above
#define VDY_PAR_ACC_YAW_RATE_OFFS_ERROR_OFF VDYParACCYawRateOffsErrorOff_c
VDY_DECL_CONST(fYawRate_t, VDYParACCYawRateOffsErrorOff_c)

/// [ms] ACC threshold time for event (yaw rate offset not ok for ACC) 
#define VDY_PAR_ACC_YAW_RATE_OFFS_THLD_TIME VDYParACCYawRateOffsThldTime_c
VDY_DECL_CONST(uint32, VDYParACCYawRateOffsThldTime_c)

/// [deg] CG event (yaw rate offset not ok for CG) is set if difference between alignment offset and vdy offset is above
#define VDY_PAR_CG_YAW_RATE_OFFS_ERROR VDYParCGYawRateOffsError_c
VDY_DECL_CONST(fYawRate_t, VDYParCGYawRateOffsError_c)

/// [deg] CG event (yaw rate offset not ok for CG) is set if difference between alignment offset and vdy offset is above
#define VDY_PAR_CG_YAW_RATE_OFFS_ERROR_OFF VDYParCGYawRateOffsErrorOff_c
VDY_DECL_CONST(fYawRate_t, VDYParCGYawRateOffsErrorOff_c)

/// [ms] CG threshold time for event (yaw rate offset not ok for CG) 
#define VDY_PAR_CG_YAW_RATE_OFFS_THLD_TIME VDYParCGYawRateOffsThldTime_c
VDY_DECL_CONST(uint32, VDYParCGYawRateOffsThldTime_c)

/// [rad/s/20ms] threshold yaw rate input signal diff peak 
#define VDY_PAR_YAW_RATE_INPUT_PEAK VDYParYawRateInputPeak_c
VDY_DECL_CONST(float32, VDYParYawRateInputPeak_c)

/// [rad/s/20ms] threshold steering wheel angle input signal diff peak 
#define VDY_PAR_SWA_INPUT_PEAK VDYParSwaInputPeak_c
VDY_DECL_CONST(float32, VDYParSwaInputPeak_c)

/// [m/s^2/20ms] threshold lat accel input signal diff peak 
#define VDY_PAR_LAT_ACCEL_INPUT_PEAK VDYParLatAccelInputPeak_c
VDY_DECL_CONST(float32, VDYParLatAccelInputPeak_c)

/// [m/s^2/20ms] threshold long accel input signal diff peak 
#define VDY_PAR_LONG_ACCEL_INPUT_PEAK VDYParLongAccelInputPeak_c
VDY_DECL_CONST(float32, VDYParLongAccelInputPeak_c)

/// [m/s/20ms] threshold wheel velocity input signal diff peak 
#define VDY_PAR_WHEEL_VELO_INPUT_PEAK VDYParWheelVelocityInputPeak_c
VDY_DECL_CONST(float32, VDYParWheelVelocityInputPeak_c)

/// Max YawRate Variance
#define VDY_YAWRATE_MAX_VARIANCE VDYYawrateMaxVariance_c
VDY_DECL_CONST(float32, VDYYawrateMaxVariance_c)

/// Min YawRate Variance
#define VDY_YAWRATE_MIN_VELOCITY VDYYawrateMinVelocity_c
VDY_DECL_CONST(float32, VDYYawrateMinVelocity_c)

/// Max Velocity Variance
#define VDY_VELOCITY_MAX_VARIANCE VDYVelocityMaxVariance_c
VDY_DECL_CONST(float32,VDYVelocityMaxVariance_c)

/// Threshold probability of RTB Recognition for the Roll Test Bench Detection 
#define VDY_RTB_THRESHOLD VDYRTBRecognitionThreshold_c
VDY_DECL_CONST(float32,VDYRTBRecognitionThreshold_c)	

/// Max Dynamic Velocity Variance 
#define VDY_VELOCITY_MAX_VARIANCE_DYNAMIC VDYVelocityMaxVarianceDynamic_c
VDY_DECL_CONST(float32,VDYVelocityMaxVarianceDynamic_c)

/// [1] Maximum of permitted cycles to reset the DEM once the velocity is within range 
#define VDY_PAR_VMON_CYCLE_IN VDYParVmonCyleIn_c
VDY_DECL_CONST(uint32, VDYParVmonCyleIn_c)

/*****************************************************************************
vehicle yaw yaw rate estimation parameter
*****************************************************************************/

/// vehicle yaw yaw rate estimation parameter
VDY_DECL_CONST( float32, vdy_ye_R_curve_p[VDY_THREE])


/*****************************************************************************
setting project specific values will override the generic values
*****************************************************************************/
/// [rad/sec] Maximum delta allowed for new offset value  
#define MAX_LIMITATION_DELTA_YAW_RATE_OFFSET			(DEG2RAD(4.0F))

/// [rad/sec] Maximum allowed threshold value between gier yaw rate and front axle, rear axle 
#define VDY_YAW_RATE_DIFF_THRESHOLD				(DEG2RAD(7.0F))

/// [VDY Cycle] no of cycles to come out of the b_turn_table_flag 
#define VDY_TURN_TABLE_ENABLE_TIME				(25U)

/// node standard deviation - For 30% allowed velociy Correction VDY_CORR_ABS_DEV is 0.3 so for the intial Deviation to be the same 0.03333333 then it should be 0.3/9 
#define VDY_CORR_INIT_STD_DEV           (VDY_CORR_ABS_DEV/9.F)           

/// unused NVM position
#define VDY_NVM_POS_TWELVE              (12)

/// unused NVM position	
#define VDY_NVM_POS_FOURTEEN            (14)

/// unused NVM position
#define VDY_NVM_POS_SIXTEEN             (16)

/// unused NVM position
#define VDY_NVM_POS_EIGHTEEN            (18)

/// unused NVM position
#define VDY_NVM_POS_TWENTY              (20)

/// unused NVM position
#define VDY_NVM_POS_TWENTYTWO           (22)

/// unused NVM position
#define VDY_NVM_POS_TWENTYFOUR          (24)

/// unused NVM position
#define VDY_NVM_POS_TWENTYSIX           (26)

/// unused NVM position
#define VDY_NVM_POS_TWENTYEIGHT         (28)

/// unused NVM position
#define VDY_NVM_POS_THIRTY              (30)

//For nvm RANGE CHECK in vdy_main 
/// Min Wheel Load Distribution 
#define MINIMUM_WHEEL_LOAD_DEP       (0.0F)

/// Max Wheel Load Distribution 
#define MAXIMUM_WHEEL_LOAD_DEP       (3.0F)

/// Max Self Steering Gradient 
#define MAXIMUM_SELF_STEERING_GRAD   (CML_Deg2Rad(0.4F))

/// Min Self Steering Gradient
#define MINIMUM_SELF_NVM_STEERING_GRAD   (0.0F)

/*** END OF SINLGE INCLUDE SECTION ******************************************/
#endif

/** @} */ 
/* EOF */
