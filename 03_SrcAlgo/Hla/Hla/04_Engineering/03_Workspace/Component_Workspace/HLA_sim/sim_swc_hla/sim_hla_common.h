/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  CPU:                    TI VME

  COMPONENT:              HLA

  MODULNAME:              sim_hla_common.h

  DESCRIPTION:            Common definitions across simulation and visualization

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          21-11-2014

  VERSION:                $Revision: 1.9.1.1 $

  ---*/ /*---
  CHANGES:                $Log: sim_hla_common.h  $
  CHANGES:                Revision 1.9.1.1 2019/06/05 14:27:38CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed MFC5xx stuff
  CHANGES:                Revision 1.9 2019/02/01 23:46:55CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Include hla_defs.h instead of hla_ext.h/hla_type.h
  CHANGES:                Revision 1.8 2018/10/31 10:15:43CET Fischer, Alexander (uidv8778) 
  CHANGES:                adapt to MFC5XX set-up
  CHANGES:                
  CHANGES:                Reviewed by Alexander Manz
  CHANGES:                Revision 1.7 2018/10/24 13:46:26CEST Fischer, Alexander (uidv8778) 
  CHANGES:                Adapt port naming to mfc5xx project
  CHANGES:                Revision 1.6 2018/08/06 10:33:18CEST Fischer, Alexander (uidv8778) 
  CHANGES:                Added input port for radar objects
  CHANGES:                
  CHANGES:                Reviewed by Alexander Manz
  CHANGES:                Revision 1.5 2018/03/12 14:29:19CET Fischer, Alexander (uidv8778) 
  CHANGES:                remove LD/ABD input ports
  CHANGES:                
  CHANGES:                Reviewed by Matthias Mutschler
  CHANGES:                Revision 1.4 2018/02/22 15:00:22CET Fischer, Alexander (uidv8778) 
  CHANGES:                Added LSD pLightList port as an input to HLA
  CHANGES:                - input checks
  CHANGES:                - visu update
  CHANGES:                
  CHANGES:                Reviewed by Matthias Mutschler
  CHANGES:                Revision 1.3 2017/10/27 13:49:45CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated mainstream repo to AL_HLA_06.03.02_INT-0
  CHANGES:                Revision 2.3 2017/09/07 15:12:56CEST Fischer, Alexander (uidv8778) 
  CHANGES:                Switch from LdOutputData_t to AbdOutputData_t
  CHANGES:                
  CHANGES:                Reviewed by Matthias Mutschler
  CHANGES:                Revision 2.2 2017/06/21 15:53:19CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Backport changes from R6.2_lib0 branch
  CHANGES:                Revision 2.1 2017/03/15 13:33:23CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixes to HLA running
  CHANGES:                Revision 2.0 2017/02/27 10:16:29CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Adapt sim/vis to work with LSD but
  CHANGES:                visualization parts are switched off, mainly.
  CHANGES:                Revision 1.23 2016/11/22 17:05:49CET Mutschler, Matthias (uidv7867) 
  CHANGES:                CamRot goes object orientated programming
  CHANGES:                Revision 1.22 2016/11/18 13:39:53CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Adapt to RTE version SW_COMMON_161111_MFC431_RTE:
  CHANGES:                - Replaced HlaSignals and Headlightstate reqports by HlaBusInputSignals
  CHANGES:                - Split CPAR HLA parameters
  CHANGES:                - Clean-up of CPARS -> more internal parameters
  CHANGES:                Revision 1.21 2016/11/11 15:33:30CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed oddSat request port
  CHANGES:                Revision 1.20 2016/10/14 16:43:50CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Adapt algo to be ANSI-C compliant (for VS 2005 Compiler) -> No longer compile c files as c++ for simulation dll
  CHANGES:                Remove includes of external headers besides algo_glob.h
  CHANGES:                Adapt to generated interface hla_ext.h
  CHANGES:                Revision 1.19 2016/09/22 12:56:46CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Code clean-up:
  CHANGES:                - Removed internal input interface and use request ports directly
  CHANGES:                - Removed debouncing of request ports
  CHANGES:                - Header file includes aligned
  CHANGES:                - Removed VDYOffsets port as no longer needed
  CHANGES:                - Smaller clean-up like usage of curvature instead of own implementation, etc.
  CHANGES:                
  CHANGES:                Reviewed by Alexander Fischer
  CHANGES:                Revision 1.18 2016/08/25 14:10:13CEST Fischer, Alexander (uidv8778) 
  CHANGES:                Use OD output for faster detection of overtaking cars
  CHANGES:                - Added OD input port to interface
  CHANGES:                - set turn off reason in hlaf in case of relevant OD object was found
  CHANGES:                - added relevant OD objects to visu
  CHANGES:                
  CHANGES:                - if wiper state is not available HLA is still running
  CHANGES:                
  CHANGES:                Reviewed by Patrick Schillinger
  CHANGES:                Revision 1.17 2016/08/19 22:50:30CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Implemented new DEM event handling
  CHANGES:                
  CHANGES:                Reviewed by Patrick Schillinger
  CHANGES:                Revision 1.16 2016/08/19 16:52:14CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Replaced system info by new error stack
  CHANGES:                Implemented new NVM handling
  CHANGES:                Implemented missing input checks
  CHANGES:                Implemented soft error state
  CHANGES:                
  CHANGES:                Reviewed by Alexander Fischer
  CHANGES:                Revision 1.15 2016/08/12 08:31:41CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for RTE from 160805 
  CHANGES:                Implemeted architectural changes
  CHANGES:                - Removed busdebugdata port and diagnose messages
  CHANGES:                - Changed input checks
  CHANGES:                - Clean-up of wrapper files
  CHANGES:                
  CHANGES:                Reviewed by Alexander Fischer
  CHANGES:                Revision 1.14 2016/05/18 12:41:56CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Use RTA for runtime measurement
  CHANGES:                Revision 1.13 2016/04/05 18:17:01CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Support for MFC431 R4.0 RTE
  CHANGES:                Revision 1.12 2015/12/17 13:25:51CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Trunk clean-up:
  CHANGES:                - Removed all project specific stuff besides MFC411/MFC431
  CHANGES:                - Configured trunk as HLA base project
  CHANGES:                - Clean-up of internal interface
  CHANGES:                - Re-structured hla_defs.h
  CHANGES:                Revision 1.11 2015/09/08 14:20:15CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Replace LD cali by MEMO cali
  CHANGES:                - Added comments -  uidv7867 [Sep 8, 2015 2:20:16 PM CEST]
  CHANGES:                Change Package : 234060:257 http://mks-psad:7002/im/viewissue?selection=234060
  CHANGES:                Revision 1.10 2015/09/07 16:20:17CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Removed support for color seg on both odd and even image
  CHANGES:                Centralized decision on which color seg level we run
  CHANGES:                Enhancements to color seg visu
  CHANGES:                --- Added comments ---  uidv7867 [Sep 7, 2015 4:20:18 PM CEST]
  CHANGES:                Change Package : 359571:1 http://mks-psad:7002/im/viewissue?selection=359571
  CHANGES:                Revision 1.9 2015/09/01 13:21:47CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Activate stereo object list only for MFC403BW16 project
  CHANGES:                --- Added comments ---  uidv7867 [Sep 1, 2015 1:21:48 PM CEST]
  CHANGES:                Change Package : 234060:254 http://mks-psad:7002/im/viewissue?selection=234060
  CHANGES:                Revision 1.8 2015/07/31 14:32:01CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Make use of CIPP's sat even image
  CHANGES:                --- Added comments ---  uidv7867 [Jul 31, 2015 2:32:02 PM CEST]
  CHANGES:                Change Package : 359573:1 http://mks-psad:7002/im/viewissue?selection=359573
  CHANGES:                Revision 1.7 2015/06/09 14:23:21CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Re-enabled evenSatImage port
  CHANGES:                --- Added comments ---  uidv7867 [Jun 9, 2015 2:23:21 PM CEST]
  CHANGES:                Change Package : 234060:66 http://mks-psad:7002/im/viewissue?selection=234060
  CHANGES:                Revision 1.6 2015/06/02 14:07:29CEST Fischer, Alexander (uidv8778) 
  CHANGES:                commented pInputImageEvenSat pointer
  CHANGES:                -> to check if this is needed in the future
  CHANGES:                --- Added comments ---  uidv8778 [Jun 2, 2015 2:07:29 PM CEST]
  CHANGES:                Change Package : 234060:204 http://mks-psad:7002/im/viewissue?selection=234060
  CHANGES:                Revision 1.5 2015/05/26 10:16:31CEST Fischer, Alexander (uidv8778) 
  CHANGES:                fixed missing image pointer in SimHlaReqPrtList_t
  CHANGES:                Revision 1.4 2015/03/24 16:18:52CET Schillinger, Patrick (uidv8776) 
  CHANGES:                include LD output into HLA
  CHANGES:                --- Added comments ---  uidv8776 [Mar 24, 2015 4:18:53 PM CET]
  CHANGES:                Change Package : 234060:9 http://mks-psad:7002/im/viewissue?selection=234060
  CHANGES:                Revision 1.3 2015/03/16 17:26:20CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added even image IC port
  CHANGES:                --- Added comments ---  uidv7867 [Mar 16, 2015 5:26:21 PM CET]
  CHANGES:                Change Package : 312470:1 http://mks-psad:7002/im/viewissue?selection=312470
  CHANGES:                Revision 1.2 2014/11/24 14:27:35CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Moved generic parts from sim_hla_mease.h to sim_hla_common.h
  CHANGES:                --- Added comments ---  uidv7867 [Nov 24, 2014 2:27:35 PM CET]
  CHANGES:                Change Package : 234060:66 http://mks-psad:7002/im/viewissue?selection=234060
  CHANGES:                Revision 1.1 2014/11/24 09:18:18CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/03_Workspace/algo/hla_sim/sim_swc_hla/project.pj
**************************************************************************** */

#ifndef SIM_HLA_COMMON_H
#define SIM_HLA_COMMON_H

#include "hla_defs.h"
#include "hlaf_matrix.h"
#include "hla_errorhandling.h"
#include "rtatype.h"


/*****************************************************************************
  MACROS 
*****************************************************************************/

#define IMAGE_MAX_NUM_PIXEL (1300 * 1000)
#define IMAGE_MAX_NUM_PIXEL_SUBSAMPLED (IMAGE_MAX_NUM_PIXEL / 4)

#define CONV_I32VERSION_TO_TUPPLE(x)   (((x) >> 16) & 0xFF), (((x) >> 8) & 0xFF), ((x) & 0xFF)

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
/* pointer list to internal data */
typedef struct
{
  /* Error stack */
  const t_ErrorHandling_ErrorStack* pHlaErrorStack; /* hla_errorhandling.c */

  /* HLAF  */
  HLAFData_t*                 pHlafData; /*hlaf.c*/

  /* HIL time measurement */
  AS_t_RtaBuffer*             pRtaBuffer;
  AS_t_RtaBuffer*             pRtaBufferEve;
} SimHlaInternMeasdataList_t;

/* buffer for internal data */
typedef struct
{
  /* Error stack */
  t_ErrorHandling_ErrorStack HlaErrorStack; /* hla_errorhandling.c */

  /* HLAF  */
  HLAFData_t                 HlafData; /*hlaf.c*/
} SimHlaInternMeasdataBuffers_t;

/* Redefinition of RTE request port list without const qualifier */
/* !!! Attention: this struct must look exactly like the one from the hla_ext.h file !!! */
typedef struct
{
  BaseCtrlData_t*            pBaseCtrlData;           /* Contains operations mode for HLA */
  CB_t_ProvidedOutputs_t*    pCbOutputs;              /* blockage data */
  CPAR_HLAF_Parameter_t*     pCPar_HlafPar;           /* coding parameters stored in special section on ICU: hlaf parameter */  
  EM_t_GenObjectList*        pGenObjectList;          /* EM Object list data */
  HLA_BusInputSignals_t*     pHlaBusInputSignals;     /* Bus signals from ICU: Hla specific ones */
  HLA_RadarObjectList_t*     pHlaRadarObjectList; 
  LSD_EnvironmentData_t*     pLsdEnvironmentData;
  LSD_LightList_t*           pLsdLightList;
  LSD_LightObjectList_t*     pLsdLightObjectList;
  MonoCalibration_t*         pMonoCalibration;        /* mono calibration data */ /* NEW CALI */
  VehDyn_t*                  pVehDyn;                 /* Bus signals from ICU: vehicle dynamic data */  
  VehSig_t*                  pVehSig;                 /* Bus signals from ICU: vehicle signals like raw yawrate, steering wheel angle, ... */
} SimHlaReqPrtList_t;

/* Big buffer that contains whole RTE request port buffers */
typedef struct
{
  BaseCtrlData_t            BaseCtrlData;                   /* Contains operations mode for HLA */
  CB_t_ProvidedOutputs_t    Sig_Blockage;                   /* blockage data */
  CPAR_HLAF_Parameter_t     CPar_HlafPar;                   /* coding parameters stored in special section on ICU: hlaf parameter */  
  EM_t_GenObjectList        Sig_EMObjectsList;              /* EM Object list data */
  HLA_BusInputSignals_t     HlaBusInputSignals;             /* Bus signals from ICU: Hla specific ones */
  HLA_RadarObjectList_t     HlaRadarObjectList; 
  LSD_EnvironmentData_t     LsdEnvironmentData;
  LSD_LightObjectList_t     LsdLightObjectList;
  LSD_LightList_t           LsdLightList;
  MonoCalibration_t         Sig_MonoCalibration;            /* mono calibration data */ /* NEW CALI */
  VehDyn_t                  SigVeh_VDYData;                 /* Bus signals from ICU: vehicle dynamic data */  
  VehSig_t                  SigVeh_VehSig;                  /* Bus signals from ICU: vehicle signals like raw yawrate, steering wheel angle, ... */
} SimHlaReqPrtBuffers_t;

/* Redefinition of RTE provide port list with const qualifier to ensure that no one overwrites ECU outputs*/
typedef struct
{
  const AlgoCompState_t*              pAlgoCompState;               /* Feedback to global scheduler (GS): HLA state (errors, etc.), AlgoVersionNumber */
  const RTE_HLAF_HeadlightControl_t*  pHlaf_HeadlightControl;       /* Bus signals to ICU: head light control data */  
} SimHlaProPrtList_t;

/* Big buffer that contains whole RTE provide port buffers */
typedef struct  
{
  AlgoCompState_t                   AlgoCompState;
  RTE_HLAF_HeadlightControl_t       Hlaf_HeadlightControl;
} SimHlaProPrtBuffers_t;


#endif /* SIM_HLA_COMMON_H */
