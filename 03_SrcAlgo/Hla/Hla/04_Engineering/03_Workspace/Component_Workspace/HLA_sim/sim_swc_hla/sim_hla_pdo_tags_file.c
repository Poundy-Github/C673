/*! \file **********************************************************************

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 HLA

  MODULNAME:                 sim_hla_pdo_tags_file.c

  DESCRIPTION:               Contains type re-definitions for sdl file generation

  AUTHOR:                    Matthias Mutschler

  CREATION DATE:             01.04.2014

  VERSION:                   $Revision: 1.3 $


  ---*/ /*---
  CHANGES:                   $Log: sim_hla_pdo_tags_file.c  $
  CHANGES:                   Revision 1.3 2019/04/05 17:03:27CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                   - Move error/warning/information arrays at the end of error stack type
  CHANGES:                   - Align next measfreeze after error stack so that it got not corrupted in case of problems with error stack measfreeze
  CHANGES:                   - Removed ADB port measfreeze stuff as no longer needed
  CHANGES:                   Revision 1.2 2017/10/27 13:49:46CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                   Updated mainstream repo to AL_HLA_06.03.02_INT-0
  CHANGES:                   Revision 2.3 2017/10/10 13:45:12CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                   Typo
  CHANGES:                   Revision 2.2 2017/09/07 15:13:49CEST Fischer, Alexander (uidv8778) 
  CHANGES:                   Switch from LdOutputData_t to AbdOutputData_t
  CHANGES:                   
  CHANGES:                   Reviewed by Matthias Mutschler
  CHANGES:                   Revision 2.1 2017/06/21 15:53:20CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                   Backport changes from R6.2_lib0 branch
  CHANGES:                   Revision 2.0 2017/02/27 10:16:25CET Mutschler, Matthias (uidv7867) 
  CHANGES:                   Adapt sim/vis to work with LSD but
  CHANGES:                   visualization parts are switched off, mainly.
  CHANGES:                   Revision 1.13 2016/11/18 13:39:56CET Mutschler, Matthias (uidv7867) 
  CHANGES:                   Adapt to RTE version SW_COMMON_161111_MFC431_RTE:
  CHANGES:                   - Replaced HlaSignals and Headlightstate reqports by HlaBusInputSignals
  CHANGES:                   - Split CPAR HLA parameters
  CHANGES:                   - Clean-up of CPARS -> more internal parameters
  CHANGES:                   Revision 1.12 2016/11/11 15:33:33CET Mutschler, Matthias (uidv7867) 
  CHANGES:                   Removed oddSat request port
  CHANGES:                   Revision 1.11 2016/09/23 11:34:43CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                   Adapt names according to convention
  CHANGES:                   Revision 1.10 2016/09/23 10:04:06CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                   - Measfreeze req ports in SIL
  CHANGES:                   - Change vaddr of measfreeze to be calculated automatically
  CHANGES:                   Revision 1.9 2016/05/18 12:41:22CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                   Use RTA for runtime measurement
  CHANGES:                   Revision 1.8 2016/04/08 10:13:23CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                   Added color seg measfreeze to sdl file for PC_SIM and EVAL_BOARD
  CHANGES:                   Revision 1.7 2016/04/05 18:17:03CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                   Support for MFC431 R4.0 RTE
  CHANGES:                   Revision 1.6 2015/01/15 13:14:08CET Stark-EXT, Roland (uidw1169) 
  CHANGES:                   Enable RTA Tooling for EVM HIL.
  CHANGES:                   - Added comments -  uidw1169 [Jan 15, 2015 1:14:09 PM CET]
  CHANGES:                   Change Package : 296155:1 http://mks-psad:7002/im/viewissue?selection=296155
  CHANGES:                   Revision 1.5 2014/11/27 11:30:04CET Mutschler, Matthias (uidv7867) 
  CHANGES:                   Added time meas for color segmentation
  CHANGES:                   Visualized color segmentation results of EVM HIL
  CHANGES:                   --- Added comments ---  uidv7867 [Nov 27, 2014 11:30:04 AM CET]
  CHANGES:                   Change Package : 274754:2 http://mks-psad:7002/im/viewissue?selection=274754
  CHANGES:                   Revision 1.4 2014/06/16 08:48:36CEST Fischer, Alexander (uidv8778) 
  CHANGES:                   Renamed SystemInfoState
  CHANGES:                   --- Added comments ---  uidv8778 [Jun 16, 2014 8:48:37 AM CEST]
  CHANGES:                   Change Package : 241200:1 http://mks-psad:7002/im/viewissue?selection=241200
  CHANGES:                   Revision 1.3 2014/04/23 18:16:32CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                   Removed auto_eval
  CHANGES:                   Removed old hlaf (plus/standard/light/spotlight)
  CHANGES:                   --- Added comments ---  uidv7867 [Apr 23, 2014 6:16:33 PM CEST]
  CHANGES:                   Change Package : 207432:73 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                   Revision 1.2 2014/04/10 16:44:09CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                   Added cycle trigger in simu
  CHANGES:                   Fixed compiler warnings
  CHANGES:                   Fixed chain of light time meas
  CHANGES:                   Fixed internal measfreezes to HIL
  CHANGES:                   --- Added comments ---  uidv7867 [Apr 10, 2014 4:44:10 PM CEST]
  CHANGES:                   Change Package : 207432:59 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                   Revision 1.1 2014/04/03 10:17:14CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/03_Workspace/algo/hla_sim/sim_swc_hla/project.pj

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/


#ifdef __PDO__

/* Include header files where all to-be-measfreezed types are defined */
#include "sim_hla_measfreeze_data.h"

/* SIL measfreezes */
typedef CPAR_HLAF_Parameter_t        PdoSilHlaReqPortCparHlafPar;        /*!< @vaddr: SIL_HLA_MEAS_VADDR_REQ_PORT_CPAR_HLAF_PAR          @cycleid: HLA_ENV_SIM @vname: SilHlaReqPortCparHlafPar */
typedef MonoCalibration_t            PdoSilHlaReqPortMonoCalibration;    /*!< @vaddr: SIL_HLA_MEAS_VADDR_REQ_PORT_MONO_CALI              @cycleid: HLA_ENV_SIM @vname: SilHlaReqPortMonoCalibration */
typedef HLA_BusInputSignals_t        PdoSilHlaReqPortHlaBusInputSignals; /*!< @vaddr: SIL_HLA_MEAS_VADDR_REQ_PORT_HLA_BUS_INPUT_SIGNALS  @cycleid: HLA_ENV_SIM @vname: SilHlaReqPortHlaBusInputSignals */
typedef VehSig_t                     PdoSilHlaReqPortVehSig;             /*!< @vaddr: SIL_HLA_MEAS_VADDR_REQ_PORT_VEH_SIG                @cycleid: HLA_ENV_SIM @vname: SilHlaReqPortVehSig */
typedef VehDyn_t                     PdoSilHlaReqPortVehDyn;             /*!< @vaddr: SIL_HLA_MEAS_VADDR_REQ_PORT_VDY_DATA               @cycleid: HLA_ENV_SIM @vname: SilHlaReqPortVehDyn */
typedef CB_t_ProvidedOutputs_t       PdoSilHlaReqPortBlockageOutputs;    /*!< @vaddr: SIL_HLA_MEAS_VADDR_REQ_PORT_BLOCKAGE_OUTPUTS       @cycleid: HLA_ENV_SIM @vname: SilHlaReqPortBlockageOutputs */
typedef EM_t_GenObjectList           PdoSilHlaReqPortEMObjectList;       /*!< @vaddr: SIL_HLA_MEAS_VADDR_REQ_PORT_EM_OBJECT_LIST         @cycleid: HLA_ENV_SIM @vname: SilHlaReqPortEMObjectList */
typedef LdOutputData_t               PdoSilHlaReqPortLDOutput;           /*!< @vaddr: SIL_HLA_MEAS_VADDR_REQ_PORT_LD_OUT                 @cycleid: HLA_ENV_SIM @vname: SilHlaReqPortLDOutput */
typedef LSD_EnvironmentData_t        PdoSilHlaReqPortLsdEnvironmentData; /*!< @vaddr: SIL_HLA_MEAS_VADDR_REQ_PORT_LSD_ENVIRONMENT_DATA   @cycleid: HLA_ENV_SIM @vname: SilHlaReqPortLsdEnvironmentData */
typedef LSD_LightObjectList_t        PdoSilHlaReqPortLsdLightObjectList; /*!< @vaddr: SIL_HLA_MEAS_VADDR_REQ_PORT_LSD_LIGHT_OBJECT_LIST  @cycleid: HLA_ENV_SIM @vname: SilHlaReqPortLsdLightObjectList */
                                                                      
/* HIL measfreezes */
typedef AlgoCompState_t              PdoHilHlaProPortAlgoCompState;      /*!< @vaddr: HIL_HLA_MEAS_VADDR_ALGO_COMP_STATE                 @cycleid: HLA_ENV_SIM @vname: HilHlaProPortAlgoCompState */
                                                                                                                                         
typedef AS_t_RtaBuffer               PdoHilHlaRtaBuffer;                 /*!< @vaddr: HIL_HLA_MEAS_VADDR_RTA_BUFFER                      @cycleid: HLA_ENV_SIM @vname: HilHlaRtaBuffer */
typedef AS_t_RtaBuffer               PdoHilHlaRtaBufferEve;              /*!< @vaddr: HIL_HLA_MEAS_VADDR_RTA_BUFFER_EVE                  @cycleid: HLA_ENV_SIM @vname: HilHlaRtaBufferEve */

#endif /* __PDO__ */

static void HlaPdoDummyForCompiler (void) {}
