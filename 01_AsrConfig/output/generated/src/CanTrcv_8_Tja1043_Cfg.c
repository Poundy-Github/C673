/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */
/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "CanTrcv_8_Tja1043_Cfg.h"



/**********************************************************************************************************************
  VERSION DEFINES (Adapted with: ESCAN00086365)
**********************************************************************************************************************/
#if (DRVTRANS_CAN_TJA1043_GENTOOL_CFG5_MAJOR_VERSION != 0x03u)
# error "CanTrcv_Tja1043_Cfg.c : Incompatible DRVTRANS_TJA1043_GENTOOL_CFG5_MAJOR_VERSION in generated File!"
#endif

#if (DRVTRANS_CAN_TJA1043_GENTOOL_CFG5_MINOR_VERSION != 0x03u)
# error "CanTrcv_Tja1043_Cfg.c : Incompatible DRVTRANS_TJA1043_GENTOOL_CFG5_MINOR_VERSION in generated File!"
#endif

#if (DRVTRANS_CAN_TJA1043_GENTOOL_CFG5_PATCH_VERSION != 0x00u)
# error "CanTrcv_Tja1043_Cfg.c : Incompatible DRVTRANS_TJA1043_GENTOOL_CFG5_PATCH_VERSION in generated File!"
#endif


                                /*[cover parentID={152B4BF1-9AF6-4cf8-B4D8-184F7B3C2E77}][/cover]*/

/**********************************************************************************************************************
GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
CONFIGURATION CLASS: PRE_COMPILE
SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
CanTrcv_Tja1043_ChannelUsed
**********************************************************************************************************************/
#define CANTRCV_TJA1043_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_Tja1043_ChannelUsedType, CANTRCV_TJA1043_CONST) CanTrcv_Tja1043_ChannelUsed[CANTRCV_TJA1043_MAX_CHANNEL] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  
  TRUE

};
#define CANTRCV_TJA1043_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
CanTrcv_Tja1043_DioConfiguration
**********************************************************************************************************************/
/** 
\var    CanTrcv_Tja1043_DioConfiguration
\details
Element    Description
PinEN  
PinERR 
PinRXD 
PinSTB 
*/ 
#define CANTRCV_TJA1043_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_Tja1043_DioConfigurationType, CANTRCV_TJA1043_CONST) CanTrcv_Tja1043_DioConfiguration[CANTRCV_TJA1043_MAX_CHANNEL] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
/* Index    PinEN                       PinERR                       PinRXD                       PinSTB                      */
  
  {
  DioConf_DioChannel_DIO_DO_B2_Sample_AURIX_CAN0_STB_B,
  DioConf_DioChannel_DIO_DO_B2_Sample_AURIX_CAN0_EN,
  DioConf_DioChannel_DIO_DI_B2_Sample_CAN0_ERR_B,
  DioConf_DioChannel_MCU_CAN10_RXD_CAN0RXD
  }
};
#define CANTRCV_TJA1043_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
CanTrcv_Tja1043_Hw_VariantGroup
**********************************************************************************************************************/
#define CANTRCV_TJA1043_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_Tja1043_Hw_VariantGroupType, CANTRCV_TJA1043_CONST) CanTrcv_Tja1043_Hw_VariantGroup[CANTRCV_TJA1043_MAX_CHANNEL] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
/* Index     Hw_VariantGroup      Comment */
/*     0 */            0x00u   /* [Tja1043 Reference Group] */
};
#define CANTRCV_TJA1043_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
CanTrcv_Tja1043_WakeupByBusUsed
**********************************************************************************************************************/
#define CANTRCV_TJA1043_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_Tja1043_WakeupByBusUsedType, CANTRCV_TJA1043_CONST) CanTrcv_Tja1043_WakeupByBusUsed[CANTRCV_TJA1043_MAX_CHANNEL] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
/* Index     WakeupByBusUsed  */
  
  FALSE

};
#define CANTRCV_TJA1043_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
CanTrcv_Tja1043_WakeupSource
**********************************************************************************************************************/
#define CANTRCV_TJA1043_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_Tja1043_WakeupSourceType, CANTRCV_TJA1043_CONST) CanTrcv_Tja1043_WakeupSource[CANTRCV_TJA1043_MAX_CHANNEL] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
/* Index     WakeupSource  */
  
  0x00u

};
#define CANTRCV_TJA1043_STOP_SEC_CONST_BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define CANTRCV_TJA1043_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
#if (CANTRCV_TJA1043_DEM_REPORT_SUPPORT == STD_ON)
CONST(Dem_EventIdType, CANTRCV_TJA1043_CONST) CanTrcv_TJA1043_DemIdList[CANTRCV_TJA1043_MAX_CHANNEL][2] = 
{
  
  0x00u

};
#endif

#define CANTRCV_TJA1043_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "CanTrcv_8_Tja1043_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

const CanTrcv_Tja1043_ConfigType* CanTrcv_Tja1043_ConfigTypePtr = NULL_PTR;

/**********************************************************************************************************************
CONFIGURATION CLASS: LINK
SECTION: GLOBAL DATA
**********************************************************************************************************************/




