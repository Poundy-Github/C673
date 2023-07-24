/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTCDC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_TCTCDC.h
//! @brief     (TCTCDC) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TCTCDC_VehReset
void TCTCDC_VehResetData(void);
void TCTCDC_VehReset(void)
{
	
	TCTCDC_VehResetData();
	
	DW_tctcdc_Unit_Delay_DSTATE_p = 0U;
	DW_tctcdc_Unit_Delay_DSTATE_e = 0U;
	DW_tctcdc_Unit_Delay_DSTATE = 0.F;
	DW_tctcdc_Unit_Delay1_DSTATE = 0.F;
	DW_tctcdc_Unit_Delay2_DSTATE = 0.F;
	DW_tctcdc_Unit_Delay3_DSTATE = 0.F;
	DW_tctcdc_Unit_Delay4_DSTATE = 0.F;
	DW_tctcdc_Unit_Delay5_DSTATE = 0.F;
	DW_tctcdc_Unit_Delay6_DSTATE = 0.F;
	DW_tctcdc_Unit_Delay7_DSTATE = 0.F;
	DW_tctcdc_UnitDelay2_DSTATE = 0.F;
	DW_tctcdc_Unit_Delay2_DSTATE_p = 0.F;
	DW_tctcdc_UnitDelay2_DSTATE_c = 0.F;
	DW_tctcdc_Unit_Delay3_DSTATE_f = 0.F;
	
}
#define TCTCDC_VehReset TCTCDC_VehResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

