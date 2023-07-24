/*! \file **********************************************************************

COMPANY:              Continental

PROJECT:              Simulation

COMPONENT:            sim_swc_hla_adapter

MODULNAME:            sim_interface_hlar_input_data.h

DESCRIPTION:          

AUTHOR:               Marcus Brunn

CREATION DATE:        03.08.2010

VERSION:              $Revision: 1.1 $

---*/ /*---
CHANGES:              $Log: sim_interface_hlar_input_data.h  $
CHANGES:              Revision 1.1 2021/12/13 17:23:21CET Wang, David (Wangd3) 
CHANGES:              Initial revision
CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Converter/HLA/project.pj
CHANGES:              Revision 1.0 2017/03/03 10:34:53CET Sorge, Sven (uidg3181) 
CHANGES:              Initial revision
CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Converter/HLA/project.pj
CHANGES:              Revision 1.1 2014/03/18 16:59:20CET Mutschler, Matthias (uidv7867) 
CHANGES:              Initial revision
CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/03_Workspace/algo/hla_sim/hla_adapter/hlar_input/project.pj
CHANGES:              Revision 1.24 2014/03/10 17:13:20CET Brunn, Marcus (brunnm) 
CHANGES:              support hlar_in interface  version 2.4.0
CHANGES:              --- Added comments ---  brunnm [Mar 10, 2014 5:13:20 PM CET]
CHANGES:              Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
CHANGES:              Revision 1.23 2014/01/30 16:13:26CET Brunn, Marcus (brunnm) 
CHANGES:              adapter update for mfc4xx I320 rec-files
CHANGES:              --- Added comments ---  brunnm [Jan 30, 2014 4:13:27 PM CET]
CHANGES:              Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
CHANGES:              Revision 1.22 2013/09/26 11:21:37CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced specific HLA opmodes by TestMode CPar
CHANGES:              --- Added comments ---  uidv7867 [Sep 26, 2013 11:21:37 AM CEST]
CHANGES:              Change Package : 198642:1 http://mks-psad:7002/im/viewissue?selection=198642
CHANGES:              Revision 1.21 2013/08/28 11:19:29CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Changed adapter according to new camera parameter struct
CHANGES:              --- Added comments ---  uidv7867 [Aug 28, 2013 11:19:30 AM CEST]
CHANGES:              Change Package : 195030:1 http://mks-psad:7002/im/viewissue?selection=195030
CHANGES:              Revision 1.20 2013/07/18 18:12:26CEST Manz, Alexander (uidv8777) 
CHANGES:              Updates due to RTE change:
CHANGES:              Includes: 
CHANGES:               - new HeadlightState
CHANGES:               - EcoLight Feature
CHANGES:               - Light Dimming Areas Feature
CHANGES:               - Light adaptive image display settings for MTS visu
CHANGES:               - SRLCam rec file support in visu
CHANGES:              --- Added comments ---  uidv8777 [Jul 18, 2013 6:12:26 PM CEST]
CHANGES:              Change Package : 189283:1 http://mks-psad:7002/im/viewissue?selection=189283
CHANGES:              Revision 1.19 2013/05/02 12:43:00CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Updated to latest RTE for I300
CHANGES:              --- Added comments ---  uidv7867 [May 2, 2013 12:43:00 PM CEST]
CHANGES:              Change Package : 167173:30 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.18 2013/04/09 16:30:35CEST Mutschler, Matthias (uidv7867) 
CHANGES:              Updated to latest RTE (SW_COMMON_03.01.01_INT-4)
CHANGES:              --- Added comments ---  uidv7867 [Apr 9, 2013 4:30:36 PM CEST]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.17 2013/03/12 15:57:55CET Mutschler, Matthias (uidv7867) 
CHANGES:              Smaller adapter fixes and clean-up
CHANGES:              --- Added comments ---  uidv7867 [Mar 12, 2013 3:57:56 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.16 2013/03/12 14:12:10CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced no longer needed types by RTE ones
CHANGES:              --- Added comments ---  uidv7867 [Mar 12, 2013 2:12:10 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.15 2013/03/12 10:59:27CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced no longer needed types by RTE ones
CHANGES:              --- Added comments ---  uidv7867 [Mar 12, 2013 10:59:27 AM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.14 2013/03/11 16:13:41CET Mutschler, Matthias (uidv7867) 
CHANGES:              Replaced no longer needed types by RTE ones
CHANGES:              - HLA_t_eSignalState
CHANGES:              - HLA_t_eLightStyle
CHANGES:              - HLA_t_eTunnel
CHANGES:              - HLA_t_eCityState
CHANGES:              - HLA_t_eWeatherState
CHANGES:              - HLA_t_eMotorwayState
CHANGES:              --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:42 PM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.13 2013/03/08 10:30:59CET Mutschler, Matthias (uidv7867) 
CHANGES:              Updated to latest RTE
CHANGES:              --- Added comments ---  uidv7867 [Mar 8, 2013 10:31:00 AM CET]
CHANGES:              Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
CHANGES:              Revision 1.12 2013/02/06 08:42:22CET Brunn, Marcus (brunnm) 
CHANGES:              updated adapter for i210
CHANGES:              --- Added comments ---  brunnm [Feb 6, 2013 8:42:32 AM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.11 2013/01/11 09:07:48CET Brunn, Marcus (brunnm) 
CHANGES:              support new opmodes (segmentation: autothreshold off)
CHANGES:              --- Added comments ---  brunnm [Jan 11, 2013 9:07:48 AM CET]
CHANGES:              Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
CHANGES:              Revision 1.10 2011/12/01 17:43:25CET Zechner, Stefan (uidt9253) 
CHANGES:              - hlaf nightview blinking spot uses new interface vehicle parameters f32_SpotLightTolerance_rad and f32_HeadLampLatency
CHANGES:              - spot light tolerance adds additional space to the spot width for the night view blinking safety area
CHANGES:              - correct prediction based on the specified head lamp latency of the hla objects
CHANGES:              --- Added comments ---  uidt9253 [Dec 1, 2011 5:43:26 PM CET]
CHANGES:              Change Package : 76260:1 http://mks-psad:7002/im/viewissue?selection=76260
CHANGES:              Revision 1.9 2011/11/04 11:32:30CET Brunn, Marcus (brunnm) 
CHANGES:              added new traffic style structure (HLA_t_TrafficStyle_v1)
CHANGES:              --- Added comments ---  brunnm [Nov 4, 2011 11:32:30 AM CET]
CHANGES:              Change Package : 49575:1 http://mks-psad:7002/im/viewissue?selection=49575
CHANGES:              Revision 1.8 2011/10/24 09:06:24CEST Lugez Boris (uidt2765) (uidt2765) 
CHANGES:              -> Add e_TrafficStyleLastLearned to HLAR_t_RequiredInputs and HLAR_t_ProvidedOutputs
CHANGES:              -> Add e_TrafficStyleLearningState to HLAR_t_RequiredInputs and HLAR_t_ProvidedOutputs
CHANGES:              --- Added comments ---  uidt2765 [Oct 24, 2011 9:06:25 AM CEST]
CHANGES:              Change Package : 49557:1 http://mks-psad:7002/im/viewissue?selection=49557
CHANGES:              Revision 1.7 2011/10/12 15:06:55CEST Zechner Stefan (uidt9253) (uidt9253) 
CHANGES:              - new visualization of the HLA SystemInfo Measfreeze
CHANGES:              --- Added comments ---  uidt9253 [Oct 12, 2011 3:06:55 PM CEST]
CHANGES:              Change Package : 53536:1 http://mks-psad:7002/im/viewissue?selection=53536
CHANGES:              Revision 1.6 2011/09/06 17:18:54CEST Brunn Marcus (brunnm) (brunnm) 
CHANGES:              added HLAR_t_InputSignals_v4 (scn parameter update)
CHANGES:              --- Added comments ---  brunnm [Sep 6, 2011 5:18:54 PM CEST]
CHANGES:              Change Package : 54328:1 http://mks-psad:7002/im/viewissue?selection=54328
CHANGES:              Revision 1.5 2011/09/06 14:33:19CEST Brunn Marcus (brunnm) (brunnm) 
CHANGES:              updated Interface for MFC310 Release 3.2.0 (SCN Parameter)
CHANGES:              Revision 1.4 2011/04/26 14:26:40CEST Brunn Marcus (brunnm) (brunnm) 
CHANGES:              new interface for MFC310 Releaee 2.5 (Idiada)
CHANGES:              --- Added comments ---  brunnm [Apr 26, 2011 2:26:41 PM CEST]
CHANGES:              Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
CHANGES:              Revision 1.3 2011/02/18 12:58:46CET Marcus Brunn (brunnm) 
CHANGES:              support new hla interface (HLA 01.01.00)
CHANGES:              Revision 1.2 2011/02/01 14:48:01CET Marcus Brunn (brunnm) 
CHANGES:              use current imager response curve (calculated and updated by IC on every frame)
CHANGES:              --- Added comments ---  brunnm [Feb 1, 2011 2:48:01 PM CET]
CHANGES:              Change Package : 53526:1 http://mks-psad:7002/im/viewissue?selection=53526
CHANGES:              Revision 1.1 2010/08/05 17:33:42CEST Marcus Brunn (brunnm) 
CHANGES:              Initial revision
CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/03_Workspace/algo/hla_sim/sim_swc_hla_adapter/src/hlar_input/project.pj
CHANGES:              

**************************************************************************** */
#pragma once
#include "common_interface/sim_interface_hla.h"
#include "mfc3_type/mfc3_type.h"


/*! Type definition for debug switch */
typedef enum
{
  HLAR_DEBUG_MODE_NORMAL      = 0u,
  HLAR_DEBUG_MODE_DEMO        = 1u,
  HLAR_DEBUG_MEASFREEZE_ONLY  = 2u,
  HLAR_DEBUG_HB_ON            = 3u,
  HLAR_DEBUG_HB_OFF           = 4u,

  HLAR_DEBUG_MODE_0           = 20u,
  HLAR_DEBUG_MODE_1           = 21u,
  HLAR_DEBUG_MODE_2           = 22u,
  HLAR_DEBUG_MODE_3           = 23u,
  HLAR_DEBUG_MODE_4           = 24u,
  HLAR_DEBUG_MODE_5           = 25u,
  HLAR_DEBUG_MODE_6           = 26u,
  HLAR_DEBUG_MODE_7           = 27u,
  HLAR_DEBUG_MODE_8           = 28u,
  HLAR_DEBUG_MODE_9           = 29u,
  HLAR_DEBUG_MODE_10          = 30u,
  HLAR_DEBUG_MODE_11          = 31u,
  HLAR_DEBUG_MODE_12          = 32u,
  HLAR_DEBUG_MODE_13          = 33u,
  HLAR_DEBUG_MODE_14          = 34u,
  HLAR_DEBUG_MODE_15          = 35u,

  HLAR_DEBUG_LAST             = SI32_T_MAX
} HLAR_t_eDebugSwitch_v1;

/*! Type definition of the required input parameters for HLAR */
/* static inputs = parameter */
/* constant during runtime   */
typedef struct
{
  HLA_t_CameraParameter_v1          s_CameraParameter;          /*!< camera parameter         */
  HLA_t_VehicleParameter_v1         s_VehicleParameter;         /*!< vehicle parameter        */
  HLA_t_SensorSocket                s_SensorSocket;             /*!< sensor socket parameters */
  HLA_t_SensorAngles_v1             s_SensorAngles;             /*!< sensor angles parameters */
} HLAR_t_InputParameters_v1;

typedef struct
{
  HLA_t_CameraParameter_v2          s_CameraParameter;          /*!< camera parameter         */
  HLA_t_VehicleParameter_v1         s_VehicleParameter;         /*!< vehicle parameter        */
  HLA_t_SensorSocket                s_SensorSocket;             /*!< sensor socket parameters */
  HLA_t_SensorAngles_v1             s_SensorAngles;             /*!< sensor angles parameters */
  HLA_t_RoiParameter_v1  		        s_Roi;		          				/*!< hla roi parameters       */
} HLAR_t_InputParameters_v2;

typedef struct
{
  HLA_t_CameraParameter_v3          s_CameraParameter;          /*!< camera parameter         */
  HLA_t_VehicleParameter_v1         s_VehicleParameter;         /*!< vehicle parameter        */
  HLA_t_SensorSocket                s_SensorSocket;             /*!< sensor socket parameters */
  HLA_t_SensorAngles_v1             s_SensorAngles;             /*!< sensor angles parameters */
  HLA_t_RoiParameter_v1  		        s_Roi;		          				/*!< hla roi parameters       */
} HLAR_t_InputParameters_v3;

typedef struct
{
  HLA_t_CameraParameter_v3          s_CameraParameter;          /*!< camera parameter         */
  HLA_t_VehicleParameter_v2         s_VehicleParameter;         /*!< vehicle parameter        */
  HLA_t_SensorSocket                s_SensorSocket;             /*!< sensor socket parameters */
  HLA_t_SensorAngles_v1             s_SensorAngles;             /*!< sensor angles parameters */
  HLA_t_RoiParameter_v1  		        s_Roi;		          				/*!< hla roi parameters       */
} HLAR_t_InputParameters_v4;

typedef struct
{
  HLA_t_CameraParameter_v3          s_CameraParameter;          /*!< camera parameter         */
  HLA_t_VehicleParameter_v3         s_VehicleParameter;         /*!< vehicle parameter        */
  HLA_t_SensorSocket                s_SensorSocket;             /*!< sensor socket parameters */
  HLA_t_SensorAngles_v1             s_SensorAngles;             /*!< sensor angles parameters */
  HLA_t_RoiParameter_v1  		        s_Roi;		          				/*!< hla roi parameters       */
} HLAR_t_InputParameters_v5;

typedef struct
{
  HLA_t_CameraParameter_v4          s_CameraParameter;          /*!< camera parameter         */
  HLA_t_VehicleParameter_v3         s_VehicleParameter;         /*!< vehicle parameter        */
  HLA_t_SensorSocket                s_SensorSocket;             /*!< sensor socket parameters */
  HLA_t_SensorAngles_v1             s_SensorAngles;             /*!< sensor angles parameters */
  HLA_t_RoiParameter_v2             s_Roi;                      /*!< hla roi parameters       */
} HLAR_t_InputParameters_v6;

typedef struct
{
  HLA_t_CameraParameter_v4          s_CameraParameter;          /*!< camera parameter         */
  HLA_t_VehicleParameter_v4         s_VehicleParameter;         /*!< vehicle parameter        */
  HLA_t_SensorSocket                s_SensorSocket;             /*!< sensor socket parameters */
  HLA_t_SensorAngles_v1             s_SensorAngles;             /*!< sensor angles parameters */
  CPAR_HLA_Parameter_t_v1           s_HlaPar;                   /*!< common hla parameter     */
  CPAR_HLAR_Parameter_t_v1          s_HlarPar;                  /*!< hlar parameter           */
} HLAR_t_InputParameters_v7;

typedef struct
{
  HLA_t_CameraParameter_v4          s_CameraParameter;          /*!< camera parameter         */
  HLA_t_VehicleParameter_v4         s_VehicleParameter;         /*!< vehicle parameter        */
  HLA_t_SensorSocket                s_SensorSocket;             /*!< sensor socket parameters */
  HLA_t_SensorAngles_v2             s_SensorAngles;             /*!< sensor angles parameters */
  CPAR_HLA_Parameter_t_v1           s_HlaPar;                   /*!< common hla parameter     */
  CPAR_HLAR_Parameter_t_v1          s_HlarPar;                  /*!< hlar parameter           */
} HLAR_t_InputParameters_v8;

typedef struct
{
  HLA_t_CameraParameter_v5          s_CameraParameter;          /*!< camera parameter         */
  HLA_t_VehicleParameter_v4         s_VehicleParameter;         /*!< vehicle parameter        */
  HLA_t_SensorSocket                s_SensorSocket;             /*!< sensor socket parameters */
  HLA_t_SensorAngles_v2             s_SensorAngles;             /*!< sensor angles parameters */
  CPAR_HLA_Parameter_t_v1           s_HlaPar;                   /*!< common hla parameter     */
  CPAR_HLAR_Parameter_t_v1          s_HlarPar;                  /*!< hlar parameter           */
} HLAR_t_InputParameters_v9;

typedef struct
{
  HLA_t_CameraParameter_v6          s_CameraParameter;          /*!< camera parameter         */
  HLA_t_VehicleParameter_v4         s_VehicleParameter;         /*!< vehicle parameter        */
  HLA_t_SensorSocket                s_SensorSocket;             /*!< sensor socket parameters */
  HLA_t_SensorAngles_v2             s_SensorAngles;             /*!< sensor angles parameters */
  CPAR_HLA_Parameter_t_v1           s_HlaPar;                   /*!< common hla parameter     */
  CPAR_HLAR_Parameter_t_v1          s_HlarPar;                  /*!< hlar parameter           */
} HLAR_t_InputParameters_v10;

/*! Type definition of the required input signals for HLAR */
/* variable inputs             */
/* not constant during runtime */
typedef struct
{
  HLA_t_Availability_v1                s_Avl;                  /*!< availability signal */
  HLA_t_ImagerState_v1                 s_ImagerState;          /*!< image control state signal */
  HLA_t_MotionState_v1                 s_MotionState;          /*!< vehicle motion state signal */
  HLA_t_HeadlightState_v1              s_HeadlightState;       /*!< head light state signal */
  HLA_t_VehicleState_v1                s_VehicleState;         /*!< vehicle state signal */
  HLA_t_CaliOnline                     s_CaliOnline;           /*!< online calibration */

  HLA_t_DefectPixelList_v1             s_DefectPixelList;      /*!< defect pixel list */
} HLAR_t_InputSignals_v1;

typedef struct
{
  HLA_t_Availability_v1                s_Avl;                  /*!< availability signal */
  HLA_t_ImagerState_v2                 s_ImagerState;          /*!< image control state signal */
  HLA_t_MotionState_v2                 s_MotionState;          /*!< vehicle motion state signal */
  HLA_t_HeadlightState_v1              s_HeadlightState;       /*!< head light state signal */
  HLA_t_VehicleState_v1                s_VehicleState;         /*!< vehicle state signal */
  HLA_t_CaliOnline                     s_CaliOnline;           /*!< online calibration */

  HLA_t_DefectPixelList_v1             s_DefectPixelList;      /*!< defect pixel list */
} HLAR_t_InputSignals_v2;

typedef struct
{
  HLA_t_Availability_v1                s_Avl;                  /*!< availability signal */
  HLA_t_ImagerState_v2                 s_ImagerState;          /*!< image control state signal */
  HLA_t_MotionState_v3                 s_MotionState;          /*!< vehicle motion state signal */
  HLA_t_HeadlightState_v1              s_HeadlightState;       /*!< head light state signal */
  HLA_t_VehicleState_v1                s_VehicleState;         /*!< vehicle state signal */
  HLA_t_CaliOnline                     s_CaliOnline;           /*!< online calibration */

  HLA_t_DefectPixelList_v1             s_DefectPixelList;      /*!< defect pixel list */
} HLAR_t_InputSignals_v3;

typedef struct
{
  HLA_t_Availability_v1                s_Avl;                  /*!< availability signal */
  HLA_t_ImagerState_v2                 s_ImagerState;          /*!< image control state signal */
  HLA_t_MotionState_v3                 s_MotionState;          /*!< vehicle motion state signal */
  HLA_t_HeadlightState_v1              s_HeadlightState;       /*!< head light state signal */
  HLA_t_VehicleState_v2                s_VehicleState;         /*!< vehicle state signal */
  HLA_t_CaliOnline                     s_CaliOnline;           /*!< online calibration */

  HLA_t_DefectPixelList_v1             s_DefectPixelList;      /*!< defect pixel list */
} HLAR_t_InputSignals_v4;

typedef struct
{
  HLA_t_Availability_v1                s_Avl;                  /*!< availability signal */
  HLA_t_ImagerState_v2                 s_ImagerState;          /*!< image control state signal */
  HLA_t_MotionState_v3                 s_MotionState;          /*!< vehicle motion state signal */
  HLA_t_HeadlightState_v1              s_HeadlightState;       /*!< head light state signal */
  HLA_t_VehicleState_v2                s_VehicleState;         /*!< vehicle state signal */
  HLA_t_CaliOnline                     s_CaliOnline;           /*!< online calibration */

  HLA_t_DefectPixelList_v1             s_DefectPixelList;      /*!< defect pixel list */
  HLA_t_TrafficStyle_v1                s_TrafficStyle;         /*!< traffic style results/Read in the eeprom */
} HLAR_t_InputSignals_v5;

typedef struct
{
  HLA_t_Availability_v1             s_Avl;                      /*!< availability signal */
  HLA_t_ImagerState_v3              s_ImagerState;              /*!< image control state signal */
  HLA_t_MotionState_v4              s_MotionState;              /*!< vehicle motion state signal */
  HLA_t_HeadlightState_v1           s_HeadlightState;           /*!< head light state signal */
  HLA_t_VehicleState_v3             s_VehicleState;             /*!< vehicle state signal */
  HLA_t_CaliOnline                  s_CaliOnline;               /*!< online calibration */

  HLA_t_DefectPixelList_v2          s_DefectPixelList;           /*!< defect pixel list */
  HLA_t_TrafficStyle_v1             s_TrafficStyle;              /*!< traffic style results /Read in eeprom */
} HLAR_t_InputSignals_v6;

typedef struct
{
  HLA_t_Availability_v2             s_Avl;                       /*!< availability signal */
  HLA_t_ImagerState_v3              s_ImagerState;               /*!< image control state signal */
  HLA_t_MotionState_v4              s_MotionState;               /*!< vehicle motion state signal */
  HLA_t_HeadlightState_v2           s_HeadlightState;            /*!< head light state signal */
  HLA_t_VehicleState_v3             s_VehicleState;              /*!< vehicle state signal */
  HLA_t_CaliOnline                  s_CaliOnline;                /*!< online calibration */

  HLA_t_DefectPixelList_v3          s_DefectPixelList;           /*!< defect pixel list */
  HLA_t_TrafficStyle_v2             s_TrafficStyle;              /*!< traffic style results /Read in eeprom */
} HLAR_t_InputSignals_v7;

typedef struct
{
  HLA_t_Availability_v2             s_Avl;                       /*!< availability signal */
  HLA_t_ImagerState_v3              s_ImagerState;               /*!< image control state signal */
  HLA_t_MotionState_v4              s_MotionState;               /*!< vehicle motion state signal */
  HLA_t_HeadlightState_v3           s_HeadlightState;            /*!< head light state signal */
  HLA_t_VehicleState_v3             s_VehicleState;              /*!< vehicle state signal */
  HLA_t_CaliOnline                  s_CaliOnline;                /*!< online calibration */

  HLA_t_DefectPixelList_v3          s_DefectPixelList;           /*!< defect pixel list */
  HLA_t_TrafficStyle_v2             s_TrafficStyle;              /*!< traffic style results /Read in eeprom */
} HLAR_t_InputSignals_v8;

typedef struct
{
  HLA_t_Availability_v2             s_Avl;                       /*!< availability signal */
  HLA_t_ImagerState_v4              s_ImagerState;               /*!< image control state signal */
  HLA_t_MotionState_v4              s_MotionState;               /*!< vehicle motion state signal */
  HLA_t_HeadlightState_v3           s_HeadlightState;            /*!< head light state signal */
  HLA_t_VehicleState_v3             s_VehicleState;              /*!< vehicle state signal */
  HLA_t_CaliOnline                  s_CaliOnline;                /*!< online calibration */

  HLA_t_DefectPixelList_v3          s_DefectPixelList;           /*!< defect pixel list */
  HLA_t_TrafficStyle_v2             s_TrafficStyle;              /*!< traffic style results /Read in eeprom */
} HLAR_t_InputSignals_v9;

/*! Type definition of the required input */
typedef struct
{
  uint32                              ui32_InterfaceVersionNumber;/*!< HLAR input interface version number */
  uint32                              ui32_FrameCnt;              /*!< Frame counter */
  HLAR_t_InputParameters_v1           s_Par;                      /*!< input parameters */
  HLAR_t_InputSignals_v1              s_Sig;                      /*!< input signals */
} HLAR_t_RequiredInputs_v1;

/*! Type definition of the required input */
typedef struct
{
  uint32                            ui32_InterfaceVersionNumber;/*!< HLAR input interface version number */
  uint32                            ui32_FrameCnt;              /*!< Frame counter        */
  uint64                            ui64_TimeStamp_HLA_us;      /*!< [us] HLA Timestamp, hla segmentation started, inputs freezed */ 
  uint64                            ui64_TimeStamp_VDY_us;      /*!< [us] VDY Timestamp, vdy ouput data */ 
  uint64                            ui64_TimeStamp_Image_us;    /*!< [us] Image Timestamp */
  uint32                            ui32_VDY_Cnt;               /*!< VDY cycle counter    */
  HLAR_t_InputParameters_v2         s_Par;                      /*!< input parameters     */
  HLAR_t_InputSignals_v2            s_Sig;                      /*!< input signals        */
  HLAR_t_eDebugSwitch_v1            e_DebugSwitch;              /*!< HLAR debug switch    */
} HLAR_t_RequiredInputs_v2;

/*! Type definition of the required input */
typedef struct
{
  uint32                            ui32_InterfaceVersionNumber;/*!< HLAR input interface version number */
  uint32                            ui32_FrameCnt;              /*!< Frame counter        */
  uint64                            ui64_TimeStamp_HLA_us;      /*!< [us] HLA Timestamp, hla segmentation started, inputs freezed */ 
  uint64                            ui64_TimeStamp_VDY_us;      /*!< [us] VDY Timestamp, vdy ouput data */ 
  uint64                            ui64_TimeStamp_Image_us;    /*!< [us] Image Timestamp */
  uint32                            ui32_VDY_Cnt;               /*!< VDY cycle counter    */
  HLAR_t_InputParameters_v3         s_Par;                      /*!< input parameters     */
  HLAR_t_InputSignals_v3            s_Sig;                      /*!< input signals        */
  HLAR_t_eDebugSwitch_v1            e_DebugSwitch;              /*!< HLAR debug switch    */
} HLAR_t_RequiredInputs_v3;

/*! Type definition of the required input */
typedef struct
{
  uint32                            ui32_InterfaceVersionNumber;/*!< HLAR input interface version number */
  uint32                            ui32_FrameCnt;              /*!< Frame counter        */
  uint64                            ui64_TimeStamp_HLA_us;      /*!< [us] HLA Timestamp, hla segmentation started, inputs freezed */ 
  uint64                            ui64_TimeStamp_VDY_us;      /*!< [us] VDY Timestamp, vdy ouput data */ 
  uint64                            ui64_TimeStamp_Image_us;    /*!< [us] Image Timestamp */
  uint32                            ui32_VDY_Cnt;               /*!< VDY cycle counter    */
  HLAR_t_InputParameters_v4         s_Par;                      /*!< input parameters     */
  HLAR_t_InputSignals_v4            s_Sig;                      /*!< input signals        */
  HLAR_t_eDebugSwitch_v1            e_DebugSwitch;              /*!< HLAR debug switch    */
} HLAR_t_RequiredInputs_v4;

/*! Type definition of the required input */
typedef struct
{
  uint32                            ui32_InterfaceVersionNumber;/*!< HLAR input interface version number */
  uint32                            ui32_FrameCnt;              /*!< Frame counter        */
  uint64                            ui64_TimeStamp_HLA_us;      /*!< [us] HLA Timestamp, hla segmentation started, inputs freezed */ 
  uint64                            ui64_TimeStamp_VDY_us;      /*!< [us] VDY Timestamp, vdy ouput data */ 
  uint64                            ui64_TimeStamp_Image_us;    /*!< [us] Image Timestamp */
  uint32                            ui32_VDY_Cnt;               /*!< VDY cycle counter    */
  HLAR_t_InputParameters_v4         s_Par;                      /*!< input parameters     */
  HLAR_t_InputSignals_v5            s_Sig;                      /*!< input signals        */
  HLAR_t_eDebugSwitch_v1            e_DebugSwitch;              /*!< HLAR debug switch    */
} HLAR_t_RequiredInputs_v5;

/*! Type definition of the required input */
typedef struct
{
  uint32                            ui32_InterfaceVersionNumber;/*!< HLAR input interface version number */
  uint32                            ui32_FrameCnt;              /*!< Frame counter        */
  uint64                            ui64_TimeStamp_HLA_us;      /*!< [us] HLA Timestamp, hla segmentation started, inputs freezed */ 
  uint64                            ui64_TimeStamp_VDY_us;      /*!< [us] VDY Timestamp, vdy ouput data */ 
  uint64                            ui64_TimeStamp_Image_us;    /*!< [us] Image Timestamp */
  uint32                            ui32_VDY_Cnt;               /*!< VDY cycle counter    */
  HLAR_t_InputParameters_v5         s_Par;                      /*!< input parameters     */
  HLAR_t_InputSignals_v5            s_Sig;                      /*!< input signals        */
  HLAR_t_eDebugSwitch_v1            e_DebugSwitch;              /*!< HLAR debug switch    */
} HLAR_t_RequiredInputs_v6;

/*! Type definition of the required input */
/* From SMFC4B0 I2I0 release onwards */
typedef struct
{
  uint32                            ui32_InterfaceVersionNumber;/*!< HLAR input interface version number */
  uint32                            ui32_FrameCnt;              /*!< Frame counter        */
  uint64                            ui64_TimeStamp_HLA_us;      /*!< [us] HLA Timestamp, hla segmentation started, inputs freezed */ 
  uint64                            ui64_TimeStamp_VDY_us;      /*!< [us] VDY Timestamp, vdy ouput data */ 
  uint64                            ui64_TimeStamp_Image_us;    /*!< [us] Image Timestamp */
  uint32                            ui32_VDY_Cnt;               /*!< VDY cycle counter    */
  HLAR_t_InputParameters_v6         s_Par;                      /*!< input parameters     */
  HLAR_t_InputSignals_v6            s_Sig;                      /*!< input signals        */
  HLA_t_enum32                      e_OpMode;                   /*!< HLA operation mode */
} HLAR_t_RequiredInputs_v7;

/*! Type definition of the required input */
/* From SMFC4B0 I290 release onwards */
typedef struct
{
  uint32                            ui32_InterfaceVersionNumber; /*!< HLAR input interface version number */
  uint32                            ui32_FrameCnt;               /*!< Frame counter        */
  uint64                            ui64_TimeStamp_HLA_us;       /*!< [us] HLA Timestamp, hla segmentation started, inputs freezed */ 
  uint64                            ui64_TimeStamp_VDY_us;       /*!< [us] VDY Timestamp, vdy ouput data */ 
  uint64                            ui64_TimeStamp_Image_us;     /*!< [us] Image Timestamp */
  uint32                            ui32_VDY_Cnt;                /*!< VDY cycle counter    */
  HLAR_t_InputParameters_v7         s_Par;                       /*!< input parameters     */
  HLAR_t_InputSignals_v7            s_Sig;                       /*!< input signals        */
  HLA_t_enum32                      e_OpMode;                    /*!< HLA operation mode */
} HLAR_t_RequiredInputs_v8;

/*! Type definition of the required input */
/* From SMFC4B0 I300(?) release onwards */
typedef struct
{
  uint32                            ui32_InterfaceVersionNumber; /*!< HLAR input interface version number */
  uint32                            ui32_FrameCnt;               /*!< Frame counter        */
  uint64                            ui64_TimeStamp_HLA_us;       /*!< [us] HLA Timestamp, hla segmentation started, inputs freezed */ 
  uint64                            ui64_TimeStamp_VDY_us;       /*!< [us] VDY Timestamp, vdy ouput data */ 
  uint64                            ui64_TimeStamp_Image_us;     /*!< [us] Image Timestamp */
  uint32                            ui32_VDY_Cnt;                /*!< VDY cycle counter    */
  HLAR_t_InputParameters_v8         s_Par;                       /*!< input parameters     */
  HLAR_t_InputSignals_v8            s_Sig;                       /*!< input signals        */
  HLA_t_enum32                      e_OpMode;                    /*!< HLA operation mode */
} HLAR_t_RequiredInputs_v9;

/*! Type definition of the required input */
/* From SMFC4B0 I310 release onwards */
typedef struct
{
  uint32                            ui32_InterfaceVersionNumber; /*!< HLAR input interface version number */
  uint32                            ui32_FrameCnt;               /*!< Frame counter        */
  uint64                            ui64_TimeStamp_HLA_us;       /*!< [us] HLA Timestamp, hla segmentation started, inputs freezed */ 
  uint64                            ui64_TimeStamp_VDY_us;       /*!< [us] VDY Timestamp, vdy ouput data */ 
  uint64                            ui64_TimeStamp_Image_us;     /*!< [us] Image Timestamp */
  uint32                            ui32_VDY_Cnt;                /*!< VDY cycle counter    */
  HLAR_t_InputParameters_v9         s_Par;                       /*!< input parameters     */
  HLAR_t_InputSignals_v8            s_Sig;                       /*!< input signals        */
  HLA_t_enum32                      e_OpMode;                    /*!< HLA operation mode */
} HLAR_t_RequiredInputs_v10;

/*! Type definition of the required input */
/* From SMFC4B0 I310 release onwards */
typedef struct
{
  uint32                            ui32_InterfaceVersionNumber; /*!< HLAR input interface version number */
  uint32                            ui32_FrameCnt;               /*!< Frame counter        */
  uint64                            ui64_TimeStamp_HLA_us;       /*!< [us] HLA Timestamp, hla segmentation started, inputs freezed */ 
  uint64                            ui64_TimeStamp_VDY_us;       /*!< [us] VDY Timestamp, vdy ouput data */ 
  uint64                            ui64_TimeStamp_Image_us;     /*!< [us] Image Timestamp */
  uint32                            ui32_VDY_Cnt;                /*!< VDY cycle counter    */
  HLAR_t_InputParameters_v9         s_Par;                       /*!< input parameters     */
  HLAR_t_InputSignals_v8            s_Sig;                       /*!< input signals        */
} HLAR_t_RequiredInputs_v11;

/*! Type definition of the required input */
typedef struct
{
  uint32                  ui32_InterfaceVersionNumber;/*!< HLAR input interface version number */
  uint16                  uiFrameCnt;                 /*!< Frame counter        */
  uint32                  uiTimeStamp_HLA_us;         /*!< [us] HLA Timestamp, hla segmentation started, inputs freezed */ 
  uint32                  uiTimeStamp_VDY_us;         /*!< [us] VDY Timestamp, vdy ouput data */ 
  uint32                  uiTimeStamp_Image_us;       /*!< [us] Image Timestamp */
  uint16                  uiVDY_Cnt;                  /*!< VDY cycle counter    */
  HLAR_t_InputParameters_v10 s_Par;                      /*!< input parameters     */
  HLAR_t_InputSignals_v9     s_Sig;                      /*!< input signals        */
} HLAR_t_RequiredInputs_v12;