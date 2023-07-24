/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "exec/fs_catx.h"
#include "exec/fs_mcu.h"
#include "esm/fs_adc.h"
#include "Mcu_Cfg.h"
#include "Mcu.h"
#include "fs_common.h"
#include "fs_config.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------TYEP DEFINITION-------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/
#define FS_START_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"


#define FS_STOP_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"

#pragma section farbss "log.g_lsg_log"
struct lsg_log_t g_lsg_log;
#pragma section farbss restore

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Static Function----------------------------------*/
/******************************************************************************/
#define FS_START_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

static Std_ReturnType s_kl15_value(float *kl15)
{
    /** do a filter */
    #define LEAST_IGN_CYCLE 64
    #define LEAST_IGN_LOW_CRITICAL_VALUE 6.0f

    Std_ReturnType ret;

    static uint8_t read_ign_times = 0;
    static float last_ign = 0;
    float ign = false;

    FSAdc_SelfCheckMainFunction();
    
    /** this function actually return the bool value */
    boolean res = (boolean)FSAdc_ReadChannel(FS_ADC_CHANNEL_VOLT_IGN,&ign);
    if(res == true){
        /*
        *
        * when last_ign = 12V
        * and ign drop to 0V immediately.
        * The function degraded to 
        * IGN=12*0.98^x
        * 
        * To calc the time that IGN to drop to half;
        * the equation is:
        * 
        * 1/2=0.98^x
        * x=ln(1/2)/ln(0.98)
        * x≈34.31
        * 
        * So it needs to iterate at least 35 cycles to detect 
        * IGN drop below 6V
        * 
        * 
        * Each cycle is considered to take 100us
        * So the detected-out time is roughly 3.5ms( ± 1.5ms).
        * 
        * Actually the voltage won't drop so fast.
        * The detectd-out time would be longger(and at most 
        * delayed 3.5ms after voltage drop to 6V in physical)
        * 
        */
        last_ign = last_ign * 0.98f + ign * 0.02f;
        
        if(read_ign_times < LEAST_IGN_CYCLE){
            read_ign_times++;
            ret = E_NOT_OK;
        }else{
            *kl15 = last_ign;
            ret = E_OK;
        }
    }else{
        /** 
         * doing nothing
         * this case should not happen 
         */
        ret = E_NOT_OK;
    }
    /** do a slight busy wait */
    for(int i = 0;i < 2;i++){
        FSAdc_MainFunction();
    }
    return ret;
}

/******************************************************************************/
/*-------------------------Global Function----------------------------------*/
/******************************************************************************/

void FS_Boot(void)
{
#if FS_LOG_ON
    lsg_log_init(&g_lsg_log,0);
    lsg_log_set_gloabl(&g_lsg_log);
    lsg_log_printf("init...\n");
#endif 
    FSCat_Init();

    FS_LOG_DEBUG("Last Reset Reason=%d",FSCat_LastResetReason());

    FSCat_SetResetReason(FS_CAT_RESET_REASON_UNKNOWN);

}
#include "sbc_fs8x.h"
#include "sbc_fs8x_common.h"
extern fs8x_drv_data_t* fs8400drvData;
void FS_BootEndlessModeCheck(void){
#if FS_EXEC_DISABLED 
    return;
#endif /* FS_EXEC_DISABLED */
    {
        float ign = 12.0;
        Std_ReturnType ret;
        uint32_t count = 0;
        do{
            ret = s_kl15_value(&ign);
            count++;
            if(count > 10000){
                /* read adc failed, goto app however*/
                break;
            }
        }while(ret != E_OK);
        
        if( ign < LEAST_IGN_LOW_CRITICAL_VALUE ){
            FS_LOG_DEBUG("%s","Boot:KL15 low");
            FSCat_Cat2CountReset();
        }
    }

    FS_LOG_DEBUG("Cat2_Count=%d",FSCat_Cat2Count());

    if( FSCat_Cat2Count() < 3){
        return ;
    }

    // safe state
    FS_LOG_DEBUG("%s","Enter endless mode");

    /**
     * This function is to doing a endless loop.
     * The endless is suppose to maintain until ign off.
     * 
     * So at each loop, IGN value is read;
     * A reset is performed while the IGN belows the criticle 
     * level(As Ign off is recognized )
     * 
     * A smooth filter is applied to ign value.
     * 
    */
   	//SuspendAllInterrupts();
    
	FS8x_WD_Refresh(&fs8400drvData);	//Refresh wd make sure the WD refresh time in 256ms.
	GOTO_INITFS(&fs8400drvData);		//FS8435 goto INITFS function
	Disable_WD(&fs8400drvData);		//FS8435 disable WD
	sbcInitClose(&fs8400drvData);	//FS8435 first WD refesh and exit INITFS

    float ign;
    Std_ReturnType ret;
    float last_ign = 0;
    uint32_t fault_count = 0;
    while(1){
   	    //EnableAllInterrupts();
        ret = s_kl15_value(&ign);
   	    //SuspendAllInterrupts();

        if(ret == E_OK){
            float diff = last_ign - ign;
            if( diff * (diff > 0?1:-1) < 0.0001 ){
                fault_count ++;    
            }else{
                fault_count = 0;
                last_ign = ign;
            }
            if(ign < LEAST_IGN_LOW_CRITICAL_VALUE){
                FS_LOG_DEBUG("%s","EndlessMode:KL15 low");
                FSCat_Cat2CountReset();
                FSExec_McuReset();
            }
        }else if(ret == E_NOT_OK){
            /** read failed */
            fault_count ++;

        }
        
        /** 
         * if ign value is same 10000 times or
         * read failed for 10000 times.
         * considering ADC module is die
         * reset immediately
         * around 1s
         */
        if(fault_count > 10000){
            FS_LOG_DEBUG("%s","EndlessMode:ADC Error");
            FSCat_Cat2CountReset();
            FSExec_McuReset();
        }

    }
}
#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"