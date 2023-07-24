/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter

  MODULNAME:       sim_conv_rsp1_nacom.h

  DESCRIPTION:     Adapter/Converter for Nacom

  AUTHOR:          Thomas Berndt

  CREATION DATE:   20.08.2014

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_rsp1_nacom.h  $
  CHANGES:         Revision 1.1 2017/08/10 13:15:33CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:         Revision 1.1 2014/08/20 15:43:38CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj

**************************************************************************** */
#pragma once
#include "sim_converter_base.h"

IConverter * CreateRSPNacomConvClass(void);
