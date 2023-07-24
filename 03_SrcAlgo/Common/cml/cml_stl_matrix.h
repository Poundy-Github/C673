/*! \file **********************************************************************

COMPANY:                   Continental AG, A.D.C. GmbH

CPU:                       CPU-Independent

COMPONENT:                 CML (Common Math Library)

MODULNAME:                 cml_stl_matrix.h

DESCRIPTION:               Matrix Computations Library

AUTHOR:                    Markus Friebertshaeuser / Stefan Zechner

CREATION DATE:             15.11.2012

VERSION:                   $Revision: 1.58 $

**************************************************************************** */

#ifndef CML_STL_MATRIX_H__
#define CML_STL_MATRIX_H__

#include "cml_stl_array2d.h"
#include "cml_stl_algorithm.h"
#include <limits>

#ifdef C_COMPARISON_TEST
extern "C"
{
#include "cml_ext.h"
}
#endif

namespace cml
{
    /// \brief CMatrix is a CArray2D providing additional math operations for the Matrix.
    /// \details This class is derived publicly from CArray2D class with default memory specialization as "false".
    ///  This class provides additional math operations for the Matrix.
    /// \tparam T       The type of the matrix elements
    /// \tparam ROWS    The number of rows of the matrix
    /// \tparam COLS    The number of columns of the matrix
    /// \tparam EXT_MEM Flag whether the memory of the elements of the matrix is inside
    ///                 of this class (false) or outside of this class (true).
    ///                 Default is false, meaning internal memory.
    /// \testmethod
    /// \traceability
    template < class T, sint32 ROWS, sint32 COLS, boolean_t EXT_MEM = false >
    class CMatrix
        : public CArray2D<T, ROWS, COLS, EXT_MEM>
    {
    public:
        typedef CMatrix <T, ROWS, COLS, EXT_MEM> self;          ///< Abbreviation for the type of the class.
        typedef CMatrix <T, ROWS, COLS>          self_internal; ///< Abbreviation for the type of the class but with internal memory.
        typedef CArray2D<T, ROWS, COLS, EXT_MEM> super;         ///< Base class of this CMatrix template configuration.
        typedef typename super::super            super_super;   ///< Base class of the CArray2D template configuration.
        typedef sint32                           size_type;     ///< Abbreviation for the integer type and it is used for storing array size.
        typedef typename remove_const<T>::type   type;          ///< Alias name for the type(non constant) of the matrix elements.
        typedef typename    add_const<T>::type   const_type;    ///< Alias name for the constant type of the matrix elements.
        typedef typename remove_const<T>::type&  reference;     ///< Alias name for the reference to the type of the matrix elements.
        typedef typename    add_const<T>::type&  const_reference; ///< Alias name for the constant reference to the type of the matrix elements.
        typedef typename remove_const<T>::type*  pointer;       ///< Alias name for the pointer to the type of the matrix elements.
        typedef typename    add_const<T>::type*  const_pointer; ///< Alias name for the constant pointer to the type of the matrix elements.
        typedef int                              difference_type; ///< Abbreviation for the integer type and it is used for storing the difference of two pointers.

        // iterator typedefs
        typedef typename super::it                        rowIt;  ///< Alias name for the iterator to the CArray2D.
        typedef typename super::cIt                       cRowIt; ///< Alias name for the constant iterator to the CArray2D.
#ifndef NDEBUG
        typedef typename cml::CLinMemIt< type, false, super_super, COLS >  colIt;  ///< Alias name for the Column iterator with STRIDE = COLS.
        typedef typename cml::CLinMemIt< type, true , super_super, COLS > cColIt;  ///< Alias name for the constant Column iterator with STRIDE = COLS.
#else
        typedef typename cml::CLinMemIt< type, false, COLS >  colIt; ///< Alias name for the Column iterator with STRIDE = COLS.
        typedef typename cml::CLinMemIt< type, true , COLS > cColIt; ///< Alias name for the constant Column iterator with STRIDE = COLS.
#endif

        // This is only required for TI-Compiler to be able to compile
        using super::SIZE;   
        // End of section required for TI-Compiler

        // Redefinition of constructors since they are not inherited
        /// \brief Default empty constructor.
        /// \testmethod
        /// \traceability
        CMatrix(){}

        /// \brief Constructor with pointer to a buffer and size.
        /// \details This constructor takes Pointer to constant data "data" and size of the buffer "size" as arguments.
        /// This arguments are passed to the base class constructor for object initilization.
        /// \param[in] data Pointer to constant data
        /// \param[in] size Constant size of the buffer
        /// \testmethod
        /// \traceability
        CMatrix(       pointer const data, const sint32 size ) : super(data, size) {}

        /// \brief Constructor with Constant pointer to constant data and size.
        /// \details This constructor takes Constant Pointer to constant data "data" and size of the buffer "size" as arguments.
        /// This arguments are passed to the base class constructor for object initialization.
        /// \param[in] data Constant pointer to constant data
        /// \param[in] size Constant size of the buffer
        /// \testmethod
        /// \traceability
        CMatrix( const_pointer const data, const sint32 size ) : super(data, size) {}

        /// \brief Constructor with reference to matrix of possibly different size than this.
        /// \details Template constructor that copies the given non-constant reference 
        /// non-constant external data of possibly different size (SIZE2) to the internal memory.
        /// Non-constant reference will be passed as an argument to the base class constructor in which actual data member initialization happens.
        /// \tparam    SIZE2   The size of the external matrix
        /// \param[in] data    Reference to data of SIZE2
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2 >
        CMatrix( type (&data)[SIZE2] ) : super(data) {}

        /// \brief Constructor with constant reference to matrix of possibly different size than this.
        /// \details  template  constructor that copies the given non-constant reference 
        ///  constant external data of possibly different size (SIZE2) to the internal memory. 
        ///  These parameters will be passed to the base class constructor for data member initialization.
        /// \tparam    SIZE2   The size of the external matrix
        /// \param[in] data    Constant reference to data of SIZE2
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2 >
        CMatrix( const_type (&data)[SIZE2] ) : super(data) {}

        /// \brief Constructor with reference to constant CArrayStorage object of non constant data
        /// and possibly different size and external memory setting.
        /// \details  template copy constructor that copies or attaches constant reference external identical data 
        /// with non-constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the internal data storage.
        /// These parameters will be passed to the base class constructor for data member initialization.
        /// \tparam    SIZE2      The size of CArrayStorage
        /// \tparam    EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                       of this class (false) or outside of this class (true).
        ///                       Default is false, meaning internal memory.
        /// \param[in] rhs        Constant reference to CArrayStorage object of SIZE2
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CMatrix( const CArrayStorage<type, SIZE2, EXT_MEM2>& rhs ) : super(rhs) {}

        /// \brief Constructor with reference to constant CArrayStorage object of constant data
        ///  and possibly different size and external memory setting.
        /// \details  template copy constructor that copies or attaches constant reference external identical data 
        ///  with constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the internal data storage.
        ///  These parameters will be passed to the base class constructor for data member initialization.
        /// \tparam    SIZE2      The size of CArrayStorage
        /// \tparam    EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                       of this class (false) or outside of this class (true).
        ///                       Default is false, meaning internal memory.
        /// \param[in] rhs        Constant reference to CArrayStorage object of SIZE2	
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CMatrix( const CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs ) : super(rhs) {}

        /// \brief Constructor with reference to CArrayStorage object of non constant data
        /// and possibly different size and external memory setting.
        /// \details  template copy constructor that copies or attaches non-constant reference external identical data 
        ///  with non-constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the internal data storage.
        ///  These parameters will be passed to the base class constructor for data member initialization.
        /// \tparam    SIZE2      The size of CArrayStorage
        /// \tparam    EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                       of this class (false) or outside of this class (true).
        ///                       Default is false, meaning internal memory.
        /// \param[in] rhs        Reference to CArrayStorage object of SIZE2	
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CMatrix( CArrayStorage<type, SIZE2, EXT_MEM2>& rhs ) : super(rhs) {}

        /// \brief Constructor with reference to CArrayStorage object of constant data
        /// and possibly different size and external memory setting.
        /// \details  template copy constructor that copies or attaches non-constant reference external identical data 
        ///  with constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the internal data storage.
        ///  These parameters will be passed to the base class constructor for data member initialization.
        /// \tparam    SIZE2      The size of CArrayStorage
        /// \tparam    EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                       of this class (false) or outside of this class (true).
        ///                       Default is false, meaning internal memory.
        /// \param[in] rhs        Reference to CArrayStorage object of SIZE2 with constant data	
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CMatrix( CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs ) : super(rhs) {}

        // This is only required for TI-Compiler to be able to compile
        using super::operator[];
        using super::operator();
        using super::fill;
        // End of section required for TI-Compiler
        
        /// \brief assignment operator overloaded template function.
        /// \details This function takes constant reference to the object "rhs" with possibily different type and memory specialization as an argument.
        /// object "rhs" is passed as an argument to the base class assignment operator overloaded function.This function returns reference to the calling object.
        /// \tparam    TYPE2      The type of the matrix
        /// \tparam    EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                       of this class (false) or outside of this class (true).
        ///                       Default is false, meaning internal memory.
        /// \param[in] rhs        Constant reference to CMatrix object of size ROWS X COLS
        /// \return               A reference to the calling matrix. object.
        /// \testmethod
        /// \traceability
        template< typename TYPE2, boolean_t EXT_MEM2 >
        CMatrix& operator=(const CMatrix<TYPE2, ROWS, COLS, EXT_MEM2>& rhs)
        {
            super::operator=(rhs);
            return *this;
        }

        /// \brief Add the external CMatrix content to the buffer of the calling object.
        /// \details Perform matrix addition (inplace) of two matrices, calling object  and B
        /// with same dimensions and store the result in the calling  matrix object. 
        /// This function returns reference to the calling object.
        /// \InOutCorrelation  [this] += [B] \n
        ///                     "this" is the calling  matrix object and B is the "rhs" matrix whose elements will be added to the elements of the calling object.
        /// \tparam    TYPE2      The type of the matrix
        /// \tparam    EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                       of this class (false) or outside of this class (true).
        ///                       Default is false, meaning internal memory.
        /// \param[in] rhs        Constant reference to CMatrix object of size ROWS X COLS	
        /// \return               A reference to the calling  matrix object.
        /// \testmethod
        /// \traceability
        template< typename TYPE2, boolean_t EXT_MEM2 >
        CMatrix& operator+=(const CMatrix<TYPE2, ROWS, COLS, EXT_MEM2>& rhs)
        {
            for (sint32 i = 0; i < SIZE; ++i)
            {
                operator[](i) += rhs[i];
            }
            return *this;
        }

        /// \brief Add the external CMatrix content to the buffer of the calling matrix object without allocating result to the calling matrix object.
        /// \details Perform matrix addition (outplace) of two matrices, A and B with same dimensions and piossibily of different type and memory specialization.
        ///  It stores the result in a resultant matrix. Returns the resultant matrix.
        /// \InOutCorrelation  [Res] = [A] + [B] \n
        ///                    "A" is the calling matrix object and "B" is the rhs matrix of posibilly of different type "TYPE2" and memory specialization "EXT_MEM2".\n
        ///                    "Res" is a matrix similar to that of the calling matrix object.
        /// \tparam    TYPE2      The type of the matrix
        /// \tparam    EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                       of this class (false) or outside of this class (true).
        ///                       Default is false, meaning internal memory.
        /// \param[in] rhs        Constant reference to CMatrix object of size ROWS X COLS
        /// \return               A reference to the resultant matrix of size ROWS * COLS
        /// \testmethod
        /// \traceability
        template< typename TYPE2, boolean_t EXT_MEM2 >
        CMatrix<type, ROWS, COLS, false> operator+(const CMatrix<TYPE2, ROWS, COLS, EXT_MEM2>& rhs) const
        {
            return CMatrix<type, ROWS, COLS, false>(*this).operator+=(rhs);
        }

        /// \brief Subtract the external CMatrix content from the buffer of this.
        /// \details Perform matrix subtraction (inplace) of two matrices, calling object  and B
        /// with same dimensions and piossibily of different type(TYPE2) and memory specialization (EXT_MEM2).Result will be in the calling  matrix object. 
        /// This function returns reference to the calling object.
        /// \InOutCorrelation  [this] -= [B] \n
        ///                     "this" is the calling  matrix object and B is the "rhs" matrix whose elements will be substracted from the elements of the calling object.
        /// \tparam    TYPE2      The type of the matrix
        /// \tparam    EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                       of this class (false) or outside of this class (true).
        ///                       Default is false, meaning internal memory.
        /// \param[in] rhs        Constant reference to CMatrix object of size ROWS X COLS	
        /// \return               A reference to this matrix.
        /// \testmethod
        /// \traceability
        template< typename TYPE2, boolean_t EXT_MEM2 >
        CMatrix& operator-=(const CMatrix<TYPE2, ROWS, COLS, EXT_MEM2>& rhs)
        {
            for (sint32 i = 0; i < SIZE; ++i)
            {
                operator[](i) -= rhs[i];
            }
            return *this;
        }

        /// \brief Subtract the external CMatrix content from the buffer of this without allocating result to this.
        /// \details Perform matrix subtraction (outplace) of two matrices, A and B with same dimensions and piossibily of different type and memory specialization.
        ///  It stores the result in a resultant matrix and Returns the resultant matrix.
        /// \InOutCorrelation  [Res] = [A] - [B] \n
        ///                    "A" is the calling matrix object and "B" is the rhs matrix of posibilly of different type "TYPE2" and memory specialization "EXT_MEM2".\n
        ///                    "Res" is a matrix similar to that of the calling matrix object.
        /// \tparam    TYPE2      The type of the matrix
        /// \tparam    EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                       of this class (false) or outside of this class (true).
        ///                       Default is false, meaning internal memory.
        /// \param[in] rhs        Constant reference to CMatrix object of size ROWS X COLS
        /// \return               A reference to the resultant matrix of size ROWS * COLS
        /// \testmethod
        /// \traceability
        template< typename TYPE2, boolean_t EXT_MEM2 >
        CMatrix<type, ROWS, COLS,false> operator-(const CMatrix<TYPE2, ROWS, COLS, EXT_MEM2>& rhs) const
        {
            return CMatrix<type, ROWS, COLS, false>(*this).operator-=(rhs);
        }

        /// \brief Negate the matrix without allocating result to the calling object.
        /// \details Perform negation (outplace) of a matrix B and store the result in resultant matrix. Return the resultant matrix.
        /// \InOutCorrelation  [Res] = -[B] \n
        ///                    Sign of all the elements of matrix B is changed and copied to the "Res" matrix.
        /// \tparam    EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                       of this class (false) or outside of this class (true).
        ///                       Default is false, meaning internal memory.
        /// \return               A reference to the resultant matrix of size ROWS * COLS
        /// \testmethod
        /// \traceability
        //template< boolean_t EXT_MEM2 >
        CMatrix<type, ROWS, COLS,false> operator-() const
        {
            CMatrix<type, ROWS, COLS,false> result;
            for (sint32 i = 0; i < SIZE; ++i)
            {
                result[i] = -(operator[](i));
            }
            return result;
        }

        /// \brief Multiply the external CMatrix content to the buffer of the calling matrix.
        /// \details Perform matrix multiplication (inplace) of two matrices, calling matrix with dimentions (ROWS,COLS) and matrix B with dimentions (COLS,COLS2)
        /// and store the result in the calling matrix.Returns the reference to the calling matrix object.
        /// \InOutCorrelation [this] =[this] * [B] \n
        ///                   [this] is the calling matrix of size ROWS X COLS and "B" is the matrix of size COLS X COLS2.
        ///                    after multliplication result is saved in "this" matrix.
        /// \attention Matrix dimensions must be ROWS X COLS for calling matrix and COLS X COLS2 for "rhs" matrix.
        /// \tparam    TYPE2      The type of the matrix
        /// \tparam    EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                       of this class (false) or outside of this class (true).
        ///                       Default is false, meaning internal memory.
        /// \param[in] rhs        Constant reference to CMatrix object of size COLS X COLS	
        /// \return               A reference to the calling matrix.
        /// \testmethod
        /// \traceability
        template< typename TYPE2, boolean_t EXT_MEM2 >
        CMatrix& operator*= ( const CMatrix<TYPE2, COLS, COLS, EXT_MEM2>& rhs )
        {
            *this = (*this) * rhs;
            return *this;
        }

        /// \brief Multiply the external CMatrix content to the buffer of the calling CMatrix without allocating result to calling CMatrix.
        /// \details This function performs matrix multiplication (outplace)
///                   of two matrices A and B and store the result in a
///                   resultant matrix.
///                   \f[[Res]_{mXp} = [A]_{mXn}\ \times \ [B]_{nXp}\f]
///					  \f[ \begin{bmatrix}
///					  A_{00}	&	A_{01}  & A_{02}\\
///					  A_{10}	&	A_{11}  & A_{12}
///					  \end{bmatrix}
///				  \times
///					  \begin{bmatrix}
///					  B_{00}	&	B_{01}\\
///					  B_{10}	&	B_{11}\\
///					  B_{20}	&	B_{21}\\
///					  \end{bmatrix}
///				  =
///					  \begin{bmatrix}
///					  A_{00}*B_{00} + A_{01}*B_{10}+A_{02}*B_{20}	&&	A_{00}*B_{01} + A_{01}*B_{11}+A_{02}*B_{21}\\
///					  A_{10}*B_{00} + A_{11}*B_{10}+A_{12}*B_{20}	&&	A_{10}*B_{01} + A_{11}*B_{11}+A_{12}*B_{21}\\
///					  \end{bmatrix}
///                   \f]
        /// \attention dimentions of the matrices to be multiplied should be  ROWS X COLS and COLS X COLS2 respectively.
        /// \tparam    TYPE2      The type of the matrix
        /// \tparam    EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                       of this class (false) or outside of this class (true).
        ///                       Default is false, meaning internal memory.
        /// \param[in] rhs        Constant reference to CMatrix object of size COLS X COLS2	
        /// \return               A reference to the resultant matrix of size ROWS * COLS2
        /// \testmethod
        /// \traceability
        template< typename TYPE2, sint32 COLS2, boolean_t EXT_MEM2>
        CMatrix<type, ROWS, COLS2, false> operator* ( const CMatrix<TYPE2, COLS, COLS2, EXT_MEM2>& rhs ) const
        {
            CMatrix<type, ROWS, COLS2, false> result;

            size_type rc1 = 0;
            size_type rc2 = 0;

            for (size_type i = 0; i < ROWS; i++)
            {
                for (size_type j = 0; j < COLS2; j++)
                {
                    type resultElement = 0;
                    size_type nc2c = j;

                    for (size_type k = 0; k < COLS; k++)
                    {
                        resultElement += operator[](rc1 + k) * rhs[nc2c];

                        nc2c += COLS2;
                    }

                    result[rc2 + j] = resultElement;
                }
                rc2 += COLS2;
                rc1 += COLS;
            }

#ifdef C_COMPARISON_TEST
            /* C Implementation */
            CMatrix<type, ROWS, COLS2, false> result_CVersion;
            CML_t_Matrix resMatrixImpl = result_CVersion.getCMLMatrix();
            const CML_t_Matrix lhsMatrixImpl = getCMLMatrix();
            const CML_t_Matrix rhsMatrixImpl = rhs.getCMLMatrix();
            CML_v_MultiplyMatrices( &resMatrixImpl, &lhsMatrixImpl, &rhsMatrixImpl );

            /* Perform matrix comparison */
            assert( result.getAlmostEqualRelativeAndAbs(result_CVersion) );
#endif

            return result;
        }

        /// \brief scalar value multiplication with matrix.
        /// \details  Multiply all elements of the matrix (inplace) with the given scalar value.Return the reference to the calling matrix.
        /// \InOutCorrelation [this] = rhs * [this]\n
        ///                   [this] is the calling matrix and "rhs" is the scalar value.
        /// \param[in] rhs Scalar value to multiply.
        /// \return        A reference to the calling CMatrix.
        /// \testmethod
        /// \traceability
        self& operator*= (const_reference rhs)
        {
            for (sint32 i = 0; i < SIZE; ++i)
            {
                operator[](i) *= rhs;
            }
            return *this;
        }

        /// \brief scalar division of the matrix
        /// \details Divide all elements of the matrix (inplace) by a given scalar value.Returns the reference to the calling matrix.
        /// \InOutCorrelation [this] = [this] / rhs
        ///                   [this] is the calling matrix and "rhs" is the scalar value.
        /// \param[in] rhs Scalar value to devide.
        /// \return        A reference to calling CMatrix.
        /// \testmethod
        /// \traceability

        self& operator/= (const_reference rhs)
        {
            assert( CML_f_Abs(rhs) > std::numeric_limits<float32>::epsilon() );
            for (sint32 i = 0; i < SIZE; ++i)
            {
                operator[](i) /= rhs;
            }
            return *this;
        }

        
        /// \brief scalar value addition to the matrix elements.
        /// \details Add all elements of the matrix (inplace) by a given scalar value.Returns the reference to the calling matrix.
        /// \InOutCorrelation  [this] = rhs + [this] 
        ///                    [this] is the calling matrix and "rhs" is the scalar value.
        /// \param[in] rhs Scalar value to add.
        /// \return        A reference to the calling CMatrix.
        /// \testmethod
        /// \traceability
        self& operator+= (const_reference rhs)
        {
            for (sint32 i = 0; i < SIZE; ++i)
            {
                operator[](i) += rhs;
            }
            return *this;
        }

        
        /// \brief  scalar value substraction from matrix elements.
        /// \details Subtract all elements of the matrix (inplace) by a given scalar value.Returns the reference to the calling matrix. 
        /// \InOutCorrelation [this] = [this] - rhs 
        ///                   [this] is the calling matrix and "rhs" is the scalar value.
        /// \param[in] rhs Scalar value to subtract.
        /// \return        A reference to calling CMatrix.
        /// \testmethod
        /// \traceability
        self& operator-= (const_reference rhs)
        {
            for (sint32 i = 0; i < SIZE; ++i)
            {
                operator[](i) -= rhs;
            }
            return *this;
        }

        
        /// \brief  scalar value multiplication with matrix elements.
        /// \details Multiply all elements of the matrix (outplace) by a given scalar value. Returns the resultant matrix.
        /// \InOutCorrelation [Res] = rhs * [this]
        ///                   [this] is the calling matrix and "rhs" is the scalar value.\n
        ///                   [Res] is the resultant matrix to be returned.
        /// \param[in] rhs Scalar value to multiply.
        /// \return        A Matrix of same size and type, but with internal memory
        ///                having all elements multiplied by rhs.
        /// \testmethod
        /// \traceability
        self_internal operator* (const_reference rhs) const
        {
            return self_internal(*this).operator*=(rhs);
        }

        /// \brief Divide all elements of the matrix by a scalar.
        /// \details Divide all elements of the matrix (outplace) by a given scalar value.Returns the resultant matrix.
        /// \InOutCorrelation [Res] = [this] / rhs 
        ///                   [this] is the calling matrix and "rhs" is the scalar value.\n
        ///                   [Res] is the resultant matrix to be returned.
        /// \param[in] rhs Scalar value to devide.
        /// \return        A Matrix of same size and type, but with internal memory
        ///                having all elements divided by rhs.
        /// \testmethod
        /// \traceability
        self_internal operator/ (const_reference rhs) const
        {
            return self_internal(*this).operator/=(rhs);
        }

        /// \brief Add a scalar to all elements of the matrix.
        /// \details Add all elements of the matrix (outplace) by a given scalar value.Returns the resultant matrix. 
        /// \InOutCorrelation [Res] = rhs + [this]
        ///                   [this] is the calling matrix and "rhs" is the scalar value.\n
        ///                   [Res] is the resultant matrix to be returned.
        /// \param[in] rhs Scalar value to add.
        /// \return        A Matrix of same size and type, but with internal memory
        ///                having all elements added by rhs.
        /// \testmethod
        /// \traceability
        self_internal operator+ (const_reference rhs) const
        {
            return self_internal(*this).operator+=(rhs);
        }

        /// \brief Subtract a scalar from all elements of the matrix.
        /// \details Subtract all elements of the matrix (outplace) by a given scalar value.Returns the resultant matrix.
        /// \InOutCorrelation [Res] = [this] - rhs 
        ///                   [this] is the calling matrix and "rhs" is the scalar value.\n
        ///                   [Res] is the resultant matrix to be returned.
        /// \param[in] rhs Scalar value to subtract.
        /// \return        A Matrix of same size and type, but with internal memory
        ///                having all elements subtracted by rhs.
        /// \testmethod
        /// \traceability
        self_internal operator- (const_reference rhs) const
        {
            return self_internal(*this).operator-=(rhs);
        }

        /// \brief Create an identity matrix of size ROWS X COLS.
        /// \details  This function initializes the given matrix with an
        ///  identity matrix of the provided size.
        ///  \f[ \begin{bmatrix}
        ///			  M_{00}	&	M_{01}\\
        ///			  M_{10}	&	M_{11}
        ///			  \end{bmatrix}
        ///		  =
        ///			  \begin{bmatrix}
        ///			  1	&	0\\
        ///			  0	&	1
        ///			  \end{bmatrix}
        ///\f]
        /// \attention Input matrix should be a square matrix!
        /// \return        void
        /// \testmethod
        /// \traceability
        void setIdentity()
        {
            assert(ROWS == COLS);
            fill(0.0F);
            for ( size_type i = 0; i < ROWS; ++i )
            {
                operator()(i,i) = 1.0F;
            }
        }

        /// \brief Transpose of a matrix.
        /// \details This function calculates the transpose of a matrix
        ///   (outplace)
        ///   \f[A_{mXm} = 
        ///	  \begin{bmatrix}
        ///	  A_{00}	&	A_{01}  \\
        ///	  A_{10}	&	A_{11}  \\
        ///	  \end{bmatrix}
        ///	  \\then, 
        ///   [A^T]_{mXm} = 
        ///	  \begin{bmatrix}
        ///	  A_{00}	&	A_{10}  \\
        ///	  A_{01}	&	A_{11}  \\
        ///	  \end{bmatrix}
        ///	  \f]
        /// \return        A reference to the resultant matrix of size COLS X ROWS.
        /// \testmethod
        /// \traceability
        CMatrix<type, COLS, ROWS, false> transpose() const
        {
            CMatrix<type, COLS, ROWS> result;
            for ( size_type i = 0; i < ROWS; ++i )
            {
                for ( size_type j = 0; j < COLS; ++j )
                {
                    result(j,i) = operator()(i,j);
                }
            }
            return result;
        }
                
       /// \brief Matrix multiplication if the result is known to be a symmetric matrix
        /// \details Perform matrix multiplication (outplace) of two matrices A and B and 
        ///  store the result in a resultant matrix.This function calculates only the upper triangular elements in the resultant matrix and since it is symetric these values will be copied to lower triangular elements.
///                   [Res] = [A] x [B],
///                   [A] is of the order MxN,
///                   [B] is of the order NxM,
///                   \f[[Res]_{m\times m} = [A]_{m\times n}\ X\ [B]_{n\times m} \f]
///  \InOutCorrelation
///                    \f[\begin{bmatrix}
///                   A_{00}    &   A_{01}  & A_{02}\\
///                   A_{10}    &   A_{11}  & A_{12}\\
///                   A_{20}    &   A_{21}  & A_{22}
///                   \end{bmatrix}
///               \times
///                   \begin{bmatrix}
///                   B_{00}    &   B_{01}    &   B_{02}\\
///                   B_{10}    &   B_{11}    &   B_{12}\\
///                   B_{20}    &   B_{21}    &   B_{22}\\
///                   \end{bmatrix}
///               =
///                   \begin{bmatrix}
///                   A_{00}\times B_{00} + A_{01}\times B_{10}+A_{02}\times B_{20}   &&  A_{00}\times B_{01} + A_{01}\times B_{11}+A_{02}\times B_{21}   &&  A_{00}\times B_{02} + A_{01}\times B_{12}+A_{02}\times B_{22}\\
///                   A_{10}\times B_{00} + A_{11}\times B_{10}+A_{12}\times B_{20}   &&  A_{10}\times B_{01} + A_{11}\times B_{11}+A_{12}\times B_{21}   &&  A_{10}\times B_{02} + A_{11}\times B_{12}+A_{12}\times B_{22}\\
///                   A_{20}\times B_{00} + A_{21}\times B_{10}+A_{22}\times B_{20}   &&  A_{20}\times B_{01} + A_{21}\times B_{11}+A_{22}\times B_{21}   &&  A_{20}\times B_{02} + A_{21}\times B_{12}+A_{22}\times B_{22}\\
///                   \end{bmatrix} 
///                    \\
///                    \\ Since \ resultant \ matrix \ is \ symmetric:\\
///                    A_{00}\times B_{01} + A_{01}\times B_{11}+A_{02}\times B_{21} = A_{10}\times B_{00} + A_{11}\times B_{10}+A_{12}\times B_{20} \\
///                    A_{00}\times B_{02} + A_{01}\times B_{12}+A_{02}\times B_{22} = A_{20}\times B_{00} + A_{21}\times B_{10}+A_{22}\times B_{20} \\
///                    A_{10}\times B_{02} + A_{11}\times B_{12}+A_{12}\times B_{22} = A_{20}\times B_{01} + A_{21}\times B_{11}+A_{22}\times B_{21} 
///\f]
        /// \attention user must call this function only when he knows that the resultant matrix is  going to be symmetric and also ROWS and COLS2 should be same.
        /// \tparam    TYPE2      The type of the matrix
        /// \tparam    COLS2      Number of columns of the matrix
        /// \tparam    EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                       of this class (false) or outside of this class (true).
        ///                       Default is false, meaning internal memory.
        /// \param[in] rhs        Constant reference to CMatrix object of size ROWS X COLS2.
        /// \return               A reference to the resultant matrix of size ROWS X COLS2.
        /// \testmethod
        /// \traceability
        template<typename TYPE2, sint32 COLS2, boolean_t EXT_MEM2>
        CMatrix<type, ROWS, COLS2, false> mulSym ( const CMatrix<TYPE2, COLS, COLS2, EXT_MEM2>& rhs ) const
        {
            assert( ROWS == COLS2 );
            CMatrix<type, ROWS, COLS2, false> result;

            size_type rci     = 0;
            size_type rci_res = 0;

            /* Perform calculations over upper triangular of result matrix */
            for (size_type i = 0; i < ROWS; i++)
            {
                size_type rcj_res = i * COLS2;
                for (size_type j = i; j < COLS2; j++)
                {
                    size_type nc2c = j;

                    type resultElement = 0; /* Local instance to reduces unnecessary stores as common matrix types (e.g. float) are kept in register */
                    for (size_type k = 0; k < COLS; k++)
                    {
                        resultElement += operator[](rci + k) * rhs[nc2c];
                        nc2c += COLS2;
                    }
                    result[rci_res + j] = resultElement;
                    result[rcj_res + i] = resultElement; //redundant at the diagonal but should be faster on pipelined DSPs

                    rcj_res += COLS2;
                }
                rci     += COLS;
                rci_res += COLS2;
            }

#ifdef C_COMPARISON_TEST
            /* C implementation*/
            CMatrix<type, ROWS, COLS2, false> result_CVersion;
            CML_t_Matrix resMatrixImpl = result_CVersion.getCMLMatrix();
            const CML_t_Matrix lhsMatrixImpl = getCMLMatrix();
            const CML_t_Matrix rhsMatrixImpl = rhs.getCMLMatrix();
            CML_v_MultiplyMatricesToSymResult(&resMatrixImpl, &lhsMatrixImpl, &rhsMatrixImpl);

            /* Perform matrix comparison */
            assert( result.getAlmostEqualRelativeAndAbs(result_CVersion) );
#endif

            return result;
        }

        /// \brief Matrix multiplication with transpose.
        /// \details This function performs matrix multiplication (outplace)
        ///        of matrix A with transpose of matrix B and store the
        ///        result in a resultant matrix.
        ///        [Res] = [A] X [B]'\n
        ///        \f[[Res]_{mXk} = [A]_{mXn}\ \times \ [B']_{nXk} 
        ///		   \begin{bmatrix}
        ///		  A_{00}	&	A_{01}  & A_{02}\\
        ///		  A_{10}	&	A_{11}  & A_{12}
        ///		  \end{bmatrix}
        ///	  \times
        ///		  \begin{bmatrix}
        ///		  B_{00}	&	B_{01}\\
        ///		  B_{10}	&	B_{11}\\
        ///		  B_{20}	&	B_{21}\\
        ///		  \end{bmatrix}
        ///	  =
        ///		  \begin{bmatrix}
        ///		  A_{00}\times B_{00} + A_{01}\times B_{10}+A_{02}\times B_{20}	&&	A_{00}\times B_{01} + A_{01}\times B_{11}+A_{02}\times B_{21}\\
        ///		  A_{10}\times B_{00} + A_{11}\times B_{10}+A_{12}\times B_{20}	&&	A_{10}\times B_{01} + A_{11}\times B_{11}+A_{12}\times B_{21}\\
        ///		  \end{bmatrix}
        ///\f]
        /// \tparam    TYPE2      The type of the matrix
        /// \tparam    ROWS2      Number of rows of the matrix
        /// \tparam    EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                       of this class (false) or outside of this class (true).
        ///                       Default is false, meaning internal memory.
        /// \param[in] rhs        Constant reference to CMatrix object of size ROWS2 X COLS	
        /// \return               A reference to the resultant matrix of size ROWS X ROWS2.
        /// \testmethod
        /// \traceability
        template<typename TYPE2, sint32 ROWS2, boolean_t EXT_MEM2>
        CMatrix<type, ROWS, ROWS2, false> mulTrnsp( const CMatrix<TYPE2, ROWS2, COLS, EXT_MEM2>& rhs ) const
        {
            CMatrix<type, ROWS, ROWS2, false> result;

            size_type rc_res = 0;
            size_type rc1    = 0;

            for (size_type i = 0; i < ROWS; i++)
            {
                size_type rc2 = 0;

                for (size_type j = 0; j < ROWS2; j++)
                {
                    type resultElement = 0; /* Local instance to reduces unnecessary stores as common matrix types (e.g. float) are kept in register */

                    for (size_type k = 0; k < COLS; k++)
                    {
                        resultElement += operator[](rc1 + k) * rhs[rc2 + k];
                    }

                    result[rc_res + j] = resultElement;

                    rc2 += COLS;
                }
                rc1    += COLS;
                rc_res += ROWS2;
            }

#ifdef C_COMPARISON_TEST
            /* C Implementation */
            CMatrix<type, ROWS, ROWS2, false> result_CVersion;
            CML_t_Matrix resMatrixImpl = result_CVersion.getCMLMatrix();
            const CML_t_Matrix lhsMatrixImpl = getCMLMatrix();
            const CML_t_Matrix rhsMatrixImpl = rhs.getCMLMatrix();
            CML_v_MultiplyMatrixWithTranspose( &resMatrixImpl, &lhsMatrixImpl, &rhsMatrixImpl );

            /* Perform matrix comparison */
            assert( result.getAlmostEqualRelativeAndAbs(result_CVersion) );
#endif

            return result;
        }


        /// \brief Transpose matrix before multiplication with rhs (outplace).
        /// \details This function performs matrix multiplication (outplace)
        ///  of transpose of matrix A with  matrix B and store the result in a resultant matrix.
        ///   [Res] = [A]' \times [B]
        ///      \f[[Res]_{mXk} = [A']_{mXn}\ \times \ [B]_{nXk} 
        ///	   \begin{bmatrix}
        ///	  A_{00}	&	A_{01}  & A_{02}\\
        ///	  A_{10}	&	A_{11}  & A_{12}
        ///	  \end{bmatrix}
        ///	 \times
        ///	  \begin{bmatrix}
        ///	  B_{00}	&	B_{01}\\
        ///	  B_{10}	&	B_{11}\\
        ///	  B_{20}	&	B_{21}\\
        ///	  \end{bmatrix}
        ///	 =
        ///	  \begin{bmatrix}
        ///	  A_{00}\times B_{00} + A_{01}\times B_{10}+A_{02}\times B_{20}	&&	A_{00}\times B_{01} + A_{01}\times B_{11}+A_{02}\times B_{21}\\
        ///	  A_{10}\times B_{00} + A_{11}\times B_{10}+A_{12}\times B_{20}	&&	A_{10}\times B_{01} + A_{11}\times B_{11}+A_{12}\times B_{21}\\
        ///	  \end{bmatrix}
        ///\f]
        /// \tparam    TYPE2      The type of the matrix
        /// \tparam    COLS2      Number of columns of the matrix
        /// \tparam    EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                       of this class (false) or outside of this class (true).
        ///                       Default is false, meaning internal memory.
        /// \param[in] rhs        Constant reference to CMatrix object of size ROWS X COLS2.
        /// \return               A reference to the resultant matrix of size COLS X COLS2.
        /// \testmethod
        /// \traceability
        template<typename TYPE2, sint32 COLS2, boolean_t EXT_MEM2>
        CMatrix<type, COLS, COLS2, false> trnspMul( const CMatrix<TYPE2, ROWS, COLS2, EXT_MEM2>& rhs ) const
        {
            CMatrix<type, COLS, COLS2, false> result;

            size_type rc_res = 0;

            for (size_type i = 0; i < COLS; i++)
            {
                for (size_type j = 0; j < COLS2; j++)
                {
                    type resultElement = 0;  /* Local instance to reduces unnecessary stores as common matrix types (e.g. float) are kept in register */

                    size_type nc1c = i;
                    size_type nc2c = j;

                    for (size_type k = 0; k < ROWS; k++)
                    {
                        resultElement += operator[](nc1c) * rhs[nc2c];
                        nc1c += COLS;
                        nc2c += COLS2;
                    }

                    result[rc_res + j] = resultElement;
                }
                rc_res += COLS2;
            }

#ifdef C_COMPARISON_TEST
            /* C Implementation */
            CMatrix<type, COLS, COLS2, false> result_CVersion;
            CMatrix<type, COLS, ROWS, false>  lhsTranspose_CVersion;
            CML_t_Matrix resMatrixImpl = result_CVersion.getCMLMatrix();
            CML_t_Matrix lhsTransposeMatrixImpl = lhsTranspose_CVersion.getCMLMatrix();
            const CML_t_Matrix lhsMatrixImpl = getCMLMatrix();
            const CML_t_Matrix rhsMatrixImpl = rhs.getCMLMatrix();
            CML_v_TransposeMatrix(&lhsTransposeMatrixImpl, &lhsMatrixImpl);
            CML_v_MultiplyMatrices( &resMatrixImpl, &lhsTransposeMatrixImpl, &rhsMatrixImpl );

            /* Perform matrix comparison */
            assert( result.getAlmostEqualRelativeAndAbs(result_CVersion) );
#endif

            return result;
        }

        /// \brief Implements inverse of a matrix.
        /// \details Compute matrix inverse: Res = inv(A) \n
        /// Uses Gauss-Jordan elimination with partial pivoting.
        /// finds largest element on the selected column and used as pivot element.
        /// If the selected pivot element is less than the tolerance value (1e-10F) ,then this matrix is not invertible.
        /// For matrices upto 3x3, determinant is found, singularity is
        /// checked and processing is done, whereas for higher order
        /// matrices, matrix singularity is determined during the processing. 
        /// Struct needed, because partial specialization of functions is not allowed!
        /// \tparam     TYPE2      The type of the matrix
        /// \tparam     ROWS2      Number of rows of the matrix
        /// \tparam     COLS2      Number of columns of the matrix
        /// \tparam     EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                        of this class (false) or outside of this class (true).
        ///                        Default is false, meaning internal memory.
        /// \param[in]  inp        Constant reference to input CMatrix object of size ROWS2 X COLS2	
        /// \param[out] res        Reference to resultant CMatrix object of size ROWS2 X COLS2	
        /// \return                True if  matrix is invertible else False.
        /// \testmethod
        /// \traceability
        template <typename TYPE2, sint32 ROWS2, sint32 COLS2, boolean_t EXT_MEM2>
        struct SInvert
        {
            static inline boolean_t invert(CMatrix<TYPE2, ROWS2, COLS2, false>& res, const CMatrix<TYPE2, ROWS2, COLS2, EXT_MEM2>& inp)
            {
                static const float32 fTol = 1e-10F;  /* tolerance */
                boolean_t bRet = true;
                TYPE2 fPivElem = static_cast<TYPE2>(1.0F);
                CMatrix<TYPE2, ROWS2, COLS2, false> A(inp);

                /* Gauss-Jordan elimination with partial pivoting */
                size_type col = 0;
                res.setIdentity();

                do
                {
                    /* find largest element on the selected column */
                    /* and use as pivot element                    */
                    size_type row = col;
                    size_type pos1 = col + (col * COLS2);
                    size_type pos2;

                    TYPE2 MaxElem = 0;
                    TYPE2 Temp;

                    for (size_type i = col; i < COLS2; i++)
                    {
                        Temp = CML_f_Abs(A[pos1]);
                        if (Temp > MaxElem)
                        {
                            MaxElem = Temp;
                            fPivElem = static_cast<float32>(A[pos1]);
                            row = i;
                        }
                        pos1 += COLS2;
                    }

                    /* exit routine if pivot element is very small => matrix not inversible */
                    if (MaxElem >= fTol)
                    {
                        bRet = true;
                    }
                    else
                    {
                        bRet = false;
                    }

                    /* do pivoting to reduce column to identity matrix */
                    if (bRet)
                    {
                        /* now swap rows to put the pivot element on the diagonal */
                        /* do the same operation for the result matrix */
                        if (row != col)
                        {
                            /* get pointer to matrix data */
                            pos1 = row * COLS2;
                            pos2 = col * COLS2;

                            for (size_type i = col; i < COLS2; i++)  /* only nonzero elements */
                            {
                                Temp = A[i + pos1];
                                A[i + pos1] = A[i + pos2];
                                A[i + pos2] = Temp;
                            }
                            for (size_type i = 0; i < COLS2; i++)    /* all elements */
                            {
                                Temp = res[i + pos1];
                                res[i + pos1] = res[i + pos2];
                                res[i + pos2] = Temp;
                            }
                        }

                        /* divide row by the pivot element => pivot becomes 1 */
                        /* do the same operation for the result matrix */
                        pos1 = col*COLS2;
                        const float32 fInvPivElem = 1.0F/fPivElem;
                        for (size_type i = col; i < COLS2; i++)  /* only nonzero elements */
                        {
                            A[i+pos1] *= fInvPivElem;
                        }
                        for (size_type i = 0; i < COLS2; i++)  /* all elements */
                        {
                            res[i+pos1] *= fInvPivElem;
                        }

                        /* now multiply the row by the right amount and substract from    */
                        /* each other row to make all the remaining elements in the pivot */
                        /* column zero                                                    */
                        for (size_type i = 0; i < COLS2; i++)   /* loop other rows */
                        {
                            if (i != col)
                            {
                                pos1  = i  * COLS2;
                                pos2  = col* COLS2;

                                /* use first element is row as scaling coefficient */
                                Temp = A[col + pos1];

                                /* subtract pivot row multiplied by scaling from other row */
                                /* do the same operation for the result matrix */
                                for (size_type j = col; j < COLS2; j++)  /* only nonzero elements */
                                {
                                    A[j + pos1] -= A[j + pos2] * Temp;
                                }
                                for (size_type j = 0; j  < COLS2; j++)  /* all elements */
                                {
                                    res[j + pos1] -= res[j + pos2] * Temp;
                                }
                            }
                        }

                        /* goto next column */
                        col++;
                    }
                } while ( bRet && (col < COLS2));  /* quit if finished or if matrix isn't invertible */

                return bRet;
            }
        };

        /// \brief Implements inverse of a matrix with specialized version for matrix of size 1 X 1.
        /// \details matrix size 1 X 1 means it is a single element matrix.When this element is not zero then invert of that element is the invert that matrix.
        /// This function returns True if matrix is invertible else False.
        /// \tparam     TYPE2      The type of the matrix
        /// \tparam     EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                        of this class (false) or outside of this class (true).
        ///                        Default is false, meaning internal memory.
        /// \param[in]  inp        Constant reference to input CMatrix object of size 1 X 1
        /// \param[out] res        Reference to resultant CMatrix object of size 1 X 1
        /// \return                True if matrix is invertible else False.
        /// \testmethod
        /// \traceability
        template <typename TYPE2, boolean_t EXT_MEM2>
        struct SInvert<TYPE2, 1, 1, EXT_MEM2>
        {
            static inline boolean_t invert(CMatrix<TYPE2, 1, 1, false>& res, const CMatrix<TYPE2, 1, 1, EXT_MEM2>& inp)
            {
                boolean_t retVal = false;
                if( CML_f_IsNonZero(inp[0]) )
                {
                    res[0] = 1.0F / (inp[0]); /*Use cct::invert here (apply changes to C-Version) */
                    retVal = true;
                }
                return retVal;
            }
        };

        /// \brief Implements inverse of a matrix with specialized version for matrix of size 2 X 2.
        /// \details This function implements inverse of the matrix "inp" and the resultant matrix is saved in "res" matrix.
        ///  This function returns true if matrix is invertible else false.
        /// \tparam     TYPE2      The type of the matrix
        /// \tparam     EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                        of this class (false) or outside of this class (true).
        ///                        Default is false, meaning internal memory.
        /// \param[in]  inp        Constant reference to input CMatrix object of size 2 X 2.
        /// \param[out] res        Reference to resultant CMatrix object of size 2 X 2.
        /// \return                True if matrix is invertible else False.
        /// \testmethod
        /// \traceability
        template <typename TYPE2, boolean_t EXT_MEM2>
        struct SInvert<TYPE2, 2, 2, EXT_MEM2>
        {
            static inline boolean_t invert(CMatrix<TYPE2, 2, 2, false>& res, const CMatrix<TYPE2, 2, 2, EXT_MEM2>& inp)
            {
                boolean_t retVal = false;
                /* Local variable for determinant as common matrix types (e.g. float) are kept in register */
                TYPE2 Temp = (inp[0]*inp[3]) - (inp[1]*inp[2]);

                if(CML_f_IsNonZero(Temp))
                {
                    Temp = 1.0F / Temp; /*Use cct::invert here (apply changes to C-Version) */
                    res[0] =  inp[3] * Temp;
                    res[1] = -inp[1] * Temp;
                    res[2] = -inp[2] * Temp;
                    res[3] =  inp[0] * Temp;
                    retVal = true;
                }
                return retVal;
            }
        };

        /// \brief Implements inverse of a matrix with specialized version for matrix of size 3 X 3.
        /// \details This function implements inverse of the matrix "inp" and the resultant matrix is saved in "res" matrix.
        ///  This function returns true if matrix is invertible else false.
        /// \tparam     TYPE2      The type of the matrix
        /// \tparam     EXT_MEM2   Flag whether the memory of the elements of the matrix is inside
        ///                        of this class (false) or outside of this class (true).
        ///                        Default is false, meaning internal memory.
        /// \param[in]  inp        Constant reference to input CMatrix object of size 3 X 3.
        /// \param[out] res        Reference to resultant CMatrix object of size 3 X 3.
        /// \return                True if  matrix is invertible else False.
        /// \testmethod
        /// \traceability
        template <typename TYPE2, boolean_t EXT_MEM2>
        struct SInvert<TYPE2, 3, 3, EXT_MEM2>
        {
            static inline boolean_t invert(CMatrix<TYPE2, 3, 3, false>& res, const CMatrix<TYPE2, 3, 3, EXT_MEM2>& inp)
            {
                boolean_t retVal = false;

                /* Cramers Rule for matrix size == 3 */
                TYPE2 Temp = (( (inp[0]*inp[4]) - (inp[3]*inp[1]) )*inp[8]) + (( (inp[3]*inp[7]) - (inp[6]*inp[4]) )*inp[2]) + (( (inp[6]*inp[1]) - (inp[0]*inp[7]) )*inp[5]);

                if(CML_f_IsNonZero(Temp))
                {
                    Temp = 1.0F / Temp; /*Use cct::invert here (apply changes to C-Version) */
                    res[0] = ( (inp[4]*inp[8]) - (inp[5]*inp[7]) ) * Temp;
                    res[1] = ( (inp[2]*inp[7]) - (inp[1]*inp[8]) ) * Temp;
                    res[2] = ( (inp[1]*inp[5]) - (inp[2]*inp[4]) ) * Temp;
                    res[3] = ( (inp[5]*inp[6]) - (inp[3]*inp[8]) ) * Temp;
                    res[4] = ( (inp[0]*inp[8]) - (inp[2]*inp[6]) ) * Temp;
                    res[5] = ( (inp[2]*inp[3]) - (inp[0]*inp[5]) ) * Temp;
                    res[6] = ( (inp[3]*inp[7]) - (inp[4]*inp[6]) ) * Temp;
                    res[7] = ( (inp[1]*inp[6]) - (inp[0]*inp[7]) ) * Temp;
                    res[8] = ( (inp[0]*inp[4]) - (inp[1]*inp[3]) ) * Temp;
                    retVal = true;
                }
                return retVal;
            }
        };
        /// \brief  Compute matrix inverse.
        /// \details Compute matrix inverse by calling different variants of matrix inverse
        /// implemenatations accoridng to input matrix dimensions.This function finds the inverse of the calling matrix and saves in the "result" matrix and this resultant matrix will be returned.
        /// \attention  COLS and ROWS of the calling matrix should be same.
        /// \return    A reference to resultant matrix of size COLS X ROWS.
        /// \testmethod
        /// \traceability
        CMatrix<type, COLS, ROWS, false> invert() const
        {
            assert( ROWS == COLS );
            CMatrix<type, COLS, ROWS, false> result;
            if (!SInvert<type, ROWS, COLS, EXT_MEM>::invert(result, *this))
            {
                // Inversion should never fail.
                assert(false);
            }

#ifdef C_COMPARISON_TEST
            CMatrix<type, COLS, ROWS, false> result_CVersion;
            CMatrix<type, COLS, ROWS, false> cache_CVersion(*this);
            CML_t_Matrix resMatrixImpl   = result_CVersion.getCMLMatrix();
            CML_t_Matrix cacheMatrixImpl = cache_CVersion.getCMLMatrix();
            CML_v_InvertMatrix( &resMatrixImpl, &cacheMatrixImpl );
            /* Perform matrix comparison */
            assert( result.getAlmostEqualRelativeAndAbs(result_CVersion) );
#endif

            return result;
        }
        /// \brief Compute matrix inverse.
        /// \details This function takes "result" which is reference to the CMatrix as an argument and Compute matrix inverse by calling different variants of matrix inverse
        /// implemenatations according to input matrix dimensions.This function returns True if  matrix is invertible else False.
        /// \attention Matrix must be a square matrix.
        /// \param[in]  result     Reference to resultant matrix of size COLS X ROWS.
        /// \return                Return True if  matrix is invertible else False.
        /// \testmethod
        /// \traceability
        boolean_t invert(CMatrix<type, COLS, ROWS, false>& result) const
        {
            assert( ROWS == COLS );

            const boolean_t canInvert = SInvert<type, ROWS, COLS, EXT_MEM>::invert(result, *this);
#ifdef C_COMPARISON_TEST
            if (canInvert)
            {
                CMatrix<type, COLS, ROWS, false> result_CVersion;
                CMatrix<type, COLS, ROWS, false> cache_CVersion(*this);
                CML_t_Matrix resMatrixImpl   = result_CVersion.getCMLMatrix();
                CML_t_Matrix cacheMatrixImpl = cache_CVersion.getCMLMatrix();
                CML_v_InvertMatrix( &resMatrixImpl, &cacheMatrixImpl );
                /* Perform matrix comparison */
                assert( result.getAlmostEqualRelativeAndAbs(result_CVersion) );
            }
#endif

            return canInvert;
        }

        /// \brief Compute Cholesky factor of a positive definite hermitian matrix.
        /// \details The Cholesky factorization is decomposing the hermitian
        ///      positive definite matrix (A) into product of a lower triangular
        ///      matrix (L) and its conjugare transpose (L*).
        ///      A = LL*
        ///      This function returns this lower triangular square root of
        ///      the positive definite real symmetric matrix, no exception
        ///      handling for any kind of rank deficiency rather direct
        ///      regularization
        ///      (associated m-file for unit testing: slow_chol2.m)
        ///      \f[[A]_{mXm} = [L]_{mXm} \times [L^T]_{mXm} \\
        ///	  \begin{bmatrix}
        ///	  A_{00}	&	A_{01} 	&	A_{02} \\
        ///	  A_{10}	&	A_{11} 	&	A_{12} \\
        ///	  A_{20}	&	A_{21} 	&	A_{22} 
        ///	  \end{bmatrix}
        ///	  =
        ///	  \begin{bmatrix}
        ///	  L_{11}	&	L_{21}		&	L_{31}\\
        ///	  0			&	L_{22}		&	L_{32}\\
        ///	  0			&	0			&	L_{33}
        ///	  \end{bmatrix}
        ///      \times
        ///	  \begin{bmatrix}
        ///	  L_{11}	&	0			&	0\\
        ///	  L_{21}	&	L_{22}		&	0\\
        ///	  L_{31}	&	L_{32}		&	L_{33}\\
        ///	  \end{bmatrix}\f]
        ///  \InOutCorrelation
        ///   Following formula is used for entries of L:
        ///   \f[ L_{j,j} = \sqrt{A_{j,j} - \sum_{k=1}^{j-1}{L_{j,k}}^2}\f]  
        ///   \f[ L_{i,j} = \frac{A_{i,j} - \sum_{k=1}^{j-1}L_{i,k}L_{j,k}}{L_{j,j}}, for\ i>j.\f]
        /// \attention Calling matrix must be a square matrix.
        /// \return                A reference to resultant matrix of size COLS X ROWS.
        /// \testmethod
        /// \traceability
        CMatrix<type, COLS, ROWS, false> getCholesky() const
        {
            assert( ROWS == COLS );
            static const float32 fTol = 1e-10F;

            size_type rci = 0;

            /* Copy to result matrix */
            CMatrix<type, COLS, ROWS, false> result(*this);


            /* Add pseudo regularization */
            for ( size_type i = 0; i < ROWS; i++)
            {
                if (result[rci + i] < fTol) // should never happen for p.d. input matrix
                {
                    result[rci + i]  = fTol; // just "brutal" pseudo regularization good for KAFI
                }
                rci += COLS;
            }

            /* Cholesky decomposition with Cholesky–Banachiewicz algorithm */
            rci = 0;

            for ( size_type i = 0; i < ROWS; i++)
            {
                size_type rcj = 0;

                /* Calculate elements in row not on diagonal */
                for ( size_type j = 0; j < i; j++)
                {
                    type resultElement = result[rci + j]; /* Local instance to reduces unnecessary stores as common matrix types (e.g. float) are kept in register */

                    for ( size_type k = 0; k < j; k++)
                    {
                        resultElement -= result[rci + k] * result[rcj + k];
                    }

                    resultElement /= result[rcj + j]; /*Speedup: use cct::invert here (also adapt C-Version of Cholesky) */
                    result[rci + j] = resultElement;
                    result[rcj + i] = 0; /* set upper triangular part to zero */
                    rcj += COLS;
                }

                /* Calculate diagonal element */
                {
                    type resultElement = result[rci + i]; /* Local instance to reduces unnecessary stores as common matrix types (e.g. float) are kept in register */

                    for ( size_type k = 0; k < i; k++)
                    {
                        resultElement -= cml::pow<2>(result[k + rci]);
                    }

                    /* Check for tolerance */
                    if ( resultElement > fTol)
                    {
                        result[rci + i] = CML_f_Sqrt(resultElement) /* Probably inline version of sqrt */;
                    }
                    else
                    { // this should never happen for p.d. input matrix
                        result[rci + i] = fTol; // it is caused by rank-deficient input matrix
                    }
                }

                rci += COLS;
            }

#ifdef C_COMPARISON_TEST
            /* C Implementation */
            CMatrix<type, COLS, ROWS, false> result_CVersion;
            CML_t_Matrix cacheMatrixImpl = getCMLMatrix();
            CML_t_Matrix resMatrixImpl   = result_CVersion.getCMLMatrix();
            CML_v_CholeskyMatrix( &resMatrixImpl, &cacheMatrixImpl );
            /* Perform matrix comparison */
            assert( result.getAlmostEqualRelativeAndAbs(result_CVersion) );
#endif

            return result;
        }

        /// \brief Inverse of positive definite lower triangular matrix  by forward substitution.
        /// \details Compute matrix inverseThe method of choice for inversion of positive definite symmetric matrices
        /// consists of Cholesky factorization followed by forward substitution
        /// which is efficiently implemented in this function. No exception
        /// handling in case of indefinite input rather brute force regularization
        /// which is appropriate for square-root Kalman filter applications
        /// but does a poor job in approximating the Pseudo-Inverse for least-squares
        /// \return                A reference to resultant matrix of size COLS X ROWS.
        /// \testmethod
        /// \traceability
        CMatrix<type, COLS, ROWS, false> getLowTriaInverse() const
        {
            assert( ROWS == COLS );
            static const float32 fTol = 1e-10F;
            CMatrix<type, COLS, ROWS, false> result;


            /* Vector for storing pre-calculated divisions */
            CMatrix<type, COLS, 1, false> diag;

            size_type rcj = 0;

            for (size_type j = 0; j < COLS; j++)
            {
                if (operator[](rcj + j) < fTol)
                {
                    diag[j] = 1.0F/fTol; // regularization
                }
                else
                {
                    diag[j] = 1.0F/operator[](rcj + j);  //precalc divisions, probably use cct::inverse here (adapt in C-Version too!)
                }

                for (size_type i = j; i < COLS; i++)
                {
                    result[rcj + i] = 0.0F;
                }

                rcj += COLS;
            }

            for (size_type j = 0; j < COLS; j++)
            {
                size_type rci = j * COLS;
                for (size_type i = j; i < ROWS; i++)
                {
                    type resultElement = 0.0F;

                    for (size_type k = 0; k < i; k++)
                    {
                        resultElement += operator[](rci + k) * result[(k * COLS) + j]; //k<i -> does not use elements on diagonal
                    }
                    if (i == j)
                    {
                        result[rci + j] = diag[i] * (1.0F - resultElement);
                    }
                    else
                    {
                        result[rci + j] = diag[i] * (-resultElement);
                    }

                    rci += COLS;
                }
            }

#ifdef C_COMPARISON_TEST
            /* C Implementation */
            CMatrix<type, COLS, ROWS, false> result_CVersion;
            const CML_t_Matrix cacheMatrixImpl = getCMLMatrix();
            CML_t_Matrix resMatrixImpl   = result_CVersion.getCMLMatrix();
            CML_v_LowTriaInvMatrix( &resMatrixImpl, &cacheMatrixImpl ); /*Changes cacheMatrix -> !!Changes member variable!! */
            /* Perform matrix comparison */
            assert( result.getAlmostEqualRelativeAndAbs(result_CVersion) );
#endif

            return result;
        }

        /// \brief Computes the product of the lower traingular matrix and its transpose.
        /// \details Inversion of Cholesky Res = A*transpose(A), with A lower triangular.
        /// The method of choice for squaring of positive definite
        /// symmetric matrices is from Cholesky method. This function computes the product of the lower traingular matrix and its transpose.
        /// This function returns the reference to resultant matrix of size COLS X ROWS. 
        /// \attention matrix must be a square matrix
        /// \return                A reference to resultant matrix of size COLS X ROWS.
        /// \testmethod
        /// \traceability
        CMatrix<type, COLS, ROWS, false> getLowTriaSqr() const
        {
            assert( ROWS == COLS );
            CMatrix<type, COLS, ROWS, false> result;

            size_type rci = 0;

            for (size_type i = 0; i < ROWS; i++)
            {
                size_type rcj = 0;
                for (size_type j = 0; j <= i; j++)
                {
                    type resultElement = 0.0F; /* Local instance to reduces unnecessary stores as common matrix types (e.g. float) are kept in register */
                    for (size_type k = 0; k <= j; k++)
                    {
                        resultElement += operator[](rci + k) * operator[](rcj + k);
                    }
                    result[rcj + i] = resultElement;
                    result[rci + j] = resultElement;  //redundant at the diagonal but should be faster on pipelined DSPs

                    rcj += COLS;
                }
                rci += COLS;
            }

#ifdef C_COMPARISON_TEST
            /* C Implementation */
            CMatrix<type, COLS, ROWS, false> result_CVersion;
            const CML_t_Matrix cacheMatrixImpl = getCMLMatrix();
            CML_t_Matrix       resMatrixImpl   = result_CVersion.getCMLMatrix();
            CML_v_LowTriaSqrMatrix( &resMatrixImpl, &cacheMatrixImpl );
            /* Perform matrix comparison */
            assert( result.getAlmostEqualRelativeAndAbs(result_CVersion) );
#endif

            return result;
        }

        /// \brief Computes the product of the upper traingular matrix and its transpose.
        /// \details Res = A*transpose(A), with A as upper triangular.This function returns the reference to resultant matrix of size COLS X ROWS.
        /// \return                A reference to resultant matrix of size COLS X ROWS.
        /// \testmethod
        /// \traceability
        CMatrix<type, COLS, ROWS, false> getUppTriaSqr() const
        {
            assert( ROWS == COLS );
            CMatrix<type, COLS, ROWS, false> result;

            size_type rci = 0;

            for (size_type i = 0; i < ROWS; i++)
            {
                size_type rcj = 0;
                for (size_type j = 0; j <= i; j++)  // <lint left brace
                {
                    type resultElement = 0.0F; /* Local instance to reduces unnecessary stores as common matrix types (e.g. float) are kept in register */
                    for (size_type k = i; k < COLS; k++)
                    {
                        resultElement += operator[](rci + k) * operator[](rcj + k);
                    }
                    result[rcj + i] = resultElement;
                    result[rci + j] = resultElement;  //redundant at the diagonal but should be faster on pipelined DSPs

                    rcj += COLS;
                }
                rci += COLS;
            }

#ifdef C_COMPARISON_TEST
            /* C Implementation */
            CMatrix<type, COLS, ROWS, false> result_CVersion;
            const CML_t_Matrix cacheMatrixImpl = getCMLMatrix();
            CML_t_Matrix       resMatrixImpl   = result_CVersion.getCMLMatrix();
            CML_v_UppTriaSqrMatrix( &resMatrixImpl, &cacheMatrixImpl );
            /* Perform matrix comparison */
            assert( result.getAlmostEqualRelativeAndAbs(result_CVersion) );
#endif

            return result;
        }

#ifdef C_COMPARISON_TEST
        /// \brief Write to a const matrix.
        /// \attention be careful:getCMLMatrix() enables you to write to a const matrix	
        /// \return                Reference to the resultant matrix.
        /// \testmethod
        /// \traceability
        CML_t_Matrix getCMLMatrix() const
        {
            CML_t_Matrix ret = {{COLS, ROWS, static_cast<uint16>(SIZE)}, const_cast<pointer>(&operator[](0))};
            return ret;
        }
#endif

#if defined(C_COMPARISON_TEST) || defined(CML_TEST)
        /// \brief Checks if two matrices are equal up to a certain precision
        /// \details This function calls the function getElementsAlmostEqualRelativeAndAbs() with each element in the two matrices as arguments where the equalency of two float numbers will be calculated.
        /// This function Returns True if  matrices are equal else False.
        /// \param[in]  rhs        Constant reference to matrix of identical size
        /// \return                Return True if  matrices are equal else False.
        /// \testmethod
        /// \traceability
        boolean_t getAlmostEqualRelativeAndAbs( const self& rhs ) const
        {
            boolean_t result = true;
            size_type rci = 0;

            for (size_type i = 0; i < ROWS; i++)
            {
                for (size_type j = 0; j < COLS; j++)
                {
                    if( !getElementsAlmostEqualRelativeAndAbs( operator[](rci+j), rhs[rci+j]) )
                    {
                        result = false;
                    }
                }
                rci += COLS;
            }

            return result;
        }
#endif

    private:
#if defined(C_COMPARISON_TEST) || defined(CML_TEST)
        /// \brief Checks if two floating point numbers are almost equal
        /// \details The functions performs an absolute and relative comparison of the
        /// floating point numbers. The numbers are regarded equal if their
        /// abs difference is smaller than 10*FLT_MIN (required for numbers
        /// close to zero) or if their relative difference is smaller than 5 * FLT_EPSILON
        /// This function returns True if  values are equal else False.
        /// \param[in]  A    Constant reference to value A	
        /// \param[in]  B    Constant reference to value B
        /// \return          Return True if  values are equal else False.
        /// \testmethod
        /// \traceability
        static boolean_t getElementsAlmostEqualRelativeAndAbs(const_reference A, const_reference B)
        {
            boolean_t ret = false;

            // Check if the numbers are really close -- needed
            // when comparing numbers near zero.
            const_type diff = CML_f_Abs(A - B);

            ret = diff <= (std::numeric_limits<float32>::min()*10);

            if ( !ret )
            {
                const_type absA    = CML_f_Abs(A);
                const_type absB    = CML_f_Abs(B);
                const_type largest = cml::max(absA, absB);

                ret = diff <= (largest * std::numeric_limits<float32>::epsilon() * 5);
            }

            return ret;
        }
#endif
    };

    /// \brief MULTIPLY value type with allocating to this.
    /// \details This function multiplies the elements of the matrix "rhs" with given value "lhs".This function returns the resultant matrix.
    /// \tparam     T          The type of the element
    /// \tparam     ROWS       Number of rows of the Matrix
    /// \tparam     COLS       Number of columns of the Matrix
    /// \tparam     EXT_MEM    Flag whether the memory of the elements of the matrix is inside
    ///                        of this class (false) or outside of this class (true).
    ///                        Default is false, meaning internal memory.
    /// \param[in]  lhs        Reference to the value to multiply
    /// \param[in]  rhs        Constant reference to input CMatrix object of size ROWS X COLS
    /// \return                Reference to resultant matrix
    /// \testmethod
    /// \traceability
    template<class T, sint32 ROWS, sint32 COLS, boolean_t EXT_MEM>
    static CMatrix<T, ROWS, COLS, false> operator* ( const T& lhs, const CMatrix<T,ROWS,COLS,EXT_MEM>& rhs )
    {
        typedef typename remove_const<T>::type type;
        CMatrix<type, ROWS, COLS, false> result(rhs);
        result.operator*=(lhs);
        return result;
    }
}

#endif //CML_STL_MATRIX_H__
