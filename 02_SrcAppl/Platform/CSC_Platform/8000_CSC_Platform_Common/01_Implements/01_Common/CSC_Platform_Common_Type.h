/**
 * \file CSC_Platform_Common_Type.h
 *
 * \brief
 *
 * \version refer the file of CSC_Platform_Common.h
 *
 */

#ifndef _CSC_PLATFORM_COMMON_TYPE_H_
#define _CSC_PLATFORM_COMMON_TYPE_H_

/*==================[inclusions]============================================*/


/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/
/*
 * \brief 	e_Csc_Platform_InitStatus_t,The modules init status
 *			When the status is Unint status,the software shall not run the main logic
 * */
typedef enum
{
	Csc_Platform_InitStatus_Uninit 	    = 0x00,
	Csc_Platform_InitStatus_Init 	    = 0x01,
	Csc_Platform_InitStatus_Max 		= 0xFF
}e_Csc_Platform_InitStatus_t;

#endif /* _CSC_PLATFORM_COMMON_TYPE_H_ */
