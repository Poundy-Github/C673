/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_mtrx.h

  DESCRIPTION:               implements matrix computations

  AUTHOR:                    Dan Oprisan

  CREATION DATE:             20.01.2009

  VERSION:                   $Revision: 1.28 $

  ---*/ /*---
  CHANGES:                   $Log: cml_mtrx.h  $
  CHANGES:                   Revision 1.28 2017/11/27 06:18:18CET A, Nandu (uidr5428) (uidr5428) 
  CHANGES:                   Replaced TRUE and FALSE with b_TRUE and b_FALSE to match the Mainstream update
  CHANGES:                   Revision 1.27 2017/11/15 11:17:19CET Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Checkin updates after the review.
  CHANGES:                   Revision 1.26 2017/11/13 06:19:44CET Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Updated cml_mtrx module functions with coding standard naming convention.
  CHANGES:                   Revision 1.25 2017/10/13 09:49:36CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the function header comment format
  CHANGES:                   Revision 1.24 2017/09/27 05:59:25CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Merged from branch with Detailed Design
  CHANGES:                   Revision 1.23 2016/05/20 10:57:36CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.22 2015/10/12 05:44:08CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Fix for doxygen warning
  CHANGES:                   - Added comments -  uidr5428 [Oct 12, 2015 5:44:09 AM CEST]
  CHANGES:                   Change Package : 383331:1 http://mks-psad:7002/im/viewissue?selection=383331
  CHANGES:                   Revision 1.21 2015/08/25 12:07:02CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated doxygen compliant function headers
  CHANGES:                   --- Added comments ---  uidr5428 [Aug 25, 2015 12:07:02 PM CEST]
  CHANGES:                   Change Package : 360603:2 http://mks-psad:7002/im/viewissue?selection=360603
  CHANGES:                   Revision 1.20 2015/07/07 08:27:05CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Fix for compilation error when __STDC_VERSION__
  CHANGES:                     was defined.
  CHANGES:                   --- Added comments ---  uidr5428 [Jul 7, 2015 8:27:06 AM CEST]
  CHANGES:                   Change Package : 354072:3 http://mks-psad:7002/im/viewissue?selection=354072
  CHANGES:                   Revision 1.19 2015/06/30 13:52:08CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   -  Macro definition for CML_CreateMatrixLocal 
  CHANGES:                      retained for supported compilers and hence
  CHANGES:                      QA-C warning is suppressed.
  CHANGES:                   --- Added comments ---  uidr5428 [Jun 30, 2015 1:52:09 PM CEST]
  CHANGES:                   Change Package : 335404:1 http://mks-psad:7002/im/viewissue?selection=335404
  CHANGES:                   Revision 1.18 2015/04/29 16:38:13CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Changes with respect to Coding Guidelines
  CHANGES:                     of variables
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 29, 2015 4:38:14 PM CEST]
  CHANGES:                   Change Package : 324617:3 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.17 2014/12/12 13:34:50CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - added review ID to QA-C suppressions
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 12, 2014 1:34:50 PM CET]
  CHANGES:                   Change Package : 266613:12 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.16 2014/12/04 17:18:31CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - suppressed QA-C warnings on interface
  CHANGES:                   - fixed deviating identifier
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 4, 2014 5:18:32 PM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.15 2014/11/28 10:55:25CET Friebertshaeuser, Markus (uidt0551) 
  CHANGES:                   make input matrix const
  CHANGES:                   --- Added comments ---  uidt0551 [Nov 28, 2014 10:55:25 AM CET]
  CHANGES:                   Change Package : 199714:3 http://mks-psad:7002/im/viewissue?selection=199714
  CHANGES:                   Revision 1.14 2014/07/14 15:38:21CEST Oprisan, Dan (oprisand) 
  CHANGES:                   - fix Matrix Bounds Check and throw assert if inconsitency is found.
  CHANGES:                   --- Added comments ---  oprisand [Jul 14, 2014 3:38:21 PM CEST]
  CHANGES:                   Change Package : 248463:1 http://mks-psad:7002/im/viewissue?selection=248463
  CHANGES:                   Revision 1.13 2014/04/07 10:32:00CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed erroneous include protection
  CHANGES:                   --- Added comments ---  uidg6516 [Apr 7, 2014 10:32:01 AM CEST]
  CHANGES:                   Change Package : 227281:3 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.12 2014/03/27 11:18:14CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed some QA-C- and Styleguide-issues
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 27, 2014 11:18:15 AM CET]
  CHANGES:                   Change Package : 227281:2 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.11 2014/03/25 11:34:52CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed Doxygen comments
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 25, 2014 11:34:52 AM CET]
  CHANGES:                   Change Package : 227281:1 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.10 2014/02/04 15:13:44CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - improve code quality
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 4, 2014 3:13:44 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.9 2013/07/26 13:11:12CEST Zechner, Stefan (uidt9253) 
  CHANGES:                   - bugfix: faulty non-c standard const declaration in some functions allowed passing a const pointer to the functions and functions writes into these pointers
  CHANGES:                   --- Added comments ---  uidt9253 [Jul 26, 2013 1:11:12 PM CEST]
  CHANGES:                   Change Package : 162889:30 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:                   Revision 1.8 2013/07/10 15:42:24CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - correct function name AlgoMtrxTrsp to CML_v_TransposeMatrix
  CHANGES:                   --- Added comments ---  uidu0849 [Jul 10, 2013 3:42:25 PM CEST]
  CHANGES:                   Change Package : 159154:28 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.7 2013/07/08 13:08:44CEST Schlensag, Andreas (schlensaga) 
  CHANGES:                   Add matrix transpose function
  CHANGES:                   --- Added comments ---  schlensaga [Jul 8, 2013 1:08:44 PM CEST]
  CHANGES:                   Change Package : 185100:3 http://mks-psad:7002/im/viewissue?selection=185100
  CHANGES:                   Revision 1.6 2013/06/10 18:03:15CEST Oprisan, Dan (oprisand) 
  CHANGES:                   - bugfix in CML_CreateMatrixLocal()
  CHANGES:                   --- Added comments ---  oprisand [Jun 10, 2013 6:03:15 PM CEST]
  CHANGES:                   Change Package : 178131:24 http://mks-psad:7002/im/viewissue?selection=178131
  CHANGES:                   Revision 1.5 2013/06/10 13:54:16CEST Oprisan, Dan (oprisand) 
  CHANGES:                   - add macro CML_CreateMatrixLocal() for creation of matrices with local scope
  CHANGES:                   --- Added comments ---  oprisand [Jun 10, 2013 1:54:17 PM CEST]
  CHANGES:                   Change Package : 178131:24 http://mks-psad:7002/im/viewissue?selection=178131
  CHANGES:                   Revision 1.4 2013/05/26 22:57:34CEST Kozek-EXT, Werner (uidt8688) 
  CHANGES:                   added Cholesky factorization and triangular matrix methods to be used by square-root Kalman
  CHANGES:                   filter and/or least squares estimators
  CHANGES:                   --- Added comments ---  uidt8688 [May 26, 2013 10:57:34 PM CEST]
  CHANGES:                   Change Package : 177735:1 http://mks-psad:7002/im/viewissue?selection=177735
  CHANGES:                   Revision 1.3 2013/05/03 09:57:36CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   - use new standard type names, e.g. float32 instead of f32_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:57:37 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2012/09/20 13:29:46CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:47 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:17CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/**
@defgroup mtrx MTRX (matrix computations)
  @ingroup cml
@{ */

/*****************************************************************************
  QA-C
*****************************************************************************/
/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
  /* Switch off QA-C warnings on side effects for macro, which don't have 
     any side effects and will sure never have some. The macro definition
     does not hold good for C90 compiler and this case is taken care in its
     definition.*/
  #pragma PRQA_MACRO_MESSAGES_OFF "CML_CreateMatrixLocal" 1031
#endif
/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef _CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_mtrx.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef _CML_EXT_INCLUDED */

#ifndef _CML_MTRX_INCLUDED
#define _CML_MTRX_INCLUDED


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

///< \brief       The Matrix Descriptor Structure
///< \description The matrix descriptor structure contains the description
///<              of the matrix (row count, column count and max size) reqired for matrix operations.
typedef struct
{
   uint8 col;             ///< Number of columns in the matrix
   uint8 row;             ///< Number of rows in the matrix
   uint16 maxsize;        ///< Maximum memory size allocated for this matrix
} CML_t_MatrixDescriptor;

/**/
///< \brief       The Matrix Data Structure
///< \description The matrix data structure contains the descriptor structure element 
///<              which contains row count, column count and max size reqired for matrix operations.
///<              The matrix data is linked via a pointer. This allows using a 
///<              single matrix datatype, for all matrix dimensions. \n
///<              It also allows the separation of data and header for saving 
///<              memory space: the matrix data can be stored on the heap, while 
///<              the wrapper can be created temporarily on the stack when needed 
///<              for computations.
typedef struct
{
  CML_t_MatrixDescriptor Desc;    ///< Matrix descriptor (dimensions, size, etc.) 
  float32*       pData;           ///< Pointer to the memory location where the data is stored */
} CML_t_Matrix; 

/*****************************************************************************
  MACROS
*****************************************************************************/

/* Deactivate QA-C warning 3410, 0881, 3412; Reviewer: S. Schwarzkopf; 
   Date: 04.12.2014; Reason: As this is an interface and proven in use, no 
   changes shall be made here.
   Review-ID: 3942463 */
/* PRQA S 3410, 0881, 3412 CREATEMATRIX */
/*! creates matrix and allocates new payload data with global scope */
#define CML_CreateMatrix(name,  rows, cols)          static float32 fMtrxData##name[(uint32)(rows) * (uint32)(cols)];\
                                                     CML_t_Matrix AlgoMtrxHeader##name = {{(uint8)(cols), (uint8)(rows), (uint16)((uint32)(rows) * (uint32)(cols))},fMtrxData##name};\
                                                     CML_t_Matrix* name = &AlgoMtrxHeader##name;     ///< Creates matrix and allocates new payload data with global scope 


#if (defined(_MSC_VER) || defined(__DCC__))  
#define CML_MATRIXLOCAL
#elif (defined(__STDC_VERSION__)) 
#if((__STDC_VERSION__ >= 199901)) /* C99 compatible compiler */
#define CML_MATRIXLOCAL
#endif
#endif

#ifdef CML_MATRIXLOCAL
#define CML_CreateMatrixLocal(name,  rows, cols)     float32 fMtrxData##name[(uint32)(rows) * (uint32)(cols)];\
                                                     CML_t_Matrix AlgoMtrxHeader##name = CML_initMatrixHeader((cols), (rows), fMtrxData##name);\
                                                     CML_t_Matrix* name = &AlgoMtrxHeader##name; ///< Creates matrix and allocates new payload data with local scope 
#else
#define CML_CreateMatrixLocal(name,  rows, cols)     CML_CreateMatrix(name,  rows, cols)         ///< Creates matrix and allocates new payload data 
#endif 

/* PRQA L:CREATEMATRIX */


#if (CML_MatrixBoundsCheckOn)
  #define CML_GetMatrixElement(name, Row, Col)        (name)->pData[(uint32)(Col) + ((uint32)(Row) * (name)->Desc.col)] ///<  Access to matrix element
#else
  /* (NO OVERFLOW CHECK!!) */
  #define CML_GetMatrixElement(name, Row, Col)        (name)->pData[(uint32)(Col) + ((uint32)(Row) * (name)->Desc.col)] ///<  Access to matrix element
#endif

/* Deactivate QA-C warning 3412; Reviewer: S. Schwarzkopf; 
   Date: 04.12.2014; Reason: As this is an interface and proven in use, no 
   changes shall be made here.
   Review-ID: 3942463 */
/* PRQA S 3412 5 */
#if (CML_MatrixBoundsCheckOn)
  #define CML_SetMatrixSize(name, rows, cols)  if (rows*cols <= (name)->Desc.maxsize){ (name)->Desc.col = cols; (name)->Desc.row = rows; } else {CML_ASSERT(b_FALSE);}; ///< Set new matrix size
#else                                                                                                                                                                 
  /* (NO OVERFLOW CHECK!!) */                                                                                                                                         
  #define CML_SetMatrixSize(name, rows, cols)  (name)->Desc.col = (cols); (name)->Desc.row = (rows);                                                                  ///< Set new matrix size
#endif

#define CML_IsMatrixEmpty(name)                (((name)->Desc.col == (uint8)0) || ((name)->Desc.row == (uint8)0)) ///< This checks if matrix is empty

/*****************************************************************************
  FUNCTION DECLARATIONS                                             
*****************************************************************************/

/*! helper function for creation of matrices with local scope */
CML_INLINE CML_t_Matrix CML_initMatrixHeader(uint32 u_ColNr, uint32 u_RowNr, float32* p_f_MtrxData);

/*****************************************************************************
  Functionname:    CML_v_initMatrix                                      *//*! 

  \brief           Matrix initialization with a const value

  \description     This function initializes all the elements of the matrix
                   with a const value(F).
  \InOutCorrelation
                   \f[ \begin{bmatrix}
                   M_{00}    &   M_{01}\\
                   M_{10}    &   M_{11}
                   \end{bmatrix}
               =
                   \begin{bmatrix}
                   F   &   F\\
                   F   &   F
                   \end{bmatrix}
                   \f]
  \attention       
                   RowNr and ColNr are expected to be values not
                   exceeding 8 bits.\\
                   u_RowNr*u_ColNr must not exceed A->Desc.maxsize.
  \param[in,out]   p_Matrix :  matrix o be filled
                               Range for p_Matrix->Desc.maxsize [Full range of uint16]
  \param[out]      f_Val :     value used for filling
                               [Full range of float32]
  \param[in]       u_RowNr :   Row dimension of the matrix to be created
                               [Full range of uint8]
  \param[in]       u_ColNr :   Column dimension of the matrix to be created
                               [Full range of uint8]

  \return          void

  \author          Dan Oprisan

  \testmethod    

  \traceability    
*****************************************************************************/
void CML_v_initMatrix(CML_t_Matrix* p_Matrix, uint32 u_RowNr, uint32 u_ColNr, float32 f_Val);

/*****************************************************************************
  Functionname:    CML_v_createIdentityMatrix                           *//*!

  \brief           Initialises matrix with identity matrix

  \description     This function initializes the given matrix with an
                   identity matrix of the provided size.
  \InOutCorrelation
                   \f[ \begin{bmatrix}
                   M_{00}    &   M_{01}\\
                   M_{10}    &   M_{11}
                   \end{bmatrix}
               =
                   \begin{bmatrix}
                   1 &   0\\
                   0 &   1
                   \end{bmatrix}
                   \f]
  \attention       
                   NOTE: Value for row/column is expected not to exceed 8 bits
                   CAUTION: Size of the matrix (rows x columns) must not
                   exceed p_Matrix->Desc.maxsize
                   p_Matrix->pData should hold a valid address.
  \param[in,out]   p_Matrix :  matrix o be filled (square matrix)
                               Range for p_Matrix->Desc.maxsize [Full range of uint16]
  \param[in]       u_Size :    no. of row/col square matrix (u_Size x u_Size)
                               [Full range of uint8]

  \return          void

  \author          Dan Oprisan

  \testmethod    

  \traceability    
*****************************************************************************/
void CML_v_createIdentityMatrix(CML_t_Matrix* p_Matrix, uint32 u_Size); 


/*****************************************************************************
  Functionname:    CML_v_addMatrices                                    *//*!

  \brief           Matrix addition (inplace/outplace). A or B can be same as Res

  \description     This function performs matrix addition (inplace/outplace) of
                   two matrices A and B with same dimesions and store the result
                   in a resultant matrix.
                   The matrix A or B can be same as resultant matrix.
                    \f[[Res] = [A] + [B]\f]
  \InOutCorrelation
                   \f[ \begin{bmatrix}
                   A_{00}    &   A_{01}\\
                   A_{10}    &   A_{11}
                   \end{bmatrix}
               +
                   \begin{bmatrix}
                   B_{00}    &   B_{01}\\
                   B_{10}    &   B_{11}
                   \end{bmatrix}
               =
                   \begin{bmatrix}
                   A_{00} +B_{00}    &   A_{01} +B_{01}\\
                   A_{10} +B_{10}    &   A_{11} +B_{11}
                   \end{bmatrix}
                   \f]
  \attention       
                   NOTE: Value for row/column is expected not to exceed 8 bits
                   CAUTION: Size of the matrix (rows x columns) must not
                   exceed p_MatrixRes->Desc.maxsize
                   p_MatrixRes->pData should hold a valid address.
  \param[in]       p_MatrixA : First Addend matrix (source)
                               Range for p_MatrixA->Desc.row [Full range of uint8]
                               Range for p_MatrixA->Desc.col [Full range of uint8]
                               Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixA->pData 
                               [Valid pointer with data in full range of float32]
  \param[in]       p_MatrixB : Second Addend matrix (source)
                               Range for p_MatrixB->Desc.row [Full range of uint8]
                               Range for p_MatrixB->Desc.col [Full range of uint8]
                               Range for p_MatrixB->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixB->pData 
                               [Valid pointer with data in full range of float32]
                               Overflow may occur when one or more input values in both
                               matrices are at the defined range extremities.

  \param[out]      p_MatrixRes : Result Sum matrix

  \return          void

  \author          Dan Oprisan

  \testmethod    

  \traceability    
*****************************************************************************/
void CML_v_addMatrices(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA, const CML_t_Matrix* p_MatrixB);

/*****************************************************************************
  Functionname:    CML_v_subtractMatrices                               *//*!

  \brief           Matrix substraction Res = A - B

  \description     This function performs matrix subtraction (inplace/outplace)
                   of two matrices A and B with same dimesions and store the result
                   in a resultant matrix.
                   [Res] = [A] - [B]
  \InOutCorrelation
                   \f[ \begin{bmatrix}
                   A_{00}    &   A_{01}\\
                   A_{10}    &   A_{11}
                   \end{bmatrix}
               -
                   \begin{bmatrix}
                   B_{00}    &   B_{01}\\
                   B_{10}    &   B_{11}
                   \end{bmatrix}
               =
                   \begin{bmatrix}
                   A_{00} -B_{00}    &   A_{01} -B_{01}\\
                   A_{10} -B_{10}    &   A_{11} -B_{11}
                   \end{bmatrix}
                   \f]
  \attention       
                   NOTE: Value for row/column is expected not to exceed 8 bits
                   CAUTION: Size of the matrix (rows x columns) must not
                   exceed p_MatrixRes->Desc.maxsize
                   p_MatrixRes->pData should hold a valid address.
  \param[in]       p_MatrixA : Minuend matrix
                               Range for p_MatrixA->Desc.row [Full range of uint8]
                               Range for p_MatrixA->Desc.col [Full range of uint8]
                               Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixA->pData 
                               [Valid pointer with data in full range of float32]
  \param[in]       p_MatrixB : Subtrahend matrix
                               Range for p_MatrixB->Desc.row [Full range of uint8]
                               Range for p_MatrixB->Desc.col [Full range of uint8]
                               Range for p_MatrixB->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixB->pData 
                               [Valid pointer with data in full range of float32]
                               Overflow may occur when one or more input values in both
                               matrices are at the defined range extremities.
  \param[out]      p_MatrixRes : Result Difference matrix

  \return          void

  \author          Dan Oprisan

  \testmethod    

  \traceability    
*****************************************************************************/
void CML_v_subtractMatrices(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA, const CML_t_Matrix* p_MatrixB);


/*****************************************************************************
  Functionname:    CML_v_multiplyMatrices                               *//*!

  \brief           Matrix multiplication

  \description     This function performs matrix multiplication (outplace)
                   of two matrices A and B and store the result in a
                   resultant matrix.
                   \f[[Res]_{m\times p} = [A]_{m\times n}\ \times \ [B]_{n\times p}\f]
  \InOutCorrelation
                   \f[ \begin{bmatrix}
                   A_{00}    &   A_{01}  & A_{02}\\
                   A_{10}    &   A_{11}  & A_{12}
                   \end{bmatrix}
               \times
                   \begin{bmatrix}
                   B_{00}    &   B_{01}\\
                   B_{10}    &   B_{11}\\
                   B_{20}    &   B_{21}\\
                   \end{bmatrix}
               =
                   \begin{bmatrix}
                   A_{00}\times  B_{00} + A_{01}\times B_{10}+A_{02}\times B_{20}   &&  A_{00}\times B_{01} + A_{01}\times B_{11}+A_{02}\times B_{21}\\
                   A_{10}\times  B_{00} + A_{11}\times B_{10}+A_{12}\times B_{20}   &&  A_{10}\times B_{01} + A_{11}\times B_{11}+A_{12}\times B_{21}\\
                   \end{bmatrix}
                   \f]

  \attention       
                   NOTE: Value for row/column is expected not to exceed 8 bits
                   CAUTION: Size of the matrix (p_MatrixB->Desc.col X p_MatrixA->Desc.row) must not
                   exceed p_MatrixRes->Desc.maxsize
                   p_MatrixA->Desc.col should be equal to p_MatrixB->Desc.row\\
                   p_MatrixRes->pData should hold a valid address
  \param[in]       p_MatrixA : Multiplicand matrix (source)
                               Range for p_MatrixA->Desc.row [Full range of uint8]
                               Range for p_MatrixA->Desc.col [Full range of uint8]
                               Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixA->pData 
                               [Valid pointer with data in full range of float32]
  \param[in]       p_MatrixB : Multiplier matrix (source)
                               Range for p_MatrixB->Desc.row [Full range of uint8]
                               Range for p_MatrixB->Desc.col [Full range of uint8]
                               Range for p_MatrixB->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixB->pData 
                               [Valid pointer with data in full range of float32]
                               Overflow may occur when one or more input values in both
                               matrices are at the defined range extremities.
  \param[out]      p_MatrixRes : Result Product matrix

  \return          void

  \author          Dan Oprisan, Uwe Zunker (optimization)

  \testmethod    

  \traceability    
*****************************************************************************/
void CML_v_multiplyMatrices(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA, const CML_t_Matrix* p_MatrixB);


/*****************************************************************************
  Functionname:    CML_v_multiplyMatricesToSymResult                    *//*!

  \brief           Matrix multiplication if result is symmetric

  \description     This function performs matrix multiplication (outplace)
                   of two matrices A and B and store the result in a
                   resultant matrix, if the result is known to be a symmetric
                   matrix.
                   [Res] = [A] x [B],
                   [A] is of the order MxN,
                   [B] is of the order NxM,
                   \f[[Res]_{m\times n} = [A]_{nXm}\ X\ [B]_{m\times m} \f]
  \InOutCorrelation
                    \f[\begin{bmatrix}
                   A_{00}    &   A_{01}  & A_{02}\\
                   A_{10}    &   A_{11}  & A_{12}\\
                   A_{20}    &   A_{21}  & A_{22}
                   \end{bmatrix}
               \times
                   \begin{bmatrix}
                   B_{00}    &   B_{01}    &   B_{02}\\
                   B_{10}    &   B_{11}    &   B_{12}\\
                   B_{20}    &   B_{21}    &   B_{22}\\
                   \end{bmatrix}
               =
                   \begin{bmatrix}
                   A_{00}\times B_{00} + A_{01}\times B_{10}+A_{02}\times B_{20}   &&  A_{00}\times B_{01} + A_{01}\times B_{11}+A_{02}\times B_{21}   &&  A_{00}\times B_{02} + A_{01}\times B_{12}+A_{02}\times B_{22}\\
                   A_{10}\times B_{00} + A_{11}\times B_{10}+A_{12}\times B_{20}   &&  A_{10}\times B_{01} + A_{11}\times B_{11}+A_{12}\times B_{21}   &&  A_{10}\times B_{02} + A_{11}\times B_{12}+A_{12}\times B_{22}\\
                   A_{20}\times B_{00} + A_{21}\times B_{10}+A_{22}\times B_{20}   &&  A_{20}\times B_{01} + A_{21}\times B_{11}+A_{22}\times B_{21}   &&  A_{20}\times B_{02} + A_{21}\times B_{12}+A_{22}\times B_{22}\\
                   \end{bmatrix}
                   \f]

  \attention       
                   NOTE: Value for row/column is expected not to exceed 8 bits
                   CAUTION: Size of the matrix (p_MatrixB->Desc.col X p_MatrixA->Desc.row) must not
                   exceed p_MatrixRes->Desc.maxsize
                   p_MatrixA->Desc.col should be equal to p_MatrixB->Desc.row\\
                   p_MatrixA->Desc.row should be equal to p_MatrixB->Desc.col\\
                   p_MatrixRes->pData should hold a valid address
  \param[in]       p_MatrixA : Multiplicand matrix
                               Range for p_MatrixA->Desc.row [Full range of uint8]
                               Range for p_MatrixA->Desc.col [Full range of uint8]
                               Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixA->pData 
                               [Valid pointer with data in full range of float32]
  \param[in]       p_MatrixB : Multiplier matrix
                               Range for p_MatrixB->Desc.row [Full range of uint8]
                               Range for p_MatrixB->Desc.col [Full range of uint8]
                               Range for p_MatrixB->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixB->pData 
                               [Valid pointer with data in full range of float32]
                               Overflow may occur when one or more input values in both
                               matrices are at the defined range extremities.
  \param[out]      p_MatrixRes : symmetric result matrix

  \return          void

  \author          Dan Oprisan

  \testmethod    

  \traceability    
*****************************************************************************/
void CML_v_multiplyMatricesToSymResult(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA, const CML_t_Matrix* p_MatrixB);


/*****************************************************************************
  Functionname:    CML_v_multiplyMatrixWithTranspose                    *//*!

  \brief           Matrix multiplication with transpose

  \description     This function performs matrix multiplication (outplace)
                   of matrix A with transpose of matrix B and store the
                   result in a resultant matrix.
                  \f[ [Res] = [A] \times [T] \\ \f]
                  \f[ [B] = [T]' \\ \f]
                  \f[ [Res] = [A] \times [B] \f]
                   \f[[Res]_{m\times n} = [A]_{nXm}\ \times \ [B]_{m\times n} \\\f]
  \InOutCorrelation
                    \f[\begin{bmatrix}
                   A_{00}    &   A_{01}  & A_{02}\\
                   A_{10}    &   A_{11}  & A_{12}
                   \end{bmatrix}
               \times
                   \begin{bmatrix}
                   B_{00}    &   B_{01}\\
                   B_{10}    &   B_{11}\\
                   B_{20}    &   B_{21}\\
                   \end{bmatrix}
               =
                   \begin{bmatrix}
                   A_{00}\times B_{00} + A_{01}\times B_{10}+A_{02}\times B_{20} &&  A_{00}\times B_{01} + A_{01}\times B_{11}+A_{02}\times B_{21}\\
                   A_{10}\times B_{00} + A_{11}\times B_{10}+A_{12}\times B_{20} &&  A_{10}\times B_{01} + A_{11}\times B_{11}+A_{12}\times B_{21}\\
                   \end{bmatrix}
                  \f]
  \attention       
                   NOTE: Value for row/column is expected not to exceed 8 bits
                   CAUTION: Size of the matrix (p_MatrixB->Desc.col X p_MatrixA->Desc.row) must not
                   exceed p_MatrixRes->Desc.maxsize
                   p_MatrixA->Desc.col should be equal to p_MatrixB->Desc.row\\
                   p_MatrixRes->pData should hold a valid address
  \param[in]       p_MatrixA : Multiplicand matrix
                               Range for p_MatrixA->Desc.row [Full range of uint8]
                               Range for p_MatrixA->Desc.col [Full range of uint8]
                               Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixA->pData 
                               [Valid pointer with data in full range of float32]
  \param[in]       p_MatrixB : Transpose of which is the multiplier matrix
                               Range for p_MatrixB->Desc.row [Full range of uint8]
                               Range for p_MatrixB->Desc.col [Full range of uint8]
                               Range for p_MatrixB->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixB->pData 
                               [Valid pointer with data in full range of float32]
                               Overflow may occur when one or more input values in both
                               matrices are at the defined range extremities.
  \param[out]      p_MatrixRes : result matrix

  \return          void

  \author          Dan Oprisan, Uwe Zunker (optimization)

  \testmethod    

  \traceability    
*****************************************************************************/
void CML_v_multiplyMatrixWithTranspose(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA, const CML_t_Matrix* p_MatrixB);


/*****************************************************************************
  Functionname:    CML_v_invertMatrix                                   *//*!

  \brief           Compute matrix inverse.

  \description     Compute matrix inverse: Res = inv(A)
                   Uses Gauss-Jordan elimination with partial pivoting.
                   For matrices upto 3x3, determinant is found, singularity is
                   checked and processing is done, whereas for higher order
                   matrices, matrix singularity is determined during the
                   processing.\n
                   The function checks if the matrix has valid dimensions, is a square 
                   matrix and also if the resultant matrix has enough size to hold the data.
                   The function will not process the data if the input conditions are not
                   satisfied, instead returns the resultant matrix with both row and column
                   dimensions set to zero. The checks can be disabled with the help of 
                   macro CML_MatrixBoundsCheckOn if the conditions are prechecked before the
                   function call. \n The function checks the size of the matrix. For single
                   element matrix, a direct division of the element is done, provided the element 
                   is non-zero. For 2x2 and 3x3 matrices, Cramer's rule is applied to calculate
                   the inverse. For matrix sizes of 4x4 and more, Gauss Jordan elimination method 
                   is used.
                   @startuml
                   legend
                   Gauss - Jordan method
                   endlegend
                   (*) --> Set result matrix, R as an identity matrix
                   --> Find largest element on the selected column and use as pivot element
                   --> Check the pivot element value, p
                   If p<p0
                   note left : p0 is the minimum threshold value almost equal to zero (1e-10)
                   --> [Yes] Set empty matrix
                   Else
                   --> [No] Swap rows to put the pivot element on the diagonal
                   --> Same swap operation to be done on the result matrix, R
                   --> Divide row by the pivot element so that pivot becomes 1. \n Same operation should be repeated for result matrix, R
                   --> Loop through the other rows 
                   note right #aqua
                   Now multiply the row by the right amount and substract from 
                   each other row to make all the remaining elements in the pivot column zero 
                   end note
                   --> Use the first element in row as scaling coeffiecient 
                   --> Substract pivot row multiplied by scaling from other row \n Repeat the same set of operation for result matrix, R
                   If All Rows Covered?
                   --> [Yes] Increment the column count and check if all columns are covered
                   If All Columns covered ?
                   --> [Yes] Check matrix inversion was successful
                   If matrix invertible?
                   --> [Yes] Set the dimension parameters for the resultant matrix
                   --> (*)
                   Else
                   --> [No] Set empty matrix
                   --> (*)
                   EndIf
                   Else
                   --> [No] Find largest element on the selected column and use as pivot element
                   EndIf
                   Else
                   --> [No] Loop through the other rows 
                   EndIf
                   @enduml

                   Cramer's Rule for matrix size 2x2.
                  \f[ A =  \begin{bmatrix}
                   A_0    &   A_1 \\
                   A_2    &   A_3
                   \end{bmatrix}  \f]
                   \f[ Determinant, d = (A_0 \times A_3) - (A_2 \times A_1) \f]
                   \f[ A^{-1} = \begin{bmatrix}
                   (\frac{A_3}{d}    &   \frac{-A_1}{d} \\
                   \frac{-A_2}{d}    &   \frac{A_0}{d}
                   \end{bmatrix}  \f]
                   Cramer's rule for matrix size 3x3.
                   \f[ A = \begin{bmatrix}
                   A_0     &   A_1  & A_2 \\
                   A_3     &   A_4  & A_5 \\
                   A_6     &   A_7  & A_8 \\
                   \end{bmatrix}  \f]
                   \f[ Determinant, d = (((A_0 \times A_4) - (A_3 \times A_1)) \times A_8) + 
           (((A_3 \times A_7) - (A_6 \times A_4)) \times A_2) +
           (((A_6 \times A_1) - (A_0 \times A_7)) \times A_5) \f]
                   \f[ A = \begin{bmatrix}
                   (\frac{(A_4 \times A_8) - (A_5 \times A_7))}{d}     &   \frac{((A_2 \times A_7) - (A_1 \times A_8))}{d}  &   \frac{((A_1 \times A_5) - (A_2 \times A_4))}{d}  \\
                   (\frac{(A_5 \times A_6) - (A_3 \times A_8))}{d}     &   \frac{((A_0 \times A_8) - (A_2 \times A_6))}{d}  &   \frac{((A_2 \times A_3) - (A_0 \times A_5))}{d}  \\
                   (\frac{(A_3 \times A_7) - (A_4 \times A_6))}{d}     &   \frac{((A_1 \times A_6) - (A_0 \times A_7))}{d}  &   \frac{((A_0 \times A_4) - (A_1 \times A_3))}{d}  \\
                   \end{bmatrix}  \f]

  \param[in,out]   p_MatrixA : matrix to be inversed.
                               Range for p_MatrixA->Desc.row [Full range of uint8]
                               Range for p_MatrixA->Desc.col [Full range of uint8]
                               Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixA->pData 
                               [Valid pointer with data in full range of float32]
                   The largest element on the each column MUST BE greater than
                   the tolerance value (1e-10F). Otherwise function call will
                   result in assertion fail.
                   ATTENTION! This matrix is overwritten with the identity matrix.
  \param[in,out]   p_MatrixRes : result matrix, containing the inverse of A

  \return          void

  \author          Dan Oprisan

  \testmethod    

  \traceability    
*****************************************************************************/
void CML_v_invertMatrix(CML_t_Matrix* p_MatrixRes, CML_t_Matrix* p_MatrixA);

/*****************************************************************************
  Functionname:    CML_v_scaleMatrix                                    *//*!

  \brief           Matrix multiplication with scalar

  \description     This function does an inplace matrix multiplication
                   with a given scalar. If [A] is the matrix, and p is
                   the scalar, then,
  \InOutCorrelation
                   \f[ [A]_{m\times n} = f_{Val} \times [A]_{m\times n}\\
                    \begin{bmatrix}
                   A_{00}    &   A_{01}  & A_{02}\\
                   A_{10}    &   A_{11}  & A_{12}
                   \end{bmatrix}
               X
                   \ p
               =
                   \begin{bmatrix}
                   A_{00} \times p &   A_{01} \times p   &   A_{02} \times p\\
                   A_{10} \times p &   A_{11} \times p   &   A_{12} \times p
                   \end{bmatrix}
                   \f]
  \attention       
                   NOTE: Value for row/column is expected not to exceed 8 bits
                   p_MatrixRes->pData should hold a valid address
  \param[in,out]   p_MatrixA : Matrix o be multiplied
                               Range for p_MatrixA->Desc.row [Full range of uint8]
                               Range for p_MatrixA->Desc.col [Full range of uint8]
                               Range for p_MatrixA->pData 
                               [Valid pointer with data in full range of float32]
                               Overflow may occur when one or more input values in both
                               matrices are at the defined range extremities.
  \param[in]       f_Val :     scalar
                               [Full range of float32]

  \return          void

  \author          Dan Oprisan

  \testmethod    

  \traceability    
*****************************************************************************/
void CML_v_scaleMatrix(CML_t_Matrix* p_MatrixA, float32 f_Val);


/*****************************************************************************
  Functionname:    CML_v_copyMatrix                                     *//*!

  \brief           Matrix copy

  \description     This function copies data from one matrix to another.

  \InOutCorrelation
                   \f[[Res]_{m\times n} = [A]_{m\times n}\\
                    \begin{bmatrix}
                   Res_{00}  &   Res_{01}  & Res_{02}\\
                   Res_{10}  &   Res_{11}  & Res_{12}
                   \end{bmatrix}
               =
                   \begin{bmatrix}
                   A_{00}    &   A_{01}  &   A_{02} \\
                   A_{10}    &   A_{11}  &   A_{12} 
                   \end{bmatrix}
                   \f]
  \attention       
                   NOTE: Value for row/column is expected not to exceed 8 bits
                   CAUTION: Size of the matrix (p_MatrixB->Desc.col X p_MatrixA->Desc.row) must not
                   exceed p_MatrixRes->Desc.maxsize
                   p_MatrixRes->pData should hold a valid address
  \param[in]       p_MatrixA : matrix to be copied
                               Range for p_MatrixA->Desc.row [Full range of uint8]
                               Range for p_MatrixA->Desc.col [Full range of uint8]
                               Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                               Range for p_MatrixA->pData 
                               [Valid pointer with data in full range of float32]
  \param[out]      p_MatrixRes : destination matrix
                                 Range for p_MatrixRes->Desc.maxsize [Full range of uint16]

  \return          void

  \author          Dan Oprisan

  \testmethod    

  \traceability    
*****************************************************************************/
void CML_v_copyMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA);


/*****************************************************************************
  Functionname:    CML_v_copyArrayToSymMatrix                           *//*!

  \brief           Fill matrix with data from array

  \description     This functon copies data from an array to a matrix.
                   The resultant matrix is a symmetric matrix.
  \InOutCorrelation

                   \f[[Res]_{m\times n} = [A]_{m\times n}\\
                    \begin{bmatrix}
                   Res_{00}  &   Res_{01}  & Res_{02}\\
                   Res_{10}  &   Res_{11}  & Res_{12}
                   \end{bmatrix}
               =
                   \begin{bmatrix}
                   A_{00}    &   A_{01}  &   A_{02} \\
                   A_{10}    &   A_{11}  &   A_{12} 
                   \end{bmatrix}
                   \f]

  \param[in]       p_Data :  data to be copied
                             [Valid pointer with data in full range of float32]
  \param[out]      p_MatrixRes : destination matrix
  \param[in]       u_RowNr : no. of rows
                             [Full range of uint8]
  \param[in]       u_ColNr : no. of columns
                             [Full range of uint8]

  \return          void

  \author          Dan Oprisan

  \testmethod    

  \traceability    
*****************************************************************************/
void CML_v_copyArrayToSymMatrix(CML_t_Matrix* p_MatrixRes, uint32 u_RowNr, uint32 u_ColNr, const float32* p_Data);


/*****************************************************************************
  Functionname:    CML_v_choleskyMatrix                                 *//*!

  \brief           Compute Cholesky factor of a p.d. hermitian matrix

  \description     The Cholesky factorization is decomposing the hermitian
                   positive definite matrix (A) into product of a lower triangular
                   matrix (L) and its conjugare transpose (L*).
                   A = LL*
                   This function returns this lower triangular square root of
                   the positive definite real symmetric matrix, no exception
                   handling for any kind of rank deficiency rather direct
                   regularization
                   (associated m-file for unit testing: slow_chol2.m)
                   \f[[A]_{m\times m} = [L]_{m\times m} \times [L^T]_{m\times m} \\
                   \begin{bmatrix}
                   A_{00}    &   A_{01}  &   A_{02} \\
                   A_{10}    &   A_{11}  &   A_{12} \\
                   A_{20}    &   A_{21}  &   A_{22} 
                   \end{bmatrix}
                   =
                   \begin{bmatrix}
                   L_{11}    &   L_{21}      &   L_{31}\\
                   0         &   L_{22}      &   L_{32}\\
                   0         &   0           &   L_{33}
                   \end{bmatrix}
                   \times
                   \begin{bmatrix}
                   L_{11}    &   0           &   0\\
                   L_{21}    &   L_{22}      &   0\\
                   L_{31}    &   L_{32}      &   L_{33}\\
                   \end{bmatrix}\f]
  \InOutCorrelation
                   Following formula is used for entries of L:
                   \f[ L_{j,j} = \sqrt{A_{j,j} - \sum_{k=1}^{j-1}{L_{j,k}}^2}\f]  
                   \f[ L_{i,j} = \frac{A_{i,j} - \sum_{k=1}^{j-1}L_{i,k}L_{j,k}}{L_{j,j}}, for\ i>j.\f]
  \attention       
                   NOTE: Value for row/column is expected not to exceed 8 bits.
                   CAUTION: Size of the matrix (p_MatrixA->Desc.col X p_MatrixA->Desc.row) must not
                   exceed p_MatrixRes->Desc.maxsize.
                   p_MatrixA->Desc.col should be equal to p_MatrixA->Desc.row
                   p_MatrixRes->pData should hold a valid address.
                   Regularization of values is done for matrix values less than 1e-10F.
  \param[in,out]   p_MatrixA :   matrix whose Cholesky type square root is wanted
                                 Range for p_MatrixA->Desc.row [Full range of uint8]
                                 Range for p_MatrixA->Desc.col [Full range of uint8]
                                 Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                                 Range for p_MatrixA->pData 
                                 [Valid pointer with data in full range of float32]
  \param[in,out]   p_MatrixRes : lower triangular result matrix
                                 Range for p_MatrixRes->Desc.maxsize [Full range of uint16]

  \return          void

  \author          uidt8688

  \testmethod    

  \traceability    
*****************************************************************************/
void CML_v_choleskyMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA);

/*****************************************************************************
  Functionname:    CML_v_lowTriaInvMatrix                               *//*!

  \brief           Inverse of p.d. lower triangular matrix  by forward substitution

  \description     The method of choice for inversion of positive definite
                   symmetric matrices consists of Cholesky factorization followed
                   by forward substitution which is efficiently implemented
                   in this function, no exception handling in case of indefinite
                   input rather brute force regularization which is appropriate
                   for square-root Kalman filter applications but does a poor
                   job in approximating the Pseudo-Inverse for least-squares.

                   @startuml
                   (*) --> Regularization of input values.
                   note left : Done to avoid divide by 0 errors.
                   -->Take inverse of only diagonal elements
                   note right : in place predivision for efficiency.
                   -->Assign all Result matrix elements to 0.
                   -->loop through lower triangle elements only.
                   note left: by restricting range of loops.
                   -->calculate multiplication factor(f).
                   note right: formula for calculation is mentioned below.
                   If row_index == column_index
                   --> [YES] Input_matrix element * (1.0 - f)
                   -->check if all elements are processed
                   else
                   --> [NO] Input_matrix element * (-f)
                   Endif
                   -->check if all elements are processed
                   if processing complete
                   -->[YES](*)
                   else
                   -->[NO]loop through lower triangle elements only.
                   Endif
                   @enduml
                   If A is the input matrix and Res is resultant matrix, j and i are column indices and row indices respectively then,
                   \f[ F = \sum_{k = 0}^{j}{A_{j,k} \times Res_{k, i}} \f]

  \param[in,out]   p_MatrixA :   lower triangular p.d. matrix (upper triangular entries are irrelevant)
                                 Range for p_MatrixA->Desc.row [Full range of uint8]
                                 Range for p_MatrixA->Desc.col [Full range of uint8]
                                 Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                                 Range for p_MatrixA->pData 
                                 [Valid pointer with data in full range of float32]
  \param[in,out]   p_MatrixRes : lower triangular inverse of A (upper triangular entries are invalid)
                                 Range for p_MatrixRes->Desc.maxsize [Full range of uint16]

  \return          void

  \author          uidt8688

  \testmethod    

  \traceability    
*****************************************************************************/
void CML_v_lowTriaInvMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA); //AlgoMtrxLowTriaInv 


/*****************************************************************************
  Functionname:    CML_v_lowTriaSqrMatrix                               *//*!

  \brief           Square of Cholesky Res = A*transpose(A), with A lower triangular

  \description     The method of choice for squaring of positive definite
                   symmetric matrices is from Cholesky method. This function
                   computes the product of the lower traingular matrix and its
                   transpose.\n
                   The function checks if the matrix has valid dimensions, is a square 
                   matrix and also if the resultant matrix has enough size to hold the data.
                   The function will not process the data if the input conditions are not
                   satisfied, instead returns the resultant matrix with both row and column
                   dimensions set to zero. The checks can be disabled with the help of 
                   macro CML_MatrixBoundsCheckOn if the conditions are prechecked before the
                   function call.
                   @startuml
                   (*)--> Check the validity of the input and output martices
                   note left : This check can be turned off with the macro CML_MatrixBoundsCheckOn 
                   --> Loop through the rows of the matrix for i=0 to no.of rows
                   --> Loop through the columns of matrix for j = 0 to i
                   note left #aqua
                   The loop only need to process the lower triangular part of matrix, since we know upper matrix elements are zero. 
                   end note
                   --> Compute the value 'T' as given in the equation (1)
                   --> Set the resultant matrix R(i,j) = R(j,i) = T
                   If Is end of loop for column?
                   --> [Yes] If Is end of loop for row?
                   --> [Yes] Set the dimensions for the resultant matrix
                   --> (*)
                   Else
                   --> [No] Loop through the rows of the matrix for i=0 to no.of rows
                   EndIf
                   Else
                   --> [No] Loop through the columns of matrix for j = 0 to i
                   EndIf
                   @enduml
  
                   The T value for i-th row and j-th column is calculated as follows.
                   \f[ T = \sum_{k = 0}^{p}{A_{j,k} \times A_{i,k}} \f]
                   where p is the minimum of i and j.

  \param[in,out]   p_MatrixA :   lower triangular p.d. matrix
                                 (upper triangular entries are irrelevant)
                                 Range for p_MatrixA->Desc.row [Full range of uint8]
                                 Range for p_MatrixA->Desc.col [Full range of uint8]
                                 Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                                 Range for p_MatrixA->pData 
                                 [Valid pointer with data in full range of float32]
  \param[in,out]   p_MatrixRes : square matrix A*transpose(A) symmetric and
                                 positive definite
                                 Range for p_MatrixRes->Desc.maxsize [Full range of uint16]

  \return          void

  \author          uidt8688

  \testmethod    

  \traceability    
*****************************************************************************/
void CML_v_lowTriaSqrMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA); //AlgoMtrxLowTriaSqr 


/*****************************************************************************
  Functionname:    CML_v_uppTriaSqrMatrix                               *//*!

  \brief           Res = A*transpose(A), with A upper triangular
  \description     This function computes the product of the upper triangular
                   matrix and its transpose. \n
                   The function checks if the matrix has valid dimensions, is a square 
                   matrix and also if the resultant matrix has enough size to hold the data.
                   The function will not process the data if the input conditions are not
                   satisfied, instead returns the resultant matrix with both row and column
                   dimensions set to zero. The checks can be disabled with the help of 
                   macro CML_MatrixBoundsCheckOn if the conditions are prechecked before the
                   function call.
                   @startuml
                   (*)--> Check the validity of the input and output martices
                   note left : This check can be turned off with the macro CML_MatrixBoundsCheckOn 
                   --> Loop through the rows of the matrix for i=0 to no.of rows
                   --> Loop through the columns of matrix for j = 0 to i
                   note left #aqua
                   The loop only need to process the lower triangular part of matrix, since we know upper matrix elements are zero. 
                   end note
                   --> Compute the value 'T' as given in the equation (1)
                   --> Set the resultant matrix R(i,j) = R(j,i) = T
                   If Is end of loop for column?
                   --> [Yes] If Is end of loop for row?
                   --> [Yes] Set the dimensions for the resultant matrix
                   --> (*)
                   Else
                   --> [No] Loop through the rows of the matrix for i=0 to no.of rows
                   EndIf
                   Else
                   --> [No] Loop through the columns of matrix for j = 0 to i
                   EndIf
                   @enduml
  
                   The T value for i-th row and j-th column, is calculated as follows.
                   \f[ T = \sum_{k = i1}^{R}{A_{j,k} \times A_{i,k}} \f]
                   where R is the no. of rows.

  \param[in,out]   p_MatrixA   : upper triangular p.d. matrix
                                 (lower triangular entries are irrelevant)
                                 Range for p_MatrixA->Desc.row [Full range of uint8]
                                 Range for p_MatrixA->Desc.col [Full range of uint8]
                                 Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                                 Range for p_MatrixA->pData 
                                 [Valid pointer with data in full range of float32]
  \param[in,out]   p_MatrixRes : square matrix A*transpose(A) symmetric and
                                 positive definite
                                 Range for p_MatrixRes->Desc.maxsize [Full range of uint16]

  \return          void

  \author          uidt8688

  \testmethod    

  \testmethod    

  \traceability    
*****************************************************************************/
void CML_v_uppTriaSqrMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA); //AlgoMtrxUppTriaSqr 


/* ***************************************************************************
  Functionname:    CML_v_transposeMatrix                                *//*!

  \brief           Matrix transposition, outplace

  \description     This function calculates the transpose of a matrix
                   (outplace)
  \InOutCorrelation
                   \f[A_{m\times m} = 
                   \begin{bmatrix}
                   A_{00}    &   A_{01}  \\
                   A_{10}    &   A_{11}  \\
                   \end{bmatrix}
                   \\then, 
                   [A^T]_{m\times m} = 
                   \begin{bmatrix}
                   A_{00}    &   A_{10}  \\
                   A_{01}    &   A_{11}  \\
                   \end{bmatrix}
                   \f]
  \attention       
                   NOTE: Value for row/column is expected not to exceed 8 bits.
                   CAUTION: Size of the matrix (p_MatrixA->Desc.col X p_MatrixA->Desc.row) must not
                   exceed p_MatrixRes->Desc.maxsize.
                   p_MatrixRes->pData should hold a valid address.
  \param[in]       p_MatrixA :    matrix o be transposed (source)
                                  Range for p_MatrixA->Desc.row [Full range of uint8]
                                  Range for p_MatrixA->Desc.col [Full range of uint8]
                                  Range for p_MatrixA->Desc.maxsize [Full range of uint16]
                                  Range for p_MatrixA->pData 
                                  [Valid pointer with data in full range of float32]
  \param[out]      p_MatrixRes :  destination matrix
                                  Range for p_MatrixRes->Desc.maxsize [Full range of uint16]
                                  Range for p_MatrixRes->pData 
                                  [Valid pointer with data in full range of float32]

  \return          none

  \author          Dan Oprisan

  \testmethod    

  \traceability    
**************************************************************************** */
void CML_v_transposeMatrix(CML_t_Matrix* p_MatrixRes, const CML_t_Matrix* p_MatrixA); //AlgoMtrxTrsp


/*****************************************************************************
  Functionname:    CML_initMatrixHeader                                *//*!

  \brief           helper function for creation of matrices with local scope
                  
  \description     Return a copy of the matrix structure used for 
                  setting up the user matrix. This is a work around
                  because a structure cannot be initialized via constructor 
                  with non-static pointers.
                  
  \param[in]       u_ColNr : number of columns
                            [Full range of uint8]
  \param[in]       u_RowNr : number of rows
                            [Full range of uint8]
  \param[in]       p_f_MtrxData : pointer to matrix data
                                 [Valid pointer with data in full range of float32]
                  
  \return          Matrix structure initialized with given data
                  
  \author          Dan Oprisan

  \testmethod  
  \traceability  
*****************************************************************************/

/* Deactivate QA-C warning 3406; Reviewer: S. Schwarzkopf; 
   Date: 04.12.2014; Reason: Styleguide wants it like this and CML_INLINE is 
   defined compiler dependent for inlining without external linkage.
   Review-ID: 3942463 */
/* PRQA S 3406 1 */
CML_INLINE CML_t_Matrix CML_initMatrixHeader(uint32 u_ColNr, uint32 u_RowNr, float32* p_f_MtrxData)
{
  CML_t_Matrix Ret;
  Ret.Desc.col = (uint8)u_ColNr;
  Ret.Desc.row = (uint8)u_RowNr;
  Ret.Desc.maxsize = (uint16)(u_RowNr * u_ColNr);
  Ret.pData = p_f_MtrxData;

  return Ret;
}


#endif  /* #ifndef _CML_MTRX_INCLUDED */


/** @} end defgroup */
