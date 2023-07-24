/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_mtrx.c

  DESCRIPTION:               implements matrix computations

  AUTHOR:                    Dan Oprisan

  CREATION DATE:             20.01.2009

  VERSION:                   $Revision: 1.34 $

  ---*/ /*---
  CHANGES:                   $Log: cml_mtrx.c  $
  CHANGES:                   Revision 1.34 2017/11/27 06:18:20CET A, Nandu (uidr5428) (uidr5428) 
  CHANGES:                   Replaced TRUE and FALSE with b_TRUE and b_FALSE to match the Mainstream update
  CHANGES:                   Revision 1.33 2017/11/13 06:19:27CET Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Updated cml_mtrx module functions with coding standard naming convention.
  CHANGES:                   Revision 1.32 2016/05/20 10:56:31CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.31 2016/02/02 06:08:56CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - removal of pre read to avoid bounds check error 
  CHANGES:                     and use of CML_f_MultAdd() for accumulation.
  CHANGES:                   Revision 1.30 2015/10/19 10:21:16CEST Exner, Christian (uidt8578) 
  CHANGES:                   - aligned pivo element calculation in CML_v_InvertMatrix() to the c++ version, using an precalculated inverted pivo element and multiply it onto the elements rather than dividing by it (what is slower)
  CHANGES:                   - Added comments -  uidt8578 [Oct 19, 2015 10:21:16 AM CEST]
  CHANGES:                   Change Package : 385260:1 http://mks-psad:7002/im/viewissue?selection=385260
  CHANGES:                   Revision 1.29 2015/10/12 05:42:03CEST Arulkumar-EXT, Nandu (uidr5428)
  CHANGES:                   - Fix for doxygen warning
  CHANGES:                   --- Added comments ---  uidr5428 [Oct 12, 2015 5:42:04 AM CEST]
  CHANGES:                   Change Package : 383331:1 http://mks-psad:7002/im/viewissue?selection=383331
  CHANGES:                   Revision 1.28 2015/10/06 12:09:11CEST Arulkumar-EXT, Nandu (uidr5428)
  CHANGES:                   Updated matrix inversion comment description
  CHANGES:                   --- Added comments ---  uidr5428 [Oct 6, 2015 12:09:12 PM CEST]
  CHANGES:                   Change Package : 381587:2 http://mks-psad:7002/im/viewissue?selection=381587
  CHANGES:                   Revision 1.27 2015/08/25 09:51:09CEST Arulkumar-EXT, Nandu (uidr5428)
  CHANGES:                   Updated doxygen compliant function headers
  CHANGES:                   --- Added comments ---  uidr5428 [Aug 25, 2015 9:51:10 AM CEST]
  CHANGES:                   Change Package : 360603:2 http://mks-psad:7002/im/viewissue?selection=360603
  CHANGES:                   Revision 1.26 2015/04/29 16:37:56CEST Arulkumar-EXT, Nandu (uidr5428)
  CHANGES:                   - Changes with respect to Coding Guidelines
  CHANGES:                     of variables
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 29, 2015 4:37:57 PM CEST]
  CHANGES:                   Change Package : 324617:3 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.25 2015/04/29 08:53:44CEST Arulkumar-EXT, Nandu (uidr5428)
  CHANGES:                   Edited the docu header of function CML_v_InvertMatrix
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 29, 2015 8:53:45 AM CEST]
  CHANGES:                   Change Package : 316990:1 http://mks-psad:7002/im/viewissue?selection=316990
  CHANGES:                   Revision 1.24 2015/04/28 18:12:02CEST Arulkumar-EXT, Nandu (uidr5428)
  CHANGES:                   Added check condition in function CML_v_MultiplyMatricesToSymResult
  CHANGES:                   under the macro CML_MatrixBoundsCheckOn to ensure symmetry of
  CHANGES:                   the resulting matrix
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 28, 2015 6:12:03 PM CEST]
  CHANGES:                   Change Package : 316982:1 http://mks-psad:7002/im/viewissue?selection=316982
  CHANGES:                   Revision 1.23 2015/04/28 13:25:02CEST Arulkumar-EXT, Nandu (uidr5428)
  CHANGES:                   Edited the docu header of the function CML_v_InvertMatrix.
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 28, 2015 1:25:03 PM CEST]
  CHANGES:                   Change Package : 317010:1 http://mks-psad:7002/im/viewissue?selection=317010
  CHANGES:                   Revision 1.22 2015/04/23 10:55:01CEST Arulkumar-EXT, Nandu (uidr5428)
  CHANGES:                   - Added check condition for square matrix in function
  CHANGES:                     CML_v_CopyArrayToSymMatrix
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 23, 2015 10:55:02 AM CEST]
  CHANGES:                   Change Package : 317000:1 http://mks-psad:7002/im/viewissue?selection=317000
  CHANGES:                   Revision 1.21 2015/04/22 17:35:46CEST Arulkumar-EXT, Nandu (uidr5428)
  CHANGES:                   - Edited the docu header of function CML_v_InitMatrix
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 22, 2015 5:35:47 PM CEST]
  CHANGES:                   Change Package : 316989:1 http://mks-psad:7002/im/viewissue?selection=316989
  CHANGES:                   Revision 1.20 2014/12/12 13:33:32CET Schwarzkopf, Sebastian (uidg6516)
  CHANGES:                   - added review ID to QA-C suppressions
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 12, 2014 1:33:33 PM CET]
  CHANGES:                   Change Package : 266613:12 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.19 2014/12/10 09:02:31CET Schwarzkopf, Sebastian (uidg6516)
  CHANGES:                   - suppressed QA-C warnings on pointer handling as functions are highly optimised
  CHANGES:                   - reduced McCabe index of CML_v_InvertMatrix()
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 10, 2014 9:02:32 AM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.18 2014/12/04 17:16:25CET Schwarzkopf, Sebastian (uidg6516)
  CHANGES:                   - suppressed QA-C warning
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 4, 2014 5:16:26 PM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.17 2014/12/01 13:53:54CET Rosenbaum-EXT, Lars (uidg7214)
  CHANGES:                   3x3 matrix invert using cramers rule
  CHANGES:                   --- Added comments ---  uidg7214 [Dec 1, 2014 1:53:55 PM CET]
  CHANGES:                   Change Package : 285801:1 http://mks-psad:7002/im/viewissue?selection=285801
  CHANGES:                   Revision 1.16 2014/11/28 10:55:24CET Friebertshaeuser, Markus (uidt0551)
  CHANGES:                   make input matrix const
  CHANGES:                   --- Added comments ---  uidt0551 [Nov 28, 2014 10:55:24 AM CET]
  CHANGES:                   Change Package : 199714:3 http://mks-psad:7002/im/viewissue?selection=199714
  CHANGES:                   Revision 1.15 2014/07/14 15:38:20CEST Oprisan, Dan (oprisand)
  CHANGES:                   - fix Matrix Bounds Check and throw assert if inconsitency is found.
  CHANGES:                   --- Added comments ---  oprisand [Jul 14, 2014 3:38:20 PM CEST]
  CHANGES:                   Change Package : 248463:1 http://mks-psad:7002/im/viewissue?selection=248463
  CHANGES:                   Revision 1.14 2014/03/27 11:21:23CET Schwarzkopf, Sebastian (uidg6516)
  CHANGES:                   - fixed some QA-C- and Styleguide-issues
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 27, 2014 11:21:24 AM CET]
  CHANGES:                   Change Package : 227281:2 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.13 2014/03/25 11:34:30CET Schwarzkopf, Sebastian (uidg6516)
  CHANGES:                   - fixed Doxygen comments
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 25, 2014 11:34:30 AM CET]
  CHANGES:                   Change Package : 227281:1 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.12 2013/07/26 13:11:11CEST Zechner, Stefan (uidt9253)
  CHANGES:                   - bugfix: faulty non-c standard const declaration in some functions allowed passing a const pointer to the functions and functions writes into these pointers
  CHANGES:                   --- Added comments ---  uidt9253 [Jul 26, 2013 1:11:11 PM CEST]
  CHANGES:                   Change Package : 162889:30 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:                   Revision 1.11 2013/07/10 15:42:24CEST Meschenmoser, Daniel (uidu0849)
  CHANGES:                   - correct function name AlgoMtrxTrsp to CML_v_TransposeMatrix
  CHANGES:                   --- Added comments ---  uidu0849 [Jul 10, 2013 3:42:24 PM CEST]
  CHANGES:                   Change Package : 159154:28 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.10 2013/07/08 13:08:36CEST Schlensag, Andreas (schlensaga)
  CHANGES:                   Add matrix transpose function
  CHANGES:                   --- Added comments ---  schlensaga [Jul 8, 2013 1:08:38 PM CEST]
  CHANGES:                   Change Package : 185100:3 http://mks-psad:7002/im/viewissue?selection=185100
  CHANGES:                   Revision 1.9 2013/06/05 14:08:25CEST Meschenmoser, Daniel (uidu0849)
  CHANGES:                   - remove inclusion of cml_misc.h
  CHANGES:                   --- Added comments ---  uidu0849 [Jun 5, 2013 2:08:25 PM CEST]
  CHANGES:                   Change Package : 159154:28 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.8 2013/05/28 14:27:22CEST Kozek-EXT, Werner (uidt8688)
  CHANGES:                   1) LINT/MISRA cleanup 2) skip math.h header 3) tab/spaces conformity
  CHANGES:                   --- Added comments ---  uidt8688 [May 28, 2013 2:27:22 PM CEST]
  CHANGES:                   Change Package : 177735:1 http://mks-psad:7002/im/viewissue?selection=177735
  CHANGES:                   Revision 1.7 2013/05/26 22:56:38CEST Kozek-EXT, Werner (uidt8688)
  CHANGES:                   added Cholesky factorization and triangular matrix methods to be used by square-root Kalman
  CHANGES:                   filter and/or least squares estimatiors
  CHANGES:                   --- Added comments ---  uidt8688 [May 26, 2013 10:56:39 PM CEST]
  CHANGES:                   Change Package : 177735:1 http://mks-psad:7002/im/viewissue?selection=177735
  CHANGES:                   Revision 1.6 2013/05/03 09:57:36CEST Meschenmoser, Daniel (uidu0849)
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   - use new standard type names, e.g. float32 instead of f32_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:57:36 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.5 2012/09/25 13:47:35CEST Meschenmoser, Daniel (uidu0849)
  CHANGES:                   - remove Misra / Lint warning
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 25, 2012 1:47:38 PM CEST]
  CHANGES:                   Change Package : 159154:7 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.4 2012/09/25 13:18:01CEST Oprisan, Dan (oprisand)
  CHANGES:                   - bugfix in CML_v_CreateIdentityMatrix()
  CHANGES:                   --- Added comments ---  oprisand [Sep 25, 2012 1:18:06 PM CEST]
  CHANGES:                   Change Package : 139701:10 http://mks-psad:7002/im/viewissue?selection=139701
  CHANGES:                   Revision 1.3 2012/09/20 13:29:43CEST Meschenmoser, Daniel (uidu0849)
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:43 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2012/09/20 13:19:55CEST Meschenmoser, Daniel (uidu0849)
  CHANGES:                   - remove German special characters in comments and review tags
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:19:55 PM CEST]
  CHANGES:                   Change Package : 159154:2 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:16CEST Meschenmoser, Daniel (uidu0849)
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cml_ext.h"

/* Deactivate QA-C warnings 0488, 0489, 0491; Reviewer: S. Schwarzkopf; Date: 09.12.2014;
   Reason: Matrix functions need pointer arithmetics due to interface issues and
   a high degree of optimisation. They are proven in use.
   Review-ID: 3942463 */
/* PRQA S 0488 EOF */
/* PRQA S 0489 EOF */
/* PRQA S 0491 EOF */


/*****************************************************************************
  LOCAL DEFINES
*****************************************************************************/
/*! number of elements in a 2x2 matrix */
#define MTRX_2X2_NOF_ELEMENTS 4
/*! number of elements in a 3x3 matrix */
#define MTRX_3X3_NOF_ELEMENTS 9


/*****************************************************************************
  LOCAL INLINES
*****************************************************************************/

/* Deactivate QA-C warning 3447; Reviewer: S. Schwarzkopf; Date: 05.12.2014;
   Reason: ALGO_INLINE is defined to have no external linkage on target platform.
   Review-ID: 3942463 */
/* PRQA S 3447 CML_INLINES */

CML_INLINE boolean CML_b_invertMatrixCramer2(float32 a_res[MTRX_2X2_NOF_ELEMENTS], float32 a_in[MTRX_2X2_NOF_ELEMENTS]);
CML_INLINE boolean CML_b_invertMatrixCramer3(float32 a_res[MTRX_3X3_NOF_ELEMENTS], float32 a_in[MTRX_3X3_NOF_ELEMENTS]);

/* PRQA L:CML_INLINES */


/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/*****************************************************************************
  Functionname:    CML_v_initMatrix                                      */ /*!

  @brief           Matrix initialization with a const value

  @description     This function initializes all the elements of the matrix
                   with a const value.
                   NOTE: RowNr and ColNr are expected to be values not
                   exceeding 8 bits.
                   CAUTION: u_RowNr*u_ColNr must not exceed A->Desc.maxsize

  @param[in,out]   p_Matrix :  matrix o be filled
                               Range for p_Matrix->Desc.maxsize [Full range of uint16]
  @param[out]      f_Val :     value used for filling
                               [Full range of float32]
  @param[in]       u_RowNr :   Row dimension of the matrix to be created
                               [Full range of uint8]
  @param[in]       u_ColNr :   Column dimension of the matrix to be created
                               [Full range of uint8]

  @return          void

  @author          Dan Oprisan

*****************************************************************************/
void CML_v_initMatrix(CML_t_Matrix* p_Matrix, uint32 u_RowNr, uint32 u_ColNr, float32 f_Val)
{
  uint32 u_Idx;
  uint32 u_size = u_ColNr * u_RowNr;
  float32* p_MatrixData;  /* pointer to matrix data */

#if CML_MatrixBoundsCheckOn
  if ( p_Matrix->Desc.maxsize >= u_size )
  {
#endif

    /* set new dimension */
    p_Matrix->Desc.col = (uint8)u_ColNr;
    p_Matrix->Desc.row = (uint8)u_RowNr;

    /* init elements */
    p_MatrixData = p_Matrix->pData;
    for (u_Idx = 0u; u_Idx < u_size; u_Idx++)
    {
      p_MatrixData[u_Idx] = f_Val;
    }

#if CML_MatrixBoundsCheckOn
  }
  else
  {
    /* Return empty matrix */
    p_Matrix->Desc.col = (uint8)0;
    p_Matrix->Desc.row = (uint8)0;
    CML_ASSERT(b_FALSE);
  }
#endif
}

/*****************************************************************************
  Functionname:    CML_v_createIdentityMatrix                           */ /*!

  @brief           Initialises matrix with identity matrix

  @description     This function initializes the given matrix with an
                   identity matrix of the provided size.
                   NOTE: Value for row/column is expected not to exceed 8 bits
                   CAUTION: Size of the matrix (rows x columns) must not
                   exceed A->Desc.maxsize

  @param[in,out]   p_Matrix :  matrix o be filled (square matrix)
                               Range for p_Matrix->Desc.maxsize [Full range of uint16]
  @param[in]       u_Size :    no. of row/col square matrix (u_Size x u_Size)
                               [Full range of uint8]

  @return          void

  @author          Dan Oprisan

*****************************************************************************/
void CML_v_createIdentityMatrix(CML_t_Matrix* p_Matrix, uint32 u_Size)
{
  uint32 u_Idx;
  uint32 u_SizeSquare = SQR(u_Size);
  float32* p_MatrixData;  /* pointer to matrix data */

#if CML_MatrixBoundsCheckOn
  if ( p_Matrix->Desc.maxsize >= u_SizeSquare )
  {
#endif

    /* set new dimension */
    p_Matrix->Desc.col = (uint8)u_Size;
    p_Matrix->Desc.row = (uint8)u_Size;

    /* fill with zero */
    CML_v_initMatrix(p_Matrix, u_Size, u_Size, 0.0F);

    /* set diagonal to one */
    p_MatrixData = p_Matrix->pData;
    for (u_Idx = 0u; u_Idx < u_SizeSquare; u_Idx += ((uint32)p_Matrix->Desc.col + 1u))
    {
      p_MatrixData[u_Idx] = 1.0F;
    }

#if CML_MatrixBoundsCheckOn
  }
  else
  {
    /* Set empty matrix */
    p_Matrix->Desc.col = (uint8)0;
    p_Matrix->Desc.row = (uint8)0;
    CML_ASSERT(b_FALSE);
  }
#endif
}

/*****************************************************************************
  Functionname:    CML_v_addMatrices                                    */ /*!

  @brief           Matrix addition (inplace/outplace). A or B can be same as Res

  @description     This function performs matrix addition (inplace/outplace) of
                   two matrices A and B with same dimesions and store the result
                   in a resultant matrix.
                   The matrix A or B can be same as resultant matrix.
                   [Res] = [A] + [B]

  @param[in]       p_MatrixA : First Addend matrix (source)
                               Range for p_MatrixA->Desc.row [Full range of uint8]
                               Range for p_MatrixA->Desc.col [Full range of uint8]
                               Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixA->pData 
                               [Valid pointer with data in full range of float32]
  @param[in]       p_MatrixB : Second Addend matrix (source)
                               Range for p_MatrixB->Desc.row [Full range of uint8]
                               Range for p_MatrixB->Desc.col [Full range of uint8]
                               Range for p_MatrixB->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixB->pData 
                               [Valid pointer with data in full range of float32]
                               Overflow may occur when one or more input values in both
                               matrices are at the defined range extremities.

  @param[out]      p_MatrixRes : Result Sum matrix

  @return          void

  @author          Dan Oprisan

*****************************************************************************/
void CML_v_addMatrices(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA, const CML_t_Matrix* p_MatrixB)
{
  uint32 u_Idx;
  uint32 u_size = (uint32)p_MatrixA->Desc.col * (uint32)p_MatrixA->Desc.row;
  float32* p_DataA = p_MatrixA->pData;       /* get pointer to matrix data */
  float32* p_DataB = p_MatrixB->pData;       /* get pointer to matrix data */
  float32* p_DataRes = p_MatrixRes->pData;   /* get pointer to result matrix data */

#if CML_MatrixBoundsCheckOn
  /* check if matrices are equal and Res is big enough */
  if (  (p_MatrixA->Desc.col== p_MatrixB->Desc.col)
     && (p_MatrixA->Desc.row == p_MatrixB->Desc.row)
     && (p_MatrixRes->Desc.maxsize >= u_size))
  {
#endif

    /* add elements */
    if (p_DataA == p_DataRes)
    {
      for (u_Idx = 0u; u_Idx < u_size; u_Idx++)
      {
        p_DataRes[u_Idx] += p_DataB[u_Idx];
      }
    }
    else if (p_DataB == p_DataRes)
    {
      for (u_Idx = 0u; u_Idx < u_size; u_Idx++)
      {
        p_DataRes[u_Idx] += p_DataA[u_Idx];
      }
    }
    else
    {
      for (u_Idx = 0u; u_Idx < + u_size; u_Idx++)
      {
        p_DataRes[u_Idx] = p_DataA[u_Idx] + p_DataB[u_Idx];
      }
    }

    /* create description for result matrix */
    p_MatrixRes->Desc.col = p_MatrixA->Desc.col;
    p_MatrixRes->Desc.row = p_MatrixA->Desc.row;


#if CML_MatrixBoundsCheckOn
  }
  else
  {
    /* set empty matrix */
    p_MatrixRes->Desc.col = (uint8)0;
    p_MatrixRes->Desc.row = (uint8)0;
    CML_ASSERT(b_FALSE);
  }
#endif
}

/*****************************************************************************
  Functionname:    CML_v_subtractMatrices                               */ /*!

  @brief           Matrix substraction Res = A - B

  @description     This function performs matrix subtraction (inplace/outplace)
                   of two matrices A and B with same dimesions and store the result
                   in a resultant matrix.
                   [Res] = [A] - [B]

  @param[in]       p_MatrixA : Minuend matrix
                               Range for p_MatrixA->Desc.row [Full range of uint8]
                               Range for p_MatrixA->Desc.col [Full range of uint8]
                               Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixA->pData 
                               [Valid pointer with data in full range of float32]
  @param[in]       p_MatrixB : Subtrahend matrix
                               Range for p_MatrixB->Desc.row [Full range of uint8]
                               Range for p_MatrixB->Desc.col [Full range of uint8]
                               Range for p_MatrixB->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixB->pData 
                               [Valid pointer with data in full range of float32]
                               Overflow may occur when one or more input values in both
                               matrices are at the defined range extremities.
  @param[out]      p_MatrixRes : Result Difference matrix

  @return          void

  @author          Dan Oprisan

*****************************************************************************/
void CML_v_subtractMatrices(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA, const CML_t_Matrix* p_MatrixB)
{
  uint32 u_Idx;
  uint32 u_size = (uint32)p_MatrixA->Desc.col * (uint32)p_MatrixA->Desc.row;
  float32* p_DataA = p_MatrixA->pData;       /* get pointer to matrix data */
  float32* p_DataB = p_MatrixB->pData;       /* get pointer to matrix data */
  float32* p_DataRes = p_MatrixRes->pData;   /* get pointer to result matrix data */

#if CML_MatrixBoundsCheckOn
  /* check if matrices are equal */
  if (  (p_MatrixA->Desc.col== p_MatrixB->Desc.col)
     && (p_MatrixA->Desc.row == p_MatrixB->Desc.row)
     && (p_MatrixRes->Desc.maxsize >= p_MatrixA->Desc.col * p_MatrixA->Desc.row) )
  {
#endif

    /* substract elements */
    if (p_DataA == p_DataRes)
    {
      for (u_Idx = 0u; u_Idx < u_size; u_Idx++)
      {
        p_DataRes[u_Idx] -= p_DataB[u_Idx];
      }
    }
    else
    {
      for (u_Idx = 0u; u_Idx < u_size; u_Idx++)
      {
        p_DataRes[u_Idx] = p_DataA[u_Idx] - p_DataB[u_Idx];
      }
    }

    /* create description for result matrix */
    p_MatrixRes->Desc.col = p_MatrixA->Desc.col;
    p_MatrixRes->Desc.row = p_MatrixA->Desc.row;

#if CML_MatrixBoundsCheckOn
  }
  else
  {
    /* set empty matrix */
    p_MatrixRes->Desc.col = (uint8)0;
    p_MatrixRes->Desc.row = (uint8)0;
    CML_ASSERT(b_FALSE);
  }
#endif
}

/*****************************************************************************
  Functionname:    CML_v_multiplyMatrices                               */ /*!

  @brief           Matrix multiplication

  @description     This function performs matrix multiplication (outplace)
                   of two matrices A and B and store the result in a
                   resultant matrix.
                   [Res] = [A] X [B]

  @param[in]       p_MatrixA : Multiplicand matrix (source)
                               Range for p_MatrixA->Desc.row [Full range of uint8]
                               Range for p_MatrixA->Desc.col [Full range of uint8]
                               Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixA->pData 
                               [Valid pointer with data in full range of float32]
  @param[in]       p_MatrixB : Multiplier matrix (source)
                               Range for p_MatrixB->Desc.row [Full range of uint8]
                               Range for p_MatrixB->Desc.col [Full range of uint8]
                               Range for p_MatrixB->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixB->pData 
                               [Valid pointer with data in full range of float32]
                               Overflow may occur when one or more input values in both
                               matrices are at the defined range extremities.
  @param[out]      p_MatrixRes : Result Product matrix

  @return          void

  @author          Dan Oprisan, Uwe Zunker (optimization)

*****************************************************************************/
void CML_v_multiplyMatrices(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA, const CML_t_Matrix* p_MatrixB)
{
  uint8  u_RegAcol = p_MatrixA->Desc.col;
  uint8  u_RegBcol = p_MatrixB->Desc.col;
  uint8  u_RegArow = p_MatrixA->Desc.row;
  uint32 u_count;
  float32* p_DataA;
  float32* p_DataB;
  float32* p_LineA=p_MatrixA->pData;
  float32* p_LineB=p_MatrixB->pData;
  float32* p_LineBk;
  float32* p_DataRes = p_MatrixRes->pData;         /* get pointer to matrix data */
  float32  f_Tmp;

#if CML_MatrixBoundsCheckOn
  /* check if matrix dimensions fit */
  /* and matrices are distinct */
  if (  (p_MatrixA->Desc.col != (uint8)0)
     && (p_MatrixA->Desc.col == p_MatrixB->Desc.row)
     && (p_MatrixA->pData != p_MatrixRes->pData)
     && (p_MatrixB->pData != p_MatrixRes->pData)
     && (p_MatrixRes->Desc.maxsize >= p_MatrixB->Desc.col * p_MatrixA->Desc.row) )
  {
#endif

    if ((u_RegAcol > 0U) && (u_RegBcol > 0U) && (u_RegArow > 0U))
    {
      /* multiply matrix elements */
      u_count = u_RegArow;
      do
      {
        p_LineBk = p_LineB;
        do
        {
          float32 f_DataA;
          float32 f_DataB;

          p_DataA = p_LineA;
          p_DataB = p_LineBk;
          p_LineBk++;
          f_Tmp = 0.0F;
          do
          {
            f_DataA = *p_DataA;
            f_DataB = *p_DataB;
            p_DataA++;
            p_DataB += u_RegBcol;          /* goto next line */
            /* Floating point multiply and add: y = a * b + d */
            f_Tmp = CML_f_MultAdd(f_DataA,f_DataB,f_Tmp);

            /* <ln_offset:+2 MISRA Rule 17.2: reviewer name: Daniel Meschenmoser date: 2012-09-12 reason: matrix multiplication runtime optimized by Uwe-Juergen Zunker */
            /* <ln_offset:+1 MISRA Rule 17.3: reviewer name: Daniel Meschenmoser date: 2012-09-12 reason: matrix multiplication runtime optimized by Uwe-Juergen Zunker */
          } while (p_DataA < (p_LineA + u_RegAcol));
          *p_DataRes = f_Tmp;
          p_DataRes++;                   /* go to next pRes element */
          /* <ln_offset:+2 MISRA Rule 17.2: reviewer name: Daniel Meschenmoser date: 2012-09-12 reason: matrix multiplication runtime optimized by Uwe-Juergen Zunker */
          /* <ln_offset:+1 MISRA Rule 17.3: reviewer name: Daniel Meschenmoser date: 2012-09-12 reason: matrix multiplication runtime optimized by Uwe-Juergen Zunker */
        } while (p_LineBk < (p_LineB + u_RegBcol));
        p_LineA += (uint32)u_RegAcol;  /* go to next line of A */

        u_count--;
      } while(u_count > 0UL);
    }
    else
    {
      /* error */
    }

    /* create description for result matrix */
    p_MatrixRes->Desc.col = u_RegBcol;
    p_MatrixRes->Desc.row = u_RegArow;

#if CML_MatrixBoundsCheckOn
  }
  else
  {
    /* set empty matrix */
    p_MatrixRes->Desc.col = (uint8)0;
    p_MatrixRes->Desc.row = (uint8)0;
    CML_ASSERT(b_FALSE);
  }
#endif
}

/*****************************************************************************
  Functionname:    CML_v_multiplyMatricesToSymResult                    */ /*!

  @brief           Matrix multiplication if result is symmetric

  @description     This function performs matrix multiplication (outplace)
                   of two matrices A and B and store the result in a
                   resultant matrix, if the result is known to be a symmetric
                   matrix.
                   [Res] = [A] X [B],
                   [A] is of the order MxN,
                   [B] is of the order NxM,
                   [Res] will of the order MxM.


  @param[in]       p_MatrixA : Multiplicand matrix
                               Range for p_MatrixA->Desc.row [Full range of uint8]
                               Range for p_MatrixA->Desc.col [Full range of uint8]
                               Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixA->pData 
                               [Valid pointer with data in full range of float32]
  @param[in]       p_MatrixB : Multiplier matrix
                               Range for p_MatrixB->Desc.row [Full range of uint8]
                               Range for p_MatrixB->Desc.col [Full range of uint8]
                               Range for p_MatrixB->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixB->pData 
                               [Valid pointer with data in full range of float32]
                               Overflow may occur when one or more input values in both
                               matrices are at the defined range extremities.
  @param[out]      p_MatrixRes : symmetric result matrix

  @return          void

  @author          Dan Oprisan

*****************************************************************************/
void CML_v_multiplyMatricesToSymResult(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA, const CML_t_Matrix* p_MatrixB)
{
  uint32 u_Idx1, u_Idx2;
  float32* p_DataA;
  float32* p_DataB;
  float32* pLineA;
  float32* p_DataRes = p_MatrixRes->pData;       /* get pointer to matrix data */

#if CML_MatrixBoundsCheckOn
  /* check if matrix dimensions fit */
  /* and matrices are distinct */
  if (  (p_MatrixA->Desc.col != (uint8)0)
     && (p_MatrixA->Desc.col == p_MatrixB->Desc.row)
     && (p_MatrixA->Desc.row == p_MatrixB->Desc.col)
     && (p_MatrixA->pData != p_MatrixRes->pData)
     && (p_MatrixB->pData != p_MatrixRes->pData)
     && (p_MatrixRes->Desc.maxsize >= p_MatrixB->Desc.col * p_MatrixA->Desc.row) )
  {
#endif

    /* multiply matrix elements */
    pLineA = p_MatrixA->pData;
    for (u_Idx1=0UL; u_Idx1<p_MatrixA->Desc.row; u_Idx1++)
    {
      for (u_Idx2=0UL; u_Idx2<p_MatrixB->Desc.col; u_Idx2++)
      {
        p_DataB = &p_MatrixB->pData[u_Idx2];
        *p_DataRes = 0.0F;
        if (u_Idx1 > u_Idx2)
        {
          *p_DataRes = p_MatrixRes->pData[u_Idx1 + (u_Idx2 * p_MatrixB->Desc.col)];
        }
        else
        {
          /* <ln_offset:+2 MISRA Rule 17.2: reviewer name: Daniel Meschenmoser date: 2012-09-12 reason: matrix multiplication runtime optimized by Uwe-Juergen Zunker */
          /* <ln_offset:+1 MISRA Rule 17.3: reviewer name: Daniel Meschenmoser date: 2012-09-12 reason: matrix multiplication runtime optimized by Uwe-Juergen Zunker */
          for (p_DataA = pLineA; p_DataA < (pLineA + p_MatrixA->Desc.col); p_DataA++)
          {
            *p_DataRes += (*p_DataA) * (*p_DataB);
            p_DataB+=p_MatrixB->Desc.col;        /* goto next line */
          }
        }
        p_DataRes++;                   /* go to next pRes element */
      }
      pLineA += (uint32)p_MatrixA->Desc.col;  /* go to next line of A */
    }

    /* create description for result matrix */
    p_MatrixRes->Desc.col = p_MatrixB->Desc.col;
    p_MatrixRes->Desc.row = p_MatrixA->Desc.row;

#if CML_MatrixBoundsCheckOn
  }
  else
  {
    /* set empty matrix */
    p_MatrixRes->Desc.col = (uint8)0;
    p_MatrixRes->Desc.row = (uint8)0;
    CML_ASSERT(b_FALSE);
  }
#endif
}

/*****************************************************************************
  Functionname:    CML_v_multiplyMatrixWithTranspose                    */ /*!

  @brief           Matrix multiplication with transpose

  @description     This function performs matrix multiplication (outplace)
                   of matrix A with transpose of matrix B and store the
                   result in a resultant matrix.
                   [Res] = [A] X [B]'

  @param[in]       p_MatrixA : Multiplicand matrix
                               Range for p_MatrixA->Desc.row [Full range of uint8]
                               Range for p_MatrixA->Desc.col [Full range of uint8]
                               Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixA->pData 
                               [Valid pointer with data in full range of float32]
  @param[in]       p_MatrixB : Transpose of which is the multiplier matrix
                               Range for p_MatrixB->Desc.row [Full range of uint8]
                               Range for p_MatrixB->Desc.col [Full range of uint8]
                               Range for p_MatrixB->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixB->pData 
                               [Valid pointer with data in full range of float32]
                               Overflow may occur when one or more input values in both
                               matrices are at the defined range extremities.
  @param[out]      p_MatrixRes : result matrix

  @return          void

  @author          Dan Oprisan, Uwe Zunker (optimization)

*****************************************************************************/
void CML_v_multiplyMatrixWithTranspose(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA, const CML_t_Matrix* p_MatrixB)
{
  uint8  u_RegAcol = p_MatrixA->Desc.col;
  uint8  u_RegBrow = p_MatrixB->Desc.row;
  uint8  u_RegArow = p_MatrixA->Desc.row;
  uint32 uIdx1, uIdx2;
  float32* p_DataA;
  float32* p_DataB;
  float32* p_LineA=p_MatrixA->pData;
  float32* p_LineB=p_MatrixB->pData;
  float32* p_DataRes = p_MatrixRes->pData;         /* get pointer to matrix data */
  float32  f_Tmp;

#if CML_MatrixBoundsCheckOn
  /* check if matrix dimensions fit */
  /* and matrices are distinct */
  if (  (p_MatrixA->Desc.col != (uint8)0)
     && (p_MatrixA->Desc.col == p_MatrixB->Desc.col)
     && (p_MatrixA->pData != p_MatrixRes->pData)
     && (p_MatrixB->pData != p_MatrixRes->pData)
     && (p_MatrixRes->Desc.maxsize >= p_MatrixB->Desc.col * p_MatrixA->Desc.row) )
  {
#endif

    if ((u_RegAcol > 0U) && (u_RegBrow > 0U) && (u_RegArow > 0U))
    {
      /* multiply matrix elements */
      uIdx1 = u_RegArow;
      do
      {
        uIdx2 = u_RegBrow;
        p_DataB = p_LineB;
        do
        {
          float32 fA;
          float32 fB;

          p_DataA = p_LineA;
          f_Tmp = 0.0F;
          do
          {
            fA = *p_DataA;               /* preread */
            fB = *p_DataB;
            p_DataA++;
            p_DataB++;          /* goto next line */
            /* Floating point multiply and add: y = a * b + d */
            f_Tmp = CML_f_MultAdd(fA, fB, f_Tmp);
          } while (p_DataA < (p_LineA + u_RegAcol));
          *p_DataRes = f_Tmp;
          p_DataRes++;                   /* go to next pRes element */

          uIdx2--;
        } while(uIdx2 > 0UL);
        p_LineA += (uint32)u_RegAcol;  /* go to next line of A */

        uIdx1--;
      } while(uIdx1 > 0UL);
    }
    else
    {
      /* error */
    }

    /* create description for result matrix */
    p_MatrixRes->Desc.col = u_RegBrow;
    p_MatrixRes->Desc.row = u_RegArow;

#if CML_MatrixBoundsCheckOn
  }
  else
  {
    /* set empty matrix */
    p_MatrixRes->Desc.col = (uint8)0;
    p_MatrixRes->Desc.row = (uint8)0;
    CML_ASSERT(b_FALSE);
  }
#endif
}

/*****************************************************************************
  Functionname:    CML_v_invertMatrix                                   */ /*!

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
void CML_v_invertMatrix(CML_t_Matrix* p_MatrixRes, CML_t_Matrix* p_MatrixA)
{
  boolean bRet = b_FALSE;
  uint32 u_Idx1, u_Idx2, u_col, u_row, u_pos1, u_pos2;
  float32 f_Temp, f_MaxElem;
  float32 f_PivElem       = 1.0F;
  float32 f_InvPivElem    = 1.0F;
  const float32 f_Tol     = 1e-10F;               /* tolerance */
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
        bRet = b_TRUE;
      }
    }
    else if (p_MatrixA->Desc.col == (uint8)2U)
    {
      /* Cramers Rule for matrix size == 2 */
      bRet = CML_b_invertMatrixCramer2(p_DataRes, p_DataA);
    }
    else if(p_MatrixA->Desc.col == (uint8)3U)
    {
      /* Cramers Rule for matrix size == 3 */
      bRet = CML_b_invertMatrixCramer3(p_DataRes, p_DataA);
    }
    else /* (A->Desc.col > (uint8)2U) */
    {
      /* Gauss-Jordan elimination with partial pivoting */

      bRet = b_TRUE;
      u_col = 0UL;
      CML_v_createIdentityMatrix(p_MatrixRes, (uint32)p_MatrixA->Desc.row);  /* set result matrix as identity */
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
          bRet = b_TRUE;

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
          bRet = b_FALSE;
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
    CML_ASSERT(b_FALSE);
  }
}


/*****************************************************************************
  Functionname:    CML_b_invertMatrixCramer2                        */ /*!

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
CML_INLINE boolean CML_b_invertMatrixCramer2(float32 a_res[MTRX_2X2_NOF_ELEMENTS], float32 a_in[MTRX_2X2_NOF_ELEMENTS])
{
  float32 f_temp  = 0.0f;   /* temporary variable */
  boolean b_ret   = b_FALSE;  /* return value */


  /* Cramers Rule for matrix size == 2 */
  f_temp = (a_in[0] * a_in[3]) - (a_in[1] * a_in[2]);
  if(CML_f_IsNonZero(f_temp))
  {
    f_temp = 1.0F / f_temp;

    a_res[0] = a_in[3]  * f_temp;
    a_res[1] = -a_in[1] * f_temp;
    a_res[2] = -a_in[2] * f_temp;
    a_res[3] = a_in[0]  * f_temp;

    b_ret = b_TRUE;
  } /* if(CML_f_IsNonZero(f_temp)) */


  return b_ret;
} /* b_InvertMatrixCramer2() */


/*****************************************************************************
  Functionname:    CML_b_invertMatrixCramer3                                */ /*!

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
CML_INLINE boolean CML_b_invertMatrixCramer3(float32 a_res[MTRX_3X3_NOF_ELEMENTS], float32 a_in[MTRX_3X3_NOF_ELEMENTS])
{
  float32 f_temp  = 0.0f;   /* temporary variable */
  boolean b_ret   = b_FALSE;  /* return value */


  /* Cramers Rule for matrix size == 3 */
  f_temp = (((a_in[0] * a_in[4]) - (a_in[3] * a_in[1])) * a_in[8]) +
           (((a_in[3] * a_in[7]) - (a_in[6] * a_in[4])) * a_in[2]) +
           (((a_in[6] * a_in[1]) - (a_in[0] * a_in[7])) * a_in[5]);

  if(CML_f_IsNonZero(f_temp))
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

    b_ret = b_TRUE;
  } /* if(CML_f_IsNonZero(f_temp)) */


  return b_ret;
} /* b_InvertMatrixCramer3() */


/*****************************************************************************
  Functionname:    CML_v_scaleMatrix                                    */ /*!

  @brief           Matrix multiplication with scalar

  @description     This function does an inplace matrix multiplication
                   with a given scalar. If [A] is the matrix, and p is
                   the scalar, then,
                   [A] = p * [A]

  @param[in,out]   p_MatrixA : Matrix o be multiplied
                               Range for p_MatrixA->Desc.row [Full range of uint8]
                               Range for p_MatrixA->Desc.col [Full range of uint8]
                               Range for p_MatrixA->pData 
                               [Valid pointer with data in full range of float32]
                               Overflow may occur when one or more input values in both
                               matrices are at the defined range extremities.
  @param[in]       f_Val :     scalar
                               [Full range of float32]

  @return          void

  @author          Dan Oprisan

*****************************************************************************/
void CML_v_scaleMatrix(CML_t_Matrix* p_MatrixA, float32 f_Val)
{
  uint32 u_Idx;
  uint32 u_size = (uint32)p_MatrixA->Desc.col * (uint32)p_MatrixA->Desc.row;
  float32* p_DataA;        /* get pointer to matrix data */

  /* scale elements */
  p_DataA = p_MatrixA->pData;
  for (u_Idx = 0u; u_Idx < u_size; u_Idx++)
  {
    p_DataA[u_Idx] *= f_Val;
  }
}

/*****************************************************************************
  Functionname:    CML_v_copyMatrix                                     */ /*!

  @brief           Matrix copy

  @description     This function copies data from one matrix to another.

  @param[in]       p_MatrixA : matrix to be copied
                               Range for p_MatrixA->Desc.row [Full range of uint8]
                               Range for p_MatrixA->Desc.col [Full range of uint8]
                               Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixA->pData 
                               [Valid pointer with data in full range of float32]
  @param[out]      p_MatrixRes : destination matrix
                                 Range for p_MatrixRes->Desc.maxsize [Full range of uint16]

  @return          void

  @author          Dan Oprisan

*****************************************************************************/
void CML_v_copyMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA)
{
  uint32 u_Idx;
  uint32 size = (uint32)p_MatrixA->Desc.col * (uint32)p_MatrixA->Desc.row;
  float32* p_DataA    = p_MatrixA->pData;
  float32* p_DataRes = p_MatrixRes->pData;     /* get pointer to matrix data */

#if CML_MatrixBoundsCheckOn
  if ( p_MatrixRes->Desc.maxsize >= size )
  {
#endif

    /* copy elements */
    for (u_Idx = 0u; u_Idx < size; u_Idx++)
    {
      p_DataRes[u_Idx] = p_DataA[u_Idx];
    }

    /* create description for result matrix */
    p_MatrixRes->Desc.col = p_MatrixA->Desc.col;
    p_MatrixRes->Desc.row = p_MatrixA->Desc.row;

#if CML_MatrixBoundsCheckOn
  }
  else
  {
    /* set empty matrix */
    p_MatrixRes->Desc.col = (uint8)0;
    p_MatrixRes->Desc.row = (uint8)0;
    CML_ASSERT(b_FALSE);
  }
#endif
}

/*****************************************************************************
  Functionname:    CML_v_copyArrayToSymMatrix                           */ /*!

  @brief           Fill matrix with data from array

  @description     This functon copies data from an array to a matrix.
                   The resultant matrix is a symmetric matrix.

  @param[in]       p_Data :  data to be copied
                             [Valid pointer with data in full range of float32]
  @param[out]      p_MatrixRes : destination matrix
  @param[in]       u_RowNr : no. of rows
                             [Full range of uint8]
  @param[in]       u_ColNr : no. of columns
                             [Full range of uint8]

  @return          void

  @author          Dan Oprisan

*****************************************************************************/
void CML_v_copyArrayToSymMatrix(CML_t_Matrix* p_MatrixRes, uint32 u_RowNr, uint32 u_ColNr, const float32* p_Data)
{
  uint32 u_Idx1, u_Idx2;

  /* get pointer to matrix data */
  const float32* p_MatrixData = p_Data;

#if CML_MatrixBoundsCheckOn
  /*Check for Square Matrix*/
  if(u_RowNr == u_ColNr)
  {
#endif
  /* copy elements */
  for (u_Idx1=0UL; u_Idx1<u_RowNr; u_Idx1++)
  {
    for (u_Idx2=u_Idx1; u_Idx2<u_ColNr; u_Idx2++)
    {
      p_MatrixRes->pData[u_Idx2 + (u_Idx1*u_RowNr)] = *p_MatrixData;
      if (u_Idx2 != u_Idx1)
      {
        p_MatrixRes->pData[u_Idx1 + (u_Idx2*u_RowNr)] = *p_MatrixData;
      }
      p_MatrixData++;
    }
  }
    p_MatrixRes->Desc.row = (uint8)u_RowNr;
    p_MatrixRes->Desc.col = (uint8)u_ColNr;
#if CML_MatrixBoundsCheckOn
  } /*if(u_RowNr == u_ColNr)*/
  else
  {
    /* set empty matrix */
    p_MatrixRes->Desc.col = (uint8)0;
    p_MatrixRes->Desc.row = (uint8)0;
    CML_ASSERT(b_FALSE);
  }
#endif
}

/*****************************************************************************
  Functionname:    CML_v_choleskyMatrix                                 */ /*!

  @brief           Compute Cholesky factor of a p.d. hermitian matrix

  @description     The Cholesky factorization is decomposing the hermitian
                   positive definite matrix (A) into product of a lower triangular
                   matrix (L) and its conjugare transpose (L*).
                   A = LL*
                   This function returns this lower triangular square root of
                   the positive definite real symmetric matrix, no exception
                   handling for any kind of rank deficiency rather direct
                   regularization
                   (associated m-file for unit testing: slow_chol2.m)

  @param[in,out]   p_MatrixA :   matrix whose Cholesky type square root is wanted
                                 Range for p_MatrixA->Desc.row [Full range of uint8]
                                 Range for p_MatrixA->Desc.col [Full range of uint8]
                                 Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                                 Range for p_MatrixA->pData 
                                 [Valid pointer with data in full range of float32]
  @param[in,out]   p_MatrixRes : lower triangular result matrix
                                 Range for p_MatrixRes->Desc.maxsize [Full range of uint16]

  @return          void

  @author          uidt8688

*****************************************************************************/
void CML_v_choleskyMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA)
{
  uint32   u_Idx1, u_Idx2, u_Idx3, u_ColRowNr;
  float32  f_Tol = (float32) 1e-10F;
  float32  f_Temp;
  float32* p_DataRes = p_MatrixRes->pData;   /* get pointer to matrix data */

#if CML_MatrixBoundsCheckOn
  /* check if matrix is square */
  if (  (p_MatrixA->Desc.col != (uint8)0)
    && (p_MatrixA->Desc.col == p_MatrixA->Desc.row)
    && ((p_MatrixA->pData) != (p_MatrixRes->pData))
    && (p_MatrixRes->Desc.maxsize >= (p_MatrixA->Desc.col * p_MatrixA->Desc.row)) )
  {
#endif
    CML_v_CopyMatrix(p_MatrixRes, p_MatrixA);
    u_ColRowNr = (uint32) p_MatrixA->Desc.col; // ColNr = RowNr
    for (u_Idx2=0UL; u_Idx2<u_ColRowNr; u_Idx2++)
    {
      if (p_DataRes[u_Idx2 + (u_Idx2*u_ColRowNr)] < f_Tol) // should never happen for p.d. input matrix
      {
        p_DataRes[u_Idx2 + (u_Idx2*u_ColRowNr)]  = f_Tol; // just "brutal" pseudo regularization good for KAFI
      }
    }
    for (u_Idx1=0UL; u_Idx1<u_ColRowNr; u_Idx1++)
    {
      for (u_Idx2=0UL; u_Idx2<u_Idx1; u_Idx2++)
      {
        f_Temp = p_DataRes[u_Idx2 + (u_Idx1*u_ColRowNr)];
        for (u_Idx3=0UL; u_Idx3<u_Idx2; u_Idx3++)
        {
          f_Temp -= p_DataRes[u_Idx3 + (u_Idx1*u_ColRowNr)] * p_DataRes[u_Idx3 + (u_Idx2*u_ColRowNr)];
        }
        p_DataRes[u_Idx2 + (u_Idx1*u_ColRowNr)] = f_Temp/p_DataRes[u_Idx2 + (u_Idx2*u_ColRowNr)];
        p_DataRes[u_Idx1 + (u_Idx2*u_ColRowNr)] = 0.0F;
      }
      f_Temp = p_DataRes[u_Idx1 + (u_Idx1*u_ColRowNr)];
      for (u_Idx3=0UL; u_Idx3<u_Idx1; u_Idx3++)
      {
        f_Temp -= p_DataRes[u_Idx3 + (u_Idx1*u_ColRowNr)] * p_DataRes[u_Idx3 + (u_Idx1*u_ColRowNr)];
      }
      if ( f_Temp > f_Tol)
      {
        p_DataRes[u_Idx1 + (u_Idx1*u_ColRowNr)] = (float32) CML_f_Sqrt(f_Temp);
      }
      else
      { // this should never happen for p.d. input matrix
        p_DataRes[u_Idx1 + (u_Idx1*u_ColRowNr)] = f_Tol; // it is caused by rank-deficient input matrix
      }

    } // for (u_Idx1=0UL; u_Idx1<ColRowNr; u_Idx1++)
#if CML_MatrixBoundsCheckOn
  }
  else
  {
    CML_ASSERT(b_FALSE);
  }
#endif
}


/*****************************************************************************
  Functionname:    CML_v_lowTriaInvMatrix                               */ /*!

  @brief           Inverse of p.d. lower triangular matrix  by forward substitution

  @description     The method of choice for inversion of positive definite
                   symmetric matrices consists of Cholesky factorization followed
                   by forward substitution which is efficiently implemented
                   in this function, no exception handling in case of indefinite
                   input rather brute force regularization which is appropriate
                   for square-root Kalman filter applications but does a poor
                   job in approximating the Pseudo-Inverse for least-squares.

  @param[in,out]   p_MatrixA :   lower triangular p.d. matrix (upper triangular entries are irrelevant)
                                 Range for p_MatrixA->Desc.row [Full range of uint8]
                                 Range for p_MatrixA->Desc.col [Full range of uint8]
                                 Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                                 Range for p_MatrixA->pData 
                                 [Valid pointer with data in full range of float32]
  @param[in,out]   p_MatrixRes : lower triangular inverse of A (upper triangular entries are invalid)
                                 Range for p_MatrixRes->Desc.maxsize [Full range of uint16]

  @return          void

  @author          uidt8688

*****************************************************************************/
void CML_v_lowTriaInvMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA)
{
  uint32   u_Idx3, u_Idx2, u_Idx1, u_ColRowNr;
  float32  f_Tol = (float32) 1e-10F;
  float32  f_Temp;
  float32* p_DataA   = p_MatrixA->pData;     /* get pointer to matrix data */
  float32* p_DataRes = p_MatrixRes->pData;   /* get pointer to matrix data */

#if CML_MatrixBoundsCheckOn
  /* check if matrix is square */
  if (  (p_MatrixA->Desc.col != (uint8)0)
    && (p_MatrixA->Desc.col == p_MatrixA->Desc.row)
    && (p_DataA != p_DataRes)
    && (p_MatrixRes->Desc.maxsize >= (p_MatrixA->Desc.col * p_MatrixA->Desc.row)) )
  {
#endif
    u_ColRowNr = (uint32) p_MatrixA->Desc.col; // ColNr = RowNr
    for (u_Idx1=0UL; u_Idx1<u_ColRowNr; u_Idx1++)
    {
      if (p_DataA[u_Idx1 + (u_Idx1*u_ColRowNr)] < f_Tol)
      {
        p_DataA[u_Idx1 + (u_Idx1*u_ColRowNr)] = f_Tol; // regularization
      }
      p_DataA[u_Idx1 + (u_Idx1*u_ColRowNr)] = 1.0F/p_DataA[u_Idx1 + (u_Idx1*u_ColRowNr)];  // in place predivision for efficiency
      for (u_Idx2=u_Idx1; u_Idx2<u_ColRowNr; u_Idx2++)
      {
        p_DataRes[u_Idx2 + (u_Idx1*u_ColRowNr)] = 0.0F;
      }
    }
    for (u_Idx1=0UL; u_Idx1<u_ColRowNr; u_Idx1++)
    {
      for (u_Idx2=u_Idx1; u_Idx2<u_ColRowNr; u_Idx2++)
      {
        f_Temp = 0.0F;
        for (u_Idx3=0UL; u_Idx3<u_Idx2; u_Idx3++)
        {
          f_Temp += p_DataA[u_Idx3 + (u_Idx2*u_ColRowNr)] * p_DataRes[u_Idx1 + (u_Idx3*u_ColRowNr)];
        }
        if (u_Idx2 == u_Idx1)
        {
          p_DataRes[u_Idx1 + (u_Idx2*u_ColRowNr)] = p_DataA[u_Idx2 + (u_Idx2*u_ColRowNr)] * (1.0F - f_Temp);
        }
        else
        {
          p_DataRes[u_Idx1 + (u_Idx2*u_ColRowNr)] = p_DataA[u_Idx2 + (u_Idx2*u_ColRowNr)] * (-f_Temp);
        }
      }
    }
    /* create description for result matrix */
  p_MatrixRes->Desc.col = p_MatrixA->Desc.col;
  p_MatrixRes->Desc.row = p_MatrixA->Desc.row;
#if CML_MatrixBoundsCheckOn
  }
  else
  {
    CML_ASSERT(b_FALSE);
  }
#endif
}

/*****************************************************************************
  Functionname:    CML_v_lowTriaSqrMatrix                               */ /*!

  @brief           Square of Cholesky Res = A*transpose(A), with A lower triangular

  @description     The method of choice for squaring of positive definite
                   symmetric matrices is from Cholesky method. This function
                   computes the product of the lower traingular matrix and its
                   transpose.


  @param[in,out]   p_MatrixA :   lower triangular p.d. matrix
                                 (upper triangular entries are irrelevant)
                                 Range for p_MatrixA->Desc.row [Full range of uint8]
                                 Range for p_MatrixA->Desc.col [Full range of uint8]
                                 Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                                 Range for p_MatrixA->pData 
                                 [Valid pointer with data in full range of float32]
  @param[in,out]   p_MatrixRes : square matrix A*transpose(A) symmetric and
                                 positive definite
                                 Range for p_MatrixRes->Desc.maxsize [Full range of uint16]

  @return          void

  @author          uidt8688

*****************************************************************************/
void CML_v_lowTriaSqrMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA)
{
  uint32   u_Idx1,u_Idx2,u_Idx3,u_ColRowNr;
  float32  f_Temp;
  float32* p_DataA = p_MatrixA->pData;
  float32* p_DataRes = p_MatrixRes->pData;

#if CML_MatrixBoundsCheckOn
  /* check if matrix dimensions fit */
  /* and matrices are distinct */
  if (  (p_MatrixA->Desc.col != (uint8)0)
    && (p_MatrixA->Desc.col == p_MatrixA->Desc.row)
    && (p_MatrixA->pData != p_MatrixRes->pData)
    && (p_MatrixRes->Desc.maxsize >= p_MatrixA->Desc.col * p_MatrixA->Desc.row) )
  {
#endif
    u_ColRowNr = p_MatrixA->Desc.row;
    for (u_Idx1=0UL; u_Idx1<u_ColRowNr; u_Idx1++)
    {
      for (u_Idx2=0UL; u_Idx2<=u_Idx1; u_Idx2++)
      {
        f_Temp = 0.0F;
        for (u_Idx3=0UL; (u_Idx3<=u_Idx1)&&(u_Idx3<=u_Idx2); u_Idx3++)
        {
          f_Temp += p_DataA[u_Idx3 + (u_Idx1*u_ColRowNr)] * p_DataA[u_Idx3 + (u_Idx2*u_ColRowNr)];
        }
        p_DataRes[u_Idx1 + (u_Idx2*u_ColRowNr)] = f_Temp;
        p_DataRes[u_Idx2 + (u_Idx1*u_ColRowNr)] = f_Temp;  //redundant at the diagonal but faster on pipelined DSPs
      }
    }

    /* create description for result matrix */
    p_MatrixRes->Desc.col = p_MatrixA->Desc.col;
    p_MatrixRes->Desc.row = p_MatrixA->Desc.row;

#if CML_MatrixBoundsCheckOn
  }
  else
  {
    /* set empty matrix */
    p_MatrixRes->Desc.col = (uint8)0;
    p_MatrixRes->Desc.row = (uint8)0;
  }
#endif
}

/*****************************************************************************
  Functionname:    CML_v_uppTriaSqrMatrix                               */ /*!

  @brief           Res = A*transpose(A), with A upper triangular
  @description     This function computes the product of the upper triangular
                   matrix and its transpose

  @param[in,out]   p_MatrixA   : upper triangular p.d. matrix
                                 (lower triangular entries are irrelevant)
                                 Range for p_MatrixA->Desc.row [Full range of uint8]
                                 Range for p_MatrixA->Desc.col [Full range of uint8]
                                 Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                                 Range for p_MatrixA->pData 
                                 [Valid pointer with data in full range of float32]
  @param[in,out]   p_MatrixRes : square matrix A*transpose(A) symmetric and
                                 positive definite
                                 Range for p_MatrixRes->Desc.maxsize [Full range of uint16]

  @return          void

  @author          uidt8688

*****************************************************************************/
void CML_v_uppTriaSqrMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA)
{
  uint32   u_Idx1, u_Idx2, u_Idx3, u_ColRowNr;
  float32  f_Temp;
  float32* p_DataA   = p_MatrixA->pData;
  float32* p_DataRes = p_MatrixRes->pData;

#if CML_MatrixBoundsCheckOn
  /* check if matrix dimensions fit */
  /* and matrices are distinct */
  if (  (p_MatrixA->Desc.col != (uint8)0)
    && (p_MatrixA->Desc.col == p_MatrixA->Desc.row)
    && (p_MatrixA->pData != p_MatrixRes->pData)
    && (p_MatrixRes->Desc.maxsize >= p_MatrixA->Desc.col * p_MatrixA->Desc.row) )
  {
#endif
    u_ColRowNr = p_MatrixA->Desc.row;
    for (u_Idx1=0UL; u_Idx1<u_ColRowNr; u_Idx1++)
    {
      for (u_Idx2=0UL; u_Idx2<=u_Idx1; u_Idx2++)  // <lint left brace
      {
        f_Temp = 0.0F;
        for (u_Idx3=u_Idx1; u_Idx3<u_ColRowNr; u_Idx3++)
        {
          f_Temp += p_DataA[u_Idx3 + (u_Idx1*u_ColRowNr)] * p_DataA[u_Idx3 + (u_Idx2*u_ColRowNr)];
        }
        p_DataRes[u_Idx1 + (u_Idx2*u_ColRowNr)] = f_Temp;
        p_DataRes[u_Idx2 + (u_Idx1*u_ColRowNr)] = f_Temp;  //redundant at the diagonal but faster on pipelined DSPs
      }
    }

    /* create description for result matrix */
    p_MatrixRes->Desc.col = p_MatrixA->Desc.col;
    p_MatrixRes->Desc.row = p_MatrixA->Desc.row;

#if CML_MatrixBoundsCheckOn
  }
  else
  {
    /* set empty matrix */
    p_MatrixRes->Desc.col = (uint8)0;
    p_MatrixRes->Desc.row = (uint8)0;
    CML_ASSERT(b_FALSE);
  }
#endif
}

/* ***************************************************************************
  Functionname:    CML_v_transposeMatrix                                */ /*!

  @brief           Matrix transposition, outplace

  @description     This function calculates the transpose of a matrix
                   (outplace)
                   If
                       |a b|
                   A = |c d| , then transpose of A is

                          |a c|
                   A(t) = |b d|

  @param[in]       p_MatrixA :    matrix o be transposed (source)
                                  Range for p_MatrixA->Desc.row [Full range of uint8]
                                  Range for p_MatrixA->Desc.col [Full range of uint8]
                                  Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                                  Range for p_MatrixA->pData 
                                  [Valid pointer with data in full range of float32]
  @param[out]      p_MatrixRes :  destination matrix
                                  Range for p_MatrixRes->Desc.maxsize [Full range of uint16]
                                  Range for p_MatrixRes->pData 
                                  [Valid pointer with data in full range of float32]

  @return          none

  @author          Dan Oprisan
**************************************************************************** */
void CML_v_transposeMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA)
{
  uint32   u_Idx2, u_Idx1;
  float32* p_DataA   = p_MatrixA->pData;       /* get pointer to matrix data */
  float32* p_DataRes = p_MatrixRes->pData;     /* get pointer to matrix data */

#if CML_MatrixBoundsCheckOn
  /* check if source is different from destination */
  if (  (p_MatrixA->pData != p_MatrixRes->pData)
     && (p_MatrixRes->Desc.maxsize >= p_MatrixA->Desc.col * p_MatrixA->Desc.row) )
  {
#endif

    /* transpose while copying */
    for (u_Idx1=0UL; u_Idx1<p_MatrixA->Desc.row; u_Idx1++)
    {
      for (u_Idx2=0UL; u_Idx2<p_MatrixA->Desc.col; u_Idx2++)
      {
        p_DataRes[u_Idx1 + (u_Idx2*(uint32)p_MatrixA->Desc.row)] = *p_DataA;
        p_DataA++;
      }
    }
    /* create description for result matrix */
    p_MatrixRes->Desc.col  = p_MatrixA->Desc.row;
    p_MatrixRes->Desc.row  = p_MatrixA->Desc.col;

#if CML_MatrixBoundsCheckOn
  }
  else
  {
    /* set empty matrix */
    p_MatrixRes->Desc.col = (uint8)0;
    p_MatrixRes->Desc.row = (uint8)0;
    CML_ASSERT(b_FALSE);
  }
#endif
}
