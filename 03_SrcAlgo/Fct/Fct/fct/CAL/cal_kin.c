/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_kin.c

DESCRIPTION:               Physical Funktion of all kinematical functions

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            Revision: 1.9.1.1


**************************************************************************** */

#include "cal_int.h" /* PRQA S 0380
date: 28/06/2019 author: Pruthvi Reason: Can be ignored as no functional impact */

#if ((FCT_CFG_ACC_CAL) && (FCT_CFG_LOHP_COMPONENT))
static times_t PHYS_CALCULATE_TTC_NO_ONCOMING(const velocity_t ObjectVelocity, const acceleration_t ObjectAccel, const velocity_t HostVelocity, const acceleration_t HostAccel, const distance_t ObjectDistance, velocity_t *ImpactVelocity);

/*************************************************************************************************************************
  Functionname:    PHYS_CALC_NEEDED_DECEL                                                                           */ /*!

  @brief           Calculate the acceleration needed to avoid a crash

  @description     Calculate the acceleration needed to avoid a crash

                    @startuml
                    Start
                    Partition PHYS_CALC_NEEDED_DECEL {
                        If (relative velocity is less than zero) then (TRUE)
                         - calculate own speed after reaction time
                         - calculate relative speed after reaction time
                         - calculate remaining braking distance after reaction time
                         - calculate needed acceleration (deceleration)
                         If(Object longititudnal accelaration is less than -100) the (TRUE)
                          If( differnce of needed accelaration and object accelaration is lesser than -100) then (TRUE)
                           - host time is calculated based on needed accelaration, velocity
                           - calculate time for host needs to come to a full stop
                           - calculate time for object needs to come to a full stop
                           If (Object will come to a stop, while host vehicle is still moving) then (TRUE)
                            -Calculate distance to brake
                            -calculate needed acceleration
                           Endif
                          Else(FALSE)
                           -Needed accelaraton required is set zero
                          Endif
                         EndIF
                        endif
                        -Needed accelaration is limited to maximum of possible physical decelaration
                    }
                    End
                    @enduml


  @return          needed_accel : needed acceleration to avoid crash [full range of acceleration_t defined in Rte_Type.h]

  @param[in]       long_accel             [full range of type acceleration_t defined in Rte_Type.h]
  @param[in]       long_velocity          [full range of type velocity_t defined in Rte_Type.h]
  @param[in]       reaction_time          [full range of type times_t defined in Rte_Type.h]
  @param[in]       obj_rel_long_velocity  [full range of type velocity_t defined in Rte_Type.h]
  @param[in]       obj_rel_long_accel     [full range of type acceleration_t defined in Rte_Type.h]
  @param[in]       obj_long_velocity      [full range of type velocity_t defined in Rte_Type.h]
  @param[in]       obj_long_accel         [full range of type velocity_t defined in Rte_Type.h]
  @param[in]       obj_long_diplacement   [full range of type distance_t defined in Rte_Type.h]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library  
  @c_switch_full   FCT_CFG_LOHP_COMPONENT  : Configuration switch for component LOHP

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-522-0009fc80">CAL_522</a> \n

                   @created         -
  @changed         5/31/2016

  @author          -
*************************************************************************************************************************/
acceleration_t PHYS_CALC_NEEDED_DECEL(const acceleration_t long_accel, const velocity_t long_velocity, times_t reaction_time, const velocity_t obj_rel_long_velocity, const acceleration_t obj_rel_long_accel, const velocity_t obj_long_velocity, const acceleration_t obj_long_accel, const distance_t obj_long_diplacement)
{ 
#define Phys_vehicle_max_decel  (-10000)
#define Phys_min_brake_distance (10) /*must be above zero!*/
#define Phys_object_accel_thres (-100) /*must be below zero!*/

  distance_t     braking_distance;
  velocity_t     v_host_after_t_react;
  velocity_t     v_rel_after_t_react;
  times_t        t_host;
  times_t        t_obj;
  acceleration_t needed_accel;
  sint32         localhelper1, localhelper2; 

  if (obj_rel_long_velocity < (velocity_t)0) 
  {
    /*calculate own speed after reaction time*/
    localhelper1 = (sint32)long_accel * (sint32)reaction_time;
    localhelper1 /= (sint32)Time_s;
    localhelper1 *= (sint32)Velocity_s;
    localhelper1 /= (sint32)Acceleration_s;
    
    localhelper1 = (sint32)long_velocity + localhelper1;
    v_host_after_t_react = (velocity_t)MAT_LIM(localhelper1,(sint32)0,(sint32)Speed_max);
   

    /*calculate relative speed after reaction time*/
    localhelper1 = (sint32)obj_rel_long_accel * (sint32)reaction_time;
    localhelper1 /= (sint32)Time_s;
    localhelper1 *= (sint32)Velocity_s;
    localhelper1 /= (sint32)Acceleration_s;

    localhelper1 = (sint32)obj_rel_long_velocity + localhelper1;
    v_rel_after_t_react = (velocity_t)MAT_LIM(localhelper1,(sint32)Speed_min,(sint32)Speed_max);

    /*calculate remaining braking distance after reaction time*/
    /* d1 = t*v_rel */
    localhelper1 = (sint32)reaction_time * (sint32)obj_rel_long_velocity; 
    localhelper1 /= (sint32)Velocity_s;
    localhelper1 *= (sint32)Distance_s;
    /*scaled by Time_s*/

    /* d2 = arel*t� */
    localhelper2 = (sint32)reaction_time * (sint32)reaction_time;
    localhelper2 /= (sint32)Time_s;
    localhelper2 *= (sint32)obj_rel_long_accel;
    localhelper2 /= (sint32)Acceleration_s;
    localhelper2 *= (sint32)Distance_s;
    /*scaled by Time_s*/

    /* d_rel = d1 + 1/2 * d2*/
    localhelper1 += localhelper2 / (sint32)2;
    localhelper1 /= (sint32)Time_s; 
    localhelper1 += (sint32)obj_long_diplacement;
    braking_distance = (distance_t)MAT_LIM(localhelper1,(sint32)Phys_min_brake_distance,(sint32)Distance_max);


    /*calculate needed acceleration (deceleration)*/
    localhelper1 = (sint32)v_rel_after_t_react * (sint32)v_rel_after_t_react;
    localhelper1 /= (sint32)2*(sint32)Velocity_s;
    localhelper1 *= (sint32)Distance_s;
    localhelper1 /= (sint32)braking_distance;
    localhelper1 *= (sint32)Acceleration_s;
    localhelper1 /= (sint32)Velocity_s;

    localhelper2 = (sint32)long_accel + (sint32)obj_rel_long_accel - localhelper1;

    needed_accel = (acceleration_t)MAT_LIM(localhelper2,(sint32)Accel_min,(sint32)Accel_max);

    if (obj_long_accel < Phys_object_accel_thres) 
    {
      if ((needed_accel - obj_long_accel) < Phys_object_accel_thres) 
      {
        localhelper1 = (sint32)v_rel_after_t_react;
        localhelper1 *= ((sint32)Acceleration_s);
        /*comment: div/0 -> needed_accel-obj_long_accel will always be below zero!*/
        localhelper1 /= ( ((sint32)needed_accel) - ((sint32)obj_long_accel) );
        localhelper1 *= ((sint32)Time_s);
        localhelper1 /= ((sint32)Velocity_s);

        localhelper1 = (sint32)reaction_time + localhelper1;
        t_host = (times_t)MAT_LIM(localhelper1,(sint32)Time_min,(sint32)Time_max);
      }
      else 
      {
        t_host = (times_t)0;
      }

      /*time, the object needs to come to a full stop*/
      localhelper1 = (sint32)(-obj_long_velocity);
      localhelper1 *= ((sint32)Acceleration_s);
      /*comment: div/0 -> obj_long_accel will always be below zero!*/
      localhelper1 /= ((sint32)obj_long_accel);
      localhelper1 *= ((sint32)Time_s);
      localhelper1 /= ((sint32)Velocity_s);

      t_obj = (times_t)MAT_LIM(localhelper1,(sint32)Time_min,(sint32)Time_max);
   
      if (t_obj < t_host) 
      {

        /* Object will come to a stop, while host vehicle is still moving */
        localhelper1 = (sint32)obj_long_velocity * (sint32)obj_long_velocity;
        localhelper1 /= (sint32)Velocity_s;
        localhelper1 *= (sint32)Distance_s;
        /*comment: div/0 -> obj_long_accel will always be below zero!*/
        localhelper1 /= (((sint32)2) * ((sint32)obj_long_accel));
        localhelper1 *= (sint32)Acceleration_s;
        /*scaled by Velocity_s*/

        localhelper2 = (sint32)reaction_time * (sint32)long_velocity;
        localhelper2 /= (sint32)Time_s;
        localhelper2 *= (sint32)Distance_s;
        /*scaled by Velocity_s*/

        localhelper1 += localhelper2;
        localhelper1 /= (sint32)Velocity_s;

        localhelper2 = (sint32)reaction_time * (sint32)reaction_time / (sint32)2;
        localhelper2 /= (sint32)Time_s;
        localhelper2 *= (sint32)long_accel;
        localhelper2 /= (sint32)Time_s;
        localhelper2 *= (sint32)Distance_s;
        localhelper2 /= (sint32)Acceleration_s;

        /*distance to brake*/
        localhelper1 = ((sint32)obj_long_diplacement - localhelper2) - localhelper1;

        braking_distance = (distance_t)MAT_LIM(localhelper1,(sint32)Phys_min_brake_distance,(sint32)Distance_max);
      
        /*get needed acceleration*/
        localhelper1 = (sint32)-v_host_after_t_react * (sint32)v_host_after_t_react;
        localhelper1 /= (sint32)Velocity_s;
        localhelper1 *= (sint32)Acceleration_s;
        /*comment: div/0 -> braking_distance will always be above zero!*/
        localhelper1 /= ( ((sint32)2) * ((sint32)braking_distance) );
        localhelper1 *= (sint32)Distance_s;
        localhelper1 /= (sint32)Velocity_s;
        needed_accel = (acceleration_t)MAT_LIM(localhelper1,(sint32)Accel_min,(sint32)Accel_max);
      }
    }
  }
  else 
  {
    needed_accel = (acceleration_t)0;
  }

  needed_accel = (acceleration_t)MAT_MAX((sint32)needed_accel, (sint32)Phys_vehicle_max_decel);

  return needed_accel;
}

/*************************************************************************************************************************
  Functionname:    PHYS_CALCULATE_TTC_NO_ONCOMING                                                                   */ /*!

  @brief           calculates the ttc to an object that will not come to a full stop after (eventually) the host vehicle has come to a full stop

  @description     calculates the ttc to an object that will not come to a full stop after (eventually) the host vehicle has come to a full stop

                    @startuml
                    Start
                        Partition PHYS_CALCULATE_TTC_NO_ONCOMING {
                        :Read the input velocity & acceleration of Host and Object and the distance between them;
                        :Calculate the change in velocity & acceleration of host & object;
                        If (** Is the change in acceleratoin equal to zero ?**) then (Yes)
                            If (** Is the change in speed equal to zero ?**) then (Yes)
                                :Both the Host and Object are at same speed
                                And hence time to collision(ttc) is set to the maximum;    
                            Else
                                :Find the difference of the speed of host & object;
                                If(**Is the above difference negative ?**) then (Yes)
                                    :The object is faster than the host,
                                    And hence time to collision(ttc) is set to the maximum;    
                                Else (No)
                                    :The object is slower than the host,
                                    Calculate the time to collision(ttc);
                                Endif
                            Endif
                        Else (No)
                            :There is a difference in acceleration of host & object;
                            :Calculate the parameter D;
                            If (**D is greater than 0 ?**) then (Yes)
                                If(Is calculated D greater than 0 ?) then (Yes)
                                    :Square root factor is the minimum between factor_s(1000) and signed max devided by D;
                                Else(No)
                                    :Squareroot factor is factor_s(1000);
                                Endif
                                :Do calculation of D from factor_s & square root factor;
                                :Calculate time to collision-1;
                                If(Is the calculated time to collision-1 less than zero ?)then(Yes)
                                    :Set the time to collision-1 to the maximum time;
                                Endif
                                :Calculate time to collision-2;
                                If(Is the calculated time to collision-2 less than zero ?)then(Yes)
                                    :Set the time to collision-2 to the maximum time;
                                Endif
                                If(**Is time to collision-1 greater than time to collision-2 ?**) then (Yes)
                                    :time to collision is the minimum between time to collision-2 & MaxTime;
                                Else(No)
                                    :time to collision is the minimum between time to collision-1 & MaxTime;
                                Endif
                            Else (No)
                                : time to collision(ttc) is set to the maximum;
                            Endif
                        Endif

                        If (**If the direction of acceleration & speed is different AND if object has come to full stop ?**) then (Yes)
                            : set object velocity at impact to zero;
                            : calculate the parameter help using the input acceleration, time, velocity;
                            If(**Sign of the parameter help and object velocity is same ?**) then (yes)
                                : Object has come to a full stop;
                                : Calculate the distance to stopped object;
                                If(**Is Acceleration of the host vehicle equal to zero ?**) then (Yes)
                                    If (**Is Velocity of the host equal to zero ?**) then (yes)
                                        : Set the time to collision to zero;
                                    Else(no)
                                        :calculate the time to collision from the input velocity, acceleration, distance to object;
                                    Endif
                                Else(No)
                                    :Calculate the parameter D;
                                    If (**D is greater than 0 ?**) then (Yes)
                                        If(Is calculated D greater than 0 ?) then (yes)
                                            :Square root factor is the minimum between factor_s(1000) and signed max devided by D;
                                        Else(No)
                                            :Squareroot factor is factor_s(1000);
                                        Endif
                                        :Do calculation of D from factor_s & square root factor;
                                        :Calculate time to collision-1;
                                        If(Is the calculated time to collision:1 less than zero ?)then(Yes)
                                            :Set the time to collision:1 to the maximum time;
                                        Endif
                                        :Calculate time to collision:2;
                                        If(Is the calculated time to collision:2 less than zero ?)then(Yes)
                                            :Set the time to collision:2 to the maximum time;
                                        Endif
                                If(**Is time to collision:1 greater than time to collision:2 ?**) then (Yes)
                                    :time to collision is the minimum between time to collision:2 & MaxTime;
                                Else(No)
                                    :time to collision is the minimum between time to collision:1 & MaxTime;
                                Endif
                                    Else(No)
                                        :Set the time to collision to the maximum time;
                                    Endif
                                If(**If the direction of acceleration & speed is different AND if host came also to stand ?**) then (Yes)
                                    : calculate the parameter help using the input acceleration, time, velocity;
                                    If(Sign of the parameter help and velocity is same ?) then(yes)
                                        :Host came to full stop and hence the time to collision is the maxuimum;
                                    Endif
                                Endif
                                Endif
                            Else(No)
                                :object is still moving after ttc;
                                :Calculate the object velocity during ttc;
                            Endif
                        Else
                            :object is still moving after ttc or ttc is higher;
                            :Calculate the object velocity during ttc;
                        Endif
                        If (** Is time to collision less than maximum relevent ttc ?**) then(Yes)
                            :Calculat ethe parameter help using the inputs acceleration, velocity, time, ttc;
                        Else(No)
                            :Set the parameter setg to zero;
                        Endif

                        :Calculate the ImpactVelocity to keep with in the limit of the parameter help and maximum speed;
                        }
                    Stop
                    @enduml

  @return          ttc : time to collision [static type times_t defined in Rte_Type.h; full range]

  @param[in]       ObjectVelocity     [full range of type velocity_t defined in Rte_Type.h]
  @param[in]       ObjectAccel        [full range of type acceleration_t defined in Rte_Type.h]
  @param[in]       HostVelocity       [full range of type velocity_t defined in Rte_Type.h]
  @param[in]       HostAccel          [full range of type acceleration_t defined in Rte_Type.h]
  @param[in]       ObjectDistance     [full range of ype distance_t defined in Rte_Type.h]
  @param[in,out]   *ImpactVelocity    [Pointer of the type velocity_t defined in Rte_Type.h]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library  
  @c_switch_full   FCT_CFG_LOHP_COMPONENT  : Configuration switch for component LOHP

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-523-0009fc80">CAL_523</a> \n

  @created         -
  @changed         5/31/2016

  @author          -
*************************************************************************************************************************/
static times_t PHYS_CALCULATE_TTC_NO_ONCOMING(const velocity_t ObjectVelocity, const acceleration_t ObjectAccel, const velocity_t HostVelocity, const acceleration_t HostAccel, const distance_t ObjectDistance, velocity_t *ImpactVelocity)
{
#define Phys_max_relevant_ttc (times_t)20000

  velocity_t     dv;
  acceleration_t da;
  times_t        ttc;
  sint32         help, help2;
  sint32         D;
  velocity_t     vh;
  acceleration_t ah;
  velocity_t     v_obj_at_ttc;
  sint32         sqrt_factor;
 
  vh = HostVelocity;
  ah = HostAccel;
  ttc = Time_max;
  v_obj_at_ttc = ObjectVelocity;
  
  /*delta_a = a_host - a_object*/
  da = (acceleration_t)((sint32)ObjectAccel - (sint32)HostAccel);
  
  /*delta_v = v_host - v_object*/
  dv = (acceleration_t)((sint32)ObjectVelocity - (sint32)HostVelocity);

  if(da == 0)
  {
    /*same acceleration*/
    if(dv == 0)
    {
      /*same speed*/
      ttc = Time_max;      
    }
    else
    {
      /*ttc = -d/dv*/      
      help = MAT_DIV(-ObjectDistance, dv, Distance_s, Velocity_s, Time_s);
      if(help < (sint32)0)
      { 
        /*object faster*/
        ttc = Time_max;
      }
      else
      {
        ttc = (times_t)MAT_MIN(help,(sint32)Time_max);
      }      
    }
  }
  else
  {
    /*difference in acceleration*/

    /*vh� + vo� + 2 * (d * da - vh * vo)*/
    /*vh�*/
    D = MAT_MUL(vh, vh, Velocity_s, Velocity_s, Factor_s);
    

    /*vo�*/
    help = MAT_MUL(ObjectVelocity, ObjectVelocity, Velocity_s, Velocity_s, Factor_s);
    

    /*vh� + vo�*/
    D+= help;

    /*d * da*/    
    help = MAT_MUL(-da, ObjectDistance, Distance_s, Acceleration_s, Factor_s);

    /*vh * vo*/    
    help2 = MAT_MUL(vh, ObjectVelocity, Velocity_s, Velocity_s, Factor_s);

    /*d * da - vh * vo*/
    help-= help2;
    
    /*vh� + vo� + 2 * (d * da - vh * vo)*/
    D+= (sint32)2 * help;

    if(D >= (sint32)0)
    {
      /*calculate max factor for D to get highest accuracy of sqrt(D)*/
      if(D > 0)
      {
        sqrt_factor = MAT_MIN((Signed_int32_max) / D, Factor_s);
      }
      else
      {
        sqrt_factor = Factor_s;
      }
      
      D*= sqrt_factor;
      D/= (sint32)Factor_s;
      D*= sqrt_factor;

      D = MAT_SQRT(D);
      D*= (sint32)Acceleration_s;
      D/= sqrt_factor;
      D*= (sint32)Velocity_s;
      

      /*ttc1 = (-dv + sqrt(D)) / da*/
      help = -(sint32)dv * (sint32)Acceleration_s;
      help+= D;
      help/= (sint32)Velocity_s;
      help*= (sint32)Time_s;
      help/= (sint32)da;
      if(help < (sint32)0)
      {
        help = (sint32)Time_max;
      }

      /*ttc2 = (-dv - sqrt(D)) / da*/
      help2 = (sint32)-dv * (sint32)Acceleration_s;
      help2-= D;
      help2/= (sint32)Velocity_s;
      help2*= (sint32)Time_s;
      help2/= (sint32)da;
      if(help2 < (sint32)0)
      {
        help2 = (sint32)Time_max;
      }

      if(help >= help2)
      {        
        ttc = (times_t)MAT_MIN(help2, (sint32)Time_max);       
      }
      else
      {
        ttc = (times_t)MAT_MIN(help, (sint32)Time_max);       
      }
    }
    else
    {
      ttc = Time_max;
    }
  }

  /*check if object has come to full stop while ttc*/
  if(
     (MAT_SIGN(ObjectAccel) != MAT_SIGN(ObjectVelocity)) /*if direction of acceleration is different to direction of speed*/     
     &&
     (ObjectAccel != 0)
    )
  {
    /*set object velocity at impact to 0*/
    v_obj_at_ttc = 0;

    /*v_ttc = vo + ao*ttc*/    
    help = MAT_MUL(ObjectAccel, (sint32)ttc, Acceleration_s, Time_s, Velocity_s);
    help+= (sint32)ObjectVelocity;

    if(MAT_SIGN(help) != MAT_SIGN(ObjectVelocity))
    {
      /*object has come to a full stop*/
      /*time to stop: t = -vo/ao */  
      
      help = MAT_DIV(-ObjectVelocity, ObjectAccel, Velocity_s, Acceleration_s, Time_s);
      ttc = (times_t)MAT_LIM(help, 0, (sint32)Time_max);

      /*d_remain = a/2*t� + v*t + s*/
      /*a/2*t�*/      
      help = (sint32)ObjectAccel;
      help*= (sint32)ttc;
      help/= (sint32)2;
      help/= (sint32)Acceleration_s;
      help*= (sint32)ttc;
      help/= (sint32)Time_s;
      help*= (sint32)Distance_s;
      help/= (sint32)Time_s;

      /*v*t*/
      help2 = MAT_MUL(ObjectVelocity, (sint32)ttc, Velocity_s, Time_s, Distance_s);      
      help+= help2;
      /*+s*/
      help+= (sint32)ObjectDistance;
      /*distance to stopped object stored in help (d_remain)*/

      if(ah == 0) 
      {
        if(vh == 0)
        {
          ttc = Time_max;
        }
        else
        {
          /*ttc = d_remain/vh*/
          help2 = MAT_DIV(help, vh, Distance_s, Velocity_s, Time_s);  
          ttc = (times_t)MAT_LIM(help2, 0, (sint32)Time_max);          
        }
      }
      else
      {
        /*D = v�+2*a*d_remain*/
        D = MAT_MUL(vh, vh, Velocity_s, Velocity_s, Factor_s);
        
        /*2*a*d_remain*/       
        help2 = MAT_MUL((sint32)2*(sint32)ah, help, Acceleration_s, Distance_s, Factor_s);

        D+= help2;

        /*D is scaled by local_factor�*/
        if(D >= (sint32)0)
        {
          /*calculate max factor for D to get highest accuracy of sqrt(D)*/
          if(D > 0)
          {
            sqrt_factor = MAT_MIN(Signed_int32_max / D, Factor_s);
          }
          else 
          {
            sqrt_factor = Factor_s;
          }
          
          D*= sqrt_factor;
          D/= (sint32)Factor_s;
          D*= sqrt_factor;
          /*D = sqrt(D)*/
          D = MAT_SQRT(D);          
          D*= (sint32)Acceleration_s;
          D/= sqrt_factor;
          D*= (sint32)Velocity_s;

          /*-(vh-D)/a*/
          help = (sint32)vh * (sint32)Acceleration_s;
          help-= D;          
          help/= (sint32)Velocity_s;
          help*= (sint32)Time_s;          
          help/= -(sint32)ah;
          if(help < (sint32)0)
          {
            help = (sint32)Time_max;
          }

          /*-(vh+D)/a*/
          help2 = (sint32)vh * (sint32)Acceleration_s;
          help2+= D;          
          help2/= (sint32)Velocity_s;          
          help2*= (sint32)Time_s;
          help2/= -(sint32)ah;
          if(help2 < (sint32)0)
          {
            help2 = (sint32)Time_max;
          }

          /*take smaller positive ttc as real ttc*/
          if(help >= help2)
          {        
            ttc = (times_t)MAT_MIN(help2, (sint32)Time_max); 
          }
          else
          {
            ttc = (times_t)MAT_MIN(help, (sint32)Time_max); 
          }
        }
        else
        {
          ttc = Time_max;
        }
      }

      /*if host came also to stand still while new ttc - ttc =  inf*/
      if(
        (MAT_SIGN((sint32)ah) != MAT_SIGN((sint32)vh)) /*if direction of acceleration is different to direction of speed*/     
        &&
        (ah != 0)
        )
      {        
        /*v_ttc = vh + ah*ttc*/        
        help = MAT_MUL(ah, (sint32)ttc, Acceleration_s, Time_s, Velocity_s);
        help+= (sint32)vh;
        
        if(MAT_SIGN(help) != MAT_SIGN(vh))
        {
          /*host came to full stop*/
          ttc = Time_max;
          v_obj_at_ttc = 0;
        }
      }
    }
    else
    {
      /*object is still moving after ttc*/
      /*v_ttc = vo + ao*ttc*/      
      help = MAT_MUL(ObjectAccel, (sint32)ttc, Acceleration_s, Time_s, Velocity_s);
      help+= (sint32)ObjectVelocity;
      v_obj_at_ttc = (velocity_t)MAT_LIM(help, (sint32)0, (sint32)MAT_SIGN(ObjectVelocity)*(sint32)Speed_max);
    }
  }
  else
  {
    /*object is still moving after ttc or ttc is higher*/
    /*v_ttc = vo + ao*ttc*/
    help = MAT_MUL(ObjectAccel, (sint32)ttc, Acceleration_s, Time_s, Velocity_s);
    help+= (sint32)ObjectVelocity;
    v_obj_at_ttc = (velocity_t)MAT_LIM(help, 0, (sint32)MAT_SIGN(ObjectVelocity) * (sint32)Speed_max);
  }
  
  /*calculate impact velocity*/
  /*if ttc is small enough to be effective*/
  if(ttc < Phys_max_relevant_ttc)
  {
    /*v_ttc = ah*ttc+vh*/
    help = MAT_MUL(ah, (sint32)ttc, Acceleration_s, Time_s, Velocity_s);
    help+= (sint32)vh;
    /*impactvelocity = v_ttc - v_obj_ttc*/
    help-= (sint32)v_obj_at_ttc;
  }
  else
  {
    help = 0;
  }
  
  *ImpactVelocity = (velocity_t)MAT_LIM(help, 0, Speed_max);
  
  return ttc;
}// PRQA S 7004
/* date: 2018-03-26, reviewer: Ravi Kiran Gurrala, reason: Cyclomatic complexity. Not safety critical */

/*************************************************************************************************************************
  Functionname:    PHYS_CALCULATE_TTC                                                                               */ /*!

  @brief           calculates the ttc to an object

  @description     calculates the ttc to an object

                    @startuml
                    Start
                        Partition PHYS_CALCULATE_TTC {
                        If(Target object is oncoming)then (TRUE)
                        IF(Host is stopping soon) then (TRUE)
                            If ( Object velocity is equal to object \n accelation or object accelaration is zero) then (TRUE)
                                -Set flag to Inter change the parameter of host and object
                            Else (FALSE)
                            - Calculate the time to stop for both host and object
                              IF(host accelaration is non zero ) then (TRUE)
                                -calculate the time to stop of host
                              Else
                                If(velocity of host is zero) then (TRUE)
                                 - Set flag to Inter change the parameter of host and object
                                 - set time to stop of host to zero
                                Else
                                - set time to stop of host to maximum time
                                    Endif
                              Endif
                            If( flag for interchanging parameter of host and object is set as false) then (TRUE)
                            If(timt to stop for host is less than time to stop of object)then (TRUE)
                                -Set flag to Inter change the parameter of host and object
                            Endif
                        Endif 
                        If( switch parameter flag is set) then (TRUE)
                        - inter change the parameter of host and object
                        Endif 
                        Endif
                        endif
                        Endif
                        If( object accelaration is below minimum accelaration) then (TRUE)
                        -Set object accelaration to zero
                        endif
                        If (Difference of host and object accelaration is less than minimum accelartion) then (TRUE)
                        -Set to host accelaration as Object accelaration
                        Endif
                        }
                        End
                    @enduml

  @return          ttc : time to collision [full range of type times_t defined in Rte_Type.h]

  @param[in]       ObjectVelocity     [full range of type velocity_t defined in Rte_Type.h]
  @param[in]       ObjectAccel        [full range of type acceleration_t defined in Rte_Type.h]
  @param[in]       HostVelocity       [full range of type velocity_t defined in Rte_Type.h]
  @param[in]       HostAccel          [full range of type acceleration_t defined in Rte_Type.h]
  @param[in]       ObjectDistance     [full range of ype distance_t defined in Rte_Type.h]
  @param[in,out]   *ImpactVelocity    [Pointer of the type velocity_t defined in Rte_Type.h]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library  
  @c_switch_full   FCT_CFG_LOHP_COMPONENT  : Configuration switch for component LOHP

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-524-0009fc80">CAL_524</a> \n

  @created         -
  @changed         5/31/2016

  @author          -
*************************************************************************************************************************/
times_t PHYS_CALCULATE_TTC(const velocity_t ObjectVelocity, const acceleration_t ObjectAccel, const velocity_t HostVelocity, const acceleration_t HostAccel, const distance_t ObjectDistance, velocity_t *ImpactVelocity)
{
#define local_min_accel (acceleration_t)100

  velocity_t local_object_velocity;
  velocity_t local_host_velocity;
  velocity_t local_object_accel;
  velocity_t local_host_accel;
  velocity_t local_object_distance;

  velocity_t     vh;
  acceleration_t ah;
  boolean        switch_objects;
  sint32         tts_h = 0, tts_o, help;

  switch_objects = FALSE;

  vh = HostVelocity;
  ah = HostAccel;

  /*copy object*/
  local_object_distance = ObjectDistance;
  local_object_velocity = ObjectVelocity;
  local_object_accel = ObjectAccel;
  local_host_velocity = HostVelocity;
  local_host_accel = HostAccel;

  if(ObjectVelocity < 0)
  {
    /*host vehicle may come to a full stop*/
    if(MAT_SIGN(ah) != MAT_SIGN(vh))
    {
      /*object may not come to a full stop*/
      if(
          (MAT_SIGN(ObjectVelocity) == MAT_SIGN(ObjectAccel))
          ||
          (ObjectAccel == 0)
        )
      {
        switch_objects = TRUE;
      }
      else
      { 
        /*target object may also come to a full stop*/
        /*need to calculate tts for both objects*/    
        help = MAT_DIV(-ObjectVelocity, ObjectAccel, Velocity_s, Acceleration_s, Time_s);
        tts_o = MAT_LIM(help, 0, (sint32)Time_max);

        if(ah != 0)
        {
          help = MAT_DIV(-vh, ah, Velocity_s, Acceleration_s, Time_s);
          tts_h = MAT_LIM(help, 0, (sint32)Time_max);
        }
        else
        {
          if(vh == 0)
          {
            switch_objects = TRUE;
           
          }
          else
          {
            tts_h = (sint32)Time_max;
          }
        }
        /* PRQA S 1863 400
        date: 28/06/2019 author: Pruthvi Reason: Can be ignored as no functional impact */
        /*if not already set, use calculations from tts*/
        if(switch_objects == FALSE)
        {
          if(tts_h < tts_o)
          {
            switch_objects = TRUE;
          }
        }
      }
    }
  }

  /*switch objects*/
  /* PRQA S 1863 400
  date: 28/06/2019 author: Pruthvi Reason: Can be ignored as no functional impact */  
  if(switch_objects == TRUE)
  {
    local_object_accel = (acceleration_t)-ah;
    local_object_velocity = (velocity_t)-vh;
    local_host_accel = (acceleration_t)-ObjectAccel;
    local_host_velocity = (acceleration_t)-ObjectVelocity;
  }

  /*avoid small values of a / arel due to fixed point limitations!*/
  if(MAT_ABS((sint32)local_object_accel) < (sint32)local_min_accel)
  {
    local_object_accel = 0;
  }

  if(MAT_ABS((sint32)local_object_accel - (sint32)local_host_accel) < (sint32)local_min_accel)
  {
    local_host_accel = local_object_accel;
  }

  return PHYS_CALCULATE_TTC_NO_ONCOMING(local_object_velocity, local_object_accel, local_host_velocity, local_host_accel, local_object_distance, ImpactVelocity);
}
#endif /* (FCT_CFG_ACC_CAL) && (FCT_CFG_LOHP_COMPONENT) */

