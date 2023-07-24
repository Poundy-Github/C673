/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim20_input_mgr.c

DESCRIPTION:               Header for DIM Input Manager

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/07/29 15:03:35CEST $

VERSION:                   $Revision: 1.17 $

**************************************************************************** */

#ifndef DIM20_INPUT_MGR_INCLUDED
#define DIM20_INPUT_MGR_INCLUDED

#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)

/*****************************************************************************
  MACROS
*****************************************************************************/
/*! @brief   Velocity signal value */
#define DIMGetInput_VehicleVelocity()             DIM_INPUT_EGOVEL_RAW
/*! @brief   Velocity signal stdev */
#define DIMGetStdDev_VehicleVelocity()            DIM_INPUT_EGOVEL_STDEV

/*! @brief   Acceleration signal value */
#define DIMGetInput_VehicleAcceleration()         DIM_INPUT_EGOACC_RAW
/*! @brief   Acceleration signal stdev */
#define DIMGetStdDev_VehicleAcceleration()        DIM_INPUT_EGOACC_STDEV

/*************************************************************************/

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
/* extern functions */
extern void DIMInitInputMgr(void);
extern void DIMCollectInputs(void);
#if (DIM_CFG_IN_PREPROC)
extern void DIMInitSigPreProc(void);
extern void DIMRunSigPreProc(float32 fCycleTime);
extern boolean DimDifferentiatorRun(float32 *fOutValue, float32 fInValue, float32 fCycleTime, DimIirFilt_t *pFilt);
#endif /* DIM_CFG_IN_PREPROC */

#endif /* MEDIC_CFG_DRIVER_INTENTION_MONITORING */
#endif /* DIM20_INPUT_MGR_INCLUDED */

