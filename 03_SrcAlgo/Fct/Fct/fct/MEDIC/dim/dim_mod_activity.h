/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_mod_activity.h

DESCRIPTION:               header of the DIM driver activity

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2019/05/24 16:37:33CEST $

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            1.11
  
**************************************************************************** */
/**
@ingroup Medic_dim
@{ **/
#ifndef DIM_MOD_DRV_ACT_INCLUDED
#define DIM_MOD_DRV_ACT_INCLUDED
#include "dim/dim.h"
#include "dim/dim_mod_activity_par.h"

#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)

extern eGDBError_t DIMInitModuleActivity(DIMInternalDataModActivity_t *pInternalData);
extern eGDBError_t DIMRunModuleActivity(const float32 fCycleTime, const DIMInputDataGlobal_t *pInputData, 
                                        GDB_DMHypothesis_t *pOutHypothesis, DIMInternalDataModActivity_t *pInternalData, 
                                        const DIM_ACTIVITY_PAR_struct_t *pDIM_activity_par);

#endif /* MEDIC_CFG_DRIVER_INTENTION_MONITORING */
#endif /*DIM_MOD_DRV_ACT_INCLUDED*/
/**@}*/ 

