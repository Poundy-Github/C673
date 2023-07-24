/*
 * This is a dummy C file, which is used to generate an SDL with the PDO-Tool.
 */
 
#define CORE_M3_0
#define BIT_FIELD_MSB_FIRST  0

// Generate entries for RTE types:
#include "Rte_Type.h"
#include "Rte_Ext_Type.h"

// Generate entries for SW types:
#include "sw_meastypes.h"

// Generate entries for RTA types:
#include "RTA.h"

// Generate entries for RTL types:
#include "rtl_senslog.h"

// Generate entries for VDY algo:
#include "vdy_main.c"
#include "vdy_ay_swa.c"
#include "vdy_mon.c"
#include "vdy_velcor.c"
#include "vdy_whs.c"
#include "vdy_ywr.c"
#include "vdy_ywrt.c"
#include "vdy_ext.h"

#if ((CFG_MFC_VISION_LOW == 0) && (PDO_CFG_HFL110 == 0))
// Not for HFL110 and not for ARS441
// Generate entries for FCT (EBA) algo
#include "dim_wrapper.c"
#endif

#if (PDO_CFG_HFL110 == 0)
// Not for HFL110
// Generate entries for FCT (EBA) algo
#include "dim_main.c"
#include "fct_veh.h"
#include "fct_veh_main.c"
#include "head_mts.h"
#include "cd_wrapper.c"
#endif

#if (CFG_MFC_VISION_LOW == 1)
#include "cp_cd_par.c"
#include "head_codingSwitches.c"
#include "head_wrapper.c"
#include "fct_long_veh_customfunctions.c"
#include "fct_long_sen.c"
#endif

#if (PDO_CFG_HFL110 == 0)
#include "fct_config.h"
#endif // (PDO_CFG_HFL110 == 0)

#if (PDO_CFG_MFC431 == 1)
#include "udw_frame_main.c"
#include "udw_daw_wrapper.c"
#include "udw_pdo_tags_file.c"
#include "udw_debug.h"
#endif

//If config switch does not exist default to Veh-Task
#if !defined(FCT_CFG_UDW_PROCESSING_VEH)
#define FCT_CFG_UDW_PROCESSING_VEH SWITCH_ON
#endif

#if ((FCT_CFG_UDW_PROCESSING_VEH == SWITCH_ON) && (PDO_CFG_HFL110 == 0) && (PDO_CFG_MFC431 == 0))
#include "udw.h"
#include "udw_debug.h"
#endif  

#if ((CFG_MFC_VISION_LOW == 0) && (PDO_CFG_MFC431 == 0) && (PDO_CFG_HFL110 == 0))
// Include only on MFC400
// Generate entries for EBA_Veh algo:
#include "head_autocode_cfg.h"
#include "head_wrapper.c"
#include "head_mts.h"

#endif // ((CFG_MFC_VISION_LOW == 0) && (PDO_CFG_MFC431 == 0) && (PDO_CFG_HFL110 == 0))



// Generate entries for global scheduler:
#include "gs_meas_types.h"

// Generated module and error ids
#include "xdc_module_and_error_ids.h"
