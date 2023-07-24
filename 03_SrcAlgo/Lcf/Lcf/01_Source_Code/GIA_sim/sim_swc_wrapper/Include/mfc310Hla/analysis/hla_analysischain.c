/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysischain.c

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Boris Lugez

  CREATION DATE:          2011-05-17

  VERSION:                $Revision: 1.1 $

  CHANGES:

  ---*/ /*---
  CHANGE:                 $Log: hla_analysischain.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:41CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:37:53CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:12CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.29 2014/03/28 10:36:13CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 28, 2014 10:36:13 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.28 2014/03/25 19:11:53CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Separation of hla_segmentation.c
  CHANGE:                 Removed QAC warnings
  CHANGE:                 Replaces fABS by CML_f_abs
  CHANGE:                 Introduced CML_s_Round2Int
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:53 PM CET]
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.27 2014/03/25 18:32:13CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_analysischain.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_analysischain.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGE:                 Revision 1.26 2014/03/19 16:31:28CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:29 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.25 2014/03/13 10:32:57CET Glebov, Roman (uidg4759) 
  CHANGE:                 removed leader underscores from argument names in the declaration of function candidateSet
  CHANGE:                 --- Added comments ---  uidg4759 [Mar 13, 2014 10:32:57 AM CET]
  CHANGE:                 Change Package : 217406:2 http://mks-psad:7002/im/viewissue?selection=217406
  CHANGE:                 Revision 1.24 2014/03/13 10:12:33CET Glebov, Roman (uidg4759) 
  CHANGE:                 not building chain of light with lights, which are above horizon or are isExtremelyBright
  CHANGE:                 --- Added comments ---  uidg4759 [Mar 13, 2014 10:12:33 AM CET]
  CHANGE:                 Change Package : 217406:2 http://mks-psad:7002/im/viewissue?selection=217406
  CHANGE:                 Revision 1.23 2014/03/12 18:07:44CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added LRF on EVE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:44 PM CET]
  CHANGE:                 Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.22 2014/03/10 13:21:05CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:21:05 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.21 2014/03/04 15:52:24CET Glebov, Roman (uidg4759) 
  CHANGE:                 using now sint32 in place of float32 for angle.
  CHANGE:                 
  CHANGE:                 changed directAngleFunction input arguments from float32 to sint16
  CHANGE:                 --- Added comments ---  uidg4759 [Mar 4, 2014 3:52:25 PM CET]
  CHANGE:                 Change Package : 217406:2 http://mks-psad:7002/im/viewissue?selection=217406
  CHANGE:                 Revision 1.20 2014/03/04 10:06:05CET Glebov, Roman (uidg4759)
  CHANGE:                 refactoring and speed up of chain of light
  CHANGE:                 --- Added comments ---  uidg4759 [Mar 4, 2014 10:06:06 AM CET]
  CHANGE:                 Change Package : 217406:2 http://mks-psad:7002/im/viewissue?selection=217406
  CHANGE:                 Revision 1.19 2014/01/28 16:22:39CET Glebov, Roman (uidg4759)
  CHANGE:                 optimization of chain of lights, leads to longer horizontal chains.
  CHANGE:                 checking that the segment angle does not change too much
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 28, 2014 4:22:39 PM CET]
  CHANGE:                 Change Package : 199150:2 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.18 2013/12/25 21:54:44CET Glebov, Roman (uidg4759)
  CHANGE:                 added additional comments to chain of lights
  CHANGE:                 --- Added comments ---  uidg4759 [Dec 25, 2013 9:54:45 PM CET]
  CHANGE:                 Change Package : 193435:3 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.17 2013/12/17 17:32:41CET Glebov, Roman (uidg4759)
  CHANGE:                 QAC Changes + Documentation of Chain of Light + fix of devision by 0 + small efficiency tweaks
  CHANGE:                 --- Added comments ---  uidg4759 [Dec 17, 2013 5:32:41 PM CET]
  CHANGE:                 Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.16 2013/07/23 09:51:22CEST Fischer, Alexander (uidv8778)
  CHANGE:                 Added more debug information
  CHANGE:                 --- Added comments ---  uidv8778 [Jul 23, 2013 9:51:22 AM CEST]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.15 2013/07/12 11:19:20CEST Fischer, Alexander (uidv8778)
  CHANGE:                 Further restructuring of chain of light
  CHANGE:                 --- Added comments ---  uidv8778 [Jul 12, 2013 11:19:21 AM CEST]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.14 2013/06/21 16:17:23CEST Fischer, Alexander (uidv8778)
  CHANGE:                 Moved chain of light visu from hla_analysischain to sim_hla_visualisation_draw
  CHANGE:                 --- Added comments ---  uidv8778 [Jun 21, 2013 4:17:30 PM CEST]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
**************************************************************************** */

/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>
#include "hla_analysischain.h"
#include "hla_analysischain_utils.h"

/********************/
/* CONSTANTS        */
/********************/

/* neutral angle */
static const sint32 neutralAngle = -1;

/* minimal angle between two segments to be considered as a part of chain of light. Ideally it is 180 */
static const sint32 minimalSegmentAngle = 165;

/********************/
/* TYPE DEFINITIONS */
/********************/

typedef struct
{
  /* x coordinate */
  sint16 x;

  /* y coordinate */
  sint16 y;

  /* list index*/
  uint8 idx;

  /* distance euclidean distance
  between reference node and candidate node*/
  float32 dist;

} CandidateData_t;

/*************************/
/* FUNCTION DELCARATIONS */
/*************************/

static void candidateReset (CandidateData_t* c);

static void candidateSet (CandidateData_t* c, sint16 x, sint16 y, uint8 idx, float32 dist);

static void HLAParLine (float32* A, float32* B, sint16 xa, sint16 ya, sint16 xb, sint16 yb);

static uint8 HLAInitializeData (HLATrack_t* pTrackListHead, HLAChainOfLightData_t* pCoLData);

static boolean HLADecideIsPotentialChainNode (
  const HLATrack_t* pTLReference,
  const HLATrack_t* pTLCurrent,
  const HLA_t_ChainParam* pParam,
  float32 MaxDist2_UpperLower,
  sint16 MaxDist_UpperLower_X,
  sint16 MaxDist_UpperLower_Y,
  sint16 deltaX,
  sint16 deltaY,
  float32 length,
  sint16 LightHeightReference,
  sint16 LightWidthReference
);

static void HLAFindBestNeighborsOfTrack (
  HLAChainOfLightData_t* pCoLData,
  const HLA_t_ChainParam* pParam,
  const HLATrack_t* pTLReference,
  sint32 cntReference,
  HLATrack_t* pTrackListHead,
  uint8 numberOfTracks,

  float32 MaxDist2_UpperLower,
  sint16 MaxDist_UpperLower_X,
  sint16 MaxDist_UpperLower_Y,

  CandidateData_t* upper1,

  CandidateData_t* upper2,

  CandidateData_t* lower1,

  CandidateData_t* lower2
);

static uint8 HLAMarkChains (HLAChainOfLightData_t* pCoLData);

static void HLAChooseBestCandidate ( CandidateData_t*           pUpper,
                                     CandidateData_t*           pLower,
                                     const CandidateData_t*     pUpper1,
                                     const CandidateData_t*     pLower1,
                                     const CandidateData_t*     pUpper2, 
                                     const CandidateData_t*     pLower2,
                                     sint32*                    chosenAngle,
                                     float32                    MaxDist2_UpperLower,
                                     const sint16               xImagePosReference, 
                                     const sint16               yImagePosReference,
                                     boolean*                   bAngleBetweenSegmentsIsGood
                                    );

static void HLAConnectWithAlreadyFoundSegments ( const sint32                 MaxAngleTillNow,
                                                 const boolean                isPeriodic, 
                                                 const boolean                bAngleBetweenSegmentsIsGood,
                                                       HLAChainOfLightData_t* pCoLData, 
                                                 const sint32                 cntReference,
                                                 const CandidateData_t*       upper, 
                                                 const CandidateData_t*       lower,
                                                 const sint16                 xImagePosReference, 
                                                 const sint16                 yImagePosReference
                                               );

static  boolean HLACheckIsPeriodic ( const CandidateData_t*  pUpper,
                                     const CandidateData_t*  pLower,
                                     const sint16            xImagePosReference,
                                     const sint16            yImagePosReference,
                                     const HLA_t_ChainParam* pParam
                                    );


static void HLAFindChainSegments (
  HLATrack_t* pTrackListHead,
  HLAChainOfLightData_t* pCoLData,
  float32 aParamLine,
  float32 bParamLine,
  const HLA_t_ChainParam* pParam
);

static void HLAMarkChainOfLightTracks (
  const HLAChainOfLightData_t* pCoLData,
  const HLA_t_ChainParam* pParam
);

static void HLAComputeCoLConfidence (
  HLATrack_t* pTrackListHead,
  const HLA_t_ChainParam* pParam
);

/****************************/
/* FUNCTION IMPLEMENTATIONS */
/****************************/

/* reset CoL-Flags to initial state, determine number of tracks */
static  uint8 HLAInitializeData (HLATrack_t* pTrackListHead, HLAChainOfLightData_t* pCoLData)
{
  sint32 cntCurrent = 0;
  HLATrack_t* pTLReference = pTrackListHead;

  (void) memset ( (void*) pCoLData->trackClusterList, 0, sizeof (HLATrackClusterList_Node_t) *NB_OF_TRACKS);

  (void) memset ( (void*) pCoLData->clusterTrackList, 0, sizeof (HLATrack_t*) * (NB_OF_CHAINS * MAX_LENGTH_CHAIN));

  /* Select NB_OF_TRACKS tracks out of full track list and set the Nodes */
  while (pTLReference != NULL)
  {
    if (cntCurrent < NB_OF_TRACKS)
    {
      /* initialize track/chain list */

      /*
      * for every track from track list creating a new node with a pointer to the actual track,
      */
      pCoLData->trackClusterList[cntCurrent].pT = pTLReference;

      pCoLData->trackClusterList[cntCurrent].angleUL = neutralAngle;

      /* setting reference indexes to the upper and down track to 0 */
      pCoLData->trackClusterList[cntCurrent].tCntBelow = 0;
      pCoLData->trackClusterList[cntCurrent].tCntUp = 0;

      cntCurrent++;
    }

    /* initially resetting chain of light flag for all tracks, which are to be analyzed */
    pTLReference->statusAnalysisMisc.isChainOfLight = 0;

    pTLReference = pTLReference->next;
  }

  /* storing counter value */
  return (uint8) cntCurrent;
}

static  void candidateReset (CandidateData_t* c)
{
  c->x = 0;
  c->y = 0;
  c->idx = 0;
  c->dist = 0;
}

static  void candidateSet (CandidateData_t* c, sint16 x, sint16 y, uint8 idx, float32 dist)
{
  c->x    = x;
  c->y    = y;
  c->idx  = idx;
  c->dist = dist;
}

static  boolean HLADecideIsPotentialChainNode (
  const HLATrack_t* pTLReference,
  const HLATrack_t* pTLCurrent,
  const HLA_t_ChainParam* pParam,
  float32 MaxDist2_UpperLower,
  sint16 MaxDist_UpperLower_X,
  sint16 MaxDist_UpperLower_Y,
  sint16 deltaX,
  sint16 deltaY,
  float32 length,
  sint16 LightHeightReference,
  sint16 LightWidthReference
)
{
  /* minimal brightness of light */
  static const float32 minIntensity = 50.0f;

  sint16 LightHeightCurrent;
  sint16 LightWidthCurrent;

  boolean result = b_FALSE;

  /* intensity delta */
  sint32 deltaMaxInt = 0;

  /* saves sum of intensities */
  uint32 sumMaxInt = 0;

  boolean bIntensityTooDifferent = b_FALSE;

  boolean bLightSizeInfoAvailableAndTooISDifferent = b_FALSE;

  uint16 diffSizeHeight = 0;
  uint16 diffSizeWidth = 0;

  if (pTLCurrent != pTLReference)
  {
    /*  computing widths and heights of light regions, associated with tracks,
    in the case when there are currently valid associations of a light source to each track */
    if ( (pTLCurrent->light_ref != NULL)
         && (pTLCurrent->light_ref->pRegion != NULL)
       )
    {
      /* computing width and height of current tracks light source */
      LightHeightCurrent = (sint16) pTLCurrent->light_ref->pRegion->y2 - (sint16) pTLCurrent->light_ref->pRegion->y1;
      LightWidthCurrent = (sint16) pTLCurrent->light_ref->pRegion->x2 - (sint16) pTLCurrent->light_ref->pRegion->x1;
    }
    else
    {
      LightHeightCurrent = 0;
      LightWidthCurrent = 0;
    }

    if ( (pTLReference->light_ref != NULL)
         && (pTLCurrent->light_ref != NULL)
       )
    {
      deltaMaxInt = pTLReference->light_ref->MaxInt - pTLCurrent->light_ref->MaxInt;
      sumMaxInt = pTLReference->light_ref->MaxInt + pTLCurrent->light_ref->MaxInt;
    }
    else
    {
      deltaMaxInt = 0;
      sumMaxInt = 0;
    }

    /*
    *  Examining tracks, with the goal to find for each track associated chain segments
    *
    *  Tracks which lay near each other are potential candidates for being a part of a light chain.
    *
    *  Skipping tracks if the squared distance between them and difference in the lateral position is too big,
    *  track references pointing to the same track struct
    *  or there where lost updates for the first track.
    *  Lost update happens, when it was not possible to associate a track with a light segment.
    *
    */
    if ( (abs (deltaX) < MaxDist_UpperLower_X)
         && (length < MaxDist2_UpperLower)
         /*&& (pTLCurrent->lost_time == 0)*/
         && (pTLCurrent->light_ref != NULL)
         && (pTLCurrent != pTLReference)
         &&  (pTLCurrent->statusAnalysisMisc.isFarAboveHorizon == FALSE)
         /*&&  (pTLCurrent->anaResStat.isLateralBright.result == HLA_RESULT_NEGATIVE)*/
         &&  (pTLCurrent->statusAnalysisVehicle.isExtremeBright == FALSE)

         /*skipping track, if the difference of track updates for current track (pTLCurrent) differs significantly from that
         of reference (pTLReference) track */
         /*&& (abs(pTLReference->track_time - pTLCurrent->track_time) < pParam->maxTrackTimeDiff)*/
       )
    {
      bIntensityTooDifferent = (boolean) ( (fabsf ( (float32) deltaMaxInt)  > (pParam->CoeffMaxInt * sumMaxInt))
                                           /* both lights are additionally bright enough. */
                                           && ( ( (float32) pTLReference->light_ref->MaxInt > minIntensity)
                                               || ( (float32) pTLCurrent->light_ref->MaxInt > minIntensity)
                                              )
                                         );

      diffSizeHeight = (uint16)abs(LightHeightCurrent - LightHeightReference);
      diffSizeWidth = (uint16)abs(LightWidthCurrent - LightWidthReference);

      bLightSizeInfoAvailableAndTooISDifferent = (boolean)(     ( diffSizeHeight > pParam->maxDiffSize) 
                                                             && ( LightHeightCurrent != 0) 
                                                             && ( LightHeightReference != 0)
                                                             /* when either light widths are not zero and differ significantly or ...*/
                                                             && ( diffSizeWidth > pParam->maxDiffSize)
                                                             && ( LightWidthCurrent != 0) 
                                                             && ( LightWidthReference != 0)
                                                          );

      /* additionally skipping current track when combinations of criteria apply: */
      /* distance in Y direction between the centers of the tracks is too big */
      if ( (abs (deltaY) > MaxDist_UpperLower_Y)
           /* OR */
           /* if there are associated lights with both tracks, skipping current track if these light differ significantly and are light enough */

           /* check light size - specific scenario red reflectors */
           /* when light heights are not zero, but differ significantly */
           || (bLightSizeInfoAvailableAndTooISDifferent == b_TRUE)
           /*... the difference between the light intensities is bigger
           then the sum of these intensities multiplied with special coefficient */
           || (bIntensityTooDifferent == b_TRUE)


         )
      {
        /*Do Nothing for tracks when they differ too much in their size or/and intensities. */
      }
      else
      {
        /*the node is eligible */
        result = b_TRUE;
      }
    }
  }

  return result;
}

/* finds best neighbor lights from both sides of provided track */
static  void HLAFindBestNeighborsOfTrack (
  HLAChainOfLightData_t* pCoLData,
  const HLA_t_ChainParam* pParam,
  const HLATrack_t* pTLReference,
  sint32 cntReference,
  HLATrack_t* pTrackListHead,
  uint8 numberOfTracks,

  float32 MaxDist2_UpperLower,
  sint16 MaxDist_UpperLower_X,
  sint16 MaxDist_UpperLower_Y,

  CandidateData_t* upper1,

  CandidateData_t* upper2,

  CandidateData_t* lower1,

  CandidateData_t* lower2
)
{

  uint8 cntCurrent;
  HLATrack_t* pTLCurrent;

  sint16 xImagePosCurrent;
  sint16 yImagePosCurrent;

  sint16 xImagePosReference = pTLReference->xcenter;
  sint16 yImagePosReference = pTLReference->ycenter;

  sint16 LightHeightReference;
  sint16 LightWidthReference;

  /* deltas */
  /* x coordinates delta */
  sint16 deltaX = 0;

  /* y coordinates delta */
  sint16 deltaY = 0;

  float32 length;

  boolean bCurIsAboveRef = b_FALSE;

  boolean bCurIsBelowRef = b_FALSE;

  boolean isPotentialChainNode;

  if ( (pTLReference->light_ref != NULL)
       && (pTLReference->light_ref->pRegion != NULL)
     )
  {
    LightHeightReference = (sint16) pTLReference->light_ref->pRegion->y2 - (sint16) pTLReference->light_ref->pRegion->y1;
    LightWidthReference = (sint16) pTLReference->light_ref->pRegion->x2 - (sint16) pTLReference->light_ref->pRegion->x1;
  }
  else
  {
    LightHeightReference = 0;
    LightWidthReference = 0;
  }

  /**********************************/
  /* inner for loop on track list */
  /**********************************/

  /* the goal of this loop is to find two tracks which are near and above
  and two tracks which are near and below of the reference track (pTLReference) */
  /* on each iteration incrementing cntCurrent and moving track pointer to the next element in the linked list */
  for (cntCurrent = 0, pTLCurrent = pTrackListHead; cntCurrent < numberOfTracks; cntCurrent++, pTLCurrent = pTLCurrent->next)
  {
    xImagePosCurrent = pTLCurrent->xcenter;
    yImagePosCurrent = pTLCurrent->ycenter;

    /****** Set the Up and Down Candidates ******/
    deltaX = (xImagePosReference - xImagePosCurrent);
    deltaY = (yImagePosReference - yImagePosCurrent);

    /* computing squared distance between two track centers */
    length = (float32) ( (deltaX * deltaX) + (deltaY * deltaY));

    isPotentialChainNode = HLADecideIsPotentialChainNode ( pTLReference, 
                                                           pTLCurrent, 
                                                           pParam, 
                                                           MaxDist2_UpperLower, 
                                                           MaxDist_UpperLower_X, 
                                                           MaxDist_UpperLower_Y, 
                                                           deltaX, 
                                                           deltaY,
                                                           length, 
                                                           LightHeightReference, 
                                                           LightWidthReference
                                                         );

    if (isPotentialChainNode == b_TRUE)
    {
      /* Find the best (nearest to the reference track pTLReference) two upper Nodes */

      bCurIsAboveRef = (boolean) (xImagePosCurrent > xImagePosReference);

      bCurIsBelowRef = (boolean) (xImagePosCurrent < xImagePosReference);
      /* **length is the distance between  pTLCurrent and pTLReference */

      /* if the distance between both tracks does not exceed the max distance threshold or distance is smaller then the current best known upper track  and
      current track (pTLCurrent) is above the reference Track (pTLReference) then */
      if ( (length < upper1->dist) && (bCurIsAboveRef == b_TRUE))
      {

        /***********/
        /* Set Up2 */
        /***********/

        /* copying current Up1 values (which describe some other upper track to reference track) in Up2 */
        *upper2 = *upper1;

        /***********/
        /* Set Up1 */
        /***********/

        /* setting the values of first upper track of the reference track (pTLReference) to the values of current track (pTLCurrent) */

        candidateSet (upper1, xImagePosCurrent, yImagePosCurrent, cntCurrent, length);

        /* debug */
        pCoLData->trackClusterList[cntReference].up1 = upper1->idx;
        pCoLData->trackClusterList[cntReference].up2 = upper2->idx;
      }
      /* if the distance between pTLCurrent and pTLReference is smaller then the maximal allowed distance or then the distance of the second known nearest upper track,
      then saving current track as the second known nearest upper track to the reference Track (pTLReference) */
      else if (    (length < upper2->dist) 
                && (bCurIsAboveRef == b_TRUE))
      {

        candidateSet (upper2, xImagePosCurrent, yImagePosCurrent, cntCurrent, length);

        /* Debug code */
        pCoLData->trackClusterList[cntReference].up2 = upper2->idx;
      }
      /* Find the best (nearest to the reference track pTLReference) two lower Nodes */
      /* same logic as above, but for tracks below the reference Track(pTLReference) */
      else if (    (length < lower1->dist) 
                && (bCurIsBelowRef == b_TRUE))
      {
        /* Set D2 */
        *lower2 = *lower1;

        /* Set D1 */

        candidateSet (lower1, xImagePosCurrent, yImagePosCurrent, cntCurrent, length);

        /* Debug Code */
        pCoLData->trackClusterList[cntReference].below1 = lower1->idx;
        pCoLData->trackClusterList[cntReference].below2 = lower2->idx;
      }
      else if (    (length < lower2->dist)  
                && (bCurIsBelowRef == b_TRUE))
      {
        candidateSet (lower2, xImagePosCurrent, yImagePosCurrent, cntCurrent, length);

        /* Debug Data */
        pCoLData->trackClusterList[cntReference].below2 = lower2->idx;
      }
      else
      {
        /* Do nothing when tracks differ to much in their distance between each other*/
      }
    }
  }

  /**************************************/
  /* End of INNER While loop on tracks **/
  /**************************************/
}

static void HLAChooseBestCandidate ( CandidateData_t*           pUpper,
                                     CandidateData_t*           pLower,
                                     const CandidateData_t*     pUpper1,
                                     const CandidateData_t*     pLower1,
                                     const CandidateData_t*     pUpper2, 
                                     const CandidateData_t*     pLower2,
                                     sint32*                    chosenAngle,
                                     float32                    MaxDist2_UpperLower,
                                     const sint16               xImagePosReference, 
                                     const sint16               yImagePosReference,
                                     boolean*                   bAngleBetweenSegmentsIsGood
                                    )
{

  ///* distances of a track to the lines through upper and lower neighboring tracks */
  //float32 DistUpper1Lower1, DistUpper1Lower2, DistUpper2Lower1, DistUpper2Lower2;

  /**********************************************************************/
  /* ***          Set DistU & DistLower & tCntUpper & tCntLower        *** */
  /**********************************************************************/
  /* upper1 -> lower1, upper1 -> lower2, upper2 -> lower1, upper2 -> lower2 */
  /*
                  o (upper2)
   (upper1)o     /
            \   /
             \ /
              o (pTLReference)
             / \
            /   \
  (lower1) o     \
                  o (lower2)
  */

  /* angles computed through two vectors build from the combinations of upper and lower points */
  sint32 angleU1L1 = neutralAngle;
  sint32 angleU1L2 = neutralAngle;
  sint32 angleU2L1 = neutralAngle;
  sint32 angleU2L2 = neutralAngle;
  
  /* Cross relations between upper and lower nodes and calculation of Distance of reference track (pTLReference) to the
  line between the chosen upper and lower node pair if the distances of the both ends are below MaxDist2_UD,
  what is the case when both ends where successfully found during the inner while loop */

  /*
   o (upper)
    \
     \
      \
  o----\
  Dist   \
         o (lower)
  */

  /* computing distance of the reference node to the line through centers of tracks up1 and down1 */
  if ( (pUpper1->dist < MaxDist2_UpperLower) && (pLower1->dist < MaxDist2_UpperLower))
  {
    angleU1L1 = HLAAnalysisChainSegmentDirectedAngle (pUpper1->x, pUpper1->y, xImagePosReference, yImagePosReference, pLower1->x, pLower1->y);
    angleU1L1 = abs(angleU1L1);
  }

  /* computing distance of the reference node to the line through centers of tracks up1 and down2 */
  if ( (pUpper1->dist < MaxDist2_UpperLower) && (pLower->dist < MaxDist2_UpperLower))
  {
    angleU1L2 = HLAAnalysisChainSegmentDirectedAngle (pUpper1->x, pUpper1->y, xImagePosReference, yImagePosReference, pLower2->x, pLower2->y);
    angleU1L2 = abs (angleU1L2);
  }

  /* computing distance of the reference node to the line through centers of tracks up2 and down1 */
  if ( (pUpper2->dist < MaxDist2_UpperLower) && (pLower1->dist < MaxDist2_UpperLower))
  {
    angleU2L1 = HLAAnalysisChainSegmentDirectedAngle (pUpper2->x, pUpper2->y, xImagePosReference, yImagePosReference, pLower1->x, pLower1->y);
    angleU2L1 = abs (angleU2L1);
  }

  /* computing distance of the reference node to the line through centers of tracks up2 and down2 */
  if ( (pUpper2->dist < MaxDist2_UpperLower) && (pLower2->dist < MaxDist2_UpperLower))
  {
    angleU2L2 = HLAAnalysisChainSegmentDirectedAngle (pUpper2->x, pUpper2->y, xImagePosReference, yImagePosReference, pLower2->x, pLower2->y);
    angleU2L2 = abs (angleU2L2);
  }

  /* takes first configuration of nodes which has a distance inferior to MaxDistToLine_UL */
  /* compromise between taking closest nodes or more aligned nodes */
  /* possible improvement: takes tCntUp, tCntDown, XUP, YUp, XDown, YDown for the configuration with the minimal distance */
  if (angleU1L1 < minimalSegmentAngle)
  {
    if (angleU1L2 < minimalSegmentAngle)
    {
      if (angleU2L1 < minimalSegmentAngle)
      {
        if (angleU2L2 < minimalSegmentAngle)
        {
          /* no good candidate found. only removing setting from previous runs */
          candidateReset (pLower);
          candidateReset (pUpper);
        }
        else
        {
          *pUpper = *pUpper2;
          *pLower = *pLower2;
          *chosenAngle = angleU2L2;
        }
      }
      else
      {
        *pUpper = *pUpper2;
        *pLower = *pLower1;
        *chosenAngle = angleU2L1;
      }
    }
    else
    {
      *pUpper = *pUpper1;
      *pLower = *pLower2;
      *chosenAngle = angleU1L2;
    }
  }
  else
  {
    *pUpper = *pUpper1;
    *pLower = *pLower1;
    *chosenAngle = angleU1L1;
  }

  /* maximal possible angle between candidate vectors */
  //*chosenAngle = CML_Max(CML_Max(CML_Max(angleU2L2, angleU2L1),angleU1L2),angleU1L1);

  if (*chosenAngle >= minimalSegmentAngle)
  {
    *bAngleBetweenSegmentsIsGood = b_TRUE;
  }
  else
  {
    *bAngleBetweenSegmentsIsGood = b_FALSE;
  }

#if 0

  /* Configuration with shortest distance */
  if (angleU1L1 == *chosenAngle)
  {
    *pUpper = *pUpper1;
    *pLower = *pLower1;
  }
  else if (angleU1L2 == *chosenAngle)
  {
    *pUpper = *pUpper1;
    *pLower = *pLower2;
  }
  else if (angleU2L1 == *chosenAngle)
  {
    *pUpper = *pUpper2;
    *pLower = *pLower1;
  }
  else if (angleU2L2 = *chosenAngle)
  {
    *pUpper = *pUpper2;
    *pLower = *pLower2;
  }
  else
  {
    candidateReset (pUpper);
    candidateReset (pLower);
  }

#endif
}

static void HLAConnectWithAlreadyFoundSegments ( const sint32                 MaxAngleTillNow,
                                                 const boolean                isPeriodic, 
                                                 const boolean                bAngleBetweenSegmentsIsGood,
                                                       HLAChainOfLightData_t* pCoLData, 
                                                 const sint32                 cntReference,
                                                 const CandidateData_t*       upper, 
                                                 const CandidateData_t*       lower,
                                                 const sint16                 xImagePosReference, 
                                                 const sint16                 yImagePosReference
                                               )
{
  /* Best possible angle between two vectors. In this case the two vectors have same angles*/
  static const sint32 bestAngle = 180;

  /* pointer to the track above the reference node */
  HLATrack_t* pTLUp = NULL;

  /* pointer to the track above the node which is above the reference node */
  HLATrack_t* pTUpUp = NULL;

  /* pointer to the track below reference node */
  HLATrack_t* pTLBelow = NULL;

  /*pointer to the track below the node which is below the reference node */
  HLATrack_t* pTBelowBelow = NULL;

  sint16 Xdd;
  sint16 Ydd;

  sint16 Xuu;
  sint16 Yuu;

  /* distance (d) of the node above the reference node (Up) to the line through the reference node (Reference Node) and the node above the node which is above the reference node (UpUp Node)
    (UpUp Node)
         °
         |
         |
  (Up Node)->°  angle
          \
           \
            °
            (Reference Node)
  */

  /* angle between two vectors through Reference Upper and Upper and UUpper Node*/
  sint32 angleRefUpperUUpper;

  /* distance (d) of the node above the reference node (Up) to the line through the reference node (Reference Node) and the node above the node which is above the reference node (UpUp Node)
       (Reference Node)
             °
             |
             |
  (Lower Node)-->° angle
              \
               \
                °
                (LLower Node)
  */

  /* angle between two vectors through Reference Lower and Lower and LLower Node*/
  sint32 angleRefLowerLLower;


  /**********************************************************************/
  /* ***          Set trackClusterList        *** */
  /**********************************************************************/
  /* if distances between reference node and upper node , reference node and lower node are periodic,
  and the distance from the reference node to the line through the upper and lower node is not too large */
  if (    (isPeriodic == b_TRUE)
       && (bAngleBetweenSegmentsIsGood == b_TRUE)
     )
  {

    /*
    Here is checked that there are no sharp angles in the chain (node connected with lower node, lower node, reference node , upper node, node connected with upper node ).

    In the case when the angle gets bigger then the current existing connection either with lower or upper node,
    what means that the linearity increases, the already setup connection to the upper node
    is removed and a link to the new upper node is considered */
    if (
      /* the reference track has still no association with upper track */
      ( (pCoLData->trackClusterList[cntReference].tCntUp == 0)
        /* or if there is an associated another upper track, which has the reference track as its lower node*/
        || ( (pCoLData->trackClusterList[
                /* getting the list position of the upper track associated with current track */
                pCoLData->trackClusterList[cntReference].tCntUp - 1
                /* this means that the lower node with upper track points to the reference track */
              ].tCntBelow) == (cntReference + 1))


        /* or if different connection exists, but has smaller angle, then it is replaced with current candidate*/
        || (MaxAngleTillNow > (pCoLData->trackClusterList[pCoLData->trackClusterList[cntReference].tCntUp - 1].angleUL))
      )
      /* Allowed to set  Down? */

      /* the reference track has still no association with lower track */
      && ( (pCoLData->trackClusterList[cntReference].tCntBelow == 0)
           /* or if there is an associated lower track, it has the reference track as its upper node*/
           || ( (pCoLData->trackClusterList[pCoLData->trackClusterList[cntReference].tCntBelow - 1].tCntUp) == (cntReference + 1))

           /* or if the connection exists, but is again not good enough (same considerations as in the case above) */
           || (MaxAngleTillNow > (pCoLData->trackClusterList[pCoLData->trackClusterList[cntReference].tCntBelow - 1].angleUL))
         )
    )
    {
      /* Relink nodes */
      /* Remove links of Nodes that are already connected in another way */
      /*
      --->
      o <-\- o

      */

      if (pCoLData->trackClusterList[cntReference].tCntUp != 0)
      {
        /* removing connection from already stored Up -> below */
        pCoLData->trackClusterList[pCoLData->trackClusterList[cntReference].tCntUp - 1].tCntBelow = 0;
      }

      if (pCoLData->trackClusterList[upper->idx].tCntBelow != 0)
      {
        /* removing connection from already stored upper->below->upper track */
        pCoLData->trackClusterList[pCoLData->trackClusterList[upper->idx].tCntBelow - 1].tCntUp = 0;
      }

      if (pCoLData->trackClusterList[cntReference].tCntBelow != 0)
      {
        /* removing already stored connection referenceTrack.BelowTrack->Upper */
        pCoLData->trackClusterList[pCoLData->trackClusterList[cntReference].tCntBelow - 1].tCntUp = 0;
      }

      if (pCoLData->trackClusterList[lower->idx].tCntUp != 0)
      {
        /* removing already stored connection lower->up -> up */
        pCoLData->trackClusterList[pCoLData->trackClusterList[lower->idx].tCntUp - 1].tCntUp = 0;
      }

      /* Logic to set up new links */
      /* Set Up */

      /* if new upper track was found set then storing the data of node above upper track */
      if (pCoLData->trackClusterList[upper->idx].tCntUp != 0)
      {
        /* getting pointer to the track above the upper track */
        pTUpUp = pCoLData->trackClusterList[pCoLData->trackClusterList[upper->idx].tCntUp - 1].pT;
        /* getting the upper track */
        pTLUp = pCoLData->trackClusterList[upper->idx].pT;

        /* getting x and y position of the track above upper track */
        Xuu = pTUpUp->xcenter;
        Yuu = pTUpUp->ycenter;

        /* Computing the distance between the upper track and the line through reference track and the upper upper track */
        /*HLADistLine (&Distuu, pTLUp->xcenter, pTLUp->ycenter, xImagePosReference, yImagePosReference, Xuu, Yuu);*/

        /* computing the angle through the vectors Ref-Upper and Upper-UpperUpper */
        angleRefUpperUUpper = HLAAnalysisChainSegmentDirectedAngle (xImagePosReference, yImagePosReference,
                                   pTLUp->xcenter, pTLUp->ycenter,  Xuu, Yuu);
        angleRefUpperUUpper = abs (angleRefUpperUUpper);
      }
      else
      {
        //Distuu = 0;
        angleRefUpperUUpper = bestAngle;
      }

      /* if the angle is also OK, then setting the link from reference node to upper and lower track */
      if (angleRefUpperUUpper > minimalSegmentAngle)
      {
        /* Set Up Link */
        pCoLData->trackClusterList[cntReference].tCntUp = upper->idx + 1;
        pCoLData->trackClusterList[upper->idx].tCntBelow = (uint8) cntReference + 1;
        pCoLData->trackClusterList[cntReference].angleUL = MaxAngleTillNow;
      }
      /* in other case removing already existing connection */
      else
      {
        pCoLData->trackClusterList[upper->idx].tCntUp = 0;
        pCoLData->trackClusterList[upper->idx].tCntBelow = 0;
      }

      /* Set Down */
      /* steps like above */
      if (pCoLData->trackClusterList[lower->idx].tCntBelow != 0)
      {
        pTBelowBelow = pCoLData->trackClusterList[pCoLData->trackClusterList[lower->idx].tCntBelow - 1].pT;
        pTLBelow = pCoLData->trackClusterList[lower->idx].pT;
        Xdd = pTBelowBelow->xcenter;
        Ydd = pTBelowBelow->ycenter;

        angleRefLowerLLower = HLAAnalysisChainSegmentDirectedAngle (xImagePosReference, yImagePosReference, pTLBelow->xcenter, pTLBelow->ycenter, Xdd, Ydd);
        angleRefLowerLLower = abs (angleRefLowerLLower);
      }
      else
      {
        //Distbb = 0;
        angleRefLowerLLower = bestAngle;
      }

      if (angleRefLowerLLower > minimalSegmentAngle)
      {
        /* Set Down Link */
        pCoLData->trackClusterList[cntReference].tCntBelow = lower->idx + 1;
        pCoLData->trackClusterList[lower->idx].tCntUp = (uint8) cntReference + 1;
        pCoLData->trackClusterList[lower->idx].angleUL = MaxAngleTillNow;
      }
      else
      {
        pCoLData->trackClusterList[lower->idx].tCntUp = 0;
        pCoLData->trackClusterList[lower->idx].tCntBelow = 0;
      }
    }
  }
}

/**********************************************************************/
/* ***          Check Periodicity        *** */
/**********************************************************************/
/* It was observed, that a chain of reflectors produces a chain of lights with similar distances between the single lights of the chain */
/* It was additionally observed, that the distances from one end of the chain to the other are constantly increasing of decreasing */

/* In current implementation only similar distance between nodes is examined for a chain segment consisting of lower node, reference node and upper node: */
/*
*           UpperNode
*               \
*             ReferenceNode
*                 \
*                 LowerNode
*/
static  boolean HLACheckIsPeriodic ( const CandidateData_t*  pUpper,
                                     const CandidateData_t*  pLower,
                                     const sint16            xImagePosReference,
                                     const sint16            yImagePosReference,
                                     const HLA_t_ChainParam* pParam
                                    )
{
  boolean isPeriodic = b_FALSE;

  /* these variables save difference in x and y direction between the upper, lower and reference node*/
  sint32 delta_xUpper, delta_xLower, delta_yUpper, delta_yLower;

  float32 length_prev, length;

  if ( (pUpper->idx != 0) && (pLower->idx != 0))
  {

    /* computing x delta of reference node center with upper node center */
    delta_xUpper = (xImagePosReference - pUpper->x);

    /* computing x delta of reference node center with lower node center */
    delta_xLower = (pLower->x - xImagePosReference);

    /* computing y delta of reference node center with upper node center */
    delta_yUpper = (yImagePosReference - pUpper->y);

    /* computing y delta of reference node  center with lower node center */
    delta_yLower = (pLower->y - yImagePosReference);

    /* computing distance from reference node to lower node */
    length_prev = (float32) (delta_xLower * delta_xLower) + (delta_yLower * delta_yLower);

    /* computing distance from reference node to upper node */
    length = (float32) (delta_xUpper * delta_xUpper) + (delta_yUpper * delta_yUpper);

    if ( (length_prev < (pParam->MaxDistRatio * length)) && (length < (pParam->MaxDistRatio * length_prev)))
    {
      isPeriodic = b_TRUE;
    }
  }

  return isPeriodic;
}

static  void HLAFindChainSegments (HLATrack_t* pTrackListHead,  HLAChainOfLightData_t* pCoLData, float32 aParamLine, float32 bParamLine, const HLA_t_ChainParam* pParam)
{
  uint8 numberOfTracks = pCoLData->numberOfTracks;

  /* points to actual reference track */
  HLATrack_t* pTLReference;

  /* helper variables used to save distance computation results between tracks and a track and FOE-Line */
  float32 length;

  /* temporal candidates for neighbors tracks */
  CandidateData_t lower1, lower2;
  CandidateData_t upper1, upper2;

  /* final chosen neighbor tracks, which will become part of chain*/
  CandidateData_t upper, lower;

  /* saves center position of reference track pTLReference */
  sint16 xImagePosReference, yImagePosReference;

  /* maximal allowed difference between two tracks to be considered as neighbors */
  sint16 MaxDist_UpperLower_X, MaxDist_UpperLower_Y;

  /* variable for maximal distance from the reference track center to Upper or lower Track center in the chain */
  float32 MaxDist2_UpperLower;

  /* variable saves the biggest angle between two possible vectors */
  sint32 MaxAngleTillNow;

  /* helper counter variables used in while loop to track current positions in the list of tracks */
  sint32 cntReference;

  /* booleans */
  boolean bAngleBetweenSegmentsIsGood = b_FALSE;

  boolean isPeriodic = b_FALSE;


  /********************************/
  /* Outer for loop on track list */
  /********************************/
  for (cntReference = 0, pTLReference = pTrackListHead; cntReference < numberOfTracks; cntReference++, pTLReference = pTLReference->next)
  {
    /* saving x and y coordinate of a track center into local variable*/
    /* is this needed? all access is read only. in both cases the data is on the stack */
    xImagePosReference = pTLReference->xcenter;
    yImagePosReference = pTLReference->ycenter;

    candidateReset (&upper1);

    candidateReset (&upper2);

    candidateReset (&lower1);

    candidateReset (&lower2);

    /*************************************/
    /* Computing distance to the horizon */
    /*************************************/
    /* if *length is positive, then the point (xb,yb) is below the horizon line,
    if it is negative, then the point (xb, yb ) is above the horizon line */
    length = ( (float32) yImagePosReference - ( (aParamLine * (float32) xImagePosReference) + bParamLine));

    /* Set distances according to distance to FOE line */

    /* *length is bigger then threshold, the point is far below foe line and is in the
    ROI Area called UnderHorizon-ROI */
    if ( ( (sint16) length > pParam->MinDistUnderHor)
       )
    {
      MaxDist2_UpperLower = pParam->MaxDist2_FarHor; /* max *length between the two nodes which can still belong to a chain of light */
      MaxDist_UpperLower_X = pParam->MinDist_X_FarHor; /* Search box size */
      MaxDist_UpperLower_Y = pParam->MinDist_Y_FarHor; /* Search box size */
    }
    /* *length is positive but not big. the point is below and near FOE-line. This ROI-Area
    is called Horizon-ROI*/
    else if ( (sint16) length > pParam->MinDistAboveHor)
    {
      MaxDist2_UpperLower = pParam->MaxDist2_CloseHor;
      MaxDist_UpperLower_X = pParam->MinDist_X_CloseHor;
      MaxDist_UpperLower_Y = pParam->MinDist_Y_CloseHor;
    }
    /* *length is negative, point is above the FOE-Line. This ROI-Area is called above-horizon-ROI */
    else
    {
      MaxDist2_UpperLower = pParam->MaxDist2_FarHor;
      MaxDist_UpperLower_X = pParam->MinDist_X_FarHor;
      MaxDist_UpperLower_Y = pParam->MinDist_Y_FarHor;
    }

    /* Up Part */
    upper1.dist = MaxDist2_UpperLower;
    lower2.dist = MaxDist2_UpperLower;

    /* Down Part */
    lower1.dist = MaxDist2_UpperLower;
    upper2.dist = MaxDist2_UpperLower;

    /*if (pTLReference->lost_time == 0)*/
    if (    (pTLReference->light_ref != NULL)
         && (pTLReference->statusAnalysisMisc.isFarAboveHorizon == FALSE)
       /*&& (pTLReference->anaResStat.isLateralBright.result == HLA_RESULT_NEGATIVE)*/
         && (pTLReference->statusAnalysisVehicle.isExtremeBright == FALSE)
     )
    {

      HLAFindBestNeighborsOfTrack (pCoLData, pParam, pTLReference, cntReference,
                                   pTrackListHead, numberOfTracks, MaxDist2_UpperLower, MaxDist_UpperLower_X,
                                   MaxDist_UpperLower_Y, &upper1, &upper2, &lower1, &lower2);

      HLAChooseBestCandidate (&upper, &lower, &upper1, &lower1, &upper2, &lower2,
                              &MaxAngleTillNow, MaxDist2_UpperLower,
                              xImagePosReference, yImagePosReference, &bAngleBetweenSegmentsIsGood);

      isPeriodic = HLACheckIsPeriodic (&upper, &lower, xImagePosReference, yImagePosReference, pParam);

      HLAConnectWithAlreadyFoundSegments (MaxAngleTillNow, isPeriodic, bAngleBetweenSegmentsIsGood, pCoLData, cntReference, &upper, &lower, xImagePosReference,
                                          yImagePosReference);
    }
  }
}

static  uint8 HLAMarkChains (HLAChainOfLightData_t* pCoLData)
{
  /**********************************************************************/
  /* ***            Build chain list        *** */
  /**********************************************************************/
  uint8 chainCount = 0;

  HLATrack_t* chainNode;

  HLATrack_t* nextChainNode;

  uint8 numberOfTracks = pCoLData->numberOfTracks;

  uint8 i;

  uint8 tCntUpper, tCntLower, tCntNxt, tCntPrev, tCntNxtofNxt, tracksInChain;

  for (i = 0; i < numberOfTracks; i++)
  {
    chainNode = pCoLData->trackClusterList[i].pT;
    tCntUpper = pCoLData->trackClusterList[i].tCntUp;
    tCntLower = pCoLData->trackClusterList[i].tCntBelow;

    tCntNxt = tCntUpper;
    tCntPrev = tCntLower;

    if (tCntPrev != 0)
    {
      tCntNxtofNxt = pCoLData->trackClusterList[tCntPrev - 1].tCntUp;
    }
    else
    {
      tCntNxtofNxt = 0;
    }

    if (    (    (tCntPrev == 0) /* Actual node is not previously connected || there's a down link, but no up link, means actual node is first in line */
              || (tCntNxtofNxt != (i + 1))
            )    
         && (tCntNxt != 0)  /* There is an up link */
         && (chainCount < NB_OF_CHAINS)
       )
    {
      tracksInChain = 0;

      /* add current track to current chain */
      pCoLData->clusterTrackList[chainCount][tracksInChain] = chainNode;
      tracksInChain++;

      nextChainNode = pCoLData->trackClusterList[tCntNxt - 1].pT;

      tCntNxt = pCoLData->trackClusterList[tCntNxt - 1].tCntUp;

      chainNode = nextChainNode;

      /* follow chain to end... */
      while ( (chainNode != NULL) && (tracksInChain < MAX_LENGTH_CHAIN))
      {
        /* add current track to current chain */
        pCoLData->clusterTrackList[chainCount][tracksInChain] = chainNode;
        tracksInChain++;

        /* get next chain node */
        if ( (tCntNxt != 0))
        {
          nextChainNode = pCoLData->trackClusterList[tCntNxt - 1].pT;

          tCntNxt = pCoLData->trackClusterList[tCntNxt - 1].tCntUp;

          chainNode = nextChainNode;

        }
        else
        {
          chainNode = NULL;
        }
      }

      /* update chain count */
      chainCount++;
    }
  }

  return chainCount;
}

static  void HLAMarkChainOfLightTracks (const HLAChainOfLightData_t* pCoLData, const HLA_t_ChainParam* pParam)
{
  uint8 chainIdx;
  uint8 chainElementIdx;
  uint8 nodesInChain;
  HLATrack_t* chainNode;
  HLATrack_t* nextChainNode;
  uint8 chainCount = pCoLData->chaincounter;

  /* go through chain list and mark nodes of chains as chainOfLight, when the chain is long enough*/
  for (chainIdx = 0; chainIdx < chainCount; chainIdx++)
  {
    nextChainNode = pCoLData->clusterTrackList[chainIdx][0];
    chainElementIdx = 0;

    while (nextChainNode != NULL)
    {
      chainElementIdx++;
      nextChainNode = pCoLData->clusterTrackList[chainIdx][chainElementIdx];
    }

    if (chainElementIdx > pParam->minNbOfTrackInChain)
    {
      nodesInChain = chainElementIdx;

      /* display chain */
      chainElementIdx = 0;
      nextChainNode = pCoLData->clusterTrackList[chainIdx][0];

      while (nextChainNode != NULL)
      {
        chainNode = nextChainNode;

        chainElementIdx++;
        nextChainNode = pCoLData->clusterTrackList[chainIdx][chainElementIdx];

        chainNode->statusAnalysisMisc.isChainOfLight = 1;
        chainNode->lengthChainOfLight = nodesInChain;
      }
    }
  }
}

/**********************************************************************/
/* ***         Set  idResStat.isChainOfLights, this is used as input for the classifier          *** *****/
/* when chainNode->statusAnalysisMisc.isChainOfLight == 1, increase confidence for the current track, ****/
/* in other case it is decreased. increase and decrease steps are fixed constants ************************/
/* HLA_RESULT_POSITIVE is set when the track confidence is bigger then some fixed threshold **************/
/* HLA_RESULT_NEGATIVE is set when the track confidence is smaller then some other fixed threshold *******/
/* this confidence data is later used as additional feature of the classifier                            */
/*********************************************************************************************************/
static  void HLAComputeCoLConfidence (HLATrack_t* pTrackListHead, const HLA_t_ChainParam* pParam)
{
  HLATrack_t* pTLReference = pTrackListHead;

  while (pTLReference != NULL)
  {
    /* Update Confidence */
    if (pTLReference->statusAnalysisMisc.isChainOfLight == TRUE)
    {
      pTLReference->idResStat.isChainOfLights.confidence = CML_Min (pParam->Conf_max, pTLReference->idResStat.isChainOfLights.confidence + pParam->Conf_stepPos);
    }
    else
    {
      pTLReference->idResStat.isChainOfLights.confidence = CML_Max (pParam->Conf_min, pTLReference->idResStat.isChainOfLights.confidence - pParam->Conf_stepNeg);
    }

    /* Set Result */
    if (pTLReference->idResStat.isChainOfLights.confidence > pParam->Conf_threshPos)
    {
      pTLReference->idResStat.isChainOfLights.result = HLA_RESULT_POSITIVE;
    }
    else if (pTLReference->idResStat.isChainOfLights.confidence < pParam->Conf_threshNeg)
    {
      pTLReference->idResStat.isChainOfLights.result = HLA_RESULT_NEGATIVE;
    }
    else
    {
      pTLReference->idResStat.isChainOfLights.result = HLA_RESULT_IDLE;
    }

    pTLReference = pTLReference->next;
  }
}

void HLAAnalysisChain (HLATrack_t* pTrackListHead, const HLACamRot* pcamRot, const HLA_t_ChainParam* pParam, HLAChainOfLightData_t* pCoLData)
{
  /* 32 Bits */
  float32 xFOE_L, yFOE_L, xFOE_R, yFOE_R;

  /* these variables are used to store line coefficients which is every time fitted to the pair of track centers*/
  /* the line is of the form aLineParameter * x + bLineParameter = y */
  float32 aParamLine, bParamLine;

  static const float32 farFrontLeftX = 5000.0f;
  static const float32 farFrontLeftY = 500.0f;
  static const float32 farFrontLeftZ = 0.f;

  static const float32 farFrontRightX = 5000.0f;
  static const float32 farFrontRightY = -500.0f;
  static const float32 farFrontRightZ = 0.f;

  /* Initialize */
  pCoLData->numberOfTracks = HLAInitializeData (pTrackListHead, pCoLData);

  /* go through all list entries */

  /* get simple focus of expansion */

  /**************************************************/
  /******Focus of Expansion at far front left********/
  /**************************************************/

  /* getting x and y image coordinate of a focus of expansion from its World coordinates using Camera Matrix */
  HLACamRotGetXb (pcamRot, &xFOE_L, &yFOE_L , farFrontLeftX, farFrontLeftY, farFrontLeftZ);

  /***********************************************/
  /******Focus of Expansion at far front right****/
  /***********************************************/

  /* getting x and y image coordinate of a focus of expansion from its World coordinates using Camera Matrix*/
  HLACamRotGetXb (pcamRot, &xFOE_R, &yFOE_R , farFrontRightX, farFrontRightY, farFrontRightZ);

  /**********************************************************************/
  /* determining horizon line parameters which goes through the *********/
  /* image coordinates of the left and right focus of expansion points **/
  /**********************************************************************/
  HLAParLine (&aParamLine, &bParamLine, (sint16) xFOE_L, (sint16) yFOE_L, (sint16) xFOE_R, (sint16) yFOE_R);

  HLAFindChainSegments (pTrackListHead, pCoLData, aParamLine, bParamLine, pParam);

  pCoLData->chaincounter = HLAMarkChains (pCoLData);

  HLAMarkChainOfLightTracks (pCoLData, pParam);

  HLAComputeCoLConfidence (pTrackListHead, pParam);
}
/* ****************************************************************************
  Functionname:     HLAParLine()                             */ /*!
  Description:      Derive the parameters (A,B) of the equation y = A * x + B
                    of the straight line going through (xa,ya) and (xb,yb)

  @param[in]        -

  @return           -
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
static  void HLAParLine (float32* A, float32* B, sint16 xa, sint16 ya, sint16 xb, sint16 yb)
{
  float32 a, b;

  if (xa != xb)
  {
    /* computing gradient */
    a = ( (float32) ya - (float32) yb) / ( (float32) xa - (float32) xb);
  }
  else
  {
    /* handling prevention of division by zero. in this case just approximating the solution for a.
    it should actually be equal to infinity in such a case */
    a = ( (float32) ya - (float32) yb);
  }

  /* finding factor b. the equation y = a * x + b can be transformed to b = y - a*x */
  b = ( (float32) ya - (a * (float32) xa));

  *A = a;
  *B = b;
}/* PRQA S 861 1 */
