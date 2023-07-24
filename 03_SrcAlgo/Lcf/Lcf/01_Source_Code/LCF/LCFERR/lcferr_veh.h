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

  VERSION:                   $Revision: 1.4 $


  ---*/ /*---
  CHANGES:                   $Log: lcferr_veh.h  $
  CHANGES:                   Revision 1.4 2019/11/26 12:11:26CET Grosu, George (uidl9584) 
  CHANGES:                   bring TA19 changes to trunk
  CHANGES:                   Revision 1.3 2019/04/10 03:46:29CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.2 2019/03/20 10:34:08CET Grosu, George (uidl9584) 
  CHANGES:                   move errio signals
  CHANGES:                   Revision 1.1 2019/03/13 10:38:37CET Grosu, George (uidl9584) 
  CHANGES:                   Silent LCFERR
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
#ifndef __LCFERR_VEH_H__
#define __LCFERR_VEH_H__
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "algo_glob.h"
#include "lcferr.h"
#include "LCFERR/LCFERR_VehCustom.h"



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
  ERRVEH_enAction_t eActNotDetErr;/* Action for Error not detected, but confirmed */
  ERRVEH_enAction_t eActDetErr;/* Action for Error Detected, but not confirmed */
  ERRVEH_enAction_t eActConfErr;/* Action for Error Confirmed*/
  ERRVEH_enAction_t eActRestErr;/* Action for error Restored (transition from error confirmed to no error) */
  ERRVEH_enDemEvent_t eDemEventErr;/* Dem Event associated with the error */
  
} ERRVEH_ErrCfgType_t;

/* INPUTS */
extern volatile uint32 S_ERRVEH_ErrMatrix_btf[ERRVEH_enNoOfModules];


/* OUTPUTS */
extern volatile uint32 S_ERRVEH_ActionFlag_btf;/*  */
extern volatile uint8 S_ERRVEH_DemEvents_btf;/*  */
//extern volatile uint8 S_ERRVEH_AddFreezeFrames_nu[C_ERRVEH_NumberOfDemEvents][LCFERR_cui8NumberOfBytesFF];

/* Constants */
extern const uint8 S_ERRVEH_DemArray[C_ERRVEH_DemArraySize];
extern const uint16 S_ERRVEH_DemEvents[C_ERRVEH_NumberOfDemEvents];
extern const ERRVEH_ErrCfgType_t S_ERRVEH_ConfigTable[C_ERRVEH_NumOfErrors];
extern const LCFERR_ActionTableType_t S_ERRVEH_ActionTable[C_ERRVEH_NumOfActions];

/* Ring buffer */
//extern ERRVEH_RingBufferType_t S_ERRVEH_ErrBuff;/* Debugging purpose */
extern volatile LCFERR_ErrStateType_t S_ERRVEH_ErrState_st[C_ERRVEH_NumOfErrors];


/* Public Functions */
void ERRVEH_Reset(void);
void ERRVEH_Process(void);



#endif //__LCFERR_H__