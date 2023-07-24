/*! \file **********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC3xx

  CPU:                    freescale Golddust

  COMPONENT:              HLA

  MODULNAME:              hla_icon.c

  DESCRIPTION:            Functions for icon handling.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          05.05.2011

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_icon.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:45CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:02CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:19CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.24 2014/03/26 11:27:30CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:31 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.23 2014/03/25 19:11:47CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Separation of hla_segmentation.c
  CHANGE:                 Removed QAC warnings
  CHANGE:                 Replaces fABS by CML_f_abs
  CHANGE:                 Introduced CML_s_Round2Int
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:47 PM CET]
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.22 2014/03/25 18:32:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_icon.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_icon.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGE:                 Revision 1.21 2014/03/24 18:33:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed boost assert
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 24, 2014 6:33:28 PM CET]
  CHANGE:                 Change Package : 207432:44 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.20 2014/03/22 10:28:22CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added project specific defines
  CHANGE:                 Replaced defines for CORE by predefined ones
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 22, 2014 10:28:22 AM CET]
  CHANGE:                 Change Package : 207432:40 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.19 2014/03/19 16:30:18CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:18 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.18 2014/03/11 15:43:41CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Took cfg_project.h into use
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2014 3:43:42 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.17 2014/03/10 13:20:50CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:20:51 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.16 2014/03/04 16:52:02CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:02 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.15 2014/02/28 15:42:35CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 remove unused fields in HLAIconData_t
  CHANGE:                 --- Added comments ---  uidv8776 [Feb 28, 2014 3:42:35 PM CET]
  CHANGE:                 Change Package : 217405:1 http://mks-psad:7002/im/viewissue?selection=217405
  CHANGE:                 Revision 1.14 2014/02/06 16:01:25CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:26 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.13 2014/01/13 17:00:36CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 reduce us of icon state
  CHANGE:                 --- Added comments ---  uidv8776 [Jan 13, 2014 5:00:37 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.12 2014/01/10 18:33:20CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:20 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.11 2014/01/05 22:53:26CET Glebov, Roman (uidg4759) 
  CHANGE:                 QAC: implicite conversion from int to unsigned int and vise versa removed
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 5, 2014 10:53:26 PM CET]
  CHANGE:                 Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.10 2013/11/21 17:53:22CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:23 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.9.1.2 2013/11/12 13:44:43CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed SegOut from function arguments
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 12, 2013 1:44:44 PM CET]
  CHANGE:                 Change Package : 201787:5 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.9.1.1 2013/10/18 13:27:55CEST Brunn, Marcus (brunnm) 
  CHANGE:                 intial version of new segmentation
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:27:55 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.9 2013/08/27 17:13:34CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed icon extraction
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 27, 2013 5:13:34 PM CEST]
  CHANGE:                 Change Package : 195030:1 http://mks-psad:7002/im/viewissue?selection=195030
  CHANGE:                 Revision 1.8 2013/02/05 11:41:01CET Zechner, Stefan (uidt9253) 
  CHANGE:                 - fix misra warnings
  CHANGE:                 --- Added comments ---  uidt9253 [Feb 5, 2013 11:41:02 AM CET]
  CHANGE:                 Change Package : 166950:1 http://mks-psad:7002/im/viewissue?selection=166950
  CHANGE:                 Revision 1.7 2013/02/04 10:34:24CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 added possibility for for direct image access for icon creation.
  CHANGE:                 --- Added comments ---  uidv8776 [Feb 4, 2013 10:34:24 AM CET]
  CHANGE:                 Change Package : 169297:1 http://mks-psad:7002/im/viewissue?selection=169297
  CHANGE:                 Revision 1.6 2013/01/11 16:04:55CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed compiler warnings (type casting) due to 32-bit enums
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 11, 2013 4:04:55 PM CET]
  CHANGE:                 Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.5 2012/01/19 17:12:44CET Zechner, Stefan (uidt9253) 
  CHANGE:                 - shift icon top/left position to red pixel is working regardless of Bayer type of the imager
  CHANGE:                 --- Added comments ---  uidt9253 [Jan 19, 2012 5:12:44 PM CET]
  CHANGE:                 Change Package : 90757:1 http://mks-psad:7002/im/viewissue?selection=90757
  CHANGE:                 Revision 1.4 2012/01/19 09:51:51CET Brunn, Marcus (brunnm) 
  CHANGE:                 updated diagnosis debug message (64Bit)
  CHANGE:                 - added icon result (HB on), HLAF turn off reason, keep off reason and hla version
  CHANGE:                 --- Added comments ---  brunnm [Jan 19, 2012 9:51:51 AM CET]
  CHANGE:                 Change Package : 93893:1 http://mks-psad:7002/im/viewissue?selection=93893
  CHANGE:                 Revision 1.3 2011/05/10 16:40:46CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 removed MISRA Errros
  CHANGE:                 --- Added comments ---  brunnm [May 10, 2011 4:40:47 PM CEST]
  CHANGE:                 Change Package : 53526:2 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.2 2011/05/10 08:09:11CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 removed MISRA Errors
  CHANGE:                 --- Added comments ---  brunnm [May 10, 2011 8:09:12 AM CEST]
  CHANGE:                 Change Package : 53526:2 http://mks-psad:7002/im/viewissue?selection=53526
  CHANGE:                 Revision 1.1 2011/05/06 05:46:27CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:
  CHANGE:
**************************************************************************** */
#ifdef PC_SIM
#include <assert.h>
#endif
#include <string.h>

#include "hla_icon.h"

#include "hla_trackmeas.h"


/* internal data */
static hlaIcon_t*   phlaIcon;
static t_PixelData* phlaImg;

static eHLAIconErr_t HLAIconSetBox( uint16 xTopLeft,
                                    uint16 yTopLeft,
                                    uint16 xBottomRight,
                                    uint16 yBottomRight,
                                    eHLAIconID_t eIconID,
                                    void *pRef,
                                    HLAIconData_t *pIcon,
                                    const HLACameraData_t* pCamData,
                                    const HLA_t_eBayerPatternType e_bayerPattern);

static void HLAIconSelectIcons(HLATrack_t*                         pTLB_Start,
                               HLAIconData_t                       IconData[],
                               const HLACameraData_t*              pCamData,
                               const HLA_t_CameraParameter*        pCameraParameter,
                               const HLATracking3DParametersMeasurement_t*     pTracking3DParamsMeasurement
                               );

static void HLAIconCopyIcons(const HLA_t_CameraParameter*  pCameraParameter);

static void HLAIconPosFromTrack(const HLATrack_t*                   pTLB,
                                const HLATracking3DParametersMeasurement_t*     pTracking3DParamsMeasurement,
                                sint16*                             xTopLeft,
                                sint16*                             yTopLeft,
                                sint16*                             xBottomRight,
                                sint16*                             yBottomRight);


/* **************************************************************************** 
  Functionname:     eHLAIconErr_t HLAIconSetBox()                */ /*!  
  Description:      

  @param[in]        -

  @return           eHLAIconErr_t eErr

  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static eHLAIconErr_t HLAIconSetBox(uint16 xTopLeft,
                                   uint16 yTopLeft,
                                   uint16 xBottomRight,
                                   uint16 yBottomRight,
                                   eHLAIconID_t eIconID,
                                   void *pRef,
                                   HLAIconData_t *pIcon,
                                   const HLACameraData_t* pCamData,
                                   const HLA_t_eBayerPatternType e_bayerPattern
                                  )
{
  eHLAIconErr_t   eErr = ICON_NO_ERR;
  
  /* valid icon pointer ? */
  if(pIcon != NULL)
  {
    /* shift icon top/left position to red pixel */
    const uint8 patternH = (uint8)(((uint32)(e_bayerPattern) % 2) + xTopLeft) % 2;
    const uint8 patternV = (uint8)(((uint32)(e_bayerPattern) / 2) + yTopLeft) % 2;

    if (patternV == 1)
    {
      yTopLeft++;
      yBottomRight++;
    }
    if (patternH == 0)
    {
      xTopLeft++;
      xBottomRight++;
    }
    
    /* check if icon is within HLA ROI */
    if(    (xTopLeft     > pCamData->RoiX1)
        && (yTopLeft     > pCamData->RoiY1)
        && (xBottomRight < pCamData->RoiX2)
        && (yBottomRight < pCamData->RoiY2)
        && (xTopLeft     <= xBottomRight)
        && (yTopLeft     <= yBottomRight)
      )
    {
      /* free icon available ? */
      if(phlaIcon->iNoIcons < HLA_ICON_MAX_BOXES)
      {
          
        /* put new icon into the list */
        /* at first position          */
        HLAIconList_t *pHelp = phlaIcon->phlaIconList;
        phlaIcon->phlaIconList = &phlaIcon->hlaIconList[phlaIcon->iNoIcons];
        phlaIcon->phlaIconList->pNext = pHelp;

        phlaIcon->phlaIconList->pData = pIcon;

        pIcon->pRef = pRef;
        pIcon->eIconID = eIconID;
               
        /* save current icon position */
        pIcon->Pos.X1      = xTopLeft;
        pIcon->Pos.X2      = xBottomRight;
        pIcon->Pos.Width   = (uint8)((pIcon->Pos.X2 - pIcon->Pos.X1) + 1);
        pIcon->Pos.Y1      = yTopLeft;
        pIcon->Pos.Y2      = yBottomRight;
        pIcon->Pos.Height  = (uint8)((pIcon->Pos.Y2 - pIcon->Pos.Y1) + 1);
        
      
        phlaIcon->iNoIcons++;
        eErr = ICON_NO_ERR;
      }
      else
      {
        /* no free icon available */
        eErr = ICON_NO_FREE_BOX;
      }
    }
    else
    {
      eErr = ICON_ICON_OUTSIDE_HLA_ROI;
    }

    /* save error */
    //pIcon->eErr = eErr;
  }
  else
  {
    eErr = ICON_INVALID_DATA_POINTER;
  }
 
  return eErr;
}


/* **************************************************************************** 
  Functionname:     void HLAIconInit()                */ /*!  
  Description:      

  @param[in]        -

  @return           

  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAIconInit(hlaIcon_t*     pIcon,
                 t_PixelData*   pImg)
{
  (void)memset((void*)pIcon, 0, sizeof(hlaIcon_t));

  /* save pointers */
  phlaIcon = pIcon;
  phlaImg = pImg;
}

void HLAIconPrepareThisFrame(HLATrack_t*                          pTLB_Start,
                             HLAIconData_t                        IconData[],
                             const HLACameraData_t*               pCamData,
                             const HLA_t_CameraParameter*         pCameraParameter,
                             const HLATracking3DParametersMeasurement_t*     pTracking3DParamsMeasurement
                             )
{
  HLAIconSelectIcons(pTLB_Start, IconData, pCamData, pCameraParameter, pTracking3DParamsMeasurement);
  HLAIconCopyIcons(pCameraParameter);
}


/* **************************************************************************** 
  Functionname:     HLAIconSelectIcons                                */ /*!  
  Description:      select and set the icon boxes for next frame


  @param[in]        seg_TrackListnode*          pTLB_Start

  @return           -
  @pre              -
  @post             -
  @author           Stefan Zechner
**************************************************************************** */
static void HLAIconSelectIcons(HLATrack_t*                                  pTLB_Start,
                               HLAIconData_t                                IconData[],
                               const HLACameraData_t*                       pCamData,
                               const HLA_t_CameraParameter* restrict        pCameraParameter,
                               const HLATracking3DParametersMeasurement_t*  pTracking3DParamsMeasurement
                               )
{
  sint8 i;

  HLATrack_t* pTLBmostLeft = NULL;
  HLATrack_t* pTLBmostRight = NULL;

  typedef struct
  {
    HLATrack_t* pTLB;
    sint16 cycleCnt;
  } TrackSelectItem;

  typedef struct
  {
    HLATrack_t* pTLB;
  } TrackSelectFinalItem;

  TrackSelectItem trackSelectVehicles[HLA_ICON_ANALYSIS_MAX_BOXES];
  TrackSelectItem trackSelectCityLights[HLA_ICON_ANALYSIS_MAX_BOXES];
  TrackSelectFinalItem trackSelectFinal[HLA_ICON_ANALYSIS_MAX_BOXES];

  for (i=0; i<HLA_ICON_ANALYSIS_MAX_BOXES; i++)
  {
    trackSelectVehicles[i].cycleCnt = -1;
    trackSelectCityLights[i].cycleCnt = -1;
    trackSelectFinal[i].pTLB = NULL;
  }

  /* search for the most left and most right detected vehicles */
  {
    sint16 xcenterMostLeft = SI16_T_MAX;
    sint16 xcenterMostRight = SI16_T_MIN;

    HLATrack_t *pTLB = pTLB_Start;
    while (pTLB != NULL)
    {
      if ((pTLB->statusAnalysisVehicle.isVehicleOncoming == 1) ||
          (pTLB->statusAnalysisVehicle.isVehicleAhead == 1))
      {
        if (pTLB->xcenter > xcenterMostRight)
        {
          xcenterMostRight = pTLB->xcenter;
          pTLBmostRight = pTLB;
        }

        if (pTLB->xcenter < xcenterMostLeft)
        {
          xcenterMostLeft = pTLB->xcenter;
          pTLBmostLeft = pTLB;
        }
      }

      /* go to next object */
      pTLB = pTLB->next;
    }
  }

  /* select the icons for vehicle classification (generate the ordered highestCycleCount list) */
  {
    HLATrack_t *pTLB = pTLB_Start;
    while (pTLB != NULL)
    {
      if (pTLB->TrackingStatus.willBeRemoved == 0)
      {
        if ((pTLB->statusAnalysisVehicle.isPotentialVehicleOncoming1st == 1) ||
            (pTLB->statusAnalysisVehicle.isPotentialVehicleAhead1st == 1))
        {
          /* for direct image access to not select lost tracks */
          if ((pTLB->lost_time == 0) && (pTLB->light_ref != NULL))
          {
            sint16 xTopLeft, yTopLeft, xBottomRight, yBottomRight;

            HLAIconPosFromTrack( pTLB, 
                                 pTracking3DParamsMeasurement, 
                                 &xTopLeft, 
                                 &yTopLeft, 
                                 &xBottomRight, 
                                 &yBottomRight
                                );

            if ((xTopLeft     > pCamData->RoiX1) &&
                (yTopLeft     > pCamData->RoiY1) &&
                (xBottomRight < pCamData->RoiX2) &&
                (yBottomRight < pCamData->RoiY2))
            {
              sint8 inIdx = 0;

              /* increase priority for candidates not selected for a long time */
              sint16 cyclesNoClassFromTrack = pTLB->iconState.cyclesNoClass;

              /* increase priority for actively tracked lights */
              if (pTLB->lost_time == 0)
              {
                cyclesNoClassFromTrack += 20;
              }

              if ((pTLB->statusAnalysisVehicle.isVehicleOncoming == 0) &&
                  (pTLB->statusAnalysisVehicle.isVehicleAhead == 0))
              {
                /* not detected as vehicle yet */

                /* no vehicles shall always have higher priority as already detected vehicles */
                cyclesNoClassFromTrack += 1000;

                /* increase priority for recently positive classified candidates */
                cyclesNoClassFromTrack += 3 * pTLB->iconState.status.successivePosResultCnt;

                if (pTLB->iconState.classResultSum >= (-2 * HLA_ICONRESULT_MAX_CLASS_RESPONSE))
                {
                  /* increase priority for already good rated candidates */
                  cyclesNoClassFromTrack += (sint16)((3 * pTLB->iconState.classResultSum) / HLA_ICONRESULT_MAX_CLASS_RESPONSE) + 6;
                }
              }
              else
              {
                /* already detected as vehicle */

                /* increase priority for recently negative classified candidates */
                cyclesNoClassFromTrack += 3 * pTLB->iconState.status.successiveNegResultCnt;

                /* increase priority for the vehicle most left */
                if (pTLB == pTLBmostLeft)
                {
                  cyclesNoClassFromTrack += 10;
                }

                /* increase priority for the vehicle most right */
                if (pTLB == pTLBmostRight)
                {
                  cyclesNoClassFromTrack += 10;
                }
              }

              while ((inIdx < HLA_ICON_ANALYSIS_MAX_BOXES) &&
                     (cyclesNoClassFromTrack > trackSelectVehicles[inIdx].cycleCnt))
              {
                inIdx++;
              }
              if (inIdx > 0)
              {
                inIdx--;
                i=0;
                while (i < inIdx)
                {
                  trackSelectVehicles[i] = trackSelectVehicles[i+1];
                  i++;
                }

                trackSelectVehicles[inIdx].pTLB = pTLB;
                trackSelectVehicles[inIdx].cycleCnt = cyclesNoClassFromTrack;
              }
            }
          }
        }
      }

      /* go to next object */
      pTLB = pTLB->next;
    }
  }

  /* select the icons for city light classification (generate the ordered highestCycleCount list) */
  {
    HLATrack_t *pTLB = pTLB_Start;
    while (pTLB != NULL)
    {
      if (pTLB->TrackingStatus.willBeRemoved == 0)
      {
        if ((pTLB->statusAnalysisMisc.isSceneStreetLamp == 1) ||
            (pTLB->statusAnalysisMisc.isSceneStreetLampLowInt == 1) ||
            (pTLB->statusAnalysisMisc.isLeavingStreetLamp == 1))
        {
          /* for direct image access to not select lost tracks */
          if ((pTLB->lost_time == 0) && (pTLB->light_ref != NULL))
          {
            sint16 xTopLeft, yTopLeft, xBottomRight, yBottomRight;

            HLAIconPosFromTrack( pTLB, 
                                 pTracking3DParamsMeasurement, 
                                 &xTopLeft, 
                                 &yTopLeft, 
                                 &xBottomRight, 
                                 &yBottomRight
                                );

            if ((xTopLeft     > pCamData->RoiX1) &&
                (yTopLeft     > pCamData->RoiY1) &&
                (xBottomRight < pCamData->RoiX2) &&
                (yBottomRight < pCamData->RoiY2))
            {
              sint8 inIdx = 0;

              /* increase priority for candidates not selected for a long time */
              sint16 cyclesNoClassFromTrack = pTLB->iconStateCity.cyclesNoClass;

              /* increase priority for actively tracked lights */
              if (pTLB->lost_time == 0)
              {
                cyclesNoClassFromTrack += 20;
              }

              while ((inIdx < HLA_ICON_ANALYSIS_MAX_BOXES) &&
                     (cyclesNoClassFromTrack > trackSelectCityLights[inIdx].cycleCnt))
              {
                inIdx++;
              }
              if (inIdx > 0)
              {
                inIdx--;
                i=0;
                while (i < inIdx)
                {
                  trackSelectCityLights[i] = trackSelectCityLights[i+1];
                  i++;
                }

                trackSelectCityLights[inIdx].pTLB = pTLB;
                trackSelectCityLights[inIdx].cycleCnt = cyclesNoClassFromTrack;
              }
            }
          }
        }
      }

      /* go to next object */
      pTLB = pTLB->next;
    }
  }

  /* merge vehicle and city lights into the final list */
  {
    sint8 vehicleIdx = HLA_ICON_ANALYSIS_MAX_BOXES - 1;
    sint8 cityLightsIdx = HLA_ICON_ANALYSIS_MAX_BOXES - 1;
    sint8 finalIdx = 0;

    /* copy up to HLA_ICON_ANALYSIS_VEHICLE_MAX_BOXES vehicle icons */
    for (i=0; i<HLA_ICON_ANALYSIS_VEHICLE_MAX_BOXES; i++)
    {
      if (trackSelectVehicles[vehicleIdx].cycleCnt > -1)
      {
        trackSelectFinal[i].pTLB = trackSelectVehicles[vehicleIdx].pTLB;
        vehicleIdx--;
        finalIdx++;
      }
    }

    /* copy the city lights which are not already in the final list (due to being in the vehicle list) until the final list is full or no more city lights available */
    /* ~CodeReview ~ID:27cda6e32ae7a0f719f0d7cf8486c801 ~Reviewer:CW01\uidt9253 ~Date:4/2/2012 ~Priority:2 ~Comment:The order of evaluation is not guaranteed. Check for cityLightsIdx >= 0 must be done in a separate if clause */
    while ((finalIdx < HLA_ICON_ANALYSIS_MAX_BOXES) &&
           (cityLightsIdx >= 0) &&
           (trackSelectCityLights[cityLightsIdx].cycleCnt > -1))
    {
      boolean alreadyInList = b_FALSE;

      for (i=0; i<finalIdx; i++)
      {
        if (trackSelectFinal[i].pTLB == trackSelectCityLights[cityLightsIdx].pTLB)
        {
          alreadyInList = b_TRUE;
          break;
        }
      }

      if (alreadyInList == b_FALSE)
      {
        trackSelectFinal[finalIdx].pTLB = trackSelectCityLights[cityLightsIdx].pTLB;
        finalIdx++;
      }

      cityLightsIdx--;
    }

    /* copy the vehicle lights which are not already in the final list (due to being in the city lights list) until the final list is full or no more vehicle lights available */
    while ((finalIdx < HLA_ICON_ANALYSIS_MAX_BOXES) &&
           (vehicleIdx >= 0) &&
           (trackSelectVehicles[vehicleIdx].cycleCnt > -1))
    {
      boolean alreadyInList = b_FALSE;

      for (i=0; i<finalIdx; i++)
      {
        if (trackSelectFinal[i].pTLB == trackSelectVehicles[vehicleIdx].pTLB)
        {
          alreadyInList = b_TRUE;
          break;
        }
      }

      if (alreadyInList == b_FALSE)
      {
        trackSelectFinal[finalIdx].pTLB = trackSelectVehicles[vehicleIdx].pTLB;
        finalIdx++;
      }

      vehicleIdx--;
    }
  }

  /* go through the final list entries and request the icons */
  for (i=0; i<HLA_ICON_ANALYSIS_MAX_BOXES; i++)
  {
    if (trackSelectFinal[i].pTLB != NULL)
    {
      eHLAIconErr_t eIconErr;
      HLATrack_t* pTLBselected = trackSelectFinal[i].pTLB;

      sint16 xTopLeft, yTopLeft, xBottomRight, yBottomRight;

      HLAIconPosFromTrack( pTLBselected, 
                           pTracking3DParamsMeasurement, 
                           &xTopLeft, 
                           &yTopLeft, 
                           &xBottomRight, 
                           &yBottomRight
                          );

      /* -> call SetIconBox(position) with predicted track position */
      /* ~CodeReview ~ID:706eb8ee574d861c9931f88676dfc538 ~Reviewer:CW01\uidt9253 ~Date:4/2/2012 ~Priority:3 ~Comment:sint16 / uint16 casting and confusion */
      eIconErr = HLAIconSetBox( (uint16)xTopLeft,
                                (uint16)yTopLeft,
                                (uint16)xBottomRight,
                                (uint16)yBottomRight,
                                ICON_WHITE,
                                pTLBselected,
                                &IconData[i],                                                        
                                pCamData,
                                pCameraParameter->e_bayerPattern
                              );

      if (eIconErr == ICON_NO_ERR)
      {
        if ((pTLBselected->statusAnalysisVehicle.isPotentialVehicleOncoming1st == 1) ||
            (pTLBselected->statusAnalysisVehicle.isPotentialVehicleAhead1st == 1))
        {
          pTLBselected->iconState.status.iconRequested = 1;

          /* ~CodeReviewBegin ~ID:8f168b5e9c45f86aaedd7de1040de55a ~Reviewer:CW01\uidt9253 ~Date:3/23/2012 ~Priority:2 ~Comment:To be evaluated if this really avoids any false turn-offs.\$r\$nUsing the lowest region should also be considered. */
          /* ~CodeReview ~ID:799ca7a01f698b82971e80c7d7b8db26 ~Reviewer:CW01\uidt9253 ~Date:4/2/2012 ~Priority:3 ~Comment:The order of evaluation is not guaranteed. Check for NULL must be done in a separate if clause */
          if ((pTLBselected->iconState.classCnt == 0) &&
              (pTLBselected->light_ref != NULL) &&
              (pTLBselected->light_ref->pRegion != NULL))
          {
            /* when requesting an vehicle icon for the first time: use a negative classResultSum for previously negatively validated icons in the same region */
            const HLASegLineRegion_t* restrict pRegionHighestCycleCount = pTLBselected->light_ref->pRegion;
            const HLATrack_t* pTLB = pTLB_Start;
            while (pTLB != NULL)
            {
              if ((pTLB->xcenter >= pRegionHighestCycleCount->x1) &&
                  (pTLB->xcenter <= pRegionHighestCycleCount->x2) &&
                  (pTLB->ycenter >= pRegionHighestCycleCount->y1) &&
                  (pTLB->ycenter <= pRegionHighestCycleCount->y2) &&
                  (pTLB->iconState.classResultSum < pTLBselected->iconState.classResultSum))
              {
                pTLBselected->iconState.classResultSum = pTLB->iconState.classResultSum;
              }

              /* go to next object */
              pTLB = pTLB->next;
            }
          }
          /* ~CodeReviewEnd   ~ID:8f168b5e9c45f86aaedd7de1040de55a */
        }

        if ((pTLBselected->statusAnalysisMisc.isSceneStreetLamp == 1) ||
            (pTLBselected->statusAnalysisMisc.isSceneStreetLampLowInt == 1) ||
            (pTLBselected->statusAnalysisMisc.isLeavingStreetLamp == 1))
        {
          pTLBselected->iconStateCity.status.iconRequested = 1;
        }
      }
    }
  }
}

static void HLAIconPosFromTrack(const HLATrack_t*                   pTLB,
                                const HLATracking3DParametersMeasurement_t*     pTracking3DParamsMeasurement,
                                sint16*                             xTopLeft,
                                sint16*                             yTopLeft,
                                sint16*                             xBottomRight,
                                sint16*                             yBottomRight)
{
  sint16 x, y;

#ifdef PC_SIM
  assert(pTLB->light_ref != NULL);
  assert(pTracking3DParamsMeasurement != NULL);
#endif

  /* for direct image access take the light position */
  HLAKalmanMeasPosPix_t lightPosPix;
  HLATrackMeasGetPixCoordinates(&lightPosPix, pTLB->light_ref, pTracking3DParamsMeasurement);

  x = (sint16)CML_s_Round2Int(lightPosPix.x_center_pix);
  y = (sint16)CML_s_Round2Int(lightPosPix.y_center_pix);

  *xTopLeft = x - (HLA_ICON_ANALYSIS_MAX_SIZE_X / 2);
  *yTopLeft = y - (HLA_ICON_ANALYSIS_MAX_SIZE_Y / 2);

  *xBottomRight = *xTopLeft + (HLA_ICON_ANALYSIS_MAX_SIZE_X - 1);
  *yBottomRight = *yTopLeft + (HLA_ICON_ANALYSIS_MAX_SIZE_Y - 1);
}

static void HLAIconCopyIcons(const HLA_t_CameraParameter*  pCameraParameter)
{
  HLAIconList_t* pIcon = phlaIcon->phlaIconList;
  sint32 rowOffsetPixels = pCameraParameter->s_ImageHeader.iRowBytes / pCameraParameter->s_ImageHeader.iPixelBytes;

  while(pIcon != NULL)
  {
    HLAIconData_t* restrict pIconData = pIcon->pData;


    t_PixelData* restrict pSrc =  phlaImg
                               + ((pIconData->Pos.Y1 - pCameraParameter->s_CroppedRoiX1.ui32_y) * (uint32) rowOffsetPixels)
                               + (pIconData->Pos.X1 - pCameraParameter->s_CroppedRoiX1.ui32_x);

    t_PixelData* pDst = pIconData->pData;

#ifdef _TMS320C6X
    uint32 x, y;
    uint16 offsetToNextRow = (uint16)(rowOffsetPixels - pIconData->Pos.Width);

    #pragma MUST_ITERATE(HLA_ICON_ANALYSIS_MAX_SIZE_Y, HLA_ICON_ANALYSIS_MAX_SIZE_Y, HLA_ICON_ANALYSIS_MAX_SIZE_Y)
    for (y = 0; y < pIconData->Pos.Height; y++ )
    {
      #pragma UNROLL(HLA_ICON_ANALYSIS_MAX_SIZE_X)
      #pragma MUST_ITERATE(HLA_ICON_ANALYSIS_MAX_SIZE_X, HLA_ICON_ANALYSIS_MAX_SIZE_X, HLA_ICON_ANALYSIS_MAX_SIZE_X)
      for (x = 0; x < pIconData->Pos.Width; x++)
      {
        *pDst = *pSrc;
        pDst++;
        pSrc++;
      }
      pSrc += offsetToNextRow;
    }
#else  
    uint32 y;

    for (y=0; y<pIconData->Pos.Height; y++ )
    {
      (void)memcpy(pDst, pSrc, sizeof(t_PixelData) * pIconData->Pos.Width);
      pDst += pIconData->Pos.Width;
      pSrc += pCameraParameter->s_ImageHeader.iRowBytes / pCameraParameter->s_ImageHeader.iPixelBytes;
    }
#endif

    pIconData->eState = ICON_STATE_DATA_VALID;

    /* go to next icon */
    pIcon = pIcon->pNext;
  }
}

