
#ifndef ETH_17_GETHMAC_IRQ_H
#define ETH_17_GETHMAC_IRQ_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"                                                        

#ifdef OS_KERNEL_TYPE                                                           
#include <Os.h>        /* OS interrupt services */                              
#endif
#include <Os_user.h>

/*******************************************************************************
**                      Public Macro Definitions                              **
*******************************************************************************/

/************************* interrupt CATEGORY *********************************/

#ifdef IRQ_CAT1
#if (IRQ_CAT1 != 1)
#error IRQ_CAT1 already defined with a wrong value
#endif
#else
#define IRQ_CAT1                    (1)
#endif

#ifdef IRQ_CAT2
#if (IRQ_CAT2 != 2)
#error IRQ_CAT2 already defined with a wrong value
#endif
#else
#define IRQ_CAT2                    (2)
#endif



/* The name of the ISRs shall be the same name than the ISR       *
 * functions provided by Infineon                                 */

/**********************************************************/          

/******************ETHSR0 IRQ ********************************/

#ifdef ETHSR0_ISR
#define IRQ_ETHSR0_EXIST  STD_ON
#define IRQ_GETH_SR0_PRIO    ETHSR0_ISR_ISR_LEVEL
#define IRQ_GETH_SR0_CAT     ETHSR0_ISR_ISR_CATEGORY
#else
#define IRQ_ETHSR0_EXIST  STD_OFF
#endif

/******************ETHSR10 IRQ ********************************/

#ifdef ETHSR10_ISR
#define IRQ_ETHSR10_EXIST  STD_ON
#define IRQ_GETH1_SR0_PRIO    ETHSR10_ISR_ISR_LEVEL
#define IRQ_GETH1_SR0_CAT     ETHSR10_ISR_ISR_CATEGORY
#else
#define IRQ_ETHSR10_EXIST  STD_OFF
#endif

/******************ETHSR12 IRQ ********************************/

#ifdef ETHSR12_ISR
#define IRQ_ETHSR12_EXIST  STD_ON
#define IRQ_GETH1_SR2_PRIO    ETHSR12_ISR_ISR_LEVEL
#define IRQ_GETH1_SR2_CAT     ETHSR12_ISR_ISR_CATEGORY
#else
#define IRQ_ETHSR12_EXIST  STD_OFF
#endif

/******************ETHSR16 IRQ ********************************/

#ifdef ETHSR16_ISR
#define IRQ_ETHSR16_EXIST  STD_ON
#define IRQ_GETH1_SR6_PRIO    ETHSR16_ISR_ISR_LEVEL
#define IRQ_GETH1_SR6_CAT     ETHSR16_ISR_ISR_CATEGORY
#else
#define IRQ_ETHSR16_EXIST  STD_OFF
#endif

/******************ETHSR2 IRQ ********************************/

#ifdef ETHSR2_ISR
#define IRQ_ETHSR2_EXIST  STD_ON
#define IRQ_GETH_SR2_PRIO    ETHSR2_ISR_ISR_LEVEL
#define IRQ_GETH_SR2_CAT     ETHSR2_ISR_ISR_CATEGORY
#else
#define IRQ_ETHSR2_EXIST  STD_OFF
#endif

/******************ETHSR6 IRQ ********************************/

#ifdef ETHSR6_ISR
#define IRQ_ETHSR6_EXIST  STD_ON
#define IRQ_GETH_SR6_PRIO    ETHSR6_ISR_ISR_LEVEL
#define IRQ_GETH_SR6_CAT     ETHSR6_ISR_ISR_CATEGORY
#else
#define IRQ_ETHSR6_EXIST  STD_OFF
#endif
#endif /* #ifndef ETH_17_GETHMAC_IRQ_H */
