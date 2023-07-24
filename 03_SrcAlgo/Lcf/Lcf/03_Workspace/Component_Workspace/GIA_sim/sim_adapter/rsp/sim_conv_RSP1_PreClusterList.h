/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter

  MODULNAME:            sim_conv_RSP1_PreClusterList

  DESCRIPTION:          Convert static peak list

  AUTHOR:               Stephan Kaelberer

  CREATION DATE:        28.03.2013

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_RSP1_PreClusterList.h  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:36CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:              Revision 1.1 2013/03/28 15:13:29CET Kaelberer, Stephan (uidu2442) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj
  CHANGES:              Revision 1.1 2013/02/07 13:56:14CET Ungvary, Gergely (ungvaryg) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj

**************************************************************************** */
#pragma once
#include "sim_converter_base.h"

IConverter * CreateRSP1PreClusterListConvClass(void);
