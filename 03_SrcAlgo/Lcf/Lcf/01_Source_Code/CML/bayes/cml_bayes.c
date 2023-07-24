/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_bayes.c

  DESCRIPTION:               Bayes network computation

  AUTHOR:                    Philippe Dintzer

  CREATION DATE:             08.03.2010

  VERSION:                   $Revision: 1.10.1.1 $

  ---*/ /*---
  CHANGES:                   $Log: cml_bayes.c  $
  CHANGES:                   Revision 1.10.1.1 2019/06/21 15:14:59CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   QAF Level3 fixes for MFC431TA19
  CHANGES:                   Revision 1.10 2018/02/26 08:48:51CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the source code with respect to AL_CML_01.09.18_INT-1
  CHANGES:                   Revision 1.9 2016/05/11 06:06:52CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.9 2016/05/11 06:06:52CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.9 2016/05/11 06:06:52CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.8 2015/10/06 12:28:39CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated function description to resolve doxygen warning
  CHANGES:                   - Added comments -  uidr5428 [Oct 6, 2015 12:28:40 PM CEST]
  CHANGES:                   Change Package : 383331:1 http://mks-psad:7002/im/viewissue?selection=383331
  CHANGES:                   Revision 1.7 2015/08/25 05:34:09CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated doxygen compliant function headers
  CHANGES:                   --- Added comments ---  uidr5428 [Aug 25, 2015 5:34:09 AM CEST]
  CHANGES:                   Change Package : 360603:1 http://mks-psad:7002/im/viewissue?selection=360603
  CHANGES:                   Revision 1.6 2014/08/20 11:31:30CEST Dintzer, Philippe (dintzerp) 
  CHANGES:                   - ecu-sil fixes for combined operators
  CHANGES:                   - use of CML_f_MultAdd( )
  CHANGES:                   --- Added comments ---  dintzerp [Aug 20, 2014 11:31:30 AM CEST]
  CHANGES:                   Change Package : 257759:1 http://mks-psad:7002/im/viewissue?selection=257759
  CHANGES:                   Revision 1.5 2014/03/27 11:22:33CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed some QA-C- and Styleguide-issues
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 27, 2014 11:22:34 AM CET]
  CHANGES:                   Change Package : 227281:2 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.4 2014/03/25 11:27:45CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed Doxygen comments
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 25, 2014 11:27:46 AM CET]
  CHANGES:                   Change Package : 227281:1 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.3 2013/05/03 09:54:36CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   - use new standard type names, e.g. float32 instead of f32_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:54:36 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2012/09/20 13:29:44CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:44 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:30:58CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

*****************************************************************************/

/* PRQA S 0380 10 */
/* Deactivate QAF warning 0380, Date: 2019-06-17; Reviewer: uid22555;  
   Reason: The warning is seen as number of macros exceeds 4095 which can not be avoided here. 
   Warning is analysed and no risk in suppressing this. */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cml_ext.h"

/*****************************************************************************
  Functionname:    CML_u_bayes2                                           */ /*!
  
  @brief           Calculates the probability P(C) given conditional and 
                   marginal probabilities of two events.

  @description     Calculates the probability P(C) given the conditional probabilities
                   P(C | not_A, not_B), P(C | A, not_B), P(C | not_A, B), P(C | A, B)
                   and the marginal probabilities P(A) and P(B) by the formula of total
                   probability. The events A and B are assumed to be independent.

  @param[in]       u_ProbabilityA :  Probability of event A = P(A)
                                     Range is [0 ... 100]
  @param[in]       u_ProbabilityB :  Probability of event B = P(B)
                                     Range is [0 ... 100]
  @param[in]       a_CPT :  conditional probability table  for C -->   
                            A  B  |  C
                            -----------
                            F  F  |  v0
                            T  F  |  v1
                            F  T  |  v2
                            T  T  |  v3
                   as a linear vector [v0, v1, v2, v3] 
                   Range is [0 ... 100] for each value.

  @return          the probability P(C)

  @author          Robert Thiel, Daniel Meschenmoser

*****************************************************************************/
percentage_t CML_u_bayes2(percentage_t u_ProbabilityA,
                        percentage_t u_ProbabilityB,
                        const percentage_t a_CPT[CML_BAYES2_CPT_SIZE])
{
  uint32 u_temp;
  uint32 u_p2;
  percentage_t u_ProbabilityNotA, u_ProbabilityNotB;

/* PRQA S 1862 10 */
/* Deactivate QAC warning 1862, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as both the operands are positive */
  /* range check: probability must not be greater than 100% */
  if(u_ProbabilityA > Percentage_max)
  {
    u_ProbabilityA = Percentage_max;
  }
  if(u_ProbabilityB > Percentage_max)
  {
    u_ProbabilityB = Percentage_max;
  }
/* PRQA S 1860 5 */
/* Deactivate QAC warning 1860, Date: 2019-06-17; Reviewer: uid22555;
   Reason:  Both the operands are positive and result is always >=0 */
  u_ProbabilityNotA = Percentage_max - u_ProbabilityA;
  u_ProbabilityNotB = Percentage_max - u_ProbabilityB;

  /* Calculate the probability P(C) by the formula of total probability. */
  /* The events A and B are assumed independent, so P(A, B) = P(A) * P(B) */
  u_temp  =   (uint32) (u_ProbabilityNotA) * (uint32) (u_ProbabilityNotB) * (uint32) a_CPT[0];
  u_temp += ( (uint32) (u_ProbabilityA   ) * (uint32) (u_ProbabilityNotB) * (uint32) a_CPT[1] );
  u_temp += ( (uint32) (u_ProbabilityNotA) * (uint32) (u_ProbabilityB   ) * (uint32) a_CPT[2] );
  u_temp += ( (uint32) (u_ProbabilityA   ) * (uint32) (u_ProbabilityB   ) * (uint32) a_CPT[3] );

  /* fixed point scaling */
  u_p2 = Percentage_max * Percentage_max;
  u_temp += ( u_p2/2u );
  u_temp /= u_p2;

/* PRQA S 1842 10 */
/* Deactivate QAC warning 1842, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as the right hand operand is positive. */
  if(u_temp > Percentage_max)
  {
    u_temp = Percentage_max;
  }

  return (percentage_t)u_temp;
}


/*****************************************************************************
  Functionname:    CML_u_bayes3                                           */ /*!

  @brief           Calculates the probability P(D) given conditional and marginal
                   probabilities of three mutually independent events.

  @description     Calculates the probability P(D) given the conditional probabilities
                   P(D | not_A, not_B, C), etc. and the marginal probabilities P(A),
                   P(B), and P(C) by the formula of total probability. The events A, B,
                   and C are assumed to be mutually independent.

  @param[in]       u_ProbabilityA :  Probability of event A = P(A)
                                     Range is [0 ... 100]
  @param[in]       u_ProbabilityB :  Probability of event B = P(B)
                                     Range is [0 ... 100]
  @param[in]       u_ProbabilityC :  Probability of event C = P(C)
                                     Range is [0 ... 100]
  @param[in]       a_CPT :  conditional probability table  for D -->
                            A  B  C  |  D
                            --------------
                            F  F  F  |  v0
                            T  F  F  |  v1
                            F  T  F  |  v2
                            T  T  F  |  v3
                            F  F  T  |  v4
                            T  F  T  |  v5
                            F  T  T  |  v6
                            T  T  T  |  v7
                as a linear vector [v0, v1, v2, v3, v4, v5, v6, v7] 
                Range is [0 ... 100] for each value.

  @return       the probability P(D)

  @author       Robert Thiel, Daniel Meschenmoser

**********************************************************************************************************/
percentage_t CML_u_bayes3(percentage_t u_ProbabilityA,
                        percentage_t u_ProbabilityB,
                        percentage_t u_ProbabilityC,
                        const percentage_t a_CPT[CML_BAYES3_CPT_SIZE])
{
  uint32 u_temp;
  percentage_t u_ProbabilityNotC;

/* PRQA S 1860 , 1862 20 */
/* Deactivate QAC warning 1860,1862, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating these rules as the result is positive */
  /* range check: probability must not be greater than 100% */
  if(u_ProbabilityC > Percentage_max)
  {
    u_ProbabilityC = Percentage_max;
  }

  u_ProbabilityNotC = Percentage_max - u_ProbabilityC;

  /* Calculate the probability P(D) by the formula of total probability. */
  /* The events A, B, and C are assumed independent, so P(A, B, C) = P(A) * P(B) * P(C) */
  u_temp  = (uint32) CML_u_bayes2(u_ProbabilityA,
                                u_ProbabilityB,
                                a_CPT) * (uint32) (u_ProbabilityNotC);
  
  u_temp += (uint32) CML_u_bayes2(u_ProbabilityA,
                                u_ProbabilityB,
                                &a_CPT[CML_BAYES2_CPT_SIZE]) * (uint32) (u_ProbabilityC);

  /* fixed point scaling */
/* PRQA S 4404 , 1842 , 1840 9 */
/* Deactivate QAC warning 4404, 1842,1840, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as further calculations need unsigned data.*/
  u_temp = (u_temp + (Percentage_max / 2u)) / Percentage_max;
  if(u_temp > Percentage_max)
  {
    u_temp = Percentage_max;
  }

  return (percentage_t)u_temp;
}
 

/*****************************************************************************
  Functionname:    CML_u_bayes4                                           */ /*!

  @brief           Calculates the probability P(E) given conditional and marginal
                   probabilities of four mutually independent events.

  @description     Calculates the probability P(E) given the conditional probabilities
                   P(D | not_A, not_B, C, D), etc. and the marginal probabilities P(A),
                   P(B), P(C), and P(D) by the formula of total probability. The events
                   A, B, C, and D are assumed to be mutually independent.

  @param[in]       u_ProbabilityA :  Probability of event A = P(A)
                                     Range is [0 ... 100]
  @param[in]       u_ProbabilityB :  Probability of event B = P(B)
                                     Range is [0 ... 100]
  @param[in]       u_ProbabilityC :  Probability of event C = P(C)
                                     Range is [0 ... 100]
  @param[in]       u_ProbabilityD :  Probability of event D = P(D)
                                     Range is [0 ... 100]
  @param[in]       a_CPT :  conditional probability table  for E --> 
                            A  B  C  D  |  E
                            -----------------
                            F  F  F  F  |  v0
                            T  F  F  F  |  v1
                            F  T  F  F  |  v2
                            T  T  F  F  |  v3
                            F  F  T  F  |  v4
                            T  F  T  F  |  v5
                            F  T  T  F  |  v6
                            T  T  T  F  |  v7
                            F  F  F  T  |  v8
                            T  F  F  T  |  v9
                            F  T  F  T  |  v10
                            T  T  F  T  |  v11
                            F  F  T  T  |  v12
                            T  F  T  T  |  v13
                            F  T  T  T  |  v14
                            T  T  T  T  |  v15
                   as a linear vector [v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15] 
                   Range is [0 ... 100] for each value.

  @return          the probability P(E)

  @author          Robert Thiel, Daniel Meschenmoser

**********************************************************************************************************/
percentage_t CML_u_bayes4(percentage_t u_ProbabilityA,
                        percentage_t u_ProbabilityB,
                        percentage_t u_ProbabilityC,
                        percentage_t u_ProbabilityD,
                        const percentage_t a_CPT[CML_BAYES4_CPT_SIZE])
{
  uint32 u_temp;
  percentage_t u_ProbabilityNotD;

/* PRQA S 1862 10 */
/* Deactivate QAC warning 1862, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule , as all the operands are positive */
  /* range check: probability must not be greater than 100% */
  if(u_ProbabilityD > Percentage_max)
  {
    u_ProbabilityD = Percentage_max;
  }
/* PRQA S 1860 10 */
/* Deactivate QAC warning 1860, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as the result is a positive value */
  u_ProbabilityNotD = Percentage_max - u_ProbabilityD;

  /* Calculate the probability P(D) by the formula of total probability. */
  /* The events A, B, C, and D are assumed independent, so P(A, B, C, D) = P(A) * P(B) * P(C) * P(D) */
  u_temp  = (uint32) CML_u_bayes3(u_ProbabilityA, 
                                u_ProbabilityB,
                                u_ProbabilityC,
                                a_CPT) * (uint32) (u_ProbabilityNotD);
  
  u_temp += (uint32) CML_u_bayes3(u_ProbabilityA,
                                u_ProbabilityB,
                                u_ProbabilityC,
                                &a_CPT[CML_BAYES3_CPT_SIZE]) * (uint32) (u_ProbabilityD);

/* PRQA S 1840 , 1842 10 */
/* Deactivate QAC warning 1840,1842, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as further calculations need unsigned data. */
  /*fixed point scaling*/
  u_temp = (u_temp + (Percentage_max / 2u)) / Percentage_max;
  if(u_temp > Percentage_max)
  {
    u_temp = Percentage_max;
  }

  return (percentage_t)u_temp;
}


/*****************************************************************************
  Functionname:    CML_u_bayes5                                           */ /*!

  @brief           Calculates the probability P(E) given conditional and marginal
                   probabilities of five mutually independent events.

  @description     Calculates the probability P(F) given the conditional probabilities
                   P(D | not_A, not_B, C, D, not_E), etc. and the marginal probabilities P(A),
                   P(B), P(C), P(D), and P(E) by the formula of total probability. The events
                   A, B, C, D, and E are assumed to be mutually independent.

  @param[in]       u_ProbabilityA :  Probability of event A = P(A)
                                     Range is [0 ... 100]
  @param[in]       u_ProbabilityB :  Probability of event B = P(B)
                                     Range is [0 ... 100]
  @param[in]       u_ProbabilityC :  Probability of event C = P(C)
                                     Range is [0 ... 100]
  @param[in]       u_ProbabilityD :  Probability of event D = P(D)
                                     Range is [0 ... 100]
  @param[in]       u_ProbabilityE :  Probability of event E = P(E)
                                     Range is [0 ... 100]
  @param[in]       a_CPT :  conditional probability table  for F -->
                            A  B  C  D  E | F
                            ------------------
                            F  F  F  F  F | v0
                            T  F  F  F  F | v1
                            F  T  F  F  F | v2
                            T  T  F  F  F | v3
                            F  F  T  F  F | v4
                            T  F  T  F  F | v5
                            F  T  T  F  F | v6
                            T  T  T  F  F | v7
                            F  F  F  T  F | v8
                            T  F  F  T  F | v9
                            F  T  F  T  F | v10
                            T  T  F  T  F | v11
                            F  F  T  T  F | v12
                            T  F  T  T  F | v13
                            F  T  T  T  F | v14
                            T  T  T  T  F | v15
                            F  F  F  F  T | v16 
                            T  F  F  F  T | v17
                            F  T  F  F  T | v18
                            T  T  F  F  T | v19
                            F  F  T  F  T | v20
                            T  F  T  F  T | v21
                            F  T  T  F  T | v22
                            T  T  T  F  T | v23
                            F  F  F  T  T | v24
                            T  F  F  T  T | v25
                            F  T  F  T  T | v26
                            T  T  F  T  T | v27
                            F  F  T  T  T | v28
                            T  F  T  T  T | v29
                            F  T  T  T  T | v30
                            T  T  T  T  T | v31

                   as a linear vector [v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31] 
                   Range is [0 ... 100] for each value.

  @return          the probability P(E)

  @author          Philippe Dintzer, Daniel Meschenmoser

**********************************************************************************************************/
percentage_t CML_u_bayes5(percentage_t u_ProbabilityA,
                        percentage_t u_ProbabilityB,
                        percentage_t u_ProbabilityC,
                        percentage_t u_ProbabilityD,
                        percentage_t u_ProbabilityE,
                        const percentage_t a_CPT[CML_BAYES5_CPT_SIZE])
{
  uint32 u_temp;
  percentage_t u_ProbabilityNotE;

/* PRQA S 4404 , 1862 6 */
/* Deactivate QAC warning 4404 , 1862, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is  no risk here as both the operands are positive. */
  /* range check: probability must not be greater than 100% */
  if(u_ProbabilityE > Percentage_max)
  {
    u_ProbabilityE = Percentage_max;
  }
/* PRQA S 1860 10 */
/* Deactivate QAC warning 1860, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as the result is a positive value.  */
  u_ProbabilityNotE = Percentage_max - u_ProbabilityE;

  /* Calculate the probability P(E) by the formula of total probability. */
  /* The events A, B, C, D, and E are assumed independent, so P(A, B, C, D, E) = P(A) * P(B) * P(C) * P(D) * P(E) */
  u_temp  = (uint32) CML_u_bayes4(u_ProbabilityA,
                                u_ProbabilityB,
                                u_ProbabilityC,
                                u_ProbabilityD,
                                a_CPT) * (uint32) (u_ProbabilityNotE);
  
  u_temp += (uint32) CML_u_bayes4(u_ProbabilityA,
                                u_ProbabilityB,
                                u_ProbabilityC,
                                u_ProbabilityD,
                                &a_CPT[CML_BAYES4_CPT_SIZE]) * (uint32) (u_ProbabilityE);

  /* fixed point scaling */
/* PRQA S 1840 , 1842 10 */
/* Deactivate QAC warning 1840,1842,  Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as further calculations needs unsigned variable */
  u_temp = (u_temp + (Percentage_max / 2u)) / Percentage_max;
  if(u_temp > Percentage_max)
  {
    u_temp = Percentage_max;
  }

  return (percentage_t)u_temp;
}
