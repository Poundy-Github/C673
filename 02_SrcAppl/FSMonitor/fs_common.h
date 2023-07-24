#ifndef FS_COMMON_H
#define FS_COMMON_H

#define FS_LOG_ON 1

#include "utils/lsg_print.h"
#include "IfxStm_reg.h"
#define FS_ASSERT(__cond,msg) do{\
    FS_LOG_ERROR("%s",msg);\
    (void)(__cond);\
}while(0)

// #define FS_LOG_ERROR(fmt,...)   lsg_log_printf("[%ld]"fmt"\n" ,(STM0_TIM0.U)/100,##__VA_ARGS__)
// #define FS_LOG_WARNING(fmt,...) lsg_log_printf("[%ld]"fmt"\n" ,(STM0_TIM0.U)/100,##__VA_ARGS__)
// #define FS_LOG_INFO(fmt,...)    lsg_log_printf("[%ld]"fmt"\n" ,(STM0_TIM0.U)/100,##__VA_ARGS__)
// #define FS_LOG_DEBUG(fmt,...)   lsg_log_printf("[%ld]"fmt"\n" ,(STM0_TIM0.U)/100,##__VA_ARGS__)
#define FS_LOG_ERROR(fmt,...)   
#define FS_LOG_WARNING(fmt,...) 
#define FS_LOG_INFO(fmt,...)    
#define FS_LOG_DEBUG(fmt,...)   

#define fs_ret_code_t int
#define FS_RET_CODE_OK 0

#define FS_RET_CODE_ERROR 100

#define FS_FLAG_SET(flag,value)   (flag |= (value))
#define FS_FLAG_CLEAR(flag,value) (flag &= ~(value))

#endif