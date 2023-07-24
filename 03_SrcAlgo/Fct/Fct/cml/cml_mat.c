/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_mat.c

  DESCRIPTION:               matrix computation toolbox

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             03.02.2010

  VERSION:                   $Revision: 1.23 $

  ---*/ /*---
  CHANGES:                   $Log: cml_mat.c  $
  CHANGES:                   Revision 1.23 2020/01/08 11:31:20CET Thomas, Jyothy (uid22555) 
  CHANGES:                   corrected alignment
  CHANGES:                   Revision 1.22 2019/11/21 11:31:21CET Reddy, Purushothama (uid33569) 
  CHANGES:                   QAC warning fixed.
  CHANGES:                   Revision 1.21 2019/11/18 09:55:26CET Thomas, Jyothy (uid22555) 
  CHANGES:                   Chechking in CML_f_TransformYPosition2D to get ECU-SIL bit exactness on A15
  CHANGES:                   Revision 1.20 2019/10/11 11:56:27CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   re-written code for CML_v_TransformPosition2D, CML_f_TransformXPosition2D , CML_u_MatrixMultiplication
  CHANGES:                   and CML_u_MatrixInversion for ECu-SIl bit exactness for A15
  CHANGES:                   Revision 1.19 2019/06/21 15:15:02CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   QAF Level3 fixes for MFC431TA19
  CHANGES:                   Revision 1.18 2018/02/26 08:51:29CET Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated the source code with respect to AL_CML_01.09.18_INT-1
  CHANGES:                   Revision 1.17 2017/11/09 11:36:19CET Mutschler, Matthias (uidv7867) 
  CHANGES:                   Replaced FALSE/TRUE by b_FALSE/b_TRUE
  CHANGES:                   Revision 1.16 2017/08/04 06:04:14CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Aligned and merged changes from AL_CML_01.09.11_INT-1
  CHANGES:                   Revision 1.15 2016/05/11 06:24:48CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Updated function header with argument range
  CHANGES:                   Revision 1.14 2015/08/25 06:29:16CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated doxygen compliant function headers
  CHANGES:                   - Added comments -  uidr5428 [Aug 25, 2015 6:29:17 AM CEST]
  CHANGES:                   Change Package : 360603:2 http://mks-psad:7002/im/viewissue?selection=360603
  CHANGES:                   Revision 1.13 2015/07/07 08:21:36CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Repeat changes from 317004:1 and 317006:1
  CHANGES:                     (lost in intermediate check-in)
  CHANGES:                   --- Added comments ---  uidr5428 [Jul 7, 2015 8:21:37 AM CEST]
  CHANGES:                   Change Package : 354072:2 http://mks-psad:7002/im/viewissue?selection=354072
  CHANGES:                   Revision 1.12 2015/04/29 15:03:25CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Changes with respect to Coding Guidelines
  CHANGES:                     of variables
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 29, 2015 3:03:25 PM CEST]
  CHANGES:                   Change Package : 324617:2 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.11 2015/04/28 17:47:20CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Removed the if condition in function CML_u_MatrixInversion
  CHANGES:                   which was not necessary.
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 28, 2015 5:47:21 PM CEST]
  CHANGES:                   Change Package : 317006:1 http://mks-psad:7002/im/viewissue?selection=317006
  CHANGES:                   Revision 1.10 2015/04/23 16:42:05CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Removed an additional if condition in function CML_u_MatrixInversion
  CHANGES:                     which would otherwise be true everytime.
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 23, 2015 4:42:05 PM CEST]
  CHANGES:                   Change Package : 317004:1 http://mks-psad:7002/im/viewissue?selection=317004
  CHANGES:                   Revision 1.9 2015/04/22 18:05:03CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Edited the docu header of the function CML_u_MatrixMultiplication
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 22, 2015 6:05:03 PM CEST]
  CHANGES:                   Change Package : 316991:1 http://mks-psad:7002/im/viewissue?selection=316991
  CHANGES:                   Revision 1.8 2015/04/22 13:20:11CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Corrected the nested loop test values in CML_u_MatrixTranspose
  CHANGES:                     to get the matrix transpose in case of non-square matrix
  CHANGES:                   --- Added comments ---  uidr5428 [Apr 22, 2015 1:20:11 PM CEST]
  CHANGES:                   Change Package : 316977:1 http://mks-psad:7002/im/viewissue?selection=316977
  CHANGES:                   Revision 1.7 2014/12/04 16:00:06CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - changed input data of several functions from pointer to array as they are accessed this way
  CHANGES:                   - reduced McCabe metric and nesting depth of CML_u_MatrixInversion()
  CHANGES:                   --- Added comments ---  uidg6516 [Dec 4, 2014 4:00:06 PM CET]
  CHANGES:                   Change Package : 266613:11 http://mks-psad:7002/im/viewissue?selection=266613
  CHANGES:                   Revision 1.6 2014/03/27 11:20:46CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed some QA-C- and Styleguide-issues
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 27, 2014 11:20:47 AM CET]
  CHANGES:                   Change Package : 227281:2 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.5 2014/03/25 11:32:54CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed Doxygen comments
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 25, 2014 11:32:54 AM CET]
  CHANGES:                   Change Package : 227281:1 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.4 2013/05/03 09:57:10CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   - use new standard type names, e.g. float32 instead of f32_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:57:10 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.3 2012/09/20 13:29:42CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:42 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2012/09/18 15:55:40CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   fixed visual warnings
  CHANGES:                   --- Added comments ---  eisenacherm [Sep 18, 2012 3:55:40 PM CEST]
  CHANGES:                   Change Package : 158245:1 http://mks-psad:7002/im/viewissue?selection=158245
  CHANGES:                   Revision 1.1 2012/09/14 14:31:14CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/* PRQA S 0380 10 */
/* Deactivate QAF warning 0380, Date: 2019-06-17; Reviewer: uid22555;  
   Reason: The warning is seen as number of macros exceeds 4095 which can not be avoided here. 
   Warning is analysed and no risk in suppressing this. */
/*****************************************************************************
INCLUDES
*****************************************************************************/
#include "cml_ext.h"

/*****************************************************************************
FUNCTIONS
*****************************************************************************/

/*****************************************************************************
  Functionname:    CML_TrafoMatrix2DInvert                              */ /*!

  @brief           Inversion of a transformation matrix A

  @description     This function calculates the inverse of a transformation
                   matrix. If 'A' is a transformation matrix, then the inverse 
                   'A^(-1)' can be calculated as follows:

                   A = [  cos(A), -sin(A), DX]
                       [  sin(A),  cos(A), DY]
                       [       0,      0 ,  1]
                   A^(-1) = [  cos(A),  sin(A), - DX*cos(A) - DY*sin(A)]
                            [ -sin(A),  cos(A),   DX*sin(A) - DY*cos(A)]
                            [       0,      0 ,                       1]

  @param[in]       MatrixA :  trafo matrix
                              Range for MatrixA.f00 is [0,..,1]
                              Range for MatrixA.f02 is [Full range of float32]
                              Range for MatrixA.f10 is [0,..,1]
                              Range for MatrixA.f12 is [Full range of float32]

  @return          the inverted matrix A^(-1)

  @author          Norman Apel

*****************************************************************************/
CML_t_TrafoMatrix2D CML_TrafoMatrix2DInvert(CML_t_TrafoMatrix2D MatrixA)
{
  CML_t_TrafoMatrix2D Mat;

  Mat.TrafoType = DEFAULT_;
  Mat.f00 = MatrixA.f00;      
  Mat.f02 = (-MatrixA.f02*MatrixA.f00) - (MatrixA.f12*MatrixA.f10);
  Mat.f10 = -MatrixA.f10;
  Mat.f12 =  (MatrixA.f02*MatrixA.f10) - (MatrixA.f12*MatrixA.f00);

  return Mat;
}

/*****************************************************************************
  Functionname:    CML_TrafoMatrix2DMult                                */ /*!

  @brief           Multiplication of two transformation matrices

  @description     This function does the multiplication of two transformation
                   matrices.
                   Multiplication is performed after checking the matrix type 
                   for each matrix, whether translation, rotation or default.
                   Matrix multiplication optimized under the fact, that all 
                   2D Transformation matrizes are of the form

                   TRANSLATION |  1     0   DX|
                               |  0     1   DY|
                               |  0     0    1|
                   
                   ROTATION    |COS  -SIN    0|
                               |SIN   COS    0|
                               |  0     0    1|
                   
                   DEFAULT     |COS  -SIN   DX|
                               |SIN   COS   DY|
                               |  0     0    1|
                   
  @param[in]       MatrixA :  first trafo matrix
                              Supported values for MatrixA.TrafoType are 0,1,2.
                              Range for MatrixA.f00 is [0,..,1]
                              Range for MatrixA.f02 is [Full range of float32]
                              Range for MatrixA.f10 is [0,..,1]
                              Range for MatrixA.f12 is [Full range of float32]

  @param[in]       MatrixB :  second trafo matrix
                              Supported values for MatrixB.TrafoType are 0,1,2.
                              Range for MatrixB.f00 is [0,..,1]
                              Range for MatrixB.f02 is [Full range of float32]
                              Range for MatrixB.f10 is [0,..,1]
                              Range for MatrixB.f12 is [Full range of float32]

  @return          the multiplication of the two input matrices

  @author          Norman Apel

*****************************************************************************/
CML_t_TrafoMatrix2D CML_TrafoMatrix2DMult(CML_t_TrafoMatrix2D MatrixA,CML_t_TrafoMatrix2D MatrixB)
{
  CML_t_TrafoMatrix2D Mat;
  float32 f_temp1, f_temp2, f_temp3;

  /*
  Matrix multiplication optimized under the fact, that all 2D Transformation 
  matrizes are of the form

  TRANSLATION |  1     0   DX|
  |  0     1   DY|
  |  0     0    1|

  ROTATION    |COS  -SIN    0|
  |SIN   COS    0|
  |  0     0    1|

  DEFAULT     |COS  -SIN   DX|
  |SIN   COS   DY|
  |  0     0    1|
  */
  if(MatrixA.TrafoType == TRANSLATION_)
  {
    if(MatrixB.TrafoType == TRANSLATION_)
    {
      Mat.TrafoType = MatrixA.TrafoType;
      Mat.f00 = 1.0f;      
      Mat.f02 = MatrixA.f02 + MatrixB.f02;
      Mat.f10 = 0.0f;
      Mat.f12 = MatrixA.f12 + MatrixB.f12;
    }
    else if(MatrixB.TrafoType == ROTATION_)
    {
      Mat.TrafoType = DEFAULT_;
      Mat.f00 = MatrixB.f00;
      Mat.f02 = MatrixA.f02;
      Mat.f10 = MatrixB.f10;
      Mat.f12 = MatrixA.f12;
    }
    else
    {
      Mat.TrafoType = DEFAULT_;
      Mat.f00 = MatrixB.f00;
      Mat.f02 = MatrixA.f02 + MatrixB.f02;
      Mat.f10 = MatrixB.f10;
      Mat.f12 = MatrixA.f12 + MatrixB.f12;
    }
  }
  else if(MatrixA.TrafoType == ROTATION_)
  {
    if(MatrixB.TrafoType == TRANSLATION_)
    {
      Mat.TrafoType = DEFAULT_;
      Mat.f00 = MatrixA.f00;
      //Mat.f02 = (MatrixA.f00*MatrixB.f02) - (MatrixA.f10*MatrixB.f12);
      f_temp1 = MatrixA.f00*MatrixB.f02;
      f_temp2 = MatrixA.f10*MatrixB.f12;
      Mat.f02 = f_temp1 - f_temp2;
      Mat.f10 = MatrixA.f10;
      //Mat.f12 = (MatrixA.f10*MatrixB.f02) + (MatrixA.f00*MatrixB.f12);
      f_temp1 = MatrixA.f10*MatrixB.f02;
      f_temp2 = MatrixA.f00*MatrixB.f12;
      Mat.f12 = f_temp1 + f_temp2;
    }
    else if(MatrixB.TrafoType == ROTATION_)
    {
      Mat.TrafoType = ROTATION_;
      //Mat.f00 = (MatrixA.f00*MatrixB.f00) - (MatrixA.f10*MatrixB.f10);
      f_temp1 = MatrixA.f00*MatrixB.f00;
      f_temp2 = MatrixA.f10*MatrixB.f10;
      Mat.f00 = f_temp1 - f_temp2;
      Mat.f02 = 0.0f;
      //Mat.f10 = (MatrixA.f00*MatrixB.f10) + (MatrixA.f10*MatrixB.f00);
      f_temp1 = MatrixA.f00*MatrixB.f10;
      f_temp2 = MatrixA.f10*MatrixB.f00;
      Mat.f10 = f_temp1 + f_temp2;
      Mat.f12 = 0.0f;
    }
    else
    {
      Mat.TrafoType = DEFAULT_;
      //Mat.f00 = (MatrixA.f00*MatrixB.f00) - (MatrixA.f10*MatrixB.f10);
      f_temp1 = MatrixA.f00*MatrixB.f00;
      f_temp2 = MatrixA.f10*MatrixB.f10;
      Mat.f00 = f_temp1 - f_temp2;

      //Mat.f02 = (MatrixA.f00*MatrixB.f02) - (MatrixA.f10*MatrixB.f12);
      f_temp1 = MatrixA.f00*MatrixB.f02;
      f_temp2 = MatrixA.f10*MatrixB.f12;
      Mat.f02 = f_temp1 - f_temp2;

      //Mat.f10 = (MatrixA.f00*MatrixB.f10) + (MatrixA.f10*MatrixB.f00);
      f_temp1 = MatrixA.f00*MatrixB.f10;
      f_temp2 = MatrixA.f10*MatrixB.f00;
      Mat.f10 = f_temp1 + f_temp2;

      //Mat.f12 = (MatrixA.f10*MatrixB.f02) + (MatrixA.f00*MatrixB.f12);
      f_temp1 = MatrixA.f10*MatrixB.f02;
      f_temp2 = MatrixA.f00*MatrixB.f12;
      Mat.f12 = f_temp1 + f_temp2;
    }
  }
  else
  {
    if(MatrixB.TrafoType == TRANSLATION_)
    {
      Mat.TrafoType = DEFAULT_;
      Mat.f00 = MatrixA.f00;
      //Mat.f02 = ((MatrixA.f00*MatrixB.f02) - (MatrixA.f10*MatrixB.f12)) + MatrixA.f02;
      f_temp1 = MatrixA.f00*MatrixB.f02;
      f_temp2 = MatrixA.f10*MatrixB.f12;
      f_temp3 = f_temp1 - f_temp2;
      Mat.f02 = f_temp3 + MatrixA.f02;
      Mat.f10 = MatrixA.f10;
      //Mat.f12 = ((MatrixA.f10*MatrixB.f02) + (MatrixA.f00*MatrixB.f12)) + MatrixA.f12;
      f_temp1 = MatrixA.f10*MatrixB.f02;
      f_temp2 = MatrixA.f00*MatrixB.f12;
      f_temp3 = f_temp1 + f_temp2;
      Mat.f12 = f_temp3 + MatrixA.f12;
    }
    else if(MatrixB.TrafoType == ROTATION_)
    {
      Mat.TrafoType = DEFAULT_;
      //Mat.f00 = (MatrixA.f00*MatrixB.f00) - (MatrixA.f10*MatrixB.f10);
      f_temp1 = MatrixA.f00*MatrixB.f00; 
      f_temp2 = MatrixA.f10*MatrixB.f10;
      Mat.f00 = f_temp1 - f_temp2;
      Mat.f02 = MatrixA.f02;
      //Mat.f10 = (MatrixA.f00*MatrixB.f10) + (MatrixA.f10*MatrixB.f00);
      f_temp1 = MatrixA.f00*MatrixB.f10;
      f_temp2 = MatrixA.f10*MatrixB.f00;
      Mat.f10 = f_temp1 + f_temp2;

      Mat.f12 = MatrixA.f12;
    }
    else
    {
      Mat.TrafoType = DEFAULT_;
      //Mat.f00 = (MatrixA.f00*MatrixB.f00) - (MatrixA.f10*MatrixB.f10);
      f_temp1 = MatrixA.f00*MatrixB.f00;
      f_temp2 = MatrixA.f10*MatrixB.f10;
      Mat.f00 = f_temp1 - f_temp2;

      //Mat.f02 = ( (MatrixA.f00*MatrixB.f02) - (MatrixA.f10*MatrixB.f12) ) + MatrixA.f02;
      f_temp1 = MatrixA.f00*MatrixB.f02;
      f_temp2 = MatrixA.f10*MatrixB.f12;
      f_temp3 = f_temp1 - f_temp2;
      Mat.f02 = f_temp3 + MatrixA.f02;

      //Mat.f10 = (MatrixA.f00*MatrixB.f10) + (MatrixA.f10*MatrixB.f00);
      f_temp1 = MatrixA.f00*MatrixB.f10;
      f_temp2 = MatrixA.f10*MatrixB.f00;
      Mat.f10 = f_temp1 + f_temp2;

      //Mat.f12 = ((MatrixA.f10*MatrixB.f02) + (MatrixA.f00*MatrixB.f12)) + MatrixA.f12;      
      f_temp1 = MatrixA.f10*MatrixB.f02;
      f_temp2 = MatrixA.f00*MatrixB.f12;
      f_temp3 = f_temp1 + f_temp2;
      Mat.f12 = f_temp3 + MatrixA.f12;
    }
  }
  return Mat;
}

/*****************************************************************************
  Functionname:    CML_v_TransformPosition2D                            */ /*!

  @brief           transform coordinates using transformation matrix M

  @description     This function calculates the transform coordinates using 
                   transformation matrix M. Let the transform cordinates be 
                   calculated for x,y with the two rows of transformation matrix,
                   M = |f00  f01 f02|
                       |f10  f11 f12|,
                   then new cordinates will be
                   x1 = ( x * f00 - y * f10 ) + f02
                   y1 = ( x * f10 + y * f00 ) + f12

  @param[in]       p_Matrix :  transformation matrix
                              Range for p_Matrix.f00 is [0,..,1]
                              Range for p_Matrix.f02 is [Full range of float32]
                              Range for p_Matrix.f10 is [0,..,1]
                              Range for p_Matrix.f12 is [Full range of float32]
  @param[in,out]   p_DistX :  X-coordinate
                              [Full range of float32]
  @param[in,out]   p_DistY :  Y-coordinate
                              [Full range of float32]
                              Overflow may occur when one or more input values 
                              are at the defined range extremities.

  @return          void

  @author          Norman Apel

*****************************************************************************/
void CML_v_TransformPosition2D(CML_t_TrafoMatrix2D const *p_Matrix , float32 *p_DistX , float32 *p_DistY)   
{
  float32 f_DistanceY = *p_DistY;

/* This code is re-written for ECU-SIL bit exactness */
   float32 ftemp1 = *p_DistX * p_Matrix->f10;
   float32 ftemp2 = f_DistanceY * p_Matrix->f00;
   float32 ftemp3 = ftemp1 + ftemp2;
   float32 ftemp4 = ftemp3 + p_Matrix->f12;
   *p_DistY = ftemp4;

   ftemp1 = *p_DistX * p_Matrix->f00;
   ftemp2 = f_DistanceY * p_Matrix->f10;
   ftemp3 = ftemp1 - ftemp2;
   ftemp4 = ftemp3 + p_Matrix->f02 ;
   *p_DistX = ftemp4;


}

/*****************************************************************************
  Functionname:    CML_v_RotateCoordinatesOnAPoint2D                            */ /*!

  @brief           Transform coordinates using transformation matrix M.
                   Translation and rotation of axes 

  @description     This function calculates the transform coordinates using 
                   transformation matrix M. Let the transform cordinates be 
                   calculated for x,y with the two rows of transformation matrix,
                   M = |f00  f01 f02|
                       |f10  f11 f12|,
                   then new cordinates will be
                   x1 = ( ((x + f02) * f00) - (y + f12) * f10 )
                   y1 = ( ((x + f02) * f10) + (y + f12) * f00 )

  @param[in]       p_Matrix :  transformation matrix
                              Range for p_Matrix.f00 is [0,..,1]
                              Range for p_Matrix.f02 is [Full range of float32]
                              Range for p_Matrix.f10 is [0,..,1]
                              Range for p_Matrix.f12 is [Full range of float32]
  @param[in,out]   p_DistX :  X-coordinate
                              [Full range of float32]
  @param[in,out]   p_DistY :  Y-coordinate
                              [Full range of float32]
                              Overflow may occur when one or more input values 
                              are at the defined range extremities.

  @return          void

  @author          Anu Jagannath (uid42056)

*****************************************************************************/
void CML_v_RotateCoordinatesOnAPoint2D(CML_t_TrafoMatrix2D const *p_Matrix , float32 *p_DistX , float32 *p_DistY)   
{
  float32 f_DistanceY, f_DistanceX;

  /* Translation */
  f_DistanceY = *p_DistY + p_Matrix->f12; 
  f_DistanceX = *p_DistX + p_Matrix->f02;

  /* Rotation */
  *p_DistY = (f_DistanceX * p_Matrix->f10) + (f_DistanceY * p_Matrix->f00);
  *p_DistX = (f_DistanceX * p_Matrix->f00) - (f_DistanceY * p_Matrix->f10);
}

/*****************************************************************************
  Functionname:    CML_v_TransformXPosition2D                           */ /*!

  @brief           transform X-coordinate using transformation matrix M

  @description     This function does the transform of X-coordinate using 
                   transformation matrix, and is calculated depending on
                   the matrix type: Translation, Rotation or Default.
                   Let the transform cordinate be calculated for x,y 
                   with the two rows of transformation matrix,
                   M = |f00  f01 f02|
                       |f10  f11 f12|,
                   then new cordinate will be
                   x1 = ( x * f00 - y * f10 ) + f02

  @param[in]       p_Matrix :  transformation matrix
                              Supported values for p_Matrix.TrafoType are 0,1,2.
                              Range for p_Matrix.f00 is [0,..,1]
                              Range for p_Matrix.f02 is [Full range of float32]
                              Range for p_Matrix.f10 is [0,..,1]
                              Range for p_Matrix.f12 is [Full range of float32]
  @param[in]       f_DistX :  X-coordinate
                              [Full range of float32]
  @param[in]       f_DistY :  Y-coordinate
                              [Full range of float32]
                              Overflow may occur when one or more input values 
                              are at the defined range extremities.

  @return          transformed X-coordinate

  @author          Norman Apel

*****************************************************************************/
float32 CML_f_TransformXPosition2D(CML_t_TrafoMatrix2D const *p_Matrix , float32 f_DistX , float32 f_DistY)   
{
/* This code is re-written for ECU-SIL bit exactness */

  float32 f_ret;
  float32 f_temp1, f_temp2, f_temp3;

  if(p_Matrix->TrafoType == TRANSLATION_)
  {
    f_ret = f_DistX + p_Matrix->f02;    
  }
  else if(p_Matrix->TrafoType == ROTATION_)
  {
      f_temp1 = f_DistX * p_Matrix->f00;
      f_temp2 = f_DistY * p_Matrix->f10;
      f_ret = f_temp1 - f_temp2;   
  }
  else
  {
      f_temp1 = f_DistX * p_Matrix->f00;
      f_temp2 = f_DistY * p_Matrix->f10;
      f_temp3 = f_temp1 - f_temp2;
      f_ret = f_temp3 + p_Matrix->f02;
  }
  return f_ret;

}

/*****************************************************************************
  Functionname:    CML_v_TransformYPosition2D                           */ /*!

  @brief           transform Y-coordinate using transformation matrix M

  @description     This function does the transform of Y-coordinate using 
                   transformation matrix, and is calculated depending on
                   the matrix type: Translation, Rotation or Default.
                   Let the transform cordinate be calculated for x,y 
                   with the two rows of transformation matrix,
                   M = |f00  f01 f02|
                       |f10  f11 f12|,
                   then new cordinate will be
                   y1 = ( x * f10 + y * f00 ) + f12

  @param[in]       p_Matrix :  transformation matrix
                              Supported values for p_Matrix.TrafoType are 0,1,2.
                              Range for p_Matrix.f00 is [0,..,1]
                              Range for p_Matrix.f02 is [Full range of float32]
                              Range for p_Matrix.f10 is [0,..,1]
                              Range for p_Matrix.f12 is [Full range of float32]
  @param[in]       f_DistX :  X-coordinate
                              [Full range of float32]
  @param[in]       f_DistY :  Y-coordinate
                              [Full range of float32]
                              Overflow may occur when one or more input values 
                              are at the defined range extremities.

  @return          transformed Y-coordinate

  @author          Norman Apel

*****************************************************************************/
float32 CML_f_TransformYPosition2D(CML_t_TrafoMatrix2D const *p_Matrix , float32 f_DistX , float32 f_DistY)   
{
  float32 f_ret;
  float32 f_temp1, f_temp2, f_temp3; 

  if(p_Matrix->TrafoType == TRANSLATION_)
  {    
    f_ret = f_DistY + p_Matrix->f12;     
  }
  else if(p_Matrix->TrafoType == ROTATION_)
  { 
    f_temp1 = f_DistX * p_Matrix->f10;
    f_temp2 = f_DistY * p_Matrix->f00;
    f_ret = f_temp1 + f_temp2;    
  }
  else
  {    
      f_temp1 = f_DistX * p_Matrix->f10;
      f_temp2 = f_DistY * p_Matrix->f00;
      f_temp3 = f_temp1 + f_temp2;
      f_ret = f_temp3 + p_Matrix->f12;
  }
  return f_ret;
}


/*****************************************************************************
  Functionname:    CML_GetTrafoMatrixByAngle                            */ /*!

  @brief           Get rotation matrix with given rotation angle

  @description     The function prepares a rotation matrix with given 
                   rotation angle. If the rotation angle is f_Angle, then the 
                   rotation matrix would be as follows:
                   |cos(f_Angle)  -sin(f_Angle)    0|
                   |sin(f_Angle)   cos(f_Angle)    0|
                   |  0             0              1|
                

  @param[in]       f_Angle :  the rotation angle
                              [Full range of float32]
                              Overflow may occur when input values 
                              are at the defined range extremities.

  @return          rotation matrix with given rotation angle

  @author          Norman Apel

*****************************************************************************/
CML_t_TrafoMatrix2D CML_GetTrafoMatrixByAngle(float32 f_Angle)
{
  CML_t_TrafoMatrix2D TrafoMat;

  TrafoMat.TrafoType = ROTATION_;
  CML_f_sincos( f_Angle , &TrafoMat.f10 , &TrafoMat.f00 ); 
  TrafoMat.f02 = 0.0f;   
  TrafoMat.f12 = 0.0f;
  return TrafoMat;
}

/*****************************************************************************
  Functionname:    CML_GetTrafoMatrixByDisplacement                     */ /*!

  @brief           Get translation matrix with given displacement

  @description     Get translation matrix with given displacement
                   The function prepares a translation matrix with given 
                   displacement. If the displacement is 
                   (f_XDisplacement, f_YDisplacement), then the translation
                   matrix would be as follows:
                   |1    0    f_XDisplacement|
                   |0    1    f_YDisplacement|
                   |0    0           1       |

  @param[in]       f_XDisplacement :  X-displacement
                                      [Full range of float32]
  @param[in]       f_YDisplacement :  Y-displacement
                                      [Full range of float32]

  @return          translation matrix with given displacement

  @author          Norman Apel

*****************************************************************************/
CML_t_TrafoMatrix2D CML_GetTrafoMatrixByDisplacement(float32 f_XDisplacement, float32 f_YDisplacement)
{
  CML_t_TrafoMatrix2D TrafoMat;

  TrafoMat.TrafoType = TRANSLATION_;
  TrafoMat.f00 = 1.0f;
  TrafoMat.f10 = 0.0f; 
  TrafoMat.f02 = f_XDisplacement;
  TrafoMat.f12 = f_YDisplacement;  
  return TrafoMat;
}

/*****************************************************************************
  Functionname:    CML_GetTrafoMatByDisplacementandAngle             */ /*!

  @brief           Get translation matrix with given displacement
                   and rotation angle

  @description     The function prepares a translation matrix with given 
                   displacement and rotation angle. If the displacement 
                   is (f_XDisplacement, f_YDisplacement) and rotation 
                   angle is f_Angle, then the translation matrix would 
                   be as follows:
                   |cos(f_Angle)  -sin(f_Angle)    f_XDisplacement|
                   |sin(f_Angle)   cos(f_Angle)    f_YDisplacement|
                   |     0              0                 1       |

  @param[in]       f_XDisplacement :  X-displacement
                                      [Full range of float32]
  @param[in]       f_YDisplacement :  Y-displacement
                                      [Full range of float32]
  @param[in]       f_Angle         :  the rotation angle
                                      [Full range of float32]
                                      Overflow may occur when input values 
                                      are at the defined range extremities.

  @return          Translation matrix with given displacement and angle

  @author          Anu Jagannath

*****************************************************************************/
CML_t_TrafoMatrix2D CML_GetTrafoMatByDisplacementandAngle(float32 f_Angle, float32 f_XDisplacement, float32 f_YDisplacement)
{
  CML_t_TrafoMatrix2D TrafoMat;

  TrafoMat.TrafoType = DEFAULT_;
  CML_f_sincos( f_Angle , &TrafoMat.f10 , &TrafoMat.f00 ); 
  TrafoMat.f02 = f_XDisplacement;
  TrafoMat.f12 = f_YDisplacement;  
  return TrafoMat;
}

/*****************************************************************************
  Functionname:    CML_u_MatrixCopy                                     */ /*!

  @brief           Copy a given matrix

  @description     This function copies the contents of one matrix to another
                   if the number of elements is non-zero. The function will 
                   always return TRUE.

  @param[in]       a_MatrixA :    original matrix
                                  [Full range of float32]
  @param[out]      a_MatrixCpy :  copied matrix
                                  [Full range of float32]
  @param[in]       u_dim_Ax :     x-dimension of matrix A
                                  [Full range of uint8]
  @param[in]       u_dim_Ay :     y-dimension of matrix A
                                  [Full range of uint8]

  @return          true

  @author          Robert Thiel

*****************************************************************************/
uint8 CML_u_MatrixCopy(float32 const a_MatrixA[CML_RESTRICT], float32 a_MatrixCpy[CML_RESTRICT], uint8 u_dim_Ax, uint8 u_dim_Ay)
{
  uint16 n;
  uint16 p;
  n = ((uint16)u_dim_Ay*(uint16)u_dim_Ax);
  p = 0u;
  while(n > 0UL)
  {
    n--;
    a_MatrixCpy[p] = a_MatrixA[p];
    p++;
  }  
/* PRQA S 4404 5 */
/* Deactivate QAC warning 4404, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as there is no change or loss of data in this conversion */
  return b_TRUE; /*ever*/
}

/*****************************************************************************
  Functionname:    CML_u_MatrixTranspose                                */ /*!
  
  @brief           transposition of a matrix
  
  @description     This function does the transpose of matrix.
                   For Square matrices, the pointers for the original matrix
                   and the transpose matrix can be same or different.
                   example:
                   |a1 a2 a3| TRANSPOSE  |a1 a4 a7|
                   |a4 a5 a6| ========>	 |a2 a5 a8|
                   |a7 a8 a9|			 |a3 a6 a9|
                   For Non-square matrices, the pointers for the original matrix
                   and the transpose matrix MUST BE different, otherwise the 
                   function will return false.
                   example:
                   |a1 a2 a3| TRANSPOSE  |a1 a4| 
                   |a4 a5 a6| ========>	 |a2 a5| 
                                         |a3 a6|
  
  @param[in]       a_MatrixA :     original matrix
                                   [Full range of float32]
  @param[out]      a_ATranspose :  transposed matrix (with dimension dim_Ay * dim_Ax)
                                   [Full range of float32]
  @param[in]       u_dim_Ax :      x-dimension of matrix A
                                   [Full range of uint8]
  @param[in]       u_dim_Ay :      y-dimension of matrix A
                                   [Full range of uint8]
  
  @return          true if operation was successful
  
  @author          Robert Thiel

*****************************************************************************/
uint8 CML_u_MatrixTranspose(float32 const  a_MatrixA[CML_RESTRICT], float32 a_ATranspose[CML_RESTRICT], uint8 u_dim_Ax, uint8 u_dim_Ay)
{
  uint8   u_ret;
  uint8   u_Idx2,u_Idx1;
  uint16  u_pos1, u_pos2, u_tmp;
  float32 f_save;
/* PRQA S 4404 5 */
/* Deactivate QAC warning 4404, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as there is no change or loss of data in this conversion  */
  u_ret = b_TRUE;

  if(u_dim_Ax == u_dim_Ay)
  {
    /*square matrix*/
    if(a_ATranspose!= a_MatrixA) /*in case of different pointers: copy matrix first*/
    {
      u_ret = CML_u_MatrixCopy(a_MatrixA, a_ATranspose, u_dim_Ax, u_dim_Ay);
    }

    for(u_Idx1 = 0u; u_Idx1 < u_dim_Ay; u_Idx1++)
    {
      const uint16 c1 = (uint16)u_Idx1 * (uint16)u_dim_Ax;
      for(u_Idx2 = u_Idx1+1u; u_Idx2 < u_dim_Ax; u_Idx2++)
      {  
        u_pos1 = (uint16)(c1 + u_Idx2);
        u_tmp  = ((uint16)u_Idx2 * (uint16)u_dim_Ax);
        u_tmp  = u_tmp + u_Idx1;
        u_pos2 = (uint16)u_tmp; /*position of the element to switch with*/
        /*switch values*/
        f_save = a_MatrixA[u_pos2]; /*save in case of A==a_ATransp*/
        a_ATranspose[u_pos2] = a_MatrixA[u_pos1];
        a_ATranspose[u_pos1] = f_save;        
      }
    }
  }
  else
  {
    if(a_MatrixA == a_ATranspose) /*it's not possible to transpose the matrix to its own*/
    {
/* PRQA S 4404 5 */
/* Deactivate QAC warning 4404, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as there is no change or loss of data in this conversion  */
      u_ret = b_FALSE;
    }
    else
    {
      u_pos1 = 0u;
      for(u_Idx1 = 0u; u_Idx1 < u_dim_Ax; u_Idx1++)
      {
        for(u_Idx2 = 0u; u_Idx2 < u_dim_Ay; u_Idx2++)
        {    
          u_tmp  = (uint16)u_Idx2 * (uint16)u_dim_Ax;
          u_tmp  = u_tmp + u_Idx1;
          u_pos2 = (uint16) u_tmp; /*position of the element to switch with*/
          /*switch values*/          
          a_ATranspose[u_pos2] = a_MatrixA[u_pos1];
          u_pos1++;
        }
      }
    }
  }  
  return u_ret;   
}

/*****************************************************************************
  Functionname:    CML_u_MatrixMultiplication                           */ /*!

  @brief           multiplies two matrices A and B

  @description     This function multiplies two matrices A and B (AxB)
                   NOTE: The function expects the following matrix dimensions:
                   number of rows and number of columns of the first matrix A,
                   and just number of columns of second matrix B. 
                   The function assumes the prerequisite for matrix multiplication,
                   i.e. no. of columns of A = no. of rows of B, is satisfied.

  @param[in]     a_MatrixA :  first matrix
                              [Full range of float32]
                              Overflow may occur when input values 
                              are at the defined range extremities.
  @param[in]     a_MatrixB :  second matrix
                              [Full range of float32]
                              Overflow may occur when input values 
                              are at the defined range extremities.
  @param[in]     u_dim_Ax :   x-dimension of A
                              [Full range of uint8]
  @param[in]     u_dim_Ay :   y-dimension of A
                              [Full range of uint8]
  @param[in]     u_dim_Bx :   x-dimension of B
                              [Full range of uint8]
  @param[out]    a_AxB :      product A*B
                              [Full range of float32]

  @return        true if operation was successful

  @author        Robert Thiel

*****************************************************************************/
uint8 CML_u_MatrixMultiplication(float32 const a_MatrixA[CML_RESTRICT], float32 const a_MatrixB[CML_RESTRICT], float32 a_AxB[CML_RESTRICT], uint8 u_dim_Ax, uint8 u_dim_Ay, uint8 u_dim_Bx)
{
  uint8    u_ret;
  uint8    i, j, k;  
  float32  f_save;
  float32  f_temp;
/* PRQA S 4404 5 */
/* Deactivate QAC warning 4404, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as there is no change or loss of data in this conversion  */
  u_ret = b_TRUE;
  if((a_AxB != a_MatrixA) && (a_AxB != a_MatrixB))
  {
    for(i = 0u; i < u_dim_Ay; i++)
    {
      const uint16 colA = (uint16)i * (uint16)u_dim_Ax;
      const uint16 colAxB = (uint16)i * (uint16)u_dim_Bx;
      for(j = 0u; j < u_dim_Bx; j++)
      {
        f_save = 0.f;
        for(k = 0u; k < u_dim_Ax; k++)
        {
        /* This code is re-written for ECU-SIL bit exactness */
            f_temp = a_MatrixA[colA + k] * a_MatrixB[j + (k*u_dim_Bx)];
            f_save = f_save + f_temp;
        }
        a_AxB[j + colAxB] = f_save;
      }
    }
  }
  else
  {
/* PRQA S 4404 5 */
/* Deactivate QAC warning 4404, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as there is no change or loss of data in this conversion  */
    u_ret = b_FALSE;
  } 

  return u_ret;  
}

/*****************************************************************************
  Functionname:    CML_u_MatrixInversion                                */ /*!

  @brief           calculates the inverse of a square matrix using Gauss-Jordan algorithm

  @description     This function calculates the inverse of a square matrix using 
                   Gauss-Jordan algorithm. The algorithm is as follows:
                   If the square matrix to be inverted is A, and I is the 
                   Identity matrix of the same order as A, then first I is 
                   appended to A -> |A|I|. If possible to transform this matrix by
                   using Elementary Row Operations to |I|B|, then B is the 
                   inverse of A. 
                   example: 
                   A = |a1 a2| and I = |1 0|
                       |a3 a4|         |0 1|

                                       Elementary Row Operations
                   |A|I| = |a1 a2|1 0| =========================> |1 0|b1 b2| = |I|B|
                           |a3 a4|0 1|							  |0 1|b3 b4|

                   Now, B is the inverse of A.
                  

  @param[in]       a_MatrixA :  original matrix (dim_xy*dim_xy)
                                [Full range of float32]
                                Overflow may occur when input values 
                                are at the defined range extremities.
  @param[in]       a_tempMatrix :  temporary matrix (dim_xy*dim_xy)
                                   [Full range of float32]
  @param[out]      a_InverseA :  inverse of A (dim_xy*dim_xy)
                                 [Full range of float32]
  @param[in]       u_dim_xy :  x- and y-dimension of A
                               [Full range of uint8]

  @return          true if operation was successful

  @author          Robert Thiel

*****************************************************************************/
uint8 CML_u_MatrixInversion(float32 const a_MatrixA[], float32 a_tempMatrix[], float32 a_InverseA[], uint8 u_dim_xy)
{
  uint8 u_ret;
  uint8 i,j;
  uint8 u_row, u_prow;
  uint16 u_it_row;
  float32 max_val, fak, f_temp1;
  const float32 f_e = 0.00001F;

/* PRQA S 2982 10 */
/* Deactivate QAC warning 2982, Date: 2019-06-18; Reviewer: uid22555;
   Reason: There is no risk in using a redundant operation. */
  u_ret = CML_u_MatrixCopy(a_MatrixA, a_tempMatrix, u_dim_xy, u_dim_xy); /*copy to destination because we want to work in it*/


  /*create identity matrix*/
  for (i = 0u; i < u_dim_xy; i++) 
  {
      const uint16 p = (uint16)i * (uint16)u_dim_xy;
      for (j = 0u; j < u_dim_xy; j++)
      {
          a_InverseA[p+j] = 0.f;
          if (i == j)
          {
              a_InverseA[p+j] = 1.f;
          }
      }
  }

  /*start iteration*/
  u_row = 0u;
  do 
  {
/* PRQA S 4404 5 */
/* Deactivate QAC warning 4404, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as there is no change or loss of data in this conversion  */	  
      u_ret = b_FALSE;

      max_val = CML_f_Abs(a_tempMatrix[u_row+(u_row*u_dim_xy)]);

      u_prow = u_row ; 
      for (i = u_row+1u; i < u_dim_xy; i++)
      {     
          if (CML_f_Abs(a_tempMatrix[(i*u_dim_xy)+u_row]) > max_val) 
          {
              max_val = CML_f_Abs(a_tempMatrix[(i*u_dim_xy)+u_row]) ;
              u_prow = i;
          }
      }

      if(max_val >= f_e)
      {
          if (u_prow != u_row)  /*rotate rows*/
          { 
              float32 help;
              for (j = 0u ; j < u_dim_xy; j++) 
              {
                  help = a_InverseA[(u_row*u_dim_xy) + j];
                  a_InverseA[(u_row*u_dim_xy) + j] = a_InverseA[(u_prow*u_dim_xy) + j];
                  a_InverseA[(u_prow*u_dim_xy) + j] = help;

                        
              }
              for (j = u_row ; j < u_dim_xy; j++) 
              {
                      help = a_tempMatrix[(u_row*u_dim_xy) + j];
                      a_tempMatrix[(u_row*u_dim_xy) + j]  = a_tempMatrix[(u_prow*u_dim_xy) + j];
                      a_tempMatrix[(u_prow*u_dim_xy) + j] = help;        
                 
              }
          }

          /*elimination: division by a_Ai[it,it]*/
          u_it_row = (uint16)u_row * (uint16)u_dim_xy;
          fak    = a_tempMatrix[u_row+u_it_row];
          for (j = 0u; j < u_dim_xy; j++)
          {
              if(j >= u_row)
              {
                  a_tempMatrix[u_it_row+j]/= fak;              
              }
              a_InverseA[u_it_row+j]/= fak;
          }

          /*further elimination*/
          for (i = 0u; i < u_dim_xy; i++) 
          {
              if (i != u_row) 
              {
                  fak = -a_tempMatrix[(i*u_dim_xy)+u_row]; 
                  for (j = 0u; j < u_row; j++)    
                  {  
                      /* Re-written for ECU-SIL bit exactness */    
                      f_temp1 = fak*a_InverseA[(u_row*u_dim_xy)+j]; 
                      a_InverseA[(i*u_dim_xy)+j] =  a_InverseA[(i*u_dim_xy)+j] + f_temp1; 
    
                  }

                  for (j = u_row; j < u_dim_xy; j++)    
                  {  
                     /* Re-written for ECU-SIL bit exactness */    
                      f_temp1 = fak*a_tempMatrix[(u_row*u_dim_xy)+j]; 
                      a_tempMatrix[(i*u_dim_xy)+j] = a_tempMatrix[(i*u_dim_xy)+j] + f_temp1; 

                      f_temp1 =  fak*a_InverseA[(u_row*u_dim_xy)+j];
                      a_InverseA[(i*u_dim_xy)+j] = a_InverseA[(i*u_dim_xy)+j] + f_temp1; 
                  }
              }
          }
/* PRQA S 1881 , 4404 8 */
/* Deactivate QAC warning 1881,4404,  Date: 2019-06-18; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as there is no change or loss of data in this conversion  */
          u_row++;
          u_ret = b_TRUE;
      }    
  } while ((u_ret == b_TRUE) && (u_row < u_dim_xy)) ;


  return u_ret;
}

/*****************************************************************************
  Functionname:    CML_u_MatrixAddition                                 */ /*!

  @brief           addition of two matrices A and B

  @description     This function performs addition of two matrices A and B.
                   The function assumes both matrices are of same order and 
                   hence accepts only one set of dimension.

  @param[in]       a_MatrixA :  first matrix (dim_x*dim_y)
                                [Full range of float32]
                                Overflow may occur when input values 
                                are at the defined range extremities.
  @param[in]       a_MatrixB :  second matrix (dim_x*dim_y)
                                [Full range of float32]
                                Overflow may occur when input values 
                                are at the defined range extremities.
  @param[out]      a_AplusB :   the sum A+B
                                [Full range of float32]
  @param[in]       u_dim_x :    x-dimension of A and B
                                [Full range of uint8]
  @param[in]       u_dim_y :    y-dimension of A and B
                                [Full range of uint8]

  @return          true

  @author          Robert Thiel

*****************************************************************************/
uint8 CML_u_MatrixAddition(float32 const a_MatrixA[CML_RESTRICT], float32 const a_MatrixB[CML_RESTRICT], float32 a_AplusB[CML_RESTRICT], uint8 u_dim_x, uint8 u_dim_y)
{
  uint8  u_Index      = 0u;
  uint16 u_NumEntries = (uint16)u_dim_x * (uint16)u_dim_y;
  while(u_NumEntries > 0UL)
  {
    u_NumEntries--;
    a_AplusB[u_Index] = a_MatrixA[u_Index]+a_MatrixB[u_Index];
    u_Index++;
  }
/* PRQA S 4404 5 */
/* Deactivate QAC warning 4404, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as there is no change or loss of data in this conversion  */
  return b_TRUE; /*always*/
}

/*****************************************************************************
  Functionname:    CML_u_MatrixSubtraction                              */ /*!

  @brief           subtraction of two matrices A and B

  @description     This function performs subtraction of two matrices A and B.
                   The function assumes both matrices are of same order and 
                   hence accepts only one set of dimension.

  @param[in]       a_MatrixA :  first matrix (dim_x*dim_y)
                                [Full range of float32]
                                Overflow may occur when input values 
                                are at the defined range extremities.
  @param[in]       a_MatrixB :  second matrix (dim_x*dim_y)
                                [Full range of float32]
                                Overflow may occur when input values 
                                are at the defined range extremities.
  @param[out]      a_AminusB :  the difference A-B
                                [Full range of float32]
  @param[in]       u_dim_x :    x-dimension of A and B
                                [Full range of uint8]
  @param[in]       u_dim_y :    y-dimension of A and B
                                [Full range of uint8]

  @return          true

  @author          Robert Thiel

*****************************************************************************/
uint8 CML_u_MatrixSubtraction(float32 const a_MatrixA[CML_RESTRICT], float32 const a_MatrixB[CML_RESTRICT], float32 a_AminusB[CML_RESTRICT], uint8 u_dim_x, uint8 u_dim_y)
{
  uint16 u_Index      = 0u;
  uint16 u_NumEntries = (uint16)u_dim_x * (uint16)u_dim_y;
  while(u_NumEntries > 0UL)
  {
    u_NumEntries--;
    a_AminusB[u_Index] = a_MatrixA[u_Index]-a_MatrixB[u_Index];
    u_Index++;
  }
/* PRQA S 4404 5 */
/* Deactivate QAC warning 4404, Date: 2019-06-17; Reviewer: uid22555;
   Reason: There is no risk in violating this rule as there is no change or loss of data in this conversion  */
  return b_TRUE; /*always*/
}
