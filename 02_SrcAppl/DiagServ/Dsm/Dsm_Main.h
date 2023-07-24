/**
 * \file Dsm.h
 *
 * \brief  Diagnostic Service Management
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.04.09			Mingfen XIAO			Init version
 *
 *
 */
#ifndef _DSM_H_
#define _DSM_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Sdc_Type.h"
#include "Rte_Type.h"
#include "Dcm_Types.h"
#include "Dsm_Cfg.h"

#ifndef APPL_DSM_CODE
#define APPL_DSM_CODE 
#endif

#define DSM_STATE_INIT            0x00u

#define DSM_STATE_INACTIVE        0x01u

#define DSM_STATE_ACTIVE          0x02u

#define DSM_STATE_STOP            0x03u 


typedef enum
{
    SA_Level1 = 0x00,
	SA_Level2
}e_Dsm_SALevel_t;




extern FUNC(void, APPL_DSM_CODE) Dsm_v_EcuReset(void);
extern FUNC(void, APPL_DSM_CODE) Dsm_v_HardReset_CallBack(void);
extern FUNC(void, APPL_DSM_CODE) Dsm_v_KeyOnoff_CallBack(void);
extern FUNC(void, APPL_DSM_CODE) Dsm_v_ProgrammingReset_CallBack(void);
extern FUNC(void, APPL_DSM_CODE) Dsm_v_SoftReset_CallBack(void);
extern FUNC(void, APPL_DSM_CODE) Dsm_v_LockJTAGPassword(uint8 *const ptr);



/*==================[macros]=================================================*/



#endif /* _DSM_H_ */
