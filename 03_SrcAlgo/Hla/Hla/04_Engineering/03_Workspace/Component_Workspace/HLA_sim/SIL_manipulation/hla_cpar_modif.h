/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC4xx

  CPU:                    CPU-Independent

  COMPONENT:              HLA

  MODULNAME:              hla_cpar_modif.h

  DESCRIPTION:            Coding parameter manipulation functions

  CREATION DATE:          2018-10-02

  VERSION:                $Revision: 1.2 $

**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef __HLA_CPAR_MODIF_H
#define __HLA_CPAR_MODIF_H


/****************************************************************************
 * INCLUDES
 *****************************************************************************/
#include "algo_glob.h"

/****************************************************************************
 * SYMBOLIC CONSTANTS
 *****************************************************************************/

/****************************************************************************
 * TYPEDEFS
 *****************************************************************************/

/****************************************************************************
 * GLOBAL FUNCTIONS DECLARATION
 *****************************************************************************/

/** ************************************************************************************************
  \brief            Modifies HLA coding parameters 

  \pre              None
  \post             None

  \param[in]        cparsFromRec      HLA coding parameters from recording
  \param[in,out]    cparsInitialized  HLA coding parameters initialized by CParInitCPAR_HLA()

  \return           void

  \globals
                    None

  \InOutCorrelation
                    Selected parameters of \c cparsInitialized will be overwritten by the ones from
                    recording.


  \callsequence     

  \testmethod       

  \traceability
***************************************************************************************************/
void CParModifCPAR_HLA( const CPAR_HLAF_Parameter_t& cparsFromRec, 
                              CPAR_HLAF_Parameter_t& cparsInitialized
                       );

/* avoid cyclic binding ---------------------------------------------------*/
#endif /* #ifndef __HLA_CPAR_MODIF_H */
