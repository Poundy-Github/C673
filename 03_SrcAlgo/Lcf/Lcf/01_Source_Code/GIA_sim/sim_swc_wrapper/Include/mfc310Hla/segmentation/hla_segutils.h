/*! \file **   ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    Ti DSP

  COMPONENT:              HLA

  MODULNAME:              hla_segutils.h

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_segutils.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:41CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:30CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:06:00CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/03/25 18:48:14CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj
  **************************************************************************** */

#ifndef HLA_SEGMENTATION_UTILS_INCLUDED
#define HLA_SEGMENTATION_UTILS_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include <math.h>
#include <string.h>
#include "hla_base.h" 
#include "hlar_ext.h"
#include "hla_debug.h"
#include "hla_imager.h"

#ifdef HLA_SEGMENTATION_ON_EVE
#include "hla_eve_ext.h"
#endif


/******************************************************************************
* MACROS / DEFINES
******************************************************************************/
#define HLA_SEG_LIGHT_MAX_INT_HIST_LEN  5

/******************************************************************************
* TYPEDEFS
*****************************************************************************/
typedef struct  
{
  uint16 x;
  uint16 y1;
  uint16 y2;
  uint16 yMax;
} HLASegPreProcImage_Line_t;

typedef struct  
{
  ARRAY(HLASegPreProcImage_Line_t, HLA_SEG_MAX_NUM_SEG_LINES, Line);
  uint16 nLines;
} HLASegPreProcImage_Level_t;

typedef struct  
{
  ARRAY(HLASegPreProcImage_Level_t, RTE_HLA_SEG_MAX_NUM_LEVELS, Level);
} HLASegPreProcImage_t;

typedef struct
{
  HLASegmentationParametersLightLevel_t Level_lux[HLA_SEG_LEVEL_LIGHT+1]; /* [lux] level dependent parameter */
  HLASegmentationParametersLightLevel_t Level_gv[HLA_SEG_LEVEL_LIGHT+1];  /* [greyvalue] level dependent parameter */
} HLASegmentationIntThresholdLight_t;

typedef struct
{
  uint16 Level[HLA_SEG_LEVEL_LIGHT+1]; /* normal lights */
} HLASegBinImgData_ThresLevel_GV_t;

typedef struct
{
  float32 Level[HLA_SEG_LEVEL_LIGHT+1]; /* normal lights */
} HLASegBinImgData_ThresLevel_Lux_t;

typedef struct
{
  HLASegBinImgData_ThresLevel_GV_t  GV;  /* greyvalue threshold */
  HLASegBinImgData_ThresLevel_Lux_t Lux; /* lux threshold */
} HLASegBinImgData_Threshold_t; 


typedef struct
{
  /* intensity threshold */
  HLASegBinImgData_Threshold_t Threshold;
} HLASegBinImgData_t;

typedef struct
{
  uint8 iRegion;          /* start position */
  uint8 nRegions;         /* number of regions of this level */
  uint8 nRegionsSuperior; /* number of superiors regions */
}HLASegLineRegionLevel_t;

typedef struct
{
  uint32               ui32_InterfaceVersionNumber;  /*!< Region buffer interface number */    
  AlgoCycleCounter_t   HLAS_Cnt;                     /*!< HLAS cycle counter   */
  AlgoCycleCounter_t   FrameCnt;                     /*!< [1] image counter    */  
  AlgoDataTimeStamp_t  TimeStamp_Image_us;           /*!< [us] Image Timestamp */
  uint8                nRegions;                     /* number of all regions */
  uint8                nRegionsSuperior;             /* number of all superior regions */
  uint8                iRegionFree;                  /* next free region */
  ARRAY(HLASegLineRegionLevel_t, RTE_HLA_SEG_MAX_NUM_LEVELS, Level);
  ARRAY(HLASegLineRegion_t, HLA_SEG_MAX_NUM_REGIONS, Region);
} HLASegLineRegionBuffer_t;


typedef struct
{
  uint8 iLight;
  uint8 nLights_Raw;  /* number of detected lights before light reduction     */
  uint8 nLights[2];   /* number of detected lights after 1st [index 0, RTE output] and 2nd [index 1, hla tracking input] light reduction */
} HLASegLightDataRoi_t;


typedef struct
{
  uint16 iHist;
  ARRAY(uint16, HLA_SEG_LIGHT_MAX_INT_HIST_LEN, Hist);
  uint16 maxInt;
} HLASegLightMaxInt_t;

typedef struct
{
  uint8 iLightFree; /* next free light */

  HLASegLightDataRoi_t AboveRoi;
  /* function roi */
  HLASegLightDataRoi_t FunctRoi;
  /* sub category in function roi */
  HLASegLightDataRoi_t FunctRoi_Red;    /* potential Red lights   */
  HLASegLightDataRoi_t FunctRoi_Led;    /* potential Led lights   */
  HLASegLightDataRoi_t FunctRoi_Bright; /* bright lights          */
} HLASegLightData_t;


typedef struct
{
  /* subsampled image */
  /* accumulated intensity [12Bit] */
  ARRAY2D(uint32, HLA_SEG_INTENSITY_SUB_IMG_HEIGHT, HLA_SEG_INTENSITY_SUB_IMG_WIDTH, accInt);
  /* current subsampled image row {0,1,2,3,4} */
  uint16        currentRow;
  /* accumulated intensity counters */
  ARRAY(uint16, HLA_SEG_INTENSITY_SUB_IMG_HEIGHT, accCnt);
  /* accumulated intensity: pixel offset for the current row */
  /* from row to row the offset changes (+16pixel)           */
  /* offset = 0, 16, 32 , 64, ..  240 */
  uint16        accPixOffset;
  /* count the calls to the accumulateIntensities function per frame */
  /* ~CodeReview ~ID:99fbf6eb37dc8b9ab49e315d76417175 ~Reviewer:CW01\muellerr5 ~Date:03.07.2012 ~Priority:3 ~Comment:Please add Comment ! This is used in measfreeze only. */
  uint16        accIntCallCounter;
} HLASegSubImageData_t;

typedef struct
{
  AlgoCycleCounter_t      HLAS_Cnt;           /*!< HLAS cycle counter   */
  AlgoCycleCounter_t      FrameCnt;           /*!< [1] image counter    */  
  AlgoDataTimeStamp_t     TimeStamp_Image_us; /*!< [us] Image Timestamp */

  HLASegBinImgData_t      BinarizeImgData;
  HLASegLightData_t       LightData;
  HLASegSubImageData_t    SubImage;

  HLASegLightMaxInt_t     MaxInt;
  
  uint32                  EveErrorCode;
} HLASegData_t;

typedef struct
{
  /* subsampled image size = 5 x 5 */
  /* SubImage_EndRow defines the end line (absolute image coordinates) of the subsampled image segment */
  ARRAY(uint16, HLA_SEG_INTENSITY_SUB_IMG_HEIGHT, SubImage_EndRow);

  /* brightness state: day, twilight, night */
  RTE_HLAR_BrightnessState eBrightnessState;

  /* vehicle motion state e.g. DYN_VHEMOT_STAND_STILL, DYN_VHEMOT_ROLL_FWD,... */
  HLA_t_eMovementState  eMoveState;

  /* number of tracks in the last frame */
  uint8 numTracks_LastFrame;

  /* debug switch */
  /* - auto threshold off */
  /* - night segmentation always on */
  RTE_HLA_TestMode TestMode;
} HLASegIn_t;

/******************************************************************************
* GLOBAL FUNCTION PROTOTYPES
******************************************************************************/

void HLASegUtilsFindMaxima_Lux( HLASegLightDataRoi_t* pLightData,
                                HLASegLightBuffer_t*  pLightBuffer
                              );

void HLASegUtilsFindMaxima( const HLA_t_CameraParameter* pCameraParameter,
                            const HLASegLineBuffer_t*    pLineBuffer,
                                  t_PixelData*           pImg,
                            const HLASegLightDataRoi_t*  pLightData,
                                  HLASegLightBuffer_t*   pLightBuffer
                          );

void HLASegUtilsSaveMaxima( const HLA_t_CameraParameter* pCameraParameter,
                                  t_PixelData*           pImg,
                                  t_PixelData*           ppixel_Max,
                                  HLASegLight_t*         pLight
                          );

void HLASegUtilsBinarizeImage_SetThreshold(const HLA_t_SegmentationParametersBrightness* pParBrightness, 
                                                 HLASegData_t*                           pData
                                          );

void HLASegUtilsCopyFingerPrint( const HLAR_t_RequiredInputs* ps_In,
                                 const t_PixelData*           pImg, 
                                       HLA_t_Fingerprint*     pFingerprint
                               );

#endif
