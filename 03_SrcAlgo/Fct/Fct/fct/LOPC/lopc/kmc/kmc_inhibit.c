/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               kmc_inhibit.c

DESCRIPTION:               This file contains functions concerning inhibition for ACC Veh Task functions

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.7 $

LEGACY VERSION:            Revision: 1.12.1.3

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   kmc_inhibit Kmc_Inhibit
@ingroup    kmc
@brief      KMC Inhibition functions
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "kmc.h"
#include "kmc_inhibit_ext.h"

#if ((FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_KMC))
/*****************************************************************************
  MODULE GLOBAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULE GLOBAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL FUNCTIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    KMC_v_InhibitInit                                                                                */ /*!

  @brief           Initialize the global inhibit memory

  @description     Clears and resets all information from inhibit memory

@startuml
Start
Partition KMC_v_InhibitInit(){
: Initialize the global inhibit memory and clears, resets all information from inhibit memory;
}
End
@enduml

  @return          -

  @param[in,out]   memory : Pointer to storage of FCT inhibition data [fct_inhibit_storage_t as per lopc_inhibit_ext.h]
                    INHIBIT[i].INHIBITION : Storage of current inhibition information of INHIBIT[i], i=[0u ... Fct_inhibit_storage_size), [full range of uint32]
                    INHIBIT[i].INHiBIT_NR : Number of inhibitions of INHIBIT[i], i=[0u ... Fct_inhibit_storage_size), for last cycle [0u ... 60000u]
                    INTERNAL_OP_MODE : Internal operational mode information for FCT [full range of datatype FCT_OP_MODE_t as in Rte_Type.h]
                    EXTERNAL_OP_MODE : External operational mode information for FCT [full range of datatype FCT_OP_MODE_t as in Rte_Type.h]
                    INIT_DONE : Boolean indicating initialisation of inhibition memory done [TRUE, FALSE]

  @glob_in         -
  @glob_out        EXTERNAL_OP_MODE : Local variable for external operational mode information [full range of datatype FCT_OP_MODE_t as in Rte_Type.h]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-158-0008a220
*************************************************************************************************************************/
void KMC_v_InhibitInit(fct_inhibit_storage_t *memory)
{
  uint8 i;
  for(i = 0u; i < (uint8)Fct_inhibit_storage_size; i++)
  {
    memory->INHIBIT[i].INHIBITION = 0u;
    memory->INHIBIT[i].INHiBIT_NR = 0u;
  }
  memory->INTERNAL_OP_MODE = FCT_MOD_SHUTDOWN;
  memory->EXTERNAL_OP_MODE = FCT_MOD_SHUTDOWN;
  memory->INIT_DONE = TRUE;
}


/*************************************************************************************************************************
  Functionname:    KMC_v_InhibitStartCycle                                                                          */ /*!

  @brief           Initialize inhibit memory

  @description     Clears all information from a single inhibit memory at start of a cycle

@startuml
start
partition KMC_v_InhibitStartCycle(){
: Initialize inhibit memory and Clears all information from a single inhibit memory at start of a cycle;
End
@enduml

  @return          -

  @param[in,out]   local_inhibit_buffer : Pointer to inhibition buffer [fct_inhibit_t as per lopc_inhibit_ext.h]
                    INHIBITION : Storage of current inhibition information [full range of uint32]
                    INHiBIT_NR : Number of inhibitions for last cycle [0u ... 60000u]
                    INHIBITION_COUNT : Number of inhibitions for current cycle [0u ... 60000u]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-159-0008a220
*************************************************************************************************************************/
void KMC_v_InhibitStartCycle(fct_inhibit_t *local_inhibit_buffer)
{
  local_inhibit_buffer->INHIBITION = (fct_inhibition_t)0;
  local_inhibit_buffer->INHiBIT_NR = 0u;
  local_inhibit_buffer->INHIBITION_COUNT = 0u;
}


/*************************************************************************************************************************
  Functionname:    KMC_v_InhibitAddInhibition                                                                       */ /*!

  @brief           Adds an inhibition to local buffer in case of a condition

  @description     In case the "condition" is true, the inhibition buffer (local_inhibit_buffer) 
                   is extended with the current inhibition list
@startuml
Start
Partition KMC_v_InhibitAddInhibition(){
: Adds an inhibition (Counter Incrementing) to local buffer in case of a condition;
: In case the "condition" is true, the inhibition buffer (local_inhibit_buffer) 
  is extended with the current inhibition list;
}
End
@enduml

  @return          -

  @param[in,out]   local_inhibit_buffer : Pointer to inhibition buffer [fct_inhibit_t as per lopc_inhibit_ext.h]
  @param[in]       condition : Boolean specifying a condition to be tested [TRUE, FALSE]
  @param[in]       inhibit_list : Inhibition list which is appended to the local buffer [full range of uint32]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-160-0008a220
*************************************************************************************************************************/
void KMC_v_InhibitAddInhibition(fct_inhibit_t *local_inhibit_buffer, const uint8 condition, const fct_inhibition_t inhibit_list)
{
  local_inhibit_buffer->INHIBITION_COUNT++;
  if(condition)
  {
    local_inhibit_buffer->INHIBITION|= inhibit_list;
    local_inhibit_buffer->INHiBIT_NR = local_inhibit_buffer->INHIBITION_COUNT;
  }
}


/*************************************************************************************************************************
  Functionname:    KMC_v_InhibitFinishCycle                                                                         */ /*!

  @brief           Stores the local value into inhibition storage and puts out the merged inhibition list

  @description     The current local inhibition buffer is stored into the inhibition storage. The various inhibition
                   values in the storage are then merged into a single list which is written into the local inhibition buffer

@startuml
Partition KMC_v_InhibitFinishCycle(){
Start
: Stores the local value into inhibition storage for particular task ID;
: The various inhibition values (from Different task Ids) in the storage are then merged into a single list\n which is written into the local inhibition buffer;
}
End
@enduml

  @return          -

  @param[in,out]   local_inhibit_buffer : Pointer to current cycle inhibition buffer and merged output inhibition buffer [fct_inhibit_t as per lopc_inhibit_ext.h]
                    INHIBITION : Storage of current inhibition information [full range of uint32]
  @param[in,out]   memory : Pointer to storage of FCT inhibition data [fct_inhibit_storage_t as per lopc_inhibit_ext.h]
                    INHIBIT[] : Storage of inhibition data [fct_inhibit_t as per lopc_inhibit_ext.h]
                    INHIBIT[].INHIBITION : Storage of current inhibition information [full range of uint32]
  @param[in]       task_id : Task identifier of inhibition manager [fct_inhibit_storage_size_t as per lopc_inhibit_ext.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-161-0008a220
*************************************************************************************************************************/
void KMC_v_InhibitFinishCycle(fct_inhibit_t *local_inhibit_buffer, fct_inhibit_storage_t *memory, const fct_inhibit_storage_size_t task_id)
{
  uint8 i;

  /*store local value into memory*/
  if((task_id < Fct_inhibit_storage_size) && (task_id >= Fct_inhibit_task_LC_EXEC) )  //PRQA S 3355
    /* date: 2019-05-21, reviewer: Niraj Mistry, reason: Not Safety critical */
  {
    memory->INHIBIT[task_id] = *local_inhibit_buffer;
  }

  /*merge all external buffers into new local buffer*/
  local_inhibit_buffer->INHIBITION = 0u;
  for(i = 0u; i < (uint8)Fct_inhibit_storage_size; i++)
  {
    local_inhibit_buffer->INHIBITION|= memory->INHIBIT[i].INHIBITION;
  }
}

/*************************************************************************************************************************
  Functionname:    KMC_u_InhibitGetInhibition                                                                       */ /*!

  @brief           Returns the information if a specific function needs to be inhibited

  @description     Returns true if inhibit_function is set or available in local_inhibit_buffer. Tested via bitwise operation.

@startuml
Start
Partition KMC_u_InhibitGetInhibition() {
: Returns the information if a specific function needs to be inhibited;
if (inhibit condition is True for Particular Function (TaskID)) Then (True)
: Returns true;
Else (false)
: return the value as false;
endif
}
End
@enduml


  @return          ret_value : True, if inhibition is set in local buffer [TRUE, FALSE]

  @param[in]       local_inhibit_buffer : Storage of inhibition data [fct_inhibit_t as per lopc_inhibit_ext.h]
                    INHIBITION : Storage of current inhibition information [full range of uint32]
  @param[in]       inhibit_function : Inhibition information of the function which is to be tested [full range of uint32]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-162-0008a220
*************************************************************************************************************************/
uint8 KMC_u_InhibitGetInhibition(const fct_inhibit_t local_inhibit_buffer, const fct_inhibition_t inhibit_function)
{
  uint8 ret_value;

  if((local_inhibit_buffer.INHIBITION&inhibit_function) != 0u)
  {
    ret_value = TRUE;
  }
  else
  {
    ret_value = FALSE;
  }
  return ret_value;
}

#endif /* (FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_KMC) */

/** @} end defgroup */
