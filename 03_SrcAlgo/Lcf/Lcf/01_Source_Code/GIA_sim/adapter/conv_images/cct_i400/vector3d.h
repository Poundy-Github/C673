/* ********************************* FILE ************************************/
/** \file    vector3d.h
 *
 * \brief    This file describes the declaration of the class Vector3d.
 *
 * \author   Clemens Rabe
 * \date     Mai 01, 2008
 * \note     (C) Copyright Daimler AG, GR/EAP
 *
 ******************************************************************************/
#ifndef _VECTOR3D_H
#define _VECTOR3D_H


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
    class Matrix3d;
}


/*****************************************************************************
 * MACROS USED IN THE CLASS BODY
 ******************************************************************************/
#define VECTOR_INCLASS_OPERATOR_GENERATOR_BODY( op )                          \
    {                                                                         \
        ;                                           \
        m_x op##= _DataType( f_scalar );                                      \
        m_y op##= _DataType( f_scalar );                                      \
        m_z op##= _DataType( f_scalar );                                      \
                                                 \
        return *this;                                                         \
    }

#define VECTOR_INCLASS_OPERATOR_GENERATOR( op, dt )                           \
    Vector3d< _DataType >& operator op##= ( const dt f_scalar )               \
        VECTOR_INCLASS_OPERATOR_GENERATOR_BODY( op )

#define VECTOR_INCLASS_GENERATOR( op )                                        \
    VECTOR_INCLASS_OPERATOR_GENERATOR( op, uint8 )                          \
    VECTOR_INCLASS_OPERATOR_GENERATOR( op, uint16 )                         \
    VECTOR_INCLASS_OPERATOR_GENERATOR( op, uint32 )                         \
    VECTOR_INCLASS_OPERATOR_GENERATOR( op, uint64 )                         \
    VECTOR_INCLASS_OPERATOR_GENERATOR( op, sint8 )                           \
    VECTOR_INCLASS_OPERATOR_GENERATOR( op, sint16 )                          \
    VECTOR_INCLASS_OPERATOR_GENERATOR( op, sint32 )                          \
    VECTOR_INCLASS_OPERATOR_GENERATOR( op, sint64 )                          \
    VECTOR_INCLASS_OPERATOR_GENERATOR( op, float )                            \
    VECTOR_INCLASS_OPERATOR_GENERATOR( op, double )


#define VECTOR_GLOBAL_OPERATOR_GENERATOR_BODY( op )                           \
    {                                                                         \
        ;                                           \
        Vector3d< _DataType > temp( fr_left );                                \
        temp op##= fr_right;                                                  \
                                                 \
        return(temp);                                                         \
    }

#define VECTOR_GLOBAL_OPERATOR_GENERATOR_1( op )                              \
    template< class _DataType, class _OtherType >                             \
    inline                                                                    \
    Math3d::Vector3d< _DataType > const                                       \
    operator op ( const Vector3d< _DataType >&  fr_left,                      \
                  const Vector3d< _OtherType >& fr_right )                    \
        VECTOR_GLOBAL_OPERATOR_GENERATOR_BODY( op )

#define VECTOR_GLOBAL_OPERATOR_GENERATOR_2A( op, arg )                        \
    template< class _DataType >                                               \
    inline                                                                    \
    Math3d::Vector3d< _DataType > const                                       \
    operator op ( const Vector3d< _DataType >& fr_left,                       \
                  const arg                    fr_right )                     \
        VECTOR_GLOBAL_OPERATOR_GENERATOR_BODY( op )

#define VECTOR_GLOBAL_OPERATOR_GENERATOR_2B( op, arg )                        \
    template< class _DataType >                                               \
    inline                                                                    \
    Math3d::Vector3d< _DataType > const                                       \
    operator op ( const arg                    fr_left,                       \
                  const Vector3d< _DataType >& fr_right )                     \
        VECTOR_GLOBAL_OPERATOR_GENERATOR_BODY( op )

#define VECTOR_GLOBAL_OPERATOR_GENERATOR( op )                                \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_1(  op )                                 \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2A( op, uint8 )                        \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2B( op, uint8 )                        \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2A( op, uint16 )                       \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2B( op, uint16 )                       \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2A( op, uint32 )                       \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2B( op, uint32 )                       \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2A( op, uint64 )                       \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2B( op, uint64 )                       \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2A( op, sint8 )                         \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2B( op, sint8 )                         \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2A( op, sint16 )                        \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2B( op, sint16 )                        \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2A( op, sint32 )                        \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2B( op, sint32 )                        \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2A( op, sint64 )                        \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2B( op, sint64 )                        \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2A( op, float  )                         \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2B( op, float  )                         \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2A( op, double )                         \
    VECTOR_GLOBAL_OPERATOR_GENERATOR_2B( op, double )


#define VECTOR_GLOBAL_SCALAR_OPERATOR_GENERATOR_1( op, arg )                  \
    template< class _DataType >                                               \
    inline                                                                    \
    Math3d::Vector3d< _DataType > const                                       \
    operator op ( const Vector3d< _DataType >& fr_left,                       \
                  const arg                    fr_right )                     \
    {                                                                         \
        ;                                           \
        Vector3d< _DataType > temp( fr_left );                                \
        temp op##= fr_right;                                                  \
                                                 \
        return temp;                                                          \
    }                                                                         \
                                                                              \
    template< class _DataType >                                               \
    inline                                                                    \
    Math3d::Vector3d< _DataType > const                                       \
    operator op ( const arg                    fr_left,                       \
                  const Vector3d< _DataType >& fr_right )                     \
    {                                                                         \
        ;                                           \
        Vector3d< _DataType > temp( fr_left op fr_right.getX(),               \
                                    fr_left op fr_right.getY(),               \
                                    fr_left op fr_right.getZ() );             \
                                                 \
        return temp;                                                          \
    }


#define VECTOR_GLOBAL_SCALAR_OPERATOR_GENERATOR( op )                         \
    VECTOR_GLOBAL_SCALAR_OPERATOR_GENERATOR_1( op, uint8 )                  \
    VECTOR_GLOBAL_SCALAR_OPERATOR_GENERATOR_1( op, uint16 )                 \
    VECTOR_GLOBAL_SCALAR_OPERATOR_GENERATOR_1( op, uint32 )                 \
    VECTOR_GLOBAL_SCALAR_OPERATOR_GENERATOR_1( op, uint64 )                 \
    VECTOR_GLOBAL_SCALAR_OPERATOR_GENERATOR_1( op, sint8 )                   \
    VECTOR_GLOBAL_SCALAR_OPERATOR_GENERATOR_1( op, sint16 )                  \
    VECTOR_GLOBAL_SCALAR_OPERATOR_GENERATOR_1( op, sint32 )                  \
    VECTOR_GLOBAL_SCALAR_OPERATOR_GENERATOR_1( op, sint64 )                  \
    VECTOR_GLOBAL_SCALAR_OPERATOR_GENERATOR_1( op, float )                    \
    VECTOR_GLOBAL_SCALAR_OPERATOR_GENERATOR_1( op, double )



/*****************************************************************************
 * DECLARATIONS OF EXPORTED CLASSES
 ******************************************************************************/


namespace Math3d
{


    /* ******************************** CLASS ************************************/
    /**
     * This class represents a three dimensional vector using a custom storage
     * data type for the components. This class supports the following
     * operations through operator overloading:
     *  - Addition element by element (+)
     *  - Substraction element by element (-)
     *  - Multiplication with a scalar (*)
     *  - Division with a scalar (/)
     *  - Element accessor using the () operator.
     *
     * Vectors defined using different storage data types can be assigned to
     * each other via the copy constructor or the assignement operator. In
     * addition, a NEWMAT::ColumnVector can be converted to a Vector3d with the
     * copy constructor, and a Vector3d is converted to a NEWMAT::ColumnVector
     * using the conversion operator.
     *
     * Serialization support is provided using the boost serialization support.
     * All you have to do is to serialize a vector using the "&" operator on the
     * archive.
     *
     *
     * \brief  This class represents a three dimensional vector stored as the
     *         componentes (X,Y,Z).
     *
     * \author Clemens Rabe
     * \date   Mai 01, 2008
     * \sa     -
     *****************************************************************************/
    template < class _DataType = float >
    class Vector3d
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
        Vector3d( const _DataType              f_value = _DataType( 0.0 ) );
        Vector3d( const _DataType              f_x,
                  const _DataType              f_y,
                  const _DataType              f_z );
        Vector3d( const Vector3d< _DataType >& fr_other );

        template< class _OtherType >
        Vector3d( const Vector3d< _OtherType >&  fr_other );



        /******************************************************
         * methods
         ******************************************************/

        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Read methods (getter).
        ///@{

        _DataType getX()       const;
        _DataType getY()       const;
        _DataType getZ()       const;

        double    sumSquared() const;
        double    norm_L1()    const;
        double    norm_L2()    const;
        double    norm_Inf()   const;
        double    length()     const;

        ///@}


        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Write methods (setter).
        ///@{

        void set(  const _DataType f_x,
                   const _DataType f_y,
                   const _DataType f_z );
        void setX( const _DataType f_x );
        void setY( const _DataType f_y );
        void setZ( const _DataType f_z );

        ///@}


        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Operations
        ///@{

        Vector3d< _DataType >& normalize();

        template< class _OtherType >
        double innerProduct( const Vector3d< _OtherType >&  fr_other ) const;

        template< class _OtherType >
        Matrix3d< _DataType >
        outerProduct(        const Vector3d< _OtherType >&  fr_other ) const;

        template< class _OtherType >
        Vector3d< _DataType >
        crossProduct( const Vector3d< _OtherType >&  fr_other ) const;

        ///@}


        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Operator overloading.
        ///@{

        Vector3d< _DataType >&       operator= ( const Vector3d< _DataType >&   fr_other );



        template< class _OtherType >
        Vector3d< _DataType >&       operator= ( const Vector3d< _OtherType >&  fr_other );

        Vector3d< _DataType >&       operator+=( const Vector3d< _DataType >&   fr_other );
        Vector3d< _DataType >&       operator-=( const Vector3d< _DataType >&   fr_other );

        VECTOR_INCLASS_GENERATOR(* )
        VECTOR_INCLASS_GENERATOR( / )



        _DataType& operator()( const uint32 f_index_ui );
        _DataType  operator()( const uint32 f_index_ui ) const;

        ///@}





        //------------------------------------------------------------------
    private:

        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Private methods.
        ///@{

        template< class _OtherType >
        void  copyFrom( const Vector3d< _OtherType >& fr_other );



        ///@}


        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Private slots.
        ///@{

        /// X-component
        _DataType   m_x;

        /// Y-component
        _DataType   m_y;

        /// Z-component
        _DataType   m_z;

        ///@}

    };


    /*****************************************************************************
     * GLOBAL OPERATORS.
     ******************************************************************************/
    VECTOR_GLOBAL_OPERATOR_GENERATOR( + )
    VECTOR_GLOBAL_OPERATOR_GENERATOR( - )
    VECTOR_GLOBAL_SCALAR_OPERATOR_GENERATOR(* )
    VECTOR_GLOBAL_SCALAR_OPERATOR_GENERATOR( / )



    template< class _DataType >
    Vector3d< _DataType >
    normalize(    const Vector3d< _DataType >&  fr_vector );

    template< class _DataType, class _OtherType >
    double
    innerProduct( const Vector3d< _DataType >&  fr_left,
                  const Vector3d< _OtherType >& fr_right );

    template< class _DataType, class _OtherType >
    Matrix3d< _DataType >
    outerProduct( const Vector3d< _DataType >&  fr_left,
                  const Vector3d< _OtherType >& fr_right );

    template< class _DataType, class _OtherType >
    Vector3d< _DataType >
    crossProduct( const Vector3d< _DataType >&  fr_left,
                  const Vector3d< _OtherType >& fr_right );

} // end namespace



/*****************************************************************************
 * DESTROY MACROS USED IN THE CLASS BODY
 ******************************************************************************/
#undef VECTOR_INCLASS_GENERATOR
#undef VECTOR_INCLASS_OPERATOR_GENERATOR
#undef VECTOR_INCLASS_OPERATOR_GENERATOR_BODY

#undef VECTOR_GLOBAL_OPERATOR_GENERATOR
#undef VECTOR_GLOBAL_OPERATOR_GENERATOR_1
#undef VECTOR_GLOBAL_OPERATOR_GENERATOR_2A
#undef VECTOR_GLOBAL_OPERATOR_GENERATOR_2B
#undef VECTOR_GLOBAL_OPERATOR_GENERATOR_BODY


/*****************************************************************************
 * IMPLEMENTATION
 ******************************************************************************/

/* ********************************* METHOD **********************************/
/**
 * \brief     Constructor.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \param[in] f_value - Value of all components.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Vector3d< _DataType >::Vector3d( const _DataType f_value )
        : m_x( f_value ),
          m_y( f_value ),
          m_z( f_value )
{
    
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Constructor.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \param[in] f_x - Value of x component.
 * \param[in] f_y - Value of y component.
 * \param[in] f_z - Value of z component.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Vector3d< _DataType >::Vector3d( const _DataType           f_x,
                                         const _DataType           f_y,
                                         const _DataType           f_z )
        : m_x( f_x ),
          m_y( f_y ),
          m_z( f_z )
{
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Copy Constructor.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \param[in] fr_other - Reference to the object to copy.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Vector3d< _DataType >::Vector3d( const Vector3d< _DataType >& fr_other )
{
    ;
    copyFrom( fr_other );

}


/* ********************************* METHOD **********************************/
/**
 * \brief     Copy Constructor.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \param[in] fr_other - Reference to the object to copy.
 *
 *****************************************************************************/
template< class _DataType >
template< class _OtherType >
inline
Math3d::Vector3d< _DataType >::Vector3d( const Vector3d< _OtherType >& fr_other )
{
    ;
    copyFrom( fr_other );

}



/* ********************************* METHOD **********************************/
/**
 * \brief     Get the X component.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \return    Returns the x-component.
 *****************************************************************************/
template< class _DataType >
inline
_DataType
Math3d::Vector3d< _DataType >::getX() const
{
    return m_x;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Get the Y component.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \return    Returns the y-component.
 *****************************************************************************/
template< class _DataType >
inline
_DataType
Math3d::Vector3d< _DataType >::getY() const
{
    return m_y;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Get the Z component.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \return    Returns the z-component.
 *****************************************************************************/
template< class _DataType >
inline
_DataType
Math3d::Vector3d< _DataType >::getZ() const
{
    return m_z;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Set the components.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \param[in] f_x - X component.
 * \param[in] f_y - Y component.
 * \param[in] f_z - Z component.
 *
 *****************************************************************************/
template< class _DataType >
inline
void
Math3d::Vector3d< _DataType >::set( const _DataType f_x,
                                    const _DataType f_y,
                                    const _DataType f_z )
{
    ;

    m_x = f_x;
    m_y = f_y;
    m_z = f_z;


}


/* ********************************* METHOD **********************************/
/**
 * \brief     Set the x component.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \param[in] f_x - X component.
 *
 *****************************************************************************/
template< class _DataType >
inline
void
Math3d::Vector3d< _DataType >::setX( const _DataType f_x )
{
    m_x = f_x;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Set the y component.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \param[in] f_y - Y component.
 *
 *****************************************************************************/
template< class _DataType >
inline
void
Math3d::Vector3d< _DataType >::setY( const _DataType f_y )
{
    m_y = f_y;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Set the z component.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \param[in] f_z - Z component.
 *
 *****************************************************************************/
template< class _DataType >
inline
void
Math3d::Vector3d< _DataType >::setZ( const _DataType f_z )
{
    m_z = f_z;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Calculate the sum of all squared components.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \return    Returns the sum of all squared components.
 *
 *****************************************************************************/
template< class _DataType >
inline
double
Math3d::Vector3d< _DataType >::sumSquared() const
{
    

    return ( m_x * m_x + m_y * m_y + m_z * m_z );
}


/* ********************************* METHOD **********************************/
/**
 * The L1 norm is defined as
 * \f{eqnarray}
 \left| \vec{v} \right|_{1} &=& \sum_{i=1}^{n} \left| x_{i} \right|
 \f}
 * blabla
 *
 * \brief     Calculate the L1 norm, also known as the taxicab norm or
 *            manhatten norm.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \return    Returns the L1 norm of the vector.
 *
 *****************************************************************************/
template< class _DataType >
inline
double
Math3d::Vector3d< _DataType >::norm_L1() const
{
    

    return ( fabs( m_x ) + fabs( m_y ) + fabs( m_z ) );
}


/* ********************************* METHOD **********************************/
/**
 * The L2 norm is defined as
 * \f{eqnarray}
 \left| \vec{v} \right|_{2} &=& \left( \sum_{i=1}^{n} \left| x_{i} \right|^2 \right)^{\frac{1}{2}}
 \f}
 * blabla
 *
 * \brief     Calculate the L2 norm, also known as the euclidean length.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \return    Returns the L1 norm of the vector.
 *
 *****************************************************************************/
template< class _DataType >
inline
double
Math3d::Vector3d< _DataType >::norm_L2() const
{
    

    return sqrt( m_x * m_x + m_y * m_y + m_z * m_z );
}


/* ********************************* METHOD **********************************/
/**
 * The infinity norm is defined as
 * \f{eqnarray}
 \left| \vec{v} \right|_{\infty} &=& \max \left( \left| x_1 \right|, \ldots, \left| x_n \right| \right)
 \f}
 *
 *
 * \brief     Calculate the infinity norm, also known as the maximum norm.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \return    Returns the infinity norm of the vector.
 *
 *****************************************************************************/
template< class _DataType >
inline
double
Math3d::Vector3d< _DataType >::norm_Inf() const
{
    

    const double x_abs_d = fabs( m_x );
    const double y_abs_d = fabs( m_y );
    const double z_abs_d = fabs( m_z );

    if ( ( x_abs_d > y_abs_d ) && ( x_abs_d > z_abs_d ) )
        return x_abs_d;

    else if ( y_abs_d > z_abs_d )
        return y_abs_d;

    return z_abs_d;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Calculate the euclidean length of the vector.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \sa        norm_L2()
 *
 * \return    Returns the euclidean length of the vector.
 *
 *****************************************************************************/
template< class _DataType >
inline
double
Math3d::Vector3d< _DataType >::length() const
{
    

    return norm_L2();
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Normalize the vector, so that length() is 1.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Vector3d< _DataType >&
Math3d::Vector3d< _DataType >::normalize()
{
    ;

    double length_d = norm_L2();

    m_x /= _DataType( length_d );
    m_y /= _DataType( length_d );
    m_z /= _DataType( length_d );



    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * The inner product of two vectors is also known as the dot product or
 * scalar product. It is defined as:
 * \f{eqnarray}
 \vec{a} \cdot \vec{b} &=& \sum_{i=1}^{n} a_i b_i
 \f}
 * and is related to the angle \f$ \alpha \f$ between the two vectors by
 * \f{eqnarray}
 \vec{a} \cdot \vec{b} &=& \left| a \right| \left| b \right| \cos \alpha
 \f}
 *
 *
 * \brief     Calculate the inner product, also known as the dot product or
 *            scalar product.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Reference to other vector (right operand)
 * \return    Returns the value of the inner product, a scalar.
 *
 *****************************************************************************/
template< class _DataType >
template< class _OtherType >
inline
double
Math3d::Vector3d< _DataType >::innerProduct(
        const Vector3d< _OtherType >&  fr_other ) const
{
    

    return ( m_x * fr_other.getX() + m_y * fr_other.getY() + m_z * fr_other.getZ() );
}


/* ********************************* METHOD **********************************/
/**
 * The outer product of two vectors is defined as
 * \f{eqnarray}
 \vec{a} \vec{b}^{\top} &=& \left[ \begin{array}{ccc}
 a_x b_x & a_x b_y & a_x b_z \\
 a_y b_x & a_y b_y & a_y b_z \\
 a_z b_x & a_z b_y & a_z b_z
 \end{array}
 \right]
 \f}
 * where the vector \f$ \vec{a} \f$ corresponds to this object.
 *
 *
 * \brief     Calculate the outer product of this vector and the transposed
 *            given vector.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Other vector used as the right hand operand.
 * \return    Returns a 3x3 matrix containing the outer product.
 *
 *****************************************************************************/
template< class _DataType >
template< class _OtherType >
inline
Math3d::Matrix3d< _DataType >
Math3d::Vector3d< _DataType >::outerProduct(
        const Vector3d< _OtherType >&  fr_other ) const
{
    

    return Matrix3d< _DataType >( m_x * fr_other.getX(), m_x * fr_other.getY(),
                                  m_x * fr_other.getZ(),
                                  m_y * fr_other.getX(), m_y * fr_other.getY(),
                                  m_y * fr_other.getZ(),
                                  m_z * fr_other.getX(), m_z * fr_other.getY(),
                                  m_z * fr_other.getZ() );
}


/* ********************************* METHOD **********************************/
/**
 * The cross product of two vectors is defined as
 * \f{eqnarray}
 \vec{a} \times \vec{b} &=& \left( \begin{array}{c}
 a_y b_z - a_z b_y \\
 a_z b_x - a_x b_z \\
 a_x b_y - a_y b_x
 \end{array}
 \right)
 \f}
 * where the vector \f$ \vec{a} \f$ is represented by this object, and
 * the vector \f$ b \f$ is given as the argument.
 *
 *
 * \brief     Calculate the cross product of this vector and the given one.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Right hand operand.
 * \return    Returns the result of the cross product operation.
 *
 *****************************************************************************/
template< class _DataType >
template< class _OtherType >
inline
Math3d::Vector3d< _DataType >
Math3d::Vector3d< _DataType >::crossProduct(
        const Vector3d< _OtherType >&  fr_other ) const
{
    

    Vector3d< _DataType > temp( m_y * fr_other.getZ() - m_z * fr_other.getY(),
                                m_z * fr_other.getX() - m_x * fr_other.getZ(),
                                m_x * fr_other.getY() - m_y * fr_other.getX() );
    return temp;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Assignment operator.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \param[in] fr_other - Reference to the object to copy from.
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Vector3d< _DataType >&
Math3d::Vector3d< _DataType >::operator= ( const Vector3d< _DataType >& fr_other )
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
 * \date      Mai 01, 2008
 *
 * \param[in] fr_other - Reference to the object to copy from.
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
template< class _OtherType >
inline
Math3d::Vector3d< _DataType >&
Math3d::Vector3d< _DataType >::operator= ( const Vector3d< _OtherType >& fr_other )
{
    ;

    copyFrom( fr_other );



    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Addition operator.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \param[in] fr_other - Reference to the object to add to this one.
 * \return    Returns a reference to this object.
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Vector3d< _DataType >&
Math3d::Vector3d< _DataType >::operator+=( const Vector3d< _DataType >& fr_other )
{
    ;

    m_x += fr_other.m_x;
    m_y += fr_other.m_y;
    m_z += fr_other.m_z;



    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Substraction operator.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \param[in] fr_other - Reference to the object to add to this one.
 * \return    Returns a reference to this object.
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Vector3d< _DataType >&
Math3d::Vector3d< _DataType >::operator-=( const Vector3d< _DataType >& fr_other )
{
    ;

    m_x -= fr_other.m_x;
    m_y -= fr_other.m_y;
    m_z -= fr_other.m_z;



    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Access an element of the Vector3d object. Index starts at 0.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \param[in] f_index_ui - Index (starts at 0).
 * \return    Returns a reference to the element.
 *
 *****************************************************************************/

//!!!TODO!!! remove because it's slow
template< class _DataType >
inline
_DataType&
Math3d::Vector3d< _DataType >::operator()( const uint32 f_index_ui )
{
    

    if ( f_index_ui == 0 )
        return m_x;

    else if ( f_index_ui == 1 )
        return m_y;

    else
        return m_z;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Access an element of the Vector3d object. Index starts at 0.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \param[in] f_index_ui - Index (starts at 0).
 * \return    Returns the value of the element.
 *****************************************************************************/
template< class _DataType >
inline
_DataType
Math3d::Vector3d< _DataType >::operator()( const uint32 f_index_ui ) const
{
    

    if ( f_index_ui == 0 )
        return m_x;

    else if ( f_index_ui == 1 )
        return m_y;

    else
        return m_z;
}



/* ********************************* METHOD **********************************/
/**
 * \brief     Copy the data from another object into this one.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \param[in] fr_other - Reference to the other object.
 *
 *****************************************************************************/
template< class _DataType >
template< class _OtherType >
inline
void
Math3d::Vector3d< _DataType >::copyFrom( const Vector3d< _OtherType >& fr_other )
{
    ;

    m_x = _DataType( fr_other.getX() );
    m_y = _DataType( fr_other.getY() );
    m_z = _DataType( fr_other.getZ() );


}




/* ********************************* METHOD **********************************/
/**
 * \brief     Normalize the vector, so that length() is 1.
 *
 * \author    Clemens Rabe
 * \date      Mai 01, 2008
 *
 * \param[in] fr_vector - Reference to the vector to normalize.
 * \return    Returns a the normalized vector.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Vector3d< _DataType >
Math3d::normalize( const Math3d::Vector3d< _DataType >& fr_vector )
{
    ;

    Vector3d< _DataType > temp( fr_vector );
    temp.normalize();



    return temp;
}


/* ********************************* METHOD **********************************/
/**
 * The inner product of two vectors is also known as the dot product or
 * scalar product. It is defined as:
 * \f{eqnarray}
 \vec{a} \cdot \vec{b} &=& \sum_{i=1}^{n} a_i b_i
 \f}
 * and is related to the angle \f$ \alpha \f$ between the two vectors by
 * \f{eqnarray}
 \vec{a} \cdot \vec{b} &=& \left| a \right| \left| b \right| \cos \alpha
 \f}
 *
 *
 * \brief     Calculate the inner product, also known as the dot product or
 *            scalar product.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_left  - Left operand.
 * \param[in] fr_right - Right operand.
 * \return    Returns the value of the inner product, a scalar.
 *
 *****************************************************************************/
template< class _DataType, class _OtherType >
inline
double
Math3d::innerProduct( const Vector3d< _DataType >&  fr_left,
                      const Vector3d< _OtherType >& fr_right )
{
    return fr_left.innerProduct( fr_right );
}


/* ********************************* METHOD **********************************/
/**
 * The outer product of two vectors is defined as
 * \f{eqnarray}
 \vec{a} \vec{b}^{\top} &=& \left[ \begin{array}{ccc}
 a_x b_x & a_x b_y & a_x b_z \\
 a_y b_x & a_y b_y & a_y b_z \\
 a_z b_x & a_z b_y & a_z b_z
 \end{array}
 \right]
 \f}
 * where the vector \f$ \vec{a} \f$ corresponds to the left hand operand.
 *
 *
 * \brief     Calculate the outer product of this vector and the transposed
 *            given vector.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_left  - Left operand.
 * \param[in] fr_right - Right operand.
 * \return    Returns a 3x3 matrix containing the outer product.
 *
 *****************************************************************************/
template< class _DataType, class _OtherType >
inline
Math3d::Matrix3d< _DataType >
Math3d::outerProduct( const Vector3d< _DataType >&  fr_left,
                      const Vector3d< _OtherType >& fr_right )
{
    return fr_left.outerProduct( fr_right );
}


/* ********************************* METHOD **********************************/
/**
 * The cross product of two vectors is defined as
 * \f{eqnarray}
 \vec{a} \times \vec{b} &=& \left( \begin{array}{c}
 a_y b_z - a_z b_y \\
 a_z b_x - a_x b_z \\
 a_x b_y - a_y b_x
 \end{array}
 \right)
 \f}
 * where the vector \f$ \vec{a} \f$ is represented by the first argument, and
 * the vector \f$ b \f$ is the second argument.
 *
 *
 * \brief     Calculate the cross product of two vectors.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_left  - Left operand.
 * \param[in] fr_right - Right operand.
 * \return    Returns the result of the cross product operation.
 *
 *****************************************************************************/
template< class _DataType, class _OtherType >
Math3d::Vector3d< _DataType >
Math3d::crossProduct( const Vector3d< _DataType >&  fr_left,
                      const Vector3d< _OtherType >& fr_right )
{
    return fr_left.crossProduct( fr_right );
}




#endif /* _VECTOR3D_H */

/*****************************************************************************
|----------------------------------------------------------------------------|
| R E V I S I O N   H I S T O R Y                                            |
|----------------------------------------------------------------------------|

$Log: vector3d.h  $
Revision 1.1 2021/12/13 17:20:03CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/adapter/conv_images/cct_i400/project.pj
Revision 1.0 2017/03/03 10:30:39CET Sorge, Sven (uidg3181) 
Initial revision
Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/adapter/converters/conv_images/cct_i400/project.pj
Revision 1.1 2012/11/29 15:32:15CET Thiel, Robert (thielr) 
Initial revision
Member added to project /nfs/projekte1/PROJECTS/MFC400/06_Algorithm/04_Engineering/01_Source_Code/algo/cct/project.pj
Revision 1.3 2011/04/15 16:46:18CEST Bachmann Alexander (uidt5584) (uidt5584) 
GIT update (Commit:5b0892f3ddd8fd69d47059fe2183d97e65914453)
--- Added comments ---  uidt5584 [Apr 15, 2011 4:46:18 PM CEST]
Change Package : 52130:2 http://mks-psad:7002/im/viewissue?selection=52130
Revision 1.1 2011/03/09 16:34:41CET Wagner Ulrich (uid04769) (uid04769) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SFOD_StereoFastObjectDetection/04_Engineering/01_Source_Code/Kernel/kernel_common/math3d/h/project.pj
Revision 1.5 2010/10/27 14:21:10CEST Wagner Ulrich (uid04769) (uid04769) 
GIT merge
--- Added comments ---  uid04769 [Oct 27, 2010 2:21:10 PM CEST]
Change Package : 37878:1 http://mks-psad:7002/im/viewissue?selection=37878
Revision 1.2 2010/02/24 11:18:19CET mdarms
Initial commit.
--- Added comments ---  mdarms [2010/02/24 10:18:20Z]
Change Package : 26827:2 http://LISS014:6001/im/viewissue?selection=26827
Revision 1.2  2010-02-11 10:58:30  iprep
gehrig: math3d wo newmat, paramReader commonData hardwired

Revision 1.4  2010-02-11 09:36:25  iprep
rabe: Remaining newmat stuff fixed.

Revision 1.3  2009-09-22 15:51:58  iprep
rabe+folkerts: boost optional

Revision 1.2  2009-07-21 08:46:40  iprep
rabe: Warnings of gcc 4.1.2 fixed.

Revision 1.1  2008-05-05 09:20:22  iprep
rabe: First version.


******************************************************************************/

/*****************************************************************************
 * END OF FILE
 ******************************************************************************/
