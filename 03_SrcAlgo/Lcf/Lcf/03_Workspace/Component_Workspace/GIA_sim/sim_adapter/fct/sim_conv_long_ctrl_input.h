/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_long_ctrl_input.h

  DESCRIPTION:          Converter class for AccLeverInput

  AUTHOR:               Gergely Ungvary

  CREATION DATE:        27.10.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_long_ctrl_input.h  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:20CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.1 2014/01/09 15:28:50CET Both, Jens (uidg3187) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.3 2013/05/21 18:04:23CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Modify for ARS4xx 'big' adapter: remove class declarations and complex includes from individual headers (only leaving factory
  CHANGES:              function external declaration there), moving class declaration and all additional includes into cpp file. Add single factory function
  CHANGES:              per data conversion stream.
  CHANGES:              Note: otherwise no functional changes made, thus the new revisions perform the exact same conversions (ARS3xx) as previously
  CHANGES:              --- Added comments ---  ungvaryg [May 21, 2013 6:04:23 PM CEST]
  CHANGES:              Change Package : 172401:1 http://mks-psad:7002/im/viewissue?selection=172401
  CHANGES:              Revision 1.2 2011/11/03 14:23:15CET Ungvary, Gergely (ungvaryg) 
  CHANGES:              Add dummy acc lever version & fix name (FCT simulator uses AccLever as port name)
  CHANGES:              --- Added comments ---  ungvaryg [Nov 3, 2011 2:23:15 PM CET]
  CHANGES:              Change Package : 86065:1 http://mks-psad:7002/im/viewissue?selection=86065
  CHANGES:              Revision 1.1 2011/10/27 17:59:25CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#pragma once

#include "sim_converter_base.h"

extern IConverter * CreateLongCtrlInputConvClass(void);
