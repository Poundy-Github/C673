/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 SLATE CP (Course Prediction)

MODULNAME:                 cp_customfunctions.h

DESCRIPTION:               Course prediction specific si-module header file

AUTHOR:                    Matthias Thomi, Gregor Powarzynski

CREATION DATE:             16.04.2012

VERSION:                   $Revision: 1.7 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */
#ifndef CP_CUSTOMFUNCTION_H_INCLUDED
#define CP_CUSTOMFUNCTION_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cp.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup cp_customfunctions
@{ */
/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MACROS
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
/*! The lane change overtake assist states */
typedef struct {
  uint8         uiLaneChgProb;    /*!< The current lane change probability  @min:0 @max:100 */
  uint8         uiLaneChgProbLC;  /*!< The lane change probability from the last cycle @min:0 @max:100 */
  ObjNumber_t   iOvertakeObj;     /*!< The ID of the object being overtaken (recent relevant object ID) */
  uint8         ucLaneChgDownCnt; /*!< Lane change down-counter (when non-zero, then lane change is active) */
} CP_CustomOvertakeAssistance_t;
#endif /* END IF (FCT_CFG_CUSTOM_IO_INTERFACE) */

/*****************************************************************************
  CONSTANTS
*****************************************************************************/
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
#ifndef FCT_MEAS_ID_CP_CUSTOM_OVERTAKE
#define FCT_MEAS_ID_CP_CUSTOM_OVERTAKE  0x202B1000
#endif
#endif /* (FCT_CFG_CUSTOM_IO_INTERFACE) */
/*****************************************************************************
  VARIABLES
*****************************************************************************/


/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

extern void CP_v_ACC_Process(void);

/** @} end defgroup */
#endif /* end of #ifndef _CP_CUSTOMFUNCTION_H_INCLUDED */
