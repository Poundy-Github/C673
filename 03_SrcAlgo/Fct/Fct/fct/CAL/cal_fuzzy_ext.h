/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_fuzzy_ext.h

DESCRIPTION:               Math Functions of all fuzzy related functions like
                           logical operations, fuzzification and defuzzification

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.7 $

LEGACY VERSION:            Revision: 1.5.1.1

**************************************************************************** */
#ifndef CAL_FUZZY_INCLUDED
#define CAL_FUZZY_INCLUDED

#include "fct_glob_ext.h"
#include "fct_types.h"

/** @defgroup fct_mat_fuzzy  CAL_FUZZY 
@brief    Function which performs fuzzyfication, defuzzyfication and logical operations
   @ingroup fct_veh

@{ */

/*! Defines the maximum amount of rules that can be set*/
#define FUZZY_MAXRULES 16

/*! Defines the scaling value for lingvars*/
#define FUZZY_SCALE1 1024

/*! Defines the scaling value for percentages*/
#define FUZZY_PERCENT 1024

/*! Defines for special values */
#define FUZZY_SMALL (-999999999L)
#define FUZZY_LARGE ( 999999999L)

/*! Standard type for fuzzy operations */
typedef sint32 signed_fuzzy_t;

/*! @brief Standard type for fuzzy variable */
typedef struct fuzzy_var {
  signed_fuzzy_t x1,x2,x3,x4;
} fuzzy_var_t;


/* FUNCTION PROTOTYPES (COMPONENT EXTERNAL) */
extern signed_fuzzy_t FUZZY_GET_FUZZY_VAL(const fuzzy_var_t *var, signed_fuzzy_t crispValue);
extern signed_fuzzy_t FUZZY_NOT(signed_fuzzy_t val);

#if (0) /* Disabling unused functions */
extern signed_fuzzy_t FUZZY_AND(signed_fuzzy_t v1,signed_fuzzy_t v2);
extern signed_fuzzy_t FUZZY_OR(signed_fuzzy_t v1,signed_fuzzy_t v2);
extern signed_fuzzy_t FUZZY_PROBOR(signed_fuzzy_t v1,signed_fuzzy_t v2);
#endif /* (0) Unused functions */

extern signed_fuzzy_t FUZZY_PROD(signed_fuzzy_t v1,signed_fuzzy_t v2);
extern void FUZZY_DEFUZZY_INIT(signed_fuzzy_t vmin, signed_fuzzy_t vmax);
extern signed_fuzzy_t FUZZY_DEFUZZY(void);
extern signed_fuzzy_t FUZZY_GET_CUT_VALUE(const fuzzy_var_t *var, signed_fuzzy_t scale,uint8           nr);
extern void FUZZY_DEFUZZY_ADD
(
   const fuzzy_var_t *var
 , signed_fuzzy_t scale
 , signed_fuzzy_t fuzzyval
#if (FCT_CFG_DEBUG_FUZZY_CONTROLLER) 
 , uint8 rule_id
 , FuzzyDebugData_t *pFuzzyDebugData
#endif /* (FCT_CFG_DEBUG_FUZZY_CONTROLLER) */
 );
#endif /* (CAL_FUZZY_INCLUDED) */
/** @} end defgroup */
