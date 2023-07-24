/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp_customfunctions.c

DESCRIPTION:               File containing custom functions for HP in LOHP

AUTHOR:                    Liting Lu (uid40501)

CREATION DATE:             17.07.2017

VERSION:                   $Revision: 1.21.1.1 $

LEGACY VERSION:            Revision: 1.4

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hp.h"
#include "hp_custom.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup       hp_customfunctions Hp_Customfunctions
@ingroup        hp_custom
@brief          File containing customer specific functions for ACC HP module.
@{
*/
/*****************************************************************************
  MODULE GLOBAL TYPEDEFS
*****************************************************************************/
typedef struct  
{
  float32 f_HystOut;
  float32 f_DistError;
} t_OOILongAccelFilterVars;

/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULE GLOBAL VARIABLES
*****************************************************************************/
#if (CFG_FCT_ACC_PARAMS_DEBUG)
static acc_params_t Acc_Params;/*PRQA S 3218  */
/* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/
#endif

static acceleration_t OOI_0_lastaccel = 0;  // PRQA S 3218
static t_OOILongAccelFilterVars OOILongAccelFilterVars[Acc_max_number_ooi]; // PRQA S 3218


/*****************************************************************************
  MODULE FUNCTIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    HP_v_EgoDataWapper                                                                               */ /*!

  @brief           Wrapper for ego vehicle dynamics data

  @description     Wrapper for ego vehicle dynamics data based on custom requirements

                    @startuml
                        Start
                            Partition HP_v_EgoDataWapper {
                                : Wrapper for ego vehicle dynamics data based on custom requirements;
                            }
                        End
                    @enduml

  @return          -

  @param[in]       pVehDyn : the vehicle dynamic data from VDY
                    Longitudinal.Accel : vehicle longitudinal acceleration in m/s2. Range: [-10...10u]
                    Longitudinal.Velocity: vehicle longitudinal velocity in m/s. Range: [-300...300u]
  @param[in]       pFctVehLongOut : the vehicle dynamic data from LoPC 
                    CurLongCtrlAccel : the current logitudinal control acceleration in m/s2 multiplied with factor Acceleration_s. Range: [-10000...10000u]
                    CurLongCtrlVelocity : the current logitudinal control velocity in m/s multiplied with factor Velocity_s. Range: [-30000...30000u]
  @param[in,out]   acc_input_data_ptr : ACC input data
                    LONG_VELOCITY : the longitudinal velocity in m/s multiplied with factor Velocity_s. Range: [-30000...30000u]
                    LONG_ACCELERATION : the longitudinal acceleration in m/s2 multiplied with factor Acceleration_s. Range: [-10000...10000u]

  @glob_in         -
  @glob_out        -

  @c_switch_part   CFG_FCT_USE_VDY_HOST_ACCEL : Use host accel from VDY, otherwise aInit will be used for velocity prediction
  @c_switch_part   CFG_FCT_USE_VDY_HOST_VELOCITY : Use velocity of VDY component
  @c_switch_part   VDY_VEH_DYN_INTFVER : Vehicle dynamic interface version
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : FCT switch for LOHP Component for ACC
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : FCT support for ACC HP (Headway Planner) sub-component. Needed for ACT reaction to objects

  @pre             -
  @post            -

  @created         17.07.2017
  @changed         17.07.2017

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-99-0008a201

  @author          Liting Lu | liting.lu@continental-corporation.com | +49 (8382) 9699-5209
*************************************************************************************************************************/
void HP_v_EgoDataWapper(const VehDyn_t* pVehDyn, const FctVeh2SenInfo_t* pFctVehLongOut, acc_input_data_t* acc_input_data_ptr)
{
  /*! Use this function to set the pointer to correct parameter variable, depending of customer specific modes */
#if (CFG_FCT_USE_VDY_HOST_ACCEL)
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  acc_input_data_ptr->LONG_ACCELERATION = (acceleration_t)MAT_LIM(ROUND_TO_INT(pVehDyn->Longitudinal.Accel * (float32)Acceleration_s), Accel_min, Accel_max);
#else
  acc_input_data_ptr->LONG_ACCELERATION = (acceleration_t)MAT_LIM(ROUND_TO_INT(pVehDyn->Longitudinal.MotVar.Accel * (float32)Acceleration_s), Accel_min, Accel_max);
#endif
#else
  acc_input_data_ptr->LONG_ACCELERATION   = pFctVehLongOut->CurLongCtrlAccel;
#endif

#if (CFG_FCT_USE_VDY_HOST_VELOCITY)
#if (VDY_VEH_DYN_INTFVER >= 0x20)   // 0x20 -> 18
  acc_input_data_ptr->LONG_VELOCITY = (velocity_t)MAT_LIM(ROUND_TO_INT(pVehDyn->Longitudinal.Velocity * (float32)Velocity_s), Velocity_min, Velocity_max);
#else
  acc_input_data_ptr->LONG_VELOCITY = (velocity_t)MAT_LIM(ROUND_TO_INT(pVehDyn->Longitudinal.VeloCorr.corrVelo * (float32)Velocity_s), Velocity_min, Velocity_max);
#endif
#else
  acc_input_data_ptr->LONG_VELOCITY       = pFctVehLongOut->CurLongCtrlVelocity;
#endif

#if(!( CFG_FCT_USE_VDY_HOST_ACCEL || CFG_FCT_USE_VDY_HOST_VELOCITY))
  _PARAM_UNUSED(pVehDyn);
#endif

#if( CFG_FCT_USE_VDY_HOST_ACCEL && CFG_FCT_USE_VDY_HOST_VELOCITY)
  /* pFctVehLongOut not used if CFG_FCT_USE_VDY_HOST_ACCEL is active*/
  _PARAM_UNUSED(pFctVehLongOut);
#endif
}


/*************************************************************************************************************************
  Functionname:    HP_v_ObjDataWapper                                                                               */ /*!

  @brief           Wrapper for object dynamics data

  @description     Wrapper for object dynamic data based on custom requirements

                    @startuml
                        Start
                        Partition HP_v_ObjDataWapper {
                            - Wrapper for object dynamic data based on custom requirements
                            - Object speed, acceleration and relevant speed read
                            - Values are filtered based on object acceleration and jerk
                        }
                        end
                    @enduml

  @return          -

  @param[in]       t_CopyObjInput : Input structure for copying the object input data
                     pOOIKinematics : Kinematic attributes of object from FctSenAccOOI port
                        fVabsX : the absolute velocity in x direction in m/s2. Range: [-10...10u]
                        fAabsX : the absolute acceleration in x direction in in m/s. Range: [-300...300u]
                        fVrelX : Relative velocity in x direction in m/s. Range: [-10...10u]

  @param[in]       u8_OOINr : Object OOI number [0,6]
  @param[out]      pDestObj : Local object struct where kinematic attributes are copied to [acc_object_t as per Rte_Type.h]

  @glob_in         EGO_SPEED_X_OBJ_SYNC: radar corrected speed from VDY synchronized to objects (EM takes corrected speed to fill MotVar.Velocity)
  @glob_out        -

  @c_switch_full   FCT_CFG_LOHP_COMPONENT : FCT switch for LOHP Component for ACC
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : FCT support for ACC HP (Headway Planner) sub-component. Needed for ACT reaction to objects

  @pre             -
  @post            -

  @created         17.07.2017
  @changed         10.03.2019

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-100-0008a201

  @author          Liting Lu | liting.lu@continental-corporation.com | +49 (8382) 9699-5209
*************************************************************************************************************************/
void HP_v_ObjDataWapper(const CopyObjInput_t t_CopyObjInput, acc_object_t * pDestObj, uint8 u8_OOINr)
{

  acceleration_t obj_accel, jerk;
  velocity_t obj_speed, obj_relspeed;
  factor_t Filter_const;

  /* Determine raw object speed */
  obj_speed = (velocity_t)MAT_LIM((sint32)(t_CopyObjInput.pOOIKinematics->fVabsX * (float32)Velocity_s),
                                    Velocity_min, Velocity_max );
  //obj_speed = (velocity_t)MAT_LIM((sint32)( t_CopyObjInput.pOOIKinematics->fVrelX * (float32)Velocity_s + t_CopyObjInput.pFctVehLongOut->CurLongCtrlVelocity ),
  //                                          Velocity_min, Velocity_max );

  /* Determine raw object acceleration */
  obj_accel = (acceleration_t)MAT_LIM((sint32)(t_CopyObjInput.pOOIKinematics->fAabsX * (float32)Acceleration_s),
                                      Accel_min, Accel_max);
  //obj_accel = (acceleration_t)MAT_LIM((sint32)(t_CopyObjInput.pOOIKinematics->fArelX * (float32)Acceleration_s + t_CopyObjInput.pFctVehLongOut->CurLongCtrlAccel),
  //                                              Accel_min, Accel_max);

  /* Determine raw object relative speed */
  obj_relspeed = (velocity_t)MAT_LIM((sint32)(t_CopyObjInput.pOOIKinematics->fVrelX * (float32)Velocity_s),
                                      Velocity_min, Velocity_max );
 

  /*! If relevant Object changes, filter unused and saved variables initialized */
  if(pDestObj->AUTOSAR.OBJECT_STATUS.NEW == FALSE)
  {
    if ( Hp_activate_hys_obj_accel == TRUE )
    { /* Hysteresis Filtering */
      float32 f_objaccel = (float32)obj_accel / (float32)Acceleration_s;
      /* hysteresis for object acceleration OA  >>>>>>>> >>>>>>>>  */
      MAT_HYST
      (
         t_CopyObjInput.cycle_time
       , f_objaccel
       , Obj_acc_hyst_factor
       , Obj_acc_hyst_nominator
       , Obj_acc_hyst_denominator
       , Obj_acc_hyst_antiwindup_error_limit 
       , &OOILongAccelFilterVars[u8_OOINr].f_DistError
       , &OOILongAccelFilterVars[u8_OOINr].f_HystOut
      );

      obj_accel = S16_S32( ROUND_TO_INT( OOILongAccelFilterVars[u8_OOINr].f_HystOut * ( float32 )Acceleration_s ));
    } 
    else
    { /* PT1 Filtering */
      /* Filtering Vrel when in specific object acceleration range */
      Filter_const = MAT_CALCULATE_PARAM_VALUE1D(Acc_obj_vrel_filter, Hp_obj_vrel_filter_points, (sint16)pDestObj->LONG_ACCEL);
      obj_relspeed = (acceleration_t)MAT_FILT((sint32)obj_relspeed, (sint32)pDestObj->AUTOSAR.REL_LONG_SPEED, 
                                              MAT_DIV((sint32)Filter_const, (sint32)t_CopyObjInput.cycle_time, Scale_1, Scale_1, Scale_1));
	    /* Calculate jerk-based obj accel filter factor for OOI-0 */
      if(u8_OOINr == Obj_first_host_lane)
      {
        jerk = (acceleration_t)MAT_ABS(MAT_DIFF_DT((sint32)obj_accel, (sint32)OOI_0_lastaccel, t_CopyObjInput.cycle_time));
        OOI_0_lastaccel = obj_accel;  /* Save current obj acceleration for usage in next cycle */
        Filter_const = MAT_CALCULATE_PARAM_VALUE1D(Acc_obj_jerk_fac, Hp_obj_jerk_fac_points, jerk);
      }
      else
      {
        Filter_const = Factor_s;
      }
      /* Filtering object acceleration with modified filter */
      Filter_const = (factor_t)MAT_MUL((sint32)MAT_CALCULATE_PARAM_VALUE1D(Acc_obj_accel_filter,Hp_obj_accel_filter_points, pDestObj->LONG_ACCEL),
                                        (sint32)Filter_const, Factor_s, Factor_s, Factor_s);
      obj_accel = (acceleration_t)MAT_FILT((sint32)obj_accel, (sint32)pDestObj->LONG_ACCEL, 
                                            MAT_DIV((sint32)Filter_const, (sint32)t_CopyObjInput.cycle_time, Scale_1, Scale_1, Scale_1));
    }

  }
  else  /* New object:- No filtering and resetting of static variables */
  {  
    if ( Hp_activate_hys_obj_accel == TRUE )
    {
      OOILongAccelFilterVars[u8_OOINr].f_DistError = 0.0f;
      OOILongAccelFilterVars[u8_OOINr].f_HystOut = 0.0f;
    }
    if(u8_OOINr == Obj_first_host_lane)
    {
      OOI_0_lastaccel = obj_accel;
    }  
  }

  /* Saving to internal object list */
  pDestObj->LONG_SPEED = obj_speed;
  pDestObj->LONG_ACCEL = obj_accel;
  pDestObj->AUTOSAR.REL_LONG_SPEED = obj_relspeed;

}

#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
/*************************************************************************************************************************
  Functionname:    HP_v_PlanOvertakeManoeuvreCustom                                                                 */ /*!

  @brief           Custom function to change overtake maneouvre if required

  @description     Custom function to change overtake maneouvre if required
					@startuml
					Start
						Partition HP_v_PlanOvertakeManoeuvreCustom {
						- Custom function to change overtake maneouvre if required
					}
					End
					@enduml

  @return          -

  @param[in]       acc_input : [acc_input_data_t as per hp_ext.h]
  @param[in]       object_list : [acc_object_t as as per Rte_Type.h]
  @param[in,out]   status : Pointer to HP Status Information struct [acc_status_t as per hp_ext.h]
  @param[in]       cycle_time : cycle time of FCT_VEH cycle [0u ... 1000u] ms

  @c_switch_part   -
  @c_switch_full   HP_CFG_OVERTAKE_SUPPORT_FEATURE : Switch for overtake feature activation
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : FCT switch for LOHP Component for ACC
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : FCT support for ACC HP (Headway Planner) sub-component. Needed for ACT reaction to objects

  @created         29.08.2017
  @changed         29.11.2018

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-101-0008a201

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void HP_v_PlanOvertakeManoeuvreCustom(const acc_input_data_t* acc_input, const acc_object_t object_list[Acc_max_number_ooi], acc_status_t* status, times_t cycle_time)
{
  _PARAM_UNUSED(acc_input);
  _PARAM_UNUSED(object_list);  
  _PARAM_UNUSED(status);
  _PARAM_UNUSED(cycle_time);
}
#endif /* HP_CFG_OVERTAKE_SUPPORT_FEATURE */

/*************************************************************************************************************************
  Functionname:    HP_v_SetMaxDecelCustom                                                                 */ /*!

  @brief           Custom function to limit reation to the next lane object using lanne change/Cutin/out probability 
                   and dynamics/kinametics of the object.

  @description     Custom function to change overtake maneouvre if required
					@startuml
					Start
						Partition HP_v_SetMaxDecelCustom {
						- Custom Calculation for Max Decel for OOI2,3,4&5
					}
					End
					@enduml

  @return          -

  @param[in]       acc_input : [acc_input_data_t as per hp_ext.h]
  @param[in]       driver_intention : Driver intention for ACC
  @param[in,out]   object_list : [acc_object_t as as per Rte_Type.h]
  @param[in]       status : Pointer to HP Status Information struct [acc_status_t as per hp_ext.h]
  @param[in]       cycle_time : cycle time of FCT_VEH cycle [0u ... 1000u] ms

  @c_switch_part   -
  @c_switch_full   
  @c_switch_full   
  @c_switch_full   

  @created         04.12.2020
  @changed         04.12.2020

  @traceability    

  @author          Ajay Talakadu | ajay.talakadu@continental-corporation.com | +91
*************************************************************************************************************************/

void HP_v_SetMaxDecelCustom(const acc_input_data_t* acc_input, acc_driver_intention_t* driver_intention, acc_object_t object_list[Acc_max_number_ooi], acc_status_t* status, times_t cycle_time)
{
  _PARAM_UNUSED(acc_input); 
  _PARAM_UNUSED(driver_intention);
  _PARAM_UNUSED(object_list);
  _PARAM_UNUSED(status); 
  _PARAM_UNUSED(cycle_time);
}

#if (CFG_FCT_ACC_PARAMS_DEBUG)

/*************************************************************************************************************************
  Functionname:    HP_v_FreezeACCParams                                                                             */ /*!

  @brief           Collecting and freezing acc parameter data

  @description     Parameters used in ACC logic that can be modified by test team are collected in a struct. This is
                   then frozen for debugging purposes.

                    @startuml
                        Start
                            Partition HP_v_FreezeACCParams {
                                - Collecting and freezing acc parameter data
                            } 
                        End
                    @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        Acc_Params: Struct to collect ACC parameter data

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : FCT switch for LOHP Component for ACC
  @c_switch_full   FCT_CFG_ACC_HEADWAY_PLANNER : FCT support for ACC HP (Headway Planner) sub-component. Needed for ACT reaction to objects
  @c_switch_full   CFG_FCT_ACC_PARAMS_DEBUG : Configuration switch enabling ACC paramereters are frozen for debugging

  @created         29.08.2017
  @changed         29.08.2017

  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-107-0008a201

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void HP_v_FreezeACCParams(void)
{
  uint8 u_Counter;

  /* Storage of acc parameter values for debugging */
  for (u_Counter=0; u_Counter<15; u_Counter++)
  {
    if (2*Acc_fsr_max_acceleration_points > u_Counter)
    {
      Acc_Params.ACC_FSR_MAX_ACCEL_DEFAULT[u_Counter] = Acc_fsr_max_acceleration[u_Counter];
    }
    if (2*Acc_fsr_max_deceleration_points > u_Counter)
    {
      Acc_Params.ACC_FSR_MAX_DECEL[u_Counter] = Acc_fsr_max_deceleration[u_Counter];
    }
    if (2*Acc_headway_min_dist_points > u_Counter)
    {
      Acc_Params.ACC_HEADWAY_MIN_DIST_DEFAULT[u_Counter] = ACC_pHeadwayMinDist[u_Counter];
    }
    if (2*Acc_headway_max_dist_points > u_Counter)
    {
      Acc_Params.ACC_HEADWAY_MAX_DIST_DEFAULT[u_Counter] = ACC_pHeadwayMaxDist[u_Counter];
    }
    if (2*Acc_pos_grad_neg_accel_points > u_Counter)
    {
      Acc_Params.ACC_MAX_POS_GRAD_NEG_ACCEL[u_Counter] = Acc_max_pos_grad_neg_accel[u_Counter];
    }
    if (2*Acc_pos_grad_pos_accel_points > u_Counter)
    {
      Acc_Params.ACC_MAX_POS_GRAD_POS_ACCEL[u_Counter] = Acc_max_pos_grad_pos_accel[u_Counter];
    }
    if (2*Acc_neg_grad_points > u_Counter)
    {
      Acc_Params.ACC_MAX_NEG_GRAD[u_Counter] = Acc_max_neg_grad[u_Counter];
    }
    if (2*Acc_recommended_velocity_curve_points > u_Counter)
    {
      Acc_Params.ACC_RECOMMENDED_VELOCITY_CURVE[u_Counter] = Acc_recommended_velocity_curve[u_Counter];
    }
    if (2*Acc_min_to_max_intrusion_factor_points > u_Counter)
    {
      Acc_Params.ACC_MIN_TO_MAX_INTRUSION_FACTOR[u_Counter] = Acc_min_to_max_intrusion_factor[u_Counter];
    }
    if (2*Acc_max_intrusion_distance_points > u_Counter)
    {
      Acc_Params.ACC_MAX_INTRUSION_DISTANCE[u_Counter] = Acc_max_intrusion_distance[u_Counter];
    }
  } /* Loop End */

  /* Freezing of acc_params struct */
  (void)MeasFreeze_Lohp_StackVar(FCT_MEAS_ID_LOHP_ACC_PARAMS, (void*)&Acc_Params, sizeof(acc_params_t));
}
#endif /* CFG_FCT_ACC_PARAMS_DEBUG */

/** @} end defgroup */

#endif  /* ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER)) */
