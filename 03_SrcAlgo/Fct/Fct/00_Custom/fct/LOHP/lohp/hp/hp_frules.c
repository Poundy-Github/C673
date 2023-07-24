/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/HP (Adaptive Cruise Control - Longitudinal Headway Planner - Headway Planner)

PACKAGENAME:               hp_frules.c

DESCRIPTION:               File for definition of fuzzy rules for headway planner

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.7.3.2 $

LEGACY VERSION:            Revision: 1.10

**************************************************************************** */

/*this file was created with FuzzyRuleCreator ([D:\Projekte\Basisprojekte\fct_base_project\codegen\fct\fuzzy_rule_creator\data\accfuzzy.aft] FSRA FuzzySet, fuzzy rule set for fsr acc)*/

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         hp_frules   Hp_frules
@ingroup          hp_custom
@brief            File for definitions of fuzzy rules and parameters for HP
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hp.h"
#include "hp_frules.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER))

#ifdef FCT_SIMULATION
  #include "calcFuzzy.h"
#endif


const fuzzy_var_t a_out_brake                    = {-6000, -6000, -3000,     0};
const fuzzy_var_t a_out_roll                     = {-3000, -1000,  1000,  3000};
const fuzzy_var_t a_out_accelerate               = {    0,  3000,  4000,  4000};
const fuzzy_var_t a_out_brake_hard               = {-10000, -10000, -3000, -2000};

const fuzzy_var_t rel_distance_close             = {    0,     0,   500,  1000};
const fuzzy_var_t rel_distance_OK                = {  800,  950,  1150,  1300};
const fuzzy_var_t rel_distance_far               = { 1000,  5000,  5000,  5000};
const fuzzy_var_t rel_distance_still_OK          = {  500,  1000,  1000,  1250};
const fuzzy_var_t rel_distance_vfar              = {  2500, 8000,  8000,  8000};
const fuzzy_var_t rel_distance_little_far        = { 1000,  1300,  1300,  1300};

const fuzzy_var_t speed_rel_much_slower          = {-2000, -2000, -2000,  -200};
const fuzzy_var_t speed_rel_slower               = {-1000, -1000, -1000,   -50};
const fuzzy_var_t speed_rel_same_speed           = { -200,   -50,   100,   180};
const fuzzy_var_t speed_rel_faster               = {   10,  1000,  1000,  1000};
const fuzzy_var_t speed_rel_littleslower         = { -600,  -600,  -600,    10};
const fuzzy_var_t speed_rel_littlefaster         = {    4,   130,   130,   130}; 

const factor_t speed_rel_modfaster[2*HP_frules_vrel_modfast_points] = 
{
    4,     0,
   40,   400,
  100,   550,
  150,   800,
  175,  1000
};
/*const fuzzy_var_t speed_rel_no_rel_speed         = { -200,     0,     0,     0};*/
/*const fuzzy_var_t speed_rel_very_much_slower     = {-2000, -2000, -2000, -1495};*/
const fuzzy_var_t speed_rel_really_slower        = { -800,  -800,  -800,  -300};
const fuzzy_var_t speed_rel_same_speed_large     = { -400,  -300,   100,   180};
const fuzzy_var_t speed_rel_slightly_slower      = { -140, -50, -50, -50 };

const fuzzy_var_t a_obj_hard_braking             = {-10000, -10000, -4000, -2000};
const factor_t a_obj_med_braking[2*HP_frules_aobj_med_braking_points] = 
{
  -5000,  1000,
  -3500,   700,
  -2600,   270,
  -2200,    50,
  -1900,     0
};
const fuzzy_var_t a_obj_braking                  = {-3500, -3500, -3500,  -400};
const fuzzy_var_t a_obj_rolling                  = {-1400,  -400,   200,  1000};  
/* Extended Table for a_obj_rolling parameter */
const factor_t a_obj_rolling_extended[2*HP_frules_aobj_rolling_points] = 
{
  -1500,     0,
  -1200,   350,
   -800,   450,
   -400,   700,
    -50,  1000,
    100,  1000,
   1000,  0
};
const fuzzy_var_t a_obj_accelerating             = {   40,  4000,  4000,  4000};
const fuzzy_var_t a_obj_lowaccel                 = {   20,  1000,  1000,  1000};
const fuzzy_var_t a_obj_lowbrake                 = { -600,  -200,  -200,  -200};
const fuzzy_var_t a_obj_soft_braking             = {-1500, -1500, -1500,     0};

const fuzzy_var_t distance_set_error_to_close    = {-10000, -10000, -10000,  -100};
const fuzzy_var_t distance_set_error_to_far      = {  100, 15000, 15000, 15000};
const fuzzy_var_t distance_set_error_close       = {-1599, -1599, -1599,    50};
const fuzzy_var_t distance_set_error_not_close_enough = {    1,  3500,  3500,  3500};
const fuzzy_var_t distance_set_error_near        = {  100,  9950,  9950,  9950};
const fuzzy_var_t distance_set_error_near_short  = {  100,  1000,  1000,  1000};
const fuzzy_var_t distance_set_error_more_than_requested = {  300,  1500,  1500,  1500};

/*const fuzzy_var_t distance_min_error_to_close    = {-10000, -10000, -10000,  -100};*/
const fuzzy_var_t distance_min_error_to_far      = {  100, 10000, 10000, 10000};
const fuzzy_var_t distance_min_error_short       = {    0,     0,     0,  2500};
const fuzzy_var_t distance_min_error_veryshort   = {    0,     0,     0,  1150}; 
const fuzzy_var_t distance_min_error_below       = {-1000, -1000, -1000,   500};
const fuzzy_var_t distance_min_error_near        = {    0,     0,     0,  5050};

const fuzzy_var_t softness_soft                  = {   40,    60,    60,    60};
const fuzzy_var_t softness_very_dynamic          = {   20,    20,    20,    40};

const fuzzy_var_t v_own_stillstand               = {    0,     0,     0,   250};
const fuzzy_var_t v_own_vslow                    = {    0,     0,     0,   500};
const fuzzy_var_t v_own_slow                     = {    0,     0,     0,  1000};
const fuzzy_var_t v_own_fast                     = { 2000,  5000,  5000,  5000};
const fuzzy_var_t v_own_vfast                    = { 2000,  7000,  7000,  7000};
const fuzzy_var_t v_own_urban                    = {   99,   100,   100,  2000};
const fuzzy_var_t v_own_city                     = { 1600,  1600,  1600,  2000};

const fuzzy_var_t v_obj_standstill               = {    0,     0,     0,   250};
const fuzzy_var_t v_obj_near_standstill          = {    0,     0,     0,   500};
const fuzzy_var_t v_obj_fast                     = { 2000,  3500,  3500,  3500};
const fuzzy_var_t v_obj_urban                    = {    0,     0,     0,  2000};

const fuzzy_var_t distance_to_close              = {    0,     0,   300,   800};


/*************************************************************************************************************************
  Functionname:    HP_v_DoFuzzy                                                                                     */ /*!

  @brief           Calculate the output acceleration of the fuzzy controller

  @description     Depending on different combinations of the input variables, which interpret the elemental maneuvers, 
                   the desired actions of acceleration, roll, brake and brake hard are activated with their weights through
                   the fuzzy rules. The output acceleration is a combination of these four actions based on their weights.
                   The sum-prod method is used for inferencing this weight distribution between the actions. The centroid 
                   method is used for the defuzzification of the crisp output, which is the desired acceleration.

                    @startuml
                        Start
                            Partition HP_v_DoFuzzy {
                                -Calculate the output acceleration of the fuzzy controller 
                            }
                        end
                    @enduml

  @return          Acceleration in m/s2, multiplied with factor Acceleration_s. [-30000...30000u]

  @param[in]       rel_distance : the ratio between the actual distance and the current control distance, multiplied with factor Factor_s. [0...2147483648u]
  @param[in]       speed_rel : relative object longitudinal speed in m/s, multiplied with factor Velocity_s.. [-30000...30000u] 
  @param[in]       a_obj : object longitudinal acceleration in m/s2, multiplied with factor Acceleration_s. [-30000...30000u] 
  @param[in]       distance_set_error : the control error of the headway control in m, multiplied with factor Distance_s. [0...5*RW_FCT_MAX] 
  @param[in]       distance_min_error : the difference between the required distance and the maximum intrusion distance in m, multiplied with factor Distance_s. [0...5*RW_FCT_MAX] 
  @param[in]       softness : smoothness value for the longitudinal control in percent. [0u... 100u] 
  @param[in]       v_own :  the velocity of the host vehicle in m/s, multiplied with factor Velocity_s. [-30000...30000u] 
  @param[in]       v_obj :  the velocity of the object vehicle in m/s, multiplied with factor Velocity_s. [-30000...30000u] 
  @param[in]       distance : longitudinal displacement of object in m, multiplied with factor Distance_s. [0...5*RW_FCT_MAX]

  @glob_in         -
  @glob_out        -
  
  @c_switch_part   FCT_SIMULATION : Configuration swith for enabling PC simulation
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : Configuration switch for enabling LOHP component
  @c_switch_full   CFG_FCT_ACC : Configuration switch enabeling Adaptive Cruise Control functionality (with object evaluation)

  @pre             - 
  @post            - 

  @created         03.11.2016
  @changed         03.11.2016
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-116-0008a201

  @author          Liting Lu | liting.lu@continental-corporation.com | +49 1721626978
*************************************************************************************************************************/
DLLEXPORT signed_fuzzy_t HP_v_DoFuzzy
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
)
{
#ifdef FCT_SIMULATION
  if(USE_EXT_FUZZY_FOR_SIM == 0)
  {
#endif
  signed_fuzzy_t fv_rel_distance_close;
  signed_fuzzy_t fv_speed_rel_slower;
  signed_fuzzy_t fv_speed_rel_faster;
  signed_fuzzy_t fv_v_own_stillstand;
  signed_fuzzy_t fv_v_own_vslow;
  signed_fuzzy_t fv_a_obj_braking;
  signed_fuzzy_t fv_speed_rel_same_speed;
  signed_fuzzy_t fv_speed_rel_same_speed_large;
  signed_fuzzy_t fv_a_obj_lowaccel;
  signed_fuzzy_t fv_a_obj_lowbrake;
  signed_fuzzy_t fv_distance_min_error_to_far;
  signed_fuzzy_t fv_v_own_urban;
  signed_fuzzy_t fv_v_own_city;
  signed_fuzzy_t fv_speed_rel_much_slower;
  signed_fuzzy_t fv_distance_set_error_near;
signed_fuzzy_t fv_distance_set_error_near_short;
  signed_fuzzy_t fv_softness_soft;
  signed_fuzzy_t fv_speed_rel_littleslower;
  signed_fuzzy_t fv_a_obj_accelerating;
  signed_fuzzy_t fv_a_obj_rolling;
  signed_fuzzy_t fv_v_obj_standstill;
  signed_fuzzy_t fv_v_obj_near_standstill;
  signed_fuzzy_t fv_distance_min_error_veryshort;
  signed_fuzzy_t fv_rel_distance_still_OK;
  signed_fuzzy_t fv_rel_distance_vfar;
  signed_fuzzy_t fv_distance_min_error_short;
  signed_fuzzy_t fv_v_own_fast;
  signed_fuzzy_t fv_v_own_vfast;
  signed_fuzzy_t fv_speed_rel_littlefaster;
  signed_fuzzy_t fv_speed_rel_modfaster;
  signed_fuzzy_t fv_distance_min_error_below;
  signed_fuzzy_t fv_v_own_slow;
  signed_fuzzy_t fv_rel_distance_far;
  signed_fuzzy_t fv_rel_distance_OK;
  signed_fuzzy_t fv_rel_distance_little_far;
  signed_fuzzy_t fv_a_obj_hard_braking;
  signed_fuzzy_t fv_a_obj_med_braking;
  signed_fuzzy_t fv_distance_min_error_near;
  signed_fuzzy_t fv_distance_set_error_close;
  signed_fuzzy_t fv_distance_set_error_not_close_enough;
  signed_fuzzy_t fv_softness_very_dynamic;
  signed_fuzzy_t fv_distance_to_close;
  signed_fuzzy_t fv_v_obj_fast;
  signed_fuzzy_t fv_distance_set_error_to_close;
  signed_fuzzy_t fv_a_obj_soft_braking;
  signed_fuzzy_t fv_distance_set_error_to_far;
  signed_fuzzy_t fv_v_obj_urban;
  signed_fuzzy_t fv_speed_rel_really_slower;
  signed_fuzzy_t fv_speed_rel_slightly_slower;
  signed_fuzzy_t fv_distance_set_error_more_than_requested;
/*****************************************************************************
 Fuzzication: calculate the truth value y based on input variable set and actual input
 
                    --------------------  ........... FUZZY_SCALE1
       y........../ x2                x3 \            
                 /                        \           
        ---------                          --------  0
                 x1                        x4

*****************************************************************************/
  fv_distance_set_error_more_than_requested= FUZZY_GET_FUZZY_VAL(&distance_set_error_more_than_requested,distance_set_error);
  fv_speed_rel_really_slower    = FUZZY_GET_FUZZY_VAL(&speed_rel_really_slower,speed_rel);
  fv_speed_rel_slightly_slower  = FUZZY_GET_FUZZY_VAL(&speed_rel_slightly_slower, speed_rel);
  fv_v_obj_urban                = FUZZY_GET_FUZZY_VAL(&v_obj_urban,v_obj);
  fv_distance_set_error_to_far  = FUZZY_GET_FUZZY_VAL(&distance_set_error_to_far,distance_set_error);
  fv_a_obj_soft_braking         = FUZZY_GET_FUZZY_VAL(&a_obj_soft_braking,a_obj);
  fv_distance_set_error_to_close= FUZZY_GET_FUZZY_VAL(&distance_set_error_to_close,distance_set_error);
  fv_v_obj_fast                 = FUZZY_GET_FUZZY_VAL(&v_obj_fast,v_obj);
  fv_distance_to_close          = FUZZY_GET_FUZZY_VAL(&distance_to_close,distance);
  fv_softness_very_dynamic      = FUZZY_GET_FUZZY_VAL(&softness_very_dynamic,softness);
  fv_distance_set_error_not_close_enough= FUZZY_GET_FUZZY_VAL(&distance_set_error_not_close_enough,distance_set_error);
  fv_distance_set_error_close   = FUZZY_GET_FUZZY_VAL(&distance_set_error_close,distance_set_error);
  fv_distance_min_error_near    = FUZZY_GET_FUZZY_VAL(&distance_min_error_near,distance_min_error);
  fv_a_obj_hard_braking         = FUZZY_GET_FUZZY_VAL(&a_obj_hard_braking,a_obj);
  fv_a_obj_med_braking          = (signed_fuzzy_t)MAT_CALCULATE_PARAM_VALUE1D(a_obj_med_braking,HP_frules_aobj_med_braking_points, (sint16)a_obj);
  fv_rel_distance_OK            = FUZZY_GET_FUZZY_VAL(&rel_distance_OK,rel_distance);
  fv_rel_distance_little_far    = FUZZY_GET_FUZZY_VAL(&rel_distance_little_far, rel_distance);
  fv_rel_distance_far           = FUZZY_GET_FUZZY_VAL(&rel_distance_far,rel_distance);
  fv_v_own_slow                 = FUZZY_GET_FUZZY_VAL(&v_own_slow,v_own);
  fv_distance_min_error_below   = FUZZY_GET_FUZZY_VAL(&distance_min_error_below,distance_min_error);
  fv_speed_rel_littlefaster     = FUZZY_GET_FUZZY_VAL(&speed_rel_littlefaster,speed_rel);
  fv_speed_rel_modfaster        = (signed_fuzzy_t)MAT_CALCULATE_PARAM_VALUE1D(speed_rel_modfaster, HP_frules_vrel_modfast_points, (sint16)speed_rel);
  fv_v_own_fast                 = FUZZY_GET_FUZZY_VAL(&v_own_fast,v_own);
  fv_v_own_vfast                = FUZZY_GET_FUZZY_VAL(&v_own_vfast,v_own);
  fv_distance_min_error_short   = FUZZY_GET_FUZZY_VAL(&distance_min_error_short,distance_min_error);
  fv_rel_distance_still_OK      = FUZZY_GET_FUZZY_VAL(&rel_distance_still_OK,rel_distance);
  fv_rel_distance_vfar          = FUZZY_GET_FUZZY_VAL(&rel_distance_vfar,rel_distance);
  fv_distance_min_error_veryshort= FUZZY_GET_FUZZY_VAL(&distance_min_error_veryshort,distance_min_error);
  fv_v_obj_standstill           = FUZZY_GET_FUZZY_VAL(&v_obj_standstill,v_obj);
  fv_v_obj_near_standstill      = FUZZY_GET_FUZZY_VAL(&v_obj_near_standstill,v_obj);
  //fv_a_obj_rolling              = FUZZY_GET_FUZZY_VAL(&a_obj_rolling,a_obj);
  fv_a_obj_rolling              = (signed_fuzzy_t)MAT_CALCULATE_PARAM_VALUE1D(a_obj_rolling_extended,HP_frules_aobj_rolling_points, (sint16)a_obj);
  fv_a_obj_accelerating         = FUZZY_GET_FUZZY_VAL(&a_obj_accelerating,a_obj);
  fv_speed_rel_littleslower     = FUZZY_GET_FUZZY_VAL(&speed_rel_littleslower,speed_rel);
  fv_softness_soft              = FUZZY_GET_FUZZY_VAL(&softness_soft,softness);
  fv_distance_set_error_near    = FUZZY_GET_FUZZY_VAL(&distance_set_error_near,distance_set_error);
  fv_distance_set_error_near_short = FUZZY_GET_FUZZY_VAL(&distance_set_error_near_short,distance_set_error);
  fv_speed_rel_much_slower      = FUZZY_GET_FUZZY_VAL(&speed_rel_much_slower,speed_rel);
  fv_v_own_urban                = FUZZY_GET_FUZZY_VAL(&v_own_urban,v_own);
  fv_v_own_city                 = FUZZY_GET_FUZZY_VAL(&v_own_city,v_own);
  fv_distance_min_error_to_far  = FUZZY_GET_FUZZY_VAL(&distance_min_error_to_far,distance_min_error);
  fv_a_obj_lowaccel             = FUZZY_GET_FUZZY_VAL(&a_obj_lowaccel,a_obj);
  fv_a_obj_lowbrake             = FUZZY_GET_FUZZY_VAL(&a_obj_lowbrake,a_obj);
  fv_speed_rel_same_speed       = FUZZY_GET_FUZZY_VAL(&speed_rel_same_speed,speed_rel);
  fv_speed_rel_same_speed_large = FUZZY_GET_FUZZY_VAL(&speed_rel_same_speed_large,speed_rel);
  fv_a_obj_braking              = FUZZY_GET_FUZZY_VAL(&a_obj_braking,a_obj);
  fv_v_own_stillstand           = FUZZY_GET_FUZZY_VAL(&v_own_stillstand,v_own);
  fv_v_own_vslow                = FUZZY_GET_FUZZY_VAL(&v_own_vslow,v_own);
  fv_speed_rel_faster           = FUZZY_GET_FUZZY_VAL(&speed_rel_faster,speed_rel);
  fv_speed_rel_slower           = FUZZY_GET_FUZZY_VAL(&speed_rel_slower,speed_rel);
  fv_rel_distance_close         = FUZZY_GET_FUZZY_VAL(&rel_distance_close,rel_distance);

  FUZZY_DEFUZZY_INIT((signed_fuzzy_t)-6000, (signed_fuzzy_t) 4000);

  /*Inference: summarize the output fuzzy set using sum-product inference method */
 
  /*Fuzzy-Rule   1: if(rel_distance_close & speed_rel_slower) -> a_out_brake (0.125)*/
  /*Headway intrusion and relative velocity negative (follow mode and approach)*/
  FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)  128, 
    FUZZY_PROD(
      fv_rel_distance_close,
      fv_speed_rel_slower)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )    
      ,1,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule   2: if(rel_distance_close & !speed_rel_faster & !v_own_stillstand) -> a_out_brake (0.010)*/
  /*Headway intrusion and no opening velocity (cut in of vehicle without opening velocity)*/
  FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)   10, 
    FUZZY_PROD(
      FUZZY_PROD(
        fv_rel_distance_close,
        FUZZY_NOT(
          fv_speed_rel_faster)),
      FUZZY_NOT(
        fv_v_own_stillstand))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,2,pFuzzyDebugData
#endif
    );


  /*Fuzzy-Rule   3: if(speed_rel_faster & !a_obj_braking) -> a_out_accelerate (0.258)*/
  /*Follow object that is faster than host vehicle*/
  FUZZY_DEFUZZY_ADD(&a_out_accelerate, (signed_fuzzy_t)  264, //256 
    FUZZY_PROD(
      fv_speed_rel_faster,
      FUZZY_NOT(
        fv_a_obj_braking))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,3,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule   4: if(speed_rel_same_speed & v_own_stillstand) -> a_out_roll (0.100)*/
  /*Decrease dynamics in the velocity range close to stand still*/
  FUZZY_DEFUZZY_ADD(&a_out_roll, (signed_fuzzy_t)  102, 
    FUZZY_PROD(
      fv_speed_rel_same_speed,
      fv_v_own_stillstand)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,4,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule   5: if(speed_rel_slower & !a_obj_lowaccel & !distance_min_error_to_far & !v_own_urban) -> a_out_brake (0.044)*/
  /*Decelerate to keep the headway above the alert headway at closing velocity and object not accelerating, urban roads excluded, this is handled by other rules. (approach)*/
  FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)   45, //30 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          fv_speed_rel_slower,
          FUZZY_NOT(
            fv_a_obj_lowaccel)),
        FUZZY_NOT(
          fv_distance_min_error_to_far)),
      FUZZY_NOT(
        fv_v_own_urban))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,5,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule   6: if(rel_distance_little_far & speed_rel_slightly_slower & a_obj_lowbrake) -> a_out_accelerate (0.039)*/
  /* To reduce positive distance deviation to object when in steady state conditions */
  FUZZY_DEFUZZY_ADD(&a_out_accelerate, (signed_fuzzy_t)    40, //40
    FUZZY_PROD(
        fv_rel_distance_little_far,
        FUZZY_PROD(fv_a_obj_lowbrake,
        fv_speed_rel_slightly_slower))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
    ,6,pFuzzyDebugData
#endif          
    );

  /*Fuzzy-Rule   7: if(rel_distance_vfar & a_obj_braking & !v_own_fast) -> a_out_roll (0.3)*/
  /*used to avoid decelerations on far away objects which are braking */
  FUZZY_DEFUZZY_ADD(&a_out_roll, (signed_fuzzy_t)    307, 
    FUZZY_PROD(
        FUZZY_PROD(
          fv_rel_distance_vfar,
          fv_a_obj_braking), 
        FUZZY_NOT(fv_v_own_fast))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
          ,7,pFuzzyDebugData
#endif          
    );

  /*Fuzzy-Rule   8: if(speed_rel_much_slower & !distance_set_error_near & !softness_soft & !v_own_urban) -> a_out_brake (0.005)*/
  /*used to avoid headway intrusion to much slower objects -> was 0.005*/
  FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)    5, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          fv_speed_rel_much_slower,
          FUZZY_NOT(
            fv_distance_set_error_near)),
        FUZZY_NOT(
          fv_softness_soft)),
      FUZZY_NOT(
        fv_v_own_urban))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,8,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule   9: if(!speed_rel_littleslower & a_obj_accelerating & distance_min_error_to_far) -> a_out_accelerate (0.176)*/
  /*Keep up with accelerating object when a certain minimum distance is given*/
  FUZZY_DEFUZZY_ADD(&a_out_accelerate, (signed_fuzzy_t)  180, //128
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_NOT(
          fv_speed_rel_littleslower),
        fv_a_obj_accelerating),
      fv_distance_min_error_to_far)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,9,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  10: if(!speed_rel_slower & a_obj_rolling & !v_obj_standstill) -> a_out_roll (0.100)*/
  /*Reduce dynamics during steady state following*/
  FUZZY_DEFUZZY_ADD(&a_out_roll, (signed_fuzzy_t)  102, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_NOT(
          fv_speed_rel_slower),
        fv_a_obj_rolling),
      FUZZY_NOT(
        fv_v_obj_standstill))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,10,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  11: if(a_obj_braking & distance_min_error_veryshort & !v_obj_standstill) -> a_out_brake (0.109)*/
  /*Decelerate to keep the headway above the alert headway when following a decelerating object. (follow mode)*/
  FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)  112, // 128 
    FUZZY_PROD(
      FUZZY_PROD(
        fv_a_obj_braking,
        fv_distance_min_error_veryshort),
      FUZZY_NOT(
        fv_v_obj_standstill))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,11,pFuzzyDebugData
#endif
    );
    
  /*Fuzzy-Rule  12: if(rel_distance_still_OK & !speed_rel_littleslower & !distance_min_error_short & softness_soft & !v_own_urban) -> a_out_roll (0.250)*/
  /*Reduce dynamics during steady state following with no high closing velocity while the headway error does not get to large and comfort setting.*/
  FUZZY_DEFUZZY_ADD(&a_out_roll, (signed_fuzzy_t)  256, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_PROD(
            fv_rel_distance_still_OK,
            FUZZY_NOT(
              fv_speed_rel_littleslower)),
          FUZZY_NOT(
            fv_distance_min_error_short)),
        fv_softness_soft),
      FUZZY_NOT(
        fv_v_own_urban))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,12,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  13: if(!speed_rel_littleslower & v_own_fast) -> a_out_roll (0.105)*/
  /*Reduce dynamics during steady state following with no high closing velocity.*/
  FUZZY_DEFUZZY_ADD(&a_out_roll, (signed_fuzzy_t)  108, //128
    FUZZY_PROD(
      FUZZY_NOT(
        fv_speed_rel_littleslower),
      fv_v_own_fast)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,13,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  14: if(rel_distance_still_OK & !speed_rel_slower & a_obj_accelerating & !softness_soft) -> a_out_accelerate (0.050)*/
  /*used to increase dynamic behind an accelerating object*/
  FUZZY_DEFUZZY_ADD(&a_out_accelerate, (signed_fuzzy_t)   51, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          fv_rel_distance_still_OK,
          FUZZY_NOT(
            fv_speed_rel_slower)),
        fv_a_obj_accelerating),
      FUZZY_NOT(
        fv_softness_soft))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,14,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  15: if(distance_min_error_near & a_obj_braking & v_own_urban) -> a_out_brake (0.1074)*/
  /* Decelerating in urban speeds in follow mode when object brakes */
  FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)    110,  
      FUZZY_PROD(
        FUZZY_PROD(
          fv_a_obj_braking,
          fv_distance_min_error_near),
        fv_v_own_urban)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,15,pFuzzyDebugData
#endif        
        );
    
  /*Fuzzy-Rule  16: if(!speed_rel_littlefaster & distance_min_error_below & v_own_urban) -> a_out_brake (0.050)*/
  /*Decelerate to keep the headway above the alert distance with no opening velocity on urban road. General rule is #22.*/
  FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)   51, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_NOT(
          fv_speed_rel_littlefaster),
        fv_distance_min_error_below),
      fv_v_own_urban)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,16,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  17: if(!rel_distance_close & speed_rel_faster & !a_obj_braking & v_own_slow) -> a_out_accelerate (1.5625)*/
  /*Keep up with faster object that is not to close and not decelerating in low speed range exclusive for low speed range. Rule 31 for high speed range.*/
  FUZZY_DEFUZZY_ADD(&a_out_accelerate, (signed_fuzzy_t)  256, //1600 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_NOT(
            fv_rel_distance_close),
          fv_speed_rel_faster),
        FUZZY_NOT(
          fv_a_obj_braking)),
      fv_v_own_slow)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,17,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  18: if(!rel_distance_close & !speed_rel_slower & a_obj_accelerating & v_own_slow) -> a_out_accelerate (1.000)*/
  /*Keep up with accelerating object that is not to close and no closing velocity in low speed range*/
  FUZZY_DEFUZZY_ADD(&a_out_accelerate, (signed_fuzzy_t) 1024, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_NOT(
            fv_rel_distance_close),
          FUZZY_NOT(
            fv_speed_rel_slower)),
        fv_a_obj_accelerating),
      fv_v_own_slow)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,18,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  19: if(rel_distance_far & !speed_rel_littleslower & !v_own_stillstand) -> a_out_accelerate (0.250)*/
  /*Keep the headway at the driver selected headway with no closing velocity. Exclude the velocity range close to standstill.*/
  FUZZY_DEFUZZY_ADD(&a_out_accelerate, (signed_fuzzy_t)  256, 
    FUZZY_PROD(
      FUZZY_PROD(
        fv_rel_distance_far,
        FUZZY_NOT(
          fv_speed_rel_littleslower)),
      FUZZY_NOT(
        fv_v_own_stillstand))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,19,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  20: if(rel_distance_OK & speed_rel_same_speed & a_obj_rolling) -> a_out_roll (0.078)*/
  /*Steady state following*/
  FUZZY_DEFUZZY_ADD(&a_out_roll, (signed_fuzzy_t)  80, // 102
    FUZZY_PROD(
      FUZZY_PROD(
        fv_rel_distance_OK,
        fv_speed_rel_same_speed),
      fv_a_obj_rolling)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,20,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  21: if(rel_distance_OK & !a_obj_hard_braking & !v_own_slow & !speed_rel_littleslower ) -> a_out_roll (0.016)*/
  /*Reduce dynamics during steady state following with no high object deceleration. */
  FUZZY_DEFUZZY_ADD(&a_out_roll, (signed_fuzzy_t)   16, //12 
    FUZZY_PROD(
      FUZZY_PROD(
        fv_rel_distance_OK,
        FUZZY_NOT(fv_a_obj_hard_braking)),
      FUZZY_PROD(
        FUZZY_NOT(fv_speed_rel_littleslower),
        FUZZY_NOT(fv_v_own_slow)))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,21,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  22: if(!speed_rel_modfaster & distance_min_error_below & !v_own_stillstand) -> a_out_brake (0.125)*/
  /*Decelerate to keep the headway above the alert distance with no opening velocity.*/
  FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)  128, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_NOT(
          fv_speed_rel_modfaster),
        fv_distance_min_error_below),
      FUZZY_NOT(
        fv_v_own_stillstand))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,22,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  23: if(speed_rel_slower & a_obj_hard_braking & distance_min_error_short & !v_own_fast) -> a_out_brake_hard (0.250)*/
  /*brake hard to avoid a crash if slower object is also braking very hard*/
  FUZZY_DEFUZZY_ADD(&a_out_brake_hard, (signed_fuzzy_t)  256, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          fv_speed_rel_slower,
          fv_a_obj_hard_braking),
        fv_distance_min_error_short),
      FUZZY_NOT(
        fv_v_own_fast))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,23,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  24: if(speed_rel_same_speed_large & a_obj_rolling & v_own_urban) -> a_out_roll (0.078125)*/
  /* At urban velocities, roll to reduce oscillations when vrel and obj acceleration are in bounds */
  FUZZY_DEFUZZY_ADD(&a_out_roll, (signed_fuzzy_t)    80, // 260
        FUZZY_PROD(
          FUZZY_PROD(
            fv_speed_rel_same_speed_large,
            fv_a_obj_rolling),
          fv_v_own_urban)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
          ,24,pFuzzyDebugData
#endif          
  );

  /*Fuzzy-Rule  25: if(a_obj_med_braking & distance_min_error_veryshort & v_own_city) -> a_out_brake_hard (0.254)*/
  /* brake hard to avoid a crash if object is also braking very hard. Introduced for larger KMC deceleration beyond -3 m/s^2 */
  FUZZY_DEFUZZY_ADD(&a_out_brake_hard, (signed_fuzzy_t)    260, 
      FUZZY_PROD(
        FUZZY_PROD(
          fv_a_obj_med_braking,
          fv_distance_min_error_veryshort), 
          fv_v_own_city)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
          ,25,pFuzzyDebugData
#endif      
    );

  /*Fuzzy-Rule  26: if(rel_distance_close & a_obj_hard_braking & distance_min_error_veryshort) -> a_out_brake_hard (0.125)*/
  /*brake hard to avoid a crash if object is also braking very hard*/
  FUZZY_DEFUZZY_ADD(&a_out_brake_hard, (signed_fuzzy_t)  128, 
    FUZZY_PROD(
      FUZZY_PROD(
        fv_rel_distance_close,
        fv_a_obj_hard_braking),
      fv_distance_min_error_veryshort)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,26,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  27: if(speed_rel_littleslower & !a_obj_lowaccel & distance_min_error_near & v_own_urban) -> a_out_brake (0.21)*/
  /*Reduce the relative velocity only when headway moves towards the alert headway, to prevent too early braking with respect to far objects on urban roads.*/
  FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)  215, // 256
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          fv_speed_rel_littleslower,
          FUZZY_NOT(
            fv_a_obj_lowaccel)),
        fv_distance_min_error_near),
      fv_v_own_urban)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,27,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  28: if(rel_distance_close & !speed_rel_littlefaster & v_obj_standstill) -> a_out_brake (0.125)*/
  /*brake to standstill*/
  FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)  128, 
    FUZZY_PROD(
      FUZZY_PROD(
        fv_rel_distance_close,
        FUZZY_NOT(
          fv_speed_rel_littlefaster)),
      fv_v_obj_standstill)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,28,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  29: if(!speed_rel_littleslower & !a_obj_braking & !distance_set_error_close & v_own_stillstand) -> a_out_roll (0.500)*/
  /*reduce dynamic in almost steady state */
  FUZZY_DEFUZZY_ADD(&a_out_roll, (signed_fuzzy_t)  512, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_NOT(
            fv_speed_rel_littleslower),
          FUZZY_NOT(
            fv_a_obj_braking)),
        FUZZY_NOT(
          fv_distance_set_error_close)),
      fv_v_own_stillstand)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,29,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  30: if(!speed_rel_much_slower & !a_obj_hard_braking & distance_set_error_not_close_enough & softness_very_dynamic & !v_own_urban & !distance_to_close) -> a_out_accelerate (0.500)*/
  /*Overtake maneuver: The target headway is artificially decreased based on the lane change probability.*/
  FUZZY_DEFUZZY_ADD(&a_out_accelerate, (signed_fuzzy_t)  512, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_PROD(
            FUZZY_PROD(
              FUZZY_NOT(
                fv_speed_rel_much_slower),
              FUZZY_NOT(
                fv_a_obj_hard_braking)),
            fv_distance_set_error_not_close_enough),
          fv_softness_very_dynamic),
        FUZZY_NOT(
          fv_v_own_urban)),
      FUZZY_NOT(
        fv_distance_to_close))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,30,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  31: if(speed_rel_littlefaster & !a_obj_braking & v_own_fast & v_obj_fast) -> a_out_accelerate (0.125)*/
  /*Keep up with faster object that is not decelerating in high speed range. Corresponding rule for low speed range is 17.*/
  FUZZY_DEFUZZY_ADD(&a_out_accelerate, (signed_fuzzy_t)  128, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          fv_speed_rel_littlefaster,
          FUZZY_NOT(
            fv_a_obj_braking)),
        fv_v_own_fast),
      fv_v_obj_fast)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,31,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  32: if(speed_rel_littleslower & !a_obj_lowaccel & !distance_set_error_not_close_enough & v_own_fast & v_obj_fast) -> a_out_brake (0.3125)*/
  /*Prevent release of brake pressure at the relative velocity zero crossing upon an approach. */
  FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)  320, //256 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_PROD(
            fv_speed_rel_littleslower,
            FUZZY_NOT(
              fv_a_obj_lowaccel)),
          FUZZY_NOT(
            fv_distance_set_error_not_close_enough)),
        fv_v_own_fast),
      fv_v_obj_fast)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,32,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule 33: if(!distance_min_error_short &softness_soft & a_obj_braking & !v_own_vfast) -> a_out_roll (0)*/
  /*Similar to R7, countermeasure to avoid decelerations on far objects which are braking */
  FUZZY_DEFUZZY_ADD(&a_out_roll, (signed_fuzzy_t)    0, //80 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_NOT(fv_v_own_vfast),
        FUZZY_PROD(fv_softness_soft,
          fv_a_obj_braking)), 
      FUZZY_NOT(fv_distance_min_error_short)  
      )
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
    ,33,pFuzzyDebugData
#endif          
    );

  /*Fuzzy-Rule  34: if(!a_obj_lowaccel & distance_set_error_to_close & v_own_fast & v_obj_fast) -> a_out_brake (0.050)*/
  /*Open up the gap when both vehicles have same velocity.*/
  FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)   51, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_NOT(
            fv_a_obj_lowaccel),
          fv_distance_set_error_to_close),
        fv_v_own_fast),
      fv_v_obj_fast)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,34,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  35: if(!speed_rel_much_slower & !a_obj_soft_braking & distance_set_error_to_far & !v_own_urban & !v_obj_urban) -> a_out_accelerate (0.125)*/
  /*get closer to an object in almost steady state with too long headway*/
  FUZZY_DEFUZZY_ADD(&a_out_accelerate, (signed_fuzzy_t)  128, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_PROD(
            FUZZY_NOT(
              fv_speed_rel_much_slower),
            FUZZY_NOT(
              fv_a_obj_soft_braking)),
          fv_distance_set_error_to_far),
        FUZZY_NOT(
          fv_v_own_urban)),
      FUZZY_NOT(
        fv_v_obj_urban))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,35,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  36: if(speed_rel_littleslower & !a_obj_lowaccel & a_obj_lowbrake & distance_min_error_short & v_obj_near_standstill) -> a_out_brake_hard (0.098)*/
  /* Hard brake at low object speeds where object not decelerating. Primarily for low speed approaches where TTS controller is inactive */
  FUZZY_DEFUZZY_ADD(&a_out_brake_hard, (signed_fuzzy_t)    100, //100
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_PROD(
            fv_speed_rel_littleslower,
            FUZZY_PROD(
              fv_a_obj_lowbrake,
              FUZZY_NOT(
                fv_a_obj_lowaccel))),
          fv_distance_min_error_short),
        fv_v_obj_near_standstill)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
          ,36,pFuzzyDebugData
#endif          
          );

  /*Fuzzy-Rule  37: if(speed_rel_littleslower & a_obj_rolling & !distance_set_error_not_close_enough & !v_own_urban) -> a_out_brake (0.1)*/
  /*react on little slower objects*/
  FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)   102, //76
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          fv_speed_rel_littleslower,
          fv_a_obj_rolling),
        FUZZY_NOT(
          fv_distance_set_error_not_close_enough)),
      FUZZY_NOT(
        fv_v_own_urban))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,37,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  38: if(a_obj_braking & distance_set_error_to_far & !v_own_urban) -> a_out_roll (0.125)*/
  /*avoid over-reaction to braking objects in far distance*/
  FUZZY_DEFUZZY_ADD(&a_out_roll, (signed_fuzzy_t)  128, 
    FUZZY_PROD(
      FUZZY_PROD(
        fv_a_obj_braking,
        fv_distance_set_error_to_far),
      FUZZY_NOT(
        fv_v_own_urban))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,38,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  39: if(speed_rel_really_slower & !a_obj_lowaccel & distance_min_error_short & v_own_urban & v_obj_urban) -> a_out_brake (0.750)*/
  /*decrease relative speed if close to max intrusion distance*/
  FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)  768, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_PROD(
            fv_speed_rel_really_slower,
            FUZZY_NOT(
              fv_a_obj_lowaccel)),
          fv_distance_min_error_short),
        fv_v_own_urban),
      fv_v_obj_urban)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,39,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  40: if(!speed_rel_littleslower & !a_obj_soft_braking & distance_set_error_more_than_requested & !v_own_urban) -> a_out_accelerate (0.063)*/
  /*rule for keeping the headway on highways if the object slightly accelerates*/
  FUZZY_DEFUZZY_ADD(&a_out_accelerate, (signed_fuzzy_t)   64, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_NOT(
            fv_speed_rel_littleslower),
          FUZZY_NOT(
            fv_a_obj_soft_braking)),
        fv_distance_set_error_more_than_requested),
      FUZZY_NOT(
        fv_v_own_urban))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,40,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  41: if(!a_obj_braking & !distance_set_error_more_than_requested & v_own_slow) -> a_out_roll (0.125)*/
  /*reduce dynamics if enough distance is left*/
  FUZZY_DEFUZZY_ADD(&a_out_roll, (signed_fuzzy_t)  128, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_NOT(
          fv_a_obj_braking),
        FUZZY_NOT(
          fv_distance_set_error_more_than_requested)),
      fv_v_own_slow)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,41,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  42: if(rel_distance_far & !speed_rel_much_slower & !a_obj_soft_braking & v_own_urban & v_obj_urban) -> a_out_accelerate (0.150)*/
  /*for long range approach to very slow objects*/
  FUZZY_DEFUZZY_ADD(&a_out_accelerate, (signed_fuzzy_t)  153, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_PROD(
            fv_rel_distance_far,
            FUZZY_NOT(
              fv_speed_rel_much_slower)),
          FUZZY_NOT(
            fv_a_obj_soft_braking)),
        fv_v_own_urban),
      fv_v_obj_urban)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,42,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  43: if(!speed_rel_littleslower & distance_set_error_more_than_requested & v_own_slow) -> a_out_accelerate (0.500)*/
  FUZZY_DEFUZZY_ADD(&a_out_accelerate, (signed_fuzzy_t)  512, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_NOT(
          fv_speed_rel_littleslower),
        fv_distance_set_error_more_than_requested),
      fv_v_own_slow)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,43,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  44: if(!speed_rel_slower & distance_set_error_not_close_enough & v_own_stillstand) -> a_out_accelerate (0.200)*/
  FUZZY_DEFUZZY_ADD(&a_out_accelerate, (signed_fuzzy_t)  204, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_NOT(
          fv_speed_rel_slower),
        fv_distance_set_error_not_close_enough),
      fv_v_own_stillstand)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,44,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  45: if(!speed_rel_littlefaster & a_obj_lowaccel & !distance_set_error_to_far & v_own_urban) -> a_out_brake (0.013)*/
  FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)   13, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_NOT(
            fv_speed_rel_littlefaster),
          fv_a_obj_lowaccel),
        FUZZY_NOT(
          fv_distance_set_error_to_far)),
      fv_v_own_urban)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,45,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  46: if(rel_distance_far & !speed_rel_littleslower & a_obj_lowaccel & v_own_urban & v_obj_urban) -> a_out_accelerate (0.250)*/
  FUZZY_DEFUZZY_ADD(&a_out_accelerate, (signed_fuzzy_t)  256, 
    FUZZY_PROD(
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_PROD(
            fv_rel_distance_far,
            FUZZY_NOT(
              fv_speed_rel_littleslower)),
          fv_a_obj_lowaccel),
        fv_v_own_urban),
      fv_v_obj_urban)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,46,pFuzzyDebugData
#endif
    );

  /*Fuzzy-Rule  47: if(!speed_rel_slower & !distance_set_error_near_short & fv_v_own_vslow) -> a_out_brake_hard (0.5)*/
  /* Brake at very low distances for safety */
  FUZZY_DEFUZZY_ADD(&a_out_brake_hard, (signed_fuzzy_t)    512, 
      FUZZY_PROD(
        FUZZY_NOT(
          fv_distance_set_error_near_short),
        FUZZY_PROD(
          fv_v_own_vslow,
          fv_speed_rel_slower))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,47,pFuzzyDebugData
#endif          
    );

  /*Fuzzy-Rule  47: (!NOT ACTIVE!) if(!speed_rel_faster & distance_min_error_to_close & v_own_urban) -> a_out_brake (0.000)*/
  /*not used due to !very! low relevance (was 1.0)*/
  /*FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)    0, 
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_NOT(
            fv_speed_rel_faster),
          fv_distance_min_error_to_close),
        fv_v_own_urban)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
        ,47,pFuzzyDebugData
#endif        
    );*/

  /*Fuzzy-Rule  48: (!NOT ACTIVE!) if(speed_rel_slower & a_obj_hard_braking & distance_min_error_below & !v_own_fast) -> a_out_brake_hard (0.000)*/
  /*not used due to !very! low relevance (was 1.0)*/
  /*FUZZY_DEFUZZY_ADD(&a_out_brake_hard, (signed_fuzzy_t)    0, 
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_PROD(
            fv_speed_rel_slower,
            fv_a_obj_hard_braking),
          fv_distance_min_error_below),
        FUZZY_NOT(
          fv_v_own_fast))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
          ,48,pFuzzyDebugData
#endif            
    );*/

  /*Fuzzy-Rule   49: (!NOT ACTIVE!) if(speed_rel_much_slower & distance_min_error_near & !v_own_urban) -> a_out_brake (0.000)*/
  /*used to avoid headway intrusion to much slower objects -> was 0.001 Decelerate to keep the headway above the alert headway at high closing velocity, urban roads excluded; this is handled by rule 15. (approach)*/
  /*FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)    0, 
      FUZZY_PROD(
        FUZZY_PROD(
          fv_speed_rel_much_slower,
          fv_distance_min_error_near),
        FUZZY_NOT(
          fv_v_own_urban))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
          ,49,pFuzzyDebugData
#endif            
    );*/

  /*Fuzzy-Rule   50: (!NOT ACTIVE!) if(speed_rel_slower & !a_obj_lowaccel & !distance_set_error_to_far & !softness_soft & !v_own_urban) -> a_out_brake (0.000)*/
  /*not used due to !very! low relevance (was 0.005) Decelerate to keep the headway above the driver selected headway at closing velocity and object not accelerating, at high speed. (high speed approach)*/
  /*FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)    0, 
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_PROD(
            FUZZY_PROD(
              fv_speed_rel_slower,
              FUZZY_NOT(
                fv_a_obj_lowaccel)),
            FUZZY_NOT(
              fv_distance_set_error_to_far)),
          FUZZY_NOT(
            fv_softness_soft)),
        FUZZY_NOT(
          fv_v_own_urban))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
          ,50,pFuzzyDebugData
#endif            
    );*/

  /*Fuzzy-Rule  51: (!NOT ACTIVE!) if(rel_distance_close & speed_rel_littleslower & v_own_fast & v_obj_fast) -> a_out_brake (0.000)*/
  /*not used due to !very! low relevance (was 0.125)*/
  /*FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)    0, 
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_PROD(
            fv_rel_distance_close,
            fv_speed_rel_littleslower),
          fv_v_own_fast),
        fv_v_obj_fast)
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
    ,51,pFuzzyDebugData
#endif          
    ); */

  /*Fuzzy-Rule  52: (!NOT ACTIVE!) if(speed_rel_very_much_slower & !a_obj_lowaccel & !distance_set_error_near & !v_own_urban) -> a_out_brake (0.000)*/
  /*not used due to !very! low relevance (was 0.25) - rules 5/6/8 are sufficient*/
  /*FUZZY_DEFUZZY_ADD(&a_out_brake, (signed_fuzzy_t)    0, 
      FUZZY_PROD(
        FUZZY_PROD(
          FUZZY_PROD(
            fv_speed_rel_very_much_slower,
            FUZZY_NOT(
              fv_a_obj_lowaccel)),
          FUZZY_NOT(
            fv_distance_set_error_near)),
        FUZZY_NOT(
          fv_v_own_urban))
#if ( FCT_CFG_DEBUG_FUZZY_CONTROLLER )
      ,52,pFuzzyDebugData
#endif            
      );*/

  return FUZZY_DEFUZZY();
#ifdef FCT_SIMULATION
  }
  else
  {
    signed long int sim[32];
    sim[0] = rel_distance;
    sim[1] = speed_rel;
    sim[6] = v_own;
    sim[2] = a_obj;
    sim[4] = distance_min_error;
    sim[3] = distance_set_error;
    sim[5] = softness;
    sim[7] = v_obj;
    sim[8] = distance;
    return (signed_fuzzy_t)calcFuzzy(sim);
}
#endif
} // PRQA S 7012
/* date: 2015-09-16, reviewer: Chirag Patel, reason: Not safety critical */

#endif  /* ((FCT_CFG_LOHP_COMPONENT) && (FCT_CFG_ACC_HEADWAY_PLANNER)) */


/** @} end defgroup */

