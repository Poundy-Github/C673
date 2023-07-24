/*! \file **   ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    Ti DSP

  COMPONENT:              HLA

  MODULNAME:              hla_segregion.h

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_segregion.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:40CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:27CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:58CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.2 2014/03/26 14:44:44CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 2:44:44 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.1 2014/03/25 18:48:13CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj
  **************************************************************************** */

#ifndef HLA_SEGREGION_INCLUDED
#define HLA_SEGREGION_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_segutils.h"

/******************************************************************************
* TYPEDEFS
*****************************************************************************/


/******************************************************************************
* MACROS / DEFINES
******************************************************************************/


/******************************************************************************
* GLOBAL VARIABLES
******************************************************************************/

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
void HLASegRegionBuildList(       HLASegLineBuffer_t*                           pLineBuffer,
                            const HLASegmentationParametersLineCluster_t*       pParLineCluster,
                            const HLACameraData_t*                              pCamData,
                            const uint8                                         Level,                                  
                            const HLASegLineLevel_t*                            pLinesLevel,
                                  uint8*                                        piRegStart,
                                  uint8*                                        pnRegions,
                                  uint8*                                        piRegFree,
                                  HLASegLineRegionBuffer_t*                     pRegionBuffer
                          );

void HLASegRegionBuildRelationship(       HLASegLineBuffer_t*       pLineBuffer,
                                    const uint8                     iUpperRegStart,
                                    const uint8                     iLowerRegStart,
                                          HLASegLineRegionBuffer_t* pRegionBuffer
                                  );
#endif