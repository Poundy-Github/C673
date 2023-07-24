/*
 * This is a dummy C file, which is used to generate an SDL with the PDO-Tool.
 */
 
#define CORE_M_0
#define BIT_FIELD_MSB_FIRST  0

// TODO Add needed a2l includes for this core here


// Generate entries for RTE types:
#include "Rte_Type.h"									// common
#include "Rte_Algo_Type.h"								// common


// Generate entries for SW types:
//#include "sw_meastypes.h"								// common

#if (A2L_CFG_MFC431 == 1)
// TODO add special MFC431 files here
#endif // (A2L_CFG_MFC431 == 1)

#if (A2L_CFG_HFL110 == 1)
// TODO add special HFL110 files here
#endif // (A2L_CFG_HFL110 == 1)


// Generate entries for EBA_Sen algo:
//#include "algo_type.h"									// common


// Generate entries for global scheduler:
//#include "common_scheduler_meas_types_pkg.h"	// common
