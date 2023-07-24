/**************************************************************************
This file is generated automatically by the RTE generator
Filename:	Rte_NvM.h
CESSAR-CT Version: 3.1.1.11
RTE Version: 3.2.0.1.3.0
Generated on:	Fri Feb 03 12:37:32 CET 2012
**************************************************************************/


#ifndef _RTE_NvM_H_
#define _RTE_NvM_H_



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
  typedef CONSTP2CONST(Rte_CDS_NvM, AUTOMATIC, RTE_CONST) Rte_Instance;
#endif /* RTE_C */

/* SWC:NvM Indirect API */
	/* The name of the instance handle is Rte_Inst_<c> [Satisfies_rte sws 3793]. */
extern CONST(Rte_CDS_NvM, RTE_CONST) Rte_Instance_NvM;

#ifndef RTE_C

	/*  Provided ports */

	/* Rte_NPorts Api [Satisfies_rte sws 2614], [Satisfies_rte sws 2615], [Satisfies_rte sws 3603].*/
	/* uint8 Rte_NPorts_<i>_<R/P>([IN Rte_Instance]) */
	#define Rte_NPorts_NvMAdministration_P() (62)
	/* Rte_Ports Api [Satisfies_rte sws 2619], [Satisfies_rte sws 2613], [Satisfies_rte sws 3602].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Ports_<i>_<R/P>([IN Rte_Instance]) */
	#define Rte_Ports_NvMAdministration_P() (&((Rte_Instance_NvM).NvMAdministrationA_Reserved1))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationA_Reserved1() (&((Rte_Instance_NvM).NvMAdministrationA_Reserved1))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB010_FBL_XC_008() (&((Rte_Instance_NvM).NvMAdministrationB010_FBL_XC_008))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB011_FBL_FE_011() (&((Rte_Instance_NvM).NvMAdministrationB011_FBL_FE_011))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB012_FBL_AP_014() (&((Rte_Instance_NvM).NvMAdministrationB012_FBL_AP_014))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB030_CFBL_A_017() (&((Rte_Instance_NvM).NvMAdministrationB030_CFBL_A_017))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB031_CFBL_L_020() (&((Rte_Instance_NvM).NvMAdministrationB031_CFBL_L_020))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB032_CFBL_C_023() (&((Rte_Instance_NvM).NvMAdministrationB032_CFBL_C_023))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB033_CFBL_L_026() (&((Rte_Instance_NvM).NvMAdministrationB033_CFBL_L_026))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB034_CFBL_L_029() (&((Rte_Instance_NvM).NvMAdministrationB034_CFBL_L_029))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB040_CFBL_R_032() (&((Rte_Instance_NvM).NvMAdministrationB040_CFBL_R_032))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB041_CFBL_R_035() (&((Rte_Instance_NvM).NvMAdministrationB041_CFBL_R_035))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB042_CFBL_R_038() (&((Rte_Instance_NvM).NvMAdministrationB042_CFBL_R_038))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB043_CFBL_R_041() (&((Rte_Instance_NvM).NvMAdministrationB043_CFBL_R_041))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB044_CFBL_R_044() (&((Rte_Instance_NvM).NvMAdministrationB044_CFBL_R_044))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB045_CFBL_R_047() (&((Rte_Instance_NvM).NvMAdministrationB045_CFBL_R_047))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB046_CFBL_R_050() (&((Rte_Instance_NvM).NvMAdministrationB046_CFBL_R_050))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB047_CFBL_R_053() (&((Rte_Instance_NvM).NvMAdministrationB047_CFBL_R_053))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB048_CFBL_R_056() (&((Rte_Instance_NvM).NvMAdministrationB048_CFBL_R_056))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB049_CFBL_R_059() (&((Rte_Instance_NvM).NvMAdministrationB049_CFBL_R_059))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB050_DEM_CH_140() (&((Rte_Instance_NvM).NvMAdministrationB050_DEM_CH_140))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB051_DEM_HI_143() (&((Rte_Instance_NvM).NvMAdministrationB051_DEM_HI_143))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB052_DEM_CH_146() (&((Rte_Instance_NvM).NvMAdministrationB052_DEM_CH_146))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB053_DEM_HI_149() (&((Rte_Instance_NvM).NvMAdministrationB053_DEM_HI_149))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB054_DEM_HI_152() (&((Rte_Instance_NvM).NvMAdministrationB054_DEM_HI_152))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB055_DEM_EV_155() (&((Rte_Instance_NvM).NvMAdministrationB055_DEM_EV_155))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationB056_DEM_RE_158() (&((Rte_Instance_NvM).NvMAdministrationB056_DEM_RE_158))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC001_CALI_C_062() (&((Rte_Instance_NvM).NvMAdministrationC001_CALI_C_062))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC002_CALI_E_065() (&((Rte_Instance_NvM).NvMAdministrationC002_CALI_E_065))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC003_CALI_F_068() (&((Rte_Instance_NvM).NvMAdministrationC003_CALI_F_068))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC010_VCVehD_071() (&((Rte_Instance_NvM).NvMAdministrationC010_VCVehD_071))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC020_HLA_On_074() (&((Rte_Instance_NvM).NvMAdministrationC020_HLA_On_074))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC021_LD_Onl_077() (&((Rte_Instance_NvM).NvMAdministrationC021_LD_Onl_077))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC025_SRLear_080() (&((Rte_Instance_NvM).NvMAdministrationC025_SRLear_080))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC030_HEAT_O_083() (&((Rte_Instance_NvM).NvMAdministrationC030_HEAT_O_083))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC040_IC_PAR_086() (&((Rte_Instance_NvM).NvMAdministrationC040_IC_PAR_086))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC045_SW_CON_089() (&((Rte_Instance_NvM).NvMAdministrationC045_SW_CON_089))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC080_STEREO_092() (&((Rte_Instance_NvM).NvMAdministrationC080_STEREO_092))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC081_STEREO_095() (&((Rte_Instance_NvM).NvMAdministrationC081_STEREO_095))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC082_STEREO_098() (&((Rte_Instance_NvM).NvMAdministrationC082_STEREO_098))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC083_IMAGE__101() (&((Rte_Instance_NvM).NvMAdministrationC083_IMAGE__101))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC100_ODOMET_104() (&((Rte_Instance_NvM).NvMAdministrationC100_ODOMET_104))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC101_VIN_OR_107() (&((Rte_Instance_NvM).NvMAdministrationC101_VIN_OR_107))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC102_VIN_CU_110() (&((Rte_Instance_NvM).NvMAdministrationC102_VIN_CU_110))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC103_VIN_OD_113() (&((Rte_Instance_NvM).NvMAdministrationC103_VIN_OD_113))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC104_VIN_OD_116() (&((Rte_Instance_NvM).NvMAdministrationC104_VIN_OD_116))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC110_MON_T__119() (&((Rte_Instance_NvM).NvMAdministrationC110_MON_T__119))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC111_MON_T__122() (&((Rte_Instance_NvM).NvMAdministrationC111_MON_T__122))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC120_VDY_YW_125() (&((Rte_Instance_NvM).NvMAdministrationC120_VDY_YW_125))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC121_VDY_SL_128() (&((Rte_Instance_NvM).NvMAdministrationC121_VDY_SL_128))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC122_VDY_ST_131() (&((Rte_Instance_NvM).NvMAdministrationC122_VDY_ST_131))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC123_VDY_VE_134() (&((Rte_Instance_NvM).NvMAdministrationC123_VDY_VE_134))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC124_VDY_LA_137() (&((Rte_Instance_NvM).NvMAdministrationC124_VDY_LA_137))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC800_IC_CON_161() (&((Rte_Instance_NvM).NvMAdministrationC800_IC_CON_161))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC801_IC_IMA_164() (&((Rte_Instance_NvM).NvMAdministrationC801_IC_IMA_164))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC802_NM_DEA_167() (&((Rte_Instance_NvM).NvMAdministrationC802_NM_DEA_167))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC803_SGM_CO_170() (&((Rte_Instance_NvM).NvMAdministrationC803_SGM_CO_170))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC804_POWERF_173() (&((Rte_Instance_NvM).NvMAdministrationC804_POWERF_173))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationC805_POD_CO_176() (&((Rte_Instance_NvM).NvMAdministrationC805_POD_CO_176))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationDEM_CONFIGU_179() (&((Rte_Instance_NvM).NvMAdministrationDEM_CONFIGU_179))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationDIAG_SEED_K_182() (&((Rte_Instance_NvM).NvMAdministrationDIAG_SEED_K_182))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationDIAG_TRACE__185() (&((Rte_Instance_NvM).NvMAdministrationDIAG_TRACE__185))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMAdministrationReserved0() (&((Rte_Instance_NvM).NvMAdministrationReserved0))
	/* Rte_NPorts Api [Satisfies_rte sws 2614], [Satisfies_rte sws 2615], [Satisfies_rte sws 3603].*/
	/* uint8 Rte_NPorts_<i>_<R/P>([IN Rte_Instance]) */
	#define Rte_NPorts_NvMService_P() (62)
	/* Rte_Ports Api [Satisfies_rte sws 2619], [Satisfies_rte sws 2613], [Satisfies_rte sws 3602].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Ports_<i>_<R/P>([IN Rte_Instance]) */
	#define Rte_Ports_NvMService_P() (&((Rte_Instance_NvM).NvMServiceA_Reserved1))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceA_Reserved1() (&((Rte_Instance_NvM).NvMServiceA_Reserved1))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB010_FBL_XCP_CONFI_006() (&((Rte_Instance_NvM).NvMServiceB010_FBL_XCP_CONFI_006))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB011_FBL_FEATURES() (&((Rte_Instance_NvM).NvMServiceB011_FBL_FEATURES))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB012_FBL_APPLICATI_012() (&((Rte_Instance_NvM).NvMServiceB012_FBL_APPLICATI_012))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB030_CFBL_APP_FLAS_015() (&((Rte_Instance_NvM).NvMServiceB030_CFBL_APP_FLAS_015))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB031_CFBL_LAST_VAL_018() (&((Rte_Instance_NvM).NvMServiceB031_CFBL_LAST_VAL_018))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB032_CFBL_CONTROL() (&((Rte_Instance_NvM).NvMServiceB032_CFBL_CONTROL))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB033_CFBL_LAST_APP_024() (&((Rte_Instance_NvM).NvMServiceB033_CFBL_LAST_APP_024))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB034_CFBL_LAST_APP_027() (&((Rte_Instance_NvM).NvMServiceB034_CFBL_LAST_APP_027))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB040_CFBL_Reserved() (&((Rte_Instance_NvM).NvMServiceB040_CFBL_Reserved))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB041_CFBL_Reserved() (&((Rte_Instance_NvM).NvMServiceB041_CFBL_Reserved))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB042_CFBL_Reserved() (&((Rte_Instance_NvM).NvMServiceB042_CFBL_Reserved))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB043_CFBL_Reserved() (&((Rte_Instance_NvM).NvMServiceB043_CFBL_Reserved))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB044_CFBL_Reserved() (&((Rte_Instance_NvM).NvMServiceB044_CFBL_Reserved))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB045_CFBL_Reserved() (&((Rte_Instance_NvM).NvMServiceB045_CFBL_Reserved))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB046_CFBL_Reserved() (&((Rte_Instance_NvM).NvMServiceB046_CFBL_Reserved))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB047_CFBL_Reserved() (&((Rte_Instance_NvM).NvMServiceB047_CFBL_Reserved))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB048_CFBL_Reserved() (&((Rte_Instance_NvM).NvMServiceB048_CFBL_Reserved))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB049_CFBL_Reserved() (&((Rte_Instance_NvM).NvMServiceB049_CFBL_Reserved))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB050_DEM_CHRONO_EV_138() (&((Rte_Instance_NvM).NvMServiceB050_DEM_CHRONO_EV_138))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB051_DEM_HISTO_EVE_141() (&((Rte_Instance_NvM).NvMServiceB051_DEM_HISTO_EVE_141))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB052_DEM_CHRONO_SE_144() (&((Rte_Instance_NvM).NvMServiceB052_DEM_CHRONO_SE_144))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB053_DEM_HISTO_SEQ_147() (&((Rte_Instance_NvM).NvMServiceB053_DEM_HISTO_SEQ_147))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB054_DEM_HISTO_INT_150() (&((Rte_Instance_NvM).NvMServiceB054_DEM_HISTO_INT_150))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB055_DEM_EV_INACT__153() (&((Rte_Instance_NvM).NvMServiceB055_DEM_EV_INACT__153))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceB056_DEM_READINESS_156() (&((Rte_Instance_NvM).NvMServiceB056_DEM_READINESS_156))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC001_CALI_CAM_POS() (&((Rte_Instance_NvM).NvMServiceC001_CALI_CAM_POS))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC002_CALI_ENV_DATA() (&((Rte_Instance_NvM).NvMServiceC002_CALI_ENV_DATA))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC003_CALI_FIELD_OF_066() (&((Rte_Instance_NvM).NvMServiceC003_CALI_FIELD_OF_066))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC010_VCVehData() (&((Rte_Instance_NvM).NvMServiceC010_VCVehData))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC020_HLA_OnlineCal_072() (&((Rte_Instance_NvM).NvMServiceC020_HLA_OnlineCal_072))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC021_LD_OnlineCali() (&((Rte_Instance_NvM).NvMServiceC021_LD_OnlineCali))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC025_SRLearnValues() (&((Rte_Instance_NvM).NvMServiceC025_SRLearnValues))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC030_HEAT_ON_TIME() (&((Rte_Instance_NvM).NvMServiceC030_HEAT_ON_TIME))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC040_IC_PARAMETER() (&((Rte_Instance_NvM).NvMServiceC040_IC_PARAMETER))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC045_SW_CONFIG_SWI_087() (&((Rte_Instance_NvM).NvMServiceC045_SW_CONFIG_SWI_087))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC080_STEREO_CALI_I_090() (&((Rte_Instance_NvM).NvMServiceC080_STEREO_CALI_I_090))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC081_STEREO_CALI_R_093() (&((Rte_Instance_NvM).NvMServiceC081_STEREO_CALI_R_093))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC082_STEREO_CALI_T_096() (&((Rte_Instance_NvM).NvMServiceC082_STEREO_CALI_T_096))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC083_IMAGE_DATA() (&((Rte_Instance_NvM).NvMServiceC083_IMAGE_DATA))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC100_ODOMETER() (&((Rte_Instance_NvM).NvMServiceC100_ODOMETER))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC101_VIN_ORIGINAL() (&((Rte_Instance_NvM).NvMServiceC101_VIN_ORIGINAL))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC102_VIN_CURRENT() (&((Rte_Instance_NvM).NvMServiceC102_VIN_CURRENT))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC103_VIN_ODOMETER() (&((Rte_Instance_NvM).NvMServiceC103_VIN_ODOMETER))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC104_VIN_ODOMETER__114() (&((Rte_Instance_NvM).NvMServiceC104_VIN_ODOMETER__114))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC110_MON_T_HIST() (&((Rte_Instance_NvM).NvMServiceC110_MON_T_HIST))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC111_MON_T_MAX_VAL_120() (&((Rte_Instance_NvM).NvMServiceC111_MON_T_MAX_VAL_120))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC120_VDY_YWRATE() (&((Rte_Instance_NvM).NvMServiceC120_VDY_YWRATE))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC121_VDY_SLFSTGRAD() (&((Rte_Instance_NvM).NvMServiceC121_VDY_SLFSTGRAD))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC122_VDY_STWHLANG() (&((Rte_Instance_NvM).NvMServiceC122_VDY_STWHLANG))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC123_VDY_VELCORR() (&((Rte_Instance_NvM).NvMServiceC123_VDY_VELCORR))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC124_VDY_LATACC() (&((Rte_Instance_NvM).NvMServiceC124_VDY_LATACC))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC800_IC_CONFIG() (&((Rte_Instance_NvM).NvMServiceC800_IC_CONFIG))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC801_IC_IMAGER_REG_162() (&((Rte_Instance_NvM).NvMServiceC801_IC_IMAGER_REG_162))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC802_NM_DEACT_SWIT_165() (&((Rte_Instance_NvM).NvMServiceC802_NM_DEACT_SWIT_165))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC803_SGM_CONFIG() (&((Rte_Instance_NvM).NvMServiceC803_SGM_CONFIG))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC804_POWERFLOW_CON_171() (&((Rte_Instance_NvM).NvMServiceC804_POWERFLOW_CON_171))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceC805_POD_CONFIG() (&((Rte_Instance_NvM).NvMServiceC805_POD_CONFIG))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceDEM_CONFIGURATION() (&((Rte_Instance_NvM).NvMServiceDEM_CONFIGURATION))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceDIAG_SEED_KEY() (&((Rte_Instance_NvM).NvMServiceDIAG_SEED_KEY))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceDIAG_TRACE_MEM() (&((Rte_Instance_NvM).NvMServiceDIAG_TRACE_MEM))
	/* Rte_Port Api [Satisfies_rte sws 1354], [Satisfies_rte sws 1355].*/
	/* Rte_PortHandle_<i>_<R/P> Rte_Port_<p>([IN Rte_Instance]) */
	#define Rte_Port_NvMServiceReserved0() (&((Rte_Instance_NvM).NvMServiceReserved0))


	/*  Required ports */


#endif



/* runnable entry points (symbol) */



/* application error code */
#ifndef RTE_E_NvMNotify_E_NOK
  #define RTE_E_NvMNotify_E_NOK 1
#endif
#ifndef RTE_E_NvMNotify_E_OK
  #define RTE_E_NvMNotify_E_OK 0
#endif
#ifndef RTE_E_NvMService_E_NOK
  #define RTE_E_NvMService_E_NOK 1
#endif
#ifndef RTE_E_NvMService_E_OK
  #define RTE_E_NvMService_E_OK 0
#endif



/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished1 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyA_Reserved1_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyA_Reserved1_JobFinished Rte_Call_NvM_NvMNotifyA_Reserved1_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished2 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB010_FBL_XCP_CONFIG_007_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB010_FBL_XCP_CONFIG_007_JobFinished Rte_Call_NvM_NvMNotifyB010_FBL_XCP_CONFIG_007_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished3 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB011_FBL_FEATURES_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB011_FBL_FEATURES_JobFinished Rte_Call_NvM_NvMNotifyB011_FBL_FEATURES_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished4 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB012_FBL_APPLICATIO_013_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB012_FBL_APPLICATIO_013_JobFinished Rte_Call_NvM_NvMNotifyB012_FBL_APPLICATIO_013_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished5 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB030_CFBL_APP_FLASH_016_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB030_CFBL_APP_FLASH_016_JobFinished Rte_Call_NvM_NvMNotifyB030_CFBL_APP_FLASH_016_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished6 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB031_CFBL_LAST_VALI_019_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB031_CFBL_LAST_VALI_019_JobFinished Rte_Call_NvM_NvMNotifyB031_CFBL_LAST_VALI_019_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished7 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB032_CFBL_CONTROL_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB032_CFBL_CONTROL_JobFinished Rte_Call_NvM_NvMNotifyB032_CFBL_CONTROL_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished8 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB033_CFBL_LAST_APP__025_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB033_CFBL_LAST_APP__025_JobFinished Rte_Call_NvM_NvMNotifyB033_CFBL_LAST_APP__025_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished9 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB034_CFBL_LAST_APP__028_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB034_CFBL_LAST_APP__028_JobFinished Rte_Call_NvM_NvMNotifyB034_CFBL_LAST_APP__028_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished10 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB040_CFBL_Reserved_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB040_CFBL_Reserved_JobFinished Rte_Call_NvM_NvMNotifyB040_CFBL_Reserved_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished11 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB041_CFBL_Reserved_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB041_CFBL_Reserved_JobFinished Rte_Call_NvM_NvMNotifyB041_CFBL_Reserved_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished12 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB042_CFBL_Reserved_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB042_CFBL_Reserved_JobFinished Rte_Call_NvM_NvMNotifyB042_CFBL_Reserved_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished13 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB043_CFBL_Reserved_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB043_CFBL_Reserved_JobFinished Rte_Call_NvM_NvMNotifyB043_CFBL_Reserved_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished14 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB044_CFBL_Reserved_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB044_CFBL_Reserved_JobFinished Rte_Call_NvM_NvMNotifyB044_CFBL_Reserved_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished15 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB045_CFBL_Reserved_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB045_CFBL_Reserved_JobFinished Rte_Call_NvM_NvMNotifyB045_CFBL_Reserved_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished16 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB046_CFBL_Reserved_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB046_CFBL_Reserved_JobFinished Rte_Call_NvM_NvMNotifyB046_CFBL_Reserved_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished17 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB047_CFBL_Reserved_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB047_CFBL_Reserved_JobFinished Rte_Call_NvM_NvMNotifyB047_CFBL_Reserved_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished18 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB048_CFBL_Reserved_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB048_CFBL_Reserved_JobFinished Rte_Call_NvM_NvMNotifyB048_CFBL_Reserved_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished19 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB049_CFBL_Reserved_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB049_CFBL_Reserved_JobFinished Rte_Call_NvM_NvMNotifyB049_CFBL_Reserved_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished46 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB050_DEM_CHRONO_EVE_139_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB050_DEM_CHRONO_EVE_139_JobFinished Rte_Call_NvM_NvMNotifyB050_DEM_CHRONO_EVE_139_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished47 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB051_DEM_HISTO_EVEN_142_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB051_DEM_HISTO_EVEN_142_JobFinished Rte_Call_NvM_NvMNotifyB051_DEM_HISTO_EVEN_142_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished48 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB052_DEM_CHRONO_SEQ_145_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB052_DEM_CHRONO_SEQ_145_JobFinished Rte_Call_NvM_NvMNotifyB052_DEM_CHRONO_SEQ_145_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished49 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB053_DEM_HISTO_SEQN_148_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB053_DEM_HISTO_SEQN_148_JobFinished Rte_Call_NvM_NvMNotifyB053_DEM_HISTO_SEQN_148_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished50 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB054_DEM_HISTO_INTE_151_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB054_DEM_HISTO_INTE_151_JobFinished Rte_Call_NvM_NvMNotifyB054_DEM_HISTO_INTE_151_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished51 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB055_DEM_EV_INACT_A_154_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB055_DEM_EV_INACT_A_154_JobFinished Rte_Call_NvM_NvMNotifyB055_DEM_EV_INACT_A_154_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished52 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyB056_DEM_READINESS__157_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyB056_DEM_READINESS__157_JobFinished Rte_Call_NvM_NvMNotifyB056_DEM_READINESS__157_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished20 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC001_CALI_CAM_POS_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC001_CALI_CAM_POS_JobFinished Rte_Call_NvM_NvMNotifyC001_CALI_CAM_POS_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished21 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC002_CALI_ENV_DATA_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC002_CALI_ENV_DATA_JobFinished Rte_Call_NvM_NvMNotifyC002_CALI_ENV_DATA_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished22 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC003_CALI_FIELD_OF__067_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC003_CALI_FIELD_OF__067_JobFinished Rte_Call_NvM_NvMNotifyC003_CALI_FIELD_OF__067_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished23 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC010_VCVehData_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC010_VCVehData_JobFinished Rte_Call_NvM_NvMNotifyC010_VCVehData_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished24 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC020_HLA_OnlineCali_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC020_HLA_OnlineCali_JobFinished Rte_Call_NvM_NvMNotifyC020_HLA_OnlineCali_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished25 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC021_LD_OnlineCali_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC021_LD_OnlineCali_JobFinished Rte_Call_NvM_NvMNotifyC021_LD_OnlineCali_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished26 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC025_SRLearnValues_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC025_SRLearnValues_JobFinished Rte_Call_NvM_NvMNotifyC025_SRLearnValues_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished27 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC030_HEAT_ON_TIME_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC030_HEAT_ON_TIME_JobFinished Rte_Call_NvM_NvMNotifyC030_HEAT_ON_TIME_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished28 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC040_IC_PARAMETER_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC040_IC_PARAMETER_JobFinished Rte_Call_NvM_NvMNotifyC040_IC_PARAMETER_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished29 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC045_SW_CONFIG_SWIT_088_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC045_SW_CONFIG_SWIT_088_JobFinished Rte_Call_NvM_NvMNotifyC045_SW_CONFIG_SWIT_088_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished30 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC080_STEREO_CALI_IN_091_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC080_STEREO_CALI_IN_091_JobFinished Rte_Call_NvM_NvMNotifyC080_STEREO_CALI_IN_091_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished31 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC081_STEREO_CALI_RO_094_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC081_STEREO_CALI_RO_094_JobFinished Rte_Call_NvM_NvMNotifyC081_STEREO_CALI_RO_094_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished32 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC082_STEREO_CALI_TR_097_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC082_STEREO_CALI_TR_097_JobFinished Rte_Call_NvM_NvMNotifyC082_STEREO_CALI_TR_097_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished33 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC083_IMAGE_DATA_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC083_IMAGE_DATA_JobFinished Rte_Call_NvM_NvMNotifyC083_IMAGE_DATA_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished34 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC100_ODOMETER_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC100_ODOMETER_JobFinished Rte_Call_NvM_NvMNotifyC100_ODOMETER_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished35 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC101_VIN_ORIGINAL_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC101_VIN_ORIGINAL_JobFinished Rte_Call_NvM_NvMNotifyC101_VIN_ORIGINAL_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished36 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC102_VIN_CURRENT_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC102_VIN_CURRENT_JobFinished Rte_Call_NvM_NvMNotifyC102_VIN_CURRENT_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished37 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC103_VIN_ODOMETER_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC103_VIN_ODOMETER_JobFinished Rte_Call_NvM_NvMNotifyC103_VIN_ODOMETER_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished38 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC104_VIN_ODOMETER_M_115_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC104_VIN_ODOMETER_M_115_JobFinished Rte_Call_NvM_NvMNotifyC104_VIN_ODOMETER_M_115_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished39 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC110_MON_T_HIST_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC110_MON_T_HIST_JobFinished Rte_Call_NvM_NvMNotifyC110_MON_T_HIST_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished40 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC111_MON_T_MAX_VALU_121_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC111_MON_T_MAX_VALU_121_JobFinished Rte_Call_NvM_NvMNotifyC111_MON_T_MAX_VALU_121_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished41 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC120_VDY_YWRATE_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC120_VDY_YWRATE_JobFinished Rte_Call_NvM_NvMNotifyC120_VDY_YWRATE_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished42 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC121_VDY_SLFSTGRAD_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC121_VDY_SLFSTGRAD_JobFinished Rte_Call_NvM_NvMNotifyC121_VDY_SLFSTGRAD_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished43 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC122_VDY_STWHLANG_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC122_VDY_STWHLANG_JobFinished Rte_Call_NvM_NvMNotifyC122_VDY_STWHLANG_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished44 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC123_VDY_VELCORR_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC123_VDY_VELCORR_JobFinished Rte_Call_NvM_NvMNotifyC123_VDY_VELCORR_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished45 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC124_VDY_LATACC_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC124_VDY_LATACC_JobFinished Rte_Call_NvM_NvMNotifyC124_VDY_LATACC_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished53 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC800_IC_CONFIG_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC800_IC_CONFIG_JobFinished Rte_Call_NvM_NvMNotifyC800_IC_CONFIG_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished54 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC801_IC_IMAGER_REGI_163_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC801_IC_IMAGER_REGI_163_JobFinished Rte_Call_NvM_NvMNotifyC801_IC_IMAGER_REGI_163_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished55 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC802_NM_DEACT_SWITC_166_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC802_NM_DEACT_SWITC_166_JobFinished Rte_Call_NvM_NvMNotifyC802_NM_DEACT_SWITC_166_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished56 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC803_SGM_CONFIG_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC803_SGM_CONFIG_JobFinished Rte_Call_NvM_NvMNotifyC803_SGM_CONFIG_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished57 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC804_POWERFLOW_CONF_172_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC804_POWERFLOW_CONF_172_JobFinished Rte_Call_NvM_NvMNotifyC804_POWERFLOW_CONF_172_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished58 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyC805_POD_CONFIG_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyC805_POD_CONFIG_JobFinished Rte_Call_NvM_NvMNotifyC805_POD_CONFIG_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished59 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyDEM_CONFIGURATION_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyDEM_CONFIGURATION_JobFinished Rte_Call_NvM_NvMNotifyDEM_CONFIGURATION_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished60 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyDIAG_SEED_KEY_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyDIAG_SEED_KEY_JobFinished Rte_Call_NvM_NvMNotifyDIAG_SEED_KEY_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished61 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyDIAG_TRACE_MEM_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyDIAG_TRACE_MEM_JobFinished Rte_Call_NvM_NvMNotifyDIAG_TRACE_MEM_JobFinished
#endif


/* Rte_Call Api mapping  [Satisfies_rte sws 1102], [Satisfies_rte sws 1103].*/
/* Std_ReturnType Rte_Call_<p>_<o>([IN Rte_Instance <instance>], [IN|IN/OUT|OUT] <data_1>...[IN|IN/OUT|OUT] <data_n>) */
/* For synchronous  [Satisfies_rte sws 1294] server invocation of call pt.:/AUTOSAR/Services/NvM/NVRAMManager/ReApiDummy/SscpNvMJobFinished0 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvMNotifyReserved0_JobFinished( IN VAR(UInt8,AUTOMATIC) ServiceId, IN VAR(RequestResultType,AUTOMATIC) JobResult);
#ifndef RTE_C
  #define Rte_Call_NvMNotifyReserved0_JobFinished Rte_Call_NvM_NvMNotifyReserved0_JobFinished
#endif














#ifdef __cplusplus
	} /* extern "C" */
#endif /* __cplusplus */


#endif
