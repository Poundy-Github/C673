/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysiscolor.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Carlos Almeida

  CREATION DATE:          2010-09-30

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_analysiscolor.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:26:42CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:37:55CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:14CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.19 2014/03/25 18:32:12CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hla_analysiscolor.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_analysiscolor.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGES:                Revision 1.18 2014/02/11 12:34:42CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed analysis level 1 color internal time meas
  CHANGES:                --- Added comments ---  uidv7867 [Feb 11, 2014 12:34:43 PM CET]
  CHANGES:                Change Package : 207432:18 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.17 2014/01/28 10:48:09CET Schillinger, Patrick (uidv8776) 
  CHANGES:                -renaming of some unclear variables
  CHANGES:                -changes to meet coding guideline
  CHANGES:                --- Added comments ---  uidv8776 [Jan 28, 2014 10:48:09 AM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.16 2014/01/17 13:46:30CET Schillinger, Patrick (uidv8776) 
  CHANGES:                rename pT and pTLB to pTrack
  CHANGES:                --- Added comments ---  uidv8776 [Jan 17, 2014 1:46:31 PM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.15 2013/12/13 16:45:02CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Service functions are now passed in one struct
  CHANGES:                SDLfile definitions moved to separate file
  CHANGES:                --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:02 PM CET]
  CHANGES:                Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.14 2013/11/21 17:53:39CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Merge from NEW_SEG branch
  CHANGES:                --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:40 PM CET]
  CHANGES:                Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.13.1.1 2013/10/18 13:27:31CEST Brunn, Marcus (brunnm) 
  CHANGES:                intial version of new segmentation
  CHANGES:                --- Added comments ---  brunnm [Oct 18, 2013 1:27:31 PM CEST]
  CHANGES:                Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGES:                Revision 1.13 2013/03/08 10:30:44CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated to latest RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 8, 2013 10:30:44 AM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.12 2012/10/10 13:02:48CEST Brunn, Marcus (brunnm) 
  CHANGES:                RAM optimization (Part2)
  CHANGES:                --- Added comments ---  brunnm [Oct 10, 2012 1:02:49 PM CEST]
  CHANGES:                Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGES:                Revision 1.11 2012/06/01 14:09:40CEST Zechner, Stefan (uidt9253) 
  CHANGES:                - if halogen head lamps are available a special trained halogen color classifier is used (no changes for Xenon or Led head lamps)
  CHANGES:                --- Added comments ---  uidt9253 [Jun 1, 2012 2:09:40 PM CEST]
  CHANGES:                Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGES:                Revision 1.10 2012/03/29 15:14:11CEST Mueller, Reik (muellerr5) 
  CHANGES:                - added comments from code review findings
  CHANGES:                --- Added comments ---  muellerr5 [Mar 29, 2012 3:14:12 PM CEST]
  CHANGES:                Change Package : 94915:1 http://mks-psad:7002/im/viewissue?selection=94915
  CHANGES:                Revision 1.9 2012/01/25 21:59:31CET Brunn, Marcus (brunnm) 
  CHANGES:                added time measurement for color analysis
  CHANGES:                --- Added comments ---  brunnm [Jan 25, 2012 9:59:31 PM CET]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.8 2011/09/07 18:06:44CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - removed a lot of unused stuff from blackboard
  CHANGES:                --- Added comments ---  uidt9253 [Sep 7, 2011 6:06:44 PM CEST]
  CHANGES:                Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGES:                Revision 1.7 2011/09/02 15:53:37CEST Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:                - updated color analysis
  CHANGES:                --- Added comments ---  muellerr5 [Sep 2, 2011 3:53:37 PM CEST]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.6 2011/06/28 15:21:22CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGES:                - keep pulsed light confidence counter on same level when the led light switches between led and red
  CHANGES:                --- Added comments ---  uidt9253 [Jun 28, 2011 3:21:22 PM CEST]
  CHANGES:                Change Package : 63192:1 http://mks-psad:7002/im/viewissue?selection=63192
  CHANGES:                Revision 1.5 2011/05/23 19:48:32CEST Almeida Carlos (almeidac) (almeidac) 
  CHANGES:                Adapted new identification model on all classifiers
  CHANGES:                --- Added comments ---  almeidac [May 23, 2011 7:48:32 PM CEST]
  CHANGES:                Change Package : 53530:1 http://mks-psad:7002/im/viewissue?selection=53530
  CHANGES:                Revision 1.4 2011/05/23 13:58:38CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGES:                - renamed seg_TracklistNode into HLATrack_t
  CHANGES:                - renamed seg_ListNode into HLASegLight_t
  CHANGES:                --- Added comments ---  brunnm [May 23, 2011 1:58:38 PM CEST]
  CHANGES:                Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGES:                Revision 1.3 2011/02/25 12:40:00CET Mueller Reik (muellerr5) (muellerr5) 
  CHANGES:                - moved HLAIdentificationColorNonWhite() from hla_analysis.c
  CHANGES:                --- Added comments ---  muellerr5 [Feb 25, 2011 12:40:00 PM CET]
  CHANGES:                Change Package : 54965:1 http://mks-psad:7002/im/viewissue?selection=54965
  CHANGES:                Revision 1.2 2011/02/14 07:40:28CET Marcus Brunn (brunnm) 
  CHANGES:                - added roi parameter
  CHANGES:                - moved global used type defintions to hla_base.h (e.g. tracking list, maxima list)
  CHANGES:                - removed direct access to hlaCamData, instead added hlaCamData pointer to all functions
  CHANGES:                --- Added comments ---  brunnm [Feb 14, 2011 7:40:28 AM CET]
  CHANGES:                Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGES:                Revision 1.1 2010/10/14 14:38:06CEST Marcus Brunn (brunnm) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGES:                Revision 1.2 2010/10/12 14:26:12CEST Reik Mueller (x-muellerr5) 
  CHANGES:                - added red light classificator (trained with CSF data)
  CHANGES:                --- Added comments ---  x-muellerr5 [Oct 12, 2010 2:26:12 PM CEST]
  CHANGES:                Change Package : 38439:1 http://mks-psad:7002/im/viewissue?selection=38439
  CHANGES:                Revision 1.1 2010/10/01 22:15:20CEST Carlos Almeida (almeidac) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

#ifndef HLA_ANACOL_INCLUDED
#define HLA_ANACOL_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_base.h"
#include "hla_debug.h"

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
/*! Do color based analysis. */
boolean HLAAnalysisColor( const HLA_t_AnalysisParameters* pAnalysisParamIn,
                          const RTE_HLA_HeadlightType     eHeadLightType,
                                HLATrack_t*               pTrack
                        );

/* ~CodeReview ~ID:2856eb1c8e3fc5b605f3820858918f7a ~Reviewer:CW01\muellerr5 ~Date:29.03.2012 ~Priority:3 ~Comment:dead code */
#if 0
/*! Do identification for non-white lights. */
void HLAIdentificationColorNonWhite( const HLA_t_IdentificationParameters*  pIdentParamIn,
                                           HLATrack_t*                    pTrack );
#endif

/*! Do identification for other-color lights. */
void HLAIdentificationColorOther( const HLA_t_IdentificationParameters* pIdentParamIn,
                                        HLATrack_t*                     pTrack );

/*! Do identification for white-or-red light */
void HLAIdentificationColorWhiteOrRed( const HLA_t_IdentificationParameters*  pIdentParamIn,
                                             HLATrack_t*                      pTrack );

#endif /* #ifndef HLA_INTCOL_INCLUDED */
