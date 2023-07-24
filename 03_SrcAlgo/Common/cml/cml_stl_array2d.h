/*! \file **********************************************************************

COMPANY:                   Continental AG, A.D.C. GmbH

CPU:                       CPU-Independent

COMPONENT:                 CML (Common Math Library)

MODULNAME:                 cml_stl_array2d.h

DESCRIPTION:               Two dimensional array library

AUTHOR:                    Markus Friebertshaeuser

CREATION DATE:             15.11.2012

VERSION:                   $Revision: 1.30 $

**************************************************************************** */

#ifndef CML_STL_ARRAY2D_H__
#define CML_STL_ARRAY2D_H__

#include "cml_stl_array.h"
#include <limits>

namespace cml
{

    /// \brief Two-dimensional implementation of an array.
    /// \details Two-dimensional array class "CArray2D" is publicly derived from single  dimentional array class "CArray".
    ///  Base class single dimentional array size is ROWS*COLS.ROWS and COLS are the rows and columns of Two-dimensional array.
    /// \tparam T       The type of the elements
    /// \tparam ROWS    The number of rows of the array
    /// \tparam COLS    The number of columns of the array
    /// \tparam EXT_MEM Flag whether the memory of the elements of the array is inside
    ///                 of this class (false) or outside of this class (true).
    ///                 Default is false, meaning internal memory.
    /// \testmethod
    /// \traceability
    template < class T, sint32 ROWS, sint32 COLS, boolean_t EXT_MEM = false >
    class CArray2D
        : public CArray<T, ROWS*COLS, EXT_MEM>
    {
    public:
        static const sint32 SIZE = ROWS * COLS;

        typedef CArray2D<T, ROWS, COLS, EXT_MEM> self;  ///< Abbreviation for the type of the class.
        typedef CArray  <T, SIZE,       EXT_MEM> super;  ///< Base class of this CArray2D template configuration.
        typedef sint32                           size_type;  ///< Abbreviation for the signed integer type and it is used for storing array size.
        typedef typename remove_const<T>::type   type;  ///< Alias name for the type(non constant) of the CArray2D elements.
        typedef typename    add_const<T>::type   const_type;  ///< Alias name for the constant type of the CArray2D elements.
        typedef typename remove_const<T>::type&  reference;   ///< Alias name for the reference to the type of the CArray2D elements.
        typedef typename    add_const<T>::type&  const_reference;  ///< Alias name for the constant reference to the type of the CArray2D elements.
        typedef typename remove_const<T>::type*  pointer;   ///< Alias name for the pointer to the type of the CArray2D elements.
        typedef typename    add_const<T>::type*  const_pointer;   ///< Alias name for the constant pointer to the type of the CArray2D elements.
        // iterator typedefs
#ifndef NDEBUG
        typedef cml::CLinMemIt< type, false, super >  it;  ///< Alias name for the iterator to the CArray2D elements.
        typedef cml::CLinMemIt< type, true , super > cIt;  ///< Alias name for the constant iterator to the CArray2D elements.
#else
        typedef cml::CLinMemIt< type, false >  it;  ///< Alias name for the iterator to the CArray2D elements.
        typedef cml::CLinMemIt< type, true  > cIt;  ///< Alias name for the constant iterator to the CArray2D elements.
#endif
        typedef it  iterator;  ///< iterator to the CArray2D elements.
        typedef cIt const_iterator;  ///< constant iterator to the CArray2D elements.


        /// \brief Default empty constructor.
        /// \testmethod
        /// \traceability
        CArray2D(){}

        /// \brief Constructor with non-constant pointer to a constant data and constant size. 
        /// \details Constructor that copies the given non-constant pointer 
        /// constant external data to the internal memory.These parameters will be passed to the base class constructor in which actual data member initialization happens.
        /// \param[in]       data    Non-constant pointer to the constant external data. 
        /// \param[in]       size    Constant size of the external buffer.
        CArray2D(       pointer const data, const sint32 size ) : super(data, size) {}

        /// \brief Constructor with constant pointer to a constant data constant size.  
        /// \details Constructor that copies the given constant pointer 
        /// constant external data to the internal memory.These parameters will be passed to the base class constructor in which actual data member initialization happens.
        /// \param[in]       data    Constant pointer to the constant external data. 
        /// \param[in]       size    Constant size of the external buffer.
        /// \testmethod
        /// \traceability
        CArray2D( const_pointer const data, const sint32 size ) : super(data, size) {}

        /// \brief Template constructor with non-constant external data.
        /// \details Template constructor that copies the given non-constant reference 
        /// non-constant external data of possibly different size (SIZE2) to the internal memory.
        /// Non-constant reference will be passed as an argument to the base class constructor in which actual data member initialization happens.
        /// Copies external data to the internal data storage.
        /// \tparam SIZE2    The size of the non-constant external data.    
        /// \param[in]       data    Non-constant reference to the external data of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2 >
        CArray2D(       type (&data)[SIZE2] ) : super(data) {}

        /// \brief Template constructor with constant external data.
        /// \details Template constructor that copies the given non-constant reference 
        ///  constant external data of possibly different size (SIZE2) to the internal memory. 
        /// Non-constant reference will be passed as an argument to the base class constructor in which actual data member initialization happens. 
        /// \tparam SIZE2    The size of the non-constant external data.     
        /// \param[in]       data    Constant reference to the external data of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2 >
        CArray2D( const_type (&data)[SIZE2] ) : super(data) {}

        /// \brief Template constructor with non-constant external data.
        /// \details Template constructor that copies or attaches constant reference external identical data 
        /// with non-constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the internal data storage.
        /// Object (rhs) will be passed as an argument to the base class constructor in which actual data member initialization happens. 
        /// \tparam SIZE2    The size of the non-constant external data.   
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs    Constant reference to the non-constant external data of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CArray2D( const CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs ) : super(rhs) {}

        /// \brief Template constructor with constant external data.
        /// \details Template constructor that copies or attaches constant reference external identical data 
        ///  with constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the internal data storage.
        ///  Object (rhs) will be passed as an argument to the base class constructor in which actual data member initialization happens.
        /// \tparam SIZE2    The size of the constant external data.   
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs    Constant reference to the constant external data of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CArray2D( const CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs ) : super(rhs) {}

        /// \brief Template constructor with non-constant reference to non-constant external data.
        /// \details Template constructor that copies or attaches non-constant reference external identical data 
        ///  with non-constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the internal data storage.
        ///  Object (rhs) will be passed as an argument to the base class constructor in which actual data member initialization happens.
        /// \tparam SIZE2    The size of the non-constant external data.   
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs    Non-constant reference to the non-constant external data of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CArray2D( CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs ) : super(rhs) {}

        /// \brief Template constructor with non-constant reference to non-constant external data.
        /// \details Template constructor that copies or attaches non-constant reference external identical data 
        ///  with constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the internal data storage.
        ///  Object (rhs) will be passed as an argument to the base class constructor in which actual data member initialization happens.
        /// \tparam SIZE2    The size of the constant external data.   
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs    Non-constant reference to the constant external data of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CArray2D( CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs ) : super(rhs) {}

        /// \brief Returns number of rows of the 2D array.
        /// \details Returns number of rows(ROWS) of the calling object 2D array.ROWS is the template parameter of CArray2D class.
        /// \return          Number of Rows in the 2D array.
        /// \testmethod
        /// \traceability
        static sint32 rows() { return ROWS; }

        /// \brief Returns number of Columns of the 2D array.
        /// \details Returns number of Columns(COLS) of the calling object 2D array.COLS is the template parameter of CArray2D class.
        /// \return          Number of Columns in the 2D array.
        /// \testmethod
        /// \traceability
        static sint32 cols() { return COLS; }

        /// \brief Template assignment operator overloading function with non-constant external data.
        /// \details copy external identical object(rhs) CArray2D content
        /// with possibly different memory specializations(EXT_MEM2) to the internal storage.
        /// This function calls base class assignment operator overloading function with object rhs as an argument.
        /// Returns the reference to the calling object.
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs    Constant reference to non-constant external data buffer of identical size.
        /// \return          Reference to this pointer.
        /// \testmethod
        /// \traceability
        template< boolean_t EXT_MEM2 >
        CArray2D& operator=(const CArray2D<      type, ROWS, COLS, EXT_MEM2>& rhs)
        {
            super::operator=(rhs);
            return *this;
        }

        /// \brief Template assignment operator overloading function with constant external data.
        /// \details copy external identical object(rhs) CArray2D ,constant data
        /// with possibly different memory specializations(EXT_MEM2) to the internal storage.
        /// This function calls base class assignment operator overloading function with object rhs as an argument.
        /// Returns the reference to the calling object.
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs    Constant reference to constant external data buffer of identical size.
        /// \return          Reference to this pointer.
        /// \testmethod
        /// \traceability
        template< boolean_t EXT_MEM2 >
        CArray2D& operator=(const CArray2D<const_type, ROWS, COLS, EXT_MEM2>& rhs)
        {
            super::operator=(rhs);
            return *this;
        }

        /// This is only required for TI-Compiler to be able to compile
        using super::operator[];
        // End of section required for TI-Compiler

        /// \brief Operator() overloaded function which returns the reference to the element at position (row,col) of 2D array. 
        /// \details This function calls index operator overloading function of a base class (one dimentional array) with the argument "row*COLS + col".
        ///  Returns the reference to the element.
        /// \attention Given row and column positions should be within available ROWS and COLS.
        /// \param[in]       row    Constant row position of the element. 
        /// \param[in]       col    Constant column position of the element. 
        /// \return          Reference to array element at position "row*COLS + col".
        /// \testmethod
        /// \traceability
        reference operator()(const size_type row, const size_type col)
        {
            // In operator[] only the whole array is checked
            assert( (row < ROWS) && (col < COLS) );
            return operator[]( (row*COLS) + col );
        }

        /// \brief Operator() overloaded function which returns the constant reference to the element at position (row,col) of 2D array. 
        /// \details This function calls index operator overloading function of a base class (one dimentional array) with the argument "row*COLS + col".
        ///  Returns the constant reference to the element.
        /// \attention Given row and column positions should be within available ROWS and COLS.
        /// \param[in]       row    Constant row position of the element 
        /// \param[in]       col    Constant column position of the element 
        /// \return          Constant reference to Array element at row*COLS + col
        /// \testmethod
        /// \traceability
        const_reference operator()(const size_type row, const size_type col) const
        {
            // In operator[] only the whole array is checked
            assert( (row < ROWS) && (col < COLS) );
            return operator[]( (row*COLS) + col );
        }

        /// \brief Returns a reference to the element of 2D array class at given row and column position.
        /// \details This function calls operator() overloaded function with row , column as arguments. 
        /// \param[in]       row    Constant row position of the element 
        /// \param[in]       col    Constant column position of the element 
        /// \return          Reference to Array element at given row and column position
        /// \testmethod
        /// \traceability
        reference at(const size_type row, const size_type col)
        {
            return operator()(row, col);
        }

        /// \brief Returns a constant reference to the element of 2D array class at given row and column position.
        /// \details This function calls operator() overloaded function with row , column as arguments.
        /// \param[in]       row    Constant row position of the element. 
        /// \param[in]       col    Constant column position of the element. 
        /// \return          Constant reference to Array element at given row and column position.
        /// \testmethod
        /// \traceability
        const_reference at(const size_type row, const size_type col) const
        {
            return operator()(row, col);
        }


        typedef it                                                   rowIt; ///< iterator iterating along a single row
        typedef cIt                                                 cRowIt; ///< const iterator iterating along a single row
#ifndef NDEBUG
        typedef typename cml::CLinMemIt< type, false, super, COLS >  colIt; ///< iterator iterating along a single column
        typedef typename cml::CLinMemIt< type, true , super, COLS > cColIt; ///< const iterator iterating along a single column
#else
        typedef typename cml::CLinMemIt< type, false, COLS >         colIt; ///< iterator iterating along a single column
        typedef typename cml::CLinMemIt< type, true , COLS >        cColIt; ///< const iterator iterating along a single column
#endif

        /// \brief Returns an iterator to the first row of the 2D array.
        /// \details Returns an iterator to the first row of the calling 2D array object.
        /// This iterator stores the address of data member of 2D array object at position "row*COLS".
        /// \attention Must ensure that row is within the bounds.Otherwise behaviour is undefined.				   
        /// \param[in]       row    Row position. 
        /// \return          An iterator to the first row of this array.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        rowIt  rowBegin(sint32 row)        { assert(row < ROWS); return rowIt (&m_data[row*COLS], this, &m_data[row*COLS], &m_data[(row+1)*COLS]); }
#else
        rowIt  rowBegin(sint32 row)        { return rowIt (&m_data[row*COLS]); }
#endif

        /// \brief Returns a constant iterator to the first row of the 2D array.
        /// \details Returns a constant iterator to the first row of the calling 2D array object.
        /// This iterator stores the address of data member of 2D array object at position "row*COLS".
        /// This function will be called by both constant and non-constant objects.
        /// \attention Must ensure that row is within the bounds.Otherwise behaviour is undefined.
        /// \param[in]       row    Row position. 
        /// \return          A constant iterator to the first row of this array.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        cRowIt rowBegin(sint32 row)  const 
        { 
            assert(row < ROWS); 
            return cRowIt(&m_data[row*COLS], this, &m_data[row*COLS], &m_data[(row+1)*COLS]); 
        }
#else
        cRowIt rowBegin(sint32 row)  const 
        { 
            return cRowIt(&m_data[row*COLS]); 
        }
#endif

        /// \brief Returns a constant iterator to the first row of the 2D array.
        /// \details Returns a constant iterator to the first row of the calling 2D array object.
        /// This iterator stores the address of data member of 2D array object at position "row*COLS".
        /// This function will be called by both constant and non-constant objects.
        /// \attention Must ensure that row is within the bounds.Otherwise behaviour is undefined.
        /// \param[in]       row    Row position. 
        /// \return          A constant iterator to the first row of this array.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        cRowIt cRowBegin(sint32 row) const 
        { 
            assert(row < ROWS);
            return cRowIt(&m_data[row*COLS], this, &m_data[row*COLS], &m_data[(row+1)*COLS]); 
        }
#else
        cRowIt cRowBegin(sint32 row) const 
        { 
            return cRowIt(&m_data[row*COLS]);
        }
#endif
        /// \brief Returns an iterator to the last row of the 2D array.
        /// \details Returns an iterator to the last row of the calling 2D array object.
        /// This iterator stores the address of data member of 2D array object at position "(row+1)*COLS".
        /// \attention Must ensure that row is within the bounds.Otherwise behaviour is undefined.
        /// \param[in]       row    Row position.  
        /// \return          An iterator to last row of this array.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        rowIt  rowEnd(sint32 row)        { assert(row < ROWS); return rowIt (&m_data[(row+1)*COLS], this, &m_data[row*COLS], &m_data[(row+1)*COLS]); }
#else
        rowIt  rowEnd(sint32 row)        { return rowIt (&m_data[(row+1)*COLS]); }
#endif
        /// \brief Returns a constant iterator to the last row of the 2D array.
        /// \details Returns a constant iterator to the last row of the calling 2D array object.
        /// This iterator stores the address of data member of 2D array object at position "(row+1)*COLS".
        /// This function will be called by both constant and non-constant objects.  
        /// \attention Must ensure that row is within the bounds.Otherwise behaviour is undefined.
        /// \param[in]       row    Row position 
        /// \return          A constant iterator to the last row of this array.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        cRowIt rowEnd(sint32 row)  const { assert(row < ROWS); return cRowIt(&m_data[(row+1)*COLS], this, &m_data[row*COLS], &m_data[(row+1)*COLS]); }
#else
        cRowIt rowEnd(sint32 row)  const { return cRowIt(&m_data[(row+1)*COLS]); }
#endif
        /// \brief Returns a constant iterator to the last row of the 2D array.
        /// \details Returns a constant iterator to the last row of the calling 2D array object.
        /// This iterator stores the address of data member of 2D array object at position "(row+1)*COLS".
        /// This function will be called by both constant and non-constant objects.  
        /// \attention Must ensure that row is within the bounds.Otherwise behaviour is undefined.
        /// \param[in]       row    Row position. 
        /// \return          A constant iterator to the last row of this array.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        cRowIt cRowEnd(sint32 row) const { assert(row < ROWS); return cRowIt(&m_data[(row+1)*COLS], this, &m_data[row*COLS], &m_data[(row+1)*COLS]); }
#else
        cRowIt cRowEnd(sint32 row) const { return cRowIt(&m_data[(row+1)*COLS]); }
#endif

        /// \brief Returns an iterator to the first column of the 2D array.
        /// \details Returns an iterator to the first column of the calling 2D array object.
        /// This iterator stores the address of data member of 2D array object at position "col".
        /// This function will be called by both constant and non-constant objects.
        /// \attention Must ensure that col is within the bounds.Otherwise behaviour is undefined.
        /// \param[in]       col    Column position. 
        /// \return          An iterator to the first column of this array.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        colIt  colBegin(sint32 col)        { assert(col < COLS); return colIt (&m_data[col], this); }
#else
        colIt  colBegin(sint32 col)        { return colIt (&m_data[col]); }
#endif

        /// \brief Returns a constant iterator to the first column of the 2D array.
        /// \details Returns a constant iterator to the first column of the calling 2D array object.
        /// This iterator stores the address of data member of 2D array object at position "col".
        /// This function will be called by both constant and non-constant objects.
        /// \attention Must ensure that col is within the bounds.Otherwise behaviour is undefined.
        /// \param[in]       col    Column position. 
        /// \return          A constant iterator to the first column of this array.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        cColIt colBegin(sint32 col)  const { assert(col < COLS); return cColIt(&m_data[col], this); }
#else
        cColIt colBegin(sint32 col)  const { return cColIt(&m_data[col]); }
#endif
        /// \brief Returns a constant iterator to the first column of the 2D array.
        /// \details Returns a constant iterator to the first column of the calling 2D array object.
        /// This iterator stores the address of data member of 2D array object at position "col".
        /// This function will be called by both constant and non-constant objects.
        /// \attention Must ensure that col is within the bounds.Otherwise behaviour is undefined.
        /// \param[in]       col    Column position. 
        /// \return          A constant iterator to the first column of this array.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        cColIt cColBegin(sint32 col) const { assert(col < COLS); return cColIt(&m_data[col], this); }
#else
        cColIt cColBegin(sint32 col) const { return cColIt(&m_data[col]); }
#endif
        /// \brief Returns an iterator to the last column of the 2D array.
        /// \details Returns an iterator to the last column of the calling 2D array object.
        /// This iterator stores the address of data member of 2D array object at position "col+SIZE".
        /// \attention Must ensure that col is within the bounds.Otherwise behaviour is undefined.
        /// \param[in]       col    Column position.
        /// \return          Returns an iterator to the last column of this array.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        colIt  colEnd(sint32 col)        { assert(col < COLS); return colIt (&m_data[col+SIZE], this); }
#else
        colIt  colEnd(sint32 col)        { return colIt (&m_data[col+SIZE]); }
#endif

        /// \brief Returns an iterator to the last column of the 2D array.
        /// \details Returns an iterator to the last column of the calling 2D array object.
        /// This iterator stores the address of data member of 2D array object at position "col+SIZE".
        /// This function will be called by both constant and non-constant objects.
        /// \attention Must ensure that col is within the bounds.Otherwise behaviour is undefined.
        /// \param[in]       col    Column position.
        /// \return          Returns a constant iterator to the last column of this array.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        cColIt colEnd(sint32 col)  const { assert(col < COLS); return cColIt(&m_data[col+SIZE], this); }
#else
        cColIt colEnd(sint32 col)  const { return cColIt(&m_data[col+SIZE]); }
#endif
        /// \brief Returns an iterator to the last column of the 2D array.
        /// \details Returns an iterator to the last column of the calling 2D array object.
        /// This iterator stores the address of data member of 2D array object at position "col+SIZE".
        /// This function will be called by both constant and non-constant objects.
        /// \attention Must ensure that col is within the bounds.Otherwise behaviour is undefined.
        /// \param[in]       col    Column position.
        /// \return          Returns a constant iterator to the last column of this array.
        /// \testmethod
        /// \traceability
             
#ifndef NDEBUG
        cColIt cColEnd(sint32 col) const { assert(col < COLS); return cColIt(&m_data[col+SIZE], this); }
#else
        cColIt cColEnd(sint32 col) const { return cColIt(&m_data[col+SIZE]); }
#endif

        // This is only required for TI-Compiler to be able to compile
    protected:
        using super::m_data; ///< Protected data element of the base class CArrayStorage which provides storage for the CArray2D elements.
        // End of section required for TI-Compiler
    };
} //End of cml namespace


#endif //CML_STL_ARRAY2D_H__

