/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_trackdynamic.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          2012-01-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_trackdynamic.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:08CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:49CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:09CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.12 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_trackdynamic.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_trackdynamic.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.11 2014/01/24 13:37:47CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:37:47 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.10 2014/01/21 13:09:11CET Manz, Alexander (uidv8777) 
  CHANGE:                 Cosmetic changes:
  CHANGE:                  - replaced pT and pTLB with pTrack
  CHANGE:                  - removed unnecessary PC_SIM parts
  CHANGE:                  - realigned code in various places
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 21, 2014 1:09:12 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.9 2014/01/10 18:34:01CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:34:02 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.8 2013/11/21 17:53:26CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:27 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.7.1.2 2013/11/21 14:15:28CET Manz, Alexander (uidv8777) 
  CHANGE:                 Fix: 
  CHANGE:                  - slightly changed parameter to reenable a somehow stable pair tracking
  CHANGE:                  - region selection for tracking fixed
  CHANGE:                  - minor bug in pseudo census code generation fixed
  CHANGE:                 Updates:
  CHANGE:                  - some minor cosmetic changes in tracking files
  CHANGE:                  - implemented additional visualizations for tracking (esp. pairs) and calibration
  CHANGE:                 --- Added comments ---  uidv8777 [Nov 21, 2013 2:15:28 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.7.1.1 2013/11/12 13:45:04CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed SegOut from function arguments
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:45:04 PM CET]
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.7 2013/08/02 15:25:55CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Change: changed the name of HLATargetVehicle_t to HLAPair_t for better understanding
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 2, 2013 3:25:55 PM CEST]
  CHANGE:                 Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
  CHANGE:                 Revision 1.6 2012/10/10 13:03:04CEST Brunn, Marcus (brunnm) 
  CHANGE:                 RAM optimization (Part2)
  CHANGE:                 --- Added comments ---  brunnm [Oct 10, 2012 1:03:04 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.5 2012/04/11 17:15:00CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 code review finding fix (no changes in perf): 
  CHANGE:                 split HLATrackMeasGetMeasurementExt() into smaller functions (access to light position)
  CHANGE:                   -> split corresponding structure into smaller structs
  CHANGE:                   -> affects tracking, pairs and icon functions
  CHANGE:                 --- Added comments ---  uid28828 [Apr 11, 2012 5:15:01 PM CEST]
  CHANGE:                 Change Package : 110195:1 http://mks-psad:7002/im/viewissue?selection=110195
  CHANGE:                 Revision 1.4 2012/02/24 16:34:58CET Godreau, Bertrand (uid28828) 
  CHANGE:                 -> Bugfixes pair tracker/rockets/track losses
  CHANGE:                 -> Tuning pair tracker
  CHANGE:                 --- Added comments ---  uid28828 [Feb 24, 2012 4:34:58 PM CET]
  CHANGE:                 Change Package : 94857:1 http://mks-psad:7002/im/viewissue?selection=94857
  CHANGE:                 Revision 1.3 2012/02/16 16:47:01CET Godreau, Bertrand (uid28828) 
  CHANGE:                 -> clean-up kalman dynamic update
  CHANGE:                 -> bugfix dynamic kalman state/track reprojection when unstable dynamic tracker (bad RMSE, failed kalman update, ...)
  CHANGE:                 -> reinit dynamic kalman only if light is the best assoc to the track
  CHANGE:                 -> move Pair reprojection analysis in Pair kalman update
  CHANGE:                 --- Added comments ---  uid28828 [Feb 16, 2012 4:47:01 PM CET]
  CHANGE:                 Change Package : 94862:1 http://mks-psad:7002/im/viewissue?selection=94862
  CHANGE:                 Revision 1.2 2012/02/10 14:02:28CET Godreau, Bertrand (uid28828) 
  CHANGE:                 clean HLATrackDynamicUpdate
  CHANGE:                 merge HLATrackDynamicKalmanPredictOrUpdate and HLATrackDynamicKalmanDelayedUpdate 
  CHANGE:                 remove some useless use of expf()
  CHANGE:                 --- Added comments ---  uid28828 [Feb 10, 2012 2:02:29 PM CET]
  CHANGE:                 Change Package : 94862:1 http://mks-psad:7002/im/viewissue?selection=94862
  CHANGE:                 Revision 1.1 2012/01/25 17:34:40CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_TRACKDYNAMIC_INCLUDED
#define HLA_TRACKDYNAMIC_INCLUDED

#include "hla_trackutils.h"


/* predict */
void HLATrackDynamicPredict(      HLATrack_t*                         pTrackStart,
                            const HLATracking3DDataEgomotion_t*       pDataEgomotion,
                            const HLATracking3DDataRotations_t*       pDataRotations,
                            const HLATracking3DDataPreComputed_t*     pDataPreComputed,
                            const HLATracking3DParametersMatching_t*  pParamMatching
                           );

void HLATrackDynamicPredictNextCycle(       HLATrack_t*                   pTrackStart,
                                      const HLATracking3DDataRotations_t* pDataRotations,
                                      const HLATracking3DDataEgomotion_t* pDataEgomotion
                                    );

/* update */
void HLATrackDynamicKalmanUpdate(       HLATrack_t*                     pTrack,
                                  const HLAKalmanMeasPos_t*             pLNorm,
                                  const HLATracking3DDataEgomotion_t*   pDataEgomotion,
                                  const HLATracking3DDataRotations_t*   pDataRotations,
                                  const HLATracking3DDataPreComputed_t* pDataPreComputed
#ifdef PC_SIM
                                 , const HLATracking3DParametersDynamicTracker_t* pParamDynamic
#endif
                                );

/* kalman init function */
void HLATrackDynamicKalmanInit(       HLATrack_t*                     pTrack,
                                const HLAKalmanMeasPos_t*             pLNorm,
                                const HLATracking3DDataPreComputed_t* pDataPreComputed,
                                const HLATracking3DDataRotations_t*   pDataRotations
                              );

/* kalman init function from pair distance measurement */
void HLATrackDynamicKalmanInitFromPair(       HLATrack_t*                           pTrack,
                                        const HLAPair_t*                            pP,
                                        const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                        const HLATracking3DDataRotations_t*         pDataRotations,
                                        const HLATracking3DParametersMeasurement_t* pParamMeas
                                      );


/* avoid cyclic binding ---------------------------------------------------*/
#endif
