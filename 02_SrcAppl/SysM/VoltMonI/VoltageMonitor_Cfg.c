/**
 * \file 
 *
 * \brief 
 *
 * \version refer the VoltageMonitor_Cfg.h.
 * 
 * \copyright  2021 - 2022 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include <Platform_Types.h> /* Autosar platform specific type declarations */
#include <Compiler.h>       /* Autosar compiler specific declarations */
#include <TSAutosar.h>      /* EB specific standard types */
#include "VoltageMonitor.h"
#include <Rte_VoltMonI.h>
/*==================[internal data definition]==============================*/


/*==================[external constants definition]=========================*/

/*==================[internal constants definition]=========================*/
#define VoltMonI_START_SEC_CONST
#include <VoltMonI_MemMap.h>

const s_VoltMonI_ConfigType_t s_VoltMonI_Config =
{
    {7.0f,   0.0f,        200, 0}, //PRQA S 3121,3120
    {28.0f,  0.0f,        200, 0},
    {7.5f,   7.8f,        500, 500},
    {8.5f,   9.0f,        500, 500},
    {18.5f, 18.0f,        500, 500},
    {16.5f, 16.0f,        500, 500},
    &VoltMonI_u_StartupPrecondition,
    &VoltMonI_u_Input,
    &VoltMonI_u_Output,
    &VoltMonI_u_EntryInitVolt_CallBack,
    &VoltMonI_u_EntryNormalVolt_CallBack,
    &VoltMonI_u_EntryLowVolt_CallBack,
    &VoltMonI_u_EntryUnderLowVolt_CallBack,
    &VoltMonI_u_EntryHighVolt_CallBack,
    &VoltMonI_u_EntryOverHighVolt_CallBack,
    &VoltMonI_u_EntryMinVolt_CallBack,
    &VoltMonI_u_EntryMaxVolt_CallBack
};

#define VoltMonI_STOP_SEC_CONST
#include <VoltMonI_MemMap.h>

/*==================[external data definition]==============================*/

/*==================[internal function declarations]========================*/














