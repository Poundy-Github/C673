/*! \file **********************************************************************

  COMPANY:                Continental, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    

  COMPONENT:              HLA

  MODULNAME:              auto_icon_generator.h

  DESCRIPTION:            Functions for icon generation chain.

  AUTHOR:                 Patrick Schillinger

  CREATION DATE:          05.05.2011

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
         
**************************************************************************** */
#ifndef AUTO_ICON_GENERATOR_H
#define AUTO_ICON_GENERATOR_H

#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif
#include "hla_camera.h"
#include "hla_analysisicon.h"
#include "hla_utils.h"
#ifdef __cplusplus
}
#endif

void AutoIconGeneratorInitNew(char* logFilePath);

void AutoIconGenerator( const IcRect_t*              pImagerCroi,
                        const HLACameraData_t*       pCamData,
                        const RTE_HLAR_HeadlightType HeadLightType,
                        const ImageU16_t*            pInputImageEven,
                        const ImageU16_t*            pInputImageOdd,
                        const ImageU16_t*            pInputImageEvenY0,
                        const ImageU8_t*             pInputImageEvenU1,
                        const ImageU8_t*             pInputImageEvenV1,
                              uint64                 currentTimeStamp,
                              HLATracking3DOutput_t* pTrackOutput
                      );

#define HLA_ICONGENERATOR_ADDITIONAL_FEATURES 8

typedef struct  
{
  uint32 xPos;
  uint32 yPos;
  uint32 type;
  char labelTypeVehi[128];
  char labelTypeCity[128];
  sint16 trackID;
} DebugGenIcon_t;


typedef struct
{
  DebugGenIcon_t debugGenIcon[128];
  uint8 count;
} IconGeneratorDebugList_t;

#endif
