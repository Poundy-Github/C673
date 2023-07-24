/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/KMC (Adaptive Cruise Control - Longitudinal Planner and Controller - Kinematic Motion Control)

PACKAGENAME:               kmc_alat.c

DESCRIPTION:               This file contains functions concerning limitation of lateral acceleration

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.15 $

LEGACY VERSION:            Revision: 1.11.1.2

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   kmc_alat Kmc_alat
@ingroup    kmc
@brief      KMC lateral acceleration limitation functions
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "kmc.h"

#if ((FCT_CFG_LOPC_COMPONENT) && (FCT_CFG_CC) && (LOPC_CFG_KMC))

/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/
#define Cc_lat_accel_grad_filter (4)

/*************************************************************************************************************************
  Functionname:         KMC_v_LimitLateralAccel                                                                      */ /*!

  @brief                Limit the longitudinal acceleration so that the lateral
                        acceleration is acceptable for the driven speed

  @description          Limitation of longitudinal acceleration based on lateral acceleration
    @startuml
    Start
      Partition KMC_v_LimitLateralAccel {
        : Determine current lateral acceleration;
        : Deermine gradient between the last\n and current lateral acceleration;
        : Determine the filter constant based on the\n gradient and filter the current lateral acceleration;
        : Determine Maximum allowed lateral acceleration\n based on current ego speed and a lookup table;
        : Calculate max allowed longitudinal acceleration based on difference of 
         current lateral acceleration to maximum allowed lateral acceleration;
        : Max allowed longitudinal acceleration can be increased when in object follow mode;
        : Set boolean, whether "limiter" due to lateral\n acceleration is active (**LAT_ACCEL_LIM_ACTIVE**);
      }
    End
    @enduml

  @return               -

  @param[in]            cycle_time : cycle time of FCT_VEH cycle [0u ... 1000u] ms
  @param[in]            input : Pointer to CC input interface [cc_input_data_t as per cc_ext.h]
                          LATERAL_ACCELERATION : Lateral acceleration of vehicle [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
  @param[in]            acc_output : Pointer to acc_output_data_t structure containing acc output from FCT SEN to FCT VEH
                          DISTANCE_CTRL_ACCEL_MAX : Maximum acceleration for intrusion distance [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
  @param[in]            das_input : Pointer to input from longitudinal dynamics management to driver assistance system [cart_das_input_data_t as per cart_ext.h]
                          VEHICLE_SPEED : Ego speed with factor Velocity_s [-30000u ... 30000u] cm/s
  @param[in,out]        *cc_status : Pointer to Cruisecontrol status [cc_status_t as per cc_ext.h]
                          CC_LAT_ACCEL_LAST_CYCLE : Lateral acceleration of last cycle [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                          CC_LAT_ACCEL_GRAD_LAST_CYCLE : Lateral acceleration gradient of last cycle [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                          CC_CONTROL_DATA.CC_ACCELERATION : CruiseControl acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                          CC_ACCEL_CONTROL_DATA.MAXIMUM_ACCELERATION_LATERAL_LIMITED : Maximum longitudinal acceleration limited due to lateral acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                          CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.LAT_ACCEL_LIM_ACTIVE : Boolean indicating whether limiter due to lateral acceleration is active [TRUE, FALSE]

  @glob_in              -
  @glob_out             -

  @c_switch_part        @ref FCT_CFG_ACC_HEADWAY_PLANNER \n
  @c_switch_full        @ref FCT_CFG_LOPC_COMPONENT  \n
  @c_switch_full        @ref FCT_CFG_CC  \n
  @c_switch_full        @ref LOPC_CFG_KMC  \n

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @traceability         doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-146-0008a220
        
*************************************************************************************************************************/
void KMC_v_LimitLateralAccel(const times_t cycle_time, const cc_input_data_t* input, const acc_output_data_t* acc_output, const cart_das_input_data_t* das_input, cc_status_t *cc_status)
{
  velocity_t vehicle_speed;
  acceleration_t lat_accel;
  acceleration_t lat_accel_max;
#if (KMC_INC_LAT_LIMITS_IN_FOLLOW)
  acceleration_t delta_acceleration_request;
#endif
  times_t alat_filter_time;
  gradient_t lat_accel_grad;

  vehicle_speed = das_input->VEHICLE_SPEED;
  lat_accel = (acceleration_t) MAT_ABS((sint32)input->LATERAL_ACCELERATION);

  lat_accel_grad = MAT_DIV( ((sint32)lat_accel - cc_status->CC_LAT_ACCEL_LAST_CYCLE), (sint32)cycle_time, Scale_1, Scale_1, Scale_1 );
  lat_accel_grad = MAT_FILT(lat_accel_grad, cc_status->CC_LAT_ACCEL_GRAD_LAST_CYCLE, (sint32)Cc_lat_accel_grad_filter);

  /* Filter LateralAcceleration */
  if (lat_accel_grad < (gradient_t)0)
  {
    /* coming out of a curve: slow filter */
    alat_filter_time = Cc_neg_lateral_accel_filter_time;
  }
  else
  {
    /* going into a curve, being in a curve: fast filter */
    alat_filter_time = Cc_pos_lateral_accel_filter_time;
  }

  lat_accel = (acceleration_t)MAT_FILT((sint32)lat_accel, (sint32)cc_status->CC_LAT_ACCEL_LAST_CYCLE, (sint32)alat_filter_time / cycle_time);

  /* Proposal 1
     V veh / A lat table -> A lat max
     (A lat max - A lat host) -> A long max
  */
  lat_accel_max = MAT_CALCULATE_PARAM_VALUE1D(Cc_alat_speed_curve, (uint16)Cc_alat_speed_curve_points, (sint16)MAT_ABS((sint32)vehicle_speed));
  
#if (KMC_CFG_CUSTOM_LAT_LIM)
  /* Arbitration of lateral acceleration limitation with custom calculated value */
  cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_ACCELERATION_LATERAL_LIMITED = (acceleration_t)MAT_MIN( cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_ACCELERATION_LATERAL_LIMITED_CUSTOM,
                              MAT_CALCULATE_PARAM_VALUE1D(Cc_long_accel_curve, (uint16)Cc_long_accel_curve_points, (sint16)(lat_accel_max - lat_accel)));
#else
  cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_ACCELERATION_LATERAL_LIMITED =
    MAT_CALCULATE_PARAM_VALUE1D(Cc_long_accel_curve, (uint16)Cc_long_accel_curve_points, (sint16)(lat_accel_max - lat_accel));
#endif  /* KMC_CFG_CUSTOM_LAT_LIM */

#if (KMC_INC_LAT_LIMITS_IN_FOLLOW)
  /* Reduce lateral limitation in follow for positive distance control output above threshold velocity */
  if((acc_output->DISTANCE_CTRL_ACCEL_MIN > cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_ACCELERATION_LATERAL_LIMITED)
      &&
      (acc_output->DISTANCE_CTRL_ACCEL_MIN > (acceleration_t)0)
      &&
      (acc_output->DISTANCE_CTRL_ACCEL_MIN <= acc_output->MAX_ACC_ACCELERATION)
      &&
      (vehicle_speed > Cc_alat_followmode_min_speed)
    )
  {
    delta_acceleration_request = acc_output->DISTANCE_CTRL_ACCEL_MIN - cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_ACCELERATION_LATERAL_LIMITED;
    delta_acceleration_request = (acceleration_t)MAT_MUL((sint32)delta_acceleration_request,(sint32)Cc_alat_followmode_accel_inc_fac,
                                                          Acceleration_s,Factor_s,Acceleration_s);
    cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_ACCELERATION_LATERAL_LIMITED += delta_acceleration_request;
  }
#endif /* KMC_INC_LAT_LIMITS_IN_FOLLOW */

  /* Lateral acceleration limiter shall be activated if predicted lateral acceleration exceeds a calibratable threshold */
  /* and if the output of the longitudinal curve control is smaller than the calculated CC and the ACC accelerations */
  if (   (  /* 1e-3 [m/s^2], 0x8000 ... 0x7FFF */
            lat_accel
          > /* 1e-3 [m/s^2], 0x8000 ... 0x7FFF */
            Cc_alat_speed_curve[(( 2 * Cc_alat_speed_curve_points ) - 1 )]
         )
      && (  /* 1e-3 [m/s^2], 0x8000 ... 0x7FFF */
            cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_ACCELERATION_LATERAL_LIMITED
          < /* 1e-3 [m/s^2], 0x8000 ... 0x7FFF */
            cc_status->CC_CONTROL_DATA.CC_ACCELERATION
         )
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
      && (  /* 1e-3 [m/s^2], 0x8000 ... 0x7FFF */
            cc_status->CC_ACCEL_CONTROL_DATA.MAXIMUM_ACCELERATION_LATERAL_LIMITED
          < /* 1e-3 [m/s^2], 0x8000 ... 0x7FFF */
            acc_output->DISTANCE_CTRL_ACCEL_MAX
         )
#endif
     )
  {
    cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.LAT_ACCEL_LIM_ACTIVE = TRUE;
  }
  else
  {
    cc_status->CC_ACCEL_CONTROL_DATA.ACCEL_STATUS.LAT_ACCEL_LIM_ACTIVE = FALSE;
  }

  cc_status->CC_LAT_ACCEL_LAST_CYCLE = lat_accel;
  cc_status->CC_LAT_ACCEL_GRAD_LAST_CYCLE = lat_accel_grad;
}

#endif  /* (FCT_CFG_LOPC_COMPONENT) && (FCT_CFG_CC) && (LOPC_CFG_KMC) */

/** @} end defgroup */
