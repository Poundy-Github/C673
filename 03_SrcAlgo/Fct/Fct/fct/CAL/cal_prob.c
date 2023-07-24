/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_prob.c

DESCRIPTION:               All needed probability functions

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 1.10.1.1


**************************************************************************** */
#include "cal_int.h"/* PRQA S 0380
date: 28/06/2019 author: Pruthvi Reason: Can be ignored as no functional impact */

#if (FCT_CFG_ACC_CAL)
#if (0) /* Disabling unused functions */
/*************************************************************************************************************************
  Functionname:    MAT_PROB_BAYES2                                                                                  */ /*!

  @brief           calculation of P(C|A,B) with given CPT and P(A) and P(B)
                   this function also handles out of range inputs

  @description     calculation of P(C|A,B) with given CPT and P(A) and P(B)
                   this function also handles out of range inputs

                   @startuml
                   Start
                   Partition MAT_PROB_BAYES2 {

                   : Limit the maximum probability of A and B to 1;
                   : Calculate conditional probability of C as product of the probabilities of A and B \n and respective conditional probability table values;
                   : Calculate the total probability as the sum of the conditional probabilities of C;
                   : The total probability is then scaled to handle out of range values;
                   }
                   Stop
                   @enduml

  @return          percentage_t P(C|A,B)                                            [0         100]

  @param[in]       ProbabilityA : P(A)                                              [0         100]
  @param[in]       ProbabilityB : P(B)                                              [0         100]
  @param[in]       CPT : CPT conditional probability table  for C    
                         A | B  | C
                         --|----|---
                         F | F  | v0
                         T | F  | v1
                         F | T  | v2
                         T | T  | v3
                         as a linear vector [v0, v1, v2, v3]         [0         100]

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

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-528-0009fc80">CAL_528</a> \n

  @created         -
  @changed         3/7/2016

*************************************************************************************************************************/
percentage_t MAT_PROB_BAYES2(percentage_t ProbabilityA, percentage_t ProbabilityB, const percentage_t CPT[4])
{
  uint32 temp;
  uint32 p2;

  /*range check*/
  if(ProbabilityA > (percentage_t) Percentage_max)
  {
    ProbabilityA = (percentage_t) Percentage_max;
  }
  if(ProbabilityB > (percentage_t) Percentage_max)
  {
    ProbabilityB = (percentage_t) Percentage_max;
  }
  
  /*calculate probability*/
  temp = ((uint32) Percentage_max - ProbabilityA) * ((uint32) Percentage_max - ProbabilityB) * (uint32)CPT[0];
  temp+= ((uint32)                  ProbabilityA) * ((uint32) Percentage_max - ProbabilityB) * (uint32)CPT[1];
  temp+= ((uint32) Percentage_max - ProbabilityA) * ((uint32)                  ProbabilityB) * (uint32)CPT[2];
  temp+= ((uint32)                  ProbabilityA) * ((uint32)                  ProbabilityB) * (uint32)CPT[3];

  /*fixed point scaling*/
  p2 = (uint32)Percentage_max*(uint32)Percentage_max;
  temp+= p2/(uint32) 2;
  temp/= p2;
  if(temp > (uint32)Percentage_max)
  {
    temp = (uint32)Percentage_max;
  }

  return (percentage_t)temp;
}

/*************************************************************************************************************************
  Functionname:    MAT_PROB_BAYES3                                                                                  */ /*!

  @brief           calculation of P(D|A,B,C) with given CPT and P(A) and P(B) and P(C)
                   this function also handles out of range inputs

  @description     calculation of P(D|A,B,C) with given CPT and P(A) and P(B) and P(C)
                   this function also handles out of range inputs

                   @startuml
                   Start
                   Partition MAT_PROB_BAYES3 {

                   : Limit the maximum probability of C to 1;
                   : Calculate conditional probability of D as product of conditional probability of C \n using MAT_PROB_BAYES2 and \n the probability of C; 
                   : The total probability is then scaled to handle out of range values;

                   }
                   Stop
                   @enduml

  @return          percentage_t P(D|A,B,C)                                              [0         100]

  @param[in]       ProbabilityA : P(A)                                                  [0         100]
  @param[in]       ProbabilityB : P(B)                                                  [0         100]
  @param[in]       ProbabilityC : P(C)                                                  [0         100]
  @param[in]       CPT          : conditional probability table  for D
                                  A | B | C | D
                                  --|---|---|----
                                  F | F | F | v0
                                  T | F | F | v1
                                  F | T | F | v2
                                  T | T | F | v3
                                  F | F | T | v4
                                  T | F | T | v5
                                  F | T | T | v6
                                  T | T | T | v7
                    as a linear vector [v0, v1, v2, v3, v4, v5, v6, v7]                  [0         100]

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

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-528-0009fc80">CAL_528</a> \n

  @created         -
  @changed         3/7/2016

*************************************************************************************************************************/
percentage_t MAT_PROB_BAYES3(percentage_t ProbabilityA, percentage_t ProbabilityB, percentage_t ProbabilityC, const percentage_t CPT[8])
{
  uint32 temp;

  /*range check*/
  if(ProbabilityC > (percentage_t) Percentage_max)
  {
    ProbabilityC = (percentage_t) Percentage_max;
  }

  /*calculate probability using MAT_PROB_BAYES2*/
  temp = (uint32)MAT_PROB_BAYES2(ProbabilityA, ProbabilityB, CPT    ) * ( (uint32)Percentage_max - ProbabilityC); /*C=FALSE*/
  temp+= (uint32)MAT_PROB_BAYES2(ProbabilityA, ProbabilityB, &CPT[4]) * ( (uint32)                 ProbabilityC); /*C=TRUE*/

  /*fixed point scaling*/
  temp = (temp + ((uint32) Percentage_max / (uint32)  2)) / (uint32) Percentage_max;
  if(temp > (uint32) Percentage_max)
  {
    temp = (uint32) Percentage_max;
  }

  return (percentage_t)temp;
}

/*************************************************************************************************************************
  Functionname:    MAT_PROB_BAYES4                                                                                  */ /*!

  @brief           calculation of P(E|A,B,C,D) with given CPT and P(A) and P(B) and P(C) and P(D)
                   this function also handles out of range inputs

  @description     calculation of P(E|A,B,C,D) with given CPT and P(A) and P(B) and P(C) and P(D)
                   this function also handles out of range inputs

                   @startuml
                   Start
                   Partition MAT_PROB_BAYES4 {

                   : Limit the maximum probability of D to 1;
                   : Calculate conditional probability of E as product of \n conditional probability of D using MAT_PROB_BAYES3 and \n the probability of D; 
                   : The total probability is then scaled to handle out of range values;

                   }
                   Stop
                   @enduml

  @return          percentage_t P(E|A,B,C,D)                                                                   [0         100]

  @param[in]       ProbabilityA : P(A)                                                                         [0         100]
  @param[in]       ProbabilityB : P(B)                                                                         [0         100]
  @param[in]       ProbabilityC : P(C)                                                                         [0         100]
  @param[in]       ProbabilityD : P(D)                                                                         [0         100]
  @param[in]       CPT          : conditional probability table for E
                                  A | B | C | D | E   
                                  --|---|---|---|-----
                                  F | F | F | F | v0  
                                  T | F | F | F | v1  
                                  F | T | F | F | v2  
                                  T | T | F | F | v3  
                                  F | F | T | F | v4  
                                  T | F | T | F | v5  
                                  F | T | T | F | v6  
                                  T | T | T | F | v7  
                                  F | F | F | T | v8  
                                  T | F | F | T | v9  
                                  F | T | F | T | v10 
                                  T | T | F | T | v11 
                                  F | F | T | T | v12 
                                  T | F | T | T | v13 
                                  F | T | T | T | v14 
                                  T | T | T | T | v15 
                  as a linear vector [v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15]       [0         100]

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

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-528-0009fc80">CAL_528</a> \n

  @created         -
  @changed         3/7/2016

*************************************************************************************************************************/
percentage_t MAT_PROB_BAYES4(percentage_t ProbabilityA, percentage_t ProbabilityB, percentage_t ProbabilityC, percentage_t ProbabilityD, const percentage_t CPT[16])
{
  uint32 temp;

  /*range check*/
  if(ProbabilityD > (percentage_t) Percentage_max)
  {
    ProbabilityD = (percentage_t) Percentage_max;
  }

  /*calculate probability using MAT_PROB_BAYES3*/
  temp = (uint32)MAT_PROB_BAYES3(ProbabilityA, ProbabilityB, ProbabilityC, CPT    ) * ((uint32) Percentage_max - ProbabilityD); /*D=FALSE*/
  temp+= (uint32)MAT_PROB_BAYES3(ProbabilityA, ProbabilityB, ProbabilityC, &CPT[8]) * ((uint32)                  ProbabilityD); /*D=TRUE*/

  /*fixed point scaling*/
  temp = (temp + ((uint32) Percentage_max / (uint32)  2)) / (uint32) Percentage_max;
  if(temp > (uint32) Percentage_max)
  {
    temp = (uint32) Percentage_max;
  }

  return (percentage_t)temp;
}
#endif /* (0) Unused functions */
#endif /* (FCT_CFG_ACC_CAL) */

