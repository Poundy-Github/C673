/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter

  MODULNAME:            sim_conv_head_input_generic.h

  DESCRIPTION:          Convert pre cluster list header

  AUTHOR:               Thomas Berndt

  CREATION DATE:        13.10.2015

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_head_input_generic.h  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:19CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.1 2015/10/13 16:20:33CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/fct/project.pj

**************************************************************************** */
#pragma once
#include "sim_converter_base.h"

IConverter * CreateHeadInputGenericConvInstance(void);
