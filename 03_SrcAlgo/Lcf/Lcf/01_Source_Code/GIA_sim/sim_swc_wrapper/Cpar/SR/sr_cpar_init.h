/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 SR

  MODULNAME:                 sr_cpar_init.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   $Log: sr_cpar_init.h  $
  CHANGES:                   Revision 1.1 2021/12/13 17:24:27CET Wang, David (Wangd3) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Cpar/SR/project.pj
  CHANGES:                   Revision 1.0 2017/03/03 10:35:25CET Sorge, Sven (uidg3181) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Cpar/SR/project.pj
  CHANGES:                   Revision 1.6 2014/04/04 16:43:08CEST Schepanek, Jakob (uidv1903) 
  CHANGES:                   fixed SrCustomFeature
  CHANGES:                   - Added comments -  uidv1903 [Apr 4, 2014 4:43:51 PM CEST]
  CHANGES:                   Change Package : 226352:1 http://mks-psad:7002/im/viewissue?selection=226352
  CHANGES:                   Revision 1.5 2014/03/20 10:26:10CET Zieringer-EXT, Peter (uidg5520) 
  CHANGES:                   adept to I390 usage
  CHANGES:                   --- Added comments ---  uidg5520 [Mar 20, 2014 10:26:11 AM CET]
  CHANGES:                   Change Package : 222140:3 http://mks-psad:7002/im/viewissue?selection=222140
  CHANGES:                   Revision 1.4 2013/10/02 11:35:08CEST Schepanek, Jakob (uidv1903) 
  CHANGES:                   i320 rte fix
  CHANGES:                   --- Added comments ---  uidv1903 [Oct 2, 2013 11:35:08 AM CEST]
  CHANGES:                   Change Package : 177148:2 http://mks-psad:7002/im/viewissue?selection=177148
  CHANGES:                   Revision 1.3 2013/08/05 08:50:29CEST Kristensen, Steen (kristensens) 
  CHANGES:                   corrected feature master flag to new naming
  CHANGES:                   --- Added comments ---  kristensens [Aug 5, 2013 8:50:29 AM CEST]
  CHANGES:                   Change Package : 178589:1 http://mks-psad:7002/im/viewissue?selection=178589
  CHANGES:                   Revision 1.2 2013/08/03 08:34:53CEST Kristensen, Steen (kristensens) 
  CHANGES:                   added new feature config flag values
  CHANGES:                   --- Added comments ---  kristensens [Aug 3, 2013 8:34:53 AM CEST]
  CHANGES:                   Change Package : 178589:1 http://mks-psad:7002/im/viewissue?selection=178589
  CHANGES:                   Revision 1.1 2013/04/09 11:11:20CEST Schepanek, Jakob (uidv1903) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SR_SignRecognition/04_Engineering/01_Source_Code/algo/00_Custom/sw_support/sr/project.pj
  CHANGES:                   Revision 1.1 2013/04/08 12:55:57CEST Kristensen, Steen (kristensens) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/TSA_TrafficSignAssist/04_Engineering/01_Source_Code/algo/00_Custom/sw_support/tsa/project.pj

**************************************************************************** */
#ifndef sr_cpar_init_h__
#define sr_cpar_init_h__


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
  Functionname:     CParInitSrRteParameters                              */ /*!
  
  @brief            Init function for SR coding parameters 
  
  @param[in]        -
  @param[out]       -
  
  @return           -
  
  @pre              -
  @post             -
  
  @author           Christian Gutmann   2013-04-05
***************************************************************************** */
int CParInitSrRteParameters(CPAR_SR_RTE_parameters_t * pCoding)
{
  /* local variable(s) */
  int retVal = 0;

  /* set values when valid pointer */
  if (pCoding != 0)
  {
    pCoding->uVersionNumber                   = SR_RTE_CODING_PARAMS_INTFVER;

    pCoding->sSigHeader.uiTimeStamp           = 0u;
    pCoding->sSigHeader.uiMeasurementCounter  = 0u;
    pCoding->sSigHeader.uiCycleCounter        = 0u;
    pCoding->sSigHeader.eSigStatus            = AL_SIG_STATE_OK;

    pCoding->enable                           = TRUE;
    pCoding->SrControlFlow                    = SR_RTE_APPL_CONTROL_FLOW_NORMAL;
    pCoding->SrCountryVariationVehicle        = SR_RTE_COUNTRY_VARIATION_ECE;

    pCoding->SrFeatureMaster                  = ( SR_RTE_FEATURE_CONFIG_CITYLIMIT     |
                                                  SR_RTE_FEATURE_CONFIG_NOCIRCLE      |
                                                  SR_RTE_FEATURE_CONFIG_SKIPFRAME     |
                                                  SR_RTE_FEATURE_CONFIG_PLAYSTREET    |
                                                  SR_RTE_FEATURE_CONFIG_DISABLED      |
                                                  SR_RTE_FEATURE_CONFIG_TRUCKSTICKER  |
                                                  SR_RTE_FEATURE_CONFIG_RECTANGULAR   |
                                                  SR_RTE_FEATURE_CONFIG_TRIANGULAR    |
                                                  SR_RTE_FEATURE_CONFIG_CIRCLE        |
                                                  SR_RTE_FEATURE_CONFIG_DIAMOND);
  pCoding->SrTsmCountryVariation            = SR_RTE_TSM_COUNTRY_VARIATION_ECE;
  pCoding->SrCustomFeature[0]               = 1;
  pCoding->SrCustomFeature[1]               = 1;
  pCoding->SrCustomFeature[2]               = 1;
  pCoding->SrCustomFeature[3]               = 1;
  pCoding->SrCustomFeature[4]               = 0;
  pCoding->SrCustomFeature[5]               = 1;
  pCoding->SrCustomFeature[6]               = 0;
  pCoding->SrCustomFeature[7]               = 0;

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

#endif // sr_cpar_init_h__
/** @} end defgroup */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
