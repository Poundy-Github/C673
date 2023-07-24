/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_brightobjects.c

  DESCRIPTION:            Detection of bright objects which could blind the driver (headlamp dimming candidates)

  AUTHOR:                 Stefan Zechner

  CREATION DATE:          2011-11-07

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_brightobjects.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:56CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:34CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:27CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.18 2014/03/25 18:36:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_brightobjects.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_brightobjects.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/environment/project.pj.
  CHANGE:                 Revision 1.17 2014/03/19 16:30:55CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:55 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.16 2014/03/10 13:20:53CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:20:54 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.15 2014/03/10 13:05:24CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - changed DimmingAreas to match the specs of BMW
  CHANGE:                  - implemented visualization
  CHANGE:                 --- Added comments ---  uidv8777 [Mar 10, 2014 1:05:25 PM CET]
  CHANGE:                 Change Package : 224162:1 http://mks-psad:7002/im/viewissue?selection=224162
  CHANGE:                 Revision 1.14 2014/03/03 16:51:35CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Support for R2.1 interface
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 3, 2014 4:51:36 PM CET]
  CHANGE:                 Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.13 2014/01/31 09:46:21CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some QAC critical warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 31, 2014 9:46:21 AM CET]
  CHANGE:                 Change Package : 193435:7 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.12 2014/01/05 22:51:25CET Glebov, Roman (uidg4759) 
  CHANGE:                 QAC: implicite conversion from int to unsigned int and vise versa removed
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 5, 2014 10:51:25 PM CET]
  CHANGE:                 Change Package : 193435:2 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.11 2013/12/05 17:47:55CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Update to RTE I330
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 5, 2013 5:47:55 PM CET]
  CHANGE:                 Change Package : 207432:13 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.10 2013/11/21 17:53:14CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:14 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.9.1.2 2013/10/21 10:18:28CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - merged HLASegLInePos_t and HLASegLineLevelRef_t to HLASegLine_t
  CHANGE:                 - removed bit field for line position
  CHANGE:                 - moved  level index from line to region
  CHANGE:                 --- Added comments ---  brunnm [Oct 21, 2013 10:18:28 AM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.9.1.1 2013/10/18 13:27:34CEST Brunn, Marcus (brunnm) 
  CHANGE:                 intial version of new segmentation
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:27:34 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.9 2012/10/18 17:55:44CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - allocation of array memory by array macro in order to realize a dedicated array boundary check mode
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 18, 2012 5:55:45 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.8 2012/10/10 13:02:47CEST Brunn, Marcus (brunnm) 
  CHANGE:                 RAM optimization (Part2)
  CHANGE:                 --- Added comments ---  brunnm [Oct 10, 2012 1:02:48 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.7 2012/10/05 12:44:44CEST Brunn, Marcus (brunnm) 
  CHANGE:                 RAM optimization (part1)
  CHANGE:                 --- Added comments ---  brunnm [Oct 5, 2012 12:44:44 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.6 2012/04/02 16:52:40CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - added comments from code review
  CHANGE:                 --- Added comments ---  uidt9253 [Apr 2, 2012 4:52:40 PM CEST]
  CHANGE:                 Change Package : 94867:1 http://mks-psad:7002/im/viewissue?selection=94867
  CHANGE:                 Revision 1.5 2011/11/16 18:42:34CET Zechner, Stefan (uidt9253) 
  CHANGE:                 - don't initialize pointer array in order to save flash memory
  CHANGE:                 --- Added comments ---  uidt9253 [Nov 16, 2011 6:42:34 PM CET]
  CHANGE:                 Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGE:                 Revision 1.4 2011/11/14 19:57:05CET Zechner Stefan (uidt9253) (uidt9253) 
  CHANGE:                 - street lamps and vehicles should not become bright objects
  CHANGE:                 --- Added comments ---  uidt9253 [Nov 14, 2011 7:57:05 PM CET]
  CHANGE:                 Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGE:                 Revision 1.3 2011/11/14 17:04:22CET Zechner Stefan (uidt9253) (uidt9253) 
  CHANGE:                 - consider isAboveROI and the maxima
  CHANGE:                 --- Added comments ---  uidt9253 [Nov 14, 2011 5:04:22 PM CET]
  CHANGE:                 Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGE:                 Revision 1.2 2011/11/12 19:16:46CET Zechner Stefan (uidt9253) (uidt9253) 
  CHANGE:                 - new brightness threshold
  CHANGE:                 --- Added comments ---  uidt9253 [Nov 12, 2011 7:16:46 PM CET]
  CHANGE:                 Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGE:                 Revision 1.1 2011/11/07 18:42:39CET Zechner Stefan (uidt9253) (uidt9253) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

/* ~CodeReview ~ID:b0ce86d9b37ba7905f8a580f04f01caa ~Reviewer:CW01\uidt9253 ~Date:4/2/2012 ~Priority:3 ~Comment:convert magic numbers to function parameters */


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "hla_brightobjects.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/
#define BRIGHT_OBJECTS_NUM_VEHICLE_REGION 20u

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
void HLABrightObjects(      HLATrack_t*   pTrackStart,
                      const HLASegOut_t*  pSegOut
                     )
{
  const HLASegLineRegion_t* vehicleRegionList[BRIGHT_OBJECTS_NUM_VEHICLE_REGION];
  uint16 vehicleRegionListLength = 0;
  HLATrack_t* pTrack;

  /* create a list of regions of the vehicles */
  pTrack = pTrackStart;
  while(pTrack != NULL)
  {
    if(   (pTrack->statusAnalysisVehicle.isVehicleAhead == 1)
       || (pTrack->statusAnalysisVehicle.isVehicleOncoming == 1)
      )
    {
      if(   (pTrack->light_ref != NULL)
         && (pTrack->light_ref->pRegion != NULL)
        )
      {
        const HLASegLineRegion_t* pRegion = pTrack->light_ref->pRegion;
        while(pRegion->pRegionBelow != NULL)
        {
          pRegion = pRegion->pRegionBelow;
        }

        if(vehicleRegionListLength < BRIGHT_OBJECTS_NUM_VEHICLE_REGION)
        {
          vehicleRegionList[vehicleRegionListLength] = pRegion;
          vehicleRegionListLength++;
        }
        else
        {
          break;
        }
      }
    }

    pTrack = pTrack->next;
  }

  /* calc luminous flux and set the bright object flag */
  pTrack = pTrackStart;
  while(pTrack != NULL)
  {
    uint32 areaLast = 0;
    float32 luminousFlux = 0.0f;

    if (   (pTrack->statusAnalysisMisc.isAboveROI == 0) 
        && (pTrack->idResStat.isStreetLamp.result != HLA_RESULT_POSITIVE) 
        && (pTrack->statusAnalysisVehicle.isVehicleAhead == 0) 
        && (pTrack->statusAnalysisVehicle.isVehicleOncoming == 0) 
        && (pTrack->light_ref != NULL))
    {
      const HLASegLineRegion_t* pRegion = pTrack->light_ref->pRegion;
      while(   (pRegion != NULL)
            && (pRegion->iLine < HLA_SEG_MAX_NUM_SEG_LINES)
           )
      {
        const uint32 area = (pRegion->x2 - pRegion->x1) * (pRegion->y2 - pRegion->y1);
        /* uint8 is always >= 0 */
        uint8 iLevel = CML_Min(RTE_HLA_SEG_MAX_NUM_LEVELS-1u, (uint8) pRegion->Level);

        if(iLevel == 0)
        {
          break;
        }
        else
        {
          luminousFlux += pSegOut->RegionLevel.f32_Level[iLevel] * (area - areaLast);
        }
        
        areaLast = area;
        pRegion = pRegion->pRegionBelow;
      }

      {
        const HLASegNgb_t* ngb = &pTrack->light_ref->Maxima.ngb[0];

        luminousFlux += ngb[NGB_0].lux +
                        ngb[NGB_1].lux +
                        ngb[NGB_2].lux +
                        ngb[NGB_3].lux +
                        ngb[NGB_4].lux +
                        ngb[NGB_5].lux +
                        ngb[NGB_6].lux +
                        ngb[NGB_7].lux +
                        ngb[NGB_8].lux +
                        ngb[NGB_9].lux +
                        ngb[NGB_10].lux +
                        ngb[NGB_11].lux +
                        ngb[NGB_12].lux;
      }
    }

#ifdef PC_SIM
    pTrack->LuminousFlux = luminousFlux;
#endif

    pTrack->statusAnalysisMisc.isBrightObject = 0;
    if (luminousFlux > 80000)
    {
      boolean trackCloseToVehicle = b_FALSE;
      uint16 i;
      for(i = 0; i < vehicleRegionListLength; i++)
      {
        /* J.Häfer: Misra Rule 9.1 unset variabel isn't possible, vehicleRegionListLength would be zero */
        /* PRQA S 3353 1 */
        const HLASegLineRegion_t* pRegion = vehicleRegionList[i];
        if (   (pTrack->xcenter >= pRegion->x1)
            && (pTrack->xcenter <= pRegion->x2)
            && (pTrack->ycenter >= pRegion->y1)
            && (pTrack->ycenter <= pRegion->y2)
           )
        {
          trackCloseToVehicle = b_TRUE;
          break;
        }
      }
      if (trackCloseToVehicle == b_FALSE)
      {
        pTrack->statusAnalysisMisc.isBrightObject = 1;
      }
    }

    pTrack = pTrack->next;
  }
}
