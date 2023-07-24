/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_labels.cpp

  DESCRIPTION:            Drawing of database labels

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.2 $

  ---*/ /*---

**************************************************************************** */

#include "stdafx.h"

#include "sim_hla_visu_labels.h"

#include "resource.h"

#include "sim_swc_gdv_ifc.h"
#include "sim_gdvfont_ifc.h"

#include "HLA_DB.h"

#include <string>
#include <cmath>

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLu32.lib")

CSimHlaVisuLabels::CSimHlaVisuLabels()
{
}

CSimHlaVisuLabels::~CSimHlaVisuLabels()
{
}

void CSimHlaVisuLabels::Init()
{
}

void CSimHlaVisuLabels::drawLabelOverlay(const ISimRenderContext*  pContext,
                                         const unsigned __int64*   uiTimeStamp,
                                               int                 textPosX,
                                               int                 textPosY,
                                               CSimVisuSubMenu*    pInterfacesMenu 
                                        )
{
  const int textHeight  = 10;
  int textLine          = (textPosY+10) / textHeight;
  IGDVFont& font        = pContext->GetWindow().GetFontInterface("", textHeight-3);
  int posX2             = ((textPosX + 435) > m_HLARoi.X2)? (textPosX + 435) : m_HLARoi.X2;


  
  if (!pInterfacesMenu->getItemActivation(MENU_BUTTON_DIAG_DATABLABEL))
  {
    return;
  }

  /* draw it in input yellow */
  SetColor(color_yellow, 0.3f);
  glBegin(GL_QUADS);
  {
      glVertex3i(textPosX - 5     , textPosY, 1);
      glVertex3i(posX2            , textPosY, 1);
      glVertex3i(posX2            , textPosY + 92, 1);
      glVertex3i(textPosX -5      , textPosY + 92, 1);
  }
  glEnd();
  /* draw border*/
  SetColor(color_yellow);
  glBegin(GL_LINE_LOOP);
  {
      glVertex3i(textPosX - 5     , textPosY, 1);
      glVertex3i(posX2            , textPosY, 1);
      glVertex3i(posX2            , textPosY + 92, 1);
      glVertex3i(textPosX -5      , textPosY + 92, 1);
  }
  glEnd();

  /* information part */
  font.BeginRender2D();
  SetTextColor(color_white, font);
  font.RenderTextf(textPosX + 150, textLine*textHeight, 1, "HLA Labels Stored in Database"); textLine++;
  font.RenderTextf(textPosX + 65 , textLine*textHeight, 1, "====================================================="); textLine++;
  font.RenderTextf(textPosX      , textLine*textHeight, 1, "Make sure mode (labelDB_overlay*) is enabled in INI file & correct table is selected (MFC300/MFC400)"); textLine++;
  font.EndRender2D();
  textLine++;

  /* call the various label functions to display their information */
  drawHLALabelDB( pContext, uiTimeStamp, simImg_KAFAS_FLA_t, textPosX, textLine, textHeight);
  textLine++;
  drawHighwayLabelDB( pContext,
                      uiTimeStamp,
                      textPosX,
                      textLine,
                      textHeight
                    );
  textLine++;
  drawCityLabelDB(pContext,
                  uiTimeStamp,
                  textPosX,
                  textLine,
                  textHeight
                 );
  textLine++;
  drawCarLightLabelDB(pContext, uiTimeStamp, textPosX, textLine, textHeight);

}

/* private methods */
void CSimHlaVisuLabels::drawCarLightLabelDB( const ISimRenderContext*  pContext,
                                             const unsigned __int64*   uiTimeStamp,
                                                   uint32              textPosX,
                                                   uint32              textLine,
                                                   uint32              textHeight
                                          )
{
  std::stringstream strLabeledCarLightVisibly;

  IGDVFont& font = pContext->GetWindow().GetFontInterface("", textHeight-3);
  boolean databaseConnection        = FALSE;
  boolean recordingAvailable        = FALSE;
  boolean isLabeledCarLightVisibly  = FALSE;
  unsigned int hr = 0;

  if(pLabelDB_LDSS != NULL)
  {
    databaseConnection = TRUE;

    hr = pLabelDB_LDSS->moveFirst();
    if(hr == 1)
    {
      recordingAvailable = TRUE;

      while (hr == 1)
      {
        Buffer_MFC300_HLA_LDSS* data = pLabelDB_LDSS->getData();

        if(   (strcmp(data->IHCR_Car_Light_Visibly, "") != 0)
           && (*uiTimeStamp >= data->FrameMtLDSSTimeStampStart)
           && (*uiTimeStamp <= data->FrameMtLDSSTimeStampStop)
          )
        {
          isLabeledCarLightVisibly = TRUE;
          strLabeledCarLightVisibly.clear();
          strLabeledCarLightVisibly << data->IHCR_Car_Light_Visibly << " (" << data->FrameMtLDSSTimeStampStart << " - " << data->FrameMtLDSSTimeStampStop << ")";
        }

        /* Go to next */
        hr = pLabelDB_LDSS->moveNext();
      }
    }
  }

  if (   (pLabelDB_LDSS != NULL)
      && (pLabelDB_LDSS->moveFirst() == 1)
      && (FALSE)
     )
  {
    unsigned __int64 cycleTime = (unsigned __int64)(1000000u / 16 /*dllHLARReqIn.s_Par.s_CameraParameter.f32_cycleTime*/);  // Todo zechners: As long as 1/16 is more correct than the algo cylce time
    const int xOffset = textPosX;
    const int yOffset = (textLine+1) * textHeight + 120;
    const int yScale = 15;

    font.BeginRender2D();
    SetTextColor(color_green, font);
    font.RenderTextf(xOffset + 260, yOffset + 0.7f * yScale, 1, "Unsupported Label");
    font.RenderTextf(xOffset + 260, yOffset - 0.3f * yScale, 1, "No Label");
    font.RenderTextf(xOffset + 260, yOffset - 2.3f * yScale, 1, "Non_Relevant_Traffic");
    font.RenderTextf(xOffset + 260, yOffset - 3.3f * yScale, 1, "Relevant_Traffic_Ahead");
    font.RenderTextf(xOffset + 260, yOffset - 4.3f * yScale, 1, "Relevant_Traffic_Oncoming_Ahead");
    font.RenderTextf(xOffset + 260, yOffset - 5.3f * yScale, 1, "Relevant_Traffic_Oncoming");
    font.EndRender2D();

    SetColor(color_yellow);
    glBegin(GL_LINE);
    {
      glVertex3f( (float)xOffset, yOffset + 2.0f * yScale, 1);
      glVertex3f( (float)xOffset, yOffset - 6.0f * yScale, 1);
    }
    glEnd();
    SetColor(color_green);

    for (int i = -250; i <= 250; i++)
    {
      const unsigned __int64 time = *uiTimeStamp + i*cycleTime;

      if (   (pLabelDB_LDSS != NULL)
          && (pLabelDB_LDSS->moveFirst() == 1) 
         )
      {
        bool noLabelFound = true;

        unsigned int hr = 1;
        while (hr == 1)
        {
          Buffer_MFC300_HLA_LDSS* data = pLabelDB_LDSS->getData();

          if (   (time >= data->FrameMtLDSSTimeStampStart - 0.5f * cycleTime)
              && (time <= data->FrameMtLDSSTimeStampStop  + 0.5f * cycleTime)
             )
          {
            glBegin(GL_POINTS);

            if (strcmp(data->IHCR_Car_Light_Visibly, "Relevant_Traffic_Oncoming") == 0)
            {
              glVertex3i(xOffset + i, yOffset - yScale * 5, 1);
              noLabelFound = false;
            }
            if (strcmp(data->IHCR_Car_Light_Visibly, "Relevant_Traffic_Oncoming_Ahead") == 0)
            {
              glVertex3i(xOffset + i, yOffset - yScale * 4, 1);
              noLabelFound = false;
            }
            else if (strcmp(data->IHCR_Car_Light_Visibly, "Relevant_Traffic_Ahead") == 0)
            {
              glVertex3i(xOffset + i, yOffset - yScale * 3, 1);
              noLabelFound = false;
            }
            else if (strcmp(data->IHCR_Car_Light_Visibly, "Non_Relevant_Traffic") == 0)
            {
              glVertex3i(xOffset + i, yOffset - yScale * 2, 1);
              noLabelFound = false;
            }
            else if (   (strcmp(data->IHCR_Car_Light_Visibly, "") != 0)
                     && (strcmp(data->IHCR_Car_Light_Visibly, "Relevant_Traffic_Oncoming") != 0)
                     && (strcmp(data->IHCR_Car_Light_Visibly, "Relevant_Traffic_Oncoming_Ahead") != 0)
                     && (strcmp(data->IHCR_Car_Light_Visibly, "Relevant_Traffic_Ahead") != 0)
                     && (strcmp(data->IHCR_Car_Light_Visibly, "Non_Relevant_Traffic") != 0)
                    )
            {
              glVertex3i(xOffset + i, yOffset - yScale * (-1), 1);
              noLabelFound = false;
            }
            glEnd();
          }
          /* Go to next */
          hr = pLabelDB_LDSS->moveNext();
        }

        if (noLabelFound)
        {
          glBegin(GL_POINTS);
          {
            glVertex3i(xOffset + i, yOffset, 1);
          }
          glEnd();
        }
      }
    }
  }


  font.BeginRender2D();
  SetTextColor(color_white, font);
  font.RenderTextf(textPosX, textLine*textHeight, 1, "Car Labels:");
  if(databaseConnection == FALSE)
  {
    SetTextColor(color_magenta, font);
    font.RenderTextf(textPosX + 80, textLine*textHeight, 1, "No connection to LDSS database");
  }
  else if(recordingAvailable == FALSE)
  {
    SetTextColor(color_white, font);
    font.RenderTextf(textPosX + 80, textLine*textHeight, 1, "Recording not found in LDSS database");
  }
  else
  {
    if(isLabeledCarLightVisibly == TRUE)
    {
      SetTextColor(color_green, font);
      font.RenderTextf(textPosX + 80, textLine*textHeight, 1, "Car Light Visibly: %s", strLabeledCarLightVisibly.str().c_str());
    }
    else
    {
      SetTextColor(color_white, font);
      font.RenderTextf(textPosX + 80, textLine*textHeight, 1, "Car Light Visibly: No label here");
    }
  }
  font.EndRender2D();
}

void CSimHlaVisuLabels::drawHLALabelDB(const ISimRenderContext*  pContext,
                                       const unsigned __int64*   uiTimeStamp,
                                             unsigned int        imagetype,
                                             uint32              textPosX,
                                             uint32              textLine,
                                             uint32              textHeight
                                      )
{
  unsigned int nNumberOfEntries;
  Buffer_MFC300_HLA_LDROI *buffer;

  unsigned int uiX_LowerLeft,   uiY_LowerLeft;
  unsigned int uiX_LowerRight,  uiY_LowerRight;
  unsigned int uiX_UpperLeft,   uiY_UpperLeft;
  unsigned int uiX_UpperRight,  uiY_UpperRight;

  SLabelDate_t sLabelDate, sNewestLabelTraffic = {0, 0, 0}, sNewestLabelStreetlight = {0, 0, 0};
  unsigned int uiValidBoxStreetlight = 0, uiValidBoxTraffic = 0;

  IGDVFont& font = pContext->GetWindow().GetFontInterface("", textHeight-3);
  boolean databaseConnection  = FALSE;
  boolean recordingAvailable  = FALSE;

  if(pLabelDB == NULL)
  {
    return;
  }

  if(pLabelDB != NULL)
  {
    databaseConnection = TRUE;

    if(pLabelDB->moveFirst(*uiTimeStamp, imagetype))
    {
      recordingAvailable = TRUE;

      nNumberOfEntries = pLabelDB->getNumberOfEntries(*uiTimeStamp, imagetype);

      // Determine the valid (newest) label boxes of a timestamp
      if(nNumberOfEntries >= 2) 
      {
        for(unsigned int i=0; i<nNumberOfEntries; i++) 
        {
          buffer = pLabelDB->getData();

          sLabelDate = pLabelDB->getLabelDate(buffer->TAN);

          if(strcmp(buffer->IHCR_Street_Lighting, ""))
          {
            if(sLabelDate > sNewestLabelStreetlight)
            {
              sNewestLabelStreetlight = sLabelDate;
              uiValidBoxStreetlight = i;
            }
          }
          if(strcmp(buffer->IHCPR_EVA_Lightclass_Left, ""))
          {
            if(sLabelDate > sNewestLabelTraffic)
            {
              sNewestLabelTraffic = sLabelDate;
              uiValidBoxTraffic = i;
            }
          }

          pLabelDB->moveNext();
        }
      }

      pLabelDB->moveFirst(*uiTimeStamp, imagetype);

      // Counter the occurence of multiple label boxes per timestamp by checking for validness
      for(unsigned int i=0; i<nNumberOfEntries; i++)
      {
        buffer = pLabelDB->getData();
        if(buffer == NULL)
        {
          return;
        }

        if(strcmp(buffer->IHCR_Street_Lighting, ""))
        {
          if(i != uiValidBoxStreetlight)
          {
            pLabelDB->moveNext();
            continue;
          }
        }
        else
        {
          if(i != uiValidBoxTraffic)
          {
            pLabelDB->moveNext();
            continue;
          }
        }
      
        // Determine the LowerRight, LowerLeft, UpperRight and UpperLeft coordinates of the label box ...
        if(buffer->ROI_COORDINATE_X_1 == MIN(buffer->ROI_COORDINATE_X_1, MIN(buffer->ROI_COORDINATE_X_2, MIN(buffer->ROI_COORDINATE_X_3, buffer->ROI_COORDINATE_X_4))))
        {
          if(buffer->ROI_COORDINATE_X_2 == MIN(buffer->ROI_COORDINATE_X_2, MIN(buffer->ROI_COORDINATE_X_3, buffer->ROI_COORDINATE_X_4)))
          {
            if(buffer->ROI_COORDINATE_Y_1 < buffer->ROI_COORDINATE_Y_2)
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_1;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_1;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_2;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_2;
            }
            else
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_2;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_2;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_1;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_1;
            }
            if(buffer->ROI_COORDINATE_Y_3 < buffer->ROI_COORDINATE_Y_4)
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_3;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_3;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_4;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_4;
            }
            else
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_4;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_4;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_3;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_3;
            }
          }
          else if(buffer->ROI_COORDINATE_X_3 == MIN(buffer->ROI_COORDINATE_X_2, MIN(buffer->ROI_COORDINATE_X_3, buffer->ROI_COORDINATE_X_4)))
          {
            if(buffer->ROI_COORDINATE_Y_1 < buffer->ROI_COORDINATE_Y_3)
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_1;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_1;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_3;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_3;
            }
            else
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_3;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_3;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_1;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_1;
            }
            if(buffer->ROI_COORDINATE_Y_2 < buffer->ROI_COORDINATE_Y_4)
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_2;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_2;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_4;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_4;
            }
            else
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_4;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_4;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_2;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_2;
            }
          }
          else
          {
            if(buffer->ROI_COORDINATE_Y_1 < buffer->ROI_COORDINATE_Y_4)
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_1;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_1;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_4;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_4;
            }
            else 
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_4;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_4;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_1;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_1;
            }
            if(buffer->ROI_COORDINATE_Y_3 < buffer->ROI_COORDINATE_Y_2)
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_3;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_3;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_2;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_2;
            }
            else
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_2;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_2;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_3;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_3;
            }
          }
        }
        else if(buffer->ROI_COORDINATE_X_2 == MIN(buffer->ROI_COORDINATE_X_1, MIN(buffer->ROI_COORDINATE_X_2, MIN(buffer->ROI_COORDINATE_X_3, buffer->ROI_COORDINATE_X_4))))
        {
          if(buffer->ROI_COORDINATE_X_1 == MIN(buffer->ROI_COORDINATE_X_1, MIN(buffer->ROI_COORDINATE_X_3, buffer->ROI_COORDINATE_X_4)))
          {
            if(buffer->ROI_COORDINATE_Y_2 < buffer->ROI_COORDINATE_Y_1)
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_2;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_2;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_1;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_1;
            }
            else
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_1;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_1;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_2;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_2;
            }
            if(buffer->ROI_COORDINATE_Y_3 < buffer->ROI_COORDINATE_Y_4)
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_3;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_3;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_4;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_4;
            }
            else
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_4;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_4;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_3;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_3;
            }
          }
          else if(buffer->ROI_COORDINATE_X_3 == MIN(buffer->ROI_COORDINATE_X_1, MIN(buffer->ROI_COORDINATE_X_3, buffer->ROI_COORDINATE_X_4)))
          {
            if(buffer->ROI_COORDINATE_Y_2 < buffer->ROI_COORDINATE_Y_3)
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_2;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_2;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_3;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_3;
            }
            else
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_3;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_3;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_2;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_2;
            }
            if(buffer->ROI_COORDINATE_Y_1 < buffer->ROI_COORDINATE_Y_4)
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_1;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_1;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_4;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_4;
            }
            else
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_4;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_4;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_1;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_1;
            }
          }
          else
          {
            if(buffer->ROI_COORDINATE_Y_2 < buffer->ROI_COORDINATE_Y_4)
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_2;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_2;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_4;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_4;
            }
            else
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_4;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_4;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_2;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_2;
            }
            if(buffer->ROI_COORDINATE_Y_3 < buffer->ROI_COORDINATE_Y_1)
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_3;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_3;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_1;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_1;
            }
            else
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_1;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_1;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_3;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_3;
            }
          }
        }
        else if(buffer->ROI_COORDINATE_X_3 == MIN(buffer->ROI_COORDINATE_X_1, MIN(buffer->ROI_COORDINATE_X_2, MIN(buffer->ROI_COORDINATE_X_3, buffer->ROI_COORDINATE_X_4))))
        {
          if(buffer->ROI_COORDINATE_X_1 == MIN(buffer->ROI_COORDINATE_X_2, MIN(buffer->ROI_COORDINATE_X_1, buffer->ROI_COORDINATE_X_4)))
          {
            if(buffer->ROI_COORDINATE_Y_3 < buffer->ROI_COORDINATE_Y_1)
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_3;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_3;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_1;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_1;
            }
            else
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_1;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_1;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_3;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_3;
            }
            if(buffer->ROI_COORDINATE_Y_2 < buffer->ROI_COORDINATE_Y_4)
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_2;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_2;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_4;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_4;
            }
            else
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_4;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_4;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_2;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_2;
            }
          }
          else if(buffer->ROI_COORDINATE_X_2 == MIN(buffer->ROI_COORDINATE_X_1, MIN(buffer->ROI_COORDINATE_X_2, buffer->ROI_COORDINATE_X_4)))
          {
            if(buffer->ROI_COORDINATE_Y_3 < buffer->ROI_COORDINATE_Y_2)
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_3;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_3;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_2;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_2;
            }
            else
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_2;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_2;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_3;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_3;
            }
            if(buffer->ROI_COORDINATE_Y_1 < buffer->ROI_COORDINATE_Y_4)
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_1;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_1;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_4;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_4;
            }
            else
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_4;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_4;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_1;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_1;
            }
          }
          else
          {
            if(buffer->ROI_COORDINATE_Y_3 < buffer->ROI_COORDINATE_Y_4)
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_3;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_3;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_4;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_4;
            }
            else
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_4;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_4;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_3;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_3;
            }
            if(buffer->ROI_COORDINATE_Y_2 < buffer->ROI_COORDINATE_Y_1)
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_2;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_2;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_1;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_1;
            }
            else
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_1;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_1;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_2;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_2;
            }
          }
        }
        else
        {
          if(buffer->ROI_COORDINATE_X_1 == MIN(buffer->ROI_COORDINATE_X_2, MIN(buffer->ROI_COORDINATE_X_1, buffer->ROI_COORDINATE_X_3)))
          {
            if(buffer->ROI_COORDINATE_Y_4 < buffer->ROI_COORDINATE_Y_1)
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_4;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_4;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_1;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_1;
            }
            else
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_1;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_1;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_4;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_4;
            }
            if(buffer->ROI_COORDINATE_Y_2 < buffer->ROI_COORDINATE_Y_3)
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_2;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_2;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_3;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_3;
            }
            else
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_3;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_3;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_2;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_2;
            }
          }
          else if(buffer->ROI_COORDINATE_X_2 == MIN(buffer->ROI_COORDINATE_X_1, MIN(buffer->ROI_COORDINATE_X_2, buffer->ROI_COORDINATE_X_3)))
          {
            if(buffer->ROI_COORDINATE_Y_4 < buffer->ROI_COORDINATE_Y_2)
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_4;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_4;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_2;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_2;
            }
            else
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_2;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_2;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_4;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_4;
            }
            if(buffer->ROI_COORDINATE_Y_1 < buffer->ROI_COORDINATE_Y_3)
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_1;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_1;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_3;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_3;
            }
            else
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_3;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_3;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_1;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_1;
            }
          }
          else {
            if(buffer->ROI_COORDINATE_Y_3 < buffer->ROI_COORDINATE_Y_4) 
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_3;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_3;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_4;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_4;
            }
            else
            {
              uiX_UpperLeft = buffer->ROI_COORDINATE_X_4;
              uiY_UpperLeft = buffer->ROI_COORDINATE_Y_4;
              uiX_LowerLeft = buffer->ROI_COORDINATE_X_3;
              uiY_LowerLeft = buffer->ROI_COORDINATE_Y_3;
            }
            if(buffer->ROI_COORDINATE_Y_2 < buffer->ROI_COORDINATE_Y_1)
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_2;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_2;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_1;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_1;
            }
            else
            {
              uiX_UpperRight = buffer->ROI_COORDINATE_X_1;
              uiY_UpperRight = buffer->ROI_COORDINATE_Y_1;
              uiX_LowerRight = buffer->ROI_COORDINATE_X_2;
              uiY_LowerRight = buffer->ROI_COORDINATE_Y_2;
            }
          }
        }

        if(strcmp(buffer->IHCR_Street_Lighting, ""))
        {
          if(strcmp(buffer->IHCR_Street_Lighting,"Bordering_Own_Lane") == 0)
          {
            SetColor(color_yellow);
          }
          else/* Near Road */
          {
            SetColor(color_white);
          }

          glBegin(GL_QUADS);
          {
            glVertex3i(uiX_UpperLeft , uiY_UpperLeft , 1);
            glVertex3i(uiX_UpperRight, uiY_UpperRight, 1);
            glVertex3i(uiX_LowerRight, uiY_LowerRight, 1);
            glVertex3i(uiX_LowerLeft , uiY_LowerLeft , 1);
          }
          glEnd();
        }
        else
        {
          // Traffic oncoming : Green      Traffic ahead : Pink
          if(!strcmp(buffer->IHCPR_EVA_Lightclass_Left, "Traffic_Oncoming"))
          {
            SetColor(color_green, 0.5f);
          }
          else
          {
            SetColor(color_magenta, 0.5f);
          }
        

          glBegin(GL_QUADS);
          {
            glVertex3f((float)uiX_UpperLeft, (float)uiY_UpperLeft, 1.0f);
            glVertex3f((float)((uiX_UpperRight - uiX_UpperLeft)/2 + uiX_UpperLeft), (float)(((int)uiY_UpperRight - (int)uiY_UpperLeft)/2 + uiY_UpperLeft), 1.0f);
            glVertex3f((float)((uiX_LowerRight - uiX_LowerLeft)/2 + uiX_LowerLeft), (float)(((int)uiY_LowerRight - (int)uiY_LowerLeft)/2 + uiY_LowerLeft), 1.0f);
            glVertex3f((float)uiX_LowerLeft, (float)uiY_LowerLeft, 1.0f);
          }
          glEnd();

          if(!strcmp(buffer->IHCPR_EVA_Lightclass_Right, "Traffic_Oncoming"))
          {
            SetColor(color_green, 0.5f);
          }
          else
          {
            SetColor(color_magenta, 0.5f);
          }

          glBegin(GL_QUADS);
          {
            glVertex3f((float)uiX_UpperRight, (float)uiY_UpperRight, 1.0f);
            glVertex3f((float)(uiX_UpperRight - (uiX_UpperRight - uiX_UpperLeft)/2), (float)(uiY_UpperRight - ((int)uiY_UpperRight - (int)uiY_UpperLeft)/2), 1.0f);
            glVertex3f((float)(uiX_LowerRight - (uiX_LowerRight - uiX_LowerLeft)/2), (float)(uiY_LowerRight - ((int)uiY_LowerRight - (int)uiY_LowerLeft)/2), 1.0f);
            glVertex3f((float)uiX_LowerRight, (float)uiY_LowerRight, 1.0f);
          }
          glEnd();
        }

        pLabelDB->moveNext();
      }
    }
  }

  font.BeginRender2D();
  SetTextColor(color_white, font);
  font.RenderTextf(textPosX, textLine*textHeight, 1, "HLA Labels:");
  if(databaseConnection == FALSE)
  {
    SetTextColor(color_magenta, font);
    font.RenderTextf(textPosX + 80, textLine*textHeight, 1, "No connection to LDROI database");
  }
  else if(recordingAvailable == FALSE)
  {
    SetTextColor(color_white, font);
    font.RenderTextf(textPosX + 80, textLine*textHeight, 1, "Recording not found in LDROI database");
  }
  else
  {
    SetTextColor(color_red, font);
    font.RenderTextf(textPosX + 80, textLine*textHeight, 1, "Labels as shown in ROI");
  }
  font.EndRender2D();
}

void CSimHlaVisuLabels::drawHighwayLabelDB(const ISimRenderContext*  pContext,
                                           const unsigned __int64*   uiTimeStamp,
                                                 uint32              textPosX,
                                                 uint32              textLine,
                                                 uint32              textHeight
                                         )
{
  //Buffer_MFC300_HLA_LDROI *buffer;
  Buffer_MFC300_HLA_LDSS *Data;
  uint16 nNumberOfEntries;

  IGDVFont& font              = pContext->GetWindow().GetFontInterface("", textHeight-3);
  boolean isLabeledHighway    = FALSE;
  boolean databaseConnection  = FALSE;
  boolean recordingAvailable  = FALSE;
  uint16 hr = 1;

  ///* LDROI PART */
  ///* Update odometer in Highway internal data filtered with oncoming traffic */
  //if(   (pLabelDB != NULL)
  //  &&  (pLabelDB->moveFirst(m_interestTimestamp, imagetype)) 
  //  )
  //{
  //  nNumberOfEntries = pLabelDB->getNumberOfEntries(m_interestTimestamp, imagetype);

  //  for(unsigned int i=0; i<nNumberOfEntries; i++) 
  //  {
  //    buffer = pLabelDB->getData();

  //    if(strcmp(buffer->IHCPR_EVA_Lightclass_Left, "Traffic_Oncoming")==0) 
  //    {
  //      hlaHighwayInternalData.Odometer += hlaCamData.ddist_m;
  //    }
  //    else
  //    {
  //      pLabelDB->moveNext();
  //    }
  //  }
  //}
  ///* Display Odometer */
  //SetColor2(GLD_White);
  //DrawFormattedText(500,520,"%0.1f",hlaHighwayInternalData.Odometer);

  /* LDSS PART */
  if(pLabelDB_LDSS != NULL)
  {
    databaseConnection = TRUE;

    if(pLabelDB_LDSS->moveFirst() == 1)
    {
      recordingAvailable = TRUE;

      nNumberOfEntries = pLabelDB_LDSS->getNumberOfEntries();

      for(uint16 n = 0; n < nNumberOfEntries; n ++)
      {
        if(hr == 1)
        {
          Data = pLabelDB_LDSS->getData();

          if(   (strcmp(Data->SLAF_Phyisical_Seperation,"") != 0)
            && (*uiTimeStamp >= Data->FrameMtLDSSTimeStampStart)
            && (*uiTimeStamp <= Data->FrameMtLDSSTimeStampStop)
            )
          {
            isLabeledHighway = TRUE;
          }
        }

        /* Go to next */
        hr = pLabelDB_LDSS->moveNext();
      }
    }
  }

  font.BeginRender2D();
  SetTextColor(color_white, font);
  font.RenderTextf(textPosX, textLine*textHeight, 1, "Highway Label:");
  if(databaseConnection == FALSE)
  {
    SetTextColor(color_magenta, font);
    font.RenderTextf(textPosX + 80, textLine*textHeight, 1, "No connection to LDSS database");
  }
  else if(recordingAvailable == FALSE)
  {
    SetTextColor(color_white, font);
    font.RenderTextf(textPosX + 80, textLine*textHeight, 1, "Recording not found in LDSS database");
  }
  else if(isLabeledHighway)
  {
    SetTextColor(color_green, font);
    font.RenderTextf(textPosX + 80, textLine*textHeight, 1, "HIGHWAY LABELED");
  }
  else
  {
    SetTextColor(color_red, font);
    font.RenderTextf(textPosX + 80, textLine*textHeight, 1, "HIGHWAY NOT LABELED");
  }
  font.EndRender2D();
}

void CSimHlaVisuLabels::drawCityLabelDB( const ISimRenderContext*  pContext,
                                         const unsigned __int64*   uiTimeStamp,
                                               uint32              textPosX,
                                               uint32              textLine,
                                               uint32              textHeight
                                      )
{
  Buffer_MFC300_HLA_LDSS *Data;
  uint16 nNumberOfEntries;

  IGDVFont& font              = pContext->GetWindow().GetFontInterface("", textHeight-3);
  uint16 hr                   = 1;
  boolean IsLabeledCity       = FALSE;
  boolean IsBorderingOwnLane  = FALSE;
  boolean databaseconnection  = FALSE;
  boolean recordingAvailable  = FALSE;

  if(pLabelDB_LDSS != NULL)
  {
    databaseconnection = TRUE;

    if(pLabelDB_LDSS->moveFirst() == 1)
    {
      recordingAvailable = TRUE;

      nNumberOfEntries = pLabelDB_LDSS->getNumberOfEntries();

      for(uint16 n = 0; n < nNumberOfEntries; n ++)
      {
        if(hr == 1)
        {
          Data = pLabelDB_LDSS->getData();

          if(     (strcmp(Data->IHCR_Street_Lighting_S,"") != 0)
              &&  (*uiTimeStamp >= Data->FrameMtLDSSTimeStampStart)
              &&  (*uiTimeStamp <= Data->FrameMtLDSSTimeStampStop)
              )
          {
            IsLabeledCity = TRUE;
            if ((strstr(Data->IHCR_Street_Lighting_S,"Bordering_Own_Lane") != 0))
            {
              IsBorderingOwnLane = b_TRUE;
            }
          }
        }

        /* Go to next */
        hr = pLabelDB_LDSS->moveNext();
      }
    }
  }

  font.BeginRender2D();
  SetTextColor(color_white, font);
  font.RenderTextf(textPosX, textLine*textHeight, 1, "City Label:");
  if(databaseconnection == FALSE)
  {
    SetTextColor(color_magenta, font);
    font.RenderTextf(textPosX + 80, textLine*textHeight, 1, "No connection to LDSS database");
  }
  else if(recordingAvailable == FALSE)
  {
    SetTextColor(color_white, font);
    font.RenderTextf(textPosX + 80, textLine*textHeight, 1, "Recording not found in LDSS database");
  }
  else if(IsLabeledCity)
  {
    SetTextColor(color_green, font);
    font.RenderTextf(textPosX + 80, textLine*textHeight, 1, "CITY LABELED");
    font.RenderTextf(textPosX + 160, textLine*textHeight, 1, IsBorderingOwnLane ? "Bordering Own Lane": "Near Road");
  }
  else
  {
    SetTextColor(color_red, font);
    font.RenderTextf(textPosX + 80, textLine*textHeight, 1, "CITY NOT LABELED");
  }
  font.EndRender2D();
}
