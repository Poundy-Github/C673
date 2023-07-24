/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision) 

PACKAGENAME:               head_int.h

DESCRIPTION:               header file for HEAD module 

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2019/09/09 09:34:28CEST $

VERSION:                   $Revision: 1.10 $

**************************************************************************** */

/**
@ingroup head
@{ **/

#ifndef HEAD_INT_H_INCLUDED
#define HEAD_INT_H_INCLUDED

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

#include "head/head_ext.h"
#include "head/head_main.h"
#include "head/head_out_togglefunction.h"
#include "head/head_out_brakefunction_autocodepar.h"
#include "head/head_out_brakefunction.h"
#include "head/head_out_hbafunction_autocodepar.h"
#include "head/head_out_hbafunction.h"
#include "head/head_out_warnfunction_autocodepar.h"
#include "head/head_out_warnfunction.h"
#include "head/head_autocode_cfg.h"
#include "head/head_wrapper.h"
#include "head/head_codingSwitches.h"

#if defined (HEAD_USE_CUSTOM_SYSTEMFUNCTION) && (HEAD_USE_CUSTOM_SYSTEMFUNCTION == MEDIC_ON)
#include "head/head_customSystemfunction.h"
#endif

#endif  // MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

#endif  // HEAD_INT_H_INCLUDED

/**@}*/

