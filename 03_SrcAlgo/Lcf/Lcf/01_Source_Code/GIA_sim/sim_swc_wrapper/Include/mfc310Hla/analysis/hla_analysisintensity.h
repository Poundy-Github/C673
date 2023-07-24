/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysisintensity.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Carlos Almeida

  CREATION DATE:          2010-09-30

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_analysisintensity.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:26:43CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:37:58CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:16CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGES:                Revision 1.22 2014/03/25 18:32:13CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hla_analysisintensity.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_analysisintensity.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGES:                Revision 1.21 2014/03/04 16:51:50CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed QAC warnings
  CHANGES:                Coding style
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 4:51:50 PM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.20 2014/01/28 10:48:12CET Schillinger, Patrick (uidv8776) 
  CHANGES:                -renaming of some unclear variables
  CHANGES:                -changes to meet coding guideline
  CHANGES:                --- Added comments ---  uidv8776 [Jan 28, 2014 10:48:13 AM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.19 2014/01/17 13:18:53CET Schillinger, Patrick (uidv8776) 
  CHANGES:                rename pT to pTrack
  CHANGES:                --- Added comments ---  uidv8776 [Jan 17, 2014 1:18:54 PM CET]
  CHANGES:                Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGES:                Revision 1.18 2013/03/08 10:31:16CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated to latest RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 8, 2013 10:31:17 AM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.17 2013/03/04 11:15:08CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Integrated cam_rot into HLA
  CHANGES:                bug fix in jacobian calculation
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2013 11:15:08 AM CET]
  CHANGES:                Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167
**************************************************************************** */

#ifndef HLA_ANAINT_INCLUDED
#define HLA_ANAINT_INCLUDED

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
/*! initialize state variables */
void HLAAnalysisIntensityInit(const HLAR_t_RequiredInputs* ps_In);

/*! Prepare the intensity based analysis once per frame before the tracks are analyzed. */
void HLAAnalysisIntensityPrepare( const HLAR_t_RequiredInputs*    pRequiredIn,
                                  const HLACameraData_t*          pCamData,
                                  const HLACamRot*                pCamRot,
                                  const RTE_HLA_TrafficStyle      eTrafficStyle
                                );

/*! Do intensity based analysis. */
void HLAAnalysisIntensity( const HLA_t_AnalysisParameters* pAnalysisParamIn,
                           const HLACameraData_t*          pCamData,
                                 HLATrack_t*               pTrack
                          );

/*! Do intensity based identification. */
void HLAIdentificationIntensity( const HLA_t_IdentificationParameters*  pIdentParamIn,
                                       HLATrack_t*                      pTrack );

#endif /* #ifndef HLA_INTANA_INCLUDED */