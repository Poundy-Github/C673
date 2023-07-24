/**
 * \file
 *
 * \brief AUTOSAR EcuM
 *
 * This file contains the implementation of the AUTOSAR
 * module EcuM.
 *
 * \version 5.12.9
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/
#include "EcuM_UserCallout.h"
#include "Cdd_Pmc.h"
#include "Cdd_EvAdc.h"
#include "Cdd_SpiServ.h"
#include "Mcu.h"
#include "Print.h"


/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*------------------[Main callouts]-----------------------------------------*/
void UserEcuM_Init(void)
{   
    /*Init UART when if need debug*/
	Cdd_Print_Init();
	/*init Cdd_Pmc*/
    Cdd_Pmc_Init();
    /*init Cdd_Evadc and dma*/
    Cdd_EvAdc_InitFunction();
    /*Init Cdd_SPIServ DMA and SPITp layer*/
	Cdd_SpiServ_Init();
}




