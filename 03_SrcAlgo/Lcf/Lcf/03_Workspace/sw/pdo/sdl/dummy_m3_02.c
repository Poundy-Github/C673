/*
 * This is a dummy C file, which is used to generate an SDL with the PDO-Tool.
 */
 
#define CORE_M3_0
#define BIT_FIELD_MSB_FIRST  0

// Generate entries for RTE types:
#include "Rte_Type.h"
#include "Rte_Ext_Type.h"

#include "algo_cfg.h"

// Generate entries for EBA_Sen algo:
#include "algo_type.h"

#if (PDO_CFG_HFL110 == 0)
#include "cd.h"
#include "cp_fusion_trace.c"
#include "cp_main.c"
#include "fip_navi_data_plg.c"
#include "cd_wrapper.c"
#endif // (PDO_CFG_HFL110 == 0)

#if (CFG_MFC_VISION_LOW == 1) //ARS441
#include "cp_trajectory.c"
#include "fip_camera_lane_plg.c"
#include "fip_lane_matrix_plg.c"
#include "fip_navi_data_process.c"
#include "fip_road_type.c"
#include "fip_traffic_orientation.c"
#endif

#if (PDO_CFG_HFL110 == 0)
#include "fct_meas.c"
#include "fct_sen.h"
#include "fct_sen_main.c"
#endif // (PDO_CFG_HFL110 == 0)

//If config switch does not exist default to Veh-Task
#if !defined(FCT_CFG_UDW_PROCESSING_VEH)
#define FCT_CFG_UDW_PROCESSING_VEH SWITCH_ON
#endif

#if ((FCT_CFG_UDW_PROCESSING_VEH != SWITCH_ON) && (CFG_MFC_VISION_LOW == 0))
#include "udw.h"
#include "udw_debug.h"
#endif  

#if ((PDO_CFG_MFC431 == 0) && (PDO_CFG_HFL110 == 0))
#include "si_acc_function_presel.c"
#include "si_calc_cutin_pot.c"
#include "si_corridor_crit.c"
#include "si_lanechange.c"
#include "si_main.c"
#include "si_objscore.c"
#include "si_output.c"
#include "si_traffic_density.c"

#include "spm_main.c"
#include "spm_objectloss.c"

#include "cp_si.c"
#endif // (PDO_CFG_MFC431 == 0) && (PDO_CFG_HFL110 == 0)

#if (CFG_MFC_VISION_LOW == 1) //ARS441
//FCT
#include "si_corridor.c"
#include "si_corridor_cam.c"
#include "si_corridor_scene.c"
#include "si_traffic_estimation.c"

// EM
#include "dapveh_wrapper.c"
#include "dap_wrapper.c"
#include "ec_wrapper.c"
#include "gp_wrapper.c"
#include "od_wrapper.c"
#include "pcc_wrapper.c"
#include "vc_wrapper.c"

// RD
#include "rd_wrapper.c"

// GFRS
#include "gfrs_wrapper.c"

// PD
#include "pd_wrapper.c"

// FPS
#include "fps_wrapper.c"
#endif

#if (PDO_CFG_HFL110 == 0)
#include "frame_sen_custom_types.h"
#endif // (PDO_CFG_HFL110 == 0)

