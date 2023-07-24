// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: MTSI
// VERSION:   $Revision: 1.11 $ 
/// @file

 
#ifndef MTSI_CommonTypes_H
#define MTSI_CommonTypes_H

#include <Std_Types.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef RTE_TYPE_MTSI_t_FreezeInfo
/// @brief    Information about freeze
typedef struct
{  
  uint32 VirtualAddress;  ///< Virtual address of meas freeze
  uint32 Length;          ///< Length of data
  uint16 FunctionId;      ///< Identifier of data source
  uint16 Options;         ///< Additional options (not yet supported - set to zero by default)
} MTSI_t_FreezeInfo;
#endif

/// @brief    Information about lost freeze
typedef struct
{
  uint32 VirtualAddress : 32; ///< Virtual address of meas freeze
  uint32 Length : 24;         ///< Length of data of meas freeze
  uint8 RejectReason : 8;     ///< Reject reason of meas freeze
  uint16 FunctionId : 16;     ///< Identifier of data source
} MTSI_t_FreezeLostInfo;

/// @brief Callback function for freezes
typedef void (*MTSI_t_Callback)(void); 

/// @brief No option selected (default value)
#define MTSI_OPTION_NONE (uint16)0x0000


/// @brief Data shall be copied to local buffer in MTSI (to be used for volatile data only)
/// 
/// Option not supported! For future development!
/// Set callback function to NULL-pointer to indicate volatile data!
#define MTSI_OPTION_BUFFERED (uint16)0x0001

/// @brief MISC checksum shall be calculated for data (32bit alignment required)
/// 
/// Option not supported! For future development!
#define MTSI_OPTION_MISC (uint16)0x0010

/// @brief CRC checksum shall be calculated for data
/// 
/// Option not supported! For future development!
#define MTSI_OPTION_CRC32 (uint16)0x0020

/// @brief Number of header padding bytes division
/// The number of padding bytes that must be added
/// to the MTS packet header.
/// Padding bytes can be used to adapt the header size
/// to the platform specific byte alignment.
#define CFG_MTSI_HEADER_NUMBER_OF_PADDING_BYTES_DIV 2u

/***    User explicit entries    ***/


#ifdef __cplusplus
}
#endif


#endif


