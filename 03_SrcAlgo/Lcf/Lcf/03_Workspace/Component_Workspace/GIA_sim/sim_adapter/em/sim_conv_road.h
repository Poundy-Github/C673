/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_road.h

  DESCRIPTION:          Converter class for Road

  AUTHOR:               Teodora Cretu

  CREATION DATE:        13.01.2017

  VERSION:              $$

  ---*/ /*---
  CHANGES:              $Log: sim_conv_road.h  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:09CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/em/project.pj
  CHANGES:              Revision 1.1 2017/01/13 13:32:15CET Cretu, Teodora (CretuT) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/em/project.pj


**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#pragma once

#include "sim_converter_base.h"

extern IConverter * CreateRoadConvInstance(void);
