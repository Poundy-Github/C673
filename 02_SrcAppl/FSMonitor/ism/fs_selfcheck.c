/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "Mcu.h"				/* invoke Mcu_GetRamState() */
#include "Wdg_17_Scu.h"			/* invoke Wdg_17_Scu_InitCheck() */
#include "Cdd_HeartbeatDet.h" 	/* invoke Cdd_HeartbeatDet_GetDetState() */
#include "Fls_17_Dmu.h" 		/* type of FLS_17_DMU_xx */
//#include "Com_Version.h" 		/* type of COM_MODULE_ID */
//#include "Com_Api_Static.h" 	/* type of COM_E_xx */
#include "IfxDmu_reg.h"
#include "esm/fs_adc.h"
#include "exec/fs_exec.h"
#include "IfxPort_reg.h"
#include "Sdc_Diag.h"


/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

// battery volatage and temperature max check times
#define FS_SELFCHECK_VBAT_TEMP_CHECK_TIMES      10

#define FS_SELFCHECK_ERROR_MASK_VBAT_HIGH       FS_SELF_TEST_ERROR_FLAG_UBATT_HIGHT
#define FS_SELFCHECK_ERROR_MASK_VBAT_LOW        FS_SELF_TEST_ERROR_FLAG_UBATT_LOW
#define FS_SELFCHECK_ERROR_MASK_MCU_TEMP_HIGH   FS_SELF_TEST_ERROR_FLAG_MCUTEMP_HIGH
#define FS_SELFCHECK_ERROR_MASK_MCU_TEMP_LOW    FS_SELF_TEST_ERROR_FLAG_MCUTEMP_LOW
#define FS_SELFCHECK_ERROR_MASK_RAM             FS_SELF_TEST_ERROR_FLAG_RAM
#define FS_SELFCHECK_ERROR_MASK_FLASH           FS_SELF_TEST_ERROR_FLAG_DATA_FLASH
#define FS_SELFCHECK_ERROR_MASK_WDG             FS_SELF_TEST_ERROR_FLAG_WDG
#define FS_SELFCHECK_ERROR_MASK_COM             FS_SELF_TEST_ERROR_FLAG_COM


// The start address of data flash
//#define FS_FLS_DFLASH_START_ADDR        (FLS_17_DMU_BASE_ADDRESS + 0)
// The end address of data flash
//#define FS_FLS_DFLASH_END_ADDR          0xAF07FFFF
// the ECC bit error status
//#define FS_FLS_BIT_ERROR                (0x00080000U)

// The max battery voltage
#define FS_SELFCHECK_VBAT_HIGH_THSLD    (28.0f)
// The min battery voltage
#define FS_SELFCHECK_VBAT_LOW_THSLD     (6.0f)
// The max mcu temperature
#define FS_SELFCHCEK_TEMP_HIGH_THSLD    (120.0f)
// The min mcu temperature
#define FS_SELFCHCEK_TEMP_LOW_THSLD     (-40.0f)

// Error increment times 
#define FS_SELFCHECK_ERROR_TIMES_INCREASE           1
// battery voltage max error times
#define FS_SELFCHECK_VBAT_MAX_ERROR_TIMES           2
// mcu temperature max error times
#define FS_SELFCHECK_MCU_TEMP_MAX_ERROR_TIMES       2


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

static volatile boolean FSSelfCheck_ComIsError = FALSE;
static volatile uint32 FSSelfCheck_Flag = 0;

#define FS_STOP_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"


/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
extern const Wdg_17_Scu_ConfigType Wdg_17_Scu_Config_0;

/******************************************************************************/
/*-------------------------Static Function----------------------------------*/
/******************************************************************************/
#define FS_START_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

/**
 * \functions FSSelfCheck_RamError
 *
 * \brief Used to check RAM status at startup
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return  FALSE - RAM contents are valid
 *          TRUE  - RAM contents got corrupted
 *
 * \comments:
 *
 */
#if 0
static boolean FSSelfCheck_RamError(void)
{
    /* This service provides the actual status of the microcontroller Ram. */
    Mcu_RamStateType RamCheckRetVal = MCU_RAMSTATE_INVALID;
    RamCheckRetVal =  Mcu_GetRamState();
    
    if(MCU_RAMSTATE_INVALID == RamCheckRetVal)
    {
        return TRUE;
    }
    return FALSE;
}
#endif

/**
 * \functions FSSelfCheck_FlashError
 *
 * \brief Used to check Data Flash status at startup by ECC
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return  FALSE - DFlash is normal
 *          TRUE  - DFlash is error
 *
 * \comments:
 *
 */
#if 0
static boolean FSSelfCheck_FlashError(void)
{
    uint32 RetVal = 0;

    /* check the ECC bit error status.*/
    RetVal = ((uint32)DMU_HF_ECCS.U & FS_FLS_BIT_ERROR);
    if(RetVal != 0)
    {
        return TRUE;
    }
    return FALSE;
}
#endif

/**
 * \functions FSSelfCheck_WdgError
 *
 * \brief Used to check watch dog status at startup
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return  FALSE - WDG initialization was successful
 *          TRUE  - WDG initialization was not successful
 *
 * \comments:
 *
 */
static boolean FSSelfCheck_WdgError(void)
{
    /* check if softwdg init ok*/
    Std_ReturnType WdgCheckRetVal = (Std_ReturnType)E_NOT_OK;
    const Wdg_17_Scu_ConfigType * ConfigPtr = &Wdg_17_Scu_Config_0;
    WdgCheckRetVal =  Wdg_17_Scu_InitCheck(ConfigPtr);
    if(E_NOT_OK == WdgCheckRetVal)
    {
        return TRUE;
    }
    return FALSE;
}

/**
 * \functions FSSelfCheck_ComError
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 
 *
 * \comments:
 *
 */
static boolean FSSelfCheck_ComError(void)
{
    return FSSelfCheck_ComIsError;
}

/**
 * \functions FSSelfCheck_VBatTooHigh
 *
 * \brief Used to check the high battery voltage during startup
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return  FALSE - Battery voltage is normal
 *          TRUE  - Battery voltage is too high
 *
 * \comments:
 *
 */
static boolean FSSelfCheck_VBatTooHigh(void)
{
    static uint16 errorTime = 0;
    float vbat = 0.0f;
    boolean ret = FALSE;

    // Read Adc success
    if(TRUE == FSAdc_ReadChannel(FS_ADC_CHANNEL_VOLT_BATT, &vbat)) {
        // Check whether the voltage is too high
        if(vbat > FS_SELFCHECK_VBAT_HIGH_THSLD) {
            // Error timing
            errorTime += FS_SELFCHECK_ERROR_TIMES_INCREASE;
            // Check whether the error times more than max times
            if(errorTime >= FS_SELFCHECK_VBAT_MAX_ERROR_TIMES) {
                errorTime = FS_SELFCHECK_VBAT_MAX_ERROR_TIMES;
                ret = TRUE;
            }
        } else {
            errorTime = 0;
            ret = FALSE;
        }
    }
    return ret;
}

/**
 * \functions FSSelfCheck_VBatTooLow
 *
 * \brief Used to check the low battery voltage during startup
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return  FALSE - battery voltage is normal
 *          TRUE  - battery voltage is too low
 *
 * \comments:
 *
 */
static boolean FSSelfCheck_VBatTooLow(void)
{
    static uint16 errorTime = 0;
    float vbat = 0.0f;
    boolean ret = FALSE;

    // Read Adc success
    if(TRUE ==FSAdc_ReadChannel(FS_ADC_CHANNEL_VOLT_BATT, &vbat)) {
        // Check whether the voltage is too low
        if(vbat < FS_SELFCHECK_VBAT_LOW_THSLD) {
            // Error timing
            errorTime += FS_SELFCHECK_ERROR_TIMES_INCREASE;
            // Check whether the error times more than max times
            if(errorTime >= FS_SELFCHECK_VBAT_MAX_ERROR_TIMES) {
                errorTime = FS_SELFCHECK_VBAT_MAX_ERROR_TIMES;
                ret = TRUE;
            }
        } else {
            errorTime = 0;
            ret = FALSE;
        }
    }
    return ret;
}

/**
 * \functions FSSelfCheck_McuTempTooHigh
 *
 * \brief Used to check the high temperature of mcu during startup
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return  FALSE - the mcu temperature is normal
 *          TRUE  - the mcu temperature is too high
 *
 * \comments:
 *
 */
static boolean FSSelfCheck_McuTempTooHigh(void)
{
    static uint16 errorTime = 0;
    float temp = 0.0f;
    boolean ret = FALSE;

    // Read Adc success
    if(TRUE == FSAdc_ReadChannel(FS_ADC_CHANNEL_TEMP_MCU_EXT, &temp)) {
        // Check whether the mcu temperature is too high
        if(temp > FS_SELFCHCEK_TEMP_HIGH_THSLD) {
            // Error timing
            errorTime += FS_SELFCHECK_ERROR_TIMES_INCREASE;
            // Check whether the error times more than max times
            if(errorTime >= FS_SELFCHECK_MCU_TEMP_MAX_ERROR_TIMES) {
                errorTime = FS_SELFCHECK_MCU_TEMP_MAX_ERROR_TIMES;
                ret = TRUE;
            }
        } else {
            errorTime = 0;
            ret = FALSE;
        }
    }
    return ret;
}

/**
 * \functions FSSelfCheck_McuTempTooLow
 *
 * \brief Used to check the low temperature of mcu during startup
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return  FALSE - the mcu temperature is normal
 *          TRUE  - the mcu temperature is too low
 *
 * \comments:
 *
 */
static boolean FSSelfCheck_McuTempTooLow(void)
{
    static uint16 errorTime = 0;
    float temp = 0.0f;
    boolean ret = FALSE;

    // Read Adc success
    if(TRUE == FSAdc_ReadChannel(FS_ADC_CHANNEL_TEMP_MCU_EXT, &temp)) {
        // Check whether the mcu temperature is too low
        if(temp < FS_SELFCHCEK_TEMP_LOW_THSLD) {
            // Error timing
            errorTime += FS_SELFCHECK_ERROR_TIMES_INCREASE;
            // Check whether the error times more than max times
            if(errorTime >= FS_SELFCHECK_MCU_TEMP_MAX_ERROR_TIMES) {
                errorTime = FS_SELFCHECK_MCU_TEMP_MAX_ERROR_TIMES;
                ret = TRUE;
            }
        } else {
            errorTime = 0;
            ret = FALSE;
        }
    }
    return ret;
}

/******************************************************************************/
/*-------------------------Global Function----------------------------------*/
/******************************************************************************/

/**
 * \functions FSSelfCheck_MainFunction
 *
 * \brief Used to check Ram, Dflash, Wdg, Com, Battery voltage, Mcu temperature during startup. 
 *        And report the selfcheck status to EXEC in the end.
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments:
 *
 */
void FSSelfCheck_MainFunction(void)
{  
	uint32 ui32_AdcCheckCnt = 0xFFu;
	
    FSSelfCheck_Flag = 0;

    do 
	{
	    ui32_AdcCheckCnt--;

		FSAdc_SelfCheckMainFunction();
		
		if(TRUE == FSSelfCheck_VBatTooHigh()) 
		{
			FSSelfCheck_Flag |= FS_SELFCHECK_ERROR_MASK_VBAT_HIGH;
		} 
		else if(TRUE == FSSelfCheck_VBatTooLow()) 
		{
			FSSelfCheck_Flag |= FS_SELFCHECK_ERROR_MASK_VBAT_LOW;
		}
		
		if(TRUE == FSSelfCheck_McuTempTooHigh())
		{
			FSSelfCheck_Flag |= FS_SELFCHECK_ERROR_MASK_MCU_TEMP_HIGH;
		} 
		else if(TRUE == FSSelfCheck_McuTempTooLow()) 
		{
			FSSelfCheck_Flag |= FS_SELFCHECK_ERROR_MASK_MCU_TEMP_LOW;
		}

    }while((FSSelfCheck_Flag == 0) && (ui32_AdcCheckCnt != 0));

    //if(TRUE == FSSelfCheck_FlashError()) {
    //     FSSelfCheck_Flag |= FS_SELFCHECK_ERROR_MASK_FLASH;
    //}

    //if(TRUE == FSSelfCheck_RamError()) {
    //     FSSelfCheck_Flag |= FS_SELFCHECK_ERROR_MASK_RAM;
    //}

    if(TRUE == FSSelfCheck_WdgError()) 
	{
        FSSelfCheck_Flag |= FS_SELFCHECK_ERROR_MASK_WDG;
    }

    if(TRUE == FSSelfCheck_ComError()) 
	{
        FSSelfCheck_Flag |= FS_SELFCHECK_ERROR_MASK_COM;
    }
}

/**
 * \functions FSSelfCheck_Finish
 *
 * \brief Used to report selfcheck result to FSExec
 *
 * \parameters-in  none
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments:
 *
 */
void FSSelfCheck_Finish(void)
{
    FSExec_FinishSelfTest(FSSelfCheck_Flag);
}

/**
 * \functions FsCom_DetCallback
 *
 * \brief Used to check if the communication can be done in safe condition.
 *
 * \parameters-in   ModuleId
 *                  InstanceId
 *                  ApiId
 *                  ErrorId
 *
 * \parameters-out none
 *
 * \return
 *
 * \comments: This function will be called when development error report to DET.
 *
 */
#if 0
void FsCom_DetCallback(uint16 ModuleId,uint8 InstanceId,uint8 ApiId,uint8 ErrorId)
{
    if(COM_MODULE_ID == ModuleId)
    {
        /* select condition communiction can not be done */
        if(COM_E_UNINIT == ErrorId || COM_E_PARAM_POINTER == ErrorId || COM_E_PARAM == ErrorId)
        {
            FSSelfCheck_ComIsError = TRUE;
        }
    }
    else
    {
        /* nothing to do */
    }
}
#endif


#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"
