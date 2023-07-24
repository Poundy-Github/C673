/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Sensor
  SUB-COMPONENT : ODPR
  MODULE        : ODPFOP
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: 1.4 $
  $Author: Nastasa, Elena (uidt4846) $
  $Date: 2019/09/13 10:32:20CEST $
  $Log: Pse_ODPFOP.h  $
  Revision 1.4 2019/09/13 10:32:20CEST Nastasa, Elena (uidt4846) 
  Update LCF files for Sprint 10.08
**===========================================================*/
//! @file     Pse_ODPFOP.h
//! @brief     (ODPFOP) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_ODPFOP_SenReset
void ODPFOP_SenResetData(void);
void ODPFOP_SenReset(void)
{
	
	ODPFOP_SenResetData();
	
	DW_odpfop_Unit_Delay_DSTATE_i = 0U;
	DW_odpfop_Unit_Delay5_DSTATE = 0U;
	DW_odpfop_Unit_Delay1_DSTATE_l = 0U;
	DW_odpfop_Unit_Delay2_DSTATE_n = 0U;
	DW_odpfop_Unit_Delay4_DSTATE_f = 0U;
	DW_odpfop_Unit_Delay10_DSTATE = 0U;
	DW_odpfop_Unit_Delay6_DSTATE_d = 0U;
	DW_odpfop_Unit_Delay5_DSTATE_a = 0U;
	DW_odpfop_Unit_Delay4_DSTATE_c = 0U;
	DW_odpfop_Unit_Delay_DSTATE_h = 0U;
	DW_odpfop_Unit_Delay_DSTATE_c = 0U;
	DW_odpfop_Unit_Delay1_DSTATE_g = 0U;
	BI_odpfop_Div = 0.F;
	DW_odpfop_Unit_Delay3_DSTATE = 0.F;
	DW_odpfop_Unit_Delay1_DSTATE = 0.F;
	DW_odpfop_Unit_Delay2_DSTATE = 0.F;
	DW_odpfop_Unit_Delay4_DSTATE = 0.F;
	DW_odpfop_Unit_Delay3_DSTATE_n = 0.F;
	DW_odpfop_Unit_Delay12_DSTATE = 0.F;
	DW_odpfop_Unit_Delay9_DSTATE = 0.F;
	DW_odpfop_Unit_Delay_DSTATE = 0.F;
	DW_odpfop_Unit_Delay8_DSTATE = 0.F;
	DW_odpfop_Unit_Delay2_DSTATE_m = 0.F;
	DW_odpfop_Unit_Delay3_DSTATE_o = 0.F;
	DW_odpfop_Unit_Delay2_DSTATE_e = 0.F;
	DW_odpfop_Unit_Delay1_DSTATE_c = 0.F;
	DW_odpfop_Unit_Delay4_DSTATE_m = 0.F;
	DW_odpfop_Unit_Delay6_DSTATE = 0.F;
	DW_odpfop_Unit_Delay_DSTATE_j = 0.F;
	DW_odpfop_Unit_Delay4_DSTATE_g = 0.F;
	DW_odpfop_Unit_Delay1_DSTATE_d = 0.F;
	DW_odpfop_Unit_Delay3_DSTATE_h = 0.F;
	
}
#define ODPFOP_SenReset ODPFOP_SenResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

