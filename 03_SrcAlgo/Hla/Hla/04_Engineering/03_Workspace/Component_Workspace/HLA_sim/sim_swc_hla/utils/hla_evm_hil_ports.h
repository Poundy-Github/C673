/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hla_evm_hil_ports.h

  DESCRIPTION:            Definition for debugging and evaluation

  CREATION DATE:          2010-10-26
  
  CPU:                    Independent

  VERSION:                $Revision: 1.2 $
**************************************************************************** */

#ifndef HLA_EVM_HIL_PORTS_H
#define HLA_EVM_HIL_PORTS_H

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_defs.h"
#ifndef AS_RTA_MAX_EVENTS
#include "rtatype.h"
#endif
#include "sim_hla_common.h"

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
typedef struct
{
  /* request ports */                                                           
  SimHlaReqPrtBuffers_t        reqPortBuffers;
                          
  /* Internal measfreezes for HIL initialization, e.g. ROI */
  uint8                        isHilInitNeeded;

  /* In simulation InitGlobVars() is called if reset port is triggered. Same behaviour shall be done for HIL by using this flag */
  uint8                        isHilResetNeeded;
} Mts2Hil_t;

typedef struct
{
  /* provide ports */  
  SimHlaProPrtBuffers_t        proPortBuffers;

  /* internal measfreezes */
  t_ErrorHandling_ErrorStack   hlaErrorStack;

  /* HIL time measurement */
  AS_t_RtaBuffer               rtaBuffer;
  AS_t_RtaBuffer               rtaBufferEve;

  /* active flag for visualization */
  boolean                      bHilActive;

} Hil2Mts_t;

typedef uint8 Hil2MtsArray_t[sizeof(Hil2Mts_t)];

#endif /* HLA_EVM_HIL_PORTS_H */
