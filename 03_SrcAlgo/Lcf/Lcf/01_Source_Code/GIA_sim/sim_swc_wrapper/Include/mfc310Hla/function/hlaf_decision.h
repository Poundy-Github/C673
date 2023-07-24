/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_decision.h

  DESCRIPTION:            HLA decision. This module makes some "pre" decisions.
                          The HLAR outputs will be analysed for the hla light,
                          standard and plus function.
                          e.g.:
                          - brightness analysis (dark enough for high beams ?)  
                          - state machine for highway, city, tunnel detection
                          ...

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2011-02-23

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hlaf_decision.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:03CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:38:46CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:33CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/project.pj
  CHANGES:                Revision 1.59 2014/03/25 18:42:30CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hlaf_decision.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_decision.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/project.pj.
  CHANGES:                Revision 1.58 2014/03/05 11:17:10CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed build error from previous check-in
  CHANGES:                --- Added comments ---  uidv7867 [Mar 5, 2014 11:17:11 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.57 2014/03/04 16:52:19CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed QAC warnings
  CHANGES:                Coding style
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:20 PM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.56 2014/03/04 12:59:05CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for I390 RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 12:59:05 PM CET]
  CHANGES:                Change Package : 207432:32 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.55 2013/09/26 11:21:32CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced specific HLA opmodes by TestMode CPar
  CHANGES:                --- Added comments ---  uidv7867 [Sep 26, 2013 11:21:32 AM CEST]
  CHANGES:                Change Package : 198642:1 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.54 2013/06/13 16:26:32CEST Brunn, Marcus (brunnm) 
  CHANGES:                initial fog detection for I300
  CHANGES:                --- Added comments ---  brunnm [Jun 13, 2013 4:26:32 PM CEST]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLAF_DECISION_INCLUDED
#define HLAF_DECISION_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_type.h"
#include "hlaf_type.h"
#include "hlaf_ext.h"
#include "hlaf_cfg.h"


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
void HLAFDecisionBrightness( /* input */
                             const RTE_HLAR_BrightnessState *peStateIn,
                             /* history */
                             /* output */
                             RTE_HLAR_BrightnessState       *peStateOut
                           );

void HLAFDecisionCity( /* input */
                       const RTE_HLAR_CityState         eCity,
                       const float32                    dTurnOnDelay,
                       const HLAFParameterCity_t        *pPar,
                       const RTE_HLAR_BrightnessState   e_Brightness,
                       /* history */
                       HLAFData_t                       *pFData,
                       /* output */
                       RTE_HLAR_CityState               *peCityOut
                       );

void HLAFDecisionTunnel( /* input */
                         const RTE_HLAR_Tunnel   eTunnel,
                         const float32           dTurnOnDelay,
                         /* history */
                         HLAFData_t              *pFData,
                         /* output */
                         RTE_HLAR_Tunnel         *peTunnelOut
                         );

void HLAFDecisionHighway( /* input */
                          const boolean                   bInternal, /* only internally used by HLAF */
                          const HLA_t_Highway             *pHighwayIn,   
                          const HLAFParameterHighway_t    *pPar,
                          const HLAFData_t                *pFData,
                          const RTE_HLAR_BrightnessState  e_Brightness,
                          /* output */
                          RTE_HLAF_MotorwayState          *peHighwayOut
                        );

void HLAFDecisionSpeed( /* input */
                        const HLA_t_MotionState    *pMotionState,
                        const HLA_t_ObjectList     *ps_ObjectList,
                        float32                    dT,
                        float32                    deactivateSpeed,
                        float32                    activateSpeed,
                        float32                    alwaysActiveSpeed,
                        float32                    keepOffVeryLowSpeed,
                        float32                    keepOffLowRadius,
                        float32                    keepOffHighAcceleration,
                        float32                    keepOffAccelTime,
                        float32                    keepOffDelay,
                        /* history / output */
                        HLAFSpeed_t                *pDat
                      );

void HLAFDecisionPenaltyTimer(  /* input */
                                const RTE_HLAF_HighBeamState eHBState,
                                const float32                dtime_s,
                                /* history/ output */
                                HLAFPenaltyTimer_t          *pPenalty
                             );

void HLAFDecisionTurnOnDelayTTB( /* input */
                                 const HLA_t_Object                   *pObj,
                                 const float32                        Speed,
                                 const RTE_HLAF_MotorwayState         eMotorwayState,
                                 const RTE_HLA_TrafficStyle           eTrafficStyle,
                                 const HLAF_t_RequiredInputs          *pIn,
                                 /* history/ output */
                                 float32                              *pTurnOnDelayOut_s
                               );

uint8 HLAFDecisionChangeOverLevel_TurnOff( /* input */
                                           const HLA_t_fLightDistance LowBeamDist,
                                           const RTE_HLAF_ObjStatus eTargetDrivingDirection,
                                           const HLAFParStdChangeOverLevel_t *pParChangeOverLevel
                                         );
void HLAFDecisionBlockage( /* input */
                           const HLAF_t_Blockage          *pBlockageIn,
                           const HLAFParameterBlockage_t  *pPar,
                           const HLAFCameraData_t         *pCamData,
                           const HLAFTurnOffReasonGlob_t  *pTurnOffReason,
                           const RTE_HLA_State            IHCActivationState,
                           /* history */
                           HLAFBlockage_t                 *pData,
                           /* output */
                           HLA_t_Blockage                 *pBlockageOut,
                           HLA_t_SystemInfo               *ps_SystemInfo
                         );

void HLAFDecisionWeather(  /* input */
                           const HLAF_t_Blockage          *pBlockageIn,
                           /* history */
                           HLAFWeather_t                  *pData,
                           /* output */
                           RTE_HLAR_WeatherState          *peWeatherStateOut
                         );

void HLAFDecisionDimmedLight( /* input */
                              const HLA_t_HeadlightState          *ps_HeadlightState,
                              const HLA_t_ObjectList              *ps_ObjectList,
                              /* history */
                              HLAFDimmedLight_t                   *ps_DimmedLight,
                              /* output */
                              RTE_HLAF_LightOutput                *pe_LightOutput_Lt,
                              RTE_HLAF_LightOutput                *pe_LightOutput_Rt
                            );

void HLAFDecisionTrafficStyle( /* input */
                               const RTE_HLA_TrafficStyle     eTrafficStyleIn,
                               /* history */
                               HLAFTrafficStyle_t             *pData,
                               /* output */
                               HLAFTrafficStyleOut_t          *pOut
                             );

void HLAFDecicionLightStyle( /* input */
                             const HLAF_t_RequiredInputs *ps_In,
                             const float32 dTime_s, 
                             /* history */
                             HLAFLightStyle_t *pHist,
                             /* output */
                             HLAFLightStyleOut_t *pLightStyle
                           );

void HLAFDecisionSetTurnOffReasonGlob( const RTE_HLAR_BrightnessState   e_Brightness,
                                       const RTE_HLA_ParameterAlgoCfg_t *pAlgoCfg,
                                       const HLAFData_t                 *pFData,
                                       const HLA_t_Availability         *pAvail,
                                       /* output */ 
                                       HLAFTurnOffReasonGlob_t          *pTurnOffReason
                                     );

boolean HLAFDecisionRelevantVehicle2TurnOff( /* input */
                                             const RTE_HLAF_HighBeamState eHBState,
                                             const HLA_t_Object *pObj,
                                             const HLAFData_t *pFData,
                                             const RTE_HLAF_ParameterTurnOff_t *pParTurnOff,
                                             /* ROI */
                                             const HLA_t_ObjectRoi *pROI,
                                             /* Region of interest for relevant traffic              */
                                             /* vehicles within this region will be relevant traffic */
                                             /* - independent of TTB and object angle                */
                                             /* - region only used for partial HB and spot light     */   
                                             const float32 RoiAngLeft,
                                             const float32 RoiAngRight
                                           );

void HLAFDecisionSetKeepOffReason( /* input */
                                   const HLAF_t_RequiredInputs      *ps_In,
                                   const HLAFData_t                 *pFData,
                                   const HLAFParameterKeepOff_t     *pParKeepOff,
                                   const HLAFParameterTurnOnDelay_t *pParTurnOnDelay,
                                   const RTE_HLAF_HighBeamState      eHighBeamStatePrev,
                                   const HLAFRelevantVehicle_t      *pRelVeh,
                                   const HLAFPenaltyTimer_t         *pPenaltyTimer,
                                   const HLAFStdTurnOffReason_t     *pTurnOffReason,
                                   /* history and  output */
                                   HLAFStdKeepOffReason_t           *pKeepOffReason
                                 );

void HLAFDecisionFindRelevantVehicle( /* input */
                                      const HLAF_t_RequiredInputs          *ps_In,
                                      const HLAFData_t                     *pFData,
                                      const HLA_t_ObjectList               *pObjectList,
                                      const RTE_HLAF_HighBeamState          eHighBeamStatePrev,
                                      /* History/ output */
                                      HLAFRelevantVehicle_t                *pRelVeh
                                    );

void HLAFDecisionSetTurnOffReason( /* input */
                                   const HLAFRelevantVehicle_t *pRelVeh,
                                   /* output */
                                   HLAFStdTurnOffReason_t      *pTurnOffReason
                                 );

void HLAFDecisionSetHBState( /* input */
                             const HLAFTurnOffReasonGlob_t *pTurnOffReason_glob,
                             const HLAFStdTurnOffReason_t  *pTurnOffReason,
                             const HLAFStdKeepOffReason_t  *pKeepOffReason,
                             const RTE_HLAF_HighBeamState   eHighBeamStatePrev,
                             /* output */  
                             RTE_HLAF_HighBeamState        *peHighBeamStateOut
                           );



/* avoid cyclic binding ---------------------------------------------------*/
#endif
