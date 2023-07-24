#ifndef FS_PDO_H
#define FS_PDO_H

#include "Std_Types.h"
#include "fs_config.h"

// #if FS_PDO_ENABLED
#define FS_RS_NO 0
#define FS_RS_WATCHDOG 1
#define FS_RS_PROTECTION_HOOK 2
#define FS_RS_REGISTER_CHECK 3
#define FS_RS_SPI 4
#define FS_RS_ESM 5
#define FS_RS_EcumSwitchOff	6
#define FS_RS_Refresh_Judge 7
#define FS_RS_BswM_GoOffA	8
#define FS_RS_WdgM_PerformReset 9
#define FS_RS_WdgM_EB_SetGlobalStatus 10
struct fs_debug_status_protection_info_t{
    uint16 coreid;
    uint16 taskid;
};

struct fs_debug_status_t{

    uint32 cat2_count;
    uint32 reset_source_fs_count;
    uint32 cat3_record_post[8];
    uint32 cat3_record_post_count;
    uint32 selfcheck_result[8];
    uint32 selfcheck_result_count;
    uint32 reset_counter;
    struct fs_debug_status_protection_info_t protection_info[8];
    uint8  wdgm_status[8];
    uint8 reset_source_fs[32];
    uint8 reset_reasonlist[8];
};

typedef struct fs_debug_status_t FSDebugStateus;
extern struct fs_debug_status_t g_fs_debug_status;

#define fs_catx_id_t uint32
struct fs_cat_t{
    fs_catx_id_t cat3s[16];
};

extern struct fs_cat_t s_cat_data;
typedef struct fs_cat_t FSCat;
typedef struct
{
    uint32   Status;
    float   Value;
}tFSAdcInfo;

extern tFSAdcInfo FSAdcInfo[8];
// #endif /** FS_PDO_ENABLED */
void FS_Pdo_MainFunction(void);
#endif /* FS_PDO_H */