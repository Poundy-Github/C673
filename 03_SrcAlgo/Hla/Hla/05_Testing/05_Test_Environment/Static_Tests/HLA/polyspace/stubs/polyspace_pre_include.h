/* Re-definition of NULL needed as Polyspace cannot handle the definition of
 * "04_Engineering\01_Source_Code\common\glob_type.h"
 */
#ifndef NULL
  #ifdef __cplusplus
    #define NULL 0
  #else
    #define NULL ((void *)0)
  #endif
#endif
