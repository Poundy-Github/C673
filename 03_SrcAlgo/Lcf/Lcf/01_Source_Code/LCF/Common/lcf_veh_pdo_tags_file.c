/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 lcf_veh_pdo_tags_file.c

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                   Initial revision
  
**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/


#ifdef __PDO__
#include "algo_glob.h"
#include "lcf_veh_ext.h"
#include "lcf_veh_main.h"

/* place your additional internal types here */
typedef BaseCtrlData_t        LcfVehBaseCtrlData_t;        /*!< @vaddr:LCF_VEH_MEAS_ID_CTRL_BSW_DATA           @cycleid:LCF_VEH_ENV_PVT @vname:pLcfVehBaseCtrlData        */
typedef AlgoCompState_t       LcfVehAlgoCompState_t;       /*!< @vaddr:LCF_VEH_MEAS_ID_ALGO_COMP_STATE         @cycleid:LCF_VEH_ENV_PVT @vname:pLcfVehAlgoCompState       */
typedef LcfVeh_SyncRef_t      LcfVehSyncRef_t;             /*!< @vaddr:LCF_VEH_MEAS_ID_SYNC_REF                @cycleid:LCF_VEH_ENV_PVT @vname:pLcfVehSyncRef             */

#endif

void LcfVehPDODummyForCompiler (void) {}

