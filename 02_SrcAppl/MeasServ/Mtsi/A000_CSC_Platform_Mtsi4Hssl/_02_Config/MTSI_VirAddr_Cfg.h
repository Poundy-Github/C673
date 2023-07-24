/**
 * \file MTSI_VirAddr_Cfg.h
 *
 * \brief
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Data		|		Author			| 	Comments
 * V0.0.1		15th,Nov,2022		    HAN Gu			    Init version
 *
 *
 */
#ifndef MTSI_VIRADDR_CFG_H
#define MTSI_VIRADDR_CFG_H

#include <Std_Types.h>

/*****************************************************************************
 * Meas Freeze Virtual Address Definition 
 * 
 * Naming rule:
 * #define MTSI_ADDR_<Module Name>_<Variable Name>_<Reserve> <4 Bytes address> 
 * 
 * <Module Name> represent user module such as FCT, LCF, FCU, SDC, etc
 * <Variable Name> represent variables used to meas freeze such as VEHDYN, VEHPAR, CTRL
 * <Reserve> used to identify several variables with the same data type
 * 
 * Notice:
 * Virtual Address defined here are only for BSW used variable or Interface variables between BSW and SWC.
 * Those variables used in SWC internally shall be defined elsewhere.
 * 
 * Range:
 * 0xA0000000 - 0xFFFFFEFF
*****************************************************************************/
#define MTSI_ADDR_FCT_CTRL_V 		0xA0050000  /*Size: 0x00000970*/
#define MTSI_ADDR_FCT_VEHDYN_V 		0xA0051000  /*Size: 0x00000128*/
#define MTSI_ADDR_FCT_VEHPAR_V 		0xA0051200  /*Size: 0x00000110*/













#endif /*MTSI_VIRADDR_CFG_H*/