/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2017 by G-Pulse.		All rights reserved.
** This software is copyright protected and proprietary to G-Pulse.
** G-Pulse grants to you only those rights as set out in the license conditions.
** All other rights remain with G-Pulse.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \..\Notification$
* $Class_____: C$
* $Name______: Notifications.c$
* $Variant___: 1.0.0$
* $Revision__: 0$
* $Author____: YM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: Yes
**----------------------------------------------------------------------------**
** DESCRIPTION:
** Notifications Դ�ļ�
*******************************************************************************/

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Std_Types.h"
#include "common_platform.h"
#include "IfxStm_reg.h"
#if (!FS_EXEC_DISABLED)
#include "fs_check.h"
#include "function_safety.h"
#endif

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/

/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
uint32 J3_Ack_Cnt = 0u;
uint32 J3_Rdy_Cnt = 0u;
uint32 J3_End_Cnt = 0u;


/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/




void Icu_J3_Ack_Notification(void)
{
	J3_Ack_Cnt++;
	/* HR spitp ack edge callback */
	SpiTp_masterAck();
}



void Icu_J3_Rdy_Notification(void)
{
	J3_Rdy_Cnt++;
	/* HR spitp rdy edge callback */
	SpiTp_masterFrameExchange();
}


void Spi_J3SeqNotification(void)
{
	J3_End_Cnt++;

	/* HR spitp job finish callback */
	SpiTp_masterFiniNotification();
	#if (!FS_EXEC_DISABLED)
	FSCheck_SetSpiAliveFlag();
	#endif
}





/*******************************************************************************
* $History__:$
* V1.0.0; 0     15.05.2017 YM
*  N: new created
* V2.0.0; 0     28.02.2019 LY
*  N: Add DMA_CPU
*******************************************************************************/

