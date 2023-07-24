/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_head_input_custom.h

  DESCRIPTION:          

  AUTHOR:               Ovidiu Raicu

  CREATION DATE:        08.06.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_head_input_custom.h  $
  CHANGES:              Revision 1.1 2021/12/13 17:21:03CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:19CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.8 2014/01/24 15:35:48CET Obst, Christian02 (uidv8774) 
  CHANGES:              updated Adapter TypeNaming and
  CHANGES:              using "big Adapter" version of HeadInputCustom
  CHANGES:              - Added comments -  uidv8774 [Jan 24, 2014 3:35:48 PM CET]
  CHANGES:              Change Package : 215077:1 http://mks-psad:7002/im/viewissue?selection=215077
  CHANGES:              Revision 1.7 2013/05/21 18:04:27CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Modify for ARS4xx 'big' adapter: remove class declarations and complex includes from individual headers (only leaving factory
  CHANGES:              function external declaration there), moving class declaration and all additional includes into cpp file. Add single factory function
  CHANGES:              per data conversion stream.
  CHANGES:              Note: otherwise no functional changes made, thus the new revisions perform the exact same conversions (ARS3xx) as previously
  CHANGES:              --- Added comments ---  ungvaryg [May 21, 2013 6:04:27 PM CEST]
  CHANGES:              Change Package : 172401:1 http://mks-psad:7002/im/viewissue?selection=172401
  CHANGES:              Revision 1.6 2012/04/18 14:10:37CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Add head input custom v4b (long live the exponential complexity explosion of interfaces!)
  CHANGES:              --- Added comments ---  ungvaryg [Apr 18, 2012 2:10:37 PM CEST]
  CHANGES:              Change Package : 111577:1 http://mks-psad:7002/im/viewissue?selection=111577
  CHANGES:              Revision 1.5 2012/03/15 09:01:45CET Froehlich, Dominik01 (froehlichd1) 
  CHANGES:              * change: updated adapter to RTE change for FCM inhibit
  CHANGES:              --- Added comments ---  froehlichd1 [Mar 15, 2012 9:01:45 AM CET]
  CHANGES:              Change Package : 102796:3 http://mks-psad:7002/im/viewissue?selection=102796
  CHANGES:              Revision 1.4 2012/02/21 17:46:17CET Diepolder, Thomas (diepoldert) 
  CHANGES:              New adaptations for ars353 version 3 headinputcustom
  CHANGES:              --- Added comments ---  diepoldert [Feb 21, 2012 5:46:17 PM CET]
  CHANGES:              Change Package : 97173:1 http://mks-psad:7002/im/viewissue?selection=97173
  CHANGES:              Revision 1.3 2012/01/19 10:08:25CET Froehlich, Dominik01 (froehlichd1) 
  CHANGES:              * change: support of HEADInputCustom interface changes
  CHANGES:              --- Added comments ---  froehlichd1 [Jan 19, 2012 10:08:26 AM CET]
  CHANGES:              Change Package : 30337:8 http://mks-psad:7002/im/viewissue?selection=30337
  CHANGES:              Revision 1.2 2011/03/02 16:32:57CET Diepolder Thomas (diepoldert) (diepoldert) 
  CHANGES:              Scope corrected
  CHANGES:              --- Added comments ---  diepoldert [Mar 2, 2011 4:32:58 PM CET]
  CHANGES:              Change Package : 59660:2 http://mks-psad:7002/im/viewissue?selection=59660
  CHANGES:              Revision 1.1 2011/03/02 13:49:05CET Thomas Diepolder (diepoldert) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj
 
**************************************************************************** */

/* includes ---------------------------------------------------------------- */
#pragma once

#include "sim_converter_base.h"

extern IConverter * CreateHeadInputCustomConvInstance(void);
