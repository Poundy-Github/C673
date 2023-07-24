/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACT/LOHP (Adaptive Cruise Control - Longitudinal Headway Planner)

PACKAGENAME:               lohp_custom_pdo_tags.c

DESCRIPTION:               This module contains custom LOHP PDO tags 

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2018

VERSION:                   $Revision: 1.3 $

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         lohp_custom_pdo   Lohp_custom_pdo
@ingroup          lohp_custom_frame
@brief            This module contains all custom tags for the PDO scan.
@{
*/

/*****************************************************************************
  INCLUDE
*****************************************************************************/
#include "frame_lohp.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT))
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
#include "hp_custom.h"
#endif

#ifdef __PDO__

/*****************************************************************************
  PDO TYPEDEFS
*****************************************************************************/

#if (FCT_CFG_ACC_HEADWAY_PLANNER)
#if (CFG_FCT_ACC_PARAMS_DEBUG)
typedef acc_params_t        PDO_acc_params_t;                      /*!< @VADDR:   FCT_MEAS_ID_LOHP_ACC_PARAMS
                                                                        @CYCLEID: FCT_ENV
                                                                        @VNAME:   LOHP_ACCParams */
#endif
#endif  /* FCT_CFG_ACC_HEADWAY_PLANNER */

#endif /* #ifdef __PDO__ */

/*! Dummy for the compiler.*/ /* PRQA S 3219,3450 1 */ /* Function definition is only needed to avoid empty translation unit */
static void DummyForCompiler (void) {return;}

/** @} end defgroup */

#endif  /* ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT)) */

