#include "Rtm_Types.h"
#include "Os_config.h"

extern void Rtm_StartThread(uint8 CoreId, RtmThreadType_t threadtype, uint16 threadid);
extern void Rtm_EndThread(uint8 CoreId, RtmThreadType_t threadtype, uint16 threadid);

/*==================[macros]=================================================*/
/*
 * \brief 	RTM_MODULE_ID,
 * */
#ifndef RTM_MODULE_ID
#define RTM_MODULE_ID			        (0x8009ul)
#endif