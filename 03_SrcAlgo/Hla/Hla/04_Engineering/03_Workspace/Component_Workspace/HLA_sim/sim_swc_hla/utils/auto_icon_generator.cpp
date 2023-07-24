/*! \file **********************************************************************

  COMPANY:                Continental, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    

  COMPONENT:              HLA

  MODULNAME:              auto_icon_generator.c

  DESCRIPTION:            Functions for icon generation chain.

  AUTHOR:                 Patrick Schillinger

  CREATION DATE:          05.05.2011

  VERSION:                $Revision: 1.2 $

  CHANGES:                

  ---*/ /*---
         
**************************************************************************** */
#include <direct.h>
#include "param.h"
#include "auto_icon_generator.h"

#include "stdafx.h"
#include "sim_headlightassist.h"

#ifdef __cplusplus
extern "C"
{
#endif
extern void HLAIconNormalize( const t_PixelData*  pSrcData,
                              const uint8         srcWidth,
                              const uint8         srcHeight,
                              const HLAIconData_t*pIcon,
                                    uint8*        pDstData
                            );
extern IconResultInfo_t HLAIconCheckSaturation(const HLAIconData_t* pIcon);
#ifdef __cplusplus
}
#endif

static void AutoIconGeneratorCopyIcon( const IcRect_t*      pImagerCroi,
                                       const ImageU16_t*    pInputImage,
                                             HLAIconData_t* pIcon
                                     );

static void AutoIconGeneratorWriteIcon( const int                    iconType,
                                        const RTE_HLAR_HeadlightType HeadLightType,
                                        const char*                  lightClass, 
                                        const uint8*                 pSrc,
                                        const HLAIconData_t*         pIconData,
                                        const uint32                 iconWidth, 
                                        const uint32                 iconHeight,
                                        const char*                  nameAddition );


static uint8 IconGeneratorCheckIconType(const char*       lightClass,
                                              HLATrack_t* pTrack,                                        
                                              char*       lightClassVehicle,
                                              char*       lightClassCity );

//HLA_GLOBAL_STATIC void HLAIconFillAdditionalFeatures( const HLACameraData_t*        pCamData,
//                                                      const HLATrack_t*             pTrack,
//                                                      const float32                 lightPosY,
//                                                            sint32*                 additionalFeatures );

static void HLAIconGeneratorFillAdditionalFeatures( const HLACameraData_t* restrict pCamData,
                                                    const HLATrack_t*      restrict pTrack,
                                                    const sint16                    lightPosY,
                                                          HLATracking3DOutput_t*    pTrackOutput,
                                                          sint32                    pAddFeatures[] );

static void HLAIconCheckMaxIntensity(  const uint8*          restrict  pSrcData,
                                       const HLAIconData_t*  restrict  pIcon,
                                       const sint16                    lightPosX,
                                       const sint16                    lightPosY,
                                             HLATrack_t*               pTrack
                                    );

static boolean AutoIconGeneratorInitGeneratorIcons(       HLATrack_t*             pTrackMinDist,
                                                    const HLACameraData_t*        pCamData );

enum
{
  ICON_NO_TYPE  = 0,     
  ICON_TYPE_VEHICLE,          
  ICON_TYPE_CITY,
  ICON_TYPE_VEHICLE_AND_CITY
};


HLA_GLOBAL_STATIC IconGeneratorDebugList_t    iconGeneratorDebugList;

/* Icon from even raw image */
static ARRAY  (HLAIconData_t, 1 , generatorIconDataEvenRaw);
static ARRAY2D(t_PixelData  , 1 , (HLA_ICON_ANALYSIS_MAX_SIZE_X * HLA_ICON_ANALYSIS_MAX_SIZE_Y), generatorIconEvenRaw); /* icon memory */
static ARRAY(uint8, HLA_ICON_ANALYSIS_MAX_SIZE_X * HLA_ICON_ANALYSIS_MAX_SIZE_Y, generatorIconNormalizedEvenRaw);

/* Icon from odd raw image */
static ARRAY  (HLAIconData_t, 1 , generatorIconDataOddRaw);
static ARRAY2D(t_PixelData  , 1 , (HLA_ICON_ANALYSIS_MAX_SIZE_X * HLA_ICON_ANALYSIS_MAX_SIZE_Y), generatorIconOddRaw); /* icon memory */
static ARRAY(uint8, HLA_ICON_ANALYSIS_MAX_SIZE_X * HLA_ICON_ANALYSIS_MAX_SIZE_Y, generatorIconNormalizedOddRaw);

/* additional features */
static ARRAY(sint32, HLA_ICONGENERATOR_ADDITIONAL_FEATURES , generatorAdditionalFeatures );

char currentRecFileName[1024];
char trainingSetName[256];
char labelFilePath[1024];
char iconGeneratorTargetPath_DatTraining[1024];
char iconGeneratorTargetPath_DatValidation[1024];

std::string old_str_labelFilePath;
int TrainValSelect = 1;

/* first pixel position of MTS ROI (transfered image) in absolute imager coordinates */
extern float32 simData_MTSRoiX1;
extern float32 simData_MTSRoiY1;

void AutoIconGeneratorInitNew(char* logFilePath)
{
  char recFileName[1024];
  FILE* fp;
  char* c;
  char backslash = 92; /* '\' = 92 */

  /* allocate memory for Icon of even raw image */
  (void)memset(generatorIconEvenRaw, 0, sizeof(generatorIconEvenRaw));
  (void)memset(&generatorIconDataEvenRaw[0], 0, sizeof(generatorIconDataEvenRaw));
  generatorIconDataEvenRaw[0].pData = generatorIconEvenRaw[0];

  /* allocate memory for Icon of odd raw image */
  (void)memset(generatorIconOddRaw, 0, sizeof(generatorIconOddRaw));
  (void)memset(&generatorIconDataOddRaw[0], 0, sizeof(generatorIconDataOddRaw));
  generatorIconDataOddRaw[0].pData = generatorIconOddRaw[0];

  /* allocate memory for debug icon list (needed for visualization) */
  (void)memset((void*)&iconGeneratorDebugList, 0, sizeof(iconGeneratorDebugList));
  
  
  /* get rec file name */
  strcpy(recFileName, logFilePath);
  c = strrchr(recFileName, '.');
  if (c)
  {
    *c = 0;
  }

  /* extend rec-file-path by Labelfile standard ending */
  sprintf(labelFilePath, "%s%s", recFileName, "_CSF2XX_IHCR_LDROI_Icon.ctl");

  
  /* check if Label file exists and is readable */
  fp = fopen(labelFilePath,"r"); 
  if (fp != NULL)
  {
    /* file exists and ready to read */
    fclose(fp);
  }
  else
  {
    sprintf(labelFilePath, "NotFound");
  }


  if(*logFilePath != 0)
  {
    c = strrchr(logFilePath, '/');
    if (c == NULL)
    {
      c = strrchr(logFilePath, backslash);
    }
    strcpy(currentRecFileName, c+1);
    c = strrchr(currentRecFileName, '.');
    if (c)
    {
      *c = 0x00;
    }
  }

  /* set target path for new "vehicle" icons */
  char autoicon_targetDir[256] = "";
  GetParamString("auto_icon_generator", "TARGET_DIR", 255, autoicon_targetDir);
  GetParamString("auto_icon_generator", "SET_NAME", 255, trainingSetName);

  /* set target path for new "vehicle" icons */
  _mkdir(std::string(autoicon_targetDir).c_str());
  _mkdir((std::string(autoicon_targetDir) + "/Training").c_str());
  _mkdir((std::string(autoicon_targetDir) + "/Validation").c_str());

  sprintf(iconGeneratorTargetPath_DatTraining,     "%s/Training", autoicon_targetDir);
  sprintf(iconGeneratorTargetPath_DatValidation,   "%s/Validation", autoicon_targetDir);
}

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
                      )
{
#ifndef HLA_LRF_ON_EVE
  FILE* fpLabel;
  
  HLATrack_t* pTrackMinDist = NULL;
  HLATrack_t* pTrack = NULL;
  
  uint8       iTrack;

  boolean     bIconsValid = b_FALSE;

  HLAIconData_t* pIconEvenRaw = NULL;
  HLAIconData_t* pIconOddRaw  = NULL;

  IconResultInfo_t iconResult;

  std::map <int,int> allreadyUsedTracks;

  char line[512];
  char temp[512];
  char lightClass[32];
  char lightClassVehicle[32] = "";
  char lightClassCity[32] = "";

  int xtl, ytl, xtr, ytr, xbr, ybr, xbl, ybl, idNum, numCorners;

  char* c;

  unsigned __int64 timestamp;

  uint8 iconType = ICON_NO_TYPE;

  iconGeneratorDebugList.count=0;

  allreadyUsedTracks.clear();
  
  /* check if current rec is for training set or for validation set */
  /* copy filepath of label file */
  std::string str_labelFilePath(labelFilePath);
  if (str_labelFilePath != old_str_labelFilePath)
  {   
    const int validationSetRatio = GetParamInt("auto_icon_generator", "VALIDATION_SET_RATIO", 0);

    if (validationSetRatio > 0)
    {
      TrainValSelect = (TrainValSelect + 1) % validationSetRatio;
      /* safe current label file path as 'new' old label file path */
      old_str_labelFilePath = str_labelFilePath;
    }
  }


  /* open label file */
  fpLabel = fopen(labelFilePath, "r");
  if (fpLabel != NULL)
  {
    /* search for "begindata" */
    while(fgets(line, 512, fpLabel) != NULL && !feof(fpLabel))
    {
      if (strstr(line, "begindata") != NULL)
      {
        /* stop searching */
        break;
      }
    }

    /* start scan... */
    while(fgets(line, 512, fpLabel) != NULL && !feof(fpLabel))
    {
      /* get data from line... */
      strcpy(temp, line);

      /* delete first column */
      c = strchr(temp, ',');
      if (c != NULL)
      {
        sprintf(temp, "%s", c + 1);
      }

      /* scan all data from the label also the not needed one to support older label files*/
      sscanf( temp,
              "%I64d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%s",
              &timestamp,                         /* time stamp of label */
              &idNum,                             /* Track ID (not needed)*/
              &numCorners,                        /* number of corners (not needed)*/
              &xtl,                               /* x-position of top left corner */
              &ytl,                               /* y-position of top left corner */
              &xtr,                               /* x-position of top right corner */
              &ytr,                               /* y-position of top right corner */
              &xbr,                               /* x-position of bottom right corner */
              &ybr,                               /* y-position of bottom right corner */
              &xbl,                               /* x-position of bottom left corner */
              &ybl,                               /* y-position of bottom left corner */
              &lightClass
           );

      if (timestamp == currentTimeStamp)
      {
        /* set center position of label */
        const int labelCenterX = (xtl + xtr + xbl + xbr) / 4;
        const int labelCenterY = (ytl + ytr + ybl + ybr) / 4;
        double    minDistance  = 9999.0f;

        
        /* find closest track to label center */
        iTrack = pTrackOutput->iStartTrack;
        while(iTrack < HLA_TRACKING_MAX_NUM_TRACKS)
        {
          pTrack = &(pTrackOutput->trackArray[iTrack]);
          if(pTrack->lost_time == 0)
          {
            /* check if track position is inside the box */
            const float32 distX   = std::abs(labelCenterX - (pTrack->xcenter - simData_MTSRoiX1));
            const float32 distY   = std::abs(labelCenterY - (pTrack->ycenter - simData_MTSRoiY1));
            const double distance = std::sqrt((distX*distX) + (distY*distY));

            if (distance < minDistance)
            {
              minDistance = distance;
              pTrackMinDist = pTrack;
            }
          }
          iTrack = pTrack->iNextTrack;
        }

        if (pTrackMinDist)
        {
          iconType = IconGeneratorCheckIconType( lightClass,
                                                 pTrackMinDist,
                                                 lightClassVehicle,
                                                 lightClassCity
                                               );
        }        

        std::pair<std::map<int,int>::iterator,boolean> ret;
        ret = allreadyUsedTracks.insert ( std::pair<int,int>(pTrackMinDist->TrackID,pTrackMinDist->TrackID) );

        if (   (iconType != ICON_NO_TYPE)
            && (pTrackMinDist)
            && (ret.second == b_TRUE)
           )
        {
          /* only write Icon if distance to label center is not too big */
          if (   (minDistance <= 3.9)
              || (   (minDistance <= 12)
                  && (   (strstr(lightClass, "White_Reflector#2") != NULL)
                      || (strstr(lightClass, "Red_Reflector#3")   != NULL)
                     )
                 )
             )
          {
            bIconsValid = AutoIconGeneratorInitGeneratorIcons( pTrackMinDist,
                                                               pCamData
                                                             );
              
            /* check if icon is valid */
            if (bIconsValid == b_TRUE)
            {
              pIconEvenRaw = &generatorIconDataEvenRaw[0];
              pIconOddRaw  = &generatorIconDataOddRaw[0];
              /* Copy Icon from Image to IconData !not directly from analysisicon.c todo: try to replace by function from analysisicon.c */
              AutoIconGeneratorCopyIcon( pImagerCroi,
                                         pInputImageEven,
                                         pIconEvenRaw
                                       );

              /* Copy Icon from Image to IconData !not directly from analysisicon.c todo: try to replace by function from analysisicon.c */
              AutoIconGeneratorCopyIcon( pImagerCroi,
                                         pInputImageOdd,
                                         pIconOddRaw
                                       );

              /* run normalization (direct from analysisicon.c) */
              HLAIconNormalize( pIconEvenRaw->pData,
                                pIconEvenRaw->Pos.Width,
                                pIconEvenRaw->Pos.Height,
                                pIconEvenRaw,
                                &generatorIconNormalizedEvenRaw[0]
                              );

              /* run normalization (direct from analysisicon.c) */
              HLAIconNormalize( pIconOddRaw->pData,
                                pIconOddRaw->Pos.Width,
                                pIconOddRaw->Pos.Height,
                                pIconOddRaw,
                                &generatorIconNormalizedOddRaw[0]
                              );

              HLAIconCheckMaxIntensity( &generatorIconNormalizedEvenRaw[0],
                                        pIconEvenRaw,
                                        pIconEvenRaw->Pos.lightX,
                                        pIconEvenRaw->Pos.lightY,
                                        pTrackMinDist
                                      );

              HLAIconCheckMaxIntensity( &generatorIconNormalizedOddRaw[0],
                                        pIconOddRaw,
                                        pIconOddRaw->Pos.lightX,
                                        pIconOddRaw->Pos.lightY,
                                        pTrackMinDist
                                      );

              if (pTrackMinDist->iconState.status.skippedTooDark == 1)
              {
                sprintf(lightClassVehicle,"LEDtooDark");
                sprintf(lightClassCity,   "LEDtooDark");
              }

              /* fill additional features (direct from analysisicon.c) */
              HLAIconGeneratorFillAdditionalFeatures( pCamData,
                                                      pTrackMinDist,
                                                      pTrackMinDist->ycenter,
                                                      pTrackOutput,
                                                      &generatorAdditionalFeatures[0]
                                                    );
              
              /* check if icon is saturated (direct from analyisicon.c) */
              iconResult = HLAIconCheckSaturation(pIconEvenRaw);

              if(iconResult.result != HLA_ICONRESULT_SATURATED)              
              {
                iconGeneratorDebugList.debugGenIcon[iconGeneratorDebugList.count].type = iconType;
                iconGeneratorDebugList.debugGenIcon[iconGeneratorDebugList.count].xPos = pTrackMinDist->xcenter;
                iconGeneratorDebugList.debugGenIcon[iconGeneratorDebugList.count].yPos = pTrackMinDist->ycenter;
                iconGeneratorDebugList.debugGenIcon[iconGeneratorDebugList.count].trackID = pTrackMinDist->TrackID;
                sprintf(iconGeneratorDebugList.debugGenIcon[iconGeneratorDebugList.count].labelTypeVehi,"%s",lightClassVehicle);
                sprintf(iconGeneratorDebugList.debugGenIcon[iconGeneratorDebugList.count].labelTypeCity,"%s",lightClassCity);
                iconGeneratorDebugList.count++;

                /* if relevant for vehicle classifier write Icon to vehicle output folder */
                if(   (iconType == ICON_TYPE_VEHICLE)
                   || (iconType == ICON_TYPE_VEHICLE_AND_CITY)
                  )
                {
                  /* write normalized Icon to PGM */
                  AutoIconGeneratorWriteIcon( ICON_TYPE_VEHICLE,
                                              HeadLightType,
                                              lightClassVehicle,
                                              &generatorIconNormalizedEvenRaw[0],
                                              pIconEvenRaw,
                                              HLA_ICON_ANALYSIS_MAX_SIZE_X,
                                              HLA_ICON_ANALYSIS_MAX_SIZE_Y,
                                              "Even"
                                            );

                  /* write normalized Icon to PGM */
                  AutoIconGeneratorWriteIcon( ICON_TYPE_VEHICLE,
                                              HeadLightType,
                                              lightClassVehicle,
                                              &generatorIconNormalizedOddRaw[0],
                                              pIconOddRaw,
                                              HLA_ICON_ANALYSIS_MAX_SIZE_X,
                                              HLA_ICON_ANALYSIS_MAX_SIZE_Y,
                                              "Odd"
                                           );        
                }

                /* if relevant for city classifier write Icon to city output folder */
                if(   (iconType == ICON_TYPE_CITY)
                   || (iconType == ICON_TYPE_VEHICLE_AND_CITY)
                  )
                {
                  /* write normalized Icon to File */
                  AutoIconGeneratorWriteIcon( ICON_TYPE_CITY,
                                              HeadLightType,
                                              lightClassCity,
                                              &generatorIconNormalizedEvenRaw[0],
                                              pIconEvenRaw,
                                              HLA_ICON_ANALYSIS_MAX_SIZE_X,
                                              HLA_ICON_ANALYSIS_MAX_SIZE_Y,
                                              "Even"
                                            );
                  /* write normalized Icon to File */
                  AutoIconGeneratorWriteIcon( ICON_TYPE_CITY,
                                              HeadLightType,
                                              lightClassCity,
                                              &generatorIconNormalizedOddRaw[0],
                                              pIconOddRaw,
                                              HLA_ICON_ANALYSIS_MAX_SIZE_X,
                                              HLA_ICON_ANALYSIS_MAX_SIZE_Y,
                                              "Odd"
                                            );     
                }
              }

            }
          }
        }
      }
    }    
    fclose(fpLabel);
  }
#endif /* #ifndef HLA_LRF_ON_EVE */
}

/* similar to hla_icon.c HLAIconCopyIcons() */
static void AutoIconGeneratorCopyIcon( const IcRect_t*      pImagerCroi,
                                       const ImageU16_t*    pInputImage,
                                             HLAIconData_t* pIcon
                                     )
{
  sint32 rowOffsetPixels = pInputImage->sImgHeader.iRowBytes / pInputImage->sImgHeader.iPixelBytes;

  HLAIconData_t* restrict pIconData = pIcon;


  const t_PixelData* restrict pSrc =  pInputImage->aImageData
                                      + ((pIconData->Pos.Y1 - pImagerCroi->ui16_Y) * (uint32) rowOffsetPixels)
                                      + (pIconData->Pos.X1  - pImagerCroi->ui16_X);

  const t_PixelData* pDst = pIconData->pData;


  uint32 y;

  for (y=0; y<pIconData->Pos.Height; y++ )
  {
    (void)memcpy((void*)pDst, (const void*)pSrc, sizeof(t_PixelData) * pIconData->Pos.Width);
    pDst += pIconData->Pos.Width;
    pSrc += rowOffsetPixels;
  }

}



static void AutoIconGeneratorWriteIcon( const int                    iconType,
                                        const RTE_HLAR_HeadlightType HeadLightType,
                                        const char*                  lightClass,
                                        const uint8*                 pSrc,
                                        const HLAIconData_t*         pIconData,
                                        const uint32                 iconWidth, 
                                        const uint32                 iconHeight,
                                        const char*                  nameAddition
                                        )
{
  FILE* fpTxt;

  char txtName[512];
  char headLightType[512];
  char* targetDir;

  /* check if Icon is for Training or Validation */
  if (TrainValSelect != 0)
  {
    targetDir = iconGeneratorTargetPath_DatTraining;
  }
  else
  {
    targetDir = iconGeneratorTargetPath_DatValidation;
  }

  /* check headlampType */
  if (HeadLightType == RTE_HLA_LTYPE_HALOGEN)
  {
    sprintf(headLightType,"%s", "Halogen");
  }
  else
  {
    sprintf(headLightType,"%s", "XenonLED");
  }

  /* path for txt File with Icons */
  if(iconType == ICON_TYPE_VEHICLE)
  {
    sprintf(txtName, "%s/%s_Vehicle_%s_%s_%s.dat", targetDir, trainingSetName, headLightType, lightClass, nameAddition);
  }
  if(iconType == ICON_TYPE_CITY)
  {
    sprintf(txtName, "%s/%s_City_%s_%s_%s.dat", targetDir, trainingSetName, headLightType, lightClass, nameAddition);
  }


  /* write Icon to .dat File */
  fpTxt = fopen(txtName, "a");
  
  if (fpTxt != NULL)
  {
    fprintf(fpTxt, "%i;", (int)(pIconData->Pos.lightX - pIconData->Pos.X1));
    fprintf(fpTxt, "%i;", (int)(pIconData->Pos.lightY - pIconData->Pos.Y1));

    for (int i=0; i<HLA_ICONGENERATOR_ADDITIONAL_FEATURES ; i++)
    {
      fprintf(fpTxt, "%i;", generatorAdditionalFeatures[i]);
    }

    uint32 yPos;
    uint32 xPos;

    for (yPos=0; yPos<iconHeight; yPos++ )
    {
      for(xPos=0; xPos<iconWidth; xPos++ )
      {
        fprintf(fpTxt, "%d;", *pSrc );
        pSrc++;
      }
    }
    fprintf(fpTxt, "\n");

    fclose(fpTxt);
  }


}



static uint8 IconGeneratorCheckIconType( const  char*       lightClass,
                                                HLATrack_t* pTrack,
                                                char*       lightClassVehicle,
                                                char*       lightClassCity
                                       )
{ 
  uint8 iconType = ICON_NO_TYPE;
  pTrack->iconState.status.iconRequested = 0;
  pTrack->iconStateCity.status.iconRequested = 0;

  /* check if Vehicle Icon Label is set AND if Vehicle Icon is suitable */

  /* potential Ahead? */
  if (   (pTrack->RedLightCnt  > 5  )
      || (   (pTrack->idResStat.isOtherColor.result != HLA_RESULT_OTHER_COLOR)
          && (pTrack->idResStat.isWhiteOrRed.result == HLA_RESULT_RED)
         )
      || (pTrack->statusAnalysisVehicle.isMovingNonWhite == 1)
     )
  {
    pTrack->iconState.status.iconRequested = 1;
    iconType = ICON_TYPE_VEHICLE;

    if (   (strstr(lightClass, "White_Reflector#2")  != NULL)
        || (strstr(lightClass, "Red_Reflector#3")    != NULL)
       )
    {
      sprintf ( lightClassVehicle, "(Red_Reflector)" );
    }

    if (strstr(lightClass, "Traffic_Ahead#1")    != NULL)
    {
      sprintf ( lightClassVehicle, "(Traffic_Ahead)" );
    }

    if (strstr(lightClass, "Red_Light#7")        != NULL)
    {
       sprintf ( lightClassVehicle, "(Red_Light)" );
    }

    if (strstr(lightClass, "Street_Lights#4") != NULL)
    {
      sprintf ( lightClassVehicle, "(Street_Lights_red)" );
    }
  }
  /* potential Oncoming? */
  else if (   (pTrack->idResStat.isCenterBright.result  == HLA_RESULT_POSITIVE)
           || (pTrack->idResStat.isTooBright.result     == HLA_RESULT_POSITIVE)
           || (pTrack->idResStat.isLateralBright.result == HLA_RESULT_POSITIVE)
           || (pTrack->idResStat.isOncomingPair.result  == HLA_RESULT_POSITIVE)
           || (pTrack->idResStat.isExtremeBright.result == HLA_RESULT_POSITIVE)
           || (pTrack->idResStat.isContraMotion.result  == HLA_RESULT_POSITIVE)
           || (pTrack->idResStat.isDynamicMotion.result == HLA_RESULT_POSITIVE)
           || (pTrack->idResStat.isHighwayBright.result == HLA_RESULT_POSITIVE)
          )
  {
    pTrack->iconState.status.iconRequested = 1;
    iconType = ICON_TYPE_VEHICLE;

    if (   (strstr(lightClass, "White_Reflector#2")  != NULL)
        || (strstr(lightClass, "Red_Reflector#3")    != NULL)
       )
    {
      sprintf ( lightClassVehicle, "(White_Reflector)" );
    }

    if (strstr(lightClass, "Traffic_Oncoming#0") != NULL)
    {
      sprintf ( lightClassVehicle, "(Traffic_Oncoming)" );
    }

    if (strstr(lightClass, "Street_Lights#4") != NULL)
    {
      sprintf ( lightClassVehicle, "(Street_Lights_white)" );
    }
  }

  /* LED pulsed lights? */
  if (   (pTrack->statusAnalysisMisc.isAboveROI == 0)
      && (pTrack->idResStat.isPulsedLight.result == HLA_RESULT_POSITIVE)
     )
  {
    pTrack->iconState.status.iconRequested = 1;
    iconType = ICON_TYPE_VEHICLE;

    if (strstr(lightClass, "Traffic_Ahead#1")    != NULL)
    {
      sprintf ( lightClassVehicle, "(LED_Traffic_Ahead)" );
    }
    else if (   (strstr(lightClass, "White_Reflector#2")  != NULL)
             || (strstr(lightClass, "Red_Reflector#3")    != NULL)
             || (strstr(lightClass, "Red_Light#7")        != NULL)
             || (strstr(lightClass, "Street_Lights#4")    != NULL)
            )
    {
      sprintf ( lightClassVehicle, "(LED_No_Traffic)" );
    }
  }
      

  /* check if City Icon Label is set AND if City Icon is suitable */

  if (   (pTrack->statusAnalysisMisc.isSceneStreetLamp == 1)
      || (pTrack->statusAnalysisMisc.isSceneStreetLampLowInt == 1)
      || (pTrack->statusAnalysisMisc.isLeavingStreetLamp == 1)
     )
  {
    pTrack->iconStateCity.status.iconRequested = 1;
    /* if Icon is also suitable for Vehicle set Icon Type to both */
    if(iconType == ICON_TYPE_VEHICLE)
    {
      iconType = ICON_TYPE_VEHICLE_AND_CITY;
    }
    else
    {
      iconType = ICON_TYPE_CITY;
    }

    if (strstr(lightClass, "City_Light#8")       != NULL)
    {
      sprintf ( lightClassCity, "(City_Light)" );
    }
    if (strstr(lightClass, "No_City_Light#9")    != NULL)
    {
      sprintf ( lightClassCity, "(No_City_Light)" );
    }
    if (strstr(lightClass, "Traffic_Oncoming#0") != NULL)
    {
      sprintf ( lightClassCity, "(Traffic_Oncoming)" );
    }
    if (strstr(lightClass, "Traffic_Ahead#1")    != NULL)
    {
      sprintf ( lightClassCity, "(Traffic_Ahead)" );
    }
    if (strstr(lightClass, "White_Reflector#2")  != NULL)
    {
      sprintf ( lightClassCity, "(White_Reflector)" );
    }
    if (strstr(lightClass, "Red_Reflector#3")    != NULL)
    {
      sprintf ( lightClassCity, "(Red_Reflector)" );
    }
    if (strstr(lightClass, "Red_Light#7")        != NULL)
    {
      sprintf ( lightClassCity, "(Red_Light)" );
    }
  }


  return iconType;
}

static  void HLAIconCheckMaxIntensity(  const uint8*           restrict  pSrcData,
                                        const HLAIconData_t*   restrict  pIcon,
                                        const sint16                     lightPosX,
                                        const sint16                     lightPosY,
                                        HLATrack_t*                      pTrack
                                     )
{
  const uint8 srcWidth  = pIcon->Pos.Width;
  const uint8 srcHeight = pIcon->Pos.Height;
  const uint16 srcX1    = pIcon->Pos.X1;
  const uint16 srcY1    = pIcon->Pos.Y1;

  uint8 x, y;

  uint8 brightestColorValue = 0u;

  uint8 brightestSubsampledValue = 0u;

  const uint8 startX = (uint8)CML_MinMax(HLA_ICON_FULLIMAGE_WIDTH  / 2, srcWidth  - (HLA_ICON_FULLIMAGE_WIDTH  / 2), (lightPosX - srcX1) - HLA_ICON_PREPROCESS_PEAK_SEARCH_AREA);
  const uint8 endX   = (uint8)CML_MinMax(HLA_ICON_FULLIMAGE_WIDTH  / 2, srcWidth  - (HLA_ICON_FULLIMAGE_WIDTH  / 2), (lightPosX - srcX1) + HLA_ICON_PREPROCESS_PEAK_SEARCH_AREA);
  const uint8 endY   = (uint8)CML_MinMax(HLA_ICON_FULLIMAGE_HEIGHT / 2, srcHeight - (HLA_ICON_FULLIMAGE_HEIGHT / 2), (lightPosY - srcY1) + HLA_ICON_PREPROCESS_PEAK_SEARCH_AREA);
  const uint8 startY = (uint8)CML_MinMax(HLA_ICON_FULLIMAGE_HEIGHT / 2, srcHeight - (HLA_ICON_FULLIMAGE_HEIGHT / 2), (lightPosY - srcY1) - HLA_ICON_PREPROCESS_PEAK_SEARCH_AREA);

  /* find the brightest pixel close to the center of the source image */
  for (y = startY; y <= endY; y++)
  {
    const uint8* pSrc = pSrcData + (y * srcWidth) + startX;
    const uint8* pSrcBelow = pSrc + srcWidth;

    for (x = startX; x <= endX; x++)
    {
      const uint8 colorValue = *pSrc;
      const uint8 subsampledValue = (*(pSrc) + *(pSrc+1) + *(pSrcBelow) + *(pSrcBelow+1)) / 4;

      if (colorValue > brightestColorValue)
      {
        brightestColorValue = colorValue;
      }

      pSrc++;
      pSrcBelow++;
    }
  }

  if (brightestColorValue < 50)
  {
    pTrack->iconState.status.skippedTooDark = 1;
  }

}


static void HLAIconGeneratorFillAdditionalFeatures( const HLACameraData_t* restrict pCamData,
                                                    const HLATrack_t*      restrict pTrack,
                                                    const sint16                    lightPosY,
                                                          HLATracking3DOutput_t*    pTrackOutput,
                                                          sint32                    pAddFeatures[]
)
{
  /* [0]: relative distance of light's y-position from y-Focus */
  pAddFeatures[0] = CML_MinMax(-HLA_ICON_LRF_FIXPOINT_SCALE, HLA_ICON_LRF_FIXPOINT_SCALE, (lightPosY - pCamData->FOE_y) * (HLA_ICON_LRF_FIXPOINT_SCALE / 200));

  /* [1]: absolute distance of light's y-position from y-Focus */
  pAddFeatures[1] = CML_u_Abs(pAddFeatures[0]);

  /* [2]: dynamic motion result: negative = MIN , positive = MAX , else = 0 */
  pAddFeatures[2] = ( (uint8) pTrack->anaResStat.isDynamicMotion.result == HLA_RESULT_NEGATIVE) ? 
                    -HLA_ICON_LRF_FIXPOINT_SCALE : 
                    (( (uint8) pTrack->anaResStat.isDynamicMotion.result == HLA_RESULT_POSITIVE) ?
                          HLA_ICON_LRF_FIXPOINT_SCALE : 
                          0 );

  /* [3]: static high result: negative = MIN , positive = MAX , else = 0 */
  pAddFeatures[3] = ( (uint8) pTrack->anaResStat.isStaticHigh.result == HLA_RESULT_NEGATIVE) ?
                    -HLA_ICON_LRF_FIXPOINT_SCALE : 
                    (( (uint8) pTrack->anaResStat.isStaticHigh.result == HLA_RESULT_POSITIVE) ? 
                          HLA_ICON_LRF_FIXPOINT_SCALE : 
                          0 );

  /* [4]: confidence of Street Lamp identification */
  pAddFeatures[4] = pTrack->idResStat.isStreetLamp.confidence * (HLA_ICON_LRF_FIXPOINT_SCALE / 32);

  /* [5]: confidence of Chain of Light identification */
  pAddFeatures[5] = pTrack->idResStat.isChainOfLights.confidence * (HLA_ICON_LRF_FIXPOINT_SCALE / 32);

  /* [6]: confidence of White or Red color identification */
  pAddFeatures[6] = pTrack->idResStat.isWhiteOrRed.confidence * (HLA_ICON_LRF_FIXPOINT_SCALE / 32);

  /* [7]: confidence of Static High identification */
  pAddFeatures[7] = pTrack->idResStat.isStaticHigh.confidence * (HLA_ICON_LRF_FIXPOINT_SCALE / 32);

  /* [8]: Is Bright Object: positive = MAX , negative = 0 */
  //pAddFeatures[8] = (pTrack->statusAnalysisMisc.isBrightObject == 1) ? HLA_ICON_LRF_FIXPOINT_SCALE : 0;

  //HLASegLineRegion_t* pLevelRegion = NULL;
  //uint32 size[8];
  //for(int i= 0; i<8; i++)
  //{
  //  size[i] = 0.0f;
  //}
  //uint8 region;

  ///* check if light_ref is valid */
  //if (   (pTrack->light_ref != NULL)
  //    && (pTrack->light_ref->pRegion != NULL)
  //   )
  //{
  //  pLevelRegion = pTrack->light_ref->pRegion;
  //  size[pLevelRegion->Level] = pLevelRegion->integratedSize;

  //  while(pLevelRegion->pRegionBelow != NULL)
  //  {
  //     pLevelRegion = pLevelRegion->pRegionBelow;
  //     size[pLevelRegion->Level] = pLevelRegion->integratedSize;
  //  }
  //}


  //pAddFeatures[0] = pTrack->track_time;
  //pAddFeatures[1] = (sint32)(100.0f*pTrack->delta_x_lp);
  //pAddFeatures[2] = (sint32)(100.0f*pTrack->delta_y_lp);
  //pAddFeatures[3] = (sint32)(100.0f*pTrack->delta_x_lp_lt);
  //pAddFeatures[4] = (sint32)(100.0f*pTrack->delta_y_lp_lt);
  //pAddFeatures[5] = pTrack->AverageMaxInt;
  //pAddFeatures[6] = pTrack->MaxInt;
  //pAddFeatures[7] = pTrack->xcenter;
  //pAddFeatures[8] = pTrack->ycenter;
  //pAddFeatures[9]  = (sint32)pTrack->xwmin100;
  //pAddFeatures[10] = (sint32)pTrack->xwmax100;
  //pAddFeatures[11] = (sint32)size[0];
  //pAddFeatures[12] = (sint32)size[1];
  //pAddFeatures[13] = (sint32)size[2];
  //pAddFeatures[14] = (sint32)size[3];
  //pAddFeatures[15] = (sint32)size[4];
  //pAddFeatures[16] = (sint32)size[5];
  //pAddFeatures[17] = (sint32)size[6];
  //pAddFeatures[18] = (sint32)size[7];

  //HLAPair_t*  pPair;

  //if (pTrack->iPairID != 255)
  //{ 
  //  pPair = &(pTrackOutput->pairArray[pTrack->iPairID]);
  //  pAddFeatures[19] = (sint32)pPair->pd;
  //}
  //else
  //{
  //  pAddFeatures[19] = -1;
  //}

}


static boolean AutoIconGeneratorInitGeneratorIcons(       HLATrack_t*               pTrackMinDist,
                                                    const HLACameraData_t*          pCamData
                                                  )
{
  boolean bIconsValid = b_FALSE;
  /* begin pseudo icon.c HLAIconSetBox*/
  /* calculate coordinates of top left and the bottom rights corners of the icon box */
  const int iconPosX_even = pTrackMinDist->xcenter - (pTrackMinDist->delta_x/2);
  const int iconPosY_even = pTrackMinDist->ycenter - (pTrackMinDist->delta_y/2);

  const int iconPosX_odd  = pTrackMinDist->xcenter;
  const int iconPosY_odd  = pTrackMinDist->ycenter;

  int xTopLeft_even      = iconPosX_even - (HLA_ICON_ANALYSIS_MAX_SIZE_X / 2);
  int yTopLeft_even      = iconPosY_even - (HLA_ICON_ANALYSIS_MAX_SIZE_Y / 2);
  int xBottomRight_even  = iconPosX_even + (HLA_ICON_ANALYSIS_MAX_SIZE_X / 2);
  int yBottomRight_even  = iconPosY_even + (HLA_ICON_ANALYSIS_MAX_SIZE_Y / 2);

  int xTopLeft_odd      = iconPosX_odd - (HLA_ICON_ANALYSIS_MAX_SIZE_X / 2);
  int yTopLeft_odd      = iconPosY_odd - (HLA_ICON_ANALYSIS_MAX_SIZE_Y / 2);
  int xBottomRight_odd  = iconPosX_odd + (HLA_ICON_ANALYSIS_MAX_SIZE_X / 2);
  int yBottomRight_odd  = iconPosY_odd + (HLA_ICON_ANALYSIS_MAX_SIZE_Y / 2);

  /* shift icon top/left position to red pixel */
  if(!HLAIsEven(yTopLeft_even))
  {
    yTopLeft_even++;
    yBottomRight_even++;
  }
  if(!HLAIsEven(xTopLeft_even))
  {
    xTopLeft_even++;
    xBottomRight_even++;
  }
  if(!HLAIsEven(yTopLeft_odd))
  {
    yTopLeft_odd++;
    yBottomRight_odd++;
  }
  if(!HLAIsEven(xTopLeft_odd))
  {
    xTopLeft_odd++;
    xBottomRight_odd++;
  }

  /* check if icon box is within HLA ROI */
  if(   (xTopLeft_even     > pCamData->RoiX1)
     && (yTopLeft_even     > pCamData->RoiY1)
     && (xBottomRight_even < pCamData->RoiX2)
     && (yBottomRight_even < pCamData->RoiY2)
     && (xTopLeft_odd      > pCamData->RoiX1)
     && (yTopLeft_odd      > pCamData->RoiY1)
     && (xBottomRight_odd  < pCamData->RoiX2)
     && (yBottomRight_odd  < pCamData->RoiY2)
    )
  {
    /* erase all old stuff and fill tempIcon with new information */
    (void)memset(&generatorIconDataEvenRaw[0], 0, sizeof(generatorIconDataEvenRaw));
    (void)memset(&generatorIconEvenRaw, 0, sizeof(generatorIconEvenRaw));
    (void)memset(&generatorAdditionalFeatures, 0, sizeof(generatorAdditionalFeatures));
    pTrackMinDist->iconState.status.skippedTooDark = 0;
    generatorIconDataEvenRaw[0].pData       = generatorIconEvenRaw[0];
    generatorIconDataEvenRaw[0].pTrackRef   = pTrackMinDist;
    generatorIconDataEvenRaw[0].Pos.X1      = xTopLeft_even;
    generatorIconDataEvenRaw[0].Pos.X2      = xBottomRight_even;
    generatorIconDataEvenRaw[0].Pos.Width   = HLA_ICON_ANALYSIS_MAX_SIZE_X;
    generatorIconDataEvenRaw[0].Pos.Y1      = yTopLeft_even;
    generatorIconDataEvenRaw[0].Pos.Y2      = yBottomRight_even;
    generatorIconDataEvenRaw[0].Pos.Height  = HLA_ICON_ANALYSIS_MAX_SIZE_Y;
    generatorIconDataEvenRaw[0].Pos.lightX  = iconPosX_even;
    generatorIconDataEvenRaw[0].Pos.lightY  = iconPosY_even;

    /* erase all old stuff and fill tempIcon with new information */
    (void)memset(&generatorIconDataOddRaw[0], 0, sizeof(generatorIconDataOddRaw));
    (void)memset(&generatorIconOddRaw, 0, sizeof(generatorIconOddRaw));
    (void)memset(&generatorAdditionalFeatures, 0, sizeof(generatorAdditionalFeatures));
    pTrackMinDist->iconState.status.skippedTooDark = 0;
    generatorIconDataOddRaw[0].pData       = generatorIconOddRaw[0];
    generatorIconDataOddRaw[0].pTrackRef   = pTrackMinDist;
    generatorIconDataOddRaw[0].Pos.X1      = xTopLeft_odd;
    generatorIconDataOddRaw[0].Pos.X2      = xBottomRight_odd;
    generatorIconDataOddRaw[0].Pos.Width   = HLA_ICON_ANALYSIS_MAX_SIZE_X;
    generatorIconDataOddRaw[0].Pos.Y1      = yTopLeft_odd;
    generatorIconDataOddRaw[0].Pos.Y2      = yBottomRight_odd;
    generatorIconDataOddRaw[0].Pos.Height  = HLA_ICON_ANALYSIS_MAX_SIZE_Y;
    generatorIconDataOddRaw[0].Pos.lightX  = iconPosX_odd;
    generatorIconDataOddRaw[0].Pos.lightY  = iconPosY_odd;

    bIconsValid = b_TRUE;
  }

  return bIconsValid;
}
