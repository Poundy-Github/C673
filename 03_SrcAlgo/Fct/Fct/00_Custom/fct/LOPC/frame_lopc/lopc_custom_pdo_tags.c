/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               lopc_custom_pdo_tags.c

DESCRIPTION:               This module contains custom LOPC PDO tags 

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2018

VERSION:                   $Revision: 1.3 $

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         lopc_custom_pdo   Lopc_custom_pdo
@ingroup          lopc_custom_frame
@brief            This module contains all tags for the PDO scan.
@{
*/

/*****************************************************************************
  INCLUDE
*****************************************************************************/
#include "frame_lopc.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT))
#if (LOPC_CFG_KMC)
#include "kmc_custom.h"
#endif

#ifdef __PDO__

/*****************************************************************************
  PDO TYPEDEFS
*****************************************************************************/

#if (LOPC_CFG_KMC)

#if (FCT_CFG_CC)
typedef kmc_static_mem_u_t          PDO_kmc_static_mem_u_t;        /*!< @VADDR:   FCT_MEAS_ID_LOPC_KMC_STATIC_MEM
                                                                        @CYCLEID: FCT_VEH
                                                                        @VNAME:   LOPC_KMCData */
#endif  /* FCT_CFG_CC */

#endif  /* LOPC_CFG_KMC */

#endif /* #ifdef __PDO__ */

/*! Dummy for the compiler.*/ /* PRQA S 3219,3450 1 */ /* Function definition is only needed to avoid empty translation unit */
static void DummyForCompiler (void) {return;}

#endif  /* ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT)) */

/** @} end defgroup */
