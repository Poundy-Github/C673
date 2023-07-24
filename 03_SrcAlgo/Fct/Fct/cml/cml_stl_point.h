/// Implementation of special column vector variants of cml::CMatrix that are called points since the mathematical
/// expression of a vector is already used by the stack-like container cml:CVector.

#ifndef cml_stl_point_h__
#define cml_stl_point_h__

#include "cml_stl_matrix.h"
#include "cml_stl_cmath.h"
#include "cml_stl_algorithm.h"

namespace cml
{
    /// \brief a two dimensional column vector.
    /// \details This class is derived publicly from CMatrix class with ROWS as 2 and COLS as 1 with EXR_MEM as "false".This class represents a two dimensional column vector that adds the scalar product,
    /// cross product and norm to the standard CMatrix operations. Also introduces named getters x() and y() for the two coordinates.
    /// \tparam T Content type of the coordinates.
    /// \testmethod
    /// \traceability
    template <typename T>
    class CartesianPoint2D : public cml::CMatrix<T, 2, 1, false>
    {
        typedef CartesianPoint2D<T>           self;  ///< Abbreviation for the type of the class.
        typedef cml::CMatrix<T, 2, 1, false>  super; ///< Base class of this CartesianPoint2D template configuration.

        /// Assigns coordinate names to indexes.
        enum CoordinateNames
        {
            X = 0, ///< Position of the X coordinate in the point and value is 0.
            Y      ///< Position of the Y coordinate in the point and value is 1.
        };

    public:
        /// \brief Default constructor
        /// \testmethod
        /// \traceability
        CartesianPoint2D()
            : super()
        {}

        /// \brief Constructor with member initialization.
        /// \details This constructor takes _x and _y as arguments and assigns to the x and y co-ordinates of the object by calling x() and y() functions respectively. 
        /// \param[in] _x Reference to value to initialize X coordinate of the point.
        /// \param[in] _y Reference to value to initialize Y coordinate of the point.
        /// \testmethod
        /// \traceability
        CartesianPoint2D(const T& _x, const T& _y)
            : super()
        {
            x() = _x;
            y() = _y;
        }

        /// \brief Constructor using CMatrix object "mat" to enable usage of methods on results of operations defined in CMatrix
        /// \details This takes constant reference to the CMatrix object as an argument and passes it to the base class CMatrix constructor.
        /// \param[in] mat   Constant reference to vector
        /// \testmethod
        /// \traceability
        CartesianPoint2D(const super& mat)
            : super(mat)
        {}

        /// \brief The x getter.
        /// \details Get the X coordinate of the point.This function calls the base class index operator overloading function with 0 as an argument.
        /// \return   Reference to X co-ordinate.
        /// \testmethod
        /// \traceability
        T& x(){return super::operator[](X);}

        /// \brief The y getter
        /// \details Get the Y coordinate of the point.This function calls the base class index operator overloading function with 1 as an argument.
        /// \return   Reference to Y co-ordinate.
        /// \testmethod
        /// \traceability
        T& y(){return super::operator[](Y);}

        /// \brief The const x getter
        /// \details Gets the constant reference to X coordinate of the point.This function calls the base class index operator overloading function with 0 as an argument.
        /// \return   Constant reference to X co-ordinate.
        /// \testmethod
        /// \traceability
        const T& x() const {return super::operator[](X);}

        /// \brief The const y getter
        /// \details Get the constant reference to Y coordinate of the point.This function calls the base class index operator overloading function with 1 as an argument.
        /// \return   Constant reference to Y co-ordinate.
        /// \testmethod
        /// \traceability
        const T& y() const {return super::operator[](Y);}

        /// \brief Calculate the length of the vector
        /// \details This function calls normSq() function which returns the sum of squares of x co-ordinate and y co-ordinate.Then it calls sqrt() to find the root of the value returned from  normSq() function.
        /// \InOutCorrelation  \f[ length = \sqrt{x^2+y^2} \f] 
        /// \return Length of the vector
        /// \testmethod
        /// \traceability
        float32 norm() const
        {
            return cml::sqrt( normSq() );
        }

        /// \brief Calculate the squared length of the vector
        /// \details This function calculates the sum of the squares of x co-ordinate and y co-ordinate.
        /// \InOutCorrelation  \f[ length = {x^2+y^2} \f] 
        /// \return Squared length of the vector
        /// \testmethod
        /// \traceability
        float32 normSq() const
        {
            return cml::pow<2>(x()) + cml::pow<2>(y());
        }

        /// \brief Calculate the scalar product of self and input vector 
        /// \details Assuming calling objects co-ordinates are x1 and y1 and object "rhs" co-ordinates are x2 and y2.Then this function returns x1x2+y1y2.This function calls trnspMul(0 function with "rhs" as argument and returns value at position (0,0) by calling at() function.
        /// \InOutCorrelation  \f[ scalarproduct = {x1 \times x2+y1 \times y2} \f] 
        /// \param[in] rhs Right hand side cartesian point
        /// \return        Resulting scalar product
        /// \testmethod
        /// \traceability
        T scalarProduct(const self& rhs) const
        {
            return super::trnspMul(rhs).at(0, 0);
        }

        /// \brief Calculate the cross product of self and input vector 
        /// \details Assuming calling objects co-ordinates are x1 and y1 and object "rhs" co-ordinates are x2 and y2.Then this function returns x1y2+y1x2.
        /// \InOutCorrelation  \f[ crossproduct = {x1 \times y2+y1 \times x2} \f] 
        /// \param[in] rhs Right hand side vector
        /// \return        Scalar value representing the z co-ordinate of the resulting vector
        /// \testmethod
        /// \traceability
        T crossProduct(const self& rhs) const
        {
            return ((x() * rhs.y()) - (y() * rhs.x()));
        }
    };

    /// \brief a three dimensional column vector.
    /// \details This class is derived publicly from CMatrix class with ROWS as 3 and COLS as 1 with EXR_MEM as "false".Represents a three dimensional column vector that adds the scalar product,
    /// cross product and norm to the standard CMatrix operations. Also introduces
    /// named getters x(), y() and z() for the three coordinates.
    /// \tparam T Content type of the coordinates.
    /// \testmethod
    /// \traceability
    template <typename T>
    class CartesianPoint3D : public cml::CMatrix<T, 3, 1, false>
    {
        typedef CartesianPoint3D<T>           self;  ///< Abbreviation for the type of the class.
        typedef cml::CMatrix<T, 3, 1, false>  super; ///< Base class of this CartesianPoint3D template configuration.

        /// Assigns coordinate names to indexes.
        enum CoordinateNames
        {
            X = 0, ///< Position of the X coordinate in the point and the value is 0.
            Y,     ///< Position of the Y coordinate in the point and the value is 1.
            Z      ///< Position of the Z coordinate in the point and the value is 2.
        };
    public:
        /// \brief Default constructor
        /// \testmethod
        /// \traceability
        CartesianPoint3D()
            : super()
        {}

        /// \brief Constructor with member initialization
        /// \details This constructor takes _x ,_y and _z as arguments and assigns to the x ,y and z co-ordinates of the object by calling x(), y() and z() functions respectively. 
        /// \param[in] _x Reference to value to initialize X coordinate of the point.
        /// \param[in] _y Reference to value to initialize Y coordinate of the point.
        /// \param[in] _z Reference to value to initialize Z coordinate of the point.	
        /// \testmethod
        /// \traceability
        CartesianPoint3D(const T& _x, const T& _y, const T& _z)
            : super()
        {
            x() = _x;
            y() = _y;
            z() = _z;
        }

        /// \brief Constructor using CMatrix to enable usage of methods on results of operations defined in CMatrix
        /// \details This takes constant reference to the CMatrix object as an argument and passes it to the base class CMatrix constructor.
        /// \param[in] mat Constant reference to vector
        /// \testmethod
        /// \traceability
        CartesianPoint3D(const super& mat)
            : super(mat)
        {}

        /// \brief The x getter
        /// \details Get the X coordinate of the point.This function calls the base class index operator overloading function with 0 as an argument.
        /// \return   Reference to X co-ordinate.
        /// \testmethod
        /// \traceability
        T& x(){return super::operator[](X);}

        /// \brief The y getter
        /// \details Get the Y coordinate of the point.This function calls the base class index operator overloading function with 1 as an argument.
        /// \return   Reference to Y co-ordinate.
        T& y(){return super::operator[](Y);}

        /// \brief The z getter
        /// \details Get the Z coordinate of the point.This function calls the base class index operator overloading function with 2 as an argument.
        /// \return   Reference to Z co-ordinate.
        /// \testmethod
        /// \traceability
        T& z(){return super::operator[](Z);}

        /// \brief The const x getter
        /// \details Gets the constant reference to X coordinate of the point.This function calls the base class index operator overloading function with 0 as an argument.
        /// \return   Constant reference to X co-ordinate.
        /// \testmethod
        /// \traceability
        const T& x() const {return super::operator[](X);}

        /// \brief The const y getter
        /// \details Gets the constant reference to Y coordinate of the point.This function calls the base class index operator overloading function with 1 as an argument.
        /// \return   Constant reference to Y co-ordinate.
        /// \testmethod
        /// \traceability
        const T& y() const {return super::operator[](Y);}

        /// \brief The const z getter
        /// \details Gets the constant reference to Z coordinate of the point.This function calls the base class index operator overloading function with 2 as an argument.
        /// \return   Constant reference to Z co-ordinate.
        /// \testmethod
        /// \traceability
        const T& z() const {return super::operator[](Z);}

        /// \brief Calculate the length of the vector.
        /// \details This function calls normSq() function which returns the sum of squares of x,y and z co-ordinates.Then it calls sqrt() to find the root of the value returned from  normSq() function.
        /// \InOutCorrelation  \f[ length = \sqrt{x^2+y^2+z^2} \f] 
        /// \return Length of vector.
        /// \testmethod
        /// \traceability
        float32 norm() const
        {
            return cml::sqrt( normSq() );
        }

        /// \brief Calculate the squared length of the vector.
        /// \details This function calculates the sum of the squares of x,y and z co-ordinates.
        /// \InOutCorrelation  \f[ length = {x^2+y^2+z^2} \f] 
        /// \return Squared length of the vector.
        /// \testmethod
        /// \traceability
        float32 normSq() const
        {
            return cml::pow<2>(x()) + cml::pow<2>(y()) + cml::pow<2>(z());
        }

        /// \brief Calculate the scalar product of self and input vector. 
        /// \details Assuming calling objects co-ordinates are x1,y1 and z1 and object "rhs" co-ordinates are x2,y2 and z2.Then this function returns x1x2+y1y2+z1z2.This function calls trnspMul() function with "rhs" as argument and returns value at position (0,0) by calling at() function.
        /// \InOutCorrelation  \f[ scalarproduct = {x1 \times x2+y1 \times y2+z1 \times z2} \f] 
        /// \param[in] rhs Right hand side carthesian point.
        /// \return        Resulting scalar product.
        /// \testmethod
        /// \traceability
        T scalarProduct(const self& rhs) const
        {
            return super::trnspMul(rhs).at(0, 0);
        }

        /// \brief Calculate the cross product of self and input vector. 
        /// \details ex: self.x() = ((*this).y() * rhs.z()) - ((*this).z() * rhs.y());
        /// \InOutCorrelation  
        ///  assuming calling objects co-ordinates are x1,y1 and z1.Object "rhs" co-ordinates are x2,y2 and z2.Then 
        /// \f[ result.x = {y1 \times z2-z1 \times y2} \f] \n
        /// \f[ result.y = {z1 \times x2-x1 \times z2} \f] \n
        /// \f[ result.z = {x1 \times y2-y1 \times x2} \f] \n
        ///  It returns the object "result".
        /// \param[in] rhs Right hand side vector.
        /// \return        Resulting cross product vector.
        /// \testmethod
        /// \traceability
        self crossProduct(const self& rhs) const
        {
            self result;
            result.x() = (y() * rhs.z()) - (z() * rhs.y());
            result.y() = (z() * rhs.x()) - (x() * rhs.z());
            result.z() = (x() * rhs.y()) - (y() * rhs.x());
            return result;
        }
    };

}

#endif // cml_stl_point_h__
