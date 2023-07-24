/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_conv_veh_dyn.h

  DESCRIPTION:          

  AUTHOR:               Ovidiu Raicu

  CREATION DATE:        25.11.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_bswalgo_param.h  $
  CHANGES:              Revision 1.1 2021/12/13 17:20:56CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:11CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/fct/project.pj
  CHANGES:              Revision 1.8 2013/06/26 10:03:07CEST ungvaryg 
  CHANGES:              ARS4xx BSW_s_AlgoParameters conversion class implementation
  CHANGES:              NOTE: Not compatible with previous versions only support for ARS400 BSW_s_AlgoParameters versions implemented!
  CHANGES:              (As support for older layouts no longer needed for ARS400 measurements)
  CHANGES:              - Added comments -  ungvaryg [Jun 26, 2013 10:03:07 AM CEST]
  CHANGES:              Change Package : 179559:3 http://mks-psad:7002/im/viewissue?selection=179559
  CHANGES:              Revision 1.7 2012/04/26 13:49:38CEST Mogos, Sorin (mogoss) 
  CHANGES:              * update: added conversion from current version to old versions of BSWAlgoParameter_t
  CHANGES:              --- Added comments ---  mogoss [Apr 26, 2012 1:49:40 PM CEST]
  CHANGES:              Change Package : 104778:1 http://mks-psad:7002/im/viewissue?selection=104778
  CHANGES:              Revision 1.6 2012/04/17 09:00:58CEST Mogos, Sorin (mogoss) 
  CHANGES:              * update: added conversion for new version of BSW_s_AlgoParameters_t
  CHANGES:              --- Added comments ---  mogoss [Apr 17, 2012 9:01:00 AM CEST]
  CHANGES:              Change Package : 104217:1 http://mks-psad:7002/im/viewissue?selection=104217
  CHANGES:              Revision 1.5 2011/09/01 13:29:20CEST Raicu, Ovidiu (RaicuO) 
  CHANGES:              Updated for new version of rte.h .
  CHANGES:              --- Added comments ---  RaicuO [Sep 1, 2011 1:29:20 PM CEST]
  CHANGES:              Change Package : 76905:1 http://mks-psad:7002/im/viewissue?selection=76905
  CHANGES:              Revision 1.4 2011/05/03 12:36:42CEST Ovidiu Raicu (RaicuO) 
  CHANGES:              Updated to new rte version.
  CHANGES:              --- Added comments ---  RaicuO [May 3, 2011 12:36:42 PM CEST]
  CHANGES:              Change Package : 62743:1 http://mks-psad:7002/im/viewissue?selection=62743
  CHANGES:              Revision 1.3 2011/04/14 11:37:00CEST Ovidiu Raicu (RaicuO) 
  CHANGES:              Updated with new conversion for BSW_s_AlgoParameters.
  CHANGES:              --- Added comments ---  RaicuO [Apr 14, 2011 11:37:00 AM CEST]
  CHANGES:              Change Package : 58958:1 http://mks-psad:7002/im/viewissue?selection=58958
  CHANGES:              Revision 1.2 2011/04/11 12:05:44CEST Ovidiu Raicu (RaicuO) 
  CHANGES:              Updated BSW_s_AlgoParameters conversion to new version.
  CHANGES:              --- Added comments ---  RaicuO [Apr 11, 2011 12:05:44 PM CEST]
  CHANGES:              Change Package : 58958:1 http://mks-psad:7002/im/viewissue?selection=58958
  CHANGES:              Revision 1.1 2010/11/25 08:45:48CET Ovidiu Raicu (RaicuO) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#pragma once
#include "sim_converter_base.h"

extern IConverter * CreateBswAlgoParamConverter(void);

