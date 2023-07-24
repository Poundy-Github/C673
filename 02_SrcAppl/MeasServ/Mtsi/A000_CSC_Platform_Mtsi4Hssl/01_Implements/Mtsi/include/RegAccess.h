/**********************************************************************************************************************
  COMPANY:     Continental Teves AG & Co. OHG
  PROJECT:     adc420ha10
  CPU:         Aurix TC389QP
  MODULNAME:   McuDrivers
  VERSION:     $Revision: 1.0 $
 *********************************************************************************************************************/

/**
 *  \file       RegAccess.h
 *  \brief      Provides interfaces/macros necessary for accessing registers
 *  \date       30.01.2029
 *  \copyright  Continental AG
 *
 *  Header file to provide the interfaces/macros necessary for accessing registers.
 *
 */

#ifndef REG_ACCESS_H
#define REG_ACCESS_H

#ifdef __cplusplus
extern "C"
{
#endif

/* ================================================================================================================= */
/*                                            QAC Warnings Suppressions                                              */
/*                                           (Global Files Suppressions)                                             */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                                Include Files                                                      */
/* ================================================================================================================= */
#include <Platform_Types.h>


/** @defgroup Productive Productive code
 *  @{
 */

/** @defgroup RegAccess RegAccess
 *  @{
 */

/* ================================================================================================================= */
/*                                               Defines & Macros                                                    */
/* ================================================================================================================= */

/**
 *  \brief  Converts a number to a bit mask
 */
#define REG_ACCESS_NO_TO_BITMASK32(u32ID)    (0x1u << (u32ID))

/**
 *  \brief  Bit masks for a 32-bit register from number 0 to 31
 */
#define REG_ACCESS_BIT_MASK_BIT0             (0x00000001UL)
#define REG_ACCESS_BIT_MASK_BIT1             (0x00000002UL)
#define REG_ACCESS_BIT_MASK_BIT2             (0x00000004UL)
#define REG_ACCESS_BIT_MASK_BIT3             (0x00000008UL)
#define REG_ACCESS_BIT_MASK_BIT4             (0x00000010UL)
#define REG_ACCESS_BIT_MASK_BIT5             (0x00000020UL)
#define REG_ACCESS_BIT_MASK_BIT6             (0x00000040UL)
#define REG_ACCESS_BIT_MASK_BIT7             (0x00000080UL)
#define REG_ACCESS_BIT_MASK_BIT8             (0x00000100UL)
#define REG_ACCESS_BIT_MASK_BIT9             (0x00000200UL)
#define REG_ACCESS_BIT_MASK_BIT10            (0x00000400UL)
#define REG_ACCESS_BIT_MASK_BIT11            (0x00000800UL)
#define REG_ACCESS_BIT_MASK_BIT12            (0x00001000UL)
#define REG_ACCESS_BIT_MASK_BIT13            (0x00002000UL)
#define REG_ACCESS_BIT_MASK_BIT14            (0x00004000UL)
#define REG_ACCESS_BIT_MASK_BIT15            (0x00008000UL)
#define REG_ACCESS_BIT_MASK_BIT16            (0x00010000UL)
#define REG_ACCESS_BIT_MASK_BIT17            (0x00020000UL)
#define REG_ACCESS_BIT_MASK_BIT18            (0x00040000UL)
#define REG_ACCESS_BIT_MASK_BIT19            (0x00080000UL)
#define REG_ACCESS_BIT_MASK_BIT20            (0x00100000UL)
#define REG_ACCESS_BIT_MASK_BIT21            (0x00200000UL)
#define REG_ACCESS_BIT_MASK_BIT22            (0x00400000UL)
#define REG_ACCESS_BIT_MASK_BIT23            (0x00800000UL)
#define REG_ACCESS_BIT_MASK_BIT24            (0x01000000UL)
#define REG_ACCESS_BIT_MASK_BIT25            (0x02000000UL)
#define REG_ACCESS_BIT_MASK_BIT26            (0x04000000UL)
#define REG_ACCESS_BIT_MASK_BIT27            (0x08000000UL)
#define REG_ACCESS_BIT_MASK_BIT28            (0x10000000UL)
#define REG_ACCESS_BIT_MASK_BIT29            (0x20000000UL)
#define REG_ACCESS_BIT_MASK_BIT30            (0x40000000UL)
#define REG_ACCESS_BIT_MASK_BIT31            (0x80000000UL)


/**
 *  \brief  Generic macros that represent channel numbers from 0 to 31
 */
#define REG_ACCESS_CHANNEL_ID0               (0u)
#define REG_ACCESS_CHANNEL_ID1               (1u)
#define REG_ACCESS_CHANNEL_ID2               (2u)
#define REG_ACCESS_CHANNEL_ID3               (3u)
#define REG_ACCESS_CHANNEL_ID4               (4u)
#define REG_ACCESS_CHANNEL_ID5               (5u)
#define REG_ACCESS_CHANNEL_ID6               (6u)
#define REG_ACCESS_CHANNEL_ID7               (7u)
#define REG_ACCESS_CHANNEL_ID8               (8u)
#define REG_ACCESS_CHANNEL_ID9               (9u)
#define REG_ACCESS_CHANNEL_ID10              (10u)
#define REG_ACCESS_CHANNEL_ID11              (11u)
#define REG_ACCESS_CHANNEL_ID12              (12u)
#define REG_ACCESS_CHANNEL_ID13              (13u)
#define REG_ACCESS_CHANNEL_ID14              (14u)
#define REG_ACCESS_CHANNEL_ID15              (15u)
#define REG_ACCESS_CHANNEL_ID16              (16u)
#define REG_ACCESS_CHANNEL_ID17              (17u)
#define REG_ACCESS_CHANNEL_ID18              (18u)
#define REG_ACCESS_CHANNEL_ID19              (19u)
#define REG_ACCESS_CHANNEL_ID20              (20u)
#define REG_ACCESS_CHANNEL_ID21              (21u)
#define REG_ACCESS_CHANNEL_ID22              (22u)
#define REG_ACCESS_CHANNEL_ID23              (23u)
#define REG_ACCESS_CHANNEL_ID24              (24u)
#define REG_ACCESS_CHANNEL_ID25              (25u)
#define REG_ACCESS_CHANNEL_ID26              (26u)
#define REG_ACCESS_CHANNEL_ID27              (27u)
#define REG_ACCESS_CHANNEL_ID28              (28u)
#define REG_ACCESS_CHANNEL_ID29              (29u)
#define REG_ACCESS_CHANNEL_ID30              (30u)
#define REG_ACCESS_CHANNEL_ID31              (31u)

/* ================================================================================================================= */
/*                                                 Public Types                                                      */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                          Public Variables Declarations                                            */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                           Public Functions Declarations                                           */
/* ================================================================================================================= */
#ifdef UNIT_TEST_EXECUTING /*Only for tests, define the public prototype*/
  void RegAccess_Write8(const uint32 addr, const uint8 value);
  uint8 RegAccess_Read8(const uint32 addr);
  void RegAccess_Write16(const uint32 addr, const uint16 value);
  uint16 RegAccess_Read16(const uint32 addr);
  void RegAccess_Write32(const uint32 addr, const uint32 value);
  uint32 RegAccess_Read32(const uint32 addr);
  void RegAccess_Write64(const uint32 addr, const uint64 value);
  uint64 RegAccess_Read64(const uint32 addr);
  void RegAccess_SetBits32(const uint32 addr, const uint32 mask);
  void RegAccess_ClrBits32(const uint32 addr, const uint32 mask);
  void RegAccess_SetBits16(const uint32 addr, const uint16 mask);
  void RegAccess_ClrBits16(const uint32 addr, const uint16 mask);
#else
/**
 *  \brief  Writes a 8-bit register
 *
 *  \pre  None
 *  \post None
 *
 *  \globals None
 *  \InOutCorrelation None
 *
 *  \param [in] addr   Address of the 8-bit register
 *  \param [in] value  Value to be written in the 8-bit register
 *
 *  \return Nothing
 *
 *  \testmethod None
 *
 *  \satisfy{}
 *
 */
static inline void RegAccess_Write8(const uint32 addr, const uint8 value)
{
    *(volatile uint8* )addr = value;
}

/**
 *  \brief  Reads a 8-bit register
 *
 *  \pre  None
 *  \post None
 *
 *  \globals None
 *  \InOutCorrelation None
 *
 *  \param [in] addr  Address of the 8-bit register
 *
 *  \return Value of the read register
 *
 *  \testmethod None
 *
 *  \satisfy{}
 *
 */
static inline uint8 RegAccess_Read8(const uint32 addr)
{
    return *(volatile uint8 *)addr;
}

/**
 *  \brief  Writes a 16-bit register
 *
 *  \pre  None
 *  \post None
 *
 *  \globals None
 *  \InOutCorrelation None
 *
 *  \param [in] addr   Address of the 16-bit register
 *  \param [in] value  Value to be written in the 16-bit register
 *
 *  \return Nothing
 *
 *  \testmethod None
 *
 *  \satisfy{}
 *
 */
static inline void RegAccess_Write16(const uint32 addr, const uint16 value)
{
    *(volatile uint16 *)addr = value;
}

/**
 *  \brief  Reads a 16-bit register
 *
 *  \pre  None
 *  \post None
 *
 *  \globals None
 *  \InOutCorrelation None
 *
 *  \param [in] addr  Address of the 16-bit register
 *
 *  \return Value of the read register
 *
 *  \testmethod None
 *
 *  \satisfy{}
 *
 */
static inline uint16 RegAccess_Read16(const uint32 addr)
{
    return *(volatile uint16 *)addr;
}

/**
 *  \brief  Writes a 32-bit register
 *
 *  \pre  None
 *  \post None
 *
 *  \globals None
 *  \InOutCorrelation None
 *
 *  \param [in] addr  Address of the 32-bit register
 *  \param [in] value  Value to be written in the 32-bit register
 *
 *  \return Nothing
 *
 *  \testmethod None
 *
 *  \satisfy{}
 *
 */
static inline void RegAccess_Write32(const uint32 addr, const uint32 value)
{
    *(volatile uint32 *)addr = value;
}

/**
 *  \brief  Reads a 32-bit register
 *
 *  \pre  None
 *  \post None
 *
 *  \globals None
 *  \InOutCorrelation None
 *
 *  \param [in] addr Address of the 32-bit register
 *
 *  \return Value of the read register
 *
 *  \testmethod None
 *
 *  \satisfy{}
 *
 */
static inline uint32 RegAccess_Read32(const uint32 addr)
{
    return *(volatile uint32 *)addr;
}

/**
 *  \brief  Writes a 64-bit register
 *
 *  \pre  None
 *  \post None
 *
 *  \globals None
 *  \InOutCorrelation None
 *
 *  \param [in] addr  Address of the 64-bit register
 *  \param [in] value Value to be written in the 64-bit register
 *
 *  \return Nothing
 *
 *  \testmethod None
 *
 *  \satisfy{}
 *
 */
static inline void RegAccess_Write64(const uint32 addr, const uint64 value)
{
    *(volatile uint64 *)addr = value;
}

/**
 *  \brief  Reads a 64-bit register
 *
 *  \pre  None
 *  \post None
 *
 *  \globals None
 *  \InOutCorrelation None
 *
 *  \param [in] addr  Address of the 64-bit register
 *
 *  \return Value of the read register
 *
 *  \testmethod None
 *
 *  \satisfy{}
 *
 */
static inline uint64 RegAccess_Read64(const uint32 addr)
{
    return *(volatile uint64 *)addr;
}

/**
 *  \brief  Sets the bits of a mask in a 32-bit register
 *
 *  \pre  None
 *  \post None
 *
 *  \globals None
 *  \InOutCorrelation None
 *
 *  \param [in] addr  Address of the 32-bit register
 *  \param [in] mask  Value of the mask that must be set in the register
 *
 *  \return Nothing
 *
 *  \testmethod None
 *
 *  \satisfy{}
 *
 */
static inline void RegAccess_SetBits32(const uint32 addr, const uint32 mask)
{
    *(volatile uint32 *)addr |= mask;
}

/**
 *  \brief  Clears the bits of a mask in a 32-bit register
 *
 *  \pre  None
 *  \post None
 *
 *  \globals None
 *  \InOutCorrelation None
 *
 *  \param [in] addr  Address of the 32-bit register
 *  \param [in] mask  Value of the mask that must be cleared in the register
 *
 *  \return Nothing
 *
 *  \testmethod None
 *
 *  \satisfy{}
 *
 */
static inline void RegAccess_ClrBits32(const uint32 addr, const uint32 mask)
{
    *(volatile uint32 *)addr &= ~mask;
}

/**
 *  \brief  Sets the bits of a mask in a 16-bit register
 *
 *  \pre  None
 *  \post None
 *
 *  \globals None
 *  \InOutCorrelation None
 *
 *  \param [in] addr  Address of the 16-bit register
 *  \param [in] mask  Value of the mask that must be set in the register
 *
 *  \return Nothing
 *
 *  \testmethod None
 *
 *  \satisfy{}
 *
 */
static inline void RegAccess_SetBits16(const uint32 addr, const uint16 mask)
{
    *(volatile uint16 *)addr |= mask;
}

/**
 *  \brief  Clears the bits of a mask in a 16-bit register
 *
 *  \pre  None
 *  \post None
 *
 *  \globals None
 *  \InOutCorrelation None
 *
 *  \param [in] addr  Address of the 16-bit register
 *  \param [in] mask  Value of the mask that must be cleared in the register
 *
 *  \return Nothing
 *
 *  \testmethod None
 *
 *  \satisfy{}
 *
 */
static inline void RegAccess_ClrBits16(const uint32 addr, const uint16 mask)
{
    *(volatile uint16 *)addr &= ~mask;
}



#ifdef __cplusplus
}
#endif

#endif  /*UNIT_TEST_EXECUTING*/
#endif /* #ifndef REG_ACCESS_H */


/** @} doxygen end group definition  */
/** @} doxygen end group definition  */

/* ================================================================================================================= */
/*                                                     End of File                                                   */
/* ================================================================================================================= */
