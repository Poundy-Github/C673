/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 lcf_sen_pdo_tags_file.c

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
#include "lcf_sen_ext.h"
#include "lcf_sen_main.h"

/* place your additional internal types here */
typedef BaseCtrlData_t        LcfSenBaseCtrlData_t;        /*!< @vaddr:LCF_SEN_MEAS_ID_CTRL_BSW_DATA           @cycleid:LCF_SEN_ENV_PVT @vname:pLcfSenBaseCtrlData        */
typedef AlgoCompState_t       LcfSenAlgoCompState_t;       /*!< @vaddr:LCF_SEN_MEAS_ID_ALGO_COMP_STATE         @cycleid:LCF_SEN_ENV_PVT @vname:pLcfSenAlgoCompState       */
typedef LcfSen_SyncRef_t      LcfSenSyncRef_t;             /*!< @vaddr:LCF_SEN_MEAS_ID_SYNC_REF                @cycleid:LCF_SEN_ENV_PVT @vname:pLcfSenSyncRef             */

#endif

void LcfSenPDODummyForCompiler (void) {}
