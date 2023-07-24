/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : TJASA
  MODULE        : TJAOBF
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.3 $
  $Author: Nastasa, Elena (uidt4846) $
  $Date: 2019/09/13 10:33:48CEST $
  $Log: Pse_TJAOBF.h  $
  Revision 1.3 2019/09/13 10:33:48CEST Nastasa, Elena (uidt4846) 
  Update LCF files for Sprint 10.08
**===========================================================*/
//! @file     Pse_TJAOBF.h
//! @brief     (TJAOBF) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TJAOBF_SenReset
void TJAOBF_SenResetData(void);
void TJAOBF_SenReset(void)
{
	uint8 k1;
	
	TJAOBF_SenResetData();
	
	DW_tjaobf_Unit_Delay2_DSTATE_cf = 0U;
	DW_tjaobf_Unit_Delay2_DSTATE_e = 0U;
	DW_tjaobf_Unit_Delay1_DSTATE_n = 0U;
	DW_tjaobf_Unit_Delay_DSTATE_l = 0U;
	DW_tjaobf_Unit_Delay_DSTATE_n = 0U;
	DW_tjaobf_Unit_Delay_DSTATE_lt = 0U;
	DW_tjaobf_Unit_Delay_DSTATE_o = 0U;
	DW_tjaobf_Unit_Delay1_DSTATE_h = 0U;
	DW_tjaobf_Unit_Delay1_DSTATE_nu = 0U;
	DW_tjaobf_Unit_Delay2_DSTATE_m = 0U;
	DW_tjaobf_Unit_Delay1_DSTATE = 0.F;
	DW_tjaobf_Unit_Delay2_DSTATE = 0.F;
	DW_tjaobf_Unit_Delay2_DSTATE_b = 0.F;
	DW_tjaobf_Unit_Delay_DSTATE = 0.F;
	DW_tjaobf_Unit_Delay_DSTATE_e = 0.F;
	DW_tjaobf_Unit_Delay2_DSTATE_c = 0.F;
	DW_tjaobf_Unit_Delay1_DSTATE_e = 0.F;
	DW_tjaobf_Unit_Delay2_DSTATE_bv = 0.F;
	
	for(k1 = 0; k1 < 2; k1++)
	{
		DW_tjaobf_Unit_Delay1_DSTATE_a[k1] = 0U;
		DW_tjaobf_Unit_Delay3_DSTATE_l[k1] = 0U;
		DW_tjaobf_Unit_Delay1_DSTATE_d[k1] = 0U;
		DW_tjaobf_Unit_Delay3_DSTATE[k1] = 0.F;
	}
	
}
#define TJAOBF_SenReset TJAOBF_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

