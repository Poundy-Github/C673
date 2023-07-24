/**********************************************************************************************************************
  COMPANY:     Continental Teves AG & Co. OHG
  PROJECT:     PROJECT-INDEPENDENT
  CPU:         Aurix TC389QP
  MODULNAME:   Scu
  VERSION:     $Revision: 1.0 $
 *********************************************************************************************************************/

/*
 *  \file       ScuWdt.c
 *  \brief      Interfaces to unlock/lock Endinit as well as Safety Endinit protection (source file)
 *  \date       2019-04-10
 *  \copyright  Continental AG
 *
 *  Unit provides the interfaces to handle the global Endinit and Safety Endinit protection of the registers.
 *  The interfaces has to be used once the system/safety related register have to be written/modified.
 *
 */

/* ================================================================================================================= */
/*                                            QAC Warnings Suppressions                                              */
/*                                           (Global Files Suppressions)                                             */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                                Include Files                                                      */
/* ================================================================================================================= */
#include "ScuWdt.h"
#include "RegAccess.h"

/** @defgroup Productive Productive code
 *  @{
 */

/** @defgroup ScuWdt ScuWdt
 *  @{
 */
/* ================================================================================================================= */
/*                                               Defines & Macros                                                    */
/* ================================================================================================================= */

/**
 *  \brief  SCU Register addresses definition (global Safety Endinit)
 *
 *  Definition of the SCU (System Control Units) registers addresses, masks and offsets of required bit
 *  fields of global Safety Endinit protection.
 *
 *
 *  \range      n/a
 *  \resolution n/a
 *  \unit       n/a
 */
#define SCUWDT_SEICON0_ADDR                         (0xF00362B4UL)
#define SCUWDT_SEICON0_EPW_MSK                      (0x3fffUL)
#define SCUWDT_SEICON0_EPW_OFF                      (2u)
#define SCUWDT_SEICON0_REL_FIXED_VALUE              (0xFFFCUL)
#define SCUWDT_SEICON0_REL_MSK                      (0xffffUL)
#define SCUWDT_SEICON0_REL_OFF                      (16u)
#define SCUWDT_SEICON0_ENDINIT_MSK                  (0x1UL)
#define SCUWDT_SEICON0_ENDINIT_OFF                  (1u)

/**
 *  \brief  SCU Register addresses definition (global Endinit)
 *
 *  Definition of the SCU (System Control Units) registers addresses as well as masks and offsets of required
 *  bit fields of global Endinit protection.
 *
 *
 *  \range      n/a
 *  \resolution n/a
 *  \unit       n/a
 */
#define SCUWDT_EICON0_ADDR                          (0xF003629CUL)
#define SCUWDT_EICON0_EPW_MSK                       (0x3fffUL)
#define SCUWDT_EICON0_EPW_OFF                       (2u)
#define SCUWDT_EICON0_REL_FIXED_VALUE               (0xFFFCUL)
#define SCUWDT_EICON0_REL_OFF                       (16u)
#define SCUWDT_EICON0_ENDINIT_MSK                   (0x1UL)
#define SCUWDT_EICON0_ENDINIT_OFF                   (1u)
#define SCUWDT_CPU0CON0_ADDR                        (0xF003624CUL)
#define SCUWDT_CPU0CON0_EPW_MSK                     (0x3fffu)
#define SCUWDT_CPU0CON0_EPW_OFF                     (2u)
#define SCUWDT_CPU0CON0_REL_MSK                     (uint32)(0xffff)
#define SCUWDT_CPU0CON0_REL_OFF                     (16u)
#define SCUWDT_CPU0CON0_ENDINIT_MSK                 (0x1u)
#define SCUWDT_CPU0CON0_ENDINIT_OFF                 (0u)
#define SCUWDT_CPU0CON0_REL_FIXED_VALUE             (0xFFFCu)
#define SCUWDT_CPU0CON0_PWACCESS_FIXED_VALUE        (0x1u)
#define SCUWDT_CPU0CON0_MODACC_CLEAR_ENDINIT        (0x2u)
#define SCUWDT_CPU0CON0_MODACC_SET_ENDINIT          (0x3u)



#define SCUWDT_CPU1CON0_ADDR                        (0xF0036258UL)
#define SCUWDT_CPU1CON0_EPW_MSK                     (0x3fffu)
#define SCUWDT_CPU1CON0_EPW_OFF                     (2u)
#define SCUWDT_CPU1CON0_REL_MSK                     (uint32)(0xffff)
#define SCUWDT_CPU1CON0_REL_OFF                     (16u)
#define SCUWDT_CPU1CON0_ENDINIT_MSK                 (0x1u)
#define SCUWDT_CPU1CON0_ENDINIT_OFF                 (0u)
#define SCUWDT_CPU1CON0_REL_FIXED_VALUE             (0xFFFCu)
#define SCUWDT_CPU1CON0_PWACCESS_FIXED_VALUE        (0x1u)
#define SCUWDT_CPU1CON0_MODACC_CLEAR_ENDINIT        (0x2u)
#define SCUWDT_CPU1CON0_MODACC_SET_ENDINIT          (0x3u)

/**
 *  \brief  Internal macro definitions
 *
 *  Definition of the internal macros to increase the readability of the code
 *
 *
 *  \range      n/a
 *  \resolution n/a
 *  \unit       n/a
 */
#define SCUWDT_PSWD_SIX_BITS_MSK                    (0x003fu)

/* ================================================================================================================= */
/*                                                Private Types                                                      */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                               Private Variables                                                   */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                               Public Variables                                                    */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                         Private Functions Definitions                                             */
/* ================================================================================================================= */

/**
 *  \brief  Returns (global) Endinit password \n
 *
 *   The function returns (global) Endinit password.
 *
 *  \startuml
 *     start
 *     :read register with password;
 *     :take password from the whole register;
 *     :shift the password back in the uint16 variable to the right side;
 *     :invert last 6 bits (inverted by HW during read of the register);
 *     stop
 *  \enduml
 *
 *  \pre         none
 *
 *  \post        none
 *
 *  \param [in]  void
 *
 *  \return      uint16 Endinit password
 *
 *  \traceability none
 */
static uint16 ScuWdt_EndinitPswdGet( void )
{
   /* Read Password from EICON0 register                                                */
   /* Toggle back the last six bits of the password before returning it (HW protection) */

   uint32 Reg_value = RegAccess_Read32(SCUWDT_EICON0_ADDR);
   uint16 password  = (uint16) (Reg_value & (SCUWDT_EICON0_EPW_MSK << SCUWDT_EICON0_EPW_OFF));
   password = password >> SCUWDT_EICON0_EPW_OFF;    /* shift the password back in the uint16 variable to the right side*/
   password = password ^  SCUWDT_PSWD_SIX_BITS_MSK; /* invert last 6 bits */

   return password;
}

/**
 *  \brief  Returns (global) Safety Endinit password \n
 *
 *   The function returns (global) Safety Endinit password.
 *
 *  \startuml
 *     start
 *     :read register with password;
 *     :take password from the whole register;
 *     :shift the password back in the uint16 variable to the right side;
 *     :invert last 6 bits (inverted by HW during read of the register);
 *     stop
 *  \enduml
 *
 *  \pre         none
 *
 *  \post        none
 *
 *  \param [in]  void
 *
 *  \return      uint16 Safety Endinit password
 *
 *  \traceability none
 */
static uint16 ScuWdt_SafetyEndinitPswdGet( void )
{
   /* Read Password from EICON0 register                                                */
   /* Toggle back the last six bits of the password before returning it (HW protection) */

   uint32 Reg_value = RegAccess_Read32( SCUWDT_SEICON0_ADDR );
   uint16 password  = (uint16) (Reg_value & ( SCUWDT_SEICON0_EPW_MSK << SCUWDT_SEICON0_EPW_OFF));
   password = password >> SCUWDT_SEICON0_EPW_OFF; /* shift the password back in the uint16 variable to the right side*/
   password = password ^  SCUWDT_PSWD_SIX_BITS_MSK; /* invert last 6 bits */

   return password;
}
/**
 *  \brief  Returns Cpu0 Endinit password \n
 *
 *   The function returns Cpu0 Endinit password.
 *
 *  \startuml
 *     start
 *     :read register with password;
 *     :take password from the whole register;
 *     :shift the password back in the uint16 variable to the right side;
 *     :invert last 6 bits (inverted by HW during read of the register);
 *     stop
 *  \enduml
 *
 *  \pre         none
 *
 *  \post        none
 *
 *  \param [in]  void
 *
 *  \return      uint16 Cpu0 Endinit password
 *
 *  \traceability none
 */
static uint16 ScuWdt_Cpu0PswdGet( void )
{
   /* Read Password from WDTCPUyCON0 register                                                */
   /* Toggle back the last six bits of the password before returning it (HW protection) */

   uint32 Reg_value = RegAccess_Read32( SCUWDT_CPU0CON0_ADDR );
   uint16 password  = (uint16) (Reg_value & ( SCUWDT_CPU0CON0_EPW_MSK << SCUWDT_CPU0CON0_EPW_OFF));
   password = password >> SCUWDT_CPU0CON0_EPW_OFF; /* shift the password back in the uint16 variable to the right side*/
   password = password ^  SCUWDT_PSWD_SIX_BITS_MSK; /* invert last 6 bits */

   return password;
}

/**
 *  \brief  Returns CPU0CON0 reload value \n
 *
 *   The function returns CPU0CON0 reload value.
 *
 *  \startuml
 *     start
 *     :read register;
 *     :take reload value(REL) from the whole register;
 *     :shift the REL in the uint32 variable to the right side;
 *     :cast the uint32 variable to uint16 variable;
 *     stop
 *  \enduml
 *
 *  \pre         Must be called after ScuWdt_Cpu0PswdGet()
 *
 *  \post        none
 *
 *  \param [in]  void
 *
 *  \return      uint16 CPU0CON0 REL value
 *
 *  \traceability none
 */
static uint16 ScuWdt_Cpu0RelGet( void )
{
   uint32 Reg_value = 0;
   uint32 Rel32 = 0;
   uint16 Rel16 = 0;

   Reg_value = RegAccess_Read32( SCUWDT_CPU0CON0_ADDR );
   Rel32 = (Reg_value & ( SCUWDT_CPU0CON0_REL_MSK << SCUWDT_CPU0CON0_REL_OFF));
   Rel32 = (Rel32 >> SCUWDT_CPU0CON0_REL_OFF); /* shift the Rel back in the uint32 variable to the right side*/
   Rel16 = (uint16)Rel32;
   return Rel16;
}

/**
 *  \brief  Returns Cpu1 Endinit password \n
 *
 *   The function returns Cpu1 Endinit password.
 *
 *  \startuml
 *     start
 *     :read register with password;
 *     :take password from the whole register;
 *     :shift the password back in the uint16 variable to the right side;
 *     :invert last 6 bits (inverted by HW during read of the register);
 *     stop
 *  \enduml
 *
 *  \pre         none
 *
 *  \post        none
 *
 *  \param [in]  void
 *
 *  \return      uint16 Cpu1 Endinit password
 *
 *  \traceability none
 */
static uint16 ScuWdt_Cpu1PswdGet( void )
{
  uint32 Reg_value = RegAccess_Read32( SCUWDT_CPU1CON0_ADDR );
  uint16 password  = (uint16) (Reg_value & ( SCUWDT_CPU1CON0_EPW_MSK << SCUWDT_CPU1CON0_EPW_OFF));
  password = password >> SCUWDT_CPU1CON0_EPW_OFF; /* shift the password back in the uint16 variable to the right side*/
  password = password ^  SCUWDT_PSWD_SIX_BITS_MSK; /* invert last 6 bits */

  return password;
}

/**
 *  \brief  Returns CPU1CON0 reload value \n
 *
 *   The function returns CPU1CON0 reload value.
 *
 *  \startuml
 *     start
 *     :read register;
 *     :take reload value(REL) from the whole register;
 *     :shift the REL in the uint32 variable to the right side;
 *     :cast the uint32 variable to uint16 variable;
 *     stop
 *  \enduml
 *
 *  \pre         Must be called after ScuWdt_Cpu0PswdGet()
 *
 *  \post        none
 *
 *  \param [in]  void
 *
 *  \return      uint16 CPU1CON0 REL value
 *
 *  \traceability none
 */
static uint16 ScuWdt_Cpu1RelGet( void )
{
   uint32 Reg_value = 0; 
   uint32 Rel32 = 0;
   uint16 Rel16 = 0;
   
   Reg_value = RegAccess_Read32( SCUWDT_CPU1CON0_ADDR );
   Rel32 = (Reg_value & ( SCUWDT_CPU1CON0_REL_MSK << SCUWDT_CPU1CON0_REL_OFF));
   Rel32 = (Rel32 >> SCUWDT_CPU1CON0_REL_OFF); /* shift the Rel back in the uint32 variable to the right side*/
   Rel16 = (uint16)Rel32;
   return Rel16;
}
/* ================================================================================================================= */
/*                                            Public Functions Definitions                                           */
/* ================================================================================================================= */

void ScuWdt_EndinitClear( void )
{
   /* Get global Endinit password */
   uint16 password = ScuWdt_EndinitPswdGet();

   /* Clear global Endinit bit*/
   uint32 Reg_value =    (SCUWDT_EICON0_REL_FIXED_VALUE << SCUWDT_EICON0_REL_OFF)
                       | (             (uint32)password << SCUWDT_EICON0_EPW_OFF);

   RegAccess_Write32( SCUWDT_EICON0_ADDR, Reg_value );

   while ( (RegAccess_Read32(SCUWDT_EICON0_ADDR) & (SCUWDT_EICON0_ENDINIT_MSK << SCUWDT_EICON0_ENDINIT_OFF)) != 0x0UL )
   {
      /* Wait until global Endinit bit is cleared */
   }
}

void ScuWdt_EndinitSet( void )
{
   /* Get global Endinit password */
   uint16 password = ScuWdt_EndinitPswdGet();

   /* Set global Endinit bit */
   uint32 Reg_value = (SCUWDT_EICON0_REL_FIXED_VALUE << SCUWDT_EICON0_REL_OFF     )
                    | (             (uint32)password << SCUWDT_EICON0_EPW_OFF     )
                    | (    SCUWDT_EICON0_ENDINIT_MSK << SCUWDT_EICON0_ENDINIT_OFF );

   RegAccess_Write32( SCUWDT_EICON0_ADDR, Reg_value );

   while ( (RegAccess_Read32(SCUWDT_EICON0_ADDR) & (SCUWDT_EICON0_ENDINIT_MSK << SCUWDT_EICON0_ENDINIT_OFF)) == 0x0UL )
   {
      /* Wait until global Endinit bit is set back */
   }
}

void ScuWdt_SafetyEndinitClear( void )
{
   /* Get Safety Endinit password */
   uint16 password = ScuWdt_SafetyEndinitPswdGet();

   /* Clear Safety EndInit Watch-dog */
   uint32 Reg_value =   ( SCUWDT_SEICON0_REL_FIXED_VALUE << SCUWDT_SEICON0_REL_OFF )
                      | (               (uint32)password << SCUWDT_SEICON0_EPW_OFF );

   RegAccess_Write32( SCUWDT_SEICON0_ADDR, Reg_value );

   while ((RegAccess_Read32(SCUWDT_SEICON0_ADDR) & (SCUWDT_SEICON0_ENDINIT_MSK << SCUWDT_SEICON0_ENDINIT_OFF))!= 0x0UL)
   {
      /* Wait until global Safety Endinit bit is cleared */
   }
}

void ScuWdt_SafetyEndinitSet( void )
{
   /* Get global Safety Endinit password */
   uint16 password = ScuWdt_SafetyEndinitPswdGet();

   /* Set global Safety EndInit Watch-dog */
   uint32 Reg_value = (SCUWDT_SEICON0_REL_FIXED_VALUE << SCUWDT_SEICON0_REL_OFF    )
                    | (              (uint32)password << SCUWDT_SEICON0_EPW_OFF    )
                    | (    SCUWDT_SEICON0_ENDINIT_MSK << SCUWDT_SEICON0_ENDINIT_OFF);

   RegAccess_Write32( SCUWDT_SEICON0_ADDR, Reg_value );

   while ((RegAccess_Read32(SCUWDT_SEICON0_ADDR) & (SCUWDT_SEICON0_ENDINIT_MSK << SCUWDT_SEICON0_ENDINIT_OFF))== 0x0UL)
   {
      /* Wait until global Safety Endinit bit is set */
   }
}

void ScuWdt_Cpu0EndinitClear( void )
{
   /* Get CPU0 Endinit password */
   uint16 password = ScuWdt_Cpu0PswdGet();
   uint16 Rel = ScuWdt_Cpu0RelGet();
   /*Password Access*/
   uint32 Reg_value = ((uint32)Rel << SCUWDT_CPU0CON0_REL_OFF) | ((uint32)password << SCUWDT_CPU0CON0_EPW_OFF) | 
                      (SCUWDT_CPU0CON0_PWACCESS_FIXED_VALUE);   
   RegAccess_Write32( SCUWDT_CPU0CON0_ADDR, Reg_value );
   
  /*Modify Access*/
  Reg_value = ((uint32)Rel << SCUWDT_CPU0CON0_REL_OFF) | ((uint32)password << SCUWDT_CPU0CON0_EPW_OFF) | 
                      (SCUWDT_CPU0CON0_MODACC_CLEAR_ENDINIT);   
  RegAccess_Write32( SCUWDT_CPU0CON0_ADDR, Reg_value );

   while ((RegAccess_Read32(SCUWDT_CPU0CON0_ADDR) & (SCUWDT_CPU0CON0_ENDINIT_MSK << SCUWDT_CPU0CON0_ENDINIT_OFF)) == 0x1UL)
   {
      /* Wait until CPU0 Endinit bit is cleared */
   }
}

void ScuWdt_Cpu0EndinitSet( void )
{
   /* Get CPU0 Endinit password */
   uint16 password = ScuWdt_Cpu0PswdGet();
   uint16 Rel = ScuWdt_Cpu0RelGet();
   /*Password Access*/
   uint32 Reg_value = ((uint32)Rel << SCUWDT_CPU0CON0_REL_OFF) | ((uint32)password << SCUWDT_CPU0CON0_EPW_OFF) | 
                      (SCUWDT_CPU0CON0_PWACCESS_FIXED_VALUE);   
   RegAccess_Write32( SCUWDT_CPU0CON0_ADDR, Reg_value );
   
  /*Modify Access*/
  Reg_value = ((uint32)Rel << SCUWDT_CPU0CON0_REL_OFF) | ((uint32)password << SCUWDT_CPU0CON0_EPW_OFF) | 
                      (SCUWDT_CPU0CON0_MODACC_SET_ENDINIT);   
  RegAccess_Write32( SCUWDT_CPU0CON0_ADDR, Reg_value );

   while ((RegAccess_Read32(SCUWDT_CPU0CON0_ADDR) & (SCUWDT_CPU0CON0_ENDINIT_MSK << SCUWDT_CPU0CON0_ENDINIT_OFF))== 0x0UL )
   {
      /* Wait until CPU0 Endinit bit is set */
   }
}

void ScuWdt_Cpu1EndinitClear( void )
{
   /* Get CPU1 Endinit password */
   uint16 password = ScuWdt_Cpu0PswdGet();
   uint16 Rel = ScuWdt_Cpu1RelGet();
   /*Password Access*/
   uint32 Reg_value = ((uint32)Rel << SCUWDT_CPU1CON0_REL_OFF) | ((uint32)password << SCUWDT_CPU1CON0_EPW_OFF) | 
                      (SCUWDT_CPU1CON0_PWACCESS_FIXED_VALUE);   
   RegAccess_Write32( SCUWDT_CPU1CON0_ADDR, Reg_value );
   
  /*Modify Access*/
  Reg_value = ((uint32)Rel << SCUWDT_CPU1CON0_REL_OFF) | ((uint32)password << SCUWDT_CPU1CON0_EPW_OFF) | 
                      (SCUWDT_CPU1CON0_MODACC_CLEAR_ENDINIT);   
   RegAccess_Write32( SCUWDT_CPU1CON0_ADDR, Reg_value );

   while ((RegAccess_Read32(SCUWDT_CPU1CON0_ADDR) & (SCUWDT_CPU1CON0_ENDINIT_MSK << SCUWDT_CPU1CON0_ENDINIT_OFF)) == 0x1UL )
   {
      /* Wait until CPU0 Endinit bit is cleared */
   }
}

void ScuWdt_Cpu1EndinitSet( void )
{
   /* Get CPU1 Endinit password */
   uint16 password = ScuWdt_Cpu1PswdGet();
   uint16 Rel = ScuWdt_Cpu1RelGet();
   /*Password Access*/
   uint32 Reg_value = ((uint32)Rel << SCUWDT_CPU1CON0_REL_OFF) | ((uint32)password << SCUWDT_CPU1CON0_EPW_OFF) | 
                      (SCUWDT_CPU1CON0_PWACCESS_FIXED_VALUE);   
   RegAccess_Write32( SCUWDT_CPU1CON0_ADDR, Reg_value );
   
  /*Modify Access*/
  Reg_value = ((uint32)Rel << SCUWDT_CPU1CON0_REL_OFF) | ((uint32)password << SCUWDT_CPU1CON0_EPW_OFF) | 
                      (SCUWDT_CPU1CON0_MODACC_SET_ENDINIT);   
  RegAccess_Write32( SCUWDT_CPU1CON0_ADDR, Reg_value );

   while ((RegAccess_Read32(SCUWDT_CPU1CON0_ADDR) & (SCUWDT_CPU1CON0_ENDINIT_MSK << SCUWDT_CPU1CON0_ENDINIT_OFF)) == 0x0UL )
   {
      /* Wait until CPU1 Endinit bit is set */
   }
}
/** @} doxygen end group definition  */
/** @} doxygen end group definition  */

/* ================================================================================================================= */
/*                                                     End of File                                                   */
/* ================================================================================================================= */
