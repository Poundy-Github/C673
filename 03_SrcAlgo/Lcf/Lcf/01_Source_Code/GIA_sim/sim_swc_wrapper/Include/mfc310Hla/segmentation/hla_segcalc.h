/*! \file **   ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    Ti DSP

  COMPONENT:              HLA

  MODULNAME:              hla_segcalc.h

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_segcalc.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:36CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:19CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:53CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/03/25 18:48:08CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj
  **************************************************************************** */

#ifndef HLA_SEGCALC_INCLUDED
#define HLA_SEGCALC_INCLUDED

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

void HLASegCalcLuxIntensity( HLASegLightDataRoi_t* pLightData,
                             HLASegLightBuffer_t*  pLightBuffer
                           );
void HLASegCalcRGB_GradientBasedInterp( const uint8                iLBStart,
                                              HLASegLightBuffer_t* pLightBuffer
                                       );

void HLASegCalcRGB_GradientBasedInterp_Pixel( const uint16* pPix,
                                              const uint16  xPix, 
                                              const uint16  yPix,
                                              const uint16  xImgWidth,
                                              const uint16  BL, 
                                                    uint16* pR, 
                                                    uint16* pG,
                                                    uint16* pB
                                             );

#endif /* HLA_SEGCALC_INCLUDED */
