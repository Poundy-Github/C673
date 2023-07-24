#ifndef SharedRAM_h__
#define SharedRAM_h__

#include "glob_type.h"
#include "algo_service_types.h"
#include "rta_service.h"
#include "algo_shared_types.h"

#ifdef _TMS320C6X
extern volatile far sint32 Flag_RunDSP;
#else
extern volatile sint32 Flag_RunDSP;
#endif

extern ASH_t_MtsToHil   PortBuffer_mts2hil;
extern ASH_t_HilToMts   PortBuffer_hil2mts;
extern AS_t_RtaBuffer   RtaBuffer;

#endif //SharedRAM_h__
