/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Print_Cfg.h"
//#include <Uart.h>
/******************************************************************************
**                      Imported Compiler Switch Checks                      **
******************************************************************************/

/******************************************************************************
**                      Private Macro Definitions                            **
******************************************************************************/


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/****************************************************************************8**
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
static volatile Ifx_ASCLIN *psASCLIN;

static char ubOutputBuf[120];

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Local Function Declarations                           **
*******************************************************************************/
static void put_char(char);
static  int get_char(void);
static void buf_to_screen(char *text_buf);
static void ClearBuffer(uint32* buf, uint32 size);


LOCAL_INLINE void delay(void)
{
  volatile int i;
  for (i = 0; i < 100; i++) {};
}

/*******************************************************************************
** Syntax : void Print_Init(void)                                         **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function Initializes the Printing on Serial             **
**               Communication Port. Baud rate : 115,200 Hz                   **
*******************************************************************************/
void Cdd_Print_Init(void)
{

#if ((defined PRINT_ENABLE) && (PRINT_ENABLE == STD_ON))

  psASCLIN = &ASCLIN_BASE;

  volatile int i;
  uint8 ui8_ModClkStatus;
  #if 0
  uint32 RegUpdate;
  #endif
  /* Update clock register with end init protection */
  Mcal_WriteCpuEndInitProtReg((uint32*)&psASCLIN->CLC.U, (uint32)0x00000000);

  /* Read back clock register */
  ui8_ModClkStatus = (uint8)(((psASCLIN->CLC.U) & 0x00000002U) >> 1U);
	
  while(ui8_ModClkStatus) {};
  #if 0
  for (i = 0; i < 1000; i++)
  {;}
  RegUpdate = psASCLIN->KRST0.U | 1U;
  /* Update kernel register with end init protection */
  Mcal_WritePeripEndInitProtReg(&psASCLIN->KRST0.U, RegUpdate);

  for (i = 0; i < 1000; i++)
  {;}
  RegUpdate = psASCLIN->KRST1.U | 1U;
  /* Update kernel register with end init protection */
  Mcal_WritePeripEndInitProtReg(&psASCLIN->KRST1.U, RegUpdate);

  for (i = 0; i < 1000; i++)
  {;}
  RegUpdate = psASCLIN->KRSTCLR.U | 1U;
  /* Clear kernel reset register status with end init protection */
  Mcal_WritePeripEndInitProtReg(&psASCLIN->KRSTCLR.U, RegUpdate); 
  #endif
  
  psASCLIN->CSR.B.CLKSEL = ASCLIN_CSR_CLKSEL_NOCLK ;
  for (i = 0; i < 1000; i++)
  {;}
  /* select the operation mode (INIT)*/
  psASCLIN->FRAMECON.B.MODE  =  ASCLIN_FRAMECON_MODE_INIT  ;
  for (i = 0; i < 1000; i++)
  {;}
  /* activate the clock source */
  psASCLIN->CSR.B.CLKSEL       =  ASCLIN_CSR_CLKSEL ;

  /* provide delay of 2-fA clock cycles */
  for (i = 0; i < 1000; i++)
  {;}

  /* deactivate the clock source */
  psASCLIN->CSR.B.CLKSEL       = ASCLIN_CSR_CLKSEL_NOCLK ;
  for (i = 0; i < 1000; i++)
  {;}
  psASCLIN->FRAMECON.B.MODE =  ASCLIN_FRAMECON_MODE_ASC ;
  for (i = 0; i < 1000; i++)
  {;}
  /* activate the clock source */
  psASCLIN->CSR.B.CLKSEL       =  ASCLIN_CSR_CLKSEL ;

  /* provide delay of 2-fA clock cycles */
  for (i = 0; i < 100; i++)
  {;}

  /* deactivate the clock source */
  psASCLIN->CSR.B.CLKSEL =  ASCLIN_CSR_CLKSEL_NOCLK ;
  /* select 1 stop bit */
  psASCLIN->FRAMECON.B.MSB = 0U;
  psASCLIN->FRAMECON.B.LEAD = 0U;
  psASCLIN->FRAMECON.B.IDLE = 0;
  psASCLIN->FRAMECON.B.PEN  = 0U;

  psASCLIN->FRAMECON.U |= (1U << 9);

  psASCLIN->DATCON.B.DATLEN = ASCLIN_DATCON_DATLEN;

  /* rx fifo inlet enable, rx fifo outlet width */
  psASCLIN->RXFIFOCON.B.OUTW = ASCLIN_RXFIFOCON_INW_VAL ; /*1*/
  psASCLIN->RXFIFOCON.B.ENI = ASCLIN_RXFIFOCON_ENO_EN ; /*1*/
  psASCLIN->RXFIFOCON.B.FLUSH = 1 ;
  psASCLIN->RXFIFOCON.B.INTLEVEL = 0;
  psASCLIN->RXFIFOCON.B.BUF    = 0U;

  /* tx fifo inlet enable, tx fifo outlet width */
  psASCLIN->TXFIFOCON.B.INW = ASCLIN_TXFIFOCON_INW_VAL ;
  psASCLIN->TXFIFOCON.B.ENO = ASCLIN_TXFIFOCON_ENO_EN ;
  psASCLIN->TXFIFOCON.B.FLUSH = 1 ;
  psASCLIN->TXFIFOCON.B.INTLEVEL = 0;
  
  /* Configure baudrate parameters  115200 Hz*/
  psASCLIN->BRG.B.NUMERATOR = 72U;
  psASCLIN->BRG.B.DENOMINATOR = 1000U;
  psASCLIN->BITCON.B.PRESCALER = 4U;
  psASCLIN->BITCON.B.OVERSAMPLING = 9U;
  /* Configure Sample mode(3 Bit), Sample point, Parity, Collision detection */
  psASCLIN->BITCON.B.SM = 1U;
  psASCLIN->BITCON.B.SAMPLEPOINT = (((9U) >> 1U) + 1U);

  /* Select line A is used as Rx Input line*/
  psASCLIN->IOCR.B.ALTI =  6U;

  /*  - P02.2 is used as ASCLIN1 receive input signal (ASCLIN1_RX)
     - the input pull-up device is assigned */

  /*  - P02.3 is used as ASCLIN0 transmit output signal (ASCLIN1_TX)
     - the push/pull function is activated (ALT2)
    - output driver characteristic: GRADE1 */

  /* activate the clock source */
  psASCLIN->CSR.B.CLKSEL =  ASCLIN_CSR_CLKSEL;
  for (i = 0; i < 100; i++)
  {;}

  /* clear the interrupt event flags*/
  psASCLIN->FLAGSCLEAR.U =  ASCLIN_FLAGSCLEAR_MASK;

  print_f("\nPrint_Init complete...\n");
#endif

}

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
int getlineWithPos(char *p_line, uint32 n_max, uint32 *pos)
{
  uint32 w_cnt;
  uint32 ret_val;
  int w_key;

  w_cnt = *pos;
  p_line += *pos;
  ret_val = 0;


  do
  {
    w_key = get_ch();
    if (w_key == -1)
    {
      ret_val = 0;
    }
    else
    {
      if ((w_key == CR) || (w_key == LF))
      {
        *p_line = 0;
        ret_val = CR;
      }
      else
      {

        if (w_key == TAB)
        {
          *p_line = 0; /* set the value to 0 so that the first part of the string can be analyzed */
          ret_val = TAB;
        }
        else
        {
          if ((w_key == BACKSPACE) || (w_key == DEL))
          {
            /* backspace or delete */

            if (w_cnt != 0)

            {
              /* delete character */
              w_cnt--;
              p_line--;
              put_char(BACKSPACE);
              put_char(' ');
              put_char(BACKSPACE);
            }
          }
          else
          {
            if ((w_key != CNTLQ) && (w_key != CNTLS))
            {
              /* normal character*/
              {
                /* store/reflect character */
                *p_line = (char)w_key;
                put_char ((char)w_key);
                p_line++;
                w_cnt++;
                if (w_cnt == n_max)
                {
                  /* limit reached */
                  (void)beep();
                  /* delete all characters */
                  while (w_cnt != 0)
                  {
                    w_cnt--;
                    p_line--;
                    put_char(BACKSPACE);
                    put_char(' ');
                    put_char(BACKSPACE);

                  }
                }
              }
            }
          }
        }
      }
    }
  }
  while ((w_key != CR) && (w_key != LF) && (w_key != BACKSPACE) && \
         (w_key != DEL) && (w_key != TAB));
  *pos = w_cnt;
  return(ret_val);
}
/*******************************************************************************
** Syntax : int get_char(void)                                                **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):                                                           **
**                                                                            **
** Parameters (out): int                                                      **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function used to put the character to terminal          **
**               and waits till a char is entered.                            **
*******************************************************************************/
volatile uint32 rxdata1;
static int get_char(void)
/*~-*/
{
  volatile uint32 rxdata;

  /*~L*/
  /* Wait till RX fifo is NOT empty */
  while ((psASCLIN->RXFIFOCON.B.FILL)  == 0)
    /*~-*/
  {
    /*~T*/
    delay();
    /*~-*/
  }
  /*~E*/
  /*~T*/
  /* get byte */
  rxdata = psASCLIN->RXDATA.U;

  psASCLIN->FLAGSCLEAR.U = ASCLIN_FLAGSCLEAR_MASK;
  rxdata1 = rxdata;
  return rxdata;
  /*~-*/
}
/*******************************************************************************
** Syntax : void put_char(char z)                                             **
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
** Description : This function sends a character to Communication Port.       **
*******************************************************************************/
static void put_char(char z)
/*~-*/
{
  /*~T*/
  /* send character */
  psASCLIN->FLAGSCLEAR.U = ASCLIN_FLAGSCLEAR_MASK;
  psASCLIN->TXDATA.U = (uint32)z;

  /*~I*/
  if (z == LF)
    /*~-*/
  {
    /*~L*/
    while ( (psASCLIN->TXFIFOCON.B.FILL) != 0)
      /*~-*/
    {
      /*~T*/
      delay();

      /*~-*/
    }
    /*~E*/
    /*~T*/
    /* send CR */
    psASCLIN->FLAGSCLEAR.U = ASCLIN_FLAGSCLEAR_MASK;
    psASCLIN->TXDATA.U = CR;
    /*~-*/
  }
  /*~E*/
  /*~L*/
  while ( (psASCLIN->TXFIFOCON.B.FILL ) != 0)
    /*~-*/
  {
    /*~T*/
    delay();
    /*~-*/
  }
  /*~E*/
  psASCLIN->FLAGSCLEAR.U = ASCLIN_FLAGSCLEAR_MASK;

  /*~-*/
}


/*******************************************************************************
** Syntax : void buf_to_screen(char *text_buf)                                **
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
** Description : This function holds the Sting to be buffered to the          **
**               Communication Port.                                          **
*******************************************************************************/
static void buf_to_screen(char *text_buf)
/*~-*/
{
  /*~L*/
  while (*text_buf != 0)
    /*~-*/
  {
    /*~T*/
    /* send character */
    put_char(*text_buf);
    text_buf++;

    /*~-*/
  }
  /*~E*/
  /*~-*/
  ClearBuffer(ubOutputBuf, sizeof(ubOutputBuf));
}

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
void print_f(const char *p_frm, ...)
{
#if ((defined PRINT_ENABLE) && (PRINT_ENABLE == STD_ON))

  /*~T*/
  va_list p_arg;

  /*~T*/
  va_start(p_arg, p_frm);
  vsprintf(ubOutputBuf, p_frm, p_arg);
  va_end(p_arg);
  buf_to_screen(ubOutputBuf);
  
#endif
  /*~-*/
}

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
void getline(char *p_line, uint32 n_max)
{

#if ((defined PRINT_ENABLE) && (PRINT_ENABLE == STD_ON))

  /*~T*/
  uint32 w_cnt;
  int w_key;

  /*~T*/
  w_cnt = 0;

  /*~U*/
  /*~-2*/
  do
  {
    /*~T*/
    w_key = get_char();
    /*~I*/
    if ((w_key == CR) || (w_key == LF))

      /*~-*/
    {
      /*~T*/
      *p_line = 0;

      /*~-*/
    }
    /*~O*/
    /*~-2*/
    else
    {
      /*~I*/
      if ((w_key == BACKSPACE) || (w_key == DEL))

        /*~-*/
      {
        /*~T*/
        /* backspace or delete */

        /*~I*/
        if (w_cnt != 0)

          /*~-*/
        {
          /*~T*/
          /* delete character */
          w_cnt--;
          p_line--;
          put_char(BACKSPACE);
          put_char(' ');
          put_char(BACKSPACE);

          /*~-*/
        }
        /*~E*/
        /*~-*/
      }
      /*~O*/
      /*~-2*/
      else
      {
        /*~I*/
        if ((w_key != CNTLQ) && (w_key != CNTLS))

          /*~-*/
        {
          /*~F*/
          /* normal character*/

          /*~-*/
          {
            /*~T*/
            /* store/reflect character */
            *p_line = (char)w_key;
            put_char ((char)w_key);
            p_line++;
            w_cnt++;

            /*~I*/
            if (w_cnt == n_max)
              /*~-*/
            {
              /*~T*/
              /* limit reached */
              (void)beep();

              /*~T*/
              /* delete all characters */

              /*~L*/
              while (w_cnt != 0)
                /*~-*/
              {
                /*~T*/
                w_cnt--;
                p_line--;
                put_char(BACKSPACE);
                put_char(' ');
                put_char(BACKSPACE);

                /*~-*/
              }
              /*~E*/
              /*~-*/
            }
            /*~E*/
            /*~-*/
          }
          /*~E*/
          /*~-*/
        }
        /*~E*/
        /*~-*/
      }
      /*~E*/
      /*~-*/
    }
    /*~E*/
    /*~-*/
  }
  /*~O*/
  while ((w_key != CR) && (w_key != LF));
  /*~E*/
  /*~-*/
#endif

}

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
int get_ch(void)
{
#if ((defined PRINT_ENABLE) && (PRINT_ENABLE == STD_ON))

  uint32 c;

  if (psASCLIN->RXFIFOCON.B.FILL  != 0)
  {
    c = (char)psASCLIN->RXDATA.U ;
    psASCLIN->FLAGSCLEAR.U = ASCLIN_FLAGSCLEAR_MASK;
    return c;
  }
  else
  {
    return (-1);
  }

#endif
 
}

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
void Continue(void)
{
#if ((defined PRINT_ENABLE) && (PRINT_ENABLE == STD_ON))

  char szString[4];
  do
  {
    print_f("\n<ENTER>to continue: ");
    getline(szString, sizeof szString - 1);
    if (*szString != 0)
    {
      (void)beep();
    }
  }
  while (*szString != 0);

#endif

}

/*******************************************************************************
** Syntax : void print_flushfifo()                                            **
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
void print_flushfifo(void)
{
  psASCLIN->RXFIFOCON.B.FLUSH = 1 ;
  psASCLIN->TXFIFOCON.B.FLUSH = 1 ;
}


static void ClearBuffer(uint32* buf, uint32 size)
{
  uint32 m;
  for(m = 0; m < size; m++)
  {
    buf[m] = 0;
  }
}


