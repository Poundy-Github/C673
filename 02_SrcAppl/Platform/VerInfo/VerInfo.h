/**
 * \file VerInfo.h
 *
 * \brief the components stored the ECU software version information.
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.03.23			Mingfen XIAO			Init version
 * V0.0.6       2022.04.29          Fangyu JIANG            Public CAN0 ASIMA
 * V0.0.7       2022.05.11          Fangyu JIANG            Private CAN1 DBC Import
 */
/*
 * The Software Version Management Measures;
 * 1.The software shall contain version number and separator;
 * 2.The version number part consists of three numbers which there contains MAJOR_VERSION ,MINOR_VERSION and PATCH_VERSION;
 * 3.The Mcu/Ecu software number add the prefix of "VERINFO_MCU_SW_",the version number identifier is VERINFO_MCU_SW_MAJOR_VERSION,VERINFO_MCU_SW_MINOR_VERSION and VERINFO_MCU_SW_PATCH_VERSION.
 * 4.The three number use the uint8 data type and the range is 00-99;
 * 5.The separator use the '.';
 * 6.The sample of version information is 01.00.00;
 * 7.The VerInfo components shall provide API to get the version number;
 * 8.The version number have two ways to upgrade the version number;
 * 9.When the project starts, The software team(SPM,SW Integrator/SW Arch/SW Developer) should define a way to upgrade the version;
 * 10.General,the software version number shall mapping to DID(e.g.ECU software version,0xF189) from Dcm.
 *
 * The software components also definition the version number following this rules.
 * 1.The software shall contain version number and separator;
 * 2.The version number part consists of three numbers which there contains MAJOR_VERSION ,MINOR_VERSION and PATCH_VERSION;
 * 3.The software components number add the prefix of "<SWCs>_SW_",the version number identifier is <SWCs>_SW_MAJOR_VERSION,<SWCs>_SW_MINOR_VERSION and <SWCs>_SW_PATCH_VERSION.
 * 4.The three number use the uint8 data type and the range is 00-99;
 * 5.The separator use the '.';
 * 6.The sample of version information is 01.00.00;
 * 7.The VerInfo components shall provide API to get the version number;
 * 8.The version number have one ways to upgrade the version number;
 * 9.The software components shall definition a component id,like the "<SWCs>_MODULE_ID",the component may be use for CICT;
 * 10.The Module ID start for 0x8001,For each new addition to the software module ID,increase 1;
 * Notes : The module ID is determined by the software architecture.
 *
 * The Software Version number have two ways following:
 * One :
 * 1.1 When developer updated any code,the PATCH_VERSION number shall increase 1(One commit,the PATCH_VERSION will increase);
 * 1.2 When the Integrator released a version software,the MINOR_VERSION  shall increase 1 and the PATCH_VERSION shall clear to 0;
 * 1.3 When the software achieve the gate or milestone(may be from customer),the MAJOR_VERSION shall increase 1,then the MINOR_VERSION and PATCH_VERSION shall clear to 0;
 * 1.4 The developer just modified the PATCH_VERSION number;
 * 1.5 The MINOR_VERSION and MAJOR_VERSION number only modified by integrator.
 *
 * Two :
 * 2.1 When the software detail design(the code implemented),the PATCH_VERSION number shall increase 1;
 * 2.2 When the software arch updated(interface updated[RTE interface]/new feature/schedule table updated/e.t.c),the MINOR_VERSION shall increase 1 and the PATCH_VERSION shall clear to 0;
 * 2.3 When the Integrator release software,the MAJOR_VERSION shall increase 1,then the MINOR_VERSION and PATCH_VERSION shall clear to 0;
 *
 * The Software Components version number have one ways following:
 * 1.When the software components detail design(the code implemented or bug fixed),the PATCH_VERSION number shall increase 1;
 * 2.When the software components arch updated(interface updated/state machine updated),the MINOR_VERSION shall increase 1 and the PATCH_VERSION shall clear to 0;
 * 3.When the software components added new feature(alse arch updated),the MAJOR_VERSION shall increase 1,then the MINOR_VERSION and PATCH_VERSION shall clear to 0;
 *
 * Notes : The MFC5J3 not following blow rules.
 * */

#ifndef _VERINFO_H_
#define _VERINFO_H_
/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */

/*==================[macros]=================================================*/
/*
 * \brief 	VERINFO_MCU_SW_MAJOR_VERSION,
 * */
#ifndef VERINFO_MCU_SW_MAJOR_VERSION
#define VERINFO_MCU_SW_MAJOR_VERSION			(1u)
#endif

/*TODO : Check the version number range*/
#if (VERINFO_MCU_SW_MAJOR_VERSION > 9)
#error VERINFO_MCU_SW_MAJOR_VERSION out of range
#endif

/*
 * \brief 	VERINFO_MCU_SW_MINOR_VERSION,
 * */
#ifndef VERINFO_MCU_SW_MINOR_VERSION
#define VERINFO_MCU_SW_MINOR_VERSION			(8u)
#endif

/*TODO : Check the version number range*/
#if (VERINFO_MCU_SW_MINOR_VERSION > 9)
#error VERINFO_MCU_SW_MINOR_VERSION out of range
#endif

/*
 * \brief 	VERINFO_MCU_SW_PATCH_VERSION,
 * */
#ifndef VERINFO_MCU_SW_PATCH_VERSION
#define VERINFO_MCU_SW_PATCH_VERSION			(2u)
#endif

/*TODO : Check the version number range*/
#if (VERINFO_MCU_SW_PATCH_VERSION > 99)
#error VERINFO_MCU_SW_PATCH_VERSION out of range
#endif


#define VERINFO_MCU_SW_VERSION_MODE_ASCII				(0u)
#define VERINFO_MCU_SW_VERSION_MODE_HEX					(1u)
#define VERINFO_MCU_SW_VERSION_MODE_CA_C385_ASCII		(2u)
/*
 * \brief 	VERINFO_MCU_SW_VERSION_MODE,
 * 			the default is VERINFO_MCU_SW_VERSION_MODE_HEX
 * */
#define VERINFO_MCU_SW_VERSION_MODE				VERINFO_MCU_SW_VERSION_MODE_CA_C385_ASCII

#ifndef VERINFO_MCU_SW_BANK_CHECK_ENABLE
#define VERINFO_MCU_SW_BANK_CHECK_ENABLE			STD_ON
#if (VERINFO_MCU_SW_BANK_CHECK_ENABLE == STD_ON)

#ifndef VERINFO_MCU_SW_BANK_A_ADDRESS
#define VERINFO_MCU_SW_BANK_A_ADDRESS 				(0x80104060ul)
#endif	/*ifndef VERINFO_MCU_SW_BANK_A_ADDRESS*/

#ifndef VERINFO_MCU_SW_BANK_B_ADDRESS
#define VERINFO_MCU_SW_BANK_B_ADDRESS				(0x80204060ul)
#endif	/*ifndef VERINFO_MCU_SW_BANK_B_ADDRESS*/

#endif	/*VERINFO_MCU_SW_BANK_CHECK_ENABLE == STD_ON*/
#endif	/*ifndef VERINFO_MCU_SW_BANK_CHECK_ENABLE*/

/*
 * \brief 	The length of software generate time,
 * */
#define VERINFO_MAKETIME_LEN                  ((uint8)23u)
/*
 * \brief 	The length of software generate user,
 * */
#define VERINFO_USERTIME_LEN                  ((uint8)10u)
/*
 * \brief 	The length of software generate computer name,
 * */
#define VERINFO_COMPUTERNAME_LEN              ((uint8)10u)
/*
 * \brief 	The length of software generate computer name,
 * */
#define VERINFO_PALTFORMNAME_LEN              ((uint8)10u)
/*
 * \brief 	The length of Network information data identifier,
 * */
#define VERINFO_NETWORKINFORMATION_LEN        ((uint8)4u)
/*
 * \brief 	The length of function dpecification data identifier,
 * */
#define VERINFO_FUNCTIONSPECIFICATION_LEN     ((uint8)4u)
/*
 * \brief 	The length of diagnostic definition data identifier,
 * */
#define VERINFO_DIAGNOSTICDEFINITION_LEN      ((uint8)4u)

/*
 * \brief 	The length of software version number,
 * */
#define VERINFO_SOFTWAREVERSIONNUMBER_LEN     ((uint8)8u)
/*
 * \brief 	The length of software number,
 * */
#define VERINFO_SOFTWARENUMBER_LEN            ((uint8)20u)
/*
 * \brief 	The length of ECU hardware version number,
 * */
#define VERINFO_ECUHARDWAREVERSIONNUMBER_LEN  ((uint8)9u)
/*
 * \brief 	The length of project id,
 * */
#define VERINFO_PROJECTID_LEN                 ((uint8)2u)
/*
 * \brief 	The length of ECU internal software number,
 * */
#define VERINFO_ECUINTERNALSWNUMBER_LEN       ((uint8)5u)
/*
 * \brief 	The length of Soc software number,
 * */
#define VERINFO_SOCSOFTWARENUMBER_LEN         ((uint8)20u)

/*==================[type definitions]=======================================*/
/*
 * \brief 	e_Cpr_InitStatus_t,Cpr Init Status
 *			When the status is Unint status,the software shall not run the main logic
 * */
typedef enum
{
	VerInfo_BankType_None   = 0x00, 
    VerInfo_BankType_A 	    = 0x41, /*A*/
	VerInfo_BankType_B 	    = 0x42, /*B*/
	VerInfo_BankType_Max 	= 0xFF
}e_VerInfo_BankType_t;

/*
 * \brief 	s_VerInfo_RelVars_t,
 *			The below struct include all important paramter store in ROM.
 * */
typedef struct 
{
    /*Part1:  used in all mot-Variants(43bytes)*/
    uint8 a_SwMakeTime[VERINFO_MAKETIME_LEN];
	uint8 a_SwDeveloperName[VERINFO_USERTIME_LEN];
	uint8 a_SwComputer[VERINFO_COMPUTERNAME_LEN];
	uint8 a_PlatformName[VERINFO_PALTFORMNAME_LEN];
	uint8 a_Padding[43];
	/* Part2: variant specific*/
    uint8 a_NetworkInformationDataIdentifier[VERINFO_NETWORKINFORMATION_LEN];
    uint8 a_FunctionSpecificationDataIdentifier[VERINFO_FUNCTIONSPECIFICATION_LEN];
    uint8 a_DiagnosticDefinitionDataIdentifier[VERINFO_DIAGNOSTICDEFINITION_LEN];
    uint8 a_ECUSoftwareVersionNumberDataIdentifier[VERINFO_SOFTWAREVERSIONNUMBER_LEN];
    uint8 a_ECUHardwareVersionNumber[VERINFO_ECUHARDWAREVERSIONNUMBER_LEN];
    uint8 a_ProjectID[VERINFO_PROJECTID_LEN];
    uint8 a_ECUInternalSoftwareVersionNumber[VERINFO_ECUINTERNALSWNUMBER_LEN];
	uint8 a_SocSoftwareNumberDataIdentifier[VERINFO_SOCSOFTWARENUMBER_LEN];
}s_VerInfo_RelVars_t;

#pragma section farrom Grp_ROM_PFlash_SharedConst_ReleaseVariables
extern const s_VerInfo_RelVars_t s_ReleaseVariables;
#pragma section farrom restore


#pragma section farrom Grp_ROM_PFlash_SharedConst_SwPartNum
extern const uint8 a_vehicleManufacturerECUSoftwareNumberDataIdentifier[VERINFO_SOFTWARENUMBER_LEN];
#pragma section farrom restore


/*==================[external function declarations]========================*/
extern uint8 VerInfo_GetSoftwareVersion(uint8 mode, uint8 *version);
#if (VERINFO_MCU_SW_BANK_CHECK_ENABLE == STD_ON)
extern e_VerInfo_BankType_t VerInfo_GetSoftwareBank(void);
#endif/* VERINFO_MCU_SW_BANK_CHECK_ENABLE == STD_ON */



#endif /* _VERINFO_H_ */
