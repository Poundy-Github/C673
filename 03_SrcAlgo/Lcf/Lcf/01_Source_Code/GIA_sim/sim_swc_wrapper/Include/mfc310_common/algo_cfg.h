/*! \file **********************************************************************

  COMPANY:                Continental Temic, PC DAS, A.D.C. GmbH

  PROJECT:                All

  CPU:                    All

  COMPONENT:              RTE

  MODULNAME:              algo_cfg.h

  DESCRIPTION:            


  CREATION DATE:          23.03.2010

  VERSION:                $Revision: 1.1 $

                  
  ---*/ /*---
  CHANGES:                $Log: algo_cfg.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:24:41CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_common/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:35:36CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_common/project.pj
  CHANGES:                Revision 1.1 2014/03/13 15:11:11CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_common/project.pj
  CHANGES:                Revision 1.2 2010/03/24 11:16:40CET gungvary 
  CHANGES:                Move CFG_USE_COMPACT_ENUMS switch to algo_cfg.h
  CHANGES:                Include algo_cfg.h in algo_glob.h and algo_type.h
  CHANGES:                Move SWITCH_ON and SWITCH_OFF definitions to algo_cfg.h, to assure that the corresponding defines
  CHANGES:                are always set, prior to any other definitions.
  CHANGES:                --- Added comments ---  gungvary [2010/03/24 10:16:40Z]
  CHANGES:                Change Package : 39685:1 http://LISS014:6001/im/viewissue?selection=39685
  CHANGES:                Revision 1.1 2010/03/23 17:23:49CET gungvary 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/PROJECTS/ARS301/05_Software/04_Engineering/01_Source_Code/rte/project.pj


**************************************************************************** */
#ifndef ALGO_CFG_H_INCLUDED
#define ALGO_CFG_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! Switch conditions */
#define SWITCH_ON       1
#define SWITCH_OFF      0

/*! Configuration switch controlling if simple numeric types shall be used
instead of real enumerations. This is useful on architectures where the
compiler always allocates 'words' for enumerations, regardless of the
enumerator range */
#define CFG_USE_COMPACT_ENUMS               1

/*! Configuration switch enabling low speed pedestrian selection support in
EM and FCT components. This switch was formerly in TP with the name
CFG_SI_LOW_SPEED_STAT_PEDESTRIAN */
#define CFG_LOW_SPEED_STAT_PEDESTRIAN       1

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  VARIABLES
*****************************************************************************/


/*****************************************************************************
  FUNCTIONS
*****************************************************************************/


#endif
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

