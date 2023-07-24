/*! \file **   ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    Ti DSP

  COMPONENT:              HLA

  MODULNAME:              hla_segsubimage.h

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_segsubimage.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:41CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:28CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:59CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/03/25 18:48:13CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj
  **************************************************************************** */

#ifndef HLA_SEGSUBIMAGE_INCLUDED
#define HLA_SEGSUBIMAGE_INCLUDED

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
/* define for mean intensity calculation */
#define HLA_SEG_INTENSITY_PIX_STEP          160u
#define HLA_SEG_INTENSITY_PIX_OFFSET_0       16u
#define HLA_SEG_INTENSITY_PIX_OFFSET_1      (HLA_SEG_INTENSITY_PIX_OFFSET_0 + HLA_SEG_INTENSITY_PIX_STEP)
#define HLA_SEG_INTENSITY_PIX_OFFSET_2      (HLA_SEG_INTENSITY_PIX_OFFSET_1 + HLA_SEG_INTENSITY_PIX_STEP)
#define HLA_SEG_INTENSITY_PIX_OFFSET_3      (HLA_SEG_INTENSITY_PIX_OFFSET_2 + HLA_SEG_INTENSITY_PIX_STEP)
#define HLA_SEG_INTENSITY_PIX_OFFSET_4      (HLA_SEG_INTENSITY_PIX_OFFSET_3 + HLA_SEG_INTENSITY_PIX_STEP)
#define HLA_SEG_INTENSITY_PIX_OFFSET_STEP   (HLA_SEG_INTENSITY_PIX_STEP/16u)
#define HLA_SEG_INTENSITY_PIX_OFFSET_MAX    (16u * HLA_SEG_INTENSITY_PIX_OFFSET_STEP)

/******************************************************************************
* GLOBAL VARIABLES
******************************************************************************/

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/* average intensity for upper/mid/lower roi part */
void HLASegSubImageCalcIntensities( const HLA_t_CameraParameter*         pCameraParameter,
                                          t_PixelData*                   pImg,
                                    const HLACameraData_t*               pCamData,
                                    const HLASegIn_t*                    pSegIn,
                                          HLASegSubImageData_t*          pData,
                                          HLASegOut_t*          restrict pOut
                                   );

#endif