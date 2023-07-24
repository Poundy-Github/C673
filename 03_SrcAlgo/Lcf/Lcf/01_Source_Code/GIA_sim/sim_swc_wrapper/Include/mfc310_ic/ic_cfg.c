/*
 * imager_config.c
 *
 *  Created on: 19.07.2011
 *      Author: uidt3974
 */
#include "ic_cfg.h"
#include "ic_types.h"

// Output warnings for certain configuration switches when compiled with CWCC (other compilers may not know #warning directive)
#if ((IC_PROFILING_ENABLED == 1) && defined(__CWCC__))
#warning "IC runtime profiling has been enabled! Please disable for saving resources." // PRQA S 1008,3115
#endif

// Maximum tolerances allowed for analog test in production.
//
// NOTE: This is included as 'extern const' in ic_controller.c and NOT declared in 'ic_cfg.h',
//       as it needs 'ic_types.h', which would generate cyclic dependencies
//
// PRQA S 1305,3211,3408 1
const IC_S_ATestMaxTols ICCFG_s_ATest_MaxTolsProduction = {
    0.25f, // f32_MeanATV1_1xGain;    /* Tolerance of the mean with 1xGain and ATV1 voltage setting */
    0.25f, // f32_MeanATV1_2xGain;    /* Tolerance of the mean with 2xGain and ATV1 voltage setting */
    0.25f, // f32_MeanATV3_1xGain;    /* Tolerance of the mean with 1xGain and ATV3 voltage setting */
    0.25f, // f32_ColMeanATV1_1xGain;
    0.25f, // f32_ColMeanATV1_2xGain;
    0.25f, // f32_ColMeanATV3_1xGain;
    0.25f, // f32_RatioATV3_1xGain;
    0.25f  // f32_RatioATV1_2xGain;
};

// Maximum tolerances allowed for analog test at startup.
//
// NOTE: This is included as 'extern const' in ic_controller.c and NOT declared in 'ic_cfg.h',
//       as it needs 'ic_types.h', which would generate cyclic dependencies
//
// PRQA S 1305,3211,3408 1
const IC_S_ATestMaxTols ICCFG_s_ATest_MaxTolsStartup = {
    0.50f, // f32_MeanATV1_1xGain;    /* Tolerance of the mean with 1xGain and ATV1 voltage setting */
    0.50f, // f32_MeanATV1_2xGain;    /* Tolerance of the mean with 2xGain and ATV1 voltage setting */
    0.50f, // f32_MeanATV3_1xGain;    /* Tolerance of the mean with 1xGain and ATV3 voltage setting */
    0.25f, // f32_ColMeanATV1_1xGain;
    0.25f, // f32_ColMeanATV1_2xGain;
    0.25f, // f32_ColMeanATV3_1xGain;
    0.25f, // f32_RatioATV3_1xGain;
    0.25f  // f32_RatioATV1_2xGain;
};
