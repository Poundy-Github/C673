/**
 * \file MTSI_TaskId_Cfg.h
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
#ifndef MTSI_TASKID_CFG_H
#define MTSI_TASKID_CFG_H

#include <Std_Types.h>

/*****************************************************************************
 * Meas Freeze TASK Id Definition 
 * 
 * Naming rule:
 * #define MTSI_TASK_ID_<Module Name> <TASK Id> 
 * 
 * <Module Name> represent user module such as FCT, LCF, FCU, SDC, etc
 * 
*****************************************************************************/
#define MTSI_TASK_ID_LCF_VEH        23U
#define MTSI_TASK_ID_LCF_SEN        90U
#define MTSI_TASK_ID_VDYADAPTER     21U
#define MTSI_TASK_ID_VDY            2U
#define MTSI_TASK_ID_HLA            65U
#define MTSI_TASK_ID_TSA            66U
#define MTSI_TASK_ID_FCT_VEH        207U
#define MTSI_TASK_ID_FCT_SEN        208U


#endif /*MTSI_TASKID_CFG_H*/