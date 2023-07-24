/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_mod_attention.h

DESCRIPTION:               header of the DIM driver attention

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2019/05/24 16:37:32CEST $

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            1.12
  
**************************************************************************** */
/**
@ingroup Medic_dim
@{ **/
#ifndef DIM_MOD_DRV_ATT_INCLUDED
#define DIM_MOD_DRV_ATT_INCLUDED
#include "dim/dim.h"
#include "dim/dim_mod_attention_par.h"
#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)

extern eGDBError_t DIMInitModuleAttention(DIMInternalDataModAttention_t *pInternalData);
extern eGDBError_t DIMRunModuleAttention(const float32 fCycleTime, const DIMInputDataGlobal_t *pInputData, 
                                         GDB_DMHypothesis_t *pOutHypothesis, DIMInternalDataModAttention_t *pInternalData, 
                                         const DIM_ATTENTION_PAR_struct_t *pDIM_attention_par);
#endif
#endif /*DIM_MOD_DRV_ATT_INCLUDED*/
/**@}*/

