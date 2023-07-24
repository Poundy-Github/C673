/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOCC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               locc_cfg.h

DESCRIPTION:               Configuration file for LOCC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.1 $

LEGACY VERSION:            Revision: 1.11.1.4

**************************************************************************** */

#ifndef LOCC_CFG_H_INCLUDED
#define LOCC_CFG_H_INCLUDED

/*****************************************************************************
  Config: Functionalities and Features
*****************************************************************************/

/* Switch for CC sub-component */
#define LOCC_CFG_CC                            FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ACT_CODE_VERSION,SWITCH_ON)



#endif /* ifndef LOCC_CFG_H_INCLUDED */

