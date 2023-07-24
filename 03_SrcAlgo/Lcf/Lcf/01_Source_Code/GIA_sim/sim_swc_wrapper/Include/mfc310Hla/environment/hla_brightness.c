/*! \file **********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC3xx

  CPU:                    freescale Golddust

  COMPONENT:              HLA

  MODULNAME:              hla_brightness.c

  DESCRIPTION:            Environmental brightness analysis.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          11.05.2011

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_brightness.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:55CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:33CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:26CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.29 2014/03/26 11:27:48CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:48 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.28 2014/03/25 19:11:51CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Separation of hla_segmentation.c
  CHANGE:                 Removed QAC warnings
  CHANGE:                 Replaces fABS by CML_f_abs
  CHANGE:                 Introduced CML_s_Round2Int
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:51 PM CET]
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.27 2014/03/25 18:36:43CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_brightness.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_brightness.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/environment/project.pj.
  CHANGE:                 Revision 1.26 2014/03/19 16:31:04CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:04 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.25 2014/03/18 11:51:22CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed brightness detection at init cycle
  CHANGE:                 --- Added comments ---  brunnm [Mar 18, 2014 11:51:22 AM CET]
  CHANGE:                 Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGE:                 Revision 1.24 2014/03/04 16:51:54CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:51:54 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.23 2014/02/18 13:21:48CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed missing initialization of global variables
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 18, 2014 1:21:49 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.22 2014/01/24 09:34:57CET Glebov, Roman (uidg4759) 
  CHANGE:                 switched from F32_IS_.* from global_defs.h to HLA_F32_IS_.* from hla_defs.h. 
  CHANGE:                 These are custom versions, which use much smaller Epsilon delta for comparison with 0
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 24, 2014 9:34:58 AM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.21 2014/01/23 10:34:29CET Glebov, Roman (uidg4759) 
  CHANGE:                 fixes for float with zero comparison
  CHANGE:                 --- Added comments ---  uidg4759 [Jan 23, 2014 10:34:30 AM CET]
  CHANGE:                 Change Package : 193435:4 http://mks-psad:7002/im/viewissue?selection=193435
  CHANGE:                 Revision 1.20 2013/03/11 14:32:41CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Placed no longer needed by RTE ones
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eLightOutput
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 2:32:42 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.19 2013/01/24 16:37:05CET Brunn, Marcus (brunnm) 
  CHANGE:                 Switched to rte like types for
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  brunnm [Jan 24, 2013 4:37:06 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.18 2012/11/15 09:56:25CET Brunn, Marcus (brunnm) 
  CHANGE:                 interface update for MFC4B0, BMW I210 (without RTE)
  CHANGE:                 --- Added comments ---  brunnm [Nov 15, 2012 9:56:26 AM CET]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.17 2012/10/18 17:55:41CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - allocation of array memory by array macro in order to realize a dedicated array boundary check mode
  CHANGE:                 --- Added comments ---  uidt9253 [Oct 18, 2012 5:55:41 PM CEST]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.16 2012/10/17 17:00:42CEST Brunn, Marcus (brunnm) 
  CHANGE:                 fixed memory write exception (bCriteriaNegFulfilled[0])
  CHANGE:                 --- Added comments ---  brunnm [Oct 17, 2012 5:00:47 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.15 2012/09/11 10:35:48CEST Brunn, Marcus (brunnm) 
  CHANGE:                 fixed  Potential blinding at daytime
  CHANGE:                 --- Added comments ---  brunnm [Sep 11, 2012 10:35:50 AM CEST]
  CHANGE:                 Change Package : 158782:1 http://mks-psad:7002/im/viewissue?selection=158782
  CHANGE:                 Revision 1.14 2012/09/04 19:01:35CEST Brunn, Marcus (brunnm) 
  CHANGE:                 improved brightness state detection
  CHANGE:                 Revision 1.13 2012/07/26 15:40:27CEST Brunn, Marcus (brunnm) 
  CHANGE:                 fixed late HB on during dusk/dawn
  CHANGE:                 --- Added comments ---  brunnm [Jul 26, 2012 3:40:29 PM CEST]
  CHANGE:                 Change Package : 144644:1 http://mks-psad:7002/im/viewissue?selection=144644
  CHANGE:                 Revision 1.12 2012/07/23 12:58:08CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - code review comments from Humic
  CHANGE:                 --- Added comments ---  uidt9253 [Jul 23, 2012 12:58:09 PM CEST]
  CHANGE:                 Change Package : 94931:1 http://mks-psad:7002/im/viewissue?selection=94931
  CHANGE:                 Revision 1.11 2012/07/18 08:56:29CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - added code review tags
  CHANGE:                 --- Added comments ---  brunnm [Jul 18, 2012 8:56:29 AM CEST]
  CHANGE:                 Change Package : 94933:1 http://mks-psad:7002/im/viewissue?selection=94933
  CHANGE:                 Revision 1.10 2012/03/26 16:36:42CEST Brunn, Marcus (brunnm) 
  CHANGE:                 introduced special handling after startup, at standstill and while driving backwards
  CHANGE:                 --- Added comments ---  brunnm [Mar 26, 2012 4:36:42 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.9 2012/03/22 18:27:12CET Brunn, Marcus (brunnm) 
  CHANGE:                 reworked brightness calculation (fixed false HB turn on during twilight3)
  CHANGE:                 Revision 1.8 2012/02/24 11:44:45CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed switching to fast into night (after hla init)
  CHANGE:                 --- Added comments ---  brunnm [Feb 24, 2012 11:44:46 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.7 2012/01/31 09:14:03CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed wrong brightness state after startup (between day and twilight 1 -> output will be twilight 1)
  CHANGE:                 --- Added comments ---  brunnm [Jan 31, 2012 9:14:04 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.6 2011/11/30 14:45:58CET Brunn, Marcus (brunnm) 
  CHANGE:                 Brightness: parameter update
  CHANGE:                 --- Added comments ---  brunnm [Nov 30, 2011 2:45:58 PM CET]
  CHANGE:                 Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.5 2011/11/29 16:30:43CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed DUSK/DAWN
  CHANGE:                 --- Added comments ---  brunnm [Nov 29, 2011 4:30:43 PM CET]
  CHANGE:                 Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.4 2011/07/11 12:55:51CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 improved dusk/dawn behaviour
  CHANGE:                 --- Added comments ---  brunnm [Jul 11, 2011 12:55:51 PM CEST]
  CHANGE:                 Change Package : 49575:2 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.3 2011/06/20 15:11:37CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 Segmentation: implemented light clustering
  CHANGE:                 --- Added comments ---  brunnm [Jun 20, 2011 3:11:37 PM CEST]
  CHANGE:                 Change Package : 49575:2 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.2 2011/05/18 19:43:25CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 improved dusk/dawn behaviour
  CHANGE:                 --- Added comments ---  brunnm [May 18, 2011 7:43:25 PM CEST]
  CHANGE:                 Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.1 2011/05/17 13:01:06CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 
  CHANGE:
**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include <string.h>
#include "hla_brightness.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static void HLABrightnessCheckIntSetDistTime( /* input */
                                              const RTE_HLAR_BrightnessState            eState,
                                              const eHLABrightnessResult                eResult,
                                              const boolean                             bPos,
                                              const boolean                             bNeg,
                                              const HLASegSubImage_t                    *pSubImg,
                                              const float32                             Thres2Sig,
                                              const HLACameraData_t                     *pCamData,
                                              const HLA_t_eMovementState                eMoveState,
                                              const HLABrightnessParThresRadius_t       *pPar_Radius,
                                              const HLABrightnessParThresTurbo_t        *pPar_Turbo,
                                              const HLABrightnessParThresMinDistTime_t  *pPar_MinDistTime,
                                              /* output */ 
                                              HLABrightnessDistTime_t                   *pOut
                                            );
static void HLABrightnessCheckInt( /* input */
                                   const RTE_HLAR_BrightnessState eState,
                                   const eHLABrightnessResult     eResult,
                                   const HLASegSubImage_t         *pSubImg,
                                   const HLABrightnessData_t      *pBrightness,
                                   const HLACameraData_t          *pCamData,
                                   const HLA_t_eMovementState     eMoveState,
                                   const HLABrightnessParThres_t  *pPar,
                                   /* output */ 
                                   HLABrightnessDistTime_t                  *pOut
                                 );
static void HLABrightnessSetResult(  /* input */
                                     const eHLABrightnessResult                eResult_in,
                                     const HLABrightnessDistTime_t             *pDat,
                                     const HLABrightnessParThresMinDistTime_t  *pPar,
                                     const HLA_t_eMovementState                 eMoveState,
                                     /* output */ 
                                     eHLABrightnessResult                      *peResult_out
                                  );
static void HLABrightnessSetState(  /* input */
                                    const HLABrightnessData_t *pBrightness,
                                    /* output */ 
                                    RTE_HLAR_BrightnessState  *peBrightnessState
                                 ); 
static void HLABrightnessCalcMeanIntF( /* input */
                                       const float32         SubImageSort_lux[HLA_SEG_INTENSITY_SUB_IMG_SIZE],
                                       const HLADataState_t  SubImage_State[HLA_SEG_INTENSITY_SUB_IMG_HEIGHT],
                                       const uint32          maxIndex,  
                                       /* output */
                                       HLABrightnessInt_t    *pOut
                                     );


/* **************************************************************************** 
  Functionname:     void HLABrightnessInit()                             */ /*!  
  Description:      

  @param[in]        -

  @return           

  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLABrightnessInit( HLABrightnessData_t*      pBrightnessData,
                        RTE_HLAR_BrightnessState* pBrightnessState
                       )
{  
  (void)memset((void*)pBrightnessData, 0, sizeof(HLABrightnessData_t));
  
  *pBrightnessState = RTE_HLAR_BRT_UNKNOWN;
}

/* **************************************************************************** 
  Functionname:     void HLABrightnessCheckIntSetDistTime()              */ /*!
  Description:      

  @param[in]        -

  @return           

  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLABrightnessCheckIntSetDistTime( /* input */
                                              const RTE_HLAR_BrightnessState            eState,
                                              const eHLABrightnessResult                eResult,
                                              const boolean                             bPos,
                                              const boolean                             bNeg,
                                              const HLASegSubImage_t                    *pSubImg,
                                              const float32                             Thres2Sig,
                                              const HLACameraData_t                     *pCamData,
                                              const HLA_t_eMovementState                eMoveState,
                                              const HLABrightnessParThresRadius_t       *pPar_Radius,
                                              const HLABrightnessParThresTurbo_t        *pPar_Turbo,
                                              const HLABrightnessParThresMinDistTime_t  *pPar_MinDistTime,
                                              /* output */ 
                                              HLABrightnessDistTime_t                   *pOut
                                            )
{
  float32 factor_turbo = 1.0f;
  float32 factor_radius = 1.0f;
  float32 factor_signal = 1.0f;
  float32 factor_total = 1.0f;
  float32 ddist, dtimeFwd, dtime_s;
  boolean bRadiusActive;


  if(eResult == HLA_BRIGHTNESS_RESULT_INIT)
  {
    /* init cycle */
    dtime_s = 0.06f;
  }
  else
  {
    /* not the init cycle */
    dtime_s = pCamData->dtime_s;
  }

  if(eMoveState == HLA_MOVE_STATE_FWD)
  {
    /* driving forwards */
    
    /* calc. factors not during init phase */
    if(    (eResult == HLA_BRIGHTNESS_RESULT_POSITIV)
        || (eResult == HLA_BRIGHTNESS_RESULT_NEGATIV)
      ) 
    {
      /* calculate factor due to the radius  */
      /* factor < 1.0f when ...              */
      /* eState == night or twilight         */
      /* we are driving into dark area       */
      if(    (eState > RTE_HLAR_BRT_DAY)
          && (bPos == b_TRUE)
        )
      {
        /* night or twilight and driving into dark area */
        if(pCamData->radiusAbs_m <= pPar_Radius->Radius0_m)
        {
          factor_radius = pPar_Radius->Factor0_ddist;
          bRadiusActive = b_TRUE;
        }
        else if(pCamData->radiusAbs_m > pPar_Radius->Radius1_m)
        {
          factor_radius = 1.0f;
          bRadiusActive = b_FALSE;
        }
        else
        {
          factor_radius = pPar_Radius->Factor0_ddist + (((1.0f-pPar_Radius->Factor0_ddist)/(pPar_Radius->Radius1_m - pPar_Radius->Radius0_m)) * (pCamData->radiusAbs_m - pPar_Radius->Radius0_m));
          bRadiusActive = b_TRUE;
        }
      }
      else
      {
        factor_radius = 1.0f;
        bRadiusActive = b_FALSE;
      }


      /* set the factor depending on the max intensity in the hla roi */
      if(    (bPos == b_TRUE)
          && (bRadiusActive == b_FALSE) /* -> factor_radius = 1.0f */
          && (pSubImg->RoiInt.Max < pPar_Turbo->Neg2Pos_MaxInt_lux)
          && (pSubImg->RoiInt.Max > pPar_Turbo->Neg2Pos_MinInt_lux)
          && (pSubImg->RoiInt.State.State == (uint8)HLA_DATA_STATE_VALID)
          )
      {
        /* night, twilight: driving into dark area     */
        /* -> increased filter speed  */
        factor_turbo = pPar_Turbo->MaxFactor;
      }
      else if(    (bNeg == b_TRUE)
               && (pSubImg->AboveRoiInt.Max < pPar_Turbo->Pos2Neg_MaxInt_lux)
               && (pSubImg->AboveRoiInt.Max > pPar_Turbo->Pos2Neg_MinInt_lux)
               && (pSubImg->AboveRoiInt.State.State == (uint8)HLA_DATA_STATE_VALID)
             )
      {
        /* night, twilight: driving into bright area     */
        /* -> increased filter speed  */
        factor_turbo = pPar_Turbo->MaxFactor;
      }
      else
      {
        factor_turbo = 1.0f;
      }

      /* calculate factor due to signal to threshold ratio */
      /* ~CodeReview ~ID:ef5479ff38fe1eca6032e9b65484d801 ~Reviewer:CW01\uidu4053 ~Date:16.07.2012 ~Priority:3 ~Comment:convert magic numbers to parameter */
      if(Thres2Sig >= 2.0f)
      {
        factor_signal = CML_f_Min(pPar_Turbo->MaxFactor, Thres2Sig);
      }
      else
      {
        factor_signal = 1.0f;
      }  
          
      /* calc. total factor */
      factor_total = CML_f_Max(factor_signal, factor_turbo) * factor_radius;
    }
    else
    {
      /* do nothing         */
      /* all factors = 1.0f */
    }
    ddist    = factor_total * pCamData->ddistFwd_m;
    dtimeFwd = factor_total * pCamData->dtimeFwd_s;
  

    if(bPos == b_TRUE)
    {
      /* min/max intensity within range */

      /* increment "Positive" distance and time */
      pOut->distPos_m += ddist;
      pOut->distPos_m = CML_f_Min(pOut->distPos_m, pPar_MinDistTime->MinDistPos_m);
      pOut->timePos_s += dtimeFwd;
      pOut->timePos_s = CML_f_Min(pOut->timePos_s, pPar_MinDistTime->MinTimePos_s);
      
      /* decrement "Negative" distance and time */
      pOut->distNeg_m -= ddist;
      pOut->distNeg_m = CML_f_Max(0.0f, pOut->distNeg_m);
      pOut->timeNeg_s -= dtimeFwd;
      pOut->timeNeg_s = CML_f_Max(0.0f, pOut->timeNeg_s);
    }
    else if(bNeg == b_TRUE)
    {
      /* min/max intensity outside range */

      /* increment "Negative" distance and time */
      pOut->distNeg_m += ddist;
      pOut->distNeg_m = CML_f_Min(pOut->distNeg_m, pPar_MinDistTime->MinDistNeg_m);
      pOut->timeNeg_s += dtimeFwd;
      pOut->timeNeg_s = CML_f_Min(pOut->timeNeg_s, pPar_MinDistTime->MinTimeNeg_s);
    
      /* decrement "Positive" distance and time */
      pOut->distPos_m -= ddist;
      pOut->distPos_m = CML_f_Max(0.0f, pOut->distPos_m);
      pOut->timePos_s -= dtimeFwd;
      pOut->timePos_s = CML_f_Max(0.0f, pOut->timePos_s);
    }
    else
    {
      /* Do nothing */
    }
  }
  else
  {
    /* standstill or driving backwards */
    float32 ddist_dec;
    float32 dtime_dec;
    float32 Inv = 1.0f/ CML_f_Max(pPar_MinDistTime->MaxTime2InitState_s, 1.0f);
   
   
    /* decrement positive distance and time */
    dtime_dec = (pPar_MinDistTime->MinTimePos_s * Inv) * dtime_s;
    ddist_dec = (pPar_MinDistTime->MinDistPos_m * Inv) * dtime_s;
    pOut->distPos_m -= ddist_dec;
    pOut->distPos_m = CML_f_Max(0.0f, pOut->distPos_m);
    pOut->timePos_s -= dtime_dec;
    pOut->timePos_s = CML_f_Max(0.0f, pOut->timePos_s);
    
    /* decrement negative distance and time */
    dtime_dec = (pPar_MinDistTime->MinTimeNeg_s * Inv) * dtime_s;
    ddist_dec = (pPar_MinDistTime->MinDistNeg_m * Inv) * dtime_s;
    pOut->distNeg_m -= ddist_dec;
    pOut->distNeg_m = CML_f_Max(0.0f, pOut->distNeg_m);
    pOut->timeNeg_s -= dtime_dec;
    pOut->timeNeg_s = CML_f_Max(0.0f, pOut->timeNeg_s);
  }
  

  /* increment/decrement timePosAll_s and timeNegAll_s */
  if(bPos == b_TRUE)
  {
    /* min/max intensity within range */

    /* increment "Positive" time */
    pOut->timePosAll_s += dtime_s;
    pOut->timePosAll_s = CML_f_Min(pOut->timePosAll_s, pPar_MinDistTime->MinTimePosInit_s);

    /* decrement "Negative" distance and time */
    pOut->timeNegAll_s -= dtime_s;
    pOut->timeNegAll_s = CML_f_Max(0.0f, pOut->timeNegAll_s);
  }
  else if(bNeg == b_TRUE)
  {
    /* min/max intensity outside range */

    /* increment "Negative" time */
    pOut->timeNegAll_s += dtime_s;
    pOut->timeNegAll_s = CML_f_Min(pOut->timeNegAll_s, pPar_MinDistTime->MinTimeNegInit_s);

    /* decrement "Positive" distance and time */
    pOut->timePosAll_s -= dtime_s;
    pOut->timePosAll_s = CML_f_Max(0.0f, pOut->timePosAll_s);
  }
  else
  {
    /* Do nothing */
  }
  

  pOut->factor_radius = factor_radius;
  pOut->factor_turbo  = factor_turbo;
  pOut->factor_turbo  = factor_signal;
  pOut->factor_total  = factor_total;
}


/* **************************************************************************** 
  Functionname:     void HLABrightnessCheckInt()                    */ /*!  
  Description:      

  @param[in]        -

  @return           

  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLABrightnessCheckInt(/* input */
                                  const RTE_HLAR_BrightnessState  eState,
                                  const eHLABrightnessResult      eResult,
                                  const HLASegSubImage_t          *pSubImg,
                                  const HLABrightnessData_t       *pBrightness,
                                  const HLACameraData_t           *pCamData,
                                  const HLA_t_eMovementState      eMoveState,
                                  const HLABrightnessParThres_t   *pPar,
                                  /* output */ 
                                  HLABrightnessDistTime_t         *pOut
                                 )
{
  boolean bPos = b_FALSE;
  boolean bNeg = b_FALSE;
  uint32  i;
  float32 Thres2Sig; /* = threshold/ signal */

  
  /* reset bCriteriaPosFulfilled, bCriteriaNegFulfilled */  
  memset(&pOut->bCriteriaPosFulfilled[0],0, HLA_BRIGHTNESS_NUM_POS_CRITERIA * sizeof(boolean));
  memset(&pOut->bCriteriaNegFulfilled[0],0, HLA_BRIGHTNESS_NUM_NEG_CRITERIA * sizeof(boolean));

  switch(eResult)
  {
    case HLA_BRIGHTNESS_RESULT_POSITIV:
      /* no sampling aborted detected ? */
      if(    (pSubImg->AboveRoiInt.State.State == (uint8)HLA_DATA_STATE_VALID)
          && (pBrightness->RoiIntF.State.State == (uint8)HLA_DATA_STATE_VALID)
        )
      {
        /* one of the "Negative" criteria fulfilled ? */
        for(i=0; i<pPar->NumberOfUsedNegCriteria; i++)
        {
          if(    (pSubImg->AboveRoiInt.Min > pPar->Neg[i].AboveRoi_MinInt_lux)            
              && (pSubImg->AboveRoiInt.Max > pPar->Neg[i].AboveRoi_MaxInt_lux)
              && (pBrightness->RoiIntF.Int > pPar->Neg[i].Roi_MeanIntF_lux)
            )
          {
            bNeg = b_TRUE;
            pOut->bCriteriaNegFulfilled[i] = b_TRUE;
          }
          else
          {
            if(i < HLA_BRIGHTNESS_NUM_POS_CRITERIA)
            {
              pOut->bCriteriaPosFulfilled[i] = b_TRUE;
            }
          }
        }
        if(bNeg == b_FALSE)
        {
          bPos = b_TRUE;
        }
      }
      else
      {
        /* Sampling aborted detected  */
        /* -> vote for day/ twilight  */
        bNeg = b_TRUE;
        bPos = b_FALSE;
      }
      break;

    case HLA_BRIGHTNESS_RESULT_INIT:
    case HLA_BRIGHTNESS_RESULT_INIT_NEGATIV:
    case HLA_BRIGHTNESS_RESULT_INIT_POSITIV:
    case HLA_BRIGHTNESS_RESULT_UNKNOWN:
    case HLA_BRIGHTNESS_RESULT_ERROR:
    case HLA_BRIGHTNESS_RESULT_NEGATIV:
    default:
      /* one of the "positive" criteria fulfilled ? */
      for(i=0; i<pPar->NumberOfUsedPosCriteria; i++)
      {
        if(    (pSubImg->AboveRoiInt.Min < pPar->Pos[i].AboveRoi_MinInt_lux)
            && (pSubImg->AboveRoiInt.Max < pPar->Pos[i].AboveRoi_MaxInt_lux)
            && (pSubImg->AboveRoiInt.State.State == (uint8)HLA_DATA_STATE_VALID)
            && (pBrightness->RoiIntF.Int < pPar->Pos[i].Roi_MeanIntF_lux)
            && (pBrightness->RoiIntF.State.State == (uint8)HLA_DATA_STATE_VALID)
          )
        {
          bPos = b_TRUE;
          pOut->bCriteriaPosFulfilled[i] = b_TRUE;
        }
        else
        {
          if(i < HLA_BRIGHTNESS_NUM_NEG_CRITERIA)
          {
            pOut->bCriteriaNegFulfilled[i] = b_TRUE;
          }
        }
      }  
      /* if positive criteria not fulfilled -> set negative criteria to true */
      if(bPos == b_FALSE)
      {
        bNeg = b_TRUE;
      }
      break;
  }

 
  /* calc. ratio between signal and threshold */
  /* not during init phase                    */
#define RATIO_MIN 1.0f
#define RATIO_MAX 5.0f
  if(    (eResult == HLA_BRIGHTNESS_RESULT_POSITIV)
      || (eResult == HLA_BRIGHTNESS_RESULT_NEGATIV)
    ) 
  {
    float32 ratio;


    if(bPos == b_TRUE)
    {
      Thres2Sig = RATIO_MIN;

      for(i=0; i<pPar->NumberOfUsedPosCriteria; i++)
      {
        if(pOut->bCriteriaPosFulfilled[i] == b_TRUE)
        {
          ratio = RATIO_MAX;

          if(    (pBrightness->RoiIntF.Int > 0.0f)  
              && (pPar->Pos[i].Roi_MeanIntF_lux > 0.0f)
            ) 
          {
            ratio = CML_f_Min(ratio, (pPar->Pos[i].Roi_MeanIntF_lux/ pBrightness->RoiIntF.Int));
          }
          else
          {
            /* do nothing */
          }   
          Thres2Sig = CML_f_Max(ratio, Thres2Sig);
        }
      }
    }
    else if(bNeg == b_TRUE)
    {
      Thres2Sig = RATIO_MIN;

      for(i=0; i<pPar->NumberOfUsedNegCriteria; i++)
      {
        if(pOut->bCriteriaNegFulfilled[i] == b_TRUE)
        {
          ratio = RATIO_MAX;
          if(pPar->Neg[i].AboveRoi_MinInt_lux > 0.0f)
          {
            ratio = CML_f_Min(ratio, (pSubImg->AboveRoiInt.Min/ pPar->Neg[i].AboveRoi_MinInt_lux));
          }
          else
          {
            /* do nothing */
          }        
          if(pPar->Neg[i].AboveRoi_MaxInt_lux > 0.0f)
          {
            ratio = CML_f_Min(ratio, (pSubImg->AboveRoiInt.Max/ pPar->Neg[i].AboveRoi_MaxInt_lux));
          }
          else
          {
            /* do nothing */
          }
          if(pPar->Neg[i].Roi_MeanIntF_lux > 0.0f)
          {
            ratio = CML_f_Min(ratio, (pBrightness->RoiIntF.Int/ pPar->Neg[i].Roi_MeanIntF_lux));
          }
          else
          {
            /* do nothing */
          }  
          Thres2Sig = CML_f_Max(ratio, Thres2Sig);
        }
      }
    }
    else
    {
      Thres2Sig = RATIO_MIN;
    }
  }
  else
  {
    Thres2Sig = RATIO_MIN;
  }
#undef RATIO_MIN
#undef RATIO_MAX

  HLABrightnessCheckIntSetDistTime( /* input */
                                    eState,
                                    eResult,
                                    bPos,
                                    bNeg,
                                    pSubImg,
                                    Thres2Sig,
                                    pCamData,
                                    eMoveState,
                                    &pPar->Radius,
                                    &pPar->Turbo,
                                    &pPar->MinDistTime,
                                    /* output */ 
                                    pOut
                                  );
}


/* **************************************************************************** 
  Functionname:     void HLABrightnessSetResult()                        */ /*!  
  Description:      

  @param[in]        -

  @return           

  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLABrightnessSetResult(  /* input */
                                    const eHLABrightnessResult                eResult_in,
                                    const HLABrightnessDistTime_t             *pDat,
                                    const HLABrightnessParThresMinDistTime_t  *pPar,
                                    const HLA_t_eMovementState                eMoveState,
                                    /* output */ 
                                    eHLABrightnessResult                      *peResult_out
                                 )
{
  switch(eResult_in)
  {
    case HLA_BRIGHTNESS_RESULT_INIT:
    case HLA_BRIGHTNESS_RESULT_INIT_NEGATIV:
    case HLA_BRIGHTNESS_RESULT_INIT_POSITIV:
      if(    (pDat->timeNeg_s >= pPar->MinTimeNeg_s)
          && (pDat->distNeg_m >= pPar->MinDistNeg_m)
        ) 
      {
        *peResult_out = HLA_BRIGHTNESS_RESULT_NEGATIV;
      }
      else if(    (pDat->timePos_s >= pPar->MinTimePos_s)
               && (pDat->distPos_m >= pPar->MinDistPos_m)
             )
      {
        *peResult_out = HLA_BRIGHTNESS_RESULT_POSITIV;
      }
      else
      {
        /* init cycle/ standstill/ driving backwards */
        if(eResult_in == HLA_BRIGHTNESS_RESULT_INIT_POSITIV)
        {
          if(pDat->timeNegAll_s >= pPar->MinTimeNegInit_s)
          {
            *peResult_out = HLA_BRIGHTNESS_RESULT_INIT_NEGATIV;
          } 
        }
        else if(eResult_in == HLA_BRIGHTNESS_RESULT_INIT_NEGATIV)
        {
          if(    (CML_f_IsZero(pDat->timeNegAll_s))
              && (pDat->timePosAll_s >= pPar->MinTimePosInit_s)
            )  
          {
            *peResult_out = HLA_BRIGHTNESS_RESULT_INIT_POSITIV;
          } 
        }
        else
        {
          /* first cycle in init */
          /* decision not made   */
          if(pDat->timePosAll_s > pDat->timeNegAll_s)
          {
            *peResult_out = HLA_BRIGHTNESS_RESULT_INIT_POSITIV;
          }
          else
          {
            *peResult_out = HLA_BRIGHTNESS_RESULT_INIT_NEGATIV;
          }
        }
      }
      break;

    case HLA_BRIGHTNESS_RESULT_NEGATIV:
      /* goto positive state ? */
      if(eMoveState != HLA_MOVE_STATE_FWD)
      {
        /* not driving forwards */
        /* J.Häfer: No Possible Side Effect */
        /* PRQA S 3415 6 */
        if(    (CML_f_IsZero(pDat->timePos_s))
            && (CML_f_IsZero(pDat->distPos_m))
            && (CML_f_IsZero(pDat->timeNeg_s))
            && (CML_f_IsZero(pDat->distNeg_m ))
            && (pDat->timePosAll_s >= pPar->MinTimePosInit_s)
            && (CML_f_IsZero(pDat->timeNegAll_s))
          )
        {
          *peResult_out = HLA_BRIGHTNESS_RESULT_POSITIV;
        }
      }
      else if(    (pDat->timePos_s >= pPar->MinTimePos_s)
               && (pDat->distPos_m >= pPar->MinDistPos_m)
             )
      {
        *peResult_out = HLA_BRIGHTNESS_RESULT_POSITIV;
      }
      else
      {
        /* Do nothing */
      }
      break;

    case HLA_BRIGHTNESS_RESULT_POSITIV:
      /* goto negative state ? */
      if(eMoveState != HLA_MOVE_STATE_FWD)
      {
        /* not driving forwards */
        /* J.Häfer: No Possible Side Effect */
        /* PRQA S 3415 5 */
        if(    (CML_f_IsZero(pDat->timePos_s))
            && (CML_f_IsZero(pDat->distPos_m))
            && (CML_f_IsZero(pDat->timeNeg_s))
            && (CML_f_IsZero(pDat->distNeg_m))
            && (pDat->timeNegAll_s >= pPar->MinTimeNegInit_s)
          )
        {
          *peResult_out = HLA_BRIGHTNESS_RESULT_NEGATIV;
        }
      }
      else if(    (pDat->timeNeg_s >= pPar->MinTimeNeg_s)
               && (pDat->distNeg_m >= pPar->MinDistNeg_m)
             )
      {
        *peResult_out = HLA_BRIGHTNESS_RESULT_NEGATIV;
      }
      else
      {
        /* Do nothing */
      }
      break;

    case HLA_BRIGHTNESS_RESULT_UNKNOWN:
    case HLA_BRIGHTNESS_RESULT_ERROR:
    default:
      *peResult_out = HLA_BRIGHTNESS_RESULT_INIT;
      break;
  } 
}

/* **************************************************************************** 
  Functionname:     void HLABrightnessSetState()                         */ /*!  
  Description:      

  @param[in]        -

  @return           

  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLABrightnessSetState(  /* input */
                                    const HLABrightnessData_t *pBrightness,
                                    /* output */ 
                                    RTE_HLAR_BrightnessState  *peBrightnessState
                                 )
{
  if(    (pBrightness->eNight == HLA_BRIGHTNESS_RESULT_POSITIV)
      || (pBrightness->eNight == HLA_BRIGHTNESS_RESULT_INIT_POSITIV)
    )
  {
    *peBrightnessState = RTE_HLAR_BRT_NIGHT;
  }
  else if(    (pBrightness->eTwilight_3 == HLA_BRIGHTNESS_RESULT_POSITIV)
           || (pBrightness->eTwilight_3 == HLA_BRIGHTNESS_RESULT_INIT_POSITIV)
         ) 
  {
    *peBrightnessState = RTE_HLAR_BRT_TWLGT_3;
  }
  else if(    (pBrightness->eTwilight_2 == HLA_BRIGHTNESS_RESULT_POSITIV)
           || (pBrightness->eTwilight_2 == HLA_BRIGHTNESS_RESULT_INIT_POSITIV)
         )
  {
    *peBrightnessState = RTE_HLAR_BRT_TWLGT_2;
  }
  else if(    (pBrightness->eTwilight_1 == HLA_BRIGHTNESS_RESULT_POSITIV)
           || (pBrightness->eTwilight_1 == HLA_BRIGHTNESS_RESULT_INIT_POSITIV)
         )
  {
    *peBrightnessState = RTE_HLAR_BRT_TWLGT_1;
  }
  else if(    (pBrightness->eTwilight_1 == HLA_BRIGHTNESS_RESULT_NEGATIV)
           || (pBrightness->eTwilight_1 == HLA_BRIGHTNESS_RESULT_INIT_NEGATIV)
         )
  {
    *peBrightnessState = RTE_HLAR_BRT_DAY;
  }
  else
  {
    /* stay in last state */
  }
}

static void HLABrightnessCalcMeanIntF( /* input */
                                       const float32         SubImageSort_lux[HLA_SEG_INTENSITY_SUB_IMG_SIZE],
                                       const HLADataState_t  SubImage_State[HLA_SEG_INTENSITY_SUB_IMG_HEIGHT],
                                       const uint32          maxIndex,  
                                       /* output */
                                       HLABrightnessInt_t    *pOut
                                     )
{
  uint32 i;
  uint8  State = (uint8)HLA_DATA_STATE_VALID;
  float32 acc  = 0.0f;
  uint32  imax = CML_Min(maxIndex, (HLA_SEG_INTENSITY_SUB_IMG_SIZE));


  for(i=0;i<HLA_SEG_INTENSITY_SUB_IMG_HEIGHT;i++)
  {
    if(SubImage_State[i].State != (uint8)HLA_DATA_STATE_VALID)
    {
      State = SubImage_State[i].State;
    }
  }

  
  for(i=0; i<imax; i++)
  {
    acc += SubImageSort_lux[i];
    
  }
  if(    (maxIndex > 0)
      && (State == (uint8)HLA_DATA_STATE_VALID)
    )
  {
    pOut->Int   = acc/imax;
    pOut->State.State = State;
  }
  else
  {
    pOut->Int = 0.0f;
    pOut->State.State = State;
  }
}

/* **************************************************************************** 
  Functionname:     void HLABrightnessExec()                             */ /*!  
  Description:      

  @param[in]        -

  @return           

  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLABrightnessExec( /* input */
                        const HLASegSubImage_t          *pSubImg, 
                        const HLACameraData_t           *pCamData,
                        const HLA_t_eMovementState      eMoveState,
                        const HLABrightnessParameters_t *pPar,
                        /* history */
                        HLABrightnessData_t             *pBrightness,
                        /* output */
                        RTE_HLAR_BrightnessState        *peBrightnessState
                      )
{
  /* calculate (filtered) mean intensity of the n darkest cells out of the 25 cells of the subsampled image */
  HLABrightnessCalcMeanIntF(  /* input */
                              &pSubImg->SubImageSort_lux[0],
                              &pSubImg->SubImage_State[0],
                              pPar->MeanIntFMaxIndex, /* e.g. 20 out of 25 */
                              /* output */
                              &pBrightness->RoiIntF
                           );


  /* check intensity for */
  /* twilight 1 */
  HLABrightnessCheckInt(  /* input */
                          RTE_HLAR_BRT_TWLGT_1,
                          pBrightness->eTwilight_1,
                          pSubImg,
                          pBrightness,
                          pCamData,
                          eMoveState,
                          &pPar->Twilight_1,
                          /* output */ 
                          &pBrightness->Twilight_1
                       );
 
  /* twilight 2 */
  HLABrightnessCheckInt(  /* input */
                          RTE_HLAR_BRT_TWLGT_2,
                          pBrightness->eTwilight_2,
                          pSubImg,
                          pBrightness,
                          pCamData,
                          eMoveState,
                          &pPar->Twilight_2,
                          /* output */ 
                          &pBrightness->Twilight_2
                       );
  
  /* twilight 3 */
  HLABrightnessCheckInt(  /* input */
                          RTE_HLAR_BRT_TWLGT_3,
                          pBrightness->eTwilight_3,
                          pSubImg,
                          pBrightness,
                          pCamData,
                          eMoveState,
                          &pPar->Twilight_3,
                          /* output */ 
                          &pBrightness->Twilight_3
                       );
  
  /* night */
  HLABrightnessCheckInt(  /* input */
                          RTE_HLAR_BRT_NIGHT,
                          pBrightness->eNight,
                          pSubImg,
                          pBrightness,
                          pCamData,
                          eMoveState,
                          &pPar->Night,
                          /* output */ 
                          &pBrightness->Night
                       );

  /* set results: day, twilight, night detected ? */
  /* twilight_1 */  
  HLABrightnessSetResult( /* input */
                          pBrightness->eTwilight_1,
                          &pBrightness->Twilight_1,
                          &pPar->Twilight_1.MinDistTime,
                          eMoveState,
                          /* output */ 
                          &pBrightness->eTwilight_1
                        );

  /* twilight_2 */
  HLABrightnessSetResult( /* input */
                          pBrightness->eTwilight_2,
                          &pBrightness->Twilight_2,
                          &pPar->Twilight_2.MinDistTime,
                          eMoveState,
                          /* output */ 
                          &pBrightness->eTwilight_2
                        );

  /* twilight_3 */  
  HLABrightnessSetResult( /* input */
                          pBrightness->eTwilight_3,
                          &pBrightness->Twilight_3,
                          &pPar->Twilight_3.MinDistTime,
                          eMoveState,
                          /* output */ 
                          &pBrightness->eTwilight_3
                        );
  
  /* night */
  HLABrightnessSetResult( /* input */
                          pBrightness->eNight,
                          &pBrightness->Night,
                          &pPar->Night.MinDistTime,
                          eMoveState,
                          /* output */ 
                          &pBrightness->eNight
                        );

  /* set brightness state */
  HLABrightnessSetState(  /* input */
                          pBrightness,
                          /* output */ 
                          peBrightnessState
                       );
}
