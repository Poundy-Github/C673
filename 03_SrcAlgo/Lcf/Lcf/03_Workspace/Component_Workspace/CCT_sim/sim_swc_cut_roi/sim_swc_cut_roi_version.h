#ifndef sim_swc_vis_colored_image_version_h__
#define sim_swc_vis_colored_image_version_h__

#include "cct_ver.h"

#define CUT_ROIALL_SW_MAIN_VER_NO  (1)
#define CUT_ROIALL_SW_SUB_VER_NO   (0)
#define CUT_ROIALL_SW_BUG_FIX_LEV  (0)
#define CUT_ROIALL_SW_BUG_FIX_LEV2 (0)

#define CUT_ROIALL_SW_VERSION_NUMBER ((CUT_ROIALL_SW_MAIN_VER_NO<<24) | (CUT_ROIALL_SW_SUB_VER_NO<<16) | (CUT_ROIALL_SW_BUG_FIX_LEV<<8) | (CUT_ROIALL_SW_BUG_FIX_LEV2))

#ifndef NDEBUG
#define CUT_ROIALL_BUILD CCT_CHECKPOINT "DEBUG"
#else
#define CUT_ROIALL_BUILD CCT_CHECKPOINT "RELEASE"
#endif

#endif // sim_swc_vis_colored_image_version_h__
