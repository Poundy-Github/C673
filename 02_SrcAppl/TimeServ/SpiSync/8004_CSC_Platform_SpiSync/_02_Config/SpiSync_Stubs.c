/**
 * \file 
 *
 * \brief 
 *
 * \version refer the SpiSync_Core.h.  
 * 
 * \copyright  2021 - 2022 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include "SpiSync_Stubs.h"
#include "SpiSync_Cfg.h"
#include "Com_SymbolicNames_PBcfg.h"
#include "SpiSync_Type.h"
/*==================[external constants definition]=========================*/


/*==================[internal constants definition]=========================*/

/*==================[external data definition]==============================*/


/*==================[internal data definition]==============================*/


/*==================[internal function declarations]========================*/
static boolean SpiSync_getAdcUtcTime(SpiSync_AdcUtcTimeType *st);
static void SpiSync_sentFcUtcTime(SpiSync_AdcUtcTimeType *st,uint8 valid);
static uint8 SpiSync_IsLeap(int year);
static uint64 SpiSync_calAllYears2Days(uint16 year);
static uint64 SpiSync_calAllMonths2Days(uint16 year,uint16 month);
uint64 SpiSync_transUtc2Seconds(uint16 year,uint16 month,uint16 day,uint16 hour,uint16 minute,uint16 sec);

/*==================[external function definitions]=========================*/
uint8 SpiSync_Cot_GetTimestampOffset(uint64 *time_stamp)
{
    uint8 ret = 0xFF;

	ret = 0x00;
	*time_stamp = 1666368000 * 1000000000;///<2022-10-22 0:0:0

    return ret;
}

#if (SPISYNC_USERFUNCTION_ENABLE == STD_ON)
/**
 * \functions SpiSync_UserInitFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
void SpiSync_UserInitFunction(void)
{

}
/**
 * \functions SpiSync_UserMainFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
void SpiSync_UserMainFunction(void)
{
     
}
#endif
/*==================[internal function definitions]=========================*/

