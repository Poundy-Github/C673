/*! \file **********************************************************************

  COMPONENT:              RTE_SIM

  MODULENAME:             rte.h

  @brief                  This file contains the RTE declarations for simulation

  ---*/ /*---

  CHANGES
  ---------------

  VERSIONNUMBER:          $Revision: 1.1 $

  EDITOR NAME:            $Author: Dinu, Marius (DinuM) $
  
  CHANGES:                $Log: rte.h  $
  CHANGES:                Revision 1.1 2016/09/09 10:27:33CEST Dinu, Marius (DinuM) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Tools/Validation_Tools/Lib_Libraries/SIM_SimulationFramework/05_Software/04_Engineering/01_Source_Code/includes/simulation/plugin_ifc/sim_rte/project.pj
  CHANGES:                Revision 1.1 2016/07/27 15:53:27CEST Dinu, Marius (DinuM) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SIM_SimulationTool/04_Engineering/20_Include/sim_rte/project.pj
  CHANGES:                Revision 1.3 2015/02/03 11:39:30CET Bagot, Benoit (uidg7670) 
  CHANGES:                added Macro "PACKED"
  CHANGES:                --- Added comments ---  uidg7670 [Feb 3, 2015 11:39:31 AM CET]
  CHANGES:                Change Package : 301818:1 http://mks-psad:7002/im/viewissue?selection=301818
  CHANGES:                Revision 1.2 2011/06/27 13:20:34CEST Spruck, Jochen (spruckj) 
  CHANGES:                Add some defines used by the sw rte
  CHANGES:                --- Added comments ---  spruckj [Jun 27, 2011 1:20:34 PM CEST]
  CHANGES:                Change Package : 46866:8 http://mks-psad:7002/im/viewissue?selection=46866
  CHANGES:                Revision 1.1 2010/02/15 11:15:41CET gungvary 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/EM_EnvironmentModel/04_Engineering/01_Source_Code/rte_sim/project.pj

*****************************************************************************/
#ifndef RTE_H
#define RTE_H

#include "Std_Types.h"    /* [Satisfies_rte sws 1164] */

#define IN
#define OUT
#define INOUT
#define PACKED   

/* [PLATFORM54], [PLATFORM55], [PLATFORM56] */
/* MISRA-C:2004 19.4 VIOLATION: Refer to REF 1 above */
#ifndef TRUE
    #define TRUE ((boolean) 1)
#endif

#ifndef FALSE
    #define FALSE ((boolean) 0)
#endif

#endif
