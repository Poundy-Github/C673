/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_mat.c

  DESCRIPTION:               matrix computation toolbox

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             03.02.2010

  VERSION:                   $Revision: 1.13.1.2 $

  ---*/ /*---
  CHANGES:                   $Log: cml_mat.h  $
  CHANGES:                   Revision 1.13.1.2 2019/06/21 15:15:02CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   QAF Level3 fixes for MFC431TA19
  CHANGES:                   Revision 1.13.1.1 2019/05/27 11:01:00CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   MFC431TA19: QAF L4 fixes added
  CHANGES:                   Revision 1.13 2018/02/27 06:50:59CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Removed the spaces after \ ; The change was lost while updating to the legacy release.
  CHANGES:                   Revision 1.12 2018/02/26 08:51:29CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the source code with respect to AL_CML_01.09.18_INT-1
  CHANGES:                   Revision 1.11 2017/12/20 06:37:50CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Correction for the compilation warning
  CHANGES:                   Revision 1.10 2017/11/14 18:41:49CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated to the code from AL_CML_01.09.13_INT-1
  CHANGES:                   Revision 1.9 2017/08/04 06:04:23CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Aligned and merged changes from AL_CML_01.09.11_INT-1
  CHANGES:                   Revision 1.8 2015/04/29 15:01:49CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Changes with respect to Coding Guidelines
  CHANGES:                     of variables
  CHANGES:                   - Added comments -  uidr5428 [Apr 29, 2015 3:01:50 PM CEST]
  CHANGES:                   Change Package : 324617:2 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.7 2014/12/04 16:01:06CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - changed input data of several functions from pointer to array as they are accessed this way
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 4, 2014 4:01:06 PM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.6 2014/04/07 10:31:29CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed erroneous include protection
  CHANGES:                   --- Added comments ---  uidg6516 [Apr 7, 2014 10:31:29 AM CEST]
  CHANGES:                   Change Package : 227281:3 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.5 2014/02/04 15:12:56CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - improve code quality
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 4, 2014 3:12:57 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.4 2013/07/08 13:09:41CEST Schlensag, Andreas (schlensaga) 
  CHANGES:                   add matrix member f35 and f45 for 6x6 symmetric matrix
  CHANGES:                   --- Added comments ---  schlensaga [Jul 8, 2013 1:09:41 PM CEST]
  CHANGES:                   Change Package : 185100:3 http://mks-psad:7002/im/viewissue?selection=185100
  CHANGES:                   Revision 1.3 2013/05/03 09:57:12CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   - use new standard type names, e.g. float32 instead of f32_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:57:12 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2012/09/20 13:29:46CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:46 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:16CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/**
@defgroup mat MAT (matrix computation toolbox)
  @ingroup cml
@{ */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/
#ifndef CML_MAT_INCLUDED
#define CML_MAT_INCLUDED

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_mat.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef CML_EXT_INCLUDED */

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
/*************************************************************************//*!
 \brief     Holds a matrix with one element
 \details   The Structure holds the element of a 1x1 matrix. The element is represented by a 32-bit floating point value.
            \f[ \begin{bmatrix}
             f00  \\
            \end{bmatrix} 
            \f]
****************************************************************************/
typedef struct
{
  float32 f00; ///< The only element of the matrix 
} CML_t_SymMatrix1;

/*************************************************************************//*!
 \brief     A symmetric matrix of 2x2 elements
 \details   The Structure holds the elements of a 2x2 matrix. The elements are represented by a 32-bit floating point value.
            \f[ \begin{bmatrix}
             f00  &   f01  \\
             f10  &   f11  \\
            \end{bmatrix} 
              \f]
****************************************************************************/
typedef struct
{
  float32 f00;      ///< Element at (0,0)
  float32 f01;      ///< Element at (0,1) and (1,0). The two values will be same due to symmetry
  float32 f11;      ///< Element at (1,1)
} CML_t_SymMatrix2;

/*************************************************************************//*!
 \brief     A symmetric matrix of 6x6 elements
 \details   The Structure holds the elements of a 6x6 matrix. The elements are represented by a 32-bit floating point value.
            \f[ \begin{bmatrix}
             f00  &   f01  &  f02  &  f03  &   f04  &  f05 \\
             f10  &   f11  &  f12  &  f13  &   f14  &  f15 \\
             f20  &   f21  &  f22  &  f23  &   f24  &  f25 \\
             f30  &   f31  &  f32  &  f33  &   f34  &  f35 \\
             f40  &   f41  &  f42  &  f43  &   f44  &  f45 \\
             f50  &   f51  &  f52  &  f53  &   f54  &  f55 \\
            \end{bmatrix} 
            \f]
****************************************************************************/
typedef struct
{
  /* (because of symmetry: f10=f01, f13 = f31, f12=f21, f13 = f31, f20=f02, f23 = f32), etc... */   
  float32 f00;      ///< Element at (0,0)
  float32 f01;      ///< Element at (0,1) and (1,0). The two values will be same due to symmetry
  float32 f02;      ///< Element at (0,2) and (2,0). The two values will be same due to symmetry
  float32 f03;      ///< Element at (0,3) and (3,0). The two values will be same due to symmetry
  float32 f04;      ///< Element at (0,4) and (4,0). The two values will be same due to symmetry
  float32 f05;      ///< Element at (0,5) and (5,0). The two values will be same due to symmetry
  float32 f11;      ///< Element at (1,1) 
  float32 f12;      ///< Element at (1,2) and (2,1). The two values will be same due to symmetry
  float32 f13;      ///< Element at (1,3) and (3,1). The two values will be same due to symmetry
  float32 f14;      ///< Element at (1,4) and (4,1). The two values will be same due to symmetry
  float32 f15;      ///< Element at (1,5) and (5,1). The two values will be same due to symmetry
  float32 f22;      ///< Element at (2,2) 
  float32 f23;      ///< Element at (2,3) and (3,2). The two values will be same due to symmetry
  float32 f24;      ///< Element at (2,4) and (4,2). The two values will be same due to symmetry
  float32 f25;      ///< Element at (2,5) and (5,2). The two values will be same due to symmetry
  float32 f33;      ///< Element at (3,3) 
  float32 f34;      ///< Element at (3,4) and (4,3). The two values will be same due to symmetry
  float32 f35;      ///< Element at (3,5) and (5,3). The two values will be same due to symmetry
  float32 f44;      ///< Element at (4,4) 
  float32 f45;      ///< Element at (4,5) and (5,4). The two values will be same due to symmetry
  float32 f55;      ///< Element at (5,5) 
} CML_t_SymMatrix6s;

/// \brief Different types of Transformation Matrix Types.
typedef enum {
  DEFAULT_,     ///< The default type, includes both rotation and translation
  ROTATION_,    ///< The matrix type for rotational transformation
  TRANSLATION_  ///< The matrix type for translational transformation
} CML_t_TrafoType;

/*************************************************************************//*!
 \brief     Structure for 2D Transfromation Matrix
 \details   The Structure holds the matrix values for the transformation matrix and also the type of the matrix. \n
            No need to save the second column since <b> f01 = -f10 </b> and <b> f11 = f00 </b> \n
            Also no need to save the third row since  <b> f20 = 0, f21 = 0, f22 = 1 </b> \n
            2D Transformation matrizes are of the form \n
            \f[ \begin{bmatrix}
             f00  &  -f10  &  f02 \\
             f10  &   f00  &  f12 \\
             0    &   0    &  1   \\
            \end{bmatrix} 
            \f]

            TRANSLATION |  1     0   DX|
                        |  0     1   DY|
                        |  0     0    1|

            ROTATION    |COS  -SIN    0|
                        |SIN   COS    0|
                        |  0     0    1|

            DEFAULT     |COS  -SIN   DX|
                        |SIN   COS   DY|
                        |  0     0    1|
****************************************************************************/
typedef struct
{
  CML_t_TrafoType TrafoType;
  float32 f00;    ///< The cosine value in the transformation matrix. Also, f11 = f00
  float32 f02;    ///< The X value of translation in the transformation matrix
  float32 f10;    ///< The sine value in the transformation matrix. Also, f01 = -f10
  float32 f12;    ///< The Y value of translation in the transformation matrix
} CML_t_TrafoMatrix2D;


/// \brief     Holds a vector of one element
/// \details   The Structure holds the element of a 1D vector. The element is represented by a 32-bit floating point value.
typedef struct
{
  float32 f0;     ///< The element of the vector
} CML_t_Vector1D;

/// \brief     Holds a vector of two elements
/// \details   The Structure holds the elements of a 2D vector. The elements are represented by 32-bit floating point values.
typedef struct
{
  float32 f0;     ///< First element of the 2D vector
  float32 f1;     ///< Second element of the 2D vector
} CML_t_Vector2D;

/// \brief     Holds a 2D Point
/// \details   The Structure holds the elements of a 2D Point (X,Y). The elements are represented by 32-bit floating point values.
/* PRQA S 0784 10 */
/* Deactivate QAF warning 0784, Date: 2019-06-19; Reviewer: uidk9586;   
   Reason: Macro defined with same name has been undefined in same file, 
   making it local and not having any impact for the defined variable. */
typedef struct{
  float32 X;     ///< X value of the 2D Point
  float32 Y;     ///< Y value of the 2D Point
} CML_t_Point2D;

/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/

/*****************************************************************************
  Functionname:    CML_TrafoMatrix2DInvert                              *//*! 

  \brief           Inversion of a transformation matrix A

  \description     This function calculates the inverse of a transformation
                   matrix. If 'A' is a transformation matrix, then the inverse 
                   'A^(-1)' can be calculated as follows:
  \InOutCorrelation
                   \f[   
                   A = \begin{bmatrix}
                   cos(A)    &   -sin(A)  & DX\\
                   sin(A)    &   cos(A)   & DY\\
                   0         &   0        & 1\\
                   \end{bmatrix}\\
                   A^{-1} = 
                   \begin{bmatrix}
                   cos(A)    &   sin(A)   & - DX\times cos(A) - DY\times sin(A)\\
                   -sin(A)   &   cos(A)   & DX\times sin(A) - DY\times cos(A)\\
                   0         &   0        & 1\\
                   \end{bmatrix}
                   \f]
  \param[in]       MatrixA :  trafo matrix
                              Range for MatrixA.f00 is [0,..,1]
                              Range for MatrixA.f02 is [Full range of float32]
                              Range for MatrixA.f10 is [0,..,1]
                              Range for MatrixA.f12 is [Full range of float32]
     
  \return          the inverted matrix A^(-1)

  \author          Norman Apel

  \testmethod    

  \traceability 
*****************************************************************************/
CML_t_TrafoMatrix2D CML_TrafoMatrix2DInvert(CML_t_TrafoMatrix2D MatrixA);

/*****************************************************************************
  Functionname:    CML_TrafoMatrix2DMult                                *//*! 

  \brief           Multiplication of two transformation matrices

  \description     This function does the multiplication of two transformation
                   matrices.
                   Multiplication is performed after checking the matrix type 
                   for each matrix, whether translation, rotation or default.
                   Matrix multiplication optimized under the fact, that all 
                   2D Transformation matrizes are of the form.

  \InOutCorrelation
                   \f[   
                   TRANSLATION = \begin{bmatrix}
                   1     &   0   & DX\\
                   0     &   1   & DY\\
                   0     &   0   & 1\\
                   \end{bmatrix}\\
                   ROTATION = \begin{bmatrix}
                   COS   & -SIN  &  0\\
                   SIN   &  COS  &  0\\
                   0     &   0   &  1\\
                   \end{bmatrix}\\
                   DEFAULT = \begin{bmatrix}
                   COS   & -SIN  &  DX\\
                   SIN   &  COS  &  DY\\
                   0     &   0   &  1\\
                   \end{bmatrix}\\
                   \f]        
                   Conventional matrix multiplication is followed in case of multipliaction of two Default TrafoType matrices. Other matrices are optimized based on type of transformation to achieve maximum effeciency.
  \InOutCorrelation
                   Multiplication of two Default transformation matrices can be represented as shown below:
                   Mat = MatrixA X  MatrixB
                   \f[   
                   Mat = \begin{bmatrix}
                   M_{00}    &   M_{01}  & M_{02}\\
                   M_{10}    &   M_{11}  & M_{12}\\
                   M_{20}    &   M_{21}  & M_{22}\\
                   \end{bmatrix}
                   = \begin{bmatrix}
                   (A_{00}\times B_{00}) - (A_{10}\times B_{10}) &   -M_{10} & ( (A_{00}\times B_{02}) - (A_{10}\times B_{12}) ) + A_{02}\\
                   (A_{00}\times B_{10}) + (A_{10}\times B_{00}) &    M_{00} & ((A_{10}\times B_{02}) + (A_{00}\times B_{12}))  + A_{12}\\
                   0         &   0       & 1\\
                   \end{bmatrix}\\
                   \f]  
  \param[in]       MatrixA :  first trafo matrix
                              Supported values for MatrixA.TrafoType are 0,1,2.
                              Range for MatrixA.f00 is [0,..,1]
                              Range for MatrixA.f02 is [Full range of float32]
                              Range for MatrixA.f10 is [0,..,1]
                              Range for MatrixA.f12 is [Full range of float32]

  \param[in]       MatrixB :  second trafo matrix
                              Supported values for MatrixB.TrafoType are 0,1,2.
                              Range for MatrixB.f00 is [0,..,1]
                              Range for MatrixB.f02 is [Full range of float32]
                              Range for MatrixB.f10 is [0,..,1]
                              Range for MatrixB.f12 is [Full range of float32]

  \return          the multiplication of the two input matrices

  \author          Norman Apel

  \testmethod    

  \traceability 
*****************************************************************************/
CML_t_TrafoMatrix2D CML_TrafoMatrix2DMult(CML_t_TrafoMatrix2D MatrixA,CML_t_TrafoMatrix2D MatrixB);

/*****************************************************************************
  Functionname:    CML_v_TransformPosition2D                            *//*! 

  \brief           transform coordinates using transformation matrix M

  \description     This function calculates the transform coordinates using 
                   transformation matrix M. Let the transform cordinates be 
                   calculated for x,y with the two rows of transformation matrix,
  \InOutCorrelation
                   \f[   
                   If \ Mat = \begin{bmatrix}
                   M_{00}    &   M_{01}  & M_{02}\\
                   M_{10}    &   M_{11}  & M_{12}\\
                   \end{bmatrix}\\
                   then, \ new \ cordinates \ will \ be :
                   X = ( x \times  M_{00} - y \times  M_{10} ) + M_{02}\\
                   Y = ( x \times  M_{10} + y \times  M_{00} ) + M_{12}
                   \f]  
  \attention       
                   CAUTION: p_Matrix, p_DistX and p_DistY should be valid addresses.
  \param[in]       p_Matrix :  transformation matrix
                              Range for p_Matrix.f00 is [0,..,1]
                              Range for p_Matrix.f02 is [Full range of float32]
                              Range for p_Matrix.f10 is [0,..,1]
                              Range for p_Matrix.f12 is [Full range of float32]
  \param[in,out]   p_DistX :  X-coordinate
                              [Full range of float32]
  \param[in,out]   p_DistY :  Y-coordinate
                              [Full range of float32]
                              Overflow may occur when one or more input values 
                              are at the defined range extremities.

  \return          void

  \author          Norman Apel

  \testmethod    

  \traceability    
*****************************************************************************/
extern void CML_v_TransformPosition2D(CML_t_TrafoMatrix2D const *p_Matrix , float32 *p_DistX , float32 *p_DistY);

/*****************************************************************************
  Functionname:    CML_v_RotateCoordinatesOnAPoint2D                     *//*!

  \brief           Transform coordinates using transformation matrix M.
                   Translation and rotation of axes 

  \description     This function calculates the transform coordinates using 
                   transformation matrix M. Let the transform cordinates be 
                   calculated for x,y with the two rows of transformation matrix,
  \InOutCorrelation
                   \f[   
                   If \ Mat = \begin{bmatrix}
                   M_{00}    &   M_{01}  & M_{02}\\
                   M_{10}    &   M_{11}  & M_{12}\\
                   \end{bmatrix}\\
                   then, \ new \ cordinates \ will \ be :\\
                   x1 = ( ((x + M_{02} \times  M_{00}) - (y + M_{12} \times  M_{10} )\\
                   y1 = ( ((x + M_{02} \times  M_{10}) + (y + M_{12} \times  M_{00} )
                   \f]  
  \attention       
                   CAUTION: p_Matrix, p_DistX and p_DistY should be valid addresses.

  \param[in]       p_Matrix :  transformation matrix
                              Range for p_Matrix.f00 is [0,..,1]
                              Range for p_Matrix.f02 is [Full range of float32]
                              Range for p_Matrix.f10 is [0,..,1]
                              Range for p_Matrix.f12 is [Full range of float32]
  \param[in,out]   p_DistX :  X-coordinate
                              [Full range of float32]
  \param[in,out]   p_DistY :  Y-coordinate
                              [Full range of float32]
                              Overflow may occur when one or more input values 
                              are at the defined range extremities.

  \return          void

  \author          Anu Jagannath (uid42056)

  \testmethod    

  \traceability    
*****************************************************************************/
extern void CML_v_RotateCoordinatesOnAPoint2D(CML_t_TrafoMatrix2D const *p_Matrix , float32 *p_DistX , float32 *p_DistY);

/*****************************************************************************
  Functionname:    CML_v_TransformXPosition2D                           *//*!

  \brief           transform X-coordinate using transformation matrix M

  \description     This function does the transform of X-coordinate using 
                   transformation matrix, and is calculated depending on
                   the matrix type: Translation, Rotation or Default.
                   Let the transform cordinate be calculated for x,y 
                   with the two rows of transformation matrix,
  \InOutCorrelation
                   \f[   
                   If \ Mat = \begin{bmatrix}
                   M_{00}    &   M_{01}  & M_{02}\\
                   M_{10}    &   M_{11}  & M_{12}\\
                   \end{bmatrix}\\
                   then, \ new \ cordinates \ will \ be :
                   x_1 = ( x \times  M_{00} - y \times  M_{10} ) + M_{02}
                   \f]  
  \attention       
                   CAUTION: p_Matrix, p_DistX and p_DistY should be valid addresses.

  \param[in]       p_Matrix :  transformation matrix
                              Supported values for p_Matrix.TrafoType are 0,1,2.
                              Range for p_Matrix.f00 is [0,..,1]
                              Range for p_Matrix.f02 is [Full range of float32]
                              Range for p_Matrix.f10 is [0,..,1]
                              Range for p_Matrix.f12 is [Full range of float32]
  \param[in]       f_DistX :  X-coordinate
                              [Full range of float32]
  \param[in]       f_DistY :  Y-coordinate
                              [Full range of float32]
                              Overflow may occur when one or more input values 
                              are at the defined range extremities.

  \return          transformed X-coordinate

  \author          Norman Apel

  \testmethod    

  \traceability   
*****************************************************************************/
extern float32 CML_f_TransformXPosition2D(CML_t_TrafoMatrix2D const *p_Matrix , float32 f_DistX , float32 f_DistY);

/*****************************************************************************
  Functionname:    CML_v_TransformYPosition2D                           *//*! 

  \brief           transform Y-coordinate using transformation matrix M

  \description     This function does the transform of Y-coordinate using 
                   transformation matrix, and is calculated depending on
                   the matrix type: Translation, Rotation or Default.
                   Let the transform cordinate be calculated for x,y 
                   with the two rows of transformation matrix,
  \InOutCorrelation
                   \f[   
                   If\  Mat = \begin{bmatrix}
                   M_{00}    &   M_{01}  & M_{02}\\
                   M_{10}    &   M_{11}  & M_{12}\\
                   \end{bmatrix}\\
                   then, \ new \ cordinates \ will \ be : 
                   y1 = ( x \times  M_{10} + y \times  M_{00} ) + M_{12}
                   \f]  
  \attention       
                   CAUTION: p_Matrix should be valid address.

  \param[in]       p_Matrix :  transformation matrix
                              Supported values for p_Matrix.TrafoType are 0,1,2.
                              Range for p_Matrix.f00 is [0,..,1]
                              Range for p_Matrix.f02 is [Full range of float32]
                              Range for p_Matrix.f10 is [0,..,1]
                              Range for p_Matrix.f12 is [Full range of float32]
  \param[in]       f_DistX :  X-coordinate
                              [Full range of float32]
  \param[in]       f_DistY :  Y-coordinate
                              [Full range of float32]
                              Overflow may occur when one or more input values 
                              are at the defined range extremities.

  \return          transformed Y-coordinate

  \author          Norman Apel

  \testmethod    

  \traceability   
*****************************************************************************/
extern float32 CML_f_TransformYPosition2D(CML_t_TrafoMatrix2D const *p_Matrix , float32 f_DistX , float32 f_DistY);


/*****************************************************************************
  Functionname:    CML_GetTrafoMatrixByAngle                            *//*! 

  \brief           Get rotation matrix with given rotation angle

  \description     The function prepares a rotation matrix with given 
                   rotation angle. If the rotation angle is Angle, then the 
                   rotation matrix would be as follows:
  \InOutCorrelation
                   \f[   
                   TrafoMat = \begin{bmatrix}
                   cos(\Theta ) & -sin(\Theta ) &   0\\
                   sin(\Theta ) &  cos(\Theta ) &   0\\
                     0          &   0           &   1\\
                   \end{bmatrix}\\
                   \f]
  \param[in]       f_Angle :  the rotation angle
                              [Full range of float32]
                              Overflow may occur when input values 
                              are at the defined range extremities.

  \return          rotation matrix with given rotation angle

  \author          Norman Apel

  \testmethod    

  \traceability    
*****************************************************************************/
extern CML_t_TrafoMatrix2D CML_GetTrafoMatrixByAngle(float32 f_Angle);

/*****************************************************************************
  Functionname:    CML_GetTrafoMatrixByDisplacement                     *//*! 

  \brief           Get translation matrix with given displacement

  \description     Get translation matrix with given displacement
                   The function prepares a translation matrix with given 
                   displacement. If the displacement is 
                   (X, Y), then the translation
                   matrix would be as follows:
  \InOutCorrelation
                   \f[   
                   TrafoMat = \begin{bmatrix}
                   1  &  0   &   X\\
                   0  &  1   &   Y\\
                   0  &  0   &   1\\
                   \end{bmatrix}\\
                   \f]

  \param[in]       f_XDisplacement :  X-displacement
                                      [Full range of float32]
  \param[in]       f_YDisplacement :  Y-displacement
                                      [Full range of float32]

  \return          translation matrix with given displacement

  \author          Norman Apel

  \testmethod    

  \traceability    
*****************************************************************************/
extern CML_t_TrafoMatrix2D CML_GetTrafoMatrixByDisplacement(float32 f_XDisplacement, float32 f_YDisplacement);

/*****************************************************************************
  Functionname:    CML_GetTrafoMatByDisplacementandAngle             *//*! 

  \brief           Get translation matrix with given displacement
                   and rotation angle

  \description     The function prepares a translation matrix with given 
                   displacement and rotation angle. If the displacement 
                   is (X, X) and rotation 
                   angle is f_Angle, then the translation matrix would 
                   be as follows:
  \InOutCorrelation
                   \f[   
                   TrafoMat = \begin{bmatrix}
                   cos(\Theta )   &  -sin(\Theta )   &   X\\
                   sin(\Theta )   &  cos(\Theta )    &   Y\\
                   0              &  0               &   1\\
                   \end{bmatrix}\\
                   \f]
  \param[in]       f_XDisplacement :  X-displacement
                                      [Full range of float32]
  \param[in]       f_YDisplacement :  Y-displacement
                                      [Full range of float32]
  \param[in]       f_Angle         :  the rotation angle
                                      [Full range of float32]
                                      Overflow may occur when input values 
                                      are at the defined range extremities.

  \return          Translation matrix with given displacement and angle

  \author          Anu Jagannath

  \testmethod    

  \traceability 
*****************************************************************************/
extern CML_t_TrafoMatrix2D CML_GetTrafoMatByDisplacementandAngle(float32 f_Angle, float32 f_XDisplacement, float32 f_YDisplacement);


 /*Interface functions for matrix operations*/
/*****************************************************************************
  Functionname:    CML_u_MatrixCopy                                     *//*! 

  \brief           Copy a given matrix

  \description     This function copies the contents of one matrix to another
                   if the number of elements is non-zero. The function will 
                   always return TRUE.
  \attention       
                   CAUTION: Size of the matrix (u_dim_Ax X u_dim_Ay) must be within array bounds.
                   NOTE: CML_RESTRICT does not add any new functionality, it is used for optmizations by compiler. 
                         <b> Optimizations are effective with c66xx platform with switch CML_OPT_c66x </b>, there would be no change for others.
  \param[in]       a_MatrixA :    original matrix
                                  [Full range of float32]
  \param[out]      a_MatrixCpy :  copied matrix
                                  [Full range of float32]
  \param[in]       u_dim_Ax :     x-dimension of matrix A
                                  [Full range of uint8]
  \param[in]       u_dim_Ay :     y-dimension of matrix A
                                  [Full range of uint8]

  \return          true

  \author          Robert Thiel

  \testmethod    

  \traceability 
*****************************************************************************/
extern uint8 CML_u_MatrixCopy(float32 const a_MatrixA[CML_RESTRICT], float32 a_MatrixCpy[CML_RESTRICT], uint8 u_dim_Ax, uint8 u_dim_Ay);

/*****************************************************************************
  Functionname:    CML_u_MatrixTranspose                                *//*! 
  
  \brief           transposition of a matrix
  
  \description     This function does the transpose of matrix.
                   For Square matrices, the pointers for the original matrix
                   and the transpose matrix can be same or different.
                   example:
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
                   CAUTION: Size of the matrix (u_dim_Ax X u_dim_Ay) must be within array bounds.
                   NOTE: CML_RESTRICT does not add any new functionality, it is used for optmizations by compiler. 
                         <b> Optimizations are effective with c66xx platform with switch CML_OPT_c66x </b>, there would be no change for others.
  \param[in]       a_MatrixA :     original matrix
                                   [Full range of float32]
  \param[out]      a_ATranspose :  transposed matrix (with dimension dim_Ay * dim_Ax)
                                   [Full range of float32]
  \param[in]       u_dim_Ax :      x-dimension of matrix A
                                   [Full range of uint8]
  \param[in]       u_dim_Ay :      y-dimension of matrix A
                                   [Full range of uint8]
  
  \return          true if operation was successful
  
  \author          Robert Thiel

  \testmethod    

  \traceability   
*****************************************************************************/
extern uint8 CML_u_MatrixTranspose(float32 const a_MatrixA[CML_RESTRICT], float32 a_ATranspose[CML_RESTRICT], uint8 u_dim_Ax, uint8 u_dim_Ay);

/*****************************************************************************
  Functionname:    CML_u_MatrixMultiplication                           *//*! 

  \brief           multiplies two matrices A and B

  \description     This function multiplies two matrices A and B (AxB)
                   NOTE: The function expects the following matrix dimensions:
                   number of rows and number of columns of the first matrix A,
                   and just number of columns of second matrix B. 
                   The function assumes the prerequisite for matrix multiplication,
                   i.e. no. of columns of A = no. of rows of B, is satisfied.
                   \f[ [Res]_{m\times p} = [A]_{m\times n} \times [B]_{n\times p} \f]
  \InOutCorrelation
                   \f[ 
                   \begin{bmatrix}
                   A_{00}    &   A_{01}  & A_{02}\\
                   A_{10}    &   A_{11}  & A_{12}
                   \end{bmatrix}
                   X
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
                   CAUTION: Size of the matrix (u_dim_Ax X u_dim_Ay) must be within array bounds.
                   NOTE: CML_RESTRICT does not add any new functionality, it is used for optmizations by compiler. 
                         <b> Optimizations are effective with c66xx platform with switch CML_OPT_c66x </b>, there would be no change for others.
  \param[in]     a_MatrixA :  first matrix
                              [Full range of float32]
                              Overflow may occur when input values 
                              are at the defined range extremities.
  \param[in]     a_MatrixB :  second matrix
                              [Full range of float32]
                              Overflow may occur when input values 
                              are at the defined range extremities.
  \param[in]     u_dim_Ax :   x-dimension of A
                              [Full range of uint8]
  \param[in]     u_dim_Ay :   y-dimension of A
                              [Full range of uint8]
  \param[in]     u_dim_Bx :   x-dimension of B
                              [Full range of uint8]
  \param[out]    a_AxB :      product A*B
                              [Full range of float32]

  \return        true if operation was successful

  \author        Robert Thiel

  \testmethod    

  \traceability    
*****************************************************************************/
extern uint8 CML_u_MatrixMultiplication(float32 const a_MatrixA[CML_RESTRICT], float32 const a_MatrixB[CML_RESTRICT], float32 a_AxB[CML_RESTRICT], uint8 u_dim_Ax, uint8 u_dim_Ay, uint8 u_dim_Bx);

/*****************************************************************************
  Functionname:    CML_u_MatrixInversion                                *//*! 

  \brief           calculates the inverse of a square matrix using Gauss-Jordan algorithm

  \description     This function calculates the inverse of a square matrix using 
                   Gauss-Jordan algorithm. The algorithm is as follows:
                   If the square matrix to be inverted is A, and I is the 
                   Identity matrix of the same order as A, then first I is 
                   appended to A -> |A|I|. If possible to transform this matrix by
                   using Elementary Row Operations to |I|B|, then B is the 
                   inverse of A. 
                   example: 
  \InOutCorrelation
                  \f[A = 
                   \begin{bmatrix}
                   A_{00}    &   A_{01}\\
                   A_{10}    &   A_{11}
                   \end{bmatrix}
                   \  and \ I = 
                   \begin{bmatrix}
                   1     &   0\\
                   0     &   1
                   \end{bmatrix}\\
                   [A][I] =  
                   \begin{bmatrix}
                   A_{00}    &   A_{01}\\
                   A_{10}    &   A_{11}
                   \end{bmatrix}
                   \begin{bmatrix}
                   1     &   0\\
                   0     &   1
                   \end{bmatrix}
                   \ --{Elementary Row Operations}->
                   \begin{bmatrix}
                   1     &   0\\
                   0     &   1
                   \end{bmatrix}
                   \begin{bmatrix}
                   B_{00}    &   B_{01}\\
                   B_{10}    &   B_{11}
                   \end{bmatrix}
                   \  = \ [I][B] \\
                   Now, \ B \ is \ the \ inverse \ of \ A.
                   \f]
  \param[in]       a_MatrixA :  original matrix (dim_xy*dim_xy)
                                [Full range of float32]
                                Overflow may occur when input values 
                                are at the defined range extremities.
  \param[in]       a_tempMatrix :  temporary matrix (dim_xy*dim_xy)
                                   [Full range of float32]
  \param[out]      a_InverseA :  inverse of A (dim_xy*dim_xy)
                                 [Full range of float32]
  \param[in]       u_dim_xy :  x- and y-dimension of A
                               [Full range of uint8]

  \return          true if operation was successful

  \author          Robert Thiel

  \testmethod    

  \traceability 
*****************************************************************************/
extern uint8 CML_u_MatrixInversion(float32 const a_MatrixA[], float32 a_tempMatrix[], float32 a_InverseA[], uint8 u_dim_xy);

/*****************************************************************************
  Functionname:    CML_u_MatrixAddition                                 *//*! 

  \brief           addition of two matrices A and B

  \description     This function performs addition of two matrices A and B.
                   The function assumes both matrices are of same order and 
                   hence accepts only one set of dimension.
                   \f[[Res] = [A] - [B]\f]
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
                   CAUTION: Size of the matrix (u_dim_Ax X u_dim_Ay) must be within array bounds.
                   NOTE: CML_RESTRICT does not add any new functionality, it is used for optmizations by compiler. 
                         <b> Optimizations are effective with c66xx platform with switch CML_OPT_c66x </b>, there would be no change for others.\param[in]       a_MatrixA :  first matrix (dim_x*dim_y)
                                [Full range of float32]
                                Overflow may occur when input values 
                                are at the defined range extremities.
  \param[in]       a_MatrixB :  second matrix (dim_x*dim_y)
                                [Full range of float32]
                                Overflow may occur when input values 
                                are at the defined range extremities.
  \param[out]      a_AplusB :   the sum A+B
                                [Full range of float32]
  \param[in]       u_dim_x :    x-dimension of A and B
                                [Full range of uint8]
  \param[in]       u_dim_y :    y-dimension of A and B
                                [Full range of uint8]

  \return          true

  \author          Robert Thiel

  \testmethod    

  \traceability    
*****************************************************************************/
extern uint8 CML_u_MatrixAddition(float32 const a_MatrixA[CML_RESTRICT], float32 const a_MatrixB[CML_RESTRICT], float32 a_AplusB[CML_RESTRICT], uint8 u_dim_x, uint8 u_dim_y);

/*****************************************************************************
  Functionname:    CML_u_MatrixSubtraction                              *//*! 

  \brief           subtraction of two matrices A and B

  \description     This function performs subtraction of two matrices A and B.
                   The function assumes both matrices are of same order and 
                   hence accepts only one set of dimension.
                   \f[[Res] = [A] - [B]\f]
  \InOutCorrelation
                   \f[
                   \begin{bmatrix}
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
                   CAUTION: Size of the matrix (u_dim_Ax X u_dim_Ay) must be within array bounds.
                   NOTE: CML_RESTRICT does not add any new functionality, it is used for optmizations by compiler. 
                         <b> Optimizations are effective with c66xx platform with switch CML_OPT_c66x </b>, there would be no change for others.
  \param[in]       a_MatrixA :  first matrix (dim_x*dim_y)
                                [Full range of float32]
                                Overflow may occur when input values 
                                are at the defined range extremities.
  \param[in]       a_MatrixB :  second matrix (dim_x*dim_y)
                                [Full range of float32]
                                Overflow may occur when input values 
                                are at the defined range extremities.
  \param[out]      a_AminusB :  the difference A-B
                                [Full range of float32]
  \param[in]       u_dim_x :    x-dimension of A and B
                                [Full range of uint8]
  \param[in]       u_dim_y :    y-dimension of A and B
                                [Full range of uint8]

  \return          true

  \author          Robert Thiel

  \testmethod    

  \traceability   
*****************************************************************************/
extern uint8 CML_u_MatrixSubtraction(float32 const a_MatrixA[CML_RESTRICT], float32 const a_MatrixB[CML_RESTRICT], float32 a_AminusB[CML_RESTRICT], uint8 u_dim_x, uint8 u_dim_y);


#endif /* #ifndef CML_MAT_INCLUDED */


/** @} end defgroup */
