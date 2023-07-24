/* $Header: dmc_if.h 1.12 2020/05/04 15:55:48CEST Feick, Stefan (uidw0691) none  $ */
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

#ifndef DMC_IF_H_INCLUDED
#define DMC_IF_H_INCLUDED


/* ------------------------- */
/*      Global functions     */
/* ------------------------- */


/* ------------------------- */
/*       Global symbols      */
/* ------------------------- */

lvc_ram_prio1 signed_int16_t DMC_EPS_TRQ_REQ;
/*!< @ASAP_NAME DMC_EPS_TRQ_REQ @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Vehicle yaw torque request for actuator wheel brake (DMC_EPS_TRQ_REQ) */
        
lvc_ram_prio1 signed_int16_t LaDMC_status;
/*!< @ASAP_NAME LaDMC_status @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 7 @OFFSET 0 @brief comment (LaDMC_status) */
        
lvc_ram_prio1 signed_int16_t LADMC_EPS_TORQUE_REQUEST;
/*!< @ASAP_NAME LADMC_EPS_TORQUE_REQUEST @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LADMC_EPS_TORQUE_REQUEST) */
        
lvc_ram_prio1 signed_int16_t LaDMC_Eps_Request_Flag;
/*!< @ASAP_NAME LaDMC_Eps_Request_Flag @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 7 @OFFSET 0 @brief comment (LaDMC_Eps_Request_Flag) */
        
lvc_ram_prio1 signed_int16_t LADMC_EPS_INTERFACE_ACTIVE_REQ;
/*!< @ASAP_NAME LADMC_EPS_INTERFACE_ACTIVE_REQ @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 7 @OFFSET 0 @brief comment (LADMC_EPS_INTERFACE_ACTIVE_REQ) */
        
lvc_ram_prio1 unsigned_char_t DMC_LAT_EPS_DAMP_LVL_REQ;
/*!< @ASAP_NAME DMC_LAT_EPS_DAMP_LVL_REQ @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (DMC_LAT_EPS_DAMP_LVL_REQ) */
        
lvc_ram_prio1 signed_int16_t DMC_LAT_STATUS;
/*!< @ASAP_NAME DMC_LAT_STATUS @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (DMC_LAT_STATUS) */
        
lvc_ram_prio1 unsigned_int16_t DMC_EPS_STATUS;
/*!< @ASAP_NAME DMC_EPS_STATUS @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (DMC_EPS_STATUS) */
        
lvc_ram_prio1 unsigned_char_t MTO_HALF_SYSTEM_STS;
/*!< @ASAP_NAME MTO_HALF_SYSTEM_STS @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 1 @OFFSET 0 @brief comment (MTO_HALF_SYSTEM_STS) */
        
lvc_ram_prio1 signed_int16_t LADMC_STEER_ANGLE_RATE_REQ;
/*!< @ASAP_NAME LADMC_STEER_ANGLE_RATE_REQ @UNIT - @LSB 0.0039062500 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LADMC_STEER_ANGLE_RATE_REQ) */
        
lvc_ram_prio1 unsigned_char_t LADMC_STIFFNESS_LEVEL_REQUEST;
/*!< @ASAP_NAME LADMC_STIFFNESS_LEVEL_REQUEST @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LADMC_STIFFNESS_LEVEL_REQUEST) */
        
lvc_ram_prio1 signed_int16_t LADMC_STEER_ANGLE_REQ;
/*!< @ASAP_NAME LADMC_STEER_ANGLE_REQ @UNIT deg @LSB 0.0437500000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LADMC_STEER_ANGLE_REQ) */
        
lvc_ram_prio1 unsigned_char_t LADMC_ACCURACY_LEVEL_REQUEST;
/*!< @ASAP_NAME LADMC_ACCURACY_LEVEL_REQUEST @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LADMC_ACCURACY_LEVEL_REQUEST) */
        
lvc_ram_prio1 unsigned_char_t LADMC_DERATING_FACTOR_REQUEST;
/*!< @ASAP_NAME LADMC_DERATING_FACTOR_REQUEST @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LADMC_DERATING_FACTOR_REQUEST) */
        
lvc_ram_prio1 signed_int16_t DMC_LONG_ENG_TRQ_REQ;
/*!< @ASAP_NAME DMC_LONG_ENG_TRQ_REQ @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief - (DMC_LONG_ENG_TRQ_REQ) */
        
lvc_ram_prio1 signed_int16_t DMC_LONG_BRK_TRQ_REQ;
/*!< @ASAP_NAME DMC_LONG_BRK_TRQ_REQ @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief - (DMC_LONG_BRK_TRQ_REQ) */
        
lvc_ram_prio1 unsigned_char_t LAT_Activation_Request_nu;
/*!< @ASAP_NAME LAT_Activation_Request__nu @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LAT_Activation_Request__nu) */
        
lvc_ram_prio1 unsigned_char_t LAT_Activation_Request_Qf_nu;
/*!< @ASAP_NAME LAT_Activation_Request_Qf__nu @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LAT_Activation_Request_Qf__nu) */
        
lvc_ram_prio1 unsigned_char_t LAT_Force_Shut_Off_Request;
/*!< @ASAP_NAME LAT_Force_Shut_Off_Request @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LAT_Force_Shut_Off_Request) */
        
lvc_ram_prio1 signed_int16_t LAT_Steer_Angle_Command_deg;
/*!< @ASAP_NAME LAT_Steer_Angle_Command__deg @UNIT deg @LSB 0.0244160000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Steer_Angle_Command__deg) */
        
lvc_ram_prio1 signed_int16_t LAT_Road_Wheel_Angle_Cmd_deg;
/*!< @ASAP_NAME LAT_Road_Wheel_Angle_Cmd__deg @UNIT deg @LSB 0.0025000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Road_Wheel_Angle_Cmd__deg) */
        
lvc_ram_prio1 signed_int16_t LAT_Kappa_Sum_Command_1pm;
/*!< @ASAP_NAME LAT_Kappa_Sum_Command__1pm @UNIT 1/m @LSB 0.0000200000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Kappa_Sum_Command__1pm) */
        
lvc_ram_prio1 signed_int16_t LAT_Torque_Overlay_Request_nm;
/*!< @ASAP_NAME LAT_Torque_Overlay_Request__nm @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Torque_Overlay_Request__nm) */
        
lvc_ram_prio1 unsigned_char_t LAT_Stiffness_Request_per;
/*!< @ASAP_NAME LAT_Stiffness_Request__per @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LAT_Stiffness_Request__per) */
        
lvc_ram_prio1 unsigned_char_t LAT_Accuracy_Request_per;
/*!< @ASAP_NAME LAT_Accuracy_Request__per @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LAT_Accuracy_Request__per) */
        
lvc_ram_prio1 unsigned_char_t LAT_Steering_Wheel_Vibration_nu;
/*!< @ASAP_NAME LAT_Steering_Wheel_Vibration__nu @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LAT_Steering_Wheel_Vibration__nu) */
        
lvc_ram_prio1 unsigned_char_t LAT_Lane_Status_nu;
/*!< @ASAP_NAME LAT_Lane_Status__nu @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LAT_Lane_Status__nu) */
        
lvc_ram_prio1 unsigned_char_t LAT_Derating_Level_Request_per;
/*!< @ASAP_NAME LAT_Derating_Level_Request__per @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LAT_Derating_Level_Request__per) */
        
lvc_ram_prio1 signed_int16_t DMC_LAT_STATUS;
/*!< @ASAP_NAME DMC_LAT_STATUS @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (DMC_LAT_STATUS) */
        
lvc_ram_prio1 unsigned_char_t MTO_HALF_SYSTEM_STS;
/*!< @ASAP_NAME MTO_HALF_SYSTEM_STS @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 1 @OFFSET 0 @brief comment (MTO_HALF_SYSTEM_STS) */
        
lvc_ram_prio1 signed_int16_t DMC_LONG_ENG_TRQ_REQ;
/*!< @ASAP_NAME DMC_LONG_ENG_TRQ_REQ @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief - (DMC_LONG_ENG_TRQ_REQ) */
        
lvc_ram_prio1 signed_int16_t DMC_LONG_BRK_TRQ_REQ;
/*!< @ASAP_NAME DMC_LONG_BRK_TRQ_REQ @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief - (DMC_LONG_BRK_TRQ_REQ) */
        
lvc_ram_prio1 unsigned_char_t LAT_Torque_Ramp_Factor_per;
/*!< @ASAP_NAME LAT_TRQ_RAMP_FACTOR @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief - (LAT_Torque_Ramp_Factor__per) */
        
lvc_ram_prio1 signed_int16_t DMC_ANGLE_OFF;
/*!< @ASAP_NAME DMC_ANGLE_OFF @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steer angle offset to be written to the Eeprom (DMC_ANGLE_OFF) */
        
lvc_ram_prio1 signed_int16_t DMC_Steer_Angle_Oc_deg;
/*!< @ASAP_NAME DMC_Steer_Angle_Oc__deg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steer angle, offset corrected (DMC_Steer_Angle_Oc__deg) */
        
lvc_ram_prio1 signed_int16_t DMC_Eps_Integrator_Hold_Req_nu;
/*!< @ASAP_NAME DMC_Eps_Integrator_Hold_Req__nu @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 7 @OFFSET 0 @brief comment (DMC_Eps_Integrator_Hold_Req__nu) */
        
lvc_ram_prio1 signed_int16_t DMC_Limiter_Status_nu;
/*!< @ASAP_NAME DMC_Limiter_Status__nu @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 7 @OFFSET 0 @brief comment (DMC_Limiter_Status__nu) */
        
lvc_ram_prio1 unsigned_int16_t DMC_ANGLE_OFF_CALIB_CNT;
/*!< @ASAP_NAME DMC_ANGLE_OFF_CALIB_CNT @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steer angle offset calibration counter to be written to the Eeprom (DMC_ANGLE_OFF_CALIB_CNT) */
        
lvc_ram_prio1 unsigned_char_t DMC_ADP_CORR_FACTOR_POS[20];
/*!< @ASAP_NAME DMC_ADP_CORR_FACTOR_POS @UNIT - @LSB 0.0078125000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steering characteristic correction factor left vector (DMC_ADP_CORR_FACTOR_POS) */
        
lvc_ram_prio1 unsigned_char_t DMC_ADP_CORR_FACTOR_NEG[20];
/*!< @ASAP_NAME DMC_ADP_CORR_FACTOR_NEG @UNIT - @LSB 0.0078125000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steering characteristic correction factor right vector (DMC_ADP_CORR_FACTOR_NEG) */
        
lvc_ram_prio1 unsigned_int16_t DMC_ADP_CORR_COUNTER_POS[20];
/*!< @ASAP_NAME DMC_ADP_CORR_COUNTER_POS @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steering characteristic correction factor counter left vector (DMC_ADP_CORR_COUNTER_POS) */
        
lvc_ram_prio1 unsigned_int16_t DMC_ADP_CORR_COUNTER_NEG[20];
/*!< @ASAP_NAME DMC_ADP_CORR_COUNTER_NEG @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steering characteristic correction factor counter right vector (DMC_ADP_CORR_COUNTER_NEG) */
        

/* ------------------------- */
/*      Get Functions        */
/* ------------------------- */


#endif  /* DMC_IF_H_INCLUDED */
