/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC4xx

  CPU:                    CPU-Independent

  COMPONENT:              HLA

  MODULNAME:              hla_project_defs.h

  DESCRIPTION:            Contains project specific defines

  AUTHOR:                 Matthias Mutshcler

  CREATION DATE:          21.03.2014

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_project_defs.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:23:20CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Converter/HLA/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:34:50CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Converter/HLA/project.pj
  CHANGE:                 Revision 1.1 2014/03/22 10:22:34CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/00_Custom/hla_wrp/project.pj
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_PROJECT_DEFS_INCLUDED
#define HLA_PROJECT_DEFS_INCLUDED

/*****************************************************************************
  MACROS 
*****************************************************************************/
/* Macros for projects */
#define HLA_PROJECT_SMFC4B0   0u
#define HLA_PROJECT_SRLCAM4T0 1u


/* Defines active project */
#define HLA_PROJECT HLA_PROJECT_SMFC4B0

/* avoid cyclic binding ---------------------------------------------------*/
#endif /* #ifndef HLA_PROJECT_DEFS_INCLUDED */
