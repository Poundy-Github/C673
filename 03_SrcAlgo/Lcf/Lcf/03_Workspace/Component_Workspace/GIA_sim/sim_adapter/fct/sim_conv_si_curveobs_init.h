/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapt_fct

  MODULNAME:            sim_conv_si_curveobs_init.h

  DESCRIPTION:          Adapter for initialization data

  AUTHOR:               Gergely Ungvary

  CREATION DATE:        08.10.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_si_curveobs_init.h  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:22CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.2 2013/06/19 16:54:19CEST ungvaryg 
  CHANGES:              Streamline header file (move conversion class declaration to cpp source, leaving only factory method here)
  CHANGES:              Remove dependency on fct_init.h (layout of CP/SI Init structure now local in Cpp source)
  CHANGES:              - Added comments -  ungvaryg [Jun 19, 2013 4:54:19 PM CEST]
  CHANGES:              Change Package : 179559:3 http://mks-psad:7002/im/viewissue?selection=179559
  CHANGES:              Revision 1.1 2010/10/08 12:40:11CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#pragma once

#include "sim_converter_base.h"

extern IConverter * CreateSICuveObsInitConvInstance(void);
