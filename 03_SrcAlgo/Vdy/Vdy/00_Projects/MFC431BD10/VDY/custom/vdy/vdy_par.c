/*! \file **********************************************************************

  @defgroup VdyParametersC VDY Parameters Definition

  @{

  $Company:			Continental AG $

  $Component:		VDY (Vehicle Dynamics Observer) $

  $Module:			vdy_par.c $

  @brief			Vehicle Dynamics parameter definition
  
  $Descripion:		$

  $Revision: 1.1 $
  
  CHANGES:
  ---*/ /*---

*****************************************************************************/
/* ###Suggested TCI Code Review###:It is legacy code of ARS301 , alreay reviewed and working fine without any critical issue " */
/* PRQA S 3412,3410 EOF */

/* ###Suggested TCI Code Review###:Const Parameter definition skip declaration " */
/* PRQA S 3408 EOF */

/// Switch from definition to decleration in parameter header file
#define VDY_DEF_CONST(type_, name_,value_)   VDY_CONST type_ name_ = (value_);

/* @todo define special memory section for parameters */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "vdy_glob.h"
#include "vdy_par.h"


/*****************************************************************************
  PARAMETER DEFINITION
*****************************************************************************/

/*! Definition of parameters. The assigned values and therby this file are 
    certainly project specific. On the ohter hand the coresponding par header 
    file (decleration of parameters) is project independent.
 */

/// Number of bybass cycles in case of non-valid sensor input signals 
VDY_DEF_CONST(sint32, VDYParBckpCntrFrzMax_c, 20)

/// Quality threshold for uncalibrated steering wheel angle sensor 
VDY_DEF_CONST(fQuality_t, VDYParYwQThrSwaUc_c, 0.5F)

/* Einfluss von Cache-Offset (Overlay) an wirksamen Offset 0 -> kein Einfluss 
   max. Wert sollte <= 0.5 sein, und THRLD_SWA_CAL < THRLD_SWA_UC */

/// Quality threshold for calibrated steering wheel angle sensor 
VDY_DEF_CONST(fQuality_t, VDYParYwQThrSwaCal_c, 0.1F)

/// Steering wheel angle repeat reinit histo counter max to releas a dem event 
VDY_DEF_CONST(uint8, VDYParErrSwaReInit_c, 3U)

/// [m/s]  Ego velocity threshold in km/h to indicate course estimation error 
VDY_DEF_CONST(fVelocity_t,VDYParErrVehVelThr_c, (-1.0F))

/// [s] Averaging time for fast standstill calibration 
VDY_DEF_CONST(fTime_t, VDYParYwrStstCalTimeMin_c, 0.3F)

/// [s] Averaging time for normal, secure standstill calibration  
VDY_DEF_CONST(fTime_t, VDYParYwrStstCalTimeNorm_c, 1.0F)

/// [s] Filter time constant for input filter of yaw rate sensor signal  
VDY_DEF_CONST(fTime_t, VDYParYwrYwRtFilT_c, 0.25F)

/// [(m/s)^2] Velocity variance in case of external conditioned velocity  
VDY_DEF_CONST(fVariance_t, VDYParVelExtUnc_c, 0.0F)

/// [(m/s^2)^2] Acceleration variance in case of external conditioned acceleration 
VDY_DEF_CONST(fVariance_t, VDYParAccelExtUnc_c, 0.0F)

/// [(1/m)^2] Curvature variance in case of external conditioned curvature 
VDY_DEF_CONST(fVariance_t, VDYparCrvExtUnc_c, 0.0F)

/// [(rad/s)^2] Yaw rate variance in case of external conditioned yaw rate 
VDY_DEF_CONST(fVariance_t, VDYparYwrExtUnc_c, 0.0F)

/// [(rad/s)^2] Side slip angle variance in case of external conditioned yaw rate 
VDY_DEF_CONST(fVariance_t, VDYparSsaExtUnc_c, 0.0F)

/// [s] Filter time constant for external velocity differentiator  
VDY_DEF_CONST(fTime_t, VDYParVelDiffFilT_c, 0.2F)

/// [(rad)^2] Steer wheel angle variance in case of external conditioned 
VDY_DEF_CONST(fVariance_t, VDYparSwaExtUnc_c, 0.0F)

/// [(rad)^2] Rear wheel angle variance in case of external conditioned 
VDY_DEF_CONST(fVariance_t, VDYparRwaExtUnc_c, 0.0F)

/// [1] Minimum motion state confidence for standstill yaw rate calibration 
VDY_DEF_CONST(fConfidence_t, VDYParYwrStstConfMin_c, 0.2F)

/// [1] Maximum permitted deviation of correction factor +/- 
VDY_DEF_CONST(float32, VDYParVcorAbsDev_c, 0.1F)

/// [s^2/m^2] Maximum permitted velocity dependence (k1) of correction factor = k0 + k1 * v^2 
VDY_DEF_CONST(float32, VDYParVcorVelDepMax_c, 7.2E-6F)

/// [s^2/m^2] Manimum permitted velocity dependence (k1) of correction factor = k0 + k1 * v^2 
VDY_DEF_CONST(float32, VDYParVcorVelDepMin_c, (-1.0E-6F))

/// [1] Maximum occurences of ambiguous distriubtions 
VDY_DEF_CONST(uint32, VDYParVcorThrhdCntMeasErr_c, 5U)

/// [1] Maximum occurences of measured correction factors out of range 
VDY_DEF_CONST(uint32, VDYParVcorThrhdCntRangeErr_c, 2U)

/// [1] Maximum of permitted cycles with external velocity deviation 
VDY_DEF_CONST(uint32, VDYParVmonCyleOut_c, 20U)

/// [1] Maximum of permitted cycles with external velocity deviation 
VDY_DEF_CONST(uint32, VDYParVmonCyleOutLt_c, 250U)

/// [rad] Steering wheel offset range(+/-) max. 12 deg 
VDY_DEF_CONST(fAngle_t, VDYParSwaOffsetLimitMax_c, CML_Deg2Rad(12.0F))

/// [rad] YawRate offset range(+/-) max. 2.86rad 
VDY_DEF_CONST(fYawRate_t, VDYParYwrOffsetLimitMax_c, 2.86F)

/// [(rad/(m/s^2))^2] Default understeer gradient variance if it is not present 
VDY_DEF_CONST(fVariance_t, VDYParSsgExtUnc_c, 0.0F)

/// [s] Filter time constant of raw yaw rate offset 
VDY_DEF_CONST(fYawRate_t, VDYParRawYawRateOffsetFT_c, 100.0F)

/// [deg] ACC event (yaw rate offset not ok for ACC) is set if difference between alignment offset and vdy offset is above
VDY_DEF_CONST(fYawRate_t, VDYParACCYawRateOffsError_c,0.3F)

/// [deg] ACC event (yaw rate offset not ok for ACC) is set off if difference between alignment offset and vdy offset is below
VDY_DEF_CONST(fYawRate_t, VDYParACCYawRateOffsErrorOff_c,0.3F)

/// [ms] ACC threshold time for event (yaw rate offset not ok for ACC) 
VDY_DEF_CONST(uint32, VDYParACCYawRateOffsThldTime_c, 180000U)

/// [deg] CG event (yaw rate offset not ok for CG) is set if difference between alignment offset and vdy offset is above
VDY_DEF_CONST(fYawRate_t, VDYParCGYawRateOffsError_c,0.45F)

/// [deg] CG event (yaw rate offset not ok for CG) is set off if difference between alignment offset and vdy offset is below
VDY_DEF_CONST(fYawRate_t, VDYParCGYawRateOffsErrorOff_c,0.45F)

/// [ms] CG threshold time for event (yaw rate offset not ok for CG) 
VDY_DEF_CONST(uint32, VDYParCGYawRateOffsThldTime_c, 300U)

/// [rad/s/20ms] threshold yaw rate input signal diff peak 
VDY_DEF_CONST(float32, VDYParYawRateInputPeak_c, DEG2RAD(14.5F))

/// [rad/s/20ms] threshold steering wheel angle input signal diff peak 
VDY_DEF_CONST(float32, VDYParSwaInputPeak_c, DEG2RAD(40.0F))

/// [m/s^2/20ms] threshold lat accel input signal diff peak 
VDY_DEF_CONST(float32, VDYParLatAccelInputPeak_c, 10.0F)

/// [m/s^2/20ms] threshold long accel input signal diff peak 
VDY_DEF_CONST(float32, VDYParLongAccelInputPeak_c, 7.5F)

/// [m/s/20ms] threshold wheel velocity input signal diff peak 
VDY_DEF_CONST(float32, VDYParWheelVelocityInputPeak_c, 10.0F)

/// [rad^2] Threshold of variance of current yawrate 
VDY_DEF_CONST(float32 , VDYYawrateMaxVariance_c ,   0.025F )

/// [m/s] Minimum velocity for yawrate variance consideration 
VDY_DEF_CONST(float32 , VDYYawrateMinVelocity_c ,   1.0F )

/// (m/s)^2 Threshold of variance of current velocity for availability 
VDY_DEF_CONST(float32 , VDYVelocityMaxVariance_c ,   30.0F )

/// Threshold probability of RTB Recognition for the Roll Test Bench Detection 
VDY_DEF_CONST(float32 , VDYRTBRecognitionThreshold_c ,   0.7F )				

/// (m/s)^2 Threshold of variance of current velocity during dynamic acceleration for availability 
VDY_DEF_CONST(float32 , VDYVelocityMaxVarianceDynamic_c ,   55.0F )

/// [1] Maximum of permitted cycles to reset the DEM once the velocity is within range 
VDY_DEF_CONST(uint32, VDYParVmonCyleIn_c, 10U)
/*****************************************************************************
vehicle yaw yaw rate estimation parameter
*****************************************************************************/

/** @} */ 
/* EOF */
