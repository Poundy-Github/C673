/*! \file **********************************************************************
  
COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head20_ext.h

DESCRIPTION:               External Header of the HEAD component (HEAD 2.0)

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/04/01 16:02:15CEST $

VERSION:                   $Revision: 1.13 $

LEGACY VERSION:            1.13.1.1 (HEAD 2.0)
  
**************************************************************************** */

#ifndef HEAD20_EXT_H_INCLUDED
#define HEAD20_EXT_H_INCLUDED

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

/*****************************************************************************
INCLUDES
*****************************************************************************/
#include "head20/head20_autoversion.h"
#include "head20/head20_cfg.h"
#include "head20/head20_par.h"
#include "head20/head20_types.h"
#include "head20/head20_autocode_sm_par.h"
#include "head20/head20_module_def.h"
#include "head20/head20_parameter_def.h"
#include "head20/head20_spm.h"
#include "head20/head20.h"
#include "head20/head20_generic_sm.h"
#include "head20/head20_par_fct.h"
#include "head20/head20_mts_inputdef.h"
#include "head20/head20_mts.h"
#include "head20/head20_mts_custom.h"
#include "head20/head20_main.h"
#include "head20/head20_out_togglefunction.h"
#include "head20/head20_out_brakefunction_autocodepar.h"
#include "head20/head20_out_brakefunction.h"
#include "head20/head20_out_hbafunction_autocodepar.h"
#include "head20/head20_out_hbafunction.h"
#include "head20/head20_out_warnfunction_autocodepar.h"
#include "head20/head20_out_warnfunction.h"
#include "head20/head20_autocode_cfg.h"
#include "head20/head20_custOutput.h"
#include "head20/head20_codingSwitches.h"
#include "head20/head20_inputData.h"

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/
/* entry functions for external framework */
extern eGDBError_t HEADInit(void);
extern eGDBError_t HEADProcess(const float32 fCycleTime);
extern void HEADSetOpMode(const eHEADOpMode_t OpMode);
#if (MEDIC_ARCHITECTURE_VERSION >= 0x10)
extern void HEADSetBrakeCascadePort(void);
#endif

/*** END OF SINLGE INCLUDE SECTION ******************************************/

#endif  /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION*/
#endif /* HEAD20_EXT_H_INCLUDED */


