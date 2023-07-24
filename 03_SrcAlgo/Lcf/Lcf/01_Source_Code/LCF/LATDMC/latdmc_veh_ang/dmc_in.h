/* $Header: dmc_in.h 1.13 2020/05/04 15:55:49CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
***************************************************************************************************
 Confidential and proprietary. This document and its contents are the exclusive property of
 Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
 associated companies. They are not to be copied, distributed, or otherwise disclosed or used
 without the prior written consent of Teves and Temic. All rights reserved.
 ABS/EBD/TCS/ESC-Controller Software.
***************************************************************************************************
Detailed informations to rebuild this code:
$TracibilityInfo$

***************************************************************************************************
$FunctionModelName$
***************************************************************************************************
Change record:
No change record because auto code generated.
***************************************************************************************************
*/

#ifndef DMC_IN_H_INCLUDED
#define DMC_IN_H_INCLUDED


#include "dmc_ac.h"

#include "lodmc.h"


/* ------------------------- */
/*  Table of used symbols    */
/* ------------------------- */
/*

EST_REFERENCE_VELOCITY 
    TYPE: signed_int16_t LSB:0.0100000000 UNIT:kph NAME:ERV_Vel REM:Estimated vehicle velocity
DMC_CAM_CRVT_FEED_FWD 
    TYPE: signed_int16_t LSB:0.0000200000 UNIT:1/m NAME:DMC_CAM_CRVT_FEED_FWD REM:Curvature command from the camera regarding middle of lane without modification by trajectory planner
DMC_CAM_LAT_ERR 
    TYPE: signed_int16_t LSB:0.0009765625 UNIT:m NAME:DMC_CAM_LAT_ERR REM:Lateral error with respect to the middle of the lane as seen by the camera without modification by the trajectory planner
DMC_CAM_HDNG_AG_ERR 
    TYPE: signed_int16_t LSB:0.0000305176 UNIT:rad NAME:DMC_CAM_HDNG_AG_ERR REM:Heading error with respect to the middle of the lane as seen by the camera without modification by the trajectory planner
DMC_CAM_CRVT_FEED_FWD_QF 
    TYPE: signed_int16_t LSB:1.0000000000 UNIT:- NAME:DMC_CAM_CRVT_FEED_FWD_QF REM:Qualifier of the pure curvature command from the camera
DMC_CAM_LAT_ERR_QF 
    TYPE: signed_int16_t LSB:1.0000000000 UNIT:- NAME:DMC_CAM_LAT_ERR_QF REM:Qualifier of the lateral error with respect to the middle of the lane as seen by the camera
DMC_CAM_HDNG_AG_ERR_QF 
    TYPE: signed_int16_t LSB:1.0000000000 UNIT:- NAME:DMC_CAM_HDNG_AG_ERR_QF REM:Qualifier of the heading error with respect to the middle of the lane as seen by the camera
DMC_FORCE_SHUT_OFF_REQUEST 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:DMC_FORCE_SHUT_OFF_REQUEST REM:Force shut down of Lateral DMC by Trajectory controller
DMC_SHUT_OFF_ON_ERROR 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:DMC_SHUT_OFF_ON_ERROR REM:Force shut down of Lateral DMC in case of error
FILTERED_STEER_ANGLE 
    TYPE: signed_int16_t LSB:0.0015260000 UNIT:deg NAME:FSTANGLE REM:lateral vehicle control - steer angle provided by stability control
FILTERED_STEER_ANGLE_RATE 
    TYPE: signed_int16_t LSB:0.0437500000 UNIT:- NAME:FSTANGLEP REM:lateral vehicle control - steer angle rate provided by stability control
UNCALIBRATED_SWA_FIL 
    TYPE: signed_int16_t LSB:0.0437500000 UNIT:deg NAME:RAWSWAFL REM:lateral vehicle control - filtered uncalibrated steer wheel angle
DMC_FILTERED_YAW_RATE 
    TYPE: signed_int16_t LSB:0.0028600000 UNIT:- NAME:DMCFYAWRATE REM:DMC filtered yaw rate
DMC_FILTERED_YAW_RATE_QF 
    TYPE: signed_int16_t LSB:1.0000000000 UNIT:- NAME:DMCFYAWRATEQF REM:DMC filtered yaw rate qualifier
DMC_FILTERED_LATERAL_ACC_COG 
    TYPE: signed_char_t LSB:0.0981000000 UNIT:m/s/s NAME:DMCFLATACCC REM:DMC filtered lateral acceleration at center of gravity
DMC_FILTERED_LATERAL_ACC_COG_QF 
    TYPE: signed_int16_t LSB:1.0000000000 UNIT:- NAME:DMCFLATACCCQF REM:DMC filtered lateral acceleration at center of gravity qualifier
DMC_FILTERED_STEER_ANGLE 
    TYPE: signed_int16_t LSB:0.0015260000 UNIT:deg NAME:DMCFSTANGLE REM:DMC filtered steer angle (FSTANGLE)
DMC_FILTERED_STEER_ANGLE_QF 
    TYPE: signed_int16_t LSB:1.0000000000 UNIT:- NAME:DMCFSTANGLEQF REM:DMC filtered steer angle (FSTANGLE) qualifier
DMC_FILTERED_STEER_ANGLE_RATE 
    TYPE: signed_int16_t LSB:0.0437500000 UNIT:- NAME:DMCFSTANGLERATE REM:DMC filtered steer angle rate
DMC_FILTERED_STEER_ANGLE_RATE_QF 
    TYPE: signed_int16_t LSB:1.0000000000 UNIT:- NAME:DMCFSTANGLERATEQF REM:DMC filtered steer angle rate qualifier
DMC_STEER_ANGLE_OFFSET 
    TYPE: signed_int16_t LSB:0.0010000000 UNIT:rad NAME:DMCSTEERANGLEOFFSET REM:DMC steering angle offset from VDY
DMC_STEER_ANGLE_OFFSET_STATE 
    TYPE: signed_int16_t LSB:1.0000000000 UNIT:- NAME:DMCSTEERANGLEOFFSETSTATE REM:DMC steering angle offset state from VDY
DMC_YAW_RATE_OFFSET 
    TYPE: signed_int16_t LSB:0.0028600000 UNIT:deg/s NAME:DMCYAWRATEOFFSET REM:DMC yaw rate offset from VDY
DMC_YAW_RATE_OFFSET_STATE 
    TYPE: signed_int16_t LSB:1.0000000000 UNIT:- NAME:DMCYAWRATEOFFSETSTATE REM:DMC yaw rate offset state from VDY
DMC_DRIVING_MODE 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:DMC_DRIVING_MODE REM:Requested driving mode by the driver
DMC_BANK_ANGLE 
    TYPE: signed_int16_t LSB:0.0000305176 UNIT:rad NAME:DMC_BANK_ANGLE REM:Bank angle
EMO_PITCH_ANGLE 
    TYPE: signed_int16_t LSB:0.0000305176 UNIT:rad NAME:EMO_PITCH_ANGLE REM:Pitch angle
DMC_ROAD_WHEEL_ANGLE 
    TYPE: signed_int16_t LSB:0.0025000000 UNIT:deg NAME:DMC_ROAD_WHEEL_ANGLE REM:xxx
EpsSteerAngleAuthority 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:EpsSteerAngleAuthority REM:eps steer angle authority 100 HALFTorqueOverlayFault 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:HALF_TORQUE_OVERLAY_FAULT REM:
HALF_TORQUE_OVERLAY_ACTIVATED 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:HALF_TORQUE_OVERLAY_ACTIVATED REM:
EPS_TEMP_DEACTIVATION_LDW 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:EPS_TEMP_DEACTIVATION_LDW REM:
DMC_STIFFNESS_LIMIT 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:DMCSTIFFLIMIT REM:Requested DMC stiffness
DMC_STIFFNESS_GRAD 
    TYPE: signed_int16_t LSB:1.0000000000 UNIT:- NAME:DMCSTIFFGRAD REM:Requested DMC stiffness gradient
DMC_TORQUE_SCALE_LIMIT 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:DMCTRQSCALELIMIT REM:Requested DMC torque scale
DMC_TORQUE_SCALE_GRAD 
    TYPE: signed_int16_t LSB:1.0000000000 UNIT:- NAME:DMCTRQSCALEGRAD REM:Requested DMC torque scale gradient
DMC_TORQUE_RAMP_GRAD 
    TYPE: signed_int16_t LSB:1.0000000000 UNIT:- NAME:DMCTORQUERAMPGRAD REM:Requested DMC torque ramp gradient
DMC_HIGH_ACCURACY_REQUEST 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:DMCHIGHACCURACYREQUEST REM:Requested high DMC control accuracy
DMC_ANGLE_FADING_REQ 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:DMC_ANGLE_FADING_REQ REM:Request for fading the angle command
DMC_RAMPING_DOWN_REQ 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:DMC_RAMPING_DOWN_REQ REM:Request for ramping down the output torque
DMC_ANGLE_REQ_MAX_LIMIT_SCALE 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:DMC_ANGLE_REQ_MAX_LIMIT_SCALE REM:Request for reducing the angle command
DMC_ANGLE_REQ_MAX_GRAD_SCALE 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:DMC_ANGLE_REQ_MAX_GRAD_SCALE REM:Request for reducing the angle command gradient
DMC_ANGLE_OFF_LOOP0 
    TYPE: signed_int16_t LSB:0.0015260000 UNIT:deg NAME:DMC_ANGLE_OFF_LOOP0 REM:Steer angle offset read from the Eeprom
DMC_ANGLE_OFF_CALIB_CNT_LOOP0 
    TYPE: unsigned_int16_t LSB:1.0000000000 UNIT:- NAME:DMC_ANGLE_OFF_CALIB_CNT_LOOP0 REM:Steer angle offset calibration counter read from the Eeprom
DMC_ANGLE_OFF_READ_ERROR 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:DMC_ANGLE_OFF_READ_ERROR REM:Eeprom data read error
DMC_ADP_CORR_FACTOR_POS_LOOP0[20] 
    TYPE: unsigned_char_t LSB:0.0078125000 UNIT:- NAME:DMC_ADP_CORR_FACTOR_POS_LOOP0 REM:Steering characteristic correction factor left vector read from Eeprom
DMC_ADP_CORR_FACTOR_NEG_LOOP0[20] 
    TYPE: unsigned_char_t LSB:0.0078125000 UNIT:- NAME:DMC_ADP_CORR_FACTOR_NEG_LOOP0 REM:Steering characteristic correction factor right vector read from Eeprom
DMC_ADP_CORR_COUNTER_POS_LOOP0[20] 
    TYPE: unsigned_int16_t LSB:1.0000000000 UNIT:- NAME:DMC_ADP_CORR_COUNTER_POS_LOOP0 REM:Steering characteristic correction counter left vector read from Eeprom
DMC_ADP_CORR_COUNTER_NEG_LOOP0[20] 
    TYPE: unsigned_int16_t LSB:1.0000000000 UNIT:- NAME:DMC_ADP_CORR_COUNTER_NEG_LOOP0 REM:Steering characteristic correction counter right vector read from Eeprom
DMC_ADP_CORR_FACTOR_READ_ERROR 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:DMC_ADP_CORR_FACTOR_READ_ERROR REM:Eeprom data read error
DMC_DERATING_LEVEL_REQ 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:DMC_DERATING_LEVEL_REQ REM:Request for driver override capability
DMC_DRIVING_MODE 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:DMC_DRIVING_MODE REM:Requested driving mode
DMC_GPIO 
    TYPE: signed_int16_t LSB:1.0000000000 UNIT:- NAME:DMC_GPIO REM:DMC_GPIO
DMC_GPIO2 
    TYPE: signed_int16_t LSB:1.0000000000 UNIT:- NAME:DMC_GPIO2 REM:DMC_GPIO2
DMC_GPIO3 
    TYPE: signed_int16_t LSB:1.0000000000 UNIT:- NAME:DMC_GPIO3 REM:DMC_GPIO3
DMC_GPIO4 
    TYPE: signed_int16_t LSB:1.0000000000 UNIT:- NAME:DMC_GPIO4 REM:DMC_GPIO4
LAT_Dmc_Status__nu 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:LAT_Dmc_Status__nu REM:DMC status as sent by the DMC part on the IuC
LAT_Eps_Torque_Request__nm 
    TYPE: signed_int16_t LSB:0.0010000000 UNIT:Nm NAME:LAT_Eps_Torque_Request__nm REM:EPS torque a requested by the DMC part on the IuC
LODMC_REFERENCE_VEHACC 
    TYPE: signed_int16_t LSB:0.0010000000 UNIT:m/ss NAME:LODMC_REFERENCE_VEHACC REM:LODMC Reference Veh Accleration
LODMC_ARB_REQ_ACC 
    TYPE: signed_int16_t LSB:0.0010000000 UNIT:m/ss NAME:LODMC_ARB_REQ_ACC REM:LODMC arbitrated requested acceleration
LODMC_ENGINE_ALLOWED 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:LODMC_ACT_ENGINE_ALLOWED REM:Lodmc Brake Actuator with Engine Ctrl allowe
LODMC_BRAKE_ALLOWED 
    TYPE: unsigned_char_t LSB:1.0000000000 UNIT:- NAME:LODMC_ACT_BRAKE_ALLOWED REM:Lodmc Brake Actuator with Brake Ctrl allowed

*/

/* ------------------------- */
/*      Get Functions        */
/* ------------------------- */
/*


*/


#endif  /* DMC_IN_H_INCLUDED */

