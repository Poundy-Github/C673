/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP (Adaptive Cruise Control - Longitudinal Headway Planner)

PACKAGENAME:               lohp.h

DESCRIPTION:               Internal header file for LOHP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.5 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

#ifndef LOHP_H_INCLUDED
#define LOHP_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   lohp_h Lohp_h
@ingroup    lohp_base_lohp
@brief      Internal header file for LOHP base module
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "frame_lohp.h"

#if (FCT_CFG_ACC_HEADWAY_PLANNER)
#include "hp_ext.h"
#endif
#if (FCT_CFG_DM)
#include "dm_ext.h"
#endif
#if (FCT_CFG_FCA)
#include "fca_ext.h"
#endif
#if (LOHP_CFG_PRED)
#include "pred_ext.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES 
*****************************************************************************/


#ifdef __cplusplus
};
#endif

/** @} end defgroup */

#endif /* LOHP_H_INCLUDED */

