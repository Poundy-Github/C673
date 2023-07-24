#ifndef sim_swc_vis_velodyne_version_h__
#define sim_swc_vis_velodyne_version_h__

#include "cct_ver.h"

#define VIS_VELODYNE_SW_MAIN_VER_NO  (1)
#define VIS_VELODYNE_SW_SUB_VER_NO   (0)
#define VIS_VELODYNE_SW_BUG_FIX_LEV  (0)
#define VIS_VELODYNE_SW_BUG_FIX_LEV2 (0)

#define VIS_VELODYNE_ALL_SW_VERSION_NUMBER ((VIS_VELOVISU_SW_MAIN_VER_NO<<24) | (VIS_VELOVISU_SW_SUB_VER_NO<<16) | (VIS_VELOVISU_SW_BUG_FIX_LEV<<8) | (VIS_VELOVISU_SW_BUG_FIX_LEV2))

#ifndef NDEBUG
#define VIS_VELODYNE_ALL_BUILD CCT_CHECKPOINT "DEBUG"
#else
#define VIS_VELODYNE_ALL_BUILD CCT_CHECKPOINT "RELEASE"
#endif

#endif // sim_swc_vis_velodyne_version_h__
