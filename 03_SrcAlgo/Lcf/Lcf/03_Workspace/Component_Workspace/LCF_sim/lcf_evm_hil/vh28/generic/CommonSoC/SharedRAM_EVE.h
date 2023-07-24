#ifndef SharedRAM_EVE_h__
#define SharedRAM_EVE_h__


#include "glob_type.h"
#include "algo_shared_types.h"

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(_TMS320C6X) || defined(__ARP32__)
extern volatile far sint32 Flag_RunEVE;
extern volatile far sint32 EVEReturnValue;
extern far AS_t_EVEContainer EVEContainer;
extern far ASH_t_EVEParams   EVEParams;
#else
extern volatile sint32 Flag_RunEVE;
extern volatile sint32 EVEReturnValue;
extern AS_t_EVEContainer EVEContainer;
extern ASH_t_EVEParams   EVEParams;
#endif

#ifdef __cplusplus
}
#endif

#endif //SharedRAM_EVE_h__
