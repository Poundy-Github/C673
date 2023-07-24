/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_fuzzy.c

DESCRIPTION:               Math Functions of all fuzzy related functions like
                           logical operations, fuzzification and defuzzification

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            Revision: 1.7.1.1


**************************************************************************** */
#include "cal_int.h"/* PRQA S 0380
date: 28/06/2019 author: Pruthvi Reason: Can be ignored as no functional impact */

#if (FCT_CFG_ACC_CAL)

static signed_fuzzy_t FuzzyArea, FuzzyAreaPos;

/*smallest/largest value of the result of the fuzzification*/
static signed_fuzzy_t Fuzzy_ValMin,Fuzzy_ValMax;// PRQA S 3218 //PRQA S 3229
/* date: 2017-10-31, reviewer: Dyuthi Varier, reason: function is switched off currently, will be used in future*/

/*-------------------------------------------------------------------------------------------*/


static signed_fuzzy_t FUZZY_GET_AREA(const fuzzy_var_t *var,signed_fuzzy_t scale,signed_fuzzy_t *mid);
static signed_fuzzy_t FUZZY_GET_AREA_POS(const fuzzy_var_t *var,signed_fuzzy_t scale,signed_fuzzy_t *mid);

/*****************************************************************************

                    --------------------    ........... FUZZY_SCALE1
                  / x2                x3 \.            
                 /                        \.           
        ---------                          -------- ... 0
                 x1                        x4

      if x1=x2 or x3=x4 the curve doesn't begin/end at 0 but at FUZZY_SCALE1
      to get a discrete (non fuzzy) logic: set x1=x2-1 / x4=x3+1

*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    FUZZY_GET_FUZZY_VAL                                                                              */ /*!

  @brief           gets the height of the curve of the linguistic variable for a "crisp value"

  @description     gets the height of the curve of the linguistic variable for a "crisp value"

                    @startuml
                    Start
                    Partition FUZZY_GET_FUZZY_VAL { 
                        : Read the linguistic variable with four fuzzy numbers (lower limit:x1,lower support limit:x2,upper support limit:x3,upper limit:x4) \n of a curve and crisp value c;
                        if (If Lower-limit and lower-support-limit are same ?) then (yes)
                            : curve begins at value 1;
                        else (no)
                            : curve begins at value 0;
                        Endif
                        if (If Upper-limit and Upper-support-limit are same ?) then (yes)
                            : curve ends at value 1;
                        else (no)
                            : curve ends at value 0;
                        endif

                        If (Is crispValue(c) smaller than lower-limit(x1) ?) then (Yes)
                            : Height of curve is set to value at beginning of curve; 
                        Else(No) 
                            If (Is crispValue(c) greater than uypper-limit(x4) ?) then (Yes)
                                : Height of curve is set to value at end of curve;
                            Else (No)
                        If (Is crispValue range in between  lower & upper support limit) then (yes)
                            : Height of curve is 1;
                        Else(No)
                            If (Is crispValue range in between Lower & upper limit) then (yes)
                                : height of curve is (c – x1)/(x2 – x1);
                            Else (No)
                                If (Is crispValue range in between upper & upper support limit) then (yes)
                                    : height of curve is (x4 – c)/(x4 – x3);
                                Else (No)
                                    : height of curve is 0;
                                Endif
                                Endif 
                            Endif
                        Endif
                        Endif
                    }
                    Stop
                    @enduml

  @return          signed_fuzzy_t return_val :                     [Full range of sint32]

  @param[in]       *var :        pointer to a linguistic variable  [fuzzy_var_t defined in cal_fuzzy_ext.h]
  @param[in]       crispValue :  a crisp value                     [Full range of sint32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full    FCT_CFG_LOPC_COMPONENT  : Configuration switch for enabling FCT_LONG processing

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-510-0009fc80">CAL_510</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
signed_fuzzy_t FUZZY_GET_FUZZY_VAL(const fuzzy_var_t *var, signed_fuzzy_t crispValue)
{
  /*values before and after the curve (standard:0)*/
  signed_fuzzy_t minval,maxval;
  signed_fuzzy_t return_val;


  minval=(signed_fuzzy_t)0;
  maxval=(signed_fuzzy_t)0;

  /*if first parameter of curve = 2nd one -> curve begins at value 1 (not 0)*/
  if(var->x1==var->x2)
  {
    minval=(signed_fuzzy_t)FUZZY_SCALE1;
  }
  /*if 3rd parameter of curve = 4th one -> curve ends at value 1 (not 0)*/
  if(var->x3==var->x4)
  {
    maxval=(signed_fuzzy_t)FUZZY_SCALE1;
  }
  
  if(crispValue<=var->x1)
  { /*smaller than begin of curve*/
    return_val = minval;
  }
  else if(crispValue>=var->x4)
  {/*larger than end of curve*/
    return_val = maxval;
  }
  else if (crispValue>var->x3)
  { /*falling part of the curve*/
    return_val = ((var->x4-crispValue)*(signed_fuzzy_t)FUZZY_SCALE1)/(var->x4-var->x3);
  }
  else if(crispValue>=var->x2)
  {/*at the top of the curve*/
    return_val = (signed_fuzzy_t)FUZZY_SCALE1;
  }
  else
  {/*rising part of the curve*/
    return_val = ((crispValue-var->x1)*(signed_fuzzy_t)FUZZY_SCALE1)/(var->x2-var->x1);
  }
  return return_val;
}

#if (0) /* Disabling unused functions */
/*************************************************************************************************************************
  Functionname:    FUZZY_AND                                                                                        */ /*!

  @brief           logical AND for fuzzy logic

  @description     logical AND for fuzzy logic

                    @startuml
                    Start
                    Partition FUZZY_AND {
                      : Read two input variables a and b;
                      if (**Is a less than b ?**) then (yes)
                          : value of b is set to a;
                      else (no)
                          : value of b is retained;
                      : Value of b gives the result of Fuzzy AND logic of a and b;
                    Endif
                    }
                    Stop
                    @enduml

  @return          signed_fuzzy_t  logical AND of the two inputs (min)   [ Full range of sint32]

  @param[in]       v1 : a crisp value out of FUZZY_GETFUZZYVAL           [Full range of sint32]
  @param[in]       v2 : a crisp value out of FUZZY_GETFUZZYVAL           [Full range of sint32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full    FCT_CFG_LOPC_COMPONENT  : Configuration switch for enabling FCT_LONG processing

  @pre             None
  @post            None

  @InOutCorrelation   Output is the minimum of the two inputs v1 and v2

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-511-0009fc80">CAL_511</a> \n

  @created         -
  @changed         3/3/2016

*************************************************************************************************************************/
signed_fuzzy_t FUZZY_AND(signed_fuzzy_t v1,signed_fuzzy_t v2)
{
  return MAT_MIN(v1,v2);
}

/*************************************************************************************************************************
  Functionname:    FUZZY_OR                                                                                         */ /*!

  @brief           logical OR for fuzzy logic

  @description     logical OR for fuzzy logic

                    @startuml
                    Start
                    Partition FUZZY_OR {
                      : Read two input variables a and b;
                      if ( **Is a greater than b ?**) then (Yes)
                          : value of b is set to a;
                      else (No)
                          : value of b is retained;
                      : Value of b gives the result of Fuzzy OR logic of a and b;
                    Endif
                    }
                    Stop
                    @enduml

  @return          signed_fuzzy_t : logical OR of the two inputs (MAX)  [Full range of sint32]

  @param[in]       v1 : a crisp value out of FUZZY_GETFUZZYVAL          [Full range of sint32]
  @param[in]       v2 : a crisp value out of FUZZY_GETFUZZYVAL          [Full range of sint32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full    FCT_CFG_LOPC_COMPONENT  : Configuration switch for enabling FCT_LONG processing

  @pre             None
  @post            None

  @InOutCorrelation   Output is the maximum of two inputs v1 and v2

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-512-0009fc80">CAL_512</a> \n

  @created         -
  @changed         3/3/2016

*************************************************************************************************************************/
signed_fuzzy_t FUZZY_OR(signed_fuzzy_t v1,signed_fuzzy_t v2)
{
  return MAT_MAX(v1,v2);
}
#endif /* (0) Unused functions */

/*************************************************************************************************************************
  Functionname:    FUZZY_NOT                                                                                        */ /*!

  @brief           logical NOT for fuzzy logic

  @description     logical NOT for fuzzy logic

                    @startuml
                    Start
                    Partition FUZZY_NOT {
                      : Read variable a as input;
                      if (**(1-a) > 0 ?**) then (yes)
                          : fuzzy NOT logic is (1-a);
                      else (no)
                          : fuzzy NOT logic is 0;
                    Endif
                    }
                    Stop
                    @enduml

  @return          signed_fuzzy_t  logical NOT of an input        [Full range of sint32 >=0]

  @param[in]       val :  a crisp value out of FUZZY_GETFUZZYVAL  [Full range of sint32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full    FCT_CFG_LOPC_COMPONENT  : Configuration switch for enabling FCT_LONG processing

  @pre             None
  @post            None

  @InOutCorrelation   Output is the maximum of (1- input value) and 0

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-513-0009fc80">CAL_513</a> \n

  @created         -
  @changed         3/3/2016

*************************************************************************************************************************/
signed_fuzzy_t FUZZY_NOT(signed_fuzzy_t val)
{
  return MAT_MAX((signed_fuzzy_t)FUZZY_SCALE1-val,(signed_fuzzy_t)0);
}

/*************************************************************************************************************************
  Functionname:    FUZZY_PROD                                                                                       */ /*!

  @brief           PROD for fuzzy logic

  @description     PROD for fuzzy logic

                    @startuml
                    Start
                    Partition FUZZY_PROD {
                      : Read input variables v1 and v2;
                      : Fuzzy product logic of v1 and v2 is ** v1*v2 **;
                    }
                    Stop
                    @enduml

  @return          signed_fuzzy_t  PROD of the two inputs       [Full range of sint32]

  @param[in]       v1 : a crisp value out of FUZZY_GETFUZZYVAL  [Full range of sint32]
  @param[in]       v2 : a crisp value out of FUZZY_GETFUZZYVAL  [Full range of sint32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full    FCT_CFG_LOPC_COMPONENT  : Configuration switch for enabling FCT_LONG processing

  @pre             None
  @post            None

  @InOutCorrelation   Output is the product of the two inputs v1 and v2

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-514-0009fc80">CAL_514</a> \n

  @created         -
  @changed         3/3/2016

*************************************************************************************************************************/
signed_fuzzy_t FUZZY_PROD(signed_fuzzy_t v1,signed_fuzzy_t v2)
{
  return (v1*v2)/(signed_fuzzy_t)FUZZY_SCALE1;
}

#if (0) /* Disabling unused functions */
/*************************************************************************************************************************
  Functionname:    FUZZY_PROBOR                                                                                     */ /*!

  @brief           logical PROBOR for fuzzy logic

  @description     logical PROBOR for fuzzy logic

                    @startuml
                    Start
                    Partition FUZZY_PROBOR {
                      : Read input variables v1 and v2;
                      : Fuzzy probabilistic OR logic is difference of the sum of inputs and product of inputs;
                    }
                    Stop
                    @enduml

  @return          signed_fuzzy_t  logical PROBOR of the two inputs  [Full range of sint32]

  @param[in]       v1 : a crisp value out of FUZZY_GETFUZZYVAL       [Full range of sint32]
  @param[in]       v2 : a crisp value out of FUZZY_GETFUZZYVAL       [Full range of sint32]

  @glob_in         No global input variables used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full    FCT_CFG_LOPC_COMPONENT  : Configuration switch for enabling FCT_LONG processing

  @pre             None
  @post            None

  @InOutCorrelation   Output is the difference between sum of two inputs and product of two inputs

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-515-0009fc80">CAL_515</a> \n

  @created         -
  @changed         3/3/2016

*************************************************************************************************************************/
signed_fuzzy_t FUZZY_PROBOR(signed_fuzzy_t v1,signed_fuzzy_t v2)
{
  return (v1+v2)-FUZZY_PROD(v1,v2);
}
#endif /* (0) Unused functions */

/*************************************************************************************************************************
  Functionname:    FUZZY_DEFUZZY_INIT                                                                               */ /*!

  @brief           initialize Defuzzification

  @description     initialize Defuzzification

                    @startuml
                    Start
                    Partition FUZZY_DEFUZZY_INIT {
                      : Read minimum and maximum values of fuzzification as inputs;
                      : Initialize minimum value and maximum value to minimum and maximum values of fuzzification respectively;
                      : Initialize the area and center of area to 0;
                    }
                    Stop
                    @enduml

  @return          void

  @param[in]       vmin : smallest value of the result of the fuzzification  [Full range of sint32]
  @param[in]       vmax : largest value of the result of the fuzzification   [Full range of sint32]

  @glob_in         No global input variables used
  @glob_out        Fuzzy_ValMin  [Full range of sint32]
  @glob_out        Fuzzy_ValMax  [Full range of sint32]
  @glob_out        FuzzyArea  [Full range of sint32]
  @glob_out        FuzzyAreaPos  [Full range of sint32]

  @c_switch_part   -
  @c_switch_full    FCT_CFG_LOPC_COMPONENT  : Configuration switch for enabling FCT_LONG processing

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-516-0009fc80">CAL_516</a> \n

  @created         -
  @changed         3/3/2016

*************************************************************************************************************************/
void FUZZY_DEFUZZY_INIT(signed_fuzzy_t vmin, signed_fuzzy_t vmax)
{
  Fuzzy_ValMin=vmin;
  Fuzzy_ValMax=vmax;
  FuzzyArea = 0;
  FuzzyAreaPos = 0;
}

/*************************************************************************************************************************
  Functionname:    FUZZY_DEFUZZY_ADD                                                                                */ /*!

  @brief           Adds a fuzzy rule

  @description     Adds a fuzzy rule

                    @startuml
                    Start
                    Partition FUZZY_DEFUZZY_ADD {
                      : Read scaling factor, fuzzy result as inputs;
                      : The fuzzy area of fuzzification is calculated using FUZZY_GET_AREA function;
                      : The center of the area is set to the centroid value;
                    }
                    Stop
                    @enduml

  @return          void

  @param[in]       *var :    Pointer to a fuzzy variable                   [fuzzy_var_t defined in cal_fuzzy_ext.h]
  @param[in]       scale :   Extra weight value for this rule (%) (0-100)  [full range of sint32]
  @param[in]       fuzzyval : a fuzzy result  fuzzyval < 0 means NOT var   [full range of sint32]

  @glob_in         FUZZY_PERCENT which is used as scaling value for percentages
  @glob_out        FuzzyArea  [Full range of sint32]
  @glob_out        FuzzyAreaPos  [Full range of sint32]

  @c_switch_part   -
  @c_switch_full    FCT_CFG_LOPC_COMPONENT  : Configuration switch for enabling FCT_LONG processing

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-517-0009fc80">CAL_517</a> \n

  @created         -
  @changed         3/3/2016

*************************************************************************************************************************/
void FUZZY_DEFUZZY_ADD
(
   const fuzzy_var_t *var
 , signed_fuzzy_t scale
 , signed_fuzzy_t fuzzyval
#if (FCT_CFG_DEBUG_FUZZY_CONTROLLER)
 , uint8 rule_id
 , FuzzyDebugData_t *pFuzzyDebugData
#endif /* (FCT_CFG_DEBUG_FUZZY_CONTROLLER) */
)
{
  signed_fuzzy_t area;
  signed_fuzzy_t mid;

  mid=(signed_fuzzy_t)0;
  area=FUZZY_GET_AREA(var,(scale*fuzzyval)/(signed_fuzzy_t)FUZZY_PERCENT,&mid);

  FuzzyArea+=area;
  FuzzyAreaPos+=area*mid;

#if (FCT_CFG_DEBUG_FUZZY_CONTROLLER)      
  (*pFuzzyDebugData).FUZZY_RULE_DATA[rule_id].area = area;
  (*pFuzzyDebugData).FUZZY_RULE_DATA[rule_id].fuzzyval = fuzzyval;
  (*pFuzzyDebugData).FUZZY_RULE_DATA[rule_id].mid = mid;
#endif /* (FCT_CFG_DEBUG_FUZZY_CONTROLLER) */
}

/*************************************************************************************************************************
  Functionname:    FUZZY_GET_CUT_VALUE                                                                              */ /*!

  @brief           calculates first/second x value for the linguistic variable "var" and the cutting line "cut"

  @description     calculates first/second x value for the linguistic variable "var" and the cutting line "cut"

                    @startuml
                    Start
                    Partition FUZZY_GET_CUT_VALUE {
                      : Read the trapezoidal fuzzy number (x1,x2,x3,x4), scaling factor and the first or second cut (nr) of the fuzzy number;
                      If (** Is it the first cut of the fuzzy number ?**) then (Yes)
                          : first x cut value is calculateda by x1 + (x2-x1)*scale ;
                      Else (No)
                          If (** Is it the second cut of the fuzzy number ?**) then (Yes)
                              : second x cut value is calculated by x4 – (x4-x3)*scale ;
                          Else (No)
                              : x cut value is 0;
                          Endif
                      Endif
                    }
                    Stop
                    @enduml

  @return          signed_fuzzy_t  return_val : x point      [full range of sint32]

  @param[in]       *var :  pointer to a fuzzy variable       [fuzzy_var_t defined in cal_fuzzy_ext.h]
  @param[in]       scale : Extra weight value for this rule  [full range of sint32]
  @param[in]       nr :    [1/2] first or second value       [full range of uint8]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full    FCT_CFG_LOPC_COMPONENT  : Configuration switch for enabling FCT_LONG processing

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-518-0009fc80">CAL_518</a> \n

  @created         -
  @changed         3/3/2016

*************************************************************************************************************************/
signed_fuzzy_t FUZZY_GET_CUT_VALUE(const fuzzy_var_t *var, signed_fuzzy_t scale,uint8 nr)
{
  signed_fuzzy_t return_val;
  return_val = (signed_fuzzy_t)0;

  if(nr==(uint8)1)
  {
    return_val = var->x1+(((scale*(var->x2-var->x1)))/(signed_fuzzy_t)FUZZY_SCALE1);
  }
  else
  {
    if(nr==(uint8)2)
    {
      return_val = var->x4-(((scale*(var->x4-var->x3)))/(signed_fuzzy_t)FUZZY_SCALE1);
    }
    else 
    {
      /*nr not in range - return 0*/
    }
  }

  return return_val;
}

/*************************************************************************************************************************
  Functionname:    FUZZY_GET_AREA                                                                                   */ /*!

  @brief           calculates the area of a curve cutted by "scale"

  @description     calculates the area of a curve cutted by "scale"

                    @startuml
                    Start
                    Partition FUZZY_GET_AREA {
                      : Read the fuzzy number (x1,x2,x3,x4), scaling factor and center of area of the curve;
                      : Limit the scaling factor in between -1 & 1;
                      If (**Is the scaling factor equal to zero ? **) then (Yes)
                          :  Area of curve is 0;
                      Else (No)
                          : Area of curve is calculated using center of area;
                      Endif
                    }
                    Stop
                    @enduml

  @return          static signed_fuzzy_t                      [full range of sint32]

  @param[in]       *var :   pointer to a fuzzy variable       [fuzzy_var_t defined in cal_fuzzy_ext.h]
  @param[in]       scale :  scale upper bound of the area     [full range of sint32]
  @param[in,out]   *mid :   center of area                    [full range of sint32]

  @glob_in         Fuzzy_ValMin     [full range of sint32]
  @glob_in         Fuzzy_ValMax     [full range of sint32]
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full    FCT_CFG_LOPC_COMPONENT  : Configuration switch for enabling FCT_LONG processing

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-519-0009fc80">CAL_519</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
static signed_fuzzy_t FUZZY_GET_AREA(const fuzzy_var_t *var,signed_fuzzy_t scale,signed_fuzzy_t *mid)
{
  signed_fuzzy_t return_val;

  scale = MAT_LIM(scale, (sint32)-FUZZY_SCALE1, (sint32)FUZZY_SCALE1);

  if(scale==(signed_fuzzy_t)0)
  {
    return_val = (signed_fuzzy_t)0; 
  }
  else
  {
    if(scale>(signed_fuzzy_t)0)
    {
      return_val = FUZZY_GET_AREA_POS(var,scale,mid);
    }
    else
    {
      /*A "NOT" OUTPUT (scale < 0)*/
#if (0) /*no NOT OUTPUT rule allowed!!!*/
      signed_fuzzy_t x1,x2,x3;
      signed_fuzzy_t a1,a2,a3;
      signed_fuzzy_t sum;
      signed_fuzzy_t tx1,tx2,ta1,ta2;

      scale=-scale; /*make scale positive*/

      ta1=FUZZY_GET_AREA_POS(var,(signed_fuzzy_t)FUZZY_SCALE1,&tx1);       /*get the whole area*/
      ta2=FUZZY_GET_AREA_POS(var,(signed_fuzzy_t)FUZZY_SCALE1-scale,&tx2); /*get the area of the cuttet var*/

      a2=ta1-ta2; /*target area is the difference of the both*/
      if(a2 != (signed_fuzzy_t)0)
      {
        x2=((ta1*tx1)-(tx2*ta2))/a2;
      }
      else
      {
        x2=tx1;
      }

      x1=(Fuzzy_ValMin+var->x1)/(signed_fuzzy_t)2;
      a1=((var->x1-Fuzzy_ValMin)/(signed_fuzzy_t)FUZZY_SCALE1)*scale;

      x3=(Fuzzy_ValMax+var->x4)/(signed_fuzzy_t)2;
      a3=((Fuzzy_ValMax-var->x4)/(signed_fuzzy_t)FUZZY_SCALE1)*scale;

      a2=(((var->x4-var->x1)/(signed_fuzzy_t)FUZZY_SCALE1)*scale)-a2;

      sum=(a1+a2+a3);
      if(sum==(signed_fuzzy_t)0)
      {
        *mid=(signed_fuzzy_t)0;
      }
      else
      {
        *mid=(a1*x1)+(a2*x2)+(a3*x3);
        *mid/=sum;
      }
#endif /* (0) */
      return_val = 0;
    }
  }

  return return_val;
}

/*************************************************************************************************************************
  Functionname:    FUZZY_GET_AREA_POS                                                                               */ /*!

  @brief           same as FUZZY_GET_AREA but scale is to be positive

  @description     same as FUZZY_GET_AREA but scale is to be positive

                    @startuml
                    Start
                    Partition FUZZY_GET_AREA_POS {
                      : Read the fuzzy number (x1,x2,x3,x4) of trapezium, scaling factor and center of area of the curve;
                      : Calculate the first and second cut value xc1 and xc2 ;
                      : The trapezium can be considered as sum of two right triangles and rectangle;
                      : The centroid of the right triangle is at a distance of 2/3 rd of the base length;
                      : The centroid of the rectangle is at the middle of the rectangle;
                      : Calculate the area of the two right-angle triangles a1,a2 and rectangle a3;
                      : Calculate the total area as the sum of the area of two triangles and rectangle;
                      If (**Is sum of area equal to zero ?**) then (Yes)
                          : Center of area is 0;
                      Else (No)
                          : Center of area is the weighted centroid given by sum of the product of area \n  
                      and centroid by the total area;
                      : Calculate the first and second cut-off value of the triangles;
                      : Reduce the area of two triangles and the rectangle for smoother edges;
                      : Raduce the total area as the sum of the area of triangles and the rectangle for smoother edges;
                      Endif
                    }
                    Stop
                    @enduml

  @return          static signed_fuzzy_t area                 [full range of sint32]

  @param[in]       *var :   pointer to a fuzzy variable       [fuzzy_var_t defined in cal_fuzzy_ext.h]
  @param[in]       scale :  scale upper bound of the area     [full range of sint32]
  @param[in,out]   *mid :   center of area                    [full range of sint32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full    FCT_CFG_LOPC_COMPONENT  : Configuration switch for enabling FCT_LONG processing

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-520-0009fc80">CAL_520</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
static signed_fuzzy_t FUZZY_GET_AREA_POS(const fuzzy_var_t *var,signed_fuzzy_t scale,signed_fuzzy_t *mid)
{
  signed_fuzzy_t return_val;
  signed_fuzzy_t xc1,xc2;
  signed_fuzzy_t a1,a2,a3;
  signed_fuzzy_t xm1,xm2,xm3;
  signed_fuzzy_t sum;

  xc1=FUZZY_GET_CUT_VALUE(var,scale,(uint8)1); /*find first  x value where the linguistic variable cuts the scale line*/
  xc2=FUZZY_GET_CUT_VALUE(var,scale,(uint8)2); /*find second x value where the linguistic variable cuts the scale line*/

  xm1=((xc1-var->x1)*(signed_fuzzy_t)2)/(signed_fuzzy_t)3;  /*centroid of the left triangle part*/
  xm2=(xc2-xc1)/(signed_fuzzy_t)2;        /*centroid of the middle rectangle part*/
  xm3=(var->x4-xc2)/(signed_fuzzy_t)3;    /*centroid of the right triangle part*/

  a1=((xc1-var->x1)*scale)/(signed_fuzzy_t)FUZZY_SCALE1; /*area of the left triangle part*/
  a2=(((xc2-xc1)*scale)*(signed_fuzzy_t)2)/(signed_fuzzy_t)FUZZY_SCALE1;     /*area of the middle rectangle part, update due to MISRA*/
  a3=((var->x4-xc2)*scale)/(signed_fuzzy_t)FUZZY_SCALE1; /*area of the right triangle part*/

  sum = (a1+a2+a3);

  if(sum==(signed_fuzzy_t)0)
  {
    *mid=(signed_fuzzy_t)0;
  }
  else
  {
    *mid=(((var->x1+xm1)*a1)+((xc1+xm2)*a2)+((xc2+xm3)*a3))/sum; /*calculate weighted centroid*/
  }

  /*reduce the area for smoother edges in sum (take upper part from the shape instead of the lower (bigger) part*/

  xc1 = FUZZY_GET_CUT_VALUE(var,(signed_fuzzy_t)FUZZY_SCALE1 - scale,(uint8)1); 
  xc2 = FUZZY_GET_CUT_VALUE(var,(signed_fuzzy_t)FUZZY_SCALE1 - scale,(uint8)2); 

  a1 = ((var->x2 - xc1)         * scale )/ (signed_fuzzy_t)FUZZY_SCALE1;
  a2 = (((var->x3 - var->x2) * (signed_fuzzy_t)2 ) * scale) / (signed_fuzzy_t)FUZZY_SCALE1;  
  a3 = ((xc2 - var->x3)         * scale ) / (signed_fuzzy_t)FUZZY_SCALE1;

  sum = a1+a2+a3;
  /*end reduce the area for smoother edges in sum*/

  return_val = sum;

  return return_val;
}

/*************************************************************************************************************************
  Functionname:    FUZZY_DEFUZZY                                                                                    */ /*!

  @brief           defuzzification of the stock with Center of Sum Method

  @description     defuzzification of the stock with Center of Sum Method

                    @startuml
                    Start
                    Partition FUZZY_DEFUZZY {
                      : Read the fuzzification of the area and the center of the area as inputs;
                      If (**If Fuzzification of area is non-zero ?**) then (Yes)
                          : Crisp value is calculated using Center of sum defuzzification method. 
                          This is given by the sum of the center of the area by the total area;
                      Else (No)
                          : Crisp value is 0;
                      endif
                    }
                    Stop
                    @enduml

  @return          signed_fuzzy_t result of defuzzification  [full range of sint32]

  @param[in]       void

  @glob_in          FuzzyArea     [full range of sint32]
  @glob_in          FuzzyAreaPos  [full range of sint32]
  @glob_out         No global output variables used

  @c_switch_part   -
  @c_switch_full    FCT_CFG_LOPC_COMPONENT  : Configuration switch for enabling FCT_LONG processing

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-521-0009fc80">CAL_521</a> \n

  @created         -
  @changed         3/4/2016

*************************************************************************************************************************/
signed_fuzzy_t FUZZY_DEFUZZY(void)
{
  signed_fuzzy_t return_val;

  return_val = 0;
  
  if(FuzzyArea != (signed_fuzzy_t)0)
  {
    return_val = FuzzyAreaPos/FuzzyArea;
  }
  else
  {
    /*not valid - return 0*/
  }

  return return_val;
}
#endif  /* (FCT_CFG_ACC_CAL) */

