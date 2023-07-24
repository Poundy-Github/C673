/*
 * This is a dummy C file, which is used to generate an SDL with the PDO-Tool.
 */
 
#define CORE_DSP_1
#define BIT_FIELD_MSB_FIRST  0

// TODO Add needed a2l includes for this core here


// Generate entries for RTE types:
#include "Rte_Type.h"										// common
#include "Rte_Algo_Type.h"									// common

#if (A2L_CFG_MFC431 == 1)

#include "CSCLTA.c"			             	// dsp_0 (+ dsp_1)
#include "CSCLTA_data.c"				    // dsp_0 (+ dsp_1)
#include "LDPSA.c"                          // dsp_0 (+ dsp_1)
#include "DPLSTM.c"                         // dsp_0 (+ dsp_1)
#include "DPLSTM_data.c"                    // dsp_0 (+ dsp_1)
#include "DPLTTG.c"                         // dsp_0 (+ dsp_1)
#include "DPLTTG_data.c"                    // dsp_0 (+ dsp_1)
#include "DPLTVG.c"                         // dsp_0 (+ dsp_1)
#include "DPLTVG_data.c"                    // dsp_0 (+ dsp_1)
#include "DPODOO.c"                         // dsp_0 (+ dsp_1)
#include "DPODOO_data.c"                    // dsp_0 (+ dsp_1)
#include "DPOSIA.c"                         // dsp_0 (+ dsp_1)
#include "DPOSIA_data.c"                    // dsp_0 (+ dsp_1)
#include "DPOSTM.c"                         // dsp_0 (+ dsp_1)
#include "DPOSTM_data.c"                    // dsp_0 (+ dsp_1)
#include "DPOTTG.c"                         // dsp_0 (+ dsp_1)
#include "DPOTTG_data.c"                    // dsp_0 (+ dsp_1)
#include "DPOTVG.c"                         // dsp_0 (+ dsp_1)
#include "DPOTVG_data.c"                    // dsp_0 (+ dsp_1)
#include "LKASA.c"                          // dsp_0 (+ dsp_1)
#include "LKASTM.c"                         // dsp_0 (+ dsp_1)
#include "LKASTM_data.c"                    // dsp_0 (+ dsp_1)
#include "LKATTG.c"                         // dsp_0 (+ dsp_1)
#include "LKATTG_data.c"                    // dsp_0 (+ dsp_1)
#include "LKATVG.c"                         // dsp_0 (+ dsp_1)
#include "LKATVG_data.c"                    // dsp_0 (+ dsp_1)
#include "ODPFOP.c"                         // dsp_0 (+ dsp_1)
#include "ODPFOP_data.c"                    // dsp_0 (+ dsp_1)
#include "ODPOOP.c"                         // dsp_0 (+ dsp_1)
#include "ODPOOP_data.c"                    // dsp_0 (+ dsp_1)
#include "TJASTM.c"                         // dsp_0 (+ dsp_1)
#include "TJASTM_data.c"                    // dsp_0 (+ dsp_1)
#include "TJATTG.c"                         // dsp_0 (+ dsp_1)
#include "TJATTG_data.c"                    // dsp_0 (+ dsp_1)
#include "TJATVG.c"                         // dsp_0 (+ dsp_1)
#include "TJATVG_data.c"                    // dsp_0 (+ dsp_1)
#include "RDPSA.c"                          // dsp_0 (+ dsp_1)
#include "DPRSTM.c"                         // dsp_0 (+ dsp_1)
#include "DPRSTM_data.c"                    // dsp_0 (+ dsp_1)
#include "DPRTTG.c"                         // dsp_0 (+ dsp_1)
#include "DPRTTG_data.c"                    // dsp_0 (+ dsp_1)
#include "DPRTVG.c"                         // dsp_0 (+ dsp_1)
#include "DPRTVG_data.c"                    // dsp_0 (+ dsp_1)
#include "MCTLFC.c"				            // dsp_0 (+ dsp_1)
#include "MCTLFC_data.c"				    // dsp_0 (+ dsp_1)
#include "ABPLBP.c"					        // dsp_0 (+ dsp_1)
#include "ABPLBP_data.c"					// dsp_0 (+ dsp_1)
#include "laneKalmanFilter_Left.c"		    	// dsp_0 (+ dsp_1)
#include "laneKalmanFilter_Right.c"		    	// dsp_0 (+ dsp_1)
#include "crvKalmanFilter.c"				// dsp_0 (+ dsp_1)
#include "ABPREP.c"					        // dsp_0 (+ dsp_1)
#include "ABPREP_data.c"					// dsp_0 (+ dsp_1)
#include "VDPDRV.c"					        // dsp_0 (+ dsp_1)
#include "VDPDRV_data.c"					// dsp_0 (+ dsp_1)
#include "SDPHDA_data.c"				    // dsp_0 (+ dsp_1)
#include "SDPHDA.c"				        	// dsp_0 (+ dsp_1)

#include "HSCHDA_data.c"				    // dsp_0 (+ dsp_1)
#include "HSCHDA.c"				        	// dsp_0 (+ dsp_1)
#include "HMOHMC.c"                         // dsp_0 (+ dsp_1)
#include "HMOHMC_data.c"                    // dsp_0 (+ dsp_1)
#include "HSCHLC.c"                         // dsp_0 (+ dsp_1)
#include "HSCHLC_data.c"                    // dsp_0 (+ dsp_1)
#include "HMOTMC.c"                         // dsp_0 (+ dsp_1)
#include "HMOTMC_data.c"                    // dsp_0 (+ dsp_1)
#include "DPWSTM.c"                         // dsp_0 (+ dsp_1)
#include "DPWSTM_data.c"                    // dsp_0 (+ dsp_1)
#include "lcf_sen_main.c"					// dsp_0 (+ dsp_1)

#endif

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
