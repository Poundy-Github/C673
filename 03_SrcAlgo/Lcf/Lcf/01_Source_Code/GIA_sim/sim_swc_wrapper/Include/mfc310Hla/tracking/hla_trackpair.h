/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_trackpair.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          2012-01-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_trackpair.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:28:11CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:54CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:12CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/tracking/project.pj
  CHANGE:                 Revision 1.18 2014/03/25 18:44:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_trackpair.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_trackpair.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/tracking/project.pj.
  CHANGE:                 Revision 1.17 2014/03/04 16:52:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:13 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.16 2014/02/21 16:54:44CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update: Changed "Vehicle" to "Pair" for better understandability in macro name
  CHANGE:                 --- Added comments ---  uidv8777 [Feb 21, 2014 4:54:44 PM CET]
  CHANGE:                 Change Package : 207634:3 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.15 2014/02/06 16:01:24CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:25 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.14 2014/01/24 13:37:53CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:37:53 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.13 2014/01/21 13:09:16CET Manz, Alexander (uidv8777) 
  CHANGE:                 Cosmetic changes:
  CHANGE:                  - replaced pT and pTLB with pTrack
  CHANGE:                  - removed unnecessary PC_SIM parts
  CHANGE:                  - realigned code in various places
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 21, 2014 1:09:17 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.12 2014/01/10 18:33:56CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:57 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.11 2013/12/18 15:18:07CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 introduction of new HighwayOncomingTruckLight detection
  CHANGE:                 --- Added comments ---  uidv8776 [Dec 18, 2013 3:18:07 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.10 2013/12/13 16:44:50CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:44:50 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.9 2013/11/21 17:53:18CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:18 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.8.1.1 2013/11/12 13:45:01CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed SegOut from function arguments
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:45:01 PM CET]
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.8 2013/08/02 15:26:00CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Change: changed the name of HLATargetVehicle_t to HLAPair_t for better understanding
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 2, 2013 3:26:00 PM CEST]
  CHANGE:                 Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
  CHANGE:                 Revision 1.7 2012/10/18 17:56:02CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - allocation of array memory by array macro in order to realize a dedicated array boundary check mode
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 18, 2012 5:56:02 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.6 2012/10/05 12:46:49CEST Brunn, Marcus (brunnm) 
  CHANGE:                 RAM optimization (part1)
  CHANGE:                 --- Added comments ---  brunnm [Oct 5, 2012 12:46:49 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.5 2012/04/19 20:02:05CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 integrate ttb18 for each track: time to border for a 18° angle
  CHANGE:                 ttb18 calculations are based on 3D estimations
  CHANGE:                 --- Added comments ---  uid28828 [Apr 19, 2012 8:02:06 PM CEST]
  CHANGE:                 Change Package : 101881:1 http://mks-psad:7002/im/viewissue?selection=101881
  CHANGE:                 Revision 1.4 2012/02/24 16:34:59CET Godreau, Bertrand (uid28828) 
  CHANGE:                 -> Bugfixes pair tracker/rockets/track losses
  CHANGE:                 -> Tuning pair tracker
  CHANGE:                 --- Added comments ---  uid28828 [Feb 24, 2012 4:34:59 PM CET]
  CHANGE:                 Change Package : 94857:1 http://mks-psad:7002/im/viewissue?selection=94857
  CHANGE:                 Revision 1.3 2012/02/20 15:07:49CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Finish restucturing of tracking algo
  CHANGE:                 --- Added comments ---  uid28828 [Feb 20, 2012 3:07:49 PM CET]
  CHANGE:                 Change Package : 94862:1 http://mks-psad:7002/im/viewissue?selection=94862
  CHANGE:                 Revision 1.2 2012/02/16 16:47:06CET Godreau, Bertrand (uid28828) 
  CHANGE:                 -> clean-up kalman dynamic update
  CHANGE:                 -> bugfix dynamic kalman state/track reprojection when unstable dynamic tracker (bad RMSE, failed kalman update, ...)
  CHANGE:                 -> reinit dynamic kalman only if light is the best assoc to the track
  CHANGE:                 -> move Pair reprojection analysis in Pair kalman update
  CHANGE:                 --- Added comments ---  uid28828 [Feb 16, 2012 4:47:07 PM CET]
  CHANGE:                 Change Package : 94862:1 http://mks-psad:7002/im/viewissue?selection=94862
  CHANGE:                 Revision 1.1 2012/01/25 17:35:30CET Godreau, Bertrand (uid28828) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_TRACKPAIR_INCLUDED
#define HLA_TRACKPAIR_INCLUDED

#include "hla_trackutils.h"

typedef struct
{
  /* pair state without width info */
  float32 fd;
  float32 fl;
  float32 fh;
  float32 fr;
  float32 fa;

  /* jacobian */
  ARRAY(float32, HLA_TRACKING_6X3_MATRIXSIZE, HJLf);
  ARRAY(float32, HLA_TRACKING_6X3_MATRIXSIZE, HJRf);
  ARRAY(float32, HLA_TRACKING_6X3_MATRIXSIZE, HCf);

  uint8 isPositionUpdated;
  uint8 isIntConstantUpdated;

} HLAPairStateWidthFree_t;

/*! Type definition for target vehicle list */
typedef struct
{
  /* allocate memory for vehicles */
  ARRAY(HLAPair_t, HLA_TRACKING_MAX_NUM_PAIRS, bufferPairs);
  HLAPair_t* pFreePair;                    /*!< @brief list of unused vehicles  */

} HLATracking3DDataPairs_t;


typedef struct
{
  float32 uwl;
  float32 dwl;
  float32 uwr;
  float32 dwr;
  float32 os;
  float32 ol;
} HLAPairTTBInput;


/* init */
void HLATrackPairInit(      HLATracking3DDataPairs_t*           pDataPairs,
                            HLATracking3DDataPreComputedPair_t* pDataPreComputedPairAhead,
                            HLATracking3DDataPreComputedPair_t* pDataPreComputedPairOncoming,
                            HLATracking3DDataPreComputedPair_t* pDataPreComputedPairTruckLights,
                      const HLATracking3DParametersPairing_t*   pParamPair,
                      const HLATracking3DDataPreComputed_t*     pDataPreComputed
                     );

/* predict pair */
void HLATrackPairPredict(       HLAPair_t*                      pPairStart,
                          const HLATracking3DDataEgomotion_t*   pDataEgomotion,
                          const HLATracking3DDataRotations_t*   pDataRotations,
                          const HLATracking3DDataPreComputed_t* pDataPreComputed
                        );
/* update pair */
void HLATrackPairUpdate(      HLAPair_t*                            pPair,
                        const HLATracking3DDataEgomotion_t*         pDataEgomotion,
                        const HLATracking3DDataRotations_t*         pDataRotations,
                        const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                        const HLATracking3DDataPreComputedPair_t*   pDataPreComputedPair,
                        const HLATracking3DParametersMeasurement_t* pParamMeas,
                        const HLATracking3DParametersTTB_t*         pParamTTB
                        );

/* tracked pair classification */
void HLATrackPairUpdateTrackedInPairFlag(       HLAPair_t*                        pPairStart,
                                                HLATracking3DDataDebug_t*         pDataDebug,
                                                HLADebugOutputs_t*                phlaDebugOutputs,
                                          const HLATracking3DParametersPairing_t* pParamPair,
                                          const HLATracking3DDataPreComputed_t*   pDataPreComputed,
                                          AS_t_GetTimestampuS32                   pfGetTimestampuS32
                                          );

/* add/remove pair */
void HLATrackPairAdd(       HLATrack_t*                           pTrackStart,
                      const HLATracking3DDataPreComputed_t*       pDataPreComputed,
                      const HLATracking3DParametersMeasurement_t* pParamMeas,
                      const HLATracking3DDataRotations_t*         pDataRotations,
                            HLAPair_t**                           ppPairStart,
                            uint8*                                pnumPairs,
                            HLATracking3DDataPairs_t*             pDataPairs,
                      const HLACameraData_t*                      pCamData,
                            HLATracking3DDataTracks_t*            pDataTracks,
                      const RTE_HLA_TrafficStyle                  eTrafficStyle
                    );

void HLATrackPairRemove(HLAPair_t**               ppPairStart,
                        uint8*                    pNumPairs,
                        HLATracking3DDataPairs_t* pDataPairs
                        );


/* avoid cyclic binding ---------------------------------------------------*/
#endif
