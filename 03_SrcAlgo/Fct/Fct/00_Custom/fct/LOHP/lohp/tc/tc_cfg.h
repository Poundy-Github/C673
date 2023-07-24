/*! \file **********************************************************************

  COMPANY:                COPYRIGHT (C) Continental AG

  PROJECT:                Mainstream

  CPU:                    CPU-Independent

  COMPONENT:              ACC/LOHP/TC (Adaptive Cruise Control - Longitudinal Headway Planner - Target Control)

  MODULNAME:              tc_cfg.h

  DESCRIPTION:            Configuration file for function ACC in LOHP/TC

  AUTHOR:                 $Author: uidj5069 $

  CREATION DATE:          26.03.2010

  VERSION:                $Revision: 1.3 $

  ---*/ /*---
  CHANGES:                $Log: tc_cfg.h  $
  CHANGES:                Revision 1.3 2018/04/16 15:25:09CEST uidj5069 
  CHANGES:                New Switch <TC_CFG_OVERTAKE_SUPPORT_FEATURE> added
  CHANGES:                Revision 1.2 2018/03/15 11:46:33CET Borgs, Wolfgang (uidj5069) 
  CHANGES:                Config Switch <TC_CFG_MULTI_OBJECT_CONTROL_FEATURE> added and activated
  CHANGES:                Revision 1.1 2017/10/05 09:48:09CEST Borgs, Wolfgang (uidj5069) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Components/LOHP_LongitudinalHeadwayPlanner/04_Engineering/00_Projects/ARS510/LOHP/lohp/tc/project.pj
  CHANGES:                Revision 1.1 2017/03/15 20:57:07CET Berendes, Ignacius (uid41806) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Components/LOPC/04_Engineering/00_Projects/ARS510/LOPC/lopc/hc/acc/project.pj

**************************************************************************** */
#ifndef TC_CFG_H_INCLUDED
#define TC_CFG_H_INCLUDED

/*****************************************************************************
  Config: ACC (Adaptive Cruise Control) Features 
*****************************************************************************/

/*! Activation of Multiobject Control feature */
#define TC_CFG_MULTI_OBJECT_CONTROL_FEATURE         SWITCH_OFF

/*! Activation of Overtake Support feature */
#define TC_CFG_OVERTAKE_SUPPORT_FEATURE             SWITCH_OFF



#endif

