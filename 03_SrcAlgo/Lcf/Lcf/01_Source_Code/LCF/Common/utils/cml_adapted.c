/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_adapted.c

  DESCRIPTION:               Modified functions from CML library

  AUTHOR:                    George Grosu

  CREATION DATE:             09.06.2017

  VERSION:                   $Revision: 1.3 $

**************************************************************************** */

#include "cml_adapted.h"


//StAr
/*****************************************************************************
  Functionname:    LCF_b_InvertMatrixCramer2                        */ /*!

  @brief           Compute matrix inverse for matrix size 2x2

  @description     This function compute matrix inverse: Res = inv(A)
                   Uses Cramers Rule for matrix size 2x2.
                   If A = |a b| and det(A) = (ad-bc),
                          |c d|
                   det(A) should be a non-zero value, then,
                   Inverse of A, inv(A) = (1/det(A))* | d -b|
                                                      |-c  a|

  @param[in,out]   a_in : matrix to be inversed.
                          [Full range of float32]
                       ATTENTION! This matrix is overwritten with the identity matrix.
  @param[in,out]   a_res : result matrix, containing the inverse of A

  @return          void

  @author          sebastian.schwarzkopf@continental-corporation.com

*****************************************************************************/
/* remove inline on 20211119*/
boolean_T LCF_b_InvertMatrixCramer2(float32 a_res[LCF_MTRX_2X2_NOF_ELEMENTS], float32 a_in[LCF_MTRX_2X2_NOF_ELEMENTS])
{
  float32 f_temp  = 0.0f;   /* temporary variable */
  boolean_T b_ret   = FALSE;  /* return value */


  /* Cramers Rule for matrix size == 2 */
  f_temp = (a_in[0] * a_in[3]) - (a_in[1] * a_in[2]);
  if(LCF_CML_f_IsNonZero(f_temp))//GeGr: Modified precision
  {
    f_temp = 1.0F / f_temp;

    a_res[0] = a_in[3]  * f_temp;
    a_res[1] = -a_in[1] * f_temp;
    a_res[2] = -a_in[2] * f_temp;
    a_res[3] = a_in[0]  * f_temp;

    b_ret = TRUE;
  } /* if(CML_f_IsNonZero(f_temp)) */


  return b_ret;
} /* LCF_b_InvertMatrixCramer2() */


/*****************************************************************************
  Functionname:    LCF_b_InvertMatrixCramer3                                */ /*!

  @brief           Compute matrix inverse for matrix size 3x3

  @description     This function compute matrix inverse: Res = inv(A)
                   Uses Cramers Rule for matrix size 3x3.
                   If A is a 3x3 matrix and det(A) is the determinant of matrix,
                   which must be non-zero, then inverse of A will be equal to
                   Adjoint matrix of A divided by det(A).

  @param[in,out]   a_in : matrix to be inversed.
                          [Full range of float32]
                       ATTENTION! This matrix is overwritten with the identity matrix.
  @param[in,out]   a_res : result matrix, containing the inverse of A

  @return          void

  @author          sebastian.schwarzkopf@continental-corporation.com

*****************************************************************************/
/* remove inline on 20211119*/
boolean_T LCF_b_InvertMatrixCramer3(float32 a_res[LCF_MTRX_3X3_NOF_ELEMENTS], float32 a_in[LCF_MTRX_3X3_NOF_ELEMENTS])
{
  float32 f_temp  = 0.0f;   /* temporary variable */
  boolean_T b_ret   = FALSE;  /* return value */


  /* Cramers Rule for matrix size == 3 */
  f_temp = (((a_in[0] * a_in[4]) - (a_in[3] * a_in[1])) * a_in[8]) +
           (((a_in[3] * a_in[7]) - (a_in[6] * a_in[4])) * a_in[2]) +
           (((a_in[6] * a_in[1]) - (a_in[0] * a_in[7])) * a_in[5]);

  if(LCF_CML_f_IsNonZero(f_temp))//AlFe: Modified precision
  {
    f_temp = 1.0F / f_temp;

    a_res[0] = ((a_in[4] * a_in[8]) - (a_in[5] * a_in[7])) * f_temp;
    a_res[1] = ((a_in[2] * a_in[7]) - (a_in[1] * a_in[8])) * f_temp;
    a_res[2] = ((a_in[1] * a_in[5]) - (a_in[2] * a_in[4])) * f_temp;
    a_res[3] = ((a_in[5] * a_in[6]) - (a_in[3] * a_in[8])) * f_temp;
    a_res[4] = ((a_in[0] * a_in[8]) - (a_in[2] * a_in[6])) * f_temp;
    a_res[5] = ((a_in[2] * a_in[3]) - (a_in[0] * a_in[5])) * f_temp;
    a_res[6] = ((a_in[3] * a_in[7]) - (a_in[4] * a_in[6])) * f_temp;
    a_res[7] = ((a_in[1] * a_in[6]) - (a_in[0] * a_in[7])) * f_temp;
    a_res[8] = ((a_in[0] * a_in[4]) - (a_in[1] * a_in[3])) * f_temp;

    b_ret = TRUE;
  } /* if(CML_f_IsNonZero(f_temp)) */


  return b_ret;
} /* LCF_b_InvertMatrixCramer3() */


/*****************************************************************************
  Functionname:    CML_v_InvertMatrix                                   */ /*!

  @brief           Compute matrix inverse.

  @description     Compute matrix inverse: Res = inv(A)
                   Uses Gauss-Jordan elimination with partial pivoting.
                   For matrices upto 3x3, determinant is found, singularity is
                   checked and processing is done, whereas for higher order
                   matrices, matrix singularity is determined during the
                   processing.

  @param[in,out]   p_MatrixA : matrix to be inversed.
                               Range for p_MatrixA->Desc.row [Full range of uint8]
                               Range for p_MatrixA->Desc.col [Full range of uint8]
                               Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixA->pData 
                               [Valid pointer with data in full range of float32]
                   The largest element on the each column MUST BE greater than
                   the tolerance value (1e-10F). Otherwise function call will
                   result in assertion fail.
                   ATTENTION! This matrix is overwritten with the identity matrix.
  @param[in,out]   p_MatrixRes : result matrix, containing the inverse of A

  @return          void

  @author          Dan Oprisan

*****************************************************************************/
void LCF_CML_v_InvertMatrix(CML_t_Matrix* p_MatrixRes, CML_t_Matrix* p_MatrixA)
{
  boolean_T bRet = FALSE;
  uint32 u_Idx1, u_Idx2, u_col, u_row, u_pos1, u_pos2;
  float32 f_Temp, f_MaxElem;
  float32 f_PivElem       = 1.0F;
  float32 f_InvPivElem    = 1.0F;
  const float32 f_Tol     = 1e-20F;               /* tolerance */ //StAR - avoid division by zero
  float32* p_DataA        = p_MatrixA->pData;     /* get pointer to matrix data */
  float32* p_DataRes      = p_MatrixRes->pData;   /* get pointer to matrix data */

#if CML_MatrixBoundsCheckOn
  /* check if matrix is square */
  if (  (p_MatrixA->Desc.col != (uint8)0)
     && (p_MatrixA->Desc.col == p_MatrixA->Desc.row)
     && (p_MatrixA->pData != p_MatrixRes->pData)
     && (p_MatrixRes->Desc.maxsize >= (p_MatrixA->Desc.col * p_MatrixA->Desc.row)) )
  {
#endif

    if (p_MatrixA->Desc.col == (uint8)1U)
    {
      /* simple division for matrix size == 1 */
      if(CML_f_IsNonZero(p_DataA[0]))
      {
        *p_DataRes = 1.0F / (*p_DataA);
        bRet = TRUE;
      }
    }
    else if (p_MatrixA->Desc.col == (uint8)2U)
    {
      /* Cramers Rule for matrix size == 2 */
      bRet = LCF_b_InvertMatrixCramer2(p_DataRes, p_DataA);
    }
    else if(p_MatrixA->Desc.col == (uint8)3U)
    {
      /* Cramers Rule for matrix size == 3 */
      bRet = LCF_b_InvertMatrixCramer3(p_DataRes, p_DataA);
    }
    else /* (A->Desc.col > (uint8)2U) */
    {
      /* Gauss-Jordan elimination with partial pivoting */

      bRet = TRUE;
      u_col = 0UL;
      CML_v_CreateIdentityMatrix(p_MatrixRes, (uint32)p_MatrixA->Desc.row);  /* set result matrix as identity */
      do
      {
        /* find largest element on the selected column */
        /* and use as pivot element                    */
        u_row = u_col;
        u_pos1 = u_col + (u_col * (uint32)p_MatrixA->Desc.col);
        f_MaxElem = 0.0F;
        for (u_Idx1 = u_col; u_Idx1<(uint32)p_MatrixA->Desc.col; u_Idx1++)
        {
          f_Temp = CML_f_Abs(p_DataA[u_pos1]);
          if (f_Temp > f_MaxElem)
          {
            f_MaxElem = f_Temp;
            f_PivElem = p_DataA[u_pos1];
            u_row = u_Idx1;
          }
          u_pos1 += (uint32)p_MatrixA->Desc.col;
        }

        /* exit routine if pivot element is very small => matrix not inversible */
        if (f_MaxElem >= f_Tol)
        {
          /* do pivoting to reduce column to identity matrix */
          bRet = TRUE;

          /* now swap rows to put the pivot element on the diagonal */
          /* do the same operation for the result matrix */
          if (u_row != u_col)
          {
            /* get pointer to matrix data */
            u_pos1 = (uint32)p_MatrixA->Desc.col * u_row ;
            u_pos2 = (uint32)p_MatrixA->Desc.col * u_col;

            for (u_Idx1 = u_col; u_Idx1<(uint32)p_MatrixA->Desc.col; u_Idx1++)  /* only nonzero elements */
            {
              f_Temp = p_DataA[u_Idx1 + u_pos1];
              p_DataA[u_Idx1 + u_pos1] = p_DataA[u_Idx1 + u_pos2];
              p_DataA[u_Idx1 + u_pos2] = f_Temp;
            }
            for (u_Idx1 = 0U; u_Idx1<(uint32)p_MatrixA->Desc.col; u_Idx1++)    /* all elements */
            {
              f_Temp = p_DataRes[u_Idx1 + u_pos1];
              p_DataRes[u_Idx1 + u_pos1] = p_DataRes[u_Idx1 + u_pos2];
              p_DataRes[u_Idx1 + u_pos2] = f_Temp;
            }
          }

          /* divide row by the pivot element => pivot becomes 1 */
          /* do the same operation for the result matrix */
          u_pos1 = u_col*(uint32)p_MatrixA->Desc.col;
          f_InvPivElem = 1.0F/f_PivElem;
          for (u_Idx1 = u_col; u_Idx1<(uint32)p_MatrixA->Desc.col; u_Idx1++)  /* only nonzero elements */
          {
            p_DataA[u_Idx1+u_pos1] *= f_InvPivElem;
          }
          for (u_Idx1 = 0UL; u_Idx1<(uint32)p_MatrixA->Desc.col; u_Idx1++)  /* all elements */
          {
            p_DataRes[u_Idx1+u_pos1] *= f_InvPivElem;
          }

          /* now multiply the row by the right amount and substract from    */
          /* each other row to make all the remaining elements in the pivot */
          /* column zero                                                    */
          for (u_Idx1 = 0UL; u_Idx1<(uint32)p_MatrixA->Desc.col; u_Idx1++)   /* loop other rows */
          {
            if (u_Idx1 != u_col)
            {
              u_pos1  = u_Idx1  *(uint32)p_MatrixA->Desc.col;
              u_pos2  = u_col*(uint32)p_MatrixA->Desc.col;

              /* use first element is row as scaling coefficient */
              f_Temp = p_DataA[u_col + u_pos1];

              /* substract pivot row multiplied by scaling from other row */
              /* do the same operation for the result matrix */
              for (u_Idx2 = u_col; u_Idx2<(uint32)p_MatrixA->Desc.col; u_Idx2++)  /* only nonzero elements */
              {
                p_DataA[u_Idx2 + u_pos1] -= p_DataA[u_Idx2 + u_pos2] * f_Temp;
              }
              for (u_Idx2 = 0UL; u_Idx2<(uint32)p_MatrixA->Desc.col; u_Idx2++)  /* all elements */
              {
                p_DataRes[u_Idx2 + u_pos1] -= p_DataRes[u_Idx2 + u_pos2] * f_Temp;
              }
            }
          }

          /* goto next column */
          u_col++;
        }

        else
        {
          bRet = FALSE;
        }
      } while ( bRet && (u_col < (uint32)p_MatrixA->Desc.col));  /* quit if finished or if matrix isn't inversible */
    }

#if CML_MatrixBoundsCheckOn
  }
#endif

  if (bRet)
  {
    /* create description for result matrix */
    p_MatrixRes->Desc.col = p_MatrixA->Desc.col;
    p_MatrixRes->Desc.row = p_MatrixA->Desc.row;
  }
  else
  {
    /* set empty matrix */
    p_MatrixRes->Desc.col = (uint8)0;
    p_MatrixRes->Desc.row = (uint8)0;
    /* Deactivate QA-C warning 3112; Reviewer: S. Schwarzkopf;
       Date: 04.12.2014; Reason: macro will be routed to assert() in simulation
       environment.
       Review-ID: 3942463 */
    /* PRQA S 3112 1 */
    //CML_ASSERT(FALSE);
  }
}
