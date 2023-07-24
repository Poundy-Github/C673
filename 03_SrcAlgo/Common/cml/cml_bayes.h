/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 algo_mat_bayes.h

  DESCRIPTION:               Bayes network computation

  AUTHOR:                    Philippe Dintzer

  CREATION DATE:             08.03.2010

  VERSION:                   $Revision: 1.9 $

  ---*/ /*---
  CHANGES:                   $Log: cml_bayes.h  $
  CHANGES:                   Revision 1.9 2017/11/13 06:20:49CET Kotre, Jeevan (uidk9586) (uidk9586) 
  CHANGES:                   Updated cml_bayes module functions with coding standard naming convention.
  CHANGES:                   Revision 1.8 2017/10/13 09:50:38CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the function header comment format
  CHANGES:                   Revision 1.7 2017/09/27 05:58:40CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Merged from branch with Detailed Design
  CHANGES:                   Revision 1.6 2017/08/07 07:02:26CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the design documentation
  CHANGES:                   Revision 1.5 2014/04/07 10:27:59CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed erroneous include protection
  CHANGES:                   - Added comments -  uidg6516 [Apr 7, 2014 10:27:59 AM CEST]
  CHANGES:                   Change Package : 227281:3 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.4 2014/03/27 11:18:54CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed some QA-C- and Styleguide-issues
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 27, 2014 11:18:54 AM CET]
  CHANGES:                   Change Package : 227281:2 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.3 2014/02/04 15:08:51CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - improve code quality
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 4, 2014 3:08:52 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2012/09/20 13:29:44CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:44 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:01CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/**
@defgroup bayes BAYES (Bayes Network Library)
  @ingroup cml
@{ */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef _CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_bayes.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef _CML_EXT_INCLUDED */

#ifndef _CML_BAYES_INCLUDED
#define _CML_BAYES_INCLUDED


/*****************************************************************************
  DEFINES
*****************************************************************************/
#define CML_BAYES2_CPT_SIZE (4)   ///< Size of conditional probability table for 2 events 
#define CML_BAYES3_CPT_SIZE (8)   ///< Size of conditional probability table for 3 events 
#define CML_BAYES4_CPT_SIZE (16)  ///< Size of conditional probability table for 4 events 
#define CML_BAYES5_CPT_SIZE (32)  ///< Size of conditional probability table for 5 events 


/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/
/*****************************************************************************
  Functionname:       CML_u_bayes2                                        *//*!
  
  \brief           Calculates the probability P(C) given conditional and 
                    marginal probabilities of two events.

  \details         Calculates the probability P(C) given the conditional probabilities
                   P(C | not_A, not_B), P(C | A, not_B), P(C | not_A, B), P(C | A, B)
                   and the marginal probabilities P(A) and P(B) by the formula of total
                   probability. The events A and B are assumed to be independent.

  \param[in]       u_ProbabilityA :  Probability of event A = P(A)
                                     Range is [0 ... 100]
  \param[in]       u_ProbabilityB :  Probability of event B = P(B)
                                     Range is [0 ... 100]
  \param[in]       a_CPT :  conditional probability table  for C --> \n  
                           | A | B |  C |\n
                           | --|---|----|\n
                           | F | F |  v0|\n
                           | T | F |  v1|\n
                           | F | T |  v2|\n
                           | T | T |  v3|\n
                   as a linear vector [v0, v1, v2, v3] 
                   Range is [0 ... 100] for each value.
  \InOutCorrelation
                   \f[ Probability = ((A' \times B' \times C[0]) +  \\
                                      (A  \times B' \times C[1]) +  \\
                                      (A' \times B  \times C[2]) +  \\
                                      (A  \times B  \times C[3]))
                   \f]

  \return          the probability P(C)

  \author          Robert Thiel, Daniel Meschenmoser

  \testmethod
  \traceability   
*****************************************************************************/
extern percentage_t CML_u_bayes2(percentage_t u_ProbabilityA,
                               percentage_t u_ProbabilityB,
                               const percentage_t a_CPT[CML_BAYES2_CPT_SIZE]);

/*****************************************************************************
  Functionname:    CML_u_bayes3                                           *//*!

  \brief           Calculates the probability P(D) given conditional and marginal
                   probabilities of three mutually independent events.

  \description     Calculates the probability P(D) given the conditional probabilities
                   P(D | not_A, not_B, C), etc. and the marginal probabilities P(A),
                   P(B), and P(C) by the formula of total probability. The events A, B,
                   and C are assumed to be mutually independent.

  \param[in]       u_ProbabilityA :  Probability of event A = P(A)
                                     Range is [0 ... 100]
  \param[in]       u_ProbabilityB :  Probability of event B = P(B)
                                     Range is [0 ... 100]
  \param[in]       u_ProbabilityC :  Probability of event C = P(C)
                                     Range is [0 ... 100]
  \param[in]       a_CPT :  conditional probability table  for D -->\n
                           | A | B | C  |  D  |\n
                           | --|---|----|---- |\n
                           | F | F | F  |  v0 |\n
                           | T | F | F  |  v1 |\n
                           | F | T | F  |  v2 |\n
                           | T | T | F  |  v3 |\n
                           | F | F | T  |  v4 |\n
                           | T | F | T  |  v5 |\n
                           | F | T | T  |  v6 |\n
                           | T | T | T  |  v7 |\n
                as a linear vector [v0, v1, v2, v3, v4, v5, v6, v7] 
                Range is [0 ... 100] for each value.
  \InOutCorrelation
                   \f[ Probability = ((A' \times B' \times C' \times D[0]) +  \\
                                      (A  \times B' \times C' \times D[1]) +  \\
                                      (A' \times B  \times C' \times D[2]) +  \\
                                      (A  \times B  \times C' \times D[3]) +  \\
                                      (A' \times B' \times C  \times D[4]) +  \\
                                      (A  \times B' \times C  \times D[5]) +  \\
                                      (A' \times B  \times C  \times D[6]) +  \\
                                      (A  \times B  \times C  \times D[7]))
                   \f]

  \return       the probability P(D)

  \author       Robert Thiel, Daniel Meschenmoser

  \testmethod
  \traceability   
*********************************************************************************************************/
extern percentage_t CML_u_bayes3(percentage_t u_ProbabilityA,
                               percentage_t u_ProbabilityB,
                               percentage_t u_ProbabilityC,
                               const percentage_t a_CPT[CML_BAYES3_CPT_SIZE]);

/*****************************************************************************
  Functionname:    CML_u_bayes4                                           *//*! 

  \brief           Calculates the probability P(E) given conditional and marginal
                   probabilities of four mutually independent events.

  \description     Calculates the probability P(E) given the conditional probabilities
                   P(D | not_A, not_B, C, D), etc. and the marginal probabilities P(A),
                   P(B), P(C), and P(D) by the formula of total probability. The events
                   A, B, C, and D are assumed to be mutually independent.

  \param[in]       u_ProbabilityA :  Probability of event A = P(A)
                                     Range is [0 ... 100]
  \param[in]       u_ProbabilityB :  Probability of event B = P(B)
                                     Range is [0 ... 100]
  \param[in]       u_ProbabilityC :  Probability of event C = P(C)
                                     Range is [0 ... 100]
  \param[in]       u_ProbabilityD :  Probability of event D = P(D)
                                     Range is [0 ... 100]
  \param[in]       a_CPT :  conditional probability table  for E --> \n
                           | A | B | C | D  |  E   |\n
                           | --|---|---|----|------|\n
                           | F | F | F | F  |  v0  |\n
                           | T | F | F | F  |  v1  |\n
                           | F | T | F | F  |  v2  |\n
                           | T | T | F | F  |  v3  |\n
                           | F | F | T | F  |  v4  |\n
                           | T | F | T | F  |  v5  |\n
                           | F | T | T | F  |  v6  |\n
                           | T | T | T | F  |  v7  |\n
                           | F | F | F | T  |  v8  |\n
                           | T | F | F | T  |  v9  |\n
                           | F | T | F | T  |  v10 |\n
                           | T | T | F | T  |  v11 |\n
                           | F | F | T | T  |  v12 |\n
                           | T | F | T | T  |  v13 |\n
                           | F | T | T | T  |  v14 |\n
                           | T | T | T | T  |  v15 |\n
                   as a linear vector [v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15] 
                   Range is [0 ... 100] for each value.
  \InOutCorrelation
                   \f[ Probability = ((A' \times B' \times C' \times D' \times E[0]) +  \\
                                      (A  \times B' \times C' \times D' \times E[1]) +  \\
                                      (A' \times B  \times C' \times D' \times E[2]) +  \\
                                      (A  \times B  \times C' \times D' \times E[3]) +  \\
                                      (A' \times B' \times C  \times D' \times E[4]) +  \\
                                      (A  \times B' \times C  \times D' \times E[5]) +  \\
                                      (A' \times B  \times C  \times D' \times E[6]) +  \\
                                      (A  \times B  \times C  \times D' \times E[7]) +  \\
                                      (A' \times B' \times C' \times D  \times E[8]) +  \\
                                      (A  \times B' \times C' \times D  \times E[9]) +  \\
                                      (A' \times B  \times C' \times D  \times E[10]) + \\ 
                                      (A  \times B  \times C' \times D  \times E[11]) + \\
                                      (A' \times B' \times C  \times D  \times E[12]) + \\ 
                                      (A  \times B' \times C  \times D  \times E[13]) + \\ 
                                      (A' \times B  \times C  \times D  \times E[14]) + \\ 
                                      (A  \times B  \times C  \times D  \times E[15]))
                   \f]

  \return          the probability P(E)

  \author          Robert Thiel, Daniel Meschenmoser

  \testmethod
  \traceability   
*********************************************************************************************************/
extern percentage_t CML_u_bayes4(percentage_t u_ProbabilityA, 
                               percentage_t u_ProbabilityB,
                               percentage_t u_ProbabilityC,
                               percentage_t u_ProbabilityD,
                               const percentage_t a_CPT[CML_BAYES4_CPT_SIZE]);


/*****************************************************************************
  Functionname:    CML_u_bayes5                                           *//*!

  \brief           Calculates the probability P(F) given conditional and marginal
                   probabilities of five mutually independent events.

  \description     Calculates the probability P(F) given the conditional probabilities
                   P(D | not_A, not_B, C, D, not_E), etc. and the marginal probabilities P(A),
                   P(B), P(C), P(D), and P(E) by the formula of total probability. The events
                   A, B, C, D, and E are assumed to be mutually independent.

  \param[in]       u_ProbabilityA :  Probability of event A = P(A)
                                     Range is [0 ... 100]
  \param[in]       u_ProbabilityB :  Probability of event B = P(B)
                                     Range is [0 ... 100]
  \param[in]       u_ProbabilityC :  Probability of event C = P(C)
                                     Range is [0 ... 100]
  \param[in]       u_ProbabilityD :  Probability of event D = P(D)
                                     Range is [0 ... 100]
  \param[in]       u_ProbabilityE :  Probability of event E = P(E)
                                     Range is [0 ... 100]
  \param[in]       a_CPT :  conditional probability table  for F --> \n
                           | A | B | C | D | E | F   |\n
                           | --|---|---|---|---|-----|\n
                           | F | F | F | F | F | v0  |\n
                           | T | F | F | F | F | v1  |\n
                           | F | T | F | F | F | v2  |\n
                           | T | T | F | F | F | v3  |\n
                           | F | F | T | F | F | v4  |\n
                           | T | F | T | F | F | v5  |\n
                           | F | T | T | F | F | v6  |\n
                           | T | T | T | F | F | v7  |\n
                           | F | F | F | T | F | v8  |\n
                           | T | F | F | T | F | v9  |\n
                           | F | T | F | T | F | v10 |\n
                           | T | T | F | T | F | v11 |\n
                           | F | F | T | T | F | v12 |\n
                           | T | F | T | T | F | v13 |\n
                           | F | T | T | T | F | v14 |\n
                           | T | T | T | T | F | v15 |\n
                           | F | F | F | F | T | v16 |\n
                           | T | F | F | F | T | v17 |\n
                           | F | T | F | F | T | v18 |\n
                           | T | T | F | F | T | v19 |\n
                           | F | F | T | F | T | v20 |\n
                           | T | F | T | F | T | v21 |\n
                           | F | T | T | F | T | v22 |\n
                           | T | T | T | F | T | v23 |\n
                           | F | F | F | T | T | v24 |\n
                           | T | F | F | T | T | v25 |\n
                           | F | T | F | T | T | v26 |\n
                           | T | T | F | T | T | v27 |\n
                           | F | F | T | T | T | v28 |\n
                           | T | F | T | T | T | v29 |\n
                           | F | T | T | T | T | v30 |\n
                           | T | T | T | T | T | v31 |\n

                   as a linear vector [v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31] 
                   Range is [0 ... 100] for each value.
  \InOutCorrelation
                   \f[ Probability = ((A' \times B' \times C' \times D' \times E' \times F[0]) +  \\
                                      (A  \times B' \times C' \times D' \times E' \times F[1]) +  \\
                                      (A' \times B  \times C' \times D' \times E' \times F[2]) +  \\
                                      (A  \times B  \times C' \times D' \times E' \times F[3]) +  \\
                                      (A' \times B' \times C  \times D' \times E' \times F[4]) +  \\
                                      (A  \times B' \times C  \times D' \times E' \times F[5]) +  \\
                                      (A' \times B  \times C  \times D' \times E' \times F[6]) +  \\
                                      (A  \times B  \times C  \times D' \times E' \times F[7]) +  \\
                                      (A' \times B' \times C' \times D  \times E' \times F[8]) +  \\
                                      (A  \times B' \times C' \times D  \times E' \times F[9]) +  \\
                                      (A' \times B  \times C' \times D  \times E' \times F[10]) + \\ 
                                      (A  \times B  \times C' \times D  \times E' \times F[11]) + \\
                                      (A' \times B' \times C  \times D  \times E' \times F[12]) + \\ 
                                      (A  \times B' \times C  \times D  \times E' \times F[13]) + \\ 
                                      (A' \times B  \times C  \times D  \times E' \times F[14]) + \\ 
                                      (A  \times B  \times C  \times D  \times E' \times F[15]) + \\
                                      (A' \times B' \times C' \times D' \times E  \times F[16]) + \\ 
                                      (A  \times B' \times C' \times D' \times E  \times F[17]) + \\ 
                                      (A' \times B  \times C' \times D' \times E  \times F[18]) + \\ 
                                      (A  \times B  \times C' \times D' \times E  \times F[19]) + \\
                                      (A' \times B' \times C  \times D' \times E  \times F[20]) + \\ 
                                      (A  \times B' \times C  \times D' \times E  \times F[21]) + \\ 
                                      (A' \times B  \times C  \times D' \times E  \times F[22]) + \\ 
                                      (A  \times B  \times C  \times D' \times E  \times F[23]) + \\
                                      (A' \times B' \times C' \times D  \times E  \times F[24]) + \\ 
                                      (A  \times B' \times C' \times D  \times E  \times F[25]) + \\ 
                                      (A' \times B  \times C' \times D  \times E  \times F[26]) + \\ 
                                      (A  \times B  \times C' \times D  \times E  \times F[27]) + \\
                                      (A' \times B' \times C  \times D  \times E  \times F[28]) + \\ 
                                      (A  \times B' \times C  \times D  \times E  \times F[29]) + \\ 
                                      (A' \times B  \times C  \times D  \times E  \times F[30]) + \\ 
                                      (A  \times B  \times C  \times D  \times E  \times F[31]))
                   \f]

  \return          the probability P(F)

  \author          Philippe Dintzer, Daniel Meschenmoser

  \testmethod
  \traceability   
*********************************************************************************************************/
extern percentage_t CML_u_bayes5(percentage_t u_ProbabilityA, 
                               percentage_t u_ProbabilityB, 
                               percentage_t u_ProbabilityC, 
                               percentage_t u_ProbabilityD, 
                               percentage_t u_ProbabilityE, 
                               const percentage_t a_CPT[CML_BAYES5_CPT_SIZE]);

#endif /* #ifndef _CML_BAYES_INCLUDED */

/** @} end defgroup */
