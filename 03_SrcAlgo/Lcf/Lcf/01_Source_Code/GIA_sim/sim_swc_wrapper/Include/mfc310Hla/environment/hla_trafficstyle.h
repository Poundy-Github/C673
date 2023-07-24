/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_analysischain.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Boris Lugez

  CREATION DATE:          2011-09-13

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_trafficstyle.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:57CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:39CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:30CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.13 2014/03/25 18:36:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_trafficstyle.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_trafficstyle.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/environment/project.pj.
  CHANGE:                 Revision 1.12 2014/01/10 18:33:38CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:38 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.11 2013/04/12 11:00:44CEST Fischer, Alexander (uidv8778) 
  CHANGE:                 Implemented BMW Codierparameter for traffic style
  CHANGE:                 --- Added comments ---  uidv8778 [Apr 12, 2013 11:00:44 AM CEST]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.10 2013/03/12 14:11:38CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2013 2:11:38 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.9 2013/03/11 16:13:39CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 - HLA_t_eSignalState
  CHANGE:                 - HLA_t_eLightStyle
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eCityState
  CHANGE:                 - HLA_t_eWeatherState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:39 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.8 2013/03/08 10:30:48CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 10:30:49 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.7 2013/03/04 11:15:01CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Integrated cam_rot into HLA
  CHANGE:                 bug fix in jacobian calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2013 11:15:02 AM CET]
  CHANGE:                 Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.6 2012/11/12 18:26:11CET Zechner, Stefan (uidt9253) 
  CHANGE:                 - remove comment in comment
  CHANGE:                 --- Added comments ---  uidt9253 [Nov 12, 2012 6:26:11 PM CET]
  CHANGE:                 Change Package : 118527:1 http://mks-psad:7002/im/viewissue?selection=118527
  CHANGE:                 Revision 1.5 2012/04/17 10:23:28CEST Lugez, Boris (uidt2765) 
  CHANGE:                 -> Do not allow locking of traffic style as long as not 5 km have been travelled since ignition start up
  CHANGE:                 --- Added comments ---  uidt2765 [Apr 17, 2012 10:23:30 AM CEST]
  CHANGE:                 Change Package : 111608:1 http://mks-psad:7002/im/viewissue?selection=111608
  CHANGE:                 Revision 1.4 2012/03/22 10:30:25CET Lugez, Boris (uidt2765) 
  CHANGE:                 -> Code review findings
  CHANGE:                 --- Added comments ---  uidt2765 [Mar 22, 2012 10:30:25 AM CET]
  CHANGE:                 Change Package : 103574:1 http://mks-psad:7002/im/viewissue?selection=103574
  CHANGE:                 Revision 1.3 2011/10/24 09:04:28CEST Lugez, Boris (uidt2765) 
  CHANGE:                 -> Add e_TrafficStyleLastLearned to HLAR_t_RequiredInputs and HLAR_t_ProvidedOutputs
  CHANGE:                 -> Add e_TrafficStyleLearningState to HLAR_t_RequiredInputs and HLAR_t_ProvidedOutputs
  CHANGE:                 --- Added comments ---  uidt2765 [Oct 24, 2011 9:04:28 AM CEST]
  CHANGE:                 Change Package : 49557:1 http://mks-psad:7002/im/viewissue?selection=49557
  CHANGE:                 Revision 1.2 2011/09/27 13:39:53CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 separation of HLAR/ HLAF
  CHANGE:                 --- Added comments ---  brunnm [Sep 27, 2011 1:39:53 PM CEST]
  CHANGE:                 Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.1 2011/09/13 17:37:14CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_TRAFFICSTYLE_INCLUDED
#define HLA_TRAFFICSTYLE_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_base.h"
#include "hla_cam_rot.h"
#include "hlar_ext.h"
#include "hla_debug.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/* TrafficStyle Internal data */
typedef struct
{
  float32 counter;       /* counts left(+) and right(-) car lights [-25;25] */
  float32 counter_sum;   /* counts left(+) and right(-) car lights [-200;200] */ 
  uint16 light_counter_total; /* intialization at each ignition cycle (number of oncoming lights before updating counter) */

#ifdef PC_SIM
  sint32 dbgTrafficStyle_light_counter;
  sint32 dbgTrafficStyle_pair_light_counter;
  uint8 dbgTrafficStyle_belowMotionData_speed;
#endif

}HLATrafficStyleHist_t;

/* TrafficStyle Input */
typedef struct
{
  const HLAR_t_RequiredInputs       *ps_HLAR_In;
  const HLACamRot                   *pcamRot;
  RTE_HLAR_CityState                eCity;  /* used to not learn traffic style within cities */
  HLATrack_t                        *pTLB;
  HLAOdometer_t                     *pOdometer; /* minimal required driven distance to lock learning */
}HLATrafficStyleInput_t;

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
/*! Do the traffic style init . 
- eTrafficStyle set to the previous learned traffic style, if not available set to SCN traffic style
- eTrafficStyleState stores wherever
- eTrafficStyleLearningState is set to the previous ignition cycle eTrafficStyleLearningState stored in non volatile memory
- memset of traffic style history (pHist)
*/
void HLATrafficStyleInit( const HLAR_t_RequiredInputs        *ps_In,
                          RTE_HLA_TrafficStyle               *peTrafficStyle,
                          RTE_HLAR_TrafficStyleState         *peTrafficStyleState,
                          RTE_HLAR_TrafficStyleLearningState *peTrafficStyleLearningState,
                          HLATrafficStyleHist_t              *pHist
                        );

/*! Do the traffic style analysis . 
  Traffic style learning needs :
- Initialization of light_counter_total (=25) oncoming lights
- 4 times 25 oncoming lights with same driving direction (each 25 oncoming light corresponding to an eTrafficStyleLearningState)*/
void HLATrafficStyle( const HLATrafficStyleInput_t           *pIn, 
                      RTE_HLA_TrafficStyle                   *peTrafficStyle,
                      RTE_HLAR_TrafficStyleState             *peTrafficStyleState,
                      RTE_HLAR_TrafficStyleLearningState     *peTrafficStyleLearningState,
                      HLATrafficStyleHist_t                  *pHist,
                      const HLA_t_TrafficStyleParameters     *pParams,
                      const RTE_HLAR_ParameterTrafficStyle_t *pTSParams
                    );

/* avoid cyclic binding ---------------------------------------------------*/
#endif