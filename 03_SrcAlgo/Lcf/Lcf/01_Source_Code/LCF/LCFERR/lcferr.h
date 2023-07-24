/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 lcferr.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.8 $


  ---*/ /*---
  CHANGES:                   $Log: lcferr.h  $
  CHANGES:                   Revision 1.8 2019/07/04 14:26:44CEST Grosu, George (uidl9584) 
  CHANGES:                   Update QAF for LCFERR
  CHANGES:                   Revision 1.7 2019/02/04 16:41:11CET Grosu, George (uidl9584) 
  CHANGES:                   Update LCF_ERR tables
  CHANGES:                   Revision 1.6 2018/09/14 16:17:26CEST Grosu, George (uidl9584) 
  CHANGES:                   Split naming for Error Handler
  CHANGES:                   Revision 1.5 2018/09/11 16:19:52CEST Grosu, George (uidl9584) 
  CHANGES:                   Update error handler
  CHANGES:                   Revision 1.4 2018/08/05 18:09:16CEST Grosu, George (uidl9584) 
  CHANGES:                   Add debug signals for ERR
  CHANGES:                   Revision 1.3 2018/05/25 08:08:43CEST Grosu, George (uidl9584) 
  CHANGES:                   update LCFERR
  CHANGES:                   Revision 1.2 2018/05/24 13:07:16CEST Grosu, George (uidl9584) 
  CHANGES:                   Update LCFERR
  CHANGES:                   Revision 1.1 2018/05/22 16:35:37CEST Grosu, George (uidl9584) 
  CHANGES:                   Reorder files
  CHANGES:                   Revision 1.6 2018/05/18 16:07:14CEST Grosu, George (uidl9584) 
  CHANGES:                   Add Allive counter check
  CHANGES:                   Revision 1.5 2018/05/16 16:01:43CEST Grosu, George (uidl9584) 
  CHANGES:                   bugfix volatile memcpy
  CHANGES:                   Revision 1.4 2018/05/16 15:46:08CEST Grosu, George (uidl9584) 
  CHANGES:                   Add more checks
  CHANGES:                   Revision 1.3 2018/05/11 09:06:06CEST Grosu, George (uidl9584) 
  CHANGES:                   Error Handler v1
  CHANGES:                   Revision 1.2 2018/05/10 12:53:18CEST Grosu, George (uidl9584) 
  CHANGES:                   Initial version of LCFERR
**************************************************************************** */
/* Avoid double inclusion */
#ifndef __LCFERR_H__
#define __LCFERR_H__
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "algo_glob.h"

#define LCFERR_EVENT_SUSPENDED (1u)
#define LCFERR_EVENT_NOT_SUSPENDED (0u)
#define LCFERR_cui8FaultHistorySize  (10u)/* Ten entries */
#define LCFERR_cui8NumberOfBytesFF   (10u)

/* Restoring condition */
#define LCFERR_REST_AT_IGNITION (0x01u)
#define LCFERR_REST_IMMEDIATELY (0x00u)

/* Data Types */
typedef enum LCFERR_enErrState
{
    LCFERR_enNoError = 0u,
    LCFERR_enErrDetected,
    LCFERR_enErrConfirmed,
     
} LCFERR_enErrState_t;

typedef struct
{
    uint16 ui16ErrIndex;
    uint16 ui16ErrorCode;
    uint32 ui32TimeStamp;
    LCFERR_enErrState_t eErrState;

} LCFERR_ErrDescType_t;

typedef struct
{
    /* fault history ring buffer */
    LCFERR_ErrDescType_t  aFaultHistoryBuf[LCFERR_cui8FaultHistorySize]; 

    /* fault history ring buffer entry pointer */
    uint8  ui8LastEntryFaultHistoryBuf;
    uint8 reserved[3];// for 4 bytes alignment
} LCFERR_RingBufferType_t;

typedef struct
{
    uint16 ui16ErrorCode;
    LCFERR_enErrState_t eErrState;
    uint16 ui16ErrCntr;
    uint1 bSuppressed;
} LCFERR_ErrStateType_t;




typedef struct{
  uint32 ui32ActionMask;
  void (*psrAction)(void);
}LCFERR_ActionTableType_t;



#endif //__LCFERR_H__