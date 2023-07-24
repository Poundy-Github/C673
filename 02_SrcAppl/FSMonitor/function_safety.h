#ifndef FUNCTION_SAFETY_H
#define FUNCTION_SAFETY_H

#include <stdbool.h>
#include "fs_boot.h"
#include "fs_config.h"
#include "Dem.h"

/* The enum used by FS_SetAppIsEOL */
#define eol_state_t int
/* A Default State of AppIsEOL,should not be unsed as param */
#define EOL_STATE_UNKNWON 0
/* The app is in EOL  */
#define EOL_STATE_ON 1
/* The app not in EOL  */
#define EOL_STATE_OFF 2

/* The states of All FSState */
enum fs_state_t {
    /* In safe silent,all can communication is disabled */
    FS_SAFE_SILENT,
    /* In safe communication,only default can data can be sent */
    FS_SAFE_COMMINUCATION,
    /* In safe silent,can communication not affected */
    FS_NORMAL_COMMINUCATION
};
/* The reset reason used by FS_MCUReset */
enum fs_reset_source_t{
    /** reset from non FS module,treat as normal reset */
    FS_RESET_SOURCE_APP = 0,
    /** reset from FS module,treat as CAT2 reset */
    FS_RESET_SOURCE_FS = 1,
    /** reset from WDG module,treat as CAT2 reset */
    FS_RESET_SOURCE_WATCH_DOG = 5,
    /** reset from UNKNWON,this should not be used,treat as normal reset */
    FS_RESET_SOURCE_OTHER
};
/**
 * @brief The init function of Function safety Module
 * 
 * It should be called from BSW,before any other function can be called
*/
void FS_Init(void);

/**
 * @brief The init function 2 of Function safety Module
 * 
 * It should be called from RTE Init
*/
void FS_RETInit(void);

/**
 * @brief Reset the MCU immediately
 * 
 * A sw reason should be provide.if a CAT2 reason is given
 * it will increase the CAT2 count
 * .
 * if a normal reset is reqeusted CAT2 count will be cleared.
 * 
 * @param source the reset reason;
 *              FS_RESET_SOURCE_APP is a normal reset;
 *              FS_RESET_SOURCE_FS is a abnormal reset from fs;
 *              FS_RESET_SOURCE_WATCH_DOG is a abnormal reset from wdg;
 * 
*/
void FS_MCUReset(enum fs_reset_source_t source);

/**
 * @brief Set the SoC pwr request to FS
 * 
 * FS will hold the request.And check current fs state.
 * after finish self test and no any cat3 error, the pwr on reqeust 
 * will be delivered to SoC.
 * 
 * If cat3 error happens, FS will cut off the pwr of SoC.
 * but as long as cat3 errors all recoveries,SoC will be pwred on again.
 * 
 * @param on_off true on SoC request;
 *               false turn offon SoC request
*/
void FS_SocPwrRequest(bool on_off);

/**
 * @brief Get The Current State of FS
 * 
 * The FSState includes
 *  FS_SAFE_SILINET,can communication should be disabled
 *  FS_SAFE_COMMUNICATION,can communication should only send default data
 *  FS_NORMAL_COMMUNICATION,can communication is nomal 
 * It is calculated by the internal state and external input of FS
 * 
 * @retval  one of FS_SAFE_SILENT,
            FS_SAFE_COMMINUCATION,
            FS_NORMAL_COMMINUCATION
*/
enum fs_state_t FS_FSState(void);

/**
 * @brief The Enterance of FS
 * 
 * The MainFunction is suppose to be called every 5ms
 * 
*/
void FS_MainFunction(void);

/**
 * @brief Tell FS if MCU is in EOl calibration mode
 * If so,a FS_SAFE_COMMUNICATION will be transition from FS_NORMAL_COMMUNICATION.
 * And only default can data can be sent;
 * 
 * @param eol_state EOL_STATE_UNKNWON 0
 *                  EOL_STATE_ON 1
 *                  EOL_STATE_OFF 2
*/
void FS_SetAppIsEOL(eol_state_t eol_state);

/**
 * @brief Post an event to FS that a CAT3 error has happend.
 * and the error is SOC PWM Error.
 * This will cause J3 shutdown immediately
 * This operation don't follow the shutdown sequence.
 * 
*/
void FS_PostCat3SOCPWMError(void);
/**
 * @brief Post an event to FS that a CAT3 error has recoveried.
 * and the error is SOC PWM Error.
 * This will cause J3 trying to power-on.
 * 
*/
void FS_RecoveryCat3SOCPWMError(void);


/**
 * @brief Return If FS have enter RTE phase
 * 
*/
bool FS_HasEnterRTE(void);

#if FS_FEATURE_CAN_TRCV_CONTROL
/**
 * @brief Supervise the Can Tranceiver Mode.
 * 
 * This function is supposed to replace `CanTrcv_8_Tja1043_SetOpMode`
 * in `output/generated/src/CanIf_Cfg.c`
 * 
 * It takes control of CanTrcv like `FS_SocPwrRequest`
 * FS will hold the request.And check current fs state.
 * after finish self test and no any cat3 error, the pwr on reqeust 
 * will be delivered to SoC.
 * 
 * @param CanTrcvIndex see `CanTrcv_8_Tja1043_SetOpMode`
 * @param OpMode see `CanTrcv_8_Tja1043_SetOpMode`
 * @retval see `CanTrcv_8_Tja1043_SetOpMode`
 * 
*/
Std_ReturnType FS_CanTrcv_SetOpMode(uint8 CanTrcvIndex, CanTrcv_TrcvModeType OpMode);

#endif /* FS_FEATURE_CAN_TRCV_CONTROL */



#if FS_FEATURE_CAN_DEFAULT_DATA_CONTROL
/**
 * @brief Supervise the Can Data transfered to CanIf.
 * 
 * This function is supposed to placed inside CanIf_Transmit in CanIf.c
 * 
 * It takes will replaced to Default Data when FSState is FS_SAFE_COMMINUCATION.
 * It looks up a configure table `s_can_default_data_table`inside,
 * if a pduid and pdulen matches.
 * The sending data will be replaced to default value
 * 
 * Nm Frame should not be affected.
 * 
 * @param CanTrcvIndex see `CanIf_Transmit`
 * @param OpMode see `CanIf_Transmit`
 * 
*/
void FS_CanIf_SupervisePduData(PduIdType CanTxPduId, PduInfoType *PduInfoPtr);
#endif /* FS_FEATURE_CAN_DEFAULT_DATA_CONTROL */

#endif /** FUNCTION_SAFETY_H */