/**
@file
$RCSfile: dmc_ac.h $
$Revision: 1.18 $
$Date: 2020/05/04 15:55:47CEST $

Confidential and proprietary. This document and its contents are the
exclusive property of Continental Teves AG & Co. OHG (Teves) and Conti Temic
microelectronic GmbH (Temic) and their associated companies. They are not to
be copied, distributed, or otherwise disclosed or used without the prior
written consent of Teves and Temic. All rights reserved.

@author $Setting file_owner: ???? $

@brief    Interface files required by autocoded part of SCS.
@details

@ingroup  SCS
*/

#ifndef Dmc_ac_h_included
#define Dmc_ac_h_included

/*==================================================================
                           INCLUDES
==================================================================*/
#include "fal_lvc_ram_def.h"  //MFC5J3





/* Signals out */
#include "dmc_if.h"
#include "dmc_ram.h"


/* Parameters */
#include "dmc_lat.h"  //MFC5J3

/* General autocode interfaces */
#include "sde_memset.h"  /* sde_memset() */
#include "rtwtypes.h"    /* autocode specific types */
/*==================================================================
                           DEFINES
===================================================================*/
#define PORTABLE_WORDSIZES //Define needed to compile LATDMC for both 32 and 64 bit


/*==================================================================
                           TYPES
===================================================================*/

/*==================================================================
                           VARIABLES
===================================================================*/

/* temporary until SSI signals available */
lvc_ram_prio1 signed_int16_t BUS_EPS_ASSIST_TRQ;
lvc_ram_prio1 signed_int16_t BUS_EPS_MOTOR_TRQ;
lvc_ram_prio1 unsigned_char_t EpsSteerAngleAuthority;
lvc_ram_prio1 boolean HALFTorqueOverlayFault;
lvc_ram_prio1 boolean EPS_TEMP_DEACTIVATION_LDW;
lvc_ram_prio1 boolean HALF_TORQUE_OVERLAY_ACTIVATED;
lvc_ram_prio1 signed_int16_t SSI_R_DMC_LAT_ACTVN_MOD;
lvc_ram_prio1 signed_int16_t SSI_R_DMC_CRVT_SUM_CMD;
lvc_ram_prio1 signed_int16_t SSI_R_DMC_CRVT_FEED_FWD;
lvc_ram_prio1 signed_int16_t SSI_R_DMC_CRVT_CHG_RATE;
lvc_ram_prio1 signed_int16_t SSI_R_DMC_CRVT_STEER_ACTR;
lvc_ram_prio1 signed_int16_t SSI_R_DMC_CRVT_CMD_RATE;
lvc_ram_prio1 unsigned_char_t SSI_R_DMC_STFN_REQ;
lvc_ram_prio1 unsigned_char_t SSI_R_DMC_OCCRCY_REQ;
lvc_ram_prio1 signed_int16_t SSI_R_DMC_LAT_ERR;
lvc_ram_prio1 signed_int16_t SSI_R_DMC_HDNG_AG_ERR;
lvc_ram_prio1 signed_int16_t SSI_R_EPS_STEER_AG;
lvc_ram_prio1 signed_int16_t SSI_R_EPS_STEER_AG_RATE;
lvc_ram_prio1 signed_int16_t SSI_R_DMC_STEER_WHL_VIBR;
lvc_ram_prio1 signed_int16_t SSI_R_LANE_STATUS;
lvc_ram_prio1 signed_int16_t EST_REFERENCE_VELOCITY;
lvc_ram_prio1 signed_int16_t BUS_EPS_TOR_BAR_TORQUE;
lvc_ram_prio1 unsigned_char_t BUS_EPS_STATUS;
lvc_ram_prio1 boolean BUS_EPS_TOR_BAR_TORQUE_QF;
lvc_ram_prio1 boolean AYC_IN_CYCLE;
lvc_ram_prio1 boolean FINAL_FUNCTION_DISABLE_AYC;
lvc_ram_prio1 boolean FUNCTION_DISABLE_AYC;
lvc_ram_prio1 boolean AYC_WARNING_LAMP;
lvc_ram_prio1 signed_int16_t DMC_FILTERED_YAW_RATE;
lvc_ram_prio1 signed_int16_t DMC_FILTERED_YAW_RATE_QF;
lvc_ram_prio1 signed_char_t DMC_FILTERED_LATERAL_ACC_COG;
lvc_ram_prio1 signed_int16_t DMC_FILTERED_LATERAL_ACC_COG_QF;
lvc_ram_prio1 signed_int16_t DMC_FILTERED_STEER_ANGLE_QF;
lvc_ram_prio1 signed_int16_t DMC_FILTERED_STEER_ANGLE_RATE_QF;
lvc_ram_prio1 signed_int16_t DMC_STEER_ANGLE_OFFSET;
lvc_ram_prio1 signed_int16_t DMC_STEER_ANGLE_OFFSET_STATE;
lvc_ram_prio1 signed_int16_t DMC_FILTERED_STEER_ANGLE;
lvc_ram_prio1 signed_int16_t DMC_FILTERED_STEER_ANGLE_RATE;
lvc_ram_prio1 signed_int16_t UNCALIBRATED_SWA_FIL;
lvc_ram_prio1 signed_int16_t DMC_CAM_CRVT_FEED_FWD;
lvc_ram_prio1 signed_int16_t DMC_CAM_LAT_ERR;
lvc_ram_prio1 signed_int16_t DMC_CAM_HDNG_AG_ERR;
lvc_ram_prio1 signed_int16_t DMC_CAM_CRVT_FEED_FWD_QF;
lvc_ram_prio1 signed_int16_t DMC_CAM_LAT_ERR_QF;
lvc_ram_prio1 signed_int16_t DMC_CAM_HDNG_AG_ERR_QF;
lvc_ram_prio1 signed_int16_t DMC_YAW_RATE_OFFSET;
lvc_ram_prio1 signed_int16_t DMC_YAW_RATE_OFFSET_STATE;
lvc_ram_prio1 unsigned_char_t DMC_FORCE_SHUT_OFF_REQUEST;
lvc_ram_prio1 signed_int16_t SSI_R_DMC_STEER_AG_REQ; //ClPr, variable not declared
lvc_ram_prio1 unsigned_char_t DMC_ANGLE_FADING_REQ;
lvc_ram_prio1 unsigned_char_t DMC_RAMPING_DOWN_REQ;
lvc_ram_prio1 unsigned_char_t DMC_ANGLE_REQ_MAX_LIMIT_SCALE; //ClPr, variable not declared
lvc_ram_prio1 unsigned_char_t DMC_ANGLE_REQ_MAX_GRAD_SCALE; //ClPr, variable not declared
lvc_ram_prio1 signed_int16_t DMC_ANGLE_OFF_LOOP0;
lvc_ram_prio1 unsigned_int16_t DMC_ANGLE_OFF_CALIB_CNT_LOOP0;
lvc_ram_prio1 unsigned_char_t DMC_ANGLE_OFF_READ_ERROR;
lvc_ram_prio1 unsigned_char_t DMC_ADP_CORR_FACTOR_POS_LOOP0[20];
lvc_ram_prio1 unsigned_char_t DMC_ADP_CORR_FACTOR_NEG_LOOP0[20];
lvc_ram_prio1 unsigned_int16_t DMC_ADP_CORR_COUNTER_POS_LOOP0[20];
lvc_ram_prio1 unsigned_int16_t DMC_ADP_CORR_COUNTER_NEG_LOOP0[20];
lvc_ram_prio1 unsigned_char_t DMC_ADP_CORR_FACTOR_READ_ERROR;
lvc_ram_prio1 unsigned_char_t DMC_DERATING_LEVEL_REQ;
lvc_ram_prio1 unsigned_char_t DMC_DRIVING_MODE;
lvc_ram_prio1 unsigned_char_t DMC_STIFFNESS_LIMIT;
lvc_ram_prio1 signed_int16_t DMC_STIFFNESS_GRAD;
lvc_ram_prio1 unsigned_char_t DMC_TORQUE_SCALE_LIMIT;
lvc_ram_prio1 signed_int16_t DMC_TORQUE_SCALE_GRAD;
lvc_ram_prio1 signed_int16_t DMC_TORQUE_RAMP_GRAD;
lvc_ram_prio1 unsigned_char_t DMC_HIGH_ACCURACY_REQUEST;
lvc_ram_prio1 unsigned_char_t LAT_Dmc_Status_nu;
lvc_ram_prio1 signed_int16_t LAT_Eps_Torque_Request_nm;
lvc_ram_prio1 signed_int16_t DMC_BANK_ANGLE;
lvc_ram_prio1 signed_int16_t DMC_GPIO;
lvc_ram_prio1 signed_int16_t DMC_GPIO2;
lvc_ram_prio1 signed_int16_t DMC_GPIO3;
lvc_ram_prio1 signed_int16_t DMC_GPIO4;
lvc_ram_prio1 signed_int16_t EMO_PITCH_ANGLE;
lvc_ram_prio1 signed_int16_t DMC_ROAD_WHEEL_ANGLE;
lvc_ram_prio1 unsigned_char_t DMC_SHUT_OFF_ON_ERROR;

/*==================================================================
                           MACROS
==================================================================*/

/* temporary until SSI signals available */
#define Get_bus_eps_assist_trq()  (BUS_EPS_ASSIST_TRQ)
#define Get_bus_eps_motor_trq()  (BUS_EPS_MOTOR_TRQ)
#define Get_bus_eps_tor_bar_torque()     (BUS_EPS_TOR_BAR_TORQUE)
#define Get_bus_eps_status()             (BUS_EPS_STATUS)
#define Get_bus_eps_tor_bar_torque_qf()  (BUS_EPS_TOR_BAR_TORQUE_QF)

#define Ssi_r_dmc_lat_actvn_mod()    (SSI_R_DMC_LAT_ACTVN_MOD)
#define Ssi_r_dmc_crvt_sum_cmd()     (SSI_R_DMC_CRVT_SUM_CMD)
#define Ssi_r_dmc_crvt_feed_fwd()    (SSI_R_DMC_CRVT_FEED_FWD)
#define Ssi_r_dmc_crvt_chg_rate()    (SSI_R_DMC_CRVT_CHG_RATE)
#define Ssi_r_dmc_crvt_dftl_brkg()   (0) /* no request in this project */
#define Ssi_r_dmc_crvt_steer_actr()  (SSI_R_DMC_CRVT_STEER_ACTR)
#define Ssi_r_dmc_crvt_cmd_rate()    (SSI_R_DMC_CRVT_CMD_RATE)
#define Ssi_r_dmc_steer_ag_req()     (SSI_R_DMC_STEER_AG_REQ) 
#define Ssi_r_dmc_stfn_req()         (SSI_R_DMC_STFN_REQ)
#define Ssi_r_dmc_occrcy_req()       (SSI_R_DMC_OCCRCY_REQ)
#define Ssi_r_dmc_lat_err()          (SSI_R_DMC_LAT_ERR)
#define Ssi_r_dmc_hdng_ag_err()      (SSI_R_DMC_HDNG_AG_ERR)
#define Ssi_r_eps_steer_ag()         (SSI_R_EPS_STEER_AG)
#define Ssi_r_eps_steer_ag_rate()    (SSI_R_EPS_STEER_AG_RATE)
#define Ssi_r_dmc_steer_whl_vibr()   (SSI_R_DMC_STEER_WHL_VIBR)
#define Ssi_r_lane_status()          (SSI_R_LANE_STATUS)

/*
#define Get_dmc_cam_crvt_feed_fwd()      (DMC_CAM_CRVT_FEED_FWD)
#define Dmc_cam_lat_err()   		 (DMC_CAM_LAT_ERR)
#define Dmc_cam_hdng_err()  		 (DMC_CAM_HDNG_AG_ERR)
#define Dmc_cam_crvt_feed_fwd_qf()	 (DMC_CAM_CRVT_FEED_FWD_QF)
#define Dmc_cam_lat_err_qf()		 (DMC_CAM_LAT_ERR_QF)
#define Dmc_cam_hdng_ag_err_qf()	 (DMC_CAM_HDNG_AG_ERR_QF)
*/

#define Ssi_r_isok_dmc_lat_actvn_mod()    (1)
#define Ssi_r_isok_dmc_crvt_feed_fwd()    (1)
#define Ssi_r_isok_dmc_crvt_chg_rate()    (1)
#define Ssi_r_isok_dmc_crvt_dftl_brkg()   (1)
#define Ssi_r_isok_dmc_crvt_steer_actr()  (1)
#define Ssi_r_isok_dmc_steer_ag_req()     (1)
#define Ssi_r_isok_dmc_stfn_req()         (1)
#define Ssi_r_isok_dmc_occrcy_req()       (1)
#define Ssi_r_isok_dmc_lat_err()          (1)
#define Ssi_r_isok_dmc_hdng_ag_err()      (1)
#define Ssi_r_isok_dmc_steer_whl_vibr()   (1)
#define Get_abs_cycle()                  (0)
#define Get_ayc_in_cycle()              (0)  
#define Get_tcs_engine_control_active()  (0)
#define Get_btcs_active()                (0)
#define Get_fs_final_func_dis_abs()      (0)
#define Get_fs_function_disable_abs()    (0)
#define Get_fs_final_func_dis_ayc()      (FINAL_FUNCTION_DISABLE_AYC)
#define Get_fs_function_disable_ayc()    (FUNCTION_DISABLE_AYC)
#define Get_fs_final_func_dis_btc()      (0)
#define Get_fs_function_disable_btc()    (0)
#define Get_fs_final_func_dis_mtc()      (0)
#define Get_fs_function_disable_mtc()    (0)
#define Get_fs_ayc_warning_lamp()        (AYC_WARNING_LAMP)

/*==================================================================
                           FUNCTIONS
===================================================================*/


#endif   /* Scs_ac_h_included */
/*==================================================================
$Log: dmc_ac.h  $
Revision 1.18 2020/05/04 15:55:47CEST Feick, Stefan (uidw0691) 
dmc angle interface update
Revision 1.8 2018/12/07 10:06:27CET Feick, Stefan (uidw0691) 
add DMC_GPIO
Revision 1.7 2018/12/06 14:56:01CET Feick, Stefan (uidw0691) 
add DMC_ANGLE_FADING_REQ_SOURCE2
Revision 1.6 2018/11/22 10:02:42CET Babar, Ketan (uidj9168) 
LaDMC_Update_22112018
Revision 1.5 2018/10/18 10:37:16CEST Feick, Stefan (uidw0691) 
- storing of angle offset as an option
- dyn corr factor depending on velocity
Revision 1.4 2018/10/08 17:29:02CEST Feick, Stefan (uidw0691) 
- angle rate limitation request via external signal
- tdf_max/min parameter introduced
- nonlinear filter to reduce lateral oscillations
- higher learning rate of the offset calibration if the driver is correctiong the vehicle path to the lane centere offset calibration if the driver is correctiong the vehicle path to the lane center
Revision 1.2.3.1 2018/10/08 17:10:19CEST Feick, Stefan (uidw0691) 
- angle rate limitation request via external signal
- tdf_max/min parameter introduced
- nonlinear filter to reduce lateral oscillations
- higher learning rate of the offset calibration if the driver is correctiong the vehicle path to the lane centere offset calibration if the driver is correctiong the vehicle path to the lane center
Revision 1.3 2018/02/09 13:09:14CET Prajescu, Claudia (uidl9533) 
MFC431 R8.0 bugfix3
Revision 1.2 2018/02/02 12:45:02CET Prajescu, Claudia (uidl9533) 
MFC431 R8.0 bugfix2 - round 3 (fix pdo tags include, use LaDMC for TA19)
Revision 1.1 2018/01/24 16:29:36CET Asong, Wedndah Asaha (uidj2187) 
Initial revision
Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LATDMC/latdmc_veh_ang/project.pj
Revision 1.2 2017/12/08 14:58:59CET Feick, Stefan (uidw0691) 
add inp var
Revision 1.1 2017/10/19 11:42:01CEST Feick, Stefan (uidw0691) 
Initial revision
Member added to project /C_ST/CMP/C_A_DMCSOC/30_Software_Engineering/30_SW_Environment/20_SourceCode/project.pj
Revision 1.7 2017/09/29 13:07:51CEST Feick, Stefan (uidw0691) 
R7.0
Revision 1.6 2017/09/29 11:47:46CEST Feick, Stefan (uidw0691) 
remove signal
Revision 1.5 2017/08/17 09:50:37CEST Feick, Stefan (uidw0691) 
add steer angle request
Revision 1.4 2017/07/13 11:02:49CEST Feick, Stefan (uidw0691) 
dmc_shut_off corr
Revision 1.3 2017/07/12 19:43:28CEST Feick, Stefan (uidw0691) 
update
Revision 1.2 2017/05/12 11:31:52CEST Feick, Stefan (uidw0691) 
add DMC_YAW_RATE_OFFSET, DMC_YAW_RATE_OFFSET_STATE
Revision 1.1 2017/01/11 06:01:44CET Babar, Ketan (uidj9168) 
Initial revision
Member added to project /C_ST/A_HI_LCF_1802/20_System_Design/40_Implementation/10_Sources/10_Models/20_System_Function/LateralControlFunctions/C_A_LATDMC/30_Software_Engineering/30_SW_Environment/20_SoCo/project.pj
Revision 1.21.2.2 2016/08/18 04:44:40CEST Babar, Ketan (uidj9168) 
Update
Revision 1.21.2.1 2016/07/25 09:58:45CEST Babar, Ketan (uidj9168) 
Preparation of lateral dmc for external hardware
Revision 1.21 2016/06/03 08:50:04CEST Babar, Ketan (uidj9168) 
Addition of header file of lateral DMC input/output
Revision 1.20 2016/04/28 12:20:01CEST Babar, Ketan (uidj9168) 
Update header files for AYC, ABS and TCS active as well as disabled
Revision 1.19 2016/01/29 10:46:52CET Bretzigheimer, Kai (TFTS06) 
rename pacs parameter
Revision 1.18 2016/01/26 10:39:21CET Feick, Stefan (uidw0691) 
check for (CFG_CCP_GLOBAL == 0) when renaming for PACS
Revision 1.17 2016/01/22 13:29:25CET Feick, Stefan (uidw0691) 
add para
Revision 1.16 2016/01/11 16:17:16CET Bretzigheimer, Kai (TFTS06) 
include lateral acceleration
Revision 1.15 2015/12/18 11:48:43CET Feick, Stefan (uidw0691) 
add Obs_filter_omega, Obs_filter_tau
Revision 1.14 2015/12/15 17:47:31CET Feick, Stefan (uidw0691) 
add LAT_Torque_Ramp_Down_Gradient, SAC_Parity_Time_Constant
Revision 1.13 2015/12/15 12:59:25CET Bretzigheimer, Kai (TFTS06) 
add extern declaration of temporary input signals
Revision 1.12 2015/12/14 20:21:32CET Feick, Stefan (uidw0691) 
rem SAC_ from PACS define
Revision 1.10 2015/12/11 15:19:50CET Feick, Stefan (uidw0691) 
add Lat_Direct_Feedthrough_Trq
Revision 1.9 2015/12/11 14:45:17CET Feick, Stefan (uidw0691) 
add Lat_Direct_Feedthrough_Torque
Revision 1.8 2015/12/01 18:38:43CET Bretzigheimer, Kai (TFTS06) 
from double to single
Revision 1.7 2015/11/18 16:16:47CET Bretzigheimer, Kai (TFTS06) 
use degradation and implement eps connection sequense
Revision 1.6 2015/11/18 15:13:47CET Bretzigheimer, Kai (TFTS06) 
distinguish simulation
Revision 1.5 2015/11/17 12:21:42CET Bretzigheimer, Kai (TFTS06) 
connect CAN interface. degradation check
Revision 1.4 2015/11/10 10:53:26CET Bretzigheimer, Kai (TFTS06) 
add LoDMC interface
Revision 1.3 2015/10/16 15:38:02CEST Bretzigheimer, Kai (TFTS06) 
Use Ssi for DMC
Revision 1.2 2015/07/27 08:04:30CEST Babar, Ketan (uidj9168) 
Mapping of PACS parameters to Simulink parameters
Revision 1.1 2015/07/23 11:19:53CEST Bretzigheimer, Kai (tfts06) 
Initial revision
Member added to project d:/mks/archives/src/LVC/2009CW35_LVC.pj
Revision 1.1.1.2 2015/05/12 17:02:34CEST Kreis, Damian (Kreis) 
remove include of scs_const.h
Revision 1.1.1.1 2015/04/17 14:09:05CEST Kreis, Damian (Kreis) 
update
Revision 1.1 2015/04/08 08:27:22CEST Henke, Patrick (HenkeP) 
Initial revision
Member added to project d:/mks/archives/src3/CT_VC1/EBS/FSW/VehDyC/VehDyC_generic/SCS/project.pj

==================================================================*/
/* EOF */
