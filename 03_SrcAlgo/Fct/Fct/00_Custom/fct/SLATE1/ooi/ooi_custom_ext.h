/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OOI (Object of Interest selection)

PACKAGENAME:               ooi_custom_ext.h

DESCRIPTION:               External Header File for Custom specific information in ACC Object Of Interest (OOI) selection module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             27.07.2016

VERSION:                   $Revision: 1.6 $

LEGACY VERSION:            Revision: 1.2

**************************************************************************** */

#ifndef OOI_CUSTOM_EXT_H_INCLUDED
#define OOI_CUSTOM_EXT_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "ooi_ver.h"
#include "slate_ext.h"
#include "ooi_cfg.h"

/* nothing should be included in this file */
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup ooi_customfunctions
@{ */

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  CONSTANTS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/
/*--- ooi_select_moving.c ---*/
/*! Configuration switch enabling increased angle thresholds for object crossing detection (detection interval 90deg +/- 10deg, hysteresis +/- 5 degrees) */
#define OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD                SWITCH_OFF

/*****************************************************************************
  VARIABLES (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/


/* End of conditional inclusion */
///@}
#endif  /*!< _OOI_CUSTOM_EXT_H_INCLUDED */

