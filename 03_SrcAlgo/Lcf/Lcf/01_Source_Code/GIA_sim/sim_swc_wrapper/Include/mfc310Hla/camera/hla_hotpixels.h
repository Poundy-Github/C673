/*! \file **********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                CSF200

  CPU:                    Pentium

  COMPONENT:              HLA

  MODULNAME:              hla_hotpixels.h

  DESCRIPTION:            Functions for light track analysis.

  AUTHOR:                 Bertrand Godreau

  CREATION DATE:          01.09.2010

  VERSION:                $Revision: 1.1 $ 

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_hotpixels.h  $  
  CHANGE:                 Revision 1.1 2021/12/13 17:26:51CET Wang, David (Wangd3)   
  CHANGE:                 Initial revision  
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/camera/project.pj  
  CHANGE:                 Revision 1.0 2017/03/03 10:38:29CET Sorge, Sven (uidg3181)   
  CHANGE:                 Initial revision  
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/camera/project.pj  
  CHANGE:                 Revision 1.1 2014/04/17 16:05:24CEST Sorge, Sven (uidg3181)   
  CHANGE:                 Initial revision  
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/camera/project.pj  
  CHANGE:                 Revision 1.4 2014/03/25 18:35:12CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Member moved from hla_hotpixels.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_hotpixels.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/camera/project.pj.  
  CHANGE:                 Revision 1.3 2014/01/10 18:33:41CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 First part of LRF on EVE (disabled)  
  CHANGE:                 Merged LRF inputs into one struct  
  CHANGE:                 Fixed exception handling of internal cali   
  CHANGE:                 Removed all tabs in the code and further clean-up  
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:41 PM CET]  
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642  
  CHANGE:                 Revision 1.2 2013/11/21 17:53:45CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Merge from NEW_SEG branch  
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:45 PM CET]  
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432  
  CHANGE:                 Revision 1.1.1.1 2013/11/12 13:45:05CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Removed SegOut from function arguments  
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:45:05 PM CET]  
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787  
  CHANGE:                 Revision 1.1 2013/08/05 17:01:55CEST Manz, Alexander (uidv8777)   
  CHANGE:                 Initial revision  
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj  
  CHANGE:                 Revision 1.1.1.12 2013/03/11 14:32:59CET Mutschler, Matthias (uidv7867)   
  CHANGE:                 Placed no longer needed by RTE ones  
  CHANGE:                 - HLA_t_eBrightnessState  
  CHANGE:                 - HLA_t_eLightOutput  
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 2:33:00 PM CET]  
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173  
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_HOTPIXELS_INCLUDED
#define HLA_HOTPIXELS_INCLUDED

/* includes */
#include "hla_base.h"

/* hot pixels data */
typedef struct
{
  /* !!! ic defect list is in absolute imager coordinates !!! */
  HLA_t_DefectPixelList   hlaDefectPixelList;
  uint16                  HotPixelTimeCounter;
  uint16                  numHotPixelInHLAROI;
  
}HLAHotPixelsData_t;


/*! init hot pixels detection */
void HLAHotPixelsInit(
                      HLAHotPixelsData_t *pDataHotPixels
                      );

/*! detect and manage hot pixels list */
void HLAHotPixels( 
                  const HLA_t_MotionState         *pMotionState,
                  const RTE_HLAR_BrightnessState  eBrightnessState,
                  HLATrack_t                      *pTStart,
                  HLAHotPixelsData_t              *pDataHotPixels,
                  const HLAHotPixelParameters_t   *pParamsHotPixels
                  );

/* avoid cyclic binding ---------------------------------------------------*/
#endif
