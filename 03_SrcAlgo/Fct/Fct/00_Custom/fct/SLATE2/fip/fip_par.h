/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_FIP (Adaptive Cruise Control - Function Input Preprocessing)

MODULNAME:                 fip_par.h

DESCRIPTION:               Parameter Header File for ACC FCT Input Preprocessing (FIP) module

AUTHOR:                    Marie-Theres Boll (uidu1091)

CREATION DATE:             08.03.2013

VERSION:                   $Revision: 1.10 $

LEGACY VERSION:            Revision: 1.5.1.3

**************************************************************************** */
#ifndef FIP_PAR_H_INCLUDED
#define FIP_PAR_H_INCLUDED

#include "fip_cfg.h"
#include "slate_par.h"

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup fip_par Parameter
@ingroup fip
@brief        Contains all parameters that are used in fip and their values.\n\n
@{
*/
/*-------------------------------------------------------------------------
| Parameters for NAVI Data handling in FIP modules                         |
-------------------------------------------------------------------------*/
#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)

/*! The minimum threshold for NAVI data quality to be plausible */
/*
0000    Functional Road Class 0     Roads of international importance 
0001    Functional Road Class 1     Roads of national importance
0010    Functional Road Class 2     Roads of regional importance
0011    Functional Road Class 3     Roads of high local importance
0100    Functional Road Class 4     Roads of local importance

qualityLevel
0 := Status_Übereinstimmung_Eindeutigkeit_Position or Status_Übereinstimmung_Qualität are bad.
1 := Functional Road Class == FRC4, FRC5 && ADAS-compliant == 0
2 := Functional Road Class == FRC1, FRC2, FRC3 && ADAS-compliant == 0
3 := Functional Road Class == FRC4, FRC5 && ADAS-compliant == 1
4 := Functional Road Class == FRC1, FRC2, FRC3 && ADAS-compliant == 1
*/
#define FIP_NAVI_DATA_QUALITY_THRESHOLD_MIN   (3u)

#define FIP_NAVI_MAXSEG_FORCITYLIMIT      (FCT_NAV_NUM_SEG)                    /*!< Number of segments used for checking if EGO is driving within city limits */
#define FIP_NAVI_MAXSEG_FORDATAVALIDITY   (FCT_NAV_NUM_SEG)                                 /*!< Number of segments used for checking if incoming segment data is valid */
#define FIP_NAVI_MAXSEG_FORCOUNTRYROAD    (FCT_NAV_NUM_SEG)                    /*!< Number of segments used for checking if EGO is driving on country road */

#endif  /* IF SLATE_CFG_SIMPLE_NAVI_INTERFACE */

#define FIP_CURVATURE_CHANGE_USE_CIRCLE_APPROX    (1.f / 1000000.f)    /* 1% error in dy aproximation */
#define FIP_CURVATURE_USE_LINEAR_APPROX           (1.f / 10000.f)      /* 1% error in dy aproximation */


#if (FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION)
#define FIP_ROAD_CURVE_CHANGE_DIST_ON_TRAJ_MAX           (RW_FCT_MAX)         /*!< [m], maximum x-distance with high curvature change */
#define FIP_ROAD_CURVE_CHANGE_DELTA_Y_THRES_PICKUP       (2.5f)               /*!< [m], delta-y pickup threshold at which x-distance to high curvature change is defined */
#define FIP_ROAD_CURVE_CHANGE_DISTX_STEP                 (10.f)               /*!< [m], step size while searching x-distance with high curvature change */
#define FIP_ROAD_CURVE_CHANGE_MIN_ROAD_CONFIDENCE_PICKUP (78u)                /*!< percentage, minimum one-sided road confidence for consideration in distance to high curvature change (pickup)*/
#define FIP_ROAD_CURVE_CHANGE_MIN_ROAD_CONFIDENCE_DROP   (30u)                /*!< percentage, minimum one-sided road confidence for consideration in distance to high curvature change (drop)*/
#define FIP_ROAD_CURVE_CHANGE_ROAD_RANGE_HYSTERESIS_HIGHWAY      (30.F)       /*!< [m], RE range hysteresis for highway*/
#define FIP_ROAD_CURVE_CHANGE_ROAD_RANGE_HYSTERESIS      (10.F)               /*!< [m], RE range hysteresis other than highway*/
#define FIP_ROAD_CURVE_CHANGE_MIN_ROAD_RANGE_TG          (3.F)                /*!< [s], time-gap of minimum RE range */
#define FIP_ROAD_CURVE_CHANGE_EGO_VELOCITY               (75.f/C_KMH_MS)      /*!< [s], ego velocity bellow which road fusion check is not taken for curvature computation */
#endif /* #if (FCT_CFG_ROAD_CURVATURE_CHANGE_COMPUTATION) */

#if (FCT_CFG_NAVI_CURVATURE_CHANGE_COMPUTATION)
#define FIP_NAVI_CURVE_CHANGE_DIST_ON_TRAJ_MAX          (RW_FCT_MAX) /*!< [m], maximum distance on trajectory with high curvature change */
#define FIP_NAVI_CURVE_CHANGE_DELTA_Y_THRES             (0.8f)       /*!< [m], delta-y threshold at which high curvature change is defined */
#define FIP_NAVI_CURVE_CHANGE_DIST_ON_TRAJ_STEP         (5.f)        /*!< [m], step size on navi trajectory while searching x-distance with high curvature change */
#endif /* FCT_CFG_NAVI_CURVATURE_CHANGE_COMPUTATION */

#if (FCT_CFG_CURVATURE_CHANGE_COMPUTATION)
#define FIP_DIST_TO_HIGH_CURVATURE_CHANGE_FUS_WEIGHT    (0.5f)                /*!< [0.f ... 1.f] fusion weight of navi and road distance to high curvature change */
#endif /* FCT_CFG_CURVATURE_CHANGE_COMPUTATION */

#if( (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) )
#if SLATE_CFG_NAVI_OBJ_LAT_DIST
#define FIP_MAX_DIST_TEN_HIGHWAY_LANES                  (37.5f)               /*!< Max limit of 10 Highway lane width */
#endif /* end of SLATE_CFG_NAVI_OBJ_LAT_DIST */
#endif /* end of (SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING) */
///@}
#endif /* FIP_PAR_H_INCLUDED */
