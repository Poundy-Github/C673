/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OUT (Output)

PACKAGENAME:               out_custom_ext.h

DESCRIPTION:               External Header File for Custom specific information in ACC Output (OUT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             27.07.2016

VERSION:                   $Revision: 1.7 $

LEGACY VERSION:            Revision: 1.6

**************************************************************************** */

#ifndef OUT_CUSTOM_EXT_H_INCLUDED
#define OUT_CUSTOM_EXT_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "out_cfg.h"
#include "slate_ext.h"
#include "out_ver.h"
/* nothing should be included in this file */
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup out_customfunctions
@{ */

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/

/*--- out_customfunctions.c ---*/
/*! Configuration switch for activating the calculation of the 
    x-relevance and y-relevance of an object */
#define OUT_CFG_CUSTOM_XY_RELEVANCE                   (SWITCH_OFF)

/*! Configuration switch for activating the calculation of the driving tube mapping of an object */
#define OUT_CFG_CUSTOM_DRIVING_TUBE_MAPPING           (SWITCH_OFF)



/*! Configuration switch for enabling custom output type (OUT_t_CustMeasOOI)
output over measurement interface for each OOI object. This allows
application-project specific data to be attached to the OOI measurement
objects for validation or visualization */
#define OUT_CFG_CUSTOM_OOI_MEAS_DATA                  (SWITCH_OFF)

/*! OUT OOI with debug TTC/TG information in meas-freeze (simplifies quick
performance evaluation) */
#define OUT_CFG_OOI_TTC_TG_DEBUG_CRITERIA             (SWITCH_OFF)

/*! Configuration switch for activating additional call to custom
SICustProcessCriteriaMatrix after all other trace bracket processing
took place. When enabled, you can use the function SICustProcessCriteriaMatrix
for customizing trace brackets */
#define OUT_CFG_CUSTOM_CRITERIA_MATRIX_PROCESSING     (SWITCH_OFF)

/*! Internal configuration switch enabling custom object width output. See
BMW CR related to traffic jam assist (CR 125427) */
#define OUT_CFG_CUSTOM_OBJ_WIDTH_OUTPUT               (SWITCH_OFF)

/*! Internal configuration switch to directly access ME input structure to output
ME object class based wide object output */
#define OUT_CFG_USE_ME_CLASS_DIRECTLY                 (SWITCH_OFF)

/*****************************************************************************
  MACROS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/

/*! Structure for OUT custom debug data */
typedef struct {
#if (LA_CFG_DTR_OBJ_SELECTION)
  uint8 ui_PreselectFusionObjCounter;
#else
  uint8 ui_dummy;
#endif
} OUT_t_CustomOutputDebugInfo;

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
#endif  /*!< _OUT_CUSTOM_EXT_H_INCLUDED */
