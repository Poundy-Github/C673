/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_trackslam.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          2012-01-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_trackslam.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:12CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:56CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:13CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.17 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_trackslam.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_trackslam.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.16 2014/02/06 16:01:09CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:10 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.15 2014/01/24 13:37:55CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:37:55 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.14 2014/01/21 13:09:18CET Manz, Alexander (uidv8777) 
  CHANGE:                 Cosmetic changes:
  CHANGE:                  - replaced pT and pTLB with pTrack
  CHANGE:                  - removed unnecessary PC_SIM parts
  CHANGE:                  - realigned code in various places
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 21, 2014 1:09:18 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.13 2014/01/10 18:33:24CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:25 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.12 2013/12/13 16:44:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:44:43 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.11 2013/11/21 17:53:07CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:08 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.10.1.3 2013/11/21 13:37:24CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Improved Icon normalize
  CHANGE:                 Bug fixes in segmentation
  CHANGE:                 Removed no longer compiler switches
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 1:37:24 PM CET]
  CHANGE:                 Change Package : 207432:1 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.10.1.2 2013/11/19 07:55:09CET Brunn, Marcus (brunnm) 
  CHANGE:                 removed day segmentation
  CHANGE:                 --- Added comments ---  brunnm [Nov 19, 2013 7:55:09 AM CET]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.10.1.1 2013/11/12 13:45:03CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed SegOut from function arguments
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:45:03 PM CET]
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.10 2013/03/11 14:32:45CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Placed no longer needed by RTE ones
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eLightOutput
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 2:32:45 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.9 2012/12/11 16:06:39CET Godreau, Bertrand (uid28828) 
  CHANGE:                 avoid keeping slam features at low speed
  CHANGE:                 --- Added comments ---  uid28828 [Dec 11, 2012 4:06:40 PM CET]
  CHANGE:                 Change Package : 166968:1 http://mks-psad:7002/im/viewissue?selection=166968
  CHANGE:                 Revision 1.8 2012/12/04 17:49:30CET Godreau, Bertrand (uid28828) 
  CHANGE:                 -> Avoid including isPotentialVehicleAhead1st in the SLAM feature list
  CHANGE:                 -> Add a step to make a robust estimate of the essential matrix between two frames using a RANSAC algorithm
  CHANGE:                 -> Integration of Day Segmentation for online calibration
  CHANGE:                 --- Added comments ---  uid28828 [Dec 4, 2012 5:49:32 PM CET]
  CHANGE:                 Change Package : 166968:1 http://mks-psad:7002/im/viewissue?selection=166968
  CHANGE:                 Revision 1.7 2012/10/10 13:02:51CEST Brunn, Marcus (brunnm) 
  CHANGE:                 RAM optimization (Part2)
  CHANGE:                 --- Added comments ---  brunnm [Oct 10, 2012 1:02:51 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.6 2012/10/05 12:46:50CEST Brunn, Marcus (brunnm) 
  CHANGE:                 RAM optimization (part1)
  CHANGE:                 --- Added comments ---  brunnm [Oct 5, 2012 12:46:50 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.5 2012/06/18 15:12:40CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 Activate online cali only during night or when twilight 3.
  CHANGE:                 The deactivation of online-cali is made by reseting all covariances related to online-cali angles.
  CHANGE:                 --- Added comments ---  uid28828 [Jun 18, 2012 3:12:42 PM CEST]
  CHANGE:                 Change Package : 129547:1 http://mks-psad:7002/im/viewissue?selection=129547
  CHANGE:                 Revision 1.4 2012/04/18 17:55:57CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 increase pitch range for tracking to avoid track losses on bumpers
  CHANGE:                 -> remove pitch range Vs speed concept
  CHANGE:                 -> sort SLAM features: update SLAM beginning with the closest light to the prediction, ending with the further one
  CHANGE:                 -> use a wider noise measurement for the isolated lights used in SLAM
  CHANGE:                 --- Added comments ---  uid28828 [Apr 18, 2012 5:55:57 PM CEST]
  CHANGE:                 Change Package : 101881:1 http://mks-psad:7002/im/viewissue?selection=101881
  CHANGE:                 Revision 1.3 2012/04/05 16:54:07CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 -> code review finding fix : use hla roi limits + margin instead of cropped roi limits for killing tracks
  CHANGE:                 -> code review finding fix : init tracking in the HLAR_v_Init() function
  CHANGE:                 
  CHANGE:                 -> clean-up HLAR_v_Init() function
  CHANGE:                 -> clean-up init and updates of cali/camera/camrot/roi in hla_main.c and hla_camera.c
  CHANGE:                 -> remove global variables from hla_camera.c
  CHANGE:                 -> remove HLA_t_CameraParameters hlaCamParam
  CHANGE:                 -> remove useless usage of camRot/camParamInput in tracking
  CHANGE:                 --- Added comments ---  uid28828 [Apr 5, 2012 4:54:07 PM CEST]
  CHANGE:                 Change Package : 101881:1 http://mks-psad:7002/im/viewissue?selection=101881
  CHANGE:                 Revision 1.2 2012/03/12 13:50:27CET Godreau, Bertrand (uid28828) 
  CHANGE:                 -> Rework of dynamic object classification
  CHANGE:                 -> Separate static kalman part from SLAM and static tracker
  CHANGE:                 --- Added comments ---  uid28828 [Mar 12, 2012 1:50:27 PM CET]
  CHANGE:                 Change Package : 94859:1 http://mks-psad:7002/im/viewissue?selection=94859
  CHANGE:                 Revision 1.1 2012/01/25 17:35:57CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_TRACKSLAM_INCLUDED
#define HLA_TRACKSLAM_INCLUDED


#include "hla_trackutils.h"



/*! Type definition for cross-correlations in Cali algo */
typedef struct
{
  /* features cross-correlations */
  TracksCrossCorr_t CrossCorrelations[HLA_TRACKING3D_MAX_NUM_CROSS_CORR];

  /* full egomotion date for limited number of tracks */
  FullEgoData_t     FullEgoData[HLA_TRACKING3D_MAX_NUM_TRACKS_CROSS_CORR];
  FullEgoData_t*    pFullEgoDataBuffer;
  FullEgoData_t*    pFullEgoDataBufferSorted;
  FullEgoData_t*    pFullEgoDataBufferFree;

} HLATracking3DDataCrossCorr_t;



/* init SLAM */
void HLATrackSlamInit(      HLATracking3DDataCali_t*        pDataCali,
                            HLATracking3DDataEgomotion_t*   pDataEgomotion,
                            HLATracking3DDataCrossCorr_t*   pDataCrossCorr,
                            HLATracking3DDataRotations_t*   pDataRotations,
                      const HLATracking3DParametersCali_t*  pParamCali,
                      const HLA_t_SensorSocket*             ps_SensorSocket
                     );

/* predict SLAM */
void HLATrackSlamPredict(       HLATracking3DDataEgomotion_t*   pDataEgomotion,
                                HLATracking3DDataCali_t*        pDataCali,
                                HLATracking3DDataRotations_t*   pDataRotations,
                          const HLATracking3DDataCrossCorr_t*   pDataCrossCorr,
                          const HLA_t_MotionState*              pMotionData,
                          const HLACameraData_t*                pCamData,
                          const HLATracking3DDataPreComputed_t* pDataPreComputed,
                          const RTE_HLAR_BrightnessState        eBrightnessState
                        );

/* update SLAM */
void HLATrackSlamUpdate(      AS_t_GetTimestampuS32                   pfGetTimestampuS32,
                              HLATracking3DDataCali_t*                pDataCali,
                              HLATracking3DDataEgomotion_t*           pDataEgomotion,
                              HLATracking3DDataRotations_t*           pDataRotations,
                              HLADebugOutputs_t*                      phlaDebugOutputs,
                        const HLATracking3DDataCrossCorr_t*           pDataCrossCorr,
                        const HLATracking3DParametersCali_t*          pParamCali,
                        const HLATracking3DDataPreComputed_t*         pDataPreComputed,
                        const HLATracking3DParametersMeasurement_t*   pParamMeas,
                        const HLATracking3DParametersStaticTracker_t* pParamStatic
                       );

/* add function */
void HLATrackSlamAdd(       HLATrack_t*                           pTrackStart,
                            HLATracking3DDataCrossCorr_t*         pDataCrossCorr,
                            uint8*                                pnumTracksCrossCorr,
                      const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                      const HLATracking3DDataCali_t*              pDataCali,
                      const HLATracking3DDataEgomotion_t*         pDataEgomotion,
                      const HLATracking3DDataRotations_t*         pDataRotations,
                      const HLATracking3DParametersMeasurement_t* pParamMeas
                    );

/* remove function */
void HLATrackSlamRemove(HLATracking3DDataCrossCorr_t* pDataCrossCorr,
                        uint8*                        pnumTracksCrossCorr
                       );


/* essential matrix */
void HLATrackSlamEstimateEssentialMatrix(       HLATrack_t*                           pTrackStart,
                                                HLATracking3DDataEgomotion_t*         pDataEgomotion,
                                                HLADebugOutputs_t*                    phlaDebugOutputs,
                                          const HLATracking3DDataRotations_t*         pDataRotations,
                                          const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                                          const HLATracking3DParametersMeasurement_t* pParamMeas,
                                          const HLASegOut_t*                          pSegOut,
                                          AS_t_GetTimestampuS32                       pfGetTimestampuS32
                                         );

/* avoid cyclic binding ---------------------------------------------------*/
#endif
