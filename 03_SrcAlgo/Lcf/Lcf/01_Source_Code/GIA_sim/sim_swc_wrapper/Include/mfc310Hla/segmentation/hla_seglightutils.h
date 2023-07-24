/*! \file **   ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    Ti DSP

  COMPONENT:              HLA

  MODULNAME:              hla_seglightutils.h

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_seglightutils.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:39CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:24CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:56CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/03/25 18:48:11CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj
  **************************************************************************** */

#ifndef HLA_SEGLIGHTUTILS_INCLUDED
#define HLA_SEGLIGHTUTILS_INCLUDED

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
void HLASegLightUtilsDetectionSaturation( HLASegLightDataRoi_t* pLightData,
                                          HLASegLightBuffer_t*  pLightBuffer
                                        );

void HLASegLightUtilsPotentialRedDetection( const HLACameraData_t*                        pCamData,
                                            const HLA_t_SegmentationParametersBrightness* pPar,
                                                  HLASegLightDataRoi_t*                   pLightData,
                                                  HLASegLightBuffer_t*                    pLightBuffer																												
                                          );

void HLASegLightUtilsPotentialLEDDetection( const HLACameraData_t*                        pCamData,
                                            const HLA_t_SegmentationParametersBrightness* pParBrightness,
                                                  HLASegLightDataRoi_t*                   pLightData,
                                                  HLASegLightBuffer_t*                    pLightBuffer
                                          );

void HLASegLightUtilsSetLightPosition( const uint8                iLBStart,
                                             HLASegLightBuffer_t* pLightBuffer
                                     );

void HLASegLightUtilsSetMaxInt( HLASegData_t*  pData,
                                HLASegOut_t*   pOut
                              );

void HLASegLightUtilsSortFromBottomUp( HLASegLightDataRoi_t* pLightData,
                                       HLASegLightBuffer_t*  pLightBuffer
                                     );

void HLASegLightUtilsSplitLightList( HLASegLightBuffer_t*  pLightBuffer,
                                     HLASegLightDataRoi_t* pLightData_In,
                                     HLASegLightDataRoi_t* pLightData_Red,
                                     HLASegLightDataRoi_t* pLightData_Led,
                                     HLASegLightDataRoi_t* pLightData_Bright
                                   );

void HLASegLightUtilsRemoveDarkLights( const HLACameraData_t*                        pCamData,
                                       const HLA_t_SegmentationParametersBrightness* pParBrightness,
                                             HLASegLightDataRoi_t* restrict          pLightData,
                                             HLASegLightBuffer_t*                    pLightBuffer
                                     );
#endif