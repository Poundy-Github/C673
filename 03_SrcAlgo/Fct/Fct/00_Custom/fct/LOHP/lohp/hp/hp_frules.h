/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp_frules.h

DESCRIPTION:               Header file for fuzzy rule parameter definitions of headway planner

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            Revision: 1.6.2.2

**************************************************************************** */

#ifndef HP_FRULES_H_INCLUDED
#define HP_FRULES_H_INCLUDED
/*this file was created with FuzzyRuleCreator ([D:\Projekte\Basisprojekte\fct_base_project\codegen\fct\fuzzy_rule_creator\data\accfuzzy.aft] FSRA FuzzySet, fuzzy rule set for fsr acc)*/

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         hp_frules_h   Hp_frules_h
@ingroup          hp_custom
@brief            Header file for fuzzy rule parameter definitions for HP
@{
*/

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))


DLLEXPORT extern signed_fuzzy_t HP_v_DoFuzzy
(  
   signed_fuzzy_t rel_distance
 , signed_fuzzy_t speed_rel
 , signed_fuzzy_t a_obj
 , signed_fuzzy_t distance_set_error
 , signed_fuzzy_t distance_min_error
 , signed_fuzzy_t softness
 , signed_fuzzy_t v_own
 , signed_fuzzy_t v_obj
 , signed_fuzzy_t distance
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
 , FuzzyDebugData_t *pFuzzyDebugData
#endif
);

/*output acceleration*/

/*brake command*/
extern const fuzzy_var_t a_out_brake;

/*do nothing*/
extern const fuzzy_var_t a_out_roll;

/*accelerate*/
extern const fuzzy_var_t a_out_accelerate;

extern const fuzzy_var_t a_out_brake_hard;



/*relative distance (dact/dset)*/

/*distance is to small*/
extern const fuzzy_var_t rel_distance_close;

/*distance is OK*/
extern const fuzzy_var_t rel_distance_OK;

/*distance is far*/
extern const fuzzy_var_t rel_distance_far;

/*distance is still OK with larger threshold*/
extern const fuzzy_var_t rel_distance_still_OK;

/*distance is quite far*/
extern const fuzzy_var_t rel_distance_vfar;

/*distance is more far than normal*/
extern const fuzzy_var_t rel_distance_little_far;


/*relative speed (m/s)*/

/*target vehicle is much slower than the own vehicle*/
extern const fuzzy_var_t speed_rel_much_slower;

/*target vehicle is slower than the own vehicle*/
extern const fuzzy_var_t speed_rel_slower;

/*target vehicle has the same speed as the own vehicle*/
extern const fuzzy_var_t speed_rel_same_speed;

/*target vehicle is faster than the own vehicle*/
extern const fuzzy_var_t speed_rel_faster;

/*vehicle in front is little bit slower*/
extern const fuzzy_var_t speed_rel_littleslower;

/*vehicle in front is little bit faster*/
extern const fuzzy_var_t speed_rel_littlefaster;

/*vehicle in front is moderately faster*/
#define HP_frules_vrel_modfast_points (uint16)5
extern const factor_t speed_rel_modfaster[2*HP_frules_vrel_modfast_points];

/*extern const fuzzy_var_t speed_rel_no_rel_speed;*/

/*extern const fuzzy_var_t speed_rel_very_much_slower;*/

/*the object is really slower*/
extern const fuzzy_var_t speed_rel_really_slower;

/*vehicle in front is about the same speed in a larger threshold*/
extern const fuzzy_var_t speed_rel_same_speed_large;

/*vehicle in front is slightly slower*/
extern const fuzzy_var_t speed_rel_slightly_slower;


/*acceleration of the object*/

/*target vehicle is braking very hard*/
extern const fuzzy_var_t a_obj_hard_braking;

#define HP_frules_aobj_med_braking_points (uint16)5
extern const factor_t a_obj_med_braking[2*HP_frules_aobj_med_braking_points];

/*target vehicle is braking*/
extern const fuzzy_var_t a_obj_braking;

/*target vehicle does not accelerate*/
extern const fuzzy_var_t a_obj_rolling;

/*target vehicle dynamics are low in an extended threshold*/
#define HP_frules_aobj_rolling_points (uint16)7
extern const factor_t a_obj_rolling_extended[2*HP_frules_aobj_rolling_points] ;

/*target vehicle is accelerating*/
extern const fuzzy_var_t a_obj_accelerating;

/*vehicle in front is acceleration slightly*/
extern const fuzzy_var_t a_obj_lowaccel;

/*target vehicle is braking very little*/
extern const fuzzy_var_t a_obj_lowbrake;

/*target vehicle is braking slightly*/
extern const fuzzy_var_t a_obj_soft_braking;



/*error (m) to the set distance*/

/*distance to headway setting is too short*/
extern const fuzzy_var_t distance_set_error_to_close;

/*distance to headway setting is too far*/
extern const fuzzy_var_t distance_set_error_to_far;

/*distance to headway setting is quite close*/
extern const fuzzy_var_t distance_set_error_close;

/*distance to headway setting is not close enough*/
extern const fuzzy_var_t distance_set_error_not_close_enough;

/*distance to headway setting is near*/
extern const fuzzy_var_t distance_set_error_near;

/*distance to headway setting is more*/
extern const fuzzy_var_t distance_set_error_more_than_requested;

/* Distance to headway setting is very less, but positive */
extern const fuzzy_var_t distance_set_error_near_short;


/*distance error (m) to the minimum allowed (alert) distance*/

/*gap is a lot smaller than alert distance*/
/*extern const fuzzy_var_t distance_min_error_to_close;*/

/*gap is a lot higher than alert distance*/
extern const fuzzy_var_t distance_min_error_to_far;

/*gap is close to the alert distance*/
extern const fuzzy_var_t distance_min_error_short;

/*gap is very close to the alert distance*/
extern const fuzzy_var_t distance_min_error_veryshort;

/*gap is lower than alert distance*/
extern const fuzzy_var_t distance_min_error_below;

/*gap is higher than alert distance*/
extern const fuzzy_var_t distance_min_error_near;



/*factor (0-100) how soft the controller shall react*/

/*the reaction shall be soft*/
extern const fuzzy_var_t softness_soft;

/*the reaction shall be very dynamic and restrictive to distance*/
extern const fuzzy_var_t softness_very_dynamic;



/*own vehicle speed in m/s (scaled by 100)*/

/*vehicle is in still stand or slowly creeping */
extern const fuzzy_var_t v_own_stillstand;

/*vehicle is slow*/
extern const fuzzy_var_t v_own_slow;

/*vehicle is fast*/
extern const fuzzy_var_t v_own_fast;

/*speed is not fast like on Highways*/
extern const fuzzy_var_t v_own_urban;

/*City driving speeds*/
extern const fuzzy_var_t v_own_city;

/*Vehicle driving at extended high speeds */
extern const fuzzy_var_t v_own_vfast;

/* Vehicle is very slow and close to standstill */
extern const fuzzy_var_t v_own_vslow;

/*Object speed*/

/*object speed in standstill*/
extern const fuzzy_var_t v_obj_standstill;

/* object speed near standstill */
extern const fuzzy_var_t v_obj_near_standstill;

/*object speed is fast*/
extern const fuzzy_var_t v_obj_fast;

/*speed is not fast like on Highways*/
extern const fuzzy_var_t v_obj_urban;



/*distance of control object*/

/*distance is to close*/
extern const fuzzy_var_t distance_to_close;

#endif  /* #if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER)) */

/** @} end defgroup */

#endif /* ifndef HP_FRULES_H_INCLUDED */
