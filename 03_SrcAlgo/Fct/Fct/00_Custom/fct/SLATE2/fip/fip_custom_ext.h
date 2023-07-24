/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

PACKAGENAME:               fip_custom_ext.h

DESCRIPTION:               External Header File for Custom specific information in ACC FCT Input Preprocessing (FIP) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             27.07.2016

VERSION:                   $Revision: 1.15 $

LEGACY VERSION:            Revision: 1.8

**************************************************************************** */

#ifndef FIP_CUSTOM_EXT_H_INCLUDED
#define FIP_CUSTOM_EXT_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fip_ver.h"
#include "fip_cfg.h"
#include "slate_ext.h"
/* nothing should be included in this file */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup fip_customfunctions
@{ */

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/

/*! FCT support for TJA specific Object Trace Preprocessing, If it is possible to move it to FIP Config then Change the name to FIP_ */
/* Currently TJA Object traces only work with EM Object traces */
#define FCT_CFG_TJA_OBJECT_TRACE                  FCT_CFG_DEPENDENT_SWITCH(((FCT_CFG_OBJECT_TRACE_PREPROCESSSING) && (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES)), SWITCH_OFF)

/*--- fip_objattributes.c ---*/
/*! Configuration switch for treating stationary objects as oncoming */
#define FIP_CFG_CHECK_STAT_OBJ_WAS_ONCOMING        1
/*****************************************************************************
  MACROS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/
#if (FCT_CFG_ACC_LANE_ASSOCIATION == SWITCH_OFF)
#define FIP_PICK_UP_RANGE_DEFAULT_TIMEGAP (4.f)
#define FIP_PICK_UP_RANGE_DEFAULT_MIN     (80.f)
#endif  /* (FCT_CFG_ACC_LANE_ASSOCIATION == SWITCH_OFF) */

/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  CONSTANTS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/


/* End of conditional inclusion */
///@}
#endif  /*!< _FIP_CUSTOM_EXT_H_INCLUDED */
