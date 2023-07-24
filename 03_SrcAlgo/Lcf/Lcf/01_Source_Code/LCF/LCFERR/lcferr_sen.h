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

  VERSION:                   $Revision: 1.3 $


  ---*/ /*---
  CHANGES:                   $Log: lcferr_sen.h  $
  CHANGES:                   Revision 1.3 2019/04/10 03:46:28CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.2 2019/03/13 10:38:38CET Grosu, George (uidl9584) 
  CHANGES:                   Silent LCFERR
  CHANGES:                   Revision 1.1 2019/02/04 16:41:09CET Grosu, George (uidl9584) 
  CHANGES:                   Update LCF_ERR tables
  CHANGES:                   Revision 1.0 2018/09/14 16:20:22CEST Grosu, George (uidl9584) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCFERR/project.pj
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
#ifndef __LCFERR_SEN_H__
#define __LCFERR_SEN_H__
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "algo_glob.h"
#include "lcferr.h"
#include "LCFERR/LCFERR_SenCustom.h"

#ifndef SET_ERRIOSEN_ErrStateArray
#define SET_ERRIOSEN_ErrStateArray(i,status) ERRIOSEN_ErrStateArray[(i)] = (status)
#endif

#ifndef GET_ERRIOSEN_ErrStateArray
#define GET_ERRIOSEN_ErrStateArray(i) ERRIOSEN_ErrStateArray[(i)]
#endif

/* Data Types */
typedef struct
{
  uint8  ui8ErrCluster;/* Unique ID for error cluster */
  uint16 ui16ErrorCode;/* Unique LCF error code */
  uint16 ui16IncValue;/* Increment value for error debouncing */
  uint16 ui16DecValue;/* Decrement value for error redebouncing */
  uint16 ui16MaxCounter;/* Max value for debounce counter -> when error is confirmed */
  uint8  ui8SupressionFlags;/* Bitfield for different types of supression */
  uint8  ui8CompCode;/* Component that generates the error */
  uint32 ui32CompErrorMask;/* Bit inside component code correspondent for current error */
  uint8  ui8RestCond;/* Error restoring condition */
  ERRSEN_enAction_t eActNotDetErr;/* Action for Error not detected, but confirmed */
  ERRSEN_enAction_t eActDetErr;/* Action for Error Detected, but not confirmed */
  ERRSEN_enAction_t eActConfErr;/* Action for Error Confirmed*/
  ERRSEN_enAction_t eActRestErr;/* Action for error Restored (transition from error confirmed to no error) */
  ERRSEN_enDemEvent_t eDemEventErr;/* Dem Event associated with the error */
  
} ERRSEN_ErrCfgType_t;



/* INPUTS */
extern volatile uint32 S_ERRSEN_ErrMatrix_btf[ERRSEN_enNoOfModules];


/* OUTPUTS */
extern volatile uint32 S_ERRSEN_ActionFlag_btf;/*  */
extern volatile uint8 S_ERRSEN_DemEvents_btf;/*  */
//extern volatile uint8 S_ERRSEN_AddFreezeFrames_nu[C_ERRSEN_NumberOfDemEvents][LCFERR_cui8NumberOfBytesFF];

/* Constants */
extern const uint8 S_ERRSEN_DemArray[C_ERRSEN_DemArraySize];
extern const uint16 S_ERRSEN_DemEvents[C_ERRSEN_NumberOfDemEvents];
extern const ERRSEN_ErrCfgType_t S_ERRSEN_ConfigTable[C_ERRSEN_NumOfErrors];
extern const LCFERR_ActionTableType_t S_ERRSEN_ActionTable[C_ERRSEN_NumOfActions];

/* Ring buffer */
extern volatile LCFERR_ErrStateType_t S_ERRSEN_ErrState_st[C_ERRSEN_NumOfErrors];


/* Public Functions */
void ERRSEN_Reset(void);
void ERRSEN_Process(void);



#endif //__LCFERR_H__