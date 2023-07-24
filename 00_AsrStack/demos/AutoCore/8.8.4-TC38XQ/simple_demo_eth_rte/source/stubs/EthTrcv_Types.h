/* --------{ EB Automotive C Source File }-------- */

#if (!defined ETHTRCV_TYPES_H)
#define ETHTRCV_TYPES_H

/*==[Includes]================================================================*/

#include <EthTrcv_StubCfg.h>
#include <Eth_GeneralTypes.h>

/*==[Macros]==================================================================*/

/*==[Types]===================================================================*/

typedef struct
{
   uint8 PBcfg_dummy;
} EthTrcv_ConfigType;

/*==[Declaration of functions with external linkage]==========================*/

#define EBSTUBS_START_SEC_CODE
#include <MemMap.h>

#define EBSTUBS_STOP_SEC_CODE
#include <MemMap.h>

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

#define EBSTUBS_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>


#define EBSTUBS_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

/* stub extension header file */
#include <EthTrcv_StubExt.h>

#endif /* !defined ETHTRCV_TYPES_H */
