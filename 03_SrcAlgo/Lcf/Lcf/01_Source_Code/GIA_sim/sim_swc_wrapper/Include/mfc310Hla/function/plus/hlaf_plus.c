/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_plus.c

  DESCRIPTION:            HLA plus function.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2011-02-23

  VERSION:                $Revision: 1.1 $
   
  ---*/ /*---
  CHANGE:                 $Log: hlaf_plus.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:26CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:39:04CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:44CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGE:                 Revision 1.109 2014/03/26 11:27:29CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed some mandatory QAC warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 26, 2014 11:27:29 AM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.108 2014/03/25 18:40:37CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_plus.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_plus.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/plus/project.pj.
  CHANGE:                 Revision 1.107 2014/03/19 16:31:33CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:34 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.106 2014/03/04 16:52:24CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:25 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.105 2014/03/04 12:58:51CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Support for I390 RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 12:58:52 PM CET]
  CHANGE:                 Change Package : 207432:32 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.104 2014/01/21 09:12:56CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added a few more checks for devision of zero
  CHANGE:                 Removed some PC_SIM code that is no longer needed
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 21, 2014 9:12:57 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.103 2013/12/13 16:44:51CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:44:51 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.102 2013/08/29 12:39:41CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Disabled almost all internal measfreezes temporary due 15K budget
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 29, 2013 12:39:42 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.101 2013/07/09 20:02:13CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - removed unused hlaf_plusspot
  CHANGE:                 - fixed changeoverlevel for oncoming vehicles
  CHANGE:                 --- Added comments ---  brunnm [Jul 9, 2013 8:02:13 PM CEST]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.100 2013/05/23 10:31:02CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed PC-LINT errors
  CHANGE:                 --- Added comments ---  uidv7867 [May 23, 2013 10:31:03 AM CEST]
  CHANGE:                 Change Package : 167173:30 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.99 2013/05/06 14:42:32CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed compile errors
  CHANGE:                 --- Added comments ---  uidv7867 [May 6, 2013 2:42:32 PM CEST]
  CHANGE:                 Change Package : 167173:30 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.98 2013/04/25 11:00:02CEST Brunn, Marcus (brunnm) 
  CHANGE:                 implemented hla plus configuration switch 
  CHANGE:                 implemented TurnOffLeft_OncOnly, TurnOffLeft_LeftOnly, KeepOffLeft_LeftOnly and AsymmetricMode
  CHANGE:                 --- Added comments ---  brunnm [Apr 25, 2013 11:00:03 AM CEST]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.97 2013/04/12 12:45:09CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Took more coding parameters into use
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 12, 2013 12:45:09 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.96 2013/04/11 16:20:52CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Implemented some coding parameters
  CHANGE:                 Tunnel is now global turn off reason
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 11, 2013 4:20:52 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.95 2013/03/11 14:32:50CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Placed no longer needed by RTE ones
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eLightOutput
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 2:32:50 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.94 2013/03/08 17:42:57CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed HeadlightState and taken RTE type into use
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 5:42:58 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.93 2013/03/08 10:30:08CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 10:30:09 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.92 2013/01/22 16:38:41CET Brunn, Marcus (brunnm) 
  CHANGE:                 introduced RTE like types for 
  CHANGE:                 - HLA_t_eState
  CHANGE:                 - HLA_t_eLevelState
  CHANGE:                 - HLA_t_eLightOutput
  CHANGE:                 --- Added comments ---  brunnm [Jan 22, 2013 4:38:42 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.91 2013/01/21 13:39:06CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed misra/ lint errors
  CHANGE:                 --- Added comments ---  brunnm [Jan 21, 2013 1:39:06 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.90 2013/01/18 07:46:01CET Brunn, Marcus (brunnm) 
  CHANGE:                 initial matrix beam version for BMW I210
  CHANGE:                 --- Added comments ---  brunnm [Jan 18, 2013 7:46:01 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.89 2012/11/15 09:56:50CET Brunn, Marcus (brunnm) 
  CHANGE:                 interface update for MFC4B0, BMW I210 (without RTE)
  CHANGE:                 --- Added comments ---  brunnm [Nov 15, 2012 9:56:51 AM CET]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.88 2012/09/24 11:28:51CEST Brunn, Marcus (brunnm) 
  CHANGE:                 hlaf plus: introduced road type depending turn on delay (partial HB -> full HB: highway = 5sec, country road = 1sec)
  CHANGE:                 --- Added comments ---  brunnm [Sep 24, 2012 11:28:52 AM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.87 2012/07/23 12:57:51CEST Zechner, Stefan (uidt9253) 
  CHANGE:                 - code review comments from Humic
  CHANGE:                 --- Added comments ---  uidt9253 [Jul 23, 2012 12:57:51 PM CEST]
  CHANGE:                 Change Package : 94931:1 http://mks-psad:7002/im/viewissue?selection=94931
  CHANGE:                 Revision 1.86 2012/07/18 07:51:45CEST Brunn, Marcus (brunnm) 
  CHANGE:                 - added code review tags
  CHANGE:                 --- Added comments ---  brunnm [Jul 18, 2012 7:51:45 AM CEST]
  CHANGE:                 Change Package : 94933:1 http://mks-psad:7002/im/viewissue?selection=94933
  CHANGE:                 Revision 1.85 2012/06/18 09:03:41CEST Brunn, Marcus (brunnm) 
  CHANGE:                 bugfix: synchronize left and right change over level
  CHANGE:                 --- Added comments ---  brunnm [Jun 18, 2012 9:03:42 AM CEST]
  CHANGE:                 Change Package : 129211:1 http://mks-psad:7002/im/viewissue?selection=129211
  CHANGE:                 Revision 1.84 2012/04/23 21:01:40CEST Brunn, Marcus (brunnm) 
  CHANGE:                 used si16_delta_x instead of si16_delta_x_lp
  CHANGE:                 --- Added comments ---  brunnm [Apr 23, 2012 9:01:40 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.83 2012/04/23 20:19:06CEST Brunn, Marcus (brunnm) 
  CHANGE:                 reduced partial blinding of preceding cars in curvy situations
  CHANGE:                 --- Added comments ---  brunnm [Apr 23, 2012 8:19:07 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.82 2012/04/21 15:04:33CEST Brunn, Marcus (brunnm) 
  CHANGE:                 introduced first hla light version
  CHANGE:                 --- Added comments ---  brunnm [Apr 21, 2012 3:04:34 PM CEST]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.81 2012/03/23 11:36:14CET Brunn, Marcus (brunnm) 
  CHANGE:                 introduced forward driving distance and time (dtimeFwd_s, ddistFwd_m),
  CHANGE:                 time and distance will only be set while driving forwards and 0 while driving backwards
  CHANGE:                 --- Added comments ---  brunnm [Mar 23, 2012 11:36:14 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.80 2012/03/14 08:51:41CET Brunn, Marcus (brunnm) 
  CHANGE:                 left hand driving bugfix: copy hla plus output into internal data struct before mirroring
  CHANGE:                 --- Added comments ---  brunnm [Mar 14, 2012 8:51:41 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.79 2012/03/13 10:09:13CET Brunn, Marcus (brunnm) 
  CHANGE:                 check if VehOutermost_Alive is present before using the detailed data
  CHANGE:                 --- Added comments ---  brunnm [Mar 13, 2012 10:09:14 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.78 2012/03/12 07:27:34CET Brunn, Marcus (brunnm) 
  CHANGE:                 removed use of global variable (hlafPlusData)
  CHANGE:                 --- Added comments ---  brunnm [Mar 12, 2012 7:27:34 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.77 2012/03/12 06:05:48CET Brunn, Marcus (brunnm) 
  CHANGE:                 Endland test drive fixes
  CHANGE:                 - change over level (full HB -> off)
  CHANGE:                 --- Added comments ---  brunnm [Mar 12, 2012 6:05:48 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.76 2012/02/23 16:42:05CET Brunn, Marcus (brunnm) 
  CHANGE:                 - fixed some issues for left hand traffic
  CHANGE:                 - increased HB turn on delay when wiper is on stage 6
  CHANGE:                 - symmetric light style: hla plus only available when the traffic style is verified during current ignition cycle
  CHANGE:                 - increased HLA plus safety angle (cut off angle) when the camera is not online calibrated
  CHANGE:                 Revision 1.75 2012/02/20 16:40:33CET Brunn, Marcus (brunnm) 
  CHANGE:                 hlaf optimization in curvy roads
  CHANGE:                 Revision 1.74 2012/02/13 06:20:14CET Brunn, Marcus (brunnm) 
  CHANGE:                 used relevant vehicle flag from extended object list
  CHANGE:                 --- Added comments ---  brunnm [Feb 13, 2012 6:20:17 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.73 2012/02/08 16:57:49CET Brunn, Marcus (brunnm) 
  CHANGE:                 - fixed detection of relevant traffic
  CHANGE:                 - hla plus: fast HB on when oncoming traffic passed
  CHANGE:                 --- Added comments ---  brunnm [Feb 8, 2012 4:57:50 PM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 Revision 1.72 2012/02/07 13:24:57CET Brunn, Marcus (brunnm) 
  CHANGE:                 changed change over level for HB off -> partial HB on from 4 to 2
  CHANGE:                 Revision 1.71 2012/02/06 15:27:41CET Brunn, Marcus (brunnm) 
  CHANGE:                 turn off HB when TTB > 2.0sec and ABS(hor.Angle) < 16°
  CHANGE:                 Revision 1.70 2012/01/31 06:39:45CET Brunn, Marcus (brunnm) 
  CHANGE:                 restructuring of HLAF Plus
  CHANGE:                 --- Added comments ---  brunnm [Jan 31, 2012 6:39:45 AM CET]
  CHANGE:                 Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGE:                 
  CHANGE:
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>
#include "hlaf_decision.h"
#include "hlaf_plus.h"
#include "hlaf_plusturnoff.h"
#include "hlaf_pluskeepoff.h"
#include "hlaf_plusangle.h"
#include "hlaf_plusdecision.h"
#include "hlaf_plusregion.h"


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
HLA_GLOBAL_STATIC HLAplusInputData_t  hlafPlusInput;
HLAplusData_t                         hlafPlusData;

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static void HLAPlusSetChangeOverLevel( HLAplusTurnOffReason_Reason_t TurnOffReason,
                                       const HLAFData_t              *pFData,
                                       const HLAFParameter_t         *pFPar,
                                       sint16                        *pChangeOverLevel,
                                       eHLAplusHBState_t             eHBState,
                                       eHLAplusHBState_t             eHBStatePre, 
                                       const HLAplusOutermostData_t  *pOutermost,
                                       const eHLAplusHeadlamp_t      eHeadlamp
                                     );
static void HLAPlusSyncChangeOverLevel( /* input */
                                        const HLAplusHBState_t *pHBState,
                                        /* output */
                                        HLAplusChangeOverLevel_t *pChangeOverLevel
                                      );
static void HLAPlusSetDecHBState( /* input */
                                  const HLAFTurnOffReasonGlob_t       TurnOffReason_Glob,
                                  const HLAplusTurnOffReason_t       TurnOffReasonPartHB,
                                  const HLAplusTurnOffReasonFullHB_t TurnOffReasonFullHB,
                                  const HLAplusKeepOffReasonPartHB_t KeepOffReasonPartHB,
                                  const HLAplusKeepOffReasonFullHB_t KeepOffReasonFullHB,
                                  /* output */ 
                                  eHLAplusHBState_t          *peState,
                                  uint32                              *pHBStateCnt,
                                  eHLAplusHBState_t          *peStatePre
                                );
static void HLAPlusFillInputData( const HLA_t_HeadlightState *pHeadlightState, 
                                  const HLAFTrafficStyleOut_t *pTrafficStyle
                                );
static void HLAPlusFindOutermostVehicle( /* input */
                                         const HLAF_t_RequiredInputs *pIn,
                                         const HLAplusData_t  *pPlusData,
                                         const HLAFTrafficStyleOut_t *pTrafficStyle,
                                         /* output */
                                         HLAplusOutermost_t          *pOutermost
                                       );
static void HLAPlusInitData(void);
static void HLAPlusInitOutput(HLAFPlusOut_t *pPlusOut);
static void HLAFPlusSetHBState( /* input */
                                const eHLAplusHBState_t  eHBState,
                                /* output */
                                RTE_HLAF_HighBeamState   *peHBState_out
                              );
static void HLAFPlusSetLightOutput( /* input */
                                    const  RTE_HLAF_HighBeamState  eHBState,
                                    /* output */
                                    RTE_HLAF_LightOutput          *pLightOutput
                                  );




/* **************************************************************************** 
  Functionname:     HLAFPlusSetHBState                            */ /*!
  @brief            Set Highbeam state.
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAFPlusSetHBState( /* input */
                                const eHLAplusHBState_t  eHBState,
                                /* output */
                                RTE_HLAF_HighBeamState   *peHBState_out
                              )
{

  switch(eHBState)
  {
    /* high beam off */
    case HLA_PLUS_HB_STATE_INIT:
    case HLA_PLUS_HB_STATE_INIT_2_OFF:
    case HLA_PLUS_HB_STATE_FULL_2_OFF:
    case HLA_PLUS_HB_STATE_PART_2_OFF:
    case HLA_PLUS_HB_STATE_OFF:
      *peHBState_out = RTE_HLAF_HB_STATE_OFF;
      break;

    /* (full) high beam on */
    case HLA_PLUS_HB_STATE_OFF_2_FULL_ON:
    case HLA_PLUS_HB_STATE_PART_2_FULL_ON: 
    case HLA_PLUS_HB_STATE_FULL_ON:
      *peHBState_out            = RTE_HLAF_HB_STATE_FULL_ON;
      break;
    
    /* partial high beam on */
    case HLA_PLUS_HB_STATE_OFF_2_PART_ON:
    case HLA_PLUS_HB_STATE_FULL_2_PART_ON:
    case HLA_PLUS_HB_STATE_PART_ON:
      *peHBState_out              = RTE_HLAF_HB_STATE_PARTIAL;
      break;

    default:
      *peHBState_out              = RTE_HLAF_HB_STATE_OFF;
      break;
  }
}

/* **************************************************************************** 
  Functionname:     HLAFPlusSetHBState                            */ /*!
  @brief            Set light output power.
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAFPlusSetLightOutput( /* input */
                                    const  RTE_HLAF_HighBeamState  eHBState,
                                    /* output */
                                    RTE_HLAF_LightOutput          *pLightOutput
                                  )
{
  switch(eHBState)
  {
    /* high beam off */
    case RTE_HLAF_HB_STATE_OFF:
      *pLightOutput = RTE_HLAF_LIGHTOUTPUT_STD;
      break;

    /* (full) high beam on */
    case RTE_HLAF_HB_STATE_FULL_ON:
      *pLightOutput = RTE_HLAF_LIGHTOUTPUT_MAX;
      break;
    
    /* partial high beam on */
    case RTE_HLAF_HB_STATE_PARTIAL:
      *pLightOutput = RTE_HLAF_LIGHTOUTPUT_MAX;
      break;

      /* spot on */
    case RTE_HLAF_HB_STATE_SPOT:
      *pLightOutput = RTE_HLAF_LIGHTOUTPUT_MAX;
      break;

    case RTE_HLAF_HB_STATE_INVALID:
    default:
      *pLightOutput = RTE_HLAF_LIGHTOUTPUT_STD;
      break;
  }
}


/* **************************************************************************** 
  Functionname:     HLAPlus2InitData                                     */ /*!
  @brief            initializes data
  @description      initializes data
                    
  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAPlusInitData(void)
{
  (void)memset((void*)&hlafPlusData, 0, sizeof(HLAplusData_t));

  /* ~CodeReview ~ID:37295e20e0379f41a9a6ccd3df261c75 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
  hlafPlusData.ChangeOverLevel.Left  = 4;
  hlafPlusData.ChangeOverLevel.Right = 4;

  hlafPlusData.HBAngle.Left.eState  = HLA_PLUS_ANG_FOLLOW_CURVEANG;
  hlafPlusData.HBAngle.Right.eState = HLA_PLUS_ANG_FOLLOW_CURVEANG;
  
}

/* **************************************************************************** 
  Functionname:     HLAPlusInitOutput                                    */ /*!
  @brief            initializes output data
  @description      initializes output data
                    
  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAPlusInitOutput(HLAFPlusOut_t *pPlusOut)
{
  pPlusOut->eHighBeamState_Lt = RTE_HLAF_HB_STATE_OFF;
  pPlusOut->eHighBeamState_Rt = RTE_HLAF_HB_STATE_OFF;
  pPlusOut->eLightOutput_Lt   = RTE_HLAF_LIGHTOUTPUT_STD;
  pPlusOut->eLightOutput_Rt   = RTE_HLAF_LIGHTOUTPUT_STD;
}


/* **************************************************************************** 
  Functionname:     HLAPlus2FindOutermostVehicle                        */ /*!
  @brief            find outermost left/ right vehicle
  @description       
                    

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAPlusFindOutermostVehicle( /* input */
                                         const HLAF_t_RequiredInputs *pIn,
                                         const HLAplusData_t         *pPlusData,
                                         const HLAFTrafficStyleOut_t *pTrafficStyle,
                                         /* output */
                                         HLAplusOutermost_t          *pOutermost
                                       )
{
  float32       AngOutermost_left, AngOutermost_Alive_left;
  float32       AngOutermost_right, AngOutermost_Alive_right;
  HLA_t_Object  *pVehOutermost_left, *pVehOutermost_Alive_left;
  HLA_t_Object  *pVehOutermost_right, *pVehOutermost_Alive_right;
  float32       Ang_min, Ang_max;
  float32       predictionCycles_Left_Oncom;
  float32       predictionCycles_Left_Preced;
  float32       predictionCycles_Right_Oncom;
  float32       predictionCycles_Right_Preced;
  float32       dAng2dx = 1.0f/CML_f_Max(1.0f, pIn->s_Par.ps_CameraParameter->s_FocalLength.f32_x);
  uint32        i;
  

  /* save current outermost data */
  if(pOutermost->Left.bVehDet == TRUE)
  {
    pOutermost->PrevVeh_left = pOutermost->Left;
  }
  if(pOutermost->Right.bVehDet == TRUE)
  {
    pOutermost->PrevVeh_right = pOutermost->Right;
  }
  
 
  /* reset outermost vehicle output */
  (void)memset((void*)&pOutermost->Left,  0, sizeof(HLAplusOutermostData_t));
  (void)memset((void*)&pOutermost->Right, 0, sizeof(HLAplusOutermostData_t));
  pOutermost->Left.VehOutermost.ui8_Id        = UI8_T_MAX;
  pOutermost->Left.VehOutermost_Alive.ui8_Id  = UI8_T_MAX;
  pOutermost->Right.VehOutermost.ui8_Id       = UI8_T_MAX;
  pOutermost->Right.VehOutermost_Alive.ui8_Id = UI8_T_MAX;

    
  /* initialize variables */
  /* ~CodeReview ~ID:253890b1244a47164da8da7a2cac5ece ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
  AngOutermost_left         = -CML_Deg2Rad(90.0f);
  AngOutermost_Alive_left   = -CML_Deg2Rad(90.0f);

  AngOutermost_right        =  CML_Deg2Rad(90.0f);
  AngOutermost_Alive_right  =  CML_Deg2Rad(90.0f);
  
  pVehOutermost_left        = NULL;
  pVehOutermost_right       = NULL;
  pVehOutermost_Alive_left  = NULL;
  pVehOutermost_Alive_right = NULL;

  
  /* init prediction cycles */
  /* Division by 0 not possible as these values are checked beginning of HLAR_v_Exec() */
  predictionCycles_Left_Oncom   = hlafPlusParameter.Left.PredictionTime_Oncom_s  / pIn->s_Par.ps_CameraParameter->f32_cycleTime;
  predictionCycles_Left_Preced  = hlafPlusParameter.Left.PredictionTime_Preced_s / pIn->s_Par.ps_CameraParameter->f32_cycleTime;
  predictionCycles_Right_Oncom  = hlafPlusParameter.Right.PredictionTime_Oncom_s / pIn->s_Par.ps_CameraParameter->f32_cycleTime;
  predictionCycles_Right_Preced = hlafPlusParameter.Right.PredictionTime_Preced_s/ pIn->s_Par.ps_CameraParameter->f32_cycleTime;

 
  /* search the outermost vehicle left/ right */
  for(i=0; i< CML_Min(RTE_HLAR_OBJECT_LIST_LENGTH, pIn->s_Sig.ps_ObjectList->ui32_NumVehicles); i++)
  {
    HLA_t_Object *pObj = &pIn->s_Sig.ps_ObjectList->as_Object[i];
    const HLAplusObjectData_t *pObjExt_lt = &pPlusData->Object.Left.Obj[i];
    const HLAplusObjectData_t *pObjExt_rt = &pPlusData->Object.Right.Obj[i];
    /* traffic style normalized object angle */
    float32 ObjAng_norm = pTrafficStyle->NormFactor * pObj->f32_ObjectHorAng_rad; 

    
    if(pObj->s_Status.isVehicleAhead == 1)
    {
      /* preceding traffic */
      /* right side  */
      Ang_min = CML_f_Min(ObjAng_norm, (ObjAng_norm - ((predictionCycles_Right_Preced * dAng2dx) * pObj->si16_delta_x)));
      /* left side */
      Ang_max = CML_f_Max(ObjAng_norm, (ObjAng_norm - ((predictionCycles_Left_Preced * dAng2dx) * pObj->si16_delta_x)));
    }
    else
    {
      /* oncoming traffic */
      /* right side  */
      Ang_min = CML_f_Min(ObjAng_norm, (ObjAng_norm - ((predictionCycles_Right_Oncom * dAng2dx) * pObj->si16_delta_x)));
      /* left side */
      Ang_max = CML_f_Max(ObjAng_norm, (ObjAng_norm - ((predictionCycles_Left_Oncom * dAng2dx) * pObj->si16_delta_x)));
    }


    /* left side */
    if(pObjExt_lt->Status.isRelevantTraffic == 1)
    {
      /* relevant traffic */
      /**************************/
      /* lost or alive vehicles */
      /**************************/
      /* new outermost left     */
      if(Ang_max > AngOutermost_left)
      {
        pVehOutermost_left  = pObj;
        AngOutermost_left   = Ang_max;
      }
      /***********************/
      /* only alive vehicles */
      /***********************/
      if(pObj->ui8_lost_time == 0)
      {
        /* new outermost left  */
        if(Ang_max > AngOutermost_Alive_left)
        {
          pVehOutermost_Alive_left  = pObj;
          AngOutermost_Alive_left   = Ang_max;
        }
      }
    }
    /* right side */
    if(pObjExt_rt->Status.isRelevantTraffic == 1)
    {
      /* relevant traffic */
      /**************************/
      /* lost or alive vehicles */
      /**************************/
      /* new outermost right */
      if(Ang_min < AngOutermost_right)
      {
        pVehOutermost_right = pObj;
        AngOutermost_right  = Ang_min;
      }
      /***********************/
      /* only alive vehicles */
      /***********************/
      if(pObj->ui8_lost_time == 0)
      {
        /* new outermost right */
        if(Ang_min < AngOutermost_Alive_right)
        {
          pVehOutermost_Alive_right = pObj;
          AngOutermost_Alive_right  = Ang_min;
        }
      }
    }
  }

  if(pVehOutermost_left != NULL)
  {
    pOutermost->Left.bVehDet            = TRUE;
    pOutermost->Left.AngOutermostPred   = AngOutermost_left;
    pOutermost->Left.VehOutermost       = *pVehOutermost_left;
  }
  if(pVehOutermost_right != NULL)
  {
    pOutermost->Right.bVehDet           = TRUE;
    pOutermost->Right.AngOutermostPred  = AngOutermost_right;
    pOutermost->Right.VehOutermost      = *pVehOutermost_right;
  }
  if(pVehOutermost_Alive_left != NULL)
  {
    pOutermost->Left.bVehDet_Alive          = TRUE;
    pOutermost->Left.AngOutermostPred_Alive = AngOutermost_Alive_left;
    pOutermost->Left.VehOutermost_Alive     = *pVehOutermost_Alive_left;
  }
  if(pVehOutermost_Alive_right != NULL)
  {
    pOutermost->Right.bVehDet_Alive           = TRUE;
    pOutermost->Right.AngOutermostPred_Alive  = AngOutermost_Alive_right;
    pOutermost->Right.VehOutermost_Alive      = *pVehOutermost_Alive_right;
  }  
}

/* **************************************************************************** 
  Functionname:     HLAPlus2DecisionSetHBStateLR                         */ /*!
  @brief            HLA plus 2 set high beam state for left/right headlamps
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAPlusSetDecHBState( /* input */
                                  const HLAFTurnOffReasonGlob_t      TurnOffReason_Glob,
                                  const HLAplusTurnOffReason_t       TurnOffReasonPartHB,
                                  const HLAplusTurnOffReasonFullHB_t TurnOffReasonFullHB,
                                  const HLAplusKeepOffReasonPartHB_t KeepOffReasonPartHB,
                                  const HLAplusKeepOffReasonFullHB_t KeepOffReasonFullHB,
                                  /* output */
                                  eHLAplusHBState_t                  *peState,
                                  uint32                             *pHBStateCnt,
                                  eHLAplusHBState_t                  *peStatePre
                                )
{
  boolean b_HBOff2PartHBOn;


  /* check whether the partial HB could be switched on (coming from HB off) */
  b_HBOff2PartHBOn = HLAPlusDecision_HBOff2PartHBOn( *peState,
                                                     TurnOffReason_Glob,
                                                     TurnOffReasonPartHB,
                                                     KeepOffReasonPartHB,
                                                     KeepOffReasonFullHB
                                                    );


  switch(*peState)
  {
    case HLA_PLUS_HB_STATE_INIT:
      *peStatePre = HLA_PLUS_HB_STATE_INIT;
      *peState    = HLA_PLUS_HB_STATE_INIT_2_OFF;
      *pHBStateCnt = 0;
      break;

    /* high beam off => low beam */
    case HLA_PLUS_HB_STATE_INIT_2_OFF:
    case HLA_PLUS_HB_STATE_FULL_2_OFF:
    case HLA_PLUS_HB_STATE_PART_2_OFF:
    case HLA_PLUS_HB_STATE_OFF:

      /* switch partial HB on ? */
      if(b_HBOff2PartHBOn == TRUE)
      {
        /* partial high beam on */
        *peStatePre = HLA_PLUS_HB_STATE_OFF;
        *peState    = HLA_PLUS_HB_STATE_OFF_2_PART_ON;
        *pHBStateCnt = 0;
      }
      /* switch full HB on ? */
      else if(    (KeepOffReasonFullHB.Reason.u32  == 0)
               && (TurnOffReasonFullHB.Reason.u32 == 0)
             )
      {
        /* no relevant object detected at all */
        /* switch high beam on */
        *peStatePre = HLA_PLUS_HB_STATE_OFF;
        *peState    = HLA_PLUS_HB_STATE_OFF_2_FULL_ON;
        *pHBStateCnt = 0;
      }
      else
      {
        /* keep high beam disabled */
        *peState = HLA_PLUS_HB_STATE_OFF;    
      }
      break;

    /* (full) high beam on */
    case HLA_PLUS_HB_STATE_OFF_2_FULL_ON:
    case HLA_PLUS_HB_STATE_PART_2_FULL_ON:
    case HLA_PLUS_HB_STATE_FULL_ON:
      if(   (TurnOffReasonFullHB.Reason.u32 == 0)
         && (TurnOffReason_Glob.Reason.u32  == 0)
        )
      {
        /* no relevant object detected at all                 */
        /* and no global turn off reason (e.g. city detected) */
        /* keep high beam on */
        *peState = HLA_PLUS_HB_STATE_FULL_ON;
      }
      else if(   (TurnOffReason_Glob.Reason.u32 > 0)
              || (TurnOffReasonPartHB.Reason.u32 > 0)
        )
      {
        *peStatePre = HLA_PLUS_HB_STATE_FULL_ON;
        *peState    = HLA_PLUS_HB_STATE_FULL_2_OFF;
        *pHBStateCnt = 0;
      }
      else
      {
        /* partial HB on */
        *peStatePre = HLA_PLUS_HB_STATE_FULL_ON;
        *peState    = HLA_PLUS_HB_STATE_FULL_2_PART_ON;
        *pHBStateCnt = 0;
      }
      
      break;

    /* partial high beam on */
    case HLA_PLUS_HB_STATE_OFF_2_PART_ON:
    case HLA_PLUS_HB_STATE_FULL_2_PART_ON:
    case HLA_PLUS_HB_STATE_PART_ON:
      if(   (TurnOffReason_Glob.Reason.u32 > 0)
         || (TurnOffReasonPartHB.Reason.u32 > 0)
        )
      {
        /* disable partial high beam */
        *peStatePre = HLA_PLUS_HB_STATE_PART_ON;
        *peState    = HLA_PLUS_HB_STATE_PART_2_OFF;
        *pHBStateCnt = 0;
      }
      /* wait until HLA wants to switch the high beam on */
      else if(    (KeepOffReasonFullHB.Reason.u32 == 0)
               && (TurnOffReasonFullHB.Reason.u32 == 0)
             )
      {
        /* no relevant object detected at all */
        /* switch high beam on */
        *peStatePre = HLA_PLUS_HB_STATE_PART_ON;
        *peState    = HLA_PLUS_HB_STATE_PART_2_FULL_ON;
        *pHBStateCnt = 0;
      }
      else
      {
        /* stay in partial high beam on */
        *peState = HLA_PLUS_HB_STATE_PART_ON;    
      }
      break;
      
    default:
      *peState = HLA_PLUS_HB_STATE_OFF;
      break;
  }

  if(*pHBStateCnt < SI32_T_MAX)
  {
    *pHBStateCnt = *pHBStateCnt + 1;
  }
}


/* **************************************************************************** 
  Functionname:     HLAPlus2DecisionSetChangeOverLevelLR                 */ /*!
  @brief            
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAPlusSetChangeOverLevel( HLAplusTurnOffReason_Reason_t TurnOffReason,
                                       const HLAFData_t              *pFData,
                                       const HLAFParameter_t         *pFPar,
                                       sint16                        *pChangeOverLevel,
                                       eHLAplusHBState_t             eHBState,
                                       eHLAplusHBState_t             eHBStatePre, 
                                       const HLAplusOutermostData_t  *pOutermost,
                                       const eHLAplusHeadlamp_t      eHeadlamp
                                     )
{
  float32 Sign;
  float32 TrafficStyle_NormFactor = pFData->DecisionOut.TrafficStyle.NormFactor;
  
  /* mirror angles/ delta_x for left headlamp */
  if(eHeadlamp == HLA_PLUS_LEFT_HEADLAMP)
  {
    /* left headlamp */
    Sign = -1.0f;  
  }
  else
  {
    /* right headlamp */
    Sign = 1.0f;
  }  

  switch(eHBState)
  {
    /* init -> off */
    case HLA_PLUS_HB_STATE_INIT_2_OFF:
      *pChangeOverLevel = (sint16)(0.5f * (pFPar->HLAStandard.ChangeOverLevel.TurnOffLow + 1));
      break;

    /* HB off -> HB */
    case HLA_PLUS_HB_STATE_OFF_2_FULL_ON:
      *pChangeOverLevel = (sint16)(0.5f * (pFPar->HLAStandard.ChangeOverLevel.TurnOnHigh + 1));
      break;

    /* Part HB -> HB */
    case HLA_PLUS_HB_STATE_PART_2_FULL_ON:
      *pChangeOverLevel = (sint16)(0.5f * (pFPar->HLAStandard.ChangeOverLevel.TurnOnHigh + 1));
      break;

    /* ~CodeReview ~ID:a61448db5bd30e0161331ccaf9af0d3f ~Reviewer:CW01\uidv0771 ~Date:17.07.2012 ~Priority:3 ~Comment:General remark: Magic numbers, use defined types! */
    /* HB off -> Part HB */
    case HLA_PLUS_HB_STATE_OFF_2_PART_ON:
      *pChangeOverLevel = (sint16)(0.25f * (pFPar->HLAStandard.ChangeOverLevel.TurnOnHigh + 2));
      break;
    
    /* HB -> Part HB */
    case HLA_PLUS_HB_STATE_FULL_2_PART_ON:
      /* ~CodeReview ~ID:5c47206451c8d9bd945c30c9f8fcbf3a ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
      *pChangeOverLevel = 6;
      break;

    /* HB -> HB off */
    case HLA_PLUS_HB_STATE_PART_2_OFF:
    case HLA_PLUS_HB_STATE_FULL_2_OFF:
    case HLA_PLUS_HB_STATE_OFF:
      /* coming from partial HB ? */
      if(eHBStatePre == HLA_PLUS_HB_STATE_PART_ON)
      {
        /* partial HB switched off in this cycle ? */
        if(eHBState == HLA_PLUS_HB_STATE_PART_2_OFF)
        {
          /* set minimum change over level                        */
          /* this level will be used when no traffic is detected  */
          /* e.g. city, blockage, too bright, ... */
          *pChangeOverLevel = (sint16)(0.5f * (pFPar->HLAStandard.ChangeOverLevel.TurnOffLow + 1)); /* IHC = 6 */
          
          if(pOutermost->bVehDet_Alive == b_TRUE)
          {
            /* partial HB switched off due to blinding                                      */
            /* -> slow angle movement (otherwise the spot will blind the vehicle even more) */
            /* -> fast changeOverLevel                                                      */
            if(TurnOffReason.Bit.dAng2Large == 1)
            {
              /* ~CodeReview ~ID:ea19a7123cb979037453a9d898f92508 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
              *pChangeOverLevel = 6;
            }
            /* oncoming car detected left from preceding car */
            /* -> slow angle movement                        */
            /*    fast changeOverLevel                       */
            if(TurnOffReason.Bit.OncLeftPrec == 1)
            {
              /* ~CodeReview ~ID:458fb5946c1507370a9d02cd67746a79 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
              *pChangeOverLevel = 6;
            }
            /* oncoming vehicle is outermost left or right */
            if(pOutermost->VehOutermost_Alive.s_Status.isVehicleOncoming == 1)
            {
              /* ~CodeReview ~ID:458fb5946c1507370a9d02cd67746a79 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
              *pChangeOverLevel = 6;
            }
          }
        }

        if(    (pOutermost->bVehDet_Alive == b_TRUE)
            && ((TrafficStyle_NormFactor * Sign * pOutermost->VehOutermost_Alive.si16_delta_x) > (TrafficStyle_NormFactor * 1.0f))
          )
        {
          uint16 minTTB = pOutermost->VehOutermost_Alive.ui16_ttb18_ms;
          /* left headlamp:  vehicle moves to left  */
          /* right headlamp: vehicle moves to right */
          if(minTTB < hlafPlusParameter.ChangeOverLevel_7_TTB)
          {
            /* ~CodeReview ~ID:4bc15965c80f25fff2446de0d97774ed ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
            *pChangeOverLevel = CML_Max(*pChangeOverLevel, 7);
          }
          else if(minTTB < hlafPlusParameter.ChangeOverLevel_6_TTB)
          {
            /* ~CodeReview ~ID:9ee6347c2d474094e283d5651d28f094 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
            *pChangeOverLevel = CML_Max(*pChangeOverLevel, 6);
          }
          else if(minTTB < hlafPlusParameter.ChangeOverLevel_5_TTB)
          {
            /* ~CodeReview ~ID:a483007b16c523f73dd4794818182fed ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
            *pChangeOverLevel = CML_Max(*pChangeOverLevel, 5);
          }
          else if(minTTB < hlafPlusParameter.ChangeOverLevel_4_TTB)
          {
            /* ~CodeReview ~ID:4108aa017acb53e98fd9b604122e468f ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
            *pChangeOverLevel = CML_Max(*pChangeOverLevel, 4);
          }
          else
          {
            /* ~CodeReview ~ID:840466d9950e197eea3d2d647e2f4a00 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
            *pChangeOverLevel = CML_Max(*pChangeOverLevel, 3);
          }
        }
        else
        {
          /* no alive vehicle */
          /* or vehicle moves not into deactivation region */
          /* ~CodeReview ~ID:3706cc40131f142581e4807693410928 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
          *pChangeOverLevel = CML_Max(*pChangeOverLevel, 3);
        }
      }
      /* coming from full HB ? */
      else if(eHBStatePre == HLA_PLUS_HB_STATE_FULL_ON)
      {
        uint8 ChangeOverLevel_Std;
            
        /* use change over level from Standard */
        ChangeOverLevel_Std = HLAFDecisionChangeOverLevel_TurnOff( /* input */
                                                                   pFData->HLAStdOut.LowBeamDist,
                                                                   pFData->HLAStdOut.eTargetDrivingDirection,
                                                                   &pFPar->HLAStandard.ChangeOverLevel
                                                                 );
        *pChangeOverLevel = (sint16)(0.5f * (ChangeOverLevel_Std + 1));
      }
      else
      {
        /* do NOT overwrite existing change over level */
      }
      break;

    /* static states */
    case HLA_PLUS_HB_STATE_INIT:
    case HLA_PLUS_HB_STATE_FULL_ON:
    case HLA_PLUS_HB_STATE_PART_ON:
    default:
      /* do NOT overwrite existing change over level */
      break;
  }
}

/* **************************************************************************** 
  Functionname:     HLAPlusSyncChangeOverLevel                           */ /*!
  @brief            
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
#define HLA_TOLERANCE_CYCLES 32
static void HLAPlusSyncChangeOverLevel( /* input */
                                        const HLAplusHBState_t *pHBState,
                                        /* output */
                                        HLAplusChangeOverLevel_t *pChangeOverLevel
                                      )
{
  /* left and right HB off */
  if(    /* left HB off */
         (    (pHBState->Left.eState == HLA_PLUS_HB_STATE_FULL_2_OFF)
           || (pHBState->Left.eState == HLA_PLUS_HB_STATE_PART_2_OFF)
           || (pHBState->Left.eState == HLA_PLUS_HB_STATE_OFF)
         )
         /* right HB off */
      && (    (pHBState->Right.eState == HLA_PLUS_HB_STATE_FULL_2_OFF)
           || (pHBState->Right.eState == HLA_PLUS_HB_STATE_PART_2_OFF)
           || (pHBState->Right.eState == HLA_PLUS_HB_STATE_OFF)
         )
    )
  {
    /* check for tolerance time */
    if(abs((sint32)pHBState->Left.Cnt - (sint32)pHBState->Right.Cnt) < HLA_TOLERANCE_CYCLES)
    {
      pChangeOverLevel->Left  = CML_Max(pChangeOverLevel->Left, pChangeOverLevel->Right);
      pChangeOverLevel->Right = pChangeOverLevel->Left;
    }
    else
    {
      /* Do nothing */
    }
  }
  /* left and right HB on */
  else if(    /* left HB on */
             (   (pHBState->Left.eState == HLA_PLUS_HB_STATE_OFF_2_FULL_ON)
              || (pHBState->Left.eState == HLA_PLUS_HB_STATE_PART_2_FULL_ON)
              || (pHBState->Left.eState == HLA_PLUS_HB_STATE_FULL_ON)
              )
           && /* right HB on */
              (    (pHBState->Right.eState == HLA_PLUS_HB_STATE_OFF_2_FULL_ON)
                || (pHBState->Right.eState == HLA_PLUS_HB_STATE_PART_2_FULL_ON)
                || (pHBState->Right.eState == HLA_PLUS_HB_STATE_FULL_ON)
              )
         )
  {
    pChangeOverLevel->Left  = CML_Min(pChangeOverLevel->Left, pChangeOverLevel->Right);
    pChangeOverLevel->Right = pChangeOverLevel->Left;
  }
  else
  {
    /* Do nothing */
  }  
}
#undef HLA_TOLERANCE_CYCLES


/* **************************************************************************** 
  Functionname:     HLAPlus2FillInputData                                */ /*!
  @brief            HLA plus fill input data
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
#define HLA_PLUS2_MAX_OFFSET_ANGLE   DEG2RAD(10.0f)

static void HLAPlusFillInputData( const HLA_t_HeadlightState *pHeadlightState, 
                                  const HLAFTrafficStyleOut_t *pTrafficStyle
                                )
{
  float32 OffsetAngle_left;
  float32 OffsetAngle_right;


  /* set hla plus configuration */
  hlafPlusInput.Cfg.TurnOffLeft_OncOnly = 0;
  hlafPlusInput.Cfg.TurnOffLeft_LeftOnly = 0;
  hlafPlusInput.Cfg.KeepOffLeft_LeftOnly = 0;
  hlafPlusInput.Cfg.AsymmetricMode = 1;


  /*********************************/
  /* set curve light angles        */
  /*  traffic style normalized !!! */
  /*********************************/
  /* AUTOSAR: left side positive angle, right side negative */
  if(pTrafficStyle->eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHD)
  {
    /* right hand traffic                 */
    /* set traffic style normalized value */
    hlafPlusInput.CurveLightAngle_left  = pHeadlightState->f32_CurveLightRotAngle_Lt;
    hlafPlusInput.CurveLightAngle_right = pHeadlightState->f32_CurveLightRotAngle_Rt;
  }  
  else
  {
    /* left hand traffic                  */
    /* set traffic style normalized value */
    hlafPlusInput.CurveLightAngle_left  = -pHeadlightState->f32_CurveLightRotAngle_Rt;
    hlafPlusInput.CurveLightAngle_right = -pHeadlightState->f32_CurveLightRotAngle_Lt;
  }

  


  /******************************/
  /* determine OffsetAngle_left */
  /******************************/
  if(hlafPlusInput.CurveLightAngle_left < 0.0f)
  {
    OffsetAngle_left = CML_f_Min(0.0f, (hlafPlusInput.CurveLightAngle_left + CML_Deg2Rad(2.0f)));
  }
  else
  {
    OffsetAngle_left = hlafPlusInput.CurveLightAngle_left;
  }
  /*******************************/
  /* determine OffsetAngle_right */
  /*******************************/
  if(hlafPlusInput.CurveLightAngle_right > 0.0f)
  {
    /* ~CodeReview ~ID:5ed441c037cc83984492a30ca05a9a18 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
    OffsetAngle_right = CML_f_Max(0.0f, (hlafPlusInput.CurveLightAngle_right - CML_Deg2Rad(2.0f)));
  }
  else
  {
    OffsetAngle_right = hlafPlusInput.CurveLightAngle_right;
  }
  /* limit offset angle for left/ right side */
  if(OffsetAngle_left > HLA_PLUS2_MAX_OFFSET_ANGLE)
  {
    hlafPlusInput.OffsetAngle_left = HLA_PLUS2_MAX_OFFSET_ANGLE;  
    /* hlaPlus2Input.OffsetAngle_right  = hlaPlus2Input.OffsetAngle_right; */
  }
  else if(OffsetAngle_right < -HLA_PLUS2_MAX_OFFSET_ANGLE)
  {
    /* hlaPlus2Input.OffsetAngle_left  = hlaPlus2Input.OffsetAngle_left; */
    hlafPlusInput.OffsetAngle_right = -HLA_PLUS2_MAX_OFFSET_ANGLE;
  }
  else
  {
    hlafPlusInput.OffsetAngle_left  = OffsetAngle_left;
    hlafPlusInput.OffsetAngle_right = OffsetAngle_right;
  }
 
}

/* **************************************************************************** 
  Functionname:     HLAFPlusExit                                         */ /*!
  @brief            HLA plus exit function
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
/* ~CodeReview ~ID:faa0d204f378d27e767fdbc283974ebb ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:unused function */
void HLAFPlusExit(void)
{

}

/* **************************************************************************** 
  Functionname:     HLAFPlusInit                                         */ /*!
  @brief            HLAF plus init function
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAFPlusInit(HLAFPlusOut_t *pPlusOut)
{
  /* init some vars only once after bootup */
  
  /* init data */
  HLAPlusInitData();

  /* init output data */
  HLAPlusInitOutput(pPlusOut);
  
}

/* **************************************************************************** 
  Functionname:     HLAFPlusMain                                         */ /*!
  @brief            HLA plus processing
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAFPlusMain( /* input */
                   const HLAF_t_RequiredInputs  *ps_In,
                   const HLAFData_t             *pFData,
                   const HLAFParameter_t        *pFPar,
                   /* output */ 
                   HLAFPlusOut_t                *pPlusOut
                 )
{
  HLAFPlusOut_t PlusOut_Prev = hlafPlusData.Out;
  HLAFPlusOut_t PlusOut_Next = hlafPlusData.Out;


  /* init extended object list */
  (void)memset(&hlafPlusData.Object, 0, sizeof(HLAplusObjectList_t));

  HLAPlusFillInputData( ps_In->s_Sig.ps_HeadlightState,
                        &pFData->DecisionOut.TrafficStyle
                      );

  
  /* below activation speed ? */
  HLAFDecisionSpeed( /* input */
                     ps_In->s_Sig.ps_MotionState,
                     ps_In->s_Sig.ps_ObjectList,
                     pFData->CamData.dtimeFwd_s,
                     pFPar->SpeedPartial.DeactivateSpeed,
                     pFPar->SpeedPartial.ActivateSpeed,
                     pFPar->SpeedPartial.AlwaysActiveSpeed,
                     pFPar->SpeedPartial.KeepOff_VeryLowSpeed,
                     pFPar->SpeedPartial.KeepOff_LowRadius,
                     pFPar->SpeedPartial.KeepOff_HighAcceleration,
                     pFPar->SpeedPartial.KeepOff_AccTime,
                     pFPar->SpeedPartial.KeepOff_Delay,
                     /* history */
                     &hlafPlusData.DecisionData.Speed
                     /* output */
                   );
 
  /* find all relevant vehicles and set flag in extended object list */
  /*            and check if vehicle is within function ROI (+ flag) */
  HLAPlusDecision_FindRelevantVehicles( ps_In,
                                        pFData,
                                        /* output */ 
                                        &hlafPlusData.Object
                                      );

  /* find outermost vehicle on the left and right side */
  HLAPlusFindOutermostVehicle( /* input */
                               ps_In,
                               &hlafPlusData,
                               &pFData->DecisionOut.TrafficStyle,
                               /* output */  
                               &hlafPlusData.Outermost
                             );

  /* analyze vehicle position                                 */
  /* vehicle found in deactivation/ hold or activation region */
  HLAPlusRegion_VehiclePosition(/* input */
                                ps_In,
                                &hlafPlusInput,
                                pFData,
                                &hlafPlusData,
                                &hlafPlusParameter, 
                                hlafPlusData.HBState.Left.eState,
                                hlafPlusData.HBState.Right.eState
                               );

  /* keep partial HB off stage 1: set keep off reasons for left / right beam */
  HLAPlusKeepOffPart_Stage1( ps_In,
                             pFData,
                             &PlusOut_Prev,
                             pFData->CamData.dtimeFwd_s,
                             &hlafPlusData,
                             &hlafPlusData.KeepOff.Reason_Left,
                             &hlafPlusData.KeepOff.Reason_Right
                           );

  /* full HB off: set keep off reason */
  HLAPlusKeepOffFull( pFData,
                      pFData->CamData.dtimeFwd_s,
                      &hlafPlusParameter.TurnOnDelay,
                      &hlafPlusData,
                      &hlafPlusData.KeepOff.Reason_FullHB
                    );

  /* set turn off reasons for left / right beam */
  HLAPlusTurnOffPart( ps_In,
                      pFData,
                      ps_In->s_Par.ps_CameraParameter,
                      &hlafPlusInput,
                      &PlusOut_Prev,
                      &hlafPlusData,
                      &hlafPlusData.TurnOff.Reason_Left,
                      &hlafPlusData.TurnOff.Reason_Right
                    );

  /* set turn off reasons for full beam */
  HLAPlusTurnOffFull( ps_In,
                      &hlafPlusData,
                      &PlusOut_Prev,
                      &pFData->DecisionOut.TrafficStyle,
                      &hlafPlusData.TurnOff.Reason_FullHB
                    );

  /* keep partial HB off 2. stage: any potential vehicles,  synchronize left/ right partial high beams */
  HLAPlusKeepOffPart_Stage2( ps_In,
                             &hlafPlusInput,
                             pFData,
                             &hlafPlusData
                           );

  /* set HB state */
  HLAPlusSetDecHBState( /* input */
                        pFData->DecisionData.TurnOffReason_glob,
                        hlafPlusData.TurnOff.Reason_Left,
                        hlafPlusData.TurnOff.Reason_FullHB,
                        hlafPlusData.KeepOff.Reason_Left,
                        hlafPlusData.KeepOff.Reason_FullHB,
                        /* output */
                        &hlafPlusData.HBState.Left.eState,
                        &hlafPlusData.HBState.Left.Cnt,
                        &hlafPlusData.HBState.Left.eStatePrev
                      );
  HLAPlusSetDecHBState( /* input */ 
                        pFData->DecisionData.TurnOffReason_glob,
                        hlafPlusData.TurnOff.Reason_Right,
                        hlafPlusData.TurnOff.Reason_FullHB,
                        hlafPlusData.KeepOff.Reason_Right,
                        hlafPlusData.KeepOff.Reason_FullHB,
                        /* output */
                        &hlafPlusData.HBState.Right.eState,
                        &hlafPlusData.HBState.Right.Cnt,
                        &hlafPlusData.HBState.Right.eStatePrev
                      );


  /* calc. high beam angle */
  HLAPlusAngle( /* input */
                pFData,
                ps_In,
                &hlafPlusParameter,
                ps_In->s_Sig.ps_ObjectList,
                &hlafPlusInput,
                /* output/ history */
                &hlafPlusData
              );

  /* set change over level */
  HLAPlusSetChangeOverLevel( hlafPlusData.TurnOff.Reason_Left.Reason,
                             pFData,
                             pFPar,
                             &hlafPlusData.ChangeOverLevel.Left,
                             hlafPlusData.HBState.Left.eState,
                             hlafPlusData.HBState.Left.eStatePrev,
                             &hlafPlusData.Outermost.Left,
                             HLA_PLUS_LEFT_HEADLAMP
                           );
  HLAPlusSetChangeOverLevel( hlafPlusData.TurnOff.Reason_Right.Reason,
                             pFData,
                             pFPar,          
                             &hlafPlusData.ChangeOverLevel.Right,
                             hlafPlusData.HBState.Right.eState,
                             hlafPlusData.HBState.Right.eStatePrev,
                             &hlafPlusData.Outermost.Right,
                             HLA_PLUS_RIGHT_HEADLAMP
                           );
  /* synchronize left and right change over level */
  HLAPlusSyncChangeOverLevel( /* input */
                              &hlafPlusData.HBState,
                              /* output */
                              &hlafPlusData.ChangeOverLevel
                            );


  /*****************************************************************************/
  /* set all plus outputs: HB state, light output, change over level, HB angle */
  /*****************************************************************************/

  /* set HB state */
  HLAFPlusSetHBState( /* input */
                      hlafPlusData.HBState.Left.eState,
                      /* output */
                      &PlusOut_Next.eHighBeamState_Lt
                    );
  HLAFPlusSetHBState( /* input */
                      hlafPlusData.HBState.Right.eState,
                      /* output */
                      &PlusOut_Next.eHighBeamState_Rt
                      );

  /* set light output power */
  HLAFPlusSetLightOutput( /* input */
                          PlusOut_Next.eHighBeamState_Lt,
                          /* output */
                          &PlusOut_Next.eLightOutput_Lt
                        );
  HLAFPlusSetLightOutput( /* input */
                          PlusOut_Next.eHighBeamState_Rt,
                          /* output */
                          &PlusOut_Next.eLightOutput_Rt
                        );

  /* set HB angle */
  PlusOut_Next.RotAngleMin_Lt = hlafPlusData.HBAngle.Left.Ang_LP;
  PlusOut_Next.RotAngleMin_Rt = hlafPlusData.HBAngle.Right.Ang_LP;

  /* set change over level */
  /* ~CodeReview ~ID:18a5a2417697694d1215b5c13791003e ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:magic number */
  PlusOut_Next.ChangeoverLevel_Lt = (uint8)CML_MinMax(0, 7, hlafPlusData.ChangeOverLevel.Left);
  PlusOut_Next.ChangeoverLevel_Rt = (uint8)CML_MinMax(0, 7, hlafPlusData.ChangeOverLevel.Right);
  
  /* copy into output data */
  
  /* copy output into internal data struct */
  /* note: copy before mirroring !!!       */
  hlafPlusData.Out = PlusOut_Next;

  /* mirror outputs for left hand traffic */
  if(pFData->DecisionOut.TrafficStyle.eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHD)
  {
    /* right hand traffic:  */
    *pPlusOut = PlusOut_Next;
  } 
  else
  {
    /* left hand traffic:  */
    /* -> mirror outputs   */
    pPlusOut->eHighBeamState_Lt  = PlusOut_Next.eHighBeamState_Rt;
    pPlusOut->eHighBeamState_Rt  = PlusOut_Next.eHighBeamState_Lt;
    pPlusOut->RotAngleMin_Lt     = -PlusOut_Next.RotAngleMin_Rt;
    pPlusOut->RotAngleMin_Rt     = -PlusOut_Next.RotAngleMin_Lt;
    pPlusOut->ChangeoverLevel_Lt = PlusOut_Next.ChangeoverLevel_Rt;
    pPlusOut->ChangeoverLevel_Rt = PlusOut_Next.ChangeoverLevel_Lt;
    pPlusOut->eLightOutput_Lt    = PlusOut_Next.eLightOutput_Rt;
    pPlusOut->eLightOutput_Rt    = PlusOut_Next.eLightOutput_Lt;
  }
}


/* ****************************************************************************
  Functionname:     HLAFPlusMeasfreeze                          */ /*!
  Description:      send internal hla plus data via measfreeze to MTS. 



  @param[in]        

  @pre              -
  @post             -
  @todo             - 
  @author           
**************************************************************************** */
void HLAFPlusMeasfreeze(AS_t_MeasHdlr pfMeasFreeze)
{
#ifdef HLA_ENABLE_INTERNAL_MEASFREEZES
  AS_t_MeasInfo HlafPlusParameterMeasInfo = {HLA_MEAS_VADDR_HLAF_PLUS_PARAMETER, sizeof(hlafPlusParameter), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo HlafPlusInputMeasInfo = {HLA_MEAS_VADDR_HLAF_PLUS_INPUT, sizeof(hlafPlusInput), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo HlafPlusDataMeasInfo = {HLA_MEAS_VADDR_HLAF_PLUS_DATA, sizeof(hlafPlusData), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};

  (void)pfMeasFreeze(&HlafPlusParameterMeasInfo, (void*)&hlafPlusParameter, NULL);
  (void)pfMeasFreeze(&HlafPlusInputMeasInfo, (void*)&hlafPlusInput, NULL);
  (void)pfMeasFreeze(&HlafPlusDataMeasInfo, (void*)&hlafPlusData, NULL);
#endif   
}/* PRQA S 861 1 */
