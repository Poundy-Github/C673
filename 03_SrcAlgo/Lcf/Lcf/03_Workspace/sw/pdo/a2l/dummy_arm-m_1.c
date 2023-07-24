/*
 * This is a dummy C file, which is used to generate an SDL with the PDO-Tool.
 */
 
#define CORE_M_1
#define BIT_FIELD_MSB_FIRST  0

// TODO Add needed a2l includes for this core here


// Generate entries for RTE types:
#include "Rte_Type.h"										// common
#include "Rte_Algo_Type.h"									// common

// Generate entries for SW types:
//#include "sw_meastypes.h"								// common

// Generate entries for VDY algo:
#include "vdy_main.c"									// (m_0 +) m_1
#include "vdy_ay_swa.c"									// (m_0 +) m_1
#include "vdy_mon.c"									// (m_0 +) m_1
#include "vdy_velcor.c"									// (m_0 +) m_1
#include "vdy_whs.c"									// (m_0 +) m_1
#include "vdy_ywr.c"									// (m_0 +) m_1
#include "vdy_ywrt.c"									// (m_0 +) m_1
#include "vdy_ext.h"									// (m_0 +) m_1

#if (A2L_CFG_MFC431 == 1)
#include "dim_wrapper.c"
#include "fct_veh.h"
#include "fct_veh_main.c"
#include "udw.h"
#include "udw_pdo_tags_file.c"
#endif // (A2L_CFG_MFC431 == 1)

#if ((A2L_CFG_MFC431 == 0) && (A2L_CFG_HFL110 == 0))
// Generate entries for EBA_Veh algo:
#include "dim_wrapper.c"								// m_1
#include "head_autocode_cfg.h"					// m_1
#include "head_wrapper.c"								// m_1
#include "fct_veh.h"										// m_1
#include "head_mts.h"										// m_1
#include "head_autocode_cfg.c"					// m_1
// Generate entries for lka algo:
#include "lka.h"												// m_1
#include "lka_wrapper.c"								// m_1
#endif // ((A2L_CFG_MFC431 == 0) && (A2L_CFG_HFL110 == 0))

// Generate entries for EBA_Sen algo:
//#include "algo_type.h"									// common

#if (A2L_CFG_MFC431 == 0)

#endif // (A2L_CFG_MFC431 == 0)

#if (A2L_CFG_MFC431 == 0)
//#include "si_acc_function_presel.c"			// unknown
//#include "si_calc_cutin_pot.c"					// unknown
//#include "si_corridor_crit.c"						// unknown
//#include "si_lanechange.c"							// unknown
//#include "si_main.c"										// unknown
//#include "si_objscore.c"								// unknown
//#include "si_output.c"									// unknown
//#include "si_traffic_density.c"					// unknown
//#include "spm_main.c"										// unknown
//#include "spm_objectloss.c"							// unknown
#endif // (A2L_CFG_MFC431 == 0)

//#include "frame_sen_custom_types.h"			// dsp_0 (+ dsp_1)

// Generate entries for global scheduler:
//#include "common_scheduler_meas_types_pkg.h"	// common

