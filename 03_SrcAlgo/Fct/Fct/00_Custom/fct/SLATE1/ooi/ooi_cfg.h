/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OOI (Object of Interest selection)

PACKAGENAME:               ooi_cfg.h

DESCRIPTION:               Configuration Header File for ACC Object Of Interest (OOI) selection module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.9.8.1 $

LEGACY VERSION:            Revision: 1.5

**************************************************************************** */

#ifndef OOI_CFG_H_INCLUDED
#define OOI_CFG_H_INCLUDED

#include "slate_config.h"
/*--- ooi_objselection.c ---*/
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup ooi_cfg Configuration
@ingroup ooi
@brief    Contains all configuration switches related to the ooi subcomponent.\n\n
@{
*/
/*! Configuration switch, which sets selection of OOI objects 4 & 5 as next longitudinal
instead of next predicted lateral */
#define OOI_CFG_SELECT_OOI_4_AND_5_NEXT_LONG           0

/*--- ooi_objloss.c ---*/

/*! Configuration switch enabling ObjectLossReason at low distance */
#define OOI_CFG_OBJLOSS_LOWDIST                        1

/* Configuration switch that supresses the selection of a stationary object as OOI 0
   if a moving object is already selected as OOI 0*/
#define OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS        1

/*Configuration switch to select OOI-1 as OOI-0 when OOI-0 is classified as a bike and is trying to overtake OOI-1. To be switched ON only in ARS510VW20 as there was no multi object controller. */
#define OOI_CFG_REL_OBJ_CHANGE_DURING_BIKE_OVERTAKE       FCT_CFG_DEPENDENT_SWITCH( (FCT_CFG_INPUT_PREPROCESSSING && FCT_CFG_ACC_LANE_ASSOCIATION),SWITCH_OFF)
///@}
#endif

