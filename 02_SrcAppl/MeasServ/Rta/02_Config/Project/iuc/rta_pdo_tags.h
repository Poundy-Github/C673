// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This files just contains the type definitions of the RTA relevant for the pdo tool. 

#ifndef RTA_PDO_TAGS_H
#define RTA_PDO_TAGS_H

// includes
#include <rta_datasets_buffer_types.h>
#include <Platform_Types.h>
#ifdef __cplusplus
extern "C"
{
#endif


/// \name All the following types are only used for pdo scan:
/// \{

// typedef unsigned long long uint64;//debug typedef Han Gu
/// structure of an RTA buffer which is sent to the MO. \n
/// It has to be compatible to the MO!

//Core 0
typedef struct
{
  /// holds the RTA version. It ensures compatibility with the MO. \n
  /// Range: Only the value of RTA_IF_VERSION is allowed.
  uint32 u_Version;
  /// has to be filled with the related coreID. It is used by the MO to map all the
  /// events in this buffer to the correct core in the visualization. \n
  /// Range: Only the value of the coreDefines (RTA_CORE_ID, RTA_CORE_ID_1, ....) is allowed.
  uint32 u_CoreID;
  /// systemTimeStamp taken at bufferChange has to be stored. BufferChange should be done
  /// near to cycleStart. \n
  /// Range:       0x0 ... 0xFFFF FFFF FFFF FFFF  \n
  /// Resolution:  1
  /// Unit:        us
  uint64 u_RefTs_us;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_00;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_01;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_02;
  /// ControlFlags to provide information to the RTA MOs
  /// Bit 0: 0 - No BufferOverflow, 1 - BufferOverflow, not all events could be stored!!
  /// Bits 1 - 7: Currently not in use
  uint8  u_CtrlFlags;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_10;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_11;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_12;
  /// Counter holding the running number of the buffer which is required by the MOs to check if there are buffers lost. \n
  /// Range: 0x0 ... 0xFF  \n
  uint8  u_BufferCnt;
  /// holds the number of currently filled events in the eventContainer. \n
  /// It has to be incremented at each entry of a new event. \n
  /// Range: 0x0 ... RTA_NO_OF_EVENTS
  uint32 u_MaxEventIndex;
  /// holds the size of the eventContainer. \n
  /// Range: It has to be equal to RTA_NO_OF_EVENTS.
  uint32 u_ContainerSize;
  /// intended to hold all events. \n
  /// Details see in definition of RTA_t_EventData.
  RTA_t_EventData EventContainer[RTA_NO_OF_EVENTS_CORE_0];
} RTA_t_BufferCore_0_PDO;                                    /* @vaddr:RTA_MEAS_VIRT_ADDRESS_CORE_0      @cycleid:RTA_ENV_CORE_0 @vname:RTA_BUFFER_0 */

typedef RTA_t_Info          RTA_t_InfoCore_0_PDO;            /* @vaddr:RTA_MEAS_VIRT_ADDRESS_INFO_CORE_0 @cycleid:RTA_ENV_CORE_0 @vname:RTA_INFO_0   */

//Core 1
typedef struct
{
  /// holds the RTA version. It ensures compatibility with the MO. \n
  /// Range: Only the value of RTA_IF_VERSION is allowed.
  uint32 u_Version;
  /// has to be filled with the related coreID. It is used by the MO to map all the
  /// events in this buffer to the correct core in the visualization. \n
  /// Range: Only the value of the coreDefines (RTA_CORE_ID, RTA_CORE_ID_1, ....) is allowed.
  uint32 u_CoreID;
  /// systemTimeStamp taken at bufferChange has to be stored. BufferChange should be done
  /// near to cycleStart. \n
  /// Range:       0x0 ... 0xFFFF FFFF FFFF FFFF  \n
  /// Resolution:  1
  /// Unit:        us
  uint64 u_RefTs_us;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_00;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_01;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_02;
  /// ControlFlags to provide information to the RTA MOs
  /// Bit 0: 0 - No BufferOverflow, 1 - BufferOverflow, not all events could be stored!!
  /// Bits 1 - 7: Currently not in use
  uint8  u_CtrlFlags;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_10;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_11;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_12;
  /// Counter holding the running number of the buffer which is required by the MOs to check if there are buffers lost. \n
  /// Range: 0x0 ... 0xFF  \n
  uint8  u_BufferCnt;
  /// holds the number of currently filled events in the eventContainer. \n
  /// It has to be incremented at each entry of a new event. \n
  /// Range: 0x0 ... RTA_NO_OF_EVENTS
  uint32 u_MaxEventIndex;
  /// holds the size of the eventContainer. \n
  /// Range: It has to be equal to RTA_NO_OF_EVENTS.
  uint32 u_ContainerSize;
  /// intended to hold all events. \n
  /// Details see in definition of RTA_t_EventData.
  RTA_t_EventData EventContainer[RTA_NO_OF_EVENTS_CORE_1];
} RTA_t_BufferCore_1_PDO;                                    /* @vaddr:RTA_MEAS_VIRT_ADDRESS_CORE_1       @cycleid:RTA_ENV_CORE_1 @vname:RTA_BUFFER_1 */

typedef RTA_t_Info          RTA_t_InfoCore_1_PDO;            /* @vaddr:RTA_MEAS_VIRT_ADDRESS_INFO_CORE_1  @cycleid:RTA_ENV_CORE_1 @vname:RTA_INFO_1   */

//Core 2
typedef struct
{
  /// holds the RTA version. It ensures compatibility with the MO. \n
  /// Range: Only the value of RTA_IF_VERSION is allowed.
  uint32 u_Version;
  /// has to be filled with the related coreID. It is used by the MO to map all the
  /// events in this buffer to the correct core in the visualization. \n
  /// Range: Only the value of the coreDefines (RTA_CORE_ID, RTA_CORE_ID_1, ....) is allowed.
  uint32 u_CoreID;
  /// systemTimeStamp taken at bufferChange has to be stored. BufferChange should be done
  /// near to cycleStart. \n
  /// Range:       0x0 ... 0xFFFF FFFF FFFF FFFF  \n
  /// Resolution:  1
  /// Unit:        us
  uint64 u_RefTs_us;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_00;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_01;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_02;
  /// ControlFlags to provide information to the RTA MOs
  /// Bit 0: 0 - No BufferOverflow, 1 - BufferOverflow, not all events could be stored!!
  /// Bits 1 - 7: Currently not in use
  uint8  u_CtrlFlags;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_10;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_11;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_12;
  /// Counter holding the running number of the buffer which is required by the MOs to check if there are buffers lost. \n
  /// Range: 0x0 ... 0xFF  \n
  uint8  u_BufferCnt;
  /// holds the number of currently filled events in the eventContainer. \n
  /// It has to be incremented at each entry of a new event. \n
  /// Range: 0x0 ... RTA_NO_OF_EVENTS
  uint32 u_MaxEventIndex;
  /// holds the size of the eventContainer. \n
  /// Range: It has to be equal to RTA_NO_OF_EVENTS.
  uint32 u_ContainerSize;
  /// intended to hold all events. \n
  /// Details see in definition of RTA_t_EventData.
  RTA_t_EventData EventContainer[RTA_NO_OF_EVENTS_CORE_2];
} RTA_t_BufferCore_2_PDO;                                    /* @vaddr:RTA_MEAS_VIRT_ADDRESS_CORE_2      @cycleid:RTA_ENV_CORE_2 @vname:RTA_BUFFER_2 */

typedef RTA_t_Info          RTA_t_InfoCore_2_PDO;            /* @vaddr:RTA_MEAS_VIRT_ADDRESS_INFO_CORE_2 @cycleid:RTA_ENV_CORE_2 @vname:RTA_INFO_2   */

//Core 3
typedef struct
{
  /// holds the RTA version. It ensures compatibility with the MO. \n
  /// Range: Only the value of RTA_IF_VERSION is allowed.
  uint32 u_Version;
  /// has to be filled with the related coreID. It is used by the MO to map all the
  /// events in this buffer to the correct core in the visualization. \n
  /// Range: Only the value of the coreDefines (RTA_CORE_ID, RTA_CORE_ID_1, ....) is allowed.
  uint32 u_CoreID;
  /// systemTimeStamp taken at bufferChange has to be stored. BufferChange should be done
  /// near to cycleStart. \n
  /// Range:       0x0 ... 0xFFFF FFFF FFFF FFFF  \n
  /// Resolution:  1
  /// Unit:        us
  uint64 u_RefTs_us;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_00;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_01;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_02;
  /// ControlFlags to provide information to the RTA MOs
  /// Bit 0: 0 - No BufferOverflow, 1 - BufferOverflow, not all events could be stored!!
  /// Bits 1 - 7: Currently not in use
  uint8  u_CtrlFlags;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_10;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_11;
  /// Padding byte - not used, just to ensure correct alignment
  uint8  u_Padding_12;
  /// Counter holding the running number of the buffer which is required by the MOs to check if there are buffers lost. \n
  /// Range: 0x0 ... 0xFF  \n
  uint8  u_BufferCnt;
  /// holds the number of currently filled events in the eventContainer. \n
  /// It has to be incremented at each entry of a new event. \n
  /// Range: 0x0 ... RTA_NO_OF_EVENTS
  uint32 u_MaxEventIndex;
  /// holds the size of the eventContainer. \n
  /// Range: It has to be equal to RTA_NO_OF_EVENTS.
  uint32 u_ContainerSize;
  /// intended to hold all events. \n
  /// Details see in definition of RTA_t_EventData.
  RTA_t_EventData EventContainer[RTA_NO_OF_EVENTS_CORE_3];
} RTA_t_BufferCore_3_PDO;                                    /* @vaddr:RTA_MEAS_VIRT_ADDRESS_CORE_3      @cycleid:RTA_ENV_CORE_3 @vname:RTA_BUFFER_3 */

typedef RTA_t_Info          RTA_t_InfoCore_3_PDO;            /* @vaddr:RTA_MEAS_VIRT_ADDRESS_INFO_CORE_3 @cycleid:RTA_ENV_CORE_3 @vname:RTA_INFO_3   */

/// \}


#ifdef __cplusplus
}
#endif

#endif // #ifndef RTA_PDO_TAGS_H
