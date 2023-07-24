/**
 * \file VerInfo.c
 *
 * \brief
 *
 * \version refer the VerInfo.h.
 *
 */
/*==================[inclusions]============================================*/
#include "VerInfo.h"

/*==================[external data]=========================================*/


/*==================[internal data]=========================================*/
/*TODO : Mapping the rodata to pflash section,......start......*/
#pragma section farrom Grp_ROM_PFlash_SharedConst_SwVerInfo
/*TODO : shall be stored ROM,may be bootloader will usage*/
#if (VERINFO_MCU_SW_VERSION_MODE == VERINFO_MCU_SW_VERSION_MODE_ASCII)
const uint8 VerInfo_McuVersionNumber_Ascii[8] =
{
	((VERINFO_MCU_SW_MAJOR_VERSION)/10 + 0x30),
	((VERINFO_MCU_SW_MAJOR_VERSION)%10 + 0x30),
	0x2E,//'.'
	((VERINFO_MCU_SW_MINOR_VERSION)/10 + 0x30),
	((VERINFO_MCU_SW_MINOR_VERSION)%10 + 0x30),
	0x2E,//'.'
	((VERINFO_MCU_SW_PATCH_VERSION)/10 + 0x30),
	((VERINFO_MCU_SW_PATCH_VERSION)%10 + 0x30),
};
#elif ((VERINFO_MCU_SW_VERSION_MODE == VERINFO_MCU_SW_VERSION_MODE_HEX))
const uint8 VerInfo_McuVersionNumber_Hex[4] =
{
	0x00,//reserved
	VERINFO_MCU_SW_MAJOR_VERSION,
	VERINFO_MCU_SW_MINOR_VERSION,
	VERINFO_MCU_SW_PATCH_VERSION
};
#elif(VERINFO_MCU_SW_VERSION_MODE == VERINFO_MCU_SW_VERSION_MODE_CA_C385_ASCII)
const uint8 VerInfo_McuVersionNumber_C385_Ascii[8] =
{
	0x53,							//ASCII S '53'
	0x57,							//ASCII W '57'
	0x3A,							//ASCII : '3A'
	0x43,							//ASCII C '43'
	0x2E,							//'.'
	((VERINFO_MCU_SW_MAJOR_VERSION)%10 + 0x30),		//VERINFO_MCU_SW_MAJOR_VERSION
	0x2E,							//'.'
	((VERINFO_MCU_SW_MINOR_VERSION)%10 + 0x30),		//VERINFO_MCU_SW_MAJOR_VERSION
};
#else
const uint8 VerInfo_McuVersionNumber_Hex[4] =
{
	0x00,//reserved
	VERINFO_MCU_SW_MAJOR_VERSION,
	VERINFO_MCU_SW_MINOR_VERSION,
	VERINFO_MCU_SW_PATCH_VERSION
};
#endif
/*TODO : Mapping the rodata to pflash section,......end......*/
#pragma section farrom restore

#pragma section farrom Grp_ROM_PFlash_SharedConst_SwPartNum
const uint8 a_vehicleManufacturerECUSoftwareNumberDataIdentifier[VERINFO_SOFTWARENUMBER_LEN] =
{
'9','2','1','5','6','0','1','-','E','D','0','1',0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
}; /*F188: vehicle Manufacturer ECU Software Number Data Identifier */ 
#pragma section farrom restore


#pragma section farrom Grp_ROM_PFlash_SharedConst_ReleaseVariables
const s_VerInfo_RelVars_t s_ReleaseVariables =
{
    { "2023/05/15 02:32 PM" },
    { "uif30295" },
    { "SHKL085W" },
    { "MFC5J3"   },
    {0x00},
    /*The below paramter definition by customer.*/   
    {'V','2','.','2'}, /*F120: Network information */ 
    {'V','2','.','0'}, /*F121: Function Specification version */
    {'V','1','.','3'}, /*F122: Diagnostic Definition version */
    {'S','W',':','C','.',((VERINFO_MCU_SW_MAJOR_VERSION)%10 + 0x30),'.',((VERINFO_MCU_SW_MINOR_VERSION)%10 + 0x30)}, /*F189: vehicle Manufacturer ECU Software Version Number Data Identifier */ 
    {'H','W',':','C','.','1','.','0',0x00}, /*F191: vehicle Manufacturer ECU Hardware Number Data Identifier */
    {0xC6,0x73}, /*FD21: project ID */
    {VERINFO_MCU_SW_MAJOR_VERSION,'.',VERINFO_MCU_SW_MINOR_VERSION,'.',VERINFO_MCU_SW_PATCH_VERSION}, /*FD28: ECU Internal Software Version number */
    {'9','2','1','5','6','0','1','-','E','D','0','2',0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00} /*FD29: Soc Software number */
};
#pragma section farrom restore


/*==================[internal function declarations]========================*/


/*==================[external function definitions]=========================*/
/**
 * \functions VerInfo_GetSoftwareVersion
 *
 * \brief
 *
 * \parameters-in mode, 0x00 : VERINFO_MCU_SW_VERSION_MODE_ASCII,the version length is 8 byte
 * 						0x01 : VERINFO_MCU_SW_VERSION_MODE_HEX,the version length is 4 byte
 *
 * \parameters-out version,different mode,the version length is different.
 *
 * \return none
 *
 * \comments
 *
 */
uint8 VerInfo_GetSoftwareVersion(uint8 mode, uint8 *version)
{
	uint8 ret = 0x00;

	/*TODO : Check the version number range*/
	if((VERINFO_MCU_SW_MAJOR_VERSION > 99) || (VERINFO_MCU_SW_MINOR_VERSION > 99) || (VERINFO_MCU_SW_PATCH_VERSION > 99))
	{
		ret = 0x01;
	}
	else
	{
		/*TODO : pack the version number*/
		if(VERINFO_MCU_SW_VERSION_MODE_ASCII == mode)
		{
#if (VERINFO_MCU_SW_VERSION_MODE == VERINFO_MCU_SW_VERSION_MODE_ASCII)
			memcpy(version, VerInfo_McuVersionNumber_Ascii, 8);
#else

			version[0] = ((VERINFO_MCU_SW_MAJOR_VERSION)/10 + 0x30);
			version[1] = ((VERINFO_MCU_SW_MAJOR_VERSION)%10 + 0x30);
			version[2] = 0x2E;
			version[3] = ((VERINFO_MCU_SW_MINOR_VERSION)/10 + 0x30);
			version[4] = ((VERINFO_MCU_SW_MINOR_VERSION)%10 + 0x30);
			version[5] = 0x2E;//'.'
			version[6] = ((VERINFO_MCU_SW_PATCH_VERSION)/10 + 0x30);
			version[7] = ((VERINFO_MCU_SW_PATCH_VERSION)%10 + 0x30);
#endif
		}
		else if(VERINFO_MCU_SW_VERSION_MODE_HEX == mode)
		{
#if (VERINFO_MCU_SW_VERSION_MODE == VERINFO_MCU_SW_VERSION_MODE_HEX)
			memcpy(version, VerInfo_McuVersionNumber_Hex, 4);
#else
			version[0] = 0x00;//reserved
			version[1] = VERINFO_MCU_SW_MAJOR_VERSION;
			version[2] = VERINFO_MCU_SW_MINOR_VERSION;
			version[3] = VERINFO_MCU_SW_PATCH_VERSION;
#endif
		}
		else if(VERINFO_MCU_SW_VERSION_MODE_CA_C385_ASCII == mode)
		{
#if (VERINFO_MCU_SW_VERSION_MODE == VERINFO_MCU_SW_VERSION_MODE_CA_C385_ASCII)
			memcpy(version, VerInfo_McuVersionNumber_C385_Ascii, 8);
#else
			version[0] = 0x53;							//ASCII S '53'
			version[1] = 0x57;							//ASCII W '57'
			version[2] = 0x42;							//ASCII B '42'
			version[3] = 0x2E;							//'.'
			version[4] = ((VERINFO_MCU_SW_MAJOR_VERSION)%10 + 0x30);	//VERINFO_MCU_SW_MAJOR_VERSION
			version[5] = 0x2E;							//'.'
			version[6] = ((VERINFO_MCU_SW_MINOR_VERSION)%10 + 0x30);	//VERINFO_MCU_SW_MAJOR_VERSION
			version[7] = 0x00;
#endif
		}
		else
		{
			version[0] = 0x00;//reserved
			version[1] = VERINFO_MCU_SW_MAJOR_VERSION;
			version[2] = VERINFO_MCU_SW_MINOR_VERSION;
			version[3] = VERINFO_MCU_SW_PATCH_VERSION;
		}
	}

	return ret;
}

#if(VERINFO_MCU_SW_BANK_CHECK_ENABLE == STD_ON)
/**
 * \functions VerInfo_GetSoftwareVersion
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	bank type
 *
 * \comments
 *
 */
e_VerInfo_BankType_t VerInfo_GetSoftwareBank(void)
{
	e_VerInfo_BankType_t ret = VerInfo_BankType_Max;
	uint8 *address = NULL_PTR;

#if (VERINFO_MCU_SW_VERSION_MODE == VERINFO_MCU_SW_VERSION_MODE_ASCII)
	address = &VerInfo_McuVersionNumber_Ascii;
#elif(VERINFO_MCU_SW_VERSION_MODE == VERINFO_MCU_SW_VERSION_MODE_CA_C385_ASCII)
	address = &VerInfo_McuVersionNumber_C385_Ascii;
#else
	address = &VerInfo_McuVersionNumber_Hex;
#endif
	if(VERINFO_MCU_SW_BANK_A_ADDRESS == address)
	{
		ret = VerInfo_BankType_A;
	}
	else if(VERINFO_MCU_SW_BANK_B_ADDRESS == address)
	{
		ret = VerInfo_BankType_B;
	}
	else
	{
		ret = VerInfo_BankType_None;
	}

	return ret;
}
#endif

