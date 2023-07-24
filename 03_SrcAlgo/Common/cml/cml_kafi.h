/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_kafi.h

  DESCRIPTION:               Functions related to the Kalman filter

  AUTHOR:                    Jochen Spruck

  CREATION DATE:             03.02.2010

  VERSION:                   $Revision: 1.9 $

  ---*/ /*---
  CHANGES:                   $Log: cml_kafi.h  $
  CHANGES:                   Revision 1.9 2017/11/16 13:24:19CET Kotre, Jeevan (uidk9586) (uidk9586) 
  CHANGES:                   Updated cml_kafi module with coding guidelines.
  CHANGES:                   Revision 1.8 2017/09/27 05:59:17CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Merged from branch with Detailed Design
  CHANGES:                   Revision 1.7 2016/09/23 11:53:43CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Structure alignment changed
  CHANGES:                   Revision 1.6 2015/04/29 14:39:10CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - Changes with respect to Coding Guidelines
  CHANGES:                     of variables.
  CHANGES:                   - Added comments -  uidr5428 [Apr 29, 2015 2:39:11 PM CEST]
  CHANGES:                   Change Package : 324617:2 http://mks-psad:7002/im/viewissue?selection=324617
  CHANGES:                   Revision 1.5 2014/04/07 10:30:47CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed erroneous include protection
  CHANGES:                   --- Added comments ---  uidg6516 [Apr 7, 2014 10:30:47 AM CEST]
  CHANGES:                   Change Package : 227281:3 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.4 2014/02/04 15:11:23CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - improve code quality
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 4, 2014 3:11:23 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.3 2013/05/03 09:56:54CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - drop algo_common from CML
  CHANGES:                   - use new standard type names, e.g. float32 instead of f32_t
  CHANGES:                   --- Added comments ---  uidu0849 [May 3, 2013 9:56:54 AM CEST]
  CHANGES:                   Change Package : 159154:27 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.2 2012/09/20 13:29:46CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:46 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:11CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/**
@defgroup kafi KAFI (Functions related to the Kalman filter)
  @ingroup cml
@{ */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef _CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_kafi.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef _CML_EXT_INCLUDED */

#ifndef _CML_KAFI_INCLUDED
#define _CML_KAFI_INCLUDED


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*! Lane Kalman Filter related Matrix Types */
/*! Type aliasing enum type for matrix type (for MCUs where enums take too much RAM) values: CML_t_e_KafiMatrixType */
typedef CML_enum_t CML_t_KafiMatrixType; // GDBMatrixType_t
/*! Lane Kalman Filter related Matrix Types */
#define  CML_KafiMatrixTypeVector     (CML_t_KafiMatrixType)0 ///< Kalman Filter matrix of type vector
#define  CML_KafiMatrixTypeFull       (CML_t_KafiMatrixType)1 ///< Kalman Filter matrix of type normal full matrix
#define  CML_KafiMatrixTypeSymmetric  (CML_t_KafiMatrixType)2 ///< Kalman Filter matrix of type symmetric matrix
#define  CML_KafiMatrixTypeUpperRight (CML_t_KafiMatrixType)3 ///< Kalman Filter matrix of type upper triangular matrix
#define  CML_KafiMatrixTypeDiagonal   (CML_t_KafiMatrixType)4 ///< Kalman Filter matrix of type diagonal matrix


/// \brief     Matrix structure for the kalman filter 
/// \details   This structure holds the details and values of matrices 
///            required for computations related to the kalman filter. This is mainly
///            used for the lane estimation.
typedef struct
{
   uint8            uiRows;          ///< Number of rows of matrix             
   uint8            uiColumns;       ///< Number of columns of matrix          
   uint16           uiElements;      ///< Number of elements in matrix         
   float32 *          pdData;        ///< Pointer to the entries of the matrix 
   CML_t_KafiMatrixType  matType;    ///< Type of matrix                       
} CML_t_KafiMatrix;


/// \brief     Base structure for the kalman filter 
/// \details   This structure holds the number of states and matrices 
///            required for computations related to the kalman filter. This is mainly
///            used for the lane estimation
typedef struct
{
  /* Kalman Matrixes */
  CML_t_KafiMatrix AMat;          ///< full matrix, transition matrix              
  CML_t_KafiMatrix QMat;          ///< diagonal matrix, process noise covariance   
  CML_t_KafiMatrix XVec;          ///< Vector, estimated state vector              
  CML_t_KafiMatrix PDiagMat;      ///< diagonal matrix, covariance                 
  /* Internal Matrixes */          
  CML_t_KafiMatrix UDMat;         ///< UDUT factorized matrix, covariance          
  CML_t_KafiMatrix XsVec;         ///< Vector, predicted state vector              
  uint8 uiNbOfStates;             ///< Number of States                            
} CML_t_BaseKafi;

/// \brief     Structure for the simple kalman filter 
/// \details   This structure holds the input, internal state, output, dimensions and temporary variables
///            required for computations related to the simple kalman filter. 
typedef struct {
  /*input*/  
  float32 *A;           ///< state transition model matrix, dimension: x_y*x_y 
  float32 *B;           ///< control-input model vector, dimension: B_x*x_y 
  float32 *u;           ///< control matrix, dimension: 1*B_x 
  float32 *Q;           ///< process noise matrix, dimension: x_y*x_y 
  float32 *z;           ///< observation vector, dimension: 1*x_y 
  float32 *H;           ///< observation model matrix, dimension: x_y*x_y 
  float32 *R;           ///< observation noise covariance, dimension: x_y*x_y 
  /*internal state*/
  float32 *P;           ///< error covariance matrix, dimension: x_y*x_y 
  /*output*/
  float32 *x;           ///< estimate vector, dimension: 1*x_y  
  /*temp vars*/
  float32 *K;           ///< kalman gain, dimension: x_y*x_y 
  float32 *T;           ///< temporary, dimension: x_y*x_y 
  float32 *T2;          ///< temporary, dimension: x_y*x_y 
  float32 *tx;          ///< temporary value for x, dimension: 1*x_y 
  /*dimension definitions*/
  uint8 x_y, B_x;
} CML_t_SimpleKafi; // GDBSimpleKafi_t

/*****************************************************************************
  MACROS
*****************************************************************************/

/*! Matrix Index Macros for the Lane Kalman Filter */
#define CML_VectMatIndex(index) (index)                                                     ///< Vector index calculation                  
#define CML_FullMatIndex(row, column, nbofcolumns) (((row) * (nbofcolumns)) + (column))     ///< Full Matrix index calculation             
#define CML_SymmMatIndex(row, column) ((((column) *((column) + 1u)) / 2u) + (row))          ///< Symmetric Matrix index calculation        
#define CML_UpriMatIndex(row, column) ((((column) *((column) + 1u)) / 2u) + (row))          ///< Upper Triangular Matrix index calculation 
#define CML_DiagMatrIndex(row) (row)  

/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/

/*! Interface functions of the kalman filter used for the lane estimation */
/******************************************************************************
  Functionname:    CML_v_kalmanTimeUpdate                                    */

///  \brief           Update the states and the error covariance matrix to the actual time
///
///  \description     This function does the time update part of the Kalman filter
///                   It update the states and the error covariance matrix to the
///                   actual time. The time update equations are responsible for 
///                   projecting forward (in time) the current state and error 
///                   covariance estimates to obtain the estimates for the next 
///                   time step. With the transition matrix, factorized covariance 
///                   it calculates the new predicted state vector and an updated
///                   covariance matrix.\n
///                   The calculations used are from Biermann Factorization Methods.\n
///                   Let the input parameters be Ud, Dd and the output parameters be Us, Ds. 
///                   The calculations used for the time update are as follows.        \n                                         
///                   W  = [ Phi*Ud QU ] \n
///                   DA = Diag(Dd, QD)  \n
///                   The following lines will be executed for values of j from 1 to one less than the number of states        \n                   
///                      Ds(j) = W(j,:)' * DA * W(j,:)      \n          
///                   The following  two lines will be executed for values of k from 0 to j-1 \n
///                        Us(k,j) = (W(k,:)' * W(j,:)) * DA / Ds(j)  \n
///                        W(k,:) = W(k,:) - Us(k,j) * W(j,:)         \n
///                  And finally the first value of the covariance matrix is updated as follows. \n
///                   Ds(0) = W(0,:)' * DA * W(0,:)       
///  \attention      The function does not verify the validity of the pointers passed.
///
///  \param[in]       p_GDBKafi :  pointer on the Kalman filter static structures
///                                Supported values for p_GDBKafi->uiNbOfStates [0,..,127]
///                                Supported values for p_GDBKafi->AMat.pdData
///                                [Valid float32 pointer]
///                                Supported values for p_GDBKafi->QMat.pdData
///                                [Valid float32 pointer]
///                                Supported values for p_GDBKafi->XVec.pdData
///                                [Valid float32 pointer]
///                                Supported values for p_GDBKafi->UDMat.pdData
///                                [Valid float32 pointer]
///                                Supported values for p_GDBKafi->XsVec.pdData
///                                [Valid float32 pointer]
///  \param[in]       WMat :       temporary Matrix W = [W1 W2] = [A*UD Id]
///                                Supported values for WMat.pdData
///                                [Valid float32 pointer]
///  \param[in]       DAMat :      temporary Matrix DA = [Diag(UD, Q)]
///                                Supported values for DAMat.pdData
///                                [Valid float32 pointer]
///  \param[in]       DAWVec :     temporary Vector DAW = W'*DA*W
///                                Supported values for DAWVec.pdData
///                                [Valid float32 pointer]
///
///  \return          void
///
///  \author          Philippe Dintzer
///
///  \testmethod  
///  \traceability    
/*****************************************************************************/
extern void CML_v_kalmanTimeUpdate (CML_t_BaseKafi const * const p_GDBKafi, CML_t_KafiMatrix WMat, CML_t_KafiMatrix DAMat, CML_t_KafiMatrix DAWVec);

/*****************************************************************************
  Functionname:    CML_v_kalmanMeasUpdate                                   */

///  \brief           Calculate the Kalman gain, estimate the states and
///                   update the error covariance matrix
///
///  \description     This function does the measurement update part of the 
///                   Kalman filter. It calculate the Kalman gain, estimate the 
///                   states and update the error covariance matrix.
///                   The measurement update equations are responsible for the 
///                   feedback, for incorporating a new measurement to obtain an
///                   improved estimate. It takes in the measurement matrix and 
///                   the prior estiate values to do the correction for the 
///                   better estimate. \n
///                   The calculations used are from Biermann Factorization Methods.\n
///                   The inputs to the calculations are x, the a priori estimate, U, the
///                   upper triangular matrix with D(i) stored on the diagonals; this corresponds
///                   to the a priori covariance and z,a and r which are the observation, 
///                   observation coefficients and the observation error variance respectively.
///                   The fact that U theoretically has unit elements on the diagonal is implicit in 
///                   the mechanization. \n
///                   The outputs are the x, the updated estimate, U, the updated upper triangular matrix, 
///                   alpha, the innovations variance of the measurement, unweighted Kalman gain.
///                   Equation 1 is looped through all k values from 1 to j-1 \n
///                    a(j) = a(j) + U(k,j) * a(k), F(j) = a(j) ---- (1)\n
///                    K = D * F ,where D= U(j,j)               \n
///                    alfa = r + K(0) * F(0)                   \n
///                    gamma1 = 1 / alfa                        \n
///                    D(0) = D(0) * r * gamma1                 \n
///                    for j = 1 ... n-1                        \n
///                      beta = alfa                            \n
///                      alfa = alfa + K(j) * F(j)              \n
///                      lamba = -F(j) * gamma1                 \n
///                      gamma1 = 1 / alfa                      \n
///                      D(j) = D(j) * beta * gamma1            \n
///                   The next two equations are run for all values of i from 1 to j-1
///                      U(i,j) = U(i,j) + lamda * K(i)         \n
///                      K(i) = K(i) + K(j) * U(i,j)            \n
///                    K = K * gamma1                           \n
///                    dx = dx + K * dy                         \n
///  \attention      The function does not verify the validity of the pointers passed.
///  \param[in]       p_GDBKafi :  pointer on the Kalman filter static structures
///                                Supported values for p_GDBKafi->uiNbOfStates [0,..,127]
///                                Supported values for p_GDBKafi->XVec.pdData
///                                [Valid float32 pointer]
///                                Supported values for p_GDBKafi->UDMat.pdData
///                                [Valid float32 pointer]
///  \param[in]       KMat :       Kalman gain matrix (Due to sequential updates
///                                is here a vector whose length = Nb of states)
///                                Supported values for KMat.pdData
///                                [Valid float32 pointer]
///  \param[in]       FVec :       temporary vector (vector length = Nb of states)
///                                Supported values for FVec.pdData
///                                [Valid float32 pointer]
///  \param[in]       CMat :       Measurement Matrix (Due to sequential updates
///                                is here a vector whose length = Nb of states)
///                                Supported values for CMat.pdData
///                                [Valid float32 pointer]
///  \param[in]       f_Meas :     Measure (dY)
///                                Supported values [Full range of float32]
///  \param[in]       f_MeasNoise :  noise associated with the Measure
///                                  Supported values [Full range of float32]
///                                  Overflow may occur at the extreme values of
///                                  the range
///
///  \return          void
///
///  \author          Philippe Dintzer
///
///  \testmethod  
///  \traceability    
/*****************************************************************************/
extern void CML_v_kalmanMeasUpdate(CML_t_BaseKafi const * const p_GDBKafi, CML_t_KafiMatrix KMat, CML_t_KafiMatrix FVec, CML_t_KafiMatrix CMat, float32 f_Meas, float32 f_MeasNoise);

/*****************************************************************************
  Functionname:    CML_v_kalmanPDiagUpdate                                  */

///  \brief           Calculate the diagonal of the P Matrix
///
///  \description     This function calculate the diagonal matrix P for covariance
///                   using the UDUT factorized matrix. The values are calculated
///                   as follows. The number of terms will be equal to the number of
///                   states. \n
///                   \f[ P(i,i) = D(i,i) + D(i+1,i+1)*U(i,i+1)^2 + D(i+2,i+2)*U(i,i+2)^2 + ...\f]
///  \attention      The function does not verify the validity of the pointers passed.
///
///  \param[in]       p_GDBKafi :  pointer on the Kalman filter static structures
///                                Supported values for p_GDBKafi->uiNbOfStates
///                                [Full range of uint8]
///                                Supported values for p_GDBKafi->PDiagMat.pdData
///                                [Valid float32 pointer]
///                                Supported values for p_GDBKafi->UDMat.pdData
///                                [Valid float32 pointer]
///
///  \return          void
///
///  \pre             the UD matrix has been updated
///
///  \author          Philippe Dintzer
///
///  \testmethod  
///  \traceability    
/*****************************************************************************/
extern void CML_v_kalmanPDiagUpdate(CML_t_BaseKafi const * const p_GDBKafi);

/*****************************************************************************
  Functionname:    CML_v_kalmanCreateMat                                    */

///  \brief           Initialise the static matrices required for the Kalman Filter
///
///  \description     This function initialise the static matrices required for 
///                   the Kalman Filter. It calculates the the number of elements
///                   based on the matrix type and given number of rows and columns
///                   Also it assigns allocated memory to the matrix elements and 
///                   initializes all matrix elements to zero. Also it assigns other 
///                   given value provided the calculation for number of elements is 
///                   successful. \n The function accepts the matrix type from the enumeration
///                   CML_t_KafiMatrixType. \n For CML_KafiMatrixTypeVector, the number of rows 
///                   and columns should be greater than 1. Whereas for CML_KafiMatrixTypeSymmetric,
///                   CML_KafiMatrixTypeUpperRight, CML_KafiMatrixTypeDiagonal, 
///                   the number of rows and columns should be same.\n. If the conditions for the 
///                   corresponding matrix type is not satisfied, the data will not be copied to the matrix. \n
///                   If  r,c be the number of rows and columns, then for each matrix type,
///
///                   |   Matrix type                  |  No. of elements  |
///                   |--------------------------------|-------------------|
///                   |CML_KafiMatrixTypeVector        |       r*c         |
///                   |CML_KafiMatrixTypeFull          |       r*c         |
///                   |CML_KafiMatrixTypeSymmetric     |       r*(r+1)/2   |
///                   |CML_KafiMatrixTypeUpperRight    |       r*(r+1)/2   |
///                   |CML_KafiMatrixTypeDiagonal      |       r           |
///
///  \attention      The function does not verify the validity of the pointers passed.
///  \param[in]       p_Data :     Pointer to already allocated data
///                                [Valid float32 pointer]
///  \param[in]       MatType :    Type of the Matrix (full, triangular...)
///                                Supported values [0,.,4]
///  \param[in]       u_Rows :     num of rows in the matrix
///                                Supported values [0,..,254]
///  \param[in]       u_Columns :  num of columns in the matrix
///                                Supported values [0,..,255]
///  \param[out]      p_matM :     Pointer to matrix structure
///                                Supported values for p_matM.matType
///                                Supported values [0,.,4]
///                                Supported values for p_matM.uiRows
///                                Supported values [0,..,255]
///                                Supported values for p_matM.uiColumns
///                                Supported values [0,..,255]
///                                Supported values for p_matM.uiElements
///                                Supported values [Full range of uint16]
///                                Supported values for p_matM.pdData
///                                [Valid float32 pointer]
///
///  \return          void
///
///  \pre             The required memory for the matrix has been allocated
///
///  \author          Philippe Dintzer
///
///  \testmethod  
///  \traceability    
/*****************************************************************************/
extern void CML_v_kalmanCreateMat(CML_t_KafiMatrix* p_matM, float32* p_Data, CML_t_KafiMatrixType  MatType, uint8 u_Rows, uint8 u_Columns);

/*****************************************************************************
  Functionname:    CML_v_kalmanSetMat                                       */

///  \brief           Alter a static matrix used by the Kalman filter
///
///  \description     This function alters a static matrix used by the Kalman 
///                   filter. Given value is updated in the specified location in 
///                   the matrix defined by the row and column depending on the 
///                   type of matrix.\n
///                   Based on the matrix type given, the index is calculated and the 
///                   value is set.
///
///                   |   Matrix type                  |  Index calculaton |
///                   |--------------------------------|-------------------|
///                   |CML_KafiMatrixTypeVector        |  CML_VectMatIndex |
///                   |CML_KafiMatrixTypeFull          |  CML_FullMatIndex |
///                   |CML_KafiMatrixTypeSymmetric     |  CML_SymmMatIndex |
///                   |CML_KafiMatrixTypeUpperRight    |  CML_UpriMatIndex |
///                   |CML_KafiMatrixTypeDiagonal      | CML_DiagMatrIndex |
///  
///  \attention      The function does not verify the validity of the pointers passed.
///
///  \param[in,out]   p_matM :   Matrix to be modified
///                              Supported values for p_matM.matType
///                              Supported values [0,.,4]
///                              Supported values for p_matM.uiRows
///                              Supported values [0,..,255]
///                              Supported values for p_matM.uiColumns
///                              Supported values [0,..,255]
///                              Supported values for p_matM.uiElements
///                              Supported values [Full range of uint16]
///                              Supported values for p_matM.pdData
///                              [Valid float32 pointer]
///  \param[in]       u_Row :    Position in the matrix (Row)
///                              Supported values [0,..,255]
///  \param[in]       u_Column : Position in the matrix (Column)
///                              Supported values [0,..,255]
///  \param[in]       f_Value :  Value to be set
///                              Supported values [Full range of float32]
///
///  \return          void
///
///  \author          Philippe Dintzer
///
///  \testmethod  
///  \traceability    
/*****************************************************************************/
extern void CML_v_kalmanSetMat(const CML_t_KafiMatrix* p_matM, uint8 u_Row, uint8 u_Column, float32 f_Value);

/*****************************************************************************
  Functionname:    CML_f_kalmanGetMatElement                                */

///  \brief           Get an element of a matrix used by the Kalman filter
///
///  \description     This function gets an element of a matrix used by the 
///                   Kalman filter.Required value is taken from the specified  
///                   location in the matrix defined by the row and column 
///                   depending on the type of matrix. \n
///                   Based on the matrix type given, the index is calculated and the 
///                   value is fetched.
///
///                   |   Matrix type                  |  Index calculaton |
///                   |--------------------------------|-------------------|
///                   |CML_KafiMatrixTypeVector        |  CML_VectMatIndex |
///                   |CML_KafiMatrixTypeFull          |  CML_FullMatIndex |
///                   |CML_KafiMatrixTypeSymmetric     |  CML_SymmMatIndex |
///                   |CML_KafiMatrixTypeUpperRight    |  CML_UpriMatIndex |
///                   |CML_KafiMatrixTypeDiagonal      | CML_DiagMatrIndex |
///
///  \attention      The function does not verify the validity of the pointers passed.
///  \param[in]       p_matM :    the Matrix to be read
///                               Supported values for p_matM.matType
///                               Supported values [0,.,4]
///                               Supported values for p_matM.uiRows
///                               Supported values [0,..,255]
///                               Supported values for p_matM.uiColumns
///                               Supported values [0,..,255]
///                               Supported values for p_matM.uiElements
///                               Supported values [Full range of uint16]
///                               Supported values for p_matM.pdData
///                               [Valid float32 pointer]
///  \param[in]       u_Row :     Position in the matrix (row)
///                               Supported values [0,..,255]
///  \param[in]       u_Column :  Position in the matrix (column)
///                               Supported values [0,..,255]
///
///  \return          The requested element of the matrix
///
///  \author          Matthias Zobel
///
///  \testmethod  
///  \traceability    
/*****************************************************************************/
extern float32 CML_f_kalmanGetMatElement(const CML_t_KafiMatrix* p_matM, uint8 u_Row, uint8 u_Column);

/*! Interface functions of the simple kalman filter (universal)*/
/*****************************************************************************
  Functionname:    CML_u_simpleKafiInit                                    */

///  \brief           initializes the Kalman filter parameters for given 
///                   kafi->z and kafi->R
///
///  \description     This function initializes the Kalman filter parameters 
///                   for given kafi->z and kafi->R. With the given observation
///                   model, noise covariance and vector, it computes the 
///                   Kalman gain, error covariance and estimate vector. All the
///                   required parameters are taken and updated within the Kalman
///                   filter structure.
///  \InOutCorrelation
///                   if X = state vector,                  \n
///                      P = covariance,                    \n
///                      H = Observation model              \n
///                      H'= Transpose of H                 \n
///                      Z = Observation vector             \n
///                      R = Observation noise covariance   \n
///                   then, 
///                   \f[ X = H^{-1} \times Z \f]
///                   \f[ P = H^{-1} \times R \times (H')^{-1} \f]
///  \attention      The function does not verify the validity of the pointers passed.
///
///  \param[in,out]   p_kafi :  a simple Kalman filter structure
///                             Supported values for p_kafi->x_y 
///                             [Full range of uint8]
///                             Supported values for p_kafi->z
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->H
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->R
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->P
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->x
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->K
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->T
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->T2
///                             [Valid float32 pointer]
///
///  \return          true if operation was successful
///
///  \author          Robert Thiel
///
///  \testmethod  
///  \traceability    
/*****************************************************************************/
extern uint8 CML_u_simpleKafiInit(CML_t_SimpleKafi const *p_kafi);

/*****************************************************************************
  Functionname:    CML_u_simpleKafiPrediction                              */

///  \brief           predict next cycle in simple Kalman filter
///
///  \description     This function predicts the next cycle in simple Kalman 
///                   filter. It does prediction for the state vector and the
///                   covariance as follows.
///  \InOutCorrelation
///                   if X = state vector,                  \n
///                      P = covariance,                    \n
///                      A = state transition model matrix  \n
///                      B = control-input model vector     \n
///                      u = control matrix                 \n
///                      Q = process noise matrix, then,    \n
///
///                    \f[  X = (A \times X )+ (B \times u)  \f]
///                    \f[  P = A * P * A' + Q               \f]
///  \attention      The function does not verify the validity of the pointers passed.
///
///  \param[in,out]   p_kafi :  a simple Kalman filter structure
///                             Supported values for p_kafi->x_y
///                             [Full range of uint8]
///                             Supported values for p_kafi->B_x
///                             [Full range of uint8]
///                             Supported values for p_kafi->A
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->B
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->u
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->Q
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->P
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->x
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->T
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->T2
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->tx
///                             [Valid float32 pointer]
///
///  \return          true if operation was successful
///
///  \author          Robert Thiel
///
///  \testmethod  
///  \traceability    
/*****************************************************************************/
extern uint8 CML_u_simpleKafiPrediction(CML_t_SimpleKafi const *p_kafi);

/*****************************************************************************
  Functionname:    CML_u_simpleKafiUpdate                                  */

///  \brief           update Kalman filter (with a given measurement kafi->z)
///
///  \description     This function updates Kalman filter 
///                   (with a given measurement kafi->z). It computes the 
///                   Kalman gain, correction based on the observation and 
///                   error covariance.
///  \InOutCorrelation
///                   if X = state vector,             \n
///                      P = error covariance,         \n
///                      H = Observation model         \n
///                      H'= Transpose of H            \n
///                      Z = Observation vector        \n
///                      K = Kalman gain factor, then, \n
///
///                   \f[   K = P \times H' \times ((H \times P \times H') + R)^{-1} \f]
///                   \f[   X = X + K \times (Z - (H \times X))             \f]
///                   \f[   P = P - (K \times H \times P)                   \f]
///
///  \attention      The function does not verify the validity of the pointers passed.
///
///  \param[in,out]   p_kafi :  a simple Kalman filter structure
///                             Supported values for p_kafi->x_y
///                             [Full range of uint8]
///                             Supported values for p_kafi->z
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->H
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->R
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->P
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->x
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->K
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->T
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->T2
///                             [Valid float32 pointer]
///                             Supported values for p_kafi->tx
///                             [Valid float32 pointer]
///
///  \return          true if operation was successful
///
///  \author          Robert Thiel
///
///  \testmethod  
///  \traceability    
/*****************************************************************************/
extern uint8 CML_u_simpleKafiUpdate(CML_t_SimpleKafi const *p_kafi);

#endif /* #ifndef _CML_KAFI_INCLUDED */


/** @} end defgroup */
