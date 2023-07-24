/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_param_ext.h

DESCRIPTION:               All functions for getting a value from a param table

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 1.6.1.1

**************************************************************************** */
#ifndef CAL_PARAM_INCLUDED
#define CAL_PARAM_INCLUDED

#include "fct_glob_ext.h"
#include "fct_types.h"

/** @defgroup fct_mat_param CAL_PARAM
@brief              Function used to access one or more dimensional calibration tables
   @ingroup fct_veh

@{ */

/* This file assumes that global types are already known, that is: #include "fct_glob_ext.h" has been done */

/* FUNCTION PROTOTYPES (COMPONENT EXTERNAL) */
extern sint16 MAT_CALCULATE_PARAM_VALUE1D (const sint16 table[], const uint16 num, const sint16 x);

#if (FCT_CFG_LOHP_COMPONENT)
extern sint16 MAT_CALCULATE_PARAM_VALUE2D (const sint16 table[], const uint16 numx, const uint16 numy, const sint32 stepx, sint32 stepy, sint32 firstx, sint32 firsty, sint32 x, sint32 y);
extern float cal_calculate_param_value_1D (const float table_x[], const float table_y[], uint16 count, float x);
extern float cal_calculate_param_gradient_1D (const float table_x[], const float table_y[], uint16 count, float x);
#endif /* (FCT_CFG_LOHP_COMPONENT) */

#endif /* (CAL_PARAM_INCLUDED) */
/** @} end defgroup */
