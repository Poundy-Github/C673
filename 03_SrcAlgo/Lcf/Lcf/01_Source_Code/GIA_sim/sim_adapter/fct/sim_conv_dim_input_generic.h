/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_dim_input_generic.h

  DESCRIPTION:          

  AUTHOR:               Ovidiu Raicu

  CREATION DATE:        08.06.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_dim_input_generic.h  $
  CHANGES:              Revision 1.1 2021/12/13 17:20:57CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:14CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.8 2013/05/21 18:04:25CEST ungvaryg 
  CHANGES:              Modify for ARS4xx 'big' adapter: remove class declarations and complex includes from individual headers (only leaving factory
  CHANGES:              function external declaration there), moving class declaration and all additional includes into cpp file. Add single factory function
  CHANGES:              per data conversion stream.
  CHANGES:              Note: otherwise no functional changes made, thus the new revisions perform the exact same conversions (ARS3xx) as previously
  CHANGES:              - Added comments -  ungvaryg [May 21, 2013 6:04:26 PM CEST]
  CHANGES:              Change Package : 172401:1 http://mks-psad:7002/im/viewissue?selection=172401
  CHANGES:              Revision 1.7 2011/10/17 18:27:21CEST Diepolder, Thomas (diepoldert) 
  CHANGES:              Update simulation adapters to handle new rte interfaces
  CHANGES:              --- Added comments ---  diepoldert [Oct 17, 2011 6:27:22 PM CEST]
  CHANGES:              Change Package : 84108:1 http://mks-psad:7002/im/viewissue?selection=84108
  CHANGES:              Revision 1.6 2011/09/14 12:45:21CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Fix misleading names of versioning namespaces (version2 was actually version1)
  CHANGES:              Add support for real version 2
  CHANGES:              --- Added comments ---  ungvaryg [Sep 14, 2011 12:45:21 PM CEST]
  CHANGES:              Change Package : 74571:3 http://mks-psad:7002/im/viewissue?selection=74571
  CHANGES:              Revision 1.5 2011/04/13 19:11:29CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Remove direct include of algo_type.h
  CHANGES:              --- Added comments ---  ungvaryg [Apr 13, 2011 7:11:29 PM CEST]
  CHANGES:              Change Package : 63692:1 http://mks-psad:7002/im/viewissue?selection=63692
  CHANGES:              Revision 1.4 2011/03/02 16:42:35CET Thomas Diepolder (diepoldert) 
  CHANGES:              Repaired compatiblilty for old recordings (ARS301, containing 28 byte block size), currently ARS300 (same size = 28) recordings are not supported
  CHANGES:              --- Added comments ---  diepoldert [Mar 2, 2011 4:42:35 PM CET]
  CHANGES:              Change Package : 59660:2 http://mks-psad:7002/im/viewissue?selection=59660
  CHANGES:              Revision 1.3 2011/02/04 14:53:34CET Thomas Diepolder (diepoldert) 
  CHANGES:              Allow connection of DIMInputGeneric port
  CHANGES:              --- Added comments ---  diepoldert [Feb 4, 2011 2:53:34 PM CET]
  CHANGES:              Change Package : 58833:1 http://mks-psad:7002/im/viewissue?selection=58833
  CHANGES:              Revision 1.2 2010/06/16 16:47:36CEST rthiel 
  CHANGES:              added 24 byte long struct type for driver inputs
  CHANGES:              --- Added comments ---  rthiel [2010/06/16 14:47:36Z]
  CHANGES:              Change Package : 19018:5 http://LISS014:6001/im/viewissue?selection=19018
  CHANGES:              Revision 1.1 2010/06/09 08:13:51CEST Ovidiu Raicu (oraicu) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj
 
**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#pragma once

#include "sim_converter_base.h"

extern IConverter * CreateDimInputGenericConvInstance(void);

