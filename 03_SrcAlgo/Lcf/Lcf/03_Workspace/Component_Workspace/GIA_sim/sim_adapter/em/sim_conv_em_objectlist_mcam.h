/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter em

  MODULNAME:       sim_conv_em_objectlist_mcam.h

  DESCRIPTION:     Converter for MFC4T0 MCAM object list

  AUTHOR:          Gergely Ungvary

  CREATION DATE:   24.04.2014

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_em_objectlist_mcam.h  $
  CHANGES:         Revision 1.1 2017/08/10 13:15:07CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/em/project.pj
  CHANGES:         Revision 1.1 2014/04/24 18:59:52CEST ungvaryg 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/em/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#pragma once
#include "sim_converter_base.h"

extern IConverter * CreateEmObjectListMcamConvClass(void);

