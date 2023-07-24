#ifndef CDD_UCB_H
#define CDD_UCB_H


#include "Cdd_Ucb_Cfg.h"
#include "Mcal_Compiler.h"



#define CDD_UCB_CODE            



typedef struct
{
    uint32 start;       /**< \brief start address of sector */
    uint32 end;         /**< \brief end address of sector */
} Ucb_IfxFlash_flashSectorType;

typedef struct
{
	uint32	pageaddr;
	uint32	data32L;
	uint32	data32H;
}Ucb_DFlashData_Type;


extern FUNC(uint8, CDD_UCB_CODE) CDD_Ucb_GetDBGIFLockState (void);
extern FUNC(uint8, CDD_UCB_CODE) CDD_Ucb_GetDBGConfirmState(void);
extern FUNC(uint8, CDD_UCB_CODE) CDD_Ucb_GetPFlashIFLockState (void);
extern FUNC(void, CDD_UCB_CODE) CDD_Ucb_ReqDBGIFLock (void);
extern FUNC(void, CDD_UCB_CODE) CDD_Ucb_SetPFlashLockState (const Ucb_DFlashData_Type *const DFlashData);
extern FUNC(void, CDD_UCB_CODE) CDD_Ucb_ReqPFlashIFLock (void);
extern FUNC(void, CDD_UCB_CODE) CDD_Ucb_ReqPFlashIFUnLock (void);
extern FUNC(void, CDD_UCB_CODE) CDD_Ucb_SetOTPLockState (const Ucb_DFlashData_Type *const DFlashData);
extern FUNC(void, CDD_UCB_CODE) CDD_Ucb_ReqOTPIFLock (void);















#endif
