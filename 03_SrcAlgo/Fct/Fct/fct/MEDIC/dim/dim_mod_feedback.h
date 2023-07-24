/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_mod_feedback.h

DESCRIPTION:               header of the DIM driver feedback

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2019/05/24 16:37:32CEST $

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            1.12
  
**************************************************************************** */
/**
@ingroup Medic_dim
@{**/
#ifndef DIM_MOD_DRV_FDBCK_INCLUDED
#define DIM_MOD_DRV_FDBCK_INCLUDED
#include "dim/dim.h"
#include "dim/dim_mod_feedback_par.h"

#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)

/*! @brief       FeedBack buffer scale

    @general     Dim feedback buffer Scale used for AccelBuffer

    @conseq      [none]

    @attention   [none]

    @typical     [none]     @unit [none]    @min 0    @max 10   */
#define DIM_FEEDBACK_ACCEL_BUFFER_SCALE (10.0f)

/*! @brief       FeedBack Filter time

    @general     Dim feedback use for fliter time defination

    @conseq      [none]

    @attention   [none]

    @typical     [none]     @unit [none]    @min 0    @max 0.25   */
#define DIM_FEEDBACK_DEF_GRAD_FILTER_TIME (0.25f)

extern eGDBError_t DIMInitModuleFeedback(DIMInternalDataModFeedback_t *pInternalData);
extern eGDBError_t DIMRunModuleFeedback(float32 fCycleTime, const DIMInputDataGlobal_t *pInputData, 
                                        GDB_DMHypothesis_t *pOutHypothesis, DIMInternalDataModFeedback_t *pInternalData, 
                                        const DIM_FEEDBACK_PAR_struct_t *pDIM_feedback_par);

#endif /* MEDIC_CFG_DRIVER_INTENTION_MONITORING */
#endif /*DIM_MOD_DRV_FDBCK_INCLUDED*/
/**@}*/ 

