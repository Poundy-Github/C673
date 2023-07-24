/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_trackstatic.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          2012-01-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_trackstatic.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:12CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:57CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:14CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.8 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_trackstatic.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_trackstatic.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.7 2014/01/24 13:37:56CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:37:57 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.6 2014/01/21 13:09:20CET Manz, Alexander (uidv8777) 
  CHANGE:                 Cosmetic changes:
  CHANGE:                  - replaced pT and pTLB with pTrack
  CHANGE:                  - removed unnecessary PC_SIM parts
  CHANGE:                  - realigned code in various places
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 21, 2014 1:09:20 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.5 2014/01/10 18:33:47CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:47 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.4 2012/04/11 17:14:32CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 code review finding fix (no changes in perf): 
  CHANGE:                 split HLATrackMeasGetMeasurementExt() into smaller functions (access to light position)
  CHANGE:                   -> split corresponding structure into smaller structs
  CHANGE:                   -> affects tracking, pairs and icon functions
  CHANGE:                 --- Added comments ---  uid28828 [Apr 11, 2012 5:14:33 PM CEST]
  CHANGE:                 Change Package : 110195:1 http://mks-psad:7002/im/viewissue?selection=110195
  CHANGE:                 Revision 1.3 2012/03/12 13:50:26CET Godreau, Bertrand (uid28828) 
  CHANGE:                 -> Rework of dynamic object classification
  CHANGE:                 -> Separate static kalman part from SLAM and static tracker
  CHANGE:                 --- Added comments ---  uid28828 [Mar 12, 2012 1:50:26 PM CET]
  CHANGE:                 Change Package : 94859:1 http://mks-psad:7002/im/viewissue?selection=94859
  CHANGE:                 Revision 1.2 2012/02/20 15:07:48CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Finish restucturing of tracking algo
  CHANGE:                 --- Added comments ---  uid28828 [Feb 20, 2012 3:07:48 PM CET]
  CHANGE:                 Change Package : 94862:1 http://mks-psad:7002/im/viewissue?selection=94862
  CHANGE:                 Revision 1.1 2012/01/25 17:36:15CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_TRACKSTATIC_INCLUDED
#define HLA_TRACKSTATIC_INCLUDED

#include "hla_trackutils.h"


/* update static tracker */
void HLATrackStaticKalmanUpdate(      HLATrack_t*                             pTrack,
                                const HLAKalmanMeasPos_t*                     pLNorm,
                                const HLATracking3DDataEgomotion_t*           pDataEgomotion,
                                const HLATracking3DDataRotations_t*           pDataRotations,
                                const HLATracking3DDataPreComputed_t*         pDataPreComputed,
                                const HLATracking3DParametersStaticTracker_t* pParamStatic
                               );

/* init kalman static tracker */
void HLATrackStaticKalmanInit(      HLATrack_t*                     pTrack,
                              const HLAKalmanMeasPos_t*             pLNorm,
                              const HLATracking3DDataPreComputed_t* pDataPreComputed,
                              const HLATracking3DDataRotations_t*   pDataRotations
                             );

/* avoid cyclic binding ---------------------------------------------------*/
#endif
