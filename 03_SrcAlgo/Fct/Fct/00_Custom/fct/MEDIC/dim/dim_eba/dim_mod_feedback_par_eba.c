/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_mod_feedback_par_eba.c

DESCRIPTION:               Implementation of the DIM driver activity parameters (as done for BMW)

AUTHOR:                    $Author: uia92763 $

CREATION DATE:             $Date: 2020/09/22 11:19:51CEST $

VERSION:                   $Revision: 1.1.8.3 $

LEGACY VERSION:            1.5.1.2

**************************************************************************** */
/**
@ingroup Medic_dim
@{ **/

#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_DIM20)
#include "dim/dim_int.h"

#if(MEDIC_CFG_DRIVER_INTENTION_MONITORING)
/*!  @cond Doxygen_Suppress */
const DIM_FEEDBACK_PAR_struct_t DIM_FEEDBACK_PAR_data_eba =
{
  #if (DIM_CFG_NO_FALL_IN_BRAKE_DETECTION)
  { 
    /* s, %*/
    {0.0f, -70.0f}, /* fWeakNegCurve, Timer is running from 1.0 -> 0.0 sec */
    {1.0f, -89.0f}
  },
  #endif
  /*fHighGasPedalPos*/         90.0f,
  /*fHighGasPedalGrad*/       250.0f,
  ///*fHighGasPedalPosWeakNegH*/ 90.0f,
  /*fHighGasPedalPosWeakNegH*/ 85.0f,
  /*fHighGasPedalPosWeakNegL*/ 20.0f,
  /*fHighGasPedalGradWeakNeg*/700.0f,
  /*fAutoBrakeJerkLimit*/      -4.0f,
  /*fAutoBrkTimeNoPosFdbck*/    0.35f,
  /*fVeryHighGasPedalPos*/     95.0f,
  /*fVeryHighGasPedalGrad*/  1000.0f,
  /*fGasPedalUsedPos*/          1.0f,
  /*fGasPedelGradNegative*/    -5.0f,
  /*fNegFdbckTime*/             1.0f,
  /*fPosFdbckTime*/             3.0f
};

/*! @endcond */

#endif
#endif  /* DIM2.0 switch */

/**@}*/
