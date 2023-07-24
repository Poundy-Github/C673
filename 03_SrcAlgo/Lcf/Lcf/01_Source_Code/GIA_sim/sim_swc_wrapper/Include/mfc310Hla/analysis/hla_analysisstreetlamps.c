/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysisstreetlamps.c

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Boris Lugez

  CREATION DATE:          2011-05-24

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_analysisstreetlamps.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:44CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:00CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:17CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/analysis/project.pj
  CHANGE:                 Revision 1.31 2014/03/28 10:36:03CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 28, 2014 10:36:03 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.30 2014/03/26 11:27:47CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:47 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.29 2014/03/25 18:32:13CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_analysisstreetlamps.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_analysisstreetlamps.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/analysis/project.pj.
  CHANGE:                 Revision 1.28 2014/03/21 09:38:39CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some QAC warnings (parenthesis)
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 21, 2014 9:38:40 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.27 2014/03/19 16:31:45CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:46 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.26 2014/03/10 13:21:10CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:21:11 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.25 2014/03/04 16:51:51CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:51:51 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.24 2014/01/10 18:34:04CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:34:04 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.23 2013/11/21 17:53:53CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:53 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.22.1.1 2013/10/18 13:27:33CEST Brunn, Marcus (brunnm) 
  CHANGE:                 intial version of new segmentation
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:27:33 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.22 2013/03/04 11:15:09CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Integrated cam_rot into HLA
  CHANGE:                 bug fix in jacobian calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2013 11:15:09 AM CET]
  CHANGE:                 Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.21 2012/11/15 09:56:25CET Brunn, Marcus (brunnm) 
  CHANGE:                 interface update for MFC4B0, BMW I210 (without RTE)
  CHANGE:                 --- Added comments ---  brunnm [Nov 15, 2012 9:56:25 AM CET]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.20 2012/08/22 18:23:11CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - cleanup and tuning the street lamp analysis (avoid blindings by increasing min street lamp height and reduced deltaConf for the 2d_idle + 3d_ok case from 2 to 1
  CHANGE:                 --- Added comments ---  uidt9253 [Aug 22, 2012 6:23:11 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.19 2012/08/07 16:15:59CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - tuning the isStaticHigh and isStreetLamp suppression
  CHANGE:                 --- Added comments ---  uidt9253 [Aug 7, 2012 4:16:00 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.18 2012/03/22 10:28:14CET Lugez, Boris (uidt2765) 
  CHANGE:                 -> Code review findings
  CHANGE:                 --- Added comments ---  uidt2765 [Mar 22, 2012 10:28:14 AM CET]
  CHANGE:                 Change Package : 103574:1 http://mks-psad:7002/im/viewissue?selection=103574
  CHANGE:                 Revision 1.17 2011/10/17 14:43:35CEST Godreau, Bertrand (uid28828) 
  CHANGE:                 Rework of pairing
  CHANGE:                 --- Added comments ---  uid28828 [Oct 17, 2011 2:43:35 PM CEST]
  CHANGE:                 Change Package : 54276:1 http://mks-psad:7002/im/viewissue?selection=54276
  CHANGE:                 Revision 1.16 2011/09/29 16:33:14CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 added Streetlamp init function
  CHANGE:                 --- Added comments ---  brunnm [Sep 29, 2011 4:33:14 PM CEST]
  CHANGE:                 Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.15 2011/09/29 16:25:00CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 added Streetlamp init function
  CHANGE:                 --- Added comments ---  brunnm [Sep 29, 2011 4:25:00 PM CEST]
  CHANGE:                 Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
**************************************************************************** */
/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>
#include "hla_defs.h"
#include "hla_analysisstreetlamps.h"


/* functions */
static boolean HLAIsSLToRemove(const HLATrack_t*  pTLB,const HLACameraData_t *pCamData);
static boolean HLAIsANewSL(const HLATrack_t*  pTLB,const HLACameraData_t *pCamData);
static void  HLASLAddLights(HLASLInput_t* pIn,HLATrack_t *pTLB_Start,const HLACameraData_t *pCamData,const HLA_t_StreetLampsParam* pParams);
static void  HLASLRemoveLights(HLASLInput_t* pIn,const HLACameraData_t *pCamData);
static void HLAStreetLampReset(HLA_SL_ListNode_t* pSL,const HLA_t_StreetLampsParam* pParams);
static void HLAStreetLamp_Shape(const HLASLInput_t* pIn,HLATrack_t *pTLB_Start,const HLA_t_StreetLampsParam* pParams);
static void HLAStreetLamp_Behave(const HLA_t_MotionState* pMotionData, HLATrack_t *pTLB_Start,const HLACameraData_t *pCamData,const HLA_t_StreetLampsParam* pParams,const HLACamRot *pcamRot,const HLA_t_CameraParameter* pCamPar);
static void HLAStreetLamp_Decision(HLATrack_t *pTLB_Start,const HLA_t_StreetLampsParam* pParams);


/* **************************************************************************** 
  Functionname:     HLAStreetLampInit                              */ /*!  
  Description:      


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
static void HLAStreetLampReset(HLA_SL_ListNode_t* pSL,const HLA_t_StreetLampsParam* pParams)
{
  HLAStreetLampHist *pHist = &pSL->Hist;

  (void)memset((void*)pHist,0,sizeof(HLAStreetLampHist));
  pHist->LastMinLux = pParams->SL_Decision_Close.Thresh_Max_Lux;

  pSL->eStreetLampShape = HLA_SL_SHAPE_IDLE;
}

/* **************************************************************************** 
  Functionname:     HLAAnalysisStreetLampsInit                              */ /*!  
  Description:      


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
void HLAAnalysisStreetLampsInit( HLASLInput_t *pSLInput,
                                 HLA_SL_ListNode_t *pFreeStreetLampsBuffer,
                                 const HLA_t_Tracking3DParameters *pTracking3DParameters
                               )
{
  uint8 i;

  /* Set hlaSLInput */
  (void)memset((void*)pSLInput, 0, sizeof(HLASLInput_t));
  pSLInput->pTracking3DParams = pTracking3DParameters;
  pSLInput->pStreetLampsBufferFree = pFreeStreetLampsBuffer;


  /* Initialisation for street lamps analysis */
  (void)memset((void*)pFreeStreetLampsBuffer,0,sizeof(HLA_SL_ListNode_t)*MAX_NUM_SL);
  for(i=0;i<(MAX_NUM_SL-1);i++)
  {
    pFreeStreetLampsBuffer->next = pFreeStreetLampsBuffer + 1;
    pFreeStreetLampsBuffer++;
  }
  
}


/* **************************************************************************** 
  Functionname:     HLAAnalysisStreetLamps                              */ /*!  
  Description:      


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
void HLAAnalysisStreetLamps(HLASLInput_t* pIn, const HLA_t_MotionState* pMotionData, HLATrack_t *pTLB_Start,const HLACameraData_t *pCamData,const HLA_t_StreetLampsParam* pParams,const HLACamRot *pcamRot,const HLA_t_CameraParameter* pCamPar)
{

/* ------------------------------- ANALYZE STREET LAMP --------------------------------------------*/
  HLAStreetLamp_Behave(pMotionData,pTLB_Start,pCamData,pParams,pcamRot,pCamPar);

/* ----------------------------- ANALYZE STREET LAMP SHAPE ----------------------------------------*/
  HLAStreetLamp_Shape(pIn,pTLB_Start,pParams);

/* ---------------------------- ANALYZE STREET LAMP DECISION --------------------------------------*/
  HLAStreetLamp_Decision(pTLB_Start,pParams);

/* ---------------------------------- ADD STREET LAMP  --------------------------------------------*/
  HLASLAddLights(pIn,pTLB_Start,pCamData,pParams);

/* --------------------------------- REMOVE STREET LAMP  ------------------------------------------*/
  HLASLRemoveLights(pIn,pCamData);

}
/* **************************************************************************** 
  Functionname:     HLAStreetLamp                              */ /*!  
  Description:      


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
static void HLAStreetLamp_Shape(const HLASLInput_t* pIn,HLATrack_t *pTLB_Start,const HLA_t_StreetLampsParam* pParams)
{
  /* 32 bits */
  HLA_SL_ListNode_t  *pSL = pIn->pStreetLampsBuffer;
  HLAStreetLampHist  *pHist;
  HLATrack_t  *pT = pTLB_Start;
  const HLA_SL_Decision_t *pPar;
  HLASegLight_t    *pL;
  float32 Var,Delta_Lux;
  float32 xwmean_f;

  /* 16 bits */
  sint16 Ind_Local_Extremum;
  sint16 Ind;
  sint16 i;
  sint16 Delta_Time;

  /* boolean */
  boolean isMax,isMin;
  
  /*****************************/
  /* Work on the lights'shape  */
  /*****************************/
  while(pSL != NULL)
  {
    pT = pSL->pT;
    pL = pT->light_ref;
    pHist = &pSL->Hist;

    /******************/
    /* Update History */
    /******************/
    /* Update Nb Sample Tot */
    if(pHist->NbTotSample < SI16_T_MAX)
    {
      pHist->NbTotSample ++;
    }
    else
    {
      /* Do Nothing */
    }
    /* Update Indice */
    Ind = CML_Min(pHist->NbTotSample,SL_LP_ORDER_PLUS_ONE);

    /* Update History */
    for (i=0;i<(Ind-1);i++)
    {
      pHist->RawIntHist[i] = pHist->RawIntHist[i+1];
      pHist->LPIntHist[i] = pHist->LPIntHist[i+1];
    }
    if(pL != NULL)
    {
      pHist->RawIntHist[Ind-1] = pL->MaxInt;
    }
    else
    {
      pHist->RawIntHist[Ind-1] = 0;
    }
    pHist->LPIntHist[Ind-1] = 0;

    /************************************/
    /*  LOW PASS FILTER : CHEBYCHEV TYPE 
      Ordre : 5 
      Gain : 1
      Edge Frequency :  0.09 * Frequence Sampling 
               =  0.09 / Periode Sampling
               =  0.09/0.06 = 1.5 Hz
      Edge Magnitude Response : 0.5dB
      Filter group delay : Depending on frequency
     */
    /************************************/
    if(Ind == SL_LP_ORDER_PLUS_ONE)
    {
      for(i=0;i<Ind;i++)
      {
        pHist->LPIntHist[Ind-1] += pParams->LowPassFilterZeros[i] * pHist->RawIntHist[(Ind - 1) - i] ;
      }
      for(i=1;i<Ind;i++)
      {
        pHist->LPIntHist[Ind-1] -= pParams->LowPassFilterPoles[i] * pHist->LPIntHist[(Ind - 1) - i];
      }
    }
    else
    {
      pHist->LPIntHist[Ind-1] = 0;
    }

    /************************************/
      /* LOCAL MIN & MAX DETECTION */
    /************************************/
    isMax = TRUE;
    isMin = TRUE;
    Ind_Local_Extremum = (uint8)CML_u_Round2Uint(((float32)Ind)/2.0f);

    if(Ind == SL_LP_ORDER_PLUS_ONE)
    {
      for(i=0;i<Ind;i++)
      {
        if(    (i != Ind_Local_Extremum)
          &&  (pHist->LPIntHist[Ind_Local_Extremum] >= pHist->LPIntHist[i])
          )
        {
          isMin = FALSE;
        }
        else
        {
          /* Do nothing */
        }
        if(    (i != Ind_Local_Extremum)
          &&  (pHist->LPIntHist[Ind_Local_Extremum] <= pHist->LPIntHist[i])
          )
        {
          isMax = FALSE;
        }
        else
        {
          /* Do nothing */
        }
      }
    }
    else
    {  
      isMax = FALSE;
      isMin = FALSE;
    }

    /* Update Last Local Min & Max */
    if(isMin == TRUE)
    {
      pHist->LastMinLux = pHist->LPIntHist[Ind_Local_Extremum];
      pHist->LastMinNb = pHist->NbTotSample - (Ind - Ind_Local_Extremum);
    }
    else if(isMax == TRUE)
    {
      pHist->LastMaxLux = pHist->LPIntHist[Ind_Local_Extremum];
      pHist->LastMaxNb = pHist->NbTotSample - (Ind - Ind_Local_Extremum);    
    }
    else
    {
      /* Do Nothing - no last local min & max */
    }

    /************************************/
      /*    DECISION   */
    /************************************/
    /* Set variables */
    if(fabsf(pHist->LastMaxLux + pHist->LastMinLux) > 0.1f)
    {
      Delta_Lux = (pHist->LastMaxLux - pHist->LastMinLux)/((pHist->LastMaxLux + pHist->LastMinLux)/2.0f);
    }
    else
    {
      /* Should never happen */
      Delta_Lux = 0;
    }

    Var = (pHist->LastMaxLux - ((pHist->LastMaxLux + pHist->LastMinLux)/2.0f) );

    Delta_Time = pHist->LastMinNb - pHist->LastMaxNb;

    xwmean_f = ( (float32)(pT->xwmin100) + (float32)(pT->xwmax100) )/200.0f;

    /* Rough Estimation of the distance */
    if(xwmean_f > pParams->ThreshFarSL)
    {
      pHist->eEstDist = HLA_SL_FAR;
      pPar = &pParams->SL_Decision_Far;
    }
    else if(xwmean_f > pParams->ThreshMiddleSL)
    {
      pHist->eEstDist = HLA_SL_MIDDLE;
      pPar = &pParams->SL_Decision_Middle;
    }
    else
    {
      pHist->eEstDist = HLA_SL_CLOSE;
      pPar = &pParams->SL_Decision_Close;
    }

    /* Filter uncertain point */
    if(      (pHist->LastMinLux < 0)
        ||  ( (Delta_Time > pParams->Thresh_Max_Time_Diff) && (pHist->LastMinNb != 0) )
        ||  ( ((sint16)fabsf((float32)Delta_Time) > pParams->Thresh_Max_Time_Diff2) && (pHist->LastMinNb != 0) )
        ||  ( (Delta_Time>0) && (Delta_Time < pParams->Thresh_Min_Time_Diff) && (pHist->LastMinNb != 0) )
        ||  ( (Delta_Time>0) && ( ( (pHist->NbTotSample - Ind_Local_Extremum) - pHist->LastMinNb) > pParams->Thresh_Max_Time_Diff ) && (pHist->LastMinNb != 0) )
        )
    {
      pSL->eStreetLampShape = HLA_SL_NOT_FLICKERING;
      if(pT->idResStat.isStreetLamp.confidence>0)
      {
        pT->idResStat.isStreetLamp.confidence = CML_Max(pT->idResStat.isStreetLamp.confidence - 5, 0);
      }
      else
      {
        /* Do Nothing */
      }
      /* Reset historic */
      HLAStreetLampReset(pSL,pParams);
    }
    else
    {
      if(pSL->eStreetLampShape == HLA_SL_NOT_FLICKERING)
      {
        pSL->eStreetLampShape = HLA_SL_SHAPE_IDLE;
      }
      else
      {
        /* Do Nothing */
      }
    }

    /* Filter Too Bright Point */
    if(    (pHist->LastMaxLux > pPar->Thresh_Max_Lux)
      ||  (Var > pPar->Thresh_Max_Var)
      )
    {
      pSL->eStreetLampShape = HLA_SL_TOO_BRIGHT;
      pT->idResStat.isStreetLamp.confidence = CML_Max(pT->idResStat.isStreetLamp.confidence - 2, pParams->SLConf_Min);
    }
    else
    {
      if(pSL->eStreetLampShape == HLA_SL_TOO_BRIGHT)
      {
        pSL->eStreetLampShape = HLA_SL_SHAPE_IDLE;
      }
      else
      {
        /* Do Nothing */
      }
    }

    /* Filter Red Point */
    if(    (pT->RedLightCnt4City >= 1) 
        || (   (!(pT->anaResStat.isOtherColor.result == HLA_RESULT_POSITIVE)) 
             &&  (pT->anaResStat.isWhiteOrRed.result == HLA_RESULT_NEGATIVE)
           )
      )
    {
      pSL->eStreetLampShape = HLA_SL_RED_LAMP;
      pT->idResStat.isStreetLamp.confidence = CML_Max(pT->idResStat.isStreetLamp.confidence - 2, pParams->SLConf_Min);
    }
    else 
    {
      if(pSL->eStreetLampShape == HLA_SL_RED_LAMP)
      {
        pSL->eStreetLampShape = HLA_SL_SHAPE_IDLE;
      }
      else
      {
        /* Do Nothing */
      }
    }
      
      
    /* Make the decision */
    if(      (isMin == TRUE)
        &&  (Delta_Lux > pPar->Thresh_Min_Delta_Lux)
        &&  (Delta_Time > 0)
        &&  (pHist->LastMaxLux > pPar->Thresh_Min_Extremum)
        &&  (pHist->LastMinLux < pPar->Thresh_Max_Extremum)
        &&  (pSL->eStreetLampShape != HLA_SL_TOO_BRIGHT)
        &&  (pSL->eStreetLampShape != HLA_SL_RED_LAMP)
        &&  (pSL->eStreetLampShape != HLA_SL_NOT_FLICKERING)
      )
    {
      if(    (pSL->eStreetLampShape == HLA_SL_SHAPE_1time)
        ||  (pSL->eStreetLampShape == HLA_SL_SHAPE_DTCD)
        )
      {
        pSL->eStreetLampShape = HLA_SL_SHAPE_DTCD;
        pT->idResStat.isStreetLamp.confidence = pParams->SLConf_Max;
      }
      else
      {
        pSL->eStreetLampShape = HLA_SL_SHAPE_1time;
      }


    }
    else
    {
      /* Do nothing */
    }
    pSL = pSL->next;
  }
}
/* **************************************************************************** 
  Functionname:     HLAStreetLamp_Behave                              */ /*!  
  Description:      


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
static void HLAStreetLamp_Behave(const HLA_t_MotionState* pMotionData, HLATrack_t *pTLB_Start,const HLACameraData_t *pCamData,const HLA_t_StreetLampsParam* pParams,const HLACamRot *pcamRot,const HLA_t_CameraParameter* pCamPar)
{
  /* 32 bits */
  HLATrack_t  *pT = pTLB_Start;
  float32 xwmean_f;
  float32 zwmax100_f32,zwmin100_f32;
  const HLA_SL_Decision_t *pPar;

  /* 16 bits */
  uint16 yb;

  /* 8 bits */
  boolean b3D_OK = FALSE,
          b3D_BAD = FALSE,
          bDYNAMIC = FALSE,
          b2D_OK = FALSE,
          b2D_BAD = FALSE;
  sint8 DeltaConf;
  uint8 NbCol,NbLin;

  /**********************************************/
    /* Set variables for 2D direction  */
  /**********************************************/
  yb = (uint16)HLACamRotGetyb(pcamRot, pParams->maxDistStreetLamp, 0.0f, pParams->minHeightStreetLamp);
  /* uint16 is always >= 0 */
  yb = CML_Min((uint16)pCamPar->s_ImageSize.ui32_y, yb);

  while(pT != NULL)
  {
    /* reset flags */
    b3D_OK = FALSE;
    b3D_BAD = FALSE;
    bDYNAMIC = FALSE;
    b2D_OK = FALSE;
    b2D_BAD = FALSE;

    xwmean_f = ( (float32)(pT->xwmin100) + (float32)(pT->xwmax100) )/200.0f;

    /* Estimation of the distance */
    if(xwmean_f > pParams->ThreshFarSL)
    {
      pPar = &pParams->SL_Decision_Far;
    }
    else if(xwmean_f > pParams->ThreshMiddleSL)
    {
      pPar = &pParams->SL_Decision_Middle;
    }
    else
    {
      pPar = &pParams->SL_Decision_Close;
    }
#ifdef PC_SIM
    pT->eStreetLampBehave = HLA_SL_BEHAVE_IDLE;
#endif

    /********************/
    /* 3D position */
    /********************/
    zwmax100_f32 = (float32)( pT->zwmax100 );
    zwmin100_f32 = (float32)( pT->zwmin100 );
    if(    ( (float32)pT->zwmin100 > pPar->Thresh_Min_Zw100 )
      &&  ( pT->lost_time == 0 )
      &&  ( ( zwmax100_f32 - zwmin100_f32 ) < pParams->Thresh_Max_DeltaZw100 )
      &&  ( pT->xwmin100 > 800 )
      )
    {
      b3D_OK = TRUE;
#ifdef PC_SIM
      pT->e3D = HLA_SL_TRUE;
#endif
    }
    else if(    ( pT->lost_time == 0 )
      &&  ( (float32)pT->zwmax100 < pPar->Thresh_Min_Zw100 )
      &&  ( ( zwmax100_f32 - zwmin100_f32 ) > pParams->Thresh_Max_DeltaZw100 )
      &&  ( pT->xwmin100 > 800 )
      )
    {
      b3D_BAD = TRUE;
#ifdef PC_SIM
      pT->e3D = HLA_SL_FALSE;
#endif
    }
    else
    {
#ifdef PC_SIM
      pT->e3D = HLA_SL_IDLE;
#endif
    }

    /***********************/
       /* DYNAMIC test */
    /***********************/
    if(pT->TrackerClass == HLA_TRACKING3D_TRACKERCLASS_DYNAMIC)
    {
      bDYNAMIC = TRUE;
#ifdef PC_SIM
      pT->eDyn = HLA_SL_TRUE;
#endif
    }
    else
    {
      bDYNAMIC = FALSE;
#ifdef PC_SIM
      pT->eDyn = HLA_SL_FALSE;
#endif
    }

    /***********************/
      /* 2D Signature */
    /***********************/
#ifdef PC_SIM
      pT->e2D = HLA_SL_IDLE;
#endif
    if (  (pT->delta_y_lp_lt < (-0.05f * (fabsf(pT->delta_x_lp)))) 
      &&  (pT->delta_y_lp_lt < pParams->minSpeed)
      &&  (pT->ycenter <  yb)
      &&  (pT->lost_time == 0)
      &&  (pMotionData->f32_Speed > 1.0f)
      &&  (pMotionData->e_MoveState == HLA_MOVE_STATE_FWD)
      &&  (pT->statusAnalysisVehicle.isVehicleOncoming == FALSE)
      )
    {
      b2D_OK = TRUE;
#ifdef PC_SIM
      pT->e2D = HLA_SL_TRUE;
#endif
    }
    else if (     (pMotionData->f32_Speed > pParams->MinSpeed_Direction) 
              &&  (pMotionData->e_MoveState == HLA_MOVE_STATE_FWD)
              && (pT->lost_time == 0) 
              && (pT->delta_y_lp > 0))
    {
      b2D_BAD = TRUE;
#ifdef PC_SIM
      pT->e2D = HLA_SL_FALSE;
#endif
    }
    else
    {
      /* Do Nothing */
    }

    /* Set NbCol */
    if(b2D_OK == TRUE)
    {
      NbCol = 0;
    }
    else if(b2D_BAD == TRUE)
    {
      NbCol = 2;
    }
    else
    {
      NbCol = 1;
    }

    /* Set NbLin */
    if(b3D_OK == TRUE)
    {
      NbLin = 0;
    }
    else if(b3D_BAD == TRUE)
    {
      NbLin = 2;
    }
    else
    {
      NbLin = 1;
    }
    NbLin = (bDYNAMIC == TRUE) ? (NbLin + 3) : (NbLin);

    if(pT->idResStat.isStreetLamp.confidence >= 0)
    {
      DeltaConf = pParams->ArrayConfPos[ ( 3 * NbLin ) + NbCol];
    }
    else
    {
      DeltaConf = pParams->ArrayConfNeg[ ( 3 * NbLin ) + NbCol];
    }

    pT->idResStat.isStreetLamp.confidence = CML_MinMax(pParams->SLConf_Min,pParams->SLConf_Max,pT->idResStat.isStreetLamp.confidence + DeltaConf);

    /***********************/
    /* Filter Traffic Sign */
    /***********************/
    if(    (pT->light_ref != 0)
      &&  (pT->light_ref->pRegion != NULL)
      &&  (     (     ( (pT->light_ref->pRegion->x2 - pT->light_ref->pRegion->x1) > pPar->SL_MaxWidth) 
                  ||  ( (pT->light_ref->pRegion->y2 - pT->light_ref->pRegion->y1) > pPar->SL_MaxHeight) 
                 )
           )
      )
    {
      pT->idResStat.isStreetLamp.confidence = pParams->SLConf_Min;
#ifdef PC_SIM
      pT->eStreetLampBehave = HLA_SL_TOO_LARGE;
#endif
    }
    else
    {
      /* Do Nothing */
    }

    /**********************/  
    /* Not a SL Detection */
    /**********************/  
    if( pT->ycenter > pCamData->FOE_y )
    {
#ifdef PC_SIM
      pT->eStreetLampBehave = HLA_SL_ND;
#endif
      pT->idResStat.isStreetLamp.confidence = pParams->SLConf_Min;
    }

    /* Next track */
    pT = pT->next;
  }  
}
/* **************************************************************************** 
  Functionname:     HLAStreetLamp_Decision                            */ /*!  
  Description:      


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
static void HLAStreetLamp_Decision(HLATrack_t *pTLB_Start,const HLA_t_StreetLampsParam* pParams)
{
  /* 32 bits */
  HLATrack_t  *pT = pTLB_Start;

  while(pT != NULL)
  {
    if(pT->idResStat.isStreetLamp.confidence > pParams->ThreshSLConfPos)
    {
      pT->idResStat.isStreetLamp.result = HLA_RESULT_POSITIVE;
    }
    else if(pT->idResStat.isStreetLamp.confidence <= pParams->ThreshSLConfNeg)
    {
      pT->idResStat.isStreetLamp.result = HLA_RESULT_NEGATIVE;
    }
    else
    {
      pT->idResStat.isStreetLamp.result = HLA_RESULT_IDLE;
    }
    pT = pT->next;
  }
}
/* **************************************************************************** 
  Functionname:     HLAIsANewSL                              */ /*!  
  Description:      


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
static boolean HLAIsANewSL(const HLATrack_t*  pTLB,const HLACameraData_t *pCamData)
{
  boolean bNew;

  if(    (pTLB->light_ref != 0)
    &&  (pTLB->ycenter < pCamData->FOE_y)
    &&  (pTLB->TrackingStatus.IsSLAssociated == FALSE)
    )
  {
    bNew = TRUE;
  }
  else
  {
    bNew = FALSE;
  }

  return bNew;
}
/* **************************************************************************** 
  Functionname:     HLAIsANewSL                              */ /*!  
  Description:      


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
static boolean HLAIsSLToRemove(const HLATrack_t*  pTLB,const HLACameraData_t *pCamData)
{
  boolean bRemove;

  if(    (pTLB->TrackingStatus.willBeRemoved == 1)
    ||  ( (pTLB->light_ref != 0) && (pTLB->ycenter > pCamData->FOE_y))
    )
  {
    bRemove = TRUE;
  }
  else
  {
    bRemove = FALSE;
  }

  return bRemove;
}
/* **************************************************************************** 
  Functionname:     HLASLAddLights                              */ /*!  
  Description:      Add Lights to free_street_lamps_buffer


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
static void  HLASLAddLights(HLASLInput_t* pIn,HLATrack_t *pTLB_Start,const HLACameraData_t *pCamData,const HLA_t_StreetLampsParam* pParams)
{
  /* local variable */
  HLATrack_t  *pT = pTLB_Start;
  HLA_SL_ListNode_t  *pSL;

  /*  return current tracked_lights if maximum count reached */
  if( (pIn->pStreetLampsBufferFree) != 0)
  {
    /* add new light */
    while (pT != 0)
    {
      if(    (HLAIsANewSL(pT,pCamData) == TRUE)
        &&  ((pIn->pStreetLampsBufferFree) != 0)
        )
      {
        /* manage ROLLING BUFFER */

        /*  get next free Street Lamp */
        pSL = pIn->pStreetLampsBufferFree;
        pIn->pStreetLampsBufferFree = pIn->pStreetLampsBufferFree->next;

        /* add new elemt as first elemt of analyzed street lamp list */
        pSL->next = pIn->pStreetLampsBuffer;

        /* return analyzed street lamps */
        pIn->pStreetLampsBuffer = pSL;

        /* initialize Street Lamp */
        HLAStreetLampReset(pSL,pParams);
        pSL->pT = pT;
        pSL->pT->TrackingStatus.IsSLAssociated = TRUE;
      }
      pT = pT->next;
    }
  }
}
/* **************************************************************************** 
  Functionname:     HLASLRemoveLights                              */ /*!  
  Description:      Remove Lights from free_street_lamps_buffer


  @param[in]        

  @return           
  @pre              -
  @post             -
  @author           Boris LUGEZ
**************************************************************************** */
static void  HLASLRemoveLights(HLASLInput_t* pIn,const HLACameraData_t *pCamData)
{
  /* local variable */
  HLA_SL_ListNode_t  *pSL,*pSL_next,*pSL_prev;
  pSL = pIn->pStreetLampsBuffer;
  pSL_next = 0;
  pSL_prev = 0;

  while (pSL != NULL)
  {
    if( HLAIsSLToRemove(pSL->pT, pCamData) == b_TRUE)
    {
      pSL->pT->TrackingStatus.IsSLAssociated = FALSE;

      /* save next SL pointer in SL list. */
      pSL_next = pSL->next;

      /* save the next-in-list SL to the previous SL. */
      if(pSL_prev != NULL)
      {
        pSL_prev->next = pSL->next;
      }
      else
      {
        pIn->pStreetLampsBuffer = pSL->next;
      }

      /* add removed SL to the beginning of free SL list. */
      pSL->next = pIn->pStreetLampsBufferFree;
      pIn->pStreetLampsBufferFree = pSL;

      /* move the pointer to the next SL. */
      pSL = pSL_next;
    }
    else
    {
      pSL_prev = pSL;
      pSL = pSL->next;
    }
  }
}/* PRQA S 861 1 */
