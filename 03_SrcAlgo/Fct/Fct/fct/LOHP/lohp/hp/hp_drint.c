/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp_drint.c

DESCRIPTION:               This module contains all functions concerning the
                           driver intention during LOHP/HP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.36 $

LEGACY VERSION:            Revision: 1.17

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   hp_drint Hp_drint
@ingroup    hp
@brief      File contains functions concerning driver intention usage in HP
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hp.h"
#include "hp_par.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))

/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/
#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
#define HP_OTS_LC_PROB (uint8)120 /* High lane change probability defined for overtake support maneuvers */
#endif /* HP_CFG_OVERTAKE_SUPPORT_FEATURE */

/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/
#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
static times_t Timer_OOINextLane_LossCheck = (times_t)0;                  /* Timer to check loss of object in neighbouring lane *//*PRQA S 3218  */
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/
static uint8 u_OOI_LC_Cycle = (uint8)0;                                   /* Variable to store number of cycles that earlier OOI-0 is now in neighbouring lane *//*PRQA S 3218  */
/* date: 2018-04-18, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/
#endif /* HP_CFG_OVERTAKE_SUPPORT_FEATURE */

#define ROBUSTNESS_CHECK_TIMER_DURATION (times_t)2000 /*!< 2000 ms */
/*************************************************************************************************************************
  Functionname:         HP_v_EstimateDriverIntention                                                                 */ /*!

  @brief                Estimates the driver intention by using steering wheel curvature, turn signal...

  @description          Gather all the information from the driver that is needed for ACC. Driver intention to change
                        lanes is analyzed and used to provide support in case of overtake. State machine for overtake 
                        support feature is shown in second figure. In the first figure, the complete description of
                        the function is shown. Based on driver inputs, lane change probability, acc active state, 
                        deceleration limiter after override function for objects and object number for control in standstill
                        mode is set.

    @startuml
    Start
      Partition HP_v_EstimateDriverIntention {
      fork 
        : Overtake Support Feature;
      fork again
        Partition Analyse_Driver_Intention {
          If (Overtake support On) then (yes)
            : Lane change probability set to 120%;
          Else (no)
            : Lane change probability mapped\n based on driver input;
          Endif
          : ACC active state mapped;
          If (Override decel limiter has become active) then (yes)
            If (OOI-0 is tracked and\n has low absolute deceleration) then (yes)
              : ACC_LIMITER_ACTIVE set to 1;
            Else (no)
              : ACC_LIMITER_ACTIVE set to 0;
            Endif
          Else (no)
            : ACC_LIMITER_ACTIVE set to 0;
          Endif
          If (ACC_CONTROL_TO_FIRST_OBJECT == TRUE\nTrue if ego vehicle is in standstill mode) then (yes)
            If (OOI-0 distance is below standstill threshold) then (yes)
              : OOI-0 Object Id saved in\n OBJECT_NR_TO_CONTROL_TO;
            Else (no)
              : OBJECT_NR_TO_CONTROL_TO\n is initialised;
            Endif
          Else (no)
            : OBJECT_NR_TO_CONTROL_TO\n is initialised;
          Endif
        }
      endfork
      }
    End
    @enduml
    @startuml
    [*] --> OVERTAKE_SUPPORT_FEATURE

    state OVERTAKE_SUPPORT_FEATURE{
      [*] --> OVERTAKE_IDLE
      OVERTAKE_IDLE --> OVERTAKE_RUNNING : Activation conditions met
      OVERTAKE_IDLE --> OVERTAKE_DONE : OOI-0 has changed since time of setting of indicator
      OVERTAKE_IDLE --> OVERTAKE_DONE : ACC switched off
      OVERTAKE_RUNNING --> OVERTAKE_EXTENDED : Lane change phase confirmed by SLATE
      OVERTAKE_EXTENDED --> OVERTAKE_PASSBY : Previous OOI-0 becomes\n obj in adjacent lane\n for a minimum time
      OVERTAKE_PASSBY --> OVERTAKE_DONE : Phase time is over
      OVERTAKE_PASSBY --> OVERTAKE_DONE : ACC switched off
      OVERTAKE_DONE --> OVERTAKE_IDLE : Turn Indicator Off for min time\n and ACC is On
      OVERTAKE_RUNNING --> OVERTAKE_DONE : Phase time is over OR\n ego object is too close to OOI-0
      OVERTAKE_RUNNING --> OVERTAKE_PASSBY : Previous OOI-0 becomes\n obj in adjacent lane\n for a minimum time
      OVERTAKE_RUNNING --> OVERTAKE_DONE : ACC switched off
      OVERTAKE_EXTENDED --> OVERTAKE_DONE : ACC switched off
      OVERTAKE_EXTENDED --> OVERTAKE_DONE : Phase time is over OR\n ego object is too close to OOI-0

      OVERTAKE_IDLE : Following activation conditions are checked for :-
      OVERTAKE_IDLE : - Driver intention to change lane to faster lane
      OVERTAKE_IDLE : - OOI-0 exists and is tracked
      OVERTAKE_IDLE : - If an object is present in faster lane, acceleration\n required for it is higher than threshold or to OOI-0
      OVERTAKE_IDLE : - Else if object is not far/fast enough, it is tracked\n for certain time to ensure robustness against\n drop-out due to lane changes
      OVERTAKE_RUNNING : Phase timer is started on entry
      OVERTAKE_RUNNING : Overtake flag b_Overtake_Support_On is set.\nThis leads to reduction of desired distance to OOI-0
      OVERTAKE_RUNNING : Direction of lanechange/overtake is saved
      OVERTAKE_RUNNING : Object Id of OOI-0 is saved in local static variable
      OVERTAKE_EXTENDED : Phase timer is started on entry
      OVERTAKE_EXTENDED : OOI-0 desired distance is reduced even further
      OVERTAKE_PASSBY : Phase timer is started on entry
      OVERTAKE_PASSBY : OOI-0 desired distance no longer reduced
      OVERTAKE_PASSBY : Phase info sent to LOPC. Leads to\n increased CC acceleration and jerk limits
      OVERTAKE_DONE : Initialize all variables
      }
    @enduml

  @return               -

  @param[in]            cycle_time : cycle time of FCT_VEH cycle [0u ... 1000u] ms
  @param[in,out]        output : [acc_driver_intention_t as per hp_ext.h]
                          ACC_ENAGAGED : [switch_t as per switch_ext.h]
                          LANE_CHANGE_LEFT_PROBABILITY : [uint8 as per Rte_Type.h]
                          LANE_CHANGE_RIGHT_PROBABILITY : [uint8 as per Rte_Type.h]
                          DECEL_LIM_OVERRIDE.CC_LIMITER_ACTIVE : [true, false]
                          DECEL_LIM_OVERRIDE.ACC_LIMITER_ACTIVE : [true, false]
                          OBJECT_NR_TO_CONTROL_TO : [ObjNumber_t as per Rte_Type.h]
  @param[in]            object_list : [acc_object_t as as per Rte_Type.h]
                          REQUESTED_DISTANCE_MODIFIED_ACT : [distance_t as per Rte_Type.h]
                          AUTOSAR.LONG_DISPLACEMENT : [distance_t as per Rte_Type.h]
                          AUTOSAR.OBJECT_ID : [ObjNumber_t as per Rte_Type.h]
                          LAST_OBJECT_ID : [ObjNumber_t as per Rte_Type.h]
                          AUTOSAR.OBJECT_STATUS.DETECTED : [true, false]
                          AUTOSAR.OBJECT_STATUS.NEW : [true, false]
                          LONG_ACCEL_MODIFIED : [acceleration_t as per Rte_Type.h]
  @param[in]            input :[acc_input_data_t as per hp_ext.h]
                          INPUT_STATUS.ACC_ON : [true, false]
                          DRIVER_CONTROLS.P_LANE_CHANGE_LEFT : [percentage_t as per Rte_Type.h]
                          DRIVER_CONTROLS.P_LANE_CHANGE_RIGHT : [percentage_t as per Rte_Type.h]
                          INPUT_STATUS.CC_DECEL_LIM_OVERRIDE : [true, false]
                          CC_DECEL_LIMIT : [acceleration_t as per Rte_Type.h]
                          INPUT_STATUS.ACC_CONTROL_TO_FIRST_OBJECT : [true, false]
  @param[in,out]        status : Pointer to HP Status Information struct [acc_status_t as per hp_ext.h]
                          ACC_OVERTAKE_DATA.e_OTState            : Overtake support feature transition state [0,5; OTState_t_e as per hp_ext.h]
                          ACC_OVERTAKE_DATA.OOI_OTS_ObjId        : OOI-0 Obj Id used for OTS [-1, 255]
                          ACC_OVERTAKE_DATA.b_Overtake_Support_On: Boolean indicating that overtake support is active [0,1]
                          ACC_OVERTAKE_DATA.Timer_TGR            : Timer for running of time gap reduction phase  [0,65535u; times_t as per Rte_Type.h]
                          ACC_OVERTAKE_DATA.Timer_BP             : Timer for running of bypass phase [0,65535u; times_t as per Rte_Type.h]
                          ACC_OVERTAKE_DATA.s_LCModFactor        : Overtake maneuver alert modification factor [0, 1000]
                          ACC_OVERTAKE_DATA.e_OTDirection        : Overtake direction status [OTIntention_t_e as per hp_ext.h]
                          REQUESTED_DISTANCE_ACT                 : Actual object control distance WITHOUT modification [Full range of datatype distance_t as in Rte_type.h]

  @glob_in              -
  @glob_out             @ref Timer_OOINextLane_LossCheck \n
  @glob_out             @ref u_OOI_LC_Cycle \n

  @c_switch_part        @ref CFG_FCT_ACC_REACT_ON_STANDING_OBJECTS \n
  @c_switch_part        @ref HP_CFG_OVERTAKE_SUPPORT_FEATURE \n
  @c_switch_full        @ref FCT_CFG_LOHP_COMPONENT  \n
  @c_switch_full        @ref FCT_CFG_ACC_HEADWAY_PLANNER  \n

  @pre                  -
  @post                 output port is written with values.

  @InOutCorrelation     -

  @traceability         doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-94-0008a201

  @author               Niraj Mistry | Niraj.Mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void HP_v_EstimateDriverIntention(const times_t cycle_time, const acc_object_t object_list[Acc_max_number_ooi], const acc_input_data_t* input, acc_driver_intention_t* output, acc_status_t* status)
{

  /* -------------------------- Overtake maneouvre planning ----------------------*/
#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)

  /* local vars */
  acceleration_t t_ReqAccel_OOINext, t_ReqAccel_OOIZero, t_ReqAccel_Diff;
  distance_t MinDistToObj = (distance_t)0;
  boolean b_PassbyStart = FALSE;
  acc_object_t OOI_0 = ACC_NO_OBJECT;// PRQA S 1031 
  /* date: 2018-04-18, reviewer: Ravi Kiran Gurrala reason: Allowed in later versions of ISO C99*/
  acc_object_t OOI_NextLane = ACC_NO_OBJECT;// PRQA S 1031 
  /* date: 2018-04-18, reviewer: Ravi Kiran Gurrala reason: Allowed in later versions of ISO C99*/
  uint8 u_help = 0u;
  distance_t s16_brake_dist;
  distance_t s16_ots_deac_dist;

  OOI_0 = object_list[Obj_first_host_lane];// PRQA S 7004, 1031
  /* date: 2018-03-26, reviewer: Ravi Kiran Gurrala, reason: Cyclomatic complexity. Not safety critical, Allowed in later versions of ISO C99 */
  /* Next lane object selected based on turn direction */
  OOI_NextLane = object_list[Obj_first_left_lane];// PRQA S 7004, 1031
  /* date: 2018-03-26, reviewer: Ravi Kiran Gurrala, reason: Cyclomatic complexity. Not safety critical, Allowed in later versions of ISO C99 */
  if (input->DRIVER_CONTROLS.e_OTIntention == OVERTAKE_RIGHT_ON)
  {
    OOI_NextLane = object_list[Obj_first_right_lane];
  }

  status->ACC_OVERTAKE_DATA.b_RampObjReqDist = FALSE;   /* Reset of variable at every cycle */

#if (CFG_FCT_ACC_TTS_CONTROLLER)
  /* objects are indicated as "real measured" for TTS controller */
  OOI_0.AUTOSAR.OBJECT_STATUS.MEASURED = TRUE;
  OOI_NextLane.AUTOSAR.OBJECT_STATUS.MEASURED = TRUE;
#endif

  /* Calculation of acceleration difference to OOI-2 with respect to OOI-0 */
  if ((status->ACC_OVERTAKE_DATA.e_OTState == OVERTAKE_IDLE) && (input->DRIVER_CONTROLS.e_OTIntention != OVERTAKE_OFF))
  {
    if(OOI_0.AUTOSAR.OBJECT_ID != OBJ_INDEX_NO_OBJECT)
    {
      t_ReqAccel_OOIZero = HP_t_DetermineDistControlAccel(&OOI_0, (input->DRIVER_CONTROLS.HEADWAY_SETTING), input->LONG_ACCELERATION);
      if(OOI_NextLane.AUTOSAR.OBJECT_ID != OBJ_INDEX_NO_OBJECT)
      {
#if (HP_CFG_OVERTAKE_PREVENTION_FEATURE)
        /* Next lane data may be modified incase overtake prevention feature is active. 
          Hence resetting desired distance for this calculation */
        OOI_NextLane.REQUESTED_DISTANCE_MODIFIED_ACT = OOI_0.REQUESTED_DISTANCE_MODIFIED_ACT;
        OOI_NextLane.REQUESTED_DISTANCE_MODIFIED_PRED = OOI_0.REQUESTED_DISTANCE_MODIFIED_PRED;
        OOI_NextLane.CONTROL_SMOOTHNESS = OOI_0.CONTROL_SMOOTHNESS;
        OOI_NextLane.ALERT_MODIFICATION_FACTOR = OOI_0.ALERT_MODIFICATION_FACTOR;
#endif
        t_ReqAccel_OOINext = HP_t_DetermineDistControlAccel(&OOI_NextLane, (input->DRIVER_CONTROLS.HEADWAY_SETTING), input->LONG_ACCELERATION);
        if(t_ReqAccel_OOINext > Acc_otsupport_ooi_accel_threshold)
        {
          t_ReqAccel_Diff = t_ReqAccel_OOINext;
        }
        else
        {
          t_ReqAccel_Diff = t_ReqAccel_OOINext - t_ReqAccel_OOIZero;
        }
        
        /* If nextlane OOI is not far enough, timer for stable logic in case of dropout during lane change */
        if(t_ReqAccel_Diff < Acc_otsupport_ooi_accel_threshold)
        {
          Timer_OOINextLane_LossCheck = ROBUSTNESS_CHECK_TIMER_DURATION;
        }
      }
      else
      {
        if(Timer_OOINextLane_LossCheck == (times_t)0)
        {
          /* No obj in neighbouring lane. Diff set to max allowed accel */
          t_ReqAccel_Diff = Acc_max_allowed_accel;
        }
        else
        { /* Obj in neighbouring lane was close but lost during (assumed) lane change phase */
          t_ReqAccel_Diff = (acceleration_t)0;
        }
      }
    }
    else
    {
      /* There is no OOI-0, accel diff is set to 0 */
      t_ReqAccel_Diff = (acceleration_t)0;
    }
  }
  else
  {
    t_ReqAccel_Diff = Acc_max_allowed_accel;
  }

  SWITCH_SET_COUNTER(cycle_time, &(status->ACC_OVERTAKE_DATA.Timer_TGR));
  SWITCH_SET_COUNTER(cycle_time, &(status->ACC_OVERTAKE_DATA.Timer_BP));
  SWITCH_SET_COUNTER(cycle_time, &Timer_OOINextLane_LossCheck);

  if ((status->ACC_OVERTAKE_DATA.Timer_TGR == 0u ) && 
      ((status->ACC_OVERTAKE_DATA.e_OTState == OVERTAKE_RUNNING) || (status->ACC_OVERTAKE_DATA.e_OTState == OVERTAKE_EXTENDED))
     )
  { /* Maximum time duration of maneouvre phase is over. Must be ended */
    status->ACC_OVERTAKE_DATA.b_Overtake_Support_On = FALSE;
  }

#ifndef FCT_SIMU
  /* If ACC is not activated in vehicle, OT feature to be deactivated immediately */
  if(input->INPUT_STATUS.ACC_NOT_OFF == FALSE)
  {
    status->ACC_OVERTAKE_DATA.b_Overtake_Support_On = FALSE;
    status->ACC_OVERTAKE_DATA.e_OTState = OVERTAKE_DONE;
  }
#endif  /* FCT_SIMU */

  if((status->ACC_OVERTAKE_DATA.b_Overtake_Support_On == TRUE) 
      && ((status->ACC_OVERTAKE_DATA.e_OTState == OVERTAKE_RUNNING) || (status->ACC_OVERTAKE_DATA.e_OTState == OVERTAKE_EXTENDED))
      &&(OOI_0.AUTOSAR.OBJECT_STATUS.DETECTED == TRUE))
  {
    /* Calculate the minimal time gap that should not be undershoot during Overtake Support */
    MinDistToObj = (distance_t)((status->REQUESTED_DISTANCE_ACT * MAT_CALCULATE_PARAM_VALUE1D(Acc_otsupport_min_dist_factor, Acc_otsupport_min_dist_factor_points, (sint16)input->DRIVER_CONTROLS.HEADWAY_SETTING))/Factor_s);
    
    /* Calculate the required deceleration distance to increase the relative velocity to 0 m/s */
    /* considering the current acceleration and the maximal possible deceleration and gradient */
    /* 1e-2 [m], 0x8000 ... 0x7FFF */
    s16_brake_dist = HP_t_DetermineMinDecelDistance
                     (  input->LONG_ACCELERATION
                      , input->LONG_VELOCITY
                      , &OOI_0
                      , LOHP_pAccOutput
                     );
    
    /* Both distance values are added to create a distance */
    /* threshold to deactivate overtake support feature */
    /* 1e-2 [m], 0x8000 ... 0x7FFF */
    s16_ots_deac_dist = ( distance_t )
      /* 1e-2 [m], 0x8000 ... 0x7FFF */
      MAT_LIM
      (  /* 1e-2 [m], 0x8000.0000 ... 0x7FFF.FFFF */
         ( sint32 )( MinDistToObj + s16_brake_dist )
       , Distance_min
       , Distance_max
      );

    /* If longitudinal displacement is smaller than the minimum allowed distance */
    /* the overtake support feature has to be deactivated */
    /* 1e-2 [m], 0x8000 ... 0x7FFF */
    if ( OOI_0.AUTOSAR.LONG_DISPLACEMENT < s16_ots_deac_dist )
    {
      status->ACC_OVERTAKE_DATA.b_Overtake_Support_On = FALSE;
    }
  }


  /* During states RUNNING / EXTENDED OOI-0 loss is checked to enable transition to PASSBY state */
  /* Furthermore adjacent OOI's must be observed in order to know if feature has to be deactivated */
  if (   ( status->ACC_OVERTAKE_DATA.e_OTState == OVERTAKE_RUNNING )
      || ( status->ACC_OVERTAKE_DATA.e_OTState == OVERTAKE_EXTENDED )
     )
  {
#if ( HP_CFG_PARALLEL_LANE_CHANGE )
    /* In case the target vehicle which ego intends to overtake also intends to perform a lanechange */
    /* in the same direction, the feature must be deactivated */
    if (   /* Passby phase has not started */
           ( status->ACC_OVERTAKE_DATA.OOI_OTS_ObjId == object_list[Obj_first_host_lane].AUTOSAR.OBJECT_ID )
        && (   (   ( status->ACC_OVERTAKE_DATA.e_OTDirection == OVERTAKE_LEFT_ON )
                && ( input->OOI_LC_DIRECTION[Obj_first_host_lane] == LANECHANGE_LEFT )
               )
            || (   ( status->ACC_OVERTAKE_DATA.e_OTDirection == OVERTAKE_RIGHT_ON )
                && ( input->OOI_LC_DIRECTION[Obj_first_host_lane] == LANECHANGE_RIGHT )
               )
           )
       )
    {
      status->ACC_OVERTAKE_DATA.b_Overtake_Support_On = FALSE;
    }
#endif
    
    /* Check for adjacent OOI after feature activation */
    if (   /* Passby phase has not started */
           ( status->ACC_OVERTAKE_DATA.OOI_OTS_ObjId == object_list[Obj_first_host_lane].AUTOSAR.OBJECT_ID )
           && (OOI_NextLane.AUTOSAR.OBJECT_ID != OBJ_INDEX_NO_OBJECT)
       )
    {
      /* In case adjacent OOI is existing the acceleration request of last cycle has to be compared with a threshold */
      /* If acceleration request is below threshold, feature must be deactivated */
      t_ReqAccel_OOINext = HP_t_DetermineDistControlAccel(&OOI_NextLane, (input->DRIVER_CONTROLS.HEADWAY_SETTING), input->LONG_ACCELERATION);
      if (  /* 1e-3 [m/s^2], 0x8000 ... 0x7FFF */
            t_ReqAccel_OOINext
          < /* 1e-3 [m/s^2], 0x8000 ... 0x7FFF */
            Acc_otsupport_deac_accel_adj_obj
         )
      {
        status->ACC_OVERTAKE_DATA.b_Overtake_Support_On = FALSE;
      }
    }
    
    if( /* Based on OT direction, check if previous OOI-0 is now OOI right or left */
      ((status->ACC_OVERTAKE_DATA.e_OTDirection == OVERTAKE_LEFT_ON)&&(status->ACC_OVERTAKE_DATA.OOI_OTS_ObjId == object_list[Obj_first_right_lane].AUTOSAR.OBJECT_ID)) ||
      ((status->ACC_OVERTAKE_DATA.e_OTDirection == OVERTAKE_RIGHT_ON)&&(status->ACC_OVERTAKE_DATA.OOI_OTS_ObjId == object_list[Obj_first_left_lane].AUTOSAR.OBJECT_ID))
      )
    { 
      u_OOI_LC_Cycle++;
      u_help = (uint8)MAT_CALCULATE_PARAM_VALUE1D(Acc_otsupport_lc_cycle_counter, Acc_otsupport_lc_cycle_counter_points, (sint16)input->DRIVER_CONTROLS.HEADWAY_SETTING);
      if(u_OOI_LC_Cycle > u_help) /* Check if earlier OOI-0 has been replaced for certain number of cycles for robustness */
      {
        b_PassbyStart = TRUE;
      }
    }
    else
    {
      u_OOI_LC_Cycle = 0u;
    }
  }
  
  HP_v_PlanOvertakeManoeuvreCustom(input, object_list, status, cycle_time);

  switch(status->ACC_OVERTAKE_DATA.e_OTState)
  {
  case OVERTAKE_IDLE:
    {
      /* Check if an overtake maneuver is intended by the driver */
      if ( input->DRIVER_CONTROLS.e_OTIntention != OVERTAKE_OFF )
      {
        /* In order to avoid inadequate overtake behavior caused by */
        /* wrong lane association, new object ID is compared with the previous one */
        /* No object in last cycle also deactivates the feature */
        if ( OOI_0.AUTOSAR.OBJECT_ID != status->ACC_OVERTAKE_DATA.OOI_OTS_ObjId )
        {
          status->ACC_OVERTAKE_DATA.e_OTState = OVERTAKE_DONE;
        }
        else
        {
          /* Perform a transition to Overtake running in case that host vehicle is moving faster than threshold velocity */
          /* and the requested control acceleration to the vehicle in next lane is greater than the next vehicle in host lane */
          /* and OOI-0 is existing and tracked */
          /* and OOI-0 does not intend to perform a lane change */
          if( /* 1e-2 [m/s], 0x8000 ... 0x7FFF */
              ( input->LONG_VELOCITY > Acc_otsupport_min_speed )
              /* 1e-3 [m/s^2], 0x8000 ... 0x7FFF */
              && ( t_ReqAccel_Diff > Acc_otsupport_ooi_accel_threshold) /* Acceleration for OOI-next is beyond threshold */
              && ( OOI_0.AUTOSAR.OBJECT_STATUS.DETECTED == TRUE )
#if ( HP_CFG_PARALLEL_LANE_CHANGE )
              && ( input->OOI_LC_DIRECTION[Obj_first_host_lane] == LANECHANGE_NONE )
#endif
            )
          {
            status->ACC_OVERTAKE_DATA.e_OTState = OVERTAKE_RUNNING;
            status->ACC_OVERTAKE_DATA.Timer_TGR = Acc_otsupport_tgr_max_duration; /* Start of timer for overtake support TGR phase */
            status->ACC_OVERTAKE_DATA.b_Overtake_Support_On = TRUE;
            Timer_OOINextLane_LossCheck = (times_t)0; /* Reset of next lane OOI check timer static variable */
            status->ACC_OVERTAKE_DATA.e_OTDirection = input->DRIVER_CONTROLS.e_OTIntention;
          }
        }
      }
      
      /* Save a static copy of OOI0's object ID used for calculations in next cycle */
      status->ACC_OVERTAKE_DATA.OOI_OTS_ObjId = OOI_0.AUTOSAR.OBJECT_ID;

      break;
    }
  case OVERTAKE_RUNNING:
    {
      if(b_PassbyStart == TRUE)
      { /* Change/loss of OOI-0 starts passby state */
        status->ACC_OVERTAKE_DATA.e_OTState = OVERTAKE_PASSBY; /* Passing by of previous OOI-0 */
        status->ACC_OVERTAKE_DATA.Timer_BP = Acc_otsupport_bp_max_duration; 
      }
      else
      {
        if(input->DRIVER_CONTROLS.e_LCPhase == LANECHANGE_ON)
        { /* Lane change phase confirmed by SLATE */
          status->ACC_OVERTAKE_DATA.e_OTState = OVERTAKE_EXTENDED;
        }
        else
        {
          if(status->ACC_OVERTAKE_DATA.b_Overtake_Support_On == FALSE) /* Timer_TGR ended or OOI-0 is too close */
          {
            status->ACC_OVERTAKE_DATA.e_OTState = OVERTAKE_DONE; /* Completed */
            status->ACC_OVERTAKE_DATA.b_RampObjReqDist = TRUE;
          }
        }
      }
      break;
    }
  case OVERTAKE_EXTENDED:
    {
      if(b_PassbyStart == TRUE)
      { /* Change/loss of OOI-0 starts passby state */
        status->ACC_OVERTAKE_DATA.e_OTState = OVERTAKE_PASSBY; /* Passing by of previous OOI-0 */
        status->ACC_OVERTAKE_DATA.Timer_BP = Acc_otsupport_bp_max_duration; 
      }
      if(status->ACC_OVERTAKE_DATA.b_Overtake_Support_On == FALSE)
      {
        status->ACC_OVERTAKE_DATA.e_OTState = OVERTAKE_DONE; /* Completed */
        status->ACC_OVERTAKE_DATA.b_RampObjReqDist = TRUE;
      }
      break;
    }
  case OVERTAKE_PASSBY:
    {
      if(status->ACC_OVERTAKE_DATA.Timer_BP == (times_t)0)
      {
        status->ACC_OVERTAKE_DATA.e_OTState = OVERTAKE_DONE; /* Completed */
      }
      status->ACC_OVERTAKE_DATA.s_LCModFactor = Factor_s; /* In passby phase, obj distance is not to be modified */
      u_OOI_LC_Cycle = 0u;
      break;
    }
  case OVERTAKE_DONE:
    {
      /* Reset all OTS relevant variables to neutral/idle values */
      status->ACC_OVERTAKE_DATA.b_Overtake_Support_On = FALSE;
      status->ACC_OVERTAKE_DATA.Timer_TGR = (times_t)0;
      status->ACC_OVERTAKE_DATA.Timer_BP = (times_t)0;
      status->ACC_OVERTAKE_DATA.s_LCModFactor = Factor_s;
      status->ACC_OVERTAKE_DATA.e_OTDirection = OVERTAKE_OFF;
      status->ACC_OVERTAKE_DATA.OOI_OTS_ObjId = OBJ_INDEX_NO_OBJECT;
      status->ACC_OVERTAKE_DATA.b_RampObjReqDist = FALSE;
      Timer_OOINextLane_LossCheck = (times_t)0; /* Reset of next lane OOI check timer static variable */
      u_OOI_LC_Cycle = 0u;

      /* only reset the Overtake support state machine after */
      /* the overtake intention was removed and ACC is switched on */
      if (
            ( input->DRIVER_CONTROLS.e_TurnIndicator == INDICATOR_OFF )
#ifndef FCT_SIMU
            &&
            (input->INPUT_STATUS.ACC_NOT_OFF == TRUE)
#endif
         )
      {
        status->ACC_OVERTAKE_DATA.e_OTState = OVERTAKE_IDLE; /* Reset */
      }
      break;
    }
  default:
    {
      /* Reset all OTS relevant variables to neutral/idle values */
      status->ACC_OVERTAKE_DATA.e_OTState = OVERTAKE_IDLE;
      status->ACC_OVERTAKE_DATA.b_Overtake_Support_On = FALSE;
      status->ACC_OVERTAKE_DATA.Timer_TGR = (times_t)0;
      status->ACC_OVERTAKE_DATA.Timer_BP = (times_t)0;
      status->ACC_OVERTAKE_DATA.s_LCModFactor = Factor_s;
      status->ACC_OVERTAKE_DATA.e_OTDirection = OVERTAKE_OFF;
      status->ACC_OVERTAKE_DATA.OOI_OTS_ObjId = OBJ_INDEX_NO_OBJECT;
      status->ACC_OVERTAKE_DATA.b_RampObjReqDist = FALSE;
      u_OOI_LC_Cycle = 0u;
      Timer_OOINextLane_LossCheck = (times_t)0; /* Reset of next lane OOI check timer static variable */
      break;
    }
  }

#else /* HP_CFG_OVERTAKE_SUPPORT_FEATURE */
  _PARAM_UNUSED(status);
  _PARAM_UNUSED(cycle_time);
#endif /* HP_CFG_OVERTAKE_SUPPORT_FEATURE */

  output->LANE_CHANGE_LEFT_PROBABILITY = input->DRIVER_CONTROLS.P_LANE_CHANGE_LEFT;
  output->LANE_CHANGE_RIGHT_PROBABILITY = input->DRIVER_CONTROLS.P_LANE_CHANGE_RIGHT;

#if (HP_CFG_OVERTAKE_SUPPORT_FEATURE)
  /* When feature is active in certain phases, neighbouring lane objects set active based on expected driver lane change */
  if((status->ACC_OVERTAKE_DATA.b_Overtake_Support_On == TRUE) &&
    ((status->ACC_OVERTAKE_DATA.e_OTState == OVERTAKE_RUNNING) || (status->ACC_OVERTAKE_DATA.e_OTState == OVERTAKE_EXTENDED))
    )
  {
    if(status->ACC_OVERTAKE_DATA.e_OTDirection == OVERTAKE_LEFT_ON)
    {
      output->LANE_CHANGE_LEFT_PROBABILITY = HP_OTS_LC_PROB;
    }
    else
    {
      output->LANE_CHANGE_RIGHT_PROBABILITY = HP_OTS_LC_PROB;
    }
  }
#endif /* HP_CFG_OVERTAKE_SUPPORT_FEATURE */

  SWITCH_SET_STATE(&(output->ACC_ENGAGED), (boolean)(input->INPUT_STATUS.ACC_NOT_OFF == TRUE));

  /* -------------------------- override detection ----------------------*/

  /*CC limiter active in case of transition from override to active state */
  if(input->INPUT_STATUS.CC_DECEL_LIM_OVERRIDE == TRUE)
  {
    /*internal copy not active yet*/
    if(output->DECEL_LIM_OVERRIDE.CC_LIMITER_ACTIVE == FALSE)
    {
      output->DECEL_LIM_OVERRIDE.CC_LIMITER_ACTIVE = TRUE;
      if(object_list[Obj_first_host_lane].AUTOSAR.OBJECT_STATUS.DETECTED == TRUE)
      {
        if(
           (object_list[Obj_first_host_lane].AUTOSAR.OBJECT_STATUS.NEW == FALSE)
           &&
           (object_list[Obj_first_host_lane].LONG_ACCEL_MODIFIED >= input->CC_DECEL_LIMIT)
          )
        {
          output->DECEL_LIM_OVERRIDE.ACC_LIMITER_ACTIVE = TRUE;
        }
        else
        {
          output->DECEL_LIM_OVERRIDE.ACC_LIMITER_ACTIVE = FALSE;
        }
      }
    }
  }
  else
  {
    output->DECEL_LIM_OVERRIDE.CC_LIMITER_ACTIVE = FALSE;
    output->DECEL_LIM_OVERRIDE.ACC_LIMITER_ACTIVE = FALSE;
  }

  /*save object id of stationary object thats relevant in cycle where the drive off possible bit is true*/
  if(
    (input->INPUT_STATUS.ACC_CONTROL_TO_FIRST_OBJECT == TRUE) /* Set true if ego vehicle is stationary */
#if (!CFG_FCT_ACC_REACT_ON_STANDING_OBJECTS)
    ||
    (
      (input->LONG_VELOCITY < Acc_decel_on_stationary_speed)
      &&
      (input->INPUT_STATUS.ACC_ON == FALSE)
    )
#endif
    &&
    (object_list[Obj_first_host_lane].AUTOSAR.LONG_DISPLACEMENT <= Acc_max_dist_rel_standing_obj)
    )
  {
    output->OBJECT_NR_TO_CONTROL_TO = object_list[Obj_first_host_lane].AUTOSAR.OBJECT_ID;
  }
  
  if(output->OBJECT_NR_TO_CONTROL_TO != object_list[Obj_first_host_lane].AUTOSAR.OBJECT_ID)
  {
    output->OBJECT_NR_TO_CONTROL_TO = OBJ_INDEX_NO_OBJECT;
  }
  
}// PRQA S 7004, 7012
/* date: 2018-03-26, reviewer: Ravi Kiran Gurrala, reason: Cyclomatic complexity. Not safety critical */


#endif /* (FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER) */

/** @} end defgroup */
