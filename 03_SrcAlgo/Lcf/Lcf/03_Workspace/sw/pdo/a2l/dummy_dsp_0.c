/*
 * This is a dummy C file, which is used to generate an SDL with the PDO-Tool.
 */
 
#define CORE_DSP_0
#define BIT_FIELD_MSB_FIRST  0

// TODO Check if number of errors in a2l file could be reduced.      
#if (A2L_CFG_MFC431 == 1)

#include "C_A_DRVMN_model.c"				// dsp_0 (+ dsp_1)
#include "DRMDAE.c"				            // dsp_0 (+ dsp_1)
#include "DRMDAE_data.c"		            // dsp_0 (+ dsp_1)
#include "DRMHOD.c"		                    // dsp_0 (+ dsp_1)
#include "DRMHOD_data.c"		            // dsp_0 (+ dsp_1)
#include "TCTCDC.c"                         // dsp_0 (+ dsp_1)
#include "TCTCDC_data.c"                    // dsp_0 (+ dsp_1)
#include "TCTCLM.c"                         // dsp_0 (+ dsp_1)
#include "TCTCLM_data.c"                    // dsp_0 (+ dsp_1)
#include "TCTDTE.c"                         // dsp_0 (+ dsp_1)
#include "TCTDTE_data.c"                    // dsp_0 (+ dsp_1)
#include "TCTFFC.c"                         // dsp_0 (+ dsp_1)
#include "TCTFFC_data.c"                    // dsp_0 (+ dsp_1)
#include "TCTLGC.c"                         // dsp_0 (+ dsp_1)
#include "TCTLGC_data.c"                    // dsp_0 (+ dsp_1)
#include "TRJCTR.c"                         // dsp_0 (+ dsp_1)
#include "TPLTJC_data.c"                    // dsp_0 (+ dsp_1)
#include "TPLTJC.c"                         // dsp_0 (+ dsp_1)
#include "TPLLCO_data.c"                    // dsp_0 (+ dsp_1)
#include "TPLLCO.c"                         // dsp_0 (+ dsp_1)
#include "TPLFRT_data.c"                    // dsp_0 (+ dsp_1)
#include "TPLFRT.c"	                        // dsp_0 (+ dsp_1)
#include "TPLFBT_data.c"                    // dsp_0 (+ dsp_1)	
#include "TPLFBT.c"	                        // dsp_0 (+ dsp_1)
#include "TPLCEN_data.c"                    // dsp_0 (+ dsp_1)	
#include "TPLCEN.c"	                        // dsp_0 (+ dsp_1)
#include "TRJPLN.c"							// dsp_0 (+ dsp_1)
#include "C_A_TRJPLN_model.c"				// dsp_0 (+ dsp_1)
#include "paramlvc.c"						// dsp_0 (+ dsp_1)
#include "dmc.c"							// dsp_0 (+ dsp_1)
#include "lcf_veh_main.c"					// dsp_0 (+ dsp_1)
#include "latdmc_wrp.c"						// dsp_0 (+ dsp_1)
#include "DROTMC.c"				            // dsp_0 (+ dsp_1)
#include "DROTMC_data.c"		            // dsp_0 (+ dsp_1)

#endif // (A2L_CFG_MFC431 == 1)

// Generate entries for RTE types:
#include "Rte_Type.h"										// common
#include "Rte_Algo_Type.h"									// common

// Generate entries for SW types:
//#include "sw_meastypes.h"								// common

// Generate entries for EBA_Sen algo:
//#include "algo_type.h"									// common

#if ((A2L_CFG_MFC431 == 0) && (A2L_CFG_HFL110 == 0))
#include "cd.h"													// dsp_0 (+ dsp_1)
#include "cp_fusion_trace.c"						// dsp_0 (+ dsp_1)
#include "cp_main.c"										// dsp_0 (+ dsp_1)
#include "fip_navi_data_plg.c"					// dsp_0 (+ dsp_1)
#endif // ((A2L_CFG_MFC431 == 0) && (A2L_CFG_HFL110 == 0))

#if (A2L_CFG_HFL110 == 0)
#include "fct_meas.c"										// dsp_0 (+ dsp_1)
#include "fct_sen.h"										// dsp_0 (+ dsp_1)
#include "fct_sen_main.c"								// dsp_0 (+ dsp_1)
#endif // (A2L_CFG_HFL110 == 0)

#if ((A2L_CFG_MFC431 == 0) && (A2L_CFG_HFL110 == 0))
#include "cd_wrapper.c"									// dsp_0 (+ dsp_1)
#include "cp_si.c"											// dsp_0 (+ dsp_1)
#endif // ((A2L_CFG_MFC431 == 0) && (A2L_CFG_HFL110 == 0))

#if (A2L_CFG_HFL110 == 0)
#include "frame_sen_custom_types.h"			// dsp_0 (+ dsp_1)
#endif // (A2L_CFG_HFL110 == 0)

// Generate entries for global scheduler:
//#include "common_scheduler_meas_types_pkg.h"	// common
