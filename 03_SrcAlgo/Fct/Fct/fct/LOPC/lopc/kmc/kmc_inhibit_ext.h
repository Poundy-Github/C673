/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               kmc_inhibit_ext.h

DESCRIPTION:               External Header file containing types, definitions, prototypes for function inhibition functions

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.4 $

LEGACY VERSION:            Revision: 1.8.1.3

**************************************************************************** */

#ifndef KMC_INHIBIT_EXT_H_INCLUDED
#define KMC_INHIBIT_EXT_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   kmc_inhibit Kmc_Inhibit
@ingroup    kmc
@brief      External header file for KMC inhibit functions
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_lopc_ext.h"

/*usage:*/
/*
1. add an external buffer in the wrapper file:
-> fct_inhibit_storage_t BUFFER;

2. add the KMC_v_InhibitInit function to the main INIT routine
-> KMC_v_InhibitInit(&BUFFER);

3. add a local inhibition buffer to each FCT task (e.g. to KMC_v_Process and LOHP_v_Process)
-> fct_inhibit_t LocalInhibitionBuffer;

3. at the beginning of every task call add KMC_v_InhibitStartCycle
-> KMC_v_InhibitStartCycle(&LocalInhibitionBuffer);

4. when gathering signals, check if they are valid and if their quality is good enough, and add the inhibition handler and the failure indication if this is not the case
-> VDATA_GET_SOMETHING(&data, &signal_status);
-> KMC_v_InhibitAddInhibition(&LocalInhibitionBuffer, signal_status==VDATA_SIG_STATUS_INVALID, Fct_inhibit_FctACC|Fct_inhibit_FctFCA|Fct_inhibit_FctDM|Fct_inhibit_DspTmpNotAv);

... do step 4 as often as signals are read out in this task

5. call KMC_v_InhibitFinishCycle to finish the inhibition check for this task. This function will copy the information from LocalInhibitionBuffer 
   to the global BUFFER and writes back (to LocalInhibitionBuffer) the merged inhibition information. 
   Additionally a unique task_id is needed for every task.
   this function call needs to be "thread save", that means it should be called with "locked ressoureces"
-> OS_LOCK(FCT_RESSOURCE);
-> KMC_v_InhibitFinishCycle(&LocalInhibitionBuffer, &BUFFER, Fct_inhibit_task_LC_EXEC);
-> OS_UNLOCK(FCT_RESSOURCE);

6. map inhibition states to the different inhibit flags for every function and the information for failure indication using KMC_u_InhibitGetInhibition
-> ACC_INPUT_DATA.INPUT_STATUS.INHIBIT = KMC_u_InhibitGetInhibition(LocalInhibitionBuffer, Fct_inhibit_FctACC);

*/

/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/
/*function inhibition information*/
#define Fct_inhibit_FctCC        (fct_inhibition_t)0x00000001u
#define Fct_inhibit_FctACC       (fct_inhibition_t)0x00000002u
#define Fct_inhibit_FctFCA       (fct_inhibition_t)0x00000004u
#define Fct_inhibit_FctDM        (fct_inhibition_t)0x00000008u
#define Fct_inhibit_FctLDW       (fct_inhibition_t)0x00000010u
#define Fct_inhibit_FctDIE       (fct_inhibition_t)0x00000020u
#define Fct_inhibit_FctLODM      (fct_inhibition_t)0x00000040u
#define Fct_inhibit_FctLADM      (fct_inhibition_t)0x00000080u
/*add new functions ...*/

/*failure indication information*/
#define Fct_inhibit_DspTmpNotAv  (fct_inhibition_t)0x80000000u
#define Fct_inhibit_DspPerfDeg   (fct_inhibition_t)0x40000000u
#define Fct_inhibit_DspWorkshop  (fct_inhibition_t)0x20000000u

/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/
/*task ids for inhibition manager*/
typedef enum
{
  Fct_inhibit_task_LC_EXEC,
  Fct_inhibit_task_LONG_EXEC,
  Fct_inhibit_task_LAT_EXEC,
 
  /*-------------------------------------------------------------*/
  Fct_inhibit_storage_size /*must be the last entry in this enum!*/
}fct_inhibit_storage_size_t;

typedef uint32 fct_inhibition_t; 

typedef struct fct_inhibit_t {
  fct_inhibition_t INHIBITION;        /*stores the current inhibition information*/
  uint16           INHiBIT_NR;        /*stores the last inhibition nr*/
  uint16           INHIBITION_COUNT;  /*stores the current inhibition nr*/
} fct_inhibit_t;

typedef struct fct_inhibit_storage_t {
  fct_inhibit_t INHIBIT[Fct_inhibit_storage_size]; 
  uint8         INIT_DONE;
  FCT_OP_MODE_t INTERNAL_OP_MODE, EXTERNAL_OP_MODE;
} fct_inhibit_storage_t;


/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/

extern void KMC_v_InhibitInit(fct_inhibit_storage_t *memory);
extern void KMC_v_InhibitStartCycle(fct_inhibit_t *local_inhibit_buffer);
extern void KMC_v_InhibitAddInhibition(fct_inhibit_t *local_inhibit_buffer, const uint8 condition, const fct_inhibition_t inhibit_list);
extern void KMC_v_InhibitFinishCycle(fct_inhibit_t *local_inhibit_buffer, fct_inhibit_storage_t *memory, const fct_inhibit_storage_size_t task_id);
extern uint8 KMC_u_InhibitGetInhibition(const fct_inhibit_t local_inhibit_buffer, const fct_inhibition_t inhibit_function);

#endif /* ifndef KMC_INHIBIT_EXT_H_INCLUDED */
/** @} end defgroup */
