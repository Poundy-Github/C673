#include "glob_type.h"
#include "algo_service_types.h"

// TODO: move this to "algo_service_types.h" (correct mane of define to be clarified)
// This is intended to be max. 1K but reserve 256K for adding test data
#define MAX_EVE_PARAM_SIZE  0x40000

#if defined(__TI_COMPILER_VERSION__)

#pragma DATA_ALIGN   (EVEContainer, 128)
#pragma DATA_SECTION (EVEContainer, ".memsec_shared_data_eve.1")
AS_t_EVEContainer EVEContainer;

#pragma DATA_ALIGN   (EVEParams, 128)
#pragma DATA_SECTION (EVEParams, ".memsec_shared_data_eve.2")
uint8 EVEParams[MAX_EVE_PARAM_SIZE];

#pragma DATA_ALIGN   (Flag_RunEVE, 128)
#pragma DATA_SECTION (Flag_RunEVE, ".memsec_shared_data_eve.3")
volatile sint32 Flag_RunEVE = 0;

#pragma DATA_ALIGN   (EVEReturnValue, 128)
#pragma DATA_SECTION (EVEReturnValue, ".memsec_shared_data_eve.4")
volatile sint32 EVEReturnValue = 0;

#elif defined(__GNUC__)

AS_t_EVEContainer EVEContainer      __attribute__((section(".memsec_shared_data_eve.1"), aligned(128))) ;
uint8 EVEParams[MAX_EVE_PARAM_SIZE] __attribute__((section(".memsec_shared_data_eve.2"), aligned(128))) ;              
volatile sint32 Flag_RunEVE         __attribute__((section(".memsec_shared_data_eve.3"), aligned(128))) = 0;
volatile sint32 EVEReturnValue      __attribute__((section(".memsec_shared_data_eve.4"), aligned(128))) = 0;

#endif /* __TI_COMPILER_VERSION__ & __GNUC__ */
