/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter rsp

  MODULNAME:       sim_conv_rsp1_noise.h

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   24.6.2015

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_rsp1_noise.h  $
  CHANGES:         Revision 1.1 2017/08/10 13:15:34CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:         Revision 1.1 2015/06/24 07:06:11CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#pragma once
#include "sim_converter_base.h"

extern IConverter * CreateRSP1NoiseConvClass(void);

