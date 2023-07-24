/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter

  MODULNAME:            sim_conv_fct_cam_lane_input_data.h

  DESCRIPTION:          Conversion module

  AUTHOR:               Thomas Berndt

  CREATION DATE:        14.01.2016

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_fct_cam_lane_input_data.h  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:15CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.1 2016/03/29 07:04:25CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/fct/project.pj

**************************************************************************** */
#pragma once
#include "sim_converter_base.h"

IConverter * CreateFctCamLaneInputDataConvInstance(void);
