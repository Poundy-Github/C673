/* $Header: DMC_Soc.c 1.65 2020/08/20 10:43:57CEST Feick, Stefan (uidw0691) none  $ */
/* ---MksAttribute: CodeSrc=Mdl;CodeGrp=Core--- */
/*
 ***************************************************************************************************
   Confidential and proprietary. This document and its contents are the exclusive property of
   Continental Teves AG Co. OHG (Teves) and Conti Temic microelectronic GmbH (Temic) and their
   associated companies. They are not to be copied, distributed, or otherwise disclosed or used
   without the prior written consent of Teves and Temic. All rights reserved.
 ***************************************************************************************************
   Filename of C source                 : DMC_Soc.c
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
/* PRQA S 502, 4131, 295, 3757, 3344, 3112, 2204, 2209, 2215, 3356, 3359, 3201, 3391, 3355, 3358, 272, 3415, 3390, 3398, 297, 272, 841, 2201, 3334, 499, 3203, 2002, 380, 4115, 4116, 602, 310, 2203, 3673, 311, 606, 3451, 4104, 4105, 4130, 2200, 5013, 3447, 2203, 3210 EOF */
/* --- Includes --- */
#include "DMC_Soc.h"
#include "DMC_Soc_private.h"

/*
 ***************************************************************************************************
   Table of INputs / OUTputs / STATEs / PARAms / CALLs / FILEs
   OUT: signed_int16_t LADMC_EPS_INTERFACE_ACTIVE_REQ, [0, 7], 1  1, LADMC_EPS_INTERFACE_ACTIVE_REQ
   OUT: signed_int16_t DMC_LAT_STATUS, [0, 100], 1  1, DMC_LAT_STATUS
   OUT: unsigned_int16_t DMC_EPS_STATUS, [0, 100], 1  1, DMC_EPS_STATUS
   OUT: signed_int16_t DMC_LONG_ENG_TRQ_REQ, [, ], 1  1, DMC_LONG_ENG_TRQ_REQ
   OUT: signed_int16_t DMC_LONG_BRK_TRQ_REQ, [, ], 1  1, DMC_LONG_BRK_TRQ_REQ
   OUT: unsigned_char_t LAT_Activation_Request__nu, [0, 100], 1  1, LAT_Activation_Request__nu
   OUT: unsigned_char_t LAT_Activation_Request_Qf__nu, [0, 100], 1  1, LAT_Activation_Request_Qf__nu
   OUT: unsigned_char_t LAT_Force_Shut_Off_Request, [0, 100], 1  1, LAT_Force_Shut_Off_Request
   OUT: signed_int16_t LAT_Steer_Angle_Command__deg, [, ], 1  1, LAT_Steer_Angle_Command__deg
   OUT: unsigned_char_t LAT_Stiffness_Request__per, [0, 100], 1  1, LAT_Stiffness_Request__per
   OUT: unsigned_char_t LAT_Accuracy_Request__per, [0, 100], 1  1, LAT_Accuracy_Request__per
   OUT: unsigned_char_t LAT_Steering_Wheel_Vibration__nu, [0, 100], 1  1, LAT_Steering_Wheel_Vibration__nu
   OUT: unsigned_char_t LAT_Lane_Status__nu, [0, 100], 1  1, LAT_Lane_Status__nu
   OUT: unsigned_char_t LAT_Derating_Level_Request__per, [0, 100], 1  1, LAT_Derating_Level_Request__per
   OUT: signed_int16_t LAT_Torque_Overlay_Request__nm, [, ], 1  1, LAT_Torque_Overlay_Request__nm
   OUT: unsigned_char_t LAT_Torque_Ramp_Factor__per, [, ], 1  1, LAT_TRQ_RAMP_FACTOR
   OUT: signed_int16_t DMC_ANGLE_OFF, [, ], 1  1, DMC_ANGLE_OFF
   OUT: unsigned_int16_t DMC_ANGLE_OFF_CALIB_CNT, [, ], 1  1, DMC_ANGLE_OFF_CALIB_CNT
   OUT: signed_int16_t DMC_Steer_Angle_Oc__deg, [, ], 1  1, DMC_Steer_Angle_Oc__deg
   OUT: signed_int16_t DMC_Eps_Integrator_Hold_Req__nu, [0, 7], 1  1, DMC_Eps_Integrator_Hold_Req__nu
   OUT: signed_int16_t LAT_Road_Wheel_Angle_Cmd__deg, [, ], 1  1, LAT_Road_Wheel_Angle_Cmd__deg
   IN: signed_int16_t SSI_R_DMC_LAT_ACTVN_MOD, [, ], 1  1, SSI_DMC_LAT_ACTVN_MOD
   IN: signed_int16_t SSI_R_DMC_CRVT_FEED_FWD, [, ], 1  1, SSI_DMC_CRVT_FEED_FWD
   IN: signed_int16_t SSI_R_DMC_CRVT_CHG_RATE, [, ], 1  1, SSI_DMC_CRVT_CHG_RATE
   IN: signed_int16_t SSI_R_DMC_CRVT_DFTL_BRKG, [, ], 1  1, SSI_DMC_CRVT_DFTL_BRKG
   IN: signed_int16_t SSI_R_DMC_CRVT_STEER_ACTR, [, ], 1  1, SSI_DMC_CRVT_STEER_ACTR
   IN: signed_int16_t SSI_R_DMC_STEER_AG_REQ, [, ], 1  1, SSI_DMC_STEER_AG_REQ
   IN: unsigned_char_t SSI_R_DMC_STFN_REQ, [, ], 1  1, SSI_DMC_STFN_REQ
   IN: unsigned_char_t SSI_R_DMC_OCCRCY_REQ, [, ], 1  1, SSI_DMC_OCCRCY_REQ
   IN: signed_int16_t SSI_R_DMC_LAT_ERR, [, ], 1  1, SSI_DMC_LAT_ERR
   IN: signed_int16_t SSI_R_DMC_HDNG_AG_ERR, [, ], 1  1, SSI_DMC_HDNG_AG_ERR
   IN: signed_int16_t SSI_R_DMC_STEER_WHL_VIBR, [, ], 1  1, SSI_DMC_STEER_WHL_VIBR
   IN: signed_int16_t EST_REFERENCE_VELOCITY, [, ], 1  1, ERV_Vel
   IN: signed_int16_t SSI_R_EPS_STEER_AG, [, ], 1  1, SSI_EPS_STEER_AG
   IN: signed_int16_t SSI_R_EPS_STEER_AG_RATE, [, ], 1  1, SSI_EPS_STEER_AG_RATE
   IN: signed_int16_t BUS_EPS_TOR_BAR_TORQUE, [, ], 1  1, BUSEPSTORTRQ
   IN: signed_int16_t BUS_EPS_ASSIST_TRQ, [, ], 1  1, BUSEPSASSITRQ
   IN: signed_int16_t BUS_EPS_MOTOR_TRQ, [, ], 1  1, BUSEPSMOTRTRQ
   IN: signed_int16_t BUS_EPS_STATUS, [, ], 1  1, BUSEPSSTATUS
   IN: unsigned_char_t SSI_R_ISOK_DMC_LAT_ACTVN_MOD, [, ], 1  1, SSIOK_DMC_LAT_ACTVN_MOD
   IN: unsigned_char_t SSI_R_ISOK_DMC_CRVT_FEED_FWD, [, ], 1  1, SSIOK_DMC_CRVT_FEED_FWD
   IN: unsigned_char_t SSI_R_ISOK_DMC_CRVT_CHG_RATE, [, ], 1  1, SSIOK_DMC_CRVT_CHG_RATE
   IN: unsigned_char_t SSI_R_ISOK_DMC_CRVT_DFTL_BRKG, [, ], 1  1, SSIOK_DMC_CRVT_DFTL_BRKG
   IN: unsigned_char_t SSI_R_ISOK_DMC_CRVT_STEER_ACTR, [, ], 1  1, SSIOK_DMC_CRVT_STEER_ACTR
   IN: unsigned_char_t SSI_R_ISOK_DMC_STEER_AG_REQ, [, ], 1  1, SSIOK_DMC_STEER_AG_REQ
   IN: unsigned_char_t SSI_R_ISOK_DMC_STFN_REQ, [, ], 1  1, SSIOK_DMC_STFN_REQ
   IN: unsigned_char_t SSI_R_ISOK_DMC_OCCRCY_REQ, [, ], 1  1, SSIOK_DMC_OCCRCY_REQ
   IN: unsigned_char_t SSI_R_ISOK_DMC_LAT_ERR, [, ], 1  1, SSIOK_DMC_LAT_ERR
   IN: unsigned_char_t SSI_R_ISOK_DMC_HDNG_AG_ERR, [, ], 1  1, SSIOK_DMC_HDNG_AG_ERR
   IN: unsigned_char_t SSI_R_ISOK_DMC_STEER_WHL_VIBR, [, ], 1  1, SSIOK_DMC_STEER_WHL_VIBR
   IN: unsigned_char_t BUS_EPS_TOR_BAR_TORQUE_QF, [, ], 1  1, BUSEPSTORTRQQF
   IN: unsigned_char_t HALFTorqueOverlayFault, [, ], 1  1, HALF_TORQUE_OVERLAY_FAULT
   IN: unsigned_char_t HALF_TORQUE_OVERLAY_ACTIVATED, [, ], 1  1, HALF_TORQUE_OVERLAY_ACTIVATED
   IN: unsigned_char_t EpsSteerAngleAuthority, [, ], 1  1, EpsSteerAngleAuthority
   IN: unsigned_char_t EPS_TEMP_DEACTIVATION_LDW, [, ], 1  1, EPS_TEMP_DEACTIVATION_LDW
   IN: signed_int16_t LODMC_REFERENCE_VEHACC, [, ], 1  1, LODMC_REFERENCE_VEHACC
   IN: signed_int16_t LODMC_ARB_REQ_ACC, [, ], 1  1, LODMC_ARB_REQ_ACC
   IN: unsigned_char_t LODMC_BUS_SELECTORPOSITION, [, ], 1  1, LODMC_BUS_SELECTORPOSITION
   IN: signed_int16_t LODMC_THROTTLE_POS, [, ], 1  1, LODMC_THROTTLE_POS
   IN: unsigned_char_t LODMC_ENGINE_ALLOWED, [, ], 1  1, LODMC_ACT_ENGINE_ALLOWED
   IN: unsigned_char_t LODMC_BRAKE_ALLOWED, [, ], 1  1, LODMC_ACT_BRAKE_ALLOWED
   IN: unsigned_char_t ABS_IN_CYCLE, [, ], 1  1, ABS_CYCLE
   IN: unsigned_char_t AYC_IN_CYCLE, [, ], 1  1, AYC_IN_CYCLE
   IN: unsigned_char_t TCS_ENGINE_CONTROL_ACTIVE, [, ], 1  1, EngCtrlAct
   IN: unsigned_char_t BTCS_IN_CYCLE, [, ], 1  1, BTCS_CYCLE
   IN: unsigned_char_t FINAL_FUNCTION_DISABLE_ABS, [, ], 1  1, FIN_ABS_DIS
   IN: unsigned_char_t FUNCTION_DISABLE_ABS, [, ], 1  1, ABS_DISABLED
   IN: unsigned_char_t FINAL_FUNCTION_DISABLE_AYC, [, ], 1  1, FIN_AYC_DIS
   IN: unsigned_char_t FUNCTION_DISABLE_AYC, [, ], 1  1, AYC_DISABLED
   IN: unsigned_char_t FINAL_FUNCTION_DISABLE_BTC, [, ], 1  1, FIN_BTC_DIS
   IN: unsigned_char_t FUNCTION_DISABLE_BTC, [, ], 1  1, BTC_DISABLED
   IN: unsigned_char_t FINAL_FUNCTION_DISABLE_MTC, [, ], 1  1, FIN_MTC_DIS
   IN: unsigned_char_t FUNCTION_DISABLE_MTC, [, ], 1  1, MTC_DISABLED
   IN: unsigned_char_t AYC_WARNING_LAMP, [, ], 1  1, FS_AYC_WL
   IN: signed_int16_t DMC_FILTERED_YAW_RATE, [, ], 1  1, DMCFYAWRATE
   IN: signed_int16_t DMC_FILTERED_YAW_RATE_QF, [, ], 1  1, DMCFYAWRATEQF
   IN: signed_char_t DMC_FILTERED_LATERAL_ACC_COG, [, ], 1  1, DMCFLATACCC
   IN: signed_int16_t DMC_FILTERED_LATERAL_ACC_COG_QF, [, ], 1  1, DMCFLATACCCQF
   IN: signed_int16_t DMC_FILTERED_STEER_ANGLE, [, ], 1  1, DMCFSTANGLE
   IN: signed_int16_t DMC_FILTERED_STEER_ANGLE_QF, [, ], 1  1, DMCFSTANGLEQF
   IN: signed_int16_t DMC_FILTERED_STEER_ANGLE_RATE, [, ], 1  1, DMCFSTANGLERATE
   IN: signed_int16_t DMC_FILTERED_STEER_ANGLE_RATE_QF, [, ], 1  1, DMCFSTANGLERATEQF
   IN: signed_int16_t SSI_R_LANE_STATUS, [, ], 1  1, SSI_LANE_STATUS
   IN: signed_int16_t DMC_CAM_CRVT_FEED_FWD, [, ], 1  1, DMC_CAM_CRVT_FEED_FWD
   IN: signed_int16_t DMC_CAM_LAT_ERR, [, ], 1  1, DMC_CAM_LAT_ERR
   IN: signed_int16_t DMC_CAM_HDNG_AG_ERR, [, ], 1  1, DMC_CAM_HDNG_AG_ERR
   IN: signed_int16_t DMC_STEER_ANGLE_OFFSET, [, ], 1  1, DMCSTEERANGLEOFFSET
   IN: signed_int16_t DMC_STEER_ANGLE_OFFSET_STATE, [, ], 1  1, DMCSTEERANGLEOFFSETSTATE
   IN: signed_int16_t UNCALIBRATED_SWA_FIL, [, ], 1  1, RAWSWAFL
   IN: signed_int16_t DMC_CAM_CRVT_FEED_FWD_QF, [, ], 1  1, DMC_CAM_CRVT_FEED_FWD_QF
   IN: signed_int16_t DMC_CAM_LAT_ERR_QF, [, ], 1  1, DMC_CAM_LAT_ERR_QF
   IN: signed_int16_t DMC_CAM_HDNG_AG_ERR_QF, [, ], 1  1, DMC_CAM_HDNG_AG_ERR_QF
   IN: signed_int16_t SSI_R_DMC_CRVT_SUM_CMD, [, ], 1  1, SSI_DMC_CRVT_SUM_CMD
   IN: signed_int16_t SSI_R_DMC_CRVT_CMD_RATE, [, ], 1  1, SSI_DMC_CRVT_CMD_RATE
   IN: signed_int16_t DMC_YAW_RATE_OFFSET, [, ], 1  1, DMCYAWRATEOFFSET
   IN: signed_int16_t DMC_YAW_RATE_OFFSET_STATE, [, ], 1  1, DMCYAWRATEOFFSETSTATE
   IN: unsigned_char_t DMC_FORCE_SHUT_OFF_REQUEST, [, ], 1  1, DMC_FORCE_SHUT_OFF_REQUEST
   IN: unsigned_char_t DMC_STIFFNESS_LIMIT, [, ], 1  1, DMCSTIFFLIMIT
   IN: signed_int16_t DMC_STIFFNESS_GRAD, [, ], 1  1, DMCSTIFFGRAD
   IN: unsigned_char_t DMC_TORQUE_SCALE_LIMIT, [, ], 1  1, DMCTRQSCALELIMIT
   IN: signed_int16_t DMC_TORQUE_SCALE_GRAD, [, ], 1  1, DMCTRQSCALEGRAD
   IN: signed_int16_t DMC_TORQUE_RAMP_GRAD, [, ], 1  1, DMCTORQUERAMPGRAD
   IN: unsigned_char_t DMC_HIGH_ACCURACY_REQUEST, [, ], 1  1, DMCHIGHACCURACYREQUEST
   IN: signed_int16_t LAT_Eps_Torque_Request__nm, [, ], 1  1, LAT_Eps_Torque_Request__nm
   IN: unsigned_char_t LAT_Dmc_Status__nu, [, ], 1  1, LAT_Dmc_Status__nu
   IN: unsigned_char_t DMC_ANGLE_FADING_REQ, [, ], 1  1, DMC_ANGLE_FADING_REQ
   IN: unsigned_char_t DMC_RAMPING_DOWN_REQ, [, ], 1  1, DMC_RAMPING_DOWN_REQ
   IN: unsigned_char_t DMC_ANGLE_REQ_MAX_LIMIT_SCALE, [, ], 1  1, DMC_ANGLE_REQ_MAX_LIMIT_SCALE
   IN: unsigned_char_t DMC_ANGLE_REQ_MAX_GRAD_SCALE, [, ], 1  1, DMC_ANGLE_REQ_MAX_GRAD_SCALE
   IN: signed_int16_t DMC_ANGLE_OFF_LOOP0, [, ], 1  1, DMC_ANGLE_OFF_LOOP0
   IN: unsigned_int16_t DMC_ANGLE_OFF_CALIB_CNT_LOOP0, [, ], 1  1, DMC_ANGLE_OFF_CALIB_CNT_LOOP0
   IN: unsigned_char_t DMC_ANGLE_OFF_READ_ERROR, [, ], 1  1, DMC_ANGLE_OFF_READ_ERROR
   IN: unsigned_char_t DMC_ADP_CORR_FACTOR_POS_LOOP0, [, ], 20   1, DMC_ADP_CORR_FACTOR_POS_LOOP0
   IN: unsigned_char_t DMC_ADP_CORR_FACTOR_NEG_LOOP0, [, ], 20   1, DMC_ADP_CORR_FACTOR_NEG_LOOP0
   IN: unsigned_int16_t DMC_ADP_CORR_COUNTER_POS_LOOP0, [, ], 20   1, DMC_ADP_CORR_COUNTER_POS_LOOP0
   IN: unsigned_int16_t DMC_ADP_CORR_COUNTER_NEG_LOOP0, [, ], 20   1, DMC_ADP_CORR_COUNTER_NEG_LOOP0
   IN: unsigned_char_t DMC_ADP_CORR_FACTOR_READ_ERROR, [, ], 1  1, DMC_ADP_CORR_FACTOR_READ_ERROR
   IN: unsigned_char_t DMC_DERATING_LEVEL_REQ, [, ], 1  1, DMC_DERATING_LEVEL_REQ
   IN: unsigned_char_t DMC_DRIVING_MODE, [, ], 1  1, DMC_DRIVING_MODE
   IN: signed_int16_t DMC_BANK_ANGLE, [, ], 1  1, DMC_BANK_ANGLE
   IN: signed_int16_t DMC_GPIO, [, ], 1  1, DMC_GPIO
   IN: signed_int16_t EMO_PITCH_ANGLE, [, ], 1  1, EMO_PITCH_ANGLE
   IN: signed_int16_t DMC_GPIO2, [, ], 1  1, DMC_GPIO2
   IN: signed_int16_t DMC_GPIO3, [, ], 1  1, DMC_GPIO3
   IN: signed_int16_t DMC_GPIO4, [, ], 1  1, DMC_GPIO4
   PARA: signed_int16_t Lat_min_offset_state, [, ], 1  1,
   PARA: signed_int16_t Lat_min_yaw_rate_offset_state, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_min_kappa_quality, [, ], 1  1,
   PARA: signed_int16_t Sac_activation_override, [, ], 1  1,
   PARA: signed_int16_t Sac_one_by_ts, [, ], 1  1,
   PARA: unsigned_int16_t Dmc_configuration_mode, [, ], 1  1,
   PARA: unsigned_int16_t Dmc_configuration_mode_2, [, ], 1  1,
   PARA: unsigned_int16_t Dmc_configuration_mode_3, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_compensation_mode, [, ], 1  1,
   PARA: unsigned_int16_t Exc_restart_chirp, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_off_flt_initial_loops, [, ], 1  1,
   PARA: unsigned_int16_t Lat_dmc_status_override_cycles, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_foretime_loops, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_minimum_confidence, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_yaw_debounce_loops, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_yaw_debounce_thrs, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_discharge_slope, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_const_trq_cnt_max_limit, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_const_trq_cnt_threshold, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_const_trq_pos_increment, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_dys_pre_filter_length, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_min_head_err_qual, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_min_latency, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_min_offset_state, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_minimum_latency, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_minimum_latency_shrt, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_controller_mode, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_downsample, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_min_state_nvm, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_weighting_power, [, ], 1  1,
   PARA: unsigned_int16_t Lat_pitch_max_accuracy, [, ], 1  1,
   PARA: unsigned_int16_t Lat_select_input_source, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_curvature_dot_slope, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_curvature_slope, [, ], 1  1,
   PARA: unsigned_int16_t Ldc_controller_mode, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_mode, [, ], 1  1,
   PARA: unsigned_int16_t Sac_controller_mode_1, [, ], 1  1,
   PARA: unsigned_int16_t Sac_controller_mode_2, [, ], 1  1,
   PARA: unsigned_int16_t Sac_derating_override, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_activ_source, [, ], 1  1,
   PARA: unsigned_int16_t Sac_lin_fad_enable_multi_ramp, [, ], 1  1,
   PARA: unsigned_int16_t Sac_stiffness_override, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_derating_mode, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_boost_signal_reduction, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_dot_boost_thrs, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_dot_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_state_filter_time_constant, [, ], 1  1,
   PARA: unsigned_int16_t Hec_yaw_rate_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_control_cmd_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_controller_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_f_dot_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_off_flt_initial_omega, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_offset_filter_omega, [, ], 1  1,
   PARA: unsigned_int16_t Lat_derating_factor_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_direct_feedthrough_kappa, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_dot_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_yaw_dot_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_discharge_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_gradient_aes, [, ], 1  1,
   PARA: unsigned_int16_t Lat_max_kappa_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_fast_ki, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_cmd_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_ffwd_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_delta_psi, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_sign_delta_ys_weighting, [, ], 1  1,
   PARA: unsigned_int16_t Lat_pitch_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ref_ctrl_delt_dot_flt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ref_ctrl_parity_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ref_pt1_control_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_support_ay_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_support_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_support_memshp_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_yaw_rate_dot_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lat_yaw_rate_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_curv_dot_filter_fall_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_curv_dot_filter_risng_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_error_filter_falling_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_error_filter_rising_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_filter_falling_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Lco_filter_rising_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Mot_mean_value_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Sac_backlash_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Sac_feedforward_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Sac_pt1_filter_coeff_2, [, ], 1  1,
   PARA: unsigned_int16_t Sac_pt1_filter_coeff_3, [, ], 1  1,
   PARA: unsigned_int16_t Sac_pt1_filter_coeff_6, [, ], 1  1,
   PARA: unsigned_int16_t Sac_pt1_filter_coeff_7, [, ], 1  1,
   PARA: unsigned_int16_t Sac_pt1_max_filter_coeff_2, [, ], 1  1,
   PARA: unsigned_int16_t Sac_ts, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_pt1_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_yr_cmd_dot_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_comp_factor_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_delta_f_latency_comp_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_min_compensation_factor, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_pac_resid_rising_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_pac_residue_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_pac_torque_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_pac_torque_vel_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_pac_trq_req_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_torque_ff_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_trq_ctrl_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_trq_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_trq_resd_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_torque_der_filt_coeff_hf, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_torque_derating_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_trq_filter_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_vel_der_falling_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_vel_der_rising_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_vel_derating_filt_coeff, [, ], 1  1,
   PARA: unsigned_int16_t Acf_slop_lateral_error_fact_dec, [, ], 1  1,
   PARA: unsigned_int16_t Acf_slop_lateral_error_fact_inc, [, ], 1  1,
   PARA: unsigned_int16_t Acf_slop_road_gradient_fact_dec, [, ], 1  1,
   PARA: unsigned_int16_t Acf_slop_road_gradient_fact_inc, [, ], 1  1,
   PARA: unsigned_int16_t Adp_dyc_corr_fact_dec_y_sched, [, ], 1  12,
   PARA: unsigned_int16_t Adp_dyc_corr_fact_inc_y_sched, [, ], 1  12,
   PARA: unsigned_int16_t Adp_dyc_corr_factor_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Adp_dyc_corr_factor_lower_limit, [, ], 1  1,
   PARA: unsigned_int16_t Adp_dyc_corr_factor_upper_limit, [, ], 1  1,
   PARA: unsigned_int16_t Dit_dirac_loop_count, [, ], 1  1,
   PARA: unsigned_int16_t Dit_signal_gen_frequency, [, ], 1  1,
   PARA: unsigned_int16_t Dit_torque_pulse_amplitude, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_boost_factor, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_boost_factor_neg, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_boost_factor_pos, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_angle_ldp_corr_y_sch, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_time_constant_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Hec_r_dot_factor, [, ], 1  1,
   PARA: unsigned_int16_t Hec_r_dot_factor_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Hec_r_factor_obf, [, ], 1  1,
   PARA: unsigned_int16_t Hec_r_obf_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Lat_ay_arw_k, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_cmd_margin_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_comp_eps_damping, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_comp_eps_time_const, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_compensation_time_const, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_control_kd, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_control_ki, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_control_kp, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_control_pt1_kp, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_ctrl_detach_thrs, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_ctrl_i_part_margin, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_ctrl_min_jerk, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_ctrl_reset_thrs, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_ctrl_torque_thrs, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_decreasing_threshold, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_max_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Lat_ay_parity_time_const, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_sat_margin_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ay_threshold_decrement, [, ], 1  1,
   PARA: unsigned_int16_t Lat_damp_eps_damping, [, ], 1  1,
   PARA: unsigned_int16_t Lat_damp_eps_time_const, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_f_offset_max_nvm, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_f_offset_max_nvm_strt, [, ], 1  1,
   PARA: unsigned_int16_t Lat_delta_f_offset_variation, [, ], 1  1,
   PARA: unsigned_int16_t Lat_force_trq_shut_off_time, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_debounce_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_min_delta_f_cmd_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_min_lateral_error, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_min_lateral_error_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_min_yaw_rate_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_min_yrc_residl_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Lat_gi_quadrnt_discharge_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_lateral_error_slope, [, ], 1  1,
   PARA: unsigned_int16_t Lat_kappa_max_lateral_error, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ldp_counter_preload, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ldp_kappa_gain, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ldp_startup_time, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ldp_switch_decrement, [, ], 1  1,
   PARA: unsigned_int16_t Lat_lka_startup_time, [, ], 1  1,
   PARA: unsigned_int16_t Lat_max_kappa_grad_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Lat_oc_calib_cnt_grad, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_delta_f_offset, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_delta_ki, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_implaus_lateral_error, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_max_driver_torque, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_max_learning_rate, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_delta_f_dot, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_delta_offset, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_delta_offset_kappa, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_driver_torque, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_lateral_accel, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_lateral_error, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_max_offset_rate, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_min_lateral_error, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_max_angle, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_max_angle_speed, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_max_holding_time, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_min_driver_torque, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_min_veh_velocity, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_offset_init, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_offset_saturation, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_reset, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_rls_stiffness_init, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_small_driver_torque, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_tolerated_delta_ys, [, ], 1  1,
   PARA: unsigned_int16_t Lat_pitch_threshold, [, ], 1  1,
   PARA: unsigned_int16_t Lat_r_factor_level_decrement, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ref_control_k_pt1, [, ], 1  1,
   PARA: unsigned_int16_t Lat_ref_control_kd, [, ], 1  1,
   PARA: unsigned_int16_t Lat_status_first_run_time, [, ], 1  1,
   PARA: unsigned_int16_t Lat_stiffness_falling_decrement, [, ], 1  1,
   PARA: unsigned_int16_t Lat_support_enhancement_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lat_support_factor_y_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Lat_support_torque_gain, [, ], 1  1,
   PARA: unsigned_int16_t Lat_support_torque_threshold, [, ], 1  1,
   PARA: unsigned_int16_t Lco_curv_dot_preload_enh_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_control_error, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_control_error_slope, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_err_preload_enh_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_lateral_error, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_lateral_error_slope, [, ], 1  1,
   PARA: unsigned_int16_t Lco_min_load_comp_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lco_preload_enhancement_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lka_max_align_torque, [, ], 1  1,
   PARA: unsigned_int16_t Mot_modulation_duty_cycle, [, ], 1  1,
   PARA: unsigned_int16_t Mot_signal_gen_freq_modulation, [, ], 1  1,
   PARA: unsigned_int16_t Mot_signal_gen_frequency_base, [, ], 1  1,
   PARA: unsigned_int16_t Mot_torque_duty_cycle, [, ], 1  1,
   PARA: unsigned_int16_t Mot_torque_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Prf_t_nom, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_cmd_limit_margin_fact, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_cmd_limit_out_mn_fact, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_time, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_time_bump, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_time_dys_grad, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_time_min, [, ], 1  1,
   PARA: unsigned_int16_t Sac_angle_fading_time_mode_chg, [, ], 1  1,
   PARA: unsigned_int16_t Sac_anglerate_ctrl_sat_kp, [, ], 1  1,
   PARA: unsigned_int16_t Sac_backlash_omega, [, ], 1  1,
   PARA: unsigned_int16_t Sac_backlash_t_nom, [, ], 1  1,
   PARA: unsigned_int16_t Sac_cmd_feedforward_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_comp_factor_y_scheduling, [, ], 1  13,
   PARA: unsigned_int16_t Sac_delta_cmd_ffwd_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_delta_f_cmd_feedfwd_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grad_aes, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grad_barrier, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grad_fading, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grad_rampout, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grad_straight, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grd_aes_cr_y_sc, [, ], 1  11,
   PARA: unsigned_int16_t Sac_delta_f_cmd_initial_grad, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_cmd_min_grad, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_counter_steer_grad, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_f_latency, [, ], 1  1,
   PARA: unsigned_int16_t Sac_delta_grad_barrier_y_sched, [, ], 1  12,
   PARA: unsigned_int16_t Sac_delta_gradient_lcf_y_sched, [, ], 1  12,
   PARA: unsigned_int16_t Sac_delta_gradient_obf_y_sched, [, ], 1  12,
   PARA: unsigned_int16_t Sac_delta_gradient_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_dyn_corr_factor_decrement, [, ], 1  1,
   PARA: unsigned_int16_t Sac_dynamic_corr_factor_aes, [, ], 1  1,
   PARA: unsigned_int16_t Sac_dynamic_corr_factor_grdscal, [, ], 1  1,
   PARA: unsigned_int16_t Sac_dynamic_corr_factor_obf, [, ], 1  1,
   PARA: unsigned_int16_t Sac_dynamic_corr_min_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_dynamic_corr_min_y_schedul, [, ], 1  12,
   PARA: unsigned_int16_t Sac_dynamic_corr_obf_y_schedul, [, ], 1  12,
   PARA: unsigned_int16_t Sac_dynamic_correction_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_eps_no_control_error, [, ], 1  1,
   PARA: unsigned_int16_t Sac_feedfwd_factor_y_scheduling, [, ], 1  13,
   PARA: unsigned_int16_t Sac_feedthr_increment_per_loop, [, ], 1  1,
   PARA: unsigned_int16_t Sac_ffwd_scale_pos_angle_cmd, [, ], 1  1,
   PARA: unsigned_int16_t Sac_frc_comp_b1_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_frc_comp_omega, [, ], 1  1,
   PARA: unsigned_int16_t Sac_frc_static_friction_torque, [, ], 1  1,
   PARA: unsigned_int16_t Sac_frc_torque_corr_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_linear_slope, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_scaling_end, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_scaling_start, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_torque, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_jerk_gradient_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_jerk_inverse_eg_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_jerk_max, [, ], 1  1,
   PARA: unsigned_int16_t Sac_jerk_prediction_time, [, ], 1  1,
   PARA: unsigned_int16_t Sac_jerk_weighting, [, ], 1  1,
   PARA: unsigned_int16_t Sac_kd, [, ], 1  1,
   PARA: unsigned_int16_t Sac_kd_fading_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_kd_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_kmc_loop_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_kp, [, ], 1  1,
   PARA: unsigned_int16_t Sac_kp_derating_slope, [, ], 1  1,
   PARA: unsigned_int16_t Sac_kp_ldp, [, ], 1  1,
   PARA: unsigned_int16_t Sac_kp_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_lin_fading_activation_thrs, [, ], 1  1,
   PARA: unsigned_int16_t Sac_lin_fading_coefficient, [, ], 1  1,
   PARA: unsigned_int16_t Sac_lin_fading_gate_time, [, ], 1  1,
   PARA: unsigned_int16_t Sac_lin_fading_max_offset, [, ], 1  1,
   PARA: unsigned_int16_t Sac_lin_fading_min_offset, [, ], 1  1,
   PARA: unsigned_int16_t Sac_low_grad_max_dys, [, ], 1  1,
   PARA: unsigned_int16_t Sac_maximum_accuracy_request, [, ], 1  1,
   PARA: unsigned_int16_t Sac_maximum_stiffness_request, [, ], 1  1,
   PARA: unsigned_int16_t Sac_min_control_error, [, ], 1  1,
   PARA: unsigned_int16_t Sac_parity_time_const_barrier, [, ], 1  1,
   PARA: unsigned_int16_t Sac_pid_kd, [, ], 1  1,
   PARA: unsigned_int16_t Sac_pid_kd_damp_mode, [, ], 1  1,
   PARA: unsigned_int16_t Sac_reduced_kmc_loop_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_ctrl_cmd_fading_y_sched, [, ], 1  11,
   PARA: unsigned_int16_t Sac_yrc_kd_fading_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_ki_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_kp_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_kp_pt1_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sat_dynamic_enhancement_factor, [, ], 1  1,
   PARA: unsigned_int16_t Sat_max_cmd_factor_aes_y_sched, [, ], 1  13,
   PARA: unsigned_int16_t Sat_max_cmd_factor_y_scheduling, [, ], 1  13,
   PARA: unsigned_int16_t Tdf_activation_gain, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_comp_filter_min_residual, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_control_err_derating_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_control_error_sign_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_control_error_sign_slope_2, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_damping_gain, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_delta_f_latency, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_derating_level_decrement, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_derating_max_angle, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_derating_max_factor, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_derating_min_factor, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_derating_slope_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_derating_thrs_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_load_comp_end, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_load_comp_start, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_load_comp_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_min_steer_trq_cls_y_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_out_scale_filt_min_residual, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_pac_request_sign_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_pac_torque_residue, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_st_wheel_unbalance_factor, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_torque_comp_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_torque_comp_thrs_ldp, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_torque_ffwd_gain, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_torque_sign_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_torque_sign_slope_2, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_steer_trq_cmp_ldp_y_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_steer_trq_cmp_slp_y_schedul, [, ], 1  12,
   PARA: unsigned_int16_t Tdf_steer_trq_ff_gain_y_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_torque_derating_threshold, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_torque_reduc_gain_y_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_torque_request_sign_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_trq_derating_max_init_trq, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_trq_derating_slope_hf_path, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_trq_derating_threshold_dp, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_trq_derating_thrs_y_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_velocity_derating_slope, [, ], 1  1,
   PARA: unsigned_int16_t Tdf_velocity_derating_threshold, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_factor, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_pos_corr_factor, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a2_y_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_a3_factor, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_a3_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Dyc_kappa_angle_gen_cor_fct_neg, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_angle_gen_corr_factor, [, ], 1  1,
   PARA: unsigned_int16_t Dyc_kappa_angle_lpf_corr_factor, [, ], 1  1,
   PARA: unsigned_int16_t Lat_saturation_class_thr, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_loop_gain_corr, [, ], 1  1,
   PARA: unsigned_int16_t Acf_min_sac_enabled_time, [, ], 1  1,
   PARA: unsigned_int16_t Adp_dyc_corr_fact_dec_x_sched, [, ], 1  12,
   PARA: unsigned_int16_t Adp_dyc_corr_fact_inc_x_sched, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_a2_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_a3_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_x_schedul_aes, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_x_schedul_gen, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_time_constant_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Hec_r_dot_factor_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Hec_r_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Lat_ay_max_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Lat_max_kappa_grad_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Lat_oc_max_velocity, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_min_velocity, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_min_velocity_dys, [, ], 1  1,
   PARA: unsigned_int16_t Lat_support_factor_x_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Sac_comp_factor_x_scheduling, [, ], 1  13,
   PARA: unsigned_int16_t Sac_delta_cmd_ffwd_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_delta_f_cmd_grd_aes_cr_x_sc, [, ], 1  11,
   PARA: unsigned_int16_t Sac_delta_grad_barrier_x_sched, [, ], 1  12,
   PARA: unsigned_int16_t Sac_delta_gradient_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_dynamic_corr_min_x_schedul, [, ], 1  12,
   PARA: unsigned_int16_t Sac_feedfwd_factor_x_scheduling, [, ], 1  13,
   PARA: unsigned_int16_t Sac_friction_comp_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_kd_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_kp_x_scheduling, [, ], 1  12,
   PARA: unsigned_int16_t Sac_yrc_ctrl_cmd_fading_x_sched, [, ], 1  11,
   PARA: unsigned_int16_t Sac_yrc_kp_pt1_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Sac_yrc_kp_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Sat_max_cmd_factor_x_scheduling, [, ], 1  13,
   PARA: unsigned_int16_t Tdf_derating_slope_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_derating_thrs_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_load_comp_x_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_min_steer_trq_cls_x_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_steer_trq_cmp_ldp_x_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Tdf_steer_trq_cmp_slp_x_schedul, [, ], 1  12,
   PARA: unsigned_int16_t Tdf_trq_derating_thrs_x_schedul, [, ], 1  11,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_y_sch_aes_neg, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_y_sch_gen_neg, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_y_schedul_aes, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_y_schedul_gen, [, ], 1  12,
   PARA: unsigned_int16_t Dyc_kappa_angle_t_y_schedul_nom, [, ], 1  12,
   PARA: unsigned_int16_t Lat_torque_gradient, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_comp_error_gain, [, ], 1  1,
   PARA: unsigned_int16_t Sac_friction_control_error_gain, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_max_steer_angle, [, ], 1  1,
   PARA: signed_int16_t Exc_chirp_ay_offset, [, ], 1  1,
   PARA: signed_int16_t Exc_chirp_delta_torque, [, ], 1  1,
   PARA: signed_int16_t Exc_chirp_start_frequency, [, ], 1  1,
   PARA: signed_int16_t Exc_signal_amplitude, [, ], 1  1,
   PARA: signed_int16_t Exc_signal_gen_frequency, [, ], 1  1,
   PARA: signed_int16_t Exc_trq_signal_amplitude, [, ], 1  1,
   PARA: signed_int16_t Exc_trq_signal_gen_frequency, [, ], 1  1,
   PARA: signed_int16_t Lat_delta_f_offset, [, ], 1  1,
   PARA: signed_int16_t Lat_gi_yaw_rate_offset, [, ], 1  1,
   PARA: signed_int16_t Lat_max_ay, [, ], 1  1,
   PARA: signed_int16_t Lat_max_ay_aes, [, ], 1  1,
   PARA: signed_int16_t Lat_max_ay_tja, [, ], 1  1,
   PARA: signed_int16_t Lat_max_output_torque, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_max, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_max_clm_trq, [, ], 1  1,
   PARA: signed_int16_t Mot_signal_gen_amplitude, [, ], 1  1,
   PARA: signed_int16_t Prf_t_nom_2, [, ], 1  1,
   PARA: signed_int16_t Sac_backlash_angle, [, ], 1  1,
   PARA: signed_int16_t Sac_ffwd_diff_filter_omega, [, ], 1  1,
   PARA: signed_int16_t Sac_friction_comp_torque_cw, [, ], 1  1,
   PARA: signed_int16_t Sac_kd_max_fading_factor, [, ], 1  1,
   PARA: signed_int16_t Sac_kd_obs, [, ], 1  1,
   PARA: signed_int16_t Sac_load_compensation_factor, [, ], 1  1,
   PARA: signed_int16_t Sac_notch_l1, [, ], 1  1,
   PARA: signed_int16_t Sac_notch_l2, [, ], 1  1,
   PARA: signed_int16_t Sac_notch_l3, [, ], 1  1,
   PARA: signed_int16_t Tdf_derating_thrs_eps_i_hold, [, ], 1  1,
   PARA: signed_int16_t Tdf_min_steer_torque_class, [, ], 1  1,
   PARA: signed_int16_t Tdf_min_str_trq_class_handsoff, [, ], 1  1,
   PARA: signed_int16_t Tdf_toque_derating_slope, [, ], 1  1,
   PARA: signed_int16_t Tdf_torque_reduction_gain, [, ], 1  1,
   PARA: signed_int16_t Tdf_torque_reduction_p_gain, [, ], 1  1,
   PARA: signed_int16_t Veh_one_by_column_stiffness, [, ], 1  1,
   PARA: signed_int16_t Veh_steer_gear_ratio_y_tab, [, ], 1  6,
   PARA: signed_int16_t Lat_oc_ki, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_confid_threshold_2, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_confidence_threshold, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_input_filter_coeff, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_lambda, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_offset_increment, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_var_stiffness_init, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_rls_variance_offset_init, [, ], 1  1,
   PARA: signed_int16_t Sac_fad_flt_fallng_lw_dyn_coeff, [, ], 1  1,
   PARA: signed_int16_t Sac_fad_flt_rising_lw_dyn_coeff, [, ], 1  1,
   PARA: signed_int16_t Sac_kp_fading_flt_falling_coeff, [, ], 1  1,
   PARA: signed_int16_t Sac_kp_fading_flt_rising_coeff, [, ], 1  1,
   PARA: signed_int16_t Lat_kappa_discharge_min_error, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_max_kappa, [, ], 1  1,
   PARA: signed_int16_t Lat_oc_max_kappa_dys, [, ], 1  1,
   PARA: signed_int16_t Lco_min_curvature_command, [, ], 1  1,
   PARA: signed_int16_t Lco_min_curvature_dot, [, ], 1  1,
   PARA: unsigned_int16_t Lat_oc_kappa_max_heading_error, [, ], 1  1,
   PARA: unsigned_int16_t Lat_switch_falling_rate_2, [, ], 1  1,
   PARA: unsigned_int16_t Lat_switch_rising_rate_2, [, ], 1  1,
   PARA: unsigned_int16_t Sac_parity_time_constant, [, ], 1  1,
   PARA: unsigned_int16_t Sac_parity_time_constant_ldp, [, ], 1  1,
   PARA: unsigned_int16_t Sac_parity_time_constant_low, [, ], 1  1,
   PARA: unsigned_int16_t Sat_thrs_control_kp, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_inc_per_loop_slow, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_inc_per_loop_turn_on, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_increment_per_loop, [, ], 1  1,
   PARA: signed_int16_t Lat_offset_out_incr_per_loop, [, ], 1  1,
   PARA: unsigned_int16_t Sac_yrc_kp_pt1_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Sac_yrc_kp_y_scheduling, [, ], 1  11,
   PARA: unsigned_int16_t Sat_max_delta_f_cmd, [, ], 1  1,
   PARA: unsigned_int16_t Sat_max_delta_f_cmd_phy, [, ], 1  1,
   PARA: signed_int16_t Prf_omega, [, ], 1  1,
   PARA: signed_int16_t Prf_omega_2, [, ], 1  1,
   PARA: signed_int16_t Veh_steer_gear_ratio_x_tab, [, ], 1  6,
   PARA: unsigned_char_t Acf_no_of_items_in_sample, [, ], 1  1,
   PARA: unsigned_char_t Acf_no_of_segment_selection, [, ], 1  1,
   PARA: unsigned_char_t Veh_steer_angle_rate_source, [, ], 1  1,
   PARA: unsigned_char_t Veh_steer_angle_source, [, ], 1  1,
   CALL: DMC_Soc_step()
   CALL: DMC_Soc_initialize(0)
   FILE: DMC_Soc.c
 ***************************************************************************************************
 */

/* ClPr: added because linking errors (variables are declared extern in dmc_ac.h and dmc_if.h and dmc_ram.h) */
signed_int16_t BUS_EPS_ASSIST_TRQ;
signed_int16_t BUS_EPS_MOTOR_TRQ;
unsigned_char_t EpsSteerAngleAuthority;
boolean HALFTorqueOverlayFault;
boolean EPS_TEMP_DEACTIVATION_LDW;
boolean HALF_TORQUE_OVERLAY_ACTIVATED;
signed_int16_t SSI_R_DMC_LAT_ACTVN_MOD;
signed_int16_t SSI_R_DMC_CRVT_SUM_CMD;
signed_int16_t SSI_R_DMC_CRVT_FEED_FWD;
signed_int16_t SSI_R_DMC_CRVT_CHG_RATE;
signed_int16_t SSI_R_DMC_CRVT_STEER_ACTR;
signed_int16_t SSI_R_DMC_CRVT_CMD_RATE;
signed_int16_t SSI_R_DMC_STEER_AG_REQ;
signed_int16_t DMC_CAM_CRVT_FEED_FWD;
signed_int16_t DMC_CAM_LAT_ERR;
signed_int16_t DMC_CAM_HDNG_AG_ERR;
signed_int16_t DMC_CAM_CRVT_FEED_FWD_QF;
signed_int16_t DMC_CAM_LAT_ERR_QF;
signed_int16_t DMC_CAM_HDNG_AG_ERR_QF;
unsigned_char_t DMC_FORCE_SHUT_OFF_REQUEST;
unsigned_char_t DMC_SHUT_OFF_ON_ERROR;
unsigned_char_t SSI_R_DMC_STFN_REQ;
unsigned_char_t SSI_R_DMC_OCCRCY_REQ;
signed_int16_t SSI_R_DMC_LAT_ERR;
signed_int16_t SSI_R_DMC_HDNG_AG_ERR;
signed_int16_t SSI_R_EPS_STEER_AG;
signed_int16_t SSI_R_EPS_STEER_AG_RATE;
signed_int16_t SSI_R_DMC_STEER_WHL_VIBR;
signed_int16_t SSI_R_LANE_STATUS;
signed_int16_t EST_REFERENCE_VELOCITY;
signed_int16_t BUS_EPS_TOR_BAR_TORQUE;
unsigned_char_t BUS_EPS_STATUS;
boolean BUS_EPS_TOR_BAR_TORQUE_QF;
boolean AYC_IN_CYCLE;
boolean FINAL_FUNCTION_DISABLE_AYC;
boolean FUNCTION_DISABLE_AYC;
boolean AYC_WARNING_LAMP;
signed_int16_t DMC_FILTERED_YAW_RATE;
signed_int16_t DMC_FILTERED_YAW_RATE_QF;
signed_char_t DMC_FILTERED_LATERAL_ACC_COG;
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
/*!< @ASAP_NAME DMC_EPS_TRQ_REQ @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Vehicle yaw torque request for actuator wheel brake (DMC_EPS_TRQ_REQ) */
signed_int16_t LaDMC_status;
/*!< @ASAP_NAME LaDMC_status @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 7 @OFFSET 0 @brief comment (LaDMC_status) */
signed_int16_t LADMC_EPS_TORQUE_REQUEST;
/*!< @ASAP_NAME LADMC_EPS_TORQUE_REQUEST @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LADMC_EPS_TORQUE_REQUEST) */
signed_int16_t LaDMC_Eps_Request_Flag;
/*!< @ASAP_NAME LaDMC_Eps_Request_Flag @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 7 @OFFSET 0 @brief comment (LaDMC_Eps_Request_Flag) */
signed_int16_t LADMC_EPS_INTERFACE_ACTIVE_REQ;
/*!< @ASAP_NAME LADMC_EPS_INTERFACE_ACTIVE_REQ @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 7 @OFFSET 0 @brief comment (LADMC_EPS_INTERFACE_ACTIVE_REQ) */
unsigned_char_t DMC_LAT_EPS_DAMP_LVL_REQ;
/*!< @ASAP_NAME DMC_LAT_EPS_DAMP_LVL_REQ @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (DMC_LAT_EPS_DAMP_LVL_REQ) */
signed_int16_t DMC_LAT_STATUS;
/*!< @ASAP_NAME DMC_LAT_STATUS @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (DMC_LAT_STATUS) */
unsigned_int16_t DMC_EPS_STATUS;
/*!< @ASAP_NAME DMC_EPS_STATUS @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (DMC_EPS_STATUS) */
unsigned_char_t MTO_HALF_SYSTEM_STS;
/*!< @ASAP_NAME MTO_HALF_SYSTEM_STS @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 1 @OFFSET 0 @brief comment (MTO_HALF_SYSTEM_STS) */
signed_int16_t LADMC_STEER_ANGLE_RATE_REQ;
/*!< @ASAP_NAME LADMC_STEER_ANGLE_RATE_REQ @UNIT - @LSB 0.0039062500 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LADMC_STEER_ANGLE_RATE_REQ) */
unsigned_char_t LADMC_STIFFNESS_LEVEL_REQUEST;
/*!< @ASAP_NAME LADMC_STIFFNESS_LEVEL_REQUEST @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LADMC_STIFFNESS_LEVEL_REQUEST) */
signed_int16_t DMC_LONG_ENG_TRQ_REQ;
/*!< @ASAP_NAME DMC_LONG_ENG_TRQ_REQ @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief - (DMC_LONG_ENG_TRQ_REQ) */
signed_int16_t DMC_LONG_BRK_TRQ_REQ;
/*!< @ASAP_NAME DMC_LONG_BRK_TRQ_REQ @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief - (DMC_LONG_BRK_TRQ_REQ) */
signed_int16_t SaRateSig;
/*!< @ASAP_NAME SaRateSig @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SaRateSig) */
signed_int16_t SaRateQ;
/*!< @ASAP_NAME SaRateQ @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SaRateQ) */
float32 DYC_Steer_Angle_Feedforward;
/*!< @ASAP_NAME DYC_Steer_Angle_Feedforward @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (DYC_Steer_Angle_Feedforward) */
float32 LAT_Eps_Torque_Request;
/*!< @ASAP_NAME LAT_Eps_Torque_Request @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Eps_Torque_Request) */
unsigned_char_t SAC_Requested_Damping_Level;
/*!< @ASAP_NAME SAC_Requested_Damping_Level @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Requested_Damping_Level) */
float32 VEH_Delta_F_Dot_Est_Arb;
/*!< @ASAP_NAME VEH_Delta_F_Dot_Est_Arb @UNIT deg/s @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Delta_F_Dot_Est_Arb) */
float32 LAT_Delta_Ys;
/*!< @ASAP_NAME LAT_Delta_Ys @UNIT m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Delta_Ys) */
float32 LKC_Delta_Ys;
/*!< @ASAP_NAME LKC_Delta_Ys @UNIT m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LKC_Delta_Ys) */
float32 LAT_Delta_Psi;
/*!< @ASAP_NAME LAT_Delta_Psi @UNIT rad @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Delta_Psi) */
float32 LKC_Delta_Psi;
/*!< @ASAP_NAME LKC_Delta_Psi @UNIT rad @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LKC_Delta_Psi) */
float32 LAT_Kappa_Command;
/*!< @ASAP_NAME LAT_Kappa_Command @UNIT 1/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Kappa_Command) */
float32 LAT_Kappa_Prime_Command;
/*!< @ASAP_NAME LAT_Kappa_Prime_Command @UNIT 1/m/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Kappa_Prime_Command) */
float32 LAT_Psi;
/*!< @ASAP_NAME LAT_Psi @UNIT rad @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Psi) */
float32 SAT_Saturated_Angle_Command;
/*!< @ASAP_NAME SAT_Saturated_Angle_Command @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAT_Saturated_Angle_Command) */
float32 SAC_Yrc_Angle_Command;
/*!< @ASAP_NAME SAC_Yrc_Angle_Command @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Yrc_Angle_Command) */
unsigned_char_t LAT_Eps_Torque_Request_Flag;
/*!< @ASAP_NAME LAT_Eps_Torque_Request_Flag @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Eps_Torque_Request_Flag) */
float32 LAT_Delta_F_Cmd;
/*!< @ASAP_NAME LAT_Delta_F_Cmd @UNIT deg/s @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Delta_F_Cmd) */
float32 VEH_Delta_F;
/*!< @ASAP_NAME VEH_Delta_F @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Delta_F) */
float32 VEH_Yaw_Rate;
/*!< @ASAP_NAME VEH_Yaw_Rate @UNIT rad/s @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Yaw_Rate) */
float32 VEH_Delta_clm_sens_F;
/*!< @ASAP_NAME VEH_Delta_Clm_Sens_F @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Delta_clm_sens_F) */
float32 VEH_Vehicle_Velocity;
/*!< @ASAP_NAME VEH_Vehicle_Velocity @UNIT m/s @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Vehicle_Velocity) */
float32 VEH_Delta_F_Dot;
/*!< @ASAP_NAME VEH_Delta_F_Dot @UNIT deg/s @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Delta_F_Dot) */
float32 VEH_Steer_Torque;
/*!< @ASAP_NAME VEH_Steer_Torque @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Steer_Torque) */
float32 EPS_Tie_Rod_Load;
/*!< @ASAP_NAME EPS_Tie_Rod_Load @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (EPS_Tie_Rod_Load) */
float32 LAT_Ext_Command;
/*!< @ASAP_NAME LAT_Ext_Command @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Ext_Command) */
float32 EPS_Motor_Torque;
/*!< @ASAP_NAME EPS_Motor_Torque @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (EPS_Motor_Torque) */
signed_int16_t VEH_Brake_Force_Front_Axle;
/*!< @ASAP_NAME VEH_Brake_Force_Front_Axle @UNIT N @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Brake_Force_Front_Axle) */
signed_int16_t EPS_Status;
/*!< @ASAP_NAME EPS_Status @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (EPS_Status) */
signed_int16_t LAT_Dmc_Status;
/*!< @ASAP_NAME LAT_Dmc_Status @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Dmc_Status) */
signed_int16_t LaKMC_activation;
/*!< @ASAP_NAME LaKMC_activation @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 7 @OFFSET 0 @brief comment (LaKMC_activation) */
float32 LaKMC_kappa_cmd;
/*!< @ASAP_NAME LaKMC_kappa_cmd @UNIT 1/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_kappa_cmd) */
float32 LaKMC_kappaP_cmd;
/*!< @ASAP_NAME LaKMC_kappaP_cmd @UNIT 1/ms @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_kappaP_cmd) */
float32 LaKMC_steer_kappa_ctrl_cmd;
/*!< @ASAP_NAME LaKMC_steer_kappa_ctrl_cmd @UNIT 1/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_steer_kappa_ctrl_cmd) */
float32 LaKMC_steer_angle_ctrl_cmd;
/*!< @ASAP_NAME LaKMC_steer_angle_ctrl_cmd @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_steer_angle_ctrl_cmd) */
float32 LaKMC_brake_kappa_ctrl_cmd;
/*!< @ASAP_NAME LaKMC_brake_kappa_ctrl_cmd @UNIT 1/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_brake_kappa_ctrl_cmd) */
unsigned_char_t LaKMC_stiffness;
/*!< @ASAP_NAME LaKMC_stiffness @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_stiffness) */
unsigned_char_t LaKMC_accuracy;
/*!< @ASAP_NAME LaKMC_accuracy @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_accuracy) */
signed_int16_t LaKMC_steering_wheel_vibration;
/*!< @ASAP_NAME LaKMC_steering_wheel_vibration @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_steering_wheel_vibration) */
float32 LaKMC_lateral_error;
/*!< @ASAP_NAME LaKMC_lateral_error @UNIT m @LSB 1.0000000000 @MIN -2 @MAX 2 @OFFSET 0 @brief comment (LaKMC_lateral_error) */
float32 LaKMC_heading_error;
/*!< @ASAP_NAME LaKMC_heading_error @UNIT deg @LSB 1.0000000000 @MIN -20 @MAX 20 @OFFSET 0 @brief comment (LaKMC_heading_error) */
float32 HEC_Psi_Control_Error;
/*!< @ASAP_NAME HEC_Psi_Control_Error @UNIT rad @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (HEC_Psi_Control_Error) */
float32 LDC_Delta_Psi_Dist;
/*!< @ASAP_NAME LDC_Delta_Psi_Dist @UNIT rad @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LDC_Delta_Psi_Dist) */
float32 LDC_Psi_Command;
/*!< @ASAP_NAME LDC_Psi_Command @UNIT rad @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LDC_Psi_Command) */
float32 HEC_Delta_F_Cmd;
/*!< @ASAP_NAME HEC_Delta_F_Cmd @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (HEC_Delta_F_Cmd) */
float32 VEH_Lateral_Accel;
/*!< @ASAP_NAME VEH_Lateral_Accel @UNIT m/s/s @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Lateral_Accel) */
signed_int16_t LAT_Tdf_Eps_Torque_Request_dbg;
/*!< @ASAP_NAME LAT_Tdf_Eps_Torque_Request_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Tdf_Eps_Torque_Request_dbg) */
signed_int16_t LAT_Arb_Eps_Torque_Request_dbg;
/*!< @ASAP_NAME LAT_Arb_Eps_Torque_Request_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Arb_Eps_Torque_Request_dbg) */
signed_int16_t Lat_max_output_torque_dbg;
/*!< @ASAP_NAME Lat_max_output_torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (Lat_max_output_torque_dbg) */
signed_int16_t SAC_Torque_Sat_Out_dbg;
/*!< @ASAP_NAME SAC_Torque_Sat_Out_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Torque_Sat_Out_dbg) */
signed_int16_t SAC_Derating_Torque_dbg;
/*!< @ASAP_NAME SAC_Derating_Torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Derating_Torque_dbg) */
signed_int16_t SAC_Torque_Out_Raw_dbg;
/*!< @ASAP_NAME SAC_Torque_Out_Raw_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Torque_Out_Raw_dbg) */
signed_int16_t SAC_Load_Compensation_Torque_dbg;
/*!< @ASAP_NAME SAC_Load_Compensation_Torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Load_Compensation_Torque_dbg) */
signed_int16_t SAC_Limiter_Out_dbg;
/*!< @ASAP_NAME SAC_Limiter_Out_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Limiter_Out_dbg) */
signed_int16_t SAC_Kd_Part_dbg;
/*!< @ASAP_NAME SAC_Kd_Part_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Kd_Part_dbg) */
signed_int16_t SAC_Active_Damping_Torque_dbg;
/*!< @ASAP_NAME SAC_Active_Damping_Torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Active_Damping_Torque_dbg) */
signed_int16_t SAC_Ki_Part_dbg;
/*!< @ASAP_NAME SAC_Ki_Part_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Ki_Part_dbg) */
signed_int16_t SAC_Kx_Part_dbg;
/*!< @ASAP_NAME SAC_Kx_Part_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Kx_Part_dbg) */
signed_int16_t SAC_Latency_Compensation_Torque_dbg;
/*!< @ASAP_NAME SAC_Latency_Compensation_Torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Latency_Compensation_Torque_dbg) */
signed_int16_t SAC_OScillation_Damp_Torque_dbg;
/*!< @ASAP_NAME SAC_OScillation_Damp_Torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_OScillation_Damp_Torque_dbg) */
signed_int16_t SAC_Friction_Comp_Torque_Out_dbg;
/*!< @ASAP_NAME SAC_Friction_Comp_Torque_Out_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Friction_Comp_Torque_Out_dbg) */
signed_int16_t LAT_Rate_Limit_Control_Out_dbg;
/*!< @ASAP_NAME LAT_Rate_Limit_Control_Out_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Rate_Limit_Control_Out_dbg) */
float32 SAC_Delta_F_Filtered3_;
/*!< @ASAP_NAME SAC_Delta_F_Filtered3_ @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Delta_F_Filtered3_) */
unsigned_char_t SAC_Disable;
/*!< @ASAP_NAME OBS_Disable @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Disable) */
unsigned_int16_t Obs_observer_mode_sig;
/*!< @ASAP_NAME Obs_observer_mode_sig @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (Obs_observer_mode_sig) */
float32 VEH_Vehicle_Speed;
/*!< @ASAP_NAME VEH_Vehicle_Speed @UNIT m/s @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Vehicle_Speed) */
float32 LKA_Eps_Torque_Request_delayed;
/*!< @ASAP_NAME LKA_Eps_Torque_Request_delayed @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LKA_Eps_Torque_Request_delayed) */
float32 SAC_Requested_Damping_Level_delayed;
/*!< @ASAP_NAME SAC_Requested_Damping_Level_delayed @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Requested_Damping_Level_delayed) */
float32 TDF_Sac_Dos_Limit_Scale_delayed;
/*!< @ASAP_NAME TDF_Sac_Dos_Limit_Scale_delayed @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (TDF_Sac_Dos_Limit_Scale_delayed) */
float32 Lat_max_output_torque_sig;
/*!< @ASAP_NAME Lat_max_output_torque_sig @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (Lat_max_output_torque_sig) */
float32 SAC_Rate_Lim_Feed_Fwd_Torque;
/*!< @ASAP_NAME SAC_Rate_Lim_Feed_Fwd_Torque @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Rate_Lim_Feed_Fwd_Torque) */
float32 SAC_Eps_Trq_Load_Est;
/*!< @ASAP_NAME SAC_Eps_Trq_Load_Est @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Eps_Trq_Load_Est) */
unsigned_int16_t SAC_Steer_Velocity_Source;
/*!< @ASAP_NAME SAC_Steer_Velocity_Source @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Steer_Velocity_Source) */
unsigned_char_t SAC_Obs_Var_Delay;
/*!< @ASAP_NAME SAC_Obs_Var_Delay @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Obs_Var_Delay) */
signed_int16_t LaKMC_kappa_cmd_dbg;
/*!< @ASAP_NAME LaKMC_kappa_cmd_dbg @UNIT 1/m @LSB 0.0000200000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_kappa_cmd_dbg) */
signed_int16_t VEH_Delta_F_dbg;
/*!< @ASAP_NAME VEH_Delta_F_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Delta_F_dbg) */
signed_int16_t VEH_Delta_clm_sens_F_dbg;
/*!< @ASAP_NAME VEH_Delta_clm_sens_F_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Delta_clm_sens_F_dbg) */
signed_int16_t VEH_Delta_F_Dot_dbg;
/*!< @ASAP_NAME VEH_Delta_F_Dot_dbg @UNIT - @LSB 0.0437500000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Delta_F_Dot_dbg) */
signed_int16_t VEH_Steer_Torque_dbg;
/*!< @ASAP_NAME VEH_Steer_Torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Steer_Torque_dbg) */
signed_int16_t EPS_Tie_Rod_Load_dbg;
/*!< @ASAP_NAME EPS_Tie_Rod_Load_dbg @UNIT Nm @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (EPS_Tie_Rod_Load_dbg) */
signed_int16_t EPS_Motor_Torque_dbg;
/*!< @ASAP_NAME EPS_Motor_Torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (EPS_Motor_Torque_dbg) */
signed_int16_t EPS_Status_dbg;
/*!< @ASAP_NAME EPS_Status_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (EPS_Status_dbg) */
signed_int16_t LaDMC_Eps_Torque_Request_dbg;
/*!< @ASAP_NAME LaDMC_Eps_Torque_Request_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaDMC_Eps_Torque_Request_dbg) */
signed_int16_t SAT_Saturated_Angle_Command_dbg;
/*!< @ASAP_NAME SAT_Saturated_Angle_Command_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief steer angle target command (SAT_Saturated_Angle_Command_dbg) */
signed_int16_t SAC_Eps_Trq_Load_Est_dbg;
/*!< @ASAP_NAME SAC_Eps_Trq_Load_Est_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief estimated EPS motor load (SAC_Eps_Trq_Load_Est_dbg) */
signed_int16_t LAT_Dmc_Status_dbg;
/*!< @ASAP_NAME LAT_Dmc_Status_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief DMC status (LAT_Dmc_Status_dbg) */
signed_int16_t LDC_Psi_Command_dbg;
/*!< @ASAP_NAME LDC_Psi_Command_dbg @UNIT rad @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief psi command to the heading controller (LDC_Psi_Command_dbg) */
signed_int16_t DYC_Steer_Angle_Feedforward_dbg;
/*!< @ASAP_NAME DYC_Steer_Angle_Feedforward_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief fed forward steer angle command (DYC_Steer_Angle_Feedforward_dbg) */
signed_int16_t LAT_Delta_Ys_dbg;
/*!< @ASAP_NAME LAT_Delta_Ys_dbg @UNIT m @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief lateral deviation error (LAT_Delta_Ys_dbg) */
signed_int16_t LAT_Delta_Psi_dbg;
/*!< @ASAP_NAME LAT_Delta_Psi_dbg @UNIT rad @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief heading angle error (LAT_Delta_Psi_dbg) */
signed_int16_t LAT_Kappa_Command_dbg;
/*!< @ASAP_NAME LAT_Kappa_Command_dbg @UNIT 1/m @LSB 0.0000200000 @MIN -Inf @MAX Inf @OFFSET 0 @brief kappa command (LAT_Kappa_Command_dbg) */
signed_int16_t HEC_Psi_Control_Error_dbg;
/*!< @ASAP_NAME HEC_Psi_Control_Error_dbg @UNIT rad @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief control error of the heading angle controller (HEC_Psi_Control_Error_dbg) */
signed_int16_t HEC_Delta_F_Cmd_dbg;
/*!< @ASAP_NAME HEC_Delta_F_Cmd_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief steer angle command from the heading controller (HEC_Delta_F_Cmd_dbg) */
signed_int16_t LDC_Delta_Psi_Dist_dbg;
/*!< @ASAP_NAME LDC_Delta_Psi_Dist_dbg @UNIT rad @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief lateral disturbance psi command (LDC_Delta_Psi_Dist_dbg) */
signed_int16_t SAC_Yrc_Angle_Command_dbg;
/*!< @ASAP_NAME SAC_Yrc_Angle_Command_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief steer angle command from the active yaw rate controller (SAC_Yrc_Angle_Command_dbg) */
unsigned_int16_t LAT_Kappa_Linz_Omega_dbg;
/*!< @ASAP_NAME LAT_Kappa_Linz_Omega_dbg @UNIT rad/s @LSB 0.0078125000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Omega of the kappa input filter (LAT_Kappa_Linz_Omega_dbg) */
signed_int16_t LAT_Kappa_Filter_Output_dbg;
/*!< @ASAP_NAME LAT_Kappa_Filter_Output_dbg @UNIT 1/m @LSB 0.0000200000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Output of the kappa input filter (LAT_Kappa_Filter_Output_dbg) */
signed_int16_t LAT_Filtered_Delta_F_Offset_dbg;
/*!< @ASAP_NAME LAT_Filtered_Delta_F_Offset_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Filtered angle offset (LAT_Filtered_Delta_F_Offset_dbg) */
signed_int16_t LAT_Oc_Integrator_Input_Kappa_dbg;
/*!< @ASAP_NAME LAT_Oc_Integrator_Input_Kappa_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Kappa based integrator input (LAT_Oc_Integrator_Input_Kappa_dbg) */
signed_int16_t LAT_Oc_Integrator_Input_Raw_dbg;
/*!< @ASAP_NAME LAT_Oc_Integrator_Input_Raw_dbg @UNIT m @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Raw input of the Oc integrator (LAT_Oc_Integrator_Input_Raw_dbg) */
signed_int16_t CAM_Kappa_Cmd_dbg;
/*!< @ASAP_NAME CAM_Kappa_Cmd_dbg @UNIT 1/m @LSB 0.0000200000 @MIN -Inf @MAX Inf @OFFSET 0 @brief curvature signal provided by the camera (CAM_Kappa_Cmd_dbg) */
signed_int16_t DMC_LAT_DEGRADATION;
/*!< @ASAP_NAME DMC_LAT_DEGRADATION @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief  (DMC_LAT_DEGRADATION) */
signed_int16_t DMC_LAT_DEGRADATION_TEMP;
/*!< @ASAP_NAME DMC_LAT_DEGRADATION_TEMP @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief  (DMC_LAT_DEGRADATION_TEMP) */
unsigned_char_t VEH_Stability_Control_Active;
/*!< @ASAP_NAME VEH_Stability_Control_Active @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief ABS, ESC or TCS controller active (VEH_Stability_Control_Active) */
unsigned_char_t VEH_Stability_Control_Active_temp;
/*!< @ASAP_NAME VEH_Stability_Control_Active_temp @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief ABS, ESC or TCS controller active (VEH_Stability_Control_Active_temp) */
signed_int16_t LKC_Lane_Status;
/*!< @ASAP_NAME LKC_Lane_Status @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LKC_Lane_Status) */
signed_int16_t Lat_rate_limited_offset_dbg;
/*!< @ASAP_NAME Lat_rate_limited_offset_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (Lat_rate_limited_offset_dbg) */
unsigned_int16_t SAC_Trq_Derating_Factor_dbg;
/*!< @ASAP_NAME SAC_Trq_Derating_Factor_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Trq_Derating_Factor_dbg) */
unsigned_int16_t TDF_Torque_Derating_Factor_dbg;
unsigned_int16_t TDF_Sac_Dos_Limit_Scale_dbg;
/*!< @ASAP_NAME TDF_Sac_Dos_Limit_Scale_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (TDF_Sac_Dos_Limit_Scale_dbg) */
float32 Cam_kappa_feedfwd;
/*!< @ASAP_NAME Cam_kappa_feedfwd @UNIT 1/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (Cam_kappa_feedfwd) */
float32 LaKMC_kappa_sum_command;
/*!< @ASAP_NAME LaKMC_kappa_sum_command @UNIT 1/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LaKMC_kappa_sum_command) */
signed_int16_t Cam_kappa_qf;
/*!< @ASAP_NAME Cam_kappa_qf @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (Cam_kappa_qf) */
signed_int16_t LKC_Lane_Status_dbg;
/*!< @ASAP_NAME LKC_Lane_Status_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Lane status (LKC_Lane_Status_dbg) */
signed_int16_t LAT_Oc_Kappa_Status_dbg;
/*!< @ASAP_NAME LAT_Oc_Kappa_Status_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Oc_Kappa_Status_dbg) */
signed_int16_t LAT_Oc_Dys_Status_dbg;
/*!< @ASAP_NAME LAT_Oc_Dys_Status_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Oc_Dys_Status_dbg) */
signed_int16_t LAT_Gen_Purpose_dbg;
/*!< @ASAP_NAME LAT_Gen_Purpose_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Gen_Purpose_dbg) */
signed_int16_t VEH_Delta_F_Oc_dbg;
/*!< @ASAP_NAME VEH_Delta_F_Oc_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Offset corrected steer angle (VEH_Delta_F_Oc_dbg) */
signed_int16_t SAT_Req_Angle_Supp_Control_dbg;
/*!< @ASAP_NAME SAT_Req_Angle_Supp_Control_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Contribution of the support torque controller (SAT_Req_Angle_Supp_Control_dbg) */
signed_int16_t MOT_Modulated_Torque_dbg;
/*!< @ASAP_NAME MOT_Modulated_Torque_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Torque output of the vibration unit (MOT_Modulated_Torque_dbg) */
signed_int16_t TDF_Steer_Torque_Sample_dbg;
/*!< @ASAP_NAME TDF_Steer_Torque_Sample_dbg @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief starting torque of the output torque derating (TDF_Steer_Torque_Sample_dbg) */
unsigned_int16_t SAC_Factor_Kp_dbg;
/*!< @ASAP_NAME SAC_Factor_Kp_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Factor_Kp_dbg) */
signed_int16_t SAC_Enhanced_Angle_Cmd_dbg;
/*!< @ASAP_NAME SAC_Enhanced_Angle_Cmd_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Enhanced_Angle_Cmd_dbg) */
signed_int16_t SAC_Fading_Offset_dbg;
/*!< @ASAP_NAME SAC_Fading_Offset_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (SAC_Fading_Offset_dbg) */
signed_int16_t DYC_Boost_Filter_Out_dbg;
/*!< @ASAP_NAME DYC_Boost_Filter_Out_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Contribution of the DYC booster function (DYC_Boost_Filter_Out_dbg) */
unsigned_int16_t SAC_Load_Comp_Factor_Varia_dbg;
/*!< @ASAP_NAME SAC_Load_Comp_Factor_Varia_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Variation of the load compensation factor (SAC_Load_Comp_Factor_Varia_dbg) */
signed_int16_t SAC_Arb_Angle_Cmd_Raw_dbg;
/*!< @ASAP_NAME SAC_Arb_Angle_Cmd_Raw_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Raw angle command (SAC_Arb_Angle_Cmd_Raw_dbg) */
signed_int16_t SAC_Faded_Angle_Command_dbg;
/*!< @ASAP_NAME SAC_Faded_Angle_Command_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Rate limited angle command (SAC_Faded_Angle_Command_dbg) */
signed_int16_t DYC_Boost_Request_dbg;
/*!< @ASAP_NAME DYC_Boost_Request_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief DYC_Boost_Request_dbg (DYC_Boost_Request_dbg) */
signed_int16_t LAT_Debug1_dbg;
/*!< @ASAP_NAME LAT_Debug1_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Debug signal 1 (LAT_Debug1_dbg) */
signed_int16_t LAT_Debug2_dbg;
/*!< @ASAP_NAME LAT_Debug2_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Debug signal 2 (LAT_Debug2_dbg) */
signed_int16_t LAT_Debug3_dbg;
/*!< @ASAP_NAME LAT_Debug3_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Debug signal 3 (LAT_Debug3_dbg) */
signed_int16_t LAT_Debug4_dbg;
/*!< @ASAP_NAME LAT_Debug4_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Debug signal 4 (LAT_Debug4_dbg) */
float32 Cam_heading_error;
signed_int16_t LAT_Debug5_dbg;
signed_int16_t LAT_Debug6_dbg;
signed_int16_t LAT_Debug7_dbg;
signed_int16_t LAT_Debug8_dbg;
/*!< @ASAP_NAME Cam_heading_error @UNIT rad @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (Cam_heading_error) */
float32 VDY_Steer_Angle_Offset;
/*!< @ASAP_NAME VDY_Steer_Angle_Offset @UNIT deg @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VDY_Steer_Angle_Offset) */
float32 Cam_lateral_error;
/*!< @ASAP_NAME Cam_lateral_error @UNIT m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (Cam_lateral_error) */
unsigned_int16_t SAC_Load_Comp_Factor_Straight_dbg;
/*!< @ASAP_NAME SAC_Load_Comp_Factor_Straight_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Load compensation factor request during driving straight forward (SAC_Load_Comp_Factor_Straight_dbg) */
signed_int16_t VEH_Yaw_Rate_Oc_dbg;
/*!< @ASAP_NAME VEH_Yaw_Rate_Oc_dbg @UNIT - @LSB 0.0028600000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Offset correctetd yaw rate (VEH_Yaw_Rate_Oc_dbg) */
float32 VEH_Yaw_Rate_Offset;
/*!< @ASAP_NAME VEH_Yaw_Rate_Offset @UNIT rad/s @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (VEH_Yaw_Rate_Offset) */
signed_int16_t SAC_Steering_Wheel_Angle_Cmd_dbg;
/*!< @ASAP_NAME SAC_Steering_Wheel_Angle_Cmd_dbg @UNIT deg @LSB 0.0437500000 @MIN -Inf @MAX Inf @OFFSET 0 @brief steering wheel angle target command (SAC_Steering_Wheel_Angle_Cmd_dbg) */
signed_int16_t SAC_Filtered_Angle_Command_dbg;
/*!< @ASAP_NAME SAC_Filtered_Angle_Command_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief filtered steer angle target command (SAC_Filtered_Angle_Command_dbg) */
unsigned_int16_t OBS_Discharge_Req_Level_dbg;
/*!< @ASAP_NAME OBS_Discharge_Req_Level_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (OBS_Discharge_Req_Level_dbg) */
unsigned_int16_t OBS_Boost_Request_Level_dbg;
/*!< @ASAP_NAME OBS_Boost_Request_Level_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (OBS_Boost_Request_Level_dbg) */
float32 DYC_Boost_Request;
/*!< @ASAP_NAME DYC_Boost_Request @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Dynamic compensation filter boost request (DYC_Boost_Request) */
float32 DYC_Angle_Per_Kappa;
/*!< @ASAP_NAME DYC_Angle_Per_Kappa @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Dynamic compensation filter angle per curvature command (DYC_Angle_Per_Kappa) */
float32 LKC_Kappa_Command_Arb;
/*!< @ASAP_NAME LKC_Kappa_Command_Arb @UNIT 1/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Arbitrated curvature command (LKC_Kappa_Command_Arb) */
float32 LKC_Kappa_Dot_Command_Arb;
/*!< @ASAP_NAME LKC_Kappa_Dot_Command @UNIT 1/m/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Arbitrated curvature rate command (LKC_Kappa_Dot_Command_Arb) */
float32 LKC_Steer_Kappa_Ctrl_Command;
/*!< @ASAP_NAME LKC_Steer_Kappa_Ctrl_Command @UNIT 1/m @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Curvature command from trajectory controller (LKC_Steer_Kappa_Ctrl_Command) */
unsigned_int32_t SAC_Controller_Mode_Sig;
/*!< @ASAP_NAME SAC_Controller_Mode_Sig @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steering angle controller mode (SAC_Controller_Mode_Sig) */
unsigned_char_t LDP_Active;
/*!< @ASAP_NAME LDP_Active @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Lane departure protection function active (LDP_Active) */
float32 SAC_R_Factor;
/*!< @ASAP_NAME SAC_R_Factor @UNIT  @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Feedback factor of yaw rate controller (SAC_R_Factor) */
signed_int16_t LADMC_STEER_ANGLE_REQ;
/*!< @ASAP_NAME LADMC_STEER_ANGLE_REQ @UNIT deg @LSB 0.0437500000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LADMC_STEER_ANGLE_REQ) */
unsigned_char_t LADMC_ACCURACY_LEVEL_REQUEST;
/*!< @ASAP_NAME LADMC_ACCURACY_LEVEL_REQUEST @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LADMC_ACCURACY_LEVEL_REQUEST) */
signed_int16_t TDF_Idle_Status_dbg;
/*!< @ASAP_NAME TDF_Idle_Status_dbg @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Tdf idle status (TDF_Idle_Status_dbg) */
signed_int16_t SAC_Dyn_Corrected_Angle_Cmd_dbg;
/*!< @ASAP_NAME SAC_Dyn_Corrected_Angle_Cmd_dbg @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Dynamically corrected steer angle command (SAC_Dyn_Corrected_Angle_Cmd_dbg) */
unsigned_char_t DMC_STIFFNESS_LIMIT;
signed_int16_t DMC_STIFFNESS_GRAD;
unsigned_char_t DMC_TORQUE_SCALE_LIMIT;
signed_int16_t DMC_TORQUE_SCALE_GRAD;
signed_int16_t DMC_TORQUE_RAMP_GRAD;
unsigned_char_t DMC_HIGH_ACCURACY_REQUEST;
signed_int16_t SAC_Max_Torque_Scale_dbg;
/*!< @ASAP_NAME SAC_Max_Torque_Scale_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Max torque scaling factor (SAC_Max_Torque_Scale_dbg) */
signed_int16_t VEH_Steer_Torque_Comp_dbg;
signed_int16_t SAC_Accuracy_Request_dbg;
/*!< @ASAP_NAME SAC_Accuracy_Request_dbg @UNIT - @LSB 0.0009765625 @MIN -Inf @MAX Inf @OFFSET 0 @brief Accuracy request */
unsigned_char_t LADMC_DERATING_FACTOR_REQUEST;
unsigned_char_t LAT_Activation_Request_nu;
/*!< @ASAP_NAME LAT_Activation_Request__nu @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LAT_Activation_Request__nu) */
unsigned_char_t LAT_Activation_Request_Qf_nu;
/*!< @ASAP_NAME LAT_Activation_Request_Qf__nu @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LAT_Activation_Request_Qf__nu) */
unsigned_char_t LAT_Force_Shut_Off_Request;
/*!< @ASAP_NAME LAT_Force_Shut_Off_Request @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LAT_Force_Shut_Off_Request) */
signed_int16_t LAT_Steer_Angle_Command_deg;
/*!< @ASAP_NAME LAT_Steer_Angle_Command__deg @UNIT deg @LSB 0.0437500000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Steer_Angle_Command__deg) */
signed_int16_t LAT_Torque_Overlay_Request_nm;
/*!< @ASAP_NAME LAT_Torque_Overlay_Request__nm @UNIT Nm @LSB 0.0010000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Torque_Overlay_Request__nm) */
unsigned_char_t LAT_Stiffness_Request_per;
/*!< @ASAP_NAME LAT_Stiffness_Request__per @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LAT_Stiffness_Request__per) */
unsigned_char_t LAT_Accuracy_Request_per;
/*!< @ASAP_NAME LAT_Accuracy_Request__per @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LAT_Accuracy_Request__per) */
unsigned_char_t LAT_Steering_Wheel_Vibration_nu;
/*!< @ASAP_NAME LAT_Steering_Wheel_Vibration__nu @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LAT_Steering_Wheel_Vibration__nu) */
unsigned_char_t LAT_Lane_Status_nu;
/*!< @ASAP_NAME LAT_Lane_Status__nu @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LAT_Lane_Status__nu) */
unsigned_char_t LAT_Derating_Level_Request_per;
/*!< @ASAP_NAME LAT_Derating_Level_Request__per @UNIT - @LSB 1.0000000000 @MIN 0 @MAX 100 @OFFSET 0 @brief comment (LAT_Derating_Level_Request__per) */
unsigned_char_t LAT_Torque_Ramp_Factor_per;
/*!< @ASAP_NAME LAT_TRQ_RAMP_FACTOR @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief - (LAT_Torque_Ramp_Factor__per) */
unsigned_char_t LAT_Dmc_Status_nu;
signed_int16_t LAT_Eps_Torque_Request_nm;
signed_int16_t SAC_Ayc_Residual_dbg;
unsigned_int16_t TRL_Torque_Gradient_dbg;
signed_int16_t SAC_Delta_F_Cmd_Grad_Param_dbg;
signed_int16_t SAC_Control_Error_Eps_dbg;
signed_int16_t SAC_Yrc_Residual_dbg;
unsigned_char_t DMC_ANGLE_FADING_REQ;
unsigned_char_t DMC_RAMPING_DOWN_REQ;
unsigned_char_t DMC_ANGLE_REQ_MAX_LIMIT_SCALE;
unsigned_char_t DMC_ANGLE_REQ_MAX_GRAD_SCALE;
signed_int16_t SAC_Angle_Command_Raw_dbg;
unsigned_char_t SAC_Soc_Disable;
unsigned_int16_t SAC_Load_Cmp_Fct_Curv_Chg_dbg;
float32 ADP_Dyc_Corr_Factor;
float32 ADP_Dyc_Corr_Factor_Ls;
float32 ADP_Dyc_Corr_Factor_Rs;
unsigned_char_t Turn_And_Error_Side;
float32 CAM_Lateral_Error_Mean;
float32 CAM_Lateral_Error_Delta;
unsigned_int16_t Maximum_Waiting_Counter;
float32 Factor_Increase;
float32 Factor_Decrease;
unsigned_int16_t LTLE_Waiting_Counter;
unsigned_int16_t LTRE_Waiting_Counter;
unsigned_int16_t RTLE_Waiting_Counter;
unsigned_int16_t RTRE_Waiting_Counter;
unsigned_char_t Factor_Corr_Enable_Flag;
float32 ADP_Dyc_Corr_Factor_Left_Vect[20];
float32 ADP_Dyc_Corr_Factor_Right_Vect[20];
float32 Mean_Kappa_Command;
float32 Mean_Vehicle_Velocity;
signed_int16_t DMC_ANGLE_OFF_LOOP0;
unsigned_int16_t DMC_ANGLE_OFF_CALIB_CNT_LOOP0;
unsigned_char_t DMC_ANGLE_OFF_READ_ERROR;
signed_int16_t DMC_ANGLE_OFF;
/*!< @ASAP_NAME DMC_ANGLE_OFF @UNIT deg @LSB 0.0015260000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steer angle offset to be written to the Eeprom (DMC_ANGLE_OFF) */
signed_int16_t DMC_Eps_Integrator_Hold_Req_nu;
unsigned_int16_t DMC_ANGLE_OFF_CALIB_CNT;
/*!< @ASAP_NAME DMC_ANGLE_OFF_CALIB_CNT @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steer angle offset calibration counter to be written to the Eeprom (DMC_ANGLE_OFF_CALIB_CNT) */
signed_int16_t SAC_Derated_Angle_Command_dbg;
unsigned_char_t DMC_ADP_CORR_FACTOR_POS[20];
/*!< @ASAP_NAME DMC_ADP_CORR_FACTOR_POS @UNIT - @LSB 0.0078125000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steering characteristic correction factor left vector (DMC_ADP_CORR_FACTOR_POS) */
unsigned_char_t DMC_ADP_CORR_FACTOR_NEG[20];
/*!< @ASAP_NAME DMC_ADP_CORR_FACTOR_NEG @UNIT - @LSB 0.0078125000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steering characteristic correction factor right vector (DMC_ADP_CORR_FACTOR_NEG) */
unsigned_int16_t DMC_ADP_CORR_COUNTER_POS[20];
/*!< @ASAP_NAME DMC_ADP_CORR_COUNTER_POS @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steering characteristic correction factor counter left vector (DMC_ADP_CORR_COUNTER_POS) */
unsigned_int16_t DMC_ADP_CORR_COUNTER_NEG[20];
/*!< @ASAP_NAME DMC_ADP_CORR_COUNTER_NEG @UNIT - @LSB 1.0000000000 @MIN -Inf @MAX Inf @OFFSET 0 @brief Steering characteristic correction factor counter right vector (DMC_ADP_CORR_COUNTER_NEG) */
unsigned_char_t DMC_ADP_CORR_FACTOR_POS_LOOP0[20];
unsigned_char_t DMC_ADP_CORR_FACTOR_NEG_LOOP0[20];
unsigned_int16_t DMC_ADP_CORR_COUNTER_POS_LOOP0[20];
unsigned_int16_t DMC_ADP_CORR_COUNTER_NEG_LOOP0[20];
unsigned_char_t DMC_ADP_CORR_FACTOR_READ_ERROR;
unsigned_char_t DMC_DERATING_LEVEL_REQ;
signed_int16_t SAT_Angle_Rate_Residual_dbg;
signed_int16_t SAC_Damping_Angle_Command_dbg;
unsigned_int16_t SAC_Ctrl_Err_Memshp_Low_Dyn_dbg;
unsigned_int16_t SAC_Control_Err_Membership_dbg;
signed_int16_t LAT_Kappa_Sum_Command_1pm;
/*!< @ASAP_NAME LAT_Kappa_Sum_Command__1pm @UNIT 1/m @LSB 0.0000200000 @MIN -Inf @MAX Inf @OFFSET 0 @brief comment (LAT_Kappa_Sum_Command__1pm) */
signed_int16_t SAT_Req_Steer_Angle_Max_Ay_dbg;
signed_int16_t LAT_Ay_Control_Limit_Bias_dbg;
signed_int16_t SAC_Delta_F_Sat_Command_dbg;
unsigned_int16_t SAT_Active_Saturation_dbg;
signed_int16_t SAT_Req_Dyn_Steer_Angle_Max_dbg;
signed_int16_t SAC_Angle_Cmd_Yawrate_Fback_dbg;
signed_int16_t LAT_Oc_Delta_Ys_Filtered_dbg;
unsigned_char_t DMC_DRIVING_MODE;
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
float32 VDY_Bank_Angle;
/* Block signals (auto storage) */
BlockIO_DMC_Soc_T DMC_Soc_B;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_DMC_Soc_T DMC_Soc_U;

/* Model step function */
void DMC_Soc_step(void)
{
  /* local block i/o variables */
//  pressure_tmc_t rtb_eg00;
//  pressure_tmc_grad_t rtb_osxw;
  real32_T rtb_cs2o;
  real32_T rtb_dtct;
  real32_T rtb_aesk;
  real32_T rtb_mlzl;
  real32_T rtb_e1o1;
  real32_T rtb_feic;
  real32_T rtb_jrxk;
  real32_T rtb_kvoq[20];
  real32_T rtb_lgvf[20];
  real32_T rtb_o4ct;
  real32_T rtb_lnqj;
  real32_T rtb_kmsp;
  real32_T rtb_it2q;
  real32_T rtb_g5xq;
  real32_T rtb_eoge;
  real32_T rtb_adpx;
  real32_T rtb_hozt;
  real32_T rtb_ofn4;
  real32_T rtb_pwdk;
  real32_T rtb_g3ff;
  real32_T rtb_mokw;
  real32_T rtb_p2rb;
  real32_T rtb_nvod;
  real32_T rtb_bekh;
  real32_T rtb_mg54;
  real32_T rtb_flkk;
  int32_T rtb_dgpl;
  int16_T rtb_ltsw;
  int16_T rtb_ilbj;
  int16_T rtb_be5w;
  int16_T rtb_fgdz;
  int16_T rtb_g1it;
  uint8_T rtb_areh;
  boolean_T rtb_lzrb;
  boolean_T rtb_onan;
  boolean_T rtb_fcuq;
  boolean_T rtb_ew3r;
  real32_T rtb_;
  real32_T rtb_co3c;
  uint16_T rtb_bwtp;
  uint8_T tmp_;

  /* S-Function (sfix_bitop): '<S12>/Bitwise Operator' incorporates:
   *  Inport: '<Root>/SSI_R_DMC_LAT_ACTVN_MOD'
   */
  LaKMC_activation = (int16_T)(Ssi_r_dmc_lat_actvn_mod() & 255);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/SSI_R_DMC_CRVT_FEED_FWD'
   */
  LaKMC_kappa_cmd = ((real32_T)Ssi_r_dmc_crvt_feed_fwd()) * 2.0E-5F;

  /* DataTypeConversion: '<S12>/Data Type Conversion8' incorporates:
   *  Inport: '<Root>/SSI_R_DMC_CRVT_CHG_RATE'
   */
  LaKMC_kappaP_cmd = ((real32_T)Ssi_r_dmc_crvt_chg_rate()) * 5.0E-5F;

  /* DataTypeConversion: '<S12>/Data Type Conversion10' incorporates:
   *  Inport: '<Root>/SSI_R_DMC_HDNG_AG_ERR'
   */
  LaKMC_heading_error = ((real32_T)Ssi_r_dmc_hdng_ag_err()) * 3.05175781E-5F;

  /* DataTypeConversion: '<S12>/Data Type Conversion9' incorporates:
   *  Inport: '<Root>/SSI_R_DMC_LAT_ERR'
   */
  LaKMC_lateral_error = ((real32_T)Ssi_r_dmc_lat_err()) * 0.0009765625F;

  /* DataTypeConversion: '<S12>/Data Type Conversion7' incorporates:
   *  Inport: '<Root>/SSI_R_DMC_CRVT_STEER_ACTR'
   */
  LaKMC_steer_kappa_ctrl_cmd = ((real32_T)Ssi_r_dmc_crvt_steer_actr()) * 2.0E-5F;

  /* DataTypeConversion: '<S12>/Data Type Conversion6' incorporates:
   *  Inport: '<Root>/SSI_R_DMC_STEER_AG_REQ'
   */
  LaKMC_steer_angle_ctrl_cmd = ((real32_T)Ssi_r_dmc_steer_ag_req()) * 0.001526F;

  /* DataTypeConversion: '<S12>/Data Type Conversion11' incorporates:
   *  Inport: '<Root>/SSI_R_DMC_STEER_WHL_VIBR'
   */
  LaKMC_steering_wheel_vibration = Ssi_r_dmc_steer_whl_vibr();

  /* DataTypeConversion: '<S14>/Data Type Conversion6' incorporates:
   *  Constant: '<S14>/Constant2'
   */
  LAT_Ext_Command = 0.0F;

  /* DataTypeConversion: '<S8>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/BUS_EPS_TOR_BAR_TORQUE'
   */
  VEH_Steer_Torque = ((real32_T)Get_bus_eps_tor_bar_torque()) * 0.001F;

  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S8>/Veh_one_by_column_stiffness'
   */
  rtb_co3c = (((real32_T)Veh_one_by_column_stiffness) * 0.0009765625F) *
    VEH_Steer_Torque;

  /* Sum: '<S8>/Add1' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion15'
   *  Inport: '<Root>/DMC_FILTERED_STEER_ANGLE'
   */
  VEH_Delta_F = (((real32_T)DMC_FILTERED_STEER_ANGLE) * 0.001526F) - rtb_co3c;

  /* Sum: '<S8>/Add4' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion16'
   *  Inport: '<Root>/SSI_R_EPS_STEER_AG'
   */
  rtb_co3c = (((real32_T)Ssi_r_eps_steer_ag()) * 0.0427272F) - rtb_co3c;

  /* Lookup_n-D: '<S8>/Steer_gain' incorporates:
   *  Abs: '<S8>/Abs'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   */
  rtb_ = look1_is16lfts16n10DfIf_binlcr((int16_T)((real32_T)floor((real_T)
    ((real32_T)(((real32_T)fabs((real_T)rtb_co3c)) / 0.04375F)))),
    (&(Veh_steer_gear_ratio_x_tab[0])), (&(Veh_steer_gear_ratio_y_tab[0])), 5U);

  /* MinMax: '<S8>/MinMax' */
  if (rtb_ >= 0.01F) {
    rtb_cs2o = rtb_;
  } else {
    rtb_cs2o = 0.01F;
  }

  /* End of MinMax: '<S8>/MinMax' */

  /* Abs: '<S8>/Abs1' incorporates:
   *  Inport: '<Root>/UNCALIBRATED_SWA_FIL'
   */
  if (UNCALIBRATED_SWA_FIL < ((int16_T)0)) {
    DMC_LAT_DEGRADATION = (int16_T)(-UNCALIBRATED_SWA_FIL);
  } else {
    DMC_LAT_DEGRADATION = UNCALIBRATED_SWA_FIL;
  }

  /* End of Abs: '<S8>/Abs1' */

  /* Lookup_n-D: '<S8>/Steer_gain!' */
  rtb_ = look1_is16lftf_binlc(DMC_LAT_DEGRADATION,
    (&(Veh_steer_gear_ratio_x_tab[0])), DMC_Soc_ConstP.Steer_gain_tableData, 5U);

  /* MinMax: '<S8>/MinMax1' */
  if (rtb_ >= 0.01F) {
  } else {
    rtb_ = 0.01F;
  }

  /* Product: '<S8>/Divide3' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion19'
   *  Inport: '<Root>/UNCALIBRATED_SWA_FIL'
   *  MinMax: '<S8>/MinMax1'
   */
  VEH_Delta_clm_sens_F = (((real32_T)UNCALIBRATED_SWA_FIL) * 0.04375F) / rtb_;

  /* MinMax: '<S8>/MinMax2' incorporates:
   *  Constant: '<S8>/Veh_steer_angle_source'
   */
  if (((int32_T)Veh_steer_angle_source) <= ((int32_T)3)) {
    tmp_ = Veh_steer_angle_source;
  } else {
    tmp_ = 3U;
  }

  /* End of MinMax: '<S8>/MinMax2' */

  /* MultiPortSwitch: '<S8>/Multiport Switch1' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion48'
   *  Inport: '<Root>/DMC_ROAD_WHEEL_ANGLE'
   *  Product: '<S8>/Divide2'
   */
  switch (tmp_) {
   case 0:
    break;

   case 1:
    VEH_Delta_F = rtb_co3c / rtb_cs2o;
    break;

   case 2:
    VEH_Delta_F = VEH_Delta_clm_sens_F;
    break;

   default:
    VEH_Delta_F = ((real32_T)DMC_ROAD_WHEEL_ANGLE) * 0.0025F;
    break;
  }

  /* End of MultiPortSwitch: '<S8>/Multiport Switch1' */

  /* MultiPortSwitch: '<S8>/Multiport Switch2' incorporates:
   *  Constant: '<S8>/Veh_steer_angle_rate_source1'
   *  DataTypeConversion: '<S8>/Data Type Conversion13'
   *  DataTypeConversion: '<S8>/Data Type Conversion17'
   *  Inport: '<Root>/DMC_FILTERED_STEER_ANGLE_RATE'
   *  Inport: '<Root>/SSI_R_EPS_STEER_AG_RATE'
   *  Product: '<S8>/Divide1'
   */
  if (((int32_T)Veh_steer_angle_rate_source) == ((int32_T)0)) {
    rtb_dtct = ((real32_T)DMC_FILTERED_STEER_ANGLE_RATE) * 0.04375F;
  } else {
    rtb_dtct = (((real32_T)Ssi_r_eps_steer_ag_rate()) * 0.2442F) / rtb_cs2o;
  }

  /* End of MultiPortSwitch: '<S8>/Multiport Switch2' */

  /* Gain: '<S15>/Gain1' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion5'
   *  Inport: '<Root>/DMC_FILTERED_YAW_RATE'
   */
  VEH_Yaw_Rate = 0.0174532924F * (((real32_T)DMC_FILTERED_YAW_RATE) * 0.00286F);

  /* Gain: '<S14>/km//h to m//s' incorporates:
   *  Inport: '<Root>/EST_REFERENCE_VELOCITY'
   */
  VEH_Vehicle_Velocity = 0.277771F * (((real32_T)EST_REFERENCE_VELOCITY) * 0.01F);

  /* Gain: '<S16>/Gain1' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion16'
   *  Inport: '<Root>/DMC_YAW_RATE_OFFSET'
   */
  VEH_Yaw_Rate_Offset = 0.0174532924F * (((real32_T)DMC_YAW_RATE_OFFSET) *
    0.00286F);

  /* DataTypeConversion: '<S14>/Data Type Conversion7' incorporates:
   *  Constant: '<S14>/Constant1'
   */
  rtb_ltsw = (int16_T)0;

  /* DataTypeConversion: '<S14>/Data Type Conversion9' incorporates:
   *  Inport: '<Root>/DMC_FILTERED_LATERAL_ACC_COG'
   */
  VEH_Lateral_Accel = ((real32_T)DMC_FILTERED_LATERAL_ACC_COG) * 0.0981F;

  /* Logic: '<S19>/Logical Operator (2)' incorporates:
   *  Inport: '<Root>/DMC_FILTERED_LATERAL_ACC_COG_QF'
   *  Inport: '<Root>/DMC_FILTERED_STEER_ANGLE_QF'
   *  Inport: '<Root>/DMC_FILTERED_STEER_ANGLE_RATE_QF'
   *  Inport: '<Root>/DMC_FILTERED_YAW_RATE_QF'
   *  Inport: '<Root>/FINAL_FUNCTION_DISABLE_ABS'
   *  Inport: '<Root>/FINAL_FUNCTION_DISABLE_AYC'
   *  Inport: '<Root>/FINAL_FUNCTION_DISABLE_BTC'
   *  Inport: '<Root>/FINAL_FUNCTION_DISABLE_MTC'
   *  Logic: '<S19>/Logical Operator (1)'
   */
  MTO_HALF_SYSTEM_STS = (((((!((((DMC_FILTERED_YAW_RATE_QF != 0) &&
    (DMC_FILTERED_STEER_ANGLE_QF != 0)) && (DMC_FILTERED_STEER_ANGLE_RATE_QF !=
    0)) && (DMC_FILTERED_LATERAL_ACC_COG_QF != 0))) ||
    (Get_fs_final_func_dis_abs())) || (Get_fs_final_func_dis_ayc())) ||
    (Get_fs_final_func_dis_btc())) || (Get_fs_final_func_dis_mtc()));

  /* Switch: '<S18>/Switch (1)' incorporates:
   *  Constant: '<S18>/enabled'
   *  Constant: '<S18>/temporary_disabled'
   *  Inport: '<Root>/AYC_WARNING_LAMP'
   *  Inport: '<Root>/EPS_TEMP_DEACTIVATION_LDW'
   *  Inport: '<Root>/FUNCTION_DISABLE_ABS'
   *  Inport: '<Root>/FUNCTION_DISABLE_AYC'
   *  Inport: '<Root>/FUNCTION_DISABLE_BTC'
   *  Inport: '<Root>/FUNCTION_DISABLE_MTC'
   *  Inport: '<Root>/SSI_R_ISOK_DMC_CRVT_CHG_RATE'
   *  Inport: '<Root>/SSI_R_ISOK_DMC_CRVT_DFTL_BRKG'
   *  Inport: '<Root>/SSI_R_ISOK_DMC_CRVT_FEED_FWD'
   *  Inport: '<Root>/SSI_R_ISOK_DMC_CRVT_STEER_ACTR'
   *  Inport: '<Root>/SSI_R_ISOK_DMC_HDNG_AG_ERR'
   *  Inport: '<Root>/SSI_R_ISOK_DMC_LAT_ACTVN_MOD'
   *  Inport: '<Root>/SSI_R_ISOK_DMC_LAT_ERR'
   *  Inport: '<Root>/SSI_R_ISOK_DMC_OCCRCY_REQ'
   *  Inport: '<Root>/SSI_R_ISOK_DMC_STEER_AG_REQ'
   *  Inport: '<Root>/SSI_R_ISOK_DMC_STEER_WHL_VIBR'
   *  Inport: '<Root>/SSI_R_ISOK_DMC_STFN_REQ'
   *  Logic: '<S21>/Logical Operator (1)'
   *  Logic: '<S21>/Logical Operator (2)'
   *  Logic: '<S21>/Logical Operator (3)'
   */
  if (((((((int32_T)EPS_TEMP_DEACTIVATION_LDW) || ((int32_T)
           Get_fs_function_disable_abs())) || (((int32_T)Get_fs_ayc_warning_lamp
           ()) && ((int32_T)Get_fs_function_disable_ayc()))) || ((int32_T)
         Get_fs_function_disable_btc())) || ((int32_T)
        Get_fs_function_disable_mtc())) || (!((((((((((((int32_T)
      Ssi_r_isok_dmc_lat_actvn_mod()) && ((int32_T)Ssi_r_isok_dmc_crvt_feed_fwd()))
    && ((int32_T)Ssi_r_isok_dmc_crvt_chg_rate())) && ((int32_T)
                Ssi_r_isok_dmc_crvt_dftl_brkg())) && ((int32_T)
               Ssi_r_isok_dmc_crvt_steer_actr())) && ((int32_T)
              Ssi_r_isok_dmc_steer_ag_req())) && ((int32_T)
             Ssi_r_isok_dmc_stfn_req())) && ((int32_T)Ssi_r_isok_dmc_occrcy_req()))
          && ((int32_T)Ssi_r_isok_dmc_lat_err())) && ((int32_T)
          Ssi_r_isok_dmc_hdng_ag_err())) && ((int32_T)
         Ssi_r_isok_dmc_steer_whl_vibr())))) {
    DMC_LAT_DEGRADATION = 3;
  } else {
    DMC_LAT_DEGRADATION = 0;
  }

  /* End of Switch: '<S18>/Switch (1)' */

  /* Switch: '<S18>/Switch (2)' incorporates:
   *  Constant: '<S18>/permanent_disabled_ramp_down'
   */
  if ((int32_T)MTO_HALF_SYSTEM_STS) {
    DMC_LAT_DEGRADATION = 1;
  }

  /* End of Switch: '<S18>/Switch (2)' */

  /* Switch: '<S18>/Switch (3)' incorporates:
   *  Constant: '<S18>/permanent_disabled_shut_off'
   *  Constant: '<S23>/Constant'
   *  Inport: '<Root>/BUS_EPS_TOR_BAR_TORQUE_QF'
   *  Inport: '<Root>/EpsSteerAngleAuthority'
   *  Inport: '<Root>/HALFTorqueOverlayFault'
   *  Logic: '<S20>/Logical Operator'
   *  RelationalOperator: '<S23>/Compare'
   */
  if ((((int32_T)HALFTorqueOverlayFault) || ((int32_T)
        Get_bus_eps_tor_bar_torque_qf())) || (((int32_T)EpsSteerAngleAuthority)
       != ((int32_T)100))) {
    DMC_LAT_DEGRADATION = 2;
  }

  /* End of Switch: '<S18>/Switch (3)' */

  /* Logic: '<S14>/Stability_function_active_check' incorporates:
   *  Inport: '<Root>/ABS_IN_CYCLE'
   *  Inport: '<Root>/AYC_IN_CYCLE'
   *  Inport: '<Root>/BTCS_IN_CYCLE'
   *  Inport: '<Root>/TCS_ENGINE_CONTROL_ACTIVE'
   */
  VEH_Stability_Control_Active = ((((Get_abs_cycle()) || (Get_ayc_in_cycle())) ||
                                   (Get_tcs_engine_control_active())) ||
    (Get_btcs_active()));

  /* MinMax: '<S12>/MinMax' */
  if (rtb_cs2o >= 0.01F) {
    rtb_ = rtb_cs2o;
  } else {
    rtb_ = 0.01F;
  }

  /* Product: '<S12>/Divide2' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion16'
   *  Gain: '<S26>/Gain'
   *  Inport: '<Root>/DMC_STEER_ANGLE_OFFSET'
   *  MinMax: '<S12>/MinMax'
   */
  VDY_Steer_Angle_Offset = (57.2957802F * (((real32_T)DMC_STEER_ANGLE_OFFSET) *
    0.001F)) / rtb_;

  /* Gain: '<S3>/Gain' incorporates:
   *  Inport: '<Root>/DMC_STEER_ANGLE_OFFSET_STATE'
   */
  rtb_ilbj = DMC_STEER_ANGLE_OFFSET_STATE;

  /* DataTypeConversion: '<S12>/Data Type Conversion24' incorporates:
   *  Inport: '<Root>/SSI_R_DMC_CRVT_SUM_CMD'
   */
  LaKMC_kappa_sum_command = ((real32_T)Ssi_r_dmc_crvt_sum_cmd()) * 2.0E-5F;

  /* DataTypeConversion: '<S12>/Data Type Conversion25' incorporates:
   *  Inport: '<Root>/SSI_R_DMC_CRVT_CMD_RATE'
   */
  rtb_aesk = ((real32_T)Ssi_r_dmc_crvt_cmd_rate()) * 5.0E-5F;

  /* DataTypeConversion: '<S12>/Data Type Conversion15' incorporates:
   *  Inport: '<Root>/SSI_R_LANE_STATUS'
   */
  LKC_Lane_Status = Ssi_r_lane_status();

  /* DataTypeConversion: '<S12>/Data Type Conversion18' incorporates:
   *  Inport: '<Root>/DMC_CAM_CRVT_FEED_FWD'
   */
  Cam_kappa_feedfwd = ((real32_T)DMC_CAM_CRVT_FEED_FWD) * 2.0E-5F;

  /* DataTypeConversion: '<S12>/Data Type Conversion22' incorporates:
   *  Inport: '<Root>/DMC_CAM_CRVT_FEED_FWD_QF'
   */
  Cam_kappa_qf = DMC_CAM_CRVT_FEED_FWD_QF;

  /* DataTypeConversion: '<S12>/Data Type Conversion17' incorporates:
   *  Inport: '<Root>/DMC_CAM_LAT_ERR'
   */
  Cam_lateral_error = ((real32_T)DMC_CAM_LAT_ERR) * 0.0009765625F;

  /* DataTypeConversion: '<S12>/Data Type Conversion19' incorporates:
   *  Inport: '<Root>/DMC_CAM_HDNG_AG_ERR'
   */
  Cam_heading_error = ((real32_T)DMC_CAM_HDNG_AG_ERR) * 3.05175781E-5F;

  /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/LAT_Eps_Torque_Request__nm'
   */
  rtb_mlzl = ((real32_T)LAT_Eps_Torque_Request_nm) * 0.001F;

  /* DataTypeConversion: '<S12>/Data Type Conversion12' incorporates:
   *  Inport: '<Root>/DMC_ANGLE_REQ_MAX_LIMIT_SCALE'
   */
  rtb_e1o1 = (real32_T)DMC_ANGLE_REQ_MAX_LIMIT_SCALE;

  /* DataTypeConversion: '<S12>/Data Type Conversion13' incorporates:
   *  Inport: '<Root>/DMC_ANGLE_REQ_MAX_GRAD_SCALE'
   */
  rtb_feic = (real32_T)DMC_ANGLE_REQ_MAX_GRAD_SCALE;

  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/DMC_ANGLE_OFF_LOOP0'
   */
  rtb_jrxk = ((real32_T)DMC_ANGLE_OFF_LOOP0) * 0.001526F;

  /* DataTypeConversion: '<S8>/Data Type Conversion11' incorporates:
   *  Inport: '<Root>/BUS_EPS_MOTOR_TRQ'
   */
  EPS_Motor_Torque = ((real32_T)Get_bus_eps_motor_trq()) * 0.001F;

  /* DataTypeConversion: '<S9>/Data Type Conversion5' incorporates:
   *  Inport: '<Root>/DMC_ADP_CORR_FACTOR_POS_LOOP0'
   */
  rtb_kvoq[(int8_T)0] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[0]) *
    0.0078125F;
  rtb_kvoq[(int8_T)1] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[1]) *
    0.0078125F;
  rtb_kvoq[(int8_T)2] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[2]) *
    0.0078125F;
  rtb_kvoq[(int8_T)3] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[3]) *
    0.0078125F;
  rtb_kvoq[(int8_T)4] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[4]) *
    0.0078125F;
  rtb_kvoq[(int8_T)5] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[5]) *
    0.0078125F;
  rtb_kvoq[(int8_T)6] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[6]) *
    0.0078125F;
  rtb_kvoq[(int8_T)7] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[7]) *
    0.0078125F;
  rtb_kvoq[(int8_T)8] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[8]) *
    0.0078125F;
  rtb_kvoq[(int8_T)9] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[9]) *
    0.0078125F;
  rtb_kvoq[(int8_T)10] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[10]) *
    0.0078125F;
  rtb_kvoq[(int8_T)11] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[11]) *
    0.0078125F;
  rtb_kvoq[(int8_T)12] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[12]) *
    0.0078125F;
  rtb_kvoq[(int8_T)13] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[13]) *
    0.0078125F;
  rtb_kvoq[(int8_T)14] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[14]) *
    0.0078125F;
  rtb_kvoq[(int8_T)15] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[15]) *
    0.0078125F;
  rtb_kvoq[(int8_T)16] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[16]) *
    0.0078125F;
  rtb_kvoq[(int8_T)17] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[17]) *
    0.0078125F;
  rtb_kvoq[(int8_T)18] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[18]) *
    0.0078125F;
  rtb_kvoq[(int8_T)19] = ((real32_T)DMC_ADP_CORR_FACTOR_POS_LOOP0[19]) *
    0.0078125F;

  /* DataTypeConversion: '<S9>/Data Type Conversion6' incorporates:
   *  Inport: '<Root>/DMC_ADP_CORR_FACTOR_NEG_LOOP0'
   */
  rtb_lgvf[(int8_T)0] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[0]) *
    0.0078125F;
  rtb_lgvf[(int8_T)1] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[1]) *
    0.0078125F;
  rtb_lgvf[(int8_T)2] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[2]) *
    0.0078125F;
  rtb_lgvf[(int8_T)3] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[3]) *
    0.0078125F;
  rtb_lgvf[(int8_T)4] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[4]) *
    0.0078125F;
  rtb_lgvf[(int8_T)5] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[5]) *
    0.0078125F;
  rtb_lgvf[(int8_T)6] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[6]) *
    0.0078125F;
  rtb_lgvf[(int8_T)7] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[7]) *
    0.0078125F;
  rtb_lgvf[(int8_T)8] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[8]) *
    0.0078125F;
  rtb_lgvf[(int8_T)9] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[9]) *
    0.0078125F;
  rtb_lgvf[(int8_T)10] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[10]) *
    0.0078125F;
  rtb_lgvf[(int8_T)11] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[11]) *
    0.0078125F;
  rtb_lgvf[(int8_T)12] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[12]) *
    0.0078125F;
  rtb_lgvf[(int8_T)13] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[13]) *
    0.0078125F;
  rtb_lgvf[(int8_T)14] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[14]) *
    0.0078125F;
  rtb_lgvf[(int8_T)15] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[15]) *
    0.0078125F;
  rtb_lgvf[(int8_T)16] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[16]) *
    0.0078125F;
  rtb_lgvf[(int8_T)17] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[17]) *
    0.0078125F;
  rtb_lgvf[(int8_T)18] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[18]) *
    0.0078125F;
  rtb_lgvf[(int8_T)19] = ((real32_T)DMC_ADP_CORR_FACTOR_NEG_LOOP0[19]) *
    0.0078125F;

  /* DataTypeConversion: '<S12>/Data Type Conversion14' incorporates:
   *  Inport: '<Root>/DMC_DERATING_LEVEL_REQ'
   */
  rtb_o4ct = (real32_T)DMC_DERATING_LEVEL_REQ;

  /* DataTypeConversion: '<S12>/Data Type Conversion36' incorporates:
   *  Inport: '<Root>/DMC_DRIVING_MODE'
   */
  rtb_lnqj = (real32_T)DMC_DRIVING_MODE;

  /* Gain: '<S27>/Gain' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion38'
   *  Inport: '<Root>/DMC_BANK_ANGLE'
   */
  VDY_Bank_Angle = 57.2957802F * (((real32_T)DMC_BANK_ANGLE) * 3.05175781E-5F);

  /* DataTypeConversion: '<S12>/Data Type Conversion40' incorporates:
   *  Inport: '<Root>/SSI_R_DMC_LAT_ACTVN_MOD'
   */
  rtb_bwtp = (uint16_T)Ssi_r_dmc_lat_actvn_mod();

  /* ArithShift: '<S12>/Shift Arithmetic' */
  LCF_Operation_Mode = (uint16_T)(((uint32_T)rtb_bwtp) >> 8);

  /* DataTypeConversion: '<S12>/Data Type Conversion41' incorporates:
   *  Inport: '<Root>/EMO_PITCH_ANGLE'
   */
  rtb_kmsp = ((real32_T)EMO_PITCH_ANGLE) * 3.05175781E-5F;

  /* DataTypeConversion: '<S12>/Data Type Conversion46' incorporates:
   *  DataTypeConversion: '<S24>/Extract Desired Bits'
   */
  rtb_lzrb = (boolean_T)((int32_T)((((int32_T)((uint32_T)(((uint32_T)rtb_bwtp) >>
                              ((int8_T)10)))) & ((int32_T)1)) != ((int32_T)0)));

  /* DataTypeConversion: '<S12>/Data Type Conversion47' incorporates:
   *  DataTypeConversion: '<S25>/Extract Desired Bits'
   */
  rtb_onan = (boolean_T)((int32_T)((((int32_T)((uint32_T)(((uint32_T)rtb_bwtp) >>
                              ((int8_T)11)))) & ((int32_T)1)) != ((int32_T)0)));

  /* ModelReference: '<S3>/LAT_Soc_Lateral_Controller' */
  DMC_Soc_Lat((&(LaKMC_activation)), (&(LaKMC_kappa_cmd)), (&(LaKMC_kappaP_cmd)),
              (&(LaKMC_heading_error)), (&(LaKMC_lateral_error)),
              (&(LaKMC_steer_kappa_ctrl_cmd)), (&(LaKMC_steer_angle_ctrl_cmd)),
              (&(LaKMC_steering_wheel_vibration)), (&(LAT_Ext_Command)),
              (&(VEH_Delta_F)), (&(VEH_Delta_clm_sens_F)), &rtb_dtct,
              (&(VEH_Yaw_Rate)), (&(VEH_Vehicle_Velocity)),
              (&(VEH_Yaw_Rate_Offset)), (&(DMC_YAW_RATE_OFFSET_STATE)),
              &rtb_ltsw, (&(VEH_Steer_Torque)), (&(VEH_Lateral_Accel)),
              &rtb_cs2o, (&(DMC_LAT_DEGRADATION)),
              (&(HALF_TORQUE_OVERLAY_ACTIVATED)),
              (&(VEH_Stability_Control_Active)), (&(VDY_Steer_Angle_Offset)),
              &rtb_ilbj, (&(LaKMC_kappa_sum_command)), &rtb_aesk,
              (&(LKC_Lane_Status)), (&(Cam_kappa_feedfwd)), (&(Cam_kappa_qf)), (
    &(Cam_lateral_error)), (&(DMC_CAM_LAT_ERR_QF)), (&(Cam_heading_error)),
              (&(DMC_CAM_HDNG_AG_ERR_QF)), (&(DMC_FORCE_SHUT_OFF_REQUEST)),
              (&(DMC_STIFFNESS_LIMIT)), (&(DMC_STIFFNESS_GRAD)),
              (&(DMC_TORQUE_SCALE_LIMIT)), (&(DMC_TORQUE_SCALE_GRAD)),
              (&(DMC_TORQUE_RAMP_GRAD)), (&(DMC_HIGH_ACCURACY_REQUEST)),
              &rtb_mlzl, (&(DMC_ANGLE_FADING_REQ)), (&(DMC_RAMPING_DOWN_REQ)),
              &rtb_e1o1, &rtb_feic, &rtb_jrxk, (&(DMC_ANGLE_OFF_CALIB_CNT_LOOP0)),
              (&(DMC_ANGLE_OFF_READ_ERROR)), (&(EPS_Motor_Torque)), &rtb_kvoq[0],
              &rtb_lgvf[0], (&(DMC_ADP_CORR_COUNTER_POS_LOOP0[0])),
              (&(DMC_ADP_CORR_COUNTER_NEG_LOOP0[0])),
              (&(DMC_ADP_CORR_FACTOR_READ_ERROR)), &rtb_o4ct,
              &DMC_Soc_ConstP.Constant_Value_exs4, (&(VDY_Bank_Angle)),
              (&(LCF_Operation_Mode)), (&(DMC_GPIO)), &rtb_kmsp,
              (&(DMC_SHUT_OFF_ON_ERROR)), &rtb_lzrb, &rtb_onan,
              (&(LADMC_EPS_INTERFACE_ACTIVE_REQ)), (&(DMC_LAT_STATUS)),
              &rtb_it2q, &rtb_g5xq, &rtb_eoge, &rtb_adpx,
              (&(LAT_Stiffness_Request_per)), &rtb_hozt,
              (&(LAT_Accuracy_Request_per)), (&(LAT_Derating_Level_Request_per)),
              (&(LAT_Lane_Status_nu)), (&(LAT_Force_Shut_Off_Request)),
              &rtb_ofn4, (&(LAT_Activation_Request_Qf_nu)),
              (&(LAT_Activation_Request_nu)), (&(LAT_Torque_Ramp_Factor_per)),
              &rtb_pwdk, &rtb_fcuq, &rtb_ew3r, (&(DMC_ANGLE_OFF_CALIB_CNT)),
              &rtb_g3ff, (&(DMC_ADP_CORR_COUNTER_POS[0])),
              (&(DMC_ADP_CORR_COUNTER_NEG[0])), &rtb_mokw, &rtb_p2rb,
              (&(DMC_Eps_Integrator_Hold_Req_nu)), (&(DMC_EPS_STATUS)),
              &rtb_nvod, &rtb_bekh, &rtb_areh);

  /* ModelReference: '<S5>/LON_Longitudinal_Controller' */
  DMC_Long(&DMC_Soc_ConstP.Constant1_Value, &DMC_Soc_ConstP.pooled6,
           &DMC_Soc_ConstP.pooled6, &DMC_Soc_ConstP.Constant4_Value[0],
           &rtb_mg54, &rtb_flkk);

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  DMC_LONG_ENG_TRQ_REQ = (int16_T)((real32_T)floor(rtb_flkk));

  /* DataTypeConversion: '<S6>/Data Type Conversion1' */
  DMC_LONG_BRK_TRQ_REQ = (int16_T)((real32_T)floor(rtb_mg54));

  /* DataTypeConversion: '<S4>/Data Type Conversion21' */
  LAT_Steer_Angle_Command_deg = (int16_T)rt_roundf(rtb_hozt / 0.024416F);

  /* DataTypeConversion: '<S3>/Data Type Conversion3' */
  LAT_Steering_Wheel_Vibration_nu = (uint8_T)LaKMC_steering_wheel_vibration;

  /* DataTypeConversion: '<S4>/Data Type Conversion2' */
  LAT_Torque_Overlay_Request_nm = (int16_T)rt_roundf(rtb_ofn4 / 0.001F);

  /* DataTypeConversion: '<S4>/Data Type Conversion5' */
  DMC_ANGLE_OFF = (int16_T)rt_roundf(rtb_g3ff / 0.001526F);

  /* DataTypeConversion: '<S4>/Data Type Conversion14' */
  DMC_ADP_CORR_FACTOR_POS[0] = (uint8_T)rt_roundf(ADP_Dyc_Corr_Factor_Left_Vect
    [0] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[1] = (uint8_T)rt_roundf(ADP_Dyc_Corr_Factor_Left_Vect
    [1] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[2] = (uint8_T)rt_roundf(ADP_Dyc_Corr_Factor_Left_Vect
    [2] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[3] = (uint8_T)rt_roundf(ADP_Dyc_Corr_Factor_Left_Vect
    [3] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[4] = (uint8_T)rt_roundf(ADP_Dyc_Corr_Factor_Left_Vect
    [4] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[5] = (uint8_T)rt_roundf(ADP_Dyc_Corr_Factor_Left_Vect
    [5] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[6] = (uint8_T)rt_roundf(ADP_Dyc_Corr_Factor_Left_Vect
    [6] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[7] = (uint8_T)rt_roundf(ADP_Dyc_Corr_Factor_Left_Vect
    [7] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[8] = (uint8_T)rt_roundf(ADP_Dyc_Corr_Factor_Left_Vect
    [8] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[9] = (uint8_T)rt_roundf(ADP_Dyc_Corr_Factor_Left_Vect
    [9] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[10] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Left_Vect[10] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[11] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Left_Vect[11] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[12] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Left_Vect[12] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[13] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Left_Vect[13] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[14] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Left_Vect[14] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[15] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Left_Vect[15] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[16] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Left_Vect[16] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[17] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Left_Vect[17] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[18] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Left_Vect[18] * 128.0F);
  DMC_ADP_CORR_FACTOR_POS[19] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Left_Vect[19] * 128.0F);

  /* DataTypeConversion: '<S4>/Data Type Conversion15' */
  DMC_ADP_CORR_FACTOR_NEG[0] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[0] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[1] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[1] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[2] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[2] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[3] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[3] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[4] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[4] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[5] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[5] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[6] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[6] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[7] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[7] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[8] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[8] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[9] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[9] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[10] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[10] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[11] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[11] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[12] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[12] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[13] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[13] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[14] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[14] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[15] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[15] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[16] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[16] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[17] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[17] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[18] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[18] * 128.0F);
  DMC_ADP_CORR_FACTOR_NEG[19] = (uint8_T)rt_roundf
    (ADP_Dyc_Corr_Factor_Right_Vect[19] * 128.0F);

  /* DataTypeConversion: '<S4>/Data Type Conversion24' */
  LAT_Kappa_Sum_Command_1pm = (int16_T)rt_roundf(rtb_mokw / 2.0E-5F);

  /* DataTypeConversion: '<S4>/Data Type Conversion26' */
  DMC_Steer_Angle_Oc_deg = (int16_T)rt_roundf(rtb_p2rb / 0.001526F);

  /* DataTypeConversion: '<S4>/Data Type Conversion29' */
  LAT_Road_Wheel_Angle_Cmd_deg = (int16_T)rt_roundf(rtb_nvod / 0.0025F);

  /* S-Function (sfcn_get_sens_pressure_tmc): '<S14>/sfcn_get_sens_pressure_tmc' incorporates:
   *  Constant: '<S14>/sensor number tmc'
   */
//  rtb_be5w = GET_SENS_PRESSURE_TMC( (int16_T)1, &rtb_eg00);

  /* S-Function (sfcn_get_sens_pressure_tmc_gradient): '<S14>/sfcn_get_sens_pressure_tmc_gradient' incorporates:
   *  Constant: '<S14>/sensor number tmc gradient'
   */
//  rtb_fgdz = GET_SENS_PRESSURE_TMC_GRADIENT( (int16_T)1, &rtb_osxw);

  /* Outputs for Iterator SubSystem: '<S14>/For Iterator Subsystem' incorporates:
   *  ForIterator: '<S17>/For Iterator'
   */
  rtb_dgpl = (int32_T)0;

  /* S-Function (sfcn_get_sig_box_data): '<S17>/sfcn_get_sig_box_data' incorporates:
   *  Constant: '<S17>/pressure wheel'
   */
//  rtb_g1it = GET_SIG_BOX_DATA( (signal_type_t)Sig_box_pwh, (int32_T)rtb_dgpl);
  rtb_dgpl = (int32_T)1;

  /* S-Function (sfcn_get_sig_box_data): '<S17>/sfcn_get_sig_box_data' incorporates:
   *  Constant: '<S17>/pressure wheel'
   */
//  rtb_g1it = GET_SIG_BOX_DATA( (signal_type_t)Sig_box_pwh, (int32_T)rtb_dgpl);
  rtb_dgpl = (int32_T)2;

  /* S-Function (sfcn_get_sig_box_data): '<S17>/sfcn_get_sig_box_data' incorporates:
   *  Constant: '<S17>/pressure wheel'
   */
//  rtb_g1it = GET_SIG_BOX_DATA( (signal_type_t)Sig_box_pwh, (int32_T)rtb_dgpl);
  rtb_dgpl = (int32_T)3;

  /* S-Function (sfcn_get_sig_box_data): '<S17>/sfcn_get_sig_box_data' incorporates:
   *  Constant: '<S17>/pressure wheel'
   */
//  rtb_g1it = GET_SIG_BOX_DATA( (signal_type_t)Sig_box_pwh, (int32_T)rtb_dgpl);

  /* End of Outputs for SubSystem: '<S14>/For Iterator Subsystem' */

  /* DataTypeConversion: '<S8>/Data Type Conversion10' incorporates:
   *  Inport: '<Root>/BUS_EPS_ASSIST_TRQ'
   */
  EPS_Tie_Rod_Load = ((real32_T)Get_bus_eps_assist_trq()) * 0.01F;

  /* DataTypeConversion: '<S8>/Data Type Conversion18' */
  VEH_Delta_clm_sens_F_dbg = (int16_T)((real32_T)floor(VEH_Delta_clm_sens_F /
    0.001526F));

  /* DataTypeConversion: '<S8>/Data Type Conversion3' incorporates:
   *  Inport: '<Root>/BUS_EPS_STATUS'
   */
  EPS_Status = Get_bus_eps_status();

  /* DataTypeConversion: '<S8>/Data Type Conversion4' */
  VEH_Delta_F_dbg = (int16_T)((real32_T)floor(VEH_Delta_F / 0.001526F));

  /* DataTypeConversion: '<S8>/Data Type Conversion5' */
  VEH_Delta_F_Dot_dbg = (int16_T)((real32_T)floor(rtb_dtct / 0.04375F));

  /* DataTypeConversion: '<S8>/Data Type Conversion6' */
  VEH_Steer_Torque_dbg = (int16_T)((real32_T)floor(VEH_Steer_Torque / 0.001F));

  /* DataTypeConversion: '<S8>/Data Type Conversion7' */
  EPS_Tie_Rod_Load_dbg = (int16_T)((real32_T)floor(EPS_Tie_Rod_Load));

  /* DataTypeConversion: '<S8>/Data Type Conversion8' */
  EPS_Motor_Torque_dbg = (int16_T)((real32_T)floor(EPS_Motor_Torque / 0.001F));

  /* DataTypeConversion: '<S8>/Data Type Conversion9' */
  EPS_Status_dbg = EPS_Status;

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  LaKMC_kappa_cmd_dbg = (int16_T)((real32_T)floor(LaKMC_kappa_cmd / 2.0E-5F));

  /* DataTypeConversion: '<S12>/Data Type Conversion3' incorporates:
   *  Inport: '<Root>/SSI_R_DMC_CRVT_DFTL_BRKG'
   */
  LaKMC_brake_kappa_ctrl_cmd = ((real32_T)Ssi_r_dmc_crvt_dftl_brkg()) * 2.0E-5F;

  /* DataTypeConversion: '<S12>/Data Type Conversion4' incorporates:
   *  Inport: '<Root>/SSI_R_DMC_STFN_REQ'
   */
  LaKMC_stiffness = Ssi_r_dmc_stfn_req();

  /* DataTypeConversion: '<S12>/Data Type Conversion5' incorporates:
   *  Inport: '<Root>/SSI_R_DMC_OCCRCY_REQ'
   */
  LaKMC_accuracy = Ssi_r_dmc_occrcy_req();

  /* ModelReference: '<S3>/LAT_Lateral_Controller_By_Brake' */
  DMC_Lat_Brake();

  /* DataTypeConversion: '<S4>/Data Type Conversion3' */
  LAT_Dmc_Status_dbg = DMC_LAT_STATUS;

  /* DataTypeConversion: '<S4>/Data Type Conversion4' */
  SAT_Saturated_Angle_Command_dbg = (int16_T)rt_roundf(rtb_hozt / 0.001526F);
}

/* Model initialize function */
void DMC_Soc_initialize(void)
{
  /* Registration code */

  /* block I/O */
  {
    DMC_Soc_B.LAT_Lateral_Controller_By_Brake_o1 = 0;
    DMC_Soc_B.LAT_Lateral_Controller_By_Brake_o2 = 0;
    DMC_Soc_B.LAT_Lateral_Controller_By_Brake_o4 = 0;
    DMC_Soc_B.LAT_Lateral_Controller_By_Brake_o3 = ((uint8_T)2U);
  }

  /* external inputs */
  (void) sde_memset((void *)&DMC_Soc_U, 0,
                    sizeof(ExternalInputs_DMC_Soc_T));

  /* Model Initialize fcn for ModelReference Block: '<S3>/LAT_Lateral_Controller_By_Brake' */
  DMC_Lat_Brake_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S3>/LAT_Soc_Lateral_Controller' */
  DMC_Soc_Lat_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S5>/LON_Longitudinal_Controller' */
  DMC_Long_initialize();

  /* Start for ModelReference: '<S3>/LAT_Soc_Lateral_Controller' */
  DMC_Soc_Lat_Start();

  /* InitializeConditions for ModelReference: '<S3>/LAT_Soc_Lateral_Controller' */
  DMC_Soc_Lat_Init((&(LADMC_EPS_INTERFACE_ACTIVE_REQ)));
}
