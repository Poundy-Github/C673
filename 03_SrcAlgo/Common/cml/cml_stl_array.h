/*! \file **********************************************************************

COMPANY:                   Continental AG, A.D.C. GmbH

CPU:                       CPU-Independent

COMPONENT:                 CML (Common Math Library)

MODULNAME:                 cml_stl_array.h

DESCRIPTION:               Array Library

AUTHOR:                    Markus Friebertshaeuser

CREATION DATE:             15.11.2012

VERSION:                   $Revision: 1.47 $

**************************************************************************** */

#ifndef CML_STL_ARRAY_H__
#define CML_STL_ARRAY_H__

#include "cml_stl_iterator.h"
#include "glob_type.h"
#include <algorithm>
#include <cstring>

namespace cml
{

    /// \brief Provides storage for Array.
    /// \details Provide Storage for Array specialized for internal memory,meaning array will be delared inside the class as a data member.For internal memory EXT_MEM = false.
    /// For external memory EXT_MEM = true.In case of external memory,array will be delared outside the class and pointer to the start of the array will be stored in the class as a data member.
    /// \tparam T       The type of the elements
    /// \tparam SIZE    The size of the array
    /// \tparam EXT_MEM Flag whether the memory of the elements of the array is inside
    ///                 of this class (false) or outside of this class (true).
    ///                 Default is false, meaning internal memory.
    /// \traceability
    /// \testmethod
    template<class T, sint32 SIZE, boolean_t EXT_MEM = false>
    class CArrayStorage;

    /// \brief Provides storage which is internal to the class for Array .
    /// \details Provide Storage for array specialized for internal memory,meaning array will be delared inside the class as a data member.For internal memory EXT_MEM = false.
    /// \tparam T       The type of the elements
    /// \tparam SIZE    The size of the array
    /// \traceability
    /// \testmethod
    
    template<class T, sint32 SIZE>
    class CArrayStorage<T, SIZE, false>
    {
    public:
        typedef CArrayStorage<T, SIZE, false>   self;  ///< Abbreviation for the type of the class.
        typedef int                             size_type;  ///< Abbreviation for the integer type and it is used for storing array size.
        typedef typename remove_const<T>::type  type;        ///< Alias name for the type(non constant) of the CArrayStorage elements.
        typedef typename    add_const<T>::type  const_type;  ///< Alias name for the constant type of the CArrayStorage elements.
        typedef typename remove_const<T>::type& reference;   ///< Alias name for the reference to the type of the CArrayStorage elements.
        typedef typename    add_const<T>::type& const_reference;  ///< Alias name for the constant reference to the type of the CArrayStorage elements.

        /// \brief enumerates MAX_SIZE with SIZE.
        enum { MAX_SIZE = SIZE  ///< maximum size of the CArrayStorage memory is SIZE which is a template parameter.
             };

        /// \brief Default empty constructor.
        /// \testmethod
        /// \traceability
        // PRQA S 4054 4
        // date: 2015-21-07, reviewer: Markus Friebertshaeuser, reason:
        //   Our strategy is to have a late init using the reset call.
        //   This is necessary to be able to fulfill the SIL-SIL requirement
        CArrayStorage() {}

        /// \brief constructor that initializes internal storage of the object.
        /// \details Parameterized constructor that copies elements of the given constant pointer 
        /// constant data external array of size "s_size" into the internal storage of size "SIZE".
        /// \attention Caller should ensure that s_size >= SIZE.Otherwise behaviour is undefined.
        /// \param[in] p_data Constant pointer to external constant data buffer.
        /// \param[in] s_size Number of elements in the external data buffer.
        /// \testmethod
        /// \traceability
        explicit CArrayStorage(const T* const p_data, const sint32 s_size)
        {
            (void) s_size;
            assert( SIZE <= s_size );
            std::memcpy( &operator[](0), p_data, SIZE*sizeof(type) );
        }

        /// \brief Template constructor that initializes internal storage of the object.
        /// \details Template Parameterized constructor that copies elements of the given  
        /// constant data external array of size "SIZE2" into the internal storage of size "SIZE".It calls memcpy() to copy the data.
        /// \attention Caller should ensure that SIZE2 >= SIZE.Otherwise behaviour is undefined.
        /// \tparam    SIZE2 The size of the given external array.
        /// \param[in] data  Constant reference to the external constant Array of SIZE2.
        /// \testmethod
        /// \traceability
        template<sint32 SIZE2>
        explicit CArrayStorage( const T (&data)[SIZE2] )
        {
            assert( SIZE <= SIZE2 );
            std::memcpy( &operator[](0), &data[0], SIZE*sizeof(type) );
        }
        
        /// \brief Template constructor that initializes internal storage of the object.
        /// \details Template Parameterized constructor that copies elements of the given  
        /// non-constant data external array of size "SIZE2" into the internal storage of size "SIZE".It calls memcpy() to copy the data.
        /// \attention Caller should ensure that SIZE2 >= SIZE.Otherwise behaviour is undefined.
        /// \tparam    SIZE2 The size of the given external array.
        /// \param[in] data  Reference to the external non-constant Array of SIZE2.
        /// \testmethod
        /// \traceability
        template<sint32 SIZE2>
        explicit CArrayStorage(T (&data)[SIZE2] )
        {
            assert( SIZE <= SIZE2 );
            std::memcpy( &operator[](0), &data[0], SIZE*sizeof(type) );
        }

        /// \brief   Copy constructor that initializes internal storage of the object with similar object.
        /// \details Copy constructor that copies external identical data
        /// of same size to the internal data storage.It calls memcpy() to copy the data.
        /// \param[in] rhs Constant reference to the identical external Array of SIZE.
        /// \testmethod
        /// \traceability
        explicit CArrayStorage( const self& rhs )
        {
            std::memcpy( &operator[](0), &rhs[0], SIZE*sizeof(type) );
        }
        
        /// \brief  Template copy constructor that initializes internal storage of the object with similar object. 
        /// \details  Template copy constructor that copies non-constant external identical data 
        /// of different size "SIZE2" and possibly different memory specializations(EXT_MEM2) to the internal data storage of size "SIZE".
        /// It calls memcpy() to copy the data.
        /// \attention Caller should ensure that SIZE2 >= SIZE.Otherwise behaviour is undefined.
        /// \tparam SIZE2    The size of the given external array.
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs   Constant reference to the identical external Array of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CArrayStorage( const CArrayStorage<type,SIZE2,EXT_MEM2>& rhs )
        {
            assert( SIZE <= SIZE2 );
            std::memcpy( &operator[](0), &rhs[0], SIZE*sizeof(type) );
        }

        /// \brief  Template copy constructor that initializes internal storage of the object with similar object. 
        /// \details Template copy constructor that copies constant external identical data 
        /// of different size "SIZE2" and possibly different memory specializations(EXT_MEM2) to the internal data storage of size "SIZE.
        /// It calls memcpy() to copy the data.
        /// \attention Caller should ensure that SIZE2 >= SIZE.Otherwise behaviour is undefined.
        /// \tparam SIZE2    The size of the given external array.
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs   Constant reference to the identical external constant Array of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CArrayStorage( const CArrayStorage<const_type,SIZE2,EXT_MEM2>& rhs )
        {
            assert( SIZE <= SIZE2 );
            std::memcpy( &operator[](0), &rhs[0], SIZE*sizeof(type) );
        }

        /// \brief Index operator overloading function which returns a reference to the array element.
        /// \details Returns the reference to the array element at the given position.
        /// \attention "position" should be within the array limits.Otherwise behaviour is undefined.
        /// \param[in]       position   Constant position of the element.
        /// \return          Reference to the array element at given position.
        /// \testmethod
        /// \traceability
        reference operator[](const size_type position)
        {
            //make sure position is between limits - otherwise return zero's element
            assert( (position >= 0) && (position < size()) );
            return m_data[position];
        }

        /// \brief Index operator overloading function which returns a constant reference to the array element.
        /// \details Returns the constant reference to the array element at given position.
        /// \attention "position" should be within the array limits.Otherwise behaviour is undefined.
        /// \param[in]       position   Constant position of the element.
        /// \return          Constant reference to Array element at given position.
        /// \testmethod
        /// \traceability
        const_reference operator[](const size_type position) const
        {
            assert( (position >= 0) && (position < size()) );
            return m_data[position];
        }

        /// \brief Returns number of elements in the array.
        /// \details This function calls another function max_size() which returns the size(SIZE) of the array.This array size is "SIZE" which is a template parameter.
        /// \return   Number of elements in the Array.
        /// \testmethod
        /// \traceability
        static sint32 size()
        {
            return max_size();
        }

        /// \brief Returns number of elements in the array.
        /// \details This function returns the size(SIZE) of the array.This array size is "SIZE" which is a template parameter.
        /// \return          Number of elements in the Array.
        /// \testmethod
        /// \traceability
        static sint32 max_size()
        {
            return SIZE;
        }

        protected:
            T m_data[SIZE];///< m_data is an array of size "SIZE".Since this class is a template specialized for the internal memory with EXT_MEM as false, m_data is delared as an array of size SIZE.
    };

    /// \brief Arraystorage class with constant data and internal memory.
    /// \details This class variant is not usable, since an array with only constant data
    /// inside can't be initialized in cpp.
    /// \tparam T       The type of the elements
    /// \tparam SIZE    The size of the array
    /// \testmethod
    /// \traceability
    template<class T, sint32 SIZE>
    class CArrayStorage<const T, SIZE, false>;

    /// \brief Provides pointer to the array which has memory external to the class.
    /// \details Provide Storage for Array, specialized for external memory and non-constant data.For external memory EXT_MEM = true.
    /// This class contains only a pointer of type T as a protected data member.actual array will be declared outside of this class and only array base address will be attached to the pointer data member of this class.
    /// \tparam T       The type of the elements
    /// \tparam SIZE    The size of the array
    /// \testmethod
    /// \traceability
    
    template<class T, sint32 SIZE>
    class CArrayStorage<T,SIZE,true>
    {
    public:
        typedef CArrayStorage<T,SIZE,true> self;  ///< Abbreviation for the type of the class.
        typedef int                        size_type; ///< Abbreviation for the integer type and it is used for storing array size.

        enum { MAX_SIZE = SIZE   ///< maximum size of the External memory.
             };

        /// \brief Default constructor for specialization of external memory.
        /// \attention Makes the storage invalid in debug mode.
        /// \testmethod
        /// \traceability
        CArrayStorage()
#ifndef NDEBUG
                : m_data(0)
#endif
            {}

        /// \brief constructor that attaches external data of type non-constant pointer
        /// constant data to the internal pointer.
        /// \details It calls the attach() function.attach function attaches the external array pointer to the internal pointer which is a data member of the class.
        /// \attention Caller should ensure that s_size >= SIZE.Otherwise behaviour is undefined.
        /// \param[in] p_data   Non-constant pointer to the constant external data buffer.
        /// \param[in] s_size   Constant size of the external data buffer.
        /// \testmethod
        /// \traceability
        CArrayStorage(T* const p_data, const sint32 s_size)
        {
            attach(p_data, s_size);
        }

        /// \brief Template copy constructor that attaches external data of type non-constant reference
        /// non-constant data to the internal pointer.
        /// \details It calls the attach() function.attach function attaches the external array pointer to the internal pointer which is a data member of the class.
        /// \attention Caller should ensure that SIZE2 >= SIZE.Otherwise behaviour is undefined.
        /// \tparam SIZE2    The size of the external array.
        /// \param[in]       data  Reference to the external non-constant data buffer of SIZE2.
        /// \testmethod
        /// \traceability
        template<sint32 SIZE2>
        explicit CArrayStorage( T (&data)[SIZE2] )
        {
            attach(&data[0], SIZE2);
        }

        /// \brief Template copy constructor to attach external identical non-constant data(T) of different size(SIZE2) and possibly different memory 
        /// specializations(EXT_MEM2) to the internal pointer.
        /// \details It calls the attach() function.attach function attaches the external array pointer to the internal pointer which is a data member of the class.
        /// \attention Caller should ensure that SIZE2 >= SIZE.Otherwise behaviour is undefined.
        /// \tparam SIZE2    The size of the external array.
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs   Reference to the external non-constant data buffer of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CArrayStorage( CArrayStorage<T,SIZE2,EXT_MEM2>& rhs )
        {
            attach(&rhs[0], SIZE2);
        }

        /// \brief Assignment operator overloading template function with non-constant data.
        /// \details Copy external identical constant reference non-constant data of same size(SIZE) and possibly different memory(EXT_MEM2)
        /// specializations to the internal storage.It calls memcpy() to assign the data.
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs   Constant reference to external non-constant data buffer of identical size.
        /// \return          Reference to this pointer.
        /// \testmethod
        /// \traceability
        template< boolean_t EXT_MEM2 >
        CArrayStorage& operator=(const CArrayStorage<T,SIZE,EXT_MEM2>& rhs)
        {
            std::memcpy( &operator[](0), &rhs[0], SIZE*sizeof(T) );
            return *this;
        }

        /// \brief Assignment operator overloading function with constant data.
        /// \details Copy external identical constant reference constant data of size(SIZE) and possibly different memory 
        /// specializations(EXT_MEM2) to the internal storage.It calls memcpy() to assign the data.
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs   Constant reference to external constant data buffer of identical size.
        /// \return          Reference to this pointer.
        /// \testmethod
        /// \traceability
        template< boolean_t EXT_MEM2 >
        CArrayStorage& operator=(const CArrayStorage<const T,SIZE,EXT_MEM2>& rhs)
        {
            std::memcpy( &operator[](0), &rhs[0], SIZE*sizeof(T) );
            return *this;
        }

        /// \brief Index operator overloading function which returns reference.
        /// \details Returns the reference to the element at given constant position in the array of data.
        /// \attention 1) make sure data was initialized( m_data != 0 ).
        ///	           2) make sure position is between the array limits.Otherwise behaviour is undefined.
        /// \param[in]       position   Constant position of the element.
        /// \return          Reference to the array element at given position.
        /// \testmethod
        /// \traceability
        T& operator[](const size_type position)
        {
            // make sure data was initialized
            assert( m_data != 0 );
            // make sure position is between limits
            assert( (position >= 0) && (position < size()) );
            return m_data[position];
        }

        /// \brief Index operator overloading function which returns constant reference.
        /// \details Returns the constant reference to the element at given constant position with constant object.
        /// \attention 1) make sure data was initialized( m_data != 0 ).
        ///            2) make sure position is in between the array limits.Otherwise behaviour is undefined.
        /// \param[in]       position  Const position of the element
        /// \return          Constant reference to Array element at given position
        /// \testmethod
        /// \traceability
        const T& operator[](const size_type position) const
        {
            // make sure data was initialized
            assert( m_data != 0 );
            // make sure position is between limits
            assert( (position >= 0) && (position < size()) );
            return m_data[position];
        }

        /// \brief Attaches constant pointer non-constant external data to the internal pointer.
        /// \attention 1) make sure data was initialized( p_data != 0 ).
        ///	           2) make sure that s_size >= SIZE.Otherwise behaviour is undefined.
        /// \param[in] p_data   Pointer to the external non-constant data.
        /// \param[in] s_size   Constant size of the external array.
        /// \testmethod
        /// \traceability
        void attach(T* const p_data, const sint32 s_size)
        {
            (void) s_size;
            assert (p_data != 0    );
            assert (SIZE  <= s_size);
            m_data = p_data;
        }

        /// \brief Returns number of elements in the array.
        /// \details This function calls another function max_size() which returns the size(SIZE) of the array.SIZE is the template parameter.
        /// \return   Number of elements in the Array.
        /// \testmethod
        /// \traceability
        static sint32 size()
        {
            return max_size();
        }

        /// \brief Returns number of elements in the array.
        /// \details Returns number of elements (SIZE) in the array.SIZE is the template parameter.
        /// \return   Number of elements in the Array.
        /// \testmethod
        /// \traceability
        static sint32 max_size()
        {
            return SIZE;
        }

        protected:
          T* m_data; ///< pointer is of type T.T is the template parameter.This pointer is used to hold the address of the memory which is external to this class.attach() function has the implementation to attach external memory to m_data.
    };


    /// \brief Provides pointer to the array which has memory external to the class.
    /// \details Provide Storage for array, specialized for external memory and constant data.For external memory EXT_MEM = true.
    /// \tparam T       The type of the elements.
    /// \tparam SIZE    The size of the array
    /// \testmethod
    /// \traceability
    template<class T, sint32 SIZE>
    class CArrayStorage<const T,SIZE,true>
    {
    public:
        typedef CArrayStorage<const T,SIZE,true> self;  ///< Abbreviation for the type of the class.
        typedef int                              size_type; ///< Abbreviation for the integer type and it is used for storing array size.

        enum { MAX_SIZE = SIZE ///< maximum size of the CArrayStorage memory.
             };

        /// \brief Default constructor for specialization of external memory.
        /// \attention Makes the storage invalid in debug mode.
        /// \testmethod
        /// \traceability
        CArrayStorage()
#ifndef NDEBUG
            : m_data(0)
#endif
        {}
        /// \brief Attaches constant pointer constant external data to the internal pointer.
        /// \details attach() function takes "p_data" and "s_size" as arguments and assigns internal pointer (m_data) with "p_data".
        /// \attention 1) make sure data was initialized( p_data != 0 ).
        ///	           2) make sure that s_size >= SIZE.Otherwise behaviour is undefined.
        /// \param[in] p_data   Constant pointer to the external constant data.
        /// \param[in] s_size   Constant size of the external array.
        /// \testmethod
        /// \traceability
        void attach(const T* const p_data, const sint32 s_size)
        {
            (void) s_size;
            assert (p_data != 0    );
            assert (SIZE  <= s_size);
            m_data = p_data;
        }

        /// \brief constructor with constant pointer constant data. 
        /// \details constructor that attaches external data of type constant pointer
        /// constant data to the internal pointer.This function calls function. attach() which attaches the external array pointer to the internal pointer which is a data member of the class.
        /// \attention Caller should ensure that s_size >= SIZE.Otherwise behaviour is undefined.
        /// \param[in] p_data   Constant pointer to the constant external data buffer.
        /// \param[in] s_size   Constant size of the external data buffer.
        /// \testmethod
        /// \traceability
        CArrayStorage(const T* const p_data, const sint32 s_size)
        {
            attach(p_data, s_size);
        }

        /// \brief Template constructor with non-constant reference.
        /// \details Template constructor that attaches external data of type non-constant reference
        /// non-constant data to the internal pointer.This function calls attach function.attach function attaches the external array pointer to the internal pointer which is a data member of the class.
        /// \attention Caller should ensure that SIZE2 >= SIZE.Otherwise behaviour is undefined.
        /// \tparam SIZE2    The size of the external array.
        /// \param[in]       data  Reference to the external non-constant data buffer of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2 >
        CArrayStorage(       T (&data)[SIZE2] )
        {
            attach(&data[0], SIZE2);
        }

        /// \brief Template constructor with constant reference.
        /// \details Template constructor that attaches external data of type constant reference
        /// non-constant data to the internal pointer.This function calls attach function.attach function attaches the external array pointer to the internal pointer which is a data member of the class.
        /// \attention Caller should ensure that SIZE2 >= SIZE.Otherwise behaviour is undefined.
        /// \tparam SIZE2    The size of the external array.
        /// \param[in]       data  Constant reference to the external non-constant data buffer of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2 >
        CArrayStorage( const T (&data)[SIZE2] )
        {
            attach(&data[0], SIZE2);
        }

        /// \brief Template constructor with non-constant data.
        /// \details Template constructor to attach external identical constant reference non-constant data  
        /// of different size(SIZE2) and possibly different memory specializations(EXT_MEM2) to the internal pointer.This function calls attach function.attach function attaches the external array pointer to the internal pointer which is a data member of the class.
        /// \attention Caller should ensure that SIZE2 >= SIZE.Otherwise behaviour is undefined.
        /// \tparam SIZE2    The size of the external array.
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs   Constant reference to the external non-constant data buffer of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CArrayStorage( const CArrayStorage<T,SIZE2,EXT_MEM2>& rhs )
        {
            attach (&rhs[0], SIZE2);
        }

        /// \brief Template constructor with constant data.
        /// \details Template copy constructor to attach external identical constant reference constant data  
        /// of different size(SIZE2) and possibly different memory specializations(EXT_MEM2) to the internal pointer.This function calls attach function.attach function attaches the external array pointer to the internal pointer which is a data member of the class.
        /// \attention Caller should ensure that SIZE2 >= SIZE.
        /// \tparam SIZE2    The size of the external array.
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs   Constant reference to the external constant data buffer of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CArrayStorage( const CArrayStorage<const T,SIZE2,EXT_MEM2>& rhs )
        {
            attach (&rhs[0], SIZE2);
        }

        /// \brief Index operator overloading function which returns constant reference.
        /// \details Returns the constant reference to the element at given constant position with constant object.
        /// \attention 1) make sure data was initialized( p_data != 0 ).
        ///	           2) make sure that position is within the array limits.
        /// \param[in]       position  Constant position of the element.
        /// \return          Constant reference to Array element at given position.
        /// \testmethod
        /// \traceability
        const T& operator[](const size_type position) const
        {
            assert( m_data != 0 );
            assert( (position >= 0) && (position < size()) );
            return m_data[position];
        }

        /// \brief Returns number of elements in the array.
        /// \details This function calls another function max_size() which returns the size of the array.
        /// \return   Number of elements in the Array.
        /// \testmethod
        /// \traceability
        static sint32 size()
        {
            return max_size();
        }

        /// \brief Returns number of elements in the array.
        /// \details Returns number of elements (SIZE) in the array.
        /// \return   Number of elements in the Array.
        /// \testmethod
        /// \traceability
        static sint32 max_size()
        {
            return SIZE;
        }


        protected:
            const T* m_data;  ///< Pointer for external memory of constant data.
            // forbid shallow copy
            self& operator=(const self&);  ///< Protected function to forbid shallow copy.
    };

    /// \brief Reimplementation of stl::array with fixed amount of memory.
    /// \details This class is derived from CArrayStorage class publicly.It supports Iterators and constant iterators.
    /// \tparam T       The type of the elements
    /// \tparam SIZE    The size of the array
    /// \tparam EXT_MEM Flag whether the memory of the elements of the array is inside
    ///                 of this class (false) or outside of this class (true).
    ///                 Default is false, meaning internal memory.
    /// \traceability
    /// \testmethod
    template < class T, sint32 SIZE, boolean_t EXT_MEM = false >
    class CArray
        : public CArrayStorage<T,SIZE,EXT_MEM>
    {
    public:
        typedef CArray       <T, SIZE, EXT_MEM> self;  ///< Abbreviation for the type of the class.
        typedef CArrayStorage<T, SIZE, EXT_MEM> super;  ///< Base class of this CArray template configuration.
        typedef sint32                          size_type;  ///< Abbreviation for the signed integer type and it is used for storing array size.
        typedef typename remove_const<T>::type  type;  ///< Alias name for the type(non constant) of the CArray elements.
        typedef typename    add_const<T>::type  const_type;  ///< Alias name for the constant type of the CArray elements.
        typedef typename remove_const<T>::type& reference;   ///< Alias name for the reference to the type of the CArray elements.
        typedef typename    add_const<T>::type& const_reference;   ///< Alias name for the constant reference to the type of the CArray elements.
        typedef typename remove_const<T>::type* pointer;   ///< Alias name for the pointer to the type of the CArray elements.
        typedef typename    add_const<T>::type* const_pointer;   ///< Alias name for the constant pointer to the type of the CArray elements.
        // iterator typedefs
#ifndef NDEBUG
        typedef cml::CLinMemIt< type, false, self >  it;  ///< Alias name for the iterator to the CArray elements.
        typedef cml::CLinMemIt< type, true , self > cIt;  ///< Alias name for the constant iterator to the CArray elements.
#else
        typedef cml::CLinMemIt< type, false >  it;  ///< Alias name for the iterator to the CArray elements.
        typedef cml::CLinMemIt< type, true  > cIt;  ///< Alias name for the constant iterator to the CArray elements.
#endif
        typedef it  iterator;   ///< iterator to the CArray elements.
        typedef cIt const_iterator;   ///< constant iterator to the CArray elements.

        // PRQA S 2524 10
        // date: 2015-21-07, reviewer: Markus Friebertshaeuser, reason:
        // QAC Bug, since this using declaration is within the class scope.
        // The according MISRA rule 7-3-6 states: "using-directives and using-declarations
        // (EXCLUDING CLASS SCOPE OR FUNCTION SCOPE USING-DECLARATIONS) shall not be used in header files."
        // parent imports
        /// \brief Base class Index operator overloading function of this CArray.
        /// \details This CArray class will not implement index operator overloading function,instead  uses it's base class implementation.
        /// \testmethod
        /// \traceability
        using super::operator[];

        /// \brief Default empty constructor.
        /// \traceability
        /// \testmethod
        // PRQA S 4054 4
        // date: 2015-22-06, reviewer: Markus Friebertshaeuser, reason:
        //   Our strategy is to have a late init using the reset call.
        //   This is necessary to be able to fulfill the SIL-SIL requirement
        CArray(){}

        /// \brief   constructor with non-constant pointer to constant data.
        /// \details   constructor that copies the given non-constant pointer 
        /// constant external data to the internal memory.These parameters will be passed to the base class constructor in which actual data member initialization happens.
        /// \param[in]       data    Non-constant pointer to the constant external data.
        /// \param[in]       size    Constant size of the external data buffer.
        /// \traceability
        /// \testmethod
        
        CArray(       pointer const data, const sint32 size ) : super(data, size) {}

        /// \brief  constructor with constant pointer to constant data.
        /// \details  constructor that copies the given constant pointer 
        /// constant external data to the internal memory.These parameters will be passed to the base class constructor in which actual data member initialization happens.
        /// \param[in]       data    Constant pointer to the constant external data.
        /// \param[in]       size    Constant size of the external data buffer.
        /// \testmethod
        /// \traceability
        CArray( const_pointer const data, const sint32 size ) : super(data, size) {}

        /// \brief  template constructor with non-constant external data.
        /// \details  template constructor that copies the given non-constant reference 
        /// non-constant external data of possibly different size (SIZE2) to the internal memory.
        /// These parameters will be passed to the base class constructor in which actual data member initialization happens.
        /// \tparam SIZE2    The size of the external data.
        /// \param[in]       data    Non-constant reference to the non-constant external data of SIZE2.
        // PRQA S 2180 17
        // date: 2015-21-07, reviewer: Markus Friebertshaeuser, reason: Implicit call is intended here.
        /// Constructor with pointer to array of possibly different size than this.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2 >
        CArray(       type (&data)[SIZE2] ) : super(data) {}

        /// \brief  template  constructor with constant external data.
        /// \details  template  constructor that copies the given non-constant reference 
        ///  constant external data of possibly different size (SIZE2) to the internal memory. 
        ///  These parameters will be passed to the base class constructor for data member initialization.
        /// \tparam SIZE2    The size of the external data.
        /// \param[in]       data    Non-constant reference to the constant external data of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2 >
        CArray( const_type (&data)[SIZE2] ) : super(data) {}

        /// \brief  template copy constructor with non-constant data.
        /// \details  template copy constructor that copies or attaches constant reference external identical data 
        /// with non-constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the internal data storage.
        /// These parameters will be passed to the base class constructor in which actual data member initialization happens.
        /// \tparam SIZE2    The size of the external data.
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs    Constant reference to the non-constant identical external data of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CArray( const CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs ) : super(rhs) {}

        /// \brief    template copy constructor with constant data.
        /// \details  template copy constructor that copies or attaches constant reference external identical data 
        ///  with constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the internal data storage.
        ///  These parameters will be passed to the base class constructor in which actual data member initialization happens.
        /// \tparam SIZE2    The size of the external data.
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs    Constant reference to the constant identical external data of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CArray( const CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs ) : super(rhs) {}

        /// \brief   template copy constructor with non-constant data.
        /// \details  template copy constructor that copies or attaches non-constant reference external identical data 
        ///  with non-constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the internal data storage.
        ///  These parameters will be passed to the base class constructor in which actual data member initialization happens.
        /// \tparam SIZE2    The size of the external data.
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs    Non-constant reference to the non-constant identical external data of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CArray( CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs ) : super(rhs) {}

        /// \brief    template copy constructor with constant data.
        /// \details  template copy constructor that copies or attaches non-constant reference external identical data 
        ///  with constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the internal data storage.
        ///  These parameters will be passed to the base class constructor in which actual data member initialization happens.
        /// \tparam SIZE2    The size of the external data.
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs    Non-constant reference to the constant identical external data of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CArray( CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs ) : super(rhs) {}

        /// \brief  assignment operator overloading function with identical non-constant data.
        /// \details Copy external identical constant reference non-constant data of identical size 
        /// to the internal storage.This function calls base class assignment operator overloading function with object "rhs" as an argument.
        /// Returns the reference to the calling object.
        /// This is not automatically generated by templated version 
        // according to Misra rule 14-5-3.
        /// \param[in]       rhs    Constant reference to the external data buffer of identical size.
        /// \return          Reference to this pointer.
        /// \testmethod
        /// \traceability
        self& operator=(const self& rhs)
        {
            super::operator=(rhs);
            return *this;
        }
        /// \brief  template assignment operator overloading function with non-constant data.
        /// \details copy external identical constant reference non-constant data of identical size(SIZE)  
        /// and memory specializations(EXT_MEM2) to the internal storage.This function calls base class assignment operator overloading function with object "rhs" as an argument.
        /// Returns the reference to the calling object.
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs    Constant reference to the external non-constant data of identical size.
        /// \return          Reference to this pointer.
        /// \testmethod
        /// \traceability
        template< boolean_t EXT_MEM2 >
        self& operator=(const CArray<type,SIZE,EXT_MEM2>& rhs)
        {
            super::operator=(rhs);
            return *this;
        }

        /// \brief  template assignment operator overloading function with constant data.
        /// \details Copy external identical constant reference constant data of identical size(SIZE)  
        /// and memory specializations(EXT_MEM2) to the internal storage.This function calls base class assignment operator overloading function and object rhs will be passed to it.
        /// Returns the reference to the calling object.
        /// \tparam EXT_MEM2 Flag whether the memory of the elements of the array is inside
        ///                  of this class (false) or outside of this class (true).
        ///                  Default is false, meaning internal memory.
        /// \param[in]       rhs    Constant reference to the external constant data of identical size.
        /// \return          Reference to this pointer.
        /// \testmethod
        /// \traceability
        template< boolean_t EXT_MEM2 >
        self& operator=(const CArray<const_type,SIZE,EXT_MEM2>& rhs)
        {
            super::operator=(rhs);
            return *this;
        }

        /// \brief Returns reference to the element at given constant position.
        /// \details This function returns the reference to the element at given constant position by calling index operator overloading function with constant position as an argument.
        /// \param[in]       position    Constant position of the element.
        /// \return          Reference to the element at given constant position.
        /// \testmethod
        /// \traceability
        reference at(const size_type position)
        {
            return operator[](position);
        }

        /// \brief Returns constant reference to the element at given constant position.
        /// \details This function returns the constant reference to the element at given constant position by calling index operator overloading function with constant position as an argument.
        /// This function will be called by both constant and non-constant objects.
        /// \param[in]       position    Constant position of the element.
        /// \return          Constant reference to the element at given constant position.
        /// \testmethod
        /// \traceability
        const_reference at(const size_type position) const
        {
            return operator[](position);
        }

        /// \brief Returns reference to the first element of internal storage.
        /// \details This function returns the reference to the element at first position by calling index operator overloading function with 0 as an argument.
        /// \return          Reference to the element at first position.
        /// \testmethod
        /// \traceability
        reference front()
        {
            return operator[](0);
        }

        /// \brief Returns constant reference to the first element of internal storage.
        /// \details This function returns the constant reference to the element at first position by calling index operator overloading function with 0 as an argument.
        /// This function will be called by both constant and non-constant objects.
        /// \return          Constant reference to the element at first position.
        /// \testmethod
        /// \traceability
        const_reference front() const
        {
            return operator[](0);
        }

        /// \brief returns reference to the last element of the internal storage.
        /// \details This function returns the reference to the last element by calling index operator overloading function with "SIZE-1" as an argument.
        /// \return    Reference of the element at last position.
        /// \testmethod
        /// \traceability
        reference back()
        {
            return operator[](SIZE-1);
        }

        /// \brief Returns constant reference to the last element of the internal storage.
        /// \details This function returns constant reference to the last element by calling index operator overloading function with "SIZE-1" as an argument.
        /// This function will be called by both constant and non-constant objects.
        /// \return          Constant reference of element at last position.
        /// \testmethod
        /// \traceability
        const_reference back() const
        {
            return operator[](SIZE-1);
        }

        /// \brief Fills the whole array with input value.
        /// \details This function fills the whole array with input value by calling index operator overloading function inside a for loop of count SIZE.
        /// \param[in]       val   Constant reference to the input value.
        /// \return          void
        /// \testmethod
        /// \traceability
        void fill(const_reference val)
        {
            for (sint32 i=0; i<SIZE; i++)
            {
                operator[](i) = val;
            }
        }

        /// \brief Returns an iterator to the beginning of the CArray.
        /// \details Returns an iterator to the beginning of the CArray.
        /// \return          Returns an iterator to the beginning of the CArray.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        it  begin()        { return it (&m_data[0], this); }
#else
        it  begin()        { return it (&m_data[0]); }
#endif

        /// \brief Returns a constant iterator to the beginning of the CArray.
        /// \details Returns a constant iterator to the beginning of the CArray.
        /// This function will be called by both constant and non-constant objects.
        /// \return          Returns a constant iterator to the beginning of the CArray.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        cIt begin()  const { return cIt(&m_data[0], this); }
#else
        cIt begin()  const { return cIt(&m_data[0]); }
#endif

        /// \brief Returns a constant iterator to the beginning of the constant CArray.
        /// \details Returns a constant iterator to the beginning of the constant CArray.
        /// This function will be called by both constant and non-constant objects.
        /// \return          Returns a constant iterator to the beginning of the constant CArray.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        cIt cbegin() const { return cIt(&m_data[0], this); }
#else
        cIt cbegin() const { return cIt(&m_data[0]); }
#endif

        /// \brief Returns an iterator to the position after the end of the CArray.
        /// \details Returns an iterator to the position after the end of the CArray.
        /// \return          Returns an iterator to the position after the end of the CArray.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        it  end()        { return it (&m_data[SIZE], this); }
#else
        it  end()        { return it (&m_data[SIZE]); }
#endif

        /// \brief Returns a constant iterator to the position after the end of the CArray.
        /// \details Returns a constant iterator to the position after the end of the CArray.
        /// \return          Returns a constant iterator to the position after the end of the CArray.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        cIt end()  const { return cIt(&m_data[SIZE], this); }
#else
        cIt end()  const { return cIt(&m_data[SIZE]); }
#endif

        /// \brief Returns a constant iterator to the position after the end of the CArray.
        /// \details Returns a constant iterator to the position after the end of the CArray.
        /// \return          Returns a constant iterator to the position after the end of the CArray.
        /// \testmethod
        /// \traceability
#ifndef NDEBUG
        cIt cend() const { return cIt(&m_data[SIZE], this); }
#else
        cIt cend() const { return cIt(&m_data[SIZE]); }
#endif

            // This is only required for TI-Compiler to be able to compile
        protected:
            // PRQA S 2524 5
            // date: 2015-21-07, reviewer: Markus Friebertshaeuser, reason:
            // QAC Bug, since this using declaration is within the class scope.
            // The according MISRA rule 7-3-6 states: "using-directives and using-declarations
            // (EXCLUDING CLASS SCOPE OR FUNCTION SCOPE USING-DECLARATIONS) shall not be used in header files."
            using super::m_data; ///< Protected data element of the base class CArrayStorage which provides storage for the CArray elements.
            // End of section required for TI-Compiler
    };
}

#endif //CML_STL_ARRAY_H__
