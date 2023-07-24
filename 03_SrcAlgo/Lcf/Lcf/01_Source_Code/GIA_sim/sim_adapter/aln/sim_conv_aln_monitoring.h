/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter aln

  MODULNAME:       sim_conv_aln_monitoring.h

  DESCRIPTION:     Conversion module

  AUTHOR:          Jakob Schluttig / Mohammad Altamash Yakoob

  CREATION DATE:   29.09.2014

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_aln_monitoring.h  $
  CHANGES:         Revision 1.1 2021/12/13 17:20:21CET Wang, David (Wangd3) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/aln/project.pj
  CHANGES:         Revision 1.1 2017/08/10 13:14:49CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/aln/project.pj
  CHANGES:         Revision 2.1 2017/04/05 13:30:06CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         [ARS5xx/SRR5xx]
  CHANGES:         ? Remove A Sample compatilbility
  CHANGES:         ? Clean up SimAdapters
  CHANGES:         ? Only have version V100 and above
  CHANGES:         Revision 1.1 2014/09/29 15:22:50CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ALN_Alignment/04_Engineering/03_Workspace/algo/sim_adapter/aln/project.pj
  CHANGES:         Revision 1.1 2013/10/21 17:20:17CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/aln/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#pragma once
#include "sim_converter_base.h"

extern IConverter * CreateAlnMonitoringConvClass(void);

