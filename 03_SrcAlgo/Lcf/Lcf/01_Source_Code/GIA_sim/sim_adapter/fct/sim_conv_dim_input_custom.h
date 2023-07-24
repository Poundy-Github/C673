/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_dim_input_custom.h

  DESCRIPTION:          

  AUTHOR:               Ovidiu Raicu

  CREATION DATE:        08.06.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_dim_input_custom.h  $
  CHANGES:              Revision 1.1 2021/12/13 17:20:57CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:13CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.6 2013/05/21 18:04:24CEST ungvaryg 
  CHANGES:              Modify for ARS4xx 'big' adapter: remove class declarations and complex includes from individual headers (only leaving factory
  CHANGES:              function external declaration there), moving class declaration and all additional includes into cpp file. Add single factory function
  CHANGES:              per data conversion stream.
  CHANGES:              Note: otherwise no functional changes made, thus the new revisions perform the exact same conversions (ARS3xx) as previously
  CHANGES:              - Added comments -  ungvaryg [May 21, 2013 6:04:25 PM CEST]
  CHANGES:              Change Package : 172401:1 http://mks-psad:7002/im/viewissue?selection=172401
  CHANGES:              Revision 1.5 2013/02/15 10:40:14CET Diepolder, Thomas (diepoldert) 
  CHANGES:              Use effective front axle steer angle as addtional custom input for dim (degradation due to multiturn loss)
  CHANGES:              --- Added comments ---  diepoldert [Feb 15, 2013 10:40:15 AM CET]
  CHANGES:              Change Package : 175279:1 http://mks-psad:7002/im/viewissue?selection=175279
  CHANGES:              Revision 1.4 2011/10/17 18:27:23CEST Diepolder Thomas (diepoldert) (diepoldert) 
  CHANGES:              Update simulation adapters to handle new rte interfaces
  CHANGES:              Revision 1.3 2011/05/10 14:31:15CEST Diepolder Thomas (diepoldert) (diepoldert) 
  CHANGES:              Conversions for newest version of port
  CHANGES:              --- Added comments ---  diepoldert [May 10, 2011 2:31:16 PM CEST]
  CHANGES:              Change Package : 65322:1 http://mks-psad:7002/im/viewissue?selection=65322
  CHANGES:              Revision 1.2 2011/04/13 19:11:57CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Remove direct include of algo_type.h
  CHANGES:              --- Added comments ---  ungvaryg [Apr 13, 2011 7:11:57 PM CEST]
  CHANGES:              Change Package : 63692:1 http://mks-psad:7002/im/viewissue?selection=63692
  CHANGES:              Revision 1.1 2011/03/02 13:48:47CET Thomas Diepolder (diepoldert) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj
 
**************************************************************************** */

/* includes ---------------------------------------------------------------- */
#pragma once

#include "sim_converter_base.h"

extern IConverter * CreateDimInputCustomConvInstance(void);
