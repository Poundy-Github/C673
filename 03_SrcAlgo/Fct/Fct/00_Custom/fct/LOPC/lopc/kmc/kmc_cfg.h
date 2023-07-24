/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/KMC (Adaptive Cruise Control - Longitudinal Planner and Controller - Kinematic Motion Control)

PACKAGENAME:               kmc_cfg.h

DESCRIPTION:               Configuration file for CruiseControl functionality in KMC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.14.7.1 $

LEGACY VERSION:            Revision: 1.13.1.1
**************************************************************************** */

#ifndef KMC_CFG_H_INCLUDED
#define KMC_CFG_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/*!
@defgroup   kmc_custom KMC_Custom
@ingroup    lopc_custom_lopc
@brief      Module for KMC custom files
 */

/*!
@defgroup   kmc_cfg Kmc_cfg
@ingroup    kmc_custom
@brief      KMC Config File
@{ */ 

/*****************************************************************************
  Config: Functionalities and Features
*****************************************************************************/

/*! Configuration switch enabeling Full Speed Range Adaptive Cruise Control functionality 
    (with object evaluation and stop and go capability) */
#define FCT_CFG_FSRACC                          (1)
#define FCT_CFG_DM                              (0)
#define FCT_CFG_FCA                             (0) /* @todo: currently disabled since access to VehSig needed, see FCT_SEN_CFG_VEH_SIG_INPUT */

#define CFG_FCT_LIM                               (0) /*! speed limiter support */
#define CFG_FCT_FLIM                              (0) /*! FLIM support */
#define CFG_FCT_PLIM                              (0) /*! PLIM support */

#define KMC_CFG_AUTOGO_FEATURE                    (0) /*! Support for AutoGo feature in KMC */
#define KMC_CFG_OVERTAKE_SUPPORT_FEATURE          (0) /*! Support for Overtake support feature in KMC */
#define KMC_CFG_HI_NAVI_FEATURE                   (0) /*! HI specific Navi feature (speed control regarding speed traps and curve)*/  

/*****************************************************************************
  Config: KMC (Kinematic Motion Controller functions)
*****************************************************************************/

/*! Use a special accel/decel mode where a specific acceleration request is used as long as the driver wants so */
#define CFG_FCT_CC_USE_ACCEL_DECEL_MODE           (0)

/*! Ramp ReqAcceleration to -2m/s² to hold vehicle in standstill as dynamic part is not able to... */
#define CFG_FCT_CC_USE_HOLD_STILLSTAND_MOD        (0)

/*! Reset Setspeed */
#define CFG_FCT_CC_RST_SETSPEED_DECEL_ONLY        (0)

/*! Only accept confirmation to drive off in standstill if driver as pressed Resume twice */
#define CFG_FCT_USE_TWICE_CONFIRMATION_FOR_DRIVE_OFF        (0)

/*! Use host accel from VDY, otherwise aInit will be used for velocity prediction */
/*! Cfg to be duplicated in lohp_cfg.h as well */
#define CFG_FCT_USE_VDY_HOST_ACCEL                          (1)

/*! Only display object in host lane */
#define CFG_FCT_DISPLAY_OBJ_ONLY_IN_HOST_LANE               (1)

/*! Use predictied host velocity for lateral accelration calculation */
#define CFG_FCT_USE_PRED_VELO_FOR_ALAT                      (1)

/*! Use customer specific accel/decel arbitration logic */
#define KMC_CFG_CUSTOM_ACCEL_ARBITRATION                    (0)

/*****************************************************************************
  Config: CC (Cruise Control)
*****************************************************************************/

/*! Straps to enable/disable specific functionality within the Cruise Control function */
#define CFG_FCT_CC_USE_BRAKE                      (1) /*use brakes also for cruise controll*/
#define CFG_FCT_CC_USE_LAT_LIM                    (1) /*use lateral limiter*/
#define CFG_FCT_CC_USE_DECEL_LIM_OVERRIDE         (1) /*do not brake more than XXX after driver override (also to relevant objects)*/
#define CFG_FCT_CC_USE_DECEL_LIM_ENGAGE           (1) /*do not brake more than XXX after engagement and override (without objects)*/
#define CFG_FCT_CC_USE_BRAKES_FOR_LAT_LIM         (1) /*use brakes for lateral limiter (only valid with CFG_FCT_CC_USE_LAT_LIM)*/
#define CFG_FCT_CC_BRAKE_LAT_LIM_AFTER_OR         (1) /*use brakes for lateral limiter also after override (only valid with CFG_FCT_CC_USE_BRAKES_FOR_LAT_LIM)*/
#define CFG_FCT_CC_USE_SMOOTH_JERKS               (0) /*use logic to use smooth gradients for acceleration request*/
#define CFG_FCT_CC_USE_MIN_MAX_DISENGAGEMENT      (0) /*normal cartronic interface at disengagement the max_req_accel ramps out to maximum, the min_req_accel to minimum, else both to zero*/
#define CFG_FCT_CC_USE_ACCEL_BAND_MODIFICATION    (0) /*spread acceleration request band (min/max acceleration) to allow the vehicle to "roll" as long as its acceleration is within the band*/
#define CFG_FCT_CC_CHANGE_SETSPEED_WHILE_READY_MODE (1) /* Allow the change of the setspeed even in ready mode*/
#define CFG_FCT_INIT_ACCEL_AFTER_STANDSTILL       (0) /*Init Accel*/
#define CFG_FCT_CC_NO_ACCEL_LIM_IN_DISENGAGE      (1) /*do not limit accel request in disengage mode (band will ever run to Acc_max_accel_disengage and Acc_min_accel_disengage or until acknowledge)*/
#define CFG_FCT_CC_USE_HIGH_MIN_MAX_ACCEL_LIMIT   (0) /*this strap raises the maximum limit of a_req_max and lowers the minimum limit of a_req_min to avoid brake intervention*/
#define CFG_FCT_CC_USE_LONG_ACCEL_CUSTOM_LIMIT    (1) /* if custom limitation of longitudinal acceleration is needed, use CC_LIMIT_LONG_ACCEL_CUSTOM fuction in custom part
                                                         the specific customer requirements should be available for using this function */
#define CFG_FCT_CC_USE_CONTROL_CRITICALITY        (0) /* To get a faster reaction of the longitudinal controller, the smoothing of the jerk is reduced, if the traffic situation is critical (e.g. leading vehicle brakes strongly) */
#define CFG_FCT_CC_SMOOTH_ACCEL_REQUEST           (1) /* Filter to prevent oscillations and other discontinuous waveforms in acceleration request, which could lead to uncomfortable system behavior*/
#define CFG_FCT_CC_USE_DRIVE_MODE                 (1) /* Custom drive mode for different control modes like comfort, eco and sport */
#define CFG_FCT_CC_USE_CUSTOM_ACCEL_LIMITS        (1) /* Use custom CC acceleration limits */ 
#define CFG_FCT_CC_USE_PLIM_CONTROL_STATE         (0) /* If 1 permanent limiter afect state mashine and engagement conditions */
#define CFG_FCT_CC_ALLOW_INIT_ACCEL_REQUEST       (1) /* If newly engaged, init requested acceleration to host vehicle acceleration */
#define CFG_FCT_CC_PARAMS_DEBUG                   (0) /* CC paramereters are frozen for debugging */
#define KMC_NO_SMOOTH_JERK_IN_LOW_SPEED           (0) /* Usage of smooth jerks stopped at low ego speeds */
#define KMC_INC_LAT_LIMITS_IN_FOLLOW              (0) /* Lateral limitation limits increased when in follow mode */
#define KMC_CFG_CUSTOM_LAT_LIM                    (0) /* Custom calculation of lateral acceleration limitation */

/*****************************************************************************
  Config: Cart/CC (CARTRONIC Interface within CC)
  Formerly in fct_glob_ext.h
*****************************************************************************/

/*! use handshake (disengagement request / acknowledge) over CARTRONIC */
#define CFG_FCT_CART_USE_DISENGAGE_HANDSHAKE      (0)

/*! allow to jump always to A_INIT, not only in some special cases */
#define CFG_FCT_ALWAYS_ALLOW_INITIALISATION       (1)

/*! use accel gain functionality for acceleration low speed range*/
#define CFG_FCT_USE_ACCEL_GAIN                    (0)

/** @} end defgroup */

//for cn acc state machine
#define CN_ACCSM									SWITCH_ON  

//for cn acc state machine with BOM state
#define CN_ACCSM_BOM								FCT_CFG_DEPENDENT_SWITCH(CN_ACCSM, SWITCH_ON)

#endif /* ifndef KMC_CFG_H_INCLUDED */
