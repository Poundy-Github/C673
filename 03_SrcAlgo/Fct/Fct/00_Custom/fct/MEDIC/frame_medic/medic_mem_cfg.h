/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control)

PACKAGENAME:               medic_mem_cfg.h

DESCRIPTION:               memory configuration file for MEDIC 

AUTHOR:                    $Author: Nese, Raghavendra (uidp8028) $

CREATION DATE:             $Date: 2019/11/19 10:51:53CET $

VERSION:                   $Revision: 1.8.2.13 $
**************************************************************************** */
/**
@ingroup frame_medic
@{ **/
#ifndef MEDIC_MEM_CFG_H_INCLUDED
#define MEDIC_MEM_CFG_H_INCLUDED

/******************************************************************************
  MODULE DESCRIPTION
******************************************************************************/
/*!
@defgroup frame_mem_cfg MemoryConfiguration
@ingroup frame
@brief Contains the memory block sizes for MEDIC. The information of this file should be handled by GA as soon as possible. \n\n

The size in byte of each memory type. Only use values which allow 4 byte alignment. */

#define GA_MEDIC_SIZE_MEM_DATA_INTER_CYCLE                (3080u) /*!< Memory is kept over cycles and frozen using keyframes. */
#define GA_MEDIC_SIZE_MEM_DATA_INTER_CYCLE_MEAS            (3350u) /*!< Memory is kept over cycles and frozen cyclic. *//*PRQA S 0791 *//* Reviewer: Nagaraja Veerashettappa : With C99 standared its allowed*/
#define GA_MEDIC_SIZE_MEM_DATA_INTRA_CYCLE_MEAS            (200u) /*!< Memory is kept over cycles and frozen using keyframes. */
#define GA_MEDIC_SIZE_MEM_DATA_STACK                         (0u) /*!< Memory is located on stack in MEDIC_Exec. 
                                                                         //This memory is not provided externally.  
                                                                         //It only describes the size of the memory block allocated on stack similar to the external memory.*/

// #define GA_MEDIC_SIZE_MEM_DATA_INTER_CYCLE                 (484u) /*!< Memory is kept over cycles and frozen using keyframes. */
// #define GA_MEDIC_SIZE_MEM_DATA_INTER_CYCLE_MEAS            (520u) /*!< Memory is kept over cycles and frozen cyclic. *//*PRQA S 0791 *//* Reviewer: Nagaraja Veerashettappa : With C99 standared its allowed*/
// #define GA_MEDIC_SIZE_MEM_DATA_INTRA_CYCLE_MEAS            (176u) /*!< Memory is kept over cycles and frozen using keyframes. */
// #define GA_MEDIC_SIZE_MEM_DATA_STACK                         (0u) //!< Memory is located on stack in MEDIC_Exec. 


#endif /* MEDIC_MEM_CFG_H_INCLUDED */
/**@}*/
