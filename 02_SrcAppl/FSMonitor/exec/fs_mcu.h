#ifndef FS_MCU_H
#define FS_MCU_H

#include <stdint.h>
#include <stdbool.h>
#include "fs_exec.h"
#include "fs_common.h"
#include "exec/fs_catx.h"

#define CAN_DEFAULT_DATA_MAX_SIZE                (8u) 


struct fs_can_data_t
{
	uint32_t pduid;
	uint16_t len;
	uint8_t  data[CAN_DEFAULT_DATA_MAX_SIZE];
};


#define FS_START_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

/**
 * @brief The Fusa of Mcu side init 
*/
extern void FSExec_McuInit(void);
/**
 * @brief request MCU to reset 
*/
extern void FSExec_McuReset(void);
/**
 * @brief replace can data to default data
 * 
 * @note this function is not used
*/
extern void FSExec_FillDefaultCanData(uint32_t pduid,uint8_t *data,uint16_t len);
/** 
 * @brief Set the FS internal request to CAN Tranceiver
 * 
 * FS Exec will set the Can Tranceiver State as possible as the 
 * current FS_STATE allows.
 * 
 * @param disable true:to disable can communication,false:to enable
 */
extern void  FSExec_DisableCan(bool disable);
/** 
 * @brief Tell Exec App needs to Set the can trcv mode
 * 
 * FSExec takes control of Can Tranceiver.
 * It only remembers the external disabled request.
 * 
 * And FS Exec will set the Can Tranceiver State as possible as the 
 * current FS_STATE allows.
 * 
 * @param OpMode the requested OP Mode
 * @return if set succesfully which current state didn't block the request return OK
 *          else return false
 */
extern Std_ReturnType FSExec_AppSetCanTrcvMode( CanTrcv_TrcvModeType OpMode);

#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

#endif /** FS_MCU_H */