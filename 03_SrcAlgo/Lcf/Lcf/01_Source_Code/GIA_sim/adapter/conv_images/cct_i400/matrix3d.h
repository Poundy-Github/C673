/* ********************************* FILE ************************************/
/** \file    matrix3d.h
 *
 * \brief    This file describes the declaration of the class Matrix3d.
 *
 * \author   Clemens Rabe
 * \date     Mai 03, 2008
 * \note     (C) Copyright Daimler AG, GR/EAP
 *
 ******************************************************************************/
#ifndef _MATRIX3D_H
#define _MATRIX3D_H


/*****************************************************************************
 * INCLUDE FILES
 ******************************************************************************/

#include "algo_glob.h"
#include <math.h>



/*****************************************************************************
 * FORWARD DECLARATIONS
 ******************************************************************************/
namespace Math3d
{
    template< class _DataType >
    class Vector3d;
}


/*****************************************************************************
 * MACROS USED IN THE CLASS BODY
 ******************************************************************************/
#define MATRIX_INCLASS_OPERATOR_GENERATOR_BODY( op, dt )                      \
    Matrix3d< _DataType >& operator op##= ( const dt f_scalar )               \
    {                                                                         \
        ;                                           \
        m_matrix[0] op##= f_scalar;                                           \
        m_matrix[1] op##= f_scalar;                                           \
        m_matrix[2] op##= f_scalar;                                           \
        m_matrix[3] op##= f_scalar;                                           \
        m_matrix[4] op##= f_scalar;                                           \
        m_matrix[5] op##= f_scalar;                                           \
        m_matrix[6] op##= f_scalar;                                           \
        m_matrix[7] op##= f_scalar;                                           \
        m_matrix[8] op##= f_scalar;                                           \
                                                 \
        return *this;                                                         \
    }

#define MATRIX_INCLASS_GENERATOR( op )                                        \
    MATRIX_INCLASS_OPERATOR_GENERATOR_BODY( op, uint8 )                     \
    MATRIX_INCLASS_OPERATOR_GENERATOR_BODY( op, uint16 )                    \
    MATRIX_INCLASS_OPERATOR_GENERATOR_BODY( op, uint32 )                    \
    MATRIX_INCLASS_OPERATOR_GENERATOR_BODY( op, uint64 )                    \
    MATRIX_INCLASS_OPERATOR_GENERATOR_BODY( op, sint8 )                      \
    MATRIX_INCLASS_OPERATOR_GENERATOR_BODY( op, sint16 )                     \
    MATRIX_INCLASS_OPERATOR_GENERATOR_BODY( op, sint32 )                     \
    MATRIX_INCLASS_OPERATOR_GENERATOR_BODY( op, sint64 )                     \
    MATRIX_INCLASS_OPERATOR_GENERATOR_BODY( op, float )                       \
    MATRIX_INCLASS_OPERATOR_GENERATOR_BODY( op, double )


#define MATRIX_GLOBAL_SCALAR_MULT_OPERATOR_BODY( arg )                        \
    template< class _DataType >                                               \
    inline                                                                    \
    Math3d::Matrix3d< _DataType > const                                       \
    operator * ( const Math3d::Matrix3d< _DataType >& fr_left,                \
                 const arg                            fr_right )              \
    {                                                                         \
        ;                                           \
        Matrix3d< _DataType > temp( fr_left );                                \
        temp *= fr_right;                                                     \
                                                 \
        return temp;                                                          \
    }                                                                         \
                                                                              \
    template< class _DataType >                                               \
    inline                                                                    \
    Math3d::Matrix3d< _DataType > const                                       \
    operator * ( const arg                            fr_left,                \
                 const Math3d::Matrix3d< _DataType >& fr_right )              \
    {                                                                         \
        ;                                           \
        Matrix3d< _DataType > temp( fr_right );                               \
        temp *= fr_left;                                                      \
                                                 \
        return temp;                                                          \
    }


#define MATRIX_GLOBAL_SCALAR_DIV_OPERATOR_BODY( arg )                         \
    template< class _DataType >                                               \
    inline                                                                    \
    Math3d::Matrix3d< _DataType > const                                       \
    operator / ( const Math3d::Matrix3d< _DataType >& fr_left,                \
                 const arg                            fr_right )              \
    {                                                                         \
        ;                                           \
        Matrix3d< _DataType > temp( fr_left );                                \
        temp /= fr_right;                                                     \
                                                 \
        return temp;                                                          \
    }                                                                         \
                                                                              \
    template< class _DataType >                                               \
    inline                                                                    \
    Math3d::Matrix3d< _DataType > const                                       \
    operator / ( const arg                            fr_left,                \
                 const Math3d::Matrix3d< _DataType >& fr_right )              \
    {                                                                         \
        ;                                           \
        Matrix3d< _DataType > temp( fr_right );                               \
        temp.invert();                                                        \
        temp *= fr_left;                                                      \
                                                 \
        return temp;                                                          \
    }

#define MATRIX_GLOBAL_SCALAR_OPERATOR_GENERATOR                               \
    MATRIX_GLOBAL_SCALAR_MULT_OPERATOR_BODY( uint8 )                        \
    MATRIX_GLOBAL_SCALAR_DIV_OPERATOR_BODY(  uint8 )                        \
    MATRIX_GLOBAL_SCALAR_MULT_OPERATOR_BODY( uint16 )                       \
    MATRIX_GLOBAL_SCALAR_DIV_OPERATOR_BODY(  uint16 )                       \
    MATRIX_GLOBAL_SCALAR_MULT_OPERATOR_BODY( uint32 )                       \
    MATRIX_GLOBAL_SCALAR_DIV_OPERATOR_BODY(  uint32 )                       \
    MATRIX_GLOBAL_SCALAR_MULT_OPERATOR_BODY( uint64 )                       \
    MATRIX_GLOBAL_SCALAR_DIV_OPERATOR_BODY(  uint64 )                       \
    MATRIX_GLOBAL_SCALAR_MULT_OPERATOR_BODY( sint8 )                         \
    MATRIX_GLOBAL_SCALAR_DIV_OPERATOR_BODY(  sint8 )                         \
    MATRIX_GLOBAL_SCALAR_MULT_OPERATOR_BODY( sint16 )                        \
    MATRIX_GLOBAL_SCALAR_DIV_OPERATOR_BODY(  sint16 )                        \
    MATRIX_GLOBAL_SCALAR_MULT_OPERATOR_BODY( sint32 )                        \
    MATRIX_GLOBAL_SCALAR_DIV_OPERATOR_BODY(  sint32 )                        \
    MATRIX_GLOBAL_SCALAR_MULT_OPERATOR_BODY( sint64 )                        \
    MATRIX_GLOBAL_SCALAR_DIV_OPERATOR_BODY(  sint64 )                        \
    MATRIX_GLOBAL_SCALAR_MULT_OPERATOR_BODY( float )                          \
    MATRIX_GLOBAL_SCALAR_DIV_OPERATOR_BODY(  float )                          \
    MATRIX_GLOBAL_SCALAR_MULT_OPERATOR_BODY( double )                         \
    MATRIX_GLOBAL_SCALAR_DIV_OPERATOR_BODY(  double )


#define MATRIX_GLOBAL_OPERATOR( op )                                          \
    template< class _DataType, class _OtherType >                             \
    inline                                                                    \
    Math3d::Matrix3d< _DataType > const                                       \
    operator op ( const Math3d::Matrix3d< _DataType >& fr_left,               \
                  const Math3d::Matrix3d< _OtherType >& fr_right )            \
    {                                                                         \
        ;                                           \
        Matrix3d< _DataType > temp( fr_left );                                \
        temp op##= fr_right;                                                  \
                                                 \
        return temp;                                                          \
    }



/*****************************************************************************
 * DECLARATIONS OF EXPORTED CLASSES
 ******************************************************************************/

namespace Math3d
{


    /* ******************************** CLASS ************************************/
    /**
     * E X P O R T E D   C L A S S
     *
     * Matrix3d
     *
     * \brief  This class represents a 3x3 matrix.
     *
     * \author Clemens Rabe
     * \date   Mai 03, 2008
     * \sa     -
     *****************************************************************************/
    template < class _DataType = float >
    class Matrix3d
    {
#ifdef MATH3D_WITH_BOOST
        friend class boost::serialization::access;
#endif

        //------------------------------------------------------------------
    public:

        /******************************************************
         * Data types
         ******************************************************/

        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Types.
        ///@{

        /// Access to the data type.
        typedef _DataType  DataType;

        ///@}


        /******************************************************
         * constructors, destructor
         ******************************************************/

        // Constructor.
        Matrix3d();
        Matrix3d( const _DataType  f_value );
        Matrix3d( const _DataType  f_00, const _DataType  f_01, const _DataType  f_02,
                  const _DataType  f_10, const _DataType  f_11, const _DataType  f_12,
                  const _DataType  f_20, const _DataType  f_21, const _DataType  f_22 );
        Matrix3d( const Matrix3d< _DataType >&  fr_other );


        template< class _OtherType >
        Matrix3d( const Matrix3d< _OtherType >&  fr_other );



        /******************************************************
         * methods
         ******************************************************/

        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Read methods (getter).
        ///@{

        const _DataType (&getMatrix() const)[9]
        {
            return m_matrix;
        }

        _DataType&            element( const uint32 f_column_ui,
                                       const uint32 f_row_ui );
        _DataType             element( const uint32 f_column_ui,
                                       const uint32 f_row_ui ) const;

        _DataType             trace() const;
        _DataType             determinant() const;

        Vector3d< _DataType > getColumnVector( const uint32 f_column_ui ) const;
        Vector3d< _DataType > getRowVector(    const uint32 f_row_ui    ) const;

        ///@}


        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Write methods (setter).
        ///@{

        void       setElement( const _DataType  f_value,
                               const uint32   f_column_ui,
                               const uint32   f_row_ui );
        void       set(        const _DataType  f_00,
                               const _DataType  f_01,
                               const _DataType  f_02,
                               const _DataType  f_10,
                               const _DataType  f_11,
                               const _DataType  f_12,
                               const _DataType  f_20,
                               const _DataType  f_21,
                               const _DataType  f_22 );

        ///@}


        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Operations
        ///@{

        Matrix3d< _DataType >& invert();
        Matrix3d< _DataType >& transpose();

        ///@}


        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Operator overloading.
        ///@{

        Matrix3d< _DataType >&  operator= ( const Matrix3d< _DataType >&  fr_other );

        template< class _OtherType >
        Matrix3d< _DataType >&  operator= ( const Matrix3d< _OtherType >& fr_other );

        Matrix3d< _DataType >&  operator+=( const Matrix3d< _DataType >&  fr_other );
        Matrix3d< _DataType >&  operator-=( const Matrix3d< _DataType >&  fr_other );
        Matrix3d< _DataType >&  operator*=( const Matrix3d< _DataType >&  fr_other );
        Matrix3d< _DataType >&  operator/=( const Matrix3d< _DataType >&  fr_other );

        MATRIX_INCLASS_GENERATOR(* );
        MATRIX_INCLASS_GENERATOR( / );

        template< class _OtherType >
        Vector3d< _OtherType > const operator* ( const Vector3d< _OtherType >& fr_vector ) const;


        _DataType& operator()( const uint32 f_column_ui,
                               const uint32 f_row_ui );
        _DataType  operator()( const uint32 f_column_ui,
                               const uint32 f_row_ui ) const;

        ///@}



        //------------------------------------------------------------------
    protected:

        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Private methods.
        ///@{

        template< class _OtherType >
        void copyFrom( const Matrix3d< _OtherType >&   fr_other );



        ///@}


        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Private slots.
        ///@{

        /**
         * Matrix. Element indices are:
         * \verbatim
         | 0 1 2 |
         R = | 3 4 5 |
         | 6 7 8 |
         \endverbatim
         *
         */
        _DataType  m_matrix[9];

        ///@}

    };


    /*****************************************************************************
     * GLOBAL OPERATORS.
     ******************************************************************************/

    MATRIX_GLOBAL_SCALAR_OPERATOR_GENERATOR
    MATRIX_GLOBAL_OPERATOR( + )
        MATRIX_GLOBAL_OPERATOR( - )
        MATRIX_GLOBAL_OPERATOR(* )
        MATRIX_GLOBAL_OPERATOR( / )


    template< class _DataType >
    Matrix3d< _DataType >
    invert(      const Matrix3d< _DataType >&   fr_mat );

    template< class _DataType >
    Matrix3d< _DataType >
    transpose(   const Matrix3d< _DataType >&   fr_mat );

    template< class _DataType >
    _DataType
    trace(       const Matrix3d< _DataType >&   fr_mat );

    template< class _DataType >
    _DataType
    determinant( const Matrix3d< _DataType >&   fr_mat );

} // end namespace Math3d


/*****************************************************************************
 * DESTROY MACROS USED IN THE CLASS BODY
 ******************************************************************************/
#undef MATRIX_INCLASS_OPERATOR_GENERATOR_BODY
#undef MATRIX_INCLASS_GENERATOR
#undef MATRIX_GLOBAL_SCALAR_MULT_OPERATOR_BODY
#undef MATRIX_GLOBAL_SCALAR_DIV_OPERATOR_BODY
#undef MATRIX_GLOBAL_SCALAR_OPERATOR_GENERATOR
#undef MATRIX_GLOBAL_OPERATOR




/*****************************************************************************
 * IMPLEMENTATION
 ******************************************************************************/

/** Internal macros for matrix index access:
 * Element indices are:
 * \verbatim
 | 0 1 2 |   | I00 I01 I02 |
 R = | 3 4 5 | = | I10 I11 I12 |
 | 6 7 8 |   | I20 I21 I22 |
 \endverbatim
 *
 */
#define I00 0
#define I01 1
#define I02 2
#define I10 3
#define I11 4
#define I12 5
#define I20 6
#define I21 7
#define I22 8


/* ********************************* METHOD **********************************/
/**
 * \brief     Default constructor. Constructs a 3x3 matrix. Elements are NOT
 *            set!
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Matrix3d< _DataType >::Matrix3d()
{

}


/* ********************************* METHOD **********************************/
/**
 * \brief     Construct a matrix with all elements set to a given value.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] f_value - Value of all elements.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Matrix3d< _DataType >::Matrix3d( const _DataType  f_value )
{
    ;

    set( f_value, f_value, f_value,
         f_value, f_value, f_value,
         f_value, f_value, f_value );


}



/* ********************************* METHOD **********************************/
/**
 * \brief     Construct a matrix with the elements set to the given values.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] f_00 - Element of row=0, col=0.
 * \param[in] f_01 - Element of row=0, col=1.
 * \param[in] f_02 - Element of row=0, col=2.
 * \param[in] f_10 - Element of row=1, col=0.
 * \param[in] f_11 - Element of row=1, col=1.
 * \param[in] f_12 - Element of row=1, col=2.
 * \param[in] f_20 - Element of row=2, col=0.
 * \param[in] f_21 - Element of row=2, col=1.
 * \param[in] f_22 - Element of row=2, col=2.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Matrix3d< _DataType >::Matrix3d( const _DataType  f_00,
                                         const _DataType  f_01,
                                         const _DataType  f_02,
                                         const _DataType  f_10,
                                         const _DataType  f_11,
                                         const _DataType  f_12,
                                         const _DataType  f_20,
                                         const _DataType  f_21,
                                         const _DataType  f_22 )
{
    ;

    set( f_00, f_01, f_02,
         f_10, f_11, f_12,
         f_20, f_21, f_22 );


}


/* ********************************* METHOD **********************************/
/**
 * \brief     Copy constructor. Copy the matrix from the given object.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Reference to the object to copy.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Matrix3d< _DataType >::Matrix3d( const Matrix3d< _DataType >&  fr_other )
{
    ;

    copyFrom( fr_other );


}




/* ********************************* METHOD **********************************/
/**
 * \brief     Copy constructor. Copy the matrix from the given object.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Reference to the object to copy.
 *
 *****************************************************************************/
template< class _DataType >
template< class _OtherType >
inline
Math3d::Matrix3d< _DataType >::Matrix3d( const Matrix3d< _OtherType >&  fr_other )
{
    ;

    copyFrom( fr_other );


}



/* ********************************* METHOD **********************************/
/**
 * \brief     Get access to a matrix element.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] f_column_ui - Column between 0 and 2.
 * \param[in] f_row_ui    - Row between 0 and 2.
 * \return    Returns the element.
 *
 *****************************************************************************/
template< class _DataType >
inline
_DataType&
Math3d::Matrix3d< _DataType >::element( const uint32 f_column_ui,
                                        const uint32 f_row_ui )
{
    

    return m_matrix[ ( f_row_ui * 3 ) + f_column_ui ];
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Get access to a matrix element.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] f_column_ui - Column between 0 and 2.
 * \param[in] f_row_ui    - Row between 0 and 2.
 * \return    Returns the element.
 *
 *****************************************************************************/
template< class _DataType >
inline
_DataType
Math3d::Matrix3d< _DataType >::element( const uint32 f_column_ui,
                                        const uint32 f_row_ui ) const
{
    

    return m_matrix[ ( f_row_ui * 3 ) + f_column_ui ];
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Calculate the trace of the matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \return    Returns the trace of the matrix.
 *
 *****************************************************************************/
template< class _DataType >
inline
_DataType
Math3d::Matrix3d< _DataType >::trace() const
{
    

    return ( m_matrix[I00] + m_matrix[I11] + m_matrix[I22] );
}


/* ********************************* METHOD **********************************/
/**
 * The determinant of a 3x3 matrix
 * \f{eqnarray}
 A &=& \left[ \begin{array}{ccc}
 a_{00} & a_{01} & a_{02} \\
 a_{10} & a_{11} & a_{12} \\
 a_{20} & a_{21} & a_{22}
 \end{array} \right]
 \f}
 * is calculated as
 * \f{eqnarray}
 \det \left( A \right) &=& \left( a_{00} a_{11} a_{22} +
 a_{01} a_{12} a_{20} +
 a_{02} a_{10} a_{21} \right ) -
 \left( a_{20} a_{11} a_{02} +
 a_{21} a_{12} a_{00} +
 a_{22} a_{10} a_{01} \right )
 \f}
 *
 *
 * \brief     Calculate the determinant of the 3x3 matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \return    Returns the determinant of the 3x3 matrix.
 *
 *****************************************************************************/
template< class _DataType >
inline
_DataType
Math3d::Matrix3d< _DataType >::determinant() const
{
    

    return ( ( m_matrix[I00] * m_matrix[I11] * m_matrix[I22] +
               m_matrix[I01] * m_matrix[I12] * m_matrix[I20] +
               m_matrix[I02] * m_matrix[I10] * m_matrix[I21] ) -
             ( m_matrix[I20] * m_matrix[I11] * m_matrix[I02] +
               m_matrix[I21] * m_matrix[I12] * m_matrix[I00] +
               m_matrix[I22] * m_matrix[I10] * m_matrix[I01] ) );
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Get a column as a column vector.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] f_column_ui - Column index zero-based.
 * \return    Returns a Math3d::Vector3d object of the specified column.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Vector3d< _DataType >
Math3d::Matrix3d< _DataType >::getColumnVector( const uint32 f_column_ui ) const
{
    ;

    Vector3d< _DataType > temp( m_matrix[ f_column_ui ],
                                m_matrix[ 3 + f_column_ui ],
                                m_matrix[ 6 + f_column_ui ] );

    return temp;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Get a row as a row vector.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] f_row_ui - Row index zero-based.
 * \return    Returns a Math3d::Vector3d object of the specified row.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Vector3d< _DataType >
Math3d::Matrix3d< _DataType >::getRowVector( const uint32 f_row_ui ) const
{
    ;

    Vector3d< _DataType > temp( m_matrix[ ( f_row_ui * 3 )   ],
                                m_matrix[ ( f_row_ui * 3 )+1 ],
                                m_matrix[ ( f_row_ui * 3 )+2 ] );

    return temp;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Set a matrix element.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] f_value     - Value of the element.
 * \param[in] f_column_ui - Column between 0 and 2.
 * \param[in] f_row_ui    - Row between 0 and 2.
 *
 *****************************************************************************/
template< class _DataType >
inline
void
Math3d::Matrix3d< _DataType >::setElement( const _DataType f_value,
                                           const uint32  f_column_ui,
                                           const uint32  f_row_ui )
{
    ;

    m_matrix[ ( f_row_ui * 3 ) + f_column_ui ] = f_value;


}


/* ********************************* METHOD **********************************/
/**
 * \brief     Set the elements of the matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] f_00 - Element of row=0, col=0.
 * \param[in] f_01 - Element of row=0, col=1.
 * \param[in] f_02 - Element of row=0, col=2.
 * \param[in] f_10 - Element of row=1, col=0.
 * \param[in] f_11 - Element of row=1, col=1.
 * \param[in] f_12 - Element of row=1, col=2.
 * \param[in] f_20 - Element of row=2, col=0.
 * \param[in] f_21 - Element of row=2, col=1.
 * \param[in] f_22 - Element of row=2, col=2.
 *
 *****************************************************************************/
template< class _DataType >
inline
void
Math3d::Matrix3d< _DataType >::set( const _DataType  f_00,
                                    const _DataType  f_01,
                                    const _DataType  f_02,
                                    const _DataType  f_10,
                                    const _DataType  f_11,
                                    const _DataType  f_12,
                                    const _DataType  f_20,
                                    const _DataType  f_21,
                                    const _DataType  f_22 )
{

    m_matrix[I00] = f_00;
    m_matrix[I01] = f_01;
    m_matrix[I02] = f_02;
    m_matrix[I10] = f_10;
    m_matrix[I11] = f_11;
    m_matrix[I12] = f_12;
    m_matrix[I20] = f_20;
    m_matrix[I21] = f_21;
    m_matrix[I22] = f_22;

}


/* ********************************* METHOD **********************************/
/**
 * The inverse of the matrix
 * \f{eqnarray}
 A &=& \left[ \begin{array}{ccc}
 a_{00} & a_{01} & a_{02} \\
 a_{10} & a_{11} & a_{12} \\
 a_{20} & a_{21} & a_{22}
 \end{array} \right]
 \f}
 * is calculated as
 * \f{eqnarray}
 A^{-1} &=& \frac{1}{\det A} \left[ \begin{array}{ccc}
 a_{11} a_{22} - a_{12} a_{21} & a_{02} a_{21} - a_{01} a_{22} & a_{01} a_{12} - a_{02} a_{11} \\
 a_{12} a_{20} - a_{10} a_{22} & a_{00} a_{22} - a_{02} a_{20} & a_{02} a_{10} - a_{00} a_{12} \\
 a_{10} a_{21} - a_{11} a_{20} & a_{01} a_{20} - a_{00} a_{21} & a_{00} a_{11} - a_{01} a_{10}
 \end{array} \right]
 \f}
 *
 * \brief     Invert this matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Matrix3d< _DataType >&
Math3d::Matrix3d< _DataType >::invert()
{
    ;

    const _DataType       det = determinant();

    set( ( m_matrix[I11]*m_matrix[I22] - m_matrix[I12]*m_matrix[I21] ) / det,
         ( m_matrix[I02]*m_matrix[I21] - m_matrix[I01]*m_matrix[I22] ) / det,
         ( m_matrix[I01]*m_matrix[I12] - m_matrix[I02]*m_matrix[I11] ) / det,

         ( m_matrix[I12]*m_matrix[I20] - m_matrix[I10]*m_matrix[I22] ) / det,
         ( m_matrix[I00]*m_matrix[I22] - m_matrix[I02]*m_matrix[I20] ) / det,
         ( m_matrix[I02]*m_matrix[I10] - m_matrix[I00]*m_matrix[I12] ) / det,

         ( m_matrix[I10]*m_matrix[I21] - m_matrix[I11]*m_matrix[I20] ) / det,
         ( m_matrix[I01]*m_matrix[I20] - m_matrix[I00]*m_matrix[I21] ) / det,
         ( m_matrix[I00]*m_matrix[I11] - m_matrix[I01]*m_matrix[I10] ) / det  );


    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Transpose this matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 02, 2008
 *
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Matrix3d< _DataType >&
Math3d::Matrix3d< _DataType >::transpose()
{

    _DataType tmp;

    /// Temporary macro
#define _SWAP( i, j )                                                         \
    tmp = m_matrix[i];                                                        \
    m_matrix[i] = m_matrix[j];                                                \
    m_matrix[j] = tmp;

    _SWAP( I01, I10 );
    _SWAP( I02, I20 );
    _SWAP( I12, I21 );

#undef _SWAP


    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Assignment operator.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Object to copy.
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Matrix3d< _DataType >&
Math3d::Matrix3d< _DataType >::operator= ( const Math3d::Matrix3d< _DataType >& fr_other )
{
    ;

    copyFrom( fr_other );



    return *this;
}



/* ********************************* METHOD **********************************/
/**
 * \brief     Assignment operator.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Object to copy.
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
template< class _OtherType >
inline
Math3d::Matrix3d< _DataType >&
Math3d::Matrix3d< _DataType >::operator= ( const Math3d::Matrix3d< _OtherType >& fr_other )
{
    ;

    copyFrom( fr_other );



    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Addition operator. Adds the elements of the given matrix to
 *            the corresponding elements of this matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Reference to the other object.
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Matrix3d< _DataType >&
Math3d::Matrix3d< _DataType >::operator+=( const Math3d::Matrix3d< _DataType >& fr_other )
{
    ;

    const _DataType* other_p = fr_other.getMatrix();

    m_matrix[ I00 ] += other_p[ I00 ];
    m_matrix[ I01 ] += other_p[ I01 ];
    m_matrix[ I02 ] += other_p[ I02 ];
    m_matrix[ I10 ] += other_p[ I10 ];
    m_matrix[ I11 ] += other_p[ I11 ];
    m_matrix[ I12 ] += other_p[ I12 ];
    m_matrix[ I20 ] += other_p[ I20 ];
    m_matrix[ I21 ] += other_p[ I21 ];
    m_matrix[ I22 ] += other_p[ I22 ];



    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Substraction operator. Substracts the elements of the given
 *            matrix from the corresponding elements of this matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Reference to the other object.
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Matrix3d< _DataType >&
Math3d::Matrix3d< _DataType >::operator-=( const Math3d::Matrix3d< _DataType >& fr_other )
{
    ;

    const _DataType* other_p = fr_other.getMatrix();

    m_matrix[ I00 ] -= other_p[ I00 ];
    m_matrix[ I01 ] -= other_p[ I01 ];
    m_matrix[ I02 ] -= other_p[ I02 ];
    m_matrix[ I10 ] -= other_p[ I10 ];
    m_matrix[ I11 ] -= other_p[ I11 ];
    m_matrix[ I12 ] -= other_p[ I12 ];
    m_matrix[ I20 ] -= other_p[ I20 ];
    m_matrix[ I21 ] -= other_p[ I21 ];
    m_matrix[ I22 ] -= other_p[ I22 ];



    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * The matrix multiplication corresponds to
 * \f{eqnarray}
 A &=& A B
 \f}
 * with \f$ A \f$ as the matrix represented by this object, and \f$ B \f$ as
 * the matrix given as argument.
 *
 *
 * \brief     Matrix multiplication.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Reference to the other object.
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Matrix3d< _DataType >&
Math3d::Matrix3d< _DataType >::operator*=( const Math3d::Matrix3d< _DataType >& fr_other )
{
    ;

    const _DataType* other_p = fr_other.getMatrix();

    set( m_matrix[ I00 ]*other_p[ I00 ] + m_matrix[ I01 ]*other_p[ I10 ] + m_matrix[ I02 ]*other_p[ I20 ],
         m_matrix[ I00 ]*other_p[ I01 ] + m_matrix[ I01 ]*other_p[ I11 ] + m_matrix[ I02 ]*other_p[ I21 ],
         m_matrix[ I00 ]*other_p[ I02 ] + m_matrix[ I01 ]*other_p[ I12 ] + m_matrix[ I02 ]*other_p[ I22 ],

         m_matrix[ I10 ]*other_p[ I00 ] + m_matrix[ I11 ]*other_p[ I10 ] + m_matrix[ I12 ]*other_p[ I20 ],
         m_matrix[ I10 ]*other_p[ I01 ] + m_matrix[ I11 ]*other_p[ I11 ] + m_matrix[ I12 ]*other_p[ I21 ],
         m_matrix[ I10 ]*other_p[ I02 ] + m_matrix[ I11 ]*other_p[ I12 ] + m_matrix[ I12 ]*other_p[ I22 ],

         m_matrix[ I20 ]*other_p[ I00 ] + m_matrix[ I21 ]*other_p[ I10 ] + m_matrix[ I22 ]*other_p[ I20 ],
         m_matrix[ I20 ]*other_p[ I01 ] + m_matrix[ I21 ]*other_p[ I11 ] + m_matrix[ I22 ]*other_p[ I21 ],
         m_matrix[ I20 ]*other_p[ I02 ] + m_matrix[ I21 ]*other_p[ I12 ] + m_matrix[ I22 ]*other_p[ I22 ] );



    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * The matrix division corresponds to
 * \f{eqnarray}
 A &=& A B^{-1}
 \f}
 * with \f$ A \f$ as the matrix represented by this object, and \f$ B \f$ as
 * the matrix given as argument.
 *
 *
 * \brief     Matrix division.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Reference to the other object.
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Matrix3d< _DataType >&
Math3d::Matrix3d< _DataType >::operator/=( const Math3d::Matrix3d< _DataType >& fr_other )
{
    ;

    Math3d::Matrix3d< _DataType > temp( fr_other );
    temp.invert();
    const _DataType* other_p = temp.getMatrix();

    set( m_matrix[ I00 ]*other_p[ I00 ] + m_matrix[ I01 ]*other_p[ I10 ] + m_matrix[ I02 ]*other_p[ I20 ],
         m_matrix[ I00 ]*other_p[ I01 ] + m_matrix[ I01 ]*other_p[ I11 ] + m_matrix[ I02 ]*other_p[ I21 ],
         m_matrix[ I00 ]*other_p[ I02 ] + m_matrix[ I01 ]*other_p[ I12 ] + m_matrix[ I02 ]*other_p[ I22 ],

         m_matrix[ I10 ]*other_p[ I00 ] + m_matrix[ I11 ]*other_p[ I10 ] + m_matrix[ I12 ]*other_p[ I20 ],
         m_matrix[ I10 ]*other_p[ I01 ] + m_matrix[ I11 ]*other_p[ I11 ] + m_matrix[ I12 ]*other_p[ I21 ],
         m_matrix[ I10 ]*other_p[ I02 ] + m_matrix[ I11 ]*other_p[ I12 ] + m_matrix[ I12 ]*other_p[ I22 ],

         m_matrix[ I20 ]*other_p[ I00 ] + m_matrix[ I21 ]*other_p[ I10 ] + m_matrix[ I22 ]*other_p[ I20 ],
         m_matrix[ I20 ]*other_p[ I01 ] + m_matrix[ I21 ]*other_p[ I11 ] + m_matrix[ I22 ]*other_p[ I21 ],
         m_matrix[ I20 ]*other_p[ I02 ] + m_matrix[ I21 ]*other_p[ I12 ] + m_matrix[ I22 ]*other_p[ I22 ] );



    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Multiplication of this matrix with a column vector.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_vector - The vector.
 * \return    Returns the vector result.
 *
 *****************************************************************************/
template< class _DataType >
template< class _OtherType >
inline
Math3d::Vector3d< _OtherType > const
Math3d::Matrix3d< _DataType >::operator* ( const Math3d::Vector3d< _OtherType >& fr_vector ) const
{
    ;
    Vector3d< _OtherType > temp( m_matrix[I00]*fr_vector.getX() + m_matrix[I01]*fr_vector.getY() + m_matrix[I02]*fr_vector.getZ(),
                                 m_matrix[I10]*fr_vector.getX() + m_matrix[I11]*fr_vector.getY() + m_matrix[I12]*fr_vector.getZ(),
                                 m_matrix[I20]*fr_vector.getX() + m_matrix[I21]*fr_vector.getY() + m_matrix[I22]*fr_vector.getZ() );



    return temp;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Get access to a matrix element.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] f_column_ui - Column between 0 and 2.
 * \param[in] f_row_ui    - Row between 0 and 2.
 * \return    Returns the element.
 *
 *****************************************************************************/
template< class _DataType >
inline
_DataType&
Math3d::Matrix3d< _DataType >::operator()( const uint32 f_column_ui,
                                           const uint32 f_row_ui )
{
    

    return m_matrix[ ( f_row_ui * 3 ) + f_column_ui ];
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Get access to a matrix element.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] f_column_ui - Column between 0 and 2.
 * \param[in] f_row_ui    - Row between 0 and 2.
 * \return    Returns the element.
 *
 *****************************************************************************/
template< class _DataType >
inline
_DataType
Math3d::Matrix3d< _DataType >::operator()( const uint32 f_column_ui,
                                           const uint32 f_row_ui ) const
{
    

    return m_matrix[ ( f_row_ui * 3 ) + f_column_ui ];
}




/* ********************************* METHOD **********************************/
/**
 * \brief     Copy from another object.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Reference to the object to copy.
 *
 *****************************************************************************/
template< class _DataType >
template< class _OtherType >
inline
void
Math3d::Matrix3d< _DataType >::copyFrom( const Matrix3d< _OtherType >&   fr_other )
{
    ;

    const _OtherType* otherMat_p = fr_other.getMatrix();

    m_matrix[I00] = _DataType( otherMat_p[I00] );
    m_matrix[I01] = _DataType( otherMat_p[I01] );
    m_matrix[I02] = _DataType( otherMat_p[I02] );
    m_matrix[I10] = _DataType( otherMat_p[I10] );
    m_matrix[I11] = _DataType( otherMat_p[I11] );
    m_matrix[I12] = _DataType( otherMat_p[I12] );
    m_matrix[I20] = _DataType( otherMat_p[I20] );
    m_matrix[I21] = _DataType( otherMat_p[I21] );
    m_matrix[I22] = _DataType( otherMat_p[I22] );


}





/* ********************************* METHOD **********************************/
/**
 * \brief     Return the transpose of a matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_mat - Matrix.
 * \return    Returns the transpose of the matrix.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Matrix3d< _DataType >
Math3d::transpose( const Matrix3d< _DataType >&   fr_mat )
{
    ;

    Math3d::Matrix3d< _DataType > temp( fr_mat );
    temp.transpose();


    return temp;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Return the inverse of the matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_mat - Matrix.
 * \return    Returns the inverse of the matrix.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Matrix3d< _DataType >
Math3d::invert( const Matrix3d< _DataType >&   fr_mat )
{
    ;

    Math3d::Matrix3d< _DataType > temp( fr_mat );
    temp.invert();


    return temp;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Calculate the trace of the matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_mat - Matrix.
 * \return    Returns the trace of the matrix.
 *
 *****************************************************************************/
template< class _DataType >
inline
_DataType
Math3d::trace( const Matrix3d< _DataType >&   fr_mat )
{
    return fr_mat.trace();
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Calculate the determinant of the matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_mat - Matrix.
 * \return    Returns the determinant of the matrix.
 *
 *****************************************************************************/
template< class _DataType >
inline
_DataType
Math3d::determinant( const Matrix3d< _DataType >&   fr_mat )
{
    return fr_mat.determinant();
}


// Destroy internal macros
#undef I00
#undef I01
#undef I02
#undef I10
#undef I11
#undef I12
#undef I20
#undef I21
#undef I22


#endif /* _MATRIX3D_H */

/*****************************************************************************
|----------------------------------------------------------------------------|
| R E V I S I O N   H I S T O R Y                                            |
|----------------------------------------------------------------------------|

$Log: matrix3d.h  $
Revision 1.1 2021/12/13 17:20:02CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/adapter/conv_images/cct_i400/project.pj
Revision 1.0 2017/03/03 10:30:37CET Sorge, Sven (uidg3181) 
Initial revision
Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/adapter/converters/conv_images/cct_i400/project.pj
Revision 1.2 2013/02/12 08:47:12CET Zechner, Stefan (uidt9253) 
- remove undefined MATH3D_RETURN_CALL macro to make it compile on DSP
- Added comments -  uidt9253 [Feb 12, 2013 8:47:12 AM CET]
Change Package : 162889:30 http://mks-psad:7002/im/viewissue?selection=162889
Revision 1.1 2012/11/29 15:32:10CET Thiel, Robert (thielr) 
Initial revision
Member added to project /nfs/projekte1/PROJECTS/MFC400/06_Algorithm/04_Engineering/01_Source_Code/algo/cct/project.pj
Revision 1.4 2012/02/21 17:58:45CET Exner, Christian (uidt8578) 
- made return of getMatrix() a reference to a array with 9 elements instead of a classical pointer
--- Added comments ---  uidt8578 [Feb 21, 2012 5:58:46 PM CET]
Change Package : 95382:13 http://mks-psad:7002/im/viewissue?selection=95382
Revision 1.3 2011/04/15 16:46:16CEST Bachmann Alexander (uidt5584) (uidt5584) 
GIT update (Commit:5b0892f3ddd8fd69d47059fe2183d97e65914453)
--- Added comments ---  uidt5584 [Apr 15, 2011 4:46:16 PM CEST]
Change Package : 52130:2 http://mks-psad:7002/im/viewissue?selection=52130
Revision 1.1 2011/03/09 16:34:40CET Wagner Ulrich (uid04769) (uid04769) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SFOD_StereoFastObjectDetection/04_Engineering/01_Source_Code/Kernel/kernel_common/math3d/h/project.pj
Revision 1.4 2010/10/27 14:21:36CEST Wagner Ulrich (uid04769) (uid04769) 
GIT merge
--- Added comments ---  uid04769 [Oct 27, 2010 2:21:36 PM CEST]
Change Package : 37878:1 http://mks-psad:7002/im/viewissue?selection=37878
Revision 1.2 2010/02/24 11:18:17CET mdarms
Initial commit.
--- Added comments ---  mdarms [2010/02/24 10:18:18Z]
Change Package : 26827:2 http://LISS014:6001/im/viewissue?selection=26827
Revision 1.2  2010-02-11 10:58:30  iprep
gehrig: math3d wo newmat, paramReader commonData hardwired

Revision 1.4  2010-02-10 13:36:51  iprep
rabe: Newmat optional now.

Revision 1.3  2009-09-22 15:51:58  iprep
rabe+folkerts: boost optional

Revision 1.2  2008-05-13 09:06:02  iprep
rabe: Multiplication is now const.

Revision 1.1  2008-05-05 09:20:22  iprep
rabe: First version.


******************************************************************************/

/*****************************************************************************
 * END OF FILE
 ******************************************************************************/
