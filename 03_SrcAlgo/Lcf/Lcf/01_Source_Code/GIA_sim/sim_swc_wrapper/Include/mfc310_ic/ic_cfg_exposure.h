/*
 * ic_cfg_exposure.h
 *
 *  Created on: 05.06.2012
 *      Author: uidt3974
 */

#ifndef IC_CFG_EXPOSURE_H_
#define IC_CFG_EXPOSURE_H_

#include "ic_exposure.h"

// Function for getting exposure control settings for a specific frame-type
extern void ICCFG_v_GetExposureSettings(ICEXP_S_Settings * const ps_Settings, const IC_E_FRAMETYPE e_FrameType);

#endif /* IC_CFG_EXPOSURE_H_ */
