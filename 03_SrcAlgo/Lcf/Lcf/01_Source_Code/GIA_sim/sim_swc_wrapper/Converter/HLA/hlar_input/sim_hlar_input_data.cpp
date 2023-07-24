/*! \file **********************************************************************

COMPANY:              Continental

PROJECT:              Simulation

COMPONENT:            sim_swc_hla_adapter

MODULNAME:            sim_hlar_input_data.cpp

DESCRIPTION:          

AUTHOR:               Marcus Brunn

CREATION DATE:        03.08.2010

VERSION:              $Revision: 1.1 $

---*/ /*---
CHANGES:              $Log: sim_hlar_input_data.cpp  $
CHANGES:              Revision 1.1 2021/12/13 17:23:31CET Wang, David (Wangd3) 
CHANGES:              Initial revision
CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Converter/HLA/hlar_input/project.pj
CHANGES:              Revision 1.0 2017/03/03 10:35:01CET Sorge, Sven (uidg3181) 
CHANGES:              Initial revision
CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Converter/HLA/hlar_input/project.pj
CHANGES:              Revision 1.2.1.4 2014/11/17 16:57:30CET Mutschler, Matthias (uidv7867) 
CHANGES:              Commented out missing line
CHANGES:              - Added comments -  uidv7867 [Nov 17, 2014 4:57:31 PM CET]
CHANGES:              Change Package : 234060:171 http://mks-psad:7002/im/viewissue?selection=234060
CHANGES:              Revision 1.2.1.3 2014/05/20 16:00:19CEST Sorge-EXT, Sven (uidg3181) 
CHANGES:              commented Set_ICDefectPixel
CHANGES:              --- Added comments ---  uidg3181 [May 20, 2014 4:00:20 PM CEST]
CHANGES:              Change Package : 199693:5 http://mks-psad:7002/im/viewissue?selection=199693
CHANGES:              Revision 1.2.1.2 2014/04/08 13:15:57CEST Sorge-EXT, Sven (uidg3181) 
CHANGES:              Added RGBLuxTable Conversion
CHANGES:              --- Added comments ---  uidg3181 [Apr 8, 2014 1:15:57 PM CEST]
CHANGES:              Change Package : 199693:5 http://mks-psad:7002/im/viewissue?selection=199693
CHANGES:              Revision 1.2.1.1 2014/04/01 10:30:00CEST Sorge-EXT, Sven (uidg3181) 
CHANGES:              Modifications for MFC Wrapepr
CHANGES:              MFC Wrapper ONLY branch
CHANGES:              --- Added comments ---  uidg3181 [Apr 1, 2014 10:30:00 AM CEST]
CHANGES:              Change Package : 217703:2 http://mks-psad:7002/im/viewissue?selection=217703
CHANGES:              Revision 1.1 2014/04/01 09:37:05CEST Sorge-EXT, Sven (uidg3181) 
CHANGES:              Initial revision
CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Converter/HLA/hlar_input/project.pj
CHANGES:              Revision 1.2 2014/03/19 16:30:45CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replace macros from glob_defs.h by the ones defined in cml_ext.h
CHANGES:              Fixed hlar input adapter for old recordings (headlamp type)
CHANGES:              Clean-up of no longer needed files in simulation
CHANGES:              --- Added comments ---  uidv7867 [Mar 19, 2014 4:30:46 PM CET]
CHANGES:              Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
CHANGES:              Revision 1.1 2014/03/18 16:59:19CET Mutschler, Matthias (uidv7867) 
CHANGES:              Initial revision
CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/03_Workspace/algo/hla_sim/hla_adapter/hlar_input/project.pj
CHANGES:              Revision 1.74 2014/03/10 17:13:21CET Brunn, Marcus (brunnm) 
CHANGES:              support hlar_in interface  version 2.4.0
CHANGES:              --- Added comments ---  brunnm [Mar 10, 2014 5:13:22 PM CET]
CHANGES:              Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
CHANGES:              Revision 1.73 2014/03/04 18:00:41CET Mutschler, Matthias (uidv7867) 
CHANGES:              Removed ppars and vehpar from RTE and internal interface
CHANGES:              --- Added comments ---  uidv7867 [Mar 4, 2014 6:00:41 PM CET]
CHANGES:              Change Package : 207432:38 http://mks-psad:7002/im/viewissue?selection=207432
CHANGES:              Revision 1.72 2014/01/30 16:13:08CET Brunn, Marcus (brunnm) 
CHANGES:              adapter update for mfc4xx I320 rec-files
CHANGES:              --- Added comments ---  brunnm [Jan 30, 2014 4:13:09 PM CET]
CHANGES:              Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
CHANGES:              Revision 1.71 2014/01/10 18:33:39CET Mutschler, Matthias (uidv7867) 
CHANGES:              First part of LRF on EVE (disabled)
CHANGES:              Merged LRF inputs into one struct
CHANGES:              Fixed exception handling of internal cali 
CHANGES:              Removed all tabs in the code and further clean-up
CHANGES:              --- Added comments ---  uidv7867 [Jan 10, 2014 6:33:40 PM CET]
CHANGES:              Change Package : 198642:7 http://mks-psad:7002/im/viewissue?selection=198642
CHANGES:              Revision 1.70 2014/01/08 17:10:17CET Mutschler, Matthias (uidv7867) 
CHANGES:              Refactored HLA_Exec() function
CHANGES:              Replaced uint64 time stamps by uint32 ones
CHANGES:              Smaller bug fixes
CHANGES:              --- Added comments ---  uidv7867 [Jan 8, 2014 5:10:17 PM CET]
CHANGES:              Change Package : 207432:27 http://mks-psad:7002/im/viewissue?selection=207432
CHANGES:              Revision 1.69 2013/12/16 17:44:22CET Mutschler, Matthias (uidv7867) 
CHANGES:              Removed the long history
CHANGES:              --- Added comments ---  uidv7867 [Dec 16, 2013 5:44:22 PM CET]
CHANGES:              Change Package : 207432:23 http://mks-psad:7002/im/viewissue?selection=207432
CHANGES:              Revision 1.68 2013/12/12 14:28:33CET Fischer, Alexander (uidv8778) 
CHANGES:              Merge from I320
CHANGES:              --- Added comments ---  uidv8778 [Dec 12, 2013 2:28:33 PM CET]
CHANGES:              Change Package : 207443:1 http://mks-psad:7002/im/viewissue?selection=207443
CHANGES:              Revision 1.67 2013/11/21 17:53:20CET Mutschler, Matthias (uidv7867) 
CHANGES:              Merge from NEW_SEG branch
CHANGES:              --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:21 PM CET]
CHANGES:              Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
CHANGES:              Revision 1.66.1.1 2013/10/18 13:31:10CEST Brunn, Marcus (brunnm) 
CHANGES:              intial version of new segmentation
CHANGES:              --- Added comments ---  brunnm [Oct 18, 2013 1:31:11 PM CEST]
CHANGES:              Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
CHANGES:              Revision 1.66 2013/10/14 09:53:14CEST Manz, Alexander (uidv8777) 
CHANGES:              Fix: Wrong mapping in Adapter prevented indication of US Sensitivity mode in visualization
CHANGES:              --- Added comments ---  uidv8777 [Oct 14, 2013 9:53:14 AM CEST]
CHANGES:              Change Package : 200614:1 http://mks-psad:7002/im/viewissue?selection=200614
CHANGES:              Revision 1.65 2013/09/26 11:21:25CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced specific HLA opmodes by TestMode CPar
CHANGES:              --- Added comments ---  uidv7867 [Sep 26, 2013 11:21:26 AM CEST]
CHANGES:              Change Package : 198642:1 http://mks-psad:7002/im/viewissue?selection=198642
CHANGES:              Revision 1.64 2013/09/18 17:44:19CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Small fixes
CHANGES:              --- Added comments ---  uidv7867 [Sep 18, 2013 5:44:19 PM CEST]
CHANGES:              Change Package : 167173:35 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.63 2013/08/28 11:19:14CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Changed adapter according to new camera parameter struct
CHANGES:              --- Added comments ---  uidv7867 [Aug 28, 2013 11:19:14 AM CEST]
CHANGES:              Change Package : 195030:1 http://mks-psad:7002/im/viewissue?selection=195030
CHANGES:              Revision 1.62 2013/08/20 10:58:15CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Overwrite brightness of blacklevel if < 0
CHANGES:              --- Added comments ---  uidv7867 [Aug 20, 2013 10:58:15 AM CEST]
CHANGES:              Change Package : 167173:33 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.61 2013/07/23 20:14:24CEST Brunn, Marcus (brunnm) 
CHANGES:              HACK: temporary correction of wrong s_HeadlightState.f32_PartHBCutoffAng_Lt/Rt due to wrong formula
CHANGES:              --- Added comments ---  brunnm [Jul 23, 2013 8:14:24 PM CEST]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.60 2013/07/18 18:12:12CEST Manz, Alexander (uidv8777) 
CHANGES:              Updates due to RTE change:
CHANGES:              Includes: 
CHANGES:               - new HeadlightState
CHANGES:               - EcoLight Feature
CHANGES:               - Light Dimming Areas Feature
CHANGES:               - Light adaptive image display settings for MTS visu
CHANGES:               - SRLCam rec file support in visu
CHANGES:              --- Added comments ---  uidv8777 [Jul 18, 2013 6:12:13 PM CEST]
CHANGES:              Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
CHANGES:              Revision 1.59 2013/05/23 09:46:42CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Fixed adapter
CHANGES:              --- Added comments ---  uidv7867 [May 23, 2013 9:46:42 AM CEST]
CHANGES:              Change Package : 167173:30 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.58 2013/05/02 12:43:03CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Updated to latest RTE for I300
CHANGES:              --- Added comments ---  uidv7867 [May 2, 2013 12:43:04 PM CEST]
CHANGES:              Change Package : 167173:30 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.57 2013/04/11 16:20:51CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Implemented some coding parameters
CHANGES:              Tunnel is now global turn off reason
CHANGES:              --- Added comments ---  uidv7867 [Apr 11, 2013 4:20:51 PM CEST]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.56 2013/04/09 16:30:03CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Updated to latest RTE (SW_COMMON_03.01.01_INT-4)
CHANGES:              --- Added comments ---  uidv7867 [Apr 9, 2013 4:30:04 PM CEST]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.55 2013/03/26 17:27:52CET Manz, Alexander (uidv8777) 
CHANGES:              Adapted Tunnel Detection to use BMW Kodierparameter
CHANGES:               == Warning: not fully tested yet, though it should work (with an emphasis on should) ==
CHANGES:              --- Added comments ---  uidv8777 [Mar 26, 2013 5:27:52 PM CET]
CHANGES:              Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
CHANGES:              Revision 1.54 2013/03/21 17:20:24CET Manz, Alexander (uidv8777) 
CHANGES:              First step of US Sensitivity Mode implementation.
CHANGES:               - added Sensitivity to HLA_t_Availability
CHANGES:               - added visualization
CHANGES:              --- Added comments ---  uidv8777 [Mar 21, 2013 5:20:24 PM CET]
CHANGES:              Change Package : 169285:1 http://mks-psad:7002/im/viewissue?selection=169285
CHANGES:              Revision 1.53 2013/03/13 17:36:28CET Brunn, Marcus (brunnm) 
CHANGES:              added HLA parameter to HLAR/F input interface
CHANGES:              --- Added comments ---  brunnm [Mar 13, 2013 5:36:29 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.52 2013/03/12 15:57:53CET Mutschler, Matthias (uidv7867) 
CHANGES:              Smaller adapter fixes and clean-up
CHANGES:              --- Added comments ---  uidv7867 [Mar 12, 2013 3:57:54 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.51 2013/03/12 14:12:09CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced no longer needed types by RTE ones
CHANGES:              --- Added comments ---  uidv7867 [Mar 12, 2013 2:12:09 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.50 2013/03/12 10:59:10CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced no longer needed types by RTE ones
CHANGES:              --- Added comments ---  uidv7867 [Mar 12, 2013 10:59:11 AM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.49 2013/03/11 18:01:58CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replace some types by RTE ones
CHANGES:              --- Added comments ---  uidv7867 [Mar 11, 2013 6:01:58 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.48 2013/03/11 16:48:15CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced  no longer needed macros by RTE ones
CHANGES:              - HLAR_MAX_NUM_DEFECT_PIXEL
CHANGES:              - HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS
CHANGES:              - HLAF_NIGHTVIEW_OBJECTS
CHANGES:              - HLA_FINGERPRINT_PIXELS
CHANGES:              --- Added comments ---  uidv7867 [Mar 11, 2013 4:48:15 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.47 2013/03/11 16:13:31CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced no longer needed types by RTE ones
CHANGES:              - HLA_t_eSignalState
CHANGES:              - HLA_t_eLightStyle
CHANGES:              - HLA_t_eTunnel
CHANGES:              - HLA_t_eCityState
CHANGES:              - HLA_t_eWeatherState
CHANGES:              - HLA_t_eMotorwayState
CHANGES:              --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:31 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.46 2013/03/08 17:42:57CET Mutschler, Matthias (uidv7867) 
CHANGES:              Removed HeadlightState and taken RTE type into use
CHANGES:              --- Added comments ---  uidv7867 [Mar 8, 2013 5:42:57 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.45 2013/03/08 10:30:12CET Mutschler, Matthias (uidv7867) 
CHANGES:              Updated to latest RTE
CHANGES:              --- Added comments ---  uidv7867 [Mar 8, 2013 10:30:13 AM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.44 2013/02/06 08:41:21CET Brunn, Marcus (brunnm) 
CHANGES:              updated adapter for i210
CHANGES:              --- Added comments ---  brunnm [Feb 6, 2013 8:41:24 AM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.43 2013/01/25 16:59:43CET Mutschler, Matthias (uidv7867) 
CHANGES:              Changed enums to rte like types for missing hlar input params/signals
CHANGES:              --- Added comments ---  uidv7867 [Jan 25, 2013 4:59:43 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.42 2013/01/24 19:14:23CET Brunn, Marcus (brunnm) 
CHANGES:              Switched to rte like types for
CHANGES:              - HLA_t_eSignalState
CHANGES:              - HLAF_t_eNightViewObjectType
CHANGES:              - HLAF_t_eNightViewSpot
CHANGES:              --- Added comments ---  brunnm [Jan 24, 2013 7:14:24 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.41 2013/01/24 18:15:03CET Mutschler, Matthias (uidv7867) 
CHANGES:              Fix for previous version
CHANGES:              --- Added comments ---  uidv7867 [Jan 24, 2013 6:15:03 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.40 2013/01/24 10:33:12CET Mutschler, Matthias (uidv7867) 
CHANGES:              Switched to rte like types for
CHANGES:              - HLA_t_eGlareReductionState
CHANGES:              - HLA_t_eLightModuleState
CHANGES:              --- Added comments ---  uidv7867 [Jan 24, 2013 10:33:12 AM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.39 2013/01/23 16:39:58CET Mutschler, Matthias (uidv7867) 
CHANGES:              Converted enum to rte like type for
CHANGES:              - HLA_t_eHeadLightMode
CHANGES:              - HLA_t_eSpotLight
CHANGES:              - HLA_t_eWindshieldType
CHANGES:              - HLA_t_eDefectPixelType
CHANGES:              --- Added comments ---  uidv7867 [Jan 23, 2013 4:39:59 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.38 2013/01/23 13:27:04CET Brunn, Marcus (brunnm) 
CHANGES:              convert enums from MFC300 to MFC400 (rte types)
CHANGES:              --- Added comments ---  brunnm [Jan 23, 2013 1:27:04 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.37 2013/01/22 16:40:01CET Brunn, Marcus (brunnm) 
CHANGES:              introduced RTE like types for 
CHANGES:              - HLA_t_eState
CHANGES:              - HLA_t_eLevelState
CHANGES:              - HLA_t_eLightOutput
CHANGES:              --- Added comments ---  brunnm [Jan 22, 2013 4:40:01 PM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.36 2013/01/22 12:14:09CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced more traffic style enums by uint32
CHANGES:              --- Added comments ---  uidv7867 [Jan 22, 2013 12:14:09 PM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.35 2013/01/22 09:55:17CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced enum by uint32 for traffic style
CHANGES:              --- Added comments ---  uidv7867 [Jan 22, 2013 9:55:17 AM CET]
CHANGES:              Change Package : 167173:22 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.34 2013/01/18 07:46:48CET Brunn, Marcus (brunnm) 
CHANGES:              initial matrix beam version for BMW I210
CHANGES:              --- Added comments ---  brunnm [Jan 18, 2013 7:46:48 AM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.33 2013/01/11 09:07:48CET Brunn, Marcus (brunnm) 
CHANGES:              support new opmodes (segmentation: autothreshold off)

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "sim_hlar_input_data.h"
#include "sim_def.h"

#include "hlar_ext.h"
#include "hla_cpar_init.h"
//#include "common_interface/sim_interface_hla.h"

/* defines ------------------------------------------------------------------ */
//  Time of a line (including horizontal blanking) in us
#define IMGHWD_cf32_LineTimeUs (36.6666667f)
//  Time of a single Pixel in us
#define IMGHWD_cf32_PixelTimeUs (0.0222222222222f)


CVersionInfoImpl CHlarInputData::BASE_VERSION(0, 0, 0);

unsigned long CHlarInputData::SUPPORTED_SIZE[CHlarInputData::HLAR_IN_VER_COUNT ] = { sizeof(HLAR_t_RequiredInputs_v1),
                                                                                             sizeof(HLAR_t_RequiredInputs_v1)-2,
                                                                                             sizeof(HLAR_t_RequiredInputs_v2),
                                                                                             sizeof(HLAR_t_RequiredInputs_v3),
                                                                                             sizeof(HLAR_t_RequiredInputs_v3),
                                                                                             sizeof(HLAR_t_RequiredInputs_v4),
                                                                                             sizeof(HLAR_t_RequiredInputs_v5),
                                                                                             sizeof(HLAR_t_RequiredInputs_v6),
                                                                                             sizeof(HLAR_t_RequiredInputs_v7),
                                                                                             sizeof(HLAR_t_RequiredInputs_v8),
                                                                                             sizeof(HLAR_t_RequiredInputs_v9),
                                                                                             sizeof(HLAR_t_RequiredInputs_v10),
                                                                                             sizeof(HLAR_t_RequiredInputs_v11),
                                                                                             sizeof(HLAR_t_RequiredInputs),

};
unsigned long CHlarInputData::SUPPORTED_VERSION[CHlarInputData::HLAR_IN_VER_COUNT ] = { 0x000001,
                                                                                                0x000002,
                                                                                                0x010000,
                                                                                                0x010100,
                                                                                                0x010101,
                                                                                                0x010200,
                                                                                                0x010300,
                                                                                                0x010400,
                                                                                                0x020000,
                                                                                                0x020100,
                                                                                                0x020200,
                                                                                                0x020300,
                                                                                                0x020300,
                                                                                                HLAR_IN_INTERFACE_VERSION_NUMBER,

};

CHlarInputData::CHlarInputData(void)
{

}

CHlarInputData::~CHlarInputData(void)
{
}


void CHlarInputData::SetHlarInputData_v1(HLAR_t_RequiredInputs_v1* pIn, HLAR_t_RequiredInputs* pIn_Out)
{
  uint32 i;
  float32 f32_RatioRedGreen, f32_RatioBlueGreen;
  float32 f32_T1_us, f32_T2_us, f32_T3_us;

  if(pIn_Out && pIn)
  {
    

    
    pIn_Out->uiFrameCnt                   = pIn->ui32_FrameCnt;
    pIn_Out->ui32_InterfaceVersionNumber  = pIn->ui32_InterfaceVersionNumber;
    pIn_Out->uiTimeStamp_HLA_us            = 0u;
    pIn_Out->uiTimeStamp_VDY_us            = 0u;
    pIn_Out->uiTimeStamp_Image_us          = (AlgoDataTimeStamp_t)pIn->ui32_FrameCnt * 30000;
    pIn_Out->uiVDY_Cnt                     = 0u;

    /* HLAR_t_InputSignals */      
    Set_HLA_Availability(&pIn_Out->s_Sig.s_Avl,
                                        Convert_HLA_eType_v1(pIn->s_Sig.s_Avl.e_Type),
                                        Convert_HLA_eState_v1(pIn->s_Sig.s_Avl.e_State),
                                        RTE_HLA_US_SENS_UNKNOWN
                                       );

    /* calculate color ratios */
    f32_RatioRedGreen   = (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[2].f32_avgR - pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0].f32_avgR)/
                          (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[2].f32_avgG - pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0].f32_avgG);
    f32_RatioBlueGreen  = (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[2].f32_avgB - pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0].f32_avgB)/
                          (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[2].f32_avgG - pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0].f32_avgG);
    
    /* set T1,2,3 Production    */
    /* correct PPAR from camera */
    f32_T1_us =  511    * IMGHWD_cf32_LineTimeUs;
    f32_T2_us =   31    * IMGHWD_cf32_LineTimeUs;
    f32_T3_us = 2955.0f * IMGHWD_cf32_PixelTimeUs;

    SetRgbLuxTable(&pIn_Out->s_Par.s_CameraParameter.s_RGBLuxTable,
                   16,
                   16,
                   f32_T1_us,
                   f32_T2_us,
                   f32_T3_us,
                   2.78f,
                   f32_RatioRedGreen,
                   f32_RatioBlueGreen,
                   1.0f,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength,
                   &pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0]);

    Set_HLA_ImagerState( &pIn_Out->s_Sig.s_ImagerState,
                                        Convert_HLA_eActiveChar_v1(pIn->s_Sig.s_ImagerState.e_ActiveChar),
                                        (float32)pIn->s_Sig.s_ImagerState.ui32_Brightness_mLux,
                                        pIn->s_Sig.s_ImagerState.ui32_ExposureTime_us,
                                        pIn->s_Sig.s_ImagerState.ui32_FrameNumber,
                                        pIn->s_Sig.s_ImagerState.f32_Noise,

                                        16,//ui32_R1, 
                                        16,//ui32_R2, 
                                        18736,//f32_T1_us,
                                        1136,//f32_T2_us,
                                        65,//f32_T3_us,
                                        2.78f,//f32_Gain,
                                        /* response curve */
                                        (uint16)pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0].f32_avgR,//f32_Blacklevel_R_Greyvalue,
                                        (uint16)pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0].f32_avgG,//f32_Blacklevel_G_Greyvalue,
                                        (uint16)pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0].f32_avgB,//f32_Blacklevel_B_Greyvalue,
                                        2048,//f32_Kneepoint1_Greyvalue,
                                        49.36f,//f32_Kneepoint1_R_Lux,
                                        65.83f,//f32_Kneepoint1_G_Lux,
                                        157.03f,//f32_Kneepoint1_B_Lux,
                                        3040,//f32_Kneepoint2_Greyvalue,
                                        1714.51f,//f32_Kneepoint2_R_Lux,
                                        2286.71f,//f32_Kneepoint2_G_Lux,
                                        5454.28f,//f32_Kneepoint2_B_Lux,
                                        4000,//f32_Saturation_Greyvalue,
                                        27497.42f,//f32_Saturation_R_Lux,
                                        36674.50f,//f32_Saturation_G_Lux,
                                        87476.31f //f32_Saturation_B_Lux
                                       );
   
    Set_HLA_MotionState( &pIn_Out->s_Sig.s_MotionState,
                                        pIn->s_Sig.s_MotionState.f32_Speed, /* SpeedDisplay */
                                        pIn->s_Sig.s_MotionState.f32_Speed,
                                        pIn->s_Sig.s_MotionState.f32_Acceleration,
                                        pIn->s_Sig.s_MotionState.f32_YawRateRaw,
                                        pIn->s_Sig.s_MotionState.f32_YawRate,
                                        pIn->s_Sig.s_MotionState.f32_YawRateQuality,
                                        0.0f, /* f32_YawRateVariance */
                                        0.0f, /* f32_SteeringWheelAngle */
                                        pIn->s_Sig.s_MotionState.f32_SteeringAngle,
                                        Convert_HLA_eMovementState_v1(pIn->s_Sig.s_MotionState.e_MoveState),
                                        pIn->s_Sig.s_MotionState.f32_MoveStateConfidence
                                       );

    Set_HLA_HeadlightState_v1( &pIn_Out->s_Sig.s_HeadlightState,
                                           Convert_HLA_eLightStyle_v1(pIn->s_Sig.s_HeadlightState.e_LightStyle_Lt),
                                           Convert_HLA_eLightStyle_v1(pIn->s_Sig.s_HeadlightState.e_LightStyle_Rt),
                                           pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Lt,
                                           pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Rt,
                                           pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Lt,
                                           pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Rt,
                                           Convert_HLA_eHighBeamState_v1(pIn->s_Sig.s_HeadlightState.e_HighBeamState),
                                           Convert_HLA_eLightModuleState_v1(pIn->s_Sig.s_HeadlightState.e_LightModuleState),
                                           pIn->s_Sig.s_HeadlightState.f32_LightDistance,
                                           pIn->s_Sig.s_HeadlightState.f32_LightOutput,
                                           Convert_HLA_eGlareReductionState_v1(pIn->s_Sig.s_HeadlightState.e_GlareReductionState)
                                           );
           
    Set_HLA_VehicleState( &pIn_Out->s_Sig.s_VehicleState,
                                         pIn->s_Sig.s_VehicleState.b_FogLampFront,
                                         pIn->s_Sig.s_VehicleState.b_FogLampRear,
                                         pIn->s_Sig.s_VehicleState.b_RainSensor,
                                         pIn->s_Sig.s_VehicleState.ui8_WiperState,
                                         Convert_HLA_eWiperWasherState_v1(pIn->s_Sig.s_VehicleState.e_WiperWasherFrontState),
                                         Convert_HLA_eWiperStage_v1(pIn->s_Sig.s_VehicleState.e_WiperStage),
                                         (HLA_t_VehLevel_v1)pIn->s_Sig.s_VehicleState.s_VehicleLevel
                                       );

    Set_HLA_CaliOnline(&pIn_Out->s_Sig.s_CaliOnline,
                                      pIn->s_Sig.s_CaliOnline.f32_OdoCali_m,
                                      pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                      pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                      pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw
                                     );
    
    pIn_Out->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat = Convert_HLA_eSignalState_v1(pIn->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat);
    pIn_Out->s_Sig.s_DefectPixelList.ui8_DefectsListLength      = pIn->s_Sig.s_DefectPixelList.ui8_DefectsListLength;
    //for(i=0; i<HLAR_MAX_NUM_DEFECT_PIXEL_V1; i++)
    //{
    //  Set_ICDefectPixel( pIn_Out->s_Sig.s_DefectPixelList.as_DefectList[i],
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
    //                                    Convert_HLA_eDefectPixelType_v1(pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType),
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
    //                                  );
    //}

    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned = RTE_HLA_TRAFFIC_STYLE_UNKNOWN;
    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_0;

    /* HLAR_t_InputParameters */

    Set_HLA_CameraParameter( &pIn_Out->s_Par.s_CameraParameter,
                                            Convert_HLA_eBayerPatternType_v1(pIn->s_Par.s_CameraParameter.e_bayerPattern),
                                            pIn->s_Par.s_CameraParameter.f32_cycleTime,
                                            pIn->s_Par.s_CameraParameter.s_FocalLength,
                                            pIn->s_Par.s_CameraParameter.s_ImageSize,
                                            pIn->s_Par.s_CameraParameter.s_CroppedRoiSize,
                                            pIn->s_Par.s_CameraParameter.s_CroppedRoiX1,
                                            pIn->s_Par.s_CameraParameter.s_LensCenter,

                                            /* camera distortion parameter */
                                            0.1558493135761545f, /* f32_K1 */
                                            0.0509561314913793f, /* f32_K2 */
                                            0.0f, /* f32_K3 */
                                            0.0f, /* f32_K4 */
                                            0.0f, /* f32_K5 */
                                            /* camera distortion parameter */  

                                            /* Image header parameter */
                                            pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel,
                                            1, /* 1 byte/pixel */
                                            pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x,
                                            0, /* not in use right now */
                                            0, /* not in use right now */
                                            0, /* not in use right now */
                                            0, /* not in use right now */
                                            0, /* not in use right now */
                                            0, /* not in use right now */
                                            0, /* not in use right now */
                                            0, /* not in use right now */
                                            0 /* not in use right now */
                                            /* Image header parameter */
                                          );

    pIn_Out->s_Par.s_SensorSocket = pIn->s_Par.s_SensorSocket;
    
    Set_HLA_SensorAngles(&pIn_Out->s_Par.s_SensorAngles,
                                        pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                        pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                        pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw,
                                        pIn->s_Par.s_SensorAngles.f32_Quality,
                                        MC_NO_VERIFICATION_DONE_YET
                                        );

    /* CPAR_HLA_Parameter_t */
    pIn_Out->s_Par.s_HlaPar.HLAType = RTE_HLA_TYPE_UNKNOWN;
    CParInit_HlaPar_AlgoCfg(&pIn_Out->s_Par.s_HlaPar.AlgoCfg);
    CParInit_HlaPar_Headlight(&pIn_Out->s_Par.s_HlaPar.Headlight);
    CParInit_HlaPar_Vehicle(&pIn_Out->s_Par.s_HlaPar.Vehicle);
    CParInit_HlaPar_Country(&pIn_Out->s_Par.s_HlaPar.Country);
    /* overwrite some data */
    pIn_Out->s_Par.s_HlaPar.Headlight.HeadLightType = pIn->s_Sig.s_VehicleState.e_HeadLightType;
    pIn_Out->s_Par.s_HlaPar.Vehicle.WindshieldType  = pIn->s_Sig.s_VehicleState.e_WindshieldType;
    pIn_Out->s_Par.s_HlaPar.Country.TrafficStyle    = pIn->s_Sig.s_VehicleState.e_TrafficStyle;

    /* CPAR_HLAR_Parameter_t */
    CParInit_HlarPar_Roi(&pIn_Out->s_Par.s_HlarPar.Roi);
    CParInit_HlarPar_City(&pIn_Out->s_Par.s_HlarPar.City);
    CParInit_HlarPar_Highway(&pIn_Out->s_Par.s_HlarPar.Highway);
    CParInit_HlarPar_Tunnel(&pIn_Out->s_Par.s_HlarPar.Tunnel);
    CParInit_HlarPar_TrafficStyle(&pIn_Out->s_Par.s_HlarPar.TrafficStyle);
    CParInit_HlarPar_Ambient(&pIn_Out->s_Par.s_HlarPar.Ambient);
    CParInit_HlarPar_Vehicle(&pIn_Out->s_Par.s_HlarPar.Vehicle);
    CParInit_HlarPar_LightPair(&pIn_Out->s_Par.s_HlarPar.LightPair);
    CParInit_HlarPar_DistEst(&pIn_Out->s_Par.s_HlarPar.DistEst);
    CParInit_HlarPar_TTBEst(&pIn_Out->s_Par.s_HlarPar.TTBEst);
  }
}

void CHlarInputData::SetHlarInputData_v2(HLAR_t_RequiredInputs_v2* pIn, HLAR_t_RequiredInputs* pIn_Out)
{
  uint32 i;
  float32 f32_RatioRedGreen, f32_RatioBlueGreen;
  float32 f32_T1_us, f32_T2_us, f32_T3_us;

  if(pIn_Out && pIn)
  {
    


    pIn_Out->uiFrameCnt                   = pIn->ui32_FrameCnt;
    pIn_Out->ui32_InterfaceVersionNumber  = pIn->ui32_InterfaceVersionNumber;
    pIn_Out->uiTimeStamp_HLA_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_HLA_us;
    pIn_Out->uiTimeStamp_VDY_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_VDY_us;
    pIn_Out->uiTimeStamp_Image_us         = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_Image_us;
    pIn_Out->uiVDY_Cnt                    = pIn->ui32_VDY_Cnt;

      
    /* HLAR_t_InputSignals */  
    Set_HLA_Availability(&pIn_Out->s_Sig.s_Avl,
                                        Convert_HLA_eType_v1(pIn->s_Sig.s_Avl.e_Type),
                                        Convert_HLA_eState_v1(pIn->s_Sig.s_Avl.e_State),
                                        RTE_HLA_US_SENS_UNKNOWN
                                       );
    Set_HLA_ImagerState( &pIn_Out->s_Sig.s_ImagerState,
                                        Convert_HLA_eActiveChar_v1(pIn->s_Sig.s_ImagerState.e_ActiveChar),
                                        pIn->s_Sig.s_ImagerState.f32_Brightness_Lux,
                                        pIn->s_Sig.s_ImagerState.ui32_ExposureTime_us,
                                        pIn->s_Sig.s_ImagerState.ui32_FrameNumber,
                                        pIn->s_Sig.s_ImagerState.f32_Noise,

                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R1,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R2, 
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T1_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T2_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T3_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_Gain,
                                        /* response curve */
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_B_Lux
                                       );
   
    Set_HLA_MotionState( &pIn_Out->s_Sig.s_MotionState,
                                        pIn->s_Sig.s_MotionState.f32_Speed, /* SpeedDisplay */
                                        pIn->s_Sig.s_MotionState.f32_Speed,
                                        pIn->s_Sig.s_MotionState.f32_Acceleration,
                                        pIn->s_Sig.s_MotionState.f32_YawRateRaw,
                                        pIn->s_Sig.s_MotionState.f32_YawRate,
                                        pIn->s_Sig.s_MotionState.f32_YawRateQuality,
                                        pIn->s_Sig.s_MotionState.f32_YawRateVariance,
                                        pIn->s_Sig.s_MotionState.f32_SteeringWheelAngle,
                                        pIn->s_Sig.s_MotionState.f32_SteeringAngle,
                                        Convert_HLA_eMovementState_v1(pIn->s_Sig.s_MotionState.e_MoveState),
                                        pIn->s_Sig.s_MotionState.f32_MoveStateConfidence
                                       );

    Set_HLA_HeadlightState_v1( &pIn_Out->s_Sig.s_HeadlightState,
                                           Convert_HLA_eLightStyle_v1(pIn->s_Sig.s_HeadlightState.e_LightStyle_Lt),
                                           Convert_HLA_eLightStyle_v1(pIn->s_Sig.s_HeadlightState.e_LightStyle_Rt),
                                           pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Lt,
                                           pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Rt,
                                           pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Lt,
                                           pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Rt,
                                           Convert_HLA_eHighBeamState_v1(pIn->s_Sig.s_HeadlightState.e_HighBeamState),
                                           Convert_HLA_eLightModuleState_v1(pIn->s_Sig.s_HeadlightState.e_LightModuleState),
                                           pIn->s_Sig.s_HeadlightState.f32_LightDistance,
                                           pIn->s_Sig.s_HeadlightState.f32_LightOutput,
                                           Convert_HLA_eGlareReductionState_v1(pIn->s_Sig.s_HeadlightState.e_GlareReductionState)
                                          );

    Set_HLA_VehicleState( &pIn_Out->s_Sig.s_VehicleState,
                                         pIn->s_Sig.s_VehicleState.b_FogLampFront,
                                         pIn->s_Sig.s_VehicleState.b_FogLampRear,
                                         pIn->s_Sig.s_VehicleState.b_RainSensor,
                                         pIn->s_Sig.s_VehicleState.ui8_WiperState,
                                         Convert_HLA_eWiperWasherState_v1(pIn->s_Sig.s_VehicleState.e_WiperWasherFrontState),
                                         Convert_HLA_eWiperStage_v1(pIn->s_Sig.s_VehicleState.e_WiperStage),
                                         (HLA_t_VehLevel_v1)pIn->s_Sig.s_VehicleState.s_VehicleLevel
                                       );

    Set_HLA_CaliOnline(&pIn_Out->s_Sig.s_CaliOnline,
                                      pIn->s_Sig.s_CaliOnline.f32_OdoCali_m,
                                      pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                      pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                      pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw
                                     );
    
    pIn_Out->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat = Convert_HLA_eSignalState_v1(pIn->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat);
    pIn_Out->s_Sig.s_DefectPixelList.ui8_DefectsListLength      = pIn->s_Sig.s_DefectPixelList.ui8_DefectsListLength;
    //for(i=0; i<HLAR_MAX_NUM_DEFECT_PIXEL_V1; i++)
    //{
    //  Set_ICDefectPixel( pIn_Out->s_Sig.s_DefectPixelList.as_DefectList[i],
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
    //                                    Convert_HLA_eDefectPixelType_v1(pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType),
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
    //                                  );
    //}
    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned = RTE_HLA_TRAFFIC_STYLE_UNKNOWN;
    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_0;
        

    /* HLAR_t_InputParameters */

    Set_HLA_CameraParameter( &pIn_Out->s_Par.s_CameraParameter,
                                            Convert_HLA_eBayerPatternType_v1(pIn->s_Par.s_CameraParameter.e_bayerPattern),
                                            pIn->s_Par.s_CameraParameter.f32_cycleTime,
                                            pIn->s_Par.s_CameraParameter.s_FocalLength,
                                            pIn->s_Par.s_CameraParameter.s_ImageSize,
                                            pIn->s_Par.s_CameraParameter.s_CroppedRoiSize,
                                            pIn->s_Par.s_CameraParameter.s_CroppedRoiX1,
                                            pIn->s_Par.s_CameraParameter.s_LensCenter,

                                            /* camera distortion parameter */
                                            pIn->s_Par.s_CameraParameter.s_Distortion.f32_K1,
                                            pIn->s_Par.s_CameraParameter.s_Distortion.f32_K2,
                                            pIn->s_Par.s_CameraParameter.s_Distortion.f32_K3,
                                            pIn->s_Par.s_CameraParameter.s_Distortion.f32_K4,
                                            pIn->s_Par.s_CameraParameter.s_Distortion.f32_K5,
                                            /* camera distortion parameter */  

                                            /* Image header parameter */
                                            pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel,
                                            1, /* 1 byte/pixel */
                                            pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x,
                                            0, /* not in use right now */
                                            0, /* not in use right now */
                                            0, /* not in use right now */
                                            0, /* not in use right now */
                                            0, /* not in use right now */
                                            0, /* not in use right now */
                                            0, /* not in use right now */
                                            0, /* not in use right now */
                                            0 /* not in use right now */
                                            /* Image header parameter */
                                          );

    pIn_Out->s_Par.s_SensorSocket = pIn->s_Par.s_SensorSocket;
    
    Set_HLA_SensorAngles(&pIn_Out->s_Par.s_SensorAngles,
                                        pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                        pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                        pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw,
                                        pIn->s_Par.s_SensorAngles.f32_Quality,
                                        MC_NO_VERIFICATION_DONE_YET
                                        );

    /* CPAR_HLA_Parameter_t */
    pIn_Out->s_Par.s_HlaPar.HLAType = RTE_HLA_TYPE_UNKNOWN;
    CParInit_HlaPar_AlgoCfg(&pIn_Out->s_Par.s_HlaPar.AlgoCfg);
    CParInit_HlaPar_Headlight(&pIn_Out->s_Par.s_HlaPar.Headlight);
    CParInit_HlaPar_Vehicle(&pIn_Out->s_Par.s_HlaPar.Vehicle);
    CParInit_HlaPar_Country(&pIn_Out->s_Par.s_HlaPar.Country);
    /* overwrite some data */
    pIn_Out->s_Par.s_HlaPar.Headlight.HeadLightType = pIn->s_Sig.s_VehicleState.e_HeadLightType;
    pIn_Out->s_Par.s_HlaPar.Vehicle.WindshieldType  = pIn->s_Sig.s_VehicleState.e_WindshieldType;
    pIn_Out->s_Par.s_HlaPar.Country.TrafficStyle    = pIn->s_Sig.s_VehicleState.e_TrafficStyle;

    /* CPAR_HLAR_Parameter_t */
    Set_HLA_ParameterRoi( &pIn_Out->s_Par.s_HlarPar.Roi,
                                         pIn->s_Par.s_Roi.f32_FOV_Horizontal_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_FunctionRoiAboveHorizon_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_MinBelowHorizon_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_MinAboveHorizon_rad,
                                         3.7f,          /* PrecVehLight_minDistance     */
                                         0.7f,          /* PrecVehLight_minHeight       */
                                         pIn->s_Par.s_Roi.f32_StreetLamp_Distance_m,
                                         pIn->s_Par.s_Roi.f32_StreetLamp_Height_m
                                       );
    CParInit_HlarPar_City(&pIn_Out->s_Par.s_HlarPar.City);
    CParInit_HlarPar_Highway(&pIn_Out->s_Par.s_HlarPar.Highway);
    CParInit_HlarPar_Tunnel(&pIn_Out->s_Par.s_HlarPar.Tunnel);
    CParInit_HlarPar_TrafficStyle(&pIn_Out->s_Par.s_HlarPar.TrafficStyle);
    CParInit_HlarPar_Ambient(&pIn_Out->s_Par.s_HlarPar.Ambient);
    CParInit_HlarPar_Vehicle(&pIn_Out->s_Par.s_HlarPar.Vehicle);
    CParInit_HlarPar_LightPair(&pIn_Out->s_Par.s_HlarPar.LightPair);
    CParInit_HlarPar_DistEst(&pIn_Out->s_Par.s_HlarPar.DistEst);
    CParInit_HlarPar_TTBEst(&pIn_Out->s_Par.s_HlarPar.TTBEst);

    /* calculate color ratios */
    /* imager response curve from IC OK ? */
    if(fABS(  pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux 
            - pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_R_Lux) > 1.0f
      )
    {
      f32_RatioRedGreen   = pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux/
                            pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_R_Lux;
      f32_RatioBlueGreen  = pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux/
                            pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_B_Lux;
    }
    else
    {
      /* calculate color ratios */
      f32_RatioRedGreen   = (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[2].f32_avgR - pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0].f32_avgR)/
                            (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[2].f32_avgG - pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0].f32_avgG);
      f32_RatioBlueGreen  = (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[2].f32_avgB - pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0].f32_avgB)/
                            (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[2].f32_avgG - pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0].f32_avgG);
    }

    /* set T1,2,3 Production    */
    /* correct PPAR from camera (most B1 samples have T1 = 519 rows and T2 = 32 rows but thats wrong !!!) */
    f32_T1_us =  511    * IMGHWD_cf32_LineTimeUs;
    f32_T2_us =   31    * IMGHWD_cf32_LineTimeUs;
    f32_T3_us = 2955.0f * IMGHWD_cf32_PixelTimeUs;

    SetRgbLuxTable(&pIn_Out->s_Par.s_CameraParameter.s_RGBLuxTable,
                   16,
                   16,
                   f32_T1_us,
                   f32_T2_us,
                   f32_T3_us,
                   2.78f,
                   f32_RatioRedGreen,
                   f32_RatioBlueGreen,
                   1.0f,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength,
                   &pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0]);
  }
}

uint32 CHlarInputData::SetHlarInputData_v3(HLAR_t_RequiredInputs_v3* pIn, HLAR_t_RequiredInputs* pIn_Out)
{
  uint32  i;
  uint32  Error = SIM_ERR_OK;


  if(pIn_Out && pIn)
  {
    


    pIn_Out->uiFrameCnt                   = pIn->ui32_FrameCnt;
    pIn_Out->ui32_InterfaceVersionNumber  = pIn->ui32_InterfaceVersionNumber;
    pIn_Out->uiTimeStamp_HLA_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_HLA_us;
    pIn_Out->uiTimeStamp_VDY_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_VDY_us;
    pIn_Out->uiTimeStamp_Image_us         = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_Image_us;
    pIn_Out->uiVDY_Cnt                    = pIn->ui32_VDY_Cnt;

    /* HLAR_t_InputSignals */      
    Set_HLA_Availability(&pIn_Out->s_Sig.s_Avl,
                                        Convert_HLA_eType_v1(pIn->s_Sig.s_Avl.e_Type),
                                        Convert_HLA_eState_v1(pIn->s_Sig.s_Avl.e_State),
                                        RTE_HLA_US_SENS_UNKNOWN
                                       );

    Set_HLA_ImagerState( &pIn_Out->s_Sig.s_ImagerState,
                                        Convert_HLA_eActiveChar_v1(pIn->s_Sig.s_ImagerState.e_ActiveChar),
                                        pIn->s_Sig.s_ImagerState.f32_Brightness_Lux,
                                        pIn->s_Sig.s_ImagerState.ui32_ExposureTime_us,
                                        pIn->s_Sig.s_ImagerState.ui32_FrameNumber,
                                        pIn->s_Sig.s_ImagerState.f32_Noise,

                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R1,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R2, 
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T1_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T2_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T3_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_Gain,
                                        /* response curve */
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_B_Lux
                                       );
   
    Set_HLA_MotionState( &pIn_Out->s_Sig.s_MotionState,
                                        pIn->s_Sig.s_MotionState.f32_SpeedDisplay,
                                        pIn->s_Sig.s_MotionState.f32_Speed,
                                        pIn->s_Sig.s_MotionState.f32_Acceleration,
                                        pIn->s_Sig.s_MotionState.f32_YawRateRaw,
                                        pIn->s_Sig.s_MotionState.f32_YawRate,
                                        pIn->s_Sig.s_MotionState.f32_YawRateQuality,
                                        pIn->s_Sig.s_MotionState.f32_YawRateVariance,
                                        pIn->s_Sig.s_MotionState.f32_SteeringWheelAngle,
                                        pIn->s_Sig.s_MotionState.f32_SteeringAngle,
                                        Convert_HLA_eMovementState_v1(pIn->s_Sig.s_MotionState.e_MoveState),
                                        pIn->s_Sig.s_MotionState.f32_MoveStateConfidence
                                       );
    
    Set_HLA_HeadlightState_v1( &pIn_Out->s_Sig.s_HeadlightState,
                                           Convert_HLA_eLightStyle_v1(pIn->s_Sig.s_HeadlightState.e_LightStyle_Lt),
                                           Convert_HLA_eLightStyle_v1(pIn->s_Sig.s_HeadlightState.e_LightStyle_Rt),
                                           -pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Lt,
                                           -pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Rt,
                                           -pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Lt,
                                           -pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Rt,
                                           Convert_HLA_eHighBeamState_v1(pIn->s_Sig.s_HeadlightState.e_HighBeamState),
                                           Convert_HLA_eLightModuleState_v1(pIn->s_Sig.s_HeadlightState.e_LightModuleState),
                                           pIn->s_Sig.s_HeadlightState.f32_LightDistance,
                                           pIn->s_Sig.s_HeadlightState.f32_LightOutput,
                                           Convert_HLA_eGlareReductionState_v1(pIn->s_Sig.s_HeadlightState.e_GlareReductionState)
                                          );   

    Set_HLA_VehicleState( &pIn_Out->s_Sig.s_VehicleState,
                                         pIn->s_Sig.s_VehicleState.b_FogLampFront,
                                         pIn->s_Sig.s_VehicleState.b_FogLampRear,
                                         pIn->s_Sig.s_VehicleState.b_RainSensor,
                                         pIn->s_Sig.s_VehicleState.ui8_WiperState,
                                         Convert_HLA_eWiperWasherState_v1(pIn->s_Sig.s_VehicleState.e_WiperWasherFrontState),
                                         Convert_HLA_eWiperStage_v1(pIn->s_Sig.s_VehicleState.e_WiperStage),
                                         (HLA_t_VehLevel_v1)pIn->s_Sig.s_VehicleState.s_VehicleLevel
                                       );

    Set_HLA_CaliOnline(&pIn_Out->s_Sig.s_CaliOnline,
                                      pIn->s_Sig.s_CaliOnline.f32_OdoCali_m,
                                      pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                      pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                      pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw
                                     );
    
    pIn_Out->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat = Convert_HLA_eSignalState_v1(pIn->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat);
    pIn_Out->s_Sig.s_DefectPixelList.ui8_DefectsListLength      = pIn->s_Sig.s_DefectPixelList.ui8_DefectsListLength;
    //for(i=0; i<HLAR_MAX_NUM_DEFECT_PIXEL_V1; i++)
    //{
    //  Set_ICDefectPixel( pIn_Out->s_Sig.s_DefectPixelList.as_DefectList[i],
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
    //                                    Convert_HLA_eDefectPixelType_v1(pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType),
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
    //                                  );
    //}

    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned = RTE_HLA_TRAFFIC_STYLE_UNKNOWN;
    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_0;
            
    /* HLAR_t_InputParameters */
    {
      Set_HLA_CameraParameter( &pIn_Out->s_Par.s_CameraParameter,
                                              Convert_HLA_eBayerPatternType_v1(pIn->s_Par.s_CameraParameter.e_bayerPattern),
                                              pIn->s_Par.s_CameraParameter.f32_cycleTime,
                                              pIn->s_Par.s_CameraParameter.s_FocalLength,
                                              pIn->s_Par.s_CameraParameter.s_ImageSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiX1,
                                              pIn->s_Par.s_CameraParameter.s_LensCenter,

                                              /* camera distortion parameter */
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K1,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K2,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K3,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K4,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K5,
                                              /* camera distortion parameter */  

                                              /* Image header parameter */
                                              pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel,
                                              1, /* 1 byte/pixel */
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x,
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0 /* not in use right now */
                                              /* Image header parameter */
                                        );
    }

    pIn_Out->s_Par.s_SensorSocket = pIn->s_Par.s_SensorSocket;
    
    Set_HLA_SensorAngles(&pIn_Out->s_Par.s_SensorAngles,
                                        pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                        pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                        pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw,
                                        pIn->s_Par.s_SensorAngles.f32_Quality,
                                        MC_NO_VERIFICATION_DONE_YET
                                        );

    /* CPAR_HLA_Parameter_t */
    pIn_Out->s_Par.s_HlaPar.HLAType = RTE_HLA_TYPE_UNKNOWN;
    CParInit_HlaPar_AlgoCfg(&pIn_Out->s_Par.s_HlaPar.AlgoCfg);
    CParInit_HlaPar_Headlight(&pIn_Out->s_Par.s_HlaPar.Headlight);
    CParInit_HlaPar_Vehicle(&pIn_Out->s_Par.s_HlaPar.Vehicle);
    CParInit_HlaPar_Country(&pIn_Out->s_Par.s_HlaPar.Country);
    /* overwrite some data */
    pIn_Out->s_Par.s_HlaPar.Headlight.HeadLightType = pIn->s_Sig.s_VehicleState.e_HeadLightType;
    pIn_Out->s_Par.s_HlaPar.Vehicle.WindshieldType  = pIn->s_Sig.s_VehicleState.e_WindshieldType;
    pIn_Out->s_Par.s_HlaPar.Country.TrafficStyle    = pIn->s_Sig.s_VehicleState.e_TrafficStyle;

    /* CPAR_HLAR_Parameter_t */
    Set_HLA_ParameterRoi( &pIn_Out->s_Par.s_HlarPar.Roi,
                                         pIn->s_Par.s_Roi.f32_FOV_Horizontal_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_FunctionRoiAboveHorizon_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_MinBelowHorizon_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_MinAboveHorizon_rad,
                                         3.7f,          /* PrecVehLight_minDistance     */
                                         0.7f,          /* PrecVehLight_minHeight       */
                                         pIn->s_Par.s_Roi.f32_StreetLamp_Distance_m,
                                         pIn->s_Par.s_Roi.f32_StreetLamp_Height_m
                                       );
    CParInit_HlarPar_City(&pIn_Out->s_Par.s_HlarPar.City);
    CParInit_HlarPar_Highway(&pIn_Out->s_Par.s_HlarPar.Highway);
    CParInit_HlarPar_Tunnel(&pIn_Out->s_Par.s_HlarPar.Tunnel);
    CParInit_HlarPar_TrafficStyle(&pIn_Out->s_Par.s_HlarPar.TrafficStyle);
    CParInit_HlarPar_Ambient(&pIn_Out->s_Par.s_HlarPar.Ambient);
    CParInit_HlarPar_Vehicle(&pIn_Out->s_Par.s_HlarPar.Vehicle);
    CParInit_HlarPar_LightPair(&pIn_Out->s_Par.s_HlarPar.LightPair);
    CParInit_HlarPar_DistEst(&pIn_Out->s_Par.s_HlarPar.DistEst);
    CParInit_HlarPar_TTBEst(&pIn_Out->s_Par.s_HlarPar.TTBEst);

    float32 f32_RatioRedGreen, f32_RatioBlueGreen, f32_RatioGreenRef;
    float32 f32_T1_us, f32_T2_us, f32_T3_us;
    uint32  ui32_R1, ui32_R2;

    Set_HLA_CameraParameter_PreCheck_v1( &f32_RatioRedGreen,
                                           &f32_RatioBlueGreen,
                                           &f32_RatioGreenRef,
                                           &f32_T1_us,
                                           &f32_T2_us,
                                           &f32_T3_us,
                                           &ui32_R1,
                                           &ui32_R2,
                                           &pIn->s_Par.s_CameraParameter.s_RGBLuxTable,
                                           pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve
                                          );

    SetRgbLuxTable(&pIn_Out->s_Par.s_CameraParameter.s_RGBLuxTable,
                   ui32_R1,
                   ui32_R2,
                   f32_T1_us,
                   f32_T2_us,
                   f32_T3_us,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.f32_Gain,
                   f32_RatioRedGreen,
                   f32_RatioBlueGreen,
                   f32_RatioGreenRef,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength,
                   &pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0]);

    if(   (fABS(pIn->s_Par.s_SensorAngles.f32_Pitch)                  > 1.0f)
       || (fABS(pIn->s_Par.s_SensorAngles.f32_Roll)                   > 1.0f)
       || (fABS(pIn->s_Par.s_SensorAngles.f32_Yaw)                    > 1.0f)
       || (fABS(pIn->s_Par.s_SensorSocket.f32_X)                      > 10.0f)
       || (fABS(pIn->s_Par.s_SensorSocket.f32_Y)                      > 10.0f)
       || (fABS(pIn->s_Par.s_SensorSocket.f32_Z)                      > 10.0f)
       || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x       > 2000)
       || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_y       > 2000)
       || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_x         > 1000)
       || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_y         > 1000)
       || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     > 2000)
       || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     < 1000)
       || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     > 2000)
       || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     < 1000)
       || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_x            > 2000)
       || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_y            > 2000)
       || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_x)      > 1000)
       || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_y)      > 1000)
       || (pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel             > 16)
       || (pIn->s_Par.s_CameraParameter.e_bayerPattern                > 10)
       || (fABS(pIn->s_Par.s_CameraParameter.f32_cycleTime)           > 1.0f)
       || (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength> 20)
       || (fABS(pIn->s_Par.s_Roi.f32_minDistance_m)                   > 100)
       || (fABS(pIn->s_Sig.s_CaliOnline.f32_Pitch)                    > 1.0f)
       || (fABS(pIn->s_Sig.s_CaliOnline.f32_Roll)                     > 1.0f)
       || (fABS(pIn->s_Sig.s_CaliOnline.f32_Yaw)                      > 1.0f) 
       || (fABS(pIn->s_Sig.s_MotionState.f32_Speed)                   > 200.0f)
       || (fABS(pIn->s_Sig.s_MotionState.f32_YawRate)                 > 10.0f)
       || (fABS(pIn->s_Sig.s_MotionState.f32_YawRateRaw)              > 10.0f)
      )
    {
      Error = SIM_ERR_INVALID_DATA_SIZE;  
    }
  }
  else
  {
    // Error = ...
  }

  return Error;
}


uint32 CHlarInputData::SetHlarInputData_v4(HLAR_t_RequiredInputs_v3* pIn, HLAR_t_RequiredInputs* pIn_Out)
{
  uint32  i;
  uint32  Error = SIM_ERR_OK;


  if(pIn_Out && pIn)
  {
    


    pIn_Out->uiFrameCnt                   = pIn->ui32_FrameCnt;
    pIn_Out->ui32_InterfaceVersionNumber  = pIn->ui32_InterfaceVersionNumber;
    pIn_Out->uiTimeStamp_HLA_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_HLA_us;
    pIn_Out->uiTimeStamp_VDY_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_VDY_us;
    pIn_Out->uiTimeStamp_Image_us         = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_Image_us;
    pIn_Out->uiVDY_Cnt                    = pIn->ui32_VDY_Cnt;

    /* HLAR_t_InputSignals */      
    Set_HLA_Availability( &pIn_Out->s_Sig.s_Avl,
                                         Convert_HLA_eType_v1(pIn->s_Sig.s_Avl.e_Type),
                                         Convert_HLA_eState_v1(pIn->s_Sig.s_Avl.e_State),
                                         RTE_HLA_US_SENS_UNKNOWN
                                        );

    Set_HLA_ImagerState( &pIn_Out->s_Sig.s_ImagerState,
                                        Convert_HLA_eActiveChar_v1(pIn->s_Sig.s_ImagerState.e_ActiveChar),
                                        pIn->s_Sig.s_ImagerState.f32_Brightness_Lux,
                                        pIn->s_Sig.s_ImagerState.ui32_ExposureTime_us,
                                        pIn->s_Sig.s_ImagerState.ui32_FrameNumber,
                                        pIn->s_Sig.s_ImagerState.f32_Noise,

                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R1,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R2, 
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T1_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T2_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T3_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_Gain,
                                        /* response curve */
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_B_Lux
                                       );

    Set_HLA_MotionState( &pIn_Out->s_Sig.s_MotionState,
                                        pIn->s_Sig.s_MotionState.f32_SpeedDisplay,
                                        pIn->s_Sig.s_MotionState.f32_Speed,
                                        pIn->s_Sig.s_MotionState.f32_Acceleration,
                                        pIn->s_Sig.s_MotionState.f32_YawRateRaw,
                                        pIn->s_Sig.s_MotionState.f32_YawRate,
                                        pIn->s_Sig.s_MotionState.f32_YawRateQuality,
                                        pIn->s_Sig.s_MotionState.f32_YawRateVariance,
                                        pIn->s_Sig.s_MotionState.f32_SteeringWheelAngle,
                                        pIn->s_Sig.s_MotionState.f32_SteeringAngle,
                                        Convert_HLA_eMovementState_v1(pIn->s_Sig.s_MotionState.e_MoveState),
                                        pIn->s_Sig.s_MotionState.f32_MoveStateConfidence
                                       );

    Set_HLA_HeadlightState_v1( &pIn_Out->s_Sig.s_HeadlightState,
                                           Convert_HLA_eLightStyle_v1(pIn->s_Sig.s_HeadlightState.e_LightStyle_Lt),
                                           Convert_HLA_eLightStyle_v1(pIn->s_Sig.s_HeadlightState.e_LightStyle_Rt),
                                           pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Lt,
                                           pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Rt,
                                           pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Lt,
                                           pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Rt,
                                           Convert_HLA_eHighBeamState_v1(pIn->s_Sig.s_HeadlightState.e_HighBeamState),
                                           Convert_HLA_eLightModuleState_v1(pIn->s_Sig.s_HeadlightState.e_LightModuleState),
                                           pIn->s_Sig.s_HeadlightState.f32_LightDistance,
                                           pIn->s_Sig.s_HeadlightState.f32_LightOutput,
                                           Convert_HLA_eGlareReductionState_v1(pIn->s_Sig.s_HeadlightState.e_GlareReductionState)
                                          );

    Set_HLA_VehicleState( &pIn_Out->s_Sig.s_VehicleState,
                                          pIn->s_Sig.s_VehicleState.b_FogLampFront,
                                          pIn->s_Sig.s_VehicleState.b_FogLampRear,
                                          pIn->s_Sig.s_VehicleState.b_RainSensor,
                                          pIn->s_Sig.s_VehicleState.ui8_WiperState,
                                          Convert_HLA_eWiperWasherState_v1(pIn->s_Sig.s_VehicleState.e_WiperWasherFrontState),
                                          Convert_HLA_eWiperStage_v1(pIn->s_Sig.s_VehicleState.e_WiperStage),
                                          (HLA_t_VehLevel_v1)pIn->s_Sig.s_VehicleState.s_VehicleLevel
                                         );

    Set_HLA_CaliOnline(&pIn_Out->s_Sig.s_CaliOnline,
                                      pIn->s_Sig.s_CaliOnline.f32_OdoCali_m,
                                      pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                      pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                      pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw
                                     );
    
    pIn_Out->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat = Convert_HLA_eSignalState_v1(pIn->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat);
    pIn_Out->s_Sig.s_DefectPixelList.ui8_DefectsListLength      = pIn->s_Sig.s_DefectPixelList.ui8_DefectsListLength;
    //for(i=0; i<HLAR_MAX_NUM_DEFECT_PIXEL_V1; i++)
    //{
    //  Set_ICDefectPixel( pIn_Out->s_Sig.s_DefectPixelList.as_DefectList[i],
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
    //                                    Convert_HLA_eDefectPixelType_v1(pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType),
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
    //                                  );
    //}

    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned = RTE_HLA_TRAFFIC_STYLE_UNKNOWN;
    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_0;
            
    /* HLAR_t_InputParameters */
    {
      Set_HLA_CameraParameter( &pIn_Out->s_Par.s_CameraParameter,
                                              Convert_HLA_eBayerPatternType_v1(pIn->s_Par.s_CameraParameter.e_bayerPattern),
                                              pIn->s_Par.s_CameraParameter.f32_cycleTime,
                                              pIn->s_Par.s_CameraParameter.s_FocalLength,
                                              pIn->s_Par.s_CameraParameter.s_ImageSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiX1,
                                              pIn->s_Par.s_CameraParameter.s_LensCenter,

                                              /* camera distortion parameter */
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K1,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K2,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K3,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K4,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K5,
                                              /* camera distortion parameter */  

                                              /* Image header parameter */
                                              pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel,
                                              1, /* 1 byte/pixel */
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x,
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0 /* not in use right now */
                                              /* Image header parameter */
                                            );
    }

    pIn_Out->s_Par.s_SensorSocket = pIn->s_Par.s_SensorSocket;
    
    Set_HLA_SensorAngles(&pIn_Out->s_Par.s_SensorAngles,
                                        pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                        pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                        pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw,
                                        pIn->s_Par.s_SensorAngles.f32_Quality,
                                        MC_NO_VERIFICATION_DONE_YET
                                        );

    /* CPAR_HLA_Parameter_t */
    pIn_Out->s_Par.s_HlaPar.HLAType                 = RTE_HLA_TYPE_UNKNOWN;
    CParInit_HlaPar_AlgoCfg(&pIn_Out->s_Par.s_HlaPar.AlgoCfg);
    CParInit_HlaPar_Headlight(&pIn_Out->s_Par.s_HlaPar.Headlight);
    CParInit_HlaPar_Vehicle(&pIn_Out->s_Par.s_HlaPar.Vehicle);
    CParInit_HlaPar_Country(&pIn_Out->s_Par.s_HlaPar.Country);
    /* overwrite some data */
    pIn_Out->s_Par.s_HlaPar.Headlight.HeadLightType = pIn->s_Sig.s_VehicleState.e_HeadLightType;
    pIn_Out->s_Par.s_HlaPar.Vehicle.WindshieldType  = pIn->s_Sig.s_VehicleState.e_WindshieldType;
    pIn_Out->s_Par.s_HlaPar.Country.TrafficStyle    = pIn->s_Sig.s_VehicleState.e_TrafficStyle;

    /* CPAR_HLAR_Parameter_t */
    Set_HLA_ParameterRoi( &pIn_Out->s_Par.s_HlarPar.Roi,
                                         pIn->s_Par.s_Roi.f32_FOV_Horizontal_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_FunctionRoiAboveHorizon_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_MinBelowHorizon_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_MinAboveHorizon_rad,
                                         3.7f,          /* PrecVehLight_minDistance     */
                                         0.7f,          /* PrecVehLight_minHeight       */
                                         pIn->s_Par.s_Roi.f32_StreetLamp_Distance_m,
                                         pIn->s_Par.s_Roi.f32_StreetLamp_Height_m
                                       );
    CParInit_HlarPar_City(&pIn_Out->s_Par.s_HlarPar.City);
    CParInit_HlarPar_Highway(&pIn_Out->s_Par.s_HlarPar.Highway);
    CParInit_HlarPar_Tunnel(&pIn_Out->s_Par.s_HlarPar.Tunnel);
    CParInit_HlarPar_TrafficStyle(&pIn_Out->s_Par.s_HlarPar.TrafficStyle);
    CParInit_HlarPar_Ambient(&pIn_Out->s_Par.s_HlarPar.Ambient);
    CParInit_HlarPar_Vehicle(&pIn_Out->s_Par.s_HlarPar.Vehicle);
    CParInit_HlarPar_LightPair(&pIn_Out->s_Par.s_HlarPar.LightPair);
    CParInit_HlarPar_DistEst(&pIn_Out->s_Par.s_HlarPar.DistEst);
    CParInit_HlarPar_TTBEst(&pIn_Out->s_Par.s_HlarPar.TTBEst);

    float32 f32_RatioRedGreen, f32_RatioBlueGreen, f32_RatioGreenRef;
    float32 f32_T1_us, f32_T2_us, f32_T3_us;
    uint32  ui32_R1, ui32_R2;

    Set_HLA_CameraParameter_PreCheck_v1( &f32_RatioRedGreen,
                                           &f32_RatioBlueGreen,
                                           &f32_RatioGreenRef,
                                           &f32_T1_us,
                                           &f32_T2_us,
                                           &f32_T3_us,
                                           &ui32_R1,
                                           &ui32_R2,
                                           &pIn->s_Par.s_CameraParameter.s_RGBLuxTable,
                                           pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve
                                          );

    SetRgbLuxTable(&pIn_Out->s_Par.s_CameraParameter.s_RGBLuxTable,
                   ui32_R1,
                   ui32_R2,
                   f32_T1_us,
                   f32_T2_us,
                   f32_T3_us,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.f32_Gain,
                   f32_RatioRedGreen,
                   f32_RatioBlueGreen,
                   f32_RatioGreenRef,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength,
                   &pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0]);

    if(   (fABS(pIn->s_Par.s_SensorAngles.f32_Pitch)                  > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Roll)                   > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Yaw)                    > 1.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_X)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Y)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Z)                      > 10.0f)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_y       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_x         > 1000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_y         > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     < 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     < 1000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_x            > 2000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_y            > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_x)      > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_y)      > 1000)
      || (pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel             > 16)
      || (pIn->s_Par.s_CameraParameter.e_bayerPattern                > 10)
      || (fABS(pIn->s_Par.s_CameraParameter.f32_cycleTime)           > 1.0f)
      || (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength> 20)
      || (fABS(pIn->s_Par.s_Roi.f32_minDistance_m)                   > 100)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Pitch)                    > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Roll)                     > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Yaw)                      > 1.0f) 
      || (fABS(pIn->s_Sig.s_MotionState.f32_Speed)                   > 200.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRate)                 > 10.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRateRaw)              > 10.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue > 1000.0f)
      )
    {
      Error = SIM_ERR_INVALID_DATA_SIZE;  
    }
  }
  else
  {
    // Error = ...
  }

  return Error;
}

uint32 CHlarInputData::SetHlarInputData_v5(HLAR_t_RequiredInputs_v4* pIn, HLAR_t_RequiredInputs* pIn_Out)
{
  uint32  i;
  uint32  Error = SIM_ERR_OK;


  if(pIn_Out && pIn)
  {
    


    pIn_Out->uiFrameCnt                   = pIn->ui32_FrameCnt;
    pIn_Out->ui32_InterfaceVersionNumber  = pIn->ui32_InterfaceVersionNumber;
    pIn_Out->uiTimeStamp_HLA_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_HLA_us;
    pIn_Out->uiTimeStamp_VDY_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_VDY_us;
    pIn_Out->uiTimeStamp_Image_us         = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_Image_us;
    pIn_Out->uiVDY_Cnt                    = pIn->ui32_VDY_Cnt;

    /* HLAR_t_InputSignals */      
    Set_HLA_Availability( &pIn_Out->s_Sig.s_Avl,
                                         Convert_HLA_eType_v1(pIn->s_Sig.s_Avl.e_Type),
                                         Convert_HLA_eState_v1(pIn->s_Sig.s_Avl.e_State),
                                         RTE_HLA_US_SENS_UNKNOWN
                                        );


    Set_HLA_ImagerState( &pIn_Out->s_Sig.s_ImagerState,
                                        Convert_HLA_eActiveChar_v1(pIn->s_Sig.s_ImagerState.e_ActiveChar),
                                        pIn->s_Sig.s_ImagerState.f32_Brightness_Lux,
                                        pIn->s_Sig.s_ImagerState.ui32_ExposureTime_us,
                                        pIn->s_Sig.s_ImagerState.ui32_FrameNumber,
                                        pIn->s_Sig.s_ImagerState.f32_Noise,

                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R1,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R2, 
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T1_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T2_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T3_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_Gain,
                                        /* response curve */
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_B_Lux
                                       );

    Set_HLA_MotionState( &pIn_Out->s_Sig.s_MotionState,
                                        pIn->s_Sig.s_MotionState.f32_SpeedDisplay,
                                        pIn->s_Sig.s_MotionState.f32_Speed,
                                        pIn->s_Sig.s_MotionState.f32_Acceleration,
                                        pIn->s_Sig.s_MotionState.f32_YawRateRaw,
                                        pIn->s_Sig.s_MotionState.f32_YawRate,
                                        pIn->s_Sig.s_MotionState.f32_YawRateQuality,
                                        pIn->s_Sig.s_MotionState.f32_YawRateVariance,
                                        pIn->s_Sig.s_MotionState.f32_SteeringWheelAngle,
                                        pIn->s_Sig.s_MotionState.f32_SteeringAngle,
                                        Convert_HLA_eMovementState_v1(pIn->s_Sig.s_MotionState.e_MoveState),
                                        pIn->s_Sig.s_MotionState.f32_MoveStateConfidence
                                       );

    Set_HLA_HeadlightState_v1( &pIn_Out->s_Sig.s_HeadlightState,
                                           Convert_HLA_eLightStyle_v1(pIn->s_Sig.s_HeadlightState.e_LightStyle_Lt),
                                           Convert_HLA_eLightStyle_v1(pIn->s_Sig.s_HeadlightState.e_LightStyle_Rt),
                                           pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Lt,
                                           pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Rt,
                                           pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Lt,
                                           pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Rt,
                                           Convert_HLA_eHighBeamState_v1(pIn->s_Sig.s_HeadlightState.e_HighBeamState),
                                           Convert_HLA_eLightModuleState_v1(pIn->s_Sig.s_HeadlightState.e_LightModuleState),
                                           pIn->s_Sig.s_HeadlightState.f32_LightDistance,
                                           pIn->s_Sig.s_HeadlightState.f32_LightOutput,
                                           Convert_HLA_eGlareReductionState_v1(pIn->s_Sig.s_HeadlightState.e_GlareReductionState)
                                          );

    Set_HLA_VehicleState( &pIn_Out->s_Sig.s_VehicleState,
                                          pIn->s_Sig.s_VehicleState.b_FogLampFront,
                                          pIn->s_Sig.s_VehicleState.b_FogLampRear,
                                          pIn->s_Sig.s_VehicleState.b_RainSensor,
                                          pIn->s_Sig.s_VehicleState.ui8_WiperState,
                                          Convert_HLA_eWiperWasherState_v1(pIn->s_Sig.s_VehicleState.e_WiperWasherFrontState),
                                          Convert_HLA_eWiperStage_v1(pIn->s_Sig.s_VehicleState.e_WiperStage),
                                          (HLA_t_VehLevel_v1)pIn->s_Sig.s_VehicleState.s_VehicleLevel
                                         );

    Set_HLA_CaliOnline(&pIn_Out->s_Sig.s_CaliOnline,
                                      pIn->s_Sig.s_CaliOnline.f32_OdoCali_m,
                                      pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                      pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                      pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw
                                     );

    pIn_Out->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat = Convert_HLA_eSignalState_v1(pIn->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat);
    pIn_Out->s_Sig.s_DefectPixelList.ui8_DefectsListLength      = pIn->s_Sig.s_DefectPixelList.ui8_DefectsListLength;
    //for(i=0; i<HLAR_MAX_NUM_DEFECT_PIXEL_V1; i++)
    //{
    //  Set_ICDefectPixel( pIn_Out->s_Sig.s_DefectPixelList.as_DefectList[i],
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
    //                                    Convert_HLA_eDefectPixelType_v1(pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType),
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
    //                                  );
    //}

    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned = RTE_HLA_TRAFFIC_STYLE_UNKNOWN;
    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState = RTE_HLAR_TRAFFIC_LEARN_0;
            
    /* HLAR_t_InputParameters */
    {
      Set_HLA_CameraParameter( &pIn_Out->s_Par.s_CameraParameter,
                                              Convert_HLA_eBayerPatternType_v1(pIn->s_Par.s_CameraParameter.e_bayerPattern),
                                              pIn->s_Par.s_CameraParameter.f32_cycleTime,
                                              pIn->s_Par.s_CameraParameter.s_FocalLength,
                                              pIn->s_Par.s_CameraParameter.s_ImageSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiX1,
                                              pIn->s_Par.s_CameraParameter.s_LensCenter,

                                              /* camera distortion parameter */
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K1,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K2,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K3,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K4,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K5,
                                              /* camera distortion parameter */  

                                              /* Image header parameter */
                                              pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel,
                                              1, /* 1 byte/pixel */
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x,
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0 /* not in use right now */
                                              /* Image header parameter */
                                        );
    }

    pIn_Out->s_Par.s_SensorSocket = pIn->s_Par.s_SensorSocket;

    Set_HLA_SensorAngles(&pIn_Out->s_Par.s_SensorAngles,
                                        pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                        pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                        pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw,
                                        pIn->s_Par.s_SensorAngles.f32_Quality,
                                        MC_NO_VERIFICATION_DONE_YET
                                        );

    /* CPAR_HLA_Parameter_t */
    pIn_Out->s_Par.s_HlaPar.HLAType = RTE_HLA_TYPE_UNKNOWN;
    CParInit_HlaPar_AlgoCfg(&pIn_Out->s_Par.s_HlaPar.AlgoCfg);
    Set_HLA_ParameterHeadlight( &pIn_Out->s_Par.s_HlaPar.Headlight,
                                               Convert_HLA_eHeadLightType_v1(pIn->s_Par.s_VehicleParameter.e_HeadLightType),
                                               Convert_HLA_eHeadLightMechanics_v1(pIn->s_Par.s_VehicleParameter.e_HeadLightMechanics),
                                               Convert_HLA_eSpotLight_v1(pIn->s_Par.s_VehicleParameter.e_SpotLight),
                                               pIn->s_Par.s_VehicleParameter.f32_SpotLightWidth_rad,
                                               pIn->s_Par.s_VehicleParameter.f32_FullHBDefaultPos_Left_rad,
                                               pIn->s_Par.s_VehicleParameter.f32_FullHBDefaultPos_Right_rad,
                                               0.1f,           /* HeadLampLatency */
                                               0.0f            /* SpotLightTolerance */
                                              );
    Set_HLA_ParameterVehicle( &pIn_Out->s_Par.s_HlaPar.Vehicle,
                                             Convert_HLA_eWindshieldType_v1(pIn->s_Par.s_VehicleParameter.e_WindshieldType)
                                            );
    Set_HLA_ParameterCountry( &pIn_Out->s_Par.s_HlaPar.Country,
                                             Convert_HLA_eTrafficStyle_v1(pIn->s_Par.s_VehicleParameter.e_TrafficStyle),
                                             RTE_HLA_SENSMODE_NORMAL, /* SensitivityMode */
                                             RTE_HLA_MREFL_INACTIVE /* CountryWithMultipleReflectors */
                                           );
    /* CPAR_HLAR_Parameter_t */
    Set_HLA_ParameterRoi( &pIn_Out->s_Par.s_HlarPar.Roi,
                                         pIn->s_Par.s_Roi.f32_FOV_Horizontal_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_FunctionRoiAboveHorizon_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_MinBelowHorizon_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_MinAboveHorizon_rad,
                                         3.7f,          /* PrecVehLight_minDistance     */
                                         0.7f,          /* PrecVehLight_minHeight       */
                                         pIn->s_Par.s_Roi.f32_StreetLamp_Distance_m,
                                         pIn->s_Par.s_Roi.f32_StreetLamp_Height_m
                                       );
    CParInit_HlarPar_City(&pIn_Out->s_Par.s_HlarPar.City);
    CParInit_HlarPar_Highway(&pIn_Out->s_Par.s_HlarPar.Highway);
    CParInit_HlarPar_Tunnel(&pIn_Out->s_Par.s_HlarPar.Tunnel);
    CParInit_HlarPar_TrafficStyle(&pIn_Out->s_Par.s_HlarPar.TrafficStyle);
    CParInit_HlarPar_Ambient(&pIn_Out->s_Par.s_HlarPar.Ambient);
    CParInit_HlarPar_Vehicle(&pIn_Out->s_Par.s_HlarPar.Vehicle);
    CParInit_HlarPar_LightPair(&pIn_Out->s_Par.s_HlarPar.LightPair);
    CParInit_HlarPar_DistEst(&pIn_Out->s_Par.s_HlarPar.DistEst);
    CParInit_HlarPar_TTBEst(&pIn_Out->s_Par.s_HlarPar.TTBEst);


    /* Set Hla RGB Lux Table*/
    float32 f32_RatioRedGreen, f32_RatioBlueGreen, f32_RatioGreenRef;
    float32 f32_T1_us, f32_T2_us, f32_T3_us;
    uint32  ui32_R1, ui32_R2;

    Set_HLA_CameraParameter_PreCheck_v1( &f32_RatioRedGreen,
                                           &f32_RatioBlueGreen,
                                           &f32_RatioGreenRef,
                                           &f32_T1_us,
                                           &f32_T2_us,
                                           &f32_T3_us,
                                           &ui32_R1,
                                           &ui32_R2,
                                           &pIn->s_Par.s_CameraParameter.s_RGBLuxTable,
                                           pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve
                                          );

    SetRgbLuxTable(&pIn_Out->s_Par.s_CameraParameter.s_RGBLuxTable,
                   ui32_R1,
                   ui32_R2,
                   f32_T1_us,
                   f32_T2_us,
                   f32_T3_us,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.f32_Gain,
                   f32_RatioRedGreen,
                   f32_RatioBlueGreen,
                   f32_RatioGreenRef,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength,
                   &pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0]);

    if(   (fABS(pIn->s_Par.s_SensorAngles.f32_Pitch)                 > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Roll)                   > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Yaw)                    > 1.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_X)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Y)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Z)                      > 10.0f)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_y       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_x         > 1000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_y         > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     < 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     < 1000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_x            > 2000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_y            > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_x)      > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_y)      > 1000)
      || (pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel             > 16)
      || (pIn->s_Par.s_CameraParameter.e_bayerPattern                > 10)
      || (fABS(pIn->s_Par.s_CameraParameter.f32_cycleTime)           > 1.0f)
      || (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength> 20)
      || (fABS(pIn->s_Par.s_Roi.f32_minDistance_m)                   > 100)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Pitch)                    > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Roll)                     > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Yaw)                      > 1.0f) 
      || (fABS(pIn->s_Sig.s_MotionState.f32_Speed)                   > 200.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRate)                 > 10.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRateRaw)              > 10.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue > 1000.0f)
      )
    {
      Error = SIM_ERR_INVALID_DATA_SIZE;  
    }
  }
  else
  {
    // Error = ...
  }

  return Error;
}

uint32 CHlarInputData::SetHlarInputData_v6(HLAR_t_RequiredInputs_v5* pIn, HLAR_t_RequiredInputs* pIn_Out)
{  
  uint32  i;
  uint32  Error = SIM_ERR_OK;


  if(pIn_Out && pIn)
  {
    


    pIn_Out->uiFrameCnt                   = pIn->ui32_FrameCnt;
    pIn_Out->ui32_InterfaceVersionNumber  = pIn->ui32_InterfaceVersionNumber;
    pIn_Out->uiTimeStamp_HLA_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_HLA_us;
    pIn_Out->uiTimeStamp_VDY_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_VDY_us;
    pIn_Out->uiTimeStamp_Image_us         = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_Image_us;
    pIn_Out->uiVDY_Cnt                    = pIn->ui32_VDY_Cnt;

    /* HLAR_t_InputSignals */      
    Set_HLA_Availability( &pIn_Out->s_Sig.s_Avl,
                                         Convert_HLA_eType_v1(pIn->s_Sig.s_Avl.e_Type),
                                         Convert_HLA_eState_v1(pIn->s_Sig.s_Avl.e_State),
                                         RTE_HLA_US_SENS_UNKNOWN
                                        );


    Set_HLA_ImagerState( &pIn_Out->s_Sig.s_ImagerState,
                                        Convert_HLA_eActiveChar_v1(pIn->s_Sig.s_ImagerState.e_ActiveChar),
                                        pIn->s_Sig.s_ImagerState.f32_Brightness_Lux,
                                        pIn->s_Sig.s_ImagerState.ui32_ExposureTime_us,
                                        pIn->s_Sig.s_ImagerState.ui32_FrameNumber,
                                        pIn->s_Sig.s_ImagerState.f32_Noise,

                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R1,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R2, 
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T1_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T2_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T3_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_Gain,
                                        /* response curve */
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_B_Lux
                                       );

    Set_HLA_MotionState( &pIn_Out->s_Sig.s_MotionState,
                                        pIn->s_Sig.s_MotionState.f32_SpeedDisplay,
                                        pIn->s_Sig.s_MotionState.f32_Speed,
                                        pIn->s_Sig.s_MotionState.f32_Acceleration,
                                        pIn->s_Sig.s_MotionState.f32_YawRateRaw,
                                        pIn->s_Sig.s_MotionState.f32_YawRate,
                                        pIn->s_Sig.s_MotionState.f32_YawRateQuality,
                                        pIn->s_Sig.s_MotionState.f32_YawRateVariance,
                                        pIn->s_Sig.s_MotionState.f32_SteeringWheelAngle,
                                        pIn->s_Sig.s_MotionState.f32_SteeringAngle,
                                        Convert_HLA_eMovementState_v1(pIn->s_Sig.s_MotionState.e_MoveState),
                                        pIn->s_Sig.s_MotionState.f32_MoveStateConfidence
                                       );

    Set_HLA_HeadlightState_v1( &pIn_Out->s_Sig.s_HeadlightState,
                                           Convert_HLA_eLightStyle_v1(pIn->s_Sig.s_HeadlightState.e_LightStyle_Lt),
                                           Convert_HLA_eLightStyle_v1(pIn->s_Sig.s_HeadlightState.e_LightStyle_Rt),
                                           pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Lt,
                                           pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Rt,
                                           pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Lt,
                                           pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Rt,
                                           Convert_HLA_eHighBeamState_v1(pIn->s_Sig.s_HeadlightState.e_HighBeamState),
                                           Convert_HLA_eLightModuleState_v1(pIn->s_Sig.s_HeadlightState.e_LightModuleState),
                                           pIn->s_Sig.s_HeadlightState.f32_LightDistance,
                                           pIn->s_Sig.s_HeadlightState.f32_LightOutput,
                                           Convert_HLA_eGlareReductionState_v1(pIn->s_Sig.s_HeadlightState.e_GlareReductionState)
                                          );

    Set_HLA_VehicleState( &pIn_Out->s_Sig.s_VehicleState,
                                          pIn->s_Sig.s_VehicleState.b_FogLampFront,
                                          pIn->s_Sig.s_VehicleState.b_FogLampRear,
                                          pIn->s_Sig.s_VehicleState.b_RainSensor,
                                          pIn->s_Sig.s_VehicleState.ui8_WiperState,
                                          Convert_HLA_eWiperWasherState_v1(pIn->s_Sig.s_VehicleState.e_WiperWasherFrontState),
                                          Convert_HLA_eWiperStage_v1(pIn->s_Sig.s_VehicleState.e_WiperStage),
                                          (HLA_t_VehLevel_v1)pIn->s_Sig.s_VehicleState.s_VehicleLevel
                                         );

    Set_HLA_CaliOnline(&pIn_Out->s_Sig.s_CaliOnline,
                                      pIn->s_Sig.s_CaliOnline.f32_OdoCali_m,
                                      pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                      pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                      pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw
                                     );

    pIn_Out->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat = Convert_HLA_eSignalState_v1(pIn->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat);
    pIn_Out->s_Sig.s_DefectPixelList.ui8_DefectsListLength      = pIn->s_Sig.s_DefectPixelList.ui8_DefectsListLength;
    //for(i=0; i<HLAR_MAX_NUM_DEFECT_PIXEL_V1; i++)
    //{
    //  Set_ICDefectPixel( pIn_Out->s_Sig.s_DefectPixelList.as_DefectList[i],
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
    //                                    Convert_HLA_eDefectPixelType_v1(pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType),
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
    //                                  );
    //}

    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned = Convert_HLA_eTrafficStyle_v1(pIn->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned);
    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState = Convert_HLA_eTrafficStyleLearningState_v1(pIn->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState);
            
    /* HLAR_t_InputParameters */
    {
      Set_HLA_CameraParameter( &pIn_Out->s_Par.s_CameraParameter,
                                              Convert_HLA_eBayerPatternType_v1(pIn->s_Par.s_CameraParameter.e_bayerPattern),
                                              pIn->s_Par.s_CameraParameter.f32_cycleTime,
                                              pIn->s_Par.s_CameraParameter.s_FocalLength,
                                              pIn->s_Par.s_CameraParameter.s_ImageSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiX1,
                                              pIn->s_Par.s_CameraParameter.s_LensCenter,

                                              /* camera distortion parameter */
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K1,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K2,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K3,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K4,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K5,
                                              /* camera distortion parameter */  

                                              /* Image header parameter */
                                              pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel,
                                              1, /* 1 byte/pixel */
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x,
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0 /* not in use right now */
                                              /* Image header parameter */
                                        );
    }

    pIn_Out->s_Par.s_SensorSocket = pIn->s_Par.s_SensorSocket;

    Set_HLA_SensorAngles(&pIn_Out->s_Par.s_SensorAngles,
                                        pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                        pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                        pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw,
                                        pIn->s_Par.s_SensorAngles.f32_Quality,
                                        MC_NO_VERIFICATION_DONE_YET
                                        );

    /* CPAR_HLA_Parameter_t */
    pIn_Out->s_Par.s_HlaPar.HLAType = RTE_HLA_TYPE_UNKNOWN;
    CParInit_HlaPar_AlgoCfg(&pIn_Out->s_Par.s_HlaPar.AlgoCfg);
    Set_HLA_ParameterHeadlight( &pIn_Out->s_Par.s_HlaPar.Headlight,
                                               Convert_HLA_eHeadLightType_v1(pIn->s_Par.s_VehicleParameter.e_HeadLightType),
                                               Convert_HLA_eHeadLightMechanics_v1(pIn->s_Par.s_VehicleParameter.e_HeadLightMechanics),
                                               Convert_HLA_eSpotLight_v1(pIn->s_Par.s_VehicleParameter.e_SpotLight),
                                               pIn->s_Par.s_VehicleParameter.f32_SpotLightWidth_rad,
                                               pIn->s_Par.s_VehicleParameter.f32_FullHBDefaultPos_Left_rad,
                                               pIn->s_Par.s_VehicleParameter.f32_FullHBDefaultPos_Right_rad,
                                               0.1f,           /* HeadLampLatency */
                                               0.0f            /* SpotLightTolerance */
                                              );
    Set_HLA_ParameterVehicle( &pIn_Out->s_Par.s_HlaPar.Vehicle,
                                             Convert_HLA_eWindshieldType_v1(pIn->s_Par.s_VehicleParameter.e_WindshieldType)
                                            );
    Set_HLA_ParameterCountry( &pIn_Out->s_Par.s_HlaPar.Country,
                                             Convert_HLA_eTrafficStyle_v1(pIn->s_Par.s_VehicleParameter.e_TrafficStyle),
                                             RTE_HLA_SENSMODE_NORMAL, /* SensitivityMode */
                                             RTE_HLA_MREFL_INACTIVE /* CountryWithMultipleReflectors */
                                           );
    /* CPAR_HLAR_Parameter_t */
    Set_HLA_ParameterRoi( &pIn_Out->s_Par.s_HlarPar.Roi,
                                         pIn->s_Par.s_Roi.f32_FOV_Horizontal_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_FunctionRoiAboveHorizon_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_MinBelowHorizon_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_MinAboveHorizon_rad,
                                         3.7f,          /* PrecVehLight_minDistance     */
                                         0.7f,          /* PrecVehLight_minHeight       */
                                         pIn->s_Par.s_Roi.f32_StreetLamp_Distance_m,
                                         pIn->s_Par.s_Roi.f32_StreetLamp_Height_m
                                       );
    CParInit_HlarPar_City(&pIn_Out->s_Par.s_HlarPar.City);
    CParInit_HlarPar_Highway(&pIn_Out->s_Par.s_HlarPar.Highway);
    CParInit_HlarPar_Tunnel(&pIn_Out->s_Par.s_HlarPar.Tunnel);
    CParInit_HlarPar_TrafficStyle(&pIn_Out->s_Par.s_HlarPar.TrafficStyle);
    CParInit_HlarPar_Ambient(&pIn_Out->s_Par.s_HlarPar.Ambient);
    CParInit_HlarPar_Vehicle(&pIn_Out->s_Par.s_HlarPar.Vehicle);
    CParInit_HlarPar_LightPair(&pIn_Out->s_Par.s_HlarPar.LightPair);
    CParInit_HlarPar_DistEst(&pIn_Out->s_Par.s_HlarPar.DistEst);
    CParInit_HlarPar_TTBEst(&pIn_Out->s_Par.s_HlarPar.TTBEst);

    /* Set Hla RGB Lux Table*/
    float32 f32_RatioRedGreen, f32_RatioBlueGreen, f32_RatioGreenRef;
    float32 f32_T1_us, f32_T2_us, f32_T3_us;
    uint32  ui32_R1, ui32_R2;

    Set_HLA_CameraParameter_PreCheck_v1( &f32_RatioRedGreen,
                                           &f32_RatioBlueGreen,
                                           &f32_RatioGreenRef,
                                           &f32_T1_us,
                                           &f32_T2_us,
                                           &f32_T3_us,
                                           &ui32_R1,
                                           &ui32_R2,
                                           &pIn->s_Par.s_CameraParameter.s_RGBLuxTable,
                                           pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve
                                          );

    SetRgbLuxTable(&pIn_Out->s_Par.s_CameraParameter.s_RGBLuxTable,
                   ui32_R1,
                   ui32_R2,
                   f32_T1_us,
                   f32_T2_us,
                   f32_T3_us,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.f32_Gain,
                   f32_RatioRedGreen,
                   f32_RatioBlueGreen,
                   f32_RatioGreenRef,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength,
                   &pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0]);

    
    if(   (fABS(pIn->s_Par.s_SensorAngles.f32_Pitch)                 > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Roll)                   > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Yaw)                    > 1.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_X)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Y)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Z)                      > 10.0f)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_y       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_x         > 1000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_y         > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     < 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     < 1000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_x            > 2000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_y            > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_x)      > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_y)      > 1000)
      || (pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel             > 16)
      || (pIn->s_Par.s_CameraParameter.e_bayerPattern                > 10)
      || (fABS(pIn->s_Par.s_CameraParameter.f32_cycleTime)           > 1.0f)
      || (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength> 20)
      || (fABS(pIn->s_Par.s_Roi.f32_minDistance_m)                   > 100)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Pitch)                    > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Roll)                     > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Yaw)                      > 1.0f) 
      || (fABS(pIn->s_Sig.s_MotionState.f32_Speed)                   > 200.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRate)                 > 10.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRateRaw)              > 10.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue > 1000.0f)
      )
    {
      Error = SIM_ERR_INVALID_DATA_SIZE;  
    }
  }
  else
  {
    // Error = ...
  }

  return Error;

}

uint32 CHlarInputData::SetHlarInputData_v7(HLAR_t_RequiredInputs_v6* pIn, HLAR_t_RequiredInputs* pIn_Out)
{  
  uint32  i;
  uint32  Error = SIM_ERR_OK;


  if(pIn_Out && pIn)
  {
    


    pIn_Out->uiFrameCnt                   = pIn->ui32_FrameCnt;
    pIn_Out->ui32_InterfaceVersionNumber  = pIn->ui32_InterfaceVersionNumber;
    pIn_Out->uiTimeStamp_HLA_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_HLA_us;
    pIn_Out->uiTimeStamp_VDY_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_VDY_us;
    pIn_Out->uiTimeStamp_Image_us         = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_Image_us;
    pIn_Out->uiVDY_Cnt                    = pIn->ui32_VDY_Cnt;

    /* HLAR_t_InputSignals */      
    Set_HLA_Availability( &pIn_Out->s_Sig.s_Avl,
                                         Convert_HLA_eType_v1(pIn->s_Sig.s_Avl.e_Type),
                                         Convert_HLA_eState_v1(pIn->s_Sig.s_Avl.e_State),
                                         RTE_HLA_US_SENS_UNKNOWN
                                        );


    Set_HLA_ImagerState( &pIn_Out->s_Sig.s_ImagerState,
                                        Convert_HLA_eActiveChar_v1(pIn->s_Sig.s_ImagerState.e_ActiveChar),
                                        pIn->s_Sig.s_ImagerState.f32_Brightness_Lux,
                                        pIn->s_Sig.s_ImagerState.ui32_ExposureTime_us,
                                        pIn->s_Sig.s_ImagerState.ui32_FrameNumber,
                                        pIn->s_Sig.s_ImagerState.f32_Noise,

                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R1,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R2, 
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T1_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T2_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T3_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_Gain,
                                        /* response curve */
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_B_Lux
                                       );

    Set_HLA_MotionState( &pIn_Out->s_Sig.s_MotionState,
                                        pIn->s_Sig.s_MotionState.f32_SpeedDisplay,
                                        pIn->s_Sig.s_MotionState.f32_Speed,
                                        pIn->s_Sig.s_MotionState.f32_Acceleration,
                                        pIn->s_Sig.s_MotionState.f32_YawRateRaw,
                                        pIn->s_Sig.s_MotionState.f32_YawRate,
                                        pIn->s_Sig.s_MotionState.f32_YawRateQuality,
                                        pIn->s_Sig.s_MotionState.f32_YawRateVariance,
                                        pIn->s_Sig.s_MotionState.f32_SteeringWheelAngle,
                                        pIn->s_Sig.s_MotionState.f32_SteeringAngle,
                                        Convert_HLA_eMovementState_v1(pIn->s_Sig.s_MotionState.e_MoveState),
                                        pIn->s_Sig.s_MotionState.f32_MoveStateConfidence
                                       );

    Set_HLA_HeadlightState_v1( &pIn_Out->s_Sig.s_HeadlightState,
                                           Convert_HLA_eLightStyle_v1(pIn->s_Sig.s_HeadlightState.e_LightStyle_Lt),
                                           Convert_HLA_eLightStyle_v1(pIn->s_Sig.s_HeadlightState.e_LightStyle_Rt),
                                           pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Lt,
                                           pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Rt,
                                           pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Lt,
                                           pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Rt,
                                           Convert_HLA_eHighBeamState_v1(pIn->s_Sig.s_HeadlightState.e_HighBeamState),
                                           Convert_HLA_eLightModuleState_v1(pIn->s_Sig.s_HeadlightState.e_LightModuleState),
                                           pIn->s_Sig.s_HeadlightState.f32_LightDistance,
                                           pIn->s_Sig.s_HeadlightState.f32_LightOutput,
                                           Convert_HLA_eGlareReductionState_v1(pIn->s_Sig.s_HeadlightState.e_GlareReductionState)
                                          );

    Set_HLA_VehicleState( &pIn_Out->s_Sig.s_VehicleState,
                                          pIn->s_Sig.s_VehicleState.b_FogLampFront,
                                          pIn->s_Sig.s_VehicleState.b_FogLampRear,
                                          pIn->s_Sig.s_VehicleState.b_RainSensor,
                                          pIn->s_Sig.s_VehicleState.ui8_WiperState,
                                          Convert_HLA_eWiperWasherState_v1(pIn->s_Sig.s_VehicleState.e_WiperWasherFrontState),
                                          Convert_HLA_eWiperStage_v1(pIn->s_Sig.s_VehicleState.e_WiperStage),
                                          (HLA_t_VehLevel_v1)pIn->s_Sig.s_VehicleState.s_VehicleLevel
                                         );

    Set_HLA_CaliOnline(&pIn_Out->s_Sig.s_CaliOnline,
                                      pIn->s_Sig.s_CaliOnline.f32_OdoCali_m,
                                      pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                      pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                      pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw
                                     );

    pIn_Out->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat = Convert_HLA_eSignalState_v1(pIn->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat);
    pIn_Out->s_Sig.s_DefectPixelList.ui8_DefectsListLength      = pIn->s_Sig.s_DefectPixelList.ui8_DefectsListLength;
    assert(sizeof(pIn_Out->s_Sig.s_DefectPixelList.as_DefectList)/sizeof(HLA_t_ICDefectPixel) == HLAR_MAX_NUM_DEFECT_PIXEL_V1);
    //for(i=0; i<HLAR_MAX_NUM_DEFECT_PIXEL_V1; i++)
    //{
    //  Set_ICDefectPixel( pIn_Out->s_Sig.s_DefectPixelList.as_DefectList[i],
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
    //                                    Convert_HLA_eDefectPixelType_v1(pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType),
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
    //                                  );
    //}

    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned = Convert_HLA_eTrafficStyle_v1(pIn->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned);
    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState = Convert_HLA_eTrafficStyleLearningState_v1(pIn->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState);
            
    /* HLAR_t_InputParameters */
    {
      Set_HLA_CameraParameter( &pIn_Out->s_Par.s_CameraParameter,
                                              Convert_HLA_eBayerPatternType_v1(pIn->s_Par.s_CameraParameter.e_bayerPattern),
                                              pIn->s_Par.s_CameraParameter.f32_cycleTime,
                                              pIn->s_Par.s_CameraParameter.s_FocalLength,
                                              pIn->s_Par.s_CameraParameter.s_ImageSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiX1,
                                              pIn->s_Par.s_CameraParameter.s_LensCenter,

                                              /* camera distortion parameter */
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K1,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K2,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K3,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K4,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K5,
                                              /* camera distortion parameter */  

                                              /* Image header parameter */
                                              pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel,
                                              1, /* 1 byte/pixel */
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x,
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0 /* not in use right now */
                                              /* Image header parameter */
                                        );
    }

    pIn_Out->s_Par.s_SensorSocket = pIn->s_Par.s_SensorSocket;

    Set_HLA_SensorAngles(&pIn_Out->s_Par.s_SensorAngles,
                                        pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                        pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                        pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw,
                                        pIn->s_Par.s_SensorAngles.f32_Quality,
                                        MC_NO_VERIFICATION_DONE_YET
                                        );

    /* CPAR_HLA_Parameter_t */
    pIn_Out->s_Par.s_HlaPar.HLAType = RTE_HLA_TYPE_UNKNOWN;
    CParInit_HlaPar_AlgoCfg(&pIn_Out->s_Par.s_HlaPar.AlgoCfg);
    Set_HLA_ParameterHeadlight( &pIn_Out->s_Par.s_HlaPar.Headlight,
                                               Convert_HLA_eHeadLightType_v1(pIn->s_Par.s_VehicleParameter.e_HeadLightType),
                                               Convert_HLA_eHeadLightMechanics_v1(pIn->s_Par.s_VehicleParameter.e_HeadLightMechanics),
                                               Convert_HLA_eSpotLight_v1(pIn->s_Par.s_VehicleParameter.e_SpotLight),
                                               pIn->s_Par.s_VehicleParameter.f32_SpotLightWidth_rad,
                                               pIn->s_Par.s_VehicleParameter.f32_FullHBDefaultPos_Left_rad,
                                               pIn->s_Par.s_VehicleParameter.f32_FullHBDefaultPos_Right_rad,
                                               pIn->s_Par.s_VehicleParameter.f32_HeadLampLatency_s,
                                               pIn->s_Par.s_VehicleParameter.f32_SpotLightTolerance_rad
                                              );
    Set_HLA_ParameterVehicle( &pIn_Out->s_Par.s_HlaPar.Vehicle,
                                             Convert_HLA_eWindshieldType_v1(pIn->s_Par.s_VehicleParameter.e_WindshieldType)
                                            );
    Set_HLA_ParameterCountry( &pIn_Out->s_Par.s_HlaPar.Country,
                                             Convert_HLA_eTrafficStyle_v1(pIn->s_Par.s_VehicleParameter.e_TrafficStyle),
                                             RTE_HLA_SENSMODE_NORMAL, /* SensitivityMode */
                                             RTE_HLA_MREFL_INACTIVE /* CountryWithMultipleReflectors */
                                           );
    /* CPAR_HLAR_Parameter_t */
    Set_HLA_ParameterRoi( &pIn_Out->s_Par.s_HlarPar.Roi,
                                         pIn->s_Par.s_Roi.f32_FOV_Horizontal_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_FunctionRoiAboveHorizon_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_MinBelowHorizon_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_MinAboveHorizon_rad,
                                         3.7f,          /* PrecVehLight_minDistance     */
                                         0.7f,          /* PrecVehLight_minHeight       */
                                         pIn->s_Par.s_Roi.f32_StreetLamp_Distance_m,
                                         pIn->s_Par.s_Roi.f32_StreetLamp_Height_m
                                       );
    CParInit_HlarPar_City(&pIn_Out->s_Par.s_HlarPar.City);
    CParInit_HlarPar_Highway(&pIn_Out->s_Par.s_HlarPar.Highway);
    CParInit_HlarPar_Tunnel(&pIn_Out->s_Par.s_HlarPar.Tunnel);
    CParInit_HlarPar_TrafficStyle(&pIn_Out->s_Par.s_HlarPar.TrafficStyle);
    CParInit_HlarPar_Ambient(&pIn_Out->s_Par.s_HlarPar.Ambient);
    CParInit_HlarPar_Vehicle(&pIn_Out->s_Par.s_HlarPar.Vehicle);
    CParInit_HlarPar_LightPair(&pIn_Out->s_Par.s_HlarPar.LightPair);
    CParInit_HlarPar_DistEst(&pIn_Out->s_Par.s_HlarPar.DistEst);
    CParInit_HlarPar_TTBEst(&pIn_Out->s_Par.s_HlarPar.TTBEst);

    /* Set Hla RGB Lux Table*/
    float32 f32_RatioRedGreen, f32_RatioBlueGreen, f32_RatioGreenRef;
    float32 f32_T1_us, f32_T2_us, f32_T3_us;
    uint32  ui32_R1, ui32_R2;

    Set_HLA_CameraParameter_PreCheck_v1( &f32_RatioRedGreen,
                                           &f32_RatioBlueGreen,
                                           &f32_RatioGreenRef,
                                           &f32_T1_us,
                                           &f32_T2_us,
                                           &f32_T3_us,
                                           &ui32_R1,
                                           &ui32_R2,
                                           &pIn->s_Par.s_CameraParameter.s_RGBLuxTable,
                                           pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve
                                          );

    SetRgbLuxTable(&pIn_Out->s_Par.s_CameraParameter.s_RGBLuxTable,
                   ui32_R1,
                   ui32_R2,
                   f32_T1_us,
                   f32_T2_us,
                   f32_T3_us,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.f32_Gain,
                   f32_RatioRedGreen,
                   f32_RatioBlueGreen,
                   f32_RatioGreenRef,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength,
                   &pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0]);

  
    if(   (fABS(pIn->s_Par.s_SensorAngles.f32_Pitch)                 > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Roll)                   > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Yaw)                    > 1.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_X)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Y)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Z)                      > 10.0f)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_y       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_x         > 1000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_y         > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     < 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     < 1000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_x            > 2000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_y            > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_x)      > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_y)      > 1000)
      || (pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel             > 16)
      || (pIn->s_Par.s_CameraParameter.e_bayerPattern                > 10)
      || (fABS(pIn->s_Par.s_CameraParameter.f32_cycleTime)           > 1.0f)
      || (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength> 20)
      || (fABS(pIn->s_Par.s_Roi.f32_minDistance_m)                   > 100)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Pitch)                    > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Roll)                     > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Yaw)                      > 1.0f) 
      || (fABS(pIn->s_Sig.s_MotionState.f32_Speed)                   > 200.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRate)                 > 10.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRateRaw)              > 10.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue > 1000.0f)
      )
    {
      Error = SIM_ERR_INVALID_DATA_SIZE;  
    }
  }
  else
  {
    // Error = ...
  }

  return Error;

}

uint32 CHlarInputData::SetHlarInputData_v8(HLAR_t_RequiredInputs_v7* pIn, HLAR_t_RequiredInputs* pIn_Out)
{  
  uint32  i;
  uint32  Error = SIM_ERR_OK;


  if(pIn_Out && pIn)
  {
    


    pIn_Out->uiFrameCnt                   = pIn->ui32_FrameCnt;
    pIn_Out->ui32_InterfaceVersionNumber  = pIn->ui32_InterfaceVersionNumber;
    pIn_Out->uiTimeStamp_HLA_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_HLA_us;
    pIn_Out->uiTimeStamp_VDY_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_VDY_us;
    pIn_Out->uiTimeStamp_Image_us         = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_Image_us;
    pIn_Out->uiVDY_Cnt                    = pIn->ui32_VDY_Cnt;

    /* HLAR_t_InputSignals */      
    Set_HLA_Availability( &pIn_Out->s_Sig.s_Avl,
                                         Convert_HLA_eType_v2(pIn->s_Sig.s_Avl.e_Type),
                                         Convert_HLA_eState_v2(pIn->s_Sig.s_Avl.e_State),
                                         RTE_HLA_US_SENS_UNKNOWN
                                        );


    Set_HLA_ImagerState( &pIn_Out->s_Sig.s_ImagerState,
                                        pIn->s_Sig.s_ImagerState.e_ActiveChar,
                                        pIn->s_Sig.s_ImagerState.f32_Brightness_Lux,
                                        pIn->s_Sig.s_ImagerState.ui32_ExposureTime_us,
                                        pIn->s_Sig.s_ImagerState.ui32_FrameNumber,
                                        pIn->s_Sig.s_ImagerState.f32_Noise,

                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R1,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R2, 
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T1_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T2_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T3_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_Gain,
                                        /* response curve */
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_B_Lux
                                       );

    Set_HLA_MotionState( &pIn_Out->s_Sig.s_MotionState,
                                        pIn->s_Sig.s_MotionState.f32_SpeedDisplay,
                                        pIn->s_Sig.s_MotionState.f32_Speed,
                                        pIn->s_Sig.s_MotionState.f32_Acceleration,
                                        pIn->s_Sig.s_MotionState.f32_YawRateRaw,
                                        pIn->s_Sig.s_MotionState.f32_YawRate,
                                        pIn->s_Sig.s_MotionState.f32_YawRateQuality,
                                        pIn->s_Sig.s_MotionState.f32_YawRateVariance,
                                        pIn->s_Sig.s_MotionState.f32_SteeringWheelAngle,
                                        pIn->s_Sig.s_MotionState.f32_SteeringAngle,
                                        pIn->s_Sig.s_MotionState.e_MoveState,
                                        pIn->s_Sig.s_MotionState.f32_MoveStateConfidence
                                       );
				       
    Set_HLA_HeadlightState_v1( &pIn_Out->s_Sig.s_HeadlightState,
                                           Convert_HLA_eLightStyle_v2(pIn->s_Sig.s_HeadlightState.e_LightStyle_Lt),
                                           Convert_HLA_eLightStyle_v2(pIn->s_Sig.s_HeadlightState.e_LightStyle_Rt),
                                           pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Lt,
                                           pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Rt,
                                           pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Lt,
                                           pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Rt,
                                           Convert_HLA_eHighBeamState_v1(pIn->s_Sig.s_HeadlightState.e_HighBeamState),
                                           Convert_HLA_eLightModuleState_v2(pIn->s_Sig.s_HeadlightState.e_LightModuleState),
                                           pIn->s_Sig.s_HeadlightState.f32_LightDistance,
                                           pIn->s_Sig.s_HeadlightState.f32_LightOutput,
                                           Convert_HLA_eGlareReductionState_v2(pIn->s_Sig.s_HeadlightState.e_GlareReductionState)
                                          );

    Set_HLA_VehicleState( &pIn_Out->s_Sig.s_VehicleState,
                                         pIn->s_Sig.s_VehicleState.b_FogLampFront,
                                         pIn->s_Sig.s_VehicleState.b_FogLampRear,
                                         pIn->s_Sig.s_VehicleState.b_RainSensor,
                                         pIn->s_Sig.s_VehicleState.ui8_WiperState,
                                         pIn->s_Sig.s_VehicleState.e_WiperWasherFrontState,
                                         pIn->s_Sig.s_VehicleState.e_WiperStage,
                                         (HLA_t_VehLevel_v1)pIn->s_Sig.s_VehicleState.s_VehicleLevel
                                        );

    Set_HLA_CaliOnline(&pIn_Out->s_Sig.s_CaliOnline,
                                      pIn->s_Sig.s_CaliOnline.f32_OdoCali_m,
                                      pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                      pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                      pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw
                                     );

    pIn_Out->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat = Convert_HLA_eSignalState_v1(pIn->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat);
    pIn_Out->s_Sig.s_DefectPixelList.ui8_DefectsListLength      = pIn->s_Sig.s_DefectPixelList.ui8_DefectsListLength;
    //for(i=0; i<HLAR_MAX_NUM_DEFECT_PIXEL_V1; i++)
    //{
    //  Set_ICDefectPixel( pIn_Out->s_Sig.s_DefectPixelList.as_DefectList[i],
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
    //                                    Convert_HLA_eDefectPixelType_v1(pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType),
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
    //                                  );
    //}

    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned = Convert_HLA_eTrafficStyle_v1(pIn->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned);
    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState = Convert_HLA_eTrafficStyleLearningState_v2(pIn->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState);
            
    /* HLAR_t_InputParameters */
    {
      Set_HLA_CameraParameter( &pIn_Out->s_Par.s_CameraParameter,
                                              Convert_HLA_eBayerPatternType_v2(pIn->s_Par.s_CameraParameter.e_bayerPattern),
                                              pIn->s_Par.s_CameraParameter.f32_cycleTime,
                                              pIn->s_Par.s_CameraParameter.s_FocalLength,
                                              pIn->s_Par.s_CameraParameter.s_ImageSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiX1,
                                              pIn->s_Par.s_CameraParameter.s_LensCenter,

                                              /* camera distortion parameter */
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K1,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K2,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K3,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K4,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K5,
                                              /* camera distortion parameter */  

                                              /* Image header parameter */
                                              pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel,
                                              1, /* 1 byte/pixel */
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x,
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0 /* not in use right now */
                                              /* Image header parameter */
                                        );
    }

    pIn_Out->s_Par.s_SensorSocket = pIn->s_Par.s_SensorSocket;

    Set_HLA_SensorAngles(&pIn_Out->s_Par.s_SensorAngles,
                                        pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                        pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                        pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw,
                                        pIn->s_Par.s_SensorAngles.f32_Quality,
                                        MC_NO_VERIFICATION_DONE_YET
                                        );

    /* CPAR_HLA_Parameter_t */
    pIn_Out->s_Par.s_HlaPar.HLAType = RTE_HLA_TYPE_UNKNOWN;
    CParInit_HlaPar_AlgoCfg(&pIn_Out->s_Par.s_HlaPar.AlgoCfg);
    Set_HLA_ParameterHeadlight( &pIn_Out->s_Par.s_HlaPar.Headlight,
                                               Convert_HLA_eHeadLightType_v1(pIn->s_Par.s_VehicleParameter.e_HeadLightType),
                                               Convert_HLA_eHeadLightMechanics_v1(pIn->s_Par.s_VehicleParameter.e_HeadLightMechanics),
                                               Convert_HLA_eSpotLight_v1(pIn->s_Par.s_VehicleParameter.e_SpotLight),
                                               pIn->s_Par.s_VehicleParameter.f32_SpotLightWidth_rad,
                                               pIn->s_Par.s_VehicleParameter.f32_FullHBDefaultPos_Left_rad,
                                               pIn->s_Par.s_VehicleParameter.f32_FullHBDefaultPos_Right_rad,
                                               pIn->s_Par.s_VehicleParameter.f32_HeadLampLatency_s,
                                               pIn->s_Par.s_VehicleParameter.f32_SpotLightTolerance_rad                                              
                                              );

    Set_HLA_ParameterVehicle( &pIn_Out->s_Par.s_HlaPar.Vehicle,
                                             Convert_HLA_eWindshieldType_v1(pIn->s_Par.s_VehicleParameter.e_WindshieldType)
                                            );
    Set_HLA_ParameterCountry( &pIn_Out->s_Par.s_HlaPar.Country,
                                             Convert_HLA_eTrafficStyle_v1(pIn->s_Par.s_VehicleParameter.e_TrafficStyle),
                                             RTE_HLA_SENSMODE_NORMAL, /* SensitivityMode */
                                             RTE_HLA_MREFL_INACTIVE /* CountryWithMultipleReflectors */
                                           );
    /* CPAR_HLAR_Parameter_t */
    Set_HLA_ParameterRoi( &pIn_Out->s_Par.s_HlarPar.Roi,
                                         pIn->s_Par.s_Roi.f32_FOV_Horizontal_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_FunctionRoiAboveHorizon_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_MinBelowHorizon_rad,
                                         pIn->s_Par.s_Roi.f32_FOV_MinAboveHorizon_rad,
                                         pIn->s_Par.s_Roi.f32_minDistance_m,
                                         pIn->s_Par.s_Roi.f32_minHeight_m,
                                         pIn->s_Par.s_Roi.f32_StreetLamp_Distance_m,
                                         pIn->s_Par.s_Roi.f32_StreetLamp_Height_m
                                       );
    CParInit_HlarPar_City(&pIn_Out->s_Par.s_HlarPar.City);
    CParInit_HlarPar_Highway(&pIn_Out->s_Par.s_HlarPar.Highway);
    CParInit_HlarPar_Tunnel(&pIn_Out->s_Par.s_HlarPar.Tunnel);
    CParInit_HlarPar_TrafficStyle(&pIn_Out->s_Par.s_HlarPar.TrafficStyle);
    CParInit_HlarPar_Ambient(&pIn_Out->s_Par.s_HlarPar.Ambient);
    CParInit_HlarPar_Vehicle(&pIn_Out->s_Par.s_HlarPar.Vehicle);
    CParInit_HlarPar_LightPair(&pIn_Out->s_Par.s_HlarPar.LightPair);
    CParInit_HlarPar_DistEst(&pIn_Out->s_Par.s_HlarPar.DistEst);
    CParInit_HlarPar_TTBEst(&pIn_Out->s_Par.s_HlarPar.TTBEst);

    /* Set Hla RGB Lux Table*/
    float32 f32_RatioRedGreen, f32_RatioBlueGreen, f32_RatioGreenRef;
    float32 f32_T1_us, f32_T2_us, f32_T3_us;
    uint32  ui32_R1, ui32_R2;

    Set_HLA_CameraParameter_PreCheck_v1( &f32_RatioRedGreen,
                                           &f32_RatioBlueGreen,
                                           &f32_RatioGreenRef,
                                           &f32_T1_us,
                                           &f32_T2_us,
                                           &f32_T3_us,
                                           &ui32_R1,
                                           &ui32_R2,
                                           &pIn->s_Par.s_CameraParameter.s_RGBLuxTable,
                                           pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve
                                          );

    SetRgbLuxTable(&pIn_Out->s_Par.s_CameraParameter.s_RGBLuxTable,
                   ui32_R1,
                   ui32_R2,
                   f32_T1_us,
                   f32_T2_us,
                   f32_T3_us,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.f32_Gain,
                   f32_RatioRedGreen,
                   f32_RatioBlueGreen,
                   f32_RatioGreenRef,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength,
                   &pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0]);

    

    if(  (fABS(pIn->s_Par.s_SensorAngles.f32_Pitch)                  > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Roll)                   > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Yaw)                    > 1.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_X)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Y)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Z)                      > 10.0f)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_y       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_x         > 1000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_y         > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     < 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     < 1000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_x            > 2000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_y            > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_x)      > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_y)      > 1000)
      || (pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel             > 16)
      || (pIn->s_Par.s_CameraParameter.e_bayerPattern                > 10)
      || (fABS(pIn->s_Par.s_CameraParameter.f32_cycleTime)           > 1.0f)
      || (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength> 20)
      || (fABS(pIn->s_Par.s_Roi.f32_minDistance_m)                   > 100)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Pitch)                    > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Roll)                     > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Yaw)                      > 1.0f) 
      || (fABS(pIn->s_Sig.s_MotionState.f32_Speed)                   > 200.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRate)                 > 10.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRateRaw)              > 10.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue > 1000.0f)
      )
    {
      Error = SIM_ERR_INVALID_DATA_SIZE;  
    }
  }
  else
  {
    // Error = ...
  }

  return Error;
}

uint32 CHlarInputData::SetHlarInputData_v9(HLAR_t_RequiredInputs_v8* pIn, HLAR_t_RequiredInputs* pIn_Out)
{  
  uint32  i;
  uint32  Error = SIM_ERR_OK;


  if(pIn_Out && pIn)
  {
    


    pIn_Out->uiFrameCnt                   = pIn->ui32_FrameCnt;
    pIn_Out->ui32_InterfaceVersionNumber  = pIn->ui32_InterfaceVersionNumber;
    pIn_Out->uiTimeStamp_HLA_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_HLA_us;
    pIn_Out->uiTimeStamp_VDY_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_VDY_us;
    pIn_Out->uiTimeStamp_Image_us         = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_Image_us;
    pIn_Out->uiVDY_Cnt                    = pIn->ui32_VDY_Cnt;

    /* HLAR_t_InputSignals */
    Set_HLA_Availability( &pIn_Out->s_Sig.s_Avl,
                                         pIn->s_Sig.s_Avl.e_Type,
                                         pIn->s_Sig.s_Avl.e_State,
                                         pIn->s_Sig.s_Avl.e_USSens
                                        );
   Set_HLA_ImagerState( &pIn_Out->s_Sig.s_ImagerState,
                                        pIn->s_Sig.s_ImagerState.e_ActiveChar,
                                        pIn->s_Sig.s_ImagerState.f32_Brightness_Lux,
                                        pIn->s_Sig.s_ImagerState.ui32_ExposureTime_us,
                                        pIn->s_Sig.s_ImagerState.ui32_FrameNumber,
                                        pIn->s_Sig.s_ImagerState.f32_Noise,

                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R1,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R2, 
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T1_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T2_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T3_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_Gain,
                                        /* response curve */
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_B_Lux
                                       );

    Set_HLA_MotionState( &pIn_Out->s_Sig.s_MotionState,
                                        pIn->s_Sig.s_MotionState.f32_SpeedDisplay,
                                        pIn->s_Sig.s_MotionState.f32_Speed,
                                        pIn->s_Sig.s_MotionState.f32_Acceleration,
                                        pIn->s_Sig.s_MotionState.f32_YawRateRaw,
                                        pIn->s_Sig.s_MotionState.f32_YawRate,
                                        pIn->s_Sig.s_MotionState.f32_YawRateQuality,
                                        pIn->s_Sig.s_MotionState.f32_YawRateVariance,
                                        pIn->s_Sig.s_MotionState.f32_SteeringWheelAngle,
                                        pIn->s_Sig.s_MotionState.f32_SteeringAngle,
                                        pIn->s_Sig.s_MotionState.e_MoveState,
                                        pIn->s_Sig.s_MotionState.f32_MoveStateConfidence
                                       );

    Set_HLA_HeadlightState_v1( &pIn_Out->s_Sig.s_HeadlightState,
                                              pIn->s_Sig.s_HeadlightState.e_LightStyle_Lt,
                                              pIn->s_Sig.s_HeadlightState.e_LightStyle_Rt,
                                              pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Lt,
                                              pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Rt,
                                              /*pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Lt,
                                              pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Rt,*/

                                              /* HACK: temporary correction of wrong values due to wrong formula */
                                              CML_Deg2Rad(CML_Rad2Deg(pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Lt) - 20.8f),
                                              CML_Deg2Rad(CML_Rad2Deg(pIn->s_Sig.s_HeadlightState.f32_PartHBCutoffAng_Rt) - 30.0f),
                                              /* HACK: temporary correction of wrong values due to wrong formula */

                                              pIn->s_Sig.s_HeadlightState.e_HighBeamState,
                                              pIn->s_Sig.s_HeadlightState.e_LightModuleState,
                                              pIn->s_Sig.s_HeadlightState.f32_LightDistance,
                                              pIn->s_Sig.s_HeadlightState.f32_LightOutput,
                                              pIn->s_Sig.s_HeadlightState.e_GlareReductionState
                                            );

    Set_HLA_VehicleState( &pIn_Out->s_Sig.s_VehicleState,
                                         pIn->s_Sig.s_VehicleState.b_FogLampFront,
                                         pIn->s_Sig.s_VehicleState.b_FogLampRear,
                                         pIn->s_Sig.s_VehicleState.b_RainSensor,
                                         pIn->s_Sig.s_VehicleState.ui8_WiperState,
                                         pIn->s_Sig.s_VehicleState.e_WiperWasherFrontState,
                                         pIn->s_Sig.s_VehicleState.e_WiperStage,
                                         (HLA_t_VehLevel_v1)pIn->s_Sig.s_VehicleState.s_VehicleLevel
                                        );

    Set_HLA_CaliOnline(&pIn_Out->s_Sig.s_CaliOnline,
                                      pIn->s_Sig.s_CaliOnline.f32_OdoCali_m,
                                      pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                      pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                      pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw
                                     );

    pIn_Out->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat = pIn->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat;
    pIn_Out->s_Sig.s_DefectPixelList.ui8_DefectsListLength      = pIn->s_Sig.s_DefectPixelList.ui8_DefectsListLength;
    //for(i=0; i<RTE_HLAR_DEFECT_PIXEL_LIST_LENGTH; i++)
    //{
    //  Set_ICDefectPixel( pIn_Out->s_Sig.s_DefectPixelList.as_DefectList[i],
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
    //                                   );
    //}
    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned   = pIn->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned;
    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState = pIn->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState;

    /* HLAR_t_InputParameters */
    {
      Set_HLA_CameraParameter( &pIn_Out->s_Par.s_CameraParameter,
                                              pIn->s_Par.s_CameraParameter.e_bayerPattern,
                                              pIn->s_Par.s_CameraParameter.f32_cycleTime,
                                              pIn->s_Par.s_CameraParameter.s_FocalLength,
                                              pIn->s_Par.s_CameraParameter.s_ImageSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiX1,
                                              pIn->s_Par.s_CameraParameter.s_LensCenter,

                                              /* camera distortion parameter */
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K1,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K2,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K3,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K4,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K5,
                                              /* camera distortion parameter */  

                                              /* Image header parameter */
                                              pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel,
                                              1, /* 1 byte/pixel */
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x,
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0 /* not in use right now */
                                              /* Image header parameter */
                                             );
    }

    pIn_Out->s_Par.s_SensorSocket = pIn->s_Par.s_SensorSocket;

    Set_HLA_SensorAngles(&pIn_Out->s_Par.s_SensorAngles,
                                        pIn->s_Sig.s_CaliOnline.f32_Pitch + pIn->s_Par.s_SensorAngles.f32_Pitch,
                                        pIn->s_Sig.s_CaliOnline.f32_Roll  + pIn->s_Par.s_SensorAngles.f32_Roll,
                                        pIn->s_Sig.s_CaliOnline.f32_Yaw   + pIn->s_Par.s_SensorAngles.f32_Yaw,
                                        pIn->s_Par.s_SensorAngles.f32_Quality,
                                        MC_NO_VERIFICATION_DONE_YET
                                        );

    /* CPAR_HLA_Parameter_t */
    pIn_Out->s_Par.s_HlaPar.HLAType = pIn->s_Par.s_HlaPar.HLAType;
    Set_HLA_ParameterAlgoCfg( &pIn_Out->s_Par.s_HlaPar.AlgoCfg,
                                             pIn->s_Par.s_HlaPar.AlgoCfg.TestMode,
                                             pIn->s_Par.s_HlaPar.AlgoCfg.CityDetection,
                                             pIn->s_Par.s_HlaPar.AlgoCfg.TunnelDetection,
                                             pIn->s_Par.s_HlaPar.AlgoCfg.BadPixelDetection,
                                             pIn->s_Par.s_HlaPar.AlgoCfg.FogDetection,
                                             pIn->s_Par.s_HlaPar.AlgoCfg.BlockageDetection
                                            );
    Set_HLA_ParameterHeadlight( &pIn_Out->s_Par.s_HlaPar.Headlight,
                                                pIn->s_Par.s_HlaPar.Headlight.HeadLightType,
                                                pIn->s_Par.s_HlaPar.Headlight.HeadLightMechanics,
                                                pIn->s_Par.s_HlaPar.Headlight.SpotLight,
                                                pIn->s_Par.s_HlaPar.Headlight.SpotLightWidth,
                                                pIn->s_Par.s_HlaPar.Headlight.FullHBDefaultPos_Left,
                                                pIn->s_Par.s_HlaPar.Headlight.FullHBDefaultPos_Right,
                                                pIn->s_Par.s_HlaPar.Headlight.HeadLampLatency,
                                                pIn->s_Par.s_HlaPar.Headlight.SpotLightTolerance
                                             );

    Set_HLA_ParameterVehicle( &pIn_Out->s_Par.s_HlaPar.Vehicle,
                                             pIn->s_Par.s_HlaPar.Vehicle.WindshieldType
                                            );
    Set_HLA_ParameterCountry( &pIn_Out->s_Par.s_HlaPar.Country,
                                             pIn->s_Par.s_HlaPar.Country.TrafficStyle,
                                             pIn->s_Par.s_HlaPar.Country.SensitivityMode,
                                             pIn->s_Par.s_HlaPar.Country.CountryWithMultipleReflectors
                                            );
    /* CPAR_HLAR_Parameter_t */
    Set_HLA_ParameterRoi( &pIn_Out->s_Par.s_HlarPar.Roi,
                                         pIn->s_Par.s_HlarPar.Roi.FOV_Horizontal,
                                         pIn->s_Par.s_HlarPar.Roi.FOV_FunctionRoiAboveHorizon,
                                         pIn->s_Par.s_HlarPar.Roi.FOV_MinBelowHorizon,
                                         pIn->s_Par.s_HlarPar.Roi.FOV_MinAboveHorizon,
                                         pIn->s_Par.s_HlarPar.Roi.PrecVehLight_minDistance,
                                         pIn->s_Par.s_HlarPar.Roi.PrecVehLight_minHeight,
                                         pIn->s_Par.s_HlarPar.Roi.StreetLamp_Distance,
                                         pIn->s_Par.s_HlarPar.Roi.StreetLamp_Height
                                        );
    Set_HLA_ParameterCity( &pIn_Out->s_Par.s_HlarPar.City,
                                          pIn->s_Par.s_HlarPar.City.SpeedThresholdLow,
                                          pIn->s_Par.s_HlarPar.City.SpeedThresholdHigh,
                                          pIn->s_Par.s_HlarPar.City.NumLeavingStreetlamp_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.NumLeavingStreetlamp_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.NumSceneStreetlamp_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.NumSceneStreetlamp_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.AmbientLevel_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.AmbientLevel_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.StreetLampMaxInterDist_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.StreetLampMaxInterDist_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.StreetLampMaxDist_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.StreetLampMaxDist_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.LeavingCityDelay_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.LeavingCityDelay_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.LeavingCityDelaySceneStreetlamp_LowInt,
                                          pIn->s_Par.s_HlarPar.City.LeavingCityDelaySceneStreetlamp_HighInt,
                                          pIn->s_Par.s_HlarPar.City.NumTunnelStreetlamp
                                         );
    Set_HLA_ParameterHighway( &pIn_Out->s_Par.s_HlarPar.Highway,
                                             pIn->s_Par.s_HlarPar.Highway.SpeedDetThreshold_Fast,
                                             pIn->s_Par.s_HlarPar.Highway.SpeedDetThreshold,
                                             pIn->s_Par.s_HlarPar.Highway.SpeedDetThresholdDistance,
                                             pIn->s_Par.s_HlarPar.Highway.EgoMotionDetThresholdHigh,
                                             pIn->s_Par.s_HlarPar.Highway.EgoMotionDetThresholdLow,
                                             pIn->s_Par.s_HlarPar.Highway.LateralPositionUsedTracks,
                                             pIn->s_Par.s_HlarPar.Highway.LateralPositionConfidenceThreshHigh,
                                             pIn->s_Par.s_HlarPar.Highway.LateralPositionConfidenceThreshLow,
                                             pIn->s_Par.s_HlarPar.Highway.OcclusionOncomingLeavingLightsThresh,
                                             pIn->s_Par.s_HlarPar.Highway.OcclusionConfidenceStep
                                            );

    Set_HLA_ParameterTunnel( &pIn_Out->s_Par.s_HlarPar.Tunnel,
                                            pIn->s_Par.s_HlarPar.Tunnel.EntryThreshHigh,
                                            pIn->s_Par.s_HlarPar.Tunnel.EntryThreshLow,
                                            pIn->s_Par.s_HlarPar.Tunnel.EntryDistanceMin,
                                            pIn->s_Par.s_HlarPar.Tunnel.EntryDistanceMax,
                                            pIn->s_Par.s_HlarPar.Tunnel.ExitThreshHigh,
                                            pIn->s_Par.s_HlarPar.Tunnel.ExitThreshLow,
                                            pIn->s_Par.s_HlarPar.Tunnel.ExitDistanceMin,
                                            pIn->s_Par.s_HlarPar.Tunnel.DetectionTypeDistance
                                          );

    Set_HLA_ParameterTrafficStyle( &pIn_Out->s_Par.s_HlarPar.TrafficStyle,
                                                  pIn->s_Par.s_HlarPar.TrafficStyle.NumOncLightsThres,
                                                  pIn->s_Par.s_HlarPar.TrafficStyle.NumOncLightsLock
                                                 );
 
    Set_HLA_ParameterAmbient( &pIn_Out->s_Par.s_HlarPar.Ambient,
                                             pIn->s_Par.s_HlarPar.Ambient.SpeedThreshold,
                                             pIn->s_Par.s_HlarPar.Ambient.AmbientLevel_LowSpeed,
                                             pIn->s_Par.s_HlarPar.Ambient.AmbientLevel_HighSpeed,
                                             pIn->s_Par.s_HlarPar.Ambient.Day2NightTimeThres_LowSpeed,
                                             pIn->s_Par.s_HlarPar.Ambient.Day2NightTimeThres_HighSpeed,
                                             pIn->s_Par.s_HlarPar.Ambient.Day2NightDistThres_LowSpeed,
                                             pIn->s_Par.s_HlarPar.Ambient.Day2NightDistThres_HighSpeed,
                                             pIn->s_Par.s_HlarPar.Ambient.Night2DayTimeThres_LowSpeed,
                                             pIn->s_Par.s_HlarPar.Ambient.Night2DayTimeThres_HighSpeed,
                                             pIn->s_Par.s_HlarPar.Ambient.Night2DayDistThres_LowSpeed,
                                             pIn->s_Par.s_HlarPar.Ambient.Night2DayDistThres_HighSpeed
                                            );
    Set_HLA_ParameterVehDet( &pIn_Out->s_Par.s_HlarPar.Vehicle,
                                            pIn->s_Par.s_HlarPar.Vehicle.OncSensitivity,
                                            pIn->s_Par.s_HlarPar.Vehicle.PrecSensitivity
                                           );
    Set_HLA_ParameterLightPair( &pIn_Out->s_Par.s_HlarPar.LightPair,
                                               pIn->s_Par.s_HlarPar.LightPair.TaillightWidth_Min,
                                               pIn->s_Par.s_HlarPar.LightPair.TaillightWidth_Max,
                                               pIn->s_Par.s_HlarPar.LightPair.HeadlightWidth_Min,
                                               pIn->s_Par.s_HlarPar.LightPair.HeadlightWidth_Max,
                                               pIn->s_Par.s_HlarPar.LightPair.TaillightHeight_Min,
                                               pIn->s_Par.s_HlarPar.LightPair.TaillightHeight_Max,
                                               pIn->s_Par.s_HlarPar.LightPair.HeadlightHeight_Min,
                                               pIn->s_Par.s_HlarPar.LightPair.HeadlightHeight_Max
                                              );
    Set_HLA_ParameterDistEst( &pIn_Out->s_Par.s_HlarPar.DistEst,
                                             pIn->s_Par.s_HlarPar.DistEst.LightHeight_Min,
                                             pIn->s_Par.s_HlarPar.DistEst.LightHeight_Max,
                                             pIn->s_Par.s_HlarPar.DistEst.DistFilterConst
                                            );
    Set_HLA_ParameterTTBEst( &pIn_Out->s_Par.s_HlarPar.TTBEst,
                                            pIn->s_Par.s_HlarPar.TTBEst.ttbAngle
                                           );

    /* Set Hla RGB Lux Table*/
    float32 f32_RatioRedGreen, f32_RatioBlueGreen, f32_RatioGreenRef;
    float32 f32_T1_us, f32_T2_us, f32_T3_us;
    uint32  ui32_R1, ui32_R2;

    Set_HLA_CameraParameter_PreCheck_v1( &f32_RatioRedGreen,
                                           &f32_RatioBlueGreen,
                                           &f32_RatioGreenRef,
                                           &f32_T1_us,
                                           &f32_T2_us,
                                           &f32_T3_us,
                                           &ui32_R1,
                                           &ui32_R2,
                                           &pIn->s_Par.s_CameraParameter.s_RGBLuxTable,
                                           pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve
                                          );

    SetRgbLuxTable(&pIn_Out->s_Par.s_CameraParameter.s_RGBLuxTable,
                   ui32_R1,
                   ui32_R2,
                   f32_T1_us,
                   f32_T2_us,
                   f32_T3_us,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.f32_Gain,
                   f32_RatioRedGreen,
                   f32_RatioBlueGreen,
                   f32_RatioGreenRef,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength,
                   &pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0]);
   
    if(  (fABS(pIn->s_Par.s_SensorAngles.f32_Pitch)                  > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Roll)                   > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Yaw)                    > 1.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_X)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Y)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Z)                      > 10.0f)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_y       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_x         > 1000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_y         > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     < 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     < 1000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_x            > 2000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_y            > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_x)      > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_y)      > 1000)
      || (pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel             > 16)
      || (pIn->s_Par.s_CameraParameter.e_bayerPattern                > 10)
      || (fABS(pIn->s_Par.s_CameraParameter.f32_cycleTime)           > 1.0f)
      || (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength> 20)
      || (fABS(pIn->s_Par.s_HlarPar.Roi.PrecVehLight_minDistance)    > 100)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Pitch)                    > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Roll)                     > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Yaw)                      > 1.0f) 
      || (fABS(pIn->s_Sig.s_MotionState.f32_Speed)                   > 200.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRate)                 > 10.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRateRaw)              > 10.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue > 1000.0f)
      )
    {
      Error = SIM_ERR_INVALID_DATA_SIZE;  
    }
  }
  else
  {
    // Error = ...
  }

  return Error;
}

uint32 CHlarInputData::SetHlarInputData_v10(HLAR_t_RequiredInputs_v9* pIn, HLAR_t_RequiredInputs* pIn_Out)
{  
  uint32  i;
  uint32  Error = SIM_ERR_OK;


  if(pIn_Out && pIn)
  {
    


    pIn_Out->uiFrameCnt                   = pIn->ui32_FrameCnt;
    pIn_Out->ui32_InterfaceVersionNumber  = pIn->ui32_InterfaceVersionNumber;
    pIn_Out->uiTimeStamp_HLA_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_HLA_us;
    pIn_Out->uiTimeStamp_VDY_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_VDY_us;
    pIn_Out->uiTimeStamp_Image_us         = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_Image_us;
    pIn_Out->uiVDY_Cnt                    = pIn->ui32_VDY_Cnt;

    /* HLAR_t_InputSignals */
    Set_HLA_Availability(&pIn_Out->s_Sig.s_Avl,
                                        pIn->s_Sig.s_Avl.e_Type,
                                        pIn->s_Sig.s_Avl.e_State,
                                        pIn->s_Sig.s_Avl.e_USSens
                                       );
    Set_HLA_ImagerState( &pIn_Out->s_Sig.s_ImagerState,
                                        pIn->s_Sig.s_ImagerState.e_ActiveChar,
                                        pIn->s_Sig.s_ImagerState.f32_Brightness_Lux,
                                        pIn->s_Sig.s_ImagerState.ui32_ExposureTime_us,
                                        pIn->s_Sig.s_ImagerState.ui32_FrameNumber,
                                        pIn->s_Sig.s_ImagerState.f32_Noise,

                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R1,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R2, 
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T1_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T2_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T3_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_Gain,
                                        /* response curve */
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_B_Lux
                                      );

    Set_HLA_MotionState( &pIn_Out->s_Sig.s_MotionState,
                                        pIn->s_Sig.s_MotionState.f32_SpeedDisplay,
                                        pIn->s_Sig.s_MotionState.f32_Speed,
                                        pIn->s_Sig.s_MotionState.f32_Acceleration,
                                        pIn->s_Sig.s_MotionState.f32_YawRateRaw,
                                        pIn->s_Sig.s_MotionState.f32_YawRate,
                                        pIn->s_Sig.s_MotionState.f32_YawRateQuality,
                                        pIn->s_Sig.s_MotionState.f32_YawRateVariance,
                                        pIn->s_Sig.s_MotionState.f32_SteeringWheelAngle,
                                        pIn->s_Sig.s_MotionState.f32_SteeringAngle,
                                        pIn->s_Sig.s_MotionState.e_MoveState,
                                        pIn->s_Sig.s_MotionState.f32_MoveStateConfidence
                                      );

    Set_HLA_HeadlightState_v2( &pIn_Out->s_Sig.s_HeadlightState,
                                              pIn->s_Sig.s_HeadlightState.e_LightModuleState,                                        
                                              pIn->s_Sig.s_HeadlightState.e_HighBeamState,
                                              pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Lt,
                                              pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Rt,
                                              pIn->s_Sig.s_HeadlightState.e_GlareReductionState,
                                              pIn->s_Sig.s_HeadlightState.f32_LightOutput,
                                              pIn->s_Sig.s_HeadlightState.nGFA
                                            );

    for(i=0; i<pIn->s_Sig.s_HeadlightState.nGFA; i++)
    {
      Set_HLA_MatrixGFAState_v1( &pIn_Out->s_Sig.s_HeadlightState.GFA[i],
                                                pIn->s_Sig.s_HeadlightState.GFA[i].f32_PartHBCutoffAng_Lt,
                                                pIn->s_Sig.s_HeadlightState.GFA[i].f32_PartHBCutoffAng_Rt,
                                                pIn->s_Sig.s_HeadlightState.GFA[i].f32_HorCutOffAng,
                                                pIn->s_Sig.s_HeadlightState.GFA[i].f32_LightDistance,
                                                pIn->s_Sig.s_HeadlightState.GFA[i].e_HorCutOffAngState,
                                                pIn->s_Sig.s_HeadlightState.GFA[i].e_LightDistanceState,
                                                pIn->s_Sig.s_HeadlightState.GFA[i].e_LightStyle_Lt,
                                                pIn->s_Sig.s_HeadlightState.GFA[i].e_LightStyle_Rt
                                              );
    }

    Set_HLA_VehicleState(&pIn_Out->s_Sig.s_VehicleState,
                                        pIn->s_Sig.s_VehicleState.b_FogLampFront,
                                        pIn->s_Sig.s_VehicleState.b_FogLampRear,
                                        pIn->s_Sig.s_VehicleState.b_RainSensor,
                                        pIn->s_Sig.s_VehicleState.ui8_WiperState,
                                        pIn->s_Sig.s_VehicleState.e_WiperWasherFrontState,
                                        pIn->s_Sig.s_VehicleState.e_WiperStage,
                                        (HLA_t_VehLevel_v1)pIn->s_Sig.s_VehicleState.s_VehicleLevel
                                       );

    Set_HLA_CaliOnline(&pIn_Out->s_Sig.s_CaliOnline,
                                      pIn->s_Sig.s_CaliOnline.f32_OdoCali_m,
                                      pIn->s_Sig.s_CaliOnline.f32_Pitch,
                                      pIn->s_Sig.s_CaliOnline.f32_Roll,
                                      pIn->s_Sig.s_CaliOnline.f32_Yaw
                                     );

    pIn_Out->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat = pIn->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat;
    pIn_Out->s_Sig.s_DefectPixelList.ui8_DefectsListLength      = pIn->s_Sig.s_DefectPixelList.ui8_DefectsListLength;

    //for(i=0; i<RTE_HLAR_DEFECT_PIXEL_LIST_LENGTH; i++)
    //{
    //  Set_ICDefectPixel( pIn_Out->s_Sig.s_DefectPixelList.as_DefectList[i],
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
    //                                  );
    //}

    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned   = pIn->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned;
    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState = pIn->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState;

    /* HLAR_t_InputParameters */
    {
      Set_HLA_CameraParameter( &pIn_Out->s_Par.s_CameraParameter,
                                              pIn->s_Par.s_CameraParameter.e_bayerPattern,
                                              pIn->s_Par.s_CameraParameter.f32_cycleTime,
                                              pIn->s_Par.s_CameraParameter.s_FocalLength,
                                              pIn->s_Par.s_CameraParameter.s_ImageSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiX1,
                                              pIn->s_Par.s_CameraParameter.s_LensCenter,

                                              /* camera distortion parameter */
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K1,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K2,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K3,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K4,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K5,
                                              /* camera distortion parameter */  

                                              /* Image header parameter */
                                              pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel,
                                              1, /* 1 byte/pixel */
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x,
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0, /* not in use right now */
                                              0 /* not in use right now */
                                              /* Image header parameter */
                                            );
    }

    pIn_Out->s_Par.s_SensorSocket = pIn->s_Par.s_SensorSocket;

    Set_HLA_SensorAngles(&pIn_Out->s_Par.s_SensorAngles,
                                        pIn->s_Par.s_SensorAngles.f32_Pitch,
                                        pIn->s_Par.s_SensorAngles.f32_Roll,
                                        pIn->s_Par.s_SensorAngles.f32_Yaw,
                                        pIn->s_Par.s_SensorAngles.f32_Quality,
                                        pIn->s_Par.s_SensorAngles.e_caliState
                                       );

    /* CPAR_HLA_Parameter_t */
    pIn_Out->s_Par.s_HlaPar.HLAType = pIn->s_Par.s_HlaPar.HLAType;
    Set_HLA_ParameterAlgoCfg(&pIn_Out->s_Par.s_HlaPar.AlgoCfg,
                                            pIn->s_Par.s_HlaPar.AlgoCfg.TestMode,
                                            pIn->s_Par.s_HlaPar.AlgoCfg.CityDetection,
                                            pIn->s_Par.s_HlaPar.AlgoCfg.TunnelDetection,
                                            pIn->s_Par.s_HlaPar.AlgoCfg.BadPixelDetection,
                                            pIn->s_Par.s_HlaPar.AlgoCfg.FogDetection,
                                            pIn->s_Par.s_HlaPar.AlgoCfg.BlockageDetection
                                           );
    Set_HLA_ParameterHeadlight(&pIn_Out->s_Par.s_HlaPar.Headlight,
                                              pIn->s_Par.s_HlaPar.Headlight.HeadLightType,
                                              pIn->s_Par.s_HlaPar.Headlight.HeadLightMechanics,
                                              pIn->s_Par.s_HlaPar.Headlight.SpotLight,
                                              pIn->s_Par.s_HlaPar.Headlight.SpotLightWidth,
                                              pIn->s_Par.s_HlaPar.Headlight.FullHBDefaultPos_Left,
                                              pIn->s_Par.s_HlaPar.Headlight.FullHBDefaultPos_Right,
                                              pIn->s_Par.s_HlaPar.Headlight.HeadLampLatency,
                                              pIn->s_Par.s_HlaPar.Headlight.SpotLightTolerance
                                             );

    Set_HLA_ParameterVehicle(&pIn_Out->s_Par.s_HlaPar.Vehicle,
                                            pIn->s_Par.s_HlaPar.Vehicle.WindshieldType
                                           );
    Set_HLA_ParameterCountry(&pIn_Out->s_Par.s_HlaPar.Country,
                                            pIn->s_Par.s_HlaPar.Country.TrafficStyle,
                                            pIn->s_Par.s_HlaPar.Country.SensitivityMode,
                                            pIn->s_Par.s_HlaPar.Country.CountryWithMultipleReflectors
                                           );
    /* CPAR_HLAR_Parameter_t */
    Set_HLA_ParameterRoi(&pIn_Out->s_Par.s_HlarPar.Roi,
                                        pIn->s_Par.s_HlarPar.Roi.FOV_Horizontal,
                                        pIn->s_Par.s_HlarPar.Roi.FOV_FunctionRoiAboveHorizon,
                                        pIn->s_Par.s_HlarPar.Roi.FOV_MinBelowHorizon,
                                        pIn->s_Par.s_HlarPar.Roi.FOV_MinAboveHorizon,
                                        pIn->s_Par.s_HlarPar.Roi.PrecVehLight_minDistance,
                                        pIn->s_Par.s_HlarPar.Roi.PrecVehLight_minHeight,
                                        pIn->s_Par.s_HlarPar.Roi.StreetLamp_Distance,
                                        pIn->s_Par.s_HlarPar.Roi.StreetLamp_Height
                                       );
    Set_HLA_ParameterCity( &pIn_Out->s_Par.s_HlarPar.City,
                                          pIn->s_Par.s_HlarPar.City.SpeedThresholdLow,
                                          pIn->s_Par.s_HlarPar.City.SpeedThresholdHigh,
                                          pIn->s_Par.s_HlarPar.City.NumLeavingStreetlamp_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.NumLeavingStreetlamp_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.NumSceneStreetlamp_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.NumSceneStreetlamp_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.AmbientLevel_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.AmbientLevel_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.StreetLampMaxInterDist_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.StreetLampMaxInterDist_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.StreetLampMaxDist_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.StreetLampMaxDist_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.LeavingCityDelay_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.LeavingCityDelay_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.LeavingCityDelaySceneStreetlamp_LowInt,
                                          pIn->s_Par.s_HlarPar.City.LeavingCityDelaySceneStreetlamp_HighInt,
                                          pIn->s_Par.s_HlarPar.City.NumTunnelStreetlamp
                                        );
    Set_HLA_ParameterHighway(&pIn_Out->s_Par.s_HlarPar.Highway,
                                            pIn->s_Par.s_HlarPar.Highway.SpeedDetThreshold_Fast,
                                            pIn->s_Par.s_HlarPar.Highway.SpeedDetThreshold,
                                            pIn->s_Par.s_HlarPar.Highway.SpeedDetThresholdDistance,
                                            pIn->s_Par.s_HlarPar.Highway.EgoMotionDetThresholdHigh,
                                            pIn->s_Par.s_HlarPar.Highway.EgoMotionDetThresholdLow,
                                            pIn->s_Par.s_HlarPar.Highway.LateralPositionUsedTracks,
                                            pIn->s_Par.s_HlarPar.Highway.LateralPositionConfidenceThreshHigh,
                                            pIn->s_Par.s_HlarPar.Highway.LateralPositionConfidenceThreshLow,
                                            pIn->s_Par.s_HlarPar.Highway.OcclusionOncomingLeavingLightsThresh,
                                            pIn->s_Par.s_HlarPar.Highway.OcclusionConfidenceStep
                                           );

    Set_HLA_ParameterTunnel( &pIn_Out->s_Par.s_HlarPar.Tunnel,
                                            pIn->s_Par.s_HlarPar.Tunnel.EntryThreshHigh,
                                            pIn->s_Par.s_HlarPar.Tunnel.EntryThreshLow,
                                            pIn->s_Par.s_HlarPar.Tunnel.EntryDistanceMin,
                                            pIn->s_Par.s_HlarPar.Tunnel.EntryDistanceMax,
                                            pIn->s_Par.s_HlarPar.Tunnel.ExitThreshHigh,
                                            pIn->s_Par.s_HlarPar.Tunnel.ExitThreshLow,
                                            pIn->s_Par.s_HlarPar.Tunnel.ExitDistanceMin,
                                            pIn->s_Par.s_HlarPar.Tunnel.DetectionTypeDistance
                                           );

    Set_HLA_ParameterTrafficStyle( &pIn_Out->s_Par.s_HlarPar.TrafficStyle,
                                                  pIn->s_Par.s_HlarPar.TrafficStyle.NumOncLightsThres,
                                                  pIn->s_Par.s_HlarPar.TrafficStyle.NumOncLightsLock
                                                 );

    Set_HLA_ParameterAmbient(&pIn_Out->s_Par.s_HlarPar.Ambient,
                                            pIn->s_Par.s_HlarPar.Ambient.SpeedThreshold,
                                            pIn->s_Par.s_HlarPar.Ambient.AmbientLevel_LowSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.AmbientLevel_HighSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.Day2NightTimeThres_LowSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.Day2NightTimeThres_HighSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.Day2NightDistThres_LowSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.Day2NightDistThres_HighSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.Night2DayTimeThres_LowSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.Night2DayTimeThres_HighSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.Night2DayDistThres_LowSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.Night2DayDistThres_HighSpeed
                                           );
    Set_HLA_ParameterVehDet( &pIn_Out->s_Par.s_HlarPar.Vehicle,
                                            pIn->s_Par.s_HlarPar.Vehicle.OncSensitivity,
                                            pIn->s_Par.s_HlarPar.Vehicle.PrecSensitivity
                                           );
    Set_HLA_ParameterLightPair(&pIn_Out->s_Par.s_HlarPar.LightPair,
                                              pIn->s_Par.s_HlarPar.LightPair.TaillightWidth_Min,
                                              pIn->s_Par.s_HlarPar.LightPair.TaillightWidth_Max,
                                              pIn->s_Par.s_HlarPar.LightPair.HeadlightWidth_Min,
                                              pIn->s_Par.s_HlarPar.LightPair.HeadlightWidth_Max,
                                              pIn->s_Par.s_HlarPar.LightPair.TaillightHeight_Min,
                                              pIn->s_Par.s_HlarPar.LightPair.TaillightHeight_Max,
                                              pIn->s_Par.s_HlarPar.LightPair.HeadlightHeight_Min,
                                              pIn->s_Par.s_HlarPar.LightPair.HeadlightHeight_Max
                                             );
    Set_HLA_ParameterDistEst(&pIn_Out->s_Par.s_HlarPar.DistEst,
                                            pIn->s_Par.s_HlarPar.DistEst.LightHeight_Min,
                                            pIn->s_Par.s_HlarPar.DistEst.LightHeight_Max,
                                            pIn->s_Par.s_HlarPar.DistEst.DistFilterConst
                                           );
    Set_HLA_ParameterTTBEst( &pIn_Out->s_Par.s_HlarPar.TTBEst,
                                            pIn->s_Par.s_HlarPar.TTBEst.ttbAngle
                                           );

    /* Set Hla RGB Lux Table*/
    float32 f32_RatioRedGreen, f32_RatioBlueGreen, f32_RatioGreenRef;
    float32 f32_T1_us, f32_T2_us, f32_T3_us;
    uint32  ui32_R1, ui32_R2;

    Set_HLA_CameraParameter_PreCheck_v1( &f32_RatioRedGreen,
                                           &f32_RatioBlueGreen,
                                           &f32_RatioGreenRef,
                                           &f32_T1_us,
                                           &f32_T2_us,
                                           &f32_T3_us,
                                           &ui32_R1,
                                           &ui32_R2,
                                           &pIn->s_Par.s_CameraParameter.s_RGBLuxTable,
                                           pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve
                                          );

    SetRgbLuxTable(&pIn_Out->s_Par.s_CameraParameter.s_RGBLuxTable,
                   ui32_R1,
                   ui32_R2,
                   f32_T1_us,
                   f32_T2_us,
                   f32_T3_us,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.f32_Gain,
                   f32_RatioRedGreen,
                   f32_RatioBlueGreen,
                   f32_RatioGreenRef,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength,
                   &pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0]);


    if(  (fABS(pIn->s_Par.s_SensorAngles.f32_Pitch)                  > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Roll)                   > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Yaw)                    > 1.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_X)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Y)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Z)                      > 10.0f)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_y       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_x         > 1000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_y         > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     < 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     < 1000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_x            > 2000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_y            > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_x)      > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_y)      > 1000)
      || (pIn->s_Par.s_CameraParameter.ui32_BitsPerPixel             > 16)
      || (pIn->s_Par.s_CameraParameter.e_bayerPattern                > 10)
      || (fABS(pIn->s_Par.s_CameraParameter.f32_cycleTime)           > 1.0f)
      || (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength> 20)
      || (fABS(pIn->s_Par.s_HlarPar.Roi.PrecVehLight_minDistance)    > 100)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Pitch)                    > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Roll)                     > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Yaw)                      > 1.0f) 
      || (fABS(pIn->s_Sig.s_MotionState.f32_Speed)                   > 200.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRate)                 > 10.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRateRaw)              > 10.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue > 1000.0f)
      )
    {
      Error = SIM_ERR_INVALID_DATA_SIZE;  
    }
  }
  else
  {
    // Error = ...
  }

  return Error;
}

uint32 CHlarInputData::SetHlarInputData_v11(HLAR_t_RequiredInputs_v10* pIn, HLAR_t_RequiredInputs* pIn_Out)
{  
  uint32  i;
  uint32  Error = SIM_ERR_OK;


  if(pIn_Out && pIn)
  {
    


    pIn_Out->uiFrameCnt                   = pIn->ui32_FrameCnt;
    pIn_Out->ui32_InterfaceVersionNumber  = pIn->ui32_InterfaceVersionNumber;
    pIn_Out->uiTimeStamp_HLA_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_HLA_us;
    pIn_Out->uiTimeStamp_VDY_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_VDY_us;
    pIn_Out->uiTimeStamp_Image_us         = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_Image_us;
    pIn_Out->uiVDY_Cnt                    = pIn->ui32_VDY_Cnt;

    /* HLAR_t_InputSignals */
    Set_HLA_Availability(&pIn_Out->s_Sig.s_Avl,
                                        pIn->s_Sig.s_Avl.e_Type,
                                        pIn->s_Sig.s_Avl.e_State,
                                        pIn->s_Sig.s_Avl.e_USSens
                                       );
    Set_HLA_ImagerState( &pIn_Out->s_Sig.s_ImagerState,
                                        pIn->s_Sig.s_ImagerState.e_ActiveChar,
                                        pIn->s_Sig.s_ImagerState.f32_Brightness_Lux,
                                        pIn->s_Sig.s_ImagerState.ui32_ExposureTime_us,
                                        pIn->s_Sig.s_ImagerState.ui32_FrameNumber,
                                        pIn->s_Sig.s_ImagerState.f32_Noise,

                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R1,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R2, 
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T1_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T2_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T3_us,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_Gain,
                                        /* response curve */
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_B_Lux,
                                        (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_Greyvalue,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_R_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_G_Lux,
                                        pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_B_Lux
                                      );

    Set_HLA_MotionState( &pIn_Out->s_Sig.s_MotionState,
                                        pIn->s_Sig.s_MotionState.f32_SpeedDisplay,
                                        pIn->s_Sig.s_MotionState.f32_Speed,
                                        pIn->s_Sig.s_MotionState.f32_Acceleration,
                                        pIn->s_Sig.s_MotionState.f32_YawRateRaw,
                                        pIn->s_Sig.s_MotionState.f32_YawRate,
                                        pIn->s_Sig.s_MotionState.f32_YawRateQuality,
                                        pIn->s_Sig.s_MotionState.f32_YawRateVariance,
                                        pIn->s_Sig.s_MotionState.f32_SteeringWheelAngle,
                                        pIn->s_Sig.s_MotionState.f32_SteeringAngle,
                                        pIn->s_Sig.s_MotionState.e_MoveState,
                                        pIn->s_Sig.s_MotionState.f32_MoveStateConfidence
                                      );

    Set_HLA_HeadlightState_v2( &pIn_Out->s_Sig.s_HeadlightState,
                                              pIn->s_Sig.s_HeadlightState.e_LightModuleState,                                        
                                              pIn->s_Sig.s_HeadlightState.e_HighBeamState,
                                              pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Lt,
                                              pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Rt,
                                              pIn->s_Sig.s_HeadlightState.e_GlareReductionState,
                                              pIn->s_Sig.s_HeadlightState.f32_LightOutput,
                                              pIn->s_Sig.s_HeadlightState.nGFA
                                            );

    /*for(i=0; i<pIn->s_Sig.s_HeadlightState.nGFA; i++)*/
    // HACK AlexM
    for (i=0; i<3; i++)
    {
      Set_HLA_MatrixGFAState_v1( &pIn_Out->s_Sig.s_HeadlightState.GFA[i],
                                                pIn->s_Sig.s_HeadlightState.GFA[i].f32_PartHBCutoffAng_Lt,
                                                pIn->s_Sig.s_HeadlightState.GFA[i].f32_PartHBCutoffAng_Rt,
                                                pIn->s_Sig.s_HeadlightState.GFA[i].f32_HorCutOffAng,
                                                pIn->s_Sig.s_HeadlightState.GFA[i].f32_LightDistance,
                                                pIn->s_Sig.s_HeadlightState.GFA[i].e_HorCutOffAngState,
                                                pIn->s_Sig.s_HeadlightState.GFA[i].e_LightDistanceState,
                                                pIn->s_Sig.s_HeadlightState.GFA[i].e_LightStyle_Lt,
                                                pIn->s_Sig.s_HeadlightState.GFA[i].e_LightStyle_Rt
                                              );
    }

    Set_HLA_VehicleState(&pIn_Out->s_Sig.s_VehicleState,
                                        pIn->s_Sig.s_VehicleState.b_FogLampFront,
                                        pIn->s_Sig.s_VehicleState.b_FogLampRear,
                                        pIn->s_Sig.s_VehicleState.b_RainSensor,
                                        pIn->s_Sig.s_VehicleState.ui8_WiperState,
                                        pIn->s_Sig.s_VehicleState.e_WiperWasherFrontState,
                                        pIn->s_Sig.s_VehicleState.e_WiperStage,
                                        (HLA_t_VehLevel_v1)pIn->s_Sig.s_VehicleState.s_VehicleLevel
                                       );

    Set_HLA_CaliOnline(&pIn_Out->s_Sig.s_CaliOnline,
                                      pIn->s_Sig.s_CaliOnline.f32_OdoCali_m,
                                      pIn->s_Sig.s_CaliOnline.f32_Pitch,
                                      pIn->s_Sig.s_CaliOnline.f32_Roll,
                                      pIn->s_Sig.s_CaliOnline.f32_Yaw
                                     );

    pIn_Out->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat = pIn->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat;
    pIn_Out->s_Sig.s_DefectPixelList.ui8_DefectsListLength      = pIn->s_Sig.s_DefectPixelList.ui8_DefectsListLength;

    //for(i=0; i<RTE_HLAR_DEFECT_PIXEL_LIST_LENGTH; i++)
    //{
    //  Set_ICDefectPixel( pIn_Out->s_Sig.s_DefectPixelList.as_DefectList[i],
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType,
    //                                    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
    //                                  );
    //}

    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned   = pIn->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned;
    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState = pIn->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState;

    /* HLAR_t_InputParameters */
    {
      Set_HLA_CameraParameter( &pIn_Out->s_Par.s_CameraParameter,
                                              pIn->s_Par.s_CameraParameter.e_bayerPattern,
                                              pIn->s_Par.s_CameraParameter.f32_cycleTime,
                                              pIn->s_Par.s_CameraParameter.s_FocalLength,
                                              pIn->s_Par.s_CameraParameter.s_ImageSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize,
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiX1,
                                              pIn->s_Par.s_CameraParameter.s_LensCenter,

                                              /* camera distortion parameter */
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K1,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K2,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K3,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K4,
                                              pIn->s_Par.s_CameraParameter.s_Distortion.f32_K5,
                                              /* camera distortion parameter */  

                                              /* Image header parameter */
                                              pIn->s_Par.s_CameraParameter.s_ImageHeader.uiBitsPerChannel,
                                              1,                                                             /* see below */
                                              pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x,          /* for simu/eval board there are no dummy pixels at the end of each row */
                                              pIn->s_Par.s_CameraParameter.s_ImageHeader.iSizeBytes,
                                              pIn->s_Par.s_CameraParameter.s_ImageHeader.uiWidth,
                                              pIn->s_Par.s_CameraParameter.s_ImageHeader.uiHeight,
                                              pIn->s_Par.s_CameraParameter.s_ImageHeader.iScaleX,
                                              pIn->s_Par.s_CameraParameter.s_ImageHeader.iScaleY,
                                              pIn->s_Par.s_CameraParameter.s_ImageHeader.iOffsetX,
                                              pIn->s_Par.s_CameraParameter.s_ImageHeader.iOffsetY,
                                              pIn->s_Par.s_CameraParameter.s_ImageHeader.eDataFormat,
                                              pIn->s_Par.s_CameraParameter.s_ImageHeader.uiParameterId
                                              /* Image header parameter */                                              
                                              );
    }

    pIn_Out->s_Par.s_SensorSocket = pIn->s_Par.s_SensorSocket;

    Set_HLA_SensorAngles(&pIn_Out->s_Par.s_SensorAngles,
                                        pIn->s_Par.s_SensorAngles.f32_Pitch,
                                        pIn->s_Par.s_SensorAngles.f32_Roll,
                                        pIn->s_Par.s_SensorAngles.f32_Yaw,
                                        pIn->s_Par.s_SensorAngles.f32_Quality,
                                        pIn->s_Par.s_SensorAngles.e_caliState
                                       );

    /* CPAR_HLA_Parameter_t */
    pIn_Out->s_Par.s_HlaPar.HLAType = pIn->s_Par.s_HlaPar.HLAType;
    Set_HLA_ParameterAlgoCfg(&pIn_Out->s_Par.s_HlaPar.AlgoCfg,
                                            pIn->s_Par.s_HlaPar.AlgoCfg.TestMode,
                                            pIn->s_Par.s_HlaPar.AlgoCfg.CityDetection,
                                            pIn->s_Par.s_HlaPar.AlgoCfg.TunnelDetection,
                                            pIn->s_Par.s_HlaPar.AlgoCfg.BadPixelDetection,
                                            pIn->s_Par.s_HlaPar.AlgoCfg.FogDetection,
                                            pIn->s_Par.s_HlaPar.AlgoCfg.BlockageDetection
                                           );
    Set_HLA_ParameterHeadlight(&pIn_Out->s_Par.s_HlaPar.Headlight,
                                              pIn->s_Par.s_HlaPar.Headlight.HeadLightType,
                                              pIn->s_Par.s_HlaPar.Headlight.HeadLightMechanics,
                                              pIn->s_Par.s_HlaPar.Headlight.SpotLight,
                                              pIn->s_Par.s_HlaPar.Headlight.SpotLightWidth,
                                              pIn->s_Par.s_HlaPar.Headlight.FullHBDefaultPos_Left,
                                              pIn->s_Par.s_HlaPar.Headlight.FullHBDefaultPos_Right,
                                              pIn->s_Par.s_HlaPar.Headlight.HeadLampLatency,
                                              pIn->s_Par.s_HlaPar.Headlight.SpotLightTolerance
                                             );

    Set_HLA_ParameterVehicle(&pIn_Out->s_Par.s_HlaPar.Vehicle,
                                            pIn->s_Par.s_HlaPar.Vehicle.WindshieldType
                                           );
    Set_HLA_ParameterCountry(&pIn_Out->s_Par.s_HlaPar.Country,
                                            pIn->s_Par.s_HlaPar.Country.TrafficStyle,
                                            pIn->s_Par.s_HlaPar.Country.SensitivityMode,
                                            pIn->s_Par.s_HlaPar.Country.CountryWithMultipleReflectors
                                           );
    /* CPAR_HLAR_Parameter_t */
    Set_HLA_ParameterRoi(&pIn_Out->s_Par.s_HlarPar.Roi,
                                        pIn->s_Par.s_HlarPar.Roi.FOV_Horizontal,
                                        pIn->s_Par.s_HlarPar.Roi.FOV_FunctionRoiAboveHorizon,
                                        pIn->s_Par.s_HlarPar.Roi.FOV_MinBelowHorizon,
                                        pIn->s_Par.s_HlarPar.Roi.FOV_MinAboveHorizon,
                                        pIn->s_Par.s_HlarPar.Roi.PrecVehLight_minDistance,
                                        pIn->s_Par.s_HlarPar.Roi.PrecVehLight_minHeight,
                                        pIn->s_Par.s_HlarPar.Roi.StreetLamp_Distance,
                                        pIn->s_Par.s_HlarPar.Roi.StreetLamp_Height
                                       );
    Set_HLA_ParameterCity( &pIn_Out->s_Par.s_HlarPar.City,
                                          pIn->s_Par.s_HlarPar.City.SpeedThresholdLow,
                                          pIn->s_Par.s_HlarPar.City.SpeedThresholdHigh,
                                          pIn->s_Par.s_HlarPar.City.NumLeavingStreetlamp_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.NumLeavingStreetlamp_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.NumSceneStreetlamp_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.NumSceneStreetlamp_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.AmbientLevel_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.AmbientLevel_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.StreetLampMaxInterDist_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.StreetLampMaxInterDist_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.StreetLampMaxDist_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.StreetLampMaxDist_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.LeavingCityDelay_LowSpeed,
                                          pIn->s_Par.s_HlarPar.City.LeavingCityDelay_HighSpeed,
                                          pIn->s_Par.s_HlarPar.City.LeavingCityDelaySceneStreetlamp_LowInt,
                                          pIn->s_Par.s_HlarPar.City.LeavingCityDelaySceneStreetlamp_HighInt,
                                          pIn->s_Par.s_HlarPar.City.NumTunnelStreetlamp
                                        );
    Set_HLA_ParameterHighway(&pIn_Out->s_Par.s_HlarPar.Highway,
                                            pIn->s_Par.s_HlarPar.Highway.SpeedDetThreshold_Fast,
                                            pIn->s_Par.s_HlarPar.Highway.SpeedDetThreshold,
                                            pIn->s_Par.s_HlarPar.Highway.SpeedDetThresholdDistance,
                                            pIn->s_Par.s_HlarPar.Highway.EgoMotionDetThresholdHigh,
                                            pIn->s_Par.s_HlarPar.Highway.EgoMotionDetThresholdLow,
                                            pIn->s_Par.s_HlarPar.Highway.LateralPositionUsedTracks,
                                            pIn->s_Par.s_HlarPar.Highway.LateralPositionConfidenceThreshHigh,
                                            pIn->s_Par.s_HlarPar.Highway.LateralPositionConfidenceThreshLow,
                                            pIn->s_Par.s_HlarPar.Highway.OcclusionOncomingLeavingLightsThresh,
                                            pIn->s_Par.s_HlarPar.Highway.OcclusionConfidenceStep
                                           );

    Set_HLA_ParameterTunnel( &pIn_Out->s_Par.s_HlarPar.Tunnel,
                                            pIn->s_Par.s_HlarPar.Tunnel.EntryThreshHigh,
                                            pIn->s_Par.s_HlarPar.Tunnel.EntryThreshLow,
                                            pIn->s_Par.s_HlarPar.Tunnel.EntryDistanceMin,
                                            pIn->s_Par.s_HlarPar.Tunnel.EntryDistanceMax,
                                            pIn->s_Par.s_HlarPar.Tunnel.ExitThreshHigh,
                                            pIn->s_Par.s_HlarPar.Tunnel.ExitThreshLow,
                                            pIn->s_Par.s_HlarPar.Tunnel.ExitDistanceMin,
                                            pIn->s_Par.s_HlarPar.Tunnel.DetectionTypeDistance
                                           );

    Set_HLA_ParameterTrafficStyle( &pIn_Out->s_Par.s_HlarPar.TrafficStyle,
                                                  pIn->s_Par.s_HlarPar.TrafficStyle.NumOncLightsThres,
                                                  pIn->s_Par.s_HlarPar.TrafficStyle.NumOncLightsLock
                                                 );

    Set_HLA_ParameterAmbient(&pIn_Out->s_Par.s_HlarPar.Ambient,
                                            pIn->s_Par.s_HlarPar.Ambient.SpeedThreshold,
                                            pIn->s_Par.s_HlarPar.Ambient.AmbientLevel_LowSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.AmbientLevel_HighSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.Day2NightTimeThres_LowSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.Day2NightTimeThres_HighSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.Day2NightDistThres_LowSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.Day2NightDistThres_HighSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.Night2DayTimeThres_LowSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.Night2DayTimeThres_HighSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.Night2DayDistThres_LowSpeed,
                                            pIn->s_Par.s_HlarPar.Ambient.Night2DayDistThres_HighSpeed
                                           );
    Set_HLA_ParameterVehDet( &pIn_Out->s_Par.s_HlarPar.Vehicle,
                                            pIn->s_Par.s_HlarPar.Vehicle.OncSensitivity,
                                            pIn->s_Par.s_HlarPar.Vehicle.PrecSensitivity
                                           );
    Set_HLA_ParameterLightPair(&pIn_Out->s_Par.s_HlarPar.LightPair,
                                              pIn->s_Par.s_HlarPar.LightPair.TaillightWidth_Min,
                                              pIn->s_Par.s_HlarPar.LightPair.TaillightWidth_Max,
                                              pIn->s_Par.s_HlarPar.LightPair.HeadlightWidth_Min,
                                              pIn->s_Par.s_HlarPar.LightPair.HeadlightWidth_Max,
                                              pIn->s_Par.s_HlarPar.LightPair.TaillightHeight_Min,
                                              pIn->s_Par.s_HlarPar.LightPair.TaillightHeight_Max,
                                              pIn->s_Par.s_HlarPar.LightPair.HeadlightHeight_Min,
                                              pIn->s_Par.s_HlarPar.LightPair.HeadlightHeight_Max
                                             );
    Set_HLA_ParameterDistEst(&pIn_Out->s_Par.s_HlarPar.DistEst,
                                            pIn->s_Par.s_HlarPar.DistEst.LightHeight_Min,
                                            pIn->s_Par.s_HlarPar.DistEst.LightHeight_Max,
                                            pIn->s_Par.s_HlarPar.DistEst.DistFilterConst
                                           );
    Set_HLA_ParameterTTBEst( &pIn_Out->s_Par.s_HlarPar.TTBEst,
                                            pIn->s_Par.s_HlarPar.TTBEst.ttbAngle
                                           );

    /* Set Hla RGB Lux Table*/
    float32 f32_RatioRedGreen, f32_RatioBlueGreen, f32_RatioGreenRef;
    float32 f32_T1_us, f32_T2_us, f32_T3_us;
    uint32  ui32_R1, ui32_R2;

    Set_HLA_CameraParameter_PreCheck_v1( &f32_RatioRedGreen,
                                           &f32_RatioBlueGreen,
                                           &f32_RatioGreenRef,
                                           &f32_T1_us,
                                           &f32_T2_us,
                                           &f32_T3_us,
                                           &ui32_R1,
                                           &ui32_R2,
                                           &pIn->s_Par.s_CameraParameter.s_RGBLuxTable,
                                           pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve
                                          );

    SetRgbLuxTable(&pIn_Out->s_Par.s_CameraParameter.s_RGBLuxTable,
                   ui32_R1,
                   ui32_R2,
                   f32_T1_us,
                   f32_T2_us,
                   f32_T3_us,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.f32_Gain,
                   f32_RatioRedGreen,
                   f32_RatioBlueGreen,
                   f32_RatioGreenRef,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength,
                   &pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0]);

    if(  (fABS(pIn->s_Par.s_SensorAngles.f32_Pitch)                  > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Roll)                   > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Yaw)                    > 1.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_X)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Y)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Z)                      > 10.0f)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_y       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_x         > 1000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_y         > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     < 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     < 1000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_x            > 2000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_y            > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_x)      > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_y)      > 1000)
      || (pIn->s_Par.s_CameraParameter.s_ImageHeader.uiBitsPerChannel> 16)
      || (pIn->s_Par.s_CameraParameter.e_bayerPattern                > 10)
      || (fABS(pIn->s_Par.s_CameraParameter.f32_cycleTime)           > 1.0f)
      || (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength> 20)
      || (fABS(pIn->s_Par.s_HlarPar.Roi.PrecVehLight_minDistance)    > 100)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Pitch)                    > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Roll)                     > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Yaw)                      > 1.0f) 
      || (fABS(pIn->s_Sig.s_MotionState.f32_Speed)                   > 200.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRate)                 > 10.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRateRaw)              > 10.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue > 1000.0f)
      )
    {
      Error = SIM_ERR_INVALID_DATA_SIZE;  
    }
  }
  else
  {
    // Error = ...
  }

  return Error;
}

uint32 CHlarInputData::SetHlarInputData_v12(HLAR_t_RequiredInputs_v11* pIn, HLAR_t_RequiredInputs* pIn_Out)
{  
  uint32  i;
  uint32  Error = SIM_ERR_OK;


  if(pIn_Out && pIn)
  {
    


    pIn_Out->uiFrameCnt                   = pIn->ui32_FrameCnt;
    pIn_Out->ui32_InterfaceVersionNumber  = pIn->ui32_InterfaceVersionNumber;
    pIn_Out->uiTimeStamp_HLA_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_HLA_us;
    pIn_Out->uiTimeStamp_VDY_us           = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_VDY_us;
    pIn_Out->uiTimeStamp_Image_us         = (AlgoDataTimeStamp_t)pIn->ui64_TimeStamp_Image_us;
    pIn_Out->uiVDY_Cnt                    = pIn->ui32_VDY_Cnt;

    /* HLAR_t_InputSignals */
    Set_HLA_Availability(&pIn_Out->s_Sig.s_Avl,
      pIn->s_Sig.s_Avl.e_Type,
      pIn->s_Sig.s_Avl.e_State,
      pIn->s_Sig.s_Avl.e_USSens
      );
    Set_HLA_ImagerState( &pIn_Out->s_Sig.s_ImagerState,
      pIn->s_Sig.s_ImagerState.e_ActiveChar,
      pIn->s_Sig.s_ImagerState.f32_Brightness_Lux,
      pIn->s_Sig.s_ImagerState.ui32_ExposureTime_us,
      pIn->s_Sig.s_ImagerState.ui32_FrameNumber,
      pIn->s_Sig.s_ImagerState.f32_Noise,

      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R1,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R2, 
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T1_us,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T2_us,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T3_us,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_Gain,
      /* response curve */
      (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue,
      (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue,
      (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue,
      (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_Greyvalue,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_R_Lux,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_B_Lux,
      (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_Greyvalue,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_R_Lux,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_G_Lux,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_B_Lux,
      (uint16)pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_Greyvalue,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_R_Lux,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_G_Lux,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_B_Lux
      );

    Set_HLA_MotionState( &pIn_Out->s_Sig.s_MotionState,
      pIn->s_Sig.s_MotionState.f32_SpeedDisplay,
      pIn->s_Sig.s_MotionState.f32_Speed,
      pIn->s_Sig.s_MotionState.f32_Acceleration,
      pIn->s_Sig.s_MotionState.f32_YawRateRaw,
      pIn->s_Sig.s_MotionState.f32_YawRate,
      pIn->s_Sig.s_MotionState.f32_YawRateQuality,
      pIn->s_Sig.s_MotionState.f32_YawRateVariance,
      pIn->s_Sig.s_MotionState.f32_SteeringWheelAngle,
      pIn->s_Sig.s_MotionState.f32_SteeringAngle,
      pIn->s_Sig.s_MotionState.e_MoveState,
      pIn->s_Sig.s_MotionState.f32_MoveStateConfidence
      );

    Set_HLA_HeadlightState_v2( &pIn_Out->s_Sig.s_HeadlightState,
      pIn->s_Sig.s_HeadlightState.e_LightModuleState,                                        
      pIn->s_Sig.s_HeadlightState.e_HighBeamState,
      pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Lt,
      pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Rt,
      pIn->s_Sig.s_HeadlightState.e_GlareReductionState,
      pIn->s_Sig.s_HeadlightState.f32_LightOutput,
      pIn->s_Sig.s_HeadlightState.nGFA
      );

    /*for(i=0; i<pIn->s_Sig.s_HeadlightState.nGFA; i++)*/
    // HACK AlexM
    for (i=0; i<3; i++)
    {
      Set_HLA_MatrixGFAState_v1( &pIn_Out->s_Sig.s_HeadlightState.GFA[i],
        pIn->s_Sig.s_HeadlightState.GFA[i].f32_PartHBCutoffAng_Lt,
        pIn->s_Sig.s_HeadlightState.GFA[i].f32_PartHBCutoffAng_Rt,
        pIn->s_Sig.s_HeadlightState.GFA[i].f32_HorCutOffAng,
        pIn->s_Sig.s_HeadlightState.GFA[i].f32_LightDistance,
        pIn->s_Sig.s_HeadlightState.GFA[i].e_HorCutOffAngState,
        pIn->s_Sig.s_HeadlightState.GFA[i].e_LightDistanceState,
        pIn->s_Sig.s_HeadlightState.GFA[i].e_LightStyle_Lt,
        pIn->s_Sig.s_HeadlightState.GFA[i].e_LightStyle_Rt
        );
    }

    Set_HLA_VehicleState(&pIn_Out->s_Sig.s_VehicleState,
      pIn->s_Sig.s_VehicleState.b_FogLampFront,
      pIn->s_Sig.s_VehicleState.b_FogLampRear,
      pIn->s_Sig.s_VehicleState.b_RainSensor,
      pIn->s_Sig.s_VehicleState.ui8_WiperState,
      pIn->s_Sig.s_VehicleState.e_WiperWasherFrontState,
      pIn->s_Sig.s_VehicleState.e_WiperStage,
      (HLA_t_VehLevel_v1)pIn->s_Sig.s_VehicleState.s_VehicleLevel
      );

    Set_HLA_CaliOnline(&pIn_Out->s_Sig.s_CaliOnline,
      pIn->s_Sig.s_CaliOnline.f32_OdoCali_m,
      pIn->s_Sig.s_CaliOnline.f32_Pitch,
      pIn->s_Sig.s_CaliOnline.f32_Roll,
      pIn->s_Sig.s_CaliOnline.f32_Yaw
      );

    pIn_Out->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat = pIn->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat;
    pIn_Out->s_Sig.s_DefectPixelList.ui8_DefectsListLength      = pIn->s_Sig.s_DefectPixelList.ui8_DefectsListLength;

    //for(i=0; i<RTE_HLAR_DEFECT_PIXEL_LIST_LENGTH; i++)
    //{
    //  Set_ICDefectPixel( pIn_Out->s_Sig.s_DefectPixelList.as_DefectList[i],
    //    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
    //    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
    //    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType,
    //    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
    //    );
    //}

    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned   = pIn->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned;
    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState = pIn->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState;

    /* HLAR_t_InputParameters */
    {
      Set_HLA_CameraParameter( &pIn_Out->s_Par.s_CameraParameter,
                                pIn->s_Par.s_CameraParameter.e_bayerPattern,
                                pIn->s_Par.s_CameraParameter.f32_cycleTime,
                                pIn->s_Par.s_CameraParameter.s_FocalLength,
                                pIn->s_Par.s_CameraParameter.s_ImageSize,
                                pIn->s_Par.s_CameraParameter.s_CroppedRoiSize,
                                pIn->s_Par.s_CameraParameter.s_CroppedRoiX1,
                                pIn->s_Par.s_CameraParameter.s_LensCenter,

                                /* camera distortion parameter */
                                pIn->s_Par.s_CameraParameter.s_Distortion.f32_K1,
                                pIn->s_Par.s_CameraParameter.s_Distortion.f32_K2,
                                pIn->s_Par.s_CameraParameter.s_Distortion.f32_K3,
                                pIn->s_Par.s_CameraParameter.s_Distortion.f32_K4,
                                pIn->s_Par.s_CameraParameter.s_Distortion.f32_K5,
                                /* camera distortion parameter */  

                                /* Image header parameter */
                                pIn->s_Par.s_CameraParameter.s_ImageHeader.uiBitsPerChannel,
                                1,                                                             /* see below */
                                pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x,          /* for simu/eval board there are no dummy pixels at the end of each row */
                                pIn->s_Par.s_CameraParameter.s_ImageHeader.iSizeBytes,
                                pIn->s_Par.s_CameraParameter.s_ImageHeader.uiWidth,
                                pIn->s_Par.s_CameraParameter.s_ImageHeader.uiHeight,
                                pIn->s_Par.s_CameraParameter.s_ImageHeader.iScaleX,
                                pIn->s_Par.s_CameraParameter.s_ImageHeader.iScaleY,
                                pIn->s_Par.s_CameraParameter.s_ImageHeader.iOffsetX,
                                pIn->s_Par.s_CameraParameter.s_ImageHeader.iOffsetY,
                                pIn->s_Par.s_CameraParameter.s_ImageHeader.eDataFormat,
                                pIn->s_Par.s_CameraParameter.s_ImageHeader.uiParameterId
                                /* Image header parameter */                                              
                                );
    }

    pIn_Out->s_Par.s_SensorSocket = pIn->s_Par.s_SensorSocket;

    Set_HLA_SensorAngles(&pIn_Out->s_Par.s_SensorAngles,
      pIn->s_Par.s_SensorAngles.f32_Pitch,
      pIn->s_Par.s_SensorAngles.f32_Roll,
      pIn->s_Par.s_SensorAngles.f32_Yaw,
      pIn->s_Par.s_SensorAngles.f32_Quality,
      pIn->s_Par.s_SensorAngles.e_caliState
      );

    /* CPAR_HLA_Parameter_t */
    pIn_Out->s_Par.s_HlaPar.HLAType = pIn->s_Par.s_HlaPar.HLAType;
    Set_HLA_ParameterAlgoCfg(&pIn_Out->s_Par.s_HlaPar.AlgoCfg,
      pIn->s_Par.s_HlaPar.AlgoCfg.TestMode,
      pIn->s_Par.s_HlaPar.AlgoCfg.CityDetection,
      pIn->s_Par.s_HlaPar.AlgoCfg.TunnelDetection,
      pIn->s_Par.s_HlaPar.AlgoCfg.BadPixelDetection,
      pIn->s_Par.s_HlaPar.AlgoCfg.FogDetection,
      pIn->s_Par.s_HlaPar.AlgoCfg.BlockageDetection
      );
    Set_HLA_ParameterHeadlight(&pIn_Out->s_Par.s_HlaPar.Headlight,
      pIn->s_Par.s_HlaPar.Headlight.HeadLightType,
      pIn->s_Par.s_HlaPar.Headlight.HeadLightMechanics,
      pIn->s_Par.s_HlaPar.Headlight.SpotLight,
      pIn->s_Par.s_HlaPar.Headlight.SpotLightWidth,
      pIn->s_Par.s_HlaPar.Headlight.FullHBDefaultPos_Left,
      pIn->s_Par.s_HlaPar.Headlight.FullHBDefaultPos_Right,
      pIn->s_Par.s_HlaPar.Headlight.HeadLampLatency,
      pIn->s_Par.s_HlaPar.Headlight.SpotLightTolerance
      );

    Set_HLA_ParameterVehicle(&pIn_Out->s_Par.s_HlaPar.Vehicle,
      pIn->s_Par.s_HlaPar.Vehicle.WindshieldType
      );
    Set_HLA_ParameterCountry(&pIn_Out->s_Par.s_HlaPar.Country,
      pIn->s_Par.s_HlaPar.Country.TrafficStyle,
      pIn->s_Par.s_HlaPar.Country.SensitivityMode,
      pIn->s_Par.s_HlaPar.Country.CountryWithMultipleReflectors
      );
    /* CPAR_HLAR_Parameter_t */
    Set_HLA_ParameterRoi(&pIn_Out->s_Par.s_HlarPar.Roi,
      pIn->s_Par.s_HlarPar.Roi.FOV_Horizontal,
      pIn->s_Par.s_HlarPar.Roi.FOV_FunctionRoiAboveHorizon,
      pIn->s_Par.s_HlarPar.Roi.FOV_MinBelowHorizon,
      pIn->s_Par.s_HlarPar.Roi.FOV_MinAboveHorizon,
      pIn->s_Par.s_HlarPar.Roi.PrecVehLight_minDistance,
      pIn->s_Par.s_HlarPar.Roi.PrecVehLight_minHeight,
      pIn->s_Par.s_HlarPar.Roi.StreetLamp_Distance,
      pIn->s_Par.s_HlarPar.Roi.StreetLamp_Height
      );
    Set_HLA_ParameterCity( &pIn_Out->s_Par.s_HlarPar.City,
      pIn->s_Par.s_HlarPar.City.SpeedThresholdLow,
      pIn->s_Par.s_HlarPar.City.SpeedThresholdHigh,
      pIn->s_Par.s_HlarPar.City.NumLeavingStreetlamp_LowSpeed,
      pIn->s_Par.s_HlarPar.City.NumLeavingStreetlamp_HighSpeed,
      pIn->s_Par.s_HlarPar.City.NumSceneStreetlamp_LowSpeed,
      pIn->s_Par.s_HlarPar.City.NumSceneStreetlamp_HighSpeed,
      pIn->s_Par.s_HlarPar.City.AmbientLevel_LowSpeed,
      pIn->s_Par.s_HlarPar.City.AmbientLevel_HighSpeed,
      pIn->s_Par.s_HlarPar.City.StreetLampMaxInterDist_LowSpeed,
      pIn->s_Par.s_HlarPar.City.StreetLampMaxInterDist_HighSpeed,
      pIn->s_Par.s_HlarPar.City.StreetLampMaxDist_LowSpeed,
      pIn->s_Par.s_HlarPar.City.StreetLampMaxDist_HighSpeed,
      pIn->s_Par.s_HlarPar.City.LeavingCityDelay_LowSpeed,
      pIn->s_Par.s_HlarPar.City.LeavingCityDelay_HighSpeed,
      pIn->s_Par.s_HlarPar.City.LeavingCityDelaySceneStreetlamp_LowInt,
      pIn->s_Par.s_HlarPar.City.LeavingCityDelaySceneStreetlamp_HighInt,
      pIn->s_Par.s_HlarPar.City.NumTunnelStreetlamp
      );
    Set_HLA_ParameterHighway(&pIn_Out->s_Par.s_HlarPar.Highway,
      pIn->s_Par.s_HlarPar.Highway.SpeedDetThreshold_Fast,
      pIn->s_Par.s_HlarPar.Highway.SpeedDetThreshold,
      pIn->s_Par.s_HlarPar.Highway.SpeedDetThresholdDistance,
      pIn->s_Par.s_HlarPar.Highway.EgoMotionDetThresholdHigh,
      pIn->s_Par.s_HlarPar.Highway.EgoMotionDetThresholdLow,
      pIn->s_Par.s_HlarPar.Highway.LateralPositionUsedTracks,
      pIn->s_Par.s_HlarPar.Highway.LateralPositionConfidenceThreshHigh,
      pIn->s_Par.s_HlarPar.Highway.LateralPositionConfidenceThreshLow,
      pIn->s_Par.s_HlarPar.Highway.OcclusionOncomingLeavingLightsThresh,
      pIn->s_Par.s_HlarPar.Highway.OcclusionConfidenceStep
      );

    Set_HLA_ParameterTunnel( &pIn_Out->s_Par.s_HlarPar.Tunnel,
      pIn->s_Par.s_HlarPar.Tunnel.EntryThreshHigh,
      pIn->s_Par.s_HlarPar.Tunnel.EntryThreshLow,
      pIn->s_Par.s_HlarPar.Tunnel.EntryDistanceMin,
      pIn->s_Par.s_HlarPar.Tunnel.EntryDistanceMax,
      pIn->s_Par.s_HlarPar.Tunnel.ExitThreshHigh,
      pIn->s_Par.s_HlarPar.Tunnel.ExitThreshLow,
      pIn->s_Par.s_HlarPar.Tunnel.ExitDistanceMin,
      pIn->s_Par.s_HlarPar.Tunnel.DetectionTypeDistance
      );

    Set_HLA_ParameterTrafficStyle( &pIn_Out->s_Par.s_HlarPar.TrafficStyle,
      pIn->s_Par.s_HlarPar.TrafficStyle.NumOncLightsThres,
      pIn->s_Par.s_HlarPar.TrafficStyle.NumOncLightsLock
      );

    Set_HLA_ParameterAmbient(&pIn_Out->s_Par.s_HlarPar.Ambient,
      pIn->s_Par.s_HlarPar.Ambient.SpeedThreshold,
      pIn->s_Par.s_HlarPar.Ambient.AmbientLevel_LowSpeed,
      pIn->s_Par.s_HlarPar.Ambient.AmbientLevel_HighSpeed,
      pIn->s_Par.s_HlarPar.Ambient.Day2NightTimeThres_LowSpeed,
      pIn->s_Par.s_HlarPar.Ambient.Day2NightTimeThres_HighSpeed,
      pIn->s_Par.s_HlarPar.Ambient.Day2NightDistThres_LowSpeed,
      pIn->s_Par.s_HlarPar.Ambient.Day2NightDistThres_HighSpeed,
      pIn->s_Par.s_HlarPar.Ambient.Night2DayTimeThres_LowSpeed,
      pIn->s_Par.s_HlarPar.Ambient.Night2DayTimeThres_HighSpeed,
      pIn->s_Par.s_HlarPar.Ambient.Night2DayDistThres_LowSpeed,
      pIn->s_Par.s_HlarPar.Ambient.Night2DayDistThres_HighSpeed
      );
    Set_HLA_ParameterVehDet( &pIn_Out->s_Par.s_HlarPar.Vehicle,
      pIn->s_Par.s_HlarPar.Vehicle.OncSensitivity,
      pIn->s_Par.s_HlarPar.Vehicle.PrecSensitivity
      );
    Set_HLA_ParameterLightPair(&pIn_Out->s_Par.s_HlarPar.LightPair,
      pIn->s_Par.s_HlarPar.LightPair.TaillightWidth_Min,
      pIn->s_Par.s_HlarPar.LightPair.TaillightWidth_Max,
      pIn->s_Par.s_HlarPar.LightPair.HeadlightWidth_Min,
      pIn->s_Par.s_HlarPar.LightPair.HeadlightWidth_Max,
      pIn->s_Par.s_HlarPar.LightPair.TaillightHeight_Min,
      pIn->s_Par.s_HlarPar.LightPair.TaillightHeight_Max,
      pIn->s_Par.s_HlarPar.LightPair.HeadlightHeight_Min,
      pIn->s_Par.s_HlarPar.LightPair.HeadlightHeight_Max
      );
    Set_HLA_ParameterDistEst(&pIn_Out->s_Par.s_HlarPar.DistEst,
      pIn->s_Par.s_HlarPar.DistEst.LightHeight_Min,
      pIn->s_Par.s_HlarPar.DistEst.LightHeight_Max,
      pIn->s_Par.s_HlarPar.DistEst.DistFilterConst
      );
    Set_HLA_ParameterTTBEst( &pIn_Out->s_Par.s_HlarPar.TTBEst,
      pIn->s_Par.s_HlarPar.TTBEst.ttbAngle
      );

    /* Set Hla RGB Lux Table*/
    float32 f32_RatioRedGreen, f32_RatioBlueGreen, f32_RatioGreenRef;
    float32 f32_T1_us, f32_T2_us, f32_T3_us;
    uint32  ui32_R1, ui32_R2;

    Set_HLA_CameraParameter_PreCheck_v1( &f32_RatioRedGreen,
                                           &f32_RatioBlueGreen,
                                           &f32_RatioGreenRef,
                                           &f32_T1_us,
                                           &f32_T2_us,
                                           &f32_T3_us,
                                           &ui32_R1,
                                           &ui32_R2,
                                           &pIn->s_Par.s_CameraParameter.s_RGBLuxTable,
                                           pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve
                                          );

    SetRgbLuxTable(&pIn_Out->s_Par.s_CameraParameter.s_RGBLuxTable,
                   ui32_R1,
                   ui32_R2,
                   f32_T1_us,
                   f32_T2_us,
                   f32_T3_us,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.f32_Gain,
                   f32_RatioRedGreen,
                   f32_RatioBlueGreen,
                   f32_RatioGreenRef,
                   pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength,
                   &pIn->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[0]);

    if(  (fABS(pIn->s_Par.s_SensorAngles.f32_Pitch)                  > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Roll)                   > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Yaw)                    > 1.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_X)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Y)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Z)                      > 10.0f)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_y       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_x         > 1000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_y         > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     < 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     < 1000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_x            > 2000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_y            > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_x)      > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_y)      > 1000)
      || (pIn->s_Par.s_CameraParameter.s_ImageHeader.uiBitsPerChannel> 16)
      || (pIn->s_Par.s_CameraParameter.e_bayerPattern                > 10)
      || (fABS(pIn->s_Par.s_CameraParameter.f32_cycleTime)           > 1.0f)
      || (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength> 20)
      || (fABS(pIn->s_Par.s_HlarPar.Roi.PrecVehLight_minDistance)    > 100)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Pitch)                    > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Roll)                     > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Yaw)                      > 1.0f) 
      || (fABS(pIn->s_Sig.s_MotionState.f32_Speed)                   > 200.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRate)                 > 10.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRateRaw)              > 10.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_R_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_G_Greyvalue > 1000.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue < 100.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Blacklevel_B_Greyvalue > 1000.0f)
      )
    {
      Error = SIM_ERR_INVALID_DATA_SIZE;  
    }
  }
  else
  {
    // Error = ...
  }

  return Error;
}


uint32 CHlarInputData::SetHlarInputData_v13(HLAR_t_RequiredInputs_v12* pIn, HLAR_t_RequiredInputs* pIn_Out)
{  
  uint32  i;
  uint32  Error = SIM_ERR_OK;


  if(pIn_Out && pIn)
  {
    


    pIn_Out->uiFrameCnt                   = pIn->uiFrameCnt;
    pIn_Out->ui32_InterfaceVersionNumber  = pIn->ui32_InterfaceVersionNumber;
    pIn_Out->uiTimeStamp_HLA_us           = pIn->uiTimeStamp_HLA_us;
    pIn_Out->uiTimeStamp_VDY_us           = pIn->uiTimeStamp_VDY_us;
    pIn_Out->uiTimeStamp_Image_us         = pIn->uiTimeStamp_Image_us;
    pIn_Out->uiVDY_Cnt                    = pIn->uiVDY_Cnt;

    /* HLAR_t_InputSignals */
    Set_HLA_Availability(&pIn_Out->s_Sig.s_Avl,
      pIn->s_Sig.s_Avl.e_Type,
      pIn->s_Sig.s_Avl.e_State,
      pIn->s_Sig.s_Avl.e_USSens
      );
    Set_HLA_ImagerState( &pIn_Out->s_Sig.s_ImagerState,
      pIn->s_Sig.s_ImagerState.e_ActiveChar,
      pIn->s_Sig.s_ImagerState.f32_Brightness_Lux,
      pIn->s_Sig.s_ImagerState.ui32_ExposureTime_us,
      pIn->s_Sig.s_ImagerState.ui32_FrameNumber,
      pIn->s_Sig.s_ImagerState.f32_Noise,

      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R1,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R2, 
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T1_us,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T2_us,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T3_us,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_Gain,
      /* response curve */
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Blacklevel_R_Greyvalue,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Blacklevel_G_Greyvalue,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Blacklevel_B_Greyvalue,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Kneepoint1_Greyvalue,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_R_Lux,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_B_Lux,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Kneepoint2_Greyvalue,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_R_Lux,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_G_Lux,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_B_Lux,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Saturation_Greyvalue,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_R_Lux,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_G_Lux,
      pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_B_Lux
      );

    Set_HLA_MotionState( &pIn_Out->s_Sig.s_MotionState,
      pIn->s_Sig.s_MotionState.f32_SpeedDisplay,
      pIn->s_Sig.s_MotionState.f32_Speed,
      pIn->s_Sig.s_MotionState.f32_Acceleration,
      pIn->s_Sig.s_MotionState.f32_YawRateRaw,
      pIn->s_Sig.s_MotionState.f32_YawRate,
      pIn->s_Sig.s_MotionState.f32_YawRateQuality,
      pIn->s_Sig.s_MotionState.f32_YawRateVariance,
      pIn->s_Sig.s_MotionState.f32_SteeringWheelAngle,
      pIn->s_Sig.s_MotionState.f32_SteeringAngle,
      pIn->s_Sig.s_MotionState.e_MoveState,
      pIn->s_Sig.s_MotionState.f32_MoveStateConfidence
      );

    Set_HLA_HeadlightState_v2( &pIn_Out->s_Sig.s_HeadlightState,
      pIn->s_Sig.s_HeadlightState.e_LightModuleState,                                        
      pIn->s_Sig.s_HeadlightState.e_HighBeamState,
      pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Lt,
      pIn->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Rt,
      pIn->s_Sig.s_HeadlightState.e_GlareReductionState,
      pIn->s_Sig.s_HeadlightState.f32_LightOutput,
      pIn->s_Sig.s_HeadlightState.nGFA
      );

    /*for(i=0; i<pIn->s_Sig.s_HeadlightState.nGFA; i++)*/
    // HACK AlexM
    for (i=0; i<3; i++)
    {
      Set_HLA_MatrixGFAState_v1( &pIn_Out->s_Sig.s_HeadlightState.GFA[i],
        pIn->s_Sig.s_HeadlightState.GFA[i].f32_PartHBCutoffAng_Lt,
        pIn->s_Sig.s_HeadlightState.GFA[i].f32_PartHBCutoffAng_Rt,
        pIn->s_Sig.s_HeadlightState.GFA[i].f32_HorCutOffAng,
        pIn->s_Sig.s_HeadlightState.GFA[i].f32_LightDistance,
        pIn->s_Sig.s_HeadlightState.GFA[i].e_HorCutOffAngState,
        pIn->s_Sig.s_HeadlightState.GFA[i].e_LightDistanceState,
        pIn->s_Sig.s_HeadlightState.GFA[i].e_LightStyle_Lt,
        pIn->s_Sig.s_HeadlightState.GFA[i].e_LightStyle_Rt
        );
    }

    Set_HLA_VehicleState(&pIn_Out->s_Sig.s_VehicleState,
      pIn->s_Sig.s_VehicleState.b_FogLampFront,
      pIn->s_Sig.s_VehicleState.b_FogLampRear,
      pIn->s_Sig.s_VehicleState.b_RainSensor,
      pIn->s_Sig.s_VehicleState.ui8_WiperState,
      pIn->s_Sig.s_VehicleState.e_WiperWasherFrontState,
      pIn->s_Sig.s_VehicleState.e_WiperStage,
      (HLA_t_VehLevel_v1)pIn->s_Sig.s_VehicleState.s_VehicleLevel
      );

    Set_HLA_CaliOnline(&pIn_Out->s_Sig.s_CaliOnline,
      pIn->s_Sig.s_CaliOnline.f32_OdoCali_m,
      pIn->s_Sig.s_CaliOnline.f32_Pitch,
      pIn->s_Sig.s_CaliOnline.f32_Roll,
      pIn->s_Sig.s_CaliOnline.f32_Yaw
      );

    pIn_Out->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat = pIn->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat;
    pIn_Out->s_Sig.s_DefectPixelList.ui8_DefectsListLength      = pIn->s_Sig.s_DefectPixelList.ui8_DefectsListLength;

    //for(i=0; i<RTE_HLAR_DEFECT_PIXEL_LIST_LENGTH; i++)
    //{
    //  Set_ICDefectPixel( pIn_Out->s_Sig.s_DefectPixelList.as_DefectList[i],
    //    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos,
    //    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos,
    //    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType,
    //    pIn->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count
    //    );
    //}

    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned   = pIn->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned;
    pIn_Out->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState = pIn->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState;

    /* HLAR_t_InputParameters */
    {
      Set_HLA_CameraParameter( &pIn_Out->s_Par.s_CameraParameter,
        pIn->s_Par.s_CameraParameter.e_bayerPattern,
        pIn->s_Par.s_CameraParameter.f32_cycleTime,
        pIn->s_Par.s_CameraParameter.s_FocalLength,
        pIn->s_Par.s_CameraParameter.s_ImageSize,
        pIn->s_Par.s_CameraParameter.s_CroppedRoiSize,
        pIn->s_Par.s_CameraParameter.s_CroppedRoiX1,
        pIn->s_Par.s_CameraParameter.s_LensCenter,

        /* camera distortion parameter */
        pIn->s_Par.s_CameraParameter.s_Distortion.f32_K1,
        pIn->s_Par.s_CameraParameter.s_Distortion.f32_K2,
        pIn->s_Par.s_CameraParameter.s_Distortion.f32_K3,
        pIn->s_Par.s_CameraParameter.s_Distortion.f32_K4,
        pIn->s_Par.s_CameraParameter.s_Distortion.f32_K5,
        /* camera distortion parameter */  

        /* Image header parameter */
        pIn->s_Par.s_CameraParameter.s_ImageHeader.uiBitsPerChannel,
        1,                                                             /* see below */
        pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x,          /* for simu/eval board there are no dummy pixels at the end of each row */
        pIn->s_Par.s_CameraParameter.s_ImageHeader.iSizeBytes,
        pIn->s_Par.s_CameraParameter.s_ImageHeader.uiWidth,
        pIn->s_Par.s_CameraParameter.s_ImageHeader.uiHeight,
        pIn->s_Par.s_CameraParameter.s_ImageHeader.iScaleX,
        pIn->s_Par.s_CameraParameter.s_ImageHeader.iScaleY,
        pIn->s_Par.s_CameraParameter.s_ImageHeader.iOffsetX,
        pIn->s_Par.s_CameraParameter.s_ImageHeader.iOffsetY,
        pIn->s_Par.s_CameraParameter.s_ImageHeader.eDataFormat,
        pIn->s_Par.s_CameraParameter.s_ImageHeader.uiParameterId
        /* Image header parameter */                                              
        );
    }

    pIn_Out->s_Par.s_SensorSocket = pIn->s_Par.s_SensorSocket;

    Set_HLA_SensorAngles(&pIn_Out->s_Par.s_SensorAngles,
      pIn->s_Par.s_SensorAngles.f32_Pitch,
      pIn->s_Par.s_SensorAngles.f32_Roll,
      pIn->s_Par.s_SensorAngles.f32_Yaw,
      pIn->s_Par.s_SensorAngles.f32_Quality,
      pIn->s_Par.s_SensorAngles.e_caliState
      );

    /* CPAR_HLA_Parameter_t */
    pIn_Out->s_Par.s_HlaPar.HLAType = pIn->s_Par.s_HlaPar.HLAType;
    Set_HLA_ParameterAlgoCfg(&pIn_Out->s_Par.s_HlaPar.AlgoCfg,
      pIn->s_Par.s_HlaPar.AlgoCfg.TestMode,
      pIn->s_Par.s_HlaPar.AlgoCfg.CityDetection,
      pIn->s_Par.s_HlaPar.AlgoCfg.TunnelDetection,
      pIn->s_Par.s_HlaPar.AlgoCfg.BadPixelDetection,
      pIn->s_Par.s_HlaPar.AlgoCfg.FogDetection,
      pIn->s_Par.s_HlaPar.AlgoCfg.BlockageDetection
      );
    Set_HLA_ParameterHeadlight(&pIn_Out->s_Par.s_HlaPar.Headlight,
      pIn->s_Par.s_HlaPar.Headlight.HeadLightType,
      pIn->s_Par.s_HlaPar.Headlight.HeadLightMechanics,
      pIn->s_Par.s_HlaPar.Headlight.SpotLight,
      pIn->s_Par.s_HlaPar.Headlight.SpotLightWidth,
      pIn->s_Par.s_HlaPar.Headlight.FullHBDefaultPos_Left,
      pIn->s_Par.s_HlaPar.Headlight.FullHBDefaultPos_Right,
      pIn->s_Par.s_HlaPar.Headlight.HeadLampLatency,
      pIn->s_Par.s_HlaPar.Headlight.SpotLightTolerance
      );

    Set_HLA_ParameterVehicle(&pIn_Out->s_Par.s_HlaPar.Vehicle,
      pIn->s_Par.s_HlaPar.Vehicle.WindshieldType
      );
    Set_HLA_ParameterCountry(&pIn_Out->s_Par.s_HlaPar.Country,
      pIn->s_Par.s_HlaPar.Country.TrafficStyle,
      pIn->s_Par.s_HlaPar.Country.SensitivityMode,
      pIn->s_Par.s_HlaPar.Country.CountryWithMultipleReflectors
      );
    /* CPAR_HLAR_Parameter_t */
    Set_HLA_ParameterRoi(&pIn_Out->s_Par.s_HlarPar.Roi,
      pIn->s_Par.s_HlarPar.Roi.FOV_Horizontal,
      pIn->s_Par.s_HlarPar.Roi.FOV_FunctionRoiAboveHorizon,
      pIn->s_Par.s_HlarPar.Roi.FOV_MinBelowHorizon,
      pIn->s_Par.s_HlarPar.Roi.FOV_MinAboveHorizon,
      pIn->s_Par.s_HlarPar.Roi.PrecVehLight_minDistance,
      pIn->s_Par.s_HlarPar.Roi.PrecVehLight_minHeight,
      pIn->s_Par.s_HlarPar.Roi.StreetLamp_Distance,
      pIn->s_Par.s_HlarPar.Roi.StreetLamp_Height
      );
    Set_HLA_ParameterCity( &pIn_Out->s_Par.s_HlarPar.City,
      pIn->s_Par.s_HlarPar.City.SpeedThresholdLow,
      pIn->s_Par.s_HlarPar.City.SpeedThresholdHigh,
      pIn->s_Par.s_HlarPar.City.NumLeavingStreetlamp_LowSpeed,
      pIn->s_Par.s_HlarPar.City.NumLeavingStreetlamp_HighSpeed,
      pIn->s_Par.s_HlarPar.City.NumSceneStreetlamp_LowSpeed,
      pIn->s_Par.s_HlarPar.City.NumSceneStreetlamp_HighSpeed,
      pIn->s_Par.s_HlarPar.City.AmbientLevel_LowSpeed,
      pIn->s_Par.s_HlarPar.City.AmbientLevel_HighSpeed,
      pIn->s_Par.s_HlarPar.City.StreetLampMaxInterDist_LowSpeed,
      pIn->s_Par.s_HlarPar.City.StreetLampMaxInterDist_HighSpeed,
      pIn->s_Par.s_HlarPar.City.StreetLampMaxDist_LowSpeed,
      pIn->s_Par.s_HlarPar.City.StreetLampMaxDist_HighSpeed,
      pIn->s_Par.s_HlarPar.City.LeavingCityDelay_LowSpeed,
      pIn->s_Par.s_HlarPar.City.LeavingCityDelay_HighSpeed,
      pIn->s_Par.s_HlarPar.City.LeavingCityDelaySceneStreetlamp_LowInt,
      pIn->s_Par.s_HlarPar.City.LeavingCityDelaySceneStreetlamp_HighInt,
      pIn->s_Par.s_HlarPar.City.NumTunnelStreetlamp
      );
    Set_HLA_ParameterHighway(&pIn_Out->s_Par.s_HlarPar.Highway,
      pIn->s_Par.s_HlarPar.Highway.SpeedDetThreshold_Fast,
      pIn->s_Par.s_HlarPar.Highway.SpeedDetThreshold,
      pIn->s_Par.s_HlarPar.Highway.SpeedDetThresholdDistance,
      pIn->s_Par.s_HlarPar.Highway.EgoMotionDetThresholdHigh,
      pIn->s_Par.s_HlarPar.Highway.EgoMotionDetThresholdLow,
      pIn->s_Par.s_HlarPar.Highway.LateralPositionUsedTracks,
      pIn->s_Par.s_HlarPar.Highway.LateralPositionConfidenceThreshHigh,
      pIn->s_Par.s_HlarPar.Highway.LateralPositionConfidenceThreshLow,
      pIn->s_Par.s_HlarPar.Highway.OcclusionOncomingLeavingLightsThresh,
      pIn->s_Par.s_HlarPar.Highway.OcclusionConfidenceStep
      );

    Set_HLA_ParameterTunnel( &pIn_Out->s_Par.s_HlarPar.Tunnel,
      pIn->s_Par.s_HlarPar.Tunnel.EntryThreshHigh,
      pIn->s_Par.s_HlarPar.Tunnel.EntryThreshLow,
      pIn->s_Par.s_HlarPar.Tunnel.EntryDistanceMin,
      pIn->s_Par.s_HlarPar.Tunnel.EntryDistanceMax,
      pIn->s_Par.s_HlarPar.Tunnel.ExitThreshHigh,
      pIn->s_Par.s_HlarPar.Tunnel.ExitThreshLow,
      pIn->s_Par.s_HlarPar.Tunnel.ExitDistanceMin,
      pIn->s_Par.s_HlarPar.Tunnel.DetectionTypeDistance
      );

    Set_HLA_ParameterTrafficStyle( &pIn_Out->s_Par.s_HlarPar.TrafficStyle,
      pIn->s_Par.s_HlarPar.TrafficStyle.NumOncLightsThres,
      pIn->s_Par.s_HlarPar.TrafficStyle.NumOncLightsLock
      );

    Set_HLA_ParameterAmbient(&pIn_Out->s_Par.s_HlarPar.Ambient,
      pIn->s_Par.s_HlarPar.Ambient.SpeedThreshold,
      pIn->s_Par.s_HlarPar.Ambient.AmbientLevel_LowSpeed,
      pIn->s_Par.s_HlarPar.Ambient.AmbientLevel_HighSpeed,
      pIn->s_Par.s_HlarPar.Ambient.Day2NightTimeThres_LowSpeed,
      pIn->s_Par.s_HlarPar.Ambient.Day2NightTimeThres_HighSpeed,
      pIn->s_Par.s_HlarPar.Ambient.Day2NightDistThres_LowSpeed,
      pIn->s_Par.s_HlarPar.Ambient.Day2NightDistThres_HighSpeed,
      pIn->s_Par.s_HlarPar.Ambient.Night2DayTimeThres_LowSpeed,
      pIn->s_Par.s_HlarPar.Ambient.Night2DayTimeThres_HighSpeed,
      pIn->s_Par.s_HlarPar.Ambient.Night2DayDistThres_LowSpeed,
      pIn->s_Par.s_HlarPar.Ambient.Night2DayDistThres_HighSpeed
      );
    Set_HLA_ParameterVehDet( &pIn_Out->s_Par.s_HlarPar.Vehicle,
      pIn->s_Par.s_HlarPar.Vehicle.OncSensitivity,
      pIn->s_Par.s_HlarPar.Vehicle.PrecSensitivity
      );
    Set_HLA_ParameterLightPair(&pIn_Out->s_Par.s_HlarPar.LightPair,
      pIn->s_Par.s_HlarPar.LightPair.TaillightWidth_Min,
      pIn->s_Par.s_HlarPar.LightPair.TaillightWidth_Max,
      pIn->s_Par.s_HlarPar.LightPair.HeadlightWidth_Min,
      pIn->s_Par.s_HlarPar.LightPair.HeadlightWidth_Max,
      pIn->s_Par.s_HlarPar.LightPair.TaillightHeight_Min,
      pIn->s_Par.s_HlarPar.LightPair.TaillightHeight_Max,
      pIn->s_Par.s_HlarPar.LightPair.HeadlightHeight_Min,
      pIn->s_Par.s_HlarPar.LightPair.HeadlightHeight_Max
      );
    Set_HLA_ParameterDistEst(&pIn_Out->s_Par.s_HlarPar.DistEst,
      pIn->s_Par.s_HlarPar.DistEst.LightHeight_Min,
      pIn->s_Par.s_HlarPar.DistEst.LightHeight_Max,
      pIn->s_Par.s_HlarPar.DistEst.DistFilterConst
      );
    Set_HLA_ParameterTTBEst( &pIn_Out->s_Par.s_HlarPar.TTBEst,
      pIn->s_Par.s_HlarPar.TTBEst.ttbAngle
      );

    if(  (fABS(pIn->s_Par.s_SensorAngles.f32_Pitch)                  > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Roll)                   > 1.0f)
      || (fABS(pIn->s_Par.s_SensorAngles.f32_Yaw)                    > 1.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_X)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Y)                      > 10.0f)
      || (fABS(pIn->s_Par.s_SensorSocket.f32_Z)                      > 10.0f)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_y       > 2000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_x         > 1000)
      || (pIn->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_y         > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_x)     < 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_FocalLength.f32_y)     < 1000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_x            > 2000)
      || (pIn->s_Par.s_CameraParameter.s_ImageSize.ui32_y            > 2000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_x)      > 1000)
      || (fABS(pIn->s_Par.s_CameraParameter.s_LensCenter.f32_y)      > 1000)
      || (pIn->s_Par.s_CameraParameter.s_ImageHeader.uiBitsPerChannel> 16)
      || (pIn->s_Par.s_CameraParameter.e_bayerPattern                > 10)
      || (fABS(pIn->s_Par.s_CameraParameter.f32_cycleTime)           > 1.0f)
      || (pIn->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength> 20)
      || (fABS(pIn->s_Par.s_HlarPar.Roi.PrecVehLight_minDistance)    > 100)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Pitch)                    > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Roll)                     > 1.0f)
      || (fABS(pIn->s_Sig.s_CaliOnline.f32_Yaw)                      > 1.0f) 
      || (fABS(pIn->s_Sig.s_MotionState.f32_Speed)                   > 200.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRate)                 > 10.0f)
      || (fABS(pIn->s_Sig.s_MotionState.f32_YawRateRaw)              > 10.0f)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Blacklevel_R_Greyvalue < 100)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Blacklevel_R_Greyvalue > 1000)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Blacklevel_G_Greyvalue < 100)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Blacklevel_G_Greyvalue > 1000)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Blacklevel_B_Greyvalue < 100)
      || (pIn->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Blacklevel_B_Greyvalue > 1000)
      )
    {
      Error = SIM_ERR_INVALID_DATA_SIZE;  
    }
  }
  else
  {
    // Error = ...
  }

  return Error;
}


RTE_HLA_LightStyle CHlarInputData::Convert_HLA_eLightStyle_v1(HLA_t_enum8 e_LightStyle)
{
  /*! Type definition for HLA light style */
  typedef enum
  {
    HLA_LT_SYMM_V1             = 0u,                                   /*!< symmetric light style */
    HLA_LT_COUNTRY_V1          = 1u,                                   /*!< Country light style   */
    HLA_LT_MOTORWAY_V1         = 2u,                                   /*!< Motorway light style  */
    HLA_LT_PART_HIBM_V1        = 3u,                                   /*!< partial high beam     */
    HLA_LT_FULL_HIBM_V1        = 4u                                    /*!< full high beam        */
  } HLA_t_eLightStyle_v1;

  RTE_HLA_LightStyle eOut;

  switch(e_LightStyle)
  {
  case HLA_LT_SYMM_V1:
    eOut = RTE_HLA_LIGHTSTYLE_SYMM;
    break;
  case HLA_LT_COUNTRY_V1:
    eOut = RTE_HLA_LIGHTSTYLE_COUNTRY;
    break;
  case HLA_LT_MOTORWAY_V1:
    eOut = RTE_HLA_LIGHTSTYLE_MOTORWAY;
    break;    
  case HLA_LT_PART_HIBM_V1:
    eOut = RTE_HLA_LIGHTSTYLE_PART_HB;
    break;    
  case HLA_LT_FULL_HIBM_V1:
    eOut = RTE_HLA_LIGHTSTYLE_FULL_HB;
    break;    
  default:
    eOut = RTE_HLA_LIGHTSTYLE_INVALID;
    break;
  }
  return(eOut);
}


RTE_HLA_LightStyle CHlarInputData::Convert_HLA_eLightStyle_v2(HLA_t_enum8 e_LightStyle)
{
  /*! Type definition for HLA light style */
  typedef enum
  {
    HLA_LIGHTSTYLE_UNKNOWN_V2   = 0u,
    HLA_LIGHTSTYLE_SYMM_V2      = 1u,   
    HLA_LIGHTSTYLE_COUNTRY_V2   = 2u,   
    HLA_LIGHTSTYLE_MOTORWAY_V2  = 3u,   
    HLA_LIGHTSTYLE_PART_HB_V2   = 4u,   
    HLA_LIGHTSTYLE_FULL_HB_V2   = 5u,   
    HLA_LIGHTSTYLE_SPOT_V2      = 6u
  } HLA_t_eLightStyle_v2;

  RTE_HLA_LightStyle eOut;

  switch(e_LightStyle)
  {
  case HLA_LIGHTSTYLE_UNKNOWN_V2:
    eOut = RTE_HLA_LIGHTSTYLE_UNKNOWN;
    break;
  case HLA_LIGHTSTYLE_SYMM_V2:
    eOut = RTE_HLA_LIGHTSTYLE_SYMM;
    break;
  case HLA_LIGHTSTYLE_COUNTRY_V2:
    eOut = RTE_HLA_LIGHTSTYLE_COUNTRY;
    break;
  case HLA_LIGHTSTYLE_MOTORWAY_V2:
    eOut = RTE_HLA_LIGHTSTYLE_MOTORWAY;
    break;    
  case HLA_LIGHTSTYLE_PART_HB_V2:
    eOut = RTE_HLA_LIGHTSTYLE_PART_HB;
    break;    
  case HLA_LIGHTSTYLE_FULL_HB_V2:
    eOut = RTE_HLA_LIGHTSTYLE_FULL_HB;
    break; 
  case HLA_LIGHTSTYLE_SPOT_V2:
    eOut = RTE_HLA_LIGHTSTYLE_SPOT;
    break;  
  default:
    eOut = RTE_HLA_LIGHTSTYLE_INVALID;
    break;
  }
  return(eOut);
}

RTE_HLA_HeadlightType CHlarInputData::Convert_HLA_eHeadLightType_v1(HLA_t_enum8 e_HeadLightType)
{
  /*! Type definition for light type */
  typedef enum
  {
    HLA_LTYPE_UNKNOWN_V1         = 0u,
    HLA_LTYPE_HALOGENE_V1        = 1u,
    HLA_LTYPE_XENON_V1           = 2u,
    HLA_LTYPE_LED_V1             = 3u,
    HLA_LTYPE_PIXEL_V1           = 4u
  } HLA_t_eHeadLightType_v1;

  RTE_HLA_HeadlightType eOut;

  switch(e_HeadLightType)
  {
  case HLA_LTYPE_UNKNOWN_V1:
    eOut = RTE_HLA_LTYPE_UNKNOWN;
    break;
  case HLA_LTYPE_HALOGENE_V1:
    eOut = RTE_HLA_LTYPE_HALOGENE;
    break;
  case HLA_LTYPE_XENON_V1:
    eOut = RTE_HLA_LTYPE_XENON;
    break;
  case HLA_LTYPE_LED_V1:
    eOut = RTE_HLA_LTYPE_LED;
    break;
  case HLA_LTYPE_PIXEL_V1:
    eOut = RTE_HLA_LTYPE_PIXEL;
    break;
  default:
    eOut = RTE_HLA_LTYPE_INVALID;
    break;
  }
  return(eOut);
}

RTE_HLA_HeadLightMechanics CHlarInputData::Convert_HLA_eHeadLightMechanics_v1(HLA_t_enum8 e_HeadLightMechanics)
{
  /*! Type definition for light mechanics */
  typedef enum
  {
    HLA_LMECH_UNKNOWN_V1         = 0u,
    HLA_LMECH_ROLLER_V1          = 1u, /* "Walze"     */
    HLA_LMECH_APERTURE_V1        = 2u, /* "Blende"    */
    HLA_LMECH_NONE_V1            = 3u  /* pixel light */
  } HLA_t_eHeadLightMechanics_v1;

  RTE_HLA_HeadLightMechanics eOut;

  switch(e_HeadLightMechanics)
  {
  case HLA_LMECH_UNKNOWN_V1:
    eOut = RTE_HLA_LMECH_UNKNOWN;
    break;
  case HLA_LMECH_ROLLER_V1:
    eOut = RTE_HLA_LMECH_ROLLER;
    break;
  case HLA_LMECH_APERTURE_V1:
    eOut = RTE_HLA_LMECH_APERTURE;
    break;
  case HLA_LMECH_NONE_V1:
    eOut = RTE_HLA_LMECH_NONE;
    break;
  default:
    eOut = RTE_HLA_LMECH_INVALID;
    break;
  }
  return(eOut);
}

RTE_HLA_SpotLight CHlarInputData::Convert_HLA_eSpotLight_v1(HLA_t_enum8 eSpotLight)
{
  /*! Type definition for spot light */
  typedef enum
  {
    HLA_SPOTLIGHT_UNKNOWN_V1         = 0u,
    HLA_SPOTLIGHT_AVL_V1             = 1u, /* spot light installed     */
    HLA_SPOTLIGHT_NAVL_V1            = 2u  /* spot light not installed */
  } HLA_t_eSpotLight_v1;

  RTE_HLA_SpotLight eOut;

  switch(eSpotLight)
  {
  case HLA_SPOTLIGHT_UNKNOWN_V1:
    eOut = RTE_HLA_SPOTLIGHT_UNKNOWN;
    break;
  case HLA_SPOTLIGHT_AVL_V1:
    eOut = RTE_HLA_SPOTLIGHT_AVL;
    break;
  case HLA_SPOTLIGHT_NAVL_V1:
    eOut = RTE_HLA_SPOTLIGHT_NAVL;
    break;
  default:
    eOut = RTE_HLA_SPOTLIGHT_INVALID;
    break;
  }
  return(eOut);
}

RTE_HLA_WindshieldType CHlarInputData::Convert_HLA_eWindshieldType_v1(HLA_t_enum8 eWindshieldType)
{
  /*! Type definition for windshield type */
  typedef enum
  {
    HLA_WTYPE_UNKNOWN_V1         = 0u,
    HLA_WTYPE_CLEAR1_V1          = 1u,
    HLA_WTYPE_CLEAR2_V1          = 2u,
    HLA_WTYPE_GREEN_V1           = 3u,
    HLA_WTYPE_BLUE_V1            = 4u
  } HLA_t_eWindshieldType_v1;

  RTE_HLA_WindshieldType eOut;

  switch(eWindshieldType)
  {
  case HLA_WTYPE_UNKNOWN_V1:
    eOut = RTE_HLA_WTYPE_UNKNOWN;
    break;
  case HLA_WTYPE_CLEAR1_V1:
    eOut = RTE_HLA_WTYPE_CLEAR1;
    break;
  case HLA_WTYPE_CLEAR2_V1:
    eOut = RTE_HLA_WTYPE_CLEAR2;
    break;
  case HLA_WTYPE_GREEN_V1:
    eOut = RTE_HLA_WTYPE_GREEN;
    break;
  case HLA_WTYPE_BLUE_V1:
    eOut = RTE_HLA_WTYPE_BLUE;
    break;
  default:
    eOut = RTE_HLA_WTYPE_INVALID;
    break;
  }
  return(eOut);
}

RTE_HLAR_DefectPixelType CHlarInputData::Convert_HLA_eDefectPixelType_v1(HLA_t_enum8 eDefectPixelType)
{
  /*! Type definition for defect pixel types. */
  typedef enum
  {
    HLA_DEFECT_PIXEL_PIX_OK_V1         = 0u,         /*!< pixel has no defect */
    HLA_DEFECT_PIXEL_RED_HOT_PIX_V1    = 1u,         /*!< red and hot pixel detected during production, anywhere on the imager */
    HLA_DEFECT_PIXEL_DYN_HOT_PIX_V1    = 2u          /*!< dynamic hot pixel */
  } HLA_t_eDefectPixelType_v1;

  RTE_HLAR_DefectPixelType eOut;

  switch(eDefectPixelType)
  {
  case HLA_DEFECT_PIXEL_PIX_OK_V1:
    eOut = RTE_HLAR_DEFECT_PIXEL_PIX_OK;
    break;
  case HLA_DEFECT_PIXEL_RED_HOT_PIX_V1:
    eOut = RTE_HLAR_DEFECT_PIXEL_RED_HOT_PIX;
    break;
  case HLA_DEFECT_PIXEL_DYN_HOT_PIX_V1:
    eOut = RTE_HLAR_DEFECT_PIXEL_DYN_HOT_PIX;
    break;
  default:
    eOut = RTE_HLAR_DEFECT_PIXEL_INVALID;
    break;
  }
  return(eOut);
}


RTE_HLA_LightModuleState CHlarInputData::Convert_HLA_eLightModuleState_v1(HLA_t_enum8 eLightModuleState)
{
  /*! Type definition for HLA head light state */
  typedef enum
  {
    HLA_LTM_NAVL_V1            = 0u,                                   /*!< Light module not available */
    HLA_LTM_IDLE_V1            = 1u,                                   /*!< HLA function ready */
    HLA_LTM_FAULT_V1           = 2u,                                   /*!< Light module temporarily not available */
    HLA_LTM_DEACT_V1           = 3u                                    /*!< HLA function deactivated by tourism function */
  } HLA_t_eLightModuleState_v1; 

  RTE_HLA_LightModuleState eOut;

  switch(eLightModuleState)
  {
  case HLA_LTM_NAVL_V1:
    eOut = RTE_HLA_LTM_NAVL;
    break;
  case HLA_LTM_IDLE_V1:
    eOut = RTE_HLA_LTM_IDLE;
    break;
  case HLA_LTM_FAULT_V1:
    eOut = RTE_HLA_LTM_FAULT;
    break;
  case HLA_LTM_DEACT_V1:
    eOut = RTE_HLA_LTM_DEACT;
    break;
  default:
    eOut = RTE_HLA_LTM_INVALID;
    break;
  }
  return(eOut);
}

RTE_HLA_LightModuleState CHlarInputData::Convert_HLA_eLightModuleState_v2(HLA_t_enum8 eLightModuleState)
{
  /*! Type definition for HLA head light state */
  typedef enum
  {
    HLA_LTM_UNKNOWN_V2         = 0u,                                   /*!< Light module not available */
    HLA_LTM_NAVL_V2            = 1u,                                   /*!< Light module not available */
    HLA_LTM_IDLE_V2            = 2u,                                   /*!< HLA function ready */
    HLA_LTM_FAULT_V2           = 3u,                                   /*!< Light module temporarily not available */
    HLA_LTM_DEACT_V2           = 4u                                    /*!< HLA function deactivated by tourism function */
  } HLA_t_eLightModuleState_v2; 

  RTE_HLA_LightModuleState eOut;

  switch(eLightModuleState)
  {
  case HLA_LTM_UNKNOWN_V2:
    eOut = RTE_HLA_LTM_UNKNOWN;
    break;
  case HLA_LTM_NAVL_V2:
    eOut = RTE_HLA_LTM_NAVL;
    break;
  case HLA_LTM_IDLE_V2:
    eOut = RTE_HLA_LTM_IDLE;
    break;
  case HLA_LTM_FAULT_V2:
    eOut = RTE_HLA_LTM_FAULT;
    break;
  case HLA_LTM_DEACT_V2:
    eOut = RTE_HLA_LTM_DEACT;
    break;
  default:
    eOut = RTE_HLA_LTM_INVALID;
    break;
  }
  return(eOut);
}

RTE_HLA_GlareReductionState CHlarInputData::Convert_HLA_eGlareReductionState_v1(HLA_t_enum8 eGlareReductionState)
{
  /*! Type definition for HLA glare reduction state */
  typedef enum
  {
    HLA_GR_INACTIVE_V1         = 0u,                                   /*!< Inactive */
    HLA_GR_ACTIVE_V1           = 1u,                                   /*!< Active */
    HLA_GR_NDEF2_V1            = 2u                                    /*!< not defined */
  } HLA_t_eGlareReductionState_v1;

  RTE_HLA_GlareReductionState eOut;

  switch(eGlareReductionState)
  {
  case HLA_GR_INACTIVE_V1:
    eOut = RTE_HLA_GR_INACTIVE;
    break;
  case HLA_GR_ACTIVE_V1:
    eOut = RTE_HLA_GR_ACTIVE;
    break;
  case HLA_GR_NDEF2_V1:
    eOut = RTE_HLA_GR_UNKNOWN;
    break;
  default:
    eOut = RTE_HLA_GR_INVALID;
    break;
  }
  return(eOut);
}

RTE_HLA_GlareReductionState CHlarInputData::Convert_HLA_eGlareReductionState_v2(HLA_t_enum8 eGlareReductionState)
{
  /*! Type definition for HLA glare reduction state */
  typedef enum
  {
    HLA_GR_UNKNOWN_V2         = 0u,                                   /*!< Inactive */
    HLA_GR_INACTIVE_V2        = 1u,                                   /*!< Inactive */
    HLA_GR_ACTIVE_V2          = 2u                                    /*!< Active */
  } HLA_t_eGlareReductionState_v2;

  RTE_HLA_GlareReductionState eOut;

  switch(eGlareReductionState)
  {
  case HLA_GR_UNKNOWN_V2:
    eOut = RTE_HLA_GR_UNKNOWN;
    break;
  case HLA_GR_INACTIVE_V2:
    eOut = RTE_HLA_GR_INACTIVE;
    break;
  case HLA_GR_ACTIVE_V2:
    eOut = RTE_HLA_GR_ACTIVE;
    break;
  default:
    eOut = RTE_HLA_GR_INVALID;
    break;
  }
  return(eOut);
}

HLA_t_eWiperWasherState CHlarInputData::Convert_HLA_eWiperWasherState_v1(HLA_t_enum8 eWiperWasherState)
{
  /*! Type definition for HLA glare reduction state */
  typedef enum
  {
    HLA_WWS_IDLE_V1              = 0u,                                 /*!< Wiper/washer switch not pressed */
    HLA_WWS_TIPWIPE_V1           = 1u,                                 /*!< Tip wiping pressed */
    HLA_WWS_WASH_V1              = 2u                                  /*!< Washing pressed */
  } HLA_t_eWiperWasherState_v1;

  HLA_t_eWiperWasherState eOut;

  switch(eWiperWasherState)
  {
  case HLA_WWS_IDLE_V1:
    eOut = HLA_WWSTATE_OFF;
    break;
  case HLA_WWS_TIPWIPE_V1:
    eOut = HLA_WWSTATE_TIPWIPE;
    break;
  case HLA_WWS_WASH_V1:
    eOut = HLA_WWSTATE_WASH;
    break;
  default:
    eOut = HLA_WWSTATE_INVALID;
    break;
  }
  return(eOut);
}

HLA_t_eWiperStage CHlarInputData::Convert_HLA_eWiperStage_v1(HLA_t_enum8 eWiperStage)
{
  /* Type definition for wiper stages */
  typedef enum
  {
    HLA_WIPER_OFF_V1             = 0u,
    HLA_WIPER_INTERVAL1_V1       = 1u,
    HLA_WIPER_INTERVAL2_V1       = 2u,
    HLA_WIPER_INTERVAL3_V1       = 3u,
    HLA_WIPER_INTERVAL4_V1       = 4u,
    HLA_WIPER_STAGE1_V1          = 5u,
    HLA_WIPER_STAGE2_V1          = 6u
  } HLA_t_eWiperStage_v1;
  
  HLA_t_eWiperStage eOut;

  switch(eWiperStage)
  {
  case HLA_WIPER_OFF_V1:
    eOut = HLA_WIPER_OFF;
    break;
  case HLA_WIPER_INTERVAL1_V1:
    eOut = HLA_WIPER_INTERVAL1;
    break;
  case HLA_WIPER_INTERVAL2_V1:
    eOut = HLA_WIPER_INTERVAL2;
    break;
  case HLA_WIPER_INTERVAL3_V1:
    eOut = HLA_WIPER_INTERVAL3;
    break;
  case HLA_WIPER_INTERVAL4_V1:
    eOut = HLA_WIPER_INTERVAL4;
    break;
  case HLA_WIPER_STAGE1_V1:
    eOut = HLA_WIPER_STAGE1;
    break;
  case HLA_WIPER_STAGE2_V1:
    eOut = HLA_WIPER_STAGE2;
    break;
  default:
    eOut = HLA_WIPER_INVALID;
    break;
  }
  return(eOut);
}

HLA_t_eMovementState CHlarInputData::Convert_HLA_eMovementState_v1(HLA_t_enum8 eMovementState)
{
  /*! Type definition for vehicle movement state. */
  typedef enum
  {
    HLA_MOVE_STATE_IDLE_V1             = 0u,
    HLA_MOVE_STATE_FWD_V1              = 1u,
    HLA_MOVE_STATE_REV_V1              = 2u,
    HLA_MOVE_STATE_STAND_STILL_V1      = 3u
  } HLA_t_eMovementState_v1;

  HLA_t_eMovementState eOut;

  switch(eMovementState)
  {
  case HLA_MOVE_STATE_IDLE_V1:
    eOut = HLA_MOVE_STATE_UNKNOWN;
    break;
  case HLA_MOVE_STATE_FWD_V1:
    eOut = HLA_MOVE_STATE_FWD;
    break;
  case HLA_MOVE_STATE_REV_V1:
    eOut = HLA_MOVE_STATE_REV;
    break;
  case HLA_MOVE_STATE_STAND_STILL_V1:
    eOut = HLA_MOVE_STATE_STAND_STILL;
    break;
  default:
    eOut = HLA_MOVE_STATE_INVALID;
    break;
  }
  return(eOut);
}

HLA_t_eActiveChar CHlarInputData::Convert_HLA_eActiveChar_v1(HLA_t_enum8 eActiveChar)
{
  /*! Type definition for day time states */
  typedef enum
  {
    HLA_EXP_DAY_V1               = 0u,                                 /*!< Illumination time of day is day */
    HLA_EXP_NIGHT_V1             = 1u,                                 /*!< Illumination time of day is night */
  } HLA_t_eActCharacteristic_v1;

  HLA_t_eActiveChar eOut;

  switch(eActiveChar)
  {
  case HLA_EXP_DAY_V1:
    eOut = HLA_ACTIVE_CHAR_DAY;
    break;
  case HLA_EXP_NIGHT_V1:
    eOut = HLA_ACTIVE_CHAR_NIGHT;
    break;
  default:
    eOut = HLA_ACTIVE_CHAR_INVALID;
    break;
  }
  return(eOut);
}

HLA_t_eBayerPatternType CHlarInputData::Convert_HLA_eBayerPatternType_v1(HLA_t_enum8 eBayerPatternType)
{
  /*! Type definition for bayer pattern. */
  typedef enum
  {
    HLA_BAYERPATTERN_RGGB_V1       = 0u, /*!< Bayer Pattern: RGRG:GBGB */
    HLA_BAYERPATTERN_GRBG_V1       = 1u, /*!< Bayer Pattern: GRGR:BGBG */
    HLA_BAYERPATTERN_GBRG_V1       = 2u, /*!< Bayer Pattern: GBGB:RGRG */
    HLA_BAYERPATTERN_BGGR_V1       = 3u  /*!< Bayer Pattern: BGBG:GRGR */
  } HLA_t_eBayerPatternType_v1;

  HLA_t_eBayerPatternType eOut;

  switch(eBayerPatternType)
  {
  case HLA_BAYERPATTERN_RGGB_V1:
    eOut = HLA_BAYERPATTERN_RGGB;
    break;
  case HLA_BAYERPATTERN_GRBG_V1:
    eOut = HLA_BAYERPATTERN_GRBG;
    break;
  case HLA_BAYERPATTERN_GBRG_V1:
    eOut = HLA_BAYERPATTERN_GBRG;
    break;
  case HLA_BAYERPATTERN_BGGR_V1:
    eOut = HLA_BAYERPATTERN_BGGR;
    break;
  default:
    eOut = HLA_BAYERPATTERN_INVALID;
    break;
  }
  return(eOut);
}

HLA_t_eBayerPatternType CHlarInputData::Convert_HLA_eBayerPatternType_v2(HLA_t_enum8 eBayerPatternType)
{
  /*! Type definition for bayer pattern. */
  typedef enum
  {
    HLA_BAYERPATTERN_RGGB_V2       = 0u, /*!< Bayer Pattern: RGRG:GBGB */
    HLA_BAYERPATTERN_GRBG_V2       = 1u, /*!< Bayer Pattern: GRGR:BGBG */
    HLA_BAYERPATTERN_GBRG_V2       = 2u, /*!< Bayer Pattern: GBGB:RGRG */
    HLA_BAYERPATTERN_BGGR_V2       = 3u, /*!< Bayer Pattern: BGBG:GRGR */
    HLA_BAYERPATTERN_UNKNOWN_V2    = 254u
  } HLA_t_eBayerPatternType_v1;

  HLA_t_eBayerPatternType eOut;

  switch(eBayerPatternType)
  {
  case HLA_BAYERPATTERN_RGGB_V2:
    eOut = HLA_BAYERPATTERN_RGGB;
    break;
  case HLA_BAYERPATTERN_GRBG_V2:
    eOut = HLA_BAYERPATTERN_GRBG;
    break;
  case HLA_BAYERPATTERN_GBRG_V2:
    eOut = HLA_BAYERPATTERN_GBRG;
    break;
  case HLA_BAYERPATTERN_BGGR_V2:
    eOut = HLA_BAYERPATTERN_BGGR;
    break;
  case HLA_BAYERPATTERN_UNKNOWN_V2:
    eOut = HLA_BAYERPATTERN_UNKNOWN;
    break;
  default:
    eOut = HLA_BAYERPATTERN_INVALID;
    break;
  }
  return(eOut);
}

void CHlarInputData::Set_HLA_CameraParameter_PreCheck_v1(float32 *f32_RatioRedGreen,
                                                         float32 *f32_RatioBlueGreen,
                                                         float32 *f32_RatioGreenRef,
                                                         float32 *f32_T1_us,
                                                         float32 *f32_T2_us,
                                                         float32 *f32_T3_us,
                                                         uint32  *ui32_R1,
                                                         uint32  *ui32_R2,
                                                         HLA_t_CalibratedRGBLuxTable_v3 *s_RGBLuxTable,
                                                         HLA_t_ImagerResponseCurve_v1 &s_ResponseCurve
                                                        )
{
      /* check incoming ratios */
  if(    (s_RGBLuxTable->f32_RatioRedGreen  == 1)
      || (s_RGBLuxTable->f32_RatioRedGreen  == 0)
      || (s_RGBLuxTable->f32_RatioBlueGreen == 1)
      || (s_RGBLuxTable->f32_RatioBlueGreen == 0)
      || (s_RGBLuxTable->f32_RatioGreenRef  == 0)
    )
  {
    /* invalid color ratios */
    *f32_RatioRedGreen  = s_ResponseCurve.f32_Kneepoint1_G_Lux / s_ResponseCurve.f32_Kneepoint1_R_Lux;
    *f32_RatioBlueGreen = s_ResponseCurve.f32_Kneepoint1_G_Lux / s_ResponseCurve.f32_Kneepoint1_B_Lux;
    *f32_RatioGreenRef  = 1.0f;
  }
  else
  {
    *f32_RatioRedGreen   = s_RGBLuxTable->f32_RatioRedGreen;
    *f32_RatioBlueGreen  = s_RGBLuxTable->f32_RatioBlueGreen;
    *f32_RatioGreenRef   = s_RGBLuxTable->f32_RatioGreenRef;
  }

  /* check R1, R2 */
  if(    (s_RGBLuxTable->ui32_R1 != 16)
      || (s_RGBLuxTable->ui32_R2 != 16)
    )
  {
    /* wrong R1, R2 -> overwrite R1, R2 with correct values */
    *ui32_R1 = 16;
    *ui32_R2 = 16;
  }
  else
  {
    /* R1, R2 OK */
    *ui32_R1 = s_RGBLuxTable->ui32_R1;
    *ui32_R2 = s_RGBLuxTable->ui32_R2;
  }

  /* set T1,2,3 Production    */
  /* correct PPAR from camera */
  *f32_T1_us =  511    * IMGHWD_cf32_LineTimeUs;
  *f32_T2_us =   31    * IMGHWD_cf32_LineTimeUs;
  *f32_T3_us = 2955.0f * IMGHWD_cf32_PixelTimeUs;

}

void CHlarInputData::SetRgbLuxTable(HLA_t_CalibratedRGBLuxTable *destRGBLuxTable,
                    uint32                      ui32_R1,
                    uint32                      ui32_R2,
                    float32                     f32_T1_us,
                    float32                     f32_T2_us,
                    float32                     f32_T3_us,
                    float32                     f32_Gain,
                    float32                     f32_RatioRedGreen,
                    float32                     f32_RatioBlueGreen,
                    float32                     f32_RatioGreenRef,
                    uint32                      ui32_tableLength,
                    HLA_t_RGBLuxElement_v1      *pRGBLuxTable)
{
/* HLA_t_CalibratedRGBLuxTable */
  destRGBLuxTable->ui32_R1            = ui32_R1;
  destRGBLuxTable->ui32_R2            = ui32_R2;
  destRGBLuxTable->f32_T1_us          = f32_T1_us;
  destRGBLuxTable->f32_T2_us          = f32_T2_us;
  destRGBLuxTable->f32_T3_us          = f32_T3_us;
  destRGBLuxTable->f32_Gain           = f32_Gain;
  destRGBLuxTable->f32_RatioRedGreen  = f32_RatioRedGreen;
  destRGBLuxTable->f32_RatioBlueGreen = f32_RatioBlueGreen;
  destRGBLuxTable->f32_RatioGreenRef  = f32_RatioGreenRef;

  destRGBLuxTable->ui32_tableLength = ui32_tableLength;
  memcpy(&destRGBLuxTable->as_table[0],
         pRGBLuxTable,
         (sizeof(HLA_t_RGBLuxElement) * HLA_ui8_MAX_RGBL_ELEM)
        );
}
