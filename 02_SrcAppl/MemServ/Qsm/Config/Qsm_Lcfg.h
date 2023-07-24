/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2022 conti smart core
**----------------------------------------------------------------------------**
**
* Administrative Information
* Namespace_: \..\QuasiStaticManager
* Class_____: C
* Name______: Qsm_Lcfg.h
* vision____: 0.1
* Author____: YinXing
* History___: 2022/12/14 V0.1 new creation 
*******************************************************************************
** DESCRIPTION:
** Quasi Static manager is implemented by the user to manage the quasi-static 
** data. Quasi Static data blocks are read and written using FEE’s read and 
** write APIs.
*******************************************************************************/
#ifndef QSM_LCFG_H_
#define QSM_LCFG_H_
/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "Std_Types.h" 
#include "Qsm_Cfg.h"
#include "Qsm_Type.h"
/******************************************************************************/
/*--------------------------------Configuration-------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/
/*Secure programming log(FEC0) */ 
typedef struct
{
    uint16 u_AttemptDownloadingCounter;
    uint16 u_FlashDriverActivatedSuccessfullyCounter;
    uint16 u_AppDownloadedSuccessfullyCounter;
    uint16 u_FblDownloadedSuccessfullyCounter;
}s_Qsm_SecureUpdateLog_t;

typedef struct
{
    uint8 Padding[4];
	s_Qsm_SecureUpdateLog_t SecLogInfo;
}s_Qsm_QSBlock_SecureUpdateLog_t;

typedef struct
{
    uint8 Padding[4];
    uint8 F1FF[32];
	uint32 VehCustomCode;
	uint8 VehSpecVar; 
	uint8 OperationMode;
}s_Qsm_QSBlock_EcuSpecInfo_t;

typedef struct
{
    uint8 Padding[4];
    uint8 F18A[32];
	uint8 F187[32];
	uint8 F089[32];
}s_Qsm_QSBlock_PartNumberSector_t;

typedef struct
{
    uint8 Padding[4];
	uint8 BlankAFlag[8];
	uint8 BlankBFlag[8];
}s_Qsm_QSBlock_AbnormalStartupFlag_t;

typedef struct
{
    uint8 Padding[4];
    uint8 StartupFlag[8];
}s_Qsm_QSBlock_StartupFlag_t;

typedef struct
{
	uint16 	NvmBlockId;
	uint16 	QuasiBlockId;
	void 	*DataPtr;
	uint16 	datalen;
	uint16  offset;
}s_Qsm_ReadAllInfo_t;
/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

extern s_Qsm_QSBlock_SecureUpdateLog_t s_QSBlock_SecureUpdateInfo;

extern s_Qsm_QSBlock_PartNumberSector_t s_QSBlock_PartNumberSector;

extern s_Qsm_QSBlock_EcuSpecInfo_t  s_QSBlock_EcuSpecInfo;

extern s_Qsm_QSBlock_StartupFlag_t s_QSBlock_StartupFlag;

extern s_Qsm_QSBlock_AbnormalStartupFlag_t  s_QSBlock_AbnormalStartupFlag;

extern const s_Qsm_ReadAllInfo_t Qsm_ConfigAllTable[QSM_CONFIGBLOCKNUM];
/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define GET_QSM_CustomerCode()        (s_QSBlock_EcuSpecInfo.VehCustomCode)

#define GET_QSM_VehicleVariant()      (s_QSBlock_EcuSpecInfo.VehSpecVar)

#define GET_QSM_EcuOperationMode()    (s_QSBlock_EcuSpecInfo.OperationMode)

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
extern void Qsm_CancelPendingJob(void);
extern void Qsm_ReadAll(void);

#endif
