/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_light.c

  DESCRIPTION:            HLA light function.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2011-02-23

  VERSION:                $Revision: 1.1 $
   
  ---*/ /*---
  CHANGE:                 $Log: hlaf_light.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:12CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/light/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:55CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/light/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:38CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/light/project.pj
  CHANGE:                 Revision 1.13 2014/03/25 18:39:48CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_light.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_light.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/light/project.pj.
  CHANGE:                 Revision 1.12 2014/03/10 13:21:11CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:21:12 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.11 2014/02/06 16:02:36CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:36 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.10 2013/12/13 16:45:07CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:08 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.9 2013/08/29 12:39:40CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Disabled almost all internal measfreezes temporary due 15K budget
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 29, 2013 12:39:41 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.8 2013/04/12 12:45:24CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Took more coding parameters into use
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 12, 2013 12:45:25 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.7 2013/04/11 16:21:11CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Implemented some coding parameters
  CHANGE:                 Tunnel is now global turn off reason
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 11, 2013 4:21:11 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.6 2013/03/08 17:43:29CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed HeadlightState and taken RTE type into use
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 5:43:30 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.5 2013/01/18 07:46:00CET Brunn, Marcus (brunnm) 
  CHANGE:                 initial matrix beam version for BMW I210
  CHANGE:                 --- Added comments ---  brunnm [Jan 18, 2013 7:46:01 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.4 2012/07/23 12:58:09CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - code review comments from Humic
  CHANGE:                 --- Added comments ---  uidt9253 [Jul 23, 2012 12:58:09 PM CEST]
  CHANGE:                 Change Package : 94931:1 http://mks-psad:7002/im/viewissue?selection=94931
  CHANGE:                 Revision 1.3 2012/04/23 15:46:50CEST Brunn, Marcus (brunnm) 
  CHANGE:                 KeepOffReason:
  CHANGE:                 - introduced TurnOnDelay_Init, TurnOnDelay_Onc, TurnOnDelay_Prec
  CHANGE:                 --- Added comments ---  brunnm [Apr 23, 2012 3:46:50 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.2 2012/04/21 15:04:32CEST Brunn, Marcus (brunnm) 
  CHANGE:                 introduced first hla light version
  CHANGE:                 --- Added comments ---  brunnm [Apr 21, 2012 3:04:32 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.1 2011/02/24 15:04:31CET Brunn, Marcus (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 
  CHANGE:
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>
#include "hlaf_light.h"
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

/* internal data */
HLAFLightData_t       hlafLightData;

/*****************************************************************************
  FUNCTION 
*****************************************************************************/



/* **************************************************************************** 
  Functionname:     HLAFLightInit                                     */ /*!
  @brief            Initialize HLA light.
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
/* ~CodeReview ~ID:e891c5037832cf9a7f11bfdefbe5d399 ~Reviewer:PC2357\dijkstg ~Date:17-7-2012 ~Priority:3 ~Comment:General: poorly documented function headers. */
void HLAFLightInit(const HLAFParameterLight_t *pPar)
{
  /* init decision data */
  (void)memset((void*)&hlafLightData, 0, sizeof(hlafLightData));

  hlafLightData.KeepOffReason.TurnOnDelay.InitTimer_s = pPar->TurnOnDelay.initialTurnOnDelay;
      
  hlafLightData.Out.eHighBeamState = RTE_HLAF_HB_STATE_OFF; 
}


/* **************************************************************************** 
  Functionname:     HLAFLightMain                                        */ /*!
  @brief            HLA light processing
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAFLightMain( /* input */
                    const HLAF_t_RequiredInputs  *ps_In,
                    const HLAFParameterLight_t   *pPar,
                    const HLAFData_t             *pFData,
                    /* output */
                    HLAFLightOut_t               *pOut
                  )
{
  HLAFLightOut_t LightOut_Next = hlafLightData.Out;
  

  /* HB on time < 3sec -> increase penalty timer +0.5sec */
  HLAFDecisionPenaltyTimer( /* input */
                            hlafLightData.Out.eHighBeamState,
                            pFData->CamData.dtimeFwd_s,
                            /* history/ output */
                            &hlafLightData.PenaltyTimer
                          );

  /* check track list for existing target */
  HLAFDecisionFindRelevantVehicle( /* Input */
                                 ps_In,
                                 pFData,
                                 ps_In->s_Sig.ps_ObjectList,
                                 hlafLightData.Out.eHighBeamState,
                                 /* History/ Output */
                                 &hlafLightData.RelevantVehicle
                               );
  
  /* set turn off reason */
  HLAFDecisionSetTurnOffReason( /* input */
                                &hlafLightData.RelevantVehicle,
                                /* output */
                                &hlafLightData.TurnOffReason
                              );

  /* set keep off reason */
  HLAFDecisionSetKeepOffReason( /* input */
                                ps_In,
                                pFData,
                                &pPar->KeepOff,
                                &pPar->TurnOnDelay,
                                hlafLightData.Out.eHighBeamState,
                                &hlafLightData.RelevantVehicle,
                                &hlafLightData.PenaltyTimer,
                                &hlafLightData.TurnOffReason,
                                /* history, output */
                                &hlafLightData.KeepOffReason
                              );

  /* set HB state {HB on or off} */
  HLAFDecisionSetHBState( /* input */
                          &pFData->DecisionData.TurnOffReason_glob,
                          &hlafLightData.TurnOffReason,
                          &hlafLightData.KeepOffReason,
                          hlafLightData.Out.eHighBeamState,
                          /* output */
                          &LightOut_Next.eHighBeamState
                        );

  /* write data into output struct */
  LightOut_Next.TurnOffReason         = hlafLightData.TurnOffReason.Reason;
  LightOut_Next.KeepOffReason         = hlafLightData.KeepOffReason.Reason;
  LightOut_Next.activatePenaltyTime_s = hlafLightData.PenaltyTimer.activatePenaltyTime_s;

  hlafLightData.Out                   = LightOut_Next; 
  *pOut                               = LightOut_Next;
}

/* ****************************************************************************
  Functionname:     HLAFLightMeasfreeze                          */ /*!
  Description:      send internal hla light data via measfreeze to MTS. 



  @param[in]        

  @pre              -
  @post             -
  @todo             - 
  @author           
**************************************************************************** */
void HLAFLightMeasfreeze(AS_t_MeasHdlr pfMeasFreeze)
{
#ifdef HLA_ENABLE_INTERNAL_MEASFREEZES
  AS_t_MeasInfo HlafLightDataMeasInfo = {HLA_MEAS_VADDR_HLAF_LIGHT, sizeof(hlafLightData), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  (void)pfMeasFreeze(&HlafLightDataMeasInfo, (void*)&hlafLightData, NULL); 
#endif
}/* PRQA S 861 1 */
