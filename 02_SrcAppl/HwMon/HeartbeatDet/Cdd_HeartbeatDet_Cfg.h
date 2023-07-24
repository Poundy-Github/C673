#ifndef CDD_HEARTBEATDET_CFG_H_
#define CDD_HEARTBEATDET_CFG_H_


#include "Platform_Types.h"
#include "Compiler.h"
#include "Icu_17_TimerIp.h"


#define HEARTBEATDET_DEV_ERROR_DETECT           (STD_OFF)

/*MCAL configure*/
#define HEARTBEATDET_OPERATING_CYCLE            (5u)/*unit:ms*/
#define HEARTBEATDET_TIM_CLOCK_FREQUENCY        (1u)/*uint:M*/


/*PWM Attributes*/
#define HEARTBEATDET_FREQUENCY_MAX              (71u)/*unit:Hz*/
#define HEARTBEATDET_FREQUENCY_MIN              (38u)/*unit:Hz*/
#define HEARTBEATDET_HIGHTIME_MAX               (13u)/*unit:ms*/
#define HEARTBEATDET_HIGHTIME_MIN               (7u)/*unit:ms*/

/*startuop phase time*/
#define HEARTBEATDET_STARTUPPHASE_START         (6000u)/*unit:ms*/
#define HEARTBEATDET_STARTUPPHASE_END           (11000)/*unit:ms*/

/*No signal duration*/
#define HEARTBEATDET_NO_SINGLE_CONTINUE_MAX     (60)/*unit:ms*/


extern const Icu_17_TimerIp_ChannelType HeartbeatDet_Channel;

#endif

