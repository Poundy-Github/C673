/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_prob_ext.h

DESCRIPTION:               All needed probability functions

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.6 $

LEGACY VERSION:            Revision: 1.3.1.1


**************************************************************************** */
#ifndef CAL_PROB_INCLUDED
#define CAL_PROB_INCLUDED

#include "fct_glob_ext.h"
#include "fct_types.h"


/** @defgroup fct_mat_prob CAL_PROB
@brief              Function used for calculation of conditional probabilities (Bayes theory)
   @ingroup fct_veh

@{ */
#if (0) /* Disabling unused functions */
percentage_t MAT_PROB_BAYES2(percentage_t ProbabilityA, percentage_t ProbabilityB, const percentage_t CPT[4]);
percentage_t MAT_PROB_BAYES3(percentage_t ProbabilityA, percentage_t ProbabilityB, percentage_t ProbabilityC, const percentage_t CPT[8]);
percentage_t MAT_PROB_BAYES4(percentage_t ProbabilityA, percentage_t ProbabilityB, percentage_t ProbabilityC, percentage_t ProbabilityD, const percentage_t CPT[16]);
#endif /* (0) Unused functions */
#endif /* (CAL_PROB_INCLUDED) */
/** @} end defgroup */
