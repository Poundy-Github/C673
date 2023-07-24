/**
 * \file   FsMonitor.c.c
 *
 * \brief  Configuration data and stubs function of function Safety.
 *
 * \version refer the function_safety.h.
 *
 * \copyright  2022 - 2023 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Rte_FSMonitor.h>
#include "function_safety.h"
#include "WdgM_Cfg.h"
#include "exec/fs_catx.h"
#include "fs_pdo.h"
#include "fs_config.h"
#include "Cdd_Sbc_Cfg.h"


#define TASK_FUNCTIONAFETY_PERIOD             (5) //5ms

/*==================[internal data]=========================================*/
/*==================[.rodata]==============================*/
const volatile uint16 c_Fs_watchdogrefreshTime = 350; //350ms

/*==================[.data]===============================*/
static Boolean b_FS_FirstEntry = TRUE;

/*==================[external data]=========================================*/


/*==================[internal function declarations]========================*/
static void Fs_HardWatchDogRefresh(void);

/*==================[external function definitions]=========================*/
/**
 * \functions FSMonitor_InitFunction
 *
 * \brief The intial function of Function Safety.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none,
 * \comments
 *
 */
FUNC(void, RTE_CODE) FSMonitor_InitFunction (void)
{  
  b_FS_FirstEntry = TRUE;
  
  FS_RETInit();
  /*Set FS8435 WD Period upwindow 512ms*/  
  (void)FS8x_WriteRegisterInit(&fs8400drvData, FS8X_FS_WD_WINDOW_ADDR, (WD_PERIOD | FS8X_FS_WDW_DC_50 | FS8X_FS_WDW_RECOVERY_DISABLE));
  (void)sbcInitClose(&fs8400drvData);  //Closes INIT_FS by the first WD refresh

} /* FUNC(void, RTE_CODE) FSMonitor_InitFunction (void) */

/**
 * \functions FSMonitor_MainFunction
 *
 * \brief The runtime function of Function Safety.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none,
 * \comments
 *
 */
FUNC(void, RTE_CODE) FSMonitor_MainFunction (void)
{	 
#if FS_PDO_ENABLED
    uint8 ui8_status = 0;
#endif /** FS_PDO_ENABLED */

    if(b_FS_FirstEntry == TRUE)
    {
        (void)WdgM_SetMode(WdgMConf_WdgMMode_WDGM_NORMAL_OPERATION);
        b_FS_FirstEntry = FALSE;
    }
    else
    {
        FS_MainFunction();   
    }
  
#if FS_PDO_ENABLED  
    FS_Pdo_MainFunction();
    for(uint8 ui8_seid = 0; ui8_seid <= 5; ui8_seid++)
    {
        WdgM_GetLocalStatus(ui8_seid, &ui8_status);
        if((0 != ui8_status)&&(4 != ui8_status)) // refer to WDGM_LOCAL_STATUS_OK
        {
            g_fs_debug_status.wdgm_status[ui8_seid] = ui8_status;
        }
    }
    g_fs_debug_status.cat2_count = g_fs_cat2_count;
#endif /** FS_PDO_ENABLED */

    Fs_HardWatchDogRefresh();
} /* FUNC(void, RTE_CODE) FSMonitor_MainFunction (void) */

/**
 * \functions Fs_HardWatchDogRefresh
 *
 * \brief The runtime function of Watch dog refresh.
 *
 ** \param[in] none,
 *
 ** \param[out] none,
 *
 ** \return none,
 * \comments
 *
 */
static void Fs_HardWatchDogRefresh(void)
{
    static uint8 ui8_Wd_RefreshCnt = 0;
    /*FS8435 watchdog refresh*/
	ui8_Wd_RefreshCnt++;

	if((ui8_Wd_RefreshCnt % (c_Fs_watchdogrefreshTime/TASK_FUNCTIONAFETY_PERIOD)) == 0u) //350ms refresh WD
	{
	    ui8_Wd_RefreshCnt = 0u;
        //SuspendAllInterrupts();
		FS8x_WD_Refresh(&fs8400drvData);
        //ResumeAllInterrupts();
        FS8X_WD_Refresh_Judge(&fs8400drvData, (WD_PERIOD | FS8X_FS_WDW_DC_50 | FS8X_FS_WDW_RECOVERY_DISABLE));
	}

}