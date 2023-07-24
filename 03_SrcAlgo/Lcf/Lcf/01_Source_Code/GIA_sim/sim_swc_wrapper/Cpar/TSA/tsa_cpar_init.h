/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 TSA

  MODULNAME:                 tsa_cpar_init.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   $Log: tsa_cpar_init.h  $
  CHANGES:                   Revision 1.1 2021/12/13 17:24:31CET Wang, David (Wangd3) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Cpar/TSA/project.pj
  CHANGES:                   Revision 1.0 2017/03/03 10:35:28CET Sorge, Sven (uidg3181) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Cpar/TSA/project.pj
  CHANGES:                   Revision 1.2 2014/04/02 09:01:29CEST Rueber, Johannes02 (uidw2478) 
  CHANGES:                   enabled WWA
  CHANGES:                   - Added comments -  uidw2478 [Apr 2, 2014 9:01:29 AM CEST]
  CHANGES:                   Change Package : 191495:2 http://mks-psad:7002/im/viewissue?selection=191495
  CHANGES:                   Revision 1.1 2013/04/08 12:55:57CEST Kristensen, Steen (kristensens) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/TSA_TrafficSignAssist/04_Engineering/01_Source_Code/algo/00_Custom/sw_support/tsa/project.pj

**************************************************************************** */
#ifndef tsa_cpar_init_h__
#define tsa_cpar_init_h__


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "algo_glob.h"

#ifdef __cplusplus
extern "C" 
{
#endif


/*****************************************************************************
  FUNCTION
*****************************************************************************/

/* *****************************************************************************
  Functionname:     CParInitTsaRteParameters                              */ /*!
  
  @brief            Init function for TSA coding parameters 
  
  @param[in]        -
  @param[out]       -
  
  @return           -
  
  @pre              -
  @post             -
  
  @author           Christian Gutmann   2013-04-05
***************************************************************************** */
int CParInitTsaRteParameters(CPAR_TSA_RTE_parameters_t * pCoding)
{
  /* local variable(s) */
  int retVal = 0;

  /* set values when valid pointer */
  if (pCoding != 0)
  {
    pCoding->uVersionNumber                   = TSA_RTE_CODING_PARAMS_INTFVER;

    pCoding->sSigHeader.uiTimeStamp           = 0u;
    pCoding->sSigHeader.uiMeasurementCounter  = 0u;
    pCoding->sSigHeader.uiCycleCounter        = 0u;
    pCoding->sSigHeader.eSigStatus            = AL_SIG_STATE_OK;

    pCoding->enable                           = TRUE;
    pCoding->TsaControlFlow                   = TSA_RTE_CONTROL_FLOW_NORMAL;
    pCoding->TsaCountryVariationVehicle       = TSA_RTE_COUNTRY_VARIATION_ECE;

    pCoding->countryConfig                    = ( TSA_RTE_COUNTRY_CONFIG_SLA_SYSTEM_LEVEL_HIGH |
                                                  TSA_RTE_COUNTRY_CONFIG_HMI_DISPLAY_SUPPL_SIGNS_NOT_RESOLVED |
                                                  TSA_RTE_COUNTRY_CONFIG_SLA_HMI_ENABLE_SPDLMT_END |
                                                  TSA_RTE_COUNTRY_CONFIG_SLA_ENABLE_IMPLICIT_RULES |
                                                  TSA_RTE_COUNTRY_CONFIG_NPA_CNTRY_ENABLED |
                                                  TSA_RTE_COUNTRY_CONFIG_WWA_CNTRY_ENABLED );
  }
  /* invalid pointer, set error return value */
  else
  {
    retVal = 1;
  }

  /* return */
  return retVal;
}


#ifdef __cplusplus
}
#endif

#endif // tsa_cpar_init_h__
/** @} end defgroup */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
