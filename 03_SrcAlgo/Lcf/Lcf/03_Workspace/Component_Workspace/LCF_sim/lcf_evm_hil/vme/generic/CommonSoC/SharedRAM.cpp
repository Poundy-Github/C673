#include "SharedRAM.h"

#if defined(__TI_COMPILER_VERSION__)

#pragma DATA_SECTION(".memsec_shared_data.1")
#pragma DATA_ALIGN(128)
ASH_t_MtsToHil PortBuffer_mts2hil;

#pragma DATA_SECTION(".memsec_shared_data.2")
#pragma DATA_ALIGN(128)
ASH_t_HilToMts PortBuffer_hil2mts;

#pragma DATA_SECTION(".memsec_shared_data.3")
#pragma DATA_ALIGN(128)
volatile sint32 Flag_RunDSP = 0;

#pragma DATA_SECTION(".memsec_shared_data.4")
#pragma DATA_ALIGN(128)
AS_t_RtaBuffer RtaBuffer;

#elif defined(__GNUC__)

ASH_t_MtsToHil PortBuffer_mts2hil __attribute__((section(".memsec_shared_data.1"), aligned(128)));
ASH_t_HilToMts PortBuffer_hil2mts __attribute__((section(".memsec_shared_data.2"), aligned(128)));
volatile sint32 Flag_RunDSP       __attribute__((section(".memsec_shared_data.3"), aligned(128))) = 0;
AS_t_RtaBuffer RtaBuffer          __attribute__((section(".memsec_shared_data.4"), aligned(128)));

#endif /* __TI_COMPILER_VERSION__ & __GNUC__ */
