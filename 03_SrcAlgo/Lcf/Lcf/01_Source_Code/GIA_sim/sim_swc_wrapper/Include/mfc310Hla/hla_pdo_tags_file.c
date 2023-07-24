/*! \file **********************************************************************

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 HLA

  MODULNAME:                 hla_pdo_tags_file.c

  DESCRIPTION:               Contains type re-definitions for sdl file generation

  AUTHOR:                    Matthias Mutschler

  CREATION DATE:             12.12.2013

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   $Log: hla_pdo_tags_file.c  $
  CHANGES:                   Revision 1.1 2021/12/13 17:26:33CET Wang, David (Wangd3) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGES:                   Revision 1.0 2017/03/03 10:37:46CET Sorge, Sven (uidg3181) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/project.pj
  CHANGES:                   Revision 1.1 2014/04/17 16:05:09CEST Sorge, Sven (uidg3181) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/project.pj
  CHANGES:                   Revision 1.5 2014/03/28 10:04:41CET Mutschler, Matthias (uidv7867) 
  CHANGES:                   Removed scons warnings
  CHANGES:                   Removed compiler warnings
  CHANGES:                   --- Added comments ---  uidv7867 [Mar 28, 2014 10:04:42 AM CET]
  CHANGES:                   Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                   Revision 1.4 2014/02/11 09:20:13CET Mutschler, Matthias (uidv7867) 
  CHANGES:                   Fixed time meas
  CHANGES:                   Fixed dframe calculation on HIL
  CHANGES:                   --- Added comments ---  uidv7867 [Feb 11, 2014 9:20:13 AM CET]
  CHANGES:                   Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                   Revision 1.3 2014/02/06 16:02:51CET Mutschler, Matthias (uidv7867) 
  CHANGES:                   Refactoring of hla debug output (time meas, removed redundant stuff)
  CHANGES:                   Centralized Null pointer checks
  CHANGES:                   Refactored dframe calculation
  CHANGES:                   --- Added comments ---  uidv7867 [Feb 6, 2014 4:02:51 PM CET]
  CHANGES:                   Change Package : 214576:1 http://mks-psad:7002/im/viewissue?selection=214576
  CHANGES:                   Revision 1.2 2014/01/23 10:41:33CET Brunn, Marcus (brunnm) 
  CHANGES:                   -added #include "hla_wrpinputs.h"
  CHANGES:                   --- Added comments ---  brunnm [Jan 23, 2014 10:41:33 AM CET]
  CHANGES:                   Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGES:                   Revision 1.1 2013/12/13 16:44:52CET Mutschler, Matthias (uidv7867) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/


#ifdef __PDO__

/* Include header files where all to-be-measfreezed types are defined */
#include "Rte_Ext_Type.h"
#include "hla_wrpinputs.h"
#include "hla_defs.h"
#include "hla_wrp.h"
#include "hlar_ext.h"
#include "hlaf_ext.h"
#include "hlaf_debug.h"
#include "hlaf_light.h"
#include "hlaf_standard.h"
#include "hlaf_matrix.h"
#include "hlaf_plus.h"
#include "hla_imager.h"
#include "hla_debug.h"
#include "hla_segmentation.h"
#include "hla_trackutils.h"
#include "hla_analysisicon.h"

/* Re-define to-be-measfreezed types */
typedef BaseCtrlData_t                 PdoHlaBaseCtrlData;            /*!< @vaddr: RTE_HLA_MEAS_VADDR_BSW_CTRL_DATA @cycleid: HLA_ENV_PVT @vname: HlaBaseCtrlData */      
typedef NVM_HLAR_LearningValues_t      PdoHlarNvmLearningValues;      /*!< @vaddr: RTE_HLA_MEAS_VADDR_NVM_LEARN_VALUES_IN @cycleid: HLA_ENV_PVT @vname: HlarNvmLearningValues*/
typedef RTE_HLAF_NightView_t           PdoHlafNightView;              /*!< @vaddr: RTE_HLA_MEAS_VADDR_NIGHT_VIEW_IN @cycleid: HLA_ENV_PVT @vname: HlafNightView */
typedef BusDebugData_t                 PdoHlaBusDebugData;            /*!< @vaddr: RTE_HLA_MEAS_VADDR_BUS_DEBUG_DATA @cycleid: HLA_ENV_PVT @vname: HlaBusDebugData */
typedef AlgoCompState_t                PdoHlaAlgoCompState;           /*!< @vaddr: RTE_HLA_MEAS_VADDR_ALGO_COMP_STATE @cycleid: HLA_ENV_PVT @vname: HlaAlgoCompState */
typedef HLA_SyncRef_t                  PdoHlaSyncRef;                 /*!< @vaddr: RTE_HLA_MEAS_VADDR_SYNC_REF @cycleid: HLA_ENV_PVT @vname: HlaSyncRef */

typedef HLAR_t_RequiredInputs          PdoHlarRequiredInputs;         /*!< @vaddr: HLA_MEAS_VADDR_HLAR_IN @cycleid: HLA_ENV_PVT @vname: HlarRequiredInputs */
typedef HLAF_t_RequiredInputs          PdoHlafRequiredInputs;         /*!< @vaddr: HLA_MEAS_VADDR_HLAF_IN @cycleid: HLA_ENV_PVT @vname: HlafRequiredInputs */
typedef HLAR_t_ProvidedOutputs         PdoHlarProvidedOutputs;        /*!< @vaddr: HLA_MEAS_VADDR_HLAR_OUT @cycleid: HLA_ENV_PVT @vname: HlarProvidedOutputs */
typedef HLAF_t_ProvidedOutputs         PdoHlafProvidedOutputs;        /*!< @vaddr: HLA_MEAS_VADDR_HLAF_OUT @cycleid: HLA_ENV_PVT @vname: HlafProvidedOutputs */

typedef HLA_t_SystemInfo               PdoHlaSystemInfo;              /*!< @vaddr: HLA_MEAS_VADDR_SYSTEM_INFO @cycleid: HLA_ENV_PVT @vname: HLA_s_SystemInfo @vname: HlaSystemInfo */
typedef HLAImagerParameter_t           PdoHlaImagerParameter;         /*!< @vaddr: HLA_MEAS_VADDR_IMAGER_PARAMETERS @cycleid: HLA_ENV_PVT @vname: HlaImagerParameter */
typedef HLACameraData_t                PdoHlaCamData;                 /*!< @vaddr: HLA_MEAS_VADDR_CAM_DATA @cycleid: HLA_ENV_PVT @vname: HlaCamData */
typedef HLAOdometer_t                  PdoHlaOdometer;                /*!< @vaddr: HLA_MEAS_VADDR_ODOMETER @cycleid: HLA_ENV_PVT @vname: HlaOdometer */      
typedef HLADebugOutputs_t              PdoHlaDebugOutputs;            /*!< @vaddr: HLA_MEAS_VADDR_HLA_DEBUG_OUT @cycleid: HLA_ENV_PVT @vname: HlaDebugOutputs */

typedef HLASegIn_t                     PdoHlaSegIn;                   /*!< @vaddr: HLA_MEAS_VADDR_SEG_IN @cycleid: HLA_ENV_PVT @vname: HlaSegIn */
typedef HLASegData_t                   PdoHlaSegData;                 /*!< @vaddr: HLA_MEAS_VADDR_SEG_DATA @cycleid: HLA_ENV_PVT @vname: HlaSegData */
typedef HLASegOut_t                    PdoHlaSegOut;                  /*!< @vaddr: HLA_MEAS_VADDR_SEG_OUT @cycleid: HLA_ENV_PVT @vname: HlaSegOut */
typedef HLASegLineBuffer_t             PdoHlaSegLineBuffer;           /*!< @vaddr: HLA_MEAS_VADDR_SEG_LINE_BUFFER @cycleid: HLA_ENV_PVT @vname: HlaSegLineBuffer */
typedef HLASegLineRegionBuffer_t       PdoHlaSegLineRegionBuffer;     /*!< @vaddr: HLA_MEAS_VADDR_SEG_REGION_BUFFER @cycleid: HLA_ENV_PVT @vname: HlaSegLineRegionBuffer */
typedef HLASegLightBuffer_t            PdoHlaSegLightBuffer;          /*!< @vaddr: HLA_MEAS_VADDR_SEG_LIGHT_BUFFER @cycleid: HLA_ENV_PVT @vname: HlaSegLightBuffer */

typedef HLATracking3DOutput_t          PdoHlaTrackOut;                /*!< @vaddr: HLA_MEAS_VADDR_TRACK_OUT @cycleid: HLA_ENV_PVT @vname: HlaTrackOut */
typedef HLATracking3DDataPreComputed_t PdoHlaTrackDataPreComputed;    /*!< @vaddr: HLA_MEAS_VADDR_TRACK_PRE_COMPUTED @cycleid: HLA_ENV_PVT @vname: HlaTrackDataPreComputed */
typedef HLADebugIconList_t             PdoHlaDebugIconList;           /*!< @vaddr: HLA_MEAS_VADDR_DEBUG_ICON_LIST @cycleid: HLA_ENV_PVT @vname: HlaDebugIconList */
typedef HLA_t_Highway                  PdoHlaHighwayOutput;           /*!< @vaddr: HLA_MEAS_VADDR_HIGHWAY_OUT @cycleid: HLA_ENV_PVT @vname: HlaHighwayOutput */
typedef HLACityData_t                  PdoHlaCityData;                /*!< @vaddr: HLA_MEAS_VADDR_CITY_DATA @cycleid: HLA_ENV_PVT @vname: HlaCityData */
typedef HLATunnelOutput_t              PdoHlaTunnelOutput;            /*!< @vaddr: HLA_MEAS_VADDR_TUNNEL_OUT @cycleid: HLA_ENV_PVT @vname: HlaTunnelOutput */

typedef HLAFParameter_t                PdoHlafParameter;              /*!< @vaddr: HLA_MEAS_VADDR_HLAF_DATA @cycleid: HLA_ENV_PVT @vname: HlafParameter */
typedef HLAF_DebugOutputs_t            PdoHlafDebugOutputs;           /*!< @vaddr: HLA_MEAS_VADDR_HLAF_DEBUG_OUT @cycleid: HLA_ENV_PVT @vname: HlafDebugOutputs */
typedef HLAFData_t                     PdoHlafData;                   /*!< @vaddr: HLA_MEAS_VADDR_HLAF_PARAMETER @cycleid: HLA_ENV_PVT @vname: HlafData */
typedef HLAFMatrixParameter_t          PdoHlafMatrixParameter;        /*!< @vaddr: HLA_MEAS_VADDR_HLAF_MATRIX_PARAMETER @cycleid: HLA_ENV_PVT @vname: HlafMatrixParameter */
typedef HLAFMatrixInput_t              PdoHlafMatrixInput;            /*!< @vaddr: HLA_MEAS_VADDR_HLAF_MATRIX_INPUT @cycleid: HLA_ENV_PVT @vname: HlafMatrixInput */
typedef HLAFMatrixData_t               PdoHlafMatrixData;             /*!< @vaddr: HLA_MEAS_VADDR_HLAF_MATRIX_DATA @cycleid: HLA_ENV_PVT @vname: HlafMatrixData */
#ifdef PC_SIM
typedef HLAplusParameters_t            PdoHlafPlusParameter;          /*!< @vaddr: HLA_MEAS_VADDR_HLAF_PLUS_PARAMETER @cycleid: HLA_ENV_PVT @vname: HlafPlusParameter */
typedef HLAplusInputData_t             PdoHlafPlusInput;              /*!< @vaddr: HLA_MEAS_VADDR_HLAF_PLUS_INPUT @cycleid: HLA_ENV_PVT @vname: HlafPlusInput */
typedef HLAplusData_t                  PdoHlafPlusData;               /*!< @vaddr: HLA_MEAS_VADDR_HLAF_PLUS_DATA @cycleid: HLA_ENV_PVT @vname: HlafPlusData */
typedef HLAFStandardData_t             PdoHlafStdData;                /*!< @vaddr: HLA_MEAS_VADDR_HLAF_STANDARD_DATA @cycleid: HLA_ENV_PVT @vname: HlafStdData */
typedef HLAFLightData_t                PdoHlafLightData;              /*!< @vaddr: HLA_MEAS_VADDR_HLAF_LIGHT @cycleid: HLA_ENV_PVT @vname: HlafLightData */
#endif

/* Eval board only */
#ifdef EVAL_BOARD
typedef HLAEvmHilTimeMeas_t            PdoHlaEvmHilTimeMeas;          /*!< @vaddr: 0x312FFF00 @cycleid: HLA_ENV_PVT @vname: HlaEvmHilTimeMeas */
#endif /* EVAL_BOARD */

#endif /* __PDO__ */

void HlaPdoDummyForCompiler (void) {}
