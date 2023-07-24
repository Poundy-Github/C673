/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 errio.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.10 $


  ---*/ /*---
  CHANGES:                   $Log: errio.h  $
  CHANGES:                   Revision 1.10 2019/03/13 10:36:14CET Grosu, George (uidl9584) 
  CHANGES:                   Separate debounce limits
  CHANGES:                   Revision 1.9 2019/03/07 14:51:43CET Grosu, George (uidl9584) 
  CHANGES:                   Update trunk for LCFERR
  CHANGES:                   Revision 1.8 2019/02/24 17:09:25CET Grosu, George (uidl9584) 
  CHANGES:                   Adjust includes for veh
  CHANGES:                   Revision 1.7 2019/02/19 13:14:27CET Grosu, George (uidl9584) 
  CHANGES:                   add Intertask errors. Use algo signal names
  CHANGES:                   Revision 1.6 2018/09/14 16:17:25CEST Grosu, George (uidl9584) 
  CHANGES:                   Split naming for Error Handler
  CHANGES:                   Revision 1.5 2018/09/11 16:19:51CEST Grosu, George (uidl9584) 
  CHANGES:                   Update error handler
  CHANGES:                   Revision 1.4 2018/07/31 12:24:00CEST Grosu, George (uidl9584) 
  CHANGES:                   Update ERR after review
  CHANGES:                   Revision 1.3 2018/05/25 08:08:42CEST Grosu, George (uidl9584) 
  CHANGES:                   update LCFERR
  CHANGES:                   Revision 1.2 2018/05/24 13:07:16CEST Grosu, George (uidl9584) 
  CHANGES:                   Update LCFERR
  CHANGES:                   Revision 1.1 2018/05/22 16:35:37CEST Grosu, George (uidl9584) 
  CHANGES:                   Reorder files
  CHANGES:                   Revision 1.4 2018/05/18 16:07:13CEST Grosu, George (uidl9584) 
  CHANGES:                   Add Allive counter check
  CHANGES:                   Revision 1.3 2018/05/11 09:06:07CEST Grosu, George (uidl9584) 
  CHANGES:                   Error Handler v1
  CHANGES:                   Revision 1.2 2018/05/10 12:30:21CEST Grosu, George (uidl9584) 
  CHANGES:                   First version of LCFERR

**************************************************************************** */
/* Avoid double inclusion */
#ifndef __ERRIO_H__
#define __ERRIO_H__
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "algo_glob.h"

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
#define LCF_IS_ERROR                 (1u)     /* LCF input signal error */
#define LCF_NO_ERROR                 (0u)     /* LCF no input signal error */



#define LCF_IO_POS_NotAvailable      (255u)/* A number that is different than any LCF_IO_POS */

#define LCF_MAX_ALGO_CYCLE_CNT       (65535u) /* Max value for type AlgoCycleCounter_t */
#define LCF_MAX_TIMESTAMP            (4294967295u) /* Max value for type AlgoDataTimeStamp_t */

/*****************************************************************************
  STRUCTURES AND TYPEDEFS
*****************************************************************************/

/* Configuration for each input signal error */
typedef struct {
    const uint8  ui8LcfSignalName;                                  /* Position of the input signal in the state array from the signal source sigStateArray */
    const uint16 ui16LcfRelevantFct_btf;                            /* bitfield that contains the LCF functionalities for which this signal is relevant */
          uint8  ui8LcfErrDbcCounter;                               /* Debounce error counter for this signal */
          uint8  ui8ErrorConfirmed_bool;                            /* Error confirmed status for this signal. Can be 1 bit in LcfErrDbcCounter, but less readable code */
}ERRIO_ErrConfigData;

typedef struct {
    const SignalHeader_t* sigHead;
    AlgoDataTimeStamp_t oldTimeStamp;
    AlgoCycleCounter_t oldMeasurementCounter;
    AlgoCycleCounter_t oldCycleCounter;
    uint8 constantCycles;
    uint8 MaxConstantCycles;
	uint8 MaxOvrflCycles;
    uint8 EnableChecking_btf;
}ERRIO_HeaderParser_t;

typedef enum {
  LCF_ERRHNDL_TJA_LC = 0,
  LCF_ERRHNDL_LDP,
  LCF_ERRHNDL_RDP,
  LCF_ERRHNDL_LDW,
  LCF_ERRHNDL_TJA_OF,
  LCF_ERRHNDL_RDW,
  LCF_ERRHNDL_LDPOC,
  LCF_ERRHNDL_LDWOC,
  LCF_ERRHNDL_ALCA,
  LCF_ERRHNDL_SALC,
  LCF_ERRHNDL_AOLC,
  LCF_ERRHNDL_LATDMC,
  ERRIO_CHECKED_FUNCTIONS_NO
} ERRIO_e_ErrHndlFuncs_t; /* LCF functions with error handling for input signals */


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

#endif //__ERRIOSEN_H__
