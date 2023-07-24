// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: MTSI
// VERSION:   $Revision: 1.9 $
/// @file



/* PRQA S 883++ */
/* Include guard must not be used in this file, because this header is intended to be included multiple times. */
/* Reviewed by M. Limbrunner, G. Fischer on 2016-05-13 */

/* PRQA S 3116++ */
/* Pragmas are required for the platform specific byte alignment. */
/* Reviewed by M. Limbrunner, G. Fischer on 2016-05-13 */

/* PRQA S 3318++ */
/* Because these is an generic file, the preprocessor checks are needed at include. */
/* Reviewed by A. Pop on 2019-08-26 */

/// Platform specific memory mapping
///
/// Static variables of the MTSI module, that are related to a specific core,
/// can here be mapped to specific memory sections.

 
#if defined (MTSI_START_SEC_MAIN)
  #ifdef MTSI_SEC_MAIN_STARTED
    #error "Memory section is not stopped"
  #else
    #define MTSI_SEC_MAIN_STARTED
    #undef  MTSI_START_SEC_MAIN
  #endif
#elif defined (MTSI_STOP_SEC_MAIN)
  #ifndef MTSI_SEC_MAIN_STARTED
    #error "Memory section is not started"
  #else
    #undef  MTSI_SEC_MAIN_STARTED
    #undef  MTSI_STOP_SEC_MAIN
  #endif

#elif defined (MTSI_START_SEC_CORE_0)
  #ifdef MTSI_SEC_CORE_0_STARTED
    #error "Memory section is not stopped"
  #else
    #define MTSI_SEC_CORE_0_STARTED
    #undef  MTSI_START_SEC_CORE_0
    #pragma alignvar(2)
  #endif
#elif defined (MTSI_STOP_SEC_CORE_0)
  #ifndef MTSI_SEC_CORE_0_STARTED
    #error "Memory section is not started"
  #else
    #undef  MTSI_SEC_CORE_0_STARTED
    #undef  MTSI_STOP_SEC_CORE_0
  #endif

#elif defined (MTSI_START_SEC_CORE_1)
  #ifdef MTSI_SEC_CORE_1_STARTED
    #error "Memory section is not stopped"
  #else
    #define MTSI_SEC_CORE_1_STARTED
    #undef  MTSI_START_SEC_CORE_1
    #pragma alignvar(2)
  #endif
#elif defined (MTSI_STOP_SEC_CORE_1)
  #ifndef MTSI_SEC_CORE_1_STARTED
    #error "Memory section is not started"
  #else
    #undef  MTSI_SEC_CORE_1_STARTED
    #undef  MTSI_STOP_SEC_CORE_1
  #endif

#elif defined (MTSI_START_SEC_CORE_2)
  #ifdef MTSI_SEC_CORE_2_STARTED
    #error "Memory section is not stopped"
  #else
    #define MTSI_SEC_CORE_2_STARTED
    #undef  MTSI_START_SEC_CORE_2
    #pragma alignvar(2)
  #endif
#elif defined (MTSI_STOP_SEC_CORE_2)
  #ifndef MTSI_SEC_CORE_2_STARTED
    #error "Memory section is not started"
  #else
    #undef  MTSI_SEC_CORE_2_STARTED
    #undef  MTSI_STOP_SEC_CORE_2
  #endif

#elif defined (MTSI_START_SEC_CORE_3)
  #ifdef MTSI_SEC_CORE_3_STARTED
    #error "Memory section is not stopped"
  #else
    #define MTSI_SEC_CORE_3_STARTED
    #undef  MTSI_START_SEC_CORE_3
    #pragma alignvar(2)
  #endif
#elif defined (MTSI_STOP_SEC_CORE_3)
  #ifndef MTSI_SEC_CORE_3_STARTED
    #error "Memory section is not started"
  #else
    #undef  MTSI_SEC_CORE_3_STARTED
    #undef  MTSI_STOP_SEC_CORE_3
  #endif

#elif defined (MTSI_START_SEC_CORE_4)
  #ifdef MTSI_SEC_CORE_4_STARTED
    #error "Memory section is not stopped"
  #else
    #define MTSI_SEC_CORE_4_STARTED
    #undef  MTSI_START_SEC_CORE_4
    #pragma alignvar(2)
  #endif
#elif defined (MTSI_STOP_SEC_CORE_4)
  #ifndef MTSI_SEC_CORE_4_STARTED
    #error "Memory section is not started"
  #else
    #undef  MTSI_SEC_CORE_4_STARTED
    #undef  MTSI_STOP_SEC_CORE_4
  #endif

#elif defined (MTSI_START_SEC_PRIORITY_QUEUE)
  #ifdef MTSI_SEC_PRIORITY_QUEUE_STARTED
    #error "Memory section is not stopped"
  #else
    #define MTSI_SEC_PRIORITY_QUEUE_STARTED
    #undef  MTSI_START_SEC_PRIORITY_QUEUE
    #pragma alignvar(2)
  #endif
#elif defined (MTSI_STOP_SEC_PRIORITY_QUEUE)
  #ifndef MTSI_SEC_PRIORITY_QUEUE_STARTED
    #error "Memory section is not started"
  #else
    #undef  MTSI_SEC_PRIORITY_QUEUE_STARTED
    #undef  MTSI_STOP_SEC_PRIORITY_QUEUE
  #endif

#elif defined (MTSI_START_SEC_STATISTIC_DATA)
  #ifdef MTSI_SEC_STATISTIC_DATA_STARTED
    #error "Memory section is not stopped"
  #else
    #define MTSI_SEC_STATISTIC_DATA_STARTED
    #undef  MTSI_START_SEC_STATISTIC_DATA
    #pragma alignvar(2)
  #endif
#elif defined (MTSI_STOP_SEC_STATISTIC_DATA)
  #ifndef MTSI_SEC_STATISTIC_DATA_STARTED
    #error "Memory section is not started"
  #else
    #undef  MTSI_SEC_STATISTIC_DATA_STARTED
    #undef  MTSI_STOP_SEC_STATISTIC_DATA
  #endif

#endif


