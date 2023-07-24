/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysischain.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Boris Lugez

  CREATION DATE:          2011-05-17

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_analysischain.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:41CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:37:53CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:13CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.13 2014/03/25 18:32:13CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_analysischain.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_analysischain.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGE:                 Revision 1.12 2014/01/10 18:33:54CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:54 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.11 2013/12/17 17:32:40CET Glebov, Roman (uidg4759) 
  CHANGE:                 QAC Changes + Documentation of Chain of Light + fix of devision by 0 + small efficiency tweaks
  CHANGE:                 --- Added comments ---  uidg4759 [Dec 17, 2013 5:32:40 PM CET]
  CHANGE:                 Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.10 2013/07/12 11:20:01CEST Fischer, Alexander (uidv8778) 
  CHANGE:                 Further restructuring of chain of light
  CHANGE:                 --- Added comments ---  uidv8778 [Jul 12, 2013 11:20:01 AM CEST]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.9 2013/06/21 16:18:19CEST Fischer, Alexander (uidv8778) 
  CHANGE:                 Moved chain of light visu from hla_analysischain to sim_hla_visualisation_draw
  CHANGE:                 --- Added comments ---  uidv8778 [Jun 21, 2013 4:18:19 PM CEST]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.8 2013/03/04 11:14:56CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Integrated cam_rot into HLA
  CHANGE:                 bug fix in jacobian calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2013 11:14:57 AM CET]
  CHANGE:                 Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.7 2012/03/22 10:27:30CET Lugez, Boris (uidt2765) 
  CHANGE:                 -> Code review findings
  CHANGE:                 --- Added comments ---  uidt2765 [Mar 22, 2012 10:27:31 AM CET]
  CHANGE:                 Change Package : 103574:1 http://mks-psad:7002/im/viewissue?selection=103574
  CHANGE:                 Revision 1.6 2011/10/21 16:13:00CEST Lugez, Boris (uidt2765) 
  CHANGE:                 -> Remove most of periodicity criterions
  CHANGE:                 -> Increase sensitivity of chain detection (relax parameters)
  CHANGE:                 --- Added comments ---  uidt2765 [Oct 21, 2011 4:13:00 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.5 2011/09/27 13:39:40CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 separation of HLAR/ HLAF
  CHANGE:                 --- Added comments ---  brunnm [Sep 27, 2011 1:39:40 PM CEST]
  CHANGE:                 Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.4 2011/05/26 17:43:58CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Integrate street lamps analysis module
  CHANGE:                 -> Add 2D street lamps signature analysis
  CHANGE:                 --- Added comments ---  uidt2765 [May 26, 2011 5:43:58 PM CEST]
  CHANGE:                 Change Package : 49956:1 http://mks-psad:7002/im/viewissue?selection=49956
  CHANGE:                 Revision 1.3 2011/05/24 13:48:43CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> solve MISRA rules
  CHANGE:                 -> new chain of light structure
  CHANGE:                 --- Added comments ---  uidt2765 [May 24, 2011 1:48:43 PM CEST]
  CHANGE:                 Change Package : 49956:1 http://mks-psad:7002/im/viewissue?selection=49956
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_ANALYSISCHAIN_INCLUDED
#define HLA_ANALYSISCHAIN_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_base.h"
#include "hla_cam_rot.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  FUNCTION:      void HLAAnalysisChain(HLATrack_t*  pTrackListHead,const HLACamRot *pcamRot,
  const HLA_t_ChainParam *pParam, HLAChainOfLightData_t *pCoLData);
******************************************************************************
* Description:
*               Do the chain of light analysis . 
*               - a chain is constructed link by link
*               - for each track, one upper track and one track down are selected in the image to make a link
*               - a chain starts with a track with no track down and then follow the upper links 
*               - a chain is validated if it contains more than 5 links (max number of links = 32 )
*               - only 5 chains are stored in struct clusterTrackList
*               - each track has the isChainOfLight flag which indicates the current frame belonging to a chain
*               - each track has the isChainOfLights identification result which indicates the over time belonging to a chain
*******************************************************************************************************************************
* PARAMETERS:
* pTrackListHead    pointer to the start of linked list with tracks
* pcamRot       structure with camera parameters
* pParam        structure with settings for chain of light detection
* pColData      output argument with chains of light
*******************************************************************************************************************************
* RETURN VALUE  :
* void          see output argument
*******************************************************************************************************************************
*/
void HLAAnalysisChain(HLATrack_t* pTrackListHead, const HLACamRot* pcamRot, const HLA_t_ChainParam* pParam, HLAChainOfLightData_t* pCoLData);

/* avoid cyclic binding ---------------------------------------------------*/
#endif