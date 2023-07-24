/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_adapted.h

  DESCRIPTION:               Modified functions from CML library

  AUTHOR:                    George Grosu

  CREATION DATE:             09.06.2017

  VERSION:                   $Revision: 1.2 $

**************************************************************************** */
#include "rtwtypes.h"
#include "algo_glob.h"
#include <gmem.h>

#ifndef __CML_ADAPTED_H__
#define __CML_ADAPTED_H__ //avoid double inclusion

//#define CML_f_IsNonZero(value) (CML_f_Abs(value) >= CML_f_AlmostZero) // F32_IS_NZERO
#define LCF_CML_f_IsNonZero(value) (CML_f_Abs(value) >= LCF_CML_f_AlmostZero) // F32_IS_NZERO

//#define CML_f_AlmostZero (1e-15f)
#define LCF_CML_f_AlmostZero (1e-20f)

/*! number of elements in a 2x2 matrix */
#define LCF_MTRX_2X2_NOF_ELEMENTS 4
/*! number of elements in a 3x3 matrix */
#define LCF_MTRX_3X3_NOF_ELEMENTS 9

boolean_T LCF_b_InvertMatrixCramer2(float32 a_res[LCF_MTRX_2X2_NOF_ELEMENTS], float32 a_in[LCF_MTRX_2X2_NOF_ELEMENTS]);
boolean_T LCF_b_InvertMatrixCramer3(float32 a_res[LCF_MTRX_3X3_NOF_ELEMENTS], float32 a_in[LCF_MTRX_3X3_NOF_ELEMENTS]);
void LCF_CML_v_InvertMatrix(CML_t_Matrix* p_MatrixRes, CML_t_Matrix* p_MatrixA);

#endif
