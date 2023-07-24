/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/PRED (Adaptive Cruise Control - Longitudinal Headway Planner - Predictive ACC)

PACKAGENAME:               pred_cfg.h

DESCRIPTION:               Configuration file for PRED in LOHP

AUTHOR:                    Schnellbach Hans-Juergen (uidg5946)

CREATION DATE:             08.01.2019

VERSION:                   $Revision: 1.3 $

**************************************************************************** */

#ifndef PRED_CFG_H_INCLUDED
#define PRED_CFG_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/*!
@defgroup   pred_custom PRED_Custom
@ingroup    lohp_custom_lohp
@brief      Module for PRED custom files
 */

/*!
@defgroup   pred_cfg Pred_cfg
@ingroup    pred_custom
@brief      PRED config File
@{ */ 

/*****************************************************************************
  CONFIGURATIONS
*****************************************************************************/
/* Switch for PRED sub-component */

/*! Project's uses a VW reconstructor */
#define PRED_USE_VW_EHR_NAVI_DATA   SWITCH_ON

/*! Usage of Street type for Navi data validity calculation */
#define PRED_USE_STREET_TYP         FCT_CFG_DEPENDENT_SWITCH(PRED_USE_VW_EHR_NAVI_DATA,SWITCH_OFF)

/*! Number of segments provided by reconstructor */
#define PRED_NUM_USED_NAVI_SEG      (( uint8 )8 )

/*! Activation of Curve Control module */
#define PRED_ACT_CURVE_CTRL         FCT_CFG_DEPENDENT_SWITCH(LOHP_CFG_PRED,SWITCH_ON)

/*! Activation of Green ACC module */
#define PRED_ACT_GREEN_ACC          FCT_CFG_DEPENDENT_SWITCH(LOHP_CFG_PRED,SWITCH_ON)

/*! Activation of Speed Limit module */
#define PRED_ACT_SPEED_LIM_CTRL     FCT_CFG_DEPENDENT_SWITCH(LOHP_CFG_PRED,SWITCH_ON)

/** @} end defgroup */

#endif /* PRED_CFG_H_INCLUDED */

