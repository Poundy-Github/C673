/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 FIP (FCT Input Preprocessing)

MODULNAME:                 fip_cfg.h

DESCRIPTION:               Internal Header File for FCT Input Preprocessing (FIP)

AUTHOR:                    Marie-Theres Boll

CREATION DATE:             08.03.2013

VERSION:                   $Revision: 1.13.3.1 $

LEGACY VERSION:            Revision: 1.10

**************************************************************************** */

#ifndef FIP_CFG_H_INCLUDED
#define FIP_CFG_H_INCLUDED

#include "slate_config.h"
/*****************************************************************************
  Config: FIP (FCT Input Preprocessing)
*****************************************************************************/
#if (FCT_CFG_INPUT_PREPROCESSSING)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup fip_cfg Configuration
@ingroup fip
@brief    Contains all configuration switches related to the fip subcomponent.\n\n
@{
*/


/*! Configuration switch to correct the absolute object acceleration value 
because of assumption of longitudinal movement only in the tracking. That 
assumption leads to wrong calculated object abs. acceleration in narrow curves */
#define SIT_CFG_CORR_ABS_OBJ_ACCEL                 (SIT_CFG_FILTER_ABS_OBJ_ACCEL && SWITCH_OFF)


/*! Use the information if camera lane markers are elevated 
    -> right now information only for ARS4B0 available */
#define FIP_CAM_USE_ELEVATED_LANE_MARKERS         FCT_CFG_DEPENDENT_SWITCH(SLATE_CFG_CAM_LANE_INTERFACE, SWITCH_OFF)

#define FIP_CFG_PREPROCESS_NAVI_INPUT_FOR_FUSION  FCT_CFG_DEPENDENT_SWITCH(SLATE_CFG_SIMPLE_NAVI_INTERFACE, SWITCH_OFF)

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
#define FIP_NAVI_REPRESENTATION_TYPE                     (0u)    /*!< representation type to identify how to plot navi data correctly in the FCT_SIM 
                                                                  This Value is used to distinguish between different NAVI interfaces
                                                                  *    0u  - ARS4B0 - navi segmets based on angles 
                                                                  *    1u  - ARS410VW16 - navi segments based on clothoids
                                                                  */

#endif  /* SLATE_CFG_SIMPLE_NAVI_INTERFACE */

#define FIP_CFG_EGO_LEAVE_NAVI_PATH_PROBABILITY    FCT_CFG_DEPENDENT_SWITCH(SLATE_CFG_SIMPLE_NAVI_INTERFACE, SWITCH_OFF)  /* Calculate probability that ego veh will not follow navi path */

#define FIP_CFG_USE_TUNNEL                        (SWITCH_OFF)

/* Configuration to decide the Road type when EM road type and Navi road type doesn't match */
#define FIP_CFG_CAM_WIDTH_ROAD_TYPE               (SWITCH_OFF)

///@}
#endif /*!< FCT_CFG_INPUT_PREPROCESSSING */

#endif
