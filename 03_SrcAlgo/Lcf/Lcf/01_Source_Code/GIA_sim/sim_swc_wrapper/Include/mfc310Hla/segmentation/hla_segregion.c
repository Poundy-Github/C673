/*! \file **   ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    Ti DSP

  COMPONENT:              HLA

  MODULNAME:              hla_segregion.c

  DESCRIPTION:            Find local Maximas (Lights) in the image.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          01.10.2010

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_segregion.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:40CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:27CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:58CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/segmentation/project.pj
  CHANGE:                 Revision 1.2 2014/03/26 14:44:45CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 2:44:45 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.1 2014/03/25 18:48:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/segmentation/project.pj
  **************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_segregion.h" 

/******************************************************************************
* DEFINITIONS
******************************************************************************/
/* the function checks if the new line is part of an existing region and */
/* merges a new line to a the region                                     */
static void HLASegRegionMergeLine2Region(       HLASegLineBuffer_t*       pLineBuffer,
                                          const uint16                    iLine,             /* new line */
                                          const uint8*                    pRow, /* check if the new line is part of one of the regions from this Row (*pRow) */
                                          const uint32                    iRowStart,
                                          const uint32                    iRowStop,
                                                uint8*                    piRegStart,
                                                uint8*                    pnRegions,
                                                uint8*                    piRegFree,                                          
                                                uint8* restrict           pRow1, /* previous row */
                                                uint8* restrict           pRow0,  /* current row */
                                                uint8*                    piRegionMergeTo,
                                                HLASegLineRegionBuffer_t* pRegionBuffer
                                        );
static void HLASegRegionMerge2Regions( const uint8                     iRegionMergeTo,
                                       const uint8                     iRegionMergeFrom,
                                             HLASegLineBuffer_t*       pLineBuffer,
                                             uint8*                    piRegionStart,
                                             uint8*                    piRegFree,                                              
                                             uint8*                    pnRegions,
                                             HLASegLineRegionBuffer_t* pRegionBuffer
                                       );

static void HLASegRegionRemoveRegion( const uint8                     iRegionToRemove,
                                            uint8*                    piRegionStart,
                                            uint8*                    piRegFree,                                      
                                            uint8*                    pnRegions,
                                            HLASegLineRegionBuffer_t* pRegionBuffer
                                    );


/* ****************************************************************************
  Functionname:     HLASegRegionBuildList */ /*!
  Description:      

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLASegRegionBuildList(       HLASegLineBuffer_t*                           pLineBuffer,
                            const HLASegmentationParametersLineCluster_t*       pParLineCluster,
                            const HLACameraData_t*                              pCamData,
                            const uint8                                         Level,                                  
                            const HLASegLineLevel_t*                            pLinesLevel,
                                  uint8*                                        piRegStart,
                                  uint8*                                        pnRegions,
                                  uint8*                                        piRegFree,
                                  HLASegLineRegionBuffer_t*                     pRegionBuffer
                          )
{
  uint8 Row1_Buf[(HLA_MAX_PHYS_IMAGE_HEIGHT>>1)+2];
  uint8 Row0_Buf[(HLA_MAX_PHYS_IMAGE_HEIGHT>>1)+2];
  uint8 *pPrevRow;
  uint8 *pCurRow;
  uint8 iRegionMergeTo;
  
  sint32 iRegionBuffer;

  sint32 nPrevRow;
  sint32 nCurRow;
  uint32 j;
  sint32 FirstLine = 1; 

  uint16 iLine;
  uint16 iLine_Prev; /* previous line at same level */
  uint16 iLine_End;

  uint8 iRegHelp;
    
  uint32 cc1, cc2;
  uint8 nRegions;
  HLASegLineRegion_t *Region = &(pRegionBuffer->Region[0]);

  /* generate lights out of local maximum */
  pPrevRow  = Row1_Buf;
  pCurRow   = Row0_Buf;
  (void)memset((void*)pPrevRow,  0, ((HLA_MAX_PHYS_IMAGE_HEIGHT/2)+2)*sizeof(uint8));
  (void)memset((void*)pCurRow,   0, ((HLA_MAX_PHYS_IMAGE_HEIGHT/2)+2)*sizeof(uint8));
  

  nPrevRow = 0;
  nCurRow  = 0;
  
  iLine      = pLinesLevel->iLine;
  iLine_Prev = iLine;
  iLine_End  = pLinesLevel->iLine + pLinesLevel->nLines;
  
 
  /* reset number of regions */
  nRegions = 0;
  while(iLine < iLine_End)
  {
    
    uint32 dy0, dy1;
    {
      /* next line starts ?                    */
      /* but not the first line of this region */
      if(FirstLine == 0)
      {
        if(pLineBuffer->Line[iLine].x > pLineBuffer->Line[iLine_Prev].x)
        {
          /* distance between cur. pLine and last line is 2 pixel */
          if (pLineBuffer->Line[iLine].x == (pLineBuffer->Line[iLine_Prev].x + 2))
          {
            if(nPrevRow != 0)
            {
              (void)memset((void*)pPrevRow, 0, ((HLA_MAX_PHYS_IMAGE_HEIGHT/2)+2)*sizeof(uint8));
            }            
            
            nPrevRow  = nCurRow;
            nCurRow   = 0;
            /* swap pointers */
            {
              uint8 *tmp3;

              tmp3      = pPrevRow;
              pPrevRow  = pCurRow;
              pCurRow   = tmp3;
            }
          }
          /* more than 2 lines between current and last line */
          else
          {
            /* reset current and previous line buffer */
            if(nCurRow != 0)
            {
              (void)memset((void*)pCurRow, 0, ((HLA_MAX_PHYS_IMAGE_HEIGHT/2)+2)*sizeof(uint8));
              nCurRow  = 0;
            }
            if(nPrevRow != 0)
            {
              (void)memset((void*)pPrevRow, 0, ((HLA_MAX_PHYS_IMAGE_HEIGHT/2)+2)*sizeof(uint8));
              nPrevRow = 0;
            }
          }
        }
      }
      
      if(    (pLineBuffer->Line[iLine].y2 < (pCamData->FOE_y - pParLineCluster->dyFOE))
          || (pLineBuffer->Line[iLine].y1 > (pCamData->FOE_y + pParLineCluster->dyFOE))
          || (pLineBuffer->Line[iLine].x  < (pCamData->FOE_x - pParLineCluster->dxFOE))
          || (pLineBuffer->Line[iLine].x  > (pCamData->FOE_x + pParLineCluster->dxFOE))
        )
      {
        /* line in border region, not in FOE region */
        dy0 = (pLineBuffer->Line[iLine].y1 + 1u) >> 1;
        dy1 = (pParLineCluster->ClusterBorder.dy4dx1 + 1u) >> 1;
      }  
      else
      {
        /* line in core region around the FOE */
        dy0 = (pParLineCluster->ClusterFOE.dy4dx0 + 1u) >> 1;
        dy1 = (pParLineCluster->ClusterFOE.dy4dx1 + 1u) >> 1;
      }

      /* analyze current line segment          */
      /* -> region before current line segment */
      /*    -> merge lines                     */
      cc1 = (pLineBuffer->Line[iLine].y1 + 1u) >> 1;
      cc2 = (pLineBuffer->Line[iLine].y2 + 1u) >> 1;
      iRegionMergeTo = HLA_SEG_MAX_NUM_REGIONS;
      
      /* look in current row */
      if(nCurRow != 0)
      {
        if (dy0 > cc1)
        {
          dy0 = cc1;
        }
        /* is there a region before current line segment ? */
        /* save region array index into iRegionMergeTo    */
        HLASegRegionMergeLine2Region( pLineBuffer, 
                                      iLine,            /* new line */
                                      pCurRow,          /* check if the new line is part of one of the regions from this Row (*pRow) */
                                      cc1 - dy0,        /* iRowStart */
                                      cc1,              /* iRowStop */
                                      piRegStart,
                                      &nRegions,
                                      piRegFree,
                                      pPrevRow,         /* previous column */
                                      pCurRow,          /* current column */
                                      &iRegionMergeTo,
                                      pRegionBuffer                                      
                                     );
      }

      /* look in previous row */
      if(nPrevRow != 0)
      {
        if (dy1 > cc1)
        {
          dy1 = cc1;
        }
        /* is there a region before current line segment ? */
        /* save region array index into iRegionMergeTo    */
        HLASegRegionMergeLine2Region( pLineBuffer,
                                      iLine,             /* new line */
                                      pPrevRow,          /* check if the new line is part of one of the regions from this Row (*pRow) */
                                      cc1 - dy1,         /* iRowStart */
                                      cc2 + dy1,         /* iRowStop */
                                      piRegStart,
                                      &nRegions,
                                      piRegFree,
                                      pPrevRow,          /* previous column */
                                      pCurRow,           /* current column */
                                      &iRegionMergeTo,
                                      pRegionBuffer                                      
                                    );
      }
            
      /* found one region above the current line segment ? */
      if(iRegionMergeTo < HLA_SEG_MAX_NUM_REGIONS)
      {
        uint8 iRegionMergeToP1 = iRegionMergeTo +1;

        /* save merged light in pCurRow */
        for(j=cc1; j<=cc2; j++)
        {
          pCurRow[j] = iRegionMergeToP1;
        }
      }    

      /* new region ? */
      if(pCurRow[cc1] == 0)
      {
        /* new region ! */
        /* free region available ? */
        if(*piRegFree < HLA_SEG_MAX_NUM_REGIONS)
        {
          /* add new region into the list */
          iRegHelp    = *piRegStart;
          *piRegStart = *piRegFree;
          *piRegFree  = Region[*piRegFree].iNext;
          Region[*piRegStart].iNext = iRegHelp;
                              
          /* first line segment          */
          /* -> set next pointer to NULL */
          pLineBuffer->Line[iLine].iLineNext = HLA_SEG_MAX_NUM_SEG_LINES;
          /* save region dimension */
          Region[*piRegStart].x1 = pLineBuffer->Line[iLine].x;
          Region[*piRegStart].x2 = pLineBuffer->Line[iLine].x+1;
          Region[*piRegStart].y1 = pLineBuffer->Line[iLine].y1;
          Region[*piRegStart].y2 = pLineBuffer->Line[iLine].y2;
          Region[*piRegStart].ySum = pLineBuffer->Line[iLine].y2 - pLineBuffer->Line[iLine].y1;
          Region[*piRegStart].iLine = iLine;
          Region[*piRegStart].iLineLast = iLine;
          Region[*piRegStart].Level = Level;
                    
          /* increment number of regions */
          nRegions++;
           
          /* array index of the current region */
          iRegionBuffer = *piRegStart;
          for(j=cc1; j<=cc2; j++)
          {
            /* ~CodeReview ~ID:a4b7600a1d5b038c12ce9a0e3f0d8bd0 ~Reviewer:CW01\muellerr5 ~Date:03.07.2012 ~Priority:2 ~Comment:move +1 outside for loop */
            pCurRow[j] = (uint8)iRegionBuffer + 1;
          }
        }
        else
        {
          /* region buffer full */
          break;
        }
        
      }
      nCurRow++;
      FirstLine = 0;
      iLine_Prev = iLine;
    }
    iLine++;
  }  /* end:  for loop over line segments */
  /* copy number of region into output struct */
  *pnRegions = nRegions;
}



/* ****************************************************************************
  Functionname:     HLASegRegionBuildRelationship
  Description:      Build relationship between the regions (link to the underlying region).
                    Beginning from highest level to the lowest level.
                    L3-> L2 -> L1
                    
  @param[in]             

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
                                    
void HLASegRegionBuildRelationship(       HLASegLineBuffer_t*       pLineBuffer,
                                    const uint8                     iUpperRegStart,
                                    const uint8                     iLowerRegStart,
                                          HLASegLineRegionBuffer_t* pRegionBuffer
                                  )
{
  uint8 iUpperReg, iLowerReg;
  HLASegLineRegion_t *Region = &(pRegionBuffer->Region[0]);
  HLASegLine_t       *Line   = &pLineBuffer->Line[0];
  
  iUpperReg = iUpperRegStart;
  while(iUpperReg < HLA_SEG_MAX_NUM_REGIONS)
  {
    Region[iUpperReg].pRegionBelow = NULL;
    
    /* find lower region */
    iLowerReg = iLowerRegStart;
    while(iLowerReg < HLA_SEG_MAX_NUM_REGIONS)
    {
      /* does upper region lie completely inside the lower region ? */
      if(    (Region[iUpperReg].x1 >= Region[iLowerReg].x1)
          && (Region[iUpperReg].x2 <= Region[iLowerReg].x2)
          && (Region[iUpperReg].y1 >= Region[iLowerReg].y1)
          && (Region[iUpperReg].y2 <= Region[iLowerReg].y2)
        )
      {
        /* check if upper region is part of lower region */        
        uint16  UpperRegLine_x  = Line[Region[iUpperReg].iLine].x;
        uint16  UpperRegLine_y1 = Line[Region[iUpperReg].iLine].y1;
        uint16  iLine           = Region[iLowerReg].iLine;

        while(iLine < HLA_SEG_MAX_NUM_SEG_LINES)
        {
          if(    (UpperRegLine_x  == Line[iLine].x)
              && (UpperRegLine_y1 >= Line[iLine].y1)
              && (UpperRegLine_y1 <= Line[iLine].y2)
            )
          {
            /* link to underlying region found */
            /* save pointer to lower region    */  
            Region[iUpperReg].pRegionBelow = &Region[iLowerReg];

            /* set minor region bit */
            Region[iUpperReg].pRegionBelow->Status.MinorRegion = 1;
            pRegionBuffer->Level[Region[iUpperReg].pRegionBelow->Level].nRegionsSuperior--;
            pRegionBuffer->nRegionsSuperior--;

            /* break while loops            */
            /* -> step to next upper region */
            iLine     = HLA_SEG_MAX_NUM_SEG_LINES;
            iLowerReg = HLA_SEG_MAX_NUM_REGIONS;
          }
          else
          {
            iLine = Line[iLine].iLineNext;
          }
        }
      }
      if(iLowerReg < HLA_SEG_MAX_NUM_REGIONS)
      {
        iLowerReg = Region[iLowerReg].iNext;
      }
    }
    iUpperReg = Region[iUpperReg].iNext;
  }
}


/* ****************************************************************************
  Functionname:     HLASegRegionMergeLine2Region */ /*!
  Description:      checks if the new line is part of an existing region

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegRegionMergeLine2Region(       HLASegLineBuffer_t*       pLineBuffer,
                                          const uint16                    iLine,             /* new line */
                                          const uint8*                    pRow, /* check if the new line is part of one of the regions from this Row (*pRow) */
                                          const uint32                    iRowStart,
                                          const uint32                    iRowStop,
                                                uint8*                    piRegStart,
                                                uint8*                    pnRegions,
                                                uint8*                    piRegFree,                                          
                                                uint8* restrict           pRow1, /* previous row */
                                                uint8* restrict           pRow0,  /* current row */
                                                uint8*                    piRegionMergeTo,
                                                HLASegLineRegionBuffer_t* pRegionBuffer
                                        )
{
  uint32 j, k, k1, k2;
  HLASegLineRegion_t *Region = &(pRegionBuffer->Region[0]);

  /* is there a region before current line segment ? */
  /* save region array index into iRegionMergeTo    */
  for(j = iRowStart; j <= iRowStop; j++)
  {
    if(pRow[j])
    {
      /* region in current row detected */
      uint8 iRegion = pRow[j] - 1u;

      if((*piRegionMergeTo < HLA_SEG_MAX_NUM_REGIONS) && (*piRegionMergeTo != iRegion))
      {
        uint8 iRegionMergeFromP1 = pRow[j];
        uint8 iRegionMergeToP1 = (*piRegionMergeTo)+1;

        /* merge regions */
        /* previous and current row line buffer: overwrite old region array index with the new one */
        k1 = ((Region[iRegion].y1 + 1u) >> 1);
        k2 = ((Region[iRegion].y2 + 1u) >> 1);
        for(k = k1; k <= k2; k++)
        {
          if(pRow1[k] == iRegionMergeFromP1)
          {
            /* overwrite old region buffer index with the new one */
            pRow1[k] = iRegionMergeToP1;
          }
          if(pRow0[k] == iRegionMergeFromP1)
          {
            /* overwrite old region buffer index with the new one */
            pRow0[k] = iRegionMergeToP1;
          }
        }
        /* merge the two region into one region */
        HLASegRegionMerge2Regions( *piRegionMergeTo, 
                                    iRegion, 
                                    pLineBuffer, 
                                    piRegStart, 
                                    piRegFree, 
                                    pnRegions, 
                                    pRegionBuffer
                                   );
      }
      else
      {
        /* save merged to region pointer and array index */
        *piRegionMergeTo  = pRow[j] - 1u;
      }

      /* new line segment to add to the region ? */
      if (Region[*piRegionMergeTo].iLine != iLine)
      {
        /* update region dimension */
        Region[*piRegionMergeTo].y1 = CML_Min(Region[*piRegionMergeTo].y1, pLineBuffer->Line[iLine].y1);
        Region[*piRegionMergeTo].y2 = CML_Max(Region[*piRegionMergeTo].y2, pLineBuffer->Line[iLine].y2);
        Region[*piRegionMergeTo].x2 = pLineBuffer->Line[iLine].x + 1u;
        Region[*piRegionMergeTo].ySum += (pLineBuffer->Line[iLine].y2 - pLineBuffer->Line[iLine].y1);


        /* add line segment to the region */
        pLineBuffer->Line[iLine].iLineNext = Region[*piRegionMergeTo].iLine;
        Region[*piRegionMergeTo].iLine = iLine;
      }
    }
  }
}


/* ****************************************************************************
  Functionname:     HLASegRegionMerge2Regions
  Description:      Merge two regions.

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn, Reinhard Schuler
****************************************************************************  */
static void HLASegRegionMerge2Regions( const uint8                     iRegionMergeTo,
                                       const uint8                     iRegionMergeFrom,
                                             HLASegLineBuffer_t*       pLineBuffer,
                                             uint8*                    piRegionStart,
                                             uint8*                    piRegFree,                                              
                                             uint8*                    pnRegions,
                                             HLASegLineRegionBuffer_t* pRegionBuffer
                                      )
{
  HLASegLine_t *Line = &pLineBuffer->Line[0];
  HLASegLineRegion_t *Region = &(pRegionBuffer->Region[0]);
  
  /* merge data */
  Region[iRegionMergeTo].x1 = CML_Min(Region[iRegionMergeTo].x1, Region[iRegionMergeFrom].x1);
  Region[iRegionMergeTo].y1 = CML_Min(Region[iRegionMergeTo].y1, Region[iRegionMergeFrom].y1);
  Region[iRegionMergeTo].x2 = CML_Max(Region[iRegionMergeTo].x2, Region[iRegionMergeFrom].x2);
  Region[iRegionMergeTo].y2 = CML_Max(Region[iRegionMergeTo].y2, Region[iRegionMergeFrom].y2);

  Region[iRegionMergeTo].ySum += Region[iRegionMergeFrom].ySum;

  /* add lines from RegionMergeFrom to the end of RegionMergeTo */
  Line[Region[iRegionMergeTo].iLineLast].iLineNext = Region[iRegionMergeFrom].iLine;
  Region[iRegionMergeTo].iLineLast = Region[iRegionMergeFrom].iLineLast;

  /* delete merged region */
  HLASegRegionRemoveRegion( iRegionMergeFrom,
                            piRegionStart,
                            piRegFree,
                            pnRegions, 
                            pRegionBuffer
                          );
}


/* ****************************************************************************
  Functionname:     HLASegRegionRemoveRegion                             */ /*!
  Description:      Remove region (pRegionToRemove) from list (ppRegionStart)
                    and put it to free region list (ppRegFree).

  @param[in]        

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLASegRegionRemoveRegion( const uint8                     iRegionToRemove,
                                            uint8*                    piRegionStart,
                                            uint8*                    piRegFree,                                      
                                            uint8*                    pnRegions,
                                            HLASegLineRegionBuffer_t* pRegionBuffer
                                    )
{
  HLASegLineRegion_t *Region = &(pRegionBuffer->Region[0]);
  uint8 *piRegion;    

  /* find region in the list */
  piRegion = piRegionStart;
  while(*piRegion < HLA_SEG_MAX_NUM_REGIONS)
  {
    if(*piRegion == iRegionToRemove)
    {
      /* remove merged region from list of regions */
      *piRegion = Region[iRegionToRemove].iNext;

      /* add removed region to list of free regions */
      Region[iRegionToRemove].iNext = *piRegFree;
      *piRegFree = iRegionToRemove;

      /* decrement number of regions */  
      if(*pnRegions)
      {
        *pnRegions = *pnRegions - 1;
      }

      /* end loop */
      break;
    }
    piRegion = &Region[*piRegion].iNext;
  }
}
