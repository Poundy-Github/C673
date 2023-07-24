/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf.c

  DESCRIPTION:            HLAF main module. This module calls all sub functions for HLAF.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2011-02-23

  VERSION:                $Revision: 1.1 $
   
  ---*/ /*---
  CHANGE:                 $Log: hlaf.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:06CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:52CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:31CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/project.pj
  CHANGE:                 Revision 1.143 2014/03/28 10:04:33CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed scons warnings
  CHANGE:                 Removed compiler warnings
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 28, 2014 10:04:34 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.142 2014/03/27 14:32:07CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Support for R2.2 RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 27, 2014 2:32:07 PM CET]
  CHANGE:                 Change Package : 207432:48 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.141 2014/03/25 19:11:49CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Separation of hla_segmentation.c
  CHANGE:                 Removed QAC warnings
  CHANGE:                 Replaces fABS by CML_f_abs
  CHANGE:                 Introduced CML_s_Round2Int
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 25, 2014 7:11:49 PM CET]
  CHANGE:                 Change Package : 207432:46 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.140 2014/03/25 18:42:31CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/project.pj.
  CHANGE:                 Revision 1.139 2014/03/19 16:30:33CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:34 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.138 2014/03/18 16:15:38CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Made some symbols not static
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 18, 2014 4:15:38 PM CET]
  CHANGE:                 Change Package : 207432:22 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.137 2014/03/04 16:52:31CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:32 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.136 2014/03/04 12:59:06CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Support for I390 RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 12:59:06 PM CET]
  CHANGE:                 Change Package : 207432:32 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.135 2014/02/07 13:40:08CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Get version info in wrapper now from lib
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 7, 2014 1:40:08 PM CET]
  CHANGE:                 Change Package : 207432:30 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.134 2014/02/06 16:01:02CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGE:                 Centralized Null pointer checks
  CHANGE:                 Refactored dframe calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 6, 2014 4:01:03 PM CET]
  CHANGE:                 Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGE:                 Revision 1.133 2014/01/21 09:13:00CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added a few more checks for devision of zero
  CHANGE:                 Removed some PC_SIM code that is no longer needed
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 21, 2014 9:13:01 AM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.132 2014/01/08 17:10:09CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactored HLA_Exec() function
  CHANGE:                 Replaced uint64 time stamps by uint32 ones
  CHANGE:                 Smaller bug fixes
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 8, 2014 5:10:10 PM CET]
  CHANGE:                 Change Package : 207432:27 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.131 2013/12/18 15:20:22CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 fix to provide HLA-plus output in PC_SIM
  CHANGE:                 --- Added comments ---  uidv8776 [Dec 18, 2013 3:20:22 PM CET]
  CHANGE:                 Change Package : 199150:1 http://mks-psad:7002/im/viewissue?selection=199150
  CHANGE:                 Revision 1.130 2013/12/13 16:44:37CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:44:38 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.129 2013/11/29 13:19:46CET Brunn, Marcus (brunnm) 
  CHANGE:                 - removed HLARout, HLAFout and HLAFin measfreezes
  CHANGE:                 - enabled internal measfreezes
  CHANGE:                 - added measfreeze for HlaTrackData.preComputedData
  CHANGE:                 --- Added comments ---  brunnm [Nov 29, 2013 1:19:46 PM CET]
  CHANGE:                 Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGE:                 Revision 1.128 2013/11/29 10:27:53CET Brunn, Marcus (brunnm) 
  CHANGE:                 - updated some input checks
  CHANGE:                 - updated error handling
  CHANGE:                 --- Added comments ---  brunnm [Nov 29, 2013 10:27:53 AM CET]
  CHANGE:                 Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGE:                 Revision 1.127 2013/11/11 12:35:55CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Switch off Daimler parts on ECU
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 11, 2013 12:35:55 PM CET]
  CHANGE:                 Change Package : 198642:1 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.126 2013/10/30 08:29:03CET Werner, Felix (uidg3197) 
  CHANGE:                 - Disabled HLAFLightMain, HLAFStandardMain, HLAFPlusMain, HLAFSpotLight
  CHANGE:                 --- Added comments ---  uidg3197 [Oct 30, 2013 8:29:03 AM CET]
  CHANGE:                 Change Package : 201109:2 http://mks-psad:7002/im/viewissue?selection=201109
  CHANGE:                 Revision 1.125 2013/09/26 11:21:34CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced specific HLA opmodes by TestMode CPar
  CHANGE:                 --- Added comments ---  uidv7867 [Sep 26, 2013 11:21:34 AM CEST]
  CHANGE:                 Change Package : 198642:1 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.124 2013/09/18 17:41:55CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Hla sens mode
  CHANGE:                 --- Added comments ---  uidv7867 [Sep 18, 2013 5:41:56 PM CEST]
  CHANGE:                 Change Package : 167173:35 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.123 2013/08/29 12:39:37CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Disabled almost all internal measfreezes temporary due 15K budget
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 29, 2013 12:39:38 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.122 2013/08/23 18:16:50CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Update: Algo Interface checked to be in line with specs (e.g. signal states and return data for various OpModes)
  CHANGE:                 Update: removed NightView structure from HLA inputs
  CHANGE:                 Fix: adapted DebugIcon Adapter to reflect latest changes in Icon structure
  CHANGE:                 --- Added comments ---  uidv8777 [Aug 23, 2013 6:16:50 PM CEST]
  CHANGE:                 Change Package : 192041:3 http://mks-psad:7002/im/viewissue?selection=192041
  CHANGE:                 Revision 1.121 2013/08/02 16:18:27CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Integrated HLA runtime restrictions (down to 3 icons and 40% of lights)
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 2, 2013 4:18:28 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.120 2013/07/26 17:40:05CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Update: missed some files due to MKS not showing them - duh
  CHANGE:                  - include functionality for EcoLight and Dimming Area
  CHANGE:                 --- Added comments ---  uidv8777 [Jul 26, 2013 5:40:05 PM CEST]
  CHANGE:                 Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
  CHANGE:                 Revision 1.119 2013/07/15 10:43:15CEST Brunn, Marcus (brunnm) 
  CHANGE:                 fixed glare free area output (default: set object status to RTE_HLAF_OBJSTA_NO_OBJ)
  CHANGE:                 --- Added comments ---  brunnm [Jul 15, 2013 10:43:15 AM CEST]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include <string.h>
#include <math.h>
#include "hlaf_type.h"
#include "hlaf_cfg.h"
#include "hlaf_decision.h"
#include "hlaf_debug.h"
#include "hlaf_standard.h"
#include "hlaf_light.h"
#include "hlaf_plus.h"
#include "hlaf_spotLight.h"
#include "hlaf_matrix.h"
#include "hla_ver.h"
#include "hlaf_dimming.h"
#include "hlaf_ecolight.h"

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

/* HLAF internal Data */
HLA_GLOBAL_STATIC HLAFData_t  hlafData;

/* debug variables */
HLAF_DebugOutputs_t hlafDebugOutputs;

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static void HLAFInitOutput( /* input */
                            /* output */ 
                            HLAF_t_ProvidedOutputs *ps_Out
                          );
static void HLAFMeasfreeze(AS_t_MeasHdlr pfMeasFreeze);
static void HLAFInitData( const HLAF_t_RequiredInputs  *pHlafReqIn,
                          HLAFData_t                   *pFData
                        );
static void HLAFFillData( /* input */
                          const HLAF_t_RequiredInputs  *pIn,
                          /* output */
                          HLAFData_t                   *pFData
                        );
static void HLAFFillCameraData( /* input */
                                const HLAF_t_RequiredInputs  *pIn,
                                const HLAFData_t             *pFData,
                                /* output */ 
                                HLAFCameraData_t             *pCamData
                              );
static void HLAFFillOutputData( /* input */
                                const HLAF_t_RequiredInputs    *ps_In,
                                const HLAFData_t               *pFData,
                                const RTE_HLAR_BrightnessState e_Brightness,
                                const HLAFParameter_t          *pFPar,
                                /* output */
                                HLAF_t_ProvidedOutputs         *ps_Out,
                                HLA_t_SystemInfo               *ps_SystemInfo
                              );

static void HLAFFillDiagnosisDebugMsg( /* input */
                                       const HLAFData_t             *pFData,
#ifdef PC_SIM  /* only needed during simulation for old school evaluation based on MFC300 data */
                                       const HLAFLightData_t        *pLightData,
                                       const HLAFStandardData_t     *pStdData,
                                       const HLAplusData_t          *pPlusData,
#endif
                                       const HLA_t_HeadlightControl *pHeadlightControl,
                                       /* output */ 
                                       HLA_t_DiagnosisDebugMsg      *pDbgMsgOut
                                     );
static void HLAFFillDebugOutput( /* input data */
                                const HLAFData_t    *pFData,
                                /* output data */ 
                                HLAF_DebugOutputs_t *pOut
                                );
static void HLAFFillOutputDataMatrixBeam( /* input */
                                          const HLAFData_t *pFData,
                                          /* output */
                                          HLAF_t_Matrix *pMatrixOut
                                        );

/* ****************************************************************************
  Functionname:     HLAFFillDebugData */ /*!
  Description:      Fill debug output data of HLAF.

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           -
  @pre              -
  @post             -
  @author           Matthias Mutschler
**************************************************************************** */
static void HLAFFillDebugOutput( /* input data */
                                 const HLAFData_t    *pFData,
                                 /* output data */ 
                                 HLAF_DebugOutputs_t *pOut
                                )
{
  /* copy interface version number, HLA/ HLAR SW version number and frame counter */
  /* into output data */
  pOut->ui32_InterfaceVersionNumber = HLAF_DEBUG_INTERFACE_VERSION_NUMBER;
  pOut->ui32_HLA_SWVersionNumber    = HLA_SW_VERSION_NUMBER;
  pOut->ui32_HLAF_SWVersionNumber   = HLAF_SW_VERSION_NUMBER;
  pOut->uiFrameCnt                  = pFData->FrameCnt;
  pOut->uiHLAF_Cnt                  = pFData->HLAF_Cnt;
  
  /* set HLA and image timestamps */
  pOut->uiTimeStamp_HLA_us          = pFData->TimeStamp_HLA_us;
  pOut->uiTimeStamp_Image_us        = pFData->TimeStamp_Image_us;
    
}

/* ****************************************************************************
  Functionname:     HLAFFillDiagnosisDebugMsg                            */ /*!
  Description:      Fill diagnosis debug message (64Bit struct).

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAFFillDiagnosisDebugMsg( /* input */
                                       const HLAFData_t             *pFData,
#ifdef PC_SIM  /* only needed during simulation for old school evaluation based on MFC300 data */
                                       const HLAFLightData_t        *pLightData,
                                       const HLAFStandardData_t     *pStdData,
                                       const HLAplusData_t          *pPlusData,
#endif
                                       const HLA_t_HeadlightControl *pHeadlightControl,
                                       /* output */ 
                                       HLA_t_DiagnosisDebugMsg      *pDbgMsgOut
                                     )
{
  HLA_t_DiagnosisDebugMsg  DbgMsg;


  DbgMsg = *pDbgMsgOut;

 
  /* fill debug message, set next state */
  switch(DbgMsg.HLAVersion.NextState)
  {
    case HLA_DDM_STATE__HLA_VERSION:
    case HLA_DDM_STATE__HB_ON:
      if(pHeadlightControl->s_PlusStdLight.e_HighBeamState == RTE_HLAF_HB_STATE_FULL_ON)
      {
        /* full HB on */
        DbgMsg.HLAVersion.NextState  = (uint8)HLA_DDM_STATE__HB_ON;
      }
      else
      {
        /* full HB off */
        DbgMsg.HLAVersion.NextState  = (uint8)HLA_DDM_STATE__HLAR_INITIAL_TURN_OFF_REASON;
      } 
      break;
    case HLA_DDM_STATE__HLAR_INITIAL_TURN_OFF_REASON:
      if(pHeadlightControl->s_PlusStdLight.e_HighBeamState == RTE_HLAF_HB_STATE_FULL_ON)
      {
        /* full HB on */
        DbgMsg.HLARInitialTurnOffReason.NextState  = (uint8)HLA_DDM_STATE__HLA_VERSION;
      }
      else
      {
        /* full HB off */
        DbgMsg.HLARInitialTurnOffReason.NextState  = (uint8)HLA_DDM_STATE__HLAF_TURN_OFF_REASON;
      } 
      break;
    case HLA_DDM_STATE__HLAF_TURN_OFF_REASON:
      DbgMsg.HLAFTurnOffReason.eState      = (uint8)HLA_DDM_STATE__HLAF_TURN_OFF_REASON;
      /* HB on ? */
      if(pHeadlightControl->s_PlusStdLight.e_HighBeamState == RTE_HLAF_HB_STATE_FULL_ON)
      {
        /* full HB on */
        DbgMsg.HLAFTurnOffReason.NextState  = (uint8)HLA_DDM_STATE__HLA_VERSION;
      }
      else
      {
        /* full HB off */
        DbgMsg.HLAFTurnOffReason.NextState  = (uint8)HLA_DDM_STATE__HLAF_KEEP_OFF_REASON;
      }  
      {
        HLAFTurnOffReasonGlob_Reason_t TurnOffReason_Glob = pFData->DecisionData.TurnOffReason_glob.Reason;

        DbgMsg.HLAFTurnOffReason.Global_NotReleased         = TurnOffReason_Glob.Bit.NotReleased;
        DbgMsg.HLAFTurnOffReason.Global_NotReleasedRedPerf  = TurnOffReason_Glob.Bit.NotReleasedRedPerf;
        DbgMsg.HLAFTurnOffReason.Global_NotReleasedBlockage = TurnOffReason_Glob.Bit.NotReleasedBlockage;   
        DbgMsg.HLAFTurnOffReason.Global_RedPerformance      = TurnOffReason_Glob.Bit.RedPerformance;
        DbgMsg.HLAFTurnOffReason.Global_Blockage            = TurnOffReason_Glob.Bit.Blockage;
        DbgMsg.HLAFTurnOffReason.Global_Brightness          = TurnOffReason_Glob.Bit.Brightness;
        DbgMsg.HLAFTurnOffReason.Global_Maxima              = TurnOffReason_Glob.Bit.Maxima;
        DbgMsg.HLAFTurnOffReason.Global_Lights              = TurnOffReason_Glob.Bit.Lights;
        DbgMsg.HLAFTurnOffReason.Global_City                = TurnOffReason_Glob.Bit.City;
        DbgMsg.HLAFTurnOffReason.Global_Tunnel              = 0;
        DbgMsg.HLAFTurnOffReason.Global_MinSpeed            = TurnOffReason_Glob.Bit.MinSpeed;
        DbgMsg.HLAFTurnOffReason.Global_NotActive           = TurnOffReason_Glob.Bit.NotActive;
        DbgMsg.HLAFTurnOffReason.Global_NotAvl              = TurnOffReason_Glob.Bit.NotAvl;
        DbgMsg.HLAFTurnOffReason.Global_NotCalibrated       = TurnOffReason_Glob.Bit.NotCalibrated;
        DbgMsg.HLAFTurnOffReason.Global_Error               = TurnOffReason_Glob.Bit.Error;
        DbgMsg.HLAFTurnOffReason.Global_Unused              = 0;
      }
      
#ifdef PC_SIM  /* only needed during simulation for old school evaluation based on MFC300 data */
      DbgMsg.HLAFTurnOffReason.Light_OncDetected            = pLightData->TurnOffReason.Reason.Bit.OncDetected;
      DbgMsg.HLAFTurnOffReason.Light_PrecDetected           = pLightData->TurnOffReason.Reason.Bit.PrecDetected;
      DbgMsg.HLAFTurnOffReason.Light_Unused                 = 0;

      DbgMsg.HLAFTurnOffReason.Std_OncDetected              = pStdData->TurnOffReason.Reason.Bit.OncDetected;
      DbgMsg.HLAFTurnOffReason.Std_PrecDetected             = pStdData->TurnOffReason.Reason.Bit.PrecDetected;
      DbgMsg.HLAFTurnOffReason.Std_Unused                   = 0;    

      DbgMsg.HLAFTurnOffReason.Plus_OncDetected             = pPlusData->TurnOff.Reason_FullHB.Reason.Bit.OncDetected;
      DbgMsg.HLAFTurnOffReason.Plus_PrecDetected            = pPlusData->TurnOff.Reason_FullHB.Reason.Bit.PrecDetected;
      DbgMsg.HLAFTurnOffReason.Plus_Unused                  = 0;    

      {
        HLAplusTurnOffReason_Reason_t TurnOffReason_left  = pPlusData->TurnOff.Reason_Left.Reason;
        HLAplusTurnOffReason_Reason_t TurnOffReason_right = pPlusData->TurnOff.Reason_Right.Reason;      


        DbgMsg.HLAFTurnOffReason.PlusLeft_OncomingOnly          = TurnOffReason_left.Bit.OncomingOnly;   
        DbgMsg.HLAFTurnOffReason.PlusRight_OncomingOnly         = TurnOffReason_right.Bit.OncomingOnly;

        DbgMsg.HLAFTurnOffReason.PlusLeft_AngOutermost2Large    = TurnOffReason_left.Bit.AngOutermost2Large;
        DbgMsg.HLAFTurnOffReason.PlusRight_AngOutermost2Large   = TurnOffReason_right.Bit.AngOutermost2Large;

        DbgMsg.HLAFTurnOffReason.PlusLeft_OncomingDeactRegion   = TurnOffReason_left.Bit.OncomingDeactRegion;
        DbgMsg.HLAFTurnOffReason.PlusRight_OncomingDeactRegion  = TurnOffReason_right.Bit.OncomingDeactRegion;

        DbgMsg.HLAFTurnOffReason.PlusLeft_OncLeftPrec           = TurnOffReason_left.Bit.OncLeftPrec;
        DbgMsg.HLAFTurnOffReason.PlusRight_OncLeftPrec          = TurnOffReason_right.Bit.OncLeftPrec;

        DbgMsg.HLAFTurnOffReason.PlusLeft_TTD                   = TurnOffReason_left.Bit.TTD;
        DbgMsg.HLAFTurnOffReason.PlusRight_TTD                  = TurnOffReason_right.Bit.TTD;

        DbgMsg.HLAFTurnOffReason.PlusLeft_RightOff              = TurnOffReason_left.Bit.RightOff;
        DbgMsg.HLAFTurnOffReason.PlusRight_RightOff             = TurnOffReason_right.Bit.RightOff;

        DbgMsg.HLAFTurnOffReason.PlusLeft_dAng2Large            = TurnOffReason_left.Bit.dAng2Large;
        DbgMsg.HLAFTurnOffReason.PlusRight_dAng2Large           = TurnOffReason_right.Bit.dAng2Large;

        DbgMsg.HLAFTurnOffReason.PlusLeft_Oncoming              = TurnOffReason_left.Bit.Oncoming;
        DbgMsg.HLAFTurnOffReason.PlusRight_Oncoming             = TurnOffReason_right.Bit.Oncoming;

        DbgMsg.HLAFTurnOffReason.PlusLeft_Preceding             = TurnOffReason_left.Bit.Preceding;
        DbgMsg.HLAFTurnOffReason.PlusRight_Preceding            = TurnOffReason_right.Bit.Preceding;

        DbgMsg.HLAFTurnOffReason.PlusLeft_MinSpeed              = TurnOffReason_left.Bit.MinSpeed;
        DbgMsg.HLAFTurnOffReason.PlusRight_MinSpeed             = TurnOffReason_right.Bit.MinSpeed;

        DbgMsg.HLAFTurnOffReason.PlusLeft_MayBeCity             = TurnOffReason_left.Bit.MayBeCity;
        DbgMsg.HLAFTurnOffReason.PlusRight_MayBeCity            = TurnOffReason_right.Bit.MayBeCity;

        DbgMsg.HLAFTurnOffReason.PlusLeft_Motorway              = TurnOffReason_left.Bit.Motorway;
        DbgMsg.HLAFTurnOffReason.PlusRight_Motorway             = TurnOffReason_right.Bit.Motorway;

        DbgMsg.HLAFTurnOffReason.PlusLeft_Unused                = 0;
        DbgMsg.HLAFTurnOffReason.PlusRight_Unused               = 0;
      }
#endif
      break;
    case HLA_DDM_STATE__HLAF_KEEP_OFF_REASON:
      DbgMsg.HLAFKeepOffReason.eState     = (uint8)HLA_DDM_STATE__HLAF_KEEP_OFF_REASON;
      /* HB on ? */
      if(pHeadlightControl->s_PlusStdLight.e_HighBeamState == RTE_HLAF_HB_STATE_FULL_ON)
      {
        /* full HB on */
        DbgMsg.HLAFKeepOffReason.NextState  = (uint8)HLA_DDM_STATE__HLA_VERSION;
      }
      else
      {
        /* full HB off */
        DbgMsg.HLAFKeepOffReason.NextState  = (uint8)HLA_DDM_STATE__HLAR_INITIAL_TURN_OFF_REASON;
      }

#ifdef PC_SIM  /* only needed during simulation for old school evaluation based on MFC300 data */
      {
        HLAFStdKeepOffReason_Reason_t KeepOffReason = pStdData->KeepOffReason.Reason;

        DbgMsg.HLAFKeepOffReason.Std_SpdAcc                      = KeepOffReason.Bit.SpdAcc;
        DbgMsg.HLAFKeepOffReason.Std_SmallRadius                 = KeepOffReason.Bit.SmallRadius;
        DbgMsg.HLAFKeepOffReason.Std_MinTimeHBOff                = KeepOffReason.Bit.MinTimeHBOff;
        if(   (KeepOffReason.Bit.TurnOnDelay_Init == 1)
           || (KeepOffReason.Bit.TurnOnDelay_Onc == 1)
           || (KeepOffReason.Bit.TurnOnDelay_Prec == 1)
          )
        {
          DbgMsg.HLAFKeepOffReason.Std_TurnOnDelay = 1;
        }
        else
        {
          DbgMsg.HLAFKeepOffReason.Std_TurnOnDelay = 0;
        }
        DbgMsg.HLAFKeepOffReason.Std_PrecedingVehLost            = KeepOffReason.Bit.PrecedingVehLost;
        DbgMsg.HLAFKeepOffReason.Std_MaybeCity                   =    (KeepOffReason.Bit.MaybeCity_Onc == 1)
                                                                   || (KeepOffReason.Bit.MaybeCity_Prec == 1)
                                                                   || (KeepOffReason.Bit.MaybeCity_Glob == 1);
        DbgMsg.HLAFKeepOffReason.Std_PotVeh                      =    (KeepOffReason.Bit.PotVeh_Onc == 1)
                                                                   || (KeepOffReason.Bit.PotVeh_Prec == 1)
                                                                   || (KeepOffReason.Bit.PotVeh_Glob == 1);
        DbgMsg.HLAFKeepOffReason.Std_Unused                      = 0;
      }
      {
        HLAplusKeepOffReasonFullHB_Reason_t KeepOffReason = pPlusData->KeepOff.Reason_FullHB.Reason;
 
        DbgMsg.HLAFKeepOffReason.Plus_HB_Off                        = KeepOffReason.Bit.HB_Off;
        DbgMsg.HLAFKeepOffReason.Plus_minTimeOff                    = KeepOffReason.Bit.minTimeOff;
        DbgMsg.HLAFKeepOffReason.Plus_minTimePartOn                 = KeepOffReason.Bit.minTimePartOn;
        DbgMsg.HLAFKeepOffReason.Plus_Unused                        = 0;
      }
  
      {
        HLAplusKeepOffReasonPartHB_Reason_t KeepOffReason_left  = pPlusData->KeepOff.Reason_Left.Reason;
        HLAplusKeepOffReasonPartHB_Reason_t KeepOffReason_right = pPlusData->KeepOff.Reason_Right.Reason;
      
        DbgMsg.HLAFKeepOffReason.PlusLeft_TimeToDeact            = KeepOffReason_left.Bit.TimeToDeact;
        DbgMsg.HLAFKeepOffReason.PlusRight_TimeToDeact           = KeepOffReason_right.Bit.TimeToDeact;

        DbgMsg.HLAFKeepOffReason.PlusLeft_TimeToBorder           = KeepOffReason_left.Bit.TimeToBorder;
        DbgMsg.HLAFKeepOffReason.PlusRight_TimeToBorder          = KeepOffReason_right.Bit.TimeToBorder;

        DbgMsg.HLAFKeepOffReason.PlusLeft_NoOncomingMinTime      = KeepOffReason_left.Bit.NoOncomingMinTime;
        DbgMsg.HLAFKeepOffReason.PlusRight_NoOncomingMinTime     = KeepOffReason_right.Bit.NoOncomingMinTime;

        DbgMsg.HLAFKeepOffReason.PlusLeft_NoOncoming             = KeepOffReason_left.Bit.NoOncoming;
        DbgMsg.HLAFKeepOffReason.PlusRight_NoOncoming            = KeepOffReason_right.Bit.NoOncoming;

        DbgMsg.HLAFKeepOffReason.PlusLeft_OutermostLost          = KeepOffReason_left.Bit.OutermostLost;
        DbgMsg.HLAFKeepOffReason.PlusRight_OutermostLost         = KeepOffReason_right.Bit.OutermostLost;

        DbgMsg.HLAFKeepOffReason.PlusLeft_SyncSinglePrecCar      = KeepOffReason_left.Bit.SyncSinglePrecCar;
        DbgMsg.HLAFKeepOffReason.PlusRight_SyncSinglePrecCar     = KeepOffReason_right.Bit.SyncSinglePrecCar;

        DbgMsg.HLAFKeepOffReason.PlusLeft_NoVeh                  = KeepOffReason_left.Bit.NoVeh;
        DbgMsg.HLAFKeepOffReason.PlusRight_NoVeh                 = KeepOffReason_right.Bit.NoVeh;

        DbgMsg.HLAFKeepOffReason.PlusLeft_SpdAcc                 = KeepOffReason_left.Bit.SpdAcc;
        DbgMsg.HLAFKeepOffReason.PlusRight_SpdAcc                = KeepOffReason_right.Bit.SpdAcc;

        DbgMsg.HLAFKeepOffReason.PlusLeft_MaybeCity              = KeepOffReason_left.Bit.MaybeCity;
        DbgMsg.HLAFKeepOffReason.PlusRight_MaybeCity             = KeepOffReason_right.Bit.MaybeCity;

        DbgMsg.HLAFKeepOffReason.PlusLeft_minTimeOff             = KeepOffReason_left.Bit.minTimeOff;
        DbgMsg.HLAFKeepOffReason.PlusRight_minTimeOff            = KeepOffReason_right.Bit.minTimeOff;

        DbgMsg.HLAFKeepOffReason.PlusLeft_Gap2Large              = KeepOffReason_left.Bit.Gap2Large;
        DbgMsg.HLAFKeepOffReason.PlusRight_Gap2Large             = KeepOffReason_right.Bit.Gap2Large;

        DbgMsg.HLAFKeepOffReason.PlusLeft_TimeToDeactOther       = KeepOffReason_left.Bit.TimeToDeactOther;
        DbgMsg.HLAFKeepOffReason.PlusRight_TimeToDeactOther      = KeepOffReason_right.Bit.TimeToDeactOther;

        DbgMsg.HLAFKeepOffReason.PlusLeft_OncCoveredByPrec       = KeepOffReason_left.Bit.OncCoveredByPrec;
        DbgMsg.HLAFKeepOffReason.PlusRight_OncCoveredByPrec      = KeepOffReason_right.Bit.OncCoveredByPrec;

        DbgMsg.HLAFKeepOffReason.PlusLeft_OncWillLeaveFOV        = KeepOffReason_left.Bit.OncWillLeaveFOV;
        DbgMsg.HLAFKeepOffReason.PlusRight_OncWillLeaveFOV       = KeepOffReason_right.Bit.OncWillLeaveFOV;

        DbgMsg.HLAFKeepOffReason.PlusLeft_PotentialOncomingDeact = KeepOffReason_left.Bit.PotentialOncomingDeact;
        DbgMsg.HLAFKeepOffReason.PlusRight_PotentialOncomingDeact= KeepOffReason_right.Bit.PotentialOncomingDeact;

        DbgMsg.HLAFKeepOffReason.PlusLeft_PotentialOncoming      = KeepOffReason_left.Bit.PotentialOncoming;
        DbgMsg.HLAFKeepOffReason.PlusRight_PotentialOncoming     = KeepOffReason_right.Bit.PotentialOncoming;

        DbgMsg.HLAFKeepOffReason.PlusLeft_Wait4OtherPHB          = KeepOffReason_left.Bit.Wait4OtherPHB;
        DbgMsg.HLAFKeepOffReason.PlusRight_Wait4OtherPHB         = KeepOffReason_right.Bit.Wait4OtherPHB;

        DbgMsg.HLAFKeepOffReason.PlusLeft_Sync                   = KeepOffReason_left.Bit.Sync;
        DbgMsg.HLAFKeepOffReason.PlusRight_Sync                  = KeepOffReason_right.Bit.Sync;

        DbgMsg.HLAFKeepOffReason.PlusLeft_PrecMinTimeInActRegion = KeepOffReason_left.Bit.PrecMinTimeInActRegion;
        DbgMsg.HLAFKeepOffReason.PlusRight_PrecMinTimeInActRegion= KeepOffReason_right.Bit.PrecMinTimeInActRegion;

        DbgMsg.HLAFKeepOffReason.PlusLeft_OncMinTimeInActRegion  = KeepOffReason_left.Bit.OncMinTimeInActRegion;
        DbgMsg.HLAFKeepOffReason.PlusRight_OncMinTimeInActRegion = KeepOffReason_right.Bit.OncMinTimeInActRegion;
       
        DbgMsg.HLAFKeepOffReason.PlusLeft_Unused                 = 0;
        DbgMsg.HLAFKeepOffReason.PlusRight_Unused                = 0;
      }
#endif
      break;
    default:
      DbgMsg.HLAVersion.NextState = (uint8)HLA_DDM_STATE__HLA_VERSION;
      break;  
  }

  *pDbgMsgOut = DbgMsg;
}


static void HLAFFillOutputDataMatrixBeam( /* input */
                                          const HLAFData_t *pFData,
                                          /* output */
                                          HLAF_t_Matrix *pMatrixOut
                                        )
{
  uint32 i;


  /* copy Matrix beam data */
  memcpy(pMatrixOut, &pFData->HLAMatrixOut.Matrix, sizeof(HLAF_t_Matrix));


  pMatrixOut->LowBeam_Dist = CML_f_MinMax( hlafMatrixParameter.Output.LowBeam_Dist_Min,
                                     hlafMatrixParameter.Output.LowBeam_Dist_Max,
                                     pMatrixOut->LowBeam_Dist
                                   );
  pMatrixOut->LowBeam_Ang  = CML_f_MinMax( hlafMatrixParameter.Output.LowBeam_Ang_Min,
                                     hlafMatrixParameter.Output.LowBeam_Ang_Max,
                                     pMatrixOut->LowBeam_Ang
                                   );
  

  /* limit outputs values/ set to default */
  for(i=0; i<RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    if(i < pMatrixOut->nGFA)
    {
      /* limit outputs */
      pMatrixOut->GFA[i].BndryLeft_Ang = CML_f_MinMax( hlafMatrixParameter.Output.BndryLeft_Ang_Min,
                                                 hlafMatrixParameter.Output.BndryLeft_Ang_Max,
                                                 pMatrixOut->GFA[i].BndryLeft_Ang
                                               );
      pMatrixOut->GFA[i].BndryLeft_Ang_Cam = CML_f_MinMax( hlafMatrixParameter.Output.BndryLeft_Ang_Min,
                                                     hlafMatrixParameter.Output.BndryLeft_Ang_Max,
                                                     pMatrixOut->GFA[i].BndryLeft_Ang_Cam
                                                   );
      pMatrixOut->GFA[i].BndryRight_Ang = CML_f_MinMax( hlafMatrixParameter.Output.BndryRight_Ang_Min,
                                                  hlafMatrixParameter.Output.BndryRight_Ang_Max,
                                                  pMatrixOut->GFA[i].BndryRight_Ang
                                                );
      pMatrixOut->GFA[i].BndryRight_Ang_Cam = CML_f_MinMax( hlafMatrixParameter.Output.BndryRight_Ang_Min,
                                                      hlafMatrixParameter.Output.BndryRight_Ang_Max,
                                                      pMatrixOut->GFA[i].BndryRight_Ang_Cam
                                                    );
      pMatrixOut->GFA[i].BndryLower_Ang_Cam = CML_f_MinMax( hlafMatrixParameter.Output.BndryLower_Ang_Min,
                                                      hlafMatrixParameter.Output.BndryLower_Ang_Max,
                                                      pMatrixOut->GFA[0].BndryLower_Ang_Cam
                                                    );
      pMatrixOut->GFA[i].ClosestObj_Dist = CML_f_MinMax( hlafMatrixParameter.Output.ClosestObj_Dist_Min,
                                                   hlafMatrixParameter.Output.ClosestObj_Dist_Max,
                                                   pMatrixOut->GFA[i].ClosestObj_Dist
                                                 );
      pMatrixOut->GFA[i].ClosestObj_Ang = CML_f_MinMax( hlafMatrixParameter.Output.ClosestObj_Ang_Min,
                                                  hlafMatrixParameter.Output.ClosestObj_Ang_Max,
                                                  pMatrixOut->GFA[i].ClosestObj_Ang
                                                );
      pMatrixOut->GFA[i].MinLight_Dist = CML_f_MinMax( hlafMatrixParameter.Output.MinLight_Dist_Min,
                                                 hlafMatrixParameter.Output.MinLight_Dist_Max,
                                                 pMatrixOut->GFA[i].MinLight_Dist
                                               );
      pMatrixOut->GFA[i].MinLight_Ang = CML_f_MinMax( hlafMatrixParameter.Output.MinLight_Ang_Min,
                                                hlafMatrixParameter.Output.MinLight_Ang_Max,
                                                pMatrixOut->GFA[i].MinLight_Ang
                                              );

      pMatrixOut->GFA[i].ttb18Left           = 0;
      pMatrixOut->GFA[i].ttb18Left_Status    = RTE_HLAF_TTBSTA_NO_OBJ;

      pMatrixOut->GFA[i].ttb18Right          = 0;
      pMatrixOut->GFA[i].ttb18Right_Status   = RTE_HLAF_TTBSTA_NO_OBJ;

      pMatrixOut->GFA[i].ExistenceProb       = 100;
    }
    else
    {
      /* set to default */
      pMatrixOut->GFA[i].BndryLeft_Ang      = hlafMatrixParameter.Output.BndryLeft_Ang_Default;
      pMatrixOut->GFA[i].BndryLeft_Ang_Cam  = hlafMatrixParameter.Output.BndryLeft_Ang_Default;
      pMatrixOut->GFA[i].BndryLeft_Status   = RTE_HLAF_OBJSTA_NO_OBJ;

      pMatrixOut->GFA[i].BndryRight_Ang      = hlafMatrixParameter.Output.BndryRight_Ang_Default;
      pMatrixOut->GFA[i].BndryRight_Ang_Cam  = hlafMatrixParameter.Output.BndryRight_Ang_Default;
      pMatrixOut->GFA[i].BndryRight_Status   = RTE_HLAF_OBJSTA_NO_OBJ;

      pMatrixOut->GFA[i].BndryLower_Ang_Cam  = hlafMatrixParameter.Output.BndryLower_Ang_Default;
      pMatrixOut->GFA[i].BndryLower_Status   = RTE_HLAF_OBJSTA_NO_OBJ;

      pMatrixOut->GFA[i].ClosestObj_Dist     = hlafMatrixParameter.Output.ClosestObj_Dist_Default;
      pMatrixOut->GFA[i].ClosestObj_Ang      = hlafMatrixParameter.Output.ClosestObj_Ang_Default;
      pMatrixOut->GFA[i].ClosestObj_Status   = RTE_HLAF_OBJSTA_NO_OBJ;

      pMatrixOut->GFA[i].MinLight_Dist       = hlafMatrixParameter.Output.MinLight_Dist_Default;
      pMatrixOut->GFA[i].MinLight_Ang        = hlafMatrixParameter.Output.MinLight_Ang_Default;
      pMatrixOut->GFA[i].MinLight_Status     = RTE_HLAF_OBJSTA_NO_OBJ;

      pMatrixOut->GFA[i].ttb18Left           = 0;
      pMatrixOut->GFA[i].ttb18Left_Status    = RTE_HLAF_TTBSTA_NO_OBJ;

      pMatrixOut->GFA[i].ttb18Right          = 0;
      pMatrixOut->GFA[i].ttb18Right_Status   = RTE_HLAF_TTBSTA_NO_OBJ;

      pMatrixOut->GFA[i].ExistenceProb = 0;
    }
  }
}


static void HLAFFillOutputData( /* input */
                                const HLAF_t_RequiredInputs    *ps_In,
                                const HLAFData_t               *pFData,
                                const RTE_HLAR_BrightnessState e_Brightness,
                                const HLAFParameter_t          *pFPar,
                                /* output */
                                HLAF_t_ProvidedOutputs         *ps_Out,
                                HLA_t_SystemInfo               *ps_SystemInfo
                              )
{
  /* init output: memset of all data to zero, status = unknown */
  HLAFInitOutput( /* input */
                  /* output */ 
                  ps_Out
                );
  /* fill all data unequal to zero/ unknown status */
  

  /* copy interface version number, HLA/ HLAF SW version number and frame counter */
  /* into output data */
  ps_Out->ui32_InterfaceVersionNumber = HLAF_OUT_INTERFACE_VERSION_NUMBER;
  ps_Out->ui32_HLA_SWVersionNumber    = HLA_SW_VERSION_NUMBER;
  ps_Out->ui32_HLAF_SWVersionNumber   = HLAF_SW_VERSION_NUMBER;
  ps_Out->uiFrameCnt                  = pFData->FrameCnt;

  /* set HLA and image timestamps */
  ps_Out->uiTimeStamp_HLA_us          = ps_In->uiTimeStamp_HLA_us;
  ps_Out->uiTimeStamp_Image_us        = ps_In->uiTimeStamp_Image_us;

  /* copy counter to output struct */
  ps_Out->uiHLAF_Cnt                  = pFData->HLAF_Cnt;


  /********************************/
  /* set headlight control output */
  /* and blockage output          */
  /********************************/
  ps_Out->s_HeadlightControl.e_State = RTE_HLA_STATE_ACTV;
  if(    (ps_In->s_Par.ps_HlaPar->Country.SensitivityMode == RTE_HLA_SENSMODE_US) 
      && (ps_In->s_Sig.ps_Avl->e_USSens == RTE_HLA_US_SENS_ON)
    )
  {
    ps_Out->s_HeadlightControl.s_Common.e_SensMode = RTE_HLA_SENSMODE_US;
  }
  else
  {
    ps_Out->s_HeadlightControl.s_Common.e_SensMode = RTE_HLA_SENSMODE_NORMAL;
  }

  /* traffic style verified during this ignition cycle ? */
  /* -> report current traffic style                     */
  if(ps_In->s_Sig.ps_Environment->e_TrafficStyleState == RTE_HLAR_TRAFFIC_STATE_LEARN)
  {
    if(pFData->DecisionOut.TrafficStyle.eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_RHD)
    {
      ps_Out->s_HeadlightControl.s_Common.e_TrafficStyle = RTE_HLA_TRAFFIC_STYLE_RHD;
    }
    else if(pFData->DecisionOut.TrafficStyle.eTrafficStyle == RTE_HLA_TRAFFIC_STYLE_LHD)
    {
      ps_Out->s_HeadlightControl.s_Common.e_TrafficStyle = RTE_HLA_TRAFFIC_STYLE_LHD;
    }
    else 
    {
      ps_Out->s_HeadlightControl.s_Common.e_TrafficStyle = RTE_HLA_TRAFFIC_STYLE_UNKNOWN;
    }
  }
  else
  {
    ps_Out->s_HeadlightControl.s_Common.e_TrafficStyle = RTE_HLA_TRAFFIC_STYLE_UNKNOWN;
  }
  if(pFData->DecisionOut.eCityState == RTE_HLAR_CITY_DTCD)
  {
    ps_Out->s_HeadlightControl.s_Common.e_CityState = RTE_HLAR_CITY_DTCD;
  }
  else
  {
    ps_Out->s_HeadlightControl.s_Common.e_CityState = RTE_HLAR_CITY_NOT_DTCD;
  }
  ps_Out->s_HeadlightControl.s_Common.e_TunnelState     = pFData->DecisionOut.eTunnelState;
  ps_Out->s_HeadlightControl.s_Common.e_MotorwayState   = pFData->DecisionOut.Motorway.eStateExt;
  ps_Out->s_HeadlightControl.s_Common.e_BrightnessState = pFData->DecisionOut.eBrightnessState;
  ps_Out->s_HeadlightControl.s_Common.e_WeatherState    = pFData->DecisionOut.eWeatherState;
  ps_Out->s_Blockage                                    = pFData->DecisionOut.Blockage;


  if(pFData->DecisionData.TurnOffReason_glob.Reason.Bit.MinSpeed == 1)
  {
    ps_Out->s_HeadlightControl.s_Common.e_SpeedState = RTE_HLAF_SPEEDSTATE_LOW;
  }
  else
  {
    ps_Out->s_HeadlightControl.s_Common.e_SpeedState = RTE_HLAF_SPEEDSTATE_HIGH;
  }

  if(pFData->DecisionData.TurnOffReason_glob.Reason.Bit.Lights ==  1)
  {
    ps_Out->s_HeadlightControl.s_Common.e_RuntimeState = HLAF_RUNTIMESTATE_ABORTED;
  }
  else
  {
    ps_Out->s_HeadlightControl.s_Common.e_RuntimeState = HLAF_RUNTIMESTATE_NORMAL;
  }

  

  /* set matrix beam output */
  HLAFFillOutputDataMatrixBeam( /* input */
                                pFData,
                                /* output */
                                &ps_Out->s_HeadlightControl.Matrix
                              );
    


  /* HLA Matrix beam */
  if(    /* paid function = plus (CAN/ FR signal) */
         (ps_In->s_Sig.ps_Avl->e_Type == RTE_HLA_TYPE_MATRIX)
         /* headlight supports hla matrix beam (SCN coding) */
           && (   (ps_In->s_Par.ps_HlaPar->HLAType == RTE_HLA_TYPE_MATRIX)
               || (ps_In->s_Par.ps_HlaPar->HLAType == RTE_HLA_TYPE_LIGHT)
              )
          )
  {
    /**************/
    /* HLA Matrix */
    /**************/
    ps_Out->s_HeadlightControl.e_Type = RTE_HLA_TYPE_MATRIX;
  }  
  /* HLA Plus */
  else if(    /* paid function = plus (CAN/ FR signal) */
              (ps_In->s_Sig.ps_Avl->e_Type == RTE_HLA_TYPE_PLUS)
              /* headlight supports hla plus (SCN coding) */
           && (ps_In->s_Par.ps_HlaPar->HLAType == RTE_HLA_TYPE_PLUS)

              /* traffic style learned during this ignition cycle                */
              /* or not in symmetric light (tourism mode)                        */
              /* -> HLA plus not available because traffic style is not verified */
              /*    HLA Plus could blind oncoming vehicles                       */
              /* -> switch to HLA Standard                                       */ 
           && (    (ps_In->s_Sig.ps_Environment->e_TrafficStyleState == RTE_HLAR_TRAFFIC_STATE_LEARN)
                || (pFData->DecisionOut.LightStyle.eLightStyle == HLAF_LIGHTSTYLE_COUNTRY)
                || (pFData->DecisionOut.LightStyle.eLightStyle == HLAF_LIGHTSTYLE_MOTORWAY)
              )
         )
  {
    /************/
    /* HLA Plus */
    /************/
    ps_Out->s_HeadlightControl.e_Type  = RTE_HLA_TYPE_PLUS;

    /* any global turn off reason ? */
    if(pFData->DecisionData.TurnOffReason_glob.Reason.u32 == 0)
    {
      /* no global turn off reason */
      /* HLA Standard */
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_LevelState                   = HLAF_LEVELSTATE_ON;
      ps_Out->s_HeadlightControl.s_PlusStdLight.LowBeam_Status                 = pFData->HLAStdOut.eTargetDrivingDirection;
      /* HLA Plus */      
      ps_Out->s_HeadlightControl.s_PlusStdLight.f32_RotAngleMin_Lt             = pFData->HLAPlusOut.RotAngleMin_Lt;
      ps_Out->s_HeadlightControl.s_PlusStdLight.f32_RotAngleMin_Rt             = pFData->HLAPlusOut.RotAngleMin_Rt;
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_LightOutput_Lt               = CML_Min(pFData->DecisionOut.eLightOutput_Lt, pFData->HLAPlusOut.eLightOutput_Lt);
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_LightOutput_Rt               = CML_Min(pFData->DecisionOut.eLightOutput_Rt, pFData->HLAPlusOut.eLightOutput_Rt);
      ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Lt = pFData->HLAPlusOut.ChangeoverLevel_Lt;
      ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Rt = pFData->HLAPlusOut.ChangeoverLevel_Rt;
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState_Lt             = pFData->HLAPlusOut.eHighBeamState_Lt;
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState_Rt             = pFData->HLAPlusOut.eHighBeamState_Rt;


      /* synchronize HLA /HLA plus high beam output */
      if(    (    (pFData->HLAPlusOut.eHighBeamState_Lt == RTE_HLAF_HB_STATE_FULL_ON)
               && (pFData->HLAPlusOut.eHighBeamState_Rt == RTE_HLAF_HB_STATE_FULL_ON) 
             )
          || (    (pFData->HLAPlusOut.eHighBeamState_Lt == RTE_HLAF_HB_STATE_SPOT)
               && (pFData->HLAPlusOut.eHighBeamState_Rt == RTE_HLAF_HB_STATE_FULL_ON) 
             )
          || (    (pFData->HLAPlusOut.eHighBeamState_Lt == RTE_HLAF_HB_STATE_FULL_ON)
               && (pFData->HLAPlusOut.eHighBeamState_Rt == RTE_HLAF_HB_STATE_SPOT) 
             )
        )
      {
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState      = RTE_HLAF_HB_STATE_FULL_ON;
        ps_Out->s_HeadlightControl.s_PlusStdLight.f32_LowBeamDist      = pFPar->HLAStandard.LightDistance.MaxLightingDist;
        ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_ChangeoverLevel  = pFPar->HLAStandard.ChangeOverLevel.TurnOnHigh;
      }
      else
      {
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState      = RTE_HLAF_HB_STATE_OFF;
        ps_Out->s_HeadlightControl.s_PlusStdLight.f32_LowBeamDist      = pFData->HLAStdOut.LowBeamDist;
        ps_Out->s_HeadlightControl.s_PlusStdLight.f32_LowBeamAngle     = pFData->HLAStdOut.LowBeamAngle;
        ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_ChangeoverLevel  = pFData->HLAStdOut.ChangeoverLevel;
      }
    }
    else
    {
      /* global turn off */
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState          = RTE_HLAF_HB_STATE_OFF;
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState_Lt       = RTE_HLAF_HB_STATE_OFF;
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState_Rt       = RTE_HLAF_HB_STATE_OFF;
      ps_Out->s_HeadlightControl.s_PlusStdLight.f32_LowBeamDist          = pFPar->HLAStandard.LightDistance.MinLightingDist;
      ps_Out->s_HeadlightControl.s_PlusStdLight.LowBeam_Status           = RTE_HLAF_OBJSTA_NO_OBJ;
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_LightOutput_Lt         = RTE_HLAF_LIGHTOUTPUT_STD; 
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_LightOutput_Rt         = RTE_HLAF_LIGHTOUTPUT_STD;

      /* transition from HB on to off completed ? */
      /* after startup of camera Timer_TurnOffActive_s is set to UI16_T_MAX */
      /* ~CodeReview ~ID:f183ec6a5a256190fde9adcaa7969f60 ~Reviewer:CW01\muellerr5 ~Date:17.07.2012 ~Priority:3 ~Comment:magic number */
      if(pFData->DecisionData.TurnOffReason_glob.Timer_TurnOffActive_s > 1.0f)
      {
        /* after 1 sec the headlamps should be switched off */
        if(    (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.NotAvl == 1)
            || (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.NotCalibrated == 1)
            || (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.Blockage == 1)
               /* still in clearance measurement */
            || (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.NotReleased == 1)
            || (e_Brightness < RTE_HLAR_BRT_TWLGT_3)
          )
        {
          ps_Out->s_HeadlightControl.s_PlusStdLight.e_LevelState = HLAF_LEVELSTATE_OFF;
        }
        else
        {
          ps_Out->s_HeadlightControl.s_PlusStdLight.e_LevelState = HLAF_LEVELSTATE_ON;
        }
        ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_ChangeoverLevel            = pFData->HLAStdOut.ChangeoverLevel;
        ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Lt = (uint8)(0.5f * (pFData->HLAStdOut.ChangeoverLevel + 1));
        ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Rt = ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Lt;
      }
      else
      {
        /* still switching HB off */
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_LevelState                   = HLAF_LEVELSTATE_ON;
        ps_Out->s_HeadlightControl.s_PlusStdLight.f32_RotAngleMin_Lt             = pFData->HLAPlusOut.RotAngleMin_Lt;
        ps_Out->s_HeadlightControl.s_PlusStdLight.f32_RotAngleMin_Rt             = pFData->HLAPlusOut.RotAngleMin_Rt;
        ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_ChangeoverLevel            = pFData->HLAStdOut.ChangeoverLevel;
        ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Lt = pFData->HLAPlusOut.ChangeoverLevel_Lt;
        ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Rt = pFData->HLAPlusOut.ChangeoverLevel_Rt;
      }
    }  
  }
  /* HLA Standard */
  else if(    /* paid function = standard or plus (CAN/ FR signal) */
              (    (ps_In->s_Sig.ps_Avl->e_Type == RTE_HLA_TYPE_STANDARD)
                || (ps_In->s_Sig.ps_Avl->e_Type == RTE_HLA_TYPE_PLUS)
              )
              /* headlight supports hla standard or plus (SCN Coding) */
           && (   (ps_In->s_Par.ps_HlaPar->HLAType == RTE_HLA_TYPE_STANDARD)
               || (ps_In->s_Par.ps_HlaPar->HLAType == RTE_HLA_TYPE_PLUS)
              )
         )
  {
    /****************/
    /* HLA Standard */
    /****************/
    ps_Out->s_HeadlightControl.e_Type  = RTE_HLA_TYPE_STANDARD;
    /* any global turn off reason ? */
    if(pFData->DecisionData.TurnOffReason_glob.Reason.u32 == 0)
    {
      /* no global turn off reason */
      /* HLA Standard */
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_LevelState                   = HLAF_LEVELSTATE_ON;
      ps_Out->s_HeadlightControl.s_PlusStdLight.f32_LowBeamAngle               = pFData->HLAStdOut.LowBeamAngle;
      ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_ChangeoverLevel            = pFData->HLAStdOut.ChangeoverLevel;
      ps_Out->s_HeadlightControl.s_PlusStdLight.LowBeam_Status                 = pFData->HLAStdOut.eTargetDrivingDirection;
      /* HLA Plus */      
      ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Lt = (uint8)(0.5f * (pFData->HLAStdOut.ChangeoverLevel + 1));
      ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Rt = ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Lt;
      

      /* synchronize HLA /HLA plus high beam output */
      /* set high beam state to output data */
      if(hlafData.HLAStdOut.eHighBeamState == RTE_HLAF_HB_STATE_FULL_ON)
      {
        /* high beam on */
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState    = RTE_HLAF_HB_STATE_FULL_ON;
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState_Lt = RTE_HLAF_HB_STATE_FULL_ON;
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState_Rt = RTE_HLAF_HB_STATE_FULL_ON;
        ps_Out->s_HeadlightControl.s_PlusStdLight.f32_LowBeamDist    = pFPar->HLAStandard.LightDistance.MaxLightingDist;
        /* light output */
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_LightOutput_Lt   = pFData->DecisionOut.eLightOutput_Lt;
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_LightOutput_Rt   = pFData->DecisionOut.eLightOutput_Rt;
      }
      else
      {
        /* high beam off */
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState    = RTE_HLAF_HB_STATE_OFF;
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState_Lt = RTE_HLAF_HB_STATE_OFF;
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState_Rt = RTE_HLAF_HB_STATE_OFF;
        ps_Out->s_HeadlightControl.s_PlusStdLight.f32_LowBeamDist    = pFData->HLAStdOut.LowBeamDist;
        /* light output */
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_LightOutput_Lt   = RTE_HLAF_LIGHTOUTPUT_STD;
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_LightOutput_Rt   = RTE_HLAF_LIGHTOUTPUT_STD;
      } 
    }
    else
    {
      /* global turn off */
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState                = RTE_HLAF_HB_STATE_OFF;
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState_Lt             = RTE_HLAF_HB_STATE_OFF;
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState_Rt             = RTE_HLAF_HB_STATE_OFF;
      ps_Out->s_HeadlightControl.s_PlusStdLight.f32_LowBeamDist                = pFPar->HLAStandard.LightDistance.MinLightingDist;
      ps_Out->s_HeadlightControl.s_PlusStdLight.LowBeam_Status                 = RTE_HLAF_OBJSTA_NO_OBJ;
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_LightOutput_Lt               = RTE_HLAF_LIGHTOUTPUT_STD; 
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_LightOutput_Rt               = RTE_HLAF_LIGHTOUTPUT_STD;
      

      /* transition from HB on to off completed ? */
      /* after startup of camera Timer_TurnOffActive_s is set to UI16_T_MAX */
      /* ~CodeReview ~ID:7e1d639f25e38662f1f3df047e6c860a ~Reviewer:CW01\muellerr5 ~Date:17.07.2012 ~Priority:3 ~Comment:magic number */
      if(pFData->DecisionData.TurnOffReason_glob.Timer_TurnOffActive_s > 1.0f)
      {
        /* after 1 sec the headlamps should be switched off */
        if(    (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.NotAvl == 1)
            || (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.NotCalibrated == 1)
            || (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.Blockage == 1)
               /* still in clearance measurement */
            || (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.NotReleased == 1)
            || (e_Brightness < RTE_HLAR_BRT_TWLGT_3)
          )
        {
          ps_Out->s_HeadlightControl.s_PlusStdLight.e_LevelState = HLAF_LEVELSTATE_OFF;
        }
        else
        {
          ps_Out->s_HeadlightControl.s_PlusStdLight.e_LevelState = HLAF_LEVELSTATE_ON;
        }
        ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_ChangeoverLevel            = pFData->HLAStdOut.ChangeoverLevel;
        ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Lt = (uint8)(0.5f * (pFData->HLAStdOut.ChangeoverLevel + 1));
        ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Rt = ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Lt;
      }
      else
      {
        /* still switching HB off */
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_LevelState = HLAF_LEVELSTATE_ON;

        ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_ChangeoverLevel            = pFData->HLAStdOut.ChangeoverLevel;
        ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Lt = pFData->HLAPlusOut.ChangeoverLevel_Lt;
        ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Rt = pFData->HLAPlusOut.ChangeoverLevel_Rt;
      }
    }  
  }
  /* HLA Light (binary) */
  else if(    /* paid function = light, standard or plus (CAN/ FR signal) */
              (    (ps_In->s_Sig.ps_Avl->e_Type == RTE_HLA_TYPE_LIGHT)
                || (ps_In->s_Sig.ps_Avl->e_Type == RTE_HLA_TYPE_STANDARD)
                || (ps_In->s_Sig.ps_Avl->e_Type == RTE_HLA_TYPE_PLUS)
              )
              /* headlight supports hla light (SCN coding) */
           && (   (ps_In->s_Par.ps_HlaPar->HLAType == RTE_HLA_TYPE_LIGHT)
               || (ps_In->s_Par.ps_HlaPar->HLAType == RTE_HLA_TYPE_STANDARD)
               || (ps_In->s_Par.ps_HlaPar->HLAType == RTE_HLA_TYPE_PLUS)
              )
         )
  {
    /****************/
    /* HLA Light    */
    /****************/
    ps_Out->s_HeadlightControl.e_Type  = RTE_HLA_TYPE_LIGHT;
    
    /* any global turn off reason ? */
    if(pFData->DecisionData.TurnOffReason_glob.Reason.u32 == 0)
    {
      /* no global turn off reason */
      /* HLA Active and available */
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_LevelState                   = HLAF_LEVELSTATE_OFF;
      ps_Out->s_HeadlightControl.s_PlusStdLight.f32_LowBeamAngle               = pFData->HLAStdOut.LowBeamAngle;
      ps_Out->s_HeadlightControl.s_PlusStdLight.LowBeam_Status                 = pFData->HLAStdOut.eTargetDrivingDirection;
      /* HLA Plus */      
      ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_ChangeoverLevel            = pFPar->HLAStandard.ChangeOverLevel.Max;
      ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Lt = (uint8)(0.5f * (ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_ChangeoverLevel + 1));
      ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Rt = ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Lt;
      
      /* synchronize HLA /HLA plus high beam output */
      /* set high beam state to output data */
      if(hlafData.HLALightOut.eHighBeamState == RTE_HLAF_HB_STATE_FULL_ON)
      {
        /* high beam on */
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState    = RTE_HLAF_HB_STATE_FULL_ON;
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState_Lt = RTE_HLAF_HB_STATE_FULL_ON;
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState_Rt = RTE_HLAF_HB_STATE_FULL_ON;
        ps_Out->s_HeadlightControl.s_PlusStdLight.f32_LowBeamDist    = pFPar->HLAStandard.LightDistance.MaxLightingDist;
        /* light output */
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_LightOutput_Lt   = pFData->DecisionOut.eLightOutput_Lt;
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_LightOutput_Rt   = pFData->DecisionOut.eLightOutput_Rt;
      }
      else
      {
        /* high beam off */
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState    = RTE_HLAF_HB_STATE_OFF;
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState_Lt = RTE_HLAF_HB_STATE_OFF;
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState_Rt = RTE_HLAF_HB_STATE_OFF;
        ps_Out->s_HeadlightControl.s_PlusStdLight.f32_LowBeamDist    = pFPar->HLAStandard.LightDistance.MinLightingDist;
        /* light output */
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_LightOutput_Lt   = RTE_HLAF_LIGHTOUTPUT_STD;
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_LightOutput_Rt   = RTE_HLAF_LIGHTOUTPUT_STD;
      } 
    }
    else
    {
      /* global turn off */
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState                = RTE_HLAF_HB_STATE_OFF;
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState_Lt             = RTE_HLAF_HB_STATE_OFF;
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_HighBeamState_Rt             = RTE_HLAF_HB_STATE_OFF;
      ps_Out->s_HeadlightControl.s_PlusStdLight.f32_LowBeamDist                = pFPar->HLAStandard.LightDistance.MinLightingDist;
      ps_Out->s_HeadlightControl.s_PlusStdLight.LowBeam_Status                 = RTE_HLAF_OBJSTA_NO_OBJ;
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_LightOutput_Lt               = RTE_HLAF_LIGHTOUTPUT_STD; 
      ps_Out->s_HeadlightControl.s_PlusStdLight.e_LightOutput_Rt               = RTE_HLAF_LIGHTOUTPUT_STD;
      ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_ChangeoverLevel            = pFPar->HLAStandard.ChangeOverLevel.Max;
      ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Lt = (uint8)(0.5f * (ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_ChangeoverLevel + 1));
      ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Rt = ps_Out->s_HeadlightControl.s_PlusStdLight.ui8_HLAPlus_ChangeoverLevel_Lt;

      /* transition from HB on to off completed ? */
      /* after startup of camera Timer_TurnOffActive_s is set to UI16_T_MAX */
      /* ~CodeReview ~ID:c56f29fae327b7fcaf810eb5023708df ~Reviewer:CW01\muellerr5 ~Date:17.07.2012 ~Priority:3 ~Comment:magic number */
      if(pFData->DecisionData.TurnOffReason_glob.Timer_TurnOffActive_s > 1.0f)
      {
        /* after 1 sec the headlamps should be switched off */
        if(    (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.NotAvl == 1)
            || (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.NotCalibrated == 1)
            || (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.Blockage == 1)
               /* still in clearance measurement */
            || (pFData->DecisionData.TurnOffReason_glob.Reason.Bit.NotReleased == 1)
            || (e_Brightness < RTE_HLAR_BRT_TWLGT_3)
          )
        {
          ps_Out->s_HeadlightControl.s_PlusStdLight.e_LevelState = HLAF_LEVELSTATE_OFF;
        }
        else
        {
          ps_Out->s_HeadlightControl.s_PlusStdLight.e_LevelState = HLAF_LEVELSTATE_ON;
        }
      }
      else
      {
        /* still switching HB off */
        ps_Out->s_HeadlightControl.s_PlusStdLight.e_LevelState = HLAF_LEVELSTATE_ON;
      }
    }
  }
  else
  {
    /* 1. e_Type = RTE_HLA_TYPE_NAVL -> function not paid                                         */
    /* 2. or SCN coding (e_HeadLightMode) not matching to paid Bits (e_Type) -> report Error  */
    /*    e.g. e_Type = RTE_HLA_TYPE_BINARY (function paid)                                       */
    /*              and e_HeadLightMode != RTE_HLA_LMODE_LIGHT                                    */
    
    /* should never come into this state */
    ps_Out->s_HeadlightControl.e_Type = RTE_HLA_TYPE_NAVL;
  }

  /* SCN coding (e_HeadLightMode) not matching to paid Bits (e_Type)  */
  /*    e.g.     e_Type = RTE_HLA_TYPE_BINARY (function paid)             */
  /*         and e_HeadLightMode != RTE_HLA_LMODE_LIGHT                   */
  /* -> set error                                                     */
  if(    /* no hla function -> no Highbeams */ 
          (ps_Out->s_HeadlightControl.e_Type == RTE_HLA_TYPE_NAVL)
          /* any hla function paid (Light, Standard or Plus) */
      && (ps_In->s_Sig.ps_Avl->e_Type != RTE_HLA_TYPE_NAVL)
    ) 
  {  
    ps_SystemInfo->errors.error[HLA_ERRORID_VEHICLE_DATA].status  = HLA_ERRORSTATUS_CHECK_DONE_AND_FAILED;
    ps_SystemInfo->errors.error[HLA_ERRORID_VEHICLE_DATA].optData = HLA_ERRORID_OPTDATA_VEHICLE_SCN_HEADLIGHTMODE_MISMATCH;
  }
}


/* **************************************************************************** 
  Functionname:     HLAFInitData */ /*!
  Description:      Fills data (parameter, signal).

  @param[in]        HLAFRequiredInputs_t  *pHlafReqIn   required input for HLAF
  @param[out]       HLAFProvidedOutputs_t *pHlafProOut  provided output from HLAF

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
static void HLAFInitData( const HLAF_t_RequiredInputs  *pHlafReqIn,
                          HLAFData_t                   *pFData
                        )
{
  /* init hlaf internal data */
  (void)memset((void*)pFData ,0, sizeof(HLAFData_t));
  pFData->FrameCnt           = pHlafReqIn->uiFrameCnt;
  pFData->TimeStamp_HLA_us   = pHlafReqIn->uiTimeStamp_HLA_us;  
  pFData->TimeStamp_Image_us = pHlafReqIn->uiTimeStamp_Image_us;

  /* init timer with UI16_T_MAX                               */
  /* assumption after startup of camera: HB off for long time */
  pFData->DecisionData.TurnOffReason_glob.Timer_TurnOffActive_s = UI16_T_MAX;
}


/* **************************************************************************** 
  Functionname:     HLAFInitOutput                                       */ /*!
  Description:      Init target output data

  @param[in]        
  @param[in,out]    
  @param[out]       

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAFInitOutput( /* input */
                            /* output */ 
                            HLAF_t_ProvidedOutputs *ps_Out
                          )
{
  HLA_t_DiagnosisDebugMsg DiagnosisDebugMsg = ps_Out->s_DiagnosisDebugMsg;
  (void)memset((void*)ps_Out, 0, sizeof(HLAF_t_ProvidedOutputs));
  ps_Out->s_DiagnosisDebugMsg = DiagnosisDebugMsg;

}

/* **************************************************************************** 
  Functionname:     HLAFFillCameraData                                    */ /*!
  Description:      Fills camera data.

  @param[in]
  @param[out]

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAFFillCameraData( /* input */
                                const HLAF_t_RequiredInputs  *pIn,
                                const HLAFData_t             *pFData,
                                /* output */ 
                                HLAFCameraData_t             *pCamData
                              )
{
  /* calc dCycle */
  if(pFData->HLAF_Cnt > 1)
  {
    /* not the first run */
    sint32 dFrame = (sint32)((pIn->uiFrameCnt & MAX_FRAMENUMBER) - (pFData->FrameCnt & MAX_FRAMENUMBER));

    if(   (dFrame <  MAX_DFRAME)
       && (dFrame > -MAX_DFRAME)
      )
    {
      pCamData->dCycle = dFrame/2;
    }
    else if(dFrame < -(MAX_FRAMENUMBER-MAX_DFRAME))
    {
      /* wrap around */
      pCamData->dCycle = (dFrame + (MAX_FRAMENUMBER + 1))/2;
    }
    else if(dFrame > (MAX_FRAMENUMBER-MAX_DFRAME))
    {
      /* wrap around */
      pCamData->dCycle = (dFrame - (MAX_FRAMENUMBER + 1))/2;
    }
    else
    {
      /* frame jump > MAX_DFRAME */
      pCamData->dCycle = MAX_DFRAME/2;
    }
  }
  else
  {
    /* first run */
    pCamData->dCycle = 1;
  }

  pCamData->dtime_s    = abs(pCamData->dCycle) * pIn->s_Par.ps_CameraParameter->f32_cycleTime;
  pCamData->ddist_m    = pCamData->dtime_s * pIn->s_Sig.ps_MotionState->f32_Speed;
  if(pIn->s_Sig.ps_MotionState->e_MoveState == HLA_MOVE_STATE_FWD)
  {
    pCamData->dtimeFwd_s = pCamData->dtime_s;
    pCamData->ddistFwd_m = pCamData->ddist_m;
  }
  else
  {
    pCamData->dtimeFwd_s = 0.0f;
    pCamData->ddistFwd_m = 0.0f;
  }
  
  /* compute radius of curve */
  /* ~CodeReview ~ID:248a43c8ed0579513dcb7bf89546dc9e ~Reviewer:CW01\muellerr5 ~Date:17.07.2012 ~Priority:3 ~Comment:magic number */
  if(fabs(pIn->s_Sig.ps_MotionState->f32_YawRate) >0.001f)
  {
    pCamData->radius_m    = (pIn->s_Sig.ps_MotionState->f32_Speed/ pIn->s_Sig.ps_MotionState->f32_YawRate);
  }
  else
  {
    /* ~CodeReview ~ID:d037d643d6cadee7cba71f06e50a2c17 ~Reviewer:CW01\muellerr5 ~Date:17.07.2012 ~Priority:3 ~Comment:magic number */
    pCamData->radius_m = 100000.0f;
  }
  pCamData->radiusAbs_m = CML_f_Abs(pCamData->radius_m);

}

/* **************************************************************************** 
  Functionname:     HLAFFillData */ /*!
  Description:      Fills hlaf internal data.

  @param[in]
  @param[out]

  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAFFillData( /* input */
                          const HLAF_t_RequiredInputs  *pIn,
                          /* output */
                          HLAFData_t                   *pFData
                        )
{
  /* fill camera data */
  HLAFFillCameraData( pIn,
                      pFData,
                      /* output */
                      &pFData->CamData
                    );

  /* fill frame counter, timestamps,... */
  pFData->FrameCnt           = pIn->uiFrameCnt;
  pFData->TimeStamp_HLA_us   = pIn->uiTimeStamp_HLA_us;  
  pFData->TimeStamp_Image_us = pIn->uiTimeStamp_Image_us;
  /* increment HLAF call counter */
  pFData->HLAF_Cnt++;
    
}


/* ****************************************************************************
  Functionname:     HLAF_v_Init */ /*!
  Description:      Initializes the HLAF-component only once after bootup.

  @param[in]        HLAFRequiredInputs_t  *pHlafReqIn   required input for HLAF
  @param[out]       HLAFProvidedOutputs_t *pHlafProOut  provided output from HLAF

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
void HLAF_v_Init( const HLAF_t_RequiredInputs  *ps_In,
                  HLAF_t_ProvidedOutputs       *ps_Out,
                  HLA_t_SystemInfo             *ps_SystemInfo,
                  const AS_t_ServiceFuncts     *Services
                 )
{
  uint32        HWTime_us;
  /* get current HW time */
  HWTime_us = Services->pfGetTimestampuS32();

#ifdef PC_SIM  /* only needed during simulation for old school evaluation based on MFC300 data */
  /* init HLA standard */
  HLAFLightInit(&hlafParameter.HLALight);

  /* init HLA standard */
  HLAFStandardInit(&hlafParameter.HLAStandard);

  /* init HLA plus */
  HLAFPlusInit(&hlafData.HLAPlusOut);
#endif

  /* Init HLAF data */
  HLAFInitData(ps_In, &hlafData);

  /* init HLA matrix */
  HLAFMatrixInit(&hlafData.HLAMatrixOut);

  /* Fill hlaf data */
  HLAFFillData( /* input */
                ps_In,
                /* output */
                &hlafData
              );

  /* init hlaf output data */
  HLAFInitOutput(ps_Out);
  
  /* fill output data */
  HLAFFillOutputData( /* input */
                      ps_In,
                      &hlafData,
                      ps_In->s_Sig.ps_Environment->e_Brightness,
                      &hlafParameter, 
                      /* output */ 
                      ps_Out,
                      ps_SystemInfo
                    );
  /* fill debug output data */
  HLAFFillDebugOutput( /* input data */
                       &hlafData,
                       /* output data */ 
                       &hlafDebugOutputs
                      );

  /* save init runtime */
  hlafDebugOutputs.timeMeas.dTimeInit_us = (Services->pfGetTimestampuS32() - HWTime_us);



  /* <ln_offset+2 PCLINT Error 715: reviewer name: Marcus Brunn date: 2011-10-04 reason: Interface to frame SW is agreed to provide more than is needed */
  /* <ln_offset+1 MISRA Rule 16.7: reviewer name: Marcus Brunn date: 2011-10-04 reason: Interface to frame SW is agreed to provide more than is needed */
}

/* ****************************************************************************
  Functionname:     HLAF_v_Exec */ /*!
  Description:      Executes HLA function.

  @param[in]        HLAFRequiredInputs_t  *pHlafReqIn   required input for HLAF
  @param[out]       HLAFProvidedOutputs_t *pHlafProOut  provided output from HLAF

  @return           -
  @pre              -
  @post             -
  @author           Carlos Almeida
**************************************************************************** */
void HLAF_v_Exec( const HLAF_t_RequiredInputs  *ps_In,
                  HLAF_t_ProvidedOutputs       *ps_Out,
                  HLA_t_SystemInfo             *ps_SystemInfo,
                  const AS_t_ServiceFuncts     *Services
                 )
{
  uint32        HWTime_us;
  uint32        TimeStart_us;

  /* get current HW time */
  HWTime_us = Services->pfGetTimestampuS32();

  /* Fill hlaf data */
  HLAFFillData( /* input */
                ps_In,
                /* output */
                &hlafData);

  TimeStart_us = Services->pfGetTimestampuS32();

  /* set light style like                 */
  /* symmetric, country or motorway light */
  HLAFDecicionLightStyle( /* input */
                          ps_In,
                          hlafData.CamData.dtimeFwd_s,
                          /* history */
                          &hlafData.DecisionData.LightStyle,
                          /* output */
                          &hlafData.DecisionOut.LightStyle
                        );

  /* traffic style */
  HLAFDecisionTrafficStyle( /* input */
                            ps_In->s_Sig.ps_Environment->e_TrafficStyle,
                            /* history */
                            &hlafData.DecisionData.TrafficStyle,
                            /* output */
                            &hlafData.DecisionOut.TrafficStyle
                          );

  /* speed high enough to switch on HBs */
  HLAFDecisionSpeed( /* input */
                     ps_In->s_Sig.ps_MotionState,
                     ps_In->s_Sig.ps_ObjectList,
                     hlafData.CamData.dtimeFwd_s,
                     ps_In->s_Par.s_HlafPar.Speed.DeactivateSpeed,
                     ps_In->s_Par.s_HlafPar.Speed.ActivateSpeed,
                     ps_In->s_Par.s_HlafPar.Speed.AlwaysActiveSpeed,
                     ps_In->s_Par.s_HlafPar.Speed.KeepOff_VeryLowSpeed,
                     ps_In->s_Par.s_HlafPar.Speed.KeepOff_LowRadius,
                     ps_In->s_Par.s_HlafPar.Speed.KeepOff_HighAcceleration,
                     ps_In->s_Par.s_HlafPar.Speed.KeepOff_AccTime,
                     ps_In->s_Par.s_HlafPar.Speed.KeepOff_Delay,
                     /* history */
                     &hlafData.DecisionData.Speed
                     /* output */
                   );

  /* blockage detection */
  HLAFDecisionBlockage( /* input */
                        &ps_In->s_Sig.s_Blockage,
                        &hlafParameter.Blockage,
                        &hlafData.CamData,
                        &hlafData.DecisionData.TurnOffReason_glob,
                        ps_In->s_Sig.ps_Avl->e_State,
                        /* history */
                        &hlafData.DecisionData.Blockage,
                        /* output */
                        &hlafData.DecisionOut.Blockage,
                        ps_SystemInfo
                      );
 
  /* environmental brightness */
  HLAFDecisionBrightness( /* input */
                          &ps_In->s_Sig.ps_Environment->e_Brightness,
                          /* history */
                          /* output */
                          &hlafData.DecisionOut.eBrightnessState
                          );

  /* city detection */
  HLAFDecisionCity( /* input */
                    ps_In->s_Sig.ps_Environment->e_City,
                    ps_In->s_Par.s_HlafPar.TurnOnDelay.City,
                    &hlafParameter.City,
                    ps_In->s_Sig.ps_Environment->e_Brightness,  
                    /* history */
                    &hlafData,
                    /* output */
                    &hlafData.DecisionOut.eCityState
                   );

  /* tunnel detection */ 
  HLAFDecisionTunnel( /* input */
                      ps_In->s_Sig.ps_Environment->e_Tunnel,
                      ps_In->s_Par.s_HlafPar.TurnOnDelay.Tunnel,
                      /* history */
                      &hlafData,
                      /* output */
                      &hlafData.DecisionOut.eTunnelState
                     );

  /* highway detection (internally/ externally used state)  */
  /* internal highway state (used by HLAF Light, Std, Plus) */
  HLAFDecisionHighway( /* input data */
                       b_TRUE, /* internally used by HLAF */     
                       &ps_In->s_Sig.ps_Environment->s_Highway,
                       &hlafParameter.Highway,
                       &hlafData,                       
                       ps_In->s_Sig.ps_Environment->e_Brightness,   
                       /* output */
                       &hlafData.DecisionOut.Motorway.eStateInt
                     );
  /* external highway state (FR/CAN output) */
  HLAFDecisionHighway( /* input data */
                       b_FALSE, /* externally used -> FR/CAN output */
                       &ps_In->s_Sig.ps_Environment->s_Highway,
                       &hlafParameter.Highway,
                       &hlafData,                       
                       ps_In->s_Sig.ps_Environment->e_Brightness,
                       /* output */
                       &hlafData.DecisionOut.Motorway.eStateExt
                     );
  
  HLAFDecisionWeather( /* input */
                       &ps_In->s_Sig.s_Blockage,
                       /* history */
                       &hlafData.DecisionData.Weather,
                       /* output */
                       &hlafData.DecisionOut.eWeatherState
                     );

  HLAFDecisionDimmedLight( /* input */
                           ps_In->s_Sig.ps_HeadlightState,
                           ps_In->s_Sig.ps_ObjectList,
                           /* history */
                           &hlafData.DecisionData.DimmedLight,
                           /* output */
                           &hlafData.DecisionOut.eLightOutput_Lt,
                           &hlafData.DecisionOut.eLightOutput_Rt
                         );

  /* set global turn off reason                             */
  /* like city, too bright, min speed, too many maxima, ... */
  HLAFDecisionSetTurnOffReasonGlob( ps_In->s_Sig.ps_Environment->e_Brightness,
                                    &ps_In->s_Par.ps_HlaPar->AlgoCfg,
                                    &hlafData,
                                    ps_In->s_Sig.ps_Avl,
                                    /* output */ 
                                    &hlafData.DecisionData.TurnOffReason_glob
                                  );
  
  hlafDebugOutputs.timeMeas.dTimeDecision_us = (Services->pfGetTimestampuS32() - TimeStart_us);
  

#ifdef PC_SIM  /* only needed during simulation for old school evaluation based on MFC300 data */
  TimeStart_us = Services->pfGetTimestampuS32();
  /* run HLA Light */
  HLAFLightMain( /* input */
                 ps_In,
                 &hlafParameter.HLALight,
                 &hlafData,
                 /* output */
                 &hlafData.HLALightOut
               );
  hlafDebugOutputs.timeMeas.dTimeLight_us = (Services->pfGetTimestampuS32() - TimeStart_us);
  
  TimeStart_us = Services->pfGetTimestampuS32();  
  /* run HLA Standard */
  HLAFStandardMain( /* input */
                    ps_In,
                    &hlafParameter.HLAStandard,
                    &hlafData,
                    /* output */
                    &hlafData.HLAStdOut
                  );
  hlafDebugOutputs.timeMeas.dTimeStandard_us = (Services->pfGetTimestampuS32() - TimeStart_us);

  TimeStart_us = Services->pfGetTimestampuS32();
  /* run HLA Plus */
  HLAFPlusMain( /* input */
                ps_In,
                &hlafData,
                &hlafParameter,
                /* output */
                &hlafData.HLAPlusOut
              );
  hlafDebugOutputs.timeMeas.dTimePlus_us = (Services->pfGetTimestampuS32() - TimeStart_us);

  TimeStart_us = Services->pfGetTimestampuS32();
  
  HLAFSpotLight(ps_In->s_Par.ps_CameraParameter,
                &ps_In->s_Par.ps_HlaPar->Headlight,
                &ps_In->s_Sig.s_NightView,
                ps_In->s_Sig.ps_ObjectList,
                &ps_Out->s_NightView);
  hlafDebugOutputs.timeMeas.dTimeSpot_us = (Services->pfGetTimestampuS32() - TimeStart_us);
#endif

  TimeStart_us = Services->pfGetTimestampuS32();
  /* run HLA Matrix */
  HLAFMatrixMain( /* input */
                   ps_In,
                   &hlafMatrixParameter,                   
                   &hlafData,
                   /* output */ 
                   &hlafData.HLAMatrixOut
                 );
  hlafDebugOutputs.timeMeas.dTimeMatrix_us = (Services->pfGetTimestampuS32() - TimeStart_us);

  /* fill output data */ 
  HLAFFillOutputData( /* input */
                      ps_In,
                      &hlafData,
                      ps_In->s_Sig.ps_Environment->e_Brightness,
                      &hlafParameter,
                      /* output */ 
                      ps_Out,
                      ps_SystemInfo
                    );

  /* set dimming output */
  HLAF_FillDimmingAreas(ps_In->s_Sig.ps_ObjectList,
                       ps_In,
                       &ps_Out->s_HeadlightControl.Dimming
                      );
#if (HLA_PROJECT == HLA_PROJECT_SMFC4B0)
  /* set EcoLight output */
  HLAF_FillEcoLight(&ps_In->s_Sig,
                    30.0f,
                    0.1763f,
                    &ps_Out->s_HeadlightControl.EcoLight);
#endif
  /* fill diagnosis debug message */
  HLAFFillDiagnosisDebugMsg( /* input */
                             &hlafData,
#ifdef PC_SIM  /* only needed during simulation for old school evaluation based on MFC300 data */
                             &hlafLightData,
                             &hlafStdData,
                             &hlafPlusData,
#endif
                             &ps_Out->s_HeadlightControl,
                             /* output */ 
                             &ps_Out->s_DiagnosisDebugMsg
                           );
  /* fill debug output data */
  HLAFFillDebugOutput( /* input data */
                       &hlafData,
                       /* output data */ 
                       &hlafDebugOutputs
                      );

  hlafDebugOutputs.timeMeas.dTimeExec_us = (Services->pfGetTimestampuS32() - HWTime_us);

  /* send HLAF measfreezes */
  HLAFMeasfreeze(Services->pfMeasFreeze);
  /* send HLAF Light measfreezes */
  /* HLAFLightMeasfreeze(Services->pfMeasFreeze); */
  /* send HLAF Standard measfreezes */
  /* HLAFStandardMeasfreeze(Services->pfMeasFreeze); */
  /* send HLAF Plus measfreezes */
  /* HLAFPlusMeasfreeze(Services->pfMeasFreeze); */
  /* send HLAF matrix measfreezes */
  HLAFMatrixMeasfreeze(Services->pfMeasFreeze);

  /* <ln_offset+1 PCLINT Error 715: reviewer name: Marcus Brunn date: 2011-10-04 reason: Interface to frame SW is agreed to provide more than is needed */
}

/* ****************************************************************************
  Functionname:     HLAFMeasfreeze                          */ /*!
  Description:      send internal hla data via measfreeze to MTS. 



  @param[in]        

  @pre              -
  @post             -
  @todo             - 
  @author           
**************************************************************************** */
static void HLAFMeasfreeze(AS_t_MeasHdlr pfMeasFreeze)
{
#ifdef HLA_ENABLE_INTERNAL_MEASFREEZES
  AS_t_MeasInfo HlafDataMeasInfo      = {HLA_MEAS_VADDR_HLAF_DATA, sizeof(hlafData), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo HlafDebugOutMeasInfo  = {HLA_MEAS_VADDR_HLAF_DEBUG_OUT, sizeof(hlafDebugOutputs), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo HlafParameterMeasInfo = {HLA_MEAS_VADDR_HLAF_PARAMETER, sizeof(hlafParameter), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};

  (void)pfMeasFreeze(&HlafDataMeasInfo, (void*)&hlafData, NULL);
  (void)pfMeasFreeze(&HlafDebugOutMeasInfo, (void*)&hlafDebugOutputs, NULL);
  (void)pfMeasFreeze(&HlafParameterMeasInfo, (void*)&hlafParameter, NULL);

#endif
}
