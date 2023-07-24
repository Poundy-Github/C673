#ifndef CDD_UCB_CFG_H_
#define CDD_UCB_CFG_H_


#include "Platform_Types.h"
#include "Compiler.h"



/*busy wait time*/
#define UCB_DELAY_WAIT_UNBUSY_MAX           (3000000u)
/*passw*/
#define UCB_PASSWARD_PW0                    (0x00000000UL)
#define UCB_PASSWARD_PW1                    (0x00000001UL)
#define UCB_PASSWARD_PW2                    (0x00000002UL)
#define UCB_PASSWARD_PW3                    (0x00000003UL)
#define UCB_PASSWARD_PW4                    (0x00000004UL)
#define UCB_PASSWARD_PW5                    (0x00000005UL)
#define UCB_PASSWARD_PW6                    (0x00000006UL)
#define UCB_PASSWARD_PW7                    (0x00000007UL)
#define UCB_PFlash_PASSWARD_PW0             (0x00000000UL)
#define UCB_PFlash_PASSWARD_PW1             (0x00000000UL)
#define UCB_PFlash_PASSWARD_PW2             (0x00000000UL)
#define UCB_PFlash_PASSWARD_PW3             (0x00000000UL)
#define UCB_PFlash_PASSWARD_PW4             (0x00000000UL)
#define UCB_PFlash_PASSWARD_PW5             (0x00000000UL)
#define UCB_PFlash_PASSWARD_PW6             (0x00000000UL)
#define UCB_PFlash_PASSWARD_PW7             (0x00000000UL)

/** \brief user configuration block type
 */
typedef enum
{
    IfxFlash_UcbType_ucbRetest = 0x0Fu,   /**< \brief UCB for Re test */
    IfxFlash_UcbType_ucbPflash = 0x20u,  /**< \brief UCB for PFlash */
    IfxFlash_UcbType_ucbDflash = 0x11u,  /**< \brief UCB for DFlash */
    IfxFlash_UcbType_ucbDebug  = 0x12u,  /**< \brief UCB for debug */
} IfxFlash_UcbType;

/** \brief
 */
#define IFXFLASH_PFLASH_NUM_LOG_SECTORS                  ((192 * 3) + 64)
#define IFXFLASH_PFLASH_NUM_PHYSICAL_SECTORS             (3 * 3 + 1)
#define UCB_DBG_PASSWORD_CONST_SWITCH                    (STD_OFF)
#define UCB_DBGIF_UNLOCK_SWITCH                          (STD_OFF)


extern const unsigned char Ucb_DBG_EcuKey[16u];
#if (UCB_DBG_PASSWORD_CONST_SWITCH == STD_ON)
extern const uint32 Ucb_DBG_Password[8u];
#endif
extern const uint32 Ucb_PFlash_Password[8u];







#endif

