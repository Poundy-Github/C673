/* $Header: dmc_ram.h 1.24 2020/08/20 10:43:23CEST Feick, Stefan (uidw0691) none  $ */
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

#ifndef DMC_RAM_H_INCLUDED
#define DMC_RAM_H_INCLUDED



/* ------------------------- */
/*       Global symbols      */
/* ------------------------- */

lvc_ram_prio1 signed_int16_t SaRateSig;
/*!< @ASAP_NAME SaRateSig @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SaRateSig) */
        
lvc_ram_prio1 signed_int16_t SaRateQ;
/*!< @ASAP_NAME SaRateQ @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SaRateQ) */
        
lvc_ram_prio1 float32 DYC_Steer_Angle_Feedforward;
/*!< @ASAP_NAME DYC_Steer_Angle_Feedforward @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (DYC_Steer_Angle_Feedforward) */
        
lvc_ram_prio1 float32 LAT_Eps_Torque_Request;
/*!< @ASAP_NAME LAT_Eps_Torque_Request @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Eps_Torque_Request) */
        
lvc_ram_prio1 unsigned_char_t SAC_Requested_Damping_Level;
/*!< @ASAP_NAME SAC_Requested_Damping_Level @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Requested_Damping_Level) */
        
lvc_ram_prio1 float32 LAT_Delta_Ys;
/*!< @ASAP_NAME LAT_Delta_Ys @UNIT m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Delta_Ys) */
        
lvc_ram_prio1 float32 LKC_Delta_Ys;
/*!< @ASAP_NAME LKC_Delta_Ys @UNIT m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LKC_Delta_Ys) */
        
lvc_ram_prio1 float32 LAT_Delta_Psi;
/*!< @ASAP_NAME LAT_Delta_Psi @UNIT rad @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Delta_Psi) */
        
lvc_ram_prio1 float32 LKC_Delta_Psi;
/*!< @ASAP_NAME LKC_Delta_Psi @UNIT rad @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LKC_Delta_Psi) */
        
lvc_ram_prio1 float32 LAT_Kappa_Command;
/*!< @ASAP_NAME LAT_Kappa_Command @UNIT 1/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Kappa_Command) */
        
lvc_ram_prio1 float32 LAT_Kappa_Prime_Command;
/*!< @ASAP_NAME LAT_Kappa_Prime_Command @UNIT 1/m/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Kappa_Prime_Command) */
        
lvc_ram_prio1 float32 LAT_Psi;
/*!< @ASAP_NAME LAT_Psi @UNIT rad @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Psi) */
        
lvc_ram_prio1 float32 SAT_Saturated_Angle_Command;
/*!< @ASAP_NAME SAT_Saturated_Angle_Command @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAT_Saturated_Angle_Command) */
        
lvc_ram_prio1 float32 SAC_Yrc_Angle_Command;
/*!< @ASAP_NAME SAC_Yrc_Angle_Command @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Yrc_Angle_Command) */
        
lvc_ram_prio1 unsigned_char_t LAT_Eps_Torque_Request_Flag;
/*!< @ASAP_NAME LAT_Eps_Torque_Request_Flag @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Eps_Torque_Request_Flag) */
        
lvc_ram_prio1 float32 LAT_Delta_F_Cmd;
/*!< @ASAP_NAME LAT_Delta_F_Cmd @UNIT deg/s @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Delta_F_Cmd) */
        
lvc_ram_prio1 float32 VEH_Delta_F;
/*!< @ASAP_NAME VEH_Delta_F @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Delta_F) */
        
lvc_ram_prio1 float32 VEH_Delta_clm_sens_F;
/*!< @ASAP_NAME VEH_Delta_Clm_Sens_F @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Delta_clm_sens_F) */
        
lvc_ram_prio1 signed_int16_t Lat_rate_limited_offset_dbg;
/*!< @ASAP_NAME Lat_rate_limited_offset_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (Lat_rate_limited_offset_dbg) */
        
lvc_ram_prio1 float32 VEH_Yaw_Rate;
/*!< @ASAP_NAME VEH_Yaw_Rate @UNIT rad/s @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Yaw_Rate) */
        
lvc_ram_prio1 float32 VEH_Yaw_Rate_Offset;
/*!< @ASAP_NAME VEH_Yaw_Rate_Offset @UNIT rad/s @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Yaw_Rate_Offset) */
        
lvc_ram_prio1 float32 VEH_Vehicle_Velocity;
/*!< @ASAP_NAME VEH_Vehicle_Velocity @UNIT m/s @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Vehicle_Velocity) */
        
lvc_ram_prio1 float32 VEH_Delta_F_Dot;
/*!< @ASAP_NAME VEH_Delta_F_Dot @UNIT deg/s @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Delta_F_Dot) */
        
lvc_ram_prio1 float32 VEH_Steer_Torque;
/*!< @ASAP_NAME VEH_Steer_Torque @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Steer_Torque) */
        
lvc_ram_prio1 float32 EPS_Tie_Rod_Load;
/*!< @ASAP_NAME EPS_Tie_Rod_Load @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (EPS_Tie_Rod_Load) */
        
lvc_ram_prio1 float32 LAT_Ext_Command;
/*!< @ASAP_NAME LAT_Ext_Command @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Ext_Command) */
        
lvc_ram_prio1 float32 EPS_Motor_Torque;
/*!< @ASAP_NAME EPS_Motor_Torque @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (EPS_Motor_Torque) */
        
lvc_ram_prio1 signed_int16_t VEH_Brake_Force_Front_Axle;
/*!< @ASAP_NAME VEH_Brake_Force_Front_Axle @UNIT N @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Brake_Force_Front_Axle) */
        
lvc_ram_prio1 signed_int16_t EPS_Status;
/*!< @ASAP_NAME EPS_Status @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (EPS_Status) */
        
lvc_ram_prio1 signed_int16_t LAT_Dmc_Status;
/*!< @ASAP_NAME LAT_Dmc_Status @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Dmc_Status) */
        
lvc_ram_prio1 signed_int16_t LaKMC_activation;
/*!< @ASAP_NAME LaKMC_activation @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 7 @OFFSET 0 @brief comment (LaKMC_activation) */
        
lvc_ram_prio1 unsigned_int16_t LCF_Operation_Mode;
/*!< @ASAP_NAME Lcf_operation_mode @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 7 @OFFSET 0 @brief comment (LCF_Operation_Mode) */
        
lvc_ram_prio1 float32 LaKMC_kappa_cmd;
/*!< @ASAP_NAME LaKMC_kappa_cmd @UNIT 1/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_kappa_cmd) */
        
lvc_ram_prio1 float32 LaKMC_kappaP_cmd;
/*!< @ASAP_NAME LaKMC_kappaP_cmd @UNIT 1/ms @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_kappaP_cmd) */
        
lvc_ram_prio1 float32 LaKMC_steer_kappa_ctrl_cmd;
/*!< @ASAP_NAME LaKMC_steer_kappa_ctrl_cmd @UNIT 1/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_steer_kappa_ctrl_cmd) */
        
lvc_ram_prio1 float32 LaKMC_steer_angle_ctrl_cmd;
/*!< @ASAP_NAME LaKMC_steer_angle_ctrl_cmd @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_steer_angle_ctrl_cmd) */
        
lvc_ram_prio1 float32 LaKMC_brake_kappa_ctrl_cmd;
/*!< @ASAP_NAME LaKMC_brake_kappa_ctrl_cmd @UNIT 1/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_brake_kappa_ctrl_cmd) */
        
lvc_ram_prio1 unsigned_char_t LaKMC_stiffness;
/*!< @ASAP_NAME LaKMC_stiffness @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_stiffness) */
        
lvc_ram_prio1 unsigned_char_t LaKMC_accuracy;
/*!< @ASAP_NAME LaKMC_accuracy @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_accuracy) */
        
lvc_ram_prio1 signed_int16_t LaKMC_steering_wheel_vibration;
/*!< @ASAP_NAME LaKMC_steering_wheel_vibration @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_steering_wheel_vibration) */
        
lvc_ram_prio1 float32 LaKMC_lateral_error;
/*!< @ASAP_NAME LaKMC_lateral_error @UNIT m @LSB 1.0000000000 @MIN -2 @MAX 2 @OFFSET 0 @brief comment (LaKMC_lateral_error) */
        
lvc_ram_prio1 float32 LaKMC_heading_error;
/*!< @ASAP_NAME LaKMC_heading_error @UNIT deg @LSB 1.0000000000 @MIN -20 @MAX 20 @OFFSET 0 @brief comment (LaKMC_heading_error) */
        
lvc_ram_prio1 float32 HEC_Psi_Control_Error;
/*!< @ASAP_NAME HEC_Psi_Control_Error @UNIT rad @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (HEC_Psi_Control_Error) */
        
lvc_ram_prio1 float32 LDC_Delta_Psi_Dist;
/*!< @ASAP_NAME LDC_Delta_Psi_Dist @UNIT rad @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LDC_Delta_Psi_Dist) */
        
lvc_ram_prio1 float32 LDC_Psi_Command;
/*!< @ASAP_NAME LDC_Psi_Command @UNIT rad @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LDC_Psi_Command) */
        
lvc_ram_prio1 float32 HEC_Delta_F_Cmd;
/*!< @ASAP_NAME HEC_Delta_F_Cmd @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (HEC_Delta_F_Cmd) */
        
lvc_ram_prio1 float32 VEH_Lateral_Accel;
/*!< @ASAP_NAME VEH_Lateral_Accel @UNIT m/s/s @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Lateral_Accel) */
        
lvc_ram_prio1 signed_int16_t LKC_Lane_Status;
/*!< @ASAP_NAME LKC_Lane_Status @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LKC_Lane_Status) */
        
lvc_ram_prio1 float32 Cam_kappa_feedfwd;
/*!< @ASAP_NAME Cam_kappa_feedfwd @UNIT 1/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (Cam_kappa_feedfwd) */
        
lvc_ram_prio1 float32 Cam_lateral_error;
/*!< @ASAP_NAME Cam_lateral_error @UNIT m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (Cam_lateral_error) */
        
lvc_ram_prio1 float32 LaKMC_kappa_sum_command;
/*!< @ASAP_NAME LaKMC_kappa_sum_command @UNIT 1/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_kappa_sum_command) */
        
lvc_ram_prio1 float32 Cam_heading_error;
/*!< @ASAP_NAME Cam_heading_error @UNIT rad @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (Cam_heading_error) */
        
lvc_ram_prio1 float32 VDY_Steer_Angle_Offset;
/*!< @ASAP_NAME VDY_Steer_Angle_Offset @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VDY_Steer_Angle_Offset) */
        
lvc_ram_prio1 float32 VDY_Bank_Angle;
/*!< @ASAP_NAME VDY_Bank_Angle @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VDY_Bank_Angle) */
        
lvc_ram_prio1 signed_int16_t Cam_kappa_qf;
/*!< @ASAP_NAME Cam_kappa_qf @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (Cam_kappa_qf) */
        
lvc_ram_prio1 signed_int16_t LAT_Tdf_Eps_Torque_Request_dbg;
/*!< @ASAP_NAME LAT_Tdf_Eps_Torque_Request_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Tdf_Eps_Torque_Request_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Arb_Eps_Torque_Request_dbg;
/*!< @ASAP_NAME LAT_Arb_Eps_Torque_Request_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Arb_Eps_Torque_Request_dbg) */
        
lvc_ram_prio1 signed_int16_t Lat_max_output_torque_dbg;
/*!< @ASAP_NAME Lat_max_output_torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (Lat_max_output_torque_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Torque_Sat_Out_dbg;
/*!< @ASAP_NAME SAC_Torque_Sat_Out_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Torque_Sat_Out_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Derating_Torque_dbg;
/*!< @ASAP_NAME SAC_Derating_Torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Derating_Torque_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Torque_Out_Raw_dbg;
/*!< @ASAP_NAME SAC_Torque_Out_Raw_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Torque_Out_Raw_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Load_Compensation_Torque_dbg;
/*!< @ASAP_NAME SAC_Load_Compensation_Torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Load_Compensation_Torque_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Limiter_Out_dbg;
/*!< @ASAP_NAME SAC_Limiter_Out_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Limiter_Out_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Kd_Part_dbg;
/*!< @ASAP_NAME SAC_Kd_Part_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Kd_Part_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Active_Damping_Torque_dbg;
/*!< @ASAP_NAME SAC_Active_Damping_Torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Active_Damping_Torque_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Ki_Part_dbg;
/*!< @ASAP_NAME SAC_Ki_Part_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Ki_Part_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Kx_Part_dbg;
/*!< @ASAP_NAME SAC_Kx_Part_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Kx_Part_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Latency_Compensation_Torque_dbg;
/*!< @ASAP_NAME SAC_Latency_Compensation_Torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Latency_Compensation_Torque_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_OScillation_Damp_Torque_dbg;
/*!< @ASAP_NAME SAC_OScillation_Damp_Torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_OScillation_Damp_Torque_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Friction_Comp_Torque_Out_dbg;
/*!< @ASAP_NAME SAC_Friction_Comp_Torque_Out_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Friction_Comp_Torque_Out_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Rate_Limit_Control_Out_dbg;
/*!< @ASAP_NAME LAT_Rate_Limit_Control_Out_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Rate_Limit_Control_Out_dbg) */
        
lvc_ram_prio1 signed_int16_t MOT_Modulated_Torque_dbg;
/*!< @ASAP_NAME MOT_Modulated_Torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Torque output of the vibration unit (MOT_Modulated_Torque_dbg) */
        
lvc_ram_prio1 unsigned_int16_t LAT_Ay_Dynamic_Threshold_dbg;
/*!< @ASAP_NAME LAT_Ay_Dynamic_Threshold_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Ay_Dynamic_Threshold_dbg) */
        
lvc_ram_prio1 unsigned_int16_t SAC_Trq_Derating_Factor_dbg;
/*!< @ASAP_NAME SAC_Trq_Derating_Factor_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Trq_Derating_Factor_dbg) */
        
lvc_ram_prio1 unsigned_int16_t TDF_Sac_Dos_Limit_Scale_dbg;
/*!< @ASAP_NAME TDF_Sac_Dos_Limit_Scale_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (TDF_Sac_Dos_Limit_Scale_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Derated_Eps_Torque_dbg;
/*!< @ASAP_NAME SAC_Derated_Eps_Torque_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Derated_Eps_Torque_dbg) */
        
lvc_ram_prio1 unsigned_int16_t TDF_Torque_Derating_Factor_dbg;
/*!< @ASAP_NAME TDF_Torque_Derating_Factor_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (TDF_Torque_Derating_Factor_dbg) */
        
lvc_ram_prio1 unsigned_int16_t SAC_Dynamic_Correction_Factor_dbg;
/*!< @ASAP_NAME SAC_Dynamic_Correction_Factor_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Dynamic_Correction_Factor_dbg) */
        
lvc_ram_prio1 float32 SAC_Delta_F_Filtered3_;
/*!< @ASAP_NAME SAC_Delta_F_Filtered3_ @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Delta_F_Filtered3_) */
        
lvc_ram_prio1 unsigned_char_t SAC_Disable;
/*!< @ASAP_NAME OBS_Disable @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Disable) */
        
lvc_ram_prio1 unsigned_int16_t Obs_observer_mode_sig;
/*!< @ASAP_NAME Obs_observer_mode_sig @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (Obs_observer_mode_sig) */
        
lvc_ram_prio1 float32 VEH_Vehicle_Speed;
/*!< @ASAP_NAME VEH_Vehicle_Speed @UNIT m/s @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Vehicle_Speed) */
        
lvc_ram_prio1 float32 LKA_Eps_Torque_Request_delayed;
/*!< @ASAP_NAME LKA_Eps_Torque_Request_delayed @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LKA_Eps_Torque_Request_delayed) */
        
lvc_ram_prio1 float32 SAC_Requested_Damping_Level_delayed;
/*!< @ASAP_NAME SAC_Requested_Damping_Level_delayed @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Requested_Damping_Level_delayed) */
        
lvc_ram_prio1 float32 TDF_Sac_Dos_Limit_Scale_delayed;
/*!< @ASAP_NAME TDF_Sac_Dos_Limit_Scale_delayed @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (TDF_Sac_Dos_Limit_Scale_delayed) */
        
lvc_ram_prio1 float32 Lat_max_output_torque_sig;
/*!< @ASAP_NAME Lat_max_output_torque_sig @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (Lat_max_output_torque_sig) */
        
lvc_ram_prio1 float32 SAC_Rate_Lim_Feed_Fwd_Torque;
/*!< @ASAP_NAME SAC_Rate_Lim_Feed_Fwd_Torque @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Rate_Lim_Feed_Fwd_Torque) */
        
lvc_ram_prio1 float32 VEH_Delta_F_Dot_Est_Arb;
/*!< @ASAP_NAME VEH_Delta_F_Dot_Est_Arb @UNIT deg/s @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Delta_F_Dot_Est_Arb) */
        
lvc_ram_prio1 float32 SAC_Eps_Trq_Load_Est;
/*!< @ASAP_NAME SAC_Eps_Trq_Load_Est @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Eps_Trq_Load_Est) */
        
lvc_ram_prio1 unsigned_int16_t SAC_Steer_Velocity_Source;
/*!< @ASAP_NAME SAC_Steer_Velocity_Source @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Steer_Velocity_Source) */
        
lvc_ram_prio1 unsigned_char_t SAC_Obs_Var_Delay;
/*!< @ASAP_NAME SAC_Obs_Var_Delay @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Obs_Var_Delay) */
        
lvc_ram_prio1 unsigned_int16_t OBS_Discharge_Req_Level_dbg;
/*!< @ASAP_NAME OBS_Discharge_Req_Level_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (OBS_Discharge_Req_Level_dbg) */
        
lvc_ram_prio1 unsigned_int16_t OBS_Boost_Request_Level_dbg;
/*!< @ASAP_NAME OBS_Boost_Request_Level_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (OBS_Boost_Request_Level_dbg) */
        
lvc_ram_prio1 signed_int16_t LKC_Lane_Status_dbg;
/*!< @ASAP_NAME LKC_Lane_Status_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Lane status (LKC_Lane_Status_dbg) */
        
lvc_ram_prio1 signed_int16_t LaKMC_kappa_cmd_dbg;
/*!< @ASAP_NAME LaKMC_kappa_cmd_dbg @UNIT 1/m @LSB 0.0000200000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_kappa_cmd_dbg) */
        
lvc_ram_prio1 signed_int16_t VEH_Delta_F_dbg;
/*!< @ASAP_NAME VEH_Delta_F_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Delta_F_dbg) */
        
lvc_ram_prio1 signed_int16_t VEH_Delta_clm_sens_F_dbg;
/*!< @ASAP_NAME VEH_Delta_clm_sens_F_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Delta_clm_sens_F_dbg) */
        
lvc_ram_prio1 signed_int16_t VEH_Delta_F_Dot_dbg;
/*!< @ASAP_NAME VEH_Delta_F_Dot_dbg @UNIT - @LSB 0.0437500000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Delta_F_Dot_dbg) */
        
lvc_ram_prio1 signed_int16_t VEH_Steer_Torque_dbg;
/*!< @ASAP_NAME VEH_Steer_Torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Steer_Torque_dbg) */
        
lvc_ram_prio1 signed_int16_t EPS_Tie_Rod_Load_dbg;
/*!< @ASAP_NAME EPS_Tie_Rod_Load_dbg @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (EPS_Tie_Rod_Load_dbg) */
        
lvc_ram_prio1 signed_int16_t EPS_Motor_Torque_dbg;
/*!< @ASAP_NAME EPS_Motor_Torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (EPS_Motor_Torque_dbg) */
        
lvc_ram_prio1 signed_int16_t EPS_Status_dbg;
/*!< @ASAP_NAME EPS_Status_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (EPS_Status_dbg) */
        
lvc_ram_prio1 signed_int16_t LaDMC_Eps_Torque_Request_dbg;
/*!< @ASAP_NAME LaDMC_Eps_Torque_Request_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaDMC_Eps_Torque_Request_dbg) */
        
lvc_ram_prio1 signed_int16_t SAT_Saturated_Angle_Command_dbg;
/*!< @ASAP_NAME SAT_Saturated_Angle_Command_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief steer angle target command (SAT_Saturated_Angle_Command_dbg) */
        
lvc_ram_prio1 signed_int16_t SAT_Angle_Rate_Residual_dbg;
/*!< @ASAP_NAME SAT_Angle_Rate_Residual_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief steer angle command rate residual (SAT_Angle_Rate_Residual_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Damping_Angle_Command_dbg;
/*!< @ASAP_NAME SAC_Damping_Angle_Command_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief damping angle command (SAC_Damping_Angle_Command_dbg) */
        
lvc_ram_prio1 unsigned_int16_t SAC_Ctrl_Err_Memshp_Low_Dyn_dbg;
/*!< @ASAP_NAME SAC_Ctrl_Err_Memshp_Low_Dyn_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Ctrl_Err_Memshp_Low_Dyn_dbg) */
        
lvc_ram_prio1 unsigned_int16_t SAC_Control_Err_Membership_dbg;
/*!< @ASAP_NAME SAC_Control_Err_Membership_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Control_Err_Membership_dbg) */
        
lvc_ram_prio1 unsigned_int16_t LAT_Gi_Status_dbg;
/*!< @ASAP_NAME LAT_Gi_Status_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief LAT_Gi_Status (LAT_Gi_Status_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Steering_Wheel_Angle_Cmd_dbg;
/*!< @ASAP_NAME SAC_Steering_Wheel_Angle_Cmd_dbg @UNIT deg @LSB 0.0437500000 @MIN -Inf @MAX Inf @OFFSET 0 @brief steering wheel angle target command (SAC_Steering_Wheel_Angle_Cmd_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Filtered_Angle_Command_dbg;
/*!< @ASAP_NAME SAC_Filtered_Angle_Command_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief filtered steer angle target command (SAC_Filtered_Angle_Command_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Eps_Trq_Load_Est_dbg;
/*!< @ASAP_NAME SAC_Eps_Trq_Load_Est_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief estimated EPS motor load (SAC_Eps_Trq_Load_Est_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Motor_Torque_Est_dbg;
/*!< @ASAP_NAME LAT_Motor_Torque_Est_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief estimated EPS motor torque due to steer torque (LAT_Motor_Torque_Est_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Steer_Torque_Est_dbg;
/*!< @ASAP_NAME LAT_Steer_Torque_Est_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief estimated steer torque (LAT_Steer_Torque_Est_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Delta_F_Est_dbg;
/*!< @ASAP_NAME SAC_Delta_F_Est_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief estimated steer angle (SAC_Delta_F_Est_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Kd_Obs_Part_dbg;
/*!< @ASAP_NAME SAC_Kd_Obs_Part_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief damping torque from notch filter (SAC_Kd_Obs_Part_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Dmc_Status_dbg;
/*!< @ASAP_NAME LAT_Dmc_Status_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief DMC status (LAT_Dmc_Status_dbg) */
        
lvc_ram_prio1 signed_int16_t LDC_Psi_Command_dbg;
/*!< @ASAP_NAME LDC_Psi_Command_dbg @UNIT rad @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief psi command to the heading controller (LDC_Psi_Command_dbg) */
        
lvc_ram_prio1 signed_int16_t DYC_Steer_Angle_Feedforward_dbg;
/*!< @ASAP_NAME DYC_Steer_Angle_Feedforward_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief fed forward steer angle command (DYC_Steer_Angle_Feedforward_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Angle_Cmd_Yawrate_Fback_dbg;
/*!< @ASAP_NAME SAC_Angle_Cmd_Yawrate_Fback_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief steer angle command from the yaw rate feedback (SAC_Angle_Cmd_Yawrate_Fback_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Delta_Ys_dbg;
/*!< @ASAP_NAME LAT_Delta_Ys_dbg @UNIT m @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief lateral deviation error (LAT_Delta_Ys_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Delta_Ys_Filtered_dbg;
/*!< @ASAP_NAME LAT_Oc_Delta_Ys_Filtered_dbg @UNIT m @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief average lateral deviation error (LAT_Oc_Delta_Ys_Filtered_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Delta_Psi_dbg;
/*!< @ASAP_NAME LAT_Delta_Psi_dbg @UNIT rad @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief heading angle error (LAT_Delta_Psi_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Kappa_Command_dbg;
/*!< @ASAP_NAME LAT_Kappa_Command_dbg @UNIT 1/m @LSB 0.0000200000 @MIN -Inf @MAX Inf @OFFSET 0 @brief kappa command (LAT_Kappa_Command_dbg) */
        
lvc_ram_prio1 signed_int16_t HEC_Psi_Control_Error_dbg;
/*!< @ASAP_NAME HEC_Psi_Control_Error_dbg @UNIT rad @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief control error of the heading angle controller (HEC_Psi_Control_Error_dbg) */
        
lvc_ram_prio1 signed_int16_t HEC_Delta_F_Cmd_dbg;
/*!< @ASAP_NAME HEC_Delta_F_Cmd_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief steer angle command from the heading controller (HEC_Delta_F_Cmd_dbg) */
        
lvc_ram_prio1 signed_int16_t LDC_Delta_Psi_Dist_dbg;
/*!< @ASAP_NAME LDC_Delta_Psi_Dist_dbg @UNIT rad @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief lateral disturbance psi command (LDC_Delta_Psi_Dist_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Yrc_Angle_Command_dbg;
/*!< @ASAP_NAME SAC_Yrc_Angle_Command_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief steer angle command from the active yaw rate controller (SAC_Yrc_Angle_Command_dbg) */
        
lvc_ram_prio1 unsigned_int16_t LAT_Kappa_Linz_Omega_dbg;
/*!< @ASAP_NAME LAT_Kappa_Linz_Omega_dbg @UNIT rad/s @LSB 0.0078125000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Omega of the kappa input filter (LAT_Kappa_Linz_Omega_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Kappa_Filter_Output_dbg;
/*!< @ASAP_NAME LAT_Kappa_Filter_Output_dbg @UNIT 1/m @LSB 0.0000200000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Output of the kappa input filter (LAT_Kappa_Filter_Output_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Filtered_Delta_F_Offset_dbg;
/*!< @ASAP_NAME LAT_Filtered_Delta_F_Offset_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Filtered angle offset (LAT_Filtered_Delta_F_Offset_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Rls_Delta_L_Offset_Raw_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_Delta_L_Offset_Raw_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief raw estimated steering angle offset (LAT_Oc_Rls_Delta_L_Offset_Raw_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Rls_Delta_L_Offst_Lim_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_Delta_L_Offst_Lim_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief filtered steering angle offset (LAT_Oc_Rls_Delta_L_Offst_Lim_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Rls_Status_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_Status_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Oc_Rls_Status_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Rls_stiffness_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_stiffness_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief estimated stiffness of steering rod (LAT_Oc_Rls_stiffness_dbg) */
        
lvc_ram_prio1 unsigned_int16_t LAT_Oc_Rls_variance_stiffnes_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_variance_stiffnes_dbg @UNIT - @LSB 0.0000305176 @MIN -Inf @MAX Inf @OFFSET 0 @brief variance of stiffness (LAT_Oc_Rls_variance_stiffnes_dbg) */
        
lvc_ram_prio1 unsigned_int16_t LAT_Oc_Rls_variance_offset_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_variance_offset_dbg @UNIT - @LSB 0.0000305176 @MIN -Inf @MAX Inf @OFFSET 0 @brief variance of offset (LAT_Oc_Rls_variance_offset_dbg) */
        
lvc_ram_prio1 unsigned_int16_t LAT_Oc_Rls_cov_stiffnes_offs_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_cov_stiffnes_offs_dbg @UNIT - @LSB 0.0000305176 @MIN -Inf @MAX Inf @OFFSET 0 @brief covariance of stiffness and offset (LAT_Oc_Rls_cov_stiffnes_offs_dbg) */
        
lvc_ram_prio1 unsigned_int16_t LAT_Oc_Rls_var1_stiff_V4_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_var1_stiff_V4_dbg @UNIT - @LSB 0.0000305176 @MIN -Inf @MAX Inf @OFFSET 0 @brief variance of stiffness (LAT_Oc_Rls_var1_stiff_V4_dbg) */
        
lvc_ram_prio1 unsigned_int16_t LAT_Oc_Rls_var1_off_V4_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_var1_off_V4_dbg @UNIT - @LSB 0.0000305176 @MIN -Inf @MAX Inf @OFFSET 0 @brief variance of stiffness (LAT_Oc_Rls_var1_off_V4_dbg) */
        
lvc_ram_prio1 unsigned_int16_t LAT_Oc_Rls_var_stiff_V2_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_var_stiff_V2_dbg @UNIT - @LSB 0.0000305176 @MIN -Inf @MAX Inf @OFFSET 0 @brief variance of stiffness (LAT_Oc_Rls_var_stiff_V2_dbg) */
        
lvc_ram_prio1 unsigned_int16_t LAT_Oc_Rls_cov_stiff_off_V2_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_cov_stiff_off_V2_dbg @UNIT - @LSB 0.0000305176 @MIN -Inf @MAX Inf @OFFSET 0 @brief variance of stiffness (LAT_Oc_Rls_cov_stiff_off_V2_dbg) */
        
lvc_ram_prio1 unsigned_int16_t LAT_Oc_Rls_var_off_V2_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_var_off_V2_dbg @UNIT - @LSB 0.0000305176 @MIN -Inf @MAX Inf @OFFSET 0 @brief variance of stiffness (LAT_Oc_Rls_var_off_V2_dbg) */
        
lvc_ram_prio1 unsigned_int16_t LAT_Oc_Rls_var1_stiff_V3_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_var1_stiff_V3_dbg @UNIT - @LSB 0.0000305176 @MIN -Inf @MAX Inf @OFFSET 0 @brief variance of stiffness (LAT_Oc_Rls_var1_stiff_V3_dbg) */
        
lvc_ram_prio1 unsigned_int16_t LAT_Oc_Rls_var1_off_V3_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_var1_off_V3_dbg @UNIT - @LSB 0.0000305176 @MIN -Inf @MAX Inf @OFFSET 0 @brief variance of stiffness (LAT_Oc_Rls_var1_off_V3_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Rls_stiff_V3_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_stiff_V3_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief variance of stiffness (LAT_Oc_Rls_stiff_V3_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Rls_stiff_V4_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_stiff_V4_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief estimated stiffness of steering rod (LAT_Oc_Rls_stiff_V4_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Rls_Delta_L_dead_V4_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_Delta_L_dead_V4_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief estimated stiffness of steering rod (LAT_Oc_Rls_Delta_L_dead_V4_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Rls_Delta_L_Off_V4_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_Delta_L_Off_V4_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief estimated stiffness of steering rod (LAT_Oc_Rls_Delta_L_Off_V4_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Rls_stiffness_V2_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_stiffness_V2_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief estimated stiffness of steering rod (LAT_Oc_Rls_stiffness_V2_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Rls_Delta_L_Offset_V2_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_Delta_L_Offset_V2_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief estimated stiffness of steering rod (LAT_Oc_Rls_Delta_L_Offset_V2_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Rls_Delta_L_dead_V3_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_Delta_L_dead_V3_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief estimated stiffness of steering rod (LAT_Oc_Rls_Delta_L_dead_V3_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Rls_Delta_L_Off_V3_dbg;
/*!< @ASAP_NAME LAT_Oc_Rls_Delta_L_Off_V3_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief estimated stiffness of steering rod (LAT_Oc_Rls_Delta_L_Off_V3_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Integrator_Input_Kappa_dbg;
/*!< @ASAP_NAME LAT_Oc_Integrator_Input_Kappa_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Kappa based integrator input (LAT_Oc_Integrator_Input_Kappa_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Integrator_Input_Raw_dbg;
/*!< @ASAP_NAME LAT_Oc_Integrator_Input_Raw_dbg @UNIT m @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Raw input of the Oc integrator (LAT_Oc_Integrator_Input_Raw_dbg) */
        
lvc_ram_prio1 signed_int16_t CAM_Kappa_Cmd_dbg;
/*!< @ASAP_NAME CAM_Kappa_Cmd_dbg @UNIT 1/m @LSB 0.0000200000 @MIN -Inf @MAX Inf @OFFSET 0 @brief curvature signal provided by the camera (CAM_Kappa_Cmd_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Kappa_Status_dbg;
/*!< @ASAP_NAME LAT_Oc_Kappa_Status_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Oc_Kappa_Status_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Oc_Dys_Status_dbg;
/*!< @ASAP_NAME LAT_Oc_Dys_Status_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Oc_Dys_Status_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Gen_Purpose_dbg;
/*!< @ASAP_NAME LAT_Gen_Purpose_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Gen_Purpose_dbg) */
        
lvc_ram_prio1 unsigned_char_t LAT_Oc_Vdy_Off_Monitoring_Status;
/*!< @ASAP_NAME LAT_Oc_Vdy_Off_Monitoring_Status @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Oc_Vdy_Off_Monitoring_Status) */
        
lvc_ram_prio1 float32 LAT_Oc_Lat_Error_Mean;
/*!< @ASAP_NAME LAT_Oc_Lat_Error_Mean @UNIT m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Oc_Lat_Error_Mean) */
        
lvc_ram_prio1 unsigned_char_t LAT_Oc_Ladmc_Settlement_Status;
/*!< @ASAP_NAME LAT_Oc_Ladmc_Settlement_Status @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Oc_Ladmc_Settlement_Status) */
        
lvc_ram_prio1 float32 LAT_Oc_Integrator_Adapt;
/*!< @ASAP_NAME LAT_Oc_Integrator_Adapt @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Oc_Integrator_Adapt) */
        
lvc_ram_prio1 float32 LAT_Oc_Vdy_Ang_Off_ToBe_Used;
/*!< @ASAP_NAME LAT_Oc_Vdy_Ang_Off_ToBe_Used @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Oc_Vdy_Ang_Off_ToBe_Used) */
        
lvc_ram_prio1 signed_int16_t VEH_Delta_F_Oc_dbg;
/*!< @ASAP_NAME VEH_Delta_F_Oc_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Offset corrected steer angle (VEH_Delta_F_Oc_dbg) */
        
lvc_ram_prio1 signed_int16_t SAT_Req_Angle_Supp_Control_dbg;
/*!< @ASAP_NAME SAT_Req_Angle_Supp_Control_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Contribution of the support torque controller (SAT_Req_Angle_Supp_Control_dbg) */
        
lvc_ram_prio1 signed_int16_t TDF_Steer_Torque_Sample_dbg;
/*!< @ASAP_NAME TDF_Steer_Torque_Sample_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief starting torque of the output torque derating (TDF_Steer_Torque_Sample_dbg) */
        
lvc_ram_prio1 signed_int16_t VEH_Yaw_Rate_Oc_dbg;
/*!< @ASAP_NAME VEH_Yaw_Rate_Oc_dbg @UNIT - @LSB 0.0028600000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Offset correctetd yaw rate (VEH_Yaw_Rate_Oc_dbg) */
        
lvc_ram_prio1 unsigned_int16_t SAC_Factor_Kp_dbg;
/*!< @ASAP_NAME SAC_Factor_Kp_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Factor_Kp_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Enhanced_Angle_Cmd_dbg;
/*!< @ASAP_NAME SAC_Enhanced_Angle_Cmd_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Enhanced_Angle_Cmd_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Fading_Offset_dbg;
/*!< @ASAP_NAME SAC_Fading_Offset_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Fading_Offset_dbg) */
        
lvc_ram_prio1 signed_int16_t DYC_Boost_Filter_Out_dbg;
/*!< @ASAP_NAME DYC_Boost_Filter_Out_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Contribution of the DYC booster function (DYC_Boost_Filter_Out_dbg) */
        
lvc_ram_prio1 unsigned_int16_t SAC_Load_Comp_Factor_Varia_dbg;
/*!< @ASAP_NAME SAC_Load_Comp_Factor_Varia_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Variation of the load compensation factor (SAC_Load_Comp_Factor_Varia_dbg) */
        
lvc_ram_prio1 unsigned_int16_t SAC_Load_Comp_Factor_Straight_dbg;
/*!< @ASAP_NAME SAC_Load_Comp_Factor_Straight_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Load compensation factor request during driving straight forward (SAC_Load_Comp_Factor_Straight_dbg) */
        
lvc_ram_prio1 unsigned_int16_t SAC_Load_Cmp_Fct_Curv_Chg_dbg;
/*!< @ASAP_NAME SAC_Load_Cmp_Fct_Curv_Chg_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Load compensation factor request during changing curvature (SAC_Load_Cmp_Fct_Curv_Chg_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Arb_Angle_Cmd_Raw_dbg;
/*!< @ASAP_NAME SAC_Arb_Angle_Cmd_Raw_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Raw angle command (SAC_Arb_Angle_Cmd_Raw_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Faded_Angle_Command_dbg;
/*!< @ASAP_NAME SAC_Faded_Angle_Command_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Rate limited angle command (SAC_Faded_Angle_Command_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Angle_Command_Raw_dbg;
/*!< @ASAP_NAME SAC_Angle_Command_Raw_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steer angle command (SAC_Angle_Command_Raw_dbg) */
        
lvc_ram_prio1 signed_int16_t TDF_Idle_Status_dbg;
/*!< @ASAP_NAME TDF_Idle_Status_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Tdf idle status (TDF_Idle_Status_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Max_Torque_Scale_dbg;
/*!< @ASAP_NAME SAC_Max_Torque_Scale_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Max torque scaling factor (SAC_Max_Torque_Scale_dbg) */
        
lvc_ram_prio1 signed_int16_t VEH_Steer_Torque_Comp_dbg;
/*!< @ASAP_NAME VEH_Steer_Torque_Comp_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Unbalance compensated steer torque (VEH_Steer_Torque_Comp_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Accuracy_Request_dbg;
/*!< @ASAP_NAME SAC_Accuracy_Request_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Accuracy request (SAC_Accuracy_Request_dbg) */
        
lvc_ram_prio1 unsigned_int16_t SAT_Active_Saturation_dbg;
/*!< @ASAP_NAME SAT_Active_Saturation_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Saturation is active (SAT_Active_Saturation_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Delta_F_Sat_Command_dbg;
/*!< @ASAP_NAME SAC_Delta_F_Sat_Command_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Saturated angle command (SAC_Delta_F_Sat_Command_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Pitch_Angle_Deviation_dbg;
/*!< @ASAP_NAME LAT_Pitch_Angle_Deviation_dbg @UNIT - @LSB 0.0000305176 @MIN -Inf @MAX Inf @OFFSET 0 @brief LAT_Pitch_Angle_Deviation_dbg (LAT_Pitch_Angle_Deviation_dbg) */
        
lvc_ram_prio1 float32 DYC_Boost_Request;
/*!< @ASAP_NAME DYC_Boost_Request @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Dynamic compensation filter boost request (DYC_Boost_Request) */
        
lvc_ram_prio1 signed_int16_t DYC_Boost_Request_dbg;
/*!< @ASAP_NAME DYC_Boost_Request_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief DYC_Boost_Request_dbg (DYC_Boost_Request_dbg) */
        
lvc_ram_prio1 float32 DYC_Angle_Per_Kappa;
/*!< @ASAP_NAME DYC_Angle_Per_Kappa @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Dynamic compensation filter angle per curvature command (DYC_Angle_Per_Kappa) */
        
lvc_ram_prio1 float32 LKC_Kappa_Command_Arb;
/*!< @ASAP_NAME LKC_Kappa_Command_Arb @UNIT 1/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Arbitrated curvature command (LKC_Kappa_Command_Arb) */
        
lvc_ram_prio1 float32 LKC_Kappa_Dot_Command_Arb;
/*!< @ASAP_NAME LKC_Kappa_Dot_Command @UNIT 1/m/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Arbitrated curvature rate command (LKC_Kappa_Dot_Command_Arb) */
        
lvc_ram_prio1 float32 LKC_Steer_Kappa_Ctrl_Command;
/*!< @ASAP_NAME LKC_Steer_Kappa_Ctrl_Command @UNIT 1/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Curvature command from trajectory controller (LKC_Steer_Kappa_Ctrl_Command) */
        
lvc_ram_prio1 unsigned_int32_t SAC_Controller_Mode_Sig;
/*!< @ASAP_NAME SAC_Controller_Mode_Sig @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steering angle controller mode (SAC_Controller_Mode_Sig) */
        
lvc_ram_prio1 unsigned_char_t LDP_Active;
/*!< @ASAP_NAME LDP_Active @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Lane departure protection function active (LDP_Active) */
        
lvc_ram_prio1 float32 SAC_R_Factor;
/*!< @ASAP_NAME SAC_R_Factor @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Feedback factor of yaw rate controller (SAC_R_Factor) */
        
lvc_ram_prio1 signed_int16_t LAT_Debug1_dbg;
/*!< @ASAP_NAME LAT_Debug1_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Debug signal 1 (LAT_Debug1_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Debug2_dbg;
/*!< @ASAP_NAME LAT_Debug2_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Debug signal 2 (LAT_Debug2_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Debug3_dbg;
/*!< @ASAP_NAME LAT_Debug3_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Debug signal 3 (LAT_Debug3_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Debug4_dbg;
/*!< @ASAP_NAME LAT_Debug4_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Debug signal 4 (LAT_Debug4_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Debug5_dbg;
/*!< @ASAP_NAME LAT_Debug5_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Debug signal 5 (LAT_Debug5_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Debug6_dbg;
/*!< @ASAP_NAME LAT_Debug6_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Debug signal 6 (LAT_Debug6_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Debug7_dbg;
/*!< @ASAP_NAME LAT_Debug7_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Debug signal 7 (LAT_Debug7_dbg) */
        
lvc_ram_prio1 signed_int16_t LAT_Debug8_dbg;
/*!< @ASAP_NAME LAT_Debug8_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Debug signal 8 (LAT_Debug8_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Yrc_Residual_dbg;
/*!< @ASAP_NAME SAC_Yrc_Residual_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Residual of the YRC (SAC_Yrc_Residual_dbg) */
        
lvc_ram_prio1 unsigned_int16_t TRL_Torque_Gradient_dbg;
/*!< @ASAP_NAME TRL_Torque_Gradient_dbg @UNIT - @LSB 0.0156250000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Effective torque gradient of the rate limiter (TRL_Torque_Gradient_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Delta_F_Cmd_Grad_Param_dbg;
/*!< @ASAP_NAME SAC_Delta_F_Cmd_Grad_Param_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Debug signal 4 (SAC_Delta_F_Cmd_Grad_Param_dbg) */
        
lvc_ram_prio1 unsigned_char_t SAC_Ramp_Down_Request__nu;
/*!< @ASAP_NAME SAC_Ramp_Down_Request__nu @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief xxx (SAC_Ramp_Down_Request__nu) */
        
lvc_ram_prio1 signed_int16_t DMC_LAT_DEGRADATION;
/*!< @ASAP_NAME DMC_LAT_DEGRADATION @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief  (DMC_LAT_DEGRADATION) */
        
lvc_ram_prio1 signed_int16_t DMC_LAT_DEGRADATION_TEMP;
/*!< @ASAP_NAME DMC_LAT_DEGRADATION_TEMP @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief  (DMC_LAT_DEGRADATION_TEMP) */
        
lvc_ram_prio1 unsigned_char_t VEH_Stability_Control_Active;
/*!< @ASAP_NAME VEH_Stability_Control_Active @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief ABS, ESC or TCS controller active (VEH_Stability_Control_Active) */
        
lvc_ram_prio1 unsigned_char_t VEH_Stability_Control_Active_temp;
/*!< @ASAP_NAME VEH_Stability_Control_Active_temp @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief ABS, ESC or TCS controller active (VEH_Stability_Control_Active_temp) */
        
lvc_ram_prio1 signed_int16_t SAC_Dyn_Corrected_Angle_Cmd_dbg;
/*!< @ASAP_NAME SAC_Dyn_Corrected_Angle_Cmd_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Dynamically corrected steer angle command (SAC_Dyn_Corrected_Angle_Cmd_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Control_Error_Eps_dbg;
/*!< @ASAP_NAME SAC_Control_Error_Eps_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Control error of the EPS steering angle controller (SAC_Control_Error_Eps_dbg) */
        
lvc_ram_prio1 float32 ADP_Dyc_Corr_Factor_dbg;
/*!< @ASAP_NAME ADP_Dyc_Corr_Factor_dbg @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steering characteristic correction factor (ADP_Dyc_Corr_Factor_dbg) */
        
lvc_ram_prio1 float32 ADP_Dyc_Corr_Factor;
/*!< @ASAP_NAME ADP_Dyc_Corr_Factor @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steering characteristic correction factor (ADP_Dyc_Corr_Factor) */
        
lvc_ram_prio1 float32 ADP_Dyc_Corr_Factor_Ls;
/*!< @ASAP_NAME ADP_Dyc_Corr_Factor_Ls @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steering characteristic correction factor left side (ADP_Dyc_Corr_Factor_Ls) */
        
lvc_ram_prio1 float32 ADP_Dyc_Corr_Factor_Rs;
/*!< @ASAP_NAME ADP_Dyc_Corr_Factor_Rs @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steering characteristic correction factor right side (ADP_Dyc_Corr_Factor_Rs) */
        
lvc_ram_prio1 unsigned_char_t Turn_And_Error_Side;
/*!< @ASAP_NAME Turn_And_Error_Side @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Turn and error side (Turn_And_Error_Side) */
        
lvc_ram_prio1 float32 CAM_Lateral_Error_Mean;
/*!< @ASAP_NAME CAM_Lateral_Error_Mean @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Camera mean lateral error (CAM_Lateral_Error_Mean) */
        
lvc_ram_prio1 float32 CAM_Lateral_Error_Delta;
/*!< @ASAP_NAME CAM_Lateral_Error_Delta @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Camera mean lateral error delta (CAM_Lateral_Error_Delta) */
        
lvc_ram_prio1 unsigned_int16_t Maximum_Waiting_Counter;
/*!< @ASAP_NAME Maximum_Waiting_Counter @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Maximum waiting counter (Maximum_Waiting_Counter) */
        
lvc_ram_prio1 float32 Factor_Increase;
/*!< @ASAP_NAME Factor_Increase @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Factor increase value (Factor_Increase) */
        
lvc_ram_prio1 float32 Factor_Decrease;
/*!< @ASAP_NAME Factor_Decrease @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Factor decrease value (Factor_Decrease) */
        
lvc_ram_prio1 unsigned_int16_t LTLE_Waiting_Counter;
/*!< @ASAP_NAME LTLE_Waiting_Counter @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Left turn and left error waiting counter (LTLE_Waiting_Counter) */
        
lvc_ram_prio1 unsigned_int16_t LTRE_Waiting_Counter;
/*!< @ASAP_NAME LTRE_Waiting_Counter @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Left turn and right error waiting counter (LTRE_Waiting_Counter) */
        
lvc_ram_prio1 unsigned_int16_t RTLE_Waiting_Counter;
/*!< @ASAP_NAME RTLE_Waiting_Counter @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Right turn and left error waiting counter (RTLE_Waiting_Counter) */
        
lvc_ram_prio1 unsigned_int16_t RTRE_Waiting_Counter;
/*!< @ASAP_NAME RTRE_Waiting_Counter @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Right turn and right error waiting counter (RTRE_Waiting_Counter) */
        
lvc_ram_prio1 unsigned_char_t Factor_Corr_Enable_Flag;
/*!< @ASAP_NAME Factor_Corr_Enable_Flag @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Factor correction enable flag (Factor_Corr_Enable_Flag) */
        
lvc_ram_prio1 float32 ADP_Dyc_Corr_Factor_Left_Vect[20];
/*!< @ASAP_NAME ADP_Dyc_Corr_Factor_Left_Vect @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steering characteristic correction factor left vector (ADP_Dyc_Corr_Factor_Left_Vect) */
        
lvc_ram_prio1 float32 ADP_Dyc_Corr_Factor_Right_Vect[20];
/*!< @ASAP_NAME ADP_Dyc_Corr_Factor_Right_Vect @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steering characteristic correction factor right vector (ADP_Dyc_Corr_Factor_Right_Vect) */
        
lvc_ram_prio1 float32 Mean_Kappa_Command;
/*!< @ASAP_NAME Mean_Kappa_Command @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Mean curvature command (Mean_Kappa_Command) */
        
lvc_ram_prio1 float32 Mean_Vehicle_Velocity;
/*!< @ASAP_NAME Mean_Vehicle_Velocity @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Mean vehicle velocity (Mean_Vehicle_Velocity) */
        
lvc_ram_prio1 signed_int16_t SAC_Enhanced_Angle_Cmd_Sac_dbg;
/*!< @ASAP_NAME SAC_Enhanced_Angle_Cmd_Sac_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Enhanced_Angle_Cmd_Sac_dbg) */
        
lvc_ram_prio1 unsigned_char_t SAC_Soc_Disable;
/*!< @ASAP_NAME SAC_Soc_Disable @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Soc_Disable) */
        
lvc_ram_prio1 signed_int16_t LAT_Ay_Control_Limit_Bias_dbg;
/*!< @ASAP_NAME LAT_Ay_Control_Limit_Bias_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief lateral acceleration controller output (LAT_Ay_Control_Limit_Bias_dbg) */
        
lvc_ram_prio1 signed_int16_t SAC_Derated_Angle_Command_dbg;
/*!< @ASAP_NAME SAC_Derated_Angle_Command_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Derated angle command (SAC_Derated_Angle_Command_dbg) */
        
lvc_ram_prio1 signed_int16_t SAT_Req_Steer_Angle_Max_dbg;
/*!< @ASAP_NAME SAT_Req_Steer_Angle_Max_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Arbitrated maximum steer angle (SAT_Req_Steer_Angle_Max_dbg) */
        
lvc_ram_prio1 signed_int16_t SAT_Req_Dyn_Steer_Angle_Max_dbg;
/*!< @ASAP_NAME SAT_Req_Dyn_Steer_Angle_Max_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Dynamically enhanced maximum steer angle command (SAT_Req_Dyn_Steer_Angle_Max_dbg) */
        
lvc_ram_prio1 signed_int16_t SAT_Req_Steer_Angle_Max_Ay_dbg;
/*!< @ASAP_NAME SAT_Req_Steer_Angle_Max_Ay_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Maximum steer angle command wrt to maximum lat accel (SAT_Req_Steer_Angle_Max_Ay_dbg) */
        

/* ------------------------- */
/*      Get Functions        */
/* ------------------------- */


#endif  /* DMC_RAM_H_INCLUDED */
