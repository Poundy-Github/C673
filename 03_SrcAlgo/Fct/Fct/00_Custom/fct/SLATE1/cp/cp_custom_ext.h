/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_CP (Course Prediction)

PACKAGENAME:               cp_custom_ext.h

DESCRIPTION:               External Header File for Custom specific information in SLATE Course Prediction (CP)

AUTHOR:                    Patel Chirag (uidr6458)

CREATION DATE:             9/30/2016

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 1.2

**************************************************************************** */
#ifndef CP_CUSTOM_EXT_H_INCLUDED
#define CP_CUSTOM_EXT_H_INCLUDED

#include "slate_ext.h"
#include "cp_ver.h"
#include "cp_cfg.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup cp_customfunctions
@{ */

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/


/*! @brief CP_TRACE_FUSION_MIN_TRACEPOINTS */
#define CP_TRACE_FUSION_MIN_TRACEPOINTS      10L

/*! @brief CP_PLAUSIBILITY_HIGHWAY_SLIP_OFFSET */
#define CP_PLAUSIBILITY_HIGHWAY_SLIP_OFFSET  DEG2RAD(1.0F)

/*! @brief CP_PLAUSIBILITY_DEVIATION_CORRIDOR */
#define CP_PLAUSIBILITY_DEVIATION_CORRIDOR   1.0F


/*****************************************************************************
  FUNCTIONS DECLARATION
*****************************************************************************/
extern void CP_v_ACC_Process(void);

#if (SLATE_CFG_ENABLE_OVERTAKE_ASSIST)
/*! BMW-specific external declaration for overtake assistance activation */
extern boolean CP_b_ACC_GetCustomOvertakeAssistanceState(void);
#endif /*(SLATE_CFG_ENABLE_OVERTAKE_ASSIST)*/

#endif /* CP_CUSTOM_EXT_H_INCLUDED */
/** @} end defgroup */
