/*! \file **********************************************************************

  COMPANY:                   Continental AG

  PROJECT:                   MFC431

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 lcf_cpar_init.h

  DESCRIPTION:               Initializer code for LCF algo tunable parameters

  AUTHOR:                    Claudia Prajescu

  CREATION DATE:             2016-03-28

  VERSION:                   $$


  ---*/ /*---
  CHANGES:                   $$


**************************************************************************** */

#ifndef lcf_cpar_init_h__
#define lcf_cpar_init_h__

#include "algo_glob.h"

#ifdef __cplusplus
extern "C" 
{
#endif

#ifdef LCF_TUN_PAR_LDP_INTFVER
#if (LCF_TUN_PAR_LDP_INTFVER == 0x1)
void CParInitCPAR_LCF_TunParamsLDP(LCF_TunParamsLDP_t* const pCParLdp);
#else
void CParInitCPAR_LCF_TunParamsLDP(CPAR_LCF_TunParamsLDP_t* const pCParLdp);
#endif
#endif

#ifdef LCF_TUN_PAR_LKA_INTFVER
#if (LCF_TUN_PAR_LKA_INTFVER == 0x1)
void CParInitCPAR_LCF_TunParamsLKA(LCF_TunParamsLKA_t* const pCParLka);
#else
void CParInitCPAR_LCF_TunParamsLKA(CPAR_LCF_TunParamsLKA_t* const pCParLka);
#endif
#endif

#ifdef LCF_TUN_PAR_KMC_INTFVER
#if (LCF_TUN_PAR_KMC_INTFVER == 0x1)
void CParInitCPAR_LCF_TunParamsKMC(LCF_TunParamsKMC_t* const pCParKmc);
#else
void CParInitCPAR_LCF_TunParamsKMC(CPAR_LCF_TunParamsKMC_t* const pCParKmc);
#endif
#endif

#ifdef LCF_TUN_PAR_DMC_INTFVER
#if (LCF_TUN_PAR_DMC_INTFVER == 0x1)
void CParInitCPAR_LCF_TunParamsDMC(LCF_TunParamsDMC_t* const pCParDmc);
#else
void CParInitCPAR_LCF_TunParamsDMC(CPAR_LCF_TunParamsDMC_t* const pCParDmc);
#endif
#endif

#ifdef LCF_CPAR_INTFVER
int CParInitLcf(LCF_CPAR_Parameters_t *pCoding);
#endif

#ifdef __cplusplus
}
#endif

#endif
