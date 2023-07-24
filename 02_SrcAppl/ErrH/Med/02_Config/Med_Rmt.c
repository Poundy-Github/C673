/**
 * \file 
 *
 * \brief 
 *
 * \version refer the Med_Rmt.h.
 * 
 * \copyright  2021 - 2022 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include "Dem.h"
#include "Med_Rmt.h"
#include "Med_Lcfg.h"
#include "Med_Core.h"
#include "Med_Stubs.h"
#include "Rte_Med.h"
#include "Sdc.h"
#include "Com.h"
#include <Com_Api_Static.h>
#include "Cpr_Stubs.h"
#include "Rte_Dem_Type.h"
/*==================[external constants definition]=========================*/


/*==================[internal constants definition]=========================*/
uint8 Rmt_send_counters = 0;
uint8 dtc_status_old[MED_EVENT_TOTAL_NUMBER] = {0}; 
uint8 dtc_status_now[MED_EVENT_TOTAL_NUMBER] = {0};
s_Med_Send_CAN_t med_send_2CAN[MED_EVENT_TOTAL_NUMBER]; 

/*==================[external data definition]==============================*/


/*==================[internal data definition]==============================*/


/*==================[internal function declarations]========================*/
static void Med_Rmt_Send_DTCStatus_2CAN(uint8 Event_Index, uint8 Send_Status, uint8 method);

/*==================[external function definitions]=========================*/

/**
 * \functions Template_MainFunction
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
void Med_Rmt_MainFunction(void)
{
	uint8 i = 0;
	
	if(Rmt_send_counters == 0)
	{	
		TS_MemSet(med_send_2CAN, 0, sizeof(s_Med_Send_CAN_t)*MED_ERROR_DETECTION_NUMBER);

		for(i = 15; i < MED_EVENT_TOTAL_NUMBER; i++)
		{
			Dem_GetEventStatus(i, &dtc_status_now[i]);

			if((dtc_status_now[i] == 1  && dtc_status_old[i] != 1)
				|| (dtc_status_now[i] == 9 && dtc_status_old[i] != 9)
				|| (dtc_status_now[i] == 8 && dtc_status_old[i] == 1)
				|| (dtc_status_now[i] == 0 && dtc_status_old[i] == 8)
				|| (dtc_status_now[i] == 8 && dtc_status_old[i] == 9)
			)
			{	
				//dtc_status_old[i] = dtc_status_now[i];
				med_send_2CAN[Rmt_send_counters].Event_Index = i;
				med_send_2CAN[Rmt_send_counters].Send_Status = dtc_status_now[i];
				Rmt_send_counters ++;
			}
		}
	}

	if(Rmt_send_counters == 1)
	{
		Rmt_send_counters --;
		dtc_status_old[med_send_2CAN[Rmt_send_counters].Event_Index] = dtc_status_now[med_send_2CAN[Rmt_send_counters].Event_Index];

		Med_Rmt_Send_DTCStatus_2CAN(med_send_2CAN[0].Event_Index, med_send_2CAN[0].Send_Status, 1);
	}
	else if((Rmt_send_counters > 1) && (Rmt_send_counters <= MED_EVENT_TOTAL_NUMBER))
	{
		Rmt_send_counters --;	
		dtc_status_old[med_send_2CAN[Rmt_send_counters].Event_Index] = dtc_status_now[med_send_2CAN[Rmt_send_counters].Event_Index];

		Med_Rmt_Send_DTCStatus_2CAN(med_send_2CAN[Rmt_send_counters].Event_Index, med_send_2CAN[Rmt_send_counters].Send_Status, 1);
		if(Rmt_send_counters <= 0)
		{
			Rmt_send_counters = 0;
		}
		else
		{
			Rmt_send_counters --;
			dtc_status_old[med_send_2CAN[Rmt_send_counters].Event_Index] = dtc_status_now[med_send_2CAN[Rmt_send_counters].Event_Index];
			Med_Rmt_Send_DTCStatus_2CAN(med_send_2CAN[Rmt_send_counters].Event_Index, med_send_2CAN[Rmt_send_counters].Send_Status, 2);	
		}
	}
	else
	{
		Med_Rmt_Send_DTCStatus_2CAN(0 ,0, 0);
		Rmt_send_counters = 0;
	}

	return;
}

/*==================[internal function definitions]=========================*/

/**
 * \functions Med_Rmt_Send_DTCStatus_2CAN
 *
 * \brief Init internal and external related variable
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
static void Med_Rmt_Send_DTCStatus_2CAN(uint8 Event_Index, uint8 Send_Status, uint8 method)
{
	uint32 DTCOfEvent = 0;

    if(0u != Event_Index)
	{
		(ConstVoidPtr)Dem_GetDTCOfEvent(Event_Index, DEM_DTC_FORMAT_UDS, &DTCOfEvent);
	}
	uint8 DTC_HighByte = (uint8)((DTCOfEvent >> 16) & 0xFF);
	uint8 DTC_MiddleByte = (uint8)((DTCOfEvent >> 8) & 0xFF);
	uint8 DTC_LowByte = (uint8)(DTCOfEvent & 0xFF);
	if(method == 1)
	{
		//CAN0 FC_694
		Com_SendSignal(ComConf_ComSignal_SGLAS_DTC1_HighByte_1684T, &DTC_HighByte);
		Com_SendSignal(ComConf_ComSignal_SGLAS_DTC1_MiddByte_1684T, &DTC_MiddleByte);
		Com_SendSignal(ComConf_ComSignal_SGLAS_DTC1_LowByte_1684T, &DTC_LowByte);
		Com_SendSignal(ComConf_ComSignal_SGLAS_DTC1_Status_1684T, &Send_Status);

		//CAN1 FC_204
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_DTC1_HighByte_516T, &DTC_HighByte);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_DTC1_MiddByte_516T, &DTC_MiddleByte);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_DTC1_LowByte_516T, &DTC_LowByte);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_DTC1_Status_516T, &Send_Status);
	}
	else if(method == 2)
	{
		//CAN0 FC_694
		Com_SendSignal(ComConf_ComSignal_SGLAS_DTC2_HighByte_1684T, &DTC_HighByte);
		Com_SendSignal(ComConf_ComSignal_SGLAS_DTC2_MiddByte_1684T, &DTC_MiddleByte);
		Com_SendSignal(ComConf_ComSignal_SGLAS_DTC2_LowByte_1684T, &DTC_LowByte);
		Com_SendSignal(ComConf_ComSignal_SGLAS_DTC2_Status_1684T, &Send_Status);

		//CAN1 FC_204
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_DTC2_HighByte_516T, &DTC_HighByte);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_DTC2_MiddByte_516T, &DTC_MiddleByte);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_DTC2_LowByte_516T, &DTC_LowByte);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_DTC2_Status_516T, &Send_Status);
	}
	else
	{
		uint8 singal_u8 = 0;
		Com_SendSignal(ComConf_ComSignal_SGLAS_DTC1_HighByte_1684T, &singal_u8);
		Com_SendSignal(ComConf_ComSignal_SGLAS_DTC1_MiddByte_1684T, &singal_u8);
		Com_SendSignal(ComConf_ComSignal_SGLAS_DTC1_LowByte_1684T, &singal_u8);
		Com_SendSignal(ComConf_ComSignal_SGLAS_DTC1_Status_1684T, &singal_u8);
		Com_SendSignal(ComConf_ComSignal_SGLAS_DTC2_HighByte_1684T, &singal_u8);
		Com_SendSignal(ComConf_ComSignal_SGLAS_DTC2_MiddByte_1684T, &singal_u8);
		Com_SendSignal(ComConf_ComSignal_SGLAS_DTC2_LowByte_1684T, &singal_u8);
		Com_SendSignal(ComConf_ComSignal_SGLAS_DTC2_Status_1684T, &singal_u8);

		//CAN1 FC_204
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_DTC1_HighByte_516T, &singal_u8);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_DTC1_MiddByte_516T, &singal_u8);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_DTC1_LowByte_516T, &singal_u8);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_DTC1_Status_516T, &singal_u8);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_DTC2_HighByte_516T, &singal_u8);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_DTC2_MiddByte_516T, &singal_u8);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_DTC2_LowByte_516T, &singal_u8);
		Com_UpdateShadowSignal(ComConf_ComGroupSignal_FC_DTC2_Status_516T, &singal_u8);
	}

	Com_SendSignalGroup(ComConf_ComSignalGroup_GRFC_0x204_Group_516T);
	return;
}
