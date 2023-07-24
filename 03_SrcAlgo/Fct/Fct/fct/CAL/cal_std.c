/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_std.c

DESCRIPTION:               All standard math functions like min/max operators

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.18 $

LEGACY VERSION:            Revision: 1.15


**************************************************************************** */

#include "cal_int.h"/* PRQA S 0380
date: 28/06/2019 author: Pruthvi Reason: Can be ignored as no functional impact */

#if (FCT_CFG_ACC_CAL)

#define Mat_1_2_pi 15708
#define Mat_3_2_pi 47123
/*!@todo defined in algo glob for radar projects. Naming should be changed!*/
#ifndef Pi_fixpoint_angle
#define Pi_fixpoint_angle         31416
#endif
/* Lower limit for signed 16 bit integer -32768 */
#ifndef sint16_LowerLimit
#define sint16_LowerLimit         0x8000
#endif
/* Upper limit for signed 16 bit integer 32767 */
#ifndef sint16_UpperLimit
#define sint16_UpperLimit         0x7FFF
#endif
/* Lower limit for unsigned 8 bit integer 0 */
#ifndef uint8_LowerLimit
#define uint8_LowerLimit          0x00
#endif
/* Upper limit for unsigned 8 bit integer 255 */
#ifndef uint8_UpperLimit
#define uint8_UpperLimit          0xFF
#endif
/* Lower limit for unsigned 16 bit integer 0 */
#ifndef uint16_LowerLimit
#define uint16_LowerLimit         0x0000
#endif
/* Upper limit for unsigned 16 bit integer 65535 */
#ifndef uint16_UpperLimit
#define uint16_UpperLimit         0xFFFF
#endif
/* Lower limit for signed 8 bit integer -128 */
#ifndef sint8_LowerLimit
#define sint8_LowerLimit          0x80
#endif
/* Upper limit for signed 8 bit integer 127 */
#ifndef sint8_UpperLimit
#define sint8_UpperLimit          0x7F
#endif

#if (0) /* Disabling unused functions */
/*optimized table (sin(x) with accuracy of 1/factor_s (1000))*/
#define Mat_sin_table MAT_SIN_TABLE
#define Mat_sin_table_points (uint16)15
static const sint16         MAT_SIN_TABLE[2u*Mat_sin_table_points] =// PRQA S 3218
/* date: 2017-11-2, reviewer: Dyuthi Varier, reason: Used as look up table*/
{ /*x, sin(x)*/
   0,      0,
   2444,    242,
   3974,    387,
   5259,    502,
   6422,    599,
   7505,    682,
   8526,    753,
   9493,    813,
   10432,   864,
   11337,   906,
   12256,   941,
   13132,   967,
   13974,   985,
   14933,   997,
   Mat_1_2_pi,   1000
}; 
#endif /* (0) Unused functions */

/* local constants, valid for all used functions */
  #define MAX_TIME_INTEGRATED_ERROR   ( 0.8f )
  #define SOFT_ANTI_WINDUP_LIMIT      ( 0.7f )
  #define SOFT_ANTI_WINDUP_INPUT_FAC  ( 0.5f )
  #define ERROR_REDUCTION_FAC         ( 1.5f )
  #define MIN_ABS_HYST                ( 0.02f * (f_InputHyst_Fak * f_InputHyst_Nomin / f_InputHyst_Denom ))

// PRQA S 7013 STTPP_EXCEEDED
/*************************************************************************************************************************
  Functionname:    MAT_MIN                                                                                          */ /*!

  @brief           calculation of min(val1,val2) 

  @description     calculation of min(val1,val2) 

                   @startuml
                   Start
                       Partition Mat_MIN {
                       if(**Number1** is lesser than ** Number2**)then(TRUE)
                           :return ** Number1**;
                       else (FALSE)
                           :return ** Number2**;
                       Endif
                       }
                   End
                   @enduml
    
  @return          sint32  Val2         [full range of sint32]

  @param[in]       Val1 : first Value   [full range of sint32]
  @param[in]       Val2 : second Value  [full range of sint32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   Output is the minimum of two inputs Val1 and Val2

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-529-0009fc80">CAL_529</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
sint32 MAT_MIN (sint32 Val1, sint32 Val2)
{
  if(Val1 < Val2)
  {
    Val2 = Val1;
  }
  else
  {
    /*Val2 already < Val1*/
  }
  return Val2;
}

/*************************************************************************************************************************
  Functionname:    MAT_MAX                                                                                          */ /*!

  @brief           calculation of max(val1,val2)

  @description     calculation of max(val1,val2)

                    @startuml
                    Start
                        Partition MAT_MAX {
                        if(**Number1** greater than **Number2**)then(TRUE)
                            -return **Number1**
                        else (FALSE)
                            -return **Number2**
                        Endif
                        }
                    End
                    @enduml

  @return          sint32   Val2        [full range of sint32]
   
  @param[in]       Val1 : first Value   [full range of sint32]
  @param[in]       Val2 : second Value  [full range of sint32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   Output is the maximum of two inputs Val1 and Val2

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-530-0009fc80">CAL_530</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
sint32 MAT_MAX (sint32 Val1, sint32 Val2)
{
  if(Val1 > Val2)
  {
    Val2 = Val1;
  }
  else
  {
    /*Val2 already > Val1;*/
  }
  return Val2;
}

/*************************************************************************************************************************
  Functionname:    MAT_LIM                                                                                          */ /*!

  @brief           limits Value "val" between Lim1 and Lim2

  @description     limits Value "val" between Lim1 and Lim2

                   @startuml
                   Start
                       Partition MAT_LIM {
                       If (Input is lesser than Lower limit) then (TRUE)
                           :return Lower limit value;
                       elseif(Input is greater than upper limit)then (TRUE)
                           : return Upper limit value;
                       Else (Input value is within the given limit)
                           :return input value;
                       Endif
                       }
                   End
                   @enduml
    
  @return          sint32  Val  [full range of sint32]

  @param[in]       Val : value to limit  [full range of sint32]
  @param[in]       Lim1 :lower border    [full range of sint32]
  @param[in]       Lim2 :lower border    [full range of sint32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-531-0009fc80">CAL_531</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
sint32 MAT_LIM (sint32 Val, sint32 Lim1, sint32 Lim2)
{
  sint32 lower,higher;

  lower = MAT_MIN(Lim1,Lim2);
 
  if(Val < lower)
  {
    Val = lower;
  }
  else
  {
    higher = MAT_MAX(Lim1,Lim2);
    if (Val > higher) 
    {
      Val = higher;
    }
    else
    {
      /*value already between Lim1 and Lim2*/
    }
  }
  return Val;
}

/*************************************************************************************************************************
  Functionname:    MAT_FILT                                                                                         */ /*!

  @brief           limits Value "val" between Lim1 and Lim2

  @description     limits Value "val" between Lim1 and Lim2

                   @startuml
                   Start
                       Partition MAT_FILT {
                       -Calculate the filter value for given old and new value with filter depth.
                       if(calculated filter value is same as old value and old value is not same old value)then (TRUE)
                           if ( old value is lesser than new value) then (TRUE)
                               -Increment the filter value by 1
                           Else (FALSE)
                               -Decrement the filter value by 1
                           Endif
                       Else (FALSE)
                       endif
                       }
                   End
                   @enduml

  @return          sint32   ret_value                                   [full range of sint32]

  @param[in]       NewVal :       actual Value                          [full range of sint32]
  @param[in]       OldVal :       last Value                            [full range of sint32]
  @param[in]       FilterDepth :  FilterDepth depth of the filter       [full range of sint32 != -1]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-532-0009fc80">CAL_532</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
sint32 MAT_FILT (sint32 NewVal, sint32 OldVal, sint32 FilterDepth)
{
  sint32 ret_value;

  ret_value = OldVal;
  ret_value *= FilterDepth;
  ret_value += NewVal;
  ret_value /= (FilterDepth + (sint32)1);
  if((ret_value == OldVal) && (OldVal != NewVal))
  {
    if(OldVal < NewVal)
    {
      ret_value++;
    }
    else
    {

      ret_value--;
    }
  }

  return ret_value;
}

/*************************************************************************************************************************
  Functionname:    MAT_ABS                                                                                          */ /*!

  @brief           Finds the absolute value of i

  @description     Finds the absolute value of i

                     @startuml
                     Start
                        Partition MAT_ABS {
                        if(Input value is negative number)then (TRUE)
                           : convert into positive value by multiply input with -1;
                        else(FALSE)
                           :return the Input; 
                        Endif
                        }
                     End
                     @enduml

  @return          sint32  returns the absolute value of i   [full range of sint32 >= 0]

  @param[in]       i : input parameter to which absolute value to be determined  [full range of sint32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   Output = abs(i)

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-533-0009fc80">CAL_533</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
sint32 MAT_ABS(sint32 i)
{
  if(i < (sint32)0)
  {
    i = -i;
  }
  else
  {
    /*i already positive*/
  }

  return i;
}

/*************************************************************************************************************************
  Functionname:    MAT_DIFF_DT                                                                                      */ /*!

  @brief           Differentiate a value in time d/dt = (New - Old) / cycle time
                   cycle = 0 will cause division by 0

  @description     Differentiate a value in time d/dt = (New - Old) / cycle time
                   cycle = 0 will cause division by 0

                   @startuml
                   Start
                       Partition MAT_DIFF_DT { 
                       - Subtract current input value with previous cycle input value
                       - Divide the resultant value by number cycle to calculate the gradient
                       }
                   End
                   @enduml

  @return          sint32 Gradient                    [full range of sint32]

  @param[in]       New :   value in current cycle     [full range of sint32]
  @param[in]       Old :   value in former cycle      [full range of sint32]
  @param[in]       Cycle : time in ms between cycles  [times_t as defined Rte_Type.h >0]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   d/dt = (New - Old) / Cycle time

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-534-0009fc80">CAL_534</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
sint32 MAT_DIFF_DT(sint32 New, sint32 Old, times_t Cycle)
{
  sint32 Gradient;
  Gradient = New - Old;
  Gradient *= (sint32)Time_s;
  /*comment: div/0 -> cycle time will never be zero*/
  if (Cycle > 0u)
  {
    Gradient /= (sint32)Cycle;
  }
  
  return Gradient;
}

#if (0) /* Disabling unused functions */
/*************************************************************************************************************************
  Functionname:    MAT_INT_DT                                                                                       */ /*!

  @brief           Integrate a value in time NewInt = OldInt + ((Old - New) / 2) * cycle time

  @description     Integrate a value in time NewInt = OldInt + ((Old - New) / 2) * cycle time

                   @startuml
                   Start
                       Partition MAT_INT_DT { 
                       - Add current input value with previous cycle input value
                       - resultant is divide by 2
                       - convert the resultant in millisecond
                       - Add the resultant with integral value in last cycle
                       }
                   End
                   @enduml

  @return          sint32 NewInt                      [full range of sint32]

  @param[in]       New :   value in current cycle     [full range of sint32]
  @param[in]       Old :   value in former cycle      [full range of sint32]
  @param[in]       OldInt : integral in former cycle  [full range of sint32]
  @param[in]       Cycle :  time in ms between cycles [times_t as defined Rte_Type.h]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   NewInt = OldInt + ((Old - New) / 2) * cycle time

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-535-0009fc80">CAL_535</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
sint32 MAT_INT_DT(sint32 New, sint32 Old, sint32 OldInt, times_t Cycle)
{
  sint32 NewInt;
  NewInt = Old + New;
  NewInt /= (sint32)2;
  NewInt *= (sint32)Cycle;
  NewInt /= (sint32)Time_s;
  NewInt += OldInt;
  return NewInt;
}
#endif /* (0) Unused functions */

/*************************************************************************************************************************
  Functionname:    MAT_LIM_GRAD                                                                                     */ /*!

  @brief           Limit gradient of input value

  @description     Limit gradient of input value

                   @startuml
                   Start
                       Partition MAT_LIM_GRAD { 
                       - Calculate the gradient for the input
                       -       Gradient will be limited within the \n maximum positive and negative gradient value
                       - Convert resultant gradient in seconds 
                       - Add the new computed gradient value with old gradient value
                       }
                   End
                   @enduml

  @return          sint32 LimVal                                        [full range of sint32]

  @param[in]       New : value in current cycle                         [full range of sint32]
  @param[in]       Old : value in former cycle                          [full range of sint32]
  @param[in]       max_neg_grad : maximum decrease of value per second  [full range of sint32 <= 0]
  @param[in]       max_pos_grad : maximum increase of value per second  [full range of sint32 >= 0]
  @param[in]       Cycle : time in ms between cycles                    [times_t as defined Rte_Type.h]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-536-0009fc80">CAL_536</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
sint32 MAT_LIM_GRAD(sint32 New, sint32 Old, sint32 max_neg_grad, sint32 max_pos_grad, times_t Cycle)
{
  sint32 LimVal;

  LimVal = MAT_DIFF_DT(New, Old, Cycle);
  LimVal = MAT_LIM(LimVal, max_neg_grad, max_pos_grad);
  LimVal *= (sint32)Cycle;
  LimVal /= (sint32)Time_s;
  LimVal += Old;

  return LimVal;
}

/*************************************************************************************************************************
  Functionname:    MAT_PT1_FILTER                                                                                   */ /*!

  @brief           Smoothing filter to prevent oscillations and other discontinuous waveforms

  @description     Smoothing filter to prevent oscillations and other discontinuous waveforms
                   Used PT1-Filter formular:
                   Y(n)=(1-T/T1)*Y(n-1)+(T/T1)*X(n)

                   T      = cycle_time
                   T1     = time_constant
                   X(n)   = Input value
                   Y(n-1) = Output value from last cycle
                   Y(n)   = New output value

                   @startuml
                   Start
                       Partition MAT_PT1_FILTER {
                       -Intialize variables with zero, which used for filtering the inputs
                       If(given **time constant** value is greater than **cycle time** and less than 1 **time_s** scale) then (TRUE)
                           - calculate filter constant
                           - Calculate PT1 filter co-efficient value 
                       Else (FALSE)
                           -No filtering is applied for the input
                       endif
                       }
                   End
                   @enduml

  @return          sint32

  @param[in]       cycle_time : Task cycle time [Full range of datatype times_t as in Rte_type.h]
  @param[in]       time_constant : Filter time constant in ms [20 ... 1000]
  @param[in]       input_value : Un-filtered input value from current cycle [Full range of datatype sint16 as in Rte_type.h]
  @param[in]       output_value_last_cycle : Filtered value from last cycle [Full range of datatype sint16 as in Rte_type.h]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-537-0009fc80">CAL_537</a> \n

  @created         01.06.2016
  @changed         01.06.2016

  @author          Jens Both | jens.both@continental-corporation.com | +49 (8382) 9699-757
*************************************************************************************************************************/
sint32 MAT_PT1_FILTER(const times_t cycle_time, times_t time_constant, sint32 input_value, sint32 output_value_last_cycle)
{
  sint32 help;
  sint32 filter_constant = (sint32)0;
  sint32 output_new = (sint32)0;



  if ((time_constant > cycle_time) && (time_constant < (uint16)Time_s))
  {
    /* Calculate filter constant T/T1 - cylce_time/time_constant */
    help = (sint32)cycle_time * (sint32)Time_s;
    help /= (sint32)time_constant;
    filter_constant = (sint32)help;

    /* PT1 filter to prevent oscillations and other discontinuous waveforms */
    help = ((sint32)Factor_s - (sint32)filter_constant) * (sint32)output_value_last_cycle + (sint32)filter_constant * (sint32)input_value;
    help /= (sint32)Factor_s;
    /* Write output */
    output_new = (sint32)help;
  }
  else
  {
    /* Wrong time constant, no filtering applied */
    output_new = input_value;
  }


  return output_new;
}

#define Mat_max_sqrt_val 46340L /*sqrt(2^31)*/

/*************************************************************************************************************************
  Functionname:    MAT_SQRT                                                                                         */ /*!

  @brief           calculates the square root of Val (using newton approximation)

  @description     calculates the square root of Val (using newton approximation)

                   @startuml
                       Start
                       Partition MAT_SQRT {
                       If (given number is greater than Zero) then (TRUE)
                           - start iteration with x0 = estimated sqrt (take half of bitlength +1 )    
                           - as long as new value is better than last value start a new iteration for guessing closer square root value.
                       Else (FALSE)
                           -return Zero
                       endif
                       }
                   End
                   @enduml

  @return          sint32  x                          [full range of sint32 >= 0]


  @param[in]       Val : input pvalue to which squrare root to be determined    [full range of sint32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-538-0009fc80">CAL_538</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
sint32 MAT_SQRT(sint32 Val)
{
  sint32 x,y;
  sint32 best_accuracy;

  /*start iteration with x0 = estimated sqrt (take half of bitlength +1 ) --> faster (using d&c)*/
  if(Val > 0)
  {
    if(Val >= 0x10000L) /*2^16*/
    {
      if(Val >= 0x1000000L) /*2^24*/
      {
        if(Val >= 0x10000000L) /*2^28*/
        {
          if(Val >= 0x40000000L) /*2^30*/
          {
            x = (sint32) Mat_max_sqrt_val; /*>=30 set to Mat_max_sqrt_val because of (1<<16)^2 = 65535^2 > max positive value of sint32*/
          }
          else
          {
            x = (sint32) 0x8000L; /*2^15*/
          }
        }
        else
        {
          if(Val >= 0x4000000L) /*2^26*/
          {
            x = 0x4000; /*2^14*/
          }
          else
          {
            x = 0x2000; /*2^13*/
          }
        }
      }
      else
      {
        if(Val >= 0x100000L) /*2^20*/
        {
          if(Val >= 0x400000L) /*2^22*/
          {
            x = 0x1000; /*2^12*/
          }
          else
          {
            x = 0x800; /*2^11*/
          }
        }
        else
        {
          if(Val >= 0x40000L) /*2^18*/
          {
            x = 0x400; /*2^10*/
          }
          else
          {
            x = 0x200; /*2^9*/
          }
        }
      }
    }
    else
    {
      if(Val >= 0x100L) /*2^8*/
      {
        if(Val >= 0x1000L) /*2^12*/
        {
          if(Val >= 0x4000L) /*2^14*/
          {
            x = 0x100; /*2^8*/
          }
          else
          {
            x = 0x80; /*2^7*/
          }
        }
        else
        {
          if(Val >= 0x400L) /*2^10*/
          {
            x = 0x40; /*2^6*/
          }
          else
          {
            x = 0x20; /*2^5*/
          }
        }
      }
      else
      {
        if(Val >= 0x10L) /*2^4*/
        {
          if(Val >= 0x40L) /*2^6*/
          {
            x = 0x10; /*2^4*/
          }
          else
          {
            x = 0x8; /*2^3*/
          }
        }
        else
        {
          x = 0x4;   /*2^2*/
        }
      }
    }

    y = (x * x) - Val;
    best_accuracy = x+x;

    /*as long as new value is better than last value start a new iteration*/
    while(y >= best_accuracy)
    {
      x-= y / best_accuracy;
      y = (x * x) - Val;//PRQA S 0297
  /* date: 2017-11-02, reviewer: Dyuthi Varier, reason:It has been checked logically, no overflow will occur*/
      best_accuracy = x+x;
    }

    /*round down*/
    if(x > 1)
    {
      x--;
    }
  }
  else
  {
    /*return 0 in case Val <= 0*/
    x = 0;
  }
  return x;
}

/*************************************************************************************************************************
  Functionname:    MAT_SIGN                                                                                         */ /*!

  @brief           calculates the sign (-1 / 1) of the input value (0 will be set to sign 1)

  @description     calculates the sign (-1 / 1) of the input value (0 will be set to sign 1)

                     @startuml
                     Start
                        Partition MAT_SIGN {
                        if( sign of given number) then(NEGATIVE)
                           :return -1;
                        else(POSITIVE)
                           :return 1;
                        Endif
                        }
                     End
                     @enduml

  @return          sint8 sign           [-1 or +1]

  @param[in]       Val :  input value   [full range of sint32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   sign = -1 if val<0, else sign = 1

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-539-0009fc80">CAL_539</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
sint8 MAT_SIGN(sint32 Val)
{
  sint8 sign;
  sign = 1;
  if(Val < 0)
  {
    sign = -1;
  }
  return sign;
}

/*************************************************************************************************************************
  Functionname:    MAT_MUL                                                                                          */ /*!

  @brief           Fixed point multiplication of two sin32 values

  @description     Fixed point multiplication of two sin32 values

                   @startuml
                   Start
                       Partition MAT_MUL {
                       If (scale values of two inputs are non-zero) then (TRUE)
                           :Divide Input1 by maximum of scale values of two inputs;
                           :Multiply input1 with Input2 which is divided by \n minimum of scale values of two inputs;
                           : Resultant is multiplied with resultant scale for fixed point multiplication;
                       Else (FALSE)
                           :Retun 0;
                       endif
                       }
                   End
                   @enduml

  @return          sint32  help  [full range of sint32]

  @param[in]       Val1 :        first value                      [full range of sint32]
  @param[in]       Val2 :        second value                     [full range of sint32]
  @param[in]       Val1Scale :   first scale value                [full range of sint32]
  @param[in]       Val2Scale :   second scale value               [full range of sint32]
  @param[in]       ReturnScale : scale value for return value     [full range of sint32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-540-0009fc80">CAL_540</a> \n

  @created         -
  @changed         12/9/2017

*************************************************************************************************************************/
sint32 MAT_MUL(sint32 Val1, sint32 Val2, sint32 Val1Scale, sint32 Val2Scale, sint32 ReturnScale)
{
  float32 f_help;
  sint32 help;
  if((Val1Scale != 0) && (Val2Scale != 0))
  {
    f_help = ((float32)Val1 / (float32)MAT_MAX(Val1Scale, Val2Scale));
    f_help*= ((float32)Val2 / (float32)MAT_MIN(Val1Scale, Val2Scale));
    f_help*= (float32)ReturnScale;
    help   = (sint32)f_help;
  }
  else
  {
    help = 0;
  }

  return help;
}

/*************************************************************************************************************************
  Functionname:    MAT_DIV                                                                                          */ /*!

  @brief           Fixed point division of two sin32 values

  @description     Fixed point division of two sin32 values

                   @startuml
                   Start
                       Partition MAT_DIV {
                       If (input1 scale value and input2 are non-zero) then (TRUE)
                           :Multiply Input1 by minimum of input2 scale value and return scale;
                           :Divide input1 by maximum of input2 and input1 scale value;
                           :Multiply resultant with maximum of input2 scale value and return scale;
                           :Divide input1 by minimum of input2 and input1 scale value;
                       Else (FALSE)
                           :Retun 0;
                       endif
                       }
                   End
                   @enduml

  @return          sint32 help   [full range of sint32]

  @param[in]       Val1 :  input1 value                     [full range of sint32]
  @param[in]       Val2 :  input2 value                [full range of sint32]
  @param[in]       Val1Scale :  scale value for input1       [full range of sint32]
  @param[in]       Val2Scale :  scale value for input2       [full range of sint32]
  @param[in]       ReturnScale :  scale for the return value [full range of sint32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-541-0009fc80">CAL_541</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
sint32 MAT_DIV(sint32 Val1, sint32 Val2, sint32 Val1Scale, sint32 Val2Scale, sint32 ReturnScale)
{
  sint32 help;
  if((Val1Scale != 0) && (Val2 != 0))
  {
    help = Val1;
    help*= MAT_MIN(Val2Scale, ReturnScale);
    help/= MAT_MAX(Val2,Val1Scale);
    help*= MAT_MAX(Val2Scale, ReturnScale);
    help/= MAT_MIN(Val2,Val1Scale);
  }
  else
  {
    help = 0;
  }
  return help;
}

#if (0) /* Disabling unused functions */
/*************************************************************************************************************************
  Functionname:    MAT_SIN                                                                                          */ /*!

  @brief           calculate sin(val)

  @description     calculate sin(val)

                   @startuml
                   Start
                   Partition MAT_SIN {
                       If(Input is Positive value) then (TRUE)
                           : Create a copy of original input;
                           If( Input is greater than 2PI)then (TRUE)
                               :Perform modulus of input by 2PI;
                           Else(FALSE)
                           Endif
                           If (Input is greater than PI) then (TRUE)
                               If(Input is greater than 3/2PI)then (TRUE)
                                   :subtract input by 2PI;
                               Else(FALSE)
                                   :subtract input by PI;
                               Endif
                           : Based on resultant check the corresponding value from the LookUp table and append -ve sign to value is returned;
                           Else(FALSE)
                               If(Input is greater than PI/2)then(TRUE)
                                   :Subtract input by PI;
                               Else(FALSE)
                               Endif
                               :Based on resultant check the corresponding value from the LookUp table and  append -ve sign to value is returned; 
                           endif
            
                       Else(FALSE)
                           : Convert the sign of input value by multiplying -1;
                           : downscale the value to the range of  0 to PI/2;
                           If( Input greater than 2PI) then (TRUE)
                               :tval    %= 2PI;
                           Else(FALSE)
                           Endif
                           If (tval > PI) then (TRUE)
                               If(tval > 3/2PI)then (TRUE)
                                   : Perform modulus of input by 2PI;
                               Else(FALSE)
                                   :Substract input by PI;
                               endif
                               : Based on resultant value check the corresponding value from the LookUp table is returned;
                           Else
                               If( Input value is greater than PI/2) then (TRUE)
                                   :Subtract the input by PI;
                               Else(FALSE)
                               Endif
                               : Based on resultant value the corresponding value from the LookUp table with -ve sign is returned; 
                           endif        
                       endif
                   }
                   End

                   @enduml

  @return          sint16   return_value  [-1      +1]rad

  @param[in]       Val :    input value   [0     6283]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-542-0009fc80">CAL_542</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
sint16 MAT_SIN(sint32 Val)
{
  sint16 return_value;
  uint32 u_val,u_val2;
  sint32 MVal;

  if(Val >= 0)
  {
    u_val = (uint32)Val;
    if(u_val >= ((uint32)2*(uint32)Pi_fixpoint_angle))
    {
      u_val%= (uint32)2*(uint32)Pi_fixpoint_angle;
    }

    if(u_val > (uint32) Pi_fixpoint_angle)
    {
      if(u_val > (uint32) Mat_3_2_pi)
      {
        u_val2 = ( (uint32)2*(uint32)Pi_fixpoint_angle ) - u_val; /* by MISRA required */
        return_value = - MAT_CALCULATE_PARAM_VALUE1D(Mat_sin_table, Mat_sin_table_points, (sint16)u_val2);
      }
      else
      {
        u_val2 = u_val - (uint32)Pi_fixpoint_angle; /* by MISRA required */
        return_value = - MAT_CALCULATE_PARAM_VALUE1D(Mat_sin_table, Mat_sin_table_points, (sint16)u_val2); 
      }
    }
    else
    {
      if(u_val > (uint32)Mat_1_2_pi)
      {
        u_val2 = (uint32)Pi_fixpoint_angle - u_val;  /* by MISRA required */
        return_value = MAT_CALCULATE_PARAM_VALUE1D(Mat_sin_table, Mat_sin_table_points, (sint16)u_val2);
      }
      else
      {
        return_value = MAT_CALCULATE_PARAM_VALUE1D(Mat_sin_table, Mat_sin_table_points, (sint16)u_val);
      }
    }
  }
  else
  {
    MVal = -Val;
    u_val = (uint32)MVal;
    if(u_val >= ((uint32)2*(uint32)Pi_fixpoint_angle))
    {
      u_val%= (uint32)2*(uint32)Pi_fixpoint_angle;
    }
    
    if(u_val > (uint32)Pi_fixpoint_angle)
    {
      if(u_val > (uint32) Mat_3_2_pi)
      {
        u_val2 = ( (uint32)2*(uint32)Pi_fixpoint_angle ) - u_val; /* by MISRA required */
        return_value = MAT_CALCULATE_PARAM_VALUE1D(Mat_sin_table, Mat_sin_table_points, (sint16)u_val2);
      }
      else
      {
        u_val2 = u_val - (uint32)Pi_fixpoint_angle; /* by MISRA required */
        return_value = MAT_CALCULATE_PARAM_VALUE1D(Mat_sin_table, Mat_sin_table_points, (sint16)u_val2); 
      }
    }
    else
    {
      if(u_val > (uint32) Mat_1_2_pi)
      {
        u_val2 = (uint32)Pi_fixpoint_angle - u_val;  /* by MISRA required */
        return_value = - MAT_CALCULATE_PARAM_VALUE1D(Mat_sin_table, Mat_sin_table_points, (sint16)u_val2);
      }
      else
      {
        return_value = - MAT_CALCULATE_PARAM_VALUE1D(Mat_sin_table, Mat_sin_table_points, (sint16)u_val);
      }
    }
  }

  return return_value;
}

/*************************************************************************************************************************
  Functionname:    MAT_COS                                                                                          */ /*!

  @brief           calculate cos(val)

  @description     calculate cos(val)

                   @startuml
                   Start
                       Partition MAT_COS {
                       - Add value PI/2  to Input;
                       - Call the function with resulatant
                       }
                   End
                   @enduml

  @return          sint16 :  [-1    +1]rad

  @param[in]       Val   :  input value  [0    6283]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   MAT_COS = MAT_SIN(Val + pi/2)

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-542-0009fc80">CAL_542</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
sint16 MAT_COS(sint32 Val)
{
  return MAT_SIN(Val + Mat_1_2_pi);
}

/*************************************************************************************************************************
  Functionname:    MAT_TAN                                                                                          */ /*!

  @brief           calculate tan(val)

  @description     calculate tan(val)

                   @startuml
                   Start
                       Partition MAT_TAN {
                       : call SIN and COS function;
                       if (result of cos function is non-zero) then (yes)
                           : Divide the result of SIN function dby result of COS function;
                           : Resultant is limited to signed 16bit range(-32768 to 32767); 
                       Else(no)
                           If (result of SIN function is greater than Zero ) then (TRUE)
                               : return-the max value of signed 16bit (32767);
                           Else(FALSE)
                               : return-the min value of signed 16bit (-32768);
                           endif
                       Endif

                       }
                   End
                   @enduml

  @return          sint16               [full range of sint32]

  @param[in]       Val :  input value   [0    6283]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-542-0009fc80">CAL_542</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
sint16 MAT_TAN(sint32 Val)
{
  sint16 sin_, cos_;
  sint16 return_val;

  cos_ = MAT_COS(Val);
  sin_ = MAT_SIN(Val);
  if(cos_ != 0)
  {
    return_val = (sint16)MAT_LIM(((sint32)sin_ * (sint32)Factor_s) / (sint32)cos_, Signed_int16_min, Signed_int16_max);
  }
  else
  {
    if(sin_ > 0)
    {
      return_val = Signed_int16_max;
    }
    else
    {
      return_val = Signed_int16_min;
    }
  }
  return return_val;
}

/*************************************************************************************************************************
  Functionname:    MAT_QUANT                                                                                        */ /*!

  @brief           AD-Converter: converting a "analog" (high resolution) variable 
                   to a "discrete" (low resolution) value

  @description     AD-Converter: converting a "analog" (high resolution) variable 
                   to a "discrete" (low resolution) value
    
                   @startuml
                   Start
                       Partition MAT_QUANT {
                           If(Quantization resolution is greater than 2cycle  and quantization \n  upper limit is greater than quantization lower limit) then (TRUE)
                       -Calculate the quantization interval by subtracting quantization \n upper and lower limit and divide by quantization resolution
                           If (Given dutycyle is not equal to 50%) then (TRUE)
                       -Multiply the interval with duty cylce which is divide by 100
                       -Convert the resultant into percentage
                       Else(FALSE)
                           -Divide the interval by 2
                           -Convert the resultant into percentage
                       Endif
                           -Map the lower quantization limit to lower threshold
                           -Calculate upper threshold  value by adding lower \n threshold value with calculated quantization interval
                           -Limit the given input with given upper and lower quantization limit

                       if(calculated upper limit is less than upper quantization value \n and input is greater than  calculated upper quantization \n limit and calculated quantization interval is non zero)then (TRUE)
 
                           -Limit the upper and lower quantization limit
                       Endif
                       If( Given input value is greater than difference of upper \n quantization limit and calculated quantization limit and , given \n input value is greater than or equal to last calcuated value)then (TRUE)
                       - return the upper quantization limit
                       Else
                       If ( Given input value is greater than sum of \n lower quantization limit and calculated quantization limit and , \n given input value is lesser than or equal to last calcuated value) then (TRUE)
                       -Return lower quantization limit
                       Else
                        -Return last calculated value
                       endif
                       endif
                       endif
                   End
                   @enduml

  @return          sint32  ret_val                                                              [Full range of sint32]

  @param[in]       Val       :  analog input                                                    [Full range of sint32]
  @param[in]       LastVal   :  result from the quantisation step in the last cycle             [Full range of sint32]
  @param[in]       MinVal    :  lower limit of the quantisation range                           [Full range of sint32]
  @param[in]       MaxVal    :  upper limit of the quantisation range                           [Full range of sint32]
  @param[in]       Res       :  quantisation resolution (number of intervals)                   [Full range of sint32]
  @param[in]       DutyCycle :  relating the hysteresis to the width of a quantisation interval [Full range of sint32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-543-0009fc80">CAL_543</a> \n

  @created         -
  @changed         12/9/2017

*************************************************************************************************************************/
sint32 MAT_QUANT(sint32 Val, sint32 LastVal, sint32 MinVal, sint32 MaxVal, sint32 Res, percentage_t DutyCycle)
{
  float32 hyst;
  sint32 interval, ret_val, help_val;
  sint32 upper, lower;

  if ((Res > (sint32)2) && (MaxVal > MinVal))
  {
    interval = (MaxVal - MinVal) / Res;

    hyst = (float32) interval;
    if (DutyCycle != ( (percentage_t) Percentage_s * (percentage_t) 50 ))
    {
      hyst *= ((float32)DutyCycle/(float32)Scale_100);
      hyst /= (float32)(Percentage_s);
    }
    else
    {
      hyst /= (float32)(2);
      hyst -= (float32)(1 * Percentage_s);
    }

    lower = MinVal;
    upper = lower + interval;
    help_val = MAT_LIM(Val, MinVal, MaxVal);

    while ((upper < MaxVal) && (help_val > upper) && (interval != 0))
    {
      lower = MAT_LIM((lower+interval), MinVal, MaxVal);
      upper = MAT_LIM((upper+interval), MinVal, MaxVal);
    }

    if ((help_val > (upper - ROUND_TO_INT(hyst))) && (help_val >= LastVal))
    {
      ret_val = upper;
    }
    else
    {
      if ((help_val < (lower + ROUND_TO_INT(hyst))) && (help_val <= LastVal))
      {
        ret_val = lower;
      }
      else
      {
        ret_val = LastVal;
      }
    }
    ret_val = MAT_LIM(ret_val, lower, upper);
  }
  else
  {
    ret_val = (sint32)LastVal;
  }

  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         MAT_S16_SUB_S16_S16                                                                          */ /*!

  @brief                This operation shall subtract an sint16 value from an sint16 value with overflow and underflow limitation

  @description          This operation shall subtract an sint16 value from an sint16 value with overflow and underflow limitation

                         @startuml
                         Start
                             Partition MAT_S16_SUB_S16_S16 {
                             - subtract the inputs
                             if(**result** is less than min of signed 16bit 32767) then (TRUE)
                                 :return lower limit -32768;
                             elseif( **result** is greater than max of signed 16bit) then (TRUE)
                                 :return upper limit 32767;    
                             Else(**result** is within range of signed 16bit)
                                 : return input value;
                             endif 
                             }
                         End
                         @enduml

  @return               sint16

  @param[in]            x_value           sint16      8000..7FFF       -32768..32767
  @param[in]            y_value           sint16      8000..7FFF       -32768..32767

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     Output of type sint16 = x_value-y_value and it should be limited between -32768 and 32767

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-544-0009fc80">CAL_544</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
sint16 MAT_S16_SUB_S16_S16(sint16 x_value, sint16 y_value)
{
  sint16 ret_val;
  sint32 result;

  result = ( sint32 )x_value - ( sint32 )y_value;

  if ( result < ( sint32 )sint16_LowerLimit )
  {
    ret_val = ( sint16 )sint16_LowerLimit;
  }
  else if ( result > ( sint32 )sint16_UpperLimit )
  {
    ret_val = ( sint16 )sint16_UpperLimit;
  }
  else
  {
    ret_val = ( sint16 )result;
  }

  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         MAT_U8_SUB_U8_U8                                                                          */ /*!

  @brief                This operation shall subtract an uint8 value from an uint8 value with underflow limitation

  @description          This operation shall subtract an uint8 value from an uint8 value with underflow limitation

                         @startuml
                         Start
                             Partition MAT_U8_SUB_U8_U8 {
                             if(Check input2 is greater than input1) then ( TRUE-result will be negative)
                                 :return 0;
                             else (FALSE -result will be positive)
                                 :return subtracted value;
                                 endif 
                             }
                         End
                         @enduml

  @return               uint8

  @param[in]            x_value            uint8         0..FF            0..255
  @param[in]            y_value            uint8         0..FF            0..255

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     Output of unit8 = x_value-y_value if x_value>=y_value, else output = 0

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-545-0009fc80">CAL_545</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
uint8 MAT_U8_SUB_U8_U8(uint8 x_value, uint8 y_value)
{
  uint8 ret_val;
  
  if ( y_value > x_value )
  {
    ret_val = ( uint8 )uint8_LowerLimit;
  }
  else
  {
    ret_val = x_value - y_value;
  }

  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         MAT_U16_SUB_U16_U16                                                                          */ /*!

  @brief                This operation shall subtract an uint16 value from an uint16 value with underflow limitation

  @description          This operation shall subtract an uint16 value from an uint16 value with underflow limitation

                         @startuml
                         Start
                             Partition MAT_U16_SUB_U16_U16 {
                             if(Check input2 is greater than input1) then ( TRUE-result will be negative)
                                 :return 0;
                             else (FALSE-result will be positive)
                                 :return subtracted value;
                                 endif 
                             }
                         End
                         @enduml

  @return               uint16

  @param[in]            x_value            uint16         0..FFFF            0..65535
  @param[in]            y_value            uint16         0..FFFF            0..65535

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     Output of type sint16 = x_value-y_value if x_value>y_value, else output = 0

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-546-0009fc80">CAL_546</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
uint16 MAT_U16_SUB_U16_U16(uint16 x_value, uint16 y_value)
{
  uint16 ret_val;

  if ( y_value > x_value )
  {
    ret_val = ( uint16 )uint16_LowerLimit;
  }
  else
  {
    ret_val = x_value - y_value;
  }

  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         MAT_S8_SUB_S8_S8                                                                          */ /*!

  @brief                This operation shall subtract an sint8 value from an sint8 value with overflow and underflow limitation

  @description          This operation shall subtract an sint8 value from an sint8 value with overflow and underflow limitation

                         @startuml
                         Start
                             Partition MAT_S8_SUB_S8_S8 {
                             : subtract the inputs;
                             if(**result** is within signed 8bit range (-128 to 127)) then (TRUE)
                                 :return **result**;
                             elseif(**result** is less than signed 8bit (-128))then (TRUE)
                                 :return lower limit -128;
                             Else(**result** is greater than signed 8bit:127) 
                                 :return upper limit 127;    
                             endif 
                             }
                         End
                         @enduml

  @return               sint8

  @param[in]            x_value            sint8      80..7F           -128..127
  @param[in]            y_value            sint8      80..7F           -128..127

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     Output of type sint8 = x_value-y_value and it should be limited between -128 and 127

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-547-0009fc80">CAL_547</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
sint8 MAT_S8_SUB_S8_S8(sint8 x_value, sint8 y_value)
{
  sint8 ret_val;
  sint16 result;

  result = ( sint16 )x_value - ( sint16 )y_value;

  if ( result < ( sint16 )sint8_LowerLimit )
  {
    ret_val = ( sint8 )sint8_LowerLimit;
  }
  else if ( result > ( sint16 )sint8_UpperLimit )
  {
    ret_val = ( sint8 )sint8_UpperLimit;
  }
  else
  {
    ret_val = ( sint8 )result;
  }

  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         MAT_S8_LIM_S8_S8_S8                                                                          */ /*!

  @brief                This operation shall limit a value of type sint8 between minimum or maximum values of type sint8

  @description          This operation shall limit a value of type sint8 between minimum or maximum values of type sint8

                         @startuml
                         Start
                             Partition MAT_S8_LIM_S8_S8_S8 {
                             If(**input** is lesser than given minimum limit) then (TRUE)
                                 : return minimum limit;
                             elseif(**input** is greater than given maximum limit)the (TRUE)
                                 : return maximum limit;
                             elseif (Input value  is within boundary)
                                 :return **input**;
                             Endif
                             }
                         End
                         @enduml

  @return               sint8

  @param[in]            value              sint8    80..7F          -128..127
  @param[in]            minimum            sint8    80..7F          -128..127
  @param[in]            maximum            sint8    80..7F          -128..127

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     value of type sint8 shall be limited between minimum and maximum of type sint8

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-548-0009fc80">CAL_548</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
sint8 MAT_S8_LIM_S8_S8_S8(sint8 value, sint8 minimum, sint8 maximum)
{
  sint8 ret_val;

  if ( value > maximum )
  {
    ret_val = maximum;
  }
  else
  {
    if ( value < minimum )
    {
      ret_val = minimum;
    }
    else
    {
      ret_val = value;
    }
  }
  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         MAT_S16_LIM_S16_S16_S16                                                                          */ /*!

  @brief                This operation shall limit a value of type sint16 between minimum or maximum values of type sint16

  @description          This operation shall limit a value of type sint16 between minimum or maximum values of type sint16

                         @startuml
                         Start
                             Partition MAT_S16_LIM_S16_S16_S16 {    
                             If (**input** is greater than maximum limit) then (TRUE)
                                 : return maximum limit;
                             elseif(**input** is lesser than minimum limit) then (TRUE)
                                 : return minimum limit;
                             else (input value is within boundary)
                                 :return **input**;
                             Endif
                             }
                         End
                         @enduml

  @return               sint16

  @param[in]            value              sint16      8000..7FFF       -32768..32767
  @param[in]            minimum            sint16      8000..7FFF       -32768..32767
  @param[in]            maximum            sint16      8000..7FFF       -32768..32767

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     value of type sint16 shall be limited between minimum and maximum of type sint16

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-549-0009fc80">CAL_549</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
sint16 MAT_S16_LIM_S16_S16_S16(sint16 value, sint16 minimum, sint16 maximum)
{
  sint16 ret_val;

  if ( value > maximum )
  {
    ret_val = maximum;
  }
  else
  {
    if ( value < minimum )
    {
      ret_val = minimum;
    }
    else
    {
      ret_val = value;
    }
  }
  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         MAT_U16_LIM_U16_U16_U16                                                                          */ /*!

  @brief                This operation shall limit a value of type uint16 between minimum or maximum values of type uint16

  @description          This operation shall limit a value of type uint16 between minimum or maximum values of type uint16

                         @startuml
                         Start
                             Partition MAT_U16_LIM_U16_U16_U16 {
                             If (**input** is greater than maximum limit) then (TRUE)
                                 : return maximum limit;
                             elseif(**input** is lesser than minimum limit) then (TRUE)
                                 : return minimum limit;
                             else (input value is within boundary)
                                 :return **input**;
                             Endif
                             }
                         End
                         @enduml

  @return               uint16

  @param[in]            value              uint16        0..FFFF        0..65535
  @param[in]            minimum            uint16        0..FFFF        0..65535
  @param[in]            maximum            uint16        0..FFFF        0..65535

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     value of type uint16 shall be limited between minimum and maximum of type uint16

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-550-0009fc80">CAL_550</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
uint16 MAT_U16_LIM_U16_U16_U16(uint16 value, uint16 minimum, uint16 maximum)
{
  uint16 ret_val;

  if ( value > maximum )
  {
    ret_val = maximum;
  }
  else
  {
    if ( value < minimum )
    {
      ret_val = minimum;
    }
    else
    {
      ret_val = value;
    }
  }
  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         MAT_S8_ADD_S8_S8                                                                          */ /*!

  @brief                This operation shall perform addition of two sint8 variables with underflow and overflow limitation and return result of type sint8

  @description          This operation shall perform addition of two sint8 variables with underflow and overflow limitation and return result of type sint8

                         @startuml
                         Start
                             Partition MAT_S8_ADD_S8_S8 { 
                             : Add the inputs;
                             If (**input** is greater than maximum limit) then (TRUE)
                                 : return maximum limit;
                             elseif(**input** is lesser than minimum limit) then (TRUE)
                                 : return minimum limit;
                             else (input value is within boundary)
                                 :return **input**;
                             Endif
                             }
                         End
                         @enduml

  @return               sint8

  @param[in]            x_value        sint8        80H..7FH        -128..127
  @param[in]            y_value        sint8        80H..7FH        -128..127

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     Output of type sint8 = x_value+y_value and it should be limited between -128 and 127

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-551-0009fc80">CAL_551</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
sint8 MAT_S8_ADD_S8_S8(sint8 x_value, sint8 y_value)
{
  sint8 ret_val;
  sint16 result;

  result = ( sint16 )x_value + ( sint16 )y_value;

  if ( result < ( sint16 )sint8_LowerLimit )
  {
    ret_val = ( sint8 )sint8_LowerLimit;
  }
  else if ( result > ( sint16 )sint8_UpperLimit )
  {
    ret_val = ( sint8 )sint8_UpperLimit;
  }
  else
  {
    ret_val = ( sint8 )result;
  }

  return ret_val;
}
#endif /* (0) Unused functions */

#if (FCT_CFG_LOHP_COMPONENT)
/*************************************************************************************************************************
  Functionname:         MAT_S16_ADD_S16_S16                                                                          */ /*!

  @brief                This operation shall perform addition of two sint16 variables with underflow and overflow limitation and return result of type sint16

  @description          This operation shall perform addition of two sint16 variables with underflow and overflow limitation and return result of type sint16

                         @startuml
                         Start
                             Partition MAT_S16_ADD_S16_S16 {
                             : Add the inputs;
                             If (**input** is greater than maximum limit) then (TRUE)
                                 : return maximum limit;
                             elseif(**input** is lesser than minimum limit) then (TRUE)
                                 : return minimum limit;
                             else (input value is within boundary)
                                 :return **input**;
                             Endif
                             }
                         End
                         @enduml

  @return               sint16

  @param[in]            x_value        sint16        8000..7FFFH     -32768..32767
  @param[in]            y_value        sint16        8000..7FFFH     -32768..32767

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     Output of type sint16 = x_value+y_value and it should be limited between -32768 and 32767

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-554-0009fc80">CAL_554</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
sint16 MAT_S16_ADD_S16_S16(sint16 x_value, sint16 y_value)
{
  sint16 ret_val;
  sint32 result;

  result = ( sint32 )x_value + ( sint32 )y_value;

  if ( result < ( sint32 )sint16_LowerLimit )
  {
    ret_val = ( sint16 )sint16_LowerLimit;
  }
  else if ( result > ( sint32 )sint16_UpperLimit )
  {
    ret_val = ( sint16 )sint16_UpperLimit;
  }
  else
  {
    ret_val = ( sint16 )result;
  }

  return ret_val;
}
#endif /* (FCT_CFG_LOHP_COMPONENT) */

#if (0) /* Disabling unused functions */
/*************************************************************************************************************************
  Functionname:         MAT_U8_ADD_U8_U8                                                                          */ /*!

  @brief                This operation shall perform addition of two uint8 variables with overflow limitation and return result of type uint8

  @description          This operation shall perform addition of two uint8 variables with overflow limitation and return result of type uint8

                         @startuml
                         Start
                             Partition MAT_U8_ADD_U8_U8 {
                             : Add the inputs;
                             If (**input** is greater than maximum limit) then (TRUE)
                                 : return maximum limit;
                             elseif(**input** is lesser than minimum limit) then (TRUE)
                                 : return minimum limit;
                             else (input value is within boundary)
                                 :return **input**;
                             Endif 
                             }
                         End
                         @enduml

  @return               uint8

  @param[in]            x_value        uint8         0..FFH            0..255
  @param[in]            y_value        uint8         0..FFH            0..255

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     Output of type unit8 = x_value+y_value and it should be limited between 0 and 255

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-552-0009fc80">CAL_552</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
uint8 MAT_U8_ADD_U8_U8(uint8 x_value, uint8 y_value)
{
  uint8 ret_val;
  uint16 result;

  result = ( uint16 )x_value + ( uint16 )y_value;

  if ( result > ( uint16 )uint8_UpperLimit )
  {
    ret_val = ( uint8 )uint8_UpperLimit;
  }
  else
  {
    ret_val = ( uint8 )result;
  }

  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         MAT_U16_ADD_U16_U16                                                                          */ /*!

  @brief                This operation shall perform addition of two uint16 variables with overflow limitation and return result of type uint16

  @description          This operation shall perform addition of two uint16 variables with overflow limitation and return result of type uint16

                         @startuml
                         Start
                             Partition MAT_U16_ADD_U16_U16 {
                             : Add the inputs ;
                             if(**result** is greater than max of unsigned 16bit (65535)) then (TRUE)
                                 :return u16 max value (65535);
                             Else (within range)
                                 :return **result**;
                                 endif 
                             }
                         End
                         @enduml

  @return               uint16

  @param[in]            x_value        uint16         0..FFFFH            0..65535
  @param[in]            y_value        uint16         0..FFFFH            0..65535

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     Output of type uint16 = x_value+y_value and it should be limited between 0 and 65535

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-553-0009fc80">CAL_553</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
uint16 MAT_U16_ADD_U16_U16(uint16 x_value, uint16 y_value)
{
  uint16 ret_val;
  uint32 result;

  result = ( uint32 )x_value + ( uint32 )y_value;

  if ( result > ( uint32 )uint16_UpperLimit )
  {
    ret_val = ( uint16 )uint16_UpperLimit;
  }
  else
  {
    ret_val = ( uint16 )result;
  }

  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         MAT_S16_ADD_S16_S16_S16                                                                          */ /*!

  @brief                This operation shall perform addition of three sint16 variables with underflow and overflow limitation and return result of type sint16

  @description          This operation shall perform addition of three sint16 variables with underflow and overflow limitation and return result of type sint16

                         @startuml
                         Start
                             Partition MAT_S16_ADD_S16_S16_S16 {
                             - Add the inputs 
                             if(sum value is less than min of signed 16bit(-32768))then (yes)
                                 -return s16 lower limit (-32768)
                             Elseif(sum value is less than min of signed 16bit(-32768))
                                 -return s16 upper limit (32767)
                             Else ( sum is within range of signed 16 bit)
                                 -return **sum value**
            
                                 endif 
                             }
                         End
                         @enduml

  @return               sint16

  @param[in]            x_value        sint16       8000..7FFF      -32768..32767
  @param[in]            y_value        sint16       8000..7FFF      -32768..32767
  @param[in]            z_value        sint16       8000..7FFF      -32768..32767

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     Output of type sint16 = x_value+y_value and it should be limited between -32768 and 32767

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-555-0009fc80">CAL_555</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
sint16 MAT_S16_ADD_S16_S16_S16(sint16 x_value, sint16 y_value, sint16 z_value)
{
  sint16 ret_val;
  sint32 result;

  result = ( sint32 )x_value + ( sint32 )y_value + ( sint32 )z_value;

  if ( result < ( sint32 )sint16_LowerLimit )
  {
    ret_val = ( sint16 )sint16_LowerLimit;
  }
  else if ( result > ( sint32 )sint16_UpperLimit )
  {
    ret_val = ( sint16 )sint16_UpperLimit;
  }
  else
  {
    ret_val = ( sint16 )result;
  }

  return ret_val;
}
#endif /* (0) Unused functions */

/*************************************************************************************************************************
  Functionname:         S16_S32                                                                          */ /*!

  @brief                This operation shall convert an sint32 value to an sint16 value with overflow and underflow limitation

  @description          This operation shall convert an sint32 value to an sint16 value with overflow and underflow limitation

                         @startuml
                         Start
                             Partition S16_S32 {    
                             if(**input** is greater than max of signed 16bit (32767)) then (TRUE)
                                 -return s16 upper limit (32767)
                             elseif(**input** is less than min of signed 16bit (-32768))then (TRUE)
                                 -return s16 lower limit (-32768)
                             Else (within range)
                                 -return **result**
                              endif 
                         }
                         End
                         @enduml

  @return               sint16

  @param[in]            value     sint32       80000000..7FFFFFFF   -2147483648..2147483647

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     value should be limited between -32768 and 32767

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-556-0009fc80">CAL_556</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
sint16 S16_S32(sint32 value)
{
  sint16 ret_val;

  if ( value < ( sint32 )sint16_LowerLimit )
  {
    ret_val = ( sint16 )sint16_LowerLimit;
  }
  else if ( value > ( sint32 )sint16_UpperLimit )
  {
    ret_val = ( sint16 )sint16_UpperLimit;
  }
  else
  {
    ret_val = ( sint16 )value;
  }

  return ret_val;
}

#if (0) /* Disabling unused functions */
/*************************************************************************************************************************
  Functionname:         S16_U16                                                                          */ /*!

  @brief                This operation shall convert an uint16 value to an sint16 value with overflow limitation

  @description          This operation shall convert an uint16 value to an sint16 value with overflow limitation

                         @startuml
                         Start
                             Partition S16_U16 {
                             if(**input** is greater than max of signed 16bit(32767)) then (TRUE)
                                 :return s16 upper limit (32767);    
                             else (within range)
                                 :return ** input **;

                              endif 
                         }
                         End
                         @enduml

  @return               sint16

  @param[in]            value     uint16      0..FFFF            0..65535

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     output = value if value < 32767, else output=32767

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-557-0009fc80">CAL_557</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
sint16 S16_U16(uint16 value)
{
  sint16 ret_val;

  if ( value > ( uint16 )sint16_UpperLimit )
  {
    ret_val = ( sint16 )sint16_UpperLimit;
  }
  else
  {
    ret_val = ( sint16 )value;
  }

  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         U8_U16                                                                          */ /*!

  @brief                This operation shall convert an uint16 value to an uint8 value with overflow limitation

  @description          This operation shall convert an uint16 value to an uint8 value with overflow limitation

                         @startuml
                         Start
                             Partition U8_U16 {
                             if(**input** is greater than unsigned 8bit(255)) then (TRUE)
                                 :return u8 upper limit (255);            
                             else (within range)
                                 :return ** input **;
                              Endif
                         } 
                         End
                         @enduml

  @return               uint8

  @param[in]            value     uint16      0..FFFF            0..65535

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     output = value if value < 255, else output=255

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-558-0009fc80">CAL_558</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
uint8 U8_U16(uint16 value)
{
  uint8 ret_val;

  if ( value > ( uint16 )uint8_UpperLimit )
  {
    ret_val = ( uint8 )uint8_UpperLimit;
  }
  else
  {
    ret_val = ( uint8 )value;
  }

  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         U16_S16                                                                          */ /*!

  @brief                This operation shall convert an sint16 value to an uint16 value with underflow limitation

  @description          This operation shall convert an sint16 value to an uint16 value with underflow limitation

                         @startuml
                         Start
                             Partition U16_S16 {
                             if(**input** is less than 0) then (TRUE)
                                 :return u16 lower limit (0);            
                             else (within range)
                                 :return ** input **;
                              endif 
                         }
                         End
                         @enduml

  @return               uint16

  @param[in]            value     sint16       8000..7FFF      -32768..32767

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     output=value if value > 0, else output=0

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-559-0009fc80">CAL_559</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
uint16 U16_S16(sint16 value)
{
  uint16 ret_val;

  if ( value < ( sint16 )uint16_LowerLimit )
  {
    ret_val = ( uint16 )uint16_LowerLimit;
  }
  else
  {
    ret_val = ( uint16 )value;
  }

  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         S8_S16                                                                          */ /*!

  @brief                This operation shall convert an sint16 value to an sint8 value with overflow and underflow limitations

  @description          This operation shall convert an sint16 value to an sint8 value with overflow and underflow limitations

                         @startuml
                         Start
                             Partition S8_S16 {
                             if(**input** is greater than max of signed 8bit (127)) then (TRUE)
                                 :return s8 upper limit (127);
                             elseif(**input ** is less than min of signed 8bit (-128))then (TRUE)
                                 :return s8 lower limit (-128);
                             else (within range)
                                 :return **input**;    
                              endif 
                         }
                         End
                         @enduml

  @return               sint8

  @param[in]            value     sint16       8000..7FFF      -32768..32767

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     value shall be limited between -128 and 127

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-560-0009fc80">CAL_560</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
sint8 S8_S16(sint16 value)
{
  sint8 ret_val;

  if ( value < ( sint16 )sint8_LowerLimit )
  {
    ret_val = ( sint8 )sint8_LowerLimit;
  }
  else if ( value > ( sint16 )sint8_UpperLimit )
  {
    ret_val = ( sint8 )sint8_UpperLimit;
  }
  else
  {
    ret_val = ( sint8 )value;
  }

  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         U16_S32                                                                          */ /*!

  @brief                This operation shall convert an sint32 value to an uint16 value with overflow and underflow limitation

  @description          This operation shall convert an sint32 value to an uint16 value with overflow and underflow limitation

                         @startuml
                         Start
                             Partition U16_S32 {
                             if(**input** is greater than max of unsigned 16 bit (65535)) then (TRUE)
                                 :return u16 upper limit (65535);
                             elseif(**input ** is less than 0)then (TRUE)
                                 :return u16 lower limit (0);
                             else (within range)
                                 :return **input**;    
                              endif 
                         }
                         End
                         @enduml

  @return               uint16

  @param[in]            value     sint32      80000000..7FFFFFFF  -2147483648..2147483647

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     value shall be limited between 0 and 65535

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-561-0009fc80">CAL_561</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
uint16 U16_S32(sint32 value)
{
  uint16 ret_val;

  if ( value < ( sint32 )uint16_LowerLimit )
  {
    ret_val = ( uint16 )uint16_LowerLimit;
  }
  else if ( value > ( sint32 )uint16_UpperLimit )
  {
    ret_val = ( uint16 )uint16_UpperLimit;
  }
  else
  {
    ret_val = ( uint16 )value;
  }

  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         U8_S8                                                                          */ /*!

  @brief                This operation shall convert an sint8 value to an uint8 value with underflow limitation

  @description          This operation shall convert an sint8 value to an uint8 value with underflow limitation

                         @startuml
                         Start
                             Partition U8_S8 {
                             if(**input** is less than 0) then (TRUE)
                                 :return u8 lower limit (0);
                             else (within range)
                                 :return **input**;    
                              endif 
                         }
                         End
                         @enduml

  @return               uint8

  @param[in]            value     sint8         80..7F           -128..127

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     output=value if value >0, else output=0

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-562-0009fc80">CAL_562</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
uint8 U8_S8(sint8 value)
{
  uint8 ret_val;

  if ( value < ( sint8 )uint8_LowerLimit )
  {
    ret_val = ( uint8 )uint8_LowerLimit;
  }
  else
  {
    ret_val = ( uint8 )value;
  }

  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         U8_S16                                                                          */ /*!

  @brief                This operation shall convert an sint16 value to an uint8 value with overflow and underflow limitation

  @description          This operation shall convert an sint16 value to an uint8 value with overflow and underflow limitation

                         @startuml
                         Start
                             Partition U8_S16 {    
                             if(**input** is greater than max of unsigned 8 bit(255)) then (TRUE)
                                 :return u8 upper limit (255);
                             elseif(**input ** is lesser than min of unsigned 8 bit(0))then (TRUE)
                                 :return u8 lower limit (0);
                             else (within range)
                                 :return **input**;    
                              endif 
                         }
                         End
                         @enduml

  @return               uint8

  @param[in]            value     sint16       8000..7FFF            -32768..32767

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     value shall be limited between 0 and 255

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-563-0009fc80">CAL_563</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
uint8 U8_S16(sint16 value)
{
  uint8 ret_val;

  if ( value < ( sint16 )uint8_LowerLimit )
  {
    ret_val = ( uint8 )uint8_LowerLimit;
  }
  else if ( value > ( sint16 )uint8_UpperLimit )
  {
    ret_val = ( uint8 )uint8_UpperLimit;
  }
  else
  {
    ret_val = ( uint8 )value;
  }

  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         S8_U8                                                                          */ /*!

  @brief                This operation shall convert an uint8 value to an sint8 value with overflow limitation

  @description          This operation shall convert an uint8 value to an sint8 value with overflow limitation

                         @startuml
                         Start
                             Partition S8_U8 {
                              if(**input** is greater than max signed 8bit(127)) then (TRUE)
                                 :return s8 upper limit (127);
                             else (within range)
                                 :return **input**;    
                              endif 
                         }
                         End
                         @enduml

  @return               sint8

  @param[in]            value     uint8             0..FF               0..255

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     output=value if value <=127, else output=127

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-564-0009fc80">CAL_564</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
sint8 S8_U8(uint8 value)
{
  sint8 ret_val;

  if ( value > ( uint8 )sint8_UpperLimit )
  {
    ret_val = ( sint8 )sint8_UpperLimit;
  }
  else
  {
    ret_val = ( sint8 )value;
  }

  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         S8_U16                                                                          */ /*!

  @brief                This operation shall convert an uint16 value to an sint8 value with overflow limitation

  @description          This operation shall convert an uint16 value to an sint8 value with overflow limitation

                         @startuml
                         Start
                             Partition S8_U16 {    
                             if(**input**  is greater than min of signed 8bit (127)) then (TRUE)
                                 :return s8 upper limit (127);     
                             else (within range)
                                 :return **input**;    
                              endif 
                         }
                         End
                         @enduml

  @return               sint8

  @param[in]            value     uint16          0000..FFFF           0..65535

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     output=value if value <=127, else output=127

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-565-0009fc80">CAL_565</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
sint8 S8_U16(uint16 value)
{
  sint8 ret_val;

  if ( value > ( uint16 )sint8_UpperLimit )
  {
    ret_val = ( sint8 )sint8_UpperLimit;
  }
  else
  {
    ret_val = ( sint8 )value;
  }

  return ret_val;
}

/*************************************************************************************************************************
  Functionname:         S8_S32                                                                          */ /*!

  @brief                This operation shall convert an sint32 value to an sint8 value with over flow and underflow limitation

  @description          This operation shall convert an sint32 value to an sint8 value with over flow and underflow limitation

                         @startuml
                         Start
                             Partition S8_S32 {
                             if(**input** is greater than max of signed 8bit(127)) then (TRUE)
                                 :return s8 upper limit (127);
                             Elseif (**input ** is less than min of signed 8bit (-128))then (TRUE)
                                 :return s8 lower limit (-128);
                             else (within range)
                                 :return **input**;    
                              endif 
                         }
                         End
                         @enduml

  @return               sint8

  @param[in]            value     sint32    80000000..7FFFFFFF    -2147483648..2147483647

  @glob_in              No global input variable used
  @glob_out             No global output variable used

  @c_switch_part        FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre                  None
  @post                 None

  @InOutCorrelation     value shall be limited between -128 and 127

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-566-0009fc80">CAL_566</a> \n

  @author               Hans-Juergen Schnellbach | Hans-Juergen.Schnellbach@continental-corporation.com | +49 (8382) 9699-573
*************************************************************************************************************************/
sint8 S8_S32(sint32 value)
{
  sint8 ret_val;

  if ( value < ( sint32 )sint8_LowerLimit )
  {
    ret_val = ( sint8 )sint8_LowerLimit;
  }
  else if ( value > ( sint32 )sint8_UpperLimit )
  {
    ret_val = ( sint8 )sint8_UpperLimit;
  }
  else
  {
    ret_val = ( sint8 )value;
  }

  return ret_val;
}
#endif /* (0) Unused functions */

/*************************************************************************************************************************
  Functionname:    MAT_HYST                                                                                   */ /*!

  @brief           Hysteresis filter to clip peaks and amplitude in order to prevent oscillations 

  @description     Smoothing filter to prevent oscillations and other discontinuous waveforms

                     @startuml
                     Start
                        Partition MAT_HYST {
                        If( new input value is greater the old hysteresis output)  then (TRUE)
                           :Integral error is calculated  based on previous integral error, least hysteresis and maximum integrated error with upper limit as ZERO;
                           -Least Hysteresis as a quote of 2% of Maximum Hysteresis;
                           -Maximum of the last hystersis and new calculated value;
                        Else(FALSE)
                           :Integral error is calculated  based on previous integral error, least hysteresis and maximum integrated error with lower limit as ZERO;
                           - Least Hysteresis as a quote of 2% of Maximum Hysteresis;
                           - Minimum of the last hystersis and new calculated value ;
                        Endif
                        -Calculate the integral distance error
                        if(Integral error is present in current cyle and not in previous cycle or viceversa) then (TRUE)
                           -multipy a factor to the integral error, for faster reduction of the error distance 
                        Else (FALSE)
                           If (last cycle Integral error is greater than product integral time limit and soft anti windup limit) then (TRUE)
                                 -anti wind up in two steps
                                 - Integral error is limited in the range of +/- Integral time error limit
                           endif
                        endif
                        - Addition of the error distance due to hysteresis effect
                     }
                     End
                     @enduml

  @return          sint32

  @param[in]       u16_CycleTime           : Task cycle time [Full range of datatype times_t as in Rte_type.h]
  @param[in]       f_NewInput              : Un-filtered input value from current cycle [Full range of datatype sint16 as in Rte_type.h]
  @param[in]       f_InputHyst_Fak         : Factor value for the step value 
  @param[in]       f_InputHyst_Nomin       : Numerator input value for the hystersis step value computation
  @param[in]       f_InputHyst_Denom       : Denominator input  value for the hystersis step value computation
  @param[in]       f_IntegralTimeErrorLimit: Maximum allowed integral error 
  @param[in]       pf_IntegralError        : Integral error captured during the hystersis computation
  @param[in]       pf_HystOutput           : Filtered value from last cycle [Full range of datatype sint16 as in Rte_type.h]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation     None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-567-0009fc80">CAL_567</a> \n

  @created         16.11.2018
  @changed         16.11.2018

  @author          Armin Stecher | armin.stecher@continental-corporation.com | +49 (8382) 9699-895
*************************************************************************************************************************/
void MAT_HYST
(
   times_t u16_CycleTime
 , float32 f_NewInput
 , float32 f_InputHyst_Fak 
 , float32 f_InputHyst_Nomin 
 , float32 f_InputHyst_Denom 
 , float32 f_IntegralTimeErrorLimit
 , float32 * pf_IntegralError
 , float32 * pf_HystOutput
)
{
  /* local vars */
  float32 f_HystHalf;
  float32 f_IntegralError;
  float32 f_Abs_IntegralError;
  float32 f_CycleTime = ( float32 )u16_CycleTime /( float32 ) Time_s;
  
  f_HystHalf = f_InputHyst_Fak * ( fABS( f_NewInput) + f_InputHyst_Nomin  ) / ( f_InputHyst_Denom + fABS( f_NewInput )); 
  
  /* Dynamische Hysterese */
  if ( f_NewInput >= *pf_HystOutput )  
  {
    /* Rising value compared to hysteresis value, resulting hysteresis value is possible to be smaller */
    /* 0.8 m is maximum value for DeltaDistance leads to reduce the hysteresis by f_RelLongSpdHystHalf m/s */
    /* error distance is getting negative */
    f_IntegralError = MIN_FLOAT(( *pf_IntegralError * f_HystHalf / ( f_IntegralTimeErrorLimit * MAX_TIME_INTEGRATED_ERROR )), 0.0f );
   
    /* Least Hysteresis as a quote of 2% of Maximum Hysteresis */
    f_HystHalf = MAX_FLOAT( f_HystHalf + f_IntegralError, MIN_ABS_HYST );
    *pf_HystOutput = MAX_FLOAT( *pf_HystOutput, ( f_NewInput - f_HystHalf  ));

  }
  else 
  {   
    /* Falling value of relative speed between ego and target vehicle, f_hystFinIn lower than actual hysteresis value */
    f_IntegralError = MAX_FLOAT( *pf_IntegralError * f_HystHalf / ( f_IntegralTimeErrorLimit * MAX_TIME_INTEGRATED_ERROR), 0.0f ); // Test

    /* Least Hysteresis as a quote of 2% of Maximum Hysteresis */
    f_HystHalf = MAX_FLOAT( f_HystHalf - f_IntegralError, MIN_ABS_HYST );
    *pf_HystOutput = MIN_FLOAT( *pf_HystOutput, ( f_NewInput + f_HystHalf ));
  }

  f_IntegralError = ( *pf_HystOutput - f_NewInput ) * f_CycleTime;

  if (( f_IntegralError > 0.0f ) != ( *pf_IntegralError > 0.0f ))
  {
    /* Faster reduction of the error distance */
    f_IntegralError *= ERROR_REDUCTION_FAC;
  }
  else
  {
    f_Abs_IntegralError = fABS( *pf_IntegralError );
    if ( f_Abs_IntegralError >= ( f_IntegralTimeErrorLimit * SOFT_ANTI_WINDUP_LIMIT ))
    {
      /* anti wind up in two steps */
      f_IntegralError *= SOFT_ANTI_WINDUP_INPUT_FAC;
      /* limited to +/- f_IntegralTimeErrorLimit */
      *pf_IntegralError = MAX_FLOAT( *pf_IntegralError, -f_IntegralTimeErrorLimit );
      *pf_IntegralError = MIN_FLOAT( *pf_IntegralError,  f_IntegralTimeErrorLimit ); 
    }  
  }

  /* Addition of the error distance due to hysteresis effect */
  *pf_IntegralError += f_IntegralError;
}

#endif /* (FCT_CFG_ACC_CAL) */
// PRQA L:STTPP_EXCEEDED
/* date: 28/06/2019 author: Pruthvi Reason: Number of lines exceeded per file, not safety critical */
// PRQA S 7013
