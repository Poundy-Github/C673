/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2022 conti smart core
**----------------------------------------------------------------------------**
**
* Administrative Information
* Namespace_: \..\Cdm
* Class_____: C
* Name______: Cdm_Cfg.h
* vision____: 0.1
* Author____: YinXing
* History___: 2023/03/01 V0.1 new creation 
*******************************************************************************
** DESCRIPTION:
*******************************************************************************/

#ifndef _CDM_CFG_H
#define _CDM_CFG_H
/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Platform_Types.h>
#include <NvM.h>
#include "fs_pdo.h"
/******************************************************************************/
/*--------------------------------Configuration-------------------------------*/
/******************************************************************************/
/*
 * \brief   The Block Length of F18C,
 * */
#define DIAG_SIZE_OF_ECUSERIALNUMBERDATAID (uint8)13
/*
 * \brief   The Block Length of F190,
 * */
#define DIAG_SIZE_OF_VINDATAIDENTIFIER     (uint8)17
/*
 * \brief   The Block Length of BLOCK_SIZE_FCWLastbutoneappearedFD14,
 * */
#define BLOCK_SIZE_FCWLastbutoneappearedFD14 49U
/*
 * \brief   The Block Length of BLOCK_SIZE_AWBLastbutoneappearFD15,
 * */
#define BLOCK_SIZE_AWBLastbutoneappearFD15   49U
/*
 * \brief   The Block Length of BLOCK_SIZE_AEBLastbutoneappearFD16,
 * */
#define BLOCK_SIZE_AEBLastbutoneappearFD16   49U
/*
 * \brief   The Block Length of BLOCK_SIZE_FCWLastappearFD17,
 * */
#define BLOCK_SIZE_FCWLastappearFD17         49U
/*
 * \brief   The Block Length of BLOCK_SIZE_AWBLasteappearFD18,
 * */
#define BLOCK_SIZE_AWBLasteappearFD18        49U
/*
 * \brief   The Block Length of BLOCK_SIZE_AEBLastappearFD19,
 * */
#define BLOCK_SIZE_AEBLastappearFD19         49U

#define DIAG_SIZE_OF_ECUHardwareVersion (uint8)8

#define DIAG_SIZE_OF_SYSTEM_SUPPLIER_ID (uint8)7

#define DIAG_SIZE_OF_FBL_VERSION_INFO (uint8)4

#define DIAG_SIZE_OF_FBL_REQUIREMENT_SPEC (uint8)4

#define DIAG_SIZE_OF_SOFTWARE_NUMBER (uint8)20

#define DIAG_SIZE_OF_J3_OFTWARE_NUMBER (uint8)20

#define DIAG_SIZE_OF_SUPPLIER_HWVERSION (uint8)9

#define DIAG_SIZE_OF_SUPPLIER_SWVERSION (uint8)16

#define DIAG_SIZE_OF_FAB_SWITCH (uint8)1

#define DIAG_SIZE_OF_TSR_SWITCH (uint8)1

#define DIAG_SIZE_OF_TLA_SWITCH (uint8)1

#define DIAG_SIZE_OF_EOL_INFO_INPUT (uint8)6

#define DIAG_SIZE_OF_KEY_COUNTER (uint8)2

#define DIAG_SIZE_OF_VEHICLE_TYPE (uint8)1

#define DIAG_SIZE_OF_FINGER_PRINT (uint8)7

#define DIAG_SIZE_OF_SERIAL_NUMBER (uint8)5

#define DIAG_SIZE_OF_CALI_DATA (uint8)20

#define DIAG_SIZE_OF_APP_DOWMLOAD_AREA (uint8)1

#define DIAG_SIZE_OF_LANE_CONFIGURATION (uint8)2

#define DIAG_SIZE_OFEOLCALIBRATIONDATA (uint8)20

#define DIAG_SIZE_OFSDACALIBRATIONDATA (uint8)20

#define DIAG_SIZE_OF_EOLMODEGATE (uint8)3

#define DIAG_SIZE_OF_HMISWITCH (uint8)7

#define DIAG_SIZE_OF_EOLGATE (uint8)3

#define NVM_VOLT_MIN	(float32)10.5f

#define NVM_VOLT_MAX	(float32)18.5f

#define NVM_TOTAL_NUMBER_OF_CDM_BLOCK 28u

#define INVALID_CYCLE_MAX 0xFFFFFFFFu

#define INVALID_BLOCK_ID 0xFFu

#define CDM_JOB_MAX		40u

#define CDM_ERROR_DELAY (500/10u)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/
typedef enum{
	CDM_NVMWRITE_IMME,
	CDM_NVMWRITE_SHOTDOWN,
}CdmWriteType_e;

typedef enum{
	CDM_NVMREAD_IMME,
	CDM_NVMREAD_ALL,
}CdmReadType_e;
	
typedef enum{
	CDM_NVMBLOCK,
	CDM_QUASIBLOCK,
}CdmBlockType_e;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/
typedef struct{
uint16 								NvmBlockId;
uint16 								CdmBlockLength;
void  								*CdmramBlockDataAddress;
CdmWriteType_e 						CdmWrite;
CdmReadType_e						CdmRead;
CdmBlockType_e						CdmBlockType;
}Cdm_BlockDescriptorType;

typedef struct
{
    uint32 CustomerCode1;
	uint8 SpecVariant;
	uint8 Operationmode;
	uint8 Eolmode[2];
}s_Cdm_CustomerData_t;

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define CDM_IDX(NvmId)		(NvmId - 4u)

#define GET_CDM_CUSTOMER_CODE()    (s_Cdm_CustomerCode.CustomerCode1)

#define GET_CDM_VARIANT()          (s_Cdm_CustomerCode.SpecVariant)

#define GET_CDM_OPERATION_MODE()   (s_Cdm_CustomerCode.Operationmode)

#define EOL_MODE_ON                ((s_Cdm_CustomerCode.Eolmode[0] == 0x05u) && (s_Cdm_CustomerCode.Eolmode[1] == 0x25u))

#define EOL_MODE_OFF               ((s_Cdm_CustomerCode.Eolmode[0] == 0x00u) && (s_Cdm_CustomerCode.Eolmode[1] == 0x00u))

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
extern s_Cdm_CustomerData_t s_Cdm_CustomerCode;

extern uint8 VdyNvm_Clear;

// Declaration For ECUSoftwareVersionNumberDataIdentifier 0xF089 NVM storing use
extern const uint8 ROM_NVM_BLOCK_ECUHardwareVersion[DIAG_SIZE_OF_ECUHardwareVersion];
extern uint8 RAM_NVM_BLOCK_ECUHardwareVersion[DIAG_SIZE_OF_ECUHardwareVersion];

//Declaration For ECUSerialNumberDataIdentifier 0xF18C NVM storing use
extern const uint8 ROM_NVM_BLOCK_SerialNumberDataId[DIAG_SIZE_OF_ECUSERIALNUMBERDATAID];
extern uint8 RAM_NVM_BLOCK_SerialNumberDataId[DIAG_SIZE_OF_ECUSERIALNUMBERDATAID];

//Declaration value for VINDataIdentifier 0xF190 NVM storing use
extern const uint8 ROM_NVM_BLOCK_VINDataIdentifier[DIAG_SIZE_OF_VINDATAIDENTIFIER];
extern uint8 RAM_NVM_BLOCK_VINDataIdentifier[DIAG_SIZE_OF_VINDATAIDENTIFIER];

//Declaration value for FAB_switch 0xF1F1 NVM storing use
extern const uint8 ROM_NVM_BLOCK_FAB_switch[DIAG_SIZE_OF_FAB_SWITCH];
extern uint8 RAM_NVM_BLOCK_FAB_switch[DIAG_SIZE_OF_FAB_SWITCH];

//Declaration value for TSR_switch 0xF1F2 NVM storing use
extern const uint8 ROM_NVM_BLOCK_TSR_switch[DIAG_SIZE_OF_TSR_SWITCH];
extern uint8 RAM_NVM_BLOCK_TSR_switch[DIAG_SIZE_OF_TSR_SWITCH];

//Declaration value for FAB_switch 0xF1F3 NVM storing use
extern const uint8 ROM_NVM_BLOCK_TLA_switch[DIAG_SIZE_OF_TLA_SWITCH];
extern uint8 RAM_NVM_BLOCK_TLA_switch[DIAG_SIZE_OF_TLA_SWITCH];

//Declaration value For for EOL info input 0xF1F5 & 0x3BAF NVM storing use
extern const uint8 ROM_NVM_BLOCK_EOL_Info_Input[DIAG_SIZE_OF_EOL_INFO_INPUT];
extern uint8 RAM_NVM_BLOCK_EOL_Info_Input[DIAG_SIZE_OF_EOL_INFO_INPUT];

//Declaration value for Security Attempt counter 0x0103 NVM storing use
extern const uint8 ROM_NVM_BLOCK_Security_AttemptCount[DIAG_SIZE_OF_KEY_COUNTER];
extern uint8 RAM_NVM_BLOCK_Security_AttemptCount[DIAG_SIZE_OF_KEY_COUNTER];

//Declaration value for Vehicle type 0xF1F0 NVM storing use
extern const uint8 ROM_NVM_BLOCK_Vehicletype[DIAG_SIZE_OF_VEHICLE_TYPE];
extern uint8 RAM_NVM_BLOCK_Vehicletype[DIAG_SIZE_OF_VEHICLE_TYPE];

//Declaration value for Finger print 0xF184 NVM storing use
extern const uint8 ROM_NVM_BLOCK_Fingerprint[DIAG_SIZE_OF_FINGER_PRINT];
extern uint8 RAM_NVM_BLOCK_Fingerprint[DIAG_SIZE_OF_FINGER_PRINT];

//Declaration value for PCB A Serial Number 0xFD24 NVM storing use
extern const uint8 ROM_NVM_BLOCK_PCBASerialNumberDataIdentifier[DIAG_SIZE_OF_SERIAL_NUMBER];
extern uint8 RAM_NVM_BLOCK_PCBASerialNumberDataIdentifier[DIAG_SIZE_OF_SERIAL_NUMBER];

//Declaration value For Lane function configuration 0xF1FE
extern const uint8 ROM_NVM_BLOCK_LaneFunctionConfiguration[DIAG_SIZE_OF_LANE_CONFIGURATION];
extern uint8 RAM_NVM_BLOCK_LaneFunctionConfiguration[DIAG_SIZE_OF_LANE_CONFIGURATION];

extern const uint8 ROM_NVM_BLOCK_EOLCalibrationData[DIAG_SIZE_OFEOLCALIBRATIONDATA];
extern uint8 RAM_NVM_BLOCK_EOLCalibrationData[DIAG_SIZE_OFEOLCALIBRATIONDATA];

extern const uint8 ROM_NVM_BLOCK_SDACalibrationData[DIAG_SIZE_OFSDACALIBRATIONDATA];
extern uint8 RAM_NVM_BLOCK_SDACalibrationData[DIAG_SIZE_OFSDACALIBRATIONDATA];

extern const uint8 ROM_NVM_BLOCK_EOLModeData[DIAG_SIZE_OF_EOLMODEGATE];
extern uint8 RAM_NVM_BLOCK_EOLModeData[DIAG_SIZE_OF_EOLMODEGATE];

extern const uint8 ROM_NVM_BLOCK_HMISwitchStatus[DIAG_SIZE_OF_HMISWITCH];
extern uint8 RAM_NVM_BLOCK_HMISwitchStatus[DIAG_SIZE_OF_HMISWITCH];

/**
 * \brief Declaration value for RAM_NVM_BLOCK_FCWLastbutoneappearedFD14 NVM temporary storing  use,
 */
extern const uint8 ROM_NVM_BLOCK_FCWLastbutoneappearedFD14[BLOCK_SIZE_FCWLastbutoneappearedFD14];
extern uint8 RAM_NVM_BLOCK_FCWLastbutoneappearedFD14[BLOCK_SIZE_FCWLastbutoneappearedFD14];
/**
 * \brief Declaration value for RAM_NVM_BLOCK_AWBLastbutoneappearFD15 NVM temporary storing  use,
 */
extern const uint8 ROM_NVM_BLOCK_AWBLastbutoneappearFD15[BLOCK_SIZE_AWBLastbutoneappearFD15];
extern uint8 RAM_NVM_BLOCK_AWBLastbutoneappearFD15[BLOCK_SIZE_AWBLastbutoneappearFD15];
/**
 * \brief Declaration value for RAM_NVM_BLOCK_AEBLastbutoneappearFD16 NVM temporary storing  use,
 */
extern const uint8 ROM_NVM_BLOCK_AEBLastbutoneappearFD16[BLOCK_SIZE_AEBLastbutoneappearFD16];
extern uint8 RAM_NVM_BLOCK_AEBLastbutoneappearFD16[BLOCK_SIZE_AEBLastbutoneappearFD16];
/**
 * \brief Declaration value for RAM_NVM_BLOCK_FCWLastappearFD17 NVM temporary storing  use,
 */
extern const uint8 ROM_NVM_BLOCK_FCWLastappearFD17[BLOCK_SIZE_FCWLastappearFD17];
extern uint8 RAM_NVM_BLOCK_FCWLastappearFD17[BLOCK_SIZE_FCWLastappearFD17];
/**
 * \brief Declaration value for RAM_NVM_BLOCK_AWBLasteappearFD18 NVM temporary storing  use,
 */
extern const uint8 ROM_NVM_BLOCK_AWBLasteappearFD18[BLOCK_SIZE_AWBLasteappearFD18];
extern uint8 RAM_NVM_BLOCK_AWBLasteappearFD18[BLOCK_SIZE_AWBLasteappearFD18];
/**
 * \brief Declaration value for RAM_NVM_BLOCK_AEBLastappearFD19 NVM temporary storing  use,
 */
extern const uint8 ROM_NVM_BLOCK_AEBLastappearFD19[BLOCK_SIZE_AEBLastappearFD19];
extern uint8 RAM_NVM_BLOCK_AEBLastappearFD19[BLOCK_SIZE_AEBLastappearFD19];

extern VDYNvIoData_t RAM_BLOCK_VDY_Data;
extern const VDYNvIoData_t ROM_BLOCK_VDY_Data;

extern const Cdm_BlockDescriptorType Cdm_BlockDescriptorTable[NVM_TOTAL_NUMBER_OF_CDM_BLOCK];
extern FSDebugStateus RAM_BLOCK_FS_DEBUG;


/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
extern FUNC(void, RTE_CODE) Cdm_v_BoardDisableECCCheck(void);
extern FUNC(void, RTE_CODE) Cdm_v_BoardEnableECCCheck(void);
extern FUNC(void, RTE_CODE) Cdm_v_InitEOLModeGate_QSData(void);
extern FUNC(void, RTE_CODE) Cdm_v_InitCustomerCode_QSData(void);
extern FUNC(void, RTE_CODE) Cdm_v_InitSpecVariant_QSData(void);
extern FUNC(void, RTE_CODE) Cdm_v_InitOperationMode_QSData(void);
extern FUNC(Std_ReturnType, NVM_CODE) Fs_NvmReadCopyBlock(void* NvMBuffer);
extern FUNC(Std_ReturnType, NVM_CODE) Fs_NvmWriteCopyBlock(void* NvMBuffer);

#endif
