/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : DRVMN
  MODULE        : DRMHOD
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_DRMHOD.h
//! @brief     (DRMHOD) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_DRMHOD_VehReset
void DRMHOD_VehResetData(void);
void DRMHOD_VehReset(void)
{
	
	DRMHOD_VehResetData();
	
	BI_drmhod_D_DRMHOD_EstHandTorState_nu_e = 0U;
	DW_drmhod_Unit_Delay1_DSTATE = 0U;
	DW_drmhod_Unit_Delay_DSTATE_f = 3U;
	DW_drmhod_Unit_Delay5_DSTATE = 5U;
	DW_drmhod_is_active_c3_DRMHOD_cg = 0U;
	DW_drmhod_is_c3_DRMHOD_cg = 0U;
	DW_drmhod_Unit_Delay4_DSTATE_h = 0U;
	DW_drmhod_Unit_Delay2_DSTATE_p = 0U;
	DW_drmhod_Unit_Delay_DSTATE = 0.F;
	DW_drmhod_Unit_Delay4_DSTATE = 0.F;
	DW_drmhod_Unit_Delay2_DSTATE = 0.F;
	DW_drmhod_Unit_Delay3_DSTATE = 0.F;
	
}
#define DRMHOD_VehReset DRMHOD_VehResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

