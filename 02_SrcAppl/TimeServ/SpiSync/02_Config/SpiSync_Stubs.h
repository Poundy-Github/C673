/**
 * \file SpiSync_Stubs.h
 *
 * \brief
 *
 * \version refer the SpiSync_Core.h.  
 *
 * \copyright  2021 - 2022 Conti Smart Core
 * 
 */
#ifndef _SPISYNC_STUBS_H
#define _SPISYNC_STUBS_H

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */

/*==================[macros definitions]====================================*/
#define OFFSET_YEAR 2000
#define CELLENDAR_GET_UTC_PARA(p) p.year,p.month,p.day,p.hour,p.minute,p.sec

/*==================[type definitions]=======================================*/
typedef struct 
{
  uint8 year;
  uint8 month;
  uint8 day;
  uint8 hour;
  uint8 minute;
  uint8 sec;
}SpiSync_AdcUtcTimeType;

/*==================[external constants declarations]========================*/

/*==================[external data declarations]=============================*/

/*==================[external function declarations]=========================*/
extern uint8 SpiSync_Cot_GetTimestampOffset(uint64 *time_stamp);

#endif /* _SPISYNC_STUBS_H */
