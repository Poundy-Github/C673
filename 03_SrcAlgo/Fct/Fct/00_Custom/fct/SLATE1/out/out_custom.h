/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OUT (Output)

PACKAGENAME:               out_custom.h

DESCRIPTION:               Custom Header File for ACC Output (OUT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             28.06.2016

VERSION:                   $Revision: 1.6 $

LEGACY VERSION:            Revision: 1.3

**************************************************************************** */

#ifndef OUT_CUSTOM_H_INCLUDED
#define OUT_CUSTOM_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "slate.h"
#include "out_par.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup out_customfunctions
@{ */

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
#define TJA_DEFAULT_OBJECT_ID                (255u) /*! [no unit], default object ID used as initial value and in situations where there is no OOI-0 */

/*****************************************************************************
  MACROS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
#if (OUT_CFG_DRIVE_OFF_MONITOR) /* Copy to out_custom.h*/
typedef struct  
{
  /* delay timer for the video module of the drive off monitor*/
  float32 f_CAMTimer1;
  float32 f_CAMTimer2;
  /* last moving relevant object*/
  ObjNumber_t t_MovingOldNextOOI;
  /* driven distance since the video obstacle disappeared*/
  float32 f_drivenDist;
} OUT_t_a_DriveOff;
#endif /*END IF (OUT_CFG_DRIVE_OFF_MONITOR)*/

#ifdef FCT_SIMU
#if (OUT_CFG_DRIVE_OFF_MONITOR) /* Copy to out_custom.h*/
typedef struct
{ 
  boolean b_DriveOffMon_US;
  boolean b_DriveOffMon_CAM;
  boolean b_DriveOffMon_Radar;
  float32 f_DriveOffMon_vacantCorrProb; 
} OUT_CustDriveOffMonDebugData_t;

/*! Calculation DiveOffMonitor*/  
#ifndef OUT_CUST_DRIVEOFFMON_DEBUG_VADDR
#define OUT_CUST_DRIVEOFFMON_DEBUG_VADDR     (0x2020FDD8u) /*(0x2020FD00u)*/
#endif
#endif /* ENDIF (OUT_CFG_DRIVE_OFF_MONITOR)*/
/* TODO: Custom output debug data should be freezed in the out meas freeze function*/  

#if (FCT_CFG_CUSTOM_PASSING_STATE)
#define OUT_CUSTOM_OUTPUT_DEBUG_VADDR        (0x2020FFD8u) 
#endif  /* #endif FCT_CFG_CUSTOM_PASSING_STATE */

#endif /* END IF FCT_SIMU*/

/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
#include "slate.h"
#include "out_par.h"

#ifdef __cplusplus
};
#endif
///@}
/* End of conditional inclusion */
#endif  /*!< _OUT_CUSTOM_H_INCLUDED */
