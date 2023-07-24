/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlar_ext.h

  DESCRIPTION:            Head light assist recognition interfaces.

  AUTHOR:                 Carlos Almeida

  CREATION DATE:          2009-11-23

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hlar_ext.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:34CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:37:47CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:10CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/project.pj
  CHANGE:                 Revision 1.64 2014/03/05 14:11:45CET Brunn, Marcus (brunnm) 
  CHANGE:                 added RTE_HLA_Seg_LightList_t
  CHANGE:                 --- Added comments ---  brunnm [Mar 5, 2014 2:11:45 PM CET]
  CHANGE:                 Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGE:                 Revision 1.63 2014/03/04 18:00:49CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed ppars and vehpar from RTE and internal interface
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 6:00:49 PM CET]
  CHANGE:                 Change Package : 207432:38 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.62 2014/03/04 16:52:32CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:33 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.61 2014/03/03 16:51:43CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Support for R2.1 interface
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 3, 2014 4:51:43 PM CET]
  CHANGE:                 Change Package : 207432:31 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.60 2014/02/07 13:40:12CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Get version info in wrapper now from lib
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 7, 2014 1:40:13 PM CET]
  CHANGE:                 Change Package : 207432:30 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.59 2014/01/29 07:35:23CET Brunn, Marcus (brunnm) 
  CHANGE:                 updated HLAR_IN_INTERFACE_VERSION_NUMBER
  CHANGE:                 --- Added comments ---  brunnm [Jan 29, 2014 7:35:24 AM CET]
  CHANGE:                 Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGE:                 Revision 1.58 2014/01/08 17:10:25CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Refactored HLA_Exec() function
  CHANGE:                 Replaced uint64 time stamps by uint32 ones
  CHANGE:                 Smaller bug fixes
  CHANGE:                 --- Added comments ---  uidv7867 [Jan 8, 2014 5:10:25 PM CET]
  CHANGE:                 Change Package : 207432:27 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.57 2013/12/13 16:45:05CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:05 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.56 2013/12/09 15:03:10CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Increase Hlar out interface version number due to latest changes in object list
  CHANGE:                 Fixed hlar our adapter
  CHANGE:                 Fixed debug icon adapter for little endian
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 9, 2013 3:03:10 PM CET]
  CHANGE:                 Change Package : 207432:2 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.55 2013/12/04 16:18:25CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Use L2 Cache for SegLightBuffer, SegLineRegionBuffer
  CHANGE:                 Fixed deadlock in segmentation
  CHANGE:                 
  CHANGE:                 Review by AlexM.
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 4, 2013 4:18:26 PM CET]
  CHANGE:                 Change Package : 207432:10 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.54 2013/11/21 17:53:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Merge from NEW_SEG branch
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 21, 2013 5:53:43 PM CET]
  CHANGE:                 Change Package : 207432:6 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.53.1.3 2013/11/05 12:04:57CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added a few more RTA events
  CHANGE:                 --- Added comments ---  uidv7867 [Nov 5, 2013 12:04:57 PM CET]
  CHANGE:                 Change Package : 201787:8 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.53.1.2 2013/10/29 18:21:31CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Time meas fixes
  CHANGE:                 New roi calculation (alignment to eve)
  CHANGE:                 Call EVE in segmentation now
  CHANGE:                 --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:31 PM CET]
  CHANGE:                 Change Package : 201787:2 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGE:                 Revision 1.53.1.1 2013/10/18 13:28:00CEST Brunn, Marcus (brunnm) 
  CHANGE:                 intial version of new segmentation
  CHANGE:                 --- Added comments ---  brunnm [Oct 18, 2013 1:28:01 PM CEST]
  CHANGE:                 Change Package : 198639:1 http://mks-psad:7002/im/viewissue?selection=198639
  CHANGE:                 Revision 1.53 2013/09/26 11:21:38CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced specific HLA opmodes by TestMode CPar
  CHANGE:                 --- Added comments ---  uidv7867 [Sep 26, 2013 11:21:39 AM CEST]
  CHANGE:                 Change Package : 198642:1 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGE:                 Revision 1.52 2013/09/18 17:41:46CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Undo changes from development path
  CHANGE:                 --- Added comments ---  uidv7867 [Sep 18, 2013 5:41:46 PM CEST]
  CHANGE:                 Change Package : 167173:35 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.51 2013/09/17 15:44:35CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added more RTA Events in segmentation (bug hunting)
  CHANGE:                 --- Added comments ---  uidv7867 [Sep 17, 2013 3:44:35 PM CEST]
  CHANGE:                 Change Package : 167173:35 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.50 2013/08/28 11:19:12CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Changed adapter according to new camera parameter struct
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 28, 2013 11:19:13 AM CEST]
  CHANGE:                 Change Package : 195030:1 http://mks-psad:7002/im/viewissue?selection=195030
  CHANGE:                 Revision 1.49 2013/08/05 20:41:19CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed EVE/DSP caching issues
  CHANGE:                 Added time meas struct for EVE
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 5, 2013 8:41:20 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.48 2013/07/26 17:04:12CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Added first part of EVE implementation
  CHANGE:                 --- Added comments ---  uidv7867 [Jul 26, 2013 5:04:12 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.47 2013/07/18 18:12:27CEST Manz, Alexander (uidv8777) 
  CHANGE:                 Updates due to RTE change:
  CHANGE:                 Includes: 
  CHANGE:                  - new HeadlightState
  CHANGE:                  - EcoLight Feature
  CHANGE:                  - Light Dimming Areas Feature
  CHANGE:                  - Light adaptive image display settings for MTS visu
  CHANGE:                  - SRLCam rec file support in visu
  CHANGE:                 --- Added comments ---  uidv8777 [Jul 18, 2013 6:12:28 PM CEST]
  CHANGE:                 Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
  CHANGE:                 Revision 1.46 2013/05/02 12:43:02CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE for I300
  CHANGE:                 --- Added comments ---  uidv7867 [May 2, 2013 12:43:02 PM CEST]
  CHANGE:                 Change Package : 167173:30 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.45 2013/04/09 16:30:38CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE (SW_COMMON_03.01.01_INT-4)
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 9, 2013 4:30:38 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.44 2013/03/13 17:34:07CET Brunn, Marcus (brunnm) 
  CHANGE:                 added HLA parameter to HLAR/F input interface
  CHANGE:                 --- Added comments ---  brunnm [Mar 13, 2013 5:34:08 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.43 2013/03/12 10:59:21CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2013 10:59:21 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.42 2013/03/08 10:30:55CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 10:30:56 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.41 2013/02/22 14:51:27CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Only added comments
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 22, 2013 2:51:27 PM CET]
  CHANGE:                 Change Package : 167173:25 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.40 2013/02/20 08:02:15CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed measfreezes from DSP (little endian)
  CHANGE:                 - added endianness to Interface version number
  CHANGE:                 --- Added comments ---  brunnm [Feb 20, 2013 8:02:15 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.39 2013/02/04 10:34:01CET Schillinger, Patrick (uidv8776) 
  CHANGE:                 added possibility for for direct image access for icon creation.
  CHANGE:                 --- Added comments ---  uidv8776 [Feb 4, 2013 10:34:02 AM CET]
  CHANGE:                 Change Package : 169297:1 http://mks-psad:7002/im/viewissue?selection=169297
  CHANGE:                 Revision 1.38 2013/01/21 13:39:49CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed misra/ lint errors
  CHANGE:                 --- Added comments ---  brunnm [Jan 21, 2013 1:39:49 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.37 2013/01/11 09:07:08CET Brunn, Marcus (brunnm) 
  CHANGE:                 support new opmodes (segmentation: autothreshold off)
  CHANGE:                 --- Added comments ---  brunnm [Jan 11, 2013 9:07:08 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.36 2013/01/07 15:39:43CET Zechner, Stefan (uidt9253) 
  CHANGE:                 rename the 32-bit enum size type again to avoid a lot of ansi-c compiler errors
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLAR_EXT_INCLUDED
#define HLAR_EXT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "hla_type.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
/* 3 Bytes BCD coded: 1 Byte Mainversion, 1Byte Subversion, 1Byte Bugfixlevel */
#define HLAR_SW_VERSION_NUMBER              0x020200

/* HLAR interface version numbers */
#define HLAR_IN_INTERFACE_VERSION_NUMBER_MAIN    2
#define HLAR_IN_INTERFACE_VERSION_NUMBER_SUB     5
#define HLAR_IN_INTERFACE_VERSION_NUMBER_BUGFIX  0
#define HLAR_IN_INTERFACE_VERSION_NUMBER (  (HLA_INTERFACE_VERSION_NUMBER_ENDIAN   << 24) \
                                          | (HLAR_IN_INTERFACE_VERSION_NUMBER_MAIN << 16) \
                                          | (HLAR_IN_INTERFACE_VERSION_NUMBER_SUB  << 8) \
                                          | (HLAR_IN_INTERFACE_VERSION_NUMBER_BUGFIX))

#define HLAR_OUT_INTERFACE_VERSION_NUMBER_MAIN    2
#define HLAR_OUT_INTERFACE_VERSION_NUMBER_SUB     2
#define HLAR_OUT_INTERFACE_VERSION_NUMBER_BUGFIX  0
#define HLAR_OUT_INTERFACE_VERSION_NUMBER (  (HLA_INTERFACE_VERSION_NUMBER_ENDIAN    << 24) \
                                           | (HLAR_OUT_INTERFACE_VERSION_NUMBER_MAIN << 16) \
                                           | (HLAR_OUT_INTERFACE_VERSION_NUMBER_SUB  << 8) \
                                           | (HLAR_OUT_INTERFACE_VERSION_NUMBER_BUGFIX))


/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*! Type definition of the required input parameters for HLAR */
/* static inputs = parameter */
/* constant during runtime   */
typedef struct
{
  HLA_t_CameraParameter             s_CameraParameter;          /*!< camera parameter         */
  HLA_t_SensorSocket                s_SensorSocket;             /*!< sensor socket parameters */
  HLA_t_SensorAngles                s_SensorAngles;             /*!< sensor angles parameters */
  CPAR_HLA_Parameter_t              s_HlaPar;                   /*!< common hla parameter     */
  CPAR_HLAR_Parameter_t             s_HlarPar;                  /*!< hlar parameter           */
} HLAR_t_InputParameters;

/*! Type definition of the required input signals for HLAR */
/* variable inputs             */
/* not constant during runtime */
typedef struct
{
  HLA_t_Availability                s_Avl;                      /*!< availability signal */
  HLA_t_ImagerState                 s_ImagerState;              /*!< image control state signal */
  HLA_t_MotionState                 s_MotionState;              /*!< vehicle motion state signal */
  HLA_t_HeadlightState              s_HeadlightState;           /*!< head light state signal */
  HLA_t_VehicleState                s_VehicleState;             /*!< vehicle state signal */
  HLA_t_CaliOnline                  s_CaliOnline;               /*!< online calibration */

  HLA_t_DefectPixelList             s_DefectPixelList;          /*!< defect pixel list */
  HLA_t_TrafficStyle                s_TrafficStyle;             /*!< traffic style results /Read in eeprom */
} HLAR_t_InputSignals;

/*! Type definition of the required input */
typedef struct
{
  uint32                  ui32_InterfaceVersionNumber;/*!< HLAR input interface version number */
  AlgoCycleCounter_t      uiFrameCnt;                 /*!< Frame counter        */
  AlgoDataTimeStamp_t     uiTimeStamp_HLA_us;         /*!< [us] HLA Timestamp, hla segmentation started, inputs freezed */ 
  AlgoDataTimeStamp_t     uiTimeStamp_VDY_us;         /*!< [us] VDY Timestamp, vdy ouput data */ 
  AlgoDataTimeStamp_t     uiTimeStamp_Image_us;       /*!< [us] Image Timestamp */
  AlgoCycleCounter_t      uiVDY_Cnt;                  /*!< VDY cycle counter    */
  HLAR_t_InputParameters  s_Par;                      /*!< input parameters     */
  HLAR_t_InputSignals     s_Sig;                      /*!< input signals        */
} HLAR_t_RequiredInputs;


/*! Type definition of the provided output */
typedef struct
{
  uint32                  ui32_InterfaceVersionNumber;/*!< HLAR output interface version number */
  uint32                  ui32_HLA_SWVersionNumber;   /*!< HLA Software version number */
  uint32                  ui32_HLAR_SWVersionNumber;  /*!< HLAR Software version number */
  AlgoCycleCounter_t      uiFrameCnt;                 /*!< Frame counter */
  AlgoCycleCounter_t      uiHLAR_Cnt;                 /*!< HLAR cycle counter  */
  AlgoCycleCounter_t      uiHLAS_Cnt;                 /*!< HLAS cycle counter  */
  AlgoDataTimeStamp_t     uiTimeStamp_HLA_us;         /*!< [us] HLA Timestamp, hla input data */
  AlgoDataTimeStamp_t     uiTimeStamp_Image_us;       /*!< [us] Image Timestamp */
  HLA_t_DiagnosisDebugMsg s_DiagnosisDebugMsg;        /*!< 64 Bit Diagnosis message for HLA debugging purposes */
  HLA_t_Fingerprint       s_Fingerprint;              /*!< imager fingerprint */
  HLA_t_CaliOnline        s_CaliOnline;               /*!< online calibration results */
  HLA_t_DefectPixelList   *ps_DefectPixelList;        /*!< pointer to defect pixel list */
  HLA_t_ObjectList        s_ObjectList;               /*!< object list */
  HLA_t_EnvironmentData   s_Environment;              /*!< environment data like brightness, city, highway, tunnel, driving direction, ... */
  HLA_t_TrafficStyle      s_TrafficStyle;             /*!< traffic style results /Write in eeprom */
} HLAR_t_ProvidedOutputs;

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/* Needed for HIL since it is written in c++ */
#ifdef __cplusplus
extern "C" {
#endif

/*! Initializes the HLAR-component only once after bootup */
void HLAR_v_Init( const HLAR_t_RequiredInputs  *ps_In,
                  HLAR_t_ProvidedOutputs       *ps_Out,
                  RTE_HLA_Seg_LightList_t      *ps_SegLightList,
                  HLA_t_SystemInfo             *ps_SystemInfo,
                  t_PixelData                  *pImg,
                  const AS_t_ServiceFuncts     *Services
                );

/*! Executes tracking and environment modelling. */
void HLAR_v_Exec( const HLAR_t_RequiredInputs  *ps_In,
                  HLAR_t_ProvidedOutputs       *ps_Out,
                  RTE_HLA_Seg_LightList_t      *ps_SegLightList,
                  HLA_t_SystemInfo             *ps_SystemInfo,
                  t_PixelData                  *pImg,
                  const AS_t_ServiceFuncts     *Services
                );


/*! Get Algo Version number */
void HLA_v_GetAlgoVersion( uint32* pHlaSWVersionNumber,
                           uint32* pHlaApplicationVersionNumber,
                           uint8   versionInfo[MFC_VERSION_INFO_LENGTH]
                          );

#ifdef __cplusplus
}
#endif /* __cplusplus */


/* avoid cyclic binding ---------------------------------------------------*/
#endif /* #ifndef HLAR_EXT_INCLUDED */
