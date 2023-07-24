/* ********************************* FILE ************************************/
/** \file    motion3d.h
 *
 * \brief    This file describes the declaration of the class Motion3d.
 *
 * \author   Clemens Rabe
 * \date     Mai 03, 2008
 * \note     (C) Copyright Daimler AG, GR/EAP
 *
 ******************************************************************************/
#ifndef _MOTION3D_H
#define _MOTION3D_H


/*****************************************************************************
 * INCLUDE FILES
 ******************************************************************************/


#include "algo_glob.h"
#include <math.h>


#include "rotation3d.h"
#include "vector3d.h"


/*****************************************************************************
 * FORWARD DECLARATIONS
 ******************************************************************************/


/*****************************************************************************
 * DECLARATIONS OF EXPORTED CLASSES
 ******************************************************************************/


namespace Math3d
{


    /* ******************************** CLASS ************************************/
    /**
     *
     * \brief  This class represents a 4x4 motion matrix, containing a 3x3
     *         rotation matrix and a translation vector.
     *
     * \author Clemens Rabe
     * \date   Mai 03, 2008
     * \sa     -
     *****************************************************************************/
    template < class _DataType = float32 >
    class Motion3d
    {

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
        Motion3d();
        Motion3d( const Motion3d< _DataType >&   fr_other );

        template< class _OtherType >
        Motion3d( const Motion3d< _OtherType >&   fr_other );

        template< class _RotType, class _TransType >
        Motion3d( const Rotation3d< _RotType >&  fr_rotation,
                  const Vector3d< _TransType >&  fr_translation );

        // Destructor.
        virtual ~Motion3d();


        /******************************************************
         * methods
         ******************************************************/

        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Read methods (getter).
        ///@{

        const Rotation3d< _DataType >& getRotation() const
        {
            return m_rotation;
        }
        Rotation3d< _DataType >&       getRotation()
        {
            return m_rotation;
        }

        const Vector3d< _DataType >&   getTranslation() const
        {
            return m_translation;
        }
        Vector3d< _DataType >&         getTranslation()
        {
            return m_translation;
        }

        _DataType&                     element( const uint32 f_column_ui,
                                                const uint32 f_row_ui );
        _DataType                      element( const uint32 f_column_ui,
                                                const uint32 f_row_ui ) const;

        Vector3d< _DataType >          getColumnVector( const uint32 f_column_ui ) const;

        ///@}


        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Write methods (setter).
        ///@{

        template< class _RotType, class _TransType >
        void set(            const Rotation3d< _RotType >&  fr_rotation,
                             const Vector3d< _TransType >&  fr_translation );

        template< class _RotType >
        void setRotation(    const Rotation3d< _RotType >&  fr_rotation );

        template< class _TransType >
        void setTranslation( const Vector3d< _TransType >&  fr_translation );

        void setElement(     const _DataType                f_value,
                             const uint32                 f_column_ui,
                             const uint32                 f_row_ui );
        void set(            const _DataType                f_00,
                             const _DataType                f_01,
                             const _DataType                f_02,
                             const _DataType                f_03,
                             const _DataType                f_10,
                             const _DataType                f_11,
                             const _DataType                f_12,
                             const _DataType                f_13,
                             const _DataType                f_20,
                             const _DataType                f_21,
                             const _DataType                f_22,
                             const _DataType                f_23 );

        void clear();

        ///@}


        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Operations.
        ///@{

        Motion3d< _DataType >& invert();

        ///@}


        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Operator overloading.
        ///@{

        Motion3d< _DataType >&  operator= ( const Motion3d< _DataType >&  fr_other );


        template< class _OtherType >
        Motion3d< _DataType >&  operator= ( const Motion3d< _OtherType >& fr_other );

        Motion3d< _DataType >&  operator*=( const Motion3d< _DataType >&  fr_other );
        Motion3d< _DataType >&  operator/=( const Motion3d< _DataType >&  fr_other );


        template< class _RotType >
        Motion3d< _DataType >&  operator= ( const Rotation3d< _RotType >& fr_other );

        template< class _TransType >
        Motion3d< _DataType >&  operator= ( const Vector3d< _TransType >& fr_other );


        template< class _RotType >
        Motion3d< _DataType >&  operator*=( const Rotation3d< _RotType >& fr_other );

        template< class _RotType >
        Motion3d< _DataType >&  operator/=( const Rotation3d< _RotType >& fr_other );


        template< class _TransType >
        Motion3d< _DataType >&  operator+=( const Vector3d< _TransType >& fr_other );

        template< class _TransType >
        Motion3d< _DataType >&  operator-=( const Vector3d< _TransType >& fr_other );


        template< class _OtherType >
        Vector3d< _OtherType > const operator* ( const Vector3d< _OtherType >& fr_other ) const;

        template< class _OtherType >
        void applyTransformation ( const Vector3d< _OtherType >& fr_other,
                                   Vector3d< _OtherType >& fr_result) const;

        template< class _OtherType >
        void applyTransformation ( const _OtherType& x, 
                                   const _OtherType& y, 
                                   const _OtherType& z,
                                   _OtherType& rx, 
                                   _OtherType& ry,
                                   _OtherType& rz) const;
       

        _DataType& operator()( const uint32 f_column_ui,
                               const uint32 f_row_ui );
        _DataType  operator()( const uint32 f_column_ui,
                               const uint32 f_row_ui ) const;

        ///@}



        //------------------------------------------------------------------
    protected:

        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Protected methods.
        ///@{

        template< class _OtherType >
        void copyFrom( const Motion3d< _OtherType >&   fr_other );

        ///@}


        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Protected slots.
        ///@{

        /// Rotation component
        Rotation3d< _DataType >  m_rotation;
        const _DataType* m_rotMatrix;

        /// Translation component
        Vector3d< _DataType >    m_translation;

        ///@}

    };


    /*****************************************************************************
     * GLOBAL OPERATORS.
     ******************************************************************************/

    // Multiplication and division ( multiplication with inverse ) with Motion3d
    template< class _DataType, class _OtherType >
    Motion3d< _DataType >
    operator* ( const Motion3d< _DataType >&   fr_left,
                const Motion3d< _OtherType >&  fr_right );

    template< class _DataType, class _OtherType >
    Motion3d< _DataType >
    operator/ ( const Motion3d< _DataType >&   fr_left,
                const Motion3d< _OtherType >&  fr_right );


    // Multiplication and division ( multiplication with inverse ) with Rotation3d
    template< class _DataType, class _OtherType >
    Motion3d< _DataType >
    operator* ( const Motion3d< _DataType >&     fr_left,
                const Rotation3d< _OtherType >&  fr_right );

    template< class _DataType, class _OtherType >
    Motion3d< _DataType >
    operator* ( const Rotation3d< _OtherType >&  fr_left,
                const Motion3d< _DataType >&     fr_right );


    template< class _DataType, class _OtherType >
    Motion3d< _DataType >
    operator/ ( const Motion3d< _DataType >&     fr_left,
                const Rotation3d< _OtherType >&  fr_right );

    template< class _DataType, class _OtherType >
    Motion3d< _DataType >
    operator/ ( const Rotation3d< _OtherType >&  fr_left,
                const Motion3d< _DataType >&     fr_right );


    // Addition and substraction with Vector3d
    template< class _DataType, class _OtherType >
    Motion3d< _DataType >
    operator+ ( const Motion3d< _DataType >&     fr_left,
                const Vector3d< _OtherType >&    fr_right );

    template< class _DataType, class _OtherType >
    Motion3d< _DataType >
    operator+ ( const Vector3d< _OtherType >&    fr_left,
                const Motion3d< _DataType >&     fr_right );


    template< class _DataType, class _OtherType >
    Motion3d< _DataType >
    operator- ( const Motion3d< _DataType >&     fr_left,
                const Vector3d< _OtherType >&    fr_right );

    template< class _DataType, class _OtherType >
    Motion3d< _DataType >
    operator- ( const Vector3d< _OtherType >&    fr_left,
                const Motion3d< _DataType >&     fr_right );



    template< class _DataType >
    Motion3d< _DataType >
    invert(      const Motion3d< _DataType >&   fr_mat );

} // end namespace Math3d




/*****************************************************************************
 * IMPLEMENTATION
 ******************************************************************************/


/* ********************************* METHOD **********************************/
/**
 * \brief     Default constructor.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Motion3d< _DataType >::Motion3d()
        : m_rotation(),
          m_rotMatrix( m_rotation.getMatrix() ),
          m_translation()
{
    
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Copy constructor.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Object to copy.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Motion3d< _DataType >::Motion3d( const Motion3d< _DataType >&   fr_other )
        : m_rotation(    fr_other.getRotation()    ),
          m_rotMatrix( m_rotation.getMatrix() ),
          m_translation( fr_other.getTranslation() )
{
    
}




/* ********************************* METHOD **********************************/
/**
 * \brief     Copy constructor.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Object to copy.
 *
 *****************************************************************************/
template< class _DataType >
template< class _OtherType >
inline
Math3d::Motion3d< _DataType >::Motion3d( const Motion3d< _OtherType >&   fr_other )
        : m_rotation(),
          m_rotMatrix( m_rotation.getMatrix() ),
          m_translation()
{
    ;

    copyFrom( fr_other );


}


/* ********************************* METHOD **********************************/
/**
 * \brief     Construct the motion matrix from a rotation and a translation.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_rotation    - Rotation.
 * \param[in] fr_translation - Translation
 *
 *****************************************************************************/
template< class _DataType >
template< class _RotType, class _TransType >
inline
Math3d::Motion3d< _DataType >::Motion3d( const Rotation3d< _RotType >&  fr_rotation,
                                         const Vector3d< _TransType >&  fr_translation )
        : m_rotation(    fr_rotation    ),
          m_rotMatrix( m_rotation.getMatrix() ),
          m_translation( fr_translation )
{
    
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Destructor.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Motion3d< _DataType >::~Motion3d()
{}


/* ********************************* METHOD **********************************/
/**
 * \brief     Get access to a matrix element.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] f_column_ui - Column between 0 and 3.
 * \param[in] f_row_ui    - Row between 0 and 2.
 * \return    Returns the element.
 *
 *****************************************************************************/
template< class _DataType >
inline
_DataType&
Math3d::Motion3d< _DataType >::element( const uint32 f_column_ui,
                                        const uint32 f_row_ui )
{
    

    if ( f_column_ui == 3 )
        return m_translation( f_row_ui );

    return m_rotation( f_column_ui, f_row_ui );
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Get access to a matrix element.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] f_column_ui - Column between 0 and 3.
 * \param[in] f_row_ui    - Row between 0 and 2.
 * \return    Returns the element.
 *
 *****************************************************************************/
template< class _DataType >
inline
_DataType
Math3d::Motion3d< _DataType >::element( const uint32 f_column_ui,
                                        const uint32 f_row_ui ) const
{
    

    if ( f_column_ui == 3 )
        return m_translation( f_row_ui );

    return m_rotation( f_column_ui, f_row_ui );
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
Math3d::Motion3d< _DataType >::getColumnVector( const uint32 f_column_ui ) const
{
    

    if ( f_column_ui == 3 )
        return m_translation;

    return m_rotation.getColumnVector( f_column_ui );
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Set the rotation and translation of the motion matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_rotation    - Rotation.
 * \param[in] fr_translation - Translation
 *
 *****************************************************************************/
template< class _DataType >
template< class _RotType, class _TransType >
inline
void
Math3d::Motion3d< _DataType >::set( const Rotation3d< _RotType >&  fr_rotation,
                                    const Vector3d< _TransType >&  fr_translation )
{
    ;

    m_rotation    = fr_rotation;
    m_translation = fr_translation;


}


/* ********************************* METHOD **********************************/
/**
 * \brief     Set the rotation of the motion matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_rotation    - Rotation.
 *
 *****************************************************************************/
template< class _DataType >
template< class _RotType >
inline
void
Math3d::Motion3d< _DataType >::setRotation(
        const Rotation3d< _RotType >&  fr_rotation )
{
    m_rotation    = fr_rotation;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Set the translation of the motion matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_translation - Translation
 *
 *****************************************************************************/
template< class _DataType >
template< class _TransType >
inline
void
Math3d::Motion3d< _DataType >::setTranslation(
        const Vector3d< _TransType >&  fr_translation )
{

    m_translation = fr_translation;

}


/* ********************************* METHOD **********************************/
/**
 * \brief     Set a matrix element.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] f_value     - Value of the element.
 * \param[in] f_column_ui - Column between 0 and 3.
 * \param[in] f_row_ui    - Row between 0 and 2.
 *
 *****************************************************************************/
template< class _DataType >
inline
void
Math3d::Motion3d< _DataType >::setElement(
        const _DataType                f_value,
        const uint32                 f_column_ui,
        const uint32                 f_row_ui )
{
    ;

    if ( f_column_ui == 3 )
        m_translation( f_row_ui ) = f_value;

    else
        m_rotation.setElement( f_value, f_column_ui, f_row_ui );


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
 * \param[in] f_03 - Element of row=0, col=3.
 * \param[in] f_10 - Element of row=1, col=0.
 * \param[in] f_11 - Element of row=1, col=1.
 * \param[in] f_12 - Element of row=1, col=2.
 * \param[in] f_13 - Element of row=1, col=3.
 * \param[in] f_20 - Element of row=2, col=0.
 * \param[in] f_21 - Element of row=2, col=1.
 * \param[in] f_22 - Element of row=2, col=2.
 * \param[in] f_23 - Element of row=2, col=3.
 *
 *****************************************************************************/
template< class _DataType >
inline
void
Math3d::Motion3d< _DataType >::set(
        const _DataType                f_00,
        const _DataType                f_01,
        const _DataType                f_02,
        const _DataType                f_03,
        const _DataType                f_10,
        const _DataType                f_11,
        const _DataType                f_12,
        const _DataType                f_13,
        const _DataType                f_20,
        const _DataType                f_21,
        const _DataType                f_22,
        const _DataType                f_23
        )
{

    m_rotation.set( f_00, f_01, f_02,
                    f_10, f_11, f_12,
                    f_20, f_21, f_22 );
    m_translation.set( f_03,
                       f_13,
                       f_23 );

}


/* ********************************* METHOD **********************************/
/**
 * \brief     Reset the motion matrix by setting the rotation to identity,
 *            and the translation vector to 0.
 *
 * \author    Clemens Rabe
 * \date      Aug 16, 2008
 *
 *****************************************************************************/
template< class _DataType >
inline
void
Math3d::Motion3d< _DataType >::clear()
{
    ;

    m_rotation.clear();
    m_translation.set( 0.0, 0.0, 0.0 );


}


/* ********************************* METHOD **********************************/
/**
 * The inverse of a motion matrix, composed of the rotation matrix \f$ R \f$
 * and the translation vector \f$ \vec{t} \f$
 * \f{eqnarray}
 M &=& \left[ \begin{array}{cc}
 R & \vec{t} \\
 0 & 1
 \end{array} \right]
 \f}
 * is calculated as
 * \f{eqnarray}
 M^{-1} &=& \left[ \begin{array}{cc}
 R^{-1} & - R^{-1} \vec{t} \\
 0 & 1
 \end{array} \right]
 \f}
 *
 *
 * \brief     Invert the motion matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Motion3d< _DataType >&
Math3d::Motion3d< _DataType >::invert()
{
    ;

    m_rotation.invert();
    m_translation =  m_rotation * m_translation;  // rotation is now inverted
    m_translation *= -1.0;



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
Math3d::Motion3d< _DataType >&
Math3d::Motion3d< _DataType >::operator= ( const Motion3d< _DataType >&  fr_other )
{

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
Math3d::Motion3d< _DataType >&
Math3d::Motion3d< _DataType >::operator= ( const Motion3d< _OtherType >&  fr_other )
{
    ;

    copyFrom( fr_other );



    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * A motion matrix composed of the rotation matrix \f$ R \f$
 * and the translation vector \f$ \vec{t} \f$
 * \f{eqnarray}
 M_0 &=& \left[ \begin{array}{cc}
 R_0 & \vec{t}_0 \\
 0 & 1
 \end{array} \right]
 \f}
 * is multiplied with a motion matrix \f$ M_1 \f$ according to
 * \f{eqnarray}
 M_0 M_1 &=& \left[ \begin{array}{cc}
 R_0 & \vec{t}_0 \\
 0   & 1
 \end{array} \right]
 \left[ \begin{array}{cc}
 R_1 & \vec{t}_1 \\
 0   & 1
 \end{array} \right] \\
 &=& \left[ \begin{array}{cc}
 R_0 R_1 & \vec{t}_0 + R_0 \vec{t}_1 \\
 0       & 1
 \end{array} \right]
 \f}
 *
 *
 *
 * \brief     Multiplication operator.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Object to multiply.
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Motion3d< _DataType >&
Math3d::Motion3d< _DataType >::operator*= ( const Motion3d< _DataType >&  fr_other )
{
    ;

    m_translation += m_rotation * fr_other.m_translation;
    m_rotation    *= fr_other.m_rotation;



    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Division operator.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Object to multiply with its inverse.
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Motion3d< _DataType >&
Math3d::Motion3d< _DataType >::operator/= ( const Motion3d< _DataType >&  fr_other )
{
    ;

    Motion3d< _DataType > temp( fr_other );
    temp.invert();

    m_translation += m_rotation * temp.m_translation;
    m_rotation    *= temp.m_rotation;



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
template< class _RotType >
inline
Math3d::Motion3d< _DataType >&
Math3d::Motion3d< _DataType >::operator= ( const Rotation3d< _RotType >& fr_other )
{
    ;

    m_rotation = fr_other;



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
template< class _TransType >
inline
Math3d::Motion3d< _DataType >&
Math3d::Motion3d< _DataType >::operator= ( const Vector3d< _TransType >& fr_other )
{
    ;

    m_translation = fr_other;



    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Multiplication operator. Multiplication is only applied to the
 *            rotational part.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Rotation matrix to multiply.
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
template< class _RotType >
inline
Math3d::Motion3d< _DataType >&
Math3d::Motion3d< _DataType >::operator*= ( const Rotation3d< _RotType >&  fr_other )
{
    ;

    m_rotation    *= fr_other;



    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Division operator. Division is only applied to the
 *            rotational part.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Rotation matrix to multiply.
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
template< class _RotType >
inline
Math3d::Motion3d< _DataType >&
Math3d::Motion3d< _DataType >::operator/= ( const Rotation3d< _RotType >&  fr_other )
{
    ;

    m_rotation    /= fr_other;



    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Addition operator. Addition is only applied to the translational
 *            part.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Translation to add.
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
template< class _TransType >
inline
Math3d::Motion3d< _DataType >&
Math3d::Motion3d< _DataType >::operator+= ( const Vector3d< _TransType >& fr_other )
{
    ;

    m_translation += fr_other;



    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Subtraction operator. Subtraction is only applied to the translational
 *            part.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Translation to subtract.
 * \return    Returns a reference to this object.
 *
 *****************************************************************************/
template< class _DataType >
template< class _TransType >
inline
Math3d::Motion3d< _DataType >&
Math3d::Motion3d< _DataType >::operator-= ( const Vector3d< _TransType >& fr_other )
{
    ;

    m_translation -= fr_other;



    return *this;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Multiply a vector with this matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_other - Vector to multiply with this matrix.
 * \return    Returns the resulting vector.
 *
 *****************************************************************************/
template< class _DataType >
template< class _OtherType >
inline
Math3d::Vector3d< _OtherType > const
Math3d::Motion3d< _DataType >::operator* ( const Vector3d< _OtherType >& fr_other ) const
{
    ;

    Vector3d< _DataType > temp;
    temp = m_rotation * fr_other + m_translation;



    return temp;
}

/* ********************************* METHOD **********************************/
/**
 * \brief     Apply the transformation for a vector (faster than the generic multiplication)
 *
 * \author    Michael Darms
 * \date      Junly 08, 2010
 *
 *
 *****************************************************************************/

template< class _DataType >
template< class _OtherType >
inline
void
Math3d::Motion3d< _DataType >::applyTransformation ( const Vector3d< _OtherType >& fr_other, Vector3d< _OtherType >& fr_result ) const
{
    fr_result.setX( m_rotMatrix[0]*fr_other.getX() + m_rotMatrix[1]*fr_other.getY() + m_rotMatrix[2]*fr_other.getZ() + m_translation.getX() );
    fr_result.setY( m_rotMatrix[3]*fr_other.getX() + m_rotMatrix[4]*fr_other.getY() + m_rotMatrix[5]*fr_other.getZ() + m_translation.getY() );
    fr_result.setZ( m_rotMatrix[6]*fr_other.getX() + m_rotMatrix[7]*fr_other.getY() + m_rotMatrix[8]*fr_other.getZ() + m_translation.getZ() );
}

template< class _DataType >
template< class _OtherType >
inline
void
Math3d::Motion3d< _DataType >::applyTransformation ( const _OtherType& x, const _OtherType& y, const _OtherType& z, _OtherType& rx, _OtherType& ry, _OtherType& rz ) const
{
    rx = ( m_rotMatrix[0] * x + m_rotMatrix[1] * y + m_rotMatrix[2] * z + m_translation.getX() );
    ry = ( m_rotMatrix[3] * x + m_rotMatrix[4] * y + m_rotMatrix[5] * z + m_translation.getY() );
    rz = ( m_rotMatrix[6] * x + m_rotMatrix[7] * y + m_rotMatrix[8] * z + m_translation.getZ() );
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
inline _DataType &Math3d::Motion3d< _DataType >::operator()( const uint32 f_column_ui,
                                           const uint32 f_row_ui )
{
    

    if ( f_column_ui == 3 )
        return m_translation( f_row_ui );

    return m_rotation( f_column_ui, f_row_ui );
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
Math3d::Motion3d< _DataType >::operator()( const uint32 f_column_ui,
                                           const uint32 f_row_ui ) const
{
    

    if ( f_column_ui == 3 )
        return m_translation( f_row_ui );

    return m_rotation( f_column_ui, f_row_ui );
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
Math3d::Motion3d< _DataType >::copyFrom( const Motion3d< _OtherType >&   fr_other )
{
    ;

    m_rotation    = fr_other.getRotation();
    m_translation = fr_other.getTranslation();


}

template< class _DataType, class _OtherType >
inline
Math3d::Motion3d< _DataType >
Math3d::operator* ( const Motion3d< _DataType >&   fr_left,
                    const Motion3d< _OtherType >&  fr_right )
{
    ;

    Motion3d< _DataType > temp( fr_left );
    temp *= fr_right;



    return temp;
}


template< class _DataType, class _OtherType >
inline
Math3d::Motion3d< _DataType >
Math3d::operator/ ( const Motion3d< _DataType >&   fr_left,
                    const Motion3d< _OtherType >&  fr_right )
{
    ;

    Motion3d< _DataType > temp( fr_left );
    temp /= fr_right;



    return temp;
}


// Multiplication and division ( multiplication with inverse ) with Rotation3d
template< class _DataType, class _OtherType >
inline
Math3d::Motion3d< _DataType >
Math3d::operator* ( const Motion3d< _DataType >&     fr_left,
                    const Rotation3d< _OtherType >&  fr_right )
{
    ;

    Motion3d< _DataType > temp( fr_left );
    temp *= fr_right;



    return temp;
}


template< class _DataType, class _OtherType >
inline
Math3d::Motion3d< _DataType >
Math3d::operator* ( const Rotation3d< _OtherType >&  fr_left,
                    const Motion3d< _DataType >&     fr_right )
{
    ;

    Motion3d< _DataType > temp( fr_left * fr_right.getRotation(),
                                fr_right.getTranslation() );



    return temp;
}



template< class _DataType, class _OtherType >
inline
Math3d::Motion3d< _DataType >
Math3d::operator/ ( const Motion3d< _DataType >&     fr_left,
                    const Rotation3d< _OtherType >&  fr_right )
{
    ;

    Motion3d< _DataType > temp( fr_left );
    temp /= fr_right;



    return temp;
}


template< class _DataType, class _OtherType >
inline
Math3d::Motion3d< _DataType >
Math3d::operator/ ( const Rotation3d< _OtherType >&  fr_left,
                    const Motion3d< _DataType >&     fr_right )
{
    

    return fr_left * invert( fr_right );
}



// Addition and substraction with Vector3d
template< class _DataType, class _OtherType >
inline
Math3d::Motion3d< _DataType >
Math3d::operator+ ( const Motion3d< _DataType >&     fr_left,
                    const Vector3d< _OtherType >&    fr_right )
{
    ;

    Motion3d< _DataType > temp( fr_left );
    temp += fr_right;



    return temp;
}


template< class _DataType, class _OtherType >
inline
Math3d::Motion3d< _DataType >
Math3d::operator+ ( const Vector3d< _OtherType >&    fr_left,
                    const Motion3d< _DataType >&     fr_right )
{
    ;

    Motion3d< _DataType > temp( fr_right );
    temp += fr_right;



    return temp;
}



template< class _DataType, class _OtherType >
inline
Math3d::Motion3d< _DataType >
Math3d::operator- ( const Motion3d< _DataType >&     fr_left,
                    const Vector3d< _OtherType >&    fr_right )
{
    ;

    Motion3d< _DataType > temp( fr_left );
    temp -= fr_right;



    return temp;
}


template< class _DataType, class _OtherType >
inline
Math3d::Motion3d< _DataType >
Math3d::operator- ( const Vector3d< _OtherType >&    fr_left,
                    const Motion3d< _DataType >&     fr_right )
{
    ;

    Motion3d< _DataType > temp( fr_right.getRotation(),
                                fr_left - fr_right.getTranslation() );



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
Math3d::Motion3d< _DataType >
Math3d::invert( const Motion3d< _DataType >&   fr_mat )
{

    Motion3d< _DataType > temp( fr_mat );
    temp.invert();

    return temp;
}



#endif /* _MOTION3D_H */

/*****************************************************************************
|----------------------------------------------------------------------------|
| R E V I S I O N   H I S T O R Y                                            |
|----------------------------------------------------------------------------|

$Log: motion3d.h  $
Revision 1.1 2021/12/13 17:20:02CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/adapter/conv_images/cct_i400/project.pj
Revision 1.0 2017/03/03 10:30:38CET Sorge, Sven (uidg3181) 
Initial revision
Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/adapter/converters/conv_images/cct_i400/project.pj
Revision 1.1 2012/11/29 15:32:11CET Thiel, Robert (thielr) 
Initial revision
Member added to project /nfs/projekte1/PROJECTS/MFC400/06_Algorithm/04_Engineering/01_Source_Code/algo/cct/project.pj
Revision 1.3 2011/04/15 16:46:17CEST Bachmann Alexander (uidt5584) (uidt5584) 
GIT update (Commit:5b0892f3ddd8fd69d47059fe2183d97e65914453)
--- Added comments ---  uidt5584 [Apr 15, 2011 4:46:17 PM CEST]
Change Package : 52130:2 http://mks-psad:7002/im/viewissue?selection=52130
Revision 1.1 2011/03/09 16:34:40CET Wagner Ulrich (uid04769) (uid04769) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SFOD_StereoFastObjectDetection/04_Engineering/01_Source_Code/Kernel/kernel_common/math3d/h/project.pj
Revision 1.6 2010/10/27 14:21:38CEST Wagner Ulrich (uid04769) (uid04769) 
GIT merge
--- Added comments ---  uid04769 [Oct 27, 2010 2:21:38 PM CEST]
Change Package : 37878:1 http://mks-psad:7002/im/viewissue?selection=37878
Revision 1.3 2010/08/10 16:52:55CEST Michael Darms (darmsm)
Added methods  applyTransformation for performance reasons.
--- Added comments ---  darmsm [Aug 10, 2010 4:52:55 PM CEST]
Change Package : 26827:2 http://mks-psad:7002/im/viewissue?selection=26827
Revision 1.2 2010/02/24 11:18:18CET Michael Darms (mdarms)
Initial commit.
--- Added comments ---  mdarms [2010/02/24 10:18:18Z]
Change Package : 26827:2 http://LISS014:6001/im/viewissue?selection=26827
Revision 1.2  2010-02-11 10:58:30  iprep
gehrig: math3d wo newmat, paramReader commonData hardwired

Revision 1.5  2010-02-10 13:36:51  iprep
rabe: Newmat optional now.

Revision 1.4  2009-09-22 15:51:58  iprep
rabe+folkerts: boost optional

Revision 1.3  2009-08-04 14:33:07  iprep
rabe: Multiplication with vector made const.

Revision 1.2  2008-08-18 08:20:00  iprep
rabe: Added clear method and optimized copy constructor.

Revision 1.1  2008-05-05 09:20:22  iprep
rabe: First version.


******************************************************************************/

/*****************************************************************************
 * END OF FILE
 ******************************************************************************/
