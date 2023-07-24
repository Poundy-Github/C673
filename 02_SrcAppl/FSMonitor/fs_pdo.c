#include "fs_pdo.h"
#include "TSMem.h"
#include "algo_service_types.h"
#include "fs_config.h"
// #if FS_PDO_ENABLED
#define __PDO__
// #endif

#define SDC_MEAS_ADDR_FS_STATUS    (0xB0003000u)
#define SDC_MEAS_ADDR_FS_CAT3      (0xB0004000u)
// #define SDC_MEAS_ADDR_FSAdcInfo    (0xB0005000u)



#ifdef __PDO__
/****** Sdc ******/
/*! @VADDR: SDC_MEAS_ADDR_FS_STATUS       @CYCLEID: CycleId_110 */
typedef FSDebugStateus Sdc_fs_debug_status;
/*! @VADDR: SDC_MEAS_ADDR_FS_CAT3        @CYCLEID: CycleId_110 */
typedef FSCat Sdc_cat_data;
/*! @VADDR: SDC_MEAS_ADDR_FSAdcInfo        @CYCLEID: CycleId_110 */
// typedef tFSAdcInfo Sdc_FSAdcInfo[8];
#endif

#define FS_START_SEC_VAR_NON_CLEARED
#include "Fs_MemMap.h"
#if FS_PDO_ENABLED
/*transfer data to MTS*/
struct fs_debug_status_t g_fs_debug_status;
#endif /** FS_PDO_ENABLED */
#define FS_STOP_SEC_VAR_NON_CLEARED
#include "Fs_MemMap.h"
void FS_Pdo_MainFunction(void)
{   
#if FS_PDO_ENABLED
    static int s_time = 0;
    if(s_time == 0){
        (void)MTSI_DriverStartTaskCycle(110);
        MEASInfo_t meas_info;
        meas_info.VirtualAddress = SDC_MEAS_ADDR_FS_STATUS;
        meas_info.Length = sizeof(g_fs_debug_status);
        meas_info.FuncID = 110;
        MEASFreezeDataMTS(&meas_info, &g_fs_debug_status, NULL_PTR);

        meas_info.VirtualAddress = SDC_MEAS_ADDR_FS_CAT3;
        meas_info.Length = sizeof(s_cat_data);
        meas_info.FuncID = 110;
        MEASFreezeDataMTS(&meas_info, &s_cat_data, NULL_PTR);
    }
    s_time = (s_time + 1 ) % 4;
#endif /** FS_PDO_ENABLED */
}

