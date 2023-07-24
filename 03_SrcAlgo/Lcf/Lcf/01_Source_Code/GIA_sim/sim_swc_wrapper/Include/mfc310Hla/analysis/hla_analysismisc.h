/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysismisc.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Carlos Almeida

  CREATION DATE:          2010-12-21

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_analysismisc.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:26:44CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:37:59CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:17CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.26 2014/03/25 18:32:13CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hla_analysismisc.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_analysismisc.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGES:                Revision 1.25 2014/01/28 10:48:14CET Schillinger, Patrick (uidv8776) 
  CHANGES:                -renaming of some unclear variables
  CHANGES:                -changes to meet coding guideline
  CHANGES:                --- Added comments ---  uidv8776 [Jan 28, 2014 10:48:14 AM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.24 2014/01/17 13:46:32CET Schillinger, Patrick (uidv8776) 
  CHANGES:                rename pT and pTLB to pTrack
  CHANGES:                --- Added comments ---  uidv8776 [Jan 17, 2014 1:46:33 PM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.23 2014/01/10 18:33:16CET Mutschler, Matthias (uidv7867) 
  CHANGES:                First part of LRF on EVE (disabled)
  CHANGES:                Merged LRF inputs into one struct
  CHANGES:                Fixed exception handling of internal cali 
  CHANGES:                Removed all tabs in the code and further clean-up
  CHANGES:                --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:17 PM CET]
  CHANGES:                Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.22 2013/12/18 15:15:28CET Schillinger, Patrick (uidv8776) 
  CHANGES:                new HighwayOncomingTruckLight detection
  CHANGES:                --- Added comments ---  uidv8776 [Dec 18, 2013 3:15:29 PM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.21 2013/11/21 17:53:02CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Merge from NEW_SEG branch
  CHANGES:                --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:02 PM CET]
  CHANGES:                Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.20.1.1 2013/10/18 13:27:32CEST Brunn, Marcus (brunnm) 
  CHANGES:                intial version of new segmentation
  CHANGES:                --- Added comments ---  brunnm [Oct 18, 2013 1:27:32 PM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.20 2013/08/02 15:25:50CEST Manz, Alexander (uidv8777) 
  CHANGES:                Change: changed the name of HLATargetVehicle_t to HLAPair_t for better understanding
  CHANGES:                --- Added comments ---  uidv8777 [Aug 2, 2013 3:25:50 PM CEST]
  CHANGES:                Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
  CHANGES:                Revision 1.19 2013/03/14 17:44:35CET Schillinger, Patrick (uidv8776) 
  CHANGES:                improvement of  highway oncoming car detection.
  CHANGES:                --- Added comments ---  uidv8776 [Mar 14, 2013 5:44:36 PM CET]
  CHANGES:                Change Package : 169297:1 http://mks-psad:7002/im/viewissue?selection=169297
  CHANGES:                Revision 1.18 2013/03/08 15:51:30CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed Misra errors
  CHANGES:                --- Added comments ---  uidv7867 [Mar 8, 2013 3:51:30 PM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.17 2013/03/08 10:29:44CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated to latest RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 8, 2013 10:29:45 AM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.16 2013/03/08 10:12:27CET Schillinger, Patrick (uidv8776) 
  CHANGES:                Moved Highway Oncoming Car Analysis to First Level Analysis
  CHANGES:                --- Added comments ---  uidv8776 [Mar 8, 2013 10:12:27 AM CET]
  CHANGES:                Change Package : 169297:1 http://mks-psad:7002/im/viewissue?selection=169297
  CHANGES:                Revision 1.15 2013/03/04 11:15:04CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Integrated cam_rot into HLA
  CHANGES:                bug fix in jacobian calculation
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2013 11:15:05 AM CET]
  CHANGES:                Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.14 2012/10/10 13:03:04CEST Brunn, Marcus (brunnm) 
  CHANGES:                RAM optimization (Part2)
  CHANGES:                --- Added comments ---  brunnm [Oct 10, 2012 1:03:05 PM CEST]
  CHANGES:                Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGES:                Revision 1.13 2012/07/25 11:17:38CEST Zechner, Stefan (uidt9253) 
  CHANGES:                - return of the isStreetLamp detection and additional check for typical static high object movement which is also applied on red lights
  CHANGES:                --- Added comments ---  uidt9253 [Jul 25, 2012 11:17:41 AM CEST]
  CHANGES:                Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGES:                Revision 1.12 2012/03/13 14:05:17CET Zechner, Stefan (uidt9253) 
  CHANGES:                - first level analysis sets a potential vehicle when tracking indicates a dynamic / moving object
  CHANGES:                --- Added comments ---  uidt9253 [Mar 13, 2012 2:05:17 PM CET]
  CHANGES:                Change Package : 94867:1 http://mks-psad:7002/im/viewissue?selection=94867
  CHANGES:                Revision 1.11 2011/10/18 13:21:00CEST Mueller, Reik (muellerr5) 
  CHANGES:                - added HLAAnalysisOncomingPairFromTargetVehicles()
  CHANGES:                --- Added comments ---  muellerr5 [Oct 18, 2011 1:21:00 PM CEST]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.10 2011/09/27 13:39:42CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                separation of HLAR/ HLAF
  CHANGES:                --- Added comments ---  brunnm [Sep 27, 2011 1:39:42 PM CEST]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.9 2011/09/06 13:58:18CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - remove redundant structure motionData from blackboard and replaced by input interface motionState
  CHANGES:                --- Added comments ---  uidt9253 [Sep 6, 2011 1:58:19 PM CEST]
  CHANGES:                Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGES:                Revision 1.8 2011/06/21 16:37:21CEST Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:                - added OncomingPair Analysis
  CHANGES:                --- Added comments ---  muellerr5 [Jun 21, 2011 4:37:22 PM CEST]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.7 2011/05/24 22:00:24CEST Almeida Carlos (almeidac) (almeidac) 
  CHANGES:                Update concerning MISRA and LINT
  CHANGES:                --- Added comments ---  almeidac [May 24, 2011 10:00:25 PM CEST]
  CHANGES:                Change Package : 54255:1 http://mks-psad:7002/im/viewissue?selection=54255
  CHANGES:                Revision 1.6 2011/05/23 13:58:49CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                - renamed seg_TracklistNode into HLATrack_t
  CHANGES:                - renamed seg_ListNode into HLASegLight_t
  CHANGES:                --- Added comments ---  brunnm [May 23, 2011 1:58:49 PM CEST]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.5 2011/04/14 19:01:14CEST Godreau Bertrand (uid28828) (uid28828) 
  CHANGES:                3D tracking clean-up.
  CHANGES:                Remove use of global variables.
  CHANGES:                Set-up of an input/output/data archi
  CHANGES:                --- Added comments ---  uid28828 [Apr 14, 2011 7:01:15 PM CEST]
  CHANGES:                Change Package : 50618:1 http://mks-psad:7002/im/viewissue?selection=50618
  CHANGES:                Revision 1.4 2011/03/08 16:00:47CET Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:                - added CloseReflector suppression
  CHANGES:                --- Added comments ---  muellerr5 [Mar 8, 2011 4:00:47 PM CET]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.3 2011/02/25 12:41:59CET Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:                - added HLAIdentificationContraMotion()
  CHANGES:                --- Added comments ---  muellerr5 [Feb 25, 2011 12:41:59 PM CET]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.2 2011/02/14 07:40:29CET Marcus Brunn (brunnm) 
  CHANGES:                - added roi parameter
  CHANGES:                - moved global used type defintions to hla_base.h (e.g. tracking list, maxima list)
  CHANGES:                - removed direct access to hlaCamData, instead added hlaCamData pointer to all functions
  CHANGES:                --- Added comments ---  brunnm [Feb 14, 2011 7:40:29 AM CET]
  CHANGES:                Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGES:                Revision 1.1 2010/12/21 15:38:51CET Carlos Almeida (almeidac) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

#ifndef HLA_ANAMISC_INCLUDED
#define HLA_ANAMISC_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlar_ext.h"
#include "hla_cam_rot.h"
#include "hla_base.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
/*! Do intensity based analysis. */
void HLAAnalysisBaseMisc( const HLA_t_AnalysisParameters*     pAnalysisParamIn,
                          const HLAR_t_RequiredInputs*        pRequiredIn,
                          const HLACameraData_t*              pCamData,
                          const HLATracking3DDataEgomotion_t* pEgomotionData,
                          const HLACamRot*                    pCam,
                                HLATrack_t*                   pTrack 
                         );

/*! Do analysis for oncoming lights on highways. */
void HLAAnalysisHighwayBright(  const RTE_HLA_TrafficStyle  eTrafficStyle, 
                                const HLA_t_Highway*        pHighwayData, 
                                const HLACameraData_t*      pCamData,
                                const HLACamRot*            pCamRot,
                                      HLATrack_t*           pTrack
                             );

void HLAAnalysisHighwayBrightTruckLights( const RTE_HLA_TrafficStyle  eTrafficStyle, 
                                          const HLA_t_Highway*        pHighwayData, 
                                          const HLACameraData_t*      pCamData,
                                                HLAPair_t*            pPair_Start
                                         );

/*! Do oncoming pair analysis on list of target vehicles. */
void HLAAnalysisOncomingPairFromPairs(HLAPair_t*  pPair_Start);

/*! Do identification for contra motion. */
void HLAIdentificationContraMotion( const HLA_t_IdentificationParameters*  pIdentParamIn,
                                          HLATrack_t*                      pTrack );

/*! Do identification for dynamic motion. */
void HLAIdentificationDynamicMotion( const HLA_t_IdentificationParameters* pIdentParamIn,
                                           HLATrack_t*                     pTrack );

/*! Do identification for close reflector. */
void HLAIdentificationCloseReflector( const HLA_t_IdentificationParameters* pIdentParamIn,
                                            HLATrack_t*                     pTrack );

void HLAIdentificationHighwayBright(HLATrack_t* pTrack);

void HLAIdentificationHighwayBrightTruckLights(HLATrack_t*  pTrack);

/*! Do identification for oncoming pair. */
void HLAIdentificationOncomingPair( const HLA_t_IdentificationParameters* pIdentParamIn,
                                          HLATrack_t*                     pTrack );

void HLAIdentificationStaticHigh( const HLA_t_IdentificationParameters* pIdentParamIn,
                                        HLATrack_t*                     pTrack );


#endif /* #ifndef HLA_INTMISC_INCLUDED */
