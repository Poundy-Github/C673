/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_dyn.c

DESCRIPTION:               Physical Funktions of all kinematical functions

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.6 $

LEGACY VERSION:            Revision: 1.9.1.3


**************************************************************************** */
#include "cal_int.h"/* PRQA S 0380
date: 28/06/2019 author: Pruthvi Reason: Can be ignored as no functional impact */

#if ((FCT_CFG_ACC_CAL) && (FCT_CFG_LODMC_COMPONENT))
#if (0) /* Disabling unused functions */
#define Gravity (acceleration_t)9810

/*****************************************************************************

  @fn               PHYS_CONVERT_T2A *\ \*!
  @brief            Convert a Torque to an Acceleration according to
                    tractive resistance
  @description      Convert a Torque to an Acceleration according to
                    tractive resistance

                    @startuml
                    Partition PHYS_CONVERT_T2A {
                    Start
                    : Read the torque, vehicle operational parameters and ego velocity;
                    : Calculate the radius using the circumference;
                    : Calculate the total force using the torque and the radius;
                    : Calculate the air resistance as the product of coefficient of drag and the square of the ego velocity;
                    : Calculate the net force as the difference of the total force and air resistance;
                    : Calculate the acceleration using the net force and weight of vehicle;
                    : Calculate the deceleration due to rolling resistance;
                    : Calculate acceleration equivalent to the input torque using the calculated acceleration and the acceleration resistance;
                    }
                    end
                    @enduml

  @return           Acceleration = ((((T/(n_Wheel/2PI))-Cw*v²)/m_vehicle)-(RollResistance*Gravity))/AccelResistance
  @param[in]        T
  @param[in]        op_params
  @param[in]        vehicle_speed

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @InOutCorrelation   None

  @pre             None
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-508-0009fc80">CAL_508</a> \n

*****************************************************************************/
acceleration_t PHYS_CONVERT_T2A(const torque_t T, const CALVehOperationalParams_t* op_params, const velocity_t vehicle_speed)
{
  sint32 help, help1;

  help = (sint32)op_params->STAT_WHEEL_CIRCUMFERENCE;
  help *= (sint32)(Angle_s);
  help /= (sint32)(2 * Pi_fixpoint_angle);
  
  /*comment: div/0 -> STAT_WHEEL_CIRCUMFERENCE will never be 0*/
  help = ((sint32)T * (sint32)Length_s) / help;
  help *= (sint32)Acceleration_s;
  help /= (sint32)Torque_s;

  help1 = (sint32)op_params->AIR_RESISTANCE;
  help1 *= (sint32)vehicle_speed;
  help1 /= (sint32)Velocity_s;
  help1 *= (sint32)vehicle_speed;
  help1 /= (sint32)Velocity_s;
  help1 *= (sint32)Acceleration_s;
  help1 /= (sint32)Factor_s;

  help -= help1;

  help *= (sint32)Weight_s;
  /*comment: div/0 -> VEHICLE_WEIGHT will never be 0*/
  help /= (sint32)op_params->VEHICLE_WEIGHT;

  help1 = (sint32)op_params->ROLL_RESISTANCE;
  help1 *= (sint32)(Gravity);
  help1 /= (sint32)Acceleration_s;

  help -= help1;
  help *= (sint32)(Factor_s);
  /*comment: div/0 -> ACCEL_RESISTANCE will never be 0*/
  help /= (sint32)op_params->ACCEL_RESISTANCE;

  return (acceleration_t)help;
}

/*****************************************************************************

  @fn               PHYS_CONVERT_A2T *\ \*!
  @brief            Convert an Acceleration to a Torque according to
                    tractive resistance
  @description      Convert an Acceleration to a Torque according to
                    tractive resistance

                    @startuml
                    Partition PHYS_CONVERT_A2T {
                    Start
                      : Read the acceleration, vehicle operational parameters and ego velocity;
                      : The total force is sum of the angular force, air resistance force, rolling resistance force and the acceleration resistance force;
                      : Calculate the rolling resistance using drag coefficient;
                      : Calculate force using acceleration coefficient;
                      : Calculate the air resistance using coefficient of air resistance;
                      : The torque is calculated using the total force and the circumference;
                    }
                    end
                    @enduml

  @return           Torque = (((RollResistance*Gravity)+(AccelResistance*a))*m_vehicle+Cw*v²)*(n_wheel/2PI)
  @param[in]        a
  @param[in]        op_params
  @param[in]        vehicle_speed

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-509-0009fc80">CAL_509</a> \n
*****************************************************************************/
torque_t PHYS_CONVERT_A2T(const acceleration_t a, const CALVehOperationalParams_t* op_params, const velocity_t vehicle_speed)
{
  sint32 help, help1;

  help = (sint32)op_params->ROLL_RESISTANCE;
  help *= (sint32)(Gravity);
  help /= (sint32)Acceleration_s;

  help1 = (sint32)a;
  help1 *= (sint32)op_params->ACCEL_RESISTANCE;
  help1 /= (sint32)Acceleration_s;

  help += help1;

  help *= (sint32)op_params->VEHICLE_WEIGHT;
  help /= (sint32)Weight_s;

  help1 = (sint32)op_params->AIR_RESISTANCE;
  help1 *= (sint32)vehicle_speed;
  help1 /= (sint32)Velocity_s;
  help1 *= (sint32)vehicle_speed;
  help1 /= (sint32)Velocity_s;
  help1 *= (sint32)Acceleration_s;
  help1 /= (sint32)Factor_s;

  help += help1;
  help /= (sint32)Acceleration_s;

  help1 = (sint32)op_params->STAT_WHEEL_CIRCUMFERENCE;
  help1 *= (sint32)Angle_s;
  help *= (sint32)Torque_s;
  help1 /= (sint32)(2 * Pi_fixpoint_angle);

  help *= help1;
  help /= (sint32)Length_s;

  return (torque_t)help;
}
#endif /* (0) Unused functions */
#endif  /* END IF ((FCT_CFG_ACC_CAL) && (FCT_CFG_LODMC_COMPONENT)) */
