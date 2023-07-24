/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter aln

  MODULNAME:       sim_conv_aln_rtereqhwconfig.h

  DESCRIPTION:     Conversion module

  AUTHOR:          Mohammad Altamash Yakoob

  CREATION DATE:   22.03.2017

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_aln_rtereqhwconfig.h  $
  CHANGES:         Revision 1.1 2021/12/13 17:20:23CET Wang, David (Wangd3) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/aln/project.pj
  CHANGES:         Revision 1.1 2017/08/10 13:14:52CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/aln/project.pj
  CHANGES:         Revision 2.1 2017/04/05 13:30:10CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         [ARS5xx/SRR5xx]
  CHANGES:         ? Remove A Sample compatilbility
  CHANGES:         ? Clean up SimAdapters
  CHANGES:         ? Only have version V100 and above
  CHANGES:         Revision 1.1 2017/03/22 12:48:39CET Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ALN_Alignment/04_Engineering/03_Workspace/algo/sim_adapter/aln/project.pj
**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#pragma once
#include "sim_converter_base.h"

extern IConverter * CreateAlnRteReqHwConfigConvClass(void);

