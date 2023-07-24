/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal.h

DESCRIPTION:               Functionalities for distance to curve calculations

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.5 $

LEGACY VERSION:            Revision: 2.0.1.1


**************************************************************************** */
#ifndef CAL_H_INCLUDED
#define CAL_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fct_par.h"
#include "cal_ver.h"

#include "cal_ext.h"
#include "cal_std_ext.h"
#include "cal_fuzzy_ext.h"
#include "cal_param_ext.h"
#include "cal_prob_ext.h"
#include "cal_switch_ext.h"
#include "cal_dyn_ext.h"
#include "cal_kin_ext.h"

#if (FCT_CFG_ACC_CAL)

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
#if (FCT_CFG_OBJECT_LIST_PROC)
  /*! Infinite radius returned when no real circle radius can be detected */
#define CAL_INFINITE_RADIUS    1e6f
#endif

#ifndef C_F32_EXT_DELTA
/*! Extended F32 delta testing value, needed for the gaussian elimination
calculation for zero division testing. Due to high range dynamics, this needs
to be significantly smaller then the default 1e-4f */
#define C_F32_EXT_DELTA    (1e-8f)
#endif

#ifdef __cplusplus
};
#endif

#endif /*!< (FCT_CFG_ACC_CAL) */
/* End of conditional inclusion */
#endif  /*!< CAL_H_INCLUDED */
