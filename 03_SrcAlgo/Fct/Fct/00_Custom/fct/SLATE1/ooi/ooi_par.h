/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OOI (Object of Interest selection)

PACKAGENAME:               ooi_par.h

DESCRIPTION:               Parameter Header File for ACC Object Of Interest (OOI) selection module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.11 $

LEGACY VERSION:            Revision: 1.6

**************************************************************************** */


#ifndef OOI_PAR_H_INCLUDED
#define OOI_PAR_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "ooi_cfg.h"
#include "slate_par.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup ooi_par Parameter
@ingroup ooi
@brief        Contains all parameters that are used in ooi and their values.\n\n
@description  This module does not contain any functions. It only contains defines as soon as variable initializations.
@{
*/
/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*--- ooi_objselection.c ---*/

/*! defines the prediction time for lateral displacement prediction (using lateral velocity)*/
#define OOI_LAT_DISPL_PREDICTION_TIME (1.5f)

/*! defines the number of OOIs for which object loss reasons to be calculated*/
#define OBJLOSS_NUMBER_OF_OOI (1)

/*--- ooi_select_moving.c ---*/

/*! crossing traffic only reported to 6 object interface below the following distance */
#define OOI_MAX_DIST_FOR_CROSSING_REPORT (0.0f)


/*--- ooi_objloss.c ---*/

/* switch for enabling ROV reset condition by time */
#define OOI_ROV_RESET_BY_TIME SWITCH_OFF

#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
/* maximum time[s] for holding ROV if time reset condition Algo enabled */
#define OOI_ROV_RESET_TIME (10.0f)
#endif
/* Curve radius limitation for object loss situation */
#define OOI_ROVG_GRENZKRUEMMUNG_AUS        (0.5F/1500.F)

/*--- ooi_select_moving.c ---*/

/* the object is detected as crossing if the object's orientation is higher than 80 degrees */
#define OOI_LOW_THRESHOLD_ORIENTATION_RAD                 CML_Deg2Rad(80.0f)
/* the object is detected as crossing if the object's orientation is lower than 100 degrees */
#define OOI_HIGH_THRESHOLD_ORIENTATION_RAD                CML_Deg2Rad(100.0f)
/* hysteresis: once an object is detected as crossing it will remain as crossing if its orientation is not lower that 75 degrees */
#define OOI_LOW_THRESHOLD_HYSTERESIS_ORIENTATION_RAD      CML_Deg2Rad(75.0f)
/* hysteresis: once an object is detected as crossing it will remain as crossing if its orientation is not higher that 105 degrees */
#define OOI_HIGH_THRESHOLD_HYSTERESIS_ORIENTATION_RAD     CML_Deg2Rad(105.0f)


#if (OOI_CFG_OBJLOSS_LOWDIST)
#define OOI_ROV_LOWDIST_THRES         (5.0f)
#define OOI_ROV_DISTXSKIP_THRES       (2.0f)
#define OOI_ROV_LOWDIST_CURVE_THRES   (1.0f/20.f) /*0.04 is roundabout curve*/
#endif

/*****************************************************************************
  MACROS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
#if(OOI_CFG_REL_OBJ_CHANGE_DURING_BIKE_OVERTAKE)
#define OOI_MAX_TTC_OFFSET                                 (1.0f)                             /*TTC offset between OOI0 and OOI1 to avoid abnormal behaviour during comparison */
#define OOI_MAX_TTC0                                       (1000.0f)                          /*Max value of TTC of OOI0 when relative velocity of the object is negative*/
#define OOI_MAX_TTC1                                       (OOI_MAX_TTC0 + OOI_MAX_TTC_OFFSET)/*Max value of TTC of OOI1 when relative velocity of the object is negative */
#define OOI_OOI1_OOI0_VEL_OFFSET                           (0.5f)                             /*Velocity offset required between OOI0 and OOI1 */
#define OOI_OOI1_EGO_VEL_OFFSET                            (1.0f)                             /*Velocity offset required between Ego and OOI1 */
#define OOI_OOI1_MAX_TTC_FOR_BIKE_OVERTAKE                 (8.0f)                             /*Max value of TTC of OOI1 during bike overtake */
#define OOI_EGO_MAX_VEL_FOR_BIKE_OVERTAKE                  (43.2f/C_KMH_MS)                   /*Max velocity of Ego during bike overtake */
#define OOI_OOI0_MAX_DIST_FOR_BIKE_OVERTAKE                (60.0f)                            /*Max distance of OOI0 during bike overtake */
#define OOI_MAX_DIST_DIFF_INITIAL                          (10.0f)                            /*Max distance between OOI0 and OOI1 initally */
#define OOI_OOI0_MIN_DIST2TRAJ_INITIAL                     (0.80f)                            /*Min distance to trajectory required for OOI0 to select OOI1 as OOI0 initially */
#define OOI_OOI1_MAX_DIST2TRAJ                             (1.2f)                             /*Max distance to trajectory to select OOI1 as OOI0 */
#define OOI_MAX_DIST_DIFF_FINAL                            (4.0f)                             /*Max distance between OOI0 and OOI1 Finally */
#define OOI_OOI0_MIN_DIST2TRAJ_FINAL                       (1.0f)                             /*Min distance to trajectory required for OOI0 to select OOI1 as OOI0 Finally */
#endif /*(OOI_CFG_REL_OBJ_CHANGE_DURING_BIKE_OVERTAKE)*/

/*****************************************************************************
  TYPEDEFS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/* End of conditional inclusion */
/// @} 
#endif  /*!< _OOI_PAR_H_INCLUDED */

