/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_DemSc_LocStub.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Tue Feb 28 11:49:17 CET 2012
**************************************************************************/


#ifndef _RTE_DemSc_LocStub_H_
#define _RTE_DemSc_LocStub_H_



#ifdef RTE_APPLICATION_HEADER_FILE
	#ifndef RTE_C
		#error Multiple application header files included. 
	#endif /* RTE_C */
#endif /* RTE_APPLICATION_HEADER_FILE */

#define RTE_APPLICATION_HEADER_FILE
/* Multiple application header file must not be included in the same module [Satisfies_rte sws 1004], [Satisfies_rte sws 1006] */


#include "Rte_Type.h"
#include "Rte_Hook.h"   /*RTE trace API hook functions */


#ifdef __cplusplus
	extern "C" {
#endif /* __cplusplus */




#ifndef RTE_C
  typedef CONSTP2CONST(Rte_CDS_DemSc_LocStub, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:DemSc_LocStub Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_DemSc_LocStub, RTE_CONST) Rte_Instance_DemSc_LocStub;

#ifndef RTE_C

	/*  Provided ports */



	/*  Required ports */


#endif



/* runnable entry points (symbol) */

extern void RE_CP_SA_DemSc_LocStub (void); 


/* application error code */



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/COMPONENTTYPES/IntBehDemSc_LocStub/RE_DemSc_LocStub/SSCP_DemScLocBswGetAdcData */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSc_LocStub_RPortDemScLocBswGetAdcData_OPGetAdcData( IN VAR(uint8,AUTOMATIC) AdcChannel, OUT P2VAR(float32,AUTOMATIC,RTE_APPL_DATA) CalcVal, OUT P2VAR(uint32,AUTOMATIC,RTE_APPL_DATA) Timestamp);
#ifndef RTE_C
  #define Rte_Call_RPortDemScLocBswGetAdcData_OPGetAdcData Rte_Call_DemSc_LocStub_RPortDemScLocBswGetAdcData_OPGetAdcData
#endif






#ifndef RTE_C
  #define Rte_InitValue_SwcDemSc_LocIgnition_Ign_Stat (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_SwcDemSc_LocIoDevice_Io_Stat (0)
#endif

#ifndef RTE_C
  #define Rte_InitValue_SwcDemSc_LocVoltage_SupBat_Volt (0)
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DemSc_LocStub_SwcDemSc_LocIgnition_Ign_Stat(IN VAR(c03_ISw_Stat, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_SwcDemSc_LocIgnition_Ign_Stat Rte_Write_DemSc_LocStub_SwcDemSc_LocIgnition_Ign_Stat
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DemSc_LocStub_SwcDemSc_LocIoDevice_Io_Stat(IN VAR(SwcDemSc_StdReturnType, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_SwcDemSc_LocIoDevice_Io_Stat Rte_Write_DemSc_LocStub_SwcDemSc_LocIoDevice_Io_Stat
#endif


  /* Rte_Write Api mapping  [Satisfies_rte sws 1071], [Satisfies_rte sws 1280].*/
  /* Std_ReturnType Rte_Write_<p>_<o>([IN Rte_Instance <instance>],IN <data>) */
/* API function prototype [Satisfies_rte sws 3707],[Satisfies_rte sws 1143]  */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DemSc_LocStub_SwcDemSc_LocVoltage_SupBat_Volt(IN VAR(c08_V_0_25k4_0k1, AUTOMATIC) arg1);
#ifndef RTE_C
  #define Rte_Write_SwcDemSc_LocVoltage_SupBat_Volt Rte_Write_DemSc_LocStub_SwcDemSc_LocVoltage_SupBat_Volt
#endif

  /* Rte_IRead Api mapping  [Satisfies_rte sws 3741], [Satisfies_rte sws 1301].*/
  /* <return> Rte_IRead_<re>_<p>_<d>([IN Rte_Instance]) */
extern FUNC(P2VAR(RTE_t_AdcReads, AUTOMATIC, RTE_APPL_DATA), RTE_CODE) Rte_IRead_DemSc_LocStub_RE_DemSc_LocStub_RPortDemScLocAdcData_DEPAdcData(void);

#ifndef RTE_C
  #define Rte_IRead_RE_DemSc_LocStub_RPortDemScLocAdcData_DEPAdcData \
    Rte_IRead_DemSc_LocStub_RE_DemSc_LocStub_RPortDemScLocAdcData_DEPAdcData

#endif









#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
