/* ********************************* FILE ************************************/
/** \file    rotation3d.h
 *
 * \brief    This file describes the declaration of the class Rotation3d.
 *
 * \author   Clemens Rabe
 * \date     Mai 02, 2008
 * \note     (C) Copyright Daimler AG, GR/EAP
 *
 ******************************************************************************/
#ifndef _ROTATION3D_H
#define _ROTATION3D_H


/*****************************************************************************
 * INCLUDE FILES
 ******************************************************************************/

#include "matrix3d.h"



#include "algo_type.h"
#include <math.h>



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
     * This class represents an 3x3 rotation matrix. The rotation matrix can be
     * interpreted in different ways:
     *  - Rotation around X, Y, and Z axis with the angles alpha, beta, gamma.
     *    The rotation is performed in this order.
     *  - Rotation around a given vector v with an angle delta.
     *  - Using quaternions (4 dimensional vector). Quaternions are used mostly
     *    to avoid the so called gimbal lock, or to interpolate between two
     *    rotations.
     *
     * \par Rotation using Euler Angles:
     * To rotate a point \f$ x \f$ in the right-handed coordinate system around
     * the x-axis, the rotation matrix is:
     * \f{eqnarray}
     R_x( \alpha ) &=& \left[ \begin{array}{ccc} r_{11} & r_{12} & r_{13} \\
     r_{21} & r_{22} & r_{23} \\
     r_{31} & r_{32} & r_{33}
     \end{array} \right] \\
     &=& \left[ \begin{array}{ccc} 1 &           0 & 0 \\
     0 & \cos \alpha & - \sin \alpha \\
     0 & \sin \alpha & \cos \alpha
     \end{array} \right]
     \f}
     * Here a positive angle \f$ \alpha \f$ gives the rotation according to the
     * right-hand rule. In a left-handed coordinate system, a positive angle
     * \f$ \alpha \f$ gives the rotation according to the left-hand rule.
     *
     * To rotate around the y-axis, the rotation matrix is:
     * \f{eqnarray}
     R_y( \beta ) &=& \left[ \begin{array}{ccc} \cos \beta   & 0 & \sin \beta \\
     0 & 1 &          0 \\
     - \sin \beta & 0 & \cos \beta
     \end{array} \right]
     \f}
     * and to rotate around the z-axis:
     * \f{eqnarray}
     R_z( \gamma ) &=& \left[ \begin{array}{ccc} \cos \gamma & - \sin \gamma & 0 \\
     \sin \gamma &   \cos \gamma & 0 \\
     0 &             0 & 1
     \end{array} \right]
     \f}
     *
     * By combining these rotation matrices, a point is rotated first around
     * the x-axis, then the y-axis, and then the z-axis using the rotation
     * matrix:
     * \f{eqnarray}
     R( \alpha, \beta, \gamma )_{XYZ} &=& R_z(\gamma) R_y(\beta) R_x(\alpha)
     \f}
     * This combination can lead to the so called gimbal lock, if the angle
     * \f$ \beta \f$ is 90 degrees, in which case the x-axis and the rotated
     * z-axis are identical, and the degrees of freedom are reduced to two.
     *
     * To prevent this, the rotation can be defined using a normalized rotation
     * vector \f$ u = \left( u_0, u_1, u_2 \right) \f$ and the angle
     * \f$ \delta \f$:
     * \f{eqnarray}
     R( \delta, \vec{u} ) &=& \left[ \begin{array}{ccc}
     \cos \delta + u^2_0 ( 1 - \cos \delta )       & u_0 u_1 ( 1 - \cos \delta ) - u_2 \sin \delta & u_0 u_2 ( 1 - \cos \delta ) + u_1 \sin \delta\\
     u_0 u_1 ( 1 - \cos \delta ) + u_2 \sin \delta &       \cos \delta + u^2_1 ( 1 - \cos \delta ) & u_1 u_2 ( 1 - \cos \delta ) - u_0 \sin \delta\\
     u_0 u_2 ( 1 - \cos \delta ) - u_1 \sin \delta & u_1 u_2 ( 1 - \cos \delta ) + u_0 \sin \delta &        \cos \delta + u^2_2 ( 1 - \cos \delta )
     \end{array}
     \right]
     \f}
     *
     *
     * \par Calculation of the Rotation Vector and Angle from a Rotation Matrix
     * The rotation angle of a 3x3 rotation matrix can be easily calculated as
     * \f{eqnarray}
     Trace( R )  &=& n - 2 + 2 \cos \delta \qquad \textrm{with} \\
     n  &=& 3                                          \\
     \cos \delta &=& \frac{ Trace( R ) - 1 }{2}                 \\
     \delta      &=& \arccos \frac{ Trace( R ) - 1 }{2}
     \f}
     *
     * Now the vector \f$ \vec{u} \f$ is calculated as
     * \f{eqnarray}
     \vec{u}     &=& \frac{1}{2 \sin \delta} \left( \begin{array}{c}
     r_{32} - r_{23} \\
     r_{13} - r_{31} \\
     r_{21} - r_{12}
     \end{array}{c}
     \right)
     \f}
     * as long as \f$ \delta \f$ is not 0 or 180 degrees. In this special case,
     * the rotation vector is irrelevant, as the rotation matrix is the
     * identity matrix.
     *
     *
     * \par Calculation of the Rotation Angles from a Rotation Matrix
     * If we assume the rotation matrix was constructed using
     * \f{eqnarray}
     R( \alpha, \beta, \gamma )_{XYZ} &=& R_z(\gamma) R_y(\beta) R_x(\alpha)
     \f}
     * the question arises how to calculate the rotation angles from a given
     * rotation matrix.
     *
     * To do so, let's have a look at the resulting rotation matrix expressed
     * with the angles \f$ \alpha, \beta, \gamma \f$:
     * \f{eqnarray}
     R( \alpha, \beta, \gamma ) &=& \left[ \begin{array}{ccc}
     \cos \beta \cos \gamma & \sin \alpha \sin \beta \cos \gamma - \cos \alpha \sin \gamma & \cos \alpha \sin \beta \cos \gamma + \sin \alpha \sin \gamma \\
     \cos \beta \sin \gamma & \sin \alpha \sin \beta \sin \gamma + \cos \alpha \cos \gamma & \cos \alpha \sin \beta \sin \gamma - \sin \alpha \cos \gamma \\
     - \sin \beta           & \sin \alpha \cos \beta                                       & \cos \alpha \cos \beta
     \end{array} \right]
     \f}
     *
     * To get the angle \f$ \alpha \f$, we use the components \f$ r_{32}, r_{33} \f$:
     * \f{eqnarray}
     \tan \alpha &=& \frac{ r_{32} }{ r_{33} }
     \f}
     * in the case where \f$ r_{33} \f$ is not zero.
     * The angle \f$ \beta \f$ can be reconstructed from the component
     * \f$ r_{31} \f$ directly, or using the already calculated angle
     * \f$ \alpha \f$:
     * \f{eqnarray}
     \tan \beta &=& \frac{ \sin \beta }{ \cos \beta } \\
     &=& \frac{ - r_{31} }{ \sin \alpha r_{32} + \cos \alpha r_{33} }
     \f}
     * The angle \f$ \gamma \f$ is calculated from the components
     * \f$ r_{11}, r_{21} \f$ as:
     * \f{eqnarray}
     \tan \gamma &=& \frac{ r_{21} }{ r_{11} }
     \f}
     *
     * In the case of a gimbal lock, the elements
     * \f$ r_{11}, r_{21}, r_{32}, r_{33} \f$ are zero, as \f$ \cos \beta = 0 \f$.
     * In this case, we set the angle \f$ \gamma = 0 \f$ and the angle
     * \f$ \alpha \f$ is calculated as
     * \f{eqnarray}
     \tan \alpha &=& \frac{ r_{12} }{ r_{22} }
     \f}
     *
     *
     * \par Rotation using Quaternions:
     * A quaternion is defined as
     * \f{eqnarray}
     q &=& x_0 + x_1 i + x_2 j + x_3 k \qquad \textrm{with} \\
     i^2 &=& j^2 = k^2 = i j k = -1
     \f}
     * and the real components \f$ x_0, x_1, x_2, x_3 \f$. These can be written in
     * the following form:
     * \f{eqnarray}
     q       &=& \left[ s, \vec{v} \right] \qquad \textrm{with} \\
     s       &=& x_0 \\
     \vec{v} &=& \left( x_1, x_2, x_3 \right)
     \f}
     *
     * An unit quaternion is a quaternion of norm 1, where the norm of a
     * quaternion is simply the norm of the vector
     * \f$ \left( x_0, x_1, x_2, x_3 \right) \f$. To get the unit quaternion
     * \f$ q_n \f$ from a quaternion \f$ q \f$, all components are divided by the
     * norm \f$ \left| q \right| \f$ of the quaternion:
     * \f{eqnarray}
     q_n     &=& \frac{x_0}{\left| q \right|} +
     \frac{x_1}{\left| q \right|} i +
     \frac{x_2}{\left| q \right|} j +
     \frac{x_3}{\left| q \right|} k \\
     &=& \left[ \frac{s}{\left| q \right|}, \frac{\vec{v}}{\left| q \right|} \right]
     \f}
     *
     * The conjugated quaternion is defined as
     * \f{eqnarray}
     \bar{q} &=& x_0 - x_1 i - x_2 j - x_3 k \\
     &=& \left[ s, - \vec{v} \right]
     \f}
     * and the multiplication of two quaternions is defined as
     * \f{eqnarray}
     q * r   &=& \left[ s, \vec{v} \right] * \left[ t, \vec{w} \right] \\
     &=& \left[ st - \vec{v}\vec{w}, s\vec{w} + t\vec{v} + \vec{v} \times \vec{w} \right]
     \f}
     * using the scalar and cross product.
     *
     *
     * A point \f$ \vec{x} \f$, expressed as the quaternion
     * \f$ x = \left[ 0, \vec{x} \right] \f$ is rotated by the angle \f$ \delta \f$
     * around the axis \f$ \vec{u} \f$ with \f$ \left| \vec{u} \right| = 1 \f$
     * to the new point \f$ \vec{x'} \f$ by
     * \f{eqnarray}
     x' &=& \left[ 0, \vec{x'} \right] \\
     &=& q * x * \bar{q} \qquad \textrm{with} \\
     q  &=& \left[ \cos \frac{\delta}{2}, \sin \frac{\delta}{2} \vec{u} \right]
     \f}
     *
     * This leads to the same definition of the rotation matrix with a rotation
     * angle \f$ \delta \f$ around the vector \f$ \vec{u} \f$ as shown above.
     *
     * As stated above, quaternions are often used to interpolate between
     * rotations. To calculate the rotation matrix from a unit quaternion
     * \f$ x = \left( w, x, y, z \right) \f$ , the following transformation
     * is used:
     * \f{eqnarray}
     R(x) &=& \left[ \begin{array}{ccc}
     1 - 2 \left( y^2 + z^2 \right) & -2wz + 2xy                      & 2wy + 2xz  \\
     2wz +2xy                       & 1 - 2 \left( x^2 + z^2 \right ) & -2wx + 2yz \\
     -2wy + 2xz                     & 2wx + 2yz                       & 1 - 2 \left( x^2 + y^2 \right )
     \end{array}
     \right]
     \f}
     *
     * To convert a rotation matrix to a unit quaternion, we first calculate the
     * trace of the rotation matrix. As a unit quaternion has the norm 1, we can
     * calculate the \f$ w \f$ component as:
     * \f{eqnarray}
     w &=& \frac{1}{2} \sqrt{ Trace(R) + 1 }
     \f}
     * and the components of are then calculated as:
     * \f{eqnarray}
     x &=& \frac{1}{4 w} \left( r_{32} - r_{23} \right ) \\
     y &=& \frac{1}{4 w} \left( r_{13} - r_{31} \right ) \\
     z &=& \frac{1}{4 w} \left( r_{21} - r_{12} \right )
     \f}
     * If the \f$ Trace(R) + 1 \f$ is near zero, the square root will be small
     * and the factors for the \f$ x,y,z \f$ components will be very large. This
     * can lead to numerical instabilities. Therefore, the largest diagonal element
     * is determined and used to calculate the corresponding component. The
     * remaining components are then calculated using sums or differences of the
     * rotation matrix components.
     *
     * If the element \f$ r_{11} \f$ is the largest element:
     * \f{eqnarray}
     x &=& \frac{1}{2} \sqrt{1+r_{11}-r_{22}-r_{33}}     \\
     y &=& \frac{1}{4 x} \left( r_{21} + r_{12} \right ) \\
     z &=& \frac{1}{4 x} \left( r_{31} + r_{13} \right ) \\
     w &=& \frac{1}{4 x} \left( r_{32} - r_{23} \right )
     \f}
     *
     * If the element \f$ r_{22} \f$ is the largest element:
     * \f{eqnarray}
     y &=& \frac{1}{2} \sqrt{1+r_{22}-r_{11}-r_{33}}     \\
     x &=& \frac{1}{4 y} \left( r_{21} + r_{12} \right ) \\
     z &=& \frac{1}{4 y} \left( r_{32} + r_{23} \right ) \\
     w &=& \frac{1}{4 y} \left( r_{31} - r_{13} \right )
     \f}
     *
     * If the element \f$ r_{33} \f$ is the largest element:
     * \f{eqnarray}
     z &=& \frac{1}{2} \sqrt{1+r_{33}-r_{11}-r_{22}}     \\
     x &=& \frac{1}{4 z} \left( r_{31} + r_{13} \right ) \\
     y &=& \frac{1}{4 z} \left( r_{32} + r_{23} \right ) \\
     w &=& \frac{1}{4 z} \left( r_{12} - r_{21} \right )
     \f}
     *
     * The interpolation between two matrices is now expressed as the interpolation
     * of the two unit quaternions describing the rotations. As the resulting
     * interpolated quaternion has to be an unit quaternion, a linear interpolation
     * of all components is not suitable. Instead, a spherical interpolation is
     * performed
     * \f{eqnarray}
     q(t) &=& \frac{ \sin \left( \left[ 1 - t \right] \Omega \right) }{ \sin \Omega } q_1 + \frac{ \sin \left( t \Omega \right) }{ \sin \Omega } q_2
     \f}
     * between the two unit quaternions \f$ q_1, q_2 \f$ according to the value
     * \f$ t \f$ in the interval \f$ \left[ 0, 1 \right] \f$. The angle \f$ \Omega \f$
     * between the two quaternions is defined as
     * \f{eqnarray}
     \cos \Omega &=& \left< q_1, q_2 \right> \\
     &=& x_1 x_2 + y_1 y_2 + z_1 z_2 + w_1 w_2
     \f}
     * using the vector scalar product. If the angle \f$ \Omega \f$ is small,
     * the spherical interpolation is approximated by a linear interpolation.
     * In this case, it may be neccessary to normalize the interpolated quaternion
     * before reconstructing the rotation matrix.
     *
     *
     *
     * \brief  This class represents a 3x3 rotation matrix.
     *
     * \author Clemens Rabe
     * \date   Mai 02, 2008
     * \sa     -
     *****************************************************************************/
    template < class _DataType = float >
    class Rotation3d : public Matrix3d< _DataType >
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
        Rotation3d();
        Rotation3d( const double                    f_rotAngleX_d,
                    const double                    f_rotAngleY_d,
                    const double                    f_rotAngleZ_d );
        Rotation3d( const Rotation3d< _DataType >&  fr_other );


        template< class _OtherType >
        Rotation3d( const Rotation3d< _OtherType >& fr_other );



        /******************************************************
         * methods
         ******************************************************/

        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Read methods (getter).
        ///@{

        bool             getEuler(      double&   fr_rotAngleX_d,
                                        double&   fr_rotAngleY_d,
                                        double&   fr_rotAngleZ_d ) const;
        bool             getEulerZYX(   double&   fr_rotAngleX_d,
                                        double&   fr_rotAngleY_d,
                                        double&   fr_rotAngleZ_d ) const;

        template< class _OtherType >
        void             getEuler(      Vector3d< _OtherType > & fr_axis,
                                        double&                  fr_angle_d ) const;

        void             getQuaternion( double&   fr_x_d,
                                        double&   fr_y_d,
                                        double&   fr_z_d,
                                        double&   fr_w_d ) const;

        ///@}


        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Write methods (setter).
        ///@{

        void  setEuler(      const double  f_rotAngleX_d,
                             const double  f_rotAngleY_d,
                             const double  f_rotAngleZ_d );

        void  setEulerZYX(   const double  f_rotAngleX_d,
                             const double  f_rotAngleY_d,
                             const double  f_rotAngleZ_d );

        template < class _OtherType >
        void  setEuler(      const Vector3d< _OtherType >& fr_axis,
                             const double                  f_angle_d );

        void  setQuaternion( const double  f_x_d,
                             const double  f_y_d,
                             const double  f_z_d,
                             const double  f_w_d );

        void  clear();

        ///@}


        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Operations
        ///@{

        Rotation3d< _DataType >& invert();

        ///@}


        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Operator overloading.
        ///@{

        Rotation3d< _DataType >&   operator= ( const Rotation3d< _DataType >&  fr_other );

        template< class _OtherType >
        Rotation3d< _DataType >&   operator= ( const Rotation3d< _OtherType >& fr_other );

        Rotation3d< _DataType >&   operator/=( const Rotation3d< _DataType >&  fr_other );

        // operator NEWMAT::Matrix ();

        ///@}




        //------------------------------------------------------------------
    private:

        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ///@name Private methods.
        ///@{

        ///@}

    };


    /*****************************************************************************
     * GLOBAL OPERATORS.
     ******************************************************************************/



    template< class _DataType, class _OtherType >
    Rotation3d< _DataType > const
    operator * ( const Rotation3d< _DataType >&  fr_left,
                 const Rotation3d< _OtherType >& fr_right );

    template< class _DataType, class _OtherType >
    Rotation3d< _DataType > const
    operator / ( const Rotation3d< _DataType >&  fr_left,
                 const Rotation3d< _OtherType >& fr_right );

    template< class _DataType >
    Rotation3d< _DataType >
    invert(      const Rotation3d< _DataType >&  fr_mat );


} // end namespace


/*****************************************************************************
 * VERSION INFORMATION
 ******************************************************************************/
// BOOST_TEMPLATE_CLASS_VERSION( Math3d::Rotation3d< T >, 0 )





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

namespace MATH3D
{
  static const float MATH3D_PI_HALF = 1.5707963267948966192313216916398f;
}

/* ********************************* METHOD **********************************/
/**
 * \brief     Standard constructor. Initializes the matrix to an identity
 *            matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Rotation3d< _DataType >::Rotation3d()
{
    clear();
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Constructor. Constructs a rotation matrix to rotate a point
 *            first around the x-axis, then the y-axis and then the z-axis.
 *
 * \author    Clemens Rabe
 * \date      Mai 02, 2008
 *
 * \param[in] f_rotAngleX_d - Rotation angle in radiants around the X-axis.
 * \param[in] f_rotAngleY_d - Rotation angle in radiants around the Y-axis.
 * \param[in] f_rotAngleZ_d - Rotation angle in radiants around the Z-axis.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Rotation3d< _DataType >::Rotation3d(
        const double  f_rotAngleX_d,
        const double  f_rotAngleY_d,
        const double  f_rotAngleZ_d )
{
    ;

    setEuler( f_rotAngleX_d, f_rotAngleY_d, f_rotAngleZ_d );


}


/* ********************************* METHOD **********************************/
/**
 * \brief     Copy constructor.
 *
 * \author    Clemens Rabe
 * \date      Mai 02, 2008
 *
 * \param[in] fr_other - Object to copy.
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Rotation3d< _DataType >::Rotation3d(
        const Rotation3d< _DataType >&  fr_other )
        : Math3d::Matrix3d< _DataType >()
{
    ;

    this->copyFrom( fr_other );


}


/* ********************************* METHOD **********************************/
/**
 * \brief     Copy constructor.
 *
 * \author    Clemens Rabe
 * \date      Mai 02, 2008
 *
 * \param[in] fr_other - Object to copy.
 *
 *****************************************************************************/
template< class _DataType >
template< class _OtherType >
inline
Math3d::Rotation3d< _DataType >::Rotation3d(
        const Rotation3d< _OtherType >&  fr_other )
        : Math3d::Matrix3d< _DataType >()
{
    ;

    this->copyFrom( fr_other );


}




/* ********************************* METHOD **********************************/
/**
 * If we assume the rotation matrix was constructed using
 * \f{eqnarray}
 R( \alpha, \beta, \gamma )_{XYZ} &=& R_z(\gamma) R_y(\beta) R_x(\alpha)
 \f}
 * the angles are calculated as follows:
 *
 * To get the angle \f$ \alpha \f$, we use the components \f$ r_{32}, r_{33} \f$:
 * \f{eqnarray}
 \tan \alpha &=& \frac{ r_{32} }{ r_{33} }
 \f}
 * in the case where \f$ r_{33} \f$ is not zero.
 * The angle \f$ \beta \f$ can be reconstructed from the component
 * \f$ r_{31} \f$ directly, or using the already calculated angle
 * \f$ \alpha \f$:
 * \f{eqnarray}
 \tan \beta &=& \frac{ \sin \beta }{ \cos \beta } \\
 &=& \frac{ - r_{31} }{ \sin \alpha r_{32} + \cos \alpha r_{33} }
 \f}
 * The angle \f$ \gamma \f$ is calculated from the components
 * \f$ r_{11}, r_{21} \f$ as:
 * \f{eqnarray}
 \tan \gamma &=& \frac{ r_{21} }{ r_{11} }
 \f}
 *
 * In the case of a gimbal lock, the elements
 * \f$ r_{11}, r_{21}, r_{32}, r_{33} \f$ are zero, as \f$ \cos \beta = 0 \f$.
 * In this case, we set the angle \f$ \gamma = 0 \f$ and the angle
 * \f$ \alpha \f$ is calculated as
 * \f{eqnarray}
 \tan \alpha &=& \frac{ r_{12} }{ r_{22} }
 \f}
 *
 *
 * \brief     Get the euler angles of the current rotation matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 02, 2008
 *
 * \param[out] fr_rotAngleX_d - The rotation angle around the x-axis in radiants.
 * \param[out] fr_rotAngleY_d - The rotation angle around the y-axis in radiants.
 * \param[out] fr_rotAngleZ_d - The rotation angle around the z-axis in radiants.
 * \return     Returns \c false if a gimbal lock is detected, otherwise
 *             \c false.
 *
 *****************************************************************************/
template< class _DataType >
inline
bool
Math3d::Rotation3d< _DataType >::getEuler(      double&  fr_rotAngleX_d,
                                                double&  fr_rotAngleY_d,
                                                double&  fr_rotAngleZ_d ) const
{
    ;

    const double epsilon_d = 1.0 - 1.e-6;

    // Gimbal lock
    // ~CodeReview ~ID:579492b2a29629b3474a3009766b73b8 ~Reviewer:PC2357\dijkstg ~Date:12-6-2012 ~Priority:3 ~Comment:120930, magic numbers used as index in array m_matrix[]. Use indices as defined at line 24 to 32. Applies to whole file.
    if ( this->m_matrix[6] > epsilon_d )
    {
        fr_rotAngleX_d = atan2( this->m_matrix[1], this->m_matrix[4] );
        fr_rotAngleY_d = MATH3D::MATH3D_PI_HALF;
        fr_rotAngleZ_d = 0.0;

    
        return false;
    }

    // Gimbal lock
    if ( this->m_matrix[6] < -epsilon_d )
    {
        fr_rotAngleX_d = atan2( this->m_matrix[1], this->m_matrix[4] );
        fr_rotAngleY_d = -MATH3D::MATH3D_PI_HALF;
        fr_rotAngleZ_d = 0.0;

    
        return false;
    }


    fr_rotAngleX_d = atan2( this->m_matrix[7], this->m_matrix[8] );
    fr_rotAngleY_d = atan2( -this->m_matrix[6],
                            sin( fr_rotAngleX_d ) * this->m_matrix[7] +
                            cos( fr_rotAngleX_d ) * this->m_matrix[8] );
    fr_rotAngleZ_d = atan2( this->m_matrix[3], this->m_matrix[0] );



    return true;
}


/* ********************************* METHOD **********************************/
/**
 * If we assume the rotation matrix was constructed using
 * \f{eqnarray}
 R( \alpha, \beta, \gamma )_{XYZ} &=& R_x(\gamma) R_y(\beta) R_z(\alpha)
 \f}
 * the angles are calculated as follows:
 *
 * To get the angle \f$ \alpha \f$, we use the components \f$ r_{23}, r_{33} \f$:
 * \f{eqnarray}
 \tan \alpha &=& -\frac{ r_{23} }{ r_{33} }
 \f}
 * in the case where \f$ r_{33} \f$ is not zero.
 * The angle \f$ \beta \f$ can be reconstructed from the component
 * \f$ r_{13} \f$ directly, or using the already calculated angle
 * \f$ \alpha \f$:
 * \f{eqnarray}
 \tan \beta &=& \frac{ \sin \beta }{ \cos \beta } \\
 &=& \frac{ r_{13} }{ - \sin \alpha r_{23} + \cos \alpha r_{33} }
 \f}
 * The angle \f$ \gamma \f$ is calculated from the components
 * \f$ r_{11}, r_{21} \f$ as:
 * \f{eqnarray}
 \tan \gamma &=& - \frac{ r_{12} }{ r_{11} }
 \f}
 *
 * In the case of a gimbal lock, the elements
 * \f$ r_{11}, r_{12}, r_{23}, r_{33} \f$ are zero, as \f$ \cos \beta = 0 \f$.
 * In this case, we set the angle \f$ \gamma = 0 \f$ and the angle
 * \f$ \alpha \f$ is calculated as
 * \f{eqnarray}
 \tan \alpha &=& \frac{ r_{21} }{ r_{22} }
 \f}
 *
 *
 * \brief     Get the euler angles of the current rotation matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 02, 2008
 *
 * \param[out] fr_rotAngleX_d - The rotation angle around the x-axis in radiants.
 * \param[out] fr_rotAngleY_d - The rotation angle around the y-axis in radiants.
 * \param[out] fr_rotAngleZ_d - The rotation angle around the z-axis in radiants.
 * \return     Returns \c false if a gimbal lock is detected, otherwise
 *             \c false.
 *
 *****************************************************************************/
template< class _DataType >
inline
bool
Math3d::Rotation3d< _DataType >::getEulerZYX(   double&  fr_rotAngleX_d,
                                                double&  fr_rotAngleY_d,
                                                double&  fr_rotAngleZ_d ) const
{
    ;

    const double epsilon_d = 1.0 - 1.e-6;

    // Gimbal lock
    if ( this->m_matrix[2] > epsilon_d )
    {
        fr_rotAngleX_d = atan2( this->m_matrix[3], this->m_matrix[4] );
        fr_rotAngleY_d = MATH3D::MATH3D_PI_HALF;
        fr_rotAngleZ_d = 0.0;

    
        return false;
    }

    // Gimbal lock
    if ( this->m_matrix[2] < -epsilon_d )
    {
        fr_rotAngleX_d = atan2( this->m_matrix[3], this->m_matrix[4] );
        fr_rotAngleY_d = -MATH3D::MATH3D_PI_HALF;
        fr_rotAngleZ_d = 0.0;

    
        return false;
    }


    fr_rotAngleX_d = atan2( -this->m_matrix[5], this->m_matrix[8] );
    fr_rotAngleY_d = atan2( this->m_matrix[2],
                            -sin( fr_rotAngleX_d ) * this->m_matrix[5] +
                            cos( fr_rotAngleX_d )  * this->m_matrix[8] );
    fr_rotAngleZ_d = atan2( -this->m_matrix[1], this->m_matrix[0] );



    return true;
}


/* ********************************* METHOD **********************************/
/**
 * The rotation angle of a 3x3 rotation matrix can be easily calculated as
 * \f{eqnarray}
 Trace( R )  &=& n - 2 + 2 \cos \delta \qquad \textrm{with} \\
 n  &=& 3                                          \\
 \cos \delta &=& \frac{ Trace( R ) - 1 }{2}                 \\
 \delta      &=& \arccos \frac{ Trace( R ) - 1 }{2}
 \f}
 *
 * Now the vector \f$ \vec{u} \f$ is calculated as
 * \f{eqnarray}
 \vec{u}     &=& \frac{1}{2 \sin \delta} \left( \begin{array}{c}
 r_{32} - r_{23} \\
 r_{13} - r_{31} \\
 r_{21} - r_{12}
 \end{array}{c}
 \right)
 \f}
 * as long as \f$ \delta \f$ is not 0 or 180 degrees. In this special case,
 * the rotation vector is irrelevant, as the rotation matrix is the
 * identity matrix.
 *
 *
 *
 *
 *
 * \brief     Get the rotation axis and the rotation angle.
 *
 * \author    Clemens Rabe
 * \date      Mai 04, 2008
 *
 * \param[out] fr_axis    - The rotation axis.
 * \param[out] fr_angle_d - The rotation angle.
 *
 *****************************************************************************/
template< class _DataType >
template< class _OtherType >
inline
void
Math3d::Rotation3d< _DataType >::getEuler(
        Vector3d< _OtherType > & fr_axis,
        double&                  fr_angle_d ) const
{
    ;

    fr_angle_d = acos( 0.5 * ( this->trace() - 1.0 ) );

    const double sin_d = sin( fr_angle_d );

    // No rotation at all
    if ( ( sin_d > -1.e-7 ) && ( sin_d < 1.e-7 ) )
    {
        fr_axis.set( 1.0, 1.0, 1.0 );
        fr_angle_d = 0.0;
    }

    else
    {
        const double f_d = 1.0 / ( 2.0 * sin_d );
        fr_axis.set( f_d * ( this->m_matrix[ I21 ] - this->m_matrix[ I12 ] ),
                     f_d * ( this->m_matrix[ I02 ] - this->m_matrix[ I20 ] ),
                     f_d * ( this->m_matrix[ I10 ] - this->m_matrix[ I01 ] ) );
    }


}


/* ********************************* METHOD **********************************/
/**
 * To convert a rotation matrix to a unit quaternion, we first calculate the
 * trace of the rotation matrix. As a unit quaternion has the norm 1, we can
 * calculate the \f$ w \f$ component as:
 * \f{eqnarray}
 w &=& \frac{1}{2} \sqrt{ Trace(R) + 1 }
 \f}
 * and the components of are then calculated as:
 * \f{eqnarray}
 x &=& \frac{1}{4 w} \left( r_{32} - r_{23} \right ) \\
 y &=& \frac{1}{4 w} \left( r_{13} - r_{31} \right ) \\
 z &=& \frac{1}{4 w} \left( r_{21} - r_{12} \right )
 \f}
 * If the \f$ Trace(R) + 1 \f$ is near zero, the square root will be small
 * and the factors for the \f$ x,y,z \f$ components will be very large. This
 * can lead to numerical instabilities. Therefore, the largest diagonal element
 * is determined and used to calculate the corresponding component. The
 * remaining components are then calculated using sums or differences of the
 * rotation matrix components.
 *
 * If the element \f$ r_{11} \f$ is the largest element:
 * \f{eqnarray}
 x &=& \frac{1}{2} \sqrt{1+r_{11}-r_{22}-r_{33}}     \\
 y &=& \frac{1}{4 x} \left( r_{21} + r_{12} \right ) \\
 z &=& \frac{1}{4 x} \left( r_{31} + r_{13} \right ) \\
 w &=& \frac{1}{4 x} \left( r_{32} - r_{23} \right )
 \f}
 *
 * If the element \f$ r_{22} \f$ is the largest element:
 * \f{eqnarray}
 y &=& \frac{1}{2} \sqrt{1+r_{22}-r_{11}-r_{33}}     \\
 x &=& \frac{1}{4 y} \left( r_{21} + r_{12} \right ) \\
 z &=& \frac{1}{4 y} \left( r_{32} + r_{23} \right ) \\
 w &=& \frac{1}{4 y} \left( r_{31} - r_{13} \right )
 \f}
 *
 * If the element \f$ r_{33} \f$ is the largest element:
 * \f{eqnarray}
 z &=& \frac{1}{2} \sqrt{1+r_{33}-r_{11}-r_{22}}     \\
 x &=& \frac{1}{4 z} \left( r_{31} + r_{13} \right ) \\
 y &=& \frac{1}{4 z} \left( r_{32} + r_{23} \right ) \\
 w &=& \frac{1}{4 z} \left( r_{12} - r_{21} \right )
 \f}
 *
 *
 * \brief     Get the unit quaternion that describes this rotation matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 02, 2008
 *
 * \param[out] fr_x_d - X component of the unit quaternion.
 * \param[out] fr_y_d - Y component of the unit quaternion.
 * \param[out] fr_z_d - Z component of the unit quaternion.
 * \param[out] fr_w_d - W component of the unit quaternion.
 *
 *****************************************************************************/
template< class _DataType >
inline
void
Math3d::Rotation3d< _DataType >::getQuaternion( double&  fr_x_d,
                                                double&  fr_y_d,
                                                double&  fr_z_d,
                                                double&  fr_w_d ) const
{
    ;

    const double trace_d   = 1.0 + this->m_matrix[0] + this->m_matrix[4] + this->m_matrix[8];
    const double epsilon_d = 1.e-7;

    if ( trace_d > epsilon_d )
    {
        fr_w_d = 0.5 * sqrt( trace_d );

        const double t_d = 1.0 / ( 4.0 * fr_w_d );
        fr_x_d = ( this->m_matrix[7] - this->m_matrix[5] ) * t_d;
        fr_y_d = ( this->m_matrix[2] - this->m_matrix[6] ) * t_d;
        fr_z_d = ( this->m_matrix[3] - this->m_matrix[1] ) * t_d;
    }

    else
    {
        // Find the largest diagonal element
        if ( ( this->m_matrix[0] > this->m_matrix[4] ) && ( this->m_matrix[0] > this->m_matrix[8] ) )
        {
            fr_x_d = 0.5 * sqrt( 1.0 + this->m_matrix[0] - this->m_matrix[4] - this->m_matrix[8] );
            const double t_d = (fr_x_d > epsilon_d) ? 1.0 / ( 4.0 * fr_x_d ) : 1.0 / ( 4.0 * epsilon_d );
            fr_y_d = ( this->m_matrix[3] + this->m_matrix[1] ) * t_d;
            fr_z_d = ( this->m_matrix[6] + this->m_matrix[2] ) * t_d;
            fr_w_d = ( this->m_matrix[7] - this->m_matrix[5] ) * t_d;
        }

        else if ( this->m_matrix[4] > this->m_matrix[8] )
        {
            fr_y_d = 0.5 * sqrt( 1.0 + this->m_matrix[4] - this->m_matrix[0] - this->m_matrix[8] );
            const double t_d = (fr_y_d > epsilon_d) ? 1.0 / ( 4.0 * fr_y_d ) : 1.0 / ( 4.0 * epsilon_d );
            fr_x_d = ( this->m_matrix[3] + this->m_matrix[1] ) * t_d;
            fr_z_d = ( this->m_matrix[7] + this->m_matrix[5] ) * t_d;
            fr_w_d = ( this->m_matrix[6] - this->m_matrix[2] ) * t_d;
        }

        else
        {
            fr_z_d = 0.5 * sqrt( 1.0 + this->m_matrix[8] - this->m_matrix[0] - this->m_matrix[4] );
            const double t_d = (fr_z_d > epsilon_d) ? 1.0 / ( 4.0 * fr_z_d ) : 1.0 / ( 4.0 * epsilon_d );
            fr_x_d = ( this->m_matrix[6] + this->m_matrix[2] ) * t_d;
            fr_y_d = ( this->m_matrix[7] + this->m_matrix[5] ) * t_d;
            fr_w_d = ( this->m_matrix[1] - this->m_matrix[3] ) * t_d;
        }
    }


}


/* ********************************* METHOD **********************************/
/**
 * Constructs the rotation matrix as
 * \f{eqnarray}
 R( \alpha, \beta, \gamma )_{XYZ} &=& R_z(\gamma) R_y(\beta) R_x(\alpha) \\
 &=& \left[ \begin{array}{ccc}
 \cos \beta \cos \gamma & \sin \alpha \sin \beta \cos \gamma - \cos \alpha \sin \gamma & \cos \alpha \sin \beta \cos \gamma + \sin \alpha \sin \gamma \\
 \cos \beta \sin \gamma & \sin \alpha \sin \beta \sin \gamma + \cos \alpha \cos \gamma & \cos \alpha \sin \beta \sin \gamma - \sin \alpha \cos \gamma \\
 - \sin \beta           & \sin \alpha \cos \beta                                       & \cos \alpha \cos \beta
 \end{array} \right]
 \f}
 *
 *
 * \brief     Set the rotation matrix to rotate a point
 *            first around the x-axis, then the y-axis and then the z-axis.
 *
 * \author    Clemens Rabe
 * \date      Mai 02, 2008
 *
 * \param[in] f_rotAngleX_d - Rotation angle in radiants around the X-axis.
 * \param[in] f_rotAngleY_d - Rotation angle in radiants around the Y-axis.
 * \param[in] f_rotAngleZ_d - Rotation angle in radiants around the Z-axis.
 *
 *****************************************************************************/
template< class _DataType >
inline
void
Math3d::Rotation3d< _DataType >::setEuler( const double  f_rotAngleX_d,
                                           const double  f_rotAngleY_d,
                                           const double  f_rotAngleZ_d )
{
    ;

    const double ca = cos( f_rotAngleX_d );
    const double cb = cos( f_rotAngleY_d );
    const double cc = cos( f_rotAngleZ_d );
    const double sa = sin( f_rotAngleX_d );
    const double sb = sin( f_rotAngleY_d );
    const double sc = sin( f_rotAngleZ_d );

    this->m_matrix[0] = _DataType( cb * cc );
    this->m_matrix[1] = _DataType( sa * sb * cc - ca * sc );
    this->m_matrix[2] = _DataType( ca * sb * cc + sa * sc );
    this->m_matrix[3] = _DataType( cb * sc );
    this->m_matrix[4] = _DataType( sa * sb * sc + ca * cc );
    this->m_matrix[5] = _DataType( ca * sb * sc - sa * cc );
    this->m_matrix[6] = _DataType( -sb );
    this->m_matrix[7] = _DataType( sa * cb );
    this->m_matrix[8] = _DataType( ca * cb );


}


/* ********************************* METHOD **********************************/
/**
 * Constructs the rotation matrix as
 * \f{eqnarray}
 R( \alpha, \beta, \gamma )_{XYZ} &=& R_x(\alpha) R_y(\beta) R_z(\gamma) \\
 &=& \left[ \begin{array}{ccc}
 \cos \beta \cos \gamma                                         & - \cos \beta \sin \gamma                                     & \sin \beta               \\
 \sin \alpha \sin \beta \cos \gamma + \cos \alpha \sin \gamma   & \cos \alpha \cos \gamma - \sin \alpha \sin \beta \sin \gamma & - \sin \alpha \cos \beta \\
 - \cos \alpha \sin \beta \cos \gamma + \sin \alpha \sin \gamma & \sin \alpha \cos \gamma + \cos \alpha \sin \beta \sin \gamma & \cos \alpha \cos \beta
 \end{array} \right]
 \f}
 *
 *
 * \brief     Set the rotation matrix to rotate a point
 *            first around the z-axis, then the y-axis and then the x-axis.
 *
 * \author    Clemens Rabe
 * \date      Aug 14, 2009
 *
 * \param[in] f_rotAngleX_d - Rotation angle in radiants around the X-axis.
 * \param[in] f_rotAngleY_d - Rotation angle in radiants around the Y-axis.
 * \param[in] f_rotAngleZ_d - Rotation angle in radiants around the Z-axis.
 *
 *****************************************************************************/
template< class _DataType >
inline
void
Math3d::Rotation3d< _DataType >::setEulerZYX( const double  f_rotAngleX_d,
                                              const double  f_rotAngleY_d,
                                              const double  f_rotAngleZ_d )
{
    ;

    const double ca = cos( f_rotAngleX_d );
    const double cb = cos( f_rotAngleY_d );
    const double cg = cos( f_rotAngleZ_d );
    const double sa = sin( f_rotAngleX_d );
    const double sb = sin( f_rotAngleY_d );
    const double sg = sin( f_rotAngleZ_d );

    this->m_matrix[0] = _DataType( cb * cg );
    this->m_matrix[1] = _DataType( -cb * sg );
    this->m_matrix[2] = _DataType( sb );
    this->m_matrix[3] = _DataType( sa * sb * cg + ca * sg );
    this->m_matrix[4] = _DataType( ca * cg - sa * sb * sg );
    this->m_matrix[5] = _DataType( -sa * cb );
    this->m_matrix[6] = _DataType( sa * sg - ca * sb * cg );
    this->m_matrix[7] = _DataType( sa * cg + ca * sb * sg );
    this->m_matrix[8] = _DataType( ca * cb );


}


/* ********************************* METHOD **********************************/
/**
 * The rotation can be defined using a normalized rotation
 * vector \f$ u = \left( u_0, u_1, u_2 \right) \f$ and the angle
 * \f$ \delta \f$:
 * \f{eqnarray}
 R( \delta, \vec{u} ) &=& \left[ \begin{array}{ccc}
 \cos \delta + u^2_0 ( 1 - \cos \delta )       & u_0 u_1 ( 1 - \cos \delta ) - u_2 \sin \delta & u_0 u_2 ( 1 - \cos \delta ) + u_1 \sin \delta\\
 u_0 u_1 ( 1 - \cos \delta ) + u_2 \sin \delta &       \cos \delta + u^2_1 ( 1 - \cos \delta ) & u_1 u_2 ( 1 - \cos \delta ) - u_0 \sin \delta\\
 u_0 u_2 ( 1 - \cos \delta ) - u_1 \sin \delta & u_1 u_2 ( 1 - \cos \delta ) + u_0 \sin \delta &        \cos \delta + u^2_2 ( 1 - \cos \delta )
 \end{array}
 \right]
 \f}
 *
 *
 *
 *
 * \brief     Set the rotation given a normalized axis vector and an angle.
 *
 * \author    Clemens Rabe
 * \date      Mai 04, 2008
 *
 * \param[in] fr_axis   - Axis vector.
 * \param[in] f_angle_d - Angle.
 *
 *****************************************************************************/
template< class _DataType >
template < class _OtherType >
inline
void
Math3d::Rotation3d< _DataType >::setEuler(
        const Vector3d< _OtherType >& fr_axis,
        const double                  f_angle_d )
{
    ;

    const double cos_d   = cos( f_angle_d );
    const double sin_d   = sin( f_angle_d );
    const double icos_d  = 1.0 - cos_d;

    const double xy_d    = fr_axis.getX() * fr_axis.getY();
    const double xz_d    = fr_axis.getX() * fr_axis.getZ();
    const double yz_d    = fr_axis.getY() * fr_axis.getZ();
    const double x_sin_d = fr_axis.getX() * sin_d;
    const double y_sin_d = fr_axis.getY() * sin_d;
    const double z_sin_d = fr_axis.getZ() * sin_d;


    this->m_matrix[ I00 ] = _DataType( cos_d + fr_axis.getX() * fr_axis.getX() * icos_d );
    this->m_matrix[ I01 ] = _DataType( xy_d * icos_d - z_sin_d );
    this->m_matrix[ I02 ] = _DataType( xz_d * icos_d + y_sin_d );

    this->m_matrix[ I10 ] = _DataType( xy_d * icos_d + z_sin_d );
    this->m_matrix[ I11 ] = _DataType( cos_d + fr_axis.getY() * fr_axis.getY() * icos_d );
    this->m_matrix[ I12 ] = _DataType( yz_d * icos_d - x_sin_d );

    this->m_matrix[ I20 ] = _DataType( xz_d * icos_d - y_sin_d );
    this->m_matrix[ I21 ] = _DataType( yz_d * icos_d + x_sin_d );
    this->m_matrix[ I22 ] = _DataType( cos_d + fr_axis.getZ() * fr_axis.getZ() * icos_d );


}



/* ********************************* METHOD **********************************/
/**
 * An unit quaternion defined as
 * \f{eqnarray}
 q                &=& w + x i + y j + z k \qquad \textrm{with} \\
 i^2              &=& j^2 = k^2 = i j k = -1 \\
 \left| q \right| &=& 1
 \f}
 * with the real components \f$ x, y, z, w \f$ is transformed into a
 * rotation matrix by:
 * \f{eqnarray}
 R(x) &=& \left[ \begin{array}{ccc}
 1 - 2 \left( y^2 + z^2 \right) & -2wz + 2xy                      & 2wy + 2xz  \\
 2wz +2xy                       & 1 - 2 \left( x^2 + z^2 \right ) & -2wx + 2yz \\
 -2wy + 2xz                     & 2wx + 2yz                       & 1 - 2 \left( x^2 + y^2 \right )
 \end{array}
 \right]
 \f}
 *
 *
 *
 * \brief     Set the rotation matrix according to the given unit quaternion.
 *
 * \author    Clemens Rabe
 * \date      Mai 02, 2008
 *
 * \param[in] f_x_d - The x-component of the quaternion.
 * \param[in] f_y_d - The y-component of the quaternion.
 * \param[in] f_z_d - The z-component of the quaternion.
 * \param[in] f_w_d - The w-component of the quaternion.
 *
 *****************************************************************************/
template< class _DataType >
inline
void
Math3d::Rotation3d< _DataType >::setQuaternion( const double  f_x_d,
                                                const double  f_y_d,
                                                const double  f_z_d,
                                                const double  f_w_d )
{
    ;

    const double sx = f_x_d * f_x_d;
    const double sy = f_y_d * f_y_d;
    const double sz = f_z_d * f_z_d;

    this->m_matrix[0] = _DataType( 1.0 - 2.0 * ( sy + sz ) );
    this->m_matrix[1] = _DataType( 2.0 * ( f_x_d * f_y_d - f_z_d * f_w_d ) );
    this->m_matrix[2] = _DataType( 2.0 * ( f_x_d * f_z_d + f_y_d * f_w_d ) );
    this->m_matrix[3] = _DataType( 2.0 * ( f_x_d * f_y_d + f_z_d * f_w_d ) );
    this->m_matrix[4] = _DataType( 1.0 - 2.0 * ( sx + sz ) );
    this->m_matrix[5] = _DataType( 2.0 * ( f_y_d * f_z_d - f_x_d * f_w_d ) );
    this->m_matrix[6] = _DataType( 2.0 * ( f_x_d * f_z_d - f_y_d * f_w_d ) );
    this->m_matrix[7] = _DataType( 2.0 * ( f_y_d * f_z_d + f_x_d * f_w_d ) );
    this->m_matrix[8] = _DataType( 1.0 - 2.0 * ( sx + sy ) );


}


/* ********************************* METHOD **********************************/
/**
 * \brief     Set the rotation matrix to the identity matrix.
 *
 * \author    Clemens Rabe
 * \date      Aug 16, 2008
 *
 *****************************************************************************/
template< class _DataType >
inline
void
Math3d::Rotation3d< _DataType >::clear()
{

    this->set( static_cast<_DataType>(1.0), static_cast<_DataType>(0.0), static_cast<_DataType>(0.0),
               static_cast<_DataType>(0.0), static_cast<_DataType>(1.0), static_cast<_DataType>(0.0),
               static_cast<_DataType>(0.0), static_cast<_DataType>(0.0), static_cast<_DataType>(1.0) );

}


/* ********************************* METHOD **********************************/
/**
 * \brief     Invert this rotation matrix.
 *
 * \author    Clemens Rabe
 * \date      Mai 02, 2008
 *
 *****************************************************************************/
template< class _DataType >
inline
Math3d::Rotation3d< _DataType >&
Math3d::Rotation3d< _DataType >::invert()
{
 
    this->transpose();

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
Math3d::Rotation3d< _DataType >&
Math3d::Rotation3d< _DataType >::operator= ( const Math3d::Rotation3d< _DataType >& fr_other )
{
    this->copyFrom( fr_other );



    return *this;
}


/*
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
Math3d::Rotation3d< _DataType >&
Math3d::Rotation3d< _DataType >::operator= ( const Math3d::Rotation3d< _OtherType >& fr_other )
{

    this->copyFrom( fr_other );



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
Math3d::Rotation3d< _DataType >&
Math3d::Rotation3d< _DataType >::operator/=( const Math3d::Rotation3d< _DataType >& fr_other )
{
    ;

    Math3d::Rotation3d< _DataType > temp( fr_other );
    temp.invert();

    this->operator*=( temp );



    return *this;
}






/* ********************************* METHOD **********************************/
/**
 * \brief     Multiplication operator.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_left  - Left operand.
 * \param[in] fr_right - Right operand.
 * \return    Returns the multiplied matrix.
 *
 *****************************************************************************/
template< class _DataType, class _OtherType >
inline
Math3d::Rotation3d< _DataType > const
Math3d::operator * ( const Rotation3d< _DataType >&   fr_left,
                     const Rotation3d< _OtherType >&  fr_right )
{
    ;

    Rotation3d< _DataType > temp( fr_left );
    temp *= fr_right;



    return temp;
}


/* ********************************* METHOD **********************************/
/**
 * \brief     Division operator.
 *
 * \author    Clemens Rabe
 * \date      Mai 03, 2008
 *
 * \param[in] fr_left  - Left operand.
 * \param[in] fr_right - Right operand.
 * \return    Returns the matrix fr_left * invert( fr_right ).
 *
 *****************************************************************************/
template< class _DataType, class _OtherType >
inline
Math3d::Rotation3d< _DataType > const
Math3d::operator / ( const Rotation3d< _DataType >&   fr_left,
                     const Rotation3d< _OtherType >&  fr_right )
{
    ;

    Rotation3d< _DataType > temp( fr_left );
    temp /= fr_right;



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
Math3d::Rotation3d< _DataType >
Math3d::invert( const Rotation3d< _DataType >&   fr_mat )
{
    ;

    Math3d::Rotation3d< _DataType > temp( fr_mat );
    temp.invert();


    return temp;
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



#endif /* _ROTATION3D_H */

/*****************************************************************************
|----------------------------------------------------------------------------|
| R E V I S I O N   H I S T O R Y                                            |
|----------------------------------------------------------------------------|

$Log: rotation3d.h  $
Revision 1.1 2021/12/13 17:20:03CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/adapter/conv_images/cct_i400/project.pj
Revision 1.0 2017/03/03 10:30:38CET Sorge, Sven (uidg3181) 
Initial revision
Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/adapter/converters/conv_images/cct_i400/project.pj
Revision 1.1 2012/11/29 15:32:13CET Thiel, Robert (thielr) 
Initial revision
Member added to project /nfs/projekte1/PROJECTS/MFC400/06_Algorithm/04_Engineering/01_Source_Code/algo/cct/project.pj
Revision 1.4 2012/07/06 17:29:04CEST Friebertshaeuser, Markus (uidt0551) 
Updates after code review meeting
--- Added comments ---  uidt0551 [Jul 6, 2012 5:29:04 PM CEST]
Change Package : 118407:1 http://mks-psad:7002/im/viewissue?selection=118407
Revision 1.3 2011/04/15 16:46:17CEST Bachmann, Alexander (uidt5584) 
GIT update (Commit:5b0892f3ddd8fd69d47059fe2183d97e65914453)
--- Added comments ---  uidt5584 [Apr 15, 2011 4:46:18 PM CEST]
Change Package : 52130:2 http://mks-psad:7002/im/viewissue?selection=52130
Revision 1.1 2011/03/09 16:34:41CET Wagner Ulrich (uid04769) (uid04769) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SFOD_StereoFastObjectDetection/04_Engineering/01_Source_Code/Kernel/kernel_common/math3d/h/project.pj
Revision 1.4 2010/10/27 14:21:08CEST Wagner Ulrich (uid04769) (uid04769) 
GIT merge
--- Added comments ---  uid04769 [Oct 27, 2010 2:21:08 PM CEST]
Change Package : 37878:1 http://mks-psad:7002/im/viewissue?selection=37878
Revision 1.2 2010/02/24 11:18:19CET mdarms
Initial commit.
--- Added comments ---  mdarms [2010/02/24 10:18:19Z]
Change Package : 26827:2 http://LISS014:6001/im/viewissue?selection=26827
Revision 1.2  2010-02-11 10:58:30  iprep
gehrig: math3d wo newmat, paramReader commonData hardwired

Revision 1.4  2010-02-10 13:36:51  iprep
rabe: Newmat optional now.

Revision 1.3  2009-08-18 11:19:08  iprep
rabe: Added ZYX order for euler angles.

Revision 1.2  2008-08-18 08:20:00  iprep
rabe: Added clear method and optimized copy constructor.

Revision 1.1  2008-05-05 09:20:22  iprep
rabe: First version.


******************************************************************************/

/*****************************************************************************
 * END OF FILE
 ******************************************************************************/
