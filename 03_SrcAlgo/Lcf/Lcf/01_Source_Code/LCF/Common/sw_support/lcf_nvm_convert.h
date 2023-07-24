/*! \file **********************************************************************

  COMPANY:                   Continental AG

  PROJECT:                   MFC431

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 lcf_nvm_convert.h

  DESCRIPTION:               Conversion code for LCF NVM data (L3D_ALGO_26014)

  AUTHOR:                    Elena Nastasa

  CREATION DATE:             2018-03-06

  VERSION:                   $$


  ---*/ /*---
  CHANGES:                   $$


*****************************************************************************/

#ifndef lcf_nvm_convert_h__
#define lcf_nvm_convert_h__

#include "algo_glob.h"

#ifdef __cplusplus
extern "C"
{
#endif

#if LCF_IUC2SOC_INTFVER >= 2
sint32 NvmConvertNVM_LcfLearningData(const void* const pSource, NVM_LcfLearningData_t* const pDest);
#else
void NvmConvertNVM_LcfLearningData(void);
#endif

#ifdef __cplusplus
}
#endif												
 
#endif