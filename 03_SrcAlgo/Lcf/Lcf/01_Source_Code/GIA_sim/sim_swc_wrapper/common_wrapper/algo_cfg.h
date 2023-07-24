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
  CHANGES:                Revision 1.1 2021/12/13 17:22:58CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/common_wrapper/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:34:35CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/common_wrapper/project.pj
  CHANGES:                Revision 1.3 2013/03/05 12:45:42CET spruckj 
  CHANGES:                move algo_glob.h and algo_cfg.h from algo\algo_common to common folder
  CHANGES:                - Added comments -  spruckj [Mar 5, 2013 12:45:42 PM CET]
  CHANGES:                Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:                Revision 1.2 2012/10/25 10:51:05CEST Thiel, Robert (thielr) 
  CHANGES:                removed some radar stuff
  CHANGES:                --- Added comments ---  thielr [Oct 25, 2012 10:51:05 AM CEST]
  CHANGES:                Change Package : 161940:2 http://mks-psad:7002/im/viewissue?selection=161940


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

#ifdef _MSC_VER
#define CFG_USE_COMPACT_ENUMS               1
#else
#define CFG_USE_COMPACT_ENUMS               0
#endif


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

