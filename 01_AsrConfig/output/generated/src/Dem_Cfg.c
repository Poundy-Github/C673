/**
 * \file
 *
 * \brief AUTOSAR Dem
 *
 * This file contains the implementation of the AUTOSAR
 * module Dem.
 *
 * \version 6.4.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* This file contains all definitions of the configuration of the AUTOSAR
 * module Dem that are target independent. */

/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 11.1 (required)
 *     Conversions shall not be performed between a pointer to a function and
 *     any other type.
 *
 *     Reason:
 *     In order to save memory, the function pointers necessary for Read Callbacks are generated
 *     as an array of unions (union type which contains all such possible function pointers),
 *     instead of an array of structures containing all possible pointer types.
 *     The array containing the function pointers is initialized using brace-enclosed initializer
 *     list and C90 standard allow only the initialization of the first union member.
 *     The solution is to use a "generic function pointer" and use that type to define the array,
 *     and use explicit casts for each initialized member.
 *     Casting one function pointer type to the general type at initialization and then back again
 *     to the original type is guaranteed to preserve the correct data.
 */



/*==================[inclusions]============================================*/
/* !LINKSTO dsn.Dem.IncludeStr,1 */

#include <TSAutosar.h>                    /* EB specific standard types */
#include <Std_Types.h>                    /* AUTOSAR standard types */
#include <Dem_Int.h>                      /* API and internal declarations,
                                           * dependent and static part */
/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

#define DEM_START_SEC_CONST_8
#include <Dem_MemMap.h>

CONST(Dem_ConfigType, DEM_CONST) DemConfigSet_0 = {0U};

#define DEM_STOP_SEC_CONST_8
#include <Dem_MemMap.h>



/*------------------[Freeze frame classes configuration]--------------------*/
#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>

/** \brief Indexes of element on freeze frame data segment
** DID_Odometer
**/
STATIC CONST(Dem_DataElementIdxType, DEM_CONST)
  Dem_DataElementIdxDID_Odometer[1] =
{
  0U, /* DemDataElementClass_Odometer */
};

/** \brief Start-bytes of element on freeze frame data segment
** DID_Odometer
**/
STATIC CONST(Dem_DataElementOffsetType, DEM_CONST)
  Dem_DataElementOffsetDID_Odometer[1] =
{
  0U, /* DemDataElementClass_Odometer */
};

/** \brief Indexes of element on freeze frame data segment
** DID_Voltage
**/
STATIC CONST(Dem_DataElementIdxType, DEM_CONST)
  Dem_DataElementIdxDID_Voltage[1] =
{
  1U, /* DemDataElementClass_Voltage */
};

/** \brief Start-bytes of element on freeze frame data segment
** DID_Voltage
**/
STATIC CONST(Dem_DataElementOffsetType, DEM_CONST)
  Dem_DataElementOffsetDID_Voltage[1] =
{
  0U, /* DemDataElementClass_Voltage */
};

/** \brief Indexes of element on freeze frame data segment
** DID_VehicleSpeed
**/
STATIC CONST(Dem_DataElementIdxType, DEM_CONST)
  Dem_DataElementIdxDID_VehicleSpeed[1] =
{
  2U, /* DemDataElementClass_VehicleSpeed */
};

/** \brief Start-bytes of element on freeze frame data segment
** DID_VehicleSpeed
**/
STATIC CONST(Dem_DataElementOffsetType, DEM_CONST)
  Dem_DataElementOffsetDID_VehicleSpeed[1] =
{
  0U, /* DemDataElementClass_VehicleSpeed */
};

/** \brief Indexes of element on freeze frame data segment
** DID_LocalTime
**/
STATIC CONST(Dem_DataElementIdxType, DEM_CONST)
  Dem_DataElementIdxDID_LocalTime[1] =
{
  3U, /* DemDataElementClass_LocalTime */
};

/** \brief Start-bytes of element on freeze frame data segment
** DID_LocalTime
**/
STATIC CONST(Dem_DataElementOffsetType, DEM_CONST)
  Dem_DataElementOffsetDID_LocalTime[1] =
{
  0U, /* DemDataElementClass_LocalTime */
};

/** \brief Indexes of element on freeze frame data segment
** DID_ECUTemperature
**/
STATIC CONST(Dem_DataElementIdxType, DEM_CONST)
  Dem_DataElementIdxDID_ECUTemperature[1] =
{
  4U, /* DemDataElementClass_ECUTemperature */
};

/** \brief Start-bytes of element on freeze frame data segment
** DID_ECUTemperature
**/
STATIC CONST(Dem_DataElementOffsetType, DEM_CONST)
  Dem_DataElementOffsetDID_ECUTemperature[1] =
{
  0U, /* DemDataElementClass_ECUTemperature */
};

/** \brief Indexes of element on freeze frame data segment
** DID_YawrateValue
**/
STATIC CONST(Dem_DataElementIdxType, DEM_CONST)
  Dem_DataElementIdxDID_YawrateValue[1] =
{
  5U, /* DemDataElementClass_Yawrate */
};

/** \brief Start-bytes of element on freeze frame data segment
** DID_YawrateValue
**/
STATIC CONST(Dem_DataElementOffsetType, DEM_CONST)
  Dem_DataElementOffsetDID_YawrateValue[1] =
{
  0U, /* DemDataElementClass_Yawrate */
};

/** \brief Indexes of element on freeze frame data segment
** DID_EngineSpeed
**/
STATIC CONST(Dem_DataElementIdxType, DEM_CONST)
  Dem_DataElementIdxDID_EngineSpeed[1] =
{
  6U, /* DemDataElementClass_EngineSpeed */
};

/** \brief Start-bytes of element on freeze frame data segment
** DID_EngineSpeed
**/
STATIC CONST(Dem_DataElementOffsetType, DEM_CONST)
  Dem_DataElementOffsetDID_EngineSpeed[1] =
{
  0U, /* DemDataElementClass_EngineSpeed */
};

/** \brief Indexes of element on freeze frame data segment
** DID_GearPosition
**/
STATIC CONST(Dem_DataElementIdxType, DEM_CONST)
  Dem_DataElementIdxDID_GearPosition[1] =
{
  7U, /* DemDataElementClass_GearPosition */
};

/** \brief Start-bytes of element on freeze frame data segment
** DID_GearPosition
**/
STATIC CONST(Dem_DataElementOffsetType, DEM_CONST)
  Dem_DataElementOffsetDID_GearPosition[1] =
{
  0U, /* DemDataElementClass_GearPosition */
};

/** \brief Indexes of element on freeze frame data segment
** DID_SteeringAngle
**/
STATIC CONST(Dem_DataElementIdxType, DEM_CONST)
  Dem_DataElementIdxDID_SteeringAngle[1] =
{
  8U, /* DemDataElementClass_SteeringAngle */
};

/** \brief Start-bytes of element on freeze frame data segment
** DID_SteeringAngle
**/
STATIC CONST(Dem_DataElementOffsetType, DEM_CONST)
  Dem_DataElementOffsetDID_SteeringAngle[1] =
{
  0U, /* DemDataElementClass_SteeringAngle */
};

/** \brief Indexes of element on freeze frame data segment
** DID_SOCErrMap
**/
STATIC CONST(Dem_DataElementIdxType, DEM_CONST)
  Dem_DataElementIdxDID_SOCErrMap[1] =
{
  9U, /* DemDataElementClass_Extended_SystemKernelErrMap */
};

/** \brief Start-bytes of element on freeze frame data segment
** DID_SOCErrMap
**/
STATIC CONST(Dem_DataElementOffsetType, DEM_CONST)
  Dem_DataElementOffsetDID_SOCErrMap[1] =
{
  0U, /* DemDataElementClass_Extended_SystemKernelErrMap */
};

#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>

#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

/** \brief Freeze frame segments (DIDs) */
CONST(Dem_FFSegmentType, DEM_CONST)
Dem_FFSegment[DEM_NUM_FFSEGS] =
{
  /* DID_Odometer */
  {
    Dem_DataElementIdxDID_Odometer,
    Dem_DataElementOffsetDID_Odometer,
    DEM_FFS_DID_DID_Odometer,
    1U
  },
  /* DID_Voltage */
  {
    Dem_DataElementIdxDID_Voltage,
    Dem_DataElementOffsetDID_Voltage,
    DEM_FFS_DID_DID_Voltage,
    1U
  },
  /* DID_VehicleSpeed */
  {
    Dem_DataElementIdxDID_VehicleSpeed,
    Dem_DataElementOffsetDID_VehicleSpeed,
    DEM_FFS_DID_DID_VehicleSpeed,
    1U
  },
  /* DID_LocalTime */
  {
    Dem_DataElementIdxDID_LocalTime,
    Dem_DataElementOffsetDID_LocalTime,
    DEM_FFS_DID_DID_LocalTime,
    1U
  },
  /* DID_ECUTemperature */
  {
    Dem_DataElementIdxDID_ECUTemperature,
    Dem_DataElementOffsetDID_ECUTemperature,
    DEM_FFS_DID_DID_ECUTemperature,
    1U
  },
  /* DID_YawrateValue */
  {
    Dem_DataElementIdxDID_YawrateValue,
    Dem_DataElementOffsetDID_YawrateValue,
    DEM_FFS_DID_DID_YawrateValue,
    1U
  },
  /* DID_EngineSpeed */
  {
    Dem_DataElementIdxDID_EngineSpeed,
    Dem_DataElementOffsetDID_EngineSpeed,
    DEM_FFS_DID_DID_EngineSpeed,
    1U
  },
  /* DID_GearPosition */
  {
    Dem_DataElementIdxDID_GearPosition,
    Dem_DataElementOffsetDID_GearPosition,
    DEM_FFS_DID_DID_GearPosition,
    1U
  },
  /* DID_SteeringAngle */
  {
    Dem_DataElementIdxDID_SteeringAngle,
    Dem_DataElementOffsetDID_SteeringAngle,
    DEM_FFS_DID_DID_SteeringAngle,
    1U
  },
  /* DID_SOCErrMap */
  {
    Dem_DataElementIdxDID_SOCErrMap,
    Dem_DataElementOffsetDID_SOCErrMap,
    DEM_FFS_DID_DID_SOCErrMap,
    1U
  },
};

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

#define DEM_START_SEC_CALIB_16
#include <Dem_MemMap.h>

/* !LINKSTO Dem.Dem_FFSegId.Access,1 */

/*---[Freeze frame class DemFreezeFrameClass_A]---*/

/** \brief Indexes of segments on freeze frame class
** DemFreezeFrameClass_A to ::Dem_FFSegment[]
**/
DEM_STATIC CONST(Dem_FFSegIdxType, DEM_CONST)
Dem_FFSegIdxDemFreezeFrameClass_A[9] =
{
  0U, /* DID_Odometer */
  1U, /* DID_Voltage */
  2U, /* DID_VehicleSpeed */
  3U, /* DID_LocalTime */
  4U, /* DID_ECUTemperature */
  5U, /* DID_YawrateValue */
  6U, /* DID_EngineSpeed */
  7U, /* DID_GearPosition */
  8U, /* DID_SteeringAngle */
};

/*---[Freeze frame class DemFreezeFrameClass_B]---*/

/** \brief Indexes of segments on freeze frame class
** DemFreezeFrameClass_B to ::Dem_FFSegment[]
**/
DEM_STATIC CONST(Dem_FFSegIdxType, DEM_CONST)
Dem_FFSegIdxDemFreezeFrameClass_B[10] =
{
  0U, /* DID_Odometer */
  1U, /* DID_Voltage */
  2U, /* DID_VehicleSpeed */
  3U, /* DID_LocalTime */
  4U, /* DID_ECUTemperature */
  5U, /* DID_YawrateValue */
  6U, /* DID_EngineSpeed */
  7U, /* DID_GearPosition */
  8U, /* DID_SteeringAngle */
  9U, /* DID_SOCErrMap */
};

#define DEM_STOP_SEC_CALIB_16
#include <Dem_MemMap.h>

#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

/** \brief Array containing all freeze frame classes */
CONST(Dem_FFClassType, DEM_CONST)
Dem_FFClass[DEM_NUM_FFCLS] =
{
  {
    Dem_FFSegIdxDemFreezeFrameClass_A,
    9U /* number of segments */
  },
  {
    Dem_FFSegIdxDemFreezeFrameClass_B,
    10U /* number of segments */
  },
  {
    NULL_PTR,
    0U
  }
};

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

/*------------------[Freeze frame record number classes configuration]------*/

/*------------------[Extended data classes configuration]-------------------*/
#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>

/** \brief Indexes of element on extended data segment
** EXTDATAREC_0
**/
STATIC CONST(Dem_DataElementIdxType, DEM_CONST)
  Dem_DataElementIdxEXTDATAREC_0[1] =
{
  DEM_INT_VAL_IDX_AGECTRDWN,
};

/** \brief Start-bytes of element on extended data segment
** EXTDATAREC_0
**/
STATIC CONST(Dem_DataElementOffsetType, DEM_CONST)
  Dem_DataElementOffsetEXTDATAREC_0[1] =
{
  0U, /* DEM_AGINGCTR_DOWNCNT */
};

#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>

#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

/** \brief Extended data segments (Records) */
CONST(Dem_EDSegmentType, DEM_CONST) Dem_EDSegment[DEM_NUM_EDSEGS] =
{
  /* EXTDATAREC_0 */
  {
    Dem_DataElementIdxEXTDATAREC_0,
    Dem_DataElementOffsetEXTDATAREC_0,
    1U,
    DEM_EDS_NUM_EXTDATAREC_0,
    TRUE,
    FALSE, /* always available */
  },
};

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

#define DEM_START_SEC_CONST_8
#include <Dem_MemMap.h>

/*---[Extended data class DemExtendedDataClass_0]---*/

/** \brief Indexes of segments on extended data class
** DemExtendedDataClass_0 to ::Dem_EDSegment[]
**/
STATIC CONST(Dem_EDSegIdxType, DEM_CONST)
Dem_EDSegIdxDemExtendedDataClass_0[1] =
{
  0U, /* EXTDATAREC_0 */
};

#define DEM_STOP_SEC_CONST_8
#include <Dem_MemMap.h>

#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>

/** \brief Start-bytes of segments on extended data class
** DemExtendedDataClass_0
**/
STATIC CONST(Dem_EDStartByteType, DEM_CONST)
  Dem_EDStartByteDemExtendedDataClass_0[1] =
{
  0U, /* EXTDATAREC_0 */
};

#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>

#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

/** \brief Array containing all extended data classes */
CONST(Dem_EDClassType, DEM_CONST)
Dem_EDClass[DEM_NUM_EDCLS] =
{
  {
    Dem_EDSegIdxDemExtendedDataClass_0,
    Dem_EDStartByteDemExtendedDataClass_0,
    1U /* number of segments */
  },
  {
    NULL_PTR,
    NULL_PTR,
    0U
  }
};

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

/*------------------[Data element classes configuration]--------------------*/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

/** \brief Array containing all external data elements */
CONST(Dem_DataElementType, DEM_CONST)
Dem_DataElement[DEM_NUM_EXT_DATAELEMENTS] =
{
  /* elements are sorted for optimization reasons presented in design */
  /* DemDataElementClass_Odometer */
  {
    /* Deviation MISRAC2012-1 */
    {(Dem_GeneralFuncType)&Rte_Call_CBReadData_DemDataElementClass_Odometer_ReadData},
    4U,
    DEM_READ_DATA_CS_PROTOTYPE_WITH_EVENTID,
  },
  /* DemDataElementClass_Voltage */
  {
    /* Deviation MISRAC2012-1 */
    {(Dem_GeneralFuncType)&Rte_Call_CBReadData_DemDataElementClass_Voltage_ReadData},
    1U,
    DEM_READ_DATA_CS_PROTOTYPE_WITH_EVENTID,
  },
  /* DemDataElementClass_VehicleSpeed */
  {
    /* Deviation MISRAC2012-1 */
    {(Dem_GeneralFuncType)&Rte_Call_CBReadData_DemDataElementClass_VehicleSpeed_ReadData},
    2U,
    DEM_READ_DATA_CS_PROTOTYPE_WITH_EVENTID,
  },
  /* DemDataElementClass_LocalTime */
  {
    /* Deviation MISRAC2012-1 */
    {(Dem_GeneralFuncType)&Rte_Call_CBReadData_DemDataElementClass_LocalTime_ReadData},
    6U,
    DEM_READ_DATA_CS_PROTOTYPE_WITH_EVENTID,
  },
  /* DemDataElementClass_ECUTemperature */
  {
    /* Deviation MISRAC2012-1 */
    {(Dem_GeneralFuncType)&Rte_Call_CBReadData_DemDataElementClass_ECUTemperature_ReadData},
    2U,
    DEM_READ_DATA_CS_PROTOTYPE_WITH_EVENTID,
  },
  /* DemDataElementClass_Yawrate */
  {
    /* Deviation MISRAC2012-1 */
    {(Dem_GeneralFuncType)&Rte_Call_CBReadData_DemDataElementClass_Yawrate_ReadData},
    2U,
    DEM_READ_DATA_CS_PROTOTYPE_WITH_EVENTID,
  },
  /* DemDataElementClass_EngineSpeed */
  {
    /* Deviation MISRAC2012-1 */
    {(Dem_GeneralFuncType)&Rte_Call_CBReadData_DemDataElementClass_EngineSpeed_ReadData},
    2U,
    DEM_READ_DATA_CS_PROTOTYPE_WITH_EVENTID,
  },
  /* DemDataElementClass_GearPosition */
  {
    /* Deviation MISRAC2012-1 */
    {(Dem_GeneralFuncType)&Rte_Call_CBReadData_DemDataElementClass_GearPosition_ReadData},
    1U,
    DEM_READ_DATA_CS_PROTOTYPE_WITH_EVENTID,
  },
  /* DemDataElementClass_SteeringAngle */
  {
    /* Deviation MISRAC2012-1 */
    {(Dem_GeneralFuncType)&Rte_Call_CBReadData_DemDataElementClass_SteeringAngle_ReadData},
    2U,
    DEM_READ_DATA_CS_PROTOTYPE_WITH_EVENTID,
  },
  /* DemDataElementClass_Extended_SystemKernelErrMap */
  {
    /* Deviation MISRAC2012-1 */
    {(Dem_GeneralFuncType)&Rte_Call_CBReadData_DemDataElementClass_Extended_SystemKernelErrMap_ReadData},
    10U,
    DEM_READ_DATA_CS_PROTOTYPE_WITH_EVENTID,
  },
};

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

/*------------------[DTC groups configuration]------------------------------*/

#define DEM_START_SEC_CONST_32
#include <Dem_MemMap.h>
/** \brief Array containing the DTC group values */
CONST(Dem_DTCGroupType, DEM_CONST) Dem_DTCGroups[DEM_NUM_DTC_GROUPS] =
{
    DemConf_DemGroupOfDTC_DEM_DTC_GROUP_POWERTRAIN_DTCS,
  DemConf_DemGroupOfDTC_DEM_DTC_GROUP_CHASSIS_DTCS,
  DemConf_DemGroupOfDTC_DEM_DTC_GROUP_BODY_DTCS,
  DemConf_DemGroupOfDTC_DEM_DTC_GROUP_NETWORK_COM_DTCS,
};

#define DEM_STOP_SEC_CONST_32
#include <Dem_MemMap.h>

/*------------------[Events Class configuration]----------------------------*/

#define DEM_START_SEC_CALIB_UNSPECIFIED
#include <Dem_MemMap.h>


#define DEM_STOP_SEC_CALIB_UNSPECIFIED
#include <Dem_MemMap.h>

/*------------------[Events configuration]----------------------------------*/

#define DEM_START_SEC_CALIB_32
#include <Dem_MemMap.h>

/** \brief Event configuration description table (uses 'bit packing scheme) */
CONST(Dem_EventDescType, DEM_CONST) Dem_EventDesc[DEM_NUMBER_OF_EVENTS] =
{
  { 0U },                                 /* invalid event id entry */
  { /* event: MCU_E_CLOCK_FAILURE */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &83U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: MCU_E_OSC_FAILURE */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &84U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: MCU_E_SYSTEM_PLL_TIMEOUT_ERR */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &85U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: MCU_E_PERIPHERAL_PLL_TIMEOUT_ERR */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &86U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: MCU_E_SYSTEM_PLL_LOCK_LOSS */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &87U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: MCU_E_PERIPHERAL_PLL_LOCK_LOSS */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &88U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: MCU_E_GTM_CLC_ENABLE_ERR */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &89U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: MCU_E_GTM_CLC_DISABLE_ERR */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &90U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: MCU_E_CONVCTRL_CLC_ENABLE_ERR */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &91U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: MCU_E_CONVCTRL_CLC_DISABLE_ERR */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &92U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: MCU_E_CCUCON_UPDATE_ERR */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &93U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: MCU_E_CCU6_CLC_ENABLE_ERR */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &94U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: MCU_E_CCU6_CLC_DISABLE_ERR */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &95U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: MCU_E_GPT12_CLC_ENABLE_ERR */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &96U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: MCU_E_GPT12_CLC_DISABLE_ERR */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &97U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: MCU_E_PMSWCR_UPDATE_ERR */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &98U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: CANSM_BUSOFF_PublicCAN */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 0U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &99U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: SPI_E_HARDWARE_ERROR */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 1U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 71U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_VMON_BATT_HIGH */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 2U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 4U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_VMON_BATT_LOW */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 3U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 5U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_MCU_TEMP_EXT_HIGH */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 4U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 6U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_MCU_TEMP_EXT_LOW */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 5U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 7U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_SOCJ3_TEMP_EXT_HIGH */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 6U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 0U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 8U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_J3_SYS_KERNEL_SW */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 7U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 9U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: AdcClcFailureNotification */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &100U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: AdcConvStopTimeNotification */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &101U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: FEE_E_GC_INIT */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &102U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: FEE_E_WRITE */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 0U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 3U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: FEE_E_READ */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 0U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 3U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: FEE_E_GC_READ */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &103U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: FEE_E_GC_WRITE */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &104U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: FEE_E_GC_ERASE */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &105U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: FEE_E_INVALIDATE */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &106U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: FEE_E_WRITE_CYCLES_EXHAUSTED */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &107U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: FEE_E_GC_TRIG */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &108U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: FEE_E_UNCONFIG_BLK_EXCEEDED */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &109U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: FLS_E_COMPARE_FAILED */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &110U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: FLS_E_ERASE_FAILED */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &111U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: FLS_E_READ_FAILED */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &112U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: FLS_E_UNEXPECTED_FLASH_ID */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &113U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: FLS_E_WRITE_FAILED */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &114U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_CAMERA_CALIBRATION_FAILURE */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 8U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 10U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_CAMERA_ONLINE_CALIBRATION_FAILURE */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 9U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 11U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: CANSM_BUSOFF_PrivateCAN */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 10U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &115U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_VCU_Accr_Pedl_Posn_Invld */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 11U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 12U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_VCU_Gear_Posn_Invld */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 12U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 13U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_BCM_Turn_Indcr_Light_Fault */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 13U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 14U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_BCM_Frnt_Wiper_Sts_Fault */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 14U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 15U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ESP_Veh_Spd_Invld */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 15U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 16U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_Whl_Spd_Pls_Invld */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 16U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 17U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_Whl_Spd_Dir_Invld */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 17U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 18U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_Whl_Spd_Data_Invld */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 18U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 19U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_EPS_Sas_NOT_Cal */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 19U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 20U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_EPS_Actual_Motor_Torq_Invld */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 20U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 21U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ESP_Lat_Accel_Invld */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 21U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 22U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ESP_Long_Accel_Invld */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 22U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 23U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ESP_Yaw_Rate_Invld */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 23U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 24U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_EPS_Fault */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 24U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 25U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_VCU_All_Node_Missing */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 25U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 26U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ESP_All_Node_Missing */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 26U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 27U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_EPS_All_Node_Missing */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 27U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 28U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_VCU_Message_Alive_Counter_Error */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 28U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 29U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ESP_Message_Alive_Counter_Error */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 29U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 0U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_EPS_Message_Alive_Counter_Error_10ms */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 30U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 1U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_Front_Radar_Alive_Counter_Error */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 31U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 30U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ESP_ABS_Fault */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 32U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 31U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ESP_TCS_Fault */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 33U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 32U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ESP_ABA_NOT_Available */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 34U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 33U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ESP_AEB_NOT_Available */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 35U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 34U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ESP_AWB_NOT_Available */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 36U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 35U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_IB_Brk_Pedl_Invld */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 37U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 36U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_EPS_Actual_Torsion_Torq_Invld */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 38U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 37U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_EPS_Actual_Motor_Invld */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 39U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 38U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_EPS_Steer_AgSens_Fault */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 40U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 39U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_SRS_Drvr_BucSwt_Invld */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 41U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 40U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_EPS_Pinionang_Invld */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 42U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 41U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_EPS_Pinionang_Fault */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 43U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 42U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_EPS_APA_Epas_Fault */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 44U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 43U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_BCM_EmgyLi_Fault */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 45U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 44U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_BCM_All_Node_Missing */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 46U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 45U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_BCM_Message_Alive_Counter_Error_40ms */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 47U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 2U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_J3_Camera_Blockage */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 48U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 46U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_Private_CAN_Bus_Off */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 49U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 3U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 47U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_Public_CAN_Bus_Off */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 50U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 3U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 48U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_Ethernet_Unexpected_Link_Down */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 51U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 49U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_J3_SoC_ETH_IP_Ubnormal */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 52U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 50U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: ECUM_E_RAM_CHECK_FAILED */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &116U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_J3_SOC_Safetylib_Error */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 53U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 51U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_EPS_Steering_wheel_vibration_failure */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 54U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 52U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_EPS_Driver_hand_torque_invalid */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 55U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 53U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_IP_warning_invalid */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 56U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 54U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_IP_node_missing */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 57U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 55U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_IP_message_alive_counter_error */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 58U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 56U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_Fradar_not_calibration_or_blockage */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 59U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 57U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_Fradar_hardware_error */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 60U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 58U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_SRS_All_Node_Missing */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 61U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 59U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ADC_Message_Alive_Counter_Error */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 62U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 60U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_RLR_Message_Alive_Counter_Error */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 63U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 61U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_SRS_Message_Alive_Counter_Error */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 64U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 62U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_EPS_Message_Alive_Counter_Error_20ms */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 65U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 1U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_BCM_Message_Alive_Counter_Error_100ms */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 66U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 2U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_Private_CAN_Bus_Off_TOCAN */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 67U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &117U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_Public_CAN_Bus_Off_TOCAN */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 68U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &118U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_J3_Heavy_Rain_Detected */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 69U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &119U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_J3_Snow_Detected */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 70U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &120U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_J3_Low_Sun_Detected */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 71U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &121U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_J3_SOC_System_Service_Error */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 72U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 63U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_J3_Camera_Error */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 73U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 64U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_J3_SOC_CPU_Error_PWM_Missing */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 74U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 65U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_J3_SOC_Perception_Error */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 75U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 66U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ETH_CRC_ERROR */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 76U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 67U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ETH_LINK_SIGNAL_WAKE */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 77U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 68U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ETH_CABLE_FAULT */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 78U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 69U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ETH_ICMP_ERROR */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 79U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 70U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_SPI_DRIVER_ERROR */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 80U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &122U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_DFLASH_ERROR */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 81U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &123U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_BCM_Brake_Lamp_Error */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 82U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 72U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_Esp_Ebd_Failr */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 83U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 73U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_FR_All_Node_Missing */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 84U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 74U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ADC_All_Node_Missing */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage enabled */
    | ( (uint32)(DEM_ENABLEPRESTORAGE_MASK & 1U) << DEM_ENABLEPRESTORAGE_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 85U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 75U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_J3_Time_Sync_Error */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 86U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 76U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: NVM_E_INTEGRITY_FAILED */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 87U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 0U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 77U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: NVM_E_REQ_FAILED */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 88U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 0U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 78U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: NVM_E_WRONG_BLOCK_ID */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 89U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 0U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 79U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: NVM_E_VERIFY_FAILED */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 90U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 0U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 80U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: NVM_E_WRITE_PROTECTED */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 91U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 0U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 81U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_MCU_TEMP_INITIAL_HIGH */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 92U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 82U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: DEM_DTC_ESP_Message_Alive_Counter_Error_100ms */
    /* Event kind is SWC */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_COUNTERBASED) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 93U) << DEM_DEBOUNCEIDX_OFFSET )
    /* Index of enable condition group */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & 2U ) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_IGN) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK & 0U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: WDG_E_DISABLE_REJECTED */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &124U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: WDG_E_MODE_FAILED */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &125U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: SmuActivateRunStateFailureNotification */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &126U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: SmuClearAlarmStatusFailureNotification */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &127U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: SmuReleaseFSPFailureNotification */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &128U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: SmuCoreAliveFailureNotification */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &129U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: SmuRTStopFailureNotification */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &130U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: SmuActivatePESFailureNotification */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &131U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: SmuActivateFSPFailureNotification */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &132U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: SmuSetAlarmStatusFailureNotification */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &133U) << DEM_DTCCONFIDX_OFFSET )
  },
  { /* event: SmuSffFailureNotification */
    /* Event kind is BSW */
    ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Prestorage disabled */
    /* Monitor internal event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & DEM_DEBOUNCE_MONITOR) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index not used */
    /* No enable condition group referenced */
    | ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Index of dummy DTC Class */
    | ( (uint32)(DEM_DTCCONFIDX_MASK &134U) << DEM_DTCCONFIDX_OFFSET )
  },
};

#define DEM_STOP_SEC_CALIB_32
#include <Dem_MemMap.h>

#define DEM_START_SEC_CONST_32
#include <Dem_MemMap.h>

/** \brief DTC configuration description table (uses 'bit packing scheme)
 ** contains DTC related configuration data for
 **   - events without event combination
 **   - the master configuration event in case of event combination
 **   - events without DTC class (referred to by Dem_EventDesc[] entry)
 **/
CONST(Dem_DTCDescType, DEM_CONST) Dem_DTCDesc[DEM_NUMBER_OF_DTCS] =
{
  /* UDS-DTC of Master Configuration Event: DEM_DTC_ESP_Message_Alive_Counter_Error */
  {
    /* UDS-DTC value */
    0xD78386U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Master Configuration Event: DEM_DTC_EPS_Message_Alive_Counter_Error_10ms */
  {
    /* UDS-DTC value */
    0xD79086U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Master Configuration Event: DEM_DTC_BCM_Message_Alive_Counter_Error_40ms */
  {
    /* UDS-DTC value */
    0xD78786U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Master Configuration Event: FEE_E_READ */
  {
    /* UDS-DTC value */
    0xA2078AU
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_VMON_BATT_HIGH */
  {
    /* UDS-DTC value */
    0xA20017U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage enabled */
    | ( (uint32)(DEM_IMMEDIATESTORAGE_MASK & 1U) << DEM_IMMEDIATESTORAGE_OFFSET )
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* Extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_IDX_DemExtendedDataClass_0) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_VMON_BATT_LOW */
  {
    /* UDS-DTC value */
    0xA20016U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage enabled */
    | ( (uint32)(DEM_IMMEDIATESTORAGE_MASK & 1U) << DEM_IMMEDIATESTORAGE_OFFSET )
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_MCU_TEMP_EXT_HIGH */
  {
    /* UDS-DTC value */
    0xA20325U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage enabled */
    | ( (uint32)(DEM_IMMEDIATESTORAGE_MASK & 1U) << DEM_IMMEDIATESTORAGE_OFFSET )
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_MCU_TEMP_EXT_LOW */
  {
    /* UDS-DTC value */
    0xA20326U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage enabled */
    | ( (uint32)(DEM_IMMEDIATESTORAGE_MASK & 1U) << DEM_IMMEDIATESTORAGE_OFFSET )
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_SOCJ3_TEMP_EXT_HIGH */
  {
    /* UDS-DTC value */
    0xA20427U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage enabled */
    | ( (uint32)(DEM_IMMEDIATESTORAGE_MASK & 1U) << DEM_IMMEDIATESTORAGE_OFFSET )
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_B) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_J3_SYS_KERNEL_SW */
  {
    /* UDS-DTC value */
    0xA205E1U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage enabled */
    | ( (uint32)(DEM_IMMEDIATESTORAGE_MASK & 1U) << DEM_IMMEDIATESTORAGE_OFFSET )
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_B) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_CAMERA_CALIBRATION_FAILURE */
  {
    /* UDS-DTC value */
    0xA20AE1U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage enabled */
    | ( (uint32)(DEM_IMMEDIATESTORAGE_MASK & 1U) << DEM_IMMEDIATESTORAGE_OFFSET )
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_B) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_CAMERA_ONLINE_CALIBRATION_FAILURE */
  {
    /* UDS-DTC value */
    0xA20EE1U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage enabled */
    | ( (uint32)(DEM_IMMEDIATESTORAGE_MASK & 1U) << DEM_IMMEDIATESTORAGE_OFFSET )
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_B) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_VCU_Accr_Pedl_Posn_Invld */
  {
    /* UDS-DTC value */
    0xD790F0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_VCU_Gear_Posn_Invld */
  {
    /* UDS-DTC value */
    0xD791F0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_BCM_Turn_Indcr_Light_Fault */
  {
    /* UDS-DTC value */
    0xD790F1U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_BCM_Frnt_Wiper_Sts_Fault */
  {
    /* UDS-DTC value */
    0xD791F1U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_ESP_Veh_Spd_Invld */
  {
    /* UDS-DTC value */
    0xD792F0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_Whl_Spd_Pls_Invld */
  {
    /* UDS-DTC value */
    0xD793F0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_Whl_Spd_Dir_Invld */
  {
    /* UDS-DTC value */
    0xD794F0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_Whl_Spd_Data_Invld */
  {
    /* UDS-DTC value */
    0xD795F0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_EPS_Sas_NOT_Cal */
  {
    /* UDS-DTC value */
    0xD79010U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_EPS_Actual_Motor_Torq_Invld */
  {
    /* UDS-DTC value */
    0xD799F0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_ESP_Lat_Accel_Invld */
  {
    /* UDS-DTC value */
    0xD79DF0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_ESP_Long_Accel_Invld */
  {
    /* UDS-DTC value */
    0xD79EF0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_ESP_Yaw_Rate_Invld */
  {
    /* UDS-DTC value */
    0xD79FF0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_EPS_Fault */
  {
    /* UDS-DTC value */
    0xD795F1U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_VCU_All_Node_Missing */
  {
    /* UDS-DTC value */
    0xD78587U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_ESP_All_Node_Missing */
  {
    /* UDS-DTC value */
    0xD78387U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_EPS_All_Node_Missing */
  {
    /* UDS-DTC value */
    0xD78287U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_VCU_Message_Alive_Counter_Error */
  {
    /* UDS-DTC value */
    0xD78586U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_Front_Radar_Alive_Counter_Error */
  {
    /* UDS-DTC value */
    0xD78986U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_ESP_ABS_Fault */
  {
    /* UDS-DTC value */
    0xD792F1U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_ESP_TCS_Fault */
  {
    /* UDS-DTC value */
    0xD793F1U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_ESP_ABA_NOT_Available */
  {
    /* UDS-DTC value */
    0xD790F2U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_ESP_AEB_NOT_Available */
  {
    /* UDS-DTC value */
    0xD791F2U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_ESP_AWB_NOT_Available */
  {
    /* UDS-DTC value */
    0xD792F2U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_IB_Brk_Pedl_Invld */
  {
    /* UDS-DTC value */
    0xD796F0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_EPS_Actual_Torsion_Torq_Invld */
  {
    /* UDS-DTC value */
    0xD797F0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_EPS_Actual_Motor_Invld */
  {
    /* UDS-DTC value */
    0xD798F0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_EPS_Steer_AgSens_Fault */
  {
    /* UDS-DTC value */
    0xD79AF0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_SRS_Drvr_BucSwt_Invld */
  {
    /* UDS-DTC value */
    0xD79BF0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_EPS_Pinionang_Invld */
  {
    /* UDS-DTC value */
    0xD79CF0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_EPS_Pinionang_Fault */
  {
    /* UDS-DTC value */
    0xD794F1U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_EPS_APA_Epas_Fault */
  {
    /* UDS-DTC value */
    0xD796F1U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_BCM_EmgyLi_Fault */
  {
    /* UDS-DTC value */
    0xD7A0F0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_BCM_All_Node_Missing */
  {
    /* UDS-DTC value */
    0xD78487U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_J3_Camera_Blockage */
  {
    /* UDS-DTC value */
    0xA20BE1U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_B) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_Private_CAN_Bus_Off */
  {
    /* UDS-DTC value */
    0xD78088U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_Public_CAN_Bus_Off */
  {
    /* UDS-DTC value */
    0xD78188U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_Ethernet_Unexpected_Link_Down */
  {
    /* UDS-DTC value */
    0xD78887U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_B) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_J3_SoC_ETH_IP_Ubnormal */
  {
    /* UDS-DTC value */
    0xA203E0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_B) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_J3_SOC_Safetylib_Error */
  {
    /* UDS-DTC value */
    0xA204E0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_B) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_EPS_Steering_wheel_vibration_failure */
  {
    /* UDS-DTC value */
    0xD7A1F0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_EPS_Driver_hand_torque_invalid */
  {
    /* UDS-DTC value */
    0xD7A2F0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_IP_warning_invalid */
  {
    /* UDS-DTC value */
    0xD7A3F0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_IP_node_missing */
  {
    /* UDS-DTC value */
    0xD7A487U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_IP_message_alive_counter_error */
  {
    /* UDS-DTC value */
    0xD7A486U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_Fradar_not_calibration_or_blockage */
  {
    /* UDS-DTC value */
    0xD78910U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_Fradar_hardware_error */
  {
    /* UDS-DTC value */
    0xD789E0U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_SRS_All_Node_Missing */
  {
    /* UDS-DTC value */
    0xD7A987U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_ADC_Message_Alive_Counter_Error */
  {
    /* UDS-DTC value */
    0xD7A686U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_RLR_Message_Alive_Counter_Error */
  {
    /* UDS-DTC value */
    0xD7A786U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_SRS_Message_Alive_Counter_Error */
  {
    /* UDS-DTC value */
    0xD7A986U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_J3_SOC_System_Service_Error */
  {
    /* UDS-DTC value */
    0xA206E1U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_B) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_J3_Camera_Error */
  {
    /* UDS-DTC value */
    0xA207E1U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_B) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_J3_SOC_CPU_Error_PWM_Missing */
  {
    /* UDS-DTC value */
    0xA209E1U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_J3_SOC_Perception_Error */
  {
    /* UDS-DTC value */
    0xA208E1U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_B) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_ETH_CRC_ERROR */
  {
    /* UDS-DTC value */
    0xD78987U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_ETH_LINK_SIGNAL_WAKE */
  {
    /* UDS-DTC value */
    0xD78A87U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_ETH_CABLE_FAULT */
  {
    /* UDS-DTC value */
    0xD78C87U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_ETH_ICMP_ERROR */
  {
    /* UDS-DTC value */
    0xD78D87U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: SPI_E_HARDWARE_ERROR */
  {
    /* UDS-DTC value */
    0xA2068EU
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_BCM_Brake_Lamp_Error */
  {
    /* UDS-DTC value */
    0xD794F2U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_Esp_Ebd_Failr */
  {
    /* UDS-DTC value */
    0xD793F2U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_FR_All_Node_Missing */
  {
    /* UDS-DTC value */
    0xD7AA87U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_ADC_All_Node_Missing */
  {
    /* UDS-DTC value */
    0xD7AB87U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_J3_Time_Sync_Error */
  {
    /* UDS-DTC value */
    0xA210E1U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_B) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: NVM_E_INTEGRITY_FAILED */
  {
    /* UDS-DTC value */
    0xA2078BU
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: NVM_E_REQ_FAILED */
  {
    /* UDS-DTC value */
    0xA2078CU
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: NVM_E_WRONG_BLOCK_ID */
  {
    /* UDS-DTC value */
    0xA2078DU
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: NVM_E_VERIFY_FAILED */
  {
    /* UDS-DTC value */
    0xA2078EU
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: NVM_E_WRITE_PROTECTED */
  {
    /* UDS-DTC value */
    0xA2078FU
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_MCU_TEMP_INITIAL_HIGH */
  {
    /* UDS-DTC value */
    0xA20327U
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & 0U) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* Group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NETWORK_COM_DTCS) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: MCU_E_CLOCK_FAILURE */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: MCU_E_OSC_FAILURE */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: MCU_E_SYSTEM_PLL_TIMEOUT_ERR */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: MCU_E_PERIPHERAL_PLL_TIMEOUT_ERR */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: MCU_E_SYSTEM_PLL_LOCK_LOSS */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: MCU_E_PERIPHERAL_PLL_LOCK_LOSS */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: MCU_E_GTM_CLC_ENABLE_ERR */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: MCU_E_GTM_CLC_DISABLE_ERR */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: MCU_E_CONVCTRL_CLC_ENABLE_ERR */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: MCU_E_CONVCTRL_CLC_DISABLE_ERR */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: MCU_E_CCUCON_UPDATE_ERR */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: MCU_E_CCU6_CLC_ENABLE_ERR */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: MCU_E_CCU6_CLC_DISABLE_ERR */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: MCU_E_GPT12_CLC_ENABLE_ERR */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: MCU_E_GPT12_CLC_DISABLE_ERR */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: MCU_E_PMSWCR_UPDATE_ERR */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: CANSM_BUSOFF_PublicCAN */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: AdcClcFailureNotification */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: AdcConvStopTimeNotification */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: FEE_E_GC_INIT */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: FEE_E_GC_READ */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: FEE_E_GC_WRITE */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: FEE_E_GC_ERASE */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: FEE_E_INVALIDATE */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: FEE_E_WRITE_CYCLES_EXHAUSTED */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: FEE_E_GC_TRIG */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: FEE_E_UNCONFIG_BLK_EXCEEDED */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: FLS_E_COMPARE_FAILED */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: FLS_E_ERASE_FAILED */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: FLS_E_READ_FAILED */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: FLS_E_UNEXPECTED_FLASH_ID */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: FLS_E_WRITE_FAILED */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: CANSM_BUSOFF_PrivateCAN */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* Freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_IDX_DemFreezeFrameClass_A) << DEM_FFCLASSIDX_OFFSET)
    /* Maximal number of freeze frames */
    | ( (uint32)(DEM_FFRECINFO_MASK & 3U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: ECUM_E_RAM_CHECK_FAILED */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_Private_CAN_Bus_Off_TOCAN */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_Public_CAN_Bus_Off_TOCAN */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_J3_Heavy_Rain_Detected */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_J3_Snow_Detected */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_J3_Low_Sun_Detected */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_SPI_DRIVER_ERROR */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: DEM_DTC_DFLASH_ERROR */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Limit of DTC aging cycles */
    | ( (uint32)(DEM_AGINGCTRTHRESHOLD_MASK & 40U) << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: WDG_E_DISABLE_REJECTED */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: WDG_E_MODE_FAILED */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: SmuActivateRunStateFailureNotification */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: SmuClearAlarmStatusFailureNotification */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: SmuReleaseFSPFailureNotification */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: SmuCoreAliveFailureNotification */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: SmuRTStopFailureNotification */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: SmuActivatePESFailureNotification */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: SmuActivateFSPFailureNotification */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: SmuSetAlarmStatusFailureNotification */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
  /* UDS-DTC of Event: SmuSffFailureNotification */
  {
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Immediate storage disabled */
    ,
    /* Internal event priority (0 = most important) */
    ( (uint32)(DEM_PRIORITY_MASK & 0U) << DEM_PRIORITY_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No DTC Functional Unit */
    | ( (DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    /* DTC Significance */
    | ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
  },
};

#define DEM_STOP_SEC_CONST_32
#include <Dem_MemMap.h>

#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>
CONST(Dem_CmbDTCEvLnkType, DEM_CONST) Dem_CmbDTCEvLnk[DEM_NUM_CMB_DTCS + 1U] =
{
  0U,
  2U,
  4U,
  6U,
  8U,
};

CONST(Dem_EventIdType, DEM_CONST) Dem_CmbDTCEvents[DEM_NUM_CMB_EVENTS] =
{
  /* Next group of combined events assigned to DemDTCClassRef = DTC_D78386 */
  DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error,
  DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error_100ms,
  /* Next group of combined events assigned to DemDTCClassRef = DTC_D79086 */
  DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_10ms,
  DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_20ms,
  /* Next group of combined events assigned to DemDTCClassRef = DTC_D78786 */
  DemConf_DemEventParameter_DEM_DTC_BCM_Message_Alive_Counter_Error_40ms,
  DemConf_DemEventParameter_DEM_DTC_BCM_Message_Alive_Counter_Error_100ms,
  /* Next group of combined events assigned to DemDTCClassRef = DTC_A2078A */
  DemConf_DemEventParameter_FEE_E_READ,
  DemConf_DemEventParameter_FEE_E_WRITE,
};
#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>

#define DEM_START_SEC_CONST_8
#include <Dem_MemMap.h>

CONST(Dem_PriorityType, DEM_CONST) Dem_ExternalPrioValue[DEM_NUM_EVENT_PRIORITIES] =
{
  (uint8)1U,
};

#define DEM_STOP_SEC_CONST_8
#include <Dem_MemMap.h>


#define DEM_START_SEC_CONST_8
#include <Dem_MemMap.h>
#if (DEM_STATUS_BIT_STORAGE_TF_PER_EVENT_SUPPORT == STD_ON)
/** \brief Generate the const array Dem_StatusBitStorageTF[],
 ** only if not all configured events do have the same
 ** DemStatusBitStorageTestFailedPerEvent value. */
CONST(uint8, DEM_CONST) Dem_StatusBitStorageTF[DEM_STATUS_BIT_STORAGE_TF_ARRAY_SIZE] =
{
  0x00U,
  0x00U,
  0x00U,
  0x00U,
  0x00U,
  0x00U,
  0x00U,
  0x00U,
  0x00U,
  0x00U,
  0x00U,
  0x00U,
  0x00U,
  0x00U,
  0x00U,
  0x00U,
  0x00U,
  0x00U
};
#endif

#define DEM_STOP_SEC_CONST_8
#include <Dem_MemMap.h>




/*------------------[Enable conditions configuration]-----------------------*/

#define DEM_START_SEC_VAR_INIT_8
#include <Dem_MemMap.h>

/** \brief Enable condition status */
VAR(boolean, DEM_VAR) Dem_EnCondStatus[DEM_NUM_ENABLECONDITIONS] =
{
  TRUE,  /* condition name: CONDITION_Voltage_Normal */
  TRUE,  /* condition name: CONDITION_PowerON_3000ms */
  TRUE,  /* condition name: CONDITION_Voltage_InRange */
  TRUE,  /* condition name: CONDITION_NO_BUSOFF_PublicCAN */
  TRUE,  /* condition name: CONDITION_NO_BUSOFF_PrivateCAN */
  TRUE,  /* condition name: CONDITION_BcmPwrStsFbON */
  TRUE,  /* condition name: CONDITION_EspVehSpd */
};

/** \brief Enable condition group status counter array,
 **   holds the status counters per enable condition group, that counts how
 **   many enable conditions, that are linked to the dedicated condition
 **   group are enabled/disabled. (max. 256 conditions per group) */
VAR(Dem_EnCondGrpStatusCounterType, DEM_VAR)
  Dem_EnCondGrpStatusCounter[DEM_NUM_ENCONDGROUPS + 1U] =
{
  0U, /* group counter: CONDITION_GROUP_Voltage_Normal */
  0U, /* group counter: CONDITION_GROUP_PubCAN_Base_Normal */
  0U, /* group counter: CONDITION_GROUP_BcmPwrStsFb_ON */
  0U, /* group counter: CONDITION_GROUP_FOR_BUSOFF */
  0U  /* Dummy entry for internal processing */
};
#define DEM_STOP_SEC_VAR_INIT_8
#include <Dem_MemMap.h>

#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>

/** \brief Enable condition link array,
 ** holds the start indexes of Dem_EnCondGrpLink[] */
CONST(Dem_EnCondLnkType, DEM_CONST) Dem_EnCondToEvIdLink[DEM_NUM_ENABLECONDITIONS + 1U] =
{
  0U, /* start index, CONDITION_Voltage_Normal */
  2U, /* start index, CONDITION_PowerON_3000ms */
  5U, /* start index, CONDITION_Voltage_InRange */
  6U, /* start index, CONDITION_NO_BUSOFF_PublicCAN */
  7U, /* start index, CONDITION_NO_BUSOFF_PrivateCAN */
  7U, /* start index, CONDITION_BcmPwrStsFbON */
  9U, /* start index, CONDITION_EspVehSpd */
  9U, /* dummy entry, for internal processing */
};

#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>

#define DEM_START_SEC_CONST_8
#include <Dem_MemMap.h>

/** \brief Enable condition group status counter link array,
 ** holds the indexes of Dem_EnCondGrpStatusCounter[]. One enable condition
 ** can refer to several condition group status counters. */
CONST(Dem_EnCondGrpType, DEM_CONST)
  Dem_EnCondGrpLink[DEM_NUM_ENCONDGRP_LINKS] =
{
  0U, /* group: CONDITION_GROUP_Voltage_Normal, condition: CONDITION_Voltage_Normal */
  3U, /* group: CONDITION_GROUP_FOR_BUSOFF, condition: CONDITION_Voltage_Normal */
  0U, /* group: CONDITION_GROUP_Voltage_Normal, condition: CONDITION_PowerON_3000ms */
  1U, /* group: CONDITION_GROUP_PubCAN_Base_Normal, condition: CONDITION_PowerON_3000ms */
  3U, /* group: CONDITION_GROUP_FOR_BUSOFF, condition: CONDITION_PowerON_3000ms */
  1U, /* group: CONDITION_GROUP_PubCAN_Base_Normal, condition: CONDITION_Voltage_InRange */
  1U, /* group: CONDITION_GROUP_PubCAN_Base_Normal, condition: CONDITION_NO_BUSOFF_PublicCAN */
  2U, /* group: CONDITION_GROUP_BcmPwrStsFb_ON, condition: CONDITION_BcmPwrStsFbON */
  3U, /* group: CONDITION_GROUP_FOR_BUSOFF, condition: CONDITION_BcmPwrStsFbON */
};

#define DEM_STOP_SEC_CONST_8
#include <Dem_MemMap.h>

/*------------------[Multi event triggering configuration]------------------*/


/*------------------[Warning indicators configuration]----------------------*/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>




#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

#define DEM_START_SEC_CONST_8
#include <Dem_MemMap.h>



#define DEM_STOP_SEC_CONST_8
#include <Dem_MemMap.h>


/*------------------[Debouncing configuration]------------------------------*/

/** \brief Counter based debouncing configuration description table */
#define DEM_START_SEC_CALIB_16
#include <Dem_MemMap.h>


CONST(Dem_DebounceCounterClassType, DEM_CONST)
  Dem_DebounceCounterClass[DEM_NUM_DEBOUNCE_COUNTER_CLASSES] =
{
  { /* 0 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -128, /* DemDebounceCounterPassedThreshold */
    1, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    FALSE, /* DemDebounceCounterJumpDown */
    FALSE, /* DemDebounceCounterJumpUp */
  },
  { /* 1 */
    13U, /* DemDebounceCounterDecrementStepSize */
    13U, /* DemDebounceCounterIncrementStepSize */
    -128, /* DemDebounceCounterPassedThreshold */
    127, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    FALSE, /* DemDebounceCounterJumpDown */
    FALSE, /* DemDebounceCounterJumpUp */
  },
  { /* 2 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -50, /* DemDebounceCounterPassedThreshold */
    50, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 3 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -1, /* DemDebounceCounterPassedThreshold */
    1, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 4 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -1, /* DemDebounceCounterPassedThreshold */
    10, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 5 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -1, /* DemDebounceCounterPassedThreshold */
    10, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    FALSE, /* DemDebounceCounterJumpDown */
    FALSE, /* DemDebounceCounterJumpUp */
  },
  { /* 6 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -1, /* DemDebounceCounterPassedThreshold */
    40, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 7 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -1, /* DemDebounceCounterPassedThreshold */
    100, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 8 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -1, /* DemDebounceCounterPassedThreshold */
    250, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 9 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -1, /* DemDebounceCounterPassedThreshold */
    20, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 10 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -1, /* DemDebounceCounterPassedThreshold */
    30000, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 11 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -1, /* DemDebounceCounterPassedThreshold */
    5, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 12 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -1, /* DemDebounceCounterPassedThreshold */
    50, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 13 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -1, /* DemDebounceCounterPassedThreshold */
    300, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 14 */
    128U, /* DemDebounceCounterDecrementStepSize */
    128U, /* DemDebounceCounterIncrementStepSize */
    -128, /* DemDebounceCounterPassedThreshold */
    127, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    FALSE, /* DemDebounceCounterJumpDown */
    FALSE, /* DemDebounceCounterJumpUp */
  },
};

/** \brief Counter based debouncing class index table */
CONST(Dem_DebounceCounterClassIdxType, DEM_CONST)
  Dem_DebounceCounterClassIdx[DEM_NUM_DEBOUNCE_COUNTER] =
{
  0U, /* 17 */
  1U, /* 18 */
  2U, /* 19 */
  2U, /* 20 */
  3U, /* 21 */
  3U, /* 22 */
  3U, /* 23 */
  3U, /* 24 */
  4U, /* 42 */
  4U, /* 43 */
  5U, /* 44 */
  4U, /* 45 */
  4U, /* 46 */
  6U, /* 47 */
  6U, /* 48 */
  4U, /* 49 */
  4U, /* 50 */
  4U, /* 51 */
  4U, /* 52 */
  4U, /* 53 */
  4U, /* 54 */
  4U, /* 55 */
  4U, /* 56 */
  4U, /* 57 */
  4U, /* 58 */
  3U, /* 59 */
  3U, /* 60 */
  3U, /* 61 */
  4U, /* 62 */
  4U, /* 63 */
  4U, /* 64 */
  7U, /* 65 */
  4U, /* 66 */
  4U, /* 67 */
  4U, /* 68 */
  4U, /* 69 */
  4U, /* 70 */
  4U, /* 71 */
  4U, /* 72 */
  4U, /* 73 */
  4U, /* 74 */
  8U, /* 75 */
  4U, /* 76 */
  9U, /* 77 */
  9U, /* 78 */
  6U, /* 79 */
  3U, /* 80 */
  7U, /* 81 */
  10U, /* 82 */
  11U, /* 83 */
  11U, /* 84 */
  4U, /* 85 */
  3U, /* 86 */
  3U, /* 88 */
  9U, /* 89 */
  4U, /* 90 */
  12U, /* 91 */
  3U, /* 92 */
  7U, /* 93 */
  12U, /* 94 */
  12U, /* 95 */
  3U, /* 96 */
  7U, /* 97 */
  7U, /* 98 */
  7U, /* 99 */
  9U, /* 100 */
  7U, /* 101 */
  11U, /* 102 */
  11U, /* 103 */
  3U, /* 104 */
  3U, /* 105 */
  3U, /* 106 */
  3U, /* 107 */
  3U, /* 108 */
  3U, /* 109 */
  3U, /* 110 */
  3U, /* 111 */
  3U, /* 112 */
  3U, /* 113 */
  3U, /* 114 */
  3U, /* 115 */
  3U, /* 116 */
  6U, /* 117 */
  4U, /* 118 */
  3U, /* 119 */
  3U, /* 120 */
  13U, /* 121 */
  14U, /* 122 */
  14U, /* 123 */
  14U, /* 124 */
  14U, /* 125 */
  14U, /* 126 */
  3U, /* 127 */
  7U, /* 128 */
};

#define DEM_STOP_SEC_CALIB_16
#include <Dem_MemMap.h>

/** \brief Time based debouncing configuration description table */
/* !LINKSTO Dem.Calibration.DemTimeBasedDebounceClassConcept,1 */
/* none */

#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>

/** \brief Time based debouncing configuration description table */
/* none */

/** \brief Frequency based debouncing configuration description table */
/* none */

#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>

/*------------------[Fault confirmation configuration]----------------------*/

/* none */


/*------------------[ Event Availability ]------------------------*/

#define DEM_START_SEC_CALIB_8
#include <Dem_MemMap.h>


#define DEM_STOP_SEC_CALIB_8
#include <Dem_MemMap.h>

/*------------------[RTE / C-callback notifications]------------------------*/

#define DEM_START_SEC_CONST_8
#include <Dem_MemMap.h>

/** \brief Event callback property table */
CONST(Dem_CbPropertyType, DEM_CONST) Dem_CbProperty[DEM_NUMBER_OF_EVENTS] =
{
  0U,
  /* invalid event id entry */
  /* event: MCU_E_CLOCK_FAILURE */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: MCU_E_OSC_FAILURE */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: MCU_E_SYSTEM_PLL_TIMEOUT_ERR */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: MCU_E_PERIPHERAL_PLL_TIMEOUT_ERR */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: MCU_E_SYSTEM_PLL_LOCK_LOSS */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: MCU_E_PERIPHERAL_PLL_LOCK_LOSS */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: MCU_E_GTM_CLC_ENABLE_ERR */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: MCU_E_GTM_CLC_DISABLE_ERR */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: MCU_E_CONVCTRL_CLC_ENABLE_ERR */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: MCU_E_CONVCTRL_CLC_DISABLE_ERR */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: MCU_E_CCUCON_UPDATE_ERR */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: MCU_E_CCU6_CLC_ENABLE_ERR */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: MCU_E_CCU6_CLC_DISABLE_ERR */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: MCU_E_GPT12_CLC_ENABLE_ERR */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: MCU_E_GPT12_CLC_DISABLE_ERR */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: MCU_E_PMSWCR_UPDATE_ERR */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: CANSM_BUSOFF_PublicCAN */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: SPI_E_HARDWARE_ERROR */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_VMON_BATT_HIGH */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_VMON_BATT_LOW */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_MCU_TEMP_EXT_HIGH */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_MCU_TEMP_EXT_LOW */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_SOCJ3_TEMP_EXT_HIGH */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_J3_SYS_KERNEL_SW */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: AdcClcFailureNotification */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: AdcConvStopTimeNotification */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: FEE_E_GC_INIT */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: FEE_E_WRITE */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: FEE_E_READ */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: FEE_E_GC_READ */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: FEE_E_GC_WRITE */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: FEE_E_GC_ERASE */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: FEE_E_INVALIDATE */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: FEE_E_WRITE_CYCLES_EXHAUSTED */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: FEE_E_GC_TRIG */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: FEE_E_UNCONFIG_BLK_EXCEEDED */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: FLS_E_COMPARE_FAILED */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: FLS_E_ERASE_FAILED */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: FLS_E_READ_FAILED */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: FLS_E_UNEXPECTED_FLASH_ID */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: FLS_E_WRITE_FAILED */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: DEM_CAMERA_CALIBRATION_FAILURE */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_CAMERA_ONLINE_CALIBRATION_FAILURE */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: CANSM_BUSOFF_PrivateCAN */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_VCU_Accr_Pedl_Posn_Invld */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_VCU_Gear_Posn_Invld */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_BCM_Turn_Indcr_Light_Fault */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_BCM_Frnt_Wiper_Sts_Fault */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ESP_Veh_Spd_Invld */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_Whl_Spd_Pls_Invld */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_Whl_Spd_Dir_Invld */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_Whl_Spd_Data_Invld */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_EPS_Sas_NOT_Cal */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_EPS_Actual_Motor_Torq_Invld */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ESP_Lat_Accel_Invld */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ESP_Long_Accel_Invld */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ESP_Yaw_Rate_Invld */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_EPS_Fault */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_VCU_All_Node_Missing */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ESP_All_Node_Missing */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_EPS_All_Node_Missing */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_VCU_Message_Alive_Counter_Error */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ESP_Message_Alive_Counter_Error */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_EPS_Message_Alive_Counter_Error_10ms */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_Front_Radar_Alive_Counter_Error */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ESP_ABS_Fault */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ESP_TCS_Fault */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ESP_ABA_NOT_Available */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ESP_AEB_NOT_Available */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ESP_AWB_NOT_Available */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_IB_Brk_Pedl_Invld */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_EPS_Actual_Torsion_Torq_Invld */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_EPS_Actual_Motor_Invld */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_EPS_Steer_AgSens_Fault */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_SRS_Drvr_BucSwt_Invld */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_EPS_Pinionang_Invld */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_EPS_Pinionang_Fault */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_EPS_APA_Epas_Fault */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_BCM_EmgyLi_Fault */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_BCM_All_Node_Missing */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_BCM_Message_Alive_Counter_Error_40ms */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_J3_Camera_Blockage */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_Private_CAN_Bus_Off */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_Public_CAN_Bus_Off */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_Ethernet_Unexpected_Link_Down */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_J3_SoC_ETH_IP_Ubnormal */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: ECUM_E_RAM_CHECK_FAILED */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: DEM_DTC_J3_SOC_Safetylib_Error */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_EPS_Steering_wheel_vibration_failure */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_EPS_Driver_hand_torque_invalid */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_IP_warning_invalid */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_IP_node_missing */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_IP_message_alive_counter_error */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_Fradar_not_calibration_or_blockage */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_Fradar_hardware_error */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_SRS_All_Node_Missing */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ADC_Message_Alive_Counter_Error */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_RLR_Message_Alive_Counter_Error */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_SRS_Message_Alive_Counter_Error */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_EPS_Message_Alive_Counter_Error_20ms */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_BCM_Message_Alive_Counter_Error_100ms */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_Private_CAN_Bus_Off_TOCAN */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_Public_CAN_Bus_Off_TOCAN */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_J3_Heavy_Rain_Detected */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_J3_Snow_Detected */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_J3_Low_Sun_Detected */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_J3_SOC_System_Service_Error */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_J3_Camera_Error */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_J3_SOC_CPU_Error_PWM_Missing */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_J3_SOC_Perception_Error */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ETH_CRC_ERROR */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ETH_LINK_SIGNAL_WAKE */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ETH_CABLE_FAULT */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ETH_ICMP_ERROR */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_SPI_DRIVER_ERROR */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_DFLASH_ERROR */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_BCM_Brake_Lamp_Error */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_Esp_Ebd_Failr */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_FR_All_Node_Missing */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ADC_All_Node_Missing */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_J3_Time_Sync_Error */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: NVM_E_INTEGRITY_FAILED */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: NVM_E_REQ_FAILED */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: NVM_E_WRONG_BLOCK_ID */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: NVM_E_VERIFY_FAILED */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: NVM_E_WRITE_PROTECTED */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_MCU_TEMP_INITIAL_HIGH */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: DEM_DTC_ESP_Message_Alive_Counter_Error_100ms */
  /* no init monitor callback */
DEM_RTE_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: WDG_E_DISABLE_REJECTED */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: WDG_E_MODE_FAILED */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: SmuActivateRunStateFailureNotification */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: SmuClearAlarmStatusFailureNotification */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: SmuReleaseFSPFailureNotification */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: SmuCoreAliveFailureNotification */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: SmuRTStopFailureNotification */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: SmuActivatePESFailureNotification */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: SmuActivateFSPFailureNotification */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: SmuSetAlarmStatusFailureNotification */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
  /* event: SmuSffFailureNotification */
  /* no init monitor callback */
  /* no trigger on event status callback(s) */
  /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* no fault detection counter callback */
  DEM_ZERO_END,
};
/*---------------[Operation cycle automatic end enabled masks]-------------*/

#define DEM_STOP_SEC_CONST_8
#include <Dem_MemMap.h>

/*---[INIT_MONITOR]---*/

#if (DEM_CB_TABLE_INIT_MONITOR_SIZE != 0U)
#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

/** \brief Generic callback function pointer table for InitMonitor */
CONST(Dem_CbFuncPtrInitMonitorType, DEM_CONST)
  Dem_CbFuncPtrInitMonitor[DEM_CB_TABLE_INIT_MONITOR_SIZE] =
{
};

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>
#endif

#if (DEM_LOOKUP_TABLE_INIT_MONITOR_SIZE != 0U)
#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>

/** \brief Generic lookup table for InitMonitor */
CONST(Dem_EventIdType, DEM_CONST)
  Dem_CbLookupTableInitMonitor[DEM_LOOKUP_TABLE_INIT_MONITOR_SIZE] =
{
};

#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>
#endif

/*---[TRIGGER_ON_EVENT_STATUS]---*/

#if (DEM_C_CALLBACK_TABLE_TRIG_ON_EVST_SIZE != 0U)
#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

/** \brief C-Callback function pointer table for TriggerOnEventStatus */
CONST(Dem_CbFuncPtrTrigOnEvStType, DEM_CONST)
  Dem_CbFuncPtrTrigOnEvSt[DEM_C_CALLBACK_TABLE_TRIG_ON_EVST_SIZE] =
{
};

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>
#endif

#if (DEM_C_LOOKUP_TABLE_TRIG_ON_EVST_SIZE != 0U)
#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>

/** \brief C-Lookup table for TriggerOnEventStatus */
CONST(Dem_CbLookupTableType, DEM_CONST)
  Dem_CbLookupTableTrigOnEvSt[DEM_C_LOOKUP_TABLE_TRIG_ON_EVST_SIZE] =
{
};

#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>
#endif

#if (DEM_RTE_CALLBACK_TABLE_TRIG_ON_EVST_SIZE != 0U)
#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

/** \brief RTE-Callback function pointer table
** for TriggerOnEventStatus
**/
CONST(Dem_RteFuncPtrTrigOnEvStType, DEM_CONST)
  Dem_RteFuncPtrTrigOnEvSt[DEM_RTE_CALLBACK_TABLE_TRIG_ON_EVST_SIZE] =
{
  &Rte_Call_CBStatusEvt_SPI_E_HARDWARE_ERROR_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_VMON_BATT_HIGH_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_VMON_BATT_LOW_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_MCU_TEMP_EXT_HIGH_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_MCU_TEMP_EXT_LOW_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_SOCJ3_TEMP_EXT_HIGH_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_J3_SYS_KERNEL_SW_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_CAMERA_CALIBRATION_FAILURE_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_VCU_Accr_Pedl_Posn_Invld_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_VCU_Gear_Posn_Invld_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_BCM_Turn_Indcr_Light_Fault_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_BCM_Frnt_Wiper_Sts_Fault_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_ESP_Veh_Spd_Invld_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_Whl_Spd_Pls_Invld_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_Whl_Spd_Dir_Invld_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_Whl_Spd_Data_Invld_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_EPS_Sas_NOT_Cal_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_EPS_Actual_Motor_Torq_Invld_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_ESP_Lat_Accel_Invld_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_ESP_Long_Accel_Invld_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_ESP_Yaw_Rate_Invld_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_EPS_Fault_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_VCU_All_Node_Missing_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_ESP_All_Node_Missing_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_EPS_All_Node_Missing_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_VCU_Message_Alive_Counter_Error_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_ESP_Message_Alive_Counter_Error_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_EPS_Message_Alive_Counter_Error_10ms_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_Front_Radar_Alive_Counter_Error_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_ESP_ABS_Fault_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_ESP_TCS_Fault_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_ESP_ABA_NOT_Available_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_ESP_AEB_NOT_Available_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_ESP_AWB_NOT_Available_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_IB_Brk_Pedl_Invld_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_EPS_Actual_Torsion_Torq_Invld_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_EPS_Actual_Motor_Invld_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_EPS_Steer_AgSens_Fault_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_SRS_Drvr_BucSwt_Invld_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_EPS_Pinionang_Invld_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_EPS_Pinionang_Fault_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_EPS_APA_Epas_Fault_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_BCM_EmgyLi_Fault_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_BCM_All_Node_Missing_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_BCM_Message_Alive_Counter_Error_40ms_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_J3_Camera_Blockage_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_Private_CAN_Bus_Off_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_Public_CAN_Bus_Off_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_J3_SOC_Safetylib_Error_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_EPS_Steering_wheel_vibration_failure_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_EPS_Driver_hand_torque_invalid_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_IP_warning_invalid_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_IP_node_missing_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_IP_message_alive_counter_error_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_Fradar_not_calibration_or_blockage_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_Fradar_hardware_error_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_SRS_All_Node_Missing_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_ADC_Message_Alive_Counter_Error_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_RLR_Message_Alive_Counter_Error_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_SRS_Message_Alive_Counter_Error_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_EPS_Message_Alive_Counter_Error_20ms_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_J3_SOC_System_Service_Error_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_J3_Camera_Error_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_J3_SOC_CPU_Error_PWM_Missing_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_J3_SOC_Perception_Error_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_BCM_Brake_Lamp_Error_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_Esp_Ebd_Failr_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_FR_All_Node_Missing_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_ADC_All_Node_Missing_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_J3_Time_Sync_Error_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_MCU_TEMP_INITIAL_HIGH_1_EventStatusChanged,
  &Rte_Call_CBStatusEvt_DEM_DTC_ESP_Message_Alive_Counter_Error_100ms_1_EventStatusChanged,
};

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>
#endif

#if (DEM_RTE_LOOKUP_TABLE_TRIG_ON_EVST_SIZE != 0U)
#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>

/** \brief RTE-Lookup table for TriggerOnEventStatus */
CONST(Dem_EventIdType, DEM_CONST)
  Dem_RteLookupTableTrigOnEvSt[DEM_RTE_LOOKUP_TABLE_TRIG_ON_EVST_SIZE] =
{
  DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR,
  DemConf_DemEventParameter_DEM_VMON_BATT_HIGH,
  DemConf_DemEventParameter_DEM_VMON_BATT_LOW,
  DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_HIGH,
  DemConf_DemEventParameter_DEM_MCU_TEMP_EXT_LOW,
  DemConf_DemEventParameter_DEM_SOCJ3_TEMP_EXT_HIGH,
  DemConf_DemEventParameter_DEM_J3_SYS_KERNEL_SW,
  DemConf_DemEventParameter_DEM_CAMERA_CALIBRATION_FAILURE,
  DemConf_DemEventParameter_DEM_CAMERA_ONLINE_CALIBRATION_FAILURE,
  DemConf_DemEventParameter_DEM_DTC_VCU_Accr_Pedl_Posn_Invld,
  DemConf_DemEventParameter_DEM_DTC_VCU_Gear_Posn_Invld,
  DemConf_DemEventParameter_DEM_DTC_BCM_Turn_Indcr_Light_Fault,
  DemConf_DemEventParameter_DEM_DTC_BCM_Frnt_Wiper_Sts_Fault,
  DemConf_DemEventParameter_DEM_DTC_ESP_Veh_Spd_Invld,
  DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Pls_Invld,
  DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Dir_Invld,
  DemConf_DemEventParameter_DEM_DTC_Whl_Spd_Data_Invld,
  DemConf_DemEventParameter_DEM_DTC_EPS_Sas_NOT_Cal,
  DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Torq_Invld,
  DemConf_DemEventParameter_DEM_DTC_ESP_Lat_Accel_Invld,
  DemConf_DemEventParameter_DEM_DTC_ESP_Long_Accel_Invld,
  DemConf_DemEventParameter_DEM_DTC_ESP_Yaw_Rate_Invld,
  DemConf_DemEventParameter_DEM_DTC_EPS_Fault,
  DemConf_DemEventParameter_DEM_DTC_VCU_All_Node_Missing,
  DemConf_DemEventParameter_DEM_DTC_ESP_All_Node_Missing,
  DemConf_DemEventParameter_DEM_DTC_EPS_All_Node_Missing,
  DemConf_DemEventParameter_DEM_DTC_VCU_Message_Alive_Counter_Error,
  DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error,
  DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_10ms,
  DemConf_DemEventParameter_DEM_DTC_Front_Radar_Alive_Counter_Error,
  DemConf_DemEventParameter_DEM_DTC_ESP_ABS_Fault,
  DemConf_DemEventParameter_DEM_DTC_ESP_TCS_Fault,
  DemConf_DemEventParameter_DEM_DTC_ESP_ABA_NOT_Available,
  DemConf_DemEventParameter_DEM_DTC_ESP_AEB_NOT_Available,
  DemConf_DemEventParameter_DEM_DTC_ESP_AWB_NOT_Available,
  DemConf_DemEventParameter_DEM_DTC_IB_Brk_Pedl_Invld,
  DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Torsion_Torq_Invld,
  DemConf_DemEventParameter_DEM_DTC_EPS_Actual_Motor_Invld,
  DemConf_DemEventParameter_DEM_DTC_EPS_Steer_AgSens_Fault,
  DemConf_DemEventParameter_DEM_DTC_SRS_Drvr_BucSwt_Invld,
  DemConf_DemEventParameter_DEM_DTC_EPS_Pinionang_Invld,
  DemConf_DemEventParameter_DEM_DTC_EPS_Pinionang_Fault,
  DemConf_DemEventParameter_DEM_DTC_EPS_APA_Epas_Fault,
  DemConf_DemEventParameter_DEM_DTC_BCM_EmgyLi_Fault,
  DemConf_DemEventParameter_DEM_DTC_BCM_All_Node_Missing,
  DemConf_DemEventParameter_DEM_DTC_BCM_Message_Alive_Counter_Error_40ms,
  DemConf_DemEventParameter_DEM_DTC_J3_Camera_Blockage,
  DemConf_DemEventParameter_DEM_DTC_Private_CAN_Bus_Off,
  DemConf_DemEventParameter_DEM_DTC_Public_CAN_Bus_Off,
  DemConf_DemEventParameter_DEM_DTC_J3_SOC_Safetylib_Error,
  DemConf_DemEventParameter_DEM_DTC_EPS_Steering_wheel_vibration_failure,
  DemConf_DemEventParameter_DEM_DTC_EPS_Driver_hand_torque_invalid,
  DemConf_DemEventParameter_DEM_DTC_IP_warning_invalid,
  DemConf_DemEventParameter_DEM_DTC_IP_node_missing,
  DemConf_DemEventParameter_DEM_DTC_IP_message_alive_counter_error,
  DemConf_DemEventParameter_DEM_DTC_Fradar_not_calibration_or_blockage,
  DemConf_DemEventParameter_DEM_DTC_Fradar_hardware_error,
  DemConf_DemEventParameter_DEM_DTC_SRS_All_Node_Missing,
  DemConf_DemEventParameter_DEM_DTC_ADC_Message_Alive_Counter_Error,
  DemConf_DemEventParameter_DEM_DTC_RLR_Message_Alive_Counter_Error,
  DemConf_DemEventParameter_DEM_DTC_SRS_Message_Alive_Counter_Error,
  DemConf_DemEventParameter_DEM_DTC_EPS_Message_Alive_Counter_Error_20ms,
  DemConf_DemEventParameter_DEM_DTC_J3_SOC_System_Service_Error,
  DemConf_DemEventParameter_DEM_DTC_J3_Camera_Error,
  DemConf_DemEventParameter_DEM_DTC_J3_SOC_CPU_Error_PWM_Missing,
  DemConf_DemEventParameter_DEM_DTC_J3_SOC_Perception_Error,
  DemConf_DemEventParameter_DEM_DTC_BCM_Brake_Lamp_Error,
  DemConf_DemEventParameter_DEM_DTC_Esp_Ebd_Failr,
  DemConf_DemEventParameter_DEM_DTC_FR_All_Node_Missing,
  DemConf_DemEventParameter_DEM_DTC_ADC_All_Node_Missing,
  DemConf_DemEventParameter_DEM_DTC_J3_Time_Sync_Error,
  DemConf_DemEventParameter_DEM_DTC_MCU_TEMP_INITIAL_HIGH,
  DemConf_DemEventParameter_DEM_DTC_ESP_Message_Alive_Counter_Error_100ms,
};

#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>
#endif

/*---[TRIGGER_ON_DTC_STATUS]---*/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

#if (DEM_CB_TABLE_TRIG_ON_DTCST_SIZE != 0U)
/** \brief Generic callback function pointer table for TriggerOnDTCStatus */
CONST(Dem_CbFuncPtrTrigOnDTCStType, DEM_CONST)
  Dem_CbFuncPtrTrigOnDTCSt[DEM_CB_TABLE_TRIG_ON_DTCST_SIZE] =
{
};
#endif

/*---[TRIGGER_ON_EVENT_DATA_CHANGED]---*/

#if (DEM_C_CB_TABLE_TRIG_ON_EVDAT_SIZE != 0U)
/** \brief C-Callback function pointer table for TriggerOnEventDataChanged */
CONST(Dem_CbFuncPtrTrigOnEvDatType, DEM_CONST)
  Dem_CbFuncPtrTrigOnEvDat[DEM_C_CB_TABLE_TRIG_ON_EVDAT_SIZE] =
{
};
#endif

#if (DEM_RTE_CB_TABLE_TRIG_ON_EVDAT_SIZE != 0U)
/** \brief RTE-Callback function pointer table for TriggerOnEventDataChanged */
CONST(Dem_RteFuncPtrTrigOnEvDatType, DEM_CONST)
  Dem_RteFuncPtrTrigOnEvDat[DEM_RTE_CB_TABLE_TRIG_ON_EVDAT_SIZE] =
{
};
#endif

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>

#if (DEM_C_LOOKUP_TABLE_TRIG_ON_EVDAT_SIZE != 0U)
/** \brief C-Lookup table for TriggerOnEventDataChanged */
CONST(Dem_CbLookupTableType, DEM_CONST)
  Dem_CbLookupTableTrigOnEvDat[DEM_C_LOOKUP_TABLE_TRIG_ON_EVDAT_SIZE] =
{
};
#endif

#if (DEM_RTE_LOOKUP_TABLE_TRIG_ON_EVDAT_SIZE != 0U)
/** \brief RTE-Lookup table for TriggerOnEventDataChanged */
CONST(Dem_EventIdType, DEM_CONST)
  Dem_RteLookupTableTrigOnEvDat[DEM_RTE_LOOKUP_TABLE_TRIG_ON_EVDAT_SIZE] =
{
};
#endif

#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>

/*---[CLEAR_EVENT_ALLOWED]---*/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

#if (DEM_C_CB_TABLE_CLEAR_EVENT_ALLOWED_SIZE != 0U)
/** \brief C-Callback function pointer table for ClearEventAllowed */
CONST(Dem_CbFuncPtrClearEventAllowedType, DEM_CONST)
  Dem_CbFuncPtrClearEventAllowed[DEM_C_CB_TABLE_CLEAR_EVENT_ALLOWED_SIZE] =
{
};
#endif

#if (DEM_C_LOOKUP_TABLE_CLEAR_EVENT_ALLOWED_SIZE != 0U)
/** \brief C-Lookup table for ClearEventAllowed
 ** also Clear Event Behavior info is packed in EventId */
CONST(Dem_CbLookupTableType, DEM_CONST)
  Dem_CbLookupTableClearEventAllowed
    [DEM_C_LOOKUP_TABLE_CLEAR_EVENT_ALLOWED_SIZE] =
{
};
#endif

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

#if (DEM_RTE_LOOKUP_TABLE_CLEAR_EVENT_ALLOWED_SIZE != 0U)
#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>

/** \brief RTE-Lookup table for ClearEventAllowed
 ** also Clear Event Behavior info is packed in EventId */
CONST(Dem_EventIdType, DEM_CONST)
  Dem_RteLookupTableClearEventAllowed
    [DEM_RTE_LOOKUP_TABLE_CLEAR_EVENT_ALLOWED_SIZE] =
{
};

#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>
#endif

#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

#if (DEM_RTE_CB_TABLE_CLEAR_EVENT_ALLOWED_SIZE != 0U)
/** \brief RTE-Callback function pointer table for ClearEventAllowed */
CONST(Dem_CbFuncPtrClearEventAllowedType, DEM_CONST)
  Dem_RteFuncPtrClearEventAllowed[DEM_RTE_CB_TABLE_CLEAR_EVENT_ALLOWED_SIZE] =
{
};
#endif

/*---[GET_FDC]---*/

#if (DEM_CB_TABLE_GET_FDC_SIZE != 0U)
/** \brief Generic callback function pointer table for
** GetFaultDetectionCounter
**/
CONST(Dem_CbFuncPtrGetFDCType, DEM_CONST)
  Dem_CbFuncPtrGetFDC[DEM_CB_TABLE_GET_FDC_SIZE] =
{
};
#endif

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>
#if (DEM_LOOKUP_TABLE_GET_FDC_SIZE != 0U)

#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>

/** \brief Generic lookup table for GetFaultDetectionCounter */
CONST(Dem_EventIdType, DEM_CONST)
  Dem_CbLookupTableGetFDC[DEM_LOOKUP_TABLE_GET_FDC_SIZE] =
{
};

#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>
#endif

/*------------------[OBD Readiness Groups force complete]-------------------*/

/* !LINKSTO dsn.Dem.OBDPidSupport.Dem_ReadinessForceStatus_01,1 */
#define DEM_START_SEC_CALIB_8
#include <Dem_MemMap.h>

#if (DEM_OBD_Support == STD_ON)
CONST(uint8, DEM_CONST) Dem_ObdReadinessForceCompleteMask = 0xFFU;
#endif

/*------------------[OBD Readiness Groups PID41 ByteB Pre-set value]---------*/
#if (DEM_OBD_Support == STD_ON)
CONST(uint8, DEM_CONST) Dem_ObdReadinessPID41ByteB = 0x0CU;

#endif

#define DEM_STOP_SEC_CALIB_8
#include <Dem_MemMap.h>

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
