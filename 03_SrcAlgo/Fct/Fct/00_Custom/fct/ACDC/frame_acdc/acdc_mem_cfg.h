/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC (Advanced collision detection and classification)

PACKAGENAME:               acdc_mem_cfg.h

DESCRIPTION:               Define the size of the memory blocks for ACDC

AUTHOR:                    $Author: Kramer, Andreas (uidv8254) $

CREATION DATE:             $Date: 2018/12/14 14:51:23CET $

VERSION:                   $Revision: 1.2 $
**************************************************************************** */

#ifndef ACDC_MEM_CFG_H_INCLUDED
#define ACDC_MEM_CFG_H_INCLUDED

/******************************************************************************
  INCLUDES
******************************************************************************/

/******************************************************************************
  MODULE DESCRIPTION
******************************************************************************/
/*!
@defgroup frame_mem_cfg MemoryConfiguration
@ingroup frame
@brief Contains the memory block sizes for ACDC. The information of this file should be handled by GA as soon as possible. \n\n

///@{
The size in byte of each memory type. Only use values which allow 4 byte alignment. */
#define GA_ACDC_SIZE_MEM_DATA_INTER_CYCLE                 (7000u) /*!< Memory is kept over cycles and frozen using keyframes. */
#define GA_ACDC_SIZE_MEM_DATA_INTER_CYCLE_MEAS            (100u)  /*!< Memory is kept over cycles and frozen cyclic. */
#define GA_ACDC_SIZE_MEM_DATA_INTRA_CYCLE                 (15000u)/*!< Memory is kept over all runnables of one component. */
#define GA_ACDC_SIZE_MEM_DATA_INTRA_CYCLE_MEAS            (700u)  /*!< Memory is kept over all runnables of one component and frozen cyclic. */
#define GA_ACDC_SIZE_MEM_DATA_STACK                       (0u)    /*!< Memory is located on stack in ACDC_Exec.
                                                                       //This memory is not provided externally.
                                                                       //It only describes the size of the memory block allocated on stack similar to the external memory.*/
// #define GA_ACDC_SIZE_MEM_DATA_INTER_CYCLE                 (4300u) /*!< Memory is kept over cycles and frozen using keyframes. */
// #define GA_ACDC_SIZE_MEM_DATA_INTER_CYCLE_MEAS            (44u)  /*!< Memory is kept over cycles and frozen cyclic. */
// #define GA_ACDC_SIZE_MEM_DATA_INTRA_CYCLE                 (8500u)/*!< Memory is kept over all runnables of one component. */
// #define GA_ACDC_SIZE_MEM_DATA_INTRA_CYCLE_MEAS            (400u)  /*!< Memory is kept over all runnables of one component and frozen cyclic. */
// #define GA_ACDC_SIZE_MEM_DATA_STACK                       (0u)    /*!< Memory is located on stack in ACDC_Exec.
																	  /* This memory is not provided externally.
																	   It only describes the size of the memory block allocated on stack similar to the external memory.*/


#ifdef ACDC_SIMU
#define GA_ACDC_SIZE_MEM_DATA_SIMU                        (40000u)/*!< Memory is only available in Simu */
#endif
///@}


///@}
#endif

