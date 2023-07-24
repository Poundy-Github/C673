/**
 * \file Ifx_Ssw_Infra.h
 * \brief Startup Software support functions.
 *
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2018-11-20 15:22:49
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

#ifndef IFX_SSW_INFRA_H_
#define IFX_SSW_INFRA_H_

#include "Ifx_Ssw_Compilers.h"
#include "Ifx_Cfg_Ssw.h"
#include "IfxScu_reg.h"
#include "IfxCpu_reg.h"
#include "IfxScu_bf.h"
#include "IfxCpu_bf.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief PowerOn Reset Mask
 */
#define IFX_SSW_POWERONRESET_MASK                               \
    (((unsigned int)IFX_SCU_RSTSTAT_STBYR_MSK << IFX_SCU_RSTSTAT_STBYR_OFF) | \
     ((unsigned int)IFX_SCU_RSTSTAT_SWD_MSK << IFX_SCU_RSTSTAT_SWD_OFF) |     \
     ((unsigned int)IFX_SCU_RSTSTAT_EVR33_MSK << IFX_SCU_RSTSTAT_EVR33_OFF) | \
     ((unsigned int)IFX_SCU_RSTSTAT_EVRC_MSK << IFX_SCU_RSTSTAT_EVRC_OFF) |   \
     ((unsigned int)IFX_SCU_RSTSTAT_CB1_MSK << IFX_SCU_RSTSTAT_CB1_OFF) |     \
     ((unsigned int)IFX_SCU_RSTSTAT_CB0_MSK << IFX_SCU_RSTSTAT_CB0_OFF) |     \
     ((unsigned int)IFX_SCU_RSTSTAT_PORST_MSK << IFX_SCU_RSTSTAT_PORST_OFF))

/** \brief Application Reset Mask
 */
#define IFX_SSW_APPLICATIONRESET_MASK                         \
    (((unsigned int)IFX_SCU_RSTSTAT_SW_MSK << IFX_SCU_RSTSTAT_SW_OFF) |     \
     ((unsigned int)IFX_SCU_RSTSTAT_STM0_MSK << IFX_SCU_RSTSTAT_STM0_OFF) | \
     ((unsigned int)IFX_SCU_RSTSTAT_SMU_MSK << IFX_SCU_RSTSTAT_SMU_OFF) |   \
     ((unsigned int)IFX_SCU_RSTSTAT_ESR1_MSK << IFX_SCU_RSTSTAT_ESR1_OFF) | \
     ((unsigned int)IFX_SCU_RSTSTAT_ESR0_MSK << IFX_SCU_RSTSTAT_ESR0_OFF))

/** \brief Cold PowerOn Reset Mask
 */
#define IFX_SSW_COLD_POWERONRESET_MASK                         \
    (((unsigned int)IFX_SCU_RSTSTAT_STBYR_MSK << IFX_SCU_RSTSTAT_STBYR_OFF) | \
     ((unsigned int)IFX_SCU_RSTSTAT_SWD_MSK << IFX_SCU_RSTSTAT_SWD_OFF)     | \
     ((unsigned int)IFX_SCU_RSTSTAT_EVR33_MSK << IFX_SCU_RSTSTAT_EVR33_OFF) | \
     ((unsigned int)IFX_SCU_RSTSTAT_EVRC_MSK << IFX_SCU_RSTSTAT_EVRC_OFF))

/** \brief Application reset enabled
 * In SCU_RSTCON register, value 2 represents the Application reset
 */
#define IFX_SSW_APPLICATIONRESET              (2U)

/** \brief Reload value mask */
#define IFX_SSW_SEICON_REL_VAL_MSK           (unsigned short)(0xFFFCU << IFX_SCU_SEICON0_REL_OFF)

/** \brief Mask values is used to invert the password value bits */
#define IFX_SSW_WDT_PASSWORD_INVERT_MSK      (0x003FU)

/** \brief CSA size */
#define IFX_SSW_CSA_SIZE                      16U

#ifndef IFX_CFG_SSW_STARTCPU_WAIT_TIME_IN_SECONDS
#define IFX_CFG_SSW_STARTCPU_WAIT_TIME_IN_SECONDS (0.0001)
#endif

#ifndef IFX_CFG_SSW_EVR_OSC_FREQUENCY
#define IFX_CFG_SSW_EVR_OSC_FREQUENCY         (100000000.0)
#endif

#ifndef IFX_CFG_SSW_SYSCLK_PIN_FREQUENCY
#define IFX_CFG_SSW_SYSCLK_PIN_FREQUENCY      (20000000.0)
#endif

#ifndef IFX_CFG_SSW_XTAL_FREQUENCY
#define IFX_CFG_SSW_XTAL_FREQUENCY            (IFX_CFG_SCU_XTAL_FREQUENCY)
#endif

/******************************************************************************/
/*-------------------------Infrastructure Functions---------------------------*/
/******************************************************************************/
/** \brief clear safety endinit.\n
 * Note: IFX_CFG_SSW_CLEAR_SAFETY_ENDINIT() function macro is added to avoid issues higher optimization is enabled.
 */
#define IFX_CFG_SSW_CLEAR_SAFETY_ENDINIT()                                                                    \
    {                                                                                                       \
        /* see Table 1 (Password Access Bit Pattern Requirements) */                                        \
        SCU_WDTS_CON0.U = ((unsigned int)1 << IFX_SCU_WDTS_CON0_ENDINIT_OFF) |                              \
                          ((unsigned int)0 << IFX_SCU_WDTS_CON0_LCK_OFF) |                                  \
                          ((unsigned int)(MODULE_SCU.WDTS.CON0.B.PW ^ 0x003F) << IFX_SCU_WDTS_CON0_PW_OFF) |\
                          ((unsigned int)SCU_WDTS_CON0.B.REL << IFX_SCU_WDTS_CON0_REL_OFF);                 \
        /* Clear ENDINT and set LCK bit in Config_0 register */                                             \
        SCU_WDTS_CON0.U = ((unsigned int)0 << IFX_SCU_WDTS_CON0_ENDINIT_OFF) |                              \
                          ((unsigned int)1 << IFX_SCU_WDTS_CON0_LCK_OFF) |                                  \
                          ((unsigned int)(MODULE_SCU.WDTS.CON0.B.PW ^ 0x003F) << IFX_SCU_WDTS_CON0_PW_OFF) |\
                          ((unsigned int)SCU_WDTS_CON0.B.REL << IFX_SCU_WDTS_CON0_REL_OFF);                 \
        /* Read back of the register is mandatory to ensure the register update  */                         \
        SCU_WDTS_CON0.U;                                                                                    \
    }

/** \brief set safety endinit.\n
 * Note: IFX_CFG_SSW_SET_SAFETY_ENDINIT() function macro is added to avoid issues higher optimization is enabled.
 */
#define IFX_CFG_SSW_SET_SAFETY_ENDINIT()                                                                  \
    {                                                                                                       \
        /* see Table 1 (Password Access Bit Pattern Requirements) */                                        \
        SCU_WDTS_CON0.U = ((unsigned int)1 << IFX_SCU_WDTS_CON0_ENDINIT_OFF) |                              \
                          ((unsigned int)0 << IFX_SCU_WDTS_CON0_LCK_OFF) |                                  \
                          ((unsigned int)(MODULE_SCU.WDTS.CON0.B.PW ^ 0x003F) << IFX_SCU_WDTS_CON0_PW_OFF) |\
                          ((unsigned int)SCU_WDTS_CON0.B.REL << IFX_SCU_WDTS_CON0_REL_OFF);                 \
        /* Set ENDINT and set LCK bit in Config_0 register */                                               \
        SCU_WDTS_CON0.U = ((unsigned int)1 << IFX_SCU_WDTS_CON0_ENDINIT_OFF) |                              \
                          ((unsigned int)1 << IFX_SCU_WDTS_CON0_LCK_OFF) |                                  \
                          ((unsigned int)(MODULE_SCU.WDTS.CON0.B.PW ^ 0x003F) << IFX_SCU_WDTS_CON0_PW_OFF) |\
                          ((unsigned int)SCU_WDTS_CON0.B.REL << IFX_SCU_WDTS_CON0_REL_OFF);                 \
        /* Read back of the register is mandatory to ensure the register update  */                             \
        SCU_WDTS_CON0.U;                                                                                        \
    }

/** \brief Fetch current password of CPU Watchdog module.
 *
 * This API will fetch current Watchdog password for CPU WDT Hardware module.
 * password is needed to be passed with most of the WDT APIs. 
 * \param watchdog pointer to the watchdog register map of CPU WDT hardware instance
 * \return password Existing (Application specific) password for the Watchdog module.
 */
extern unsigned short Ifx_Ssw_getCpuWatchdogPassword(Ifx_SCU_WDTCPU *watchdog);

/** \brief Fetch current password of Safety Watchdog module.
 *
 * This API will fetch current Watchdog password for Safety WDT Hardware module.
 * password is needed to be passed with most of the WDT APIs. 
 * \return password Existing (Application specific) password for the Watchdog module.
 */
extern unsigned short Ifx_Ssw_getSafetyWatchdogPassword(void);

/** \brief Clear ENDINIT bit provided by CPU WDT Hardware module.
 *
 * This API will disable ENDINIT functionality provided by CPU WDT Hardware module.
 * User need to use this API call before modifying any ENDINIT protected register. User must
 * always set the ENDINIT bit using other API Ifx_Ssw_setCpuEndinit. The sequence clear and set
 * ENDINIT shall not be interrupted by another interrupt/call.
 * \param watchdog pointer to the watchdog register map of CPU WDT hardware instance
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
extern void           Ifx_Ssw_clearCpuEndinit(Ifx_SCU_WDTCPU *watchdog, unsigned short password);

/** \brief Set ENDINIT bit provided by CPU WDT Hardware module.
 *
 * This API will enable ENDINIT functionality provided by CPU WDT Hardware module.
 * User need to use this API call after modifying any ENDINIT protected register.
 * \param watchdog pointer to the watchdog register map of CPU WDT hardware instance
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
extern void           Ifx_Ssw_setCpuEndinit(Ifx_SCU_WDTCPU *watchdog, unsigned short password);

/** \brief Clear ENDINIT bit provided by Safety WDT Hardware module.
 *
 * This API will disable ENDINIT functionality provided by Safety WDT Hardware module.
 * User need to use this API call before modifying any ENDINIT protected register. User must
 * always set the ENDINIT bit using other API Ifx_Ssw_setCpuEndinit. The sequence clear and set
 * ENDINIT shall not be interrupted by another interrupt/call.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
extern void           Ifx_Ssw_clearSafetyEndinit(unsigned short password);

/** \brief Set ENDINIT bit provided by Safety WDT Hardware module.
 *
 * This API will enable ENDINIT functionality provided by Safety WDT Hardware module.
 * User need to use this API call after modifying any ENDINIT protected register.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
extern void           Ifx_Ssw_setSafetyEndinit(unsigned short password);

/** \brief Disable CPU Watchdog functionality.
 *
 * This API will disable Watchdog functionality of CPU WDT Hardware module. The Watchdog timers will stop counting
 * after this API call.
 * \param watchdog pointer to the watchdog register map of CPU WDT hardware instance
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
extern void           Ifx_Ssw_disableCpuWatchdog(Ifx_SCU_WDTCPU *watchdog, unsigned short password);

/** \brief SCUWDT API to enable CPU Watchdog functionality.
 *
 *   This API will enable Watchdog functionality of CPU WDT Hardware module. The Watchdog timers need to be serviced
 *   periodically after this API call.
 * \param watchdog pointer to the watchdog register map of CPU WDT hardware instance
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
extern void           Ifx_Ssw_enableCpuWatchdog(Ifx_SCU_WDTCPU *watchdog, unsigned short password);

/** \brief Disable Safety Watchdog functionality.
 *
 * This API will disable Watchdog functionality of Safety WDT Hardware module. The Watchdog timers will stop counting
 * after this API call.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
extern void           Ifx_Ssw_disableSafetyWatchdog(unsigned short password);

/** \brief Enable Safety Watchdog functionality.
 *
 * This API will enable Watchdog functionality of Safety WDT Hardware module. The Watchdog timers need to be serviced
 * periodically after this API call.
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
extern void           Ifx_Ssw_enableSafetyWatchdog(unsigned short password);

/** \brief Set the program counter for the CPU specified and start the CPU
 * \param cpu Pointer to the CPU HW module (register memory map)
 * \param programCounter Program counter value to start the CPU
 */
extern void           Ifx_Ssw_startCore(Ifx_CPU *cpu, unsigned int programCounter);

/** \brief Set CPU0 to idle state */
extern void           Ifx_Ssw_setCpu0Idle(void);

/** \brief Initialise the C runtime environment */
extern void           Ifx_Ssw_C_Init(void);

/** \brief Returns the system timer frequency.
 * \return the system timer frequency in Hz.
 */
extern float          Ifx_Ssw_getStmFrequency(void);

/** \brief SCUWDT API to service CPU Watchdog functionality.
 *
 *   This API will service Watchdog functionality corresponding to CPU WDT Hardware module.
 *   User need to use this API call periodically. This API results in reloading of the Watchdog Timer.
 *   User need to have the password stored locally in the caller function, (use Ifx_Ssw_getCpuWatchdogPassword).
 * \param password Existing (Application specific) password for the Watchdog module.
 * \param watchdog pointer to the watchdog register map of CPU WDT hardware instance.
 * \return None
 */
extern void Ifx_Ssw_serviceCpuWatchdog(Ifx_SCU_WDTCPU *watchdog, unsigned short password);

/** \brief SCUWDT API to service Safety Watchdog functionality.
 *
 * This API will service Watchdog functionality corresponding to Safety WDT Hardware module.
 * User need to use this API call periodically. This API results in reloading of the Watchdog Timer.
 * User need to have the password stored locally in the caller function, (use Ifx_Ssw_getSafetyWatchdogPassword).
 * \param password Existing (Application specific) password for the Watchdog module.
 * \return None
 */
extern void Ifx_Ssw_serviceSafetyWatchdog(unsigned short password);

/*Endinit Functions*/
IFX_SSW_INLINE unsigned short Ifx_Ssw_getGlobalSafetyEndinitPasswordInline(void)
{
    /* Read Password from CON0 register
     * !!! NOTE: !!! when read bottom six bit of password are inverted so we have
     * to toggle them before returning password */

    unsigned short password = (unsigned short)MODULE_SCU.SEICON0.B.EPW ^ IFX_SSW_WDT_PASSWORD_INVERT_MSK;
    return password;
}


IFX_SSW_INLINE void Ifx_Ssw_clearGlobalSafetyEndinitInline(unsigned short password)
{
    /* Clear EndInit Watch-dog*/
    MODULE_SCU.SEICON0.U = IFX_SSW_SEICON_REL_VAL_MSK | ((unsigned int)password << IFX_SCU_SEICON0_EPW_OFF);

    /* Read back of the register is mandatory to ensure the register update */
    MODULE_SCU.SEICON0.U;
}


IFX_SSW_INLINE void Ifx_Ssw_setGlobalSafetyEndinitInline(unsigned short password)
{
    /* Set EndInit Watch-dog*/
    MODULE_SCU.SEICON0.U = IFX_SSW_SEICON_REL_VAL_MSK | \
                           ((unsigned int)password << IFX_SCU_SEICON0_EPW_OFF) | \
                           ((unsigned int)1 << IFX_SCU_SEICON0_ENDINIT_OFF);

    /* Read back of the register is mandatory to ensure the register update  */
    MODULE_SCU.SEICON0.U;
}


IFX_SSW_INLINE unsigned short Ifx_Ssw_getCpuWatchdogPasswordInline(Ifx_SCU_WDTCPU *watchdog)
{
    unsigned short password;

    /* Read Password from CON0 register
     * !!! NOTE: !!! when read bottom six bit of password are inverted so we have
     * to toggle them before returning password */
    password  = watchdog->CON0.B.PW;
    password ^= IFX_SSW_WDT_PASSWORD_INVERT_MSK;

    return password;
}


IFX_SSW_INLINE unsigned short Ifx_Ssw_getSafetyWatchdogPasswordInline(void)
{
    unsigned short password;
    Ifx_SCU_WDTS  *watchdog;
    watchdog = &MODULE_SCU.WDTS;
    /* Read Password from Safety WDT CON0 register
     * !!! NOTE: !!! when read bottom six bit of password are inverted so we have
     * to toggle them before returning password */
    password  = watchdog->CON0.B.PW;
    password ^= IFX_SSW_WDT_PASSWORD_INVERT_MSK;

    return password;
}


IFX_SSW_INLINE void Ifx_Ssw_clearCpuEndinitInline(Ifx_SCU_WDTCPU *watchdog, unsigned short password)
{
    if (watchdog->CON0.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        watchdog->CON0.U = ((unsigned int)1 << IFX_SCU_WDTCPU_CON0_ENDINIT_OFF) |
                           ((unsigned int)0 << IFX_SCU_WDTCPU_CON0_LCK_OFF) |
                           ((unsigned int)password << IFX_SCU_WDTCPU_CON0_PW_OFF) |
                           ((unsigned int)watchdog->CON0.B.REL << IFX_SCU_WDTCPU_CON0_REL_OFF);
    }

    /* Clear ENDINT and set LCK bit in Config_0 register */
    watchdog->CON0.U = ((unsigned int)0 << IFX_SCU_WDTCPU_CON0_ENDINIT_OFF) |
                       ((unsigned int)1 << IFX_SCU_WDTCPU_CON0_LCK_OFF) |
                       ((unsigned int)password << IFX_SCU_WDTCPU_CON0_PW_OFF) |
                       ((unsigned int)watchdog->CON0.B.REL << IFX_SCU_WDTCPU_CON0_REL_OFF);

    /* Read back of the register is mandatory to ensure the register update  */
    watchdog->CON0.U;
}


IFX_SSW_INLINE void Ifx_Ssw_clearSafetyEndinitInline(unsigned short password)
{
    if (SCU_WDTS_CON0.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        SCU_WDTS_CON0.U = ((unsigned int)1 << IFX_SCU_WDTS_CON0_ENDINIT_OFF) |
                          ((unsigned int)0 << IFX_SCU_WDTS_CON0_LCK_OFF) |
                          ((unsigned int)password << IFX_SCU_WDTS_CON0_PW_OFF) |
                          ((unsigned int)SCU_WDTS_CON0.B.REL << IFX_SCU_WDTS_CON0_REL_OFF);
    }

    /* Clear ENDINT and set LCK bit in Config_0 register */
    SCU_WDTS_CON0.U = ((unsigned int)0 << IFX_SCU_WDTS_CON0_ENDINIT_OFF) |
                      ((unsigned int)1 << IFX_SCU_WDTS_CON0_LCK_OFF) |
                      ((unsigned int)password << IFX_SCU_WDTS_CON0_PW_OFF) |
                      ((unsigned int)SCU_WDTS_CON0.B.REL << IFX_SCU_WDTS_CON0_REL_OFF);

    /* Read back of the register is mandatory to ensure the register update  */
    SCU_WDTS_CON0.U;
}


IFX_SSW_INLINE void Ifx_Ssw_setCpuEndinitInline(Ifx_SCU_WDTCPU *watchdog, unsigned short password)
{
    if (watchdog->CON0.B.LCK)
    {
        /* see Table 1 (Pass.word Access Bit Pattern Requirements) */
        watchdog->CON0.U = ((unsigned int)1 << IFX_SCU_WDTCPU_CON0_ENDINIT_OFF) |
                           ((unsigned int)0 << IFX_SCU_WDTCPU_CON0_LCK_OFF) |
                           ((unsigned int)password << IFX_SCU_WDTCPU_CON0_PW_OFF) |
                           ((unsigned int)watchdog->CON0.B.REL << IFX_SCU_WDTCPU_CON0_REL_OFF);
    }

    /* Set ENDINT and set LCK bit in Config_0 register */
    watchdog->CON0.U = ((unsigned int)1 << IFX_SCU_WDTCPU_CON0_ENDINIT_OFF) |
                       ((unsigned int)1 << IFX_SCU_WDTCPU_CON0_LCK_OFF) |
                       ((unsigned int)password << IFX_SCU_WDTCPU_CON0_PW_OFF) |
                       ((unsigned int)watchdog->CON0.B.REL << IFX_SCU_WDTCPU_CON0_REL_OFF);

    /* Read back of the register is mandatory to ensure the register update  */
    watchdog->CON0.U;
}


IFX_SSW_INLINE void Ifx_Ssw_setSafetyEndinitInline(unsigned short password)
{
    if (SCU_WDTS_CON0.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        SCU_WDTS_CON0.U = ((unsigned int)1 << IFX_SCU_WDTS_CON0_ENDINIT_OFF) |
                          ((unsigned int)0 << IFX_SCU_WDTS_CON0_LCK_OFF) |
                          ((unsigned int)password << IFX_SCU_WDTS_CON0_PW_OFF) |
                          ((unsigned int)SCU_WDTS_CON0.B.REL << IFX_SCU_WDTS_CON0_REL_OFF);
    }

    /* Set ENDINT and set LCK bit in Config_0 register */
    SCU_WDTS_CON0.U = ((unsigned int)1 << IFX_SCU_WDTS_CON0_ENDINIT_OFF) |
                      ((unsigned int)1 << IFX_SCU_WDTS_CON0_LCK_OFF) |
                      ((unsigned int)password << IFX_SCU_WDTS_CON0_PW_OFF) |
                      ((unsigned int)SCU_WDTS_CON0.B.REL << IFX_SCU_WDTS_CON0_REL_OFF);

    /* Read back of the register is mandatory to ensure the register update  */
    SCU_WDTS_CON0.U;
}

/* Check if Cold PowerOn Reset */

IFX_SSW_INLINE char Ifx_Ssw_isColdPoweronReset(void)
{
    return (char)((SCU_RSTSTAT.U & IFX_SSW_COLD_POWERONRESET_MASK) > 0);
}

/*Add options to eliminate usage of stack pointers unnecessarily*/
#if defined(__HIGHTEC__)
#pragma GCC optimize "O2"
#endif

IFX_SSW_INLINE unsigned char Ifx_Ssw_isApplicationReset(void)
{
    unsigned char returnVal;
    unsigned int  tempValue = SCU_RSTSTAT.U;

    if ((tempValue & IFX_SSW_POWERONRESET_MASK) > 0U)
    {
        returnVal = 0U;
    }
    else if ((tempValue & IFX_SSW_APPLICATIONRESET_MASK) > 0U)
    {
        /* get the bit which is set at RSTSTAT (assumption: RSTSTAT register was cleared before and only one bit can be set) */
        tempValue = tempValue & IFX_SSW_APPLICATIONRESET_MASK;
        tempValue = (SCU_RSTCON.U >> ((31U - Ifx_Ssw_CLZ(tempValue)) << 1U)) & 3U;

        if (tempValue == IFX_SSW_APPLICATIONRESET)
        {
            returnVal = 1U;
        }
        else
        {
            returnVal = 0U;
        }
    }
    else if (((unsigned int)tempValue & ((unsigned int)IFX_SCU_RSTSTAT_CB3_MSK << IFX_SCU_RSTSTAT_CB3_OFF)))
    {
        /* CB3 reset is not configurable and is always application reset */
        returnVal = 1U;
    }
    else if (CPU0_KRST0.B.RSTSTAT != 0)   /*CPU0 KRST status */
    {
        returnVal = 1U;
    }
    else
    {
        returnVal = 0U;
    }

    return returnVal;
}


/*Restore the options to command line provided ones*/
#if defined(__HIGHTEC__)
#pragma GCC reset_options
#endif

IFX_SSW_INLINE void Ifx_Ssw_initCSA(unsigned int *csaBegin, unsigned int *csaEnd)
{
    unsigned int  k;
    unsigned int  nxt_cxi_val = 0U;
    unsigned int *prvCsa      = 0U;
    unsigned int *nxtCsa      = csaBegin;
    unsigned int numOfCsa     = (((unsigned int)csaEnd - (unsigned int)csaBegin) / 64U);

    for (k = 0U; k < numOfCsa; k++)
    {
        nxt_cxi_val = ((unsigned int)((unsigned int)nxtCsa & ((unsigned int)0XFU << 28U)) >> 12U) | \
                      ((unsigned int)((unsigned int)nxtCsa & ((unsigned int)0XFFFFU << 6U)) >> 6U);

        if (k == 0U)
        {
            Ifx_Ssw_MTCR(CPU_FCX, nxt_cxi_val);   /* store the new pcxi value to LCX */
        }
        else
        {
            *prvCsa = nxt_cxi_val;
        }

        if (k == (numOfCsa - 3U))
        {
            Ifx_Ssw_MTCR(CPU_LCX, nxt_cxi_val);   /* Last but 2 context save area is pointed in LCX to know if there is CSA depletion */
        }

        prvCsa  = (unsigned int *)nxtCsa;
        nxtCsa += IFX_SSW_CSA_SIZE; /* next CSA */
    }

    *prvCsa = 0U;                       /* Store null pointer in last CSA (= very first time!) */

    Ifx_Ssw_DSYNC();
}


#endif /* IFXCPU_SSW_INFRA_H_ */
