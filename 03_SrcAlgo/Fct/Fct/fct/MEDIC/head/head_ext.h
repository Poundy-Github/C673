/*! \file **********************************************************************
  
COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_ext.h

DESCRIPTION:               External Header of the HEAD component

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2019/09/09 09:34:22CEST $

VERSION:                   $Revision: 1.17 $
  
**************************************************************************** */
/**
@ingroup head
@{ **/
#ifndef HEAD_EXT_H_INCLUDED
#define HEAD_EXT_H_INCLUDED

/*! @cond */
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/*! @endcond */

/*****************************************************************************
INCLUDES
*****************************************************************************/
#include "head/head_autoversion.h"
#include "head/head_cfg.h"
#include "head/head_par.h"
#include "head/head_custOutput.h"
#include "head/head_module_def.h"
#include "head/head_float16_util.h"
#include "head/head_parameter_def.h"
#include "head/head_spm.h"
#include "head/head_generic_sm.h"
#include "head/head_par_fct.h"
#include "head/head_mts_inputdef.h"
#include "head/head_mts.h"
#include "head/head_mts_custom.h"

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief          External operation mode
    @description    Operations modes for external framework control
    */
typedef enum 
{
  HEADOpMode_Running,     /*!< Head module normal running operation */
  HEADOpMode_ShutDown,    /*!< Head module normal deactivation. It define current module is not in "stop"*/
  HEADOpMode_Stop         /*!< Head module severe deactivation. It define current module is in stop mode */
} eHEADOpMode_t;

#include "head/head.h"
#include "head/head_inputData.h"

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/
/* entry functions for external framework */
extern eGDBError_t HEADInit(void);
extern eGDBError_t HEADProcess(const float32 fCycleTime);
extern void HEADSetOpMode(eHEADOpMode_t OpMode);

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */

#endif /* HEAD_EXT_H_INCLUDED */
/**@}*/

