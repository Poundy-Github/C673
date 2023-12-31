/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2023 conti smart core
**----------------------------------------------------------------------------**
**
* Administrative Information
* Namespace_: \..\Qsm
* Class_____: C
* Name______: Qsm.c
* vision____: 0.1
* Author____: YinXing
* History___: 2023/05/12 V0.1 new creation 
*******************************************************************************
** DESCRIPTION:
** Quasi Static manager is implemented by the user to manage the quasi-static 
** data. Quasi Static data blocks are read and written using FEE’s read and 
** write APIs.
*******************************************************************************/

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "Qsm_Core.h"
/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*----------------------------Local Function----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------_Globale Function----------------------------------*/
/******************************************************************************/

/*******************************************************************************
** Syntax :FUNC(void, RTE_CODE) Qsm_InitFunction(void)      			      **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None          										  **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :  															  **
**                                            								  **
*******************************************************************************/
FUNC(void, RTE_CODE) Qsm_InitFunction(void)
{
	Qsm_Core_InitFunction();
}

/*******************************************************************************
** Syntax :FUNC(void, RTE_CODE) Qsm_InitFunction(void)      			      **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None          										  **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :  															  **
**                                            								  **
*******************************************************************************/
FUNC(void, RTE_CODE) Qsm_MainFunction(void)
{
	Qsm_Core_MainFunction();
}
/******************************************************************************/
/*----------------------------------END-FILE----------------------------------*/
/******************************************************************************/

