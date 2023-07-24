/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_plusspot.c

  DESCRIPTION:            HLA plus decision.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2012-01-26

  VERSION:                $Revision: 1.1 $
   
  ---*/ /*---
  CHANGE:                 $Log: hlaf_plusdecision.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:27CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:08CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:47CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.16 2014/03/25 18:40:37CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_plusdecision.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_plusdecision.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/plus/project.pj.
  CHANGE:                 Revision 1.15 2014/03/19 16:31:00CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:01 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.14 2013/05/03 07:55:56CEST Brunn, Marcus (brunnm) 
  CHANGE:                 fixed LINT/MISRA Errors
  CHANGE:                 --- Added comments ---  brunnm [May 3, 2013 7:55:56 AM CEST]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.13 2013/04/12 12:45:12CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Took more coding parameters into use
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 12, 2013 12:45:12 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.12 2013/03/08 17:43:01CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed HeadlightState and taken RTE type into use
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 5:43:02 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.11 2013/01/18 07:46:02CET Brunn, Marcus (brunnm) 
  CHANGE:                 initial matrix beam version for BMW I210
  CHANGE:                 --- Added comments ---  brunnm [Jan 18, 2013 7:46:03 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.10 2012/07/18 09:21:53CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - added code review tags
  CHANGE:                 --- Added comments ---  brunnm [Jul 18, 2012 9:21:53 AM CEST]
  CHANGE:                 Change Package : 94933:1 http://mks-psad:7002/im/viewissue?selection=94933
  CHANGE:                 Revision 1.9 2012/04/23 15:49:52CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - KeepOffReason: introduced TurnOnDelay_Init, TurnOnDelay_Onc, TurnOnDelay_Prec
  CHANGE:                 - delayed HB turn on after vehicles goes lost
  CHANGE:                 --- Added comments ---  brunnm [Apr 23, 2012 3:49:52 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.8 2012/04/21 15:04:37CEST Brunn, Marcus (brunnm) 
  CHANGE:                 introduced first hla light version
  CHANGE:                 --- Added comments ---  brunnm [Apr 21, 2012 3:04:37 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.7 2012/02/20 16:40:34CET Brunn, Marcus (brunnm) 
  CHANGE:                 hlaf optimization in curvy roads
  CHANGE:                 Revision 1.6 2012/02/13 19:48:08CET Brunn, Marcus (brunnm) 
  CHANGE:                 - HLAFDecisionRelevantVehicle2TurnOff: used ROI borders
  CHANGE:                 - HLAFDecisionTurnOnDelayTTB: long turn on delay for lost preceding cars with low intensity (< 75lx)
  CHANGE:                 Revision 1.5 2012/02/13 15:32:47CET Brunn, Marcus (brunnm) 
  CHANGE:                 - optimized HLAFDecisionTurnOnDelayTTB() for overtaking cars and passed oncoming vehicles 
  CHANGE:                 - HLAFDecisionRelevantVehicle2TurnOff(): check FOV
  CHANGE:                 Revision 1.4 2012/02/13 10:19:21CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed HLAPlusDecision_FindRelevantVehicles()
  CHANGE:                 Revision 1.3 2012/02/13 06:22:37CET Brunn, Marcus (brunnm) 
  CHANGE:                 used relevant traffic flag from extended object list
  CHANGE:                 Revision 1.2 2012/02/06 15:27:43CET Brunn, Marcus (brunnm) 
  CHANGE:                 turn off HB when TTB > 2.0sec and ABS(hor.Angle) < 16°
  CHANGE:                 --- Added comments ---  brunnm [Feb 6, 2012 3:27:44 PM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.1 2012/01/31 06:43:26CET Brunn, Marcus (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 
  CHANGE:                 
  CHANGE:
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_plusdecision.h"
#include "hlaf_decision.h"

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



/* **************************************************************************** 
  Functionname:     HLAPlus2DecisionHBOff2PartHBOn                       */ /*!
  @brief            function returns whether partial high beam could be switched on 
                    (coming from HB off)
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
boolean HLAPlusDecision_HBOff2PartHBOn( eHLAplusHBState_t             eHBState,
                                        const HLAFTurnOffReasonGlob_t TurnOffReason_glob,
                                        HLAplusTurnOffReason_t        TurnOffReason,
                                        HLAplusKeepOffReasonPartHB_t  KeepOffReason_PartHB,
                                        HLAplusKeepOffReasonFullHB_t  KeepOffReason_FullHB
                                      )
{
  boolean b_HBOff2PartHBOn = FALSE;
  

  if(    (eHBState == HLA_PLUS_HB_STATE_OFF)
      && (TurnOffReason_glob.Reason.u32 == 0)
      && (TurnOffReason.Reason.u32 == 0)
      && (KeepOffReason_PartHB.Reason.u32 == 0)
      /* no full HB */
      && (KeepOffReason_FullHB.Reason.u32 > 0)
    )
  {
    b_HBOff2PartHBOn = TRUE;
  }
  else
  {
    b_HBOff2PartHBOn = FALSE;
  }
  return b_HBOff2PartHBOn;
}

/* set relevant vehicle flag */
void HLAPlusDecision_FindRelevantVehicles( const HLAF_t_RequiredInputs *ps_In,
                                           const HLAFData_t            *pFData,
                                           /* output */ 
                                           HLAplusObjectList_t         *pObjListExt
                                         )
{
  uint32 i;
  uint8  numRelevantVeh_lt = 0;
  uint8  numRelevantVeh_rt = 0;
  uint8  numRelevantVeh_NextFrame_lt = 0;
  uint8  numRelevantVeh_NextFrame_rt = 0;


  /* relevant vehicle detected ?    */
  /* vehicle outside function ROI ? */
  for(i=0; i< ps_In->s_Sig.ps_ObjectList->ui32_NumVehicles; i++)
  {
    HLA_t_Object        *pObj       = &ps_In->s_Sig.ps_ObjectList->as_Object[i];
    HLAplusObjectData_t *pObjExt_lt = &pObjListExt->Left.Obj[i];
    HLAplusObjectData_t *pObjExt_rt = &pObjListExt->Right.Obj[i];
    boolean             bRelevantVehicle_left, bRelevantVehicle_right;
    float32             RoiAngLeft, RoiAngRight;

    /* vehicle outside function ROI ? */
    if(   (pObj->si16_xcenter <= ps_In->s_Sig.ps_ObjectList->s_ObjectRoi.ui16_RoiX1)
       || (pObj->si16_xcenter >= ps_In->s_Sig.ps_ObjectList->s_ObjectRoi.ui16_RoiX2)
       || (pObj->si16_ycenter <= ps_In->s_Sig.ps_ObjectList->s_ObjectRoi.ui16_RoiYu)
       || (pObj->si16_ycenter >= ps_In->s_Sig.ps_ObjectList->s_ObjectRoi.ui16_RoiY2)
      )
    {
      pObjExt_rt->Status.isOutsideFunctRoi = 1;
      pObjExt_lt->Status.isOutsideFunctRoi = 1;
    }
    else
    {
      pObjExt_rt->Status.isOutsideFunctRoi = 0;
      pObjExt_lt->Status.isOutsideFunctRoi = 0;
    }
    
    
    /* set region of interest for relevant traffic          */
    /* vehicles within this region will be relevant traffic */
    /* - independent of TTB and object angle                */
    /* - region only used for partial HB and spot light     */
    /* ~CodeReview ~ID:392686d881713807e9da4e4d06913531 ~Reviewer:CW01\uidu4053 ~Date:17.07.2012 ~Priority:3 ~Comment:Replace magic numbers with parameters. */
    if(   (pFData->HLAPlusOut.eHighBeamState_Lt == RTE_HLAF_HB_STATE_PARTIAL)
       && (pFData->HLAPlusOut.eHighBeamState_Rt == RTE_HLAF_HB_STATE_PARTIAL)
      )
    {
      RoiAngLeft  = pFData->HLAPlusOut.RotAngleMin_Lt + CML_Deg2Rad(3.0f);
      RoiAngRight = pFData->HLAPlusOut.RotAngleMin_Rt - CML_Deg2Rad(3.0f);
    }
    else if(pFData->HLAPlusOut.eHighBeamState_Lt == RTE_HLAF_HB_STATE_PARTIAL)
    {
      RoiAngLeft  = pFData->HLAPlusOut.RotAngleMin_Lt + CML_Deg2Rad(3.0f);
      RoiAngRight = -CML_Deg2Rad(90.0f);
    }       
    else if(pFData->HLAPlusOut.eHighBeamState_Rt == RTE_HLAF_HB_STATE_PARTIAL)
    {
      RoiAngLeft  = CML_Deg2Rad(90.0f);
      RoiAngRight = pFData->HLAPlusOut.RotAngleMin_Rt - CML_Deg2Rad(3.0f);
    }
    else
    {
      /* unused */
      RoiAngLeft  = 0.0f;
      RoiAngRight = 0.0f;
    }
    /* left side */
    bRelevantVehicle_left = HLAFDecisionRelevantVehicle2TurnOff( /* input */
                                                                 pFData->HLAPlusOut.eHighBeamState_Lt,
                                                                 pObj,
                                                                 pFData,
                                                                 &ps_In->s_Par.s_HlafPar.TurnOff,
                                                                 /* horizontal FOV */
                                                                 &ps_In->s_Sig.ps_ObjectList->s_ObjectRoi,
                                                                 /* Region of interest for relevant traffic              */
                                                                 /* vehicles within this region will be relevant traffic */
                                                                 /* - independent of TTB and object angle                */
                                                                 /* - region only used for partial HB and spot light     */
                                                                 RoiAngLeft,
                                                                 RoiAngRight
                                                               );
    if(bRelevantVehicle_left == b_TRUE)
    {
      pObjExt_lt->Status.isRelevantTraffic = 1;
      numRelevantVeh_lt++;
      if(pObj->s_Status.willBeRemoved == 0)
      {
        numRelevantVeh_NextFrame_lt++;
      }
    }
    /* right side */
    bRelevantVehicle_right = HLAFDecisionRelevantVehicle2TurnOff( /* input */
                                                                  pFData->HLAPlusOut.eHighBeamState_Rt,
                                                                  pObj,
                                                                  pFData,
                                                                  &ps_In->s_Par.s_HlafPar.TurnOff,
                                                                  /* horizontal FOV */
                                                                  &ps_In->s_Sig.ps_ObjectList->s_ObjectRoi,
                                                                  /* Region of interest for relevant traffic              */
                                                                  /* vehicles within this region will be relevant traffic */
                                                                  /* - independent of TTB and object angle                */
                                                                  /* - region only used for partial HB and spot light     */
                                                                  RoiAngLeft,
                                                                  RoiAngRight
                                                                );
    if(bRelevantVehicle_right == b_TRUE)
    {
      pObjExt_rt->Status.isRelevantTraffic = 1;
      numRelevantVeh_rt++;
      if(pObj->s_Status.willBeRemoved == 0)
      {
        numRelevantVeh_NextFrame_rt++;
      }
    }
  }

  pObjListExt->Left.numRelevantVehicles  = numRelevantVeh_lt;
  pObjListExt->Right.numRelevantVehicles = numRelevantVeh_rt;

  pObjListExt->Left.numRelevantVehiclesNextFrame  = numRelevantVeh_NextFrame_lt;
  pObjListExt->Right.numRelevantVehiclesNextFrame = numRelevantVeh_NextFrame_rt;
}
