#include "algo_glob.h"
#define dummy 0

#define VISUAL_C //ClPr
#ifdef VISUAL_C
//Setting for Visual Studio .NET 2003
//special define for inline needed
#ifdef inline
#undef inline
#endif

#ifdef PC_SIM
#define inline __inline

#elif defined (PRODUCT_MFC431)
#define inline __inline//Camera -> __inline

#elif defined(__ARMCC_VERSION)   // ARMCLANG Compiler used in MFC5xx
#define inline static inline

#else
#define inline __inline__//Radar -> __inline__
#endif

#else

#ifdef inline
#undef inline
#endif
#define inline

#endif

/* To avoid warnings during compilation */

#ifdef MEM_CODE
//#include <gmemcode.h>                  /* evaluate code environment */
#undef MEM_CODE                        /* clear code environment */
#endif

#ifndef MEM_CONST                      /* Redirect code constants to MEM_CONST if no other requirement is set */
#ifdef  MEM_CODECONST
#define MEM_CONST MEM_CODECONST
#endif
#endif

#ifdef MEM_CONST
//#include <gmemconst.h>                 /* evaluate const environment */
#undef MEM_CONST                       /* clear const environment */
#endif

#ifdef MEM_DATA
//#include <gmemdata.h>                  /* evaluate data environment */
#undef MEM_DATA                        /* clear data environment */
#endif

#ifdef MEM_CAL
//#include <gmemcal.h>                   /* evaluate calibration data environment */
#undef MEM_CAL                         /* clear calibration data environment */
#endif

#ifdef  MEM_CODECONST
#undef  MEM_CODECONST
#endif
