/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_fct_custom_input.h

  DESCRIPTION:          

  AUTHOR:               Gergely Ungvary

  CREATION DATE:        16.06.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_fct_custom_input.h  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:16CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.7 2013/05/21 18:04:26CEST ungvaryg 
  CHANGES:              Modify for ARS4xx 'big' adapter: remove class declarations and complex includes from individual headers (only leaving factory
  CHANGES:              function external declaration there), moving class declaration and all additional includes into cpp file. Add single factory function
  CHANGES:              per data conversion stream.
  CHANGES:              Note: otherwise no functional changes made, thus the new revisions perform the exact same conversions (ARS3xx) as previously
  CHANGES:              - Added comments -  ungvaryg [May 21, 2013 6:04:27 PM CEST]
  CHANGES:              Change Package : 172401:1 http://mks-psad:7002/im/viewissue?selection=172401
  CHANGES:              Revision 1.6 2012/06/25 14:14:36CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Add support for version 6 of FCT custom input (addition of Eco-pro flag to FCT custom input)
  CHANGES:              --- Added comments ---  ungvaryg [Jun 25, 2012 2:14:36 PM CEST]
  CHANGES:              Change Package : 125668:1 http://mks-psad:7002/im/viewissue?selection=125668
  CHANGES:              Revision 1.5 2012/04/11 10:43:32CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Added versions 4 and 5 of FCT_CUSTOM_INPUT_INTFVER, which are identical to versions 2 and 3
  CHANGES:              --- Added comments ---  berndtt1 [Apr 11, 2012 12:13:39 PM CEST]
  CHANGES:              Change Package : 105371:5 http://mks-psad:7002/im/viewissue?selection=105371
  CHANGES:              Revision 1.4 2012/02/16 15:21:07CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + version 3 (same as version 2)
  CHANGES:              --- Added comments ---  berndtt1 [Feb 16, 2012 4:44:27 PM CET]
  CHANGES:              Change Package : 97762:2 http://mks-psad:7002/im/viewissue?selection=97762
  CHANGES:              Revision 1.3 2011/02/28 15:48:35CET Ungvary, Gergely (ungvaryg) 
  CHANGES:              Update to allow conversion version 1 and 2 of FCTCustomInput
  CHANGES:              --- Added comments ---  ungvaryg [Feb 28, 2011 3:48:36 PM CET]
  CHANGES:              Change Package : 59406:1 http://mks-psad:7002/im/viewissue?selection=59406
  CHANGES:              Revision 1.2 2011/02/14 18:06:15CET Gergely Ungvary (ungvaryg) 
  CHANGES:              Remove dependence on CDataBuffer class - replace with object member buffer directly of given type
  CHANGES:              Revision 1.1 2010/06/16 15:35:57CEST gungvary 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#pragma once

#include "sim_converter_base.h"

extern IConverter * CreateFctCustomInputConvInstance(void);
