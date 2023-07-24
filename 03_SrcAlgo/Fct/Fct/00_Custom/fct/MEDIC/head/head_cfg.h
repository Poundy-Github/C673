/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_cfg.h

DESCRIPTION:               cfg of the HEAD 

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2019/07/26 14:49:31CEST $

VERSION:                   $Revision: 1.5.1.2 $
  
**************************************************************************** */
/**
@ingroup Medic_head
@{ **/
#ifndef FCT_HEAD_CFG_H_INCLUDED
#define FCT_HEAD_CFG_H_INCLUDED

/*****************************************************************************
  MACROS
*****************************************************************************/
/*! @brief HEAD module turn assistance */
#define HEAD_CFG_TURN_ASSIST                SWITCH_OFF

/*! @brief Inhibition mask for unclassified objects that have longitudinal hypothesis*/
#define HEAD_CFG_INHIBIT_OBSTACLE_LONG      SWITCH_ON

/*! @brief Inhibition mask for unclassified objects that have crossing hypothesis*/
#define HEAD_CFG_INHIBIT_OBSTACLE_CROSSING  SWITCH_ON

#define HEAD_CFG_CORRIDOROCCUPANCY          SWITCH_ON

#endif
/**@}*/ 