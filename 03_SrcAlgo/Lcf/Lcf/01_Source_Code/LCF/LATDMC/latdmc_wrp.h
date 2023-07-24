/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 latdmc_wrp.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.27 $


  ---*/ /*---
  CHANGES:                   $Log: latdmc_wrp.h  $
  CHANGES:                   Revision 1.27 2020/05/04 13:21:52CEST Feick, Stefan (uidw0691) 
  CHANGES:                   add road wheel angle input
  CHANGES:                   RAC/PAC torque as the input
  CHANGES:                   Revision 1.26 2020/01/24 17:08:38CET Feick, Stefan (uidw0691) 
  CHANGES:                   add dbg signals
  CHANGES:                   Revision 1.26.1.2 2019/07/30 10:04:15CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update wrappers after LCF workshop review
  CHANGES:                   Revision 1.26.1.1 2019/06/07 08:32:41CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update files for Sprint 05.10.01 on LCF variant
  CHANGES:                   Revision 1.26 2019/04/10 03:43:16CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.25 2019/03/12 16:22:37CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Update Source Code for Sprint5
  CHANGES:                   Revision 1.24 2019/01/15 15:01:37CET Onofrei, Marcel02 (uidk2509) 
  CHANGES:                   Update files for Sprint 1
  CHANGES:                   Revision 1.23 2018/12/18 12:08:23CET Onofrei, Marcel02 (uidk2509) 
  CHANGES:                   Checkpoint for Sprint 27 Round 3
  CHANGES:                   Revision 1.22 2018/12/12 14:02:05CET Onofrei, Marcel02 (uidk2509) 
  CHANGES:                   Check-in for sprint 27, Round1
  CHANGES:                   Revision 1.21 2018/12/05 11:42:21CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint 26, round 4
  CHANGES:                   Revision 1.20 2018/11/23 17:44:06CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint26, Round 1
  CHANGES:                   Revision 1.19 2018/11/23 10:24:40CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Correct Latdmc wrappers
  CHANGES:                   Revision 1.18 2018/11/01 15:54:30CET Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint 24, round 1
  CHANGES:                   Revision 1.17 2018/10/31 13:13:00CET Nastasa, Elena (uidt4846) 
  CHANGES:                   New mapping in LATDMC wrappers
  CHANGES:                   Revision 1.8 2018/10/08 18:00:13CEST Feick, Stefan (uidw0691) 
  CHANGES:                   - prepare offset re-calibration of pinion angle vs SWA
  CHANGES:                   Revision 1.15 2018/08/23 09:27:05CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint19
  CHANGES:                   Revision 1.14 2018/08/10 14:46:58CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Check-in for Sprint18
  CHANGES:                   Revision 1.13 2018/07/12 09:43:30CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   Updates in wrappers to be compatible with MFC431LO19_IuC_02.00.17
  CHANGES:                   Revision 1.12 2018/06/20 13:54:13CEST Stajilov, Victor (uidn1924) 
  CHANGES:                   add new signal for LATDMC (LO19)
  CHANGES:                   Revision 1.11 2018/04/19 09:38:11CEST Grosu, George (uidl9584) 
  CHANGES:                   8.2 Initial Revision
  CHANGES:                   Revision 1.9 2018/02/09 13:09:45CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   MFC431 R8.0 bugfix3
  CHANGES:                   Revision 1.8 2018/01/26 12:26:46CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Rework of LatDMC wrapper
  CHANGES:                   Revision 1.7 2017/12/08 17:20:11CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Member moved from latdmc_wrp.h in project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/lcf_veh/wrp/project.pj to latdmc_wrp.h in project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LATDMC/project.pj.
  CHANGES:                   Revision 1.6 2017/12/07 14:58:12CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Member moved from latdmc_wrp.h in project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/lcf_veh/wrp/project.pj to latdmc_wrp.h in project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LATDMC/project.pj.
  CHANGES:                   Revision 1.5 2017/11/20 19:03:43CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   LCF MFC431 R7.1
  CHANGES:                   Revision 1.4 2017/11/01 12:08:02CET Grosu, George (uidl9584) 
  CHANGES:                   Compilable version of maual code
  CHANGES:                   Revision 1.7.1.1 2017/09/22 16:08:01CEST Grosu, George (uidl9584) 
  CHANGES:                   Update for new RTE
  CHANGES:                   Revision 1.7 2017/07/06 11:43:28CEST Grosu, George (uidl9584) 
  CHANGES:                   Fix QAC errors
  CHANGES:                   Revision 1.6 2017/05/08 10:58:00CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update for R3.1 (LaDMC and CTRSC)
  CHANGES:                   Revision 1.5 2017/02/01 12:24:50CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   creation or R2.1 LCF functionality
  CHANGES:                   Revision 1.4 2016/11/09 12:08:30CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   remove inclusion of algo_glob.h from ext headers (for compatibility with generated headers)
  CHANGES:                   Revision 1.3 2016/11/03 11:59:05CET Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update for R2.0
  CHANGES:                   Revision 1.2 2016/09/08 08:55:39CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Update LCF for R1.0 release
  CHANGES:                   Revision 1.1 2016/08/29 11:02:24CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Wrapper bugfixes during LKA demo
  CHANGES:                   Revision 1.0 2016/07/01 06:45:37CEST Prajescu, Claudia (uidl9533) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/algo/00_Custom/lcfveh_wrp/project.pj

**************************************************************************** */
#ifndef latdmc_wrp_h__
#define latdmc_wrp_h__

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "latdmc_wrp_custom.h"
#include "DMC_Soc.h"
#include "LCFVEH/LCFVEH_data.h"
//#include "LCF_Custom.h"  //MFC5J3
/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
#define LADMC_TRQ_RES          (0.001f)       /* LaDMC output torque resolution */
#define LADMC_ASSIST_TRQ_RES   (0.01f)        /* LaDMC output assist torque resolution */
#define LADMC_VELX_FACTOR      (100.f)          /* LaDMC vehicle velocity input factor */ 
#define LADMC_YAWRATE_RES      (0.00286f)     /* LaDMC yaw rate resolution */
#define LADMC_LATACC_RES       (0.0981f)      /* LaDMC lateral acceleration resolution */
#define LADMC_STANGOFFSET_RES  (0.001f)       /* LaDMC steering angle offset resolution */
#define LADMC_STANG_RES        (0.0427272f)   /* LaDMC steering angle resolution */
#define LADMC_RWANG_RES        (0.0025)		  /* LaDMC road wheel angle resolution */
#define LADMC_STANGSENS_RES    (0.04375f)     /* LaDMC steering angle sensor resolution */
#define LADMC_STANGRATE_RES    (0.2442f)      /* LaDMC steering angle rate resolution */
#define LADMC_STANGRATEREQ_RES (0.00390625f)  /* LADMC steering angle rate request resolution */
#define LADMC_CRV_RES          (0.00002f)     /* LaDMC curvature resolution */
#define LADMC_CRVRATE_RES      (0.00005f)     /* LaDMC curvature rate resolution */
#define LADMC_LATERR_RES       (0.0009765625f)/* LaDMC lateral error resolution */
#define LADMC_HEADERR_RES      (0.001526f)    /* LaDMC heading error resolution */
#define LADMC_ANGLE_RES        (0.001526f)    /* LaDMC steer angle command resolution */
#define LADMC_HEADERR_HI_RES   (0.000030517578125f)  /* LaDMC heading error high resolution */
#if defined(LCF_IUC_USED) && (LCF_IUC_USED == 1)
#define LADMC_ANG_CTRL_TRQ_RES (1.0f)         /* LaDMC angle controller output torque resolution */
#else
#define LADMC_ANG_CTRL_TRQ_RES (0.001f)       /* LaDMC angle controller output torque resolution */
#endif

/*NVM data default values to be used in case of NVM read error */
#define LADMC_ADP_CORR_FCT_POS_DEF   (0xFFu)
#define LADMC_ADP_CORR_FCT_NEG_DEF   (0xFFu)
#define LADMC_ADP_CORR_CNT_POS_DEF   (0x0u)
#define LADMC_ADP_CORR_CNT_NEG_DEF   (0x0u)
#define LADMC_ANG_OFF_DEF            (0x7FFFu) /* ElNa, update in order to avoid overflow */
#define LADMC_ANG_OFF_CAL_CNT_DEF    (0x0u)

/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*****************************************************************************
  FUNCTION
*****************************************************************************/

/*****************************************************************************
  MACROS
*****************************************************************************/
/* Lateral DMC activation mode */
#ifndef	S_SSI_R_DMC_LAT_ACTVN_MOD
#define	S_SSI_R_DMC_LAT_ACTVN_MOD	((GET_S_CSCLTA_SysStateLCF_enum() == (uint8) E_LCF_SYSSTATE_REQUEST_nu) \
								||	 (GET_S_CSCLTA_SysStateLCF_enum() == (uint8) E_LCF_SYSSTATE_CONTROLLING_nu) \
								||	 (GET_S_CSCLTA_SysStateLCF_enum() == (uint8) E_LCF_SYSSTATE_RAMPOUT_nu))
#endif

#ifndef	S_DMC_ANGLE_FADING_REQ
#define	S_DMC_ANGLE_FADING_REQ	(GET_S_TPLCEN_ReplanCurValues_nu() == 1U)
#endif

#ifndef	S_DMC_RAMPING_DOWN_REQ
#define	S_DMC_RAMPING_DOWN_REQ	(GET_S_CSCLTA_SysStateLCF_enum() == (uint8) E_LCF_SYSSTATE_RAMPOUT_nu)
#endif

/* Total curvature command (feed forward + KMC)  */
#ifndef	S_SSI_R_DMC_CRVT_SUM_CMD
#define	S_SSI_R_DMC_CRVT_SUM_CMD	(GET_S_TCTCLM_Limiter_TgtCrv_1pm() / LADMC_CRV_RES)	/* curvature rate not yet output by TrjCtrl; will be done in the next release */
#endif

/* Curvature command feed forward from trajectory planner witout KMC */
#ifndef	S_SSI_R_DMC_CRVT_FEED_FWD
#define	S_SSI_R_DMC_CRVT_FEED_FWD	(GET_S_TCTCLM_Ffc_1pm() / LADMC_CRV_RES) //New mapping acc. to RO 968755
#endif

/* Curvature command rate feed forward from trajectory planner witout KMC */
#ifndef	S_SSI_R_DMC_CRVT_CHG_RATE
#define	S_SSI_R_DMC_CRVT_CHG_RATE	(0.0F / LADMC_CRVRATE_RES)
#endif

/* Curvature command from KMC without feed forward from trajectory planner */
#ifndef	S_SSI_R_DMC_CRVT_STEER_ACTR
#define	S_SSI_R_DMC_CRVT_STEER_ACTR	(GET_S_TCTCLM_FbcDc_1pm() / LADMC_CRV_RES) //New mapping acc. to RO 968755
#endif

/* Steer angle command from KMC without feed forward from trajectory planner */
#ifndef	S_SSI_R_DMC_STEER_AG_REQ
#define	S_SSI_R_DMC_STEER_AG_REQ	(GET_S_TCTCLM_DeltaFCmd_deg() / LADMC_ANGLE_RES) //New mapping acc. to RO 968755
#endif

/* Curvature commad rate from KMC without feed forward from trajectory planner */
#ifndef	S_SSI_R_DMC_CRVT_CMD_RATE
#define	S_SSI_R_DMC_CRVT_CMD_RATE	(0)	/* ask Jiaqi singal regarding mapping (for resoltion, datatype see attached excel sheet) */
#endif

/* Pure curvature command from the camera regarding the middle of the lane without modification by the trajectory planner, without preview, without latency compensation */
#ifndef	S_DMC_CAM_CRVT_FEED_FWD
#define	S_DMC_CAM_CRVT_FEED_FWD	(GET_S_ABPLBP_CntrLnClthCrv_1pm() / LADMC_CRV_RES)
#endif

/* Qualifier of the pure curvature command from the camera */
#ifndef	S_DMC_CAM_CRVT_FEED_FWD_QF
#define	S_DMC_CAM_CRVT_FEED_FWD_QF	(GET_S_LCFRCV_LaneValidQualifier_bool())
#endif

/* Lateral error with respect to the middle of the lane as seen by the camera without modification by the trajectory planner, without preview, without latency compensation */
#ifndef	S_DMC_CAM_LAT_ERR
#define	S_DMC_CAM_LAT_ERR	(GET_S_ABPLBP_CntrLnClthPosY0_met() / LADMC_LATERR_RES)
#endif

/* Qualifier of the lateral error with respect to the middle of the lane as seen by the camera */
#ifndef	S_DMC_CAM_LAT_ERR_QF
#define	S_DMC_CAM_LAT_ERR_QF	(GET_S_LCFRCV_LaneValidQualifier_bool())
#endif

/* Heading error with respect to the middle of the lane as seen by the camera without modification by the trajectory planner, without preview, without latency compensation */
#ifndef	S_DMC_CAM_HDNG_AG_ERR
#define	S_DMC_CAM_HDNG_AG_ERR	(GET_S_ABPLBP_CntrLnClthHeading_rad() / LADMC_HEADERR_HI_RES)
#endif

/* Qualifier of the heading error with respect to the middle of the lane as seen by the camera */
#ifndef	S_DMC_CAM_HDNG_AG_ERR_QF
#define	S_DMC_CAM_HDNG_AG_ERR_QF	(GET_S_LCFRCV_LaneValidQualifier_bool())
#endif

/* Lateral error with respect to the middle of the lane as it is used by the kinematic controller */
#ifndef	S_SSI_R_DMC_LAT_ERR
#define	S_SSI_R_DMC_LAT_ERR	(GET_S_TCTCDC_CtrlErrDistY_met() / LADMC_LATERR_RES)
#endif

/* Heading error with respect to the middle of the lane as it is used by the kinematic controller */
#ifndef	S_SSI_R_DMC_HDNG_AG_ERR
#define	S_SSI_R_DMC_HDNG_AG_ERR	(GET_S_TCTCDC_CtrlErrHeadAgl_rad() / LADMC_HEADERR_HI_RES)
#endif

/* Stiffness request */
#ifndef	S_SSI_R_DMC_STFN_REQ
#define	S_SSI_R_DMC_STFN_REQ	(0u)	/* signal not used anymore, only kept for compatibility reason */
#endif

/* Accuracy request */
#ifndef	S_SSI_R_DMC_OCCRCY_REQ
#define	S_SSI_R_DMC_OCCRCY_REQ	(0u)	/* signal not used anymore, only kept for compatibility reason */
#endif

/* Steering wheel vibration  */
#ifndef	S_SSI_R_DMC_STEER_WHL_VIBR
#define	S_SSI_R_DMC_STEER_WHL_VIBR	((GET_S_LCFRCV_LdwsLHWarning_bool() != 0U) ? 1 : ((GET_S_LCFRCV_LdwsRHWarning_bool() != 0U) ? 2 : 0))
#endif

/* Lane status information with prediction of oncoming LDP or RDP event */
#ifndef	S_SSI_R_LANE_STATUS
#define	S_SSI_R_LANE_STATUS	((GET_S_MCTLFC_ControllingFunction_nu() != 0U) ? GET_S_LCFRCV_LaneStatusLaKMC_st() : 0)
#endif

/* Vehicle velocity */
#ifndef	S_EST_REFERENCE_VELOCITY
#define	S_EST_REFERENCE_VELOCITY	(GET_S_LCFRCV_VehVelX_mps() * CONV_MPS2KPH * LADMC_VELX_FACTOR)
#endif

/* Steering wheel torque */
#ifndef	S_BUS_EPS_TOR_BAR_TORQUE
#define	S_BUS_EPS_TOR_BAR_TORQUE	(GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm() / LADMC_TRQ_RES)
#endif

/* Steering wheel torque (BUS_EPS_TOR_BAR_TORQUE) qualifier, 0: signal is valid, 1: signal is invalid */
#ifndef	S_BUS_EPS_TOR_BAR_TORQUE_QF
#define	S_BUS_EPS_TOR_BAR_TORQUE_QF	(GET_S_LCFRCV_StateInValidEPS_bool())
#endif

/* Current load at the tie road */
#ifndef	S_BUS_EPS_ASSIST_TRQ
#define	S_BUS_EPS_ASSIST_TRQ	(GET_S_LCFRCV_TieRodLoad_N() / LADMC_ASSIST_TRQ_RES)	/* default value 0 provided by Norm */
#endif

/* Finally arbitrated motor torque command */
#ifndef	S_BUS_EPS_MOTOR_TRQ
#define	S_BUS_EPS_MOTOR_TRQ	(GET_S_LCFRCV_MotorTorqueEPS_Nm() / LADMC_TRQ_RES)
#endif

/* EPS bus status, this singal is not used in DMC, just set it to 0 */
#ifndef	S_BUS_EPS_STATUS
#define	S_BUS_EPS_STATUS	(0u)	/* do not change this default value */
#endif

/* IuC torque request */
#ifndef	S_LAT_Eps_Torque_Request_nm
#define	S_LAT_Eps_Torque_Request_nm	(GET_S_LCFRCV_Eps_Torque_Request_nm() / LADMC_ANG_CTRL_TRQ_RES)
#endif

/* IuC DMC status */
#ifndef	S_LAT_Dmc_Status_nu
#define	S_LAT_Dmc_Status_nu	(GET_S_LCFRCV_Dmc_Status_nu())	/* do not change this default value */
#endif

/* Torque overlay interface is faulty */
#ifndef	S_HALFTorqueOverlayFault
#define	S_HALFTorqueOverlayFault	((GET_S_LCFRCV_TorqueFaultEPS_nu() != 0U) || (GET_S_LCFRCV_TorqueUnavailableEPS_nu() != 0U))
#endif

/* Torque overlay interface is activated (CF_Mdps_ToiActive) */
#ifndef	S_HALF_TORQUE_OVERLAY_ACTIVATED
#define	S_HALF_TORQUE_OVERLAY_ACTIVATED	(GET_S_LCFRCV_TorqueActiveEPS_nu())
#endif

/* EPS steer angle authority */
#ifndef	S_EpsSteerAngleAuthority
#define	S_EpsSteerAngleAuthority	(100u)	/* do not change this default value */
#endif

/* ESC active  (ESC_ActiveState) */
#ifndef	S_EPS_TEMP_DEACTIVATION_LDW
#define	S_EPS_TEMP_DEACTIVATION_LDW	(0u)	/* do not change this default value */
#endif

/* ESC active  (ESC_ActiveState) */
#ifndef	S_AYC_IN_CYCLE
#define	S_AYC_IN_CYCLE	(GET_S_LCFRCV_ActiveStCtrlESC_bool())
#endif

/* ESC is finally disabled (ESC_SystemState) */
#ifndef	S_FINAL_FUNCTION_DISABLE_AYC
#define	S_FINAL_FUNCTION_DISABLE_AYC	(GET_S_LCFRCV_SysStNotAvailESC_bool())
#endif

/* ESC is temporary disabled (ESC_SystemState) */
#ifndef	S_FUNCTION_DISABLE_AYC
#define	S_FUNCTION_DISABLE_AYC	(GET_S_LCFRCV_ActiveStShutdownESC_bool())
#endif

/* ESC warning lamp is active */
#ifndef	S_AYC_WARNING_LAMP
#define	S_AYC_WARNING_LAMP	(GET_S_LCFRCV_SysStErrorESC_bool())
#endif

/* Vehicle yaw rate */
#ifndef	S_DMC_FILTERED_YAW_RATE
#define	S_DMC_FILTERED_YAW_RATE	((GET_S_LCFRCV_EgoYawRate_rps() * CONV_RAD2DEG) / LADMC_YAWRATE_RES)
#endif

/* Vehicle yaw rate qualifier */ 
#ifndef	S_DMC_FILTERED_YAW_RATE_QF
#define	S_DMC_FILTERED_YAW_RATE_QF	(GET_S_LCFRCV_EgoYawRateValid_bool())
#endif

/* Vehicle lateral acceleration */
#ifndef	S_DMC_FILTERED_LATERAL_ACC_COG
#define	S_DMC_FILTERED_LATERAL_ACC_COG	(GET_S_LCFRCV_EgoAclY_mps2() / LADMC_LATACC_RES)
#endif

/* Vehicle lateral acceleration qualifier */
#ifndef	S_DMC_FILTERED_LATERAL_ACC_COG_QF
#define	S_DMC_FILTERED_LATERAL_ACC_COG_QF	(GET_S_LCFRCV_EgoAclYValid_bool())
#endif

/* EPS steering angle */
#ifndef	S_SSI_R_EPS_STEER_AG
#define	S_SSI_R_EPS_STEER_AG	(GET_S_LCFRCV_SteerAngleEPS_deg() / LADMC_STANG_RES)	/* DeltaFSteerAngle__deg = Steer wheel angle(SAS_Angle) */
#endif

/* Road wheel angle */
#ifndef	S_DMC_ROAD_WHEEL_ANGLE
#define S_DMC_ROAD_WHEEL_ANGLE   ( 0 / LADMC_RWANG_RES); /* to be mapped to road wheel angle (e.g. Lucid) */ 
#endif

/* EPS steering angle qualifier */
#ifndef	S_DMC_FILTERED_STEER_ANGLE_QF
#define	S_DMC_FILTERED_STEER_ANGLE_QF	(GET_S_LCFRCV_SteerAngleValidEPS_bool())
#endif

/* EPS steering angle rate */
#ifndef	S_SSI_R_EPS_STEER_AG_RATE
#define	S_SSI_R_EPS_STEER_AG_RATE	(GET_S_LCFRCV_SteerAngleRateEPS_degps() / LADMC_STANGRATE_RES)	/* DeltaFSteerAngleRate__degps = Steer wheel angle rate(SAS_speed) */
#endif

/* EPS steering angle rate qualifier */
#ifndef	S_DMC_FILTERED_STEER_ANGLE_RATE_QF
#define	S_DMC_FILTERED_STEER_ANGLE_RATE_QF	(GET_S_LCFRCV_SteerAngleRateValidEPS_bool())
#endif

/* Steering angle offset from VDY */
#ifndef	S_DMC_STEER_ANGLE_OFFSET
#define	S_DMC_STEER_ANGLE_OFFSET	(GET_S_LCFRCV_SteeringAngleOffset_rad() / LADMC_STANGOFFSET_RES)
#endif

/* Steering angle offset state from VDY; actual range of signal from VDY is 0..6 */
#ifndef	S_DMC_STEER_ANGLE_OFFSET_STATE
#define	S_DMC_STEER_ANGLE_OFFSET_STATE	(GET_S_LCFRCV_SteeringAngleState_rad())
#endif

/* Yaw rate offset from VDY */
#ifndef	S_DMC_YAW_RATE_OFFSET
#define	S_DMC_YAW_RATE_OFFSET	((GET_S_LCFRCV_EgoYawRateOffset_rps() * CONV_RAD2DEG) / LADMC_YAWRATE_RES)	// in degree
#endif

/* Yaw rate offset state from VDY */
#ifndef	S_DMC_YAW_RATE_OFFSET_STATE
#define	S_DMC_YAW_RATE_OFFSET_STATE	(GET_S_LCFRCV_EgoYawRateState_st())
#endif

/* Forced shutting off of the DMC by the mode controller */
#ifndef	S_DMC_FORCE_SHUT_OFF_REQUEST
#define	S_DMC_FORCE_SHUT_OFF_REQUEST	(0u)
#endif

/* Stiffness parameter */
#ifndef	S_DMC_STIFFNESS_LIMIT
#define	S_DMC_STIFFNESS_LIMIT	(GET_S_CSCLTA_StrWhStifLimit_nu())
#endif

/* Stiffness parameter */
#ifndef	S_DMC_STIFFNESS_GRAD
#define	S_DMC_STIFFNESS_GRAD	(GET_S_CSCLTA_StrWhStifGrad_1ps())
#endif

/* Torque scale parameter */
#ifndef	S_DMC_TORQUE_SCALE_LIMIT
#define	S_DMC_TORQUE_SCALE_LIMIT	(GET_S_CSCLTA_MaxTrqScalLimit_nu())
#endif

/* Torque scale parameter */
#ifndef	S_DMC_TORQUE_SCALE_GRAD
#define	S_DMC_TORQUE_SCALE_GRAD	(GET_S_CSCLTA_MaxTrqScalGrad_1ps())
#endif

/* Torque ramp gradient */
#ifndef	S_DMC_TORQUE_RAMP_GRAD
#define	S_DMC_TORQUE_RAMP_GRAD	(GET_S_CSCLTA_TrqRampGrad_1ps())
#endif

/* DMC accuracy */ 
#ifndef	S_DMC_HIGH_ACCURACY_REQUEST
#define	S_DMC_HIGH_ACCURACY_REQUEST	(GET_S_CSCLTA_HighStatAccu_bool())
#endif

/* DMC angle command limitation */ 
#ifndef	S_DMC_ANGLE_REQ_MAX_LIMIT_SCALE
#define	S_DMC_ANGLE_REQ_MAX_LIMIT_SCALE	(100u) //ClPr: Signal not available yet (AngReqMaxLimitScale_per added in RTE 8.2)
#endif

/* DMC angle gradient limitation */
#ifndef	S_DMC_ANGLE_REQ_MAX_GRAD_SCALE
#define	S_DMC_ANGLE_REQ_MAX_GRAD_SCALE	(100u) //ClPr: Signal not available yet (AngReqRateMaxLimitScale_per added in RTE 8.2)
#endif

/* Requested driving mode by driver */
#ifndef	S_DMC_DRIVING_MODE  
#define	S_DMC_DRIVING_MODE	(0u)// to be decided
#endif

/* Bank angle */
#ifndef	S_DMC_BANK_ANGLE
#define	S_DMC_BANK_ANGLE	 (GET_S_LCFRCV_RoadBankAngle_rad() / LADMC_HEADERR_HI_RES)
#endif

/* Pitch angle */
#ifndef	S_EMO_PITCH_ANGLE
#define	S_EMO_PITCH_ANGLE	 (GET_S_LCFRCV_PitchAngleOnline_rad() / LADMC_HEADERR_HI_RES) //ToDo: check if the input is correct?
#endif

/* ViSt added external linkage for UNCALIBRATED_SWA_FIL */
#ifndef	S_UNCALIBRATED_SWA_FIL
#define	S_UNCALIBRATED_SWA_FIL	(GET_S_LCFRCV_ActualStWheelAngle_deg() / LADMC_STANGSENS_RES)
#endif

/* Driver torque derating request */
#ifndef S_DMC_DERATING_LEVEL_REQ
#define	S_DMC_DERATING_LEVEL_REQ (GET_S_CSCLTA_DeratingLevel_nu())
#endif

/* Driving straight forward condition */
#ifndef S_STRAIGHT_FORWARD
#define	S_STRAIGHT_FORWARD (GET_S_ABPLBP_StraightPathDtct_nu())
#endif

/* Shutting off request */
#ifndef S_DMC_SHUT_OFF_ON_ERROR
#define	S_DMC_SHUT_OFF_ON_ERROR (0u)
#endif

/* Side object status */
#ifndef S_DMC_SIDE_OBJECT_STATUS
#define	S_DMC_SIDE_OBJECT_STATUS (GET_S_TJAOBS_OffScenarioInvalid_btf())
#endif

/* Road condition */
#ifndef S_DMC_ROAD_CONDITION
#define	S_DMC_ROAD_CONDITION (GET_S_ABPLBP_UpDownHillDtct_perc())
#endif

#endif // latdmc_wrp_h__
/** @} end defgroup */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
