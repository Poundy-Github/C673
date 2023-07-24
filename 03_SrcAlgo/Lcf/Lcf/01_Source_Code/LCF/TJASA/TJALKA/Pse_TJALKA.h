/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJALKA
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_TJALKA.h
//! @brief     (TJALKA) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TJALKA_SenReset
void TJALKA_SenResetData(void);
void TJALKA_SenReset(void)
{
	uint8 k1;
	
	TJALKA_SenResetData();
	
	DW_tjalka_Unit_Delay_DSTATE_o = 0U;
	DW_tjalka_Unit_Delay_DSTATE_b = 0U;
	DW_tjalka_Unit_Delay1_DSTATE_c = 0U;
	DW_tjalka_Unit_Delay3_DSTATE = 0U;
	DW_tjalka_Unit_Delay4_DSTATE_h = 0U;
	DW_tjalka_Unit_Delay_DSTATE_a = 0U;
	DW_tjalka_Unit_Delay5_DSTATE_b = 0U;
	DW_tjalka_Unit_Delay_DSTATE_bh = 0U;
	DW_tjalka_Unit_Delay2_DSTATE_i = 0U;
	DW_tjalka_Unit_Delay_DSTATE_n = 0U;
	DW_tjalka_Unit_Delay1_DSTATE_e = 0U;
	DW_tjalka_Unit_Delay_DSTATE_j = 0U;
	DW_tjalka_Unit_Delay1_DSTATE_j = 0U;
	DW_tjalka_Unit_Delay1_DSTATE_cp = 0U;
	DW_tjalka_Unit_Delay2_DSTATE_e = 0U;
	DW_tjalka_Unit_Delay2_DSTATE_d = 0U;
	DW_tjalka_Unit_Delay_DSTATE = 0.F;
	DW_tjalka_Unit_Delay2_DSTATE_b = 0.F;
	DW_tjalka_Unit_Delay1_DSTATE = 0.F;
	DW_tjalka_Unit_Delay2_DSTATE_n = 0.F;
	DW_tjalka_Unit_Delay1_DSTATE_i = 0.F;
	DW_tjalka_Unit_Delay4_DSTATE_d = 0.F;
	DW_tjalka_Unit_Delay4_DSTATE_p = 0.F;
	
	for(k1 = 0; k1 < 2; k1++)
	{
		DW_tjalka_Unit_Delay5_DSTATE[k1] = 0U;
		DW_tjalka_Unit_Delay3_DSTATE_i[k1] = 0U;
		DW_tjalka_Unit_Delay_DSTATE_bl[k1] = 0U;
		DW_tjalka_Unit_Delay1_DSTATE_ju[k1] = 0U;
		DW_tjalka_Unit_Delay4_DSTATE[k1] = 0.F;
		DW_tjalka_Unit_Delay2_DSTATE[k1] = 0.F;
		DW_tjalka_Unit_Delay2_DSTATE_j[k1] = 0.F;
	}
	
}
#define TJALKA_SenReset TJALKA_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

