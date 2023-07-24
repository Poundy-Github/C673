/*! \file **********************************************************************

  @defgroup VDYInternalTypes VDY Internal Bus
	@ingroup VDYHandCode
  @{

  $Company:			Continental AG $

  $Component:		VDY (Vehicle Dynamics Observer) $

  $Module:			vdy_internal_types.h $

  @brief			In this file the intenal bus of the autocode is defined
  
  $Descripion:		In this file the intenal bus of the autocode is defined $

  $Revision: 1.6 $

  CHANGES:
  ---*/ /*---
  CHANGE:           $Log: vdy_internal_types.h  $
  CHANGE:           Revision 1.6 2019/05/27 14:57:02CEST Chinnaswamy, Ramachandra (uids4735) (uids4735) 
  CHANGE:           QAF fix
  CHANGE:           Revision 1.5 2019/01/31 07:25:24CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.4 2018/10/26 15:48:16CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Accordance with AL_VDY_BASE_05.00.10_INT-0
  CHANGE:           Revision 1.3 2018/09/04 12:00:04CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.2 2018/08/28 13:29:30CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Unit Design Update
  CHANGE:           Revision 1.1 2018/08/09 10:40:55CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Initial revision
  CHANGE:           Member added to project /ADAS/SW/Components/VDY_VehicleDynamics/04_Engineering/01_Source_Code/VDY/vdy/project.pj
  CHANGE:           Revision 1.9.1.1 2018/07/25 11:48:52CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY mearged code for ARS and MFC : Mainstream
  CHANGE:           Revision 1.9 2018/05/13 10:22:23CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Addition of Aln and Bankroad
  CHANGE:           Revision 1.8 2017/03/31 05:27:38CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Velocity Correction internal varibles measfreezed in internal data for 510 base projects
  CHANGE:           Revision 1.7 2017/03/10 13:01:38CET Berwal, Anuj (uidp1444) 
  CHANGE:           -Checked In Rev. 1.3.1.1 into Main Branch
  CHANGE:           Revision 1.3.1.1 2016/02/04 09:37:32CET Mani, Yugesh (uidj6870) 
  CHANGE:           - Q matrix averaging technique of yaw rates  are  modified in vdy_ye
  CHANGE:           Revision 1.3 2014/03/07 09:27:42CET Wolter, Frank (wolterf) 
  CHANGE:           switched to Autosar types
  CHANGE:           - Added comments -  wolterf [Mar 7, 2014 9:27:43 AM CET]
  CHANGE:           Change Package : 223834:1 http://mks-psad:7002/im/viewissue?selection=223834
  CHANGE:           Revision 1.2 2010/01/27 15:10:51CET jspruck 
  CHANGE:           Change from .he to ext.h external header files
  CHANGE:           --- Added comments ---  jspruck [2010/01/27 14:10:51Z]
  CHANGE:           Change Package : 33263:3 http://LISS014:6001/im/viewissue?selection=33263
  CHANGE:           Revision 1.1 2009/09/17 17:01:07CEST Jochen Spruck (jspruck) 
  CHANGE:           Initial revision
  CHANGE:           Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/VDY_VehicleDynamics/04_Engineering/01_Source_Code/algo/vdy/project.pj
  CHANGE:           Revision 1.16 2009/04/03 12:34:41CEST Jochen Spruck (jspruck) 
  CHANGE:           Optimization of initalization of VDY simulator
  CHANGE:            - Add estimated disc self steering grad to the output interface
  CHANGE:           --- Added comments ---  jspruck [2009/04/03 10:34:41Z]
  CHANGE:           Change Package : 25038:1 http://LISS014:6001/im/viewissue?selection=25038
  CHANGE:           Revision 1.15 2008/10/22 13:26:40CEST Jochen Spruck (jspruck) 
  CHANGE:           - Filter raw dyn wheel speed  yaw rate offset (FT = 2500s)
  CHANGE:           - Calculate with this filtered offset sensor yaw rate for alignment
  CHANGE:           --- Added comments ---  jspruck [2008/10/22 11:26:40Z]
  CHANGE:           Change Package : 18777:1 http://LISS014:6001/im/viewissue?selection=18777
  CHANGE:           Revision 1.14 2008/05/15 17:03:54CEST Jochen Spruck (jspruck) 
  CHANGE:           raise up yaw rate variance if stand still yaw rate offset is not available or bad
  CHANGE:           --- Added comments ---  jspruck [2008/05/15 15:03:54Z]
  CHANGE:           Change Package : 13131:1 http://liss014:6001/im/viewissue?selection=13131
  CHANGE:           Revision 1.13 2008/03/25 09:45:46CET jspruck 
  CHANGE:           Use the calibration flag, to switch of learn values wld, ssg and dyn yaw offset
  CHANGE:           --- Added comments ---  jspruck [2008/03/25 08:45:46Z]
  CHANGE:           Change Package : 11024:1 http://liss014:6001/im/viewissue?selection=11024
  CHANGE:           Revision 1.12 2008/03/14 08:35:36CET jspruck 
  CHANGE:           Put the aquaplaning and slip flag to the internal data output stuct
  CHANGE:           --- Added comments ---  jspruck [2008/03/14 07:35:37Z]
  CHANGE:           Change Package : 10946:1 http://liss014:6001/im/viewissue?selection=10946
  CHANGE:           Revision 1.11 2007/11/06 08:59:32CET jspruck 
  CHANGE:           Use yaw rate for motion state detection and correct init of autocode
  CHANGE:           --- Added comments ---  jspruck [2007/11/06 07:59:32Z]
  CHANGE:           Change Package : 4326:1 http://liss014:6001/im/viewissue?selection=4326
  CHANGE:           Revision 1.10 2007/08/23 17:51:06CEST jspruck 
  CHANGE:           Add wheel load dep
  CHANGE:           --- Added comments ---  jspruck [2007/08/23 15:51:06Z]
  CHANGE:           Change Package : 4201:1 http://liss014:6001/im/viewissue?selection=4201
  CHANGE:           Revision 1.9 2007/06/21 16:40:22CEST jspruck 
  CHANGE:            
  CHANGE:           --- Added comments ---  jspruck [2007/06/21 14:40:22Z]
  CHANGE:           Change Package : 3321:1 http://liss014:6001/im/viewissue?selection=3321
  CHANGE:           Revision 1.8 2007/06/01 16:03:57CEST jspruck 
  CHANGE:            
  CHANGE:           --- Added comments ---  jspruck [2007/06/01 14:03:57Z]
  CHANGE:           Change Package : 2941:1 http://liss014:6001/im/viewissue?selection=2941
  CHANGE:           Revision 1.7 2007/04/03 15:04:28CEST jspruck 
  CHANGE:           Variance Q11 added to internal struct
  CHANGE:           --- Added comments ---  jspruck [2007/04/03 13:04:29Z]
  CHANGE:           Change Package : 1230:1 http://liss014:6001/im/viewissue?selection=1230
  CHANGE:           Revision 1.6 2007/03/23 15:19:00CET jspruck 
  CHANGE:           Include intenal states of the motion state
  CHANGE:           --- Added comments ---  jspruck [2007/03/23 14:19:00Z]
  CHANGE:           Change Package : 1230:1 http://liss014:6001/im/viewissue?selection=1230
  CHANGE:           Revision 1.5 2007/03/15 11:04:02CET jspruck 
  CHANGE:           Curve grad added
  CHANGE:           --- Added comments ---  jspruck [2007/03/15 10:04:02Z]
  CHANGE:           Change Package : 1230:1 http://liss014:6001/im/viewissue?selection=1230
  CHANGE:           Revision 1.4 2007/03/13 08:17:28CET jspruck 
  CHANGE:           Template change
  CHANGE:           --- Added comments ---  jspruck [2007/03/13 07:17:28Z]
  CHANGE:           Change Package : 1230:1 http://liss014:6001/im/viewissue?selection=1230

**************************************************************************** */

#ifndef RTW_HEADER_vdy_internal_types_h
#define RTW_HEADER_vdy_internal_types_h

#include "vdy_ext.h"
#include "vdy_cfg_ext.h"
#if (CFG_VDY_MFC)
#include "vdy_ver.h"		
#include "vdy_internal_ext.h"
#endif	

#ifndef DEFINED_TYPEDEF_FOR_vdy_wpp_out_t
/// Vehicle Wheels Speeds pre processing output structure
#define DEFINED_TYPEDEF_FOR_vdy_wpp_out_t

/// \brief Vehicle Wheels Speeds pre processing output structure
typedef struct
{
  float32 wheel_velo_front_left;		///< Front left wheel velocity
  float32 wheel_velo_front_left_var;	///< Front left wheel velocity variance
  float32 wheel_accel_front_left;       ///< Front left wheel accel
  float32 wheel_velo_front_right;		///< Front right wheel velociy 
  float32 wheel_velo_front_right_var;	///< Front right wheel velociy variance
  float32 wheel_accel_front_right;      ///< Front right wheel accel
  float32 wheel_velo_rear_left;			///< Rear left wheel velocity
  float32 wheel_velo_rear_left_var;		///< Rear left wheel velocity variance
  float32 wheel_accel_rear_left;        ///< Rear left wheel accel
  float32 wheel_velo_rear_right;		///< Rear right wheel velocity 
  float32 wheel_velo_rear_right_var;	///< Rear right wheel velocity variance
  float32 wheel_accel_rear_right;       ///< Rear right wheel accel
  uint8 aqua_slip_state_front_left;		///< Wheel Slip on water surface - Front Left
  uint8 aqua_slip_state_front_right;	///< Wheel Slip on water surface - Front Right
  uint8 aqua_slip_state_rear_left;		///< Wheel Slip on water surface - Rear Left
  uint8 aqua_slip_state_rear_right;		///< Wheel Slip on water surface - Rear Right
} vdy_wpp_out_t;
#endif

#ifndef DEFINED_TYPEDEF_FOR_vdy_ve_out_t
#define DEFINED_TYPEDEF_FOR_vdy_ve_out_t ///< Vehicle Velocity Estimation Output Structure

/// \brief Vehicle Velocity Estimation Output Structure
typedef struct
{
  float32 veh_velo;			///< Vehicle Velocity
  float32 veh_velo_var;		///< Vehicle Velocity Variance
  float32 veh_accel;		///< Vehicle Acceleration
  float32 veh_accel_var;	///< Vehicle Acceleration Variance
  uint8 traction;           ///< Vehicle traction detection bit

} vdy_ve_out_t;
#endif

#ifndef DEFINED_TYPEDEF_FOR_vdy_wye_out_t
/// Wheel speeds Yaw rate estimation output struct
#define DEFINED_TYPEDEF_FOR_vdy_wye_out_t

/// \brief Wheel speeds Yaw rate estimation output struct
typedef struct
{
  float32 whl_yaw_rate;					///< Wheel speeds yaw rate
  float32 whl_yaw_rate_var;				///< Wheel speeds yaw rate variance
  float32 gier_yaw_rate_offset;			///< Yaw rate offset
  float32 gier_yaw_rate_offset_var;		///< Yaw rate offset offset
  float32 front_whl_yaw_rate_filt;		///< Filtered wheel speeds yaw rate - Front
  float32 front_whl_yaw_rate_filt_wld;	///< Filtered wheel speeds yaw rate with wheel load departure - Front
  float32 rear_whl_yaw_rate_filt;		///< Filtered wheel speeds yaw rate - Rear
  float32 rear_whl_yaw_rate_filt_wld;	///< Filtered wheel speeds yaw rate with wheel load departure - Rear
  float32 diff_whl_yaw_front_rear;		///< Wheel speeds yaw rate difference - front and rear
  float32 est_whl_load_dep_front;		///< estimated wheel load departure - front
  float32 raw_est_yaw_offset;			///< estimated raw yaw rate offset
  uint8 dyn_yaw_off_control;			///< dynamic yaw rate offset control bit
  uint8 wld_control;					///< wheel load departure control bit
  uint8 r_On_Off_control;				///< R matrix control bit
} vdy_wye_out_t;
#endif

#ifndef DEFINED_TYPEDEF_FOR_vdy_gye_out_t
/// Gier yaw rate estimation output structure
#define DEFINED_TYPEDEF_FOR_vdy_gye_out_t

/// \brief Gier yaw rate estimation output structure
typedef struct
{
  float32 gier_yaw_rate;		///< Gier yaw rate
  float32 gier_yaw_rate_var;	///< Gier yaw rate variance
  boolean r_On_Off_control;		///< R matrix control bit
} vdy_gye_out_t;
#endif

#ifndef DEFINED_TYPEDEF_FOR_vdy_gye_out_filt_t
/// Filtered gier yaw rate estimation output struct
#define DEFINED_TYPEDEF_FOR_vdy_gye_out_filt_t

/// \brief Filtered gier yaw rate estimation output struct
typedef struct
{
  float32 gier_yaw_rate;			///< Gier yaw rate
  float32 gier_yaw_rate_var;		///< Gier yaw rate variance
  float32 raw_est_yaw_offset_filt;	///< filterd yaw rate offset
} vdy_gye_out_filt_t; 
#endif

#ifndef DEFINED_TYPEDEF_FOR_vdy_aye_out_t
/// Lateral acceleration yaw rate estimation output structure
#define DEFINED_TYPEDEF_FOR_vdy_aye_out_t

/// \brief Lateral acceleration yaw rate estimation output structure
typedef struct
{
  float32 ay_yaw_rate;		///< internal lateral accel yaw rate
  float32 ay_yaw_rate_var;	///< internal lateral accel yaw rate variance
  float32 track_bent;		///< Track bent
  float32 track_bent_var;	///< Track bent variance 
  uint8 r_On_Off_control;	///< R matrix control bit
  uint8 BankRoad;			///< Bank Road Detection
} vdy_aye_out_t;
#endif

#ifndef DEFINED_TYPEDEF_FOR_vdy_sye_out_t
/// Steering wheel angle yaw rate estimation output structure
#define DEFINED_TYPEDEF_FOR_vdy_sye_out_t

/// \brief Steering wheel angle yaw rate estimation output structure
typedef struct
{
  float32 stw_yaw_rate;				///< estimated internal steering wheel angle yaw rate
  float32 stw_yaw_rate_var;			///< internal steering wheel angle yaw rate variance
  float32 stw_yaw_rate_offset;		///< internal steering wheel angle yaw rate offset
  float32 stw_yaw_rate_offset_var;	///< internal steering wheel angle yaw rate offset variance
  float32 stw_curve;				///< steering wheel angle curvature
  float32 stw_curve_var;			///< steering wheel angle curvature variance
  float32 stw_curve_grad;			///< steering wheel angle curvature gradient
  float32 stw_curve_grad_var;		///<  steering wheel angle curvature gradient variance
  float32 stw_understeer_grad;		///< internal steering wheel angle under steering gradient
  float32 stw_understeer_grad_disc; ///< discrete estimated self steering wheel angle gradient output
  float32 stw_understeer_grad_var;	///< discrete estimated self steering wheel angle gradient output variance
  float32 stw_understeer_grad_max;	///< max discrete estimated self steering wheel angle gradient output
  float32 stw_understeer_grad_min;	///< min discrete estimated self steering wheel angle gradient output
  uint8 stw_understeer_control;		///< steering wheel angle yaw rate estimation control bit
  uint8 r_On_Off_control;			///< R matrix control bit
} vdy_sye_out_t;
#endif


#ifndef DEFINED_TYPEDEF_FOR_vdy_ye_out_t
/// Vehicle yaw rate estimation output structure
#define DEFINED_TYPEDEF_FOR_vdy_ye_out_t

/// \brief Vehicle yaw rate estimation output structure
typedef struct
{
  float32 veh_yaw_rate;				///< estimated vehicle yaw rate 
  float32 veh_yaw_rate_var;			///< estimated vehicle yaw rate variance
  float32 veh_wye_rate_usage;		///< estimated vehicle wheel speeds yaw rate 
  float32 veh_gye_rate_usage;		///< estimated gier yaw rate
  float32 veh_aye_rate_usage;		///< estimated lateral acceleration yaw rate
  float32 veh_sye_rate_usage;		///< estimated steering wheel angle yaw rate 
  float32 veh_merge_curve;			///< estimated merged(mean) curvatures - yaw rate and SWA
  float32 veh_merge_curve_var;		///< estimated merged(mean) curvatures variance
  float32 veh_merge_curve_grad;		///< estimated merged(mean) curvatures gradient
  float32 veh_merge_curve_grad_var; ///< estimated merged(mean) curvatures gradient variance
  float32 veh_merge_curve_Q11;		///< estimated merged(mean) curvatures Q11
  float32 veh_lat_accel;			///< estimated vehicle lateral acceleration 
  float32 veh_yaw_rate_var_org;		///< yaw rate variance - Reserved
  float32 veh_yaw_angle;            ///< yaw angle
} vdy_ye_out_t;
#endif


#ifndef DEFINED_TYPEDEF_FOR_vdy_sae_out_t
/// Side slip angle estmation output structure
#define DEFINED_TYPEDEF_FOR_vdy_sae_out_t 

/// \brief Side slip angle estmation output structure
typedef struct
{
  float32 est_slip_angle;		///< estimated side slip angle
  float32 est_slip_angle_var;	///< estimated side slip angle variance
  float32 raw_slip_angle;		///< raw side slip angle signal
} vdy_sae_out_t;
#endif

#ifndef DEFINED_TYPEDEF_FOR_vdy_mot_st_out_t
/// Motion State Estimation output structure
#define DEFINED_TYPEDEF_FOR_vdy_mot_st_out_t

/// \brief Motion State Estimation output structure
typedef struct
{
  uint8 fwd;			///< Forward
  uint8 ss;				///< Satndstill
  uint8 rvs;			///< Reverse
  uint8 mot_state;		///< State
  uint8 mot_quality;	///< Quality
  sint8 mot_counter;	///< Counter	
} vdy_mot_st_out_t;
#endif


#ifndef DEFINED_TYPEDEF_FOR_vdy_yaw_offset_t
/// Gier Yaw Rate Offset Structure
#define DEFINED_TYPEDEF_FOR_vdy_yaw_offset_t

/// \brief Gier Yaw Rate Offset Structure
typedef struct
{
  float32 offset;	///< Offset 
  float32 var;		///< Variance
  float32 quality;	///< Quality
  uint8 state;		///< State
} vdy_yaw_offset_t;
#endif


#ifndef DEFINED_TYPEDEF_FOR_vdy_swa_offset_t
/// SWA offset structure
#define DEFINED_TYPEDEF_FOR_vdy_swa_offset_t 

/// \brief SWA offset structure
typedef struct
{
  float32 offset;	///< Offset
  float32 var;		///< Varianve
  uint8 state;		///< State
} vdy_swa_offset_t;
#endif

#ifndef DEFINED_TYPEDEF_FOR_vdy_whs_offset_t
/// Wheel Speeds offset structure
#define DEFINED_TYPEDEF_FOR_vdy_whs_offset_t

/// \brief Wheel Speeds offset structure
typedef struct
{ 
  float32 offset_ratio_front;		///< Offset ratio front
  float32 offset_ratio_front_dev;	///< Offset ratio front standard deviation
  float32 offset_ratio_rear;		///< Offset ratio rear
  float32 offset_ratio_rear_dev;	///< Offset ratio rear standard deviation
  sint32  SpeedRange;				///< Speed range
} vdy_whs_offset_t;
#endif


#ifndef DEFINED_TYPEDEF_FOR_vdy_offsets_in_t
/// Offsets - Gier yaw rate, SWA, Wheel speeds and lateral acceration
#define DEFINED_TYPEDEF_FOR_vdy_offsets_in_t

/// \brief Offsets - Gier yaw rate, SWA, Wheel speeds and lateral acceration
typedef struct
{
  vdy_yaw_offset_t vdy_yaw_offset;		///< Gier yaw rate offset
  vdy_swa_offset_t vdy_swa_offset;		///< SWA offset
  vdy_whs_offset_t vdy_whs_offset;		///< Wheel speeds offset
  vdy_swa_offset_t vdy_ay_offset;		///< Lateral acceleration offset
} vdy_offsets_in_t;
#endif

#ifndef DEFINED_TYPEDEF_FOR_vdy_velcor_t
/// VDY Vehicle velocity correction data type
#define DEFINED_TYPEDEF_FOR_vdy_velcor_t

/// \brief VDY Vehicle velocity correction data type
typedef struct
{
  fVelocity_t            VehVelocityCorr;	///< Velocity Correction Variable
  fRatio_t               VelCorrFact;		///< Velocity Correction Factor
  fVelocity_t            VehVelo;			///< Vehicle Velocity
  fVariance_t            VehVeloVar;		///< Vehicle Velocity Variance
  fVelocity_t            corrVar;			///< Correction Variance
  fVelocity_t            corrVeloVar;		///< Corrected Velocity Variance
} vdy_velcor_t;
#endif

#ifndef DEFINED_TYPEDEF_FOR_VDYInternalData_t
/// VDY Internal Data Types
#define DEFINED_TYPEDEF_FOR_VDYInternalData_t

/// \brief VDY Internal Data Types
typedef struct
{
  vdy_wpp_out_t vdy_wpp_out;			///< Vehicle Wheels Speeds pre processing output 
  vdy_ve_out_t vdy_ve_out;				///< Vehicle Velocity Estimation
  vdy_wye_out_t vdy_wye_out;			///< Wheel speeds Yaw rate estimation
  vdy_gye_out_t vdy_gye_out;			///< Gier yaw rate estimation
  vdy_gye_out_filt_t vdy_gye_out_filt;	///< Filtered gier yaw rate estimation
  vdy_aye_out_t vdy_aye_out;			///< lateral acceleration yaw rate estimation
  vdy_sye_out_t vdy_sye_out;			///< steering wheel angle yaw rate estimation
  vdy_ye_out_t vdy_ye_out;				///< vehicle yaw rate estimation
  vdy_sae_out_t vdy_sae_out;			///< side slip angle estmation
  vdy_mot_st_out_t vdy_mot_st_out;		///< Motion State Estimation
  vdy_offsets_in_t vdy_offsets_in;		///< Offsets - Gier yaw rate, SWA, Wheel speeds and lateral acceration
  vdy_velcor_t vdy_velcor;				///< Velocity Correction
} VDYInternalData_t;
#endif



#ifndef DEFINED_TYPEDEF_FOR_vdy_mot_states_t
/// Motion State structure
#define DEFINED_TYPEDEF_FOR_vdy_mot_states_t

/// \brief Motion State structure
typedef struct
{
  percentage_t fwd;		///< Forward
  percentage_t ss;		///< Standstill
  percentage_t rvs;		///< Reverse
} vdy_mot_states_t;
#endif


#ifndef DEFINED_TYPEDEF_FOR_vdy_whl_puls_mot_st_t
/// Individual Wheel pulse counter - motion state
#define DEFINED_TYPEDEF_FOR_vdy_whl_puls_mot_st_t

/// \brief Individual Wheel pulse counter - motion state
typedef struct
{
  vdy_mot_states_t front_left;		///< Front Left
  vdy_mot_states_t front_right;		///< Front Right
  vdy_mot_states_t rear_left;		///< Front Left
  vdy_mot_states_t rear_right;		///< Front Right
} vdy_whl_puls_mot_st_t;
#endif


#ifndef DEFINED_TYPEDEF_FOR_vdy_whl_dir_mot_st_t
/// Individual Wheel direction
#define DEFINED_TYPEDEF_FOR_vdy_whl_dir_mot_st_t

/// \brief Individual Wheel direction
typedef struct
{
  vdy_mot_states_t front_left;		///< Front Left
  vdy_mot_states_t front_right;		///< Front Right
  vdy_mot_states_t rear_left;		///< Front Left
  vdy_mot_states_t rear_right;		///< Front Right
} vdy_whl_dir_mot_st_t;
#endif


#ifndef DEFINED_TYPEDEF_FOR_vdy_input_mot_st_t
/// Motion State input signals states
#define DEFINED_TYPEDEF_FOR_vdy_input_mot_st_t

/// \brief Motion State input signals states
typedef struct
{
  vdy_whl_puls_mot_st_t whl_puls_states;	///< Individual Wheel pulse counter - motion state
  vdy_mot_states_t veh_velocity_state;		///< Vehicle velocity State
  vdy_whl_dir_mot_st_t whl_dir_states;		///< Individual Wheel direction StateS
  vdy_mot_states_t brake_torque_state;		///< Brake Torque State
  vdy_mot_states_t gear_shift_state;		///< Gear Shift Position State
  vdy_mot_states_t park_brake_state;		///< Park Brake State
  vdy_mot_states_t yaw_rate_state;			///< Yaw Rate State
  vdy_mot_states_t ALN_dir_states;			///< ALN direction State
} vdy_input_mot_st_t;
#endif


#ifndef DEFINED_TYPEDEF_FOR_vdy_bayes_out_mot_states_t
/// Motion State after Bayes application
#define DEFINED_TYPEDEF_FOR_vdy_bayes_out_mot_states_t

/// \brief Motion State after Bayes application
typedef struct
{
  vdy_mot_states_t stage_1;	///< Stage_1 Motion State
  vdy_mot_states_t stage_2;	///< Stage_2 Motion State
  vdy_mot_states_t stage_3;	///< Stage_3 Motion State
  vdy_mot_states_t stage_4;	///< Stage_4 Motion State
  vdy_mot_states_t stage_5;	///< Stage_5 Motion State
 } vdy_bayes_out_mot_states_t; 
#endif


#ifndef DEFINED_TYPEDEF_FOR_vdy_bayes_mot_states_t
/// Motion State Estimation Structure after Bayes application
#define DEFINED_TYPEDEF_FOR_vdy_bayes_mot_states_t

/// \brief Motion State Estimation Structure after Bayes application
typedef struct
{
  vdy_input_mot_st_t mot_st_bayes_in;			///< Motion State input signals states
  vdy_bayes_out_mot_states_t mot_st_bayes_out;	///< Motion State after Bayes application
  vdy_mot_st_out_t mot_st_out;					///< Motion State Estimation
} vdy_bayes_mot_states_t;
#endif


#endif

/** @} */ 
/* EOF */
