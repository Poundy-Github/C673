/*! \file **********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                CSF200

  CPU:                    Renesas M32R

  COMPONENT:              HLA

  MODULNAME:              hla_tunnel.h

  DESCRIPTION:            Functions for tunnel detection.

  AUTHOR:                 Cristian Craciunas

  CREATION DATE:          18.11.2008

  VERSION:                $Revision: 1.1 $ 

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_tunnel.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:58CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:41CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:30CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/environment/project.pj
  CHANGE:                 Revision 1.4 2014/03/25 18:36:43CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hla_tunnel.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hla_tunnel.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/environment/project.pj.
  CHANGE:                 Revision 1.3 2014/02/24 11:44:35CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - tunnel detection types changed
  CHANGE:                  - removed some unnecessary flags from the simulation INI file (all related to very old visu)
  CHANGE:                 --- Added comments ---  uidv8777 [Feb 24, 2014 11:44:35 AM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.2 2014/01/24 13:38:00CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - adapt to HLA coding guidelines (more)
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 24, 2014 1:38:00 PM CET]
  CHANGE:                 Change Package : 207634:1 http://mks-psad:7002/im/viewissue?selection=207634
  CHANGE:                 Revision 1.1 2013/08/05 17:01:59CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 Revision 1.1.1.12 2013/06/07 10:42:50CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Structure updates
  CHANGE:                 --- Added comments ---  uidv8777 [Jun 7, 2013 10:42:50 AM CEST]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1.1.11 2013/03/26 17:27:51CET Manz, Alexander (uidv8777) 
  CHANGE:                 Adapted Tunnel Detection to use BMW Kodierparameter
  CHANGE:                  == Warning: not fully tested yet, though it should work (with an emphasis on should) ==
  CHANGE:                 --- Added comments ---  uidv8777 [Mar 26, 2013 5:27:51 PM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1.1.10 2013/03/15 12:56:47CET Manz, Alexander (uidv8777) 
  CHANGE:                 Tunnel detection update includes ability to work with parameter and create measFreezes
  CHANGE:                 --- Added comments ---  uidv8777 [Mar 15, 2013 12:56:48 PM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1.1.9 2013/03/11 16:13:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 - HLA_t_eSignalState
  CHANGE:                 - HLA_t_eLightStyle
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eCityState
  CHANGE:                 - HLA_t_eWeatherState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:43 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.1.1.8 2013/03/11 14:33:00CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Placed no longer needed by RTE ones
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eLightOutput
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 2:33:01 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.1.1.7 2013/03/08 17:34:49CET Manz, Alexander (uidv8777) 
  CHANGE:                 Changed data structure for tunnel recognition.
  CHANGE:                 Contains also first implementations for possibility of measFreezes
  CHANGE:                 --- Added comments ---  uidv8777 [Mar 8, 2013 5:34:49 PM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1.1.6 2013/02/04 17:33:21CET Manz, Alexander (uidv8777) 
  CHANGE:                 Further improvements for tunnel detection:
  CHANGE:                  - added city detection information for a emergency escape in twilight scenario
  CHANGE:                  - sorted features for tunnel detection in different order
  CHANGE:                  - changed limits in detection
  CHANGE:                 --- Added comments ---  uidv8777 [Feb 4, 2013 5:33:21 PM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1.1.5 2013/01/30 13:16:20CET Manz, Alexander (uidv8777) 
  CHANGE:                 Corrected TunnelDetection Init/Reset Function
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 30, 2013 1:16:21 PM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
  CHANGE:                 Revision 1.1.1.4 2013/01/18 13:51:10CET Manz, Alexander (uidv8777) 
  CHANGE:                 Tunnel detection at daylight first version
  CHANGE:                 --- Added comments ---  uidv8777 [Jan 18, 2013 1:51:10 PM CET]
  CHANGE:                 Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_TUNNEL_INCLUDED
#define HLA_TUNNEL_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_base.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
/* these defines provide an easier understanding of the filtered luminance values */
#define TNL_ALL     0  /* all, 25 values */
#define TNL_GROUND  1  /* bottom, 5 values */
#define TNL_LEFT    2  /* left, 5 values */
#define TNL_RIGHT   3  /* right, 5 values */
#define TNL_SKY     4  /* top, 5 values */
#define TNL_CEILING 5  /* top middle, 3 values */
#define TNL_CENTER  6  /* center, 2 values */
#define TNL_RING    7  /* ring around center, 10 values */
#define TNL_MIDDLE  8  /* middle, 12 values */

#define DAY_MIN_DIST_COVERED 10.0f /* minimum distance needed for day tunnel decision */

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

/* Global (day/night) tunnel detection working function */
void HLATunnelDetectionMain(const HLATunnelInput_t*           pTunnelInput,
                            const RTE_HLAR_ParameterTunnel_t* pHlaTunnelDetectionParams,
                                  HLATunnelOutput_t*          pHLATunnelOutput,
                                  RTE_HLAR_Tunnel*            pEnumTunnel
                           );

/* Global tunnel detection initialisation and reset function */
void HLATunnelDetectionInit(HLATunnelData_t*    pHLATunnelData,
                            HLATunnelOutput_t*  pHLATunnelOutput,
                            RTE_HLAR_Tunnel*    p_Out
                           );

#endif /* #ifndef HLA_TUNNEL_INCLUDED */