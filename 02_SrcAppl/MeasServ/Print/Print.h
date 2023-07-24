/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Test_Print.h                                                  **
**                                                                            **
**  VERSION   : 0.0.1                                                         **
**                                                                            **
**  DATE      : 2016-08-22                                                    **
**                                                                            **
**  VARIANT   : NA                                                            **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  :  This file exports the functionality of Test_Print.c       **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: yes                                      **
**                                                                            **
*******************************************************************************/
#ifndef LLD_PRINT_H
#define LLD_PRINT_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <stdio.h>


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define ASCLIN_BITCON_SM (0U)

#define ASCLIN_BRG_NUMERATOR_SHIFT (16U)
#define ASCLIN_BRG_DENOMINATOR_SHIFT (0U)


#define ASCLIN_CSR_CLKSEL_NOCLK     (0U)
#define ASCLIN_CSR_CLKSEL_CLC       (1U)
#define ASCLIN_CSR_CLKSEL_EVROSC    (2U)
#define ASCLIN_CSR_CLKSEL_FMAX      (8U)
#define ASCLIN_CSR_CLKSEL_SHIFT     (0U)
#define ASCLIN_CSR_CLKSEL            (4) /* EVR Osc used as Clock source*/

#define ASCLIN_TXFIFOCON_FILL_SHIFT (16U)
#define ASCLIN_TXFIFOCON_FILL_MASK  (0x1FU)
#define ASCLIN_TXFIFOCON_ENO_SHIFT  (1U)
#define ASCLIN_TXFIFOCON_ENO_EN     (1U) /* tx fifo outlet enable */
#define ASCLIN_TXFIFOCON_INW_SHIFT  (6U)
#define ASCLIN_TXFIFOCON_INW_VAL    (1U) /* tx fifo outlet width */

#define ASCLIN_RXFIFOCON_FILL_SHIFT (16U)
#define ASCLIN_RXFIFOCON_FILL_MASK  (0x1FU)
#define ASCLIN_RXFIFOCON_ENO_SHIFT  (1U)
#define ASCLIN_RXFIFOCON_ENO_EN     (1U) /* rx fifo outlet enable */
#define ASCLIN_RXFIFOCON_INW_SHIFT  (6U)
#define ASCLIN_RXFIFOCON_INW_VAL    (1U) /* rx fifo outlet width */

#define ASCLIN_FLAGSCLEAR_MASK (0xFFFFFFFFU)

#define ASCLIN_FRAMECON_MODE_INIT (0U)
#define ASCLIN_FRAMECON_MODE_ASC  (1U)
#define ASCLIN_FRAMECON_MODE_SPI  (2U)
#define ASCLIN_FRAMECON_MODE_LIN  (3U)
#define ASCLIN_FRAMECON_MODE_SHIFT (16U)
#define ASCLIN_FRAMECON_STOP_SHIFT (9U)
#define ASCLIN_FRAMECON_STOP       (1U)



#define ASCLIN_DATCON_DATLEN_SHIFT (0U)
#define ASCLIN_DATCON_DATLEN_MASK  (0xFFFFFFF0U)

#define ASCLIN_BITCON_PRESCALAR_SHIFT (0U)
#define ASCLIN_BITCON_OVERSAMPLING_SHIFT (16U)
#define ASCLIN_BITCON_SAMPLEPOINT_SHIFT (24U)
#define ASCLIN_BITCON_SM_SHIFT (31U)



#define BEL        0x07
#define TAB        0x09
#define XON        0x11
#define XOFF       0x13
#define CNTLQ      0x11
#define CNTLS      0x13
#define DEL        0x7F
#define BACKSPACE  0x08
#define CR         0x0D
#define LF         0x0A
#define ESC        0x1B

#define beep()      putchar(0x07)
#define clreol()    printf("\033[K")
#define clrscr()    printf("\033[2J")
#define gotoxy(x,y) printf("\033[%d;%dH",y,x)
#define newline()   putchar(0x0A)
#define PAR_TYP_DEC 0
#define PAR_TYP_HEX 1

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
/*******************************************************************************
** Syntax : void Test_InitPrint(void)                                         **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):                                                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function Initializes the Printing on Serial             **
**               Communication Port.                                          **
*******************************************************************************/
extern void Cdd_Print_Init(void);

/*******************************************************************************
** Syntax : void print_f(const char *p_frm, ...)                              **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):                                                           **
**                                                                            **
** Parameters (out): void                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function Prints a formatted string to the               **
**               Communication Port.                                          **
*******************************************************************************/
extern void print_f(const char *p_frm, ...);

/*******************************************************************************
** Syntax : void getline(char *p_line, uint32 n_max)                          **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in): p_line and n_max                                          **
**                                                                            **
** Parameters (out): void                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function used to Read input from communication Port     **
*******************************************************************************/
extern void getline(char *p_line, uint32 n_max);

/*******************************************************************************
** Syntax : uint32 getlineWithPos(char *p_line, uint32 n_max, uint32 pos)     **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in): p_line , n_max , pos                                      **
**                                                                            **
** Parameters (out): uint32: new char arrived is TAB or CR                    **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function used to Read input from communication Port     **
*******************************************************************************/
extern int getlineWithPos(char *p_line, uint32 n_max, uint32 *pos);

/*******************************************************************************
** Syntax : int get_ch(void)                                                  **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value: int(ASCII value for the input character)                     **
**                                                                            **
** Description :This function reads a character from the Commucation port     **
**              and does not wait.                                            **
*******************************************************************************/
extern int get_ch(void);

/*******************************************************************************
** Syntax : void Continue(void)                                               **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):                                                           **
**                                                                            **
** Parameters (out): void                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function waits to get input from communication Port     **
*******************************************************************************/
extern  void Continue(void);

/*******************************************************************************
** Syntax : void print_FlushFifo()                                            **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):   none                                                    **
**                                                                            **
** Parameters (out): void                                                     **
**                                                                            **
** Return value: void                                                         **
**                                                                            **
** Description : This function flushes TX and RX FIFO of ASCLIN               **
*******************************************************************************/
extern void print_flushfifo(void);
#endif  /*  End of File print */
