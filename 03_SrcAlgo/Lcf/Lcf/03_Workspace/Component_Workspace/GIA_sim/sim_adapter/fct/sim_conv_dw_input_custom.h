/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_DW_input_custom.h

  DESCRIPTION:          Converter class for AccLeverInput

  AUTHOR:               Teodora Cretu

  CREATION DATE:        21.03.2017

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_dw_input_custom.h  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:14CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.1 2017/03/23 12:05:16CET Cretu, Teodora (CretuT) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/fct/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#pragma once

#include "sim_converter_base.h"

extern IConverter * CreateDWInputCustomConvClass(void);
