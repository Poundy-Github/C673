/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2022 conti smart core
**----------------------------------------------------------------------------**
**
* Administrative Information
* Namespace_: \..\QuasiStaticManager
* Class_____: C
* Name______: Qsm_Lcfg.c
* vision____: 0.1
* Author____: YinXing
* History___: 2022/12/14 V0.1 new creation 
*******************************************************************************
** DESCRIPTION:
** Quasi Static manager is implemented by the user to manage the quasi-static 
** data. Quasi Static data blocks are read and written using FEE’s read and 
** write APIs.
*******************************************************************************/
/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "Qsm_Lcfg.h" 
#include "Fee.h"
#include "Nvm.h"
/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

s_Qsm_QSBlock_SecureUpdateLog_t s_QSBlock_SecureUpdateInfo = {0};

s_Qsm_QSBlock_PartNumberSector_t s_QSBlock_PartNumberSector = {0};

s_Qsm_QSBlock_EOLModeGate_t  s_QSBlock_EOLModeGate = {0};

s_Qsm_QSBlock_StartupFlag_t s_QSBlock_StartupFlag = {0};

s_Qsm_QSBlock_AbnormalStartupFlag_t s_QSBlock_AbnormalStartupFlag = {0};

const s_Qsm_ReadAllInfo_t Qsm_ConfigAllTable[QSM_CONFIGBLOCKNUM] = 
{
	{NvMConf_NvMBlockDescriptor_NVM_Block_Reserve,          FeeConf_FeeBlockConfiguration_Fee_NVM_Block_SecureUpdateLog, &s_QSBlock_SecureUpdateInfo,    sizeof(s_QSBlock_SecureUpdateInfo),    0x00u},
	{NvMConf_NvMBlockDescriptor_NVM_Block_PartNumer_Sector, FeeConf_FeeBlockConfiguration_Fee_NVM_PartNumber_Sector,	 &s_QSBlock_PartNumberSector,    sizeof(s_QSBlock_PartNumberSector),    0x00u},
	{NvMConf_NvMBlockDescriptor_NVM_Block_Startup_Flag,     FeeConf_FeeBlockConfiguration_Fee_NVM_Block_Startup_Flag,    &s_QSBlock_StartupFlag,         sizeof(s_QSBlock_StartupFlag),         0x00u},
	{NvMConf_NvMBlockDescriptor_NvM_Block_EOLModeGate,      FeeConf_FeeBlockConfiguration_Fee_NvM_Block_EOLModeGate,     &s_QSBlock_EOLModeGate,         sizeof(s_QSBlock_EOLModeGate),         0x00u},
	{NvMConf_NvMBlockDescriptor_NVM_Block_ABCheck,          FeeConf_FeeBlockConfiguration_Fee_NVM_Block_ABCheck,         &s_QSBlock_AbnormalStartupFlag, sizeof(s_QSBlock_AbnormalStartupFlag), 0x00u}
};
/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------_Globale Function----------------------------------*/
/******************************************************************************/

