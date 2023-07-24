/*! \file **   ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    Ti DSP

  COMPONENT:              HLA

  MODULNAME:              hla_seglight.h

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_seglight.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:37CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:20CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:54CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/03/25 18:48:09CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj
  **************************************************************************** */

#ifndef HLA_SEGLIGHT_INCLUDED
#define HLA_SEGLIGHT_INCLUDED

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

void HLASegLightBuildChainOut( HLASegLightData_t* pDat,
                               HLASegOut_t*       pOut
                             );

void HLASegLightBuildList( const uint16                    RoiYu,
                                 HLASegLineRegionBuffer_t* pRegionBuffer,
                                 HLASegLightBuffer_t*      pLightBuffer,
                                 uint8                     iRegionStart,
                                 HLASegLightData_t*        pLightData,
                                 HLASegLightDataRoi_t*     pLight_AboveRoi,
                                 HLASegLightDataRoi_t*     pLight_FunctRoi
                          );

void HLASegLightBuildPairLights(       HLASegLightDataRoi_t*            pLightData,
                                       HLASegLineRegionBuffer_t*        pRegionBuffer,
                                       HLASegLightBuffer_t*             pLightBuffer,
                                 const HLACameraData_t*                 pCamData,
                                 const HLASegmentationParametersPair_t* pPar
                               );

void HLASegLightSearchPairLights( const HLA_t_CameraParameter*                  pCameraParameter,
                                  const HLACameraData_t*                        pCamData,
                                        t_PixelData*                            pImg,
                                        HLASegData_t* restrict                  pData,
                                        HLASegLightDataRoi_t*                   pLightData,
                                  const HLASegmentationParametersPair_t*        pPar,
                                        HLASegLineRegionBuffer_t*               pRegionBuffer,
                                        HLASegLightBuffer_t*                    pLightBuffer
                                );

void HLASegLightBuildPairLights(       HLASegLightDataRoi_t*            pLightData,
                                       HLASegLineRegionBuffer_t*        pRegionBuffer,
                                       HLASegLightBuffer_t*             pLightBuffer,
                                 const HLACameraData_t*                 pCamData,
                                 const HLASegmentationParametersPair_t* pPar
                               );
#endif