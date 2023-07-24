/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2022 conti smart core
**----------------------------------------------------------------------------**
**
* Administrative Information
* Namespace_: \..\QuasiStaticManager
* Class_____: C
* Name______: Qsm_Core.h
* vision____: 0.1
* Author____: YinXing
* History___: 2022/12/14 V0.1 new creation 
*******************************************************************************
** DESCRIPTION:
** Quasi Static manager is implemented by the user to manage the quasi-static 
** data. Quasi Static data blocks are read and written using FEE’s read and 
** write APIs.
*******************************************************************************/
#ifndef QUASISTATICMANAGET_H
#define QUASISTATICMANAGET_H
/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "Std_Types.h" 
#include "Qsm_Cfg.h"
/******************************************************************************/
/*--------------------------------Configuration-------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define Get_QsmOprSt()			(QSM_ReqOprStaticBlock.QSM_ReqOpretion)
#define Set_QsmOprSt(Val)		(QSM_ReqOprStaticBlock.QSM_ReqOpretion = Val)
#define Get_QsmBlockId()		(QSM_ReqOprStaticBlock.BlockId)
#define Set_QsmBlockId(Val)		(QSM_ReqOprStaticBlock.BlockId = Val)
#define Get_QsmBlockOffset()	(QSM_ReqOprStaticBlock.BlockOffset)
#define Set_QsmBlockOffset(Val)	(QSM_ReqOprStaticBlock.BlockOffset = Val)
#define Get_QsmBlockLength()	(QSM_ReqOprStaticBlock.BlockLength)
#define Set_QsmBlockLength(Val)	(QSM_ReqOprStaticBlock.BlockLength = Val)
#define Get_QsmDataBuffer()		(QSM_ReqOprStaticBlock.DataBuffer)
#define Set_QsmDataBuffer(Val)	(QSM_ReqOprStaticBlock.DataBuffer = Val)
#define Get_QsmReqResult()		(QSM_ReqOprStaticBlock.ReqResult)
#define Set_QsmReqResult(Val)	(QSM_ReqOprStaticBlock.ReqResult = Val)

#define Get_QsmEraseSt()		(Qsm_EraseStatus)
#define Set_QsmEraseSt(Val)		(Qsm_EraseStatus = Val)

#define Get_QsmReadSt()			(Qsm_ReadStatus)
#define Set_QsmReadSt(Val)		(Qsm_ReadStatus = Val)

#define Get_QsmWriteSt()		(Qsm_WriteStatus)
#define Set_QsmWriteSt(Val)		(Qsm_WriteStatus = Val)

#define Get_Qsm_ErrorCnt()		(Qsm_ErrorCnt)
#define Set_Qsm_ErrorCnt(Val)	(Qsm_ErrorCnt = Val)

#define Get_QsmPreReqOprSt()	(Qsm_PreReqOprSt)
#define Set_QsmPreReqOprSt(Val)	(Qsm_PreReqOprSt = Val)

/*
 * \brief 	MED_MODULE_ID,
 * */
#ifndef QSM_MODULE_ID
#define QSM_MODULE_ID			(0x8008ul)
#endif

/*
 * \brief 	MED_SW_MAJOR_VERSION,
 * */
#ifndef QSM_SW_MAJOR_VERSION
#define QSM_SW_MAJOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (QSM_SW_MAJOR_VERSION > 99)
#error QSM_SW_MAJOR_VERSION out of range
#endif

/*
 * \brief 	MED_SW_MINOR_VERSION,
 * */
#ifndef QSM_SW_MINOR_VERSION
#define QSM_SW_MINOR_VERSION			(0u)
#endif

/*TODO : Check the version number range*/
#if (QSM_SW_MINOR_VERSION > 99)
#error QSM_SW_MINOR_VERSION out of range
#endif

/*
 * \brief 	MED_SW_PATCH_VERSION,
 * */
#ifndef QSM_SW_PATCH_VERSION
#define QSM_SW_PATCH_VERSION			(1u)
#endif

/*TODO : Check the version number range*/
#if (QSM_SW_PATCH_VERSION > 99)
#error QSM_SW_PATCH_VERSION out of range
#endif

/*
 * \brief 	MED_CORE_DEBUG_ENABLE,
 * */
#ifndef  QSM_CORE_DEBUG_ENABLE
#define QSM_CORE_DEBUG_ENABLE		STD_OFF
#endif

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
extern void Qsm_CancelPendingJob(void);
extern void Qsm_ReadAll(void);
extern FUNC(void, RTE_CODE) Qsm_Core_InitFunction(void);
extern FUNC(void, RTE_CODE) Qsm_Core_MainFunction(void);
#endif 
