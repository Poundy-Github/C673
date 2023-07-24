/*===========================================================*
  Copyright (C) Continental AG
  All Rights Reserved
  PROJECT       : LCF100
  COMPONENT     : LCF
  TASK          : Vehicle
  SUB-COMPONENT : TRJCTR
  MODULE        : TCTFFC
  AUTHOR        : Module_AuxCodeGen
  VERSION       : 4.0

  Version Management Information
  $File: $
  $Revision: $
  $Author: $
  $Date: $
  $Log: $
**===========================================================*/
//! @file     Pse_TCTFFC.h
//! @brief     (TCTFFC) Module PSE Header.

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------*
   F U N C T I O N   D E F I N I T I O N S
**-----------------------------------------------------*/

#ifdef	RUNNABLE_ID

#if		RUNNABLE_ID == RUNNABLE_ID_TCTFFC_VehReset
void TCTFFC_VehResetData(void);
void TCTFFC_VehReset(void)
{
	
	TCTFFC_VehResetData();
	
	DW_tctffc_Unit_Delay_DSTATE_o = 0U;
	DW_tctffc_Unit_Delay3_DSTATE_c = 0U;
	DW_tctffc_Unit_Delay2_DSTATE_j = 3U;
	DW_tctffc_Unit_Delay_DSTATE_m = 0U;
	DW_tctffc_Unit_Delay_DSTATE = 0.F;
	DW_tctffc_Unit_Delay1_DSTATE = 0.F;
	DW_tctffc_Unit_Delay1_DSTATE_d = 0.F;
	DW_tctffc_Unit_Delay2_DSTATE = 0.F;
	DW_tctffc_Unit_Delay3_DSTATE = 0.F;
	DW_tctffc_Unit_Delay4_DSTATE = 0.F;
	DW_tctffc_Unit_Delay1_DSTATE_k = 0.F;
	DW_tctffc_UnitDelay2_DSTATE = 0.F;
	
}
#define TCTFFC_VehReset TCTFFC_VehResetData
#endif

#undef	RUNNABLE_ID
#endif

#ifdef __cplusplus
}
#endif

