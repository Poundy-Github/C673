/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hla_city.h

  DESCRIPTION:            Definition file for head light assist.

  AUTHOR:                 Boris Lugez

  CREATION DATE:          2011-03-24

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_city.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:57CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:37CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:28CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.25 2014/03/25 18:36:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_city.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_city.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/environment/project.pj.
  CHANGE:                 Revision 1.24 2014/03/19 15:22:43CET Fischer, Alexander (uidv8778) 
  CHANGE:                 Japan specific city implementations (CountryCode Parameter must be set to RTE_HLA_COUNTRY_CODE_JP)
  CHANGE:                 - leave city when there is numSLInSceneLeaveCityJapan or less SL in scene
  CHANGE:                 - faster city exit with ambient information
  CHANGE:                 --- Added comments ---  uidv8778 [Mar 19, 2014 3:22:44 PM CET]
  CHANGE:                 Change Package : 226009:1 http://mks-psad:7002/im/viewissue?selection=226009
  CHANGE:                 Revision 1.23 2014/02/18 13:21:47CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed missing initialization of global variables
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 18, 2014 1:21:48 PM CET]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.22 2014/01/10 18:34:02CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 First part of LRF on EVE (disabled)
  CHANGE:                 Merged LRF inputs into one struct
  CHANGE:                 Fixed exception handling of internal cali 
  CHANGE:                 Removed all tabs in the code and further clean-up
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 10, 2014 6:34:02 PM CET]
  CHANGE:                 Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.21 2013/04/12 10:55:55CEST Fischer, Alexander (uidv8778) 
  CHANGE:                 Implemented BMW Codierparameter for city
  CHANGE:                 --- Added comments ---  uidv8778 [Apr 12, 2013 10:55:56 AM CEST]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.20 2013/03/11 16:13:29CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 - HLA_t_eSignalState
  CHANGE:                 - HLA_t_eLightStyle
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eCityState
  CHANGE:                 - HLA_t_eWeatherState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:29 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.19 2013/03/11 14:32:49CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Placed no longer needed by RTE ones
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eLightOutput
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 2:32:49 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.18 2013/03/08 15:38:57CET Fischer, Alexander (uidv8778) 
  CHANGE:                 First version of ambient city detection
  CHANGE:                 --- Added comments ---  uidv8778 [Mar 8, 2013 3:38:57 PM CET]
  CHANGE:                 Change Package : 169296:1 http://mks-psad:7002/im/viewissue?selection=169296
  CHANGE:                 Revision 1.17 2013/03/08 10:30:02CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 10:30:02 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.16 2013/03/04 11:14:54CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Integrated cam_rot into HLA
  CHANGE:                 bug fix in jacobian calculation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2013 11:14:55 AM CET]
  CHANGE:                 Change Package : 167173:26 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.15 2012/10/05 12:44:58CEST Brunn, Marcus (brunnm) 
  CHANGE:                 RAM optimization (part1)
  CHANGE:                 --- Added comments ---  brunnm [Oct 5, 2012 12:44:58 PM CEST]
  CHANGE:                 Change Package : 143736:1 http://mks-psad:7002/im/viewissue?selection=143736
  CHANGE:                 Revision 1.14 2012/03/20 18:19:16CET Lugez, Boris (uidt2765) 
  CHANGE:                 -> Permits extra lateral distance for bright street lamps (usage of an intensity flux model)
  CHANGE:                 --- Added comments ---  uidt2765 [Mar 20, 2012 6:19:16 PM CET]
  CHANGE:                 Change Package : 103574:1 http://mks-psad:7002/im/viewissue?selection=103574
  CHANGE:                 Revision 1.13 2011/09/28 18:41:43CEST Lugez, Boris (uidt2765) 
  CHANGE:                 -> Add an auto evaluation for highway
  CHANGE:                 -> Decrease number of false city detection
  CHANGE:                 --- Added comments ---  uidt2765 [Sep 28, 2011 6:41:43 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.12 2011/09/27 13:39:44CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 separation of HLAR/ HLAF
  CHANGE:                 --- Added comments ---  brunnm [Sep 27, 2011 1:39:44 PM CEST]
  CHANGE:                 Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.11 2011/09/06 13:58:09CEST Zechner Stefan (uidt9253) (uidt9253) 
  CHANGE:                 - remove redundant structure motionData from blackboard and replaced by input interface motionState
  CHANGE:                 --- Added comments ---  uidt9253 [Sep 6, 2011 1:58:09 PM CEST]
  CHANGE:                 Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
  CHANGE:                 Revision 1.10 2011/08/25 17:03:50CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Reduce calculation time for City
  CHANGE:                 --- Added comments ---  uidt2765 [Aug 25, 2011 5:03:50 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.9 2011/08/03 16:53:52CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Add "City" detection with height assumption for critical scenarios
  CHANGE:                 --- Added comments ---  uidt2765 [Aug 3, 2011 4:53:52 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.8 2011/07/05 17:07:13CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 updated interface
  CHANGE:                 - fill environment data
  CHANGE:                 - use object list in hlaf
  CHANGE:                 --- Added comments ---  brunnm [Jul 5, 2011 5:07:13 PM CEST]
  CHANGE:                 Change Package : 49575:2 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.7 2011/06/21 16:14:07CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> first integration of city detection
  CHANGE:                 --- Added comments ---  uidt2765 [Jun 21, 2011 4:14:07 PM CEST]
  CHANGE:                 Change Package : 49560:1 http://mks-psad:7002/im/viewissue?selection=49560
  CHANGE:                 Revision 1.6 2011/05/26 17:44:30CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Integrate street lamps analysis module
  CHANGE:                 -> Add 2D street lamps signature analysis
  CHANGE:                 --- Added comments ---  uidt2765 [May 26, 2011 5:44:30 PM CEST]
  CHANGE:                 Change Package : 49956:1 http://mks-psad:7002/im/viewissue?selection=49956
  CHANGE:                 Revision 1.5 2011/05/23 21:57:51CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Optimize street lamp analysis
  CHANGE:                 --- Added comments ---  uidt2765 [May 23, 2011 9:57:51 PM CEST]
  CHANGE:                 Change Package : 49956:1 http://mks-psad:7002/im/viewissue?selection=49956
  CHANGE:                 Revision 1.4 2011/05/23 13:58:44CEST Brunn Marcus (brunnm) (brunnm) 
  CHANGE:                 - renamed seg_TracklistNode into HLATrack_t
  CHANGE:                 - renamed seg_ListNode into HLASegLight_t
  CHANGE:                 --- Added comments ---  brunnm [May 23, 2011 1:58:44 PM CEST]
  CHANGE:                 Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
  CHANGE:                 Revision 1.3 2011/04/21 11:53:03CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 -> Add the result of identState_StreetLamp to HLAIdentificationPotentialVehicleOncoming
  CHANGE:                 -> Check MISRA rules
  CHANGE:                 --- Added comments ---  uidt2765 [Apr 21, 2011 11:53:26 AM CEST]
  CHANGE:                 Change Package : 49956:1 http://mks-psad:7002/im/viewissue?selection=49956
  CHANGE:                 Revision 1.2 2011/04/14 19:01:21CEST Godreau Bertrand (uid28828) (uid28828) 
  CHANGE:                 3D tracking clean-up.
  CHANGE:                 Remove use of global variables.
  CHANGE:                 Set-up of an input/output/data archi
  CHANGE:                 --- Added comments ---  uid28828 [Apr 14, 2011 7:01:21 PM CEST]
  CHANGE:                 Change Package : 50618:1 http://mks-psad:7002/im/viewissue?selection=50618
  CHANGE:                 Revision 1.1 2011/04/14 15:41:38CEST Lugez Boris (uidt2765) (uidt2765) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_CITY_INCLUDED
#define HLA_CITY_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_base.h"
#include "hlar_ext.h"
#include "hla_cam_rot.h"
#include "hla_segmentation.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
/* City Input */
typedef struct
{
  const HLACameraData_t         *pCamData;
  HLATrack_t                    *pTLB;
  const HLA_t_MotionState       *pMotionData;
  const HLAR_t_RequiredInputs   *ps_HLAR_In;
  const HLACamRot               *pCamRot;
  const RTE_HLA_TrafficStyle    *pTrafficStyle;
  const HLASegOut_t             *pSegOut;
  const HLASegSubImage_t        *pHLASubImage;
  RTE_HLAR_BrightnessState       eBrightnessState;
  RTE_HLA_CountryCode            eCountyCode;
}HLACityInput_t;

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
/*! Do the Street Lamp Initialization . */
void HLACityInit( HLACityData_t*      pCityData, 
                  RTE_HLAR_CityState* pCityState
                 );

/*! Do the City Detection . */
void HLACity( /* input */
              const HLACityInput_t *pIn,
              const HLA_t_CityDetectionParameters *pParams,
              const RTE_HLAR_ParameterCity_t      *pCityParams,
              /* history */
              HLACityData_t *pCityData,
              /* output */  
              RTE_HLAR_CityState *peCityOutput
            );

/* avoid cyclic binding ---------------------------------------------------*/
#endif
