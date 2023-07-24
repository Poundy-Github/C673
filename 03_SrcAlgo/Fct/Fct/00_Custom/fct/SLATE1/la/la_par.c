/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_par.c

DESCRIPTION:               Parameter File for ACC Lane Association (LA) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             20.06.2016

VERSION:                   $Revision: 1.4 $

LEGACY VERSION:            Revision: 1.4

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "la.h"

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@addtogroup la_par
@{
*/
/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*--- la_acc_function_presel.c ---*/


/* --- la_laneassociation.c ---*/
#if (SLATE_CFG_LOW_SPEED_STAT_PEDESTRIAN)
const LA_t_LowSpeedStatPedesParams LALowSpeedStatPedesParams = 
{
  5.0f,
  5.0f,
  5.0f,
  0.2f,
  0.0f,
};
#endif /* (SLATE_CFG_LOW_SPEED_STAT_PEDESTRIAN) */

/*--- la_customfunctions.c ---*/

/*****************************************************************************
  VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


///@}
#endif  /*!< FCT_CFG_ACC_LANE_ASSOCIATION */
