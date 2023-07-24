/*! \file **********************************************************************

  COMPANY:         Continental Temic, PC DAS, A.D.C. GmbH

  PROJECT:         Simulation

  CPU:             All

  COMPONENT:       Adapter

  MODULNAME:       sim_adapter_cfg.h

  DESCRIPTION:     configuration file for adapter components:
                   - parameters and switches which effect several components

  CREATION DATE:   29.01.2014

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_adapter_cfg.h  $
  CHANGES:         Revision 1.1 2021/12/13 17:21:28CET Wang, David (Wangd3) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/include/project.pj
  CHANGES:         Revision 1.1 2017/08/10 13:15:27CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/include/project.pj
  CHANGES:         Revision 1.4.1.3 2017/04/04 06:41:17CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         + Introducing project switches
  CHANGES:         * active switch ARS430BW18, transfer from sim_conv_fct_cam_lane_input_data.cpp
  CHANGES:         Revision 1.4.1.2 2017/02/15 15:55:40CET Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         [ARS510/SRR520] Update SimAdapter for the interface changes caused by removal of Elevation feature in SRR520
  CHANGES:         Revision 1.4.1.1 2016/09/13 10:14:55CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         Update Simulation adapters and Simulation plugin for ARS510
  CHANGES:         Revision 1.4 2014/09/19 16:35:31CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         ALN_BASE_AutomaticAlignmentAvailable
  CHANGES:         - Added comments -  uidv7098 [Sep 19, 2014 4:35:32 PM CEST]
  CHANGES:         Change Package : 215877:1 http://mks-psad:7002/im/viewissue?selection=215877
  CHANGES:         Revision 1.3 2014/04/11 13:33:32CEST Diewald, Fabian (uidt8878) 
  CHANGES:         added ALN_SimInitMon adapter
  CHANGES:         --- Added comments ---  uidt8878 [Apr 11, 2014 1:33:32 PM CEST]
  CHANGES:         Change Package : 230351:2 http://mks-psad:7002/im/viewissue?selection=230351
  CHANGES:         Revision 1.2 2014/04/04 11:29:05CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         initial version for Entry
  CHANGES:         --- Added comments ---  uidv7098 [Apr 4, 2014 11:29:06 AM CEST]
  CHANGES:         Change Package : 215877:1 http://mks-psad:7002/im/viewissue?selection=215877
  CHANGES:         Revision 1.1 2014/01/29 15:14:30CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/include/project.pj

**************************************************************************** */
#pragma once

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! Switch conditions for PDO tool */
#define SWITCH_ON                      1
#define SWITCH_OFF                     0

#define CFG_ARS510_SWITCH              (SWITCH_ON)
#define CFG_SRR520_SWITCH              (SWITCH_OFF)
#define CFG_ARS400_EN_SWITCH           (SWITCH_ON)
#define CFG_ARS400_PP_SWITCH           (SWITCH_OFF)
#define CFG_ARS400_PR_SWITCH           (SWITCH_OFF)

/* true if sensor type is one of the ARS400 family */
#define ARS_SWITCH                     ((CFG_ARS400_PP_SWITCH == SWITCH_ON) || (CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_EN_SWITCH == SWITCH_ON))

/* Switches for individual projects*/
/* Origin of the switches: http://ims-adas:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/00_CodeGen/algo/fct/project.pj&selection=fct_interface_types.xls&revision=1.480 Sheet: Generator Line 50 CamLaneInputData*/
/* Not relevant for ARS510 */
#define ARS430BW18 (SWITCH_ON)
#define ARS4A0 (SWITCH_OFF)
#define ARS4B0 (SWITCH_OFF)
#define ARS4E0 (SWITCH_OFF)
#define ARS4J0 (SWITCH_OFF)
#define ARS4R0 (SWITCH_OFF)
#define ARS4T0 (SWITCH_OFF)
#define ARS410RT28 (SWITCH_OFF)
#define ARS410HI17 (SWITCH_OFF)
#define ARS410VWBERTRAM (SWITCH_OFF)
#define ARS410EUNCAP (SWITCH_OFF)

/*! Configuration switch enabling SRR code*/
#define SRR_SWITCH                     (SWITCH_OFF)

/*! Global switch for enabling EM/FCT code for fusion of camera and radar data. */
#define ALGO_CFG_CameraRadarFusion     (SWITCH_ON)
#define CFG_CAMERA_RADAR_FUSION        ALGO_CFG_CameraRadarFusion

/* true if code is generated for ARS400 B0 sample */
#define ALGO_ARS400_B0_Sample          (SWITCH_OFF)

/* true if separate far scan cluster lists are available */
#define ALGO_CFG_FarScanAvailable      ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))

/* defines different for sensors (Entry, Premium, ...) */
#define CFG_ALN_MON_PATH_COMP_ELEV_ANY        (SWITCH_ON)
#if ((CFG_ARS510_SWITCH == SWITCH_ON) || (CFG_SRR520_SWITCH == SWITCH_ON))
#define ALN_MON_PATH_COMP_u_NOF_CHANNELS_MAX  (12u)
#else
#define ALN_MON_PATH_COMP_u_NOF_CHANNELS_MAX  (6u)
#endif
#define ALN_MON_PATH_COMP_u_NOF_SCANS         (1u)
#define ALN_MON_PATH_u_SCANELFEAT_NOF         (1u)
#define SYS_NUM_OF_SCANS                      (1)
#define ALN_BASE_ServiceAlignmentAvailable    (SWITCH_ON)
#define ALN_BASE_AutomaticAlignmentAvailable  (SWITCH_ON)
#define True                                  (1)
#define False                                 (0)
