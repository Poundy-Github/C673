/* $Header: DMC_Soc_types.h 1.66 2020/08/20 10:43:56CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Soc_types.h
   C source code generated on           : Wed Aug 19 16:27:04 2020
   Filename of Simulink Model           : DMC_Soc.mdl/.slx
   Revision of Simulink Model           : 1.3096
 ***************************************************************************************************
   Detailed informations needed to rebuild this code.

   MATLAB Version: 8.4.0.150421 (R2014b)
   MATLAB License Number: 40544997
   Operating System: Microsoft Windows 10 Enterprise Version 10.0 (Build 17763)
   Java Version: Java 1.7.0_11 b21 with Oracle Corporation Java HotSpot(TM) Client VM mixed mode

   MATLAB                                                Version 8.4        (R2014b)
   Simulink                                              Version 8.4        (R2014b)
   Communications System Toolbox                         Version 5.7        (R2014b)
   Computer Vision System Toolbox                        Version 6.1        (R2014b)
   Control System Toolbox                                Version 9.8        (R2014b)
   Curve Fitting Toolbox                                 Version 3.5        (R2014b)
   DSP System Toolbox                                    Version 8.7        (R2014b)
   Data Acquisition Toolbox                              Version 3.6        (R2014b)
   Database Toolbox                                      Version 5.2        (R2014b)
   Embedded Coder                                        Version 6.7        (R2014b)
   Filter Design HDL Coder                               Version 2.9.6      (R2014b)
   Fixed Point Designer                                  Version 4.3        (R2014b)
   Fuzzy Logic Toolbox                                   Version 2.2.20     (R2014b)
   Image Acquisition Toolbox                             Version 4.8        (R2014b)
   Image Processing Toolbox                              Version 9.1        (R2014b)
   Instrument Control Toolbox                            Version 3.6        (R2014b)
   MATLAB Builder NE                                     Version 4.2.2      (R2014b)
   MATLAB Coder                                          Version 2.7        (R2014b)
   MATLAB Compiler                                       Version 5.2        (R2014b)
   MATLAB Report Generator                               Version 4.0        (R2014b)
   Mapping Toolbox                                       Version 4.0.2      (R2014b)
   Model Predictive Control Toolbox                      Version 5.0        (R2014b)
   Model Based Calibration Toolbox                       Version 4.8        (R2014b)
   Neural Network Toolbox                                Version 8.2.1      (R2014b)
   Optimization Toolbox                                  Version 7.1        (R2014b)
   Parallel Computing Toolbox                            Version 6.5        (R2014b)
   Partial Differential Equation Toolbox                 Version 1.5        (R2014b)
   RF Toolbox                                            Version 2.15       (R2014b)
   Robust Control Toolbox                                Version 5.2        (R2014b)
   Signal Processing Toolbox                             Version 6.22       (R2014b)
   SimDriveline                                          Version 2.7        (R2014b)
   SimElectronics                                        Version 2.6        (R2014b)
   SimHydraulics                                         Version 1.15       (R2014b)
   SimMechanics                                          Version 4.5        (R2014b)
   SimPowerSystems                                       Version 6.2        (R2014b)
   SimRF                                                 Version 4.3        (R2014b)
   Simscape                                              Version 3.12       (R2014b)
   Simulink Coder                                        Version 8.7        (R2014b)
   Simulink Control Design                               Version 4.1        (R2014b)
   Simulink Design Optimization                          Version 2.6        (R2014b)
   Simulink Report Generator                             Version 4.0        (R2014b)
   Simulink Verification and Validation                  Version 3.8        (R2014b)
   Spreadsheet Link EX                                   Version 3.2.2      (R2014b)
   Stateflow                                             Version 8.4        (R2014b)
   Statistics Toolbox                                    Version 9.1        (R2014b)
   Symbolic Math Toolbox                                 Version 6.1        (R2014b)
   System Identification Toolbox                         Version 9.1        (R2014b)
   Vehicle Network Toolbox                               Version 2.3        (R2014b)
   Wavelet Toolbox                                       Version 4.14       (R2014b)
 ***************************************************************************************************
 ***************************************************************************************************
 */
/*
 ***************************************************************************************************
   List of disabled QA-C warnings ignored for automatic generated code.
 ***************************************************************************************************
   Warning  272: Value of integer expression is apparently not representable in the signed result type.
   Warning  295:  Result of << on value of signed expression is apparently implementation defined.
   Warning  502:  A right shift on signed data may be an arithmetic or a logical shift.
   Warning 0272: Value of integer expression is apparently not representable in the signed result type.
   Warning 0297: Value of signed expression is apparently not representable.
   Warning 0841: Use of #undef is not recommended in some programming standards.
   Warning 2204: Min_Brace case is not aligned to match its controlling switch statement.
   Warning 2209: Min_Brace This brace style is not consistent with exdented style.
   Warning 2215: Indentation is not consistent with configured depth.
   Warning 3112: Redundancy - This statement has no side-effect - it can be removed.
   Warning 3201: This statement is unreachable.
   Warning 3344: Testing a value should be made explicit: Avoid using control expression with implicit comparisions against 0
   Warning 3355: The result of this logical operation is always 'true'.
   Warning 3356: The value of this control expression is always 'true'.
   Warning 3358: The result of this logical operation is always 'true'.
   Warning 3359: The value of this control expression is always 'false'.
   Warning 3391: Extra parenthesis recommended.
   Warning 3398: Extra parenthesis recommended.
   Warning 3415: The right hand operand of '&&' or '||' has side effects.
   Warning 3757: Implicit conversion: unsigned short to short.
   Warning 4131: Left shift operation on signed operand
   Warning 3334: This declaration of ... hides a more global declaration.
   Warning  499: Right operand of shift operator is greater than or equal to the width of the underlying type.
   Warning 3203: The variable '%s' is set but never used.
   Warning 2002: No 'default' case found in this 'switch' statement.
   Warning  380: Number of macro definitions exceeds 4095 - program does not conform strictly to ISO:C99.
   Warning 4116: Operand of logical ! operator is not an 'effectively Boolean' expression.
   Warning 4115: Operand of logical && or || operator is not an 'effectively Boolean' expression.
   Warning  602: The identifier '%s' is reserved for use by the library
   Warning  310: Casting to different object pointer type.
   Warning 2203: This closing brace is not aligned appropriately with the matching opening brace.
   Warning 3673: The object addressed by the pointer parameter '%s' is not modified and so the pointer could be of type 'pointer to const'.
   Warning  311: Dangerous pointer cast results in loss of const qualification.
   Warning  606: Object '%s' is declared using typedefs which are different to those in a previous declaration.
   Warning 3451: The global identifier '%s' has been declared in more than one file.
   Warning 4104: Left hand operand of arithmetic or bitwise operator is a 'Boolean' expression.
   Warning 4105: Right hand operand of arithmetic or bitwise operator is a 'Boolean' expression.
   Warning 4130: Bitwise operations on signed data will give implementation defined results.
   Warning 2200: Indentation of this line is to the left of the line above.
   Warning 5013: Use of basic type 'char'.
   Further informations can be found in your simulink project. Refer to:
   ".\docs\coding_guidelines\AGC_MISRA_COMPLIANCE.rtf in your simulink project"
 ***************************************************************************************************
 */
/* Justification 272: AutoCode. */
/* Justification 295: AutoCode. */
/* Justification 502: AutoCode. */
/* Justification 0272: AutoCode. */
/* Justification 0297: AutoCode. */
/* Justification 0841: AutoCode. */
/* Justification 2204: AutoCode. */
/* Justification 2209: AutoCode. */
/* Justification 2215: AutoCode. */
/* Justification 3112: AutoCode. */
/* Justification 3201: AutoCode. */
/* Justification 3344: AutoCode. */
/* Justification 3355: AutoCode. */
/* Justification 3356: AutoCode. */
/* Justification 3358: AutoCode. */
/* Justification 3359: AutoCode. */
/* Justification 3391: AutoCode. */
/* Justification 3398: AutoCode. */
/* Justification 3415: AutoCode. */
/* Justification 3757: AutoCode. */
/* Justification 4131: AutoCode. */
/* Justification 2201: AutoCode. */
/* Justification 3334: AutoCode. */
/* Justification  499: AutoCode. */
/* Justification 3203: AutoCode. Autocoder optimisation of unused pathes does not remove code in variant coded blocks */
/* Justification 2002: AutoCode. Autocoder optimises empty default cases in switches */
/* Justification  380: AutoCode. */
/* Justification 4115: AutoCode. */
/* Justification 4116: AutoCode. */
/* Justification  602: AutoCode. */
/* Justification  310: AutoCode. */
/* Justification 2203: AutoCode. Brackets Alignment */
/* Justification 3673: AutoCode. */
/* Justification  311: AutoCode. */
/* Justification  606: AutoCode. */
/* Justification 3451: AutoCode. */
/* Justification 4104: AutoCode. Equal to 4105, but different operator only */
/* Justification 4105: AutoCode. */
/* Justification 4130: AutoCode. */
/* Justification 2200: AutoCode. Brackets Alignment */
/* Justification 5013: AutoCode. Variant coding of systems */
/* Justification 3447: AutoCode. '%s' has external linkage but this declaration is not in a header file. */
/* Justification 3408: AutoCode (TCS3). Avoids external linkage warning which incorrectly occurs at file global variables (call QA-Systems?) */
/* Justification 2203: AutoCode. This closing brace is not aligned appropriately with the matching opening brace. */
/* Justification 3210: AutoCode. The global identifier '%s' is declared but is not used. */
/* Justification 4103: AutoCode: Disable due to variant coding. */
/* PRQA S 4103 EOF */
/* PRQA S 502, 4131, 295, 3757, 3344, 3112, 2204, 2209, 2215, 3356, 3359, 3201, 3391, 3355, 3358, 272, 3415, 3390, 3398, 297, 272, 841, 2201, 3334, 499, 3203, 2002, 380, 4115, 4116, 602, 310, 2203, 3673, 311, 606, 3451, 4104, 4105, 4130, 2200, 5013, 3447, 2203, 3210 EOF */
/* --- Includes --- */
#ifndef RTW_HEADER_DMC_Soc_types_h_
#define RTW_HEADER_DMC_Soc_types_h_
#include "dmc_ac.h"
typedef struct {
  //4bytes
float32 DYC_Steer_Angle_Feedforward;
float32 LAT_Eps_Torque_Request;
float32 VEH_Delta_F_Dot_Est_Arb;
float32 LAT_Delta_Ys;
float32 LKC_Delta_Ys;
float32 LAT_Delta_Psi;
float32 LKC_Delta_Psi;
float32 LAT_Kappa_Command;
float32 LAT_Kappa_Prime_Command;
float32 LAT_Psi;
float32 SAT_Saturated_Angle_Command;
float32 SAC_Yrc_Angle_Command;
float32 LAT_Delta_F_Cmd;
float32 VEH_Delta_F;
float32 VEH_Yaw_Rate;
float32 VEH_Vehicle_Velocity;
float32 VEH_Delta_F_Dot;
float32 VEH_Steer_Torque;
float32 EPS_Tie_Rod_Load;
float32 LAT_Ext_Command;
float32 EPS_Motor_Torque;
float32 LaKMC_kappa_cmd;
float32 LaKMC_kappaP_cmd;
float32 LaKMC_steer_kappa_ctrl_cmd;
float32 LaKMC_steer_angle_ctrl_cmd;
float32 LaKMC_brake_kappa_ctrl_cmd;
float32 LaKMC_lateral_error;
float32 LaKMC_heading_error;
float32 HEC_Psi_Control_Error;
float32 LDC_Delta_Psi_Dist;
float32 LDC_Psi_Command;
float32 HEC_Delta_F_Cmd;
float32 VEH_Lateral_Accel;
float32 SAC_Delta_F_Filtered3_;
float32 VEH_Vehicle_Speed;
float32 LKA_Eps_Torque_Request_delayed;
float32 SAC_Requested_Damping_Level_delayed;
float32 TDF_Sac_Dos_Limit_Scale_delayed;
float32 Lat_max_output_torque_sig;
float32 SAC_Rate_Lim_Feed_Fwd_Torque;
float32 SAC_Eps_Trq_Load_Est;
float32 Cam_kappa_feedfwd;
float32 LaKMC_kappa_sum_command;
float32 Cam_heading_error;
float32 VDY_Steer_Angle_Offset;
float32 Cam_lateral_error;
float32 VEH_Yaw_Rate_Offset;
float32 DYC_Angle_Per_Kappa;
float32 LKC_Kappa_Command_Arb;
float32 LKC_Kappa_Dot_Command_Arb;
float32 LKC_Steer_Kappa_Ctrl_Command;
unsigned_int32_t SAC_Controller_Mode_Sig;
float32 SAC_R_Factor;
float32 ADP_Dyc_Corr_Factor;
float32 ADP_Dyc_Corr_Factor_Ls;
float32 ADP_Dyc_Corr_Factor_Rs;
float32 CAM_Lateral_Error_Mean;
float32 CAM_Lateral_Error_Delta;
float32 Factor_Increase;
float32 Factor_Decrease;
float32 ADP_Dyc_Corr_Factor_Left_Vect[20];
float32 ADP_Dyc_Corr_Factor_Right_Vect[20];
float32 Mean_Kappa_Command;
float32 Mean_Vehicle_Velocity;
float32 VDY_Bank_Angle;
//2bytes

unsigned_int16_t DMC_ADP_CORR_COUNTER_POS[20];
unsigned_int16_t DMC_ADP_CORR_COUNTER_NEG[20];
unsigned_int16_t DMC_ADP_CORR_COUNTER_POS_LOOP0[20];
unsigned_int16_t DMC_ADP_CORR_COUNTER_NEG_LOOP0[20];
signed_int16_t BUS_EPS_ASSIST_TRQ; 
signed_int16_t BUS_EPS_MOTOR_TRQ;
signed_int16_t SSI_R_DMC_LAT_ACTVN_MOD;
signed_int16_t SSI_R_DMC_CRVT_SUM_CMD;
signed_int16_t SSI_R_DMC_CRVT_FEED_FWD;
signed_int16_t SSI_R_DMC_CRVT_CHG_RATE;
signed_int16_t SSI_R_DMC_CRVT_STEER_ACTR;
signed_int16_t SSI_R_DMC_CRVT_CMD_RATE;
signed_int16_t SSI_R_DMC_STEER_AG_REQ;
signed_int16_t DMC_CAM_CRVT_FEED_FWD;
signed_int16_t DMC_CAM_CRVT_FEED_FWD_QF;
signed_int16_t DMC_CAM_LAT_ERR;
signed_int16_t DMC_CAM_LAT_ERR_QF;
signed_int16_t DMC_CAM_HDNG_AG_ERR;
signed_int16_t DMC_CAM_HDNG_AG_ERR_QF;
signed_int16_t SSI_R_DMC_LAT_ERR;
signed_int16_t SSI_R_DMC_HDNG_AG_ERR;
signed_int16_t SSI_R_EPS_STEER_AG;
signed_int16_t SSI_R_EPS_STEER_AG_RATE;
signed_int16_t SSI_R_DMC_STEER_WHL_VIBR;
signed_int16_t SSI_R_LANE_STATUS;
signed_int16_t EST_REFERENCE_VELOCITY;
signed_int16_t BUS_EPS_TOR_BAR_TORQUE;
signed_int16_t DMC_FILTERED_YAW_RATE;
signed_int16_t DMC_FILTERED_YAW_RATE_QF;
signed_int16_t DMC_FILTERED_LATERAL_ACC_COG_QF;
signed_int16_t DMC_FILTERED_STEER_ANGLE_QF;
signed_int16_t DMC_FILTERED_STEER_ANGLE_RATE_QF;
signed_int16_t DMC_STEER_ANGLE_OFFSET;
signed_int16_t DMC_STEER_ANGLE_OFFSET_STATE;
signed_int16_t DMC_YAW_RATE_OFFSET;
signed_int16_t DMC_YAW_RATE_OFFSET_STATE;
signed_int16_t DMC_FILTERED_STEER_ANGLE;
signed_int16_t DMC_FILTERED_STEER_ANGLE_RATE;
signed_int16_t UNCALIBRATED_SWA_FIL;
signed_int16_t DMC_EPS_TRQ_REQ;
signed_int16_t LaDMC_status;
signed_int16_t LADMC_EPS_TORQUE_REQUEST;
signed_int16_t LaDMC_Eps_Request_Flag;
signed_int16_t LADMC_EPS_INTERFACE_ACTIVE_REQ;
signed_int16_t DMC_LAT_STATUS;
unsigned_int16_t DMC_EPS_STATUS;
signed_int16_t LADMC_STEER_ANGLE_RATE_REQ;
signed_int16_t DMC_LONG_ENG_TRQ_REQ;
signed_int16_t DMC_LONG_BRK_TRQ_REQ;
signed_int16_t SaRateSig;
signed_int16_t SaRateQ;
signed_int16_t VEH_Brake_Force_Front_Axle;
signed_int16_t EPS_Status;
signed_int16_t LAT_Dmc_Status;
signed_int16_t LaKMC_activation;
signed_int16_t LaKMC_steering_wheel_vibration;
signed_int16_t LAT_Tdf_Eps_Torque_Request_dbg;
signed_int16_t LAT_Arb_Eps_Torque_Request_dbg;
signed_int16_t Lat_max_output_torque_dbg;
signed_int16_t SAC_Torque_Sat_Out_dbg;
signed_int16_t SAC_Derating_Torque_dbg;
signed_int16_t SAC_Torque_Out_Raw_dbg;
signed_int16_t SAC_Load_Compensation_Torque_dbg;
signed_int16_t SAC_Limiter_Out_dbg;
signed_int16_t SAC_Kd_Part_dbg;
signed_int16_t SAC_Active_Damping_Torque_dbg;
signed_int16_t SAC_Ki_Part_dbg;
signed_int16_t SAC_Kx_Part_dbg;
signed_int16_t SAC_Latency_Compensation_Torque_dbg;
signed_int16_t SAC_OScillation_Damp_Torque_dbg;
signed_int16_t SAC_Friction_Comp_Torque_Out_dbg;
signed_int16_t LAT_Rate_Limit_Control_Out_dbg;
unsigned_int16_t Obs_observer_mode_sig;
unsigned_int16_t SAC_Steer_Velocity_Source;
signed_int16_t LaKMC_kappa_cmd_dbg;
signed_int16_t VEH_Delta_F_dbg;
signed_int16_t VEH_Delta_clm_sens_F_dbg;
signed_int16_t VEH_Delta_F_Dot_dbg;
signed_int16_t VEH_Steer_Torque_dbg;
signed_int16_t EPS_Tie_Rod_Load_dbg;
signed_int16_t EPS_Motor_Torque_dbg;
signed_int16_t EPS_Status_dbg;
signed_int16_t LaDMC_Eps_Torque_Request_dbg;
signed_int16_t SAT_Saturated_Angle_Command_dbg;
signed_int16_t SAC_Eps_Trq_Load_Est_dbg;
signed_int16_t LAT_Dmc_Status_dbg;
signed_int16_t LDC_Psi_Command_dbg;
signed_int16_t DYC_Steer_Angle_Feedforward_dbg;
signed_int16_t LAT_Delta_Ys_dbg;
signed_int16_t LAT_Delta_Psi_dbg;
signed_int16_t LAT_Kappa_Command_dbg;
signed_int16_t HEC_Psi_Control_Error_dbg;
signed_int16_t HEC_Delta_F_Cmd_dbg;
signed_int16_t LDC_Delta_Psi_Dist_dbg;
signed_int16_t SAC_Yrc_Angle_Command_dbg;
unsigned_int16_t LAT_Kappa_Linz_Omega_dbg;
signed_int16_t LAT_Kappa_Filter_Output_dbg;
signed_int16_t LAT_Filtered_Delta_F_Offset_dbg;
signed_int16_t LAT_Oc_Integrator_Input_Kappa_dbg;
signed_int16_t LAT_Oc_Integrator_Input_Raw_dbg;
signed_int16_t CAM_Kappa_Cmd_dbg;
signed_int16_t DMC_LAT_DEGRADATION;
signed_int16_t DMC_LAT_DEGRADATION_TEMP;
signed_int16_t LKC_Lane_Status;
signed_int16_t Lat_rate_limited_offset_dbg;
unsigned_int16_t SAC_Trq_Derating_Factor_dbg;
unsigned_int16_t TDF_Torque_Derating_Factor_dbg;
unsigned_int16_t TDF_Sac_Dos_Limit_Scale_dbg;
signed_int16_t Cam_kappa_qf;
signed_int16_t LKC_Lane_Status_dbg;
signed_int16_t LAT_Oc_Kappa_Status_dbg;
signed_int16_t LAT_Oc_Dys_Status_dbg;
signed_int16_t LAT_Gen_Purpose_dbg; 
signed_int16_t MOT_Modulated_Torque_dbg;
signed_int16_t VEH_Delta_F_Oc_dbg;
signed_int16_t SAT_Req_Angle_Supp_Control_dbg;
signed_int16_t TDF_Steer_Torque_Sample_dbg;
unsigned_int16_t SAC_Factor_Kp_dbg;
signed_int16_t SAC_Enhanced_Angle_Cmd_dbg;
signed_int16_t SAC_Fading_Offset_dbg;
signed_int16_t DYC_Boost_Filter_Out_dbg;
unsigned_int16_t SAC_Load_Comp_Factor_Varia_dbg;
signed_int16_t SAC_Faded_Angle_Command_dbg;
signed_int16_t SAC_Arb_Angle_Cmd_Raw_dbg;
signed_int16_t DYC_Boost_Request_dbg;
signed_int16_t LAT_Debug1_dbg;
signed_int16_t LAT_Debug2_dbg;
signed_int16_t LAT_Debug3_dbg;
signed_int16_t LAT_Debug4_dbg;
signed_int16_t LAT_Debug5_dbg;
signed_int16_t LAT_Debug6_dbg;
signed_int16_t LAT_Debug7_dbg;
signed_int16_t LAT_Debug8_dbg;
unsigned_int16_t SAC_Load_Comp_Factor_Straight_dbg;
signed_int16_t VEH_Yaw_Rate_Oc_dbg;
unsigned_int16_t OBS_Discharge_Req_Level_dbg;
unsigned_int16_t OBS_Boost_Request_Level_dbg;
signed_int16_t SAC_Steering_Wheel_Angle_Cmd_dbg;
signed_int16_t SAC_Filtered_Angle_Command_dbg;
signed_int16_t LADMC_STEER_ANGLE_REQ;
signed_int16_t TDF_Idle_Status_dbg;
signed_int16_t SAC_Dyn_Corrected_Angle_Cmd_dbg;
signed_int16_t DMC_STIFFNESS_GRAD;
signed_int16_t DMC_TORQUE_SCALE_GRAD;
signed_int16_t DMC_TORQUE_RAMP_GRAD;
signed_int16_t SAC_Max_Torque_Scale_dbg;
signed_int16_t VEH_Steer_Torque_Comp_dbg;
signed_int16_t SAC_Accuracy_Request_dbg;
signed_int16_t LAT_Steer_Angle_Command_deg;
signed_int16_t LAT_Torque_Overlay_Request_nm;
signed_int16_t LAT_Eps_Torque_Request_nm;
signed_int16_t SAC_Ayc_Residual_dbg;
unsigned_int16_t TRL_Torque_Gradient_dbg;
signed_int16_t SAC_Delta_F_Cmd_Grad_Param_dbg;
signed_int16_t SAC_Control_Error_Eps_dbg;
signed_int16_t SAC_Yrc_Residual_dbg;
signed_int16_t SAC_Angle_Command_Raw_dbg;
unsigned_int16_t SAC_Load_Cmp_Fct_Curv_Chg_dbg;
unsigned_int16_t Maximum_Waiting_Counter;
unsigned_int16_t LTLE_Waiting_Counter;
unsigned_int16_t LTRE_Waiting_Counter;
unsigned_int16_t RTLE_Waiting_Counter;
unsigned_int16_t RTRE_Waiting_Counter;
signed_int16_t DMC_ANGLE_OFF_LOOP0;
unsigned_int16_t DMC_ANGLE_OFF_CALIB_CNT_LOOP0;
signed_int16_t DMC_ANGLE_OFF;
signed_int16_t DMC_Eps_Integrator_Hold_Req_nu;
unsigned_int16_t DMC_ANGLE_OFF_CALIB_CNT;
signed_int16_t SAC_Derated_Angle_Command_dbg;
signed_int16_t SAT_Angle_Rate_Residual_dbg;
signed_int16_t SAC_Damping_Angle_Command_dbg;
unsigned_int16_t SAC_Ctrl_Err_Memshp_Low_Dyn_dbg;
unsigned_int16_t SAC_Control_Err_Membership_dbg;
signed_int16_t LAT_Kappa_Sum_Command_1pm;
signed_int16_t SAT_Req_Steer_Angle_Max_Ay_dbg;
signed_int16_t LAT_Ay_Control_Limit_Bias_dbg;
signed_int16_t SAC_Delta_F_Sat_Command_dbg;
unsigned_int16_t SAT_Active_Saturation_dbg;
signed_int16_t SAT_Req_Dyn_Steer_Angle_Max_dbg;
signed_int16_t SAC_Angle_Cmd_Yawrate_Fback_dbg;
signed_int16_t LAT_Oc_Delta_Ys_Filtered_dbg;
signed_int16_t DMC_BANK_ANGLE;
signed_int16_t LAT_Oc_Rls_Delta_L_Offset_Raw_dbg;
signed_int16_t LAT_Oc_Rls_Delta_L_Offst_Lim_dbg;
signed_int16_t LAT_Oc_Rls_Status_dbg;
signed_int16_t LAT_Oc_Rls_stiffness_dbg;
unsigned_int16_t LAT_Oc_Rls_variance_stiffnes_dbg;
unsigned_int16_t LAT_Oc_Rls_variance_offset_dbg;
unsigned_int16_t LAT_Oc_Rls_cov_stiffnes_offs_dbg;
unsigned_int16_t LAT_Ay_Dynamic_Threshold_dbg;
signed_int16_t SAT_Req_Steer_Angle_Max_dbg;
unsigned_int16_t LCF_Operation_Mode;
signed_int16_t DMC_GPIO;
signed_int16_t DMC_GPIO2;
signed_int16_t DMC_GPIO3;
signed_int16_t DMC_GPIO4;
signed_int16_t EMO_PITCH_ANGLE;
signed_int16_t LAT_Pitch_Angle_Deviation_dbg;
unsigned_int16_t LAT_Oc_Rls_var1_stiff_V4_dbg;
unsigned_int16_t LAT_Oc_Rls_var1_off_V4_dbg;
unsigned_int16_t LAT_Oc_Rls_var_stiff_V2_dbg;
unsigned_int16_t LAT_Oc_Rls_cov_stiff_off_V2_dbg;
unsigned_int16_t LAT_Oc_Rls_var_off_V2_dbg;
unsigned_int16_t LAT_Oc_Rls_var1_stiff_V3_dbg;
unsigned_int16_t LAT_Oc_Rls_var1_off_V3_dbg;
signed_int16_t LAT_Oc_Rls_stiff_V3_dbg;
signed_int16_t LAT_Oc_Rls_stiff_V4_dbg;
signed_int16_t LAT_Oc_Rls_Delta_L_dead_V4_dbg;
signed_int16_t LAT_Oc_Rls_Delta_L_Off_V4_dbg;
signed_int16_t LAT_Oc_Rls_stiffness_V2_dbg;
signed_int16_t LAT_Oc_Rls_Delta_L_Offset_V2_dbg;
signed_int16_t LAT_Oc_Rls_Delta_L_dead_V3_dbg;
signed_int16_t LAT_Oc_Rls_Delta_L_Off_V3_dbg;
signed_int16_t DMC_Steer_Angle_Oc_deg;
unsigned_int16_t SAC_Dynamic_Correction_Factor_dbg;
signed_int16_t SAC_Derated_Eps_Torque_dbg;
signed_int16_t DMC_ROAD_WHEEL_ANGLE;
signed_int16_t LAT_Road_Wheel_Angle_Cmd_deg;
unsigned_int16_t LAT_Gi_Status_dbg;
unsigned_int16_t reserved1;//for bytes alignment
//1byte

unsigned_char_t DMC_ADP_CORR_FACTOR_POS[20];
unsigned_char_t DMC_ADP_CORR_FACTOR_NEG[20];
unsigned_char_t DMC_ADP_CORR_FACTOR_POS_LOOP0[20];
unsigned_char_t DMC_ADP_CORR_FACTOR_NEG_LOOP0[20];
unsigned_char_t EpsSteerAngleAuthority;
unsigned_char_t DMC_FORCE_SHUT_OFF_REQUEST;
unsigned_char_t DMC_SHUT_OFF_ON_ERROR;
unsigned_char_t SSI_R_DMC_STFN_REQ;
unsigned_char_t SSI_R_DMC_OCCRCY_REQ;
unsigned_char_t BUS_EPS_STATUS;
signed_char_t DMC_FILTERED_LATERAL_ACC_COG;
unsigned_char_t DMC_LAT_EPS_DAMP_LVL_REQ;
unsigned_char_t MTO_HALF_SYSTEM_STS;
unsigned_char_t LADMC_STIFFNESS_LEVEL_REQUEST;
unsigned_char_t SAC_Requested_Damping_Level;
unsigned_char_t LAT_Eps_Torque_Request_Flag;
unsigned_char_t LaKMC_stiffness;
unsigned_char_t LaKMC_accuracy;
unsigned_char_t SAC_Disable;
unsigned_char_t SAC_Obs_Var_Delay;
unsigned_char_t VEH_Stability_Control_Active;   
unsigned_char_t VEH_Stability_Control_Active_temp;
unsigned_char_t LDP_Active;
unsigned_char_t LADMC_ACCURACY_LEVEL_REQUEST;
unsigned_char_t DMC_STIFFNESS_LIMIT;
unsigned_char_t DMC_TORQUE_SCALE_LIMIT;
unsigned_char_t DMC_HIGH_ACCURACY_REQUEST;
unsigned_char_t LADMC_DERATING_FACTOR_REQUEST;
unsigned_char_t LAT_Activation_Request_nu;
unsigned_char_t LAT_Activation_Request_Qf_nu;
unsigned_char_t LAT_Force_Shut_Off_Request;
unsigned_char_t LAT_Stiffness_Request_per;
unsigned_char_t LAT_Accuracy_Request_per;
unsigned_char_t LAT_Steering_Wheel_Vibration_nu;
unsigned_char_t LAT_Lane_Status_nu;
unsigned_char_t LAT_Derating_Level_Request_per;
unsigned_char_t LAT_Dmc_Status_nu;
unsigned_char_t LAT_Torque_Ramp_Factor_per;
unsigned_char_t DMC_ANGLE_FADING_REQ;
unsigned_char_t DMC_RAMPING_DOWN_REQ;
unsigned_char_t DMC_ANGLE_REQ_MAX_LIMIT_SCALE;
unsigned_char_t DMC_ANGLE_REQ_MAX_GRAD_SCALE;
unsigned_char_t SAC_Soc_Disable;
unsigned_char_t Turn_And_Error_Side;
unsigned_char_t Factor_Corr_Enable_Flag;
unsigned_char_t DMC_ANGLE_OFF_READ_ERROR;
unsigned_char_t DMC_ADP_CORR_FACTOR_READ_ERROR;
unsigned_char_t DMC_DERATING_LEVEL_REQ;
unsigned_char_t DMC_DRIVING_MODE;
boolean HALFTorqueOverlayFault;
boolean EPS_TEMP_DEACTIVATION_LDW;
boolean HALF_TORQUE_OVERLAY_ACTIVATED;
boolean BUS_EPS_TOR_BAR_TORQUE_QF;
boolean AYC_IN_CYCLE;
boolean FINAL_FUNCTION_DISABLE_AYC;
boolean FUNCTION_DISABLE_AYC;
boolean AYC_WARNING_LAMP;

} LaDMC_DebugBus_Type;
#endif                                 /* RTW_HEADER_DMC_Soc_types_h_ */
