/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OUT (Output)

PACKAGENAME:               out_par.h

DESCRIPTION:               Parameter Header File for ACC Output (OUT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.5 $

LEGACY VERSION:            Revision: 1.2

**************************************************************************** */

#ifndef OUT_PAR_H_INCLUDED
#define OUT_PAR_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "out_cfg.h"
#include "slate_par.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup out_par Parameter
@ingroup out
@brief        Contains all parameters that are used in out and their values.\n\n
@description  This module does not contain any functions. It only contains defines as soon as variable initializations.
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
/***************************************** DriveOffMonitor ********************************************/
#if (OUT_CFG_DRIVE_OFF_MONITOR)
#define LA_DRIVEOFF_US_TOLERANCE          (0.2f)        /*  p_d_ACC_Unsicherheitsband_Weglaenge_Hindernis_US*/
#define LA_DRIVEOFF_US_MAX_LONG_DIST      (5.f)         /*  max longitudinal corridor distance*/

#define LA_DRIVEOFF_CAM_FOLLOWUP_TIME_1   (2.5f)        /*  p_t_ACC_VideoNachlauf1*/
#define LA_DRIVEOFF_CAM_FOLLOWUP_TIME_2   (2.5f)        /*  p_t_ACC_VideoNachlauf2*/
#define LA_DRIVEOFF_CAM_STATE_1           (0.f)         /*  p_w_ACC_VideoStufe1*/
#define LA_DRIVEOFF_CAM_STATE_2           (0.5f)        /*  p_w_ACC_VidoeStufe2*/
#define LA_DRIVEOFF_CAM_DIST_STANDSTILL   (3.f)         /*  p_d_ACC_VideoFreiDistNachStillstand*/
#define LA_DRIVEOFF_CAM_DIST_MOVING       (3.f)         /*  p_d_ACC_VideoFreiDistInFahrt*/

#define LA_DRIVEOFF_MAX_VELOCITY          (15.f/C_KMH_MS)/*  p_v_ACC_GeschwMaxAnfahrueb*/
#define LA_DRIVEOFF_OBSTACLE_THRES        (0.f)         /*  p_w_ACC_HindernisFreischwelle*/

#define LA_DRIVEOFF_RADAR_POE_THRES       (40u)         /*  p_w_ACC_SdfObjMaxExist*/
#define LA_DRIVEOFF_RADAR_MAX_LONG_DIST   (5.f)         /*  p_d_ACC_SdfObjMaxDist*/
#define LA_DRIVEOFF_RADAR_CORRIDOR_MIN    (1.7f / 2.f)  /*  p_d_ACC_SdfObjMinAnfKorr*/
#define LA_DRIVEOFF_RADAR_CORRIDOR_MAX    (2.f / 2.f)   /*  p_d_ACC_SdfObjMaxAnfKorr*/
#define LA_DRIVEOFF_RADAR_WEIGHT_XDIST    (1.f)         /*  p_d_ACC_SdfObjDxGrenze*/
#define LA_DRIVEOFF_RADAR_SAVE_NEXTOOI    (5.f/C_KMH_MS)/*  p_d_ACC_SdfObjDxGrenze*/

#define LA_DRIVEOFF_RADAR_THRESHOLD       (0.5f)        /*  Objectweigt for clearly detected radar obstacle*/
#define LA_DRIVEOFF_VIDEO_THRESHOLD       (0.5f)        /*  Objectweigt for clearly detected video obstacle*/
#define LA_DRIVEOFF_US_THRESHOLD          (0.5f)        /*  Objectweigt for clearly detected ultrasonic obstacle*/

#define LA_DRIVEOFF_US_OBSTACLE_RECOGNIZED (TRUE)       /*  ultrasonic obstacle detected*/
#endif /*END IF(OUT_CFG_DRIVE_OFF_MONITOR) */

/***************************************** ActivationPrevention ********************************************/
#if (OUT_CFG_ACTIVATION_PREVENTION)
#define OUT_AP_MAX_DIST_STATIONARY           (20.f)        /*p_d_ACC_DistMaxStehendesHindernisKeinWZOAktivierverhinderung*/
#define OUT_AP_MAX_DIST_ONCOMING_STOPPED     (10.f)        /*p_d_ACC_DistMaxAngehaltenEntgegenHindernisKeinWZOAktivierverhinderung*/
#define OUT_AP_POE_THRES                     (40u)         /* PoE threshold for relevant obstacles*/
#endif /* (OUT_CFG_ACTIVATION_PREVENTION) */

/*****************************************************************************
 CUSTOM PASSING STATE APPLICATION PARAMETERS 
*****************************************************************************/
#if (FCT_CFG_CUSTOM_PASSING_STATE)
#define OUT_CUSTOM_NUM_OF_LANES_INVALID                ((sint8)(-1)) /* invalid value for num of lanes */
/* threshold of Lane change probability */
#define OUT_CUSTOM_PASSING_STATE_PROB_MIN              ((sint16)(75)) /* maximum longitudinal relevance */
#endif  /* #endif FCT_CFG_CUSTOM_PASSING_STATE */

#if OUT_CFG_CUSTOM_ENGINE_TRIGGER
/* longitudinal relevance */
#define OUT_CUSTOM_ENGINE_START_XDIST_MAX              (7.0F)  /* maximum longitudinal relevance */
#define OUT_CUSTOM_ENGINE_START_HIDDEN_XDIST_MAX       (15.0F)  /* maximum longitudinal relevance */
/* velocity relevance */
#define OUT_CUSTOM_ENGINE_START_V_MIN                  (0.5F)  /* minimum velocity relevance */
#define OUT_CUSTOM_ENGINE_START_HIDDEN_V_MIN           (0.5F)  /* minimum velocity relevance */
/* increased distance relevance */
#define OUT_CUSTOM_ENGINE_START_XDIST_MIN_ROLL         (2.0F)  /* minimum increased distance relevance */
#define OUT_CUSTOM_ENGINE_START_HIDDEN_XDIST_MIN_ROLL  (2.0F)  /* minimum increased distance relevance */
/* longitudinal relevance engine stop prevention*/
#define OUT_CUSTOM_ENGINE_STOP_XDIST_MAX               (10.0F)  /* maximum longitudinal relevance */
#define OUT_CUSTOM_ENGINE_STOP_HIDDEN_XDIST_MAX        (18.0F)  /* maximum longitudinal relevance */
#endif /*END IF (FCT_CFG_CUSTOM_PASSING_STATE)*/

/*****************************************************************************
  VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/* End of conditional inclusion */
/** @} end defgroup */
#endif  /*!< _OUT_PAR_H_INCLUDED */

