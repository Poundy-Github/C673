/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_eba.h

DESCRIPTION:               header of the DIM driver 

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2019/11/25 15:17:42CET $

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            1.4
  
**************************************************************************** */
/**
@ingroup Medic_dim
@{ **/
#ifndef DIM_EBA_H_INCLUDED
#define DIM_EBA_H_INCLUDED

#if(MEDIC_CFG_DRIVER_INTENTION_MONITORING)
/* ****************************************************************
    TYPEDEF ENUM DimEBAHypothesisIdx_t
    **************************************************************** */
/*! @brief DIM EBA Hypthesis IDs

    @general Identifiers for different DIM EBA Hypothesis
    
    @conseq [None]

    @attention [None]
    
    */
typedef enum {
  DIM_EBA_HYP_IDX_ATTENTION = 0u, /*!< DIM EBA Attention Hypothesis identification */
  DIM_EBA_HYP_IDX_FEEDBACK  = 1u,/*!< DIM EBA Feedback Hypothesis identification */
  DIM_EBA_HYP_IDX_ACTIVITY  = 2u /*!< DIM EBA Activity Hypothesis identification */
} DimEBAHypothesisIdx_t;

#endif
#endif
/**@}*/


