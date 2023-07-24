/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_adapter_fct.h

  DESCRIPTION:          

  AUTHOR:               Ovidiu Raicu

  CREATION DATE:        23.03.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_adapter_main.h  $
  CHANGES:              Revision 1.1 2021/12/13 17:20:12CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:14:45CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/project.pj
  CHANGES:              Revision 1.1 2013/02/07 13:55:59CET ungvaryg 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/project.pj
  CHANGES:              Revision 1.9 2012/01/16 09:35:33CET Apel, Norman (apeln) 
  CHANGES:              add new Port for SimInit of CPTrajState
  CHANGES:              --- Added comments ---  apeln [Jan 16, 2012 9:35:34 AM CET]
  CHANGES:              Change Package : 93699:1 http://mks-psad:7002/im/viewissue?selection=93699
  CHANGES:              Revision 1.8 2011/06/27 12:00:01CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Add ALN_S_Monitoring_t conversion class implementation
  CHANGES:              --- Added comments ---  ungvaryg [Jun 27, 2011 12:00:01 PM CEST]
  CHANGES:              Change Package : 69654:1 http://mks-psad:7002/im/viewissue?selection=69654
  CHANGES:              Revision 1.7 2011/04/13 18:00:56CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Add support for adapter class for BSW algo parameters
  CHANGES:              --- Added comments ---  ungvaryg [Apr 13, 2011 6:00:57 PM CEST]
  CHANGES:              Change Package : 63692:1 http://mks-psad:7002/im/viewissue?selection=63692
  CHANGES:              Revision 1.6 2011/03/22 09:51:49CET Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Add factory function for ME input data
  CHANGES:              --- Added comments ---  ungvaryg [Mar 22, 2011 9:51:50 AM CET]
  CHANGES:              Change Package : 59359:3 http://mks-psad:7002/im/viewissue?selection=59359
  CHANGES:              Revision 1.5 2011/03/02 16:44:05CET Thomas Diepolder (diepoldert) 
  CHANGES:              "head input custom" and "dim_input_custom" interface added
  CHANGES:              --- Added comments ---  diepoldert [Mar 2, 2011 4:44:05 PM CET]
  CHANGES:              Change Package : 59660:2 http://mks-psad:7002/im/viewissue?selection=59660
  CHANGES:              Revision 1.4 2010/10/08 12:44:34CEST Gergely Ungvary (ungvaryg) 
  CHANGES:              Add factory methods for each conversion class
  CHANGES:              --- Added comments ---  ungvaryg [Oct 8, 2010 12:44:34 PM CEST]
  CHANGES:              Change Package : 48401:1 http://mks-psad:7002/im/viewissue?selection=48401
  CHANGES:              Revision 1.3 2010/07/23 13:53:30CEST Mihai Anghel (anghelm) 
  CHANGES:              created converter for "EM_COD_Output" and "EM_CLD_Output"
  CHANGES:              --- Added comments ---  AnghelM [Jul 23, 2010 1:53:30 PM CEST]
  CHANGES:              Change Package : 47849:1 http://mks-psad:7002/im/viewissue?selection=47849
  CHANGES:              Revision 1.2 2010/06/16 15:36:50CEST gungvary 
  CHANGES:              Add FCTCustomInput conversion adapter & a map for looking up names to factory functions for conversion classes
  CHANGES:              --- Added comments ---  gungvary [2010/06/16 13:36:50Z]
  CHANGES:              Change Package : 39685:3 http://LISS014:6001/im/viewissue?selection=39685
  CHANGES:              Revision 1.1 2010/03/26 09:56:44CET Ovidiu Raicu (oraicu) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#pragma once

/* includes ---------------------------------------------------------------- */
#include <map>
#include "sim_adapter_base.h"

/* main class -------------------------------------------------------------- */
class CSimAdapterMain : public CSimAdapterBase
{
  // Internal factory class, only visible within class to only have
  // to modify single source when new additional data stream adaptation
  // added (i.e.: the CSimAdapterMain class declaration does not need
  // to change)
  class __CSimAdapterFactory;
  static __CSimAdapterFactory m_InternFactory;

public:
  CSimAdapterMain(void);
  ~CSimAdapterMain(void);

protected:
  // Create Converters here dynamicaly using new operator
  // they will be deleted automaticaly on InternalFinalDestruct
  IConverter* CreateConverterInstance(const char* szTypeName);
};

