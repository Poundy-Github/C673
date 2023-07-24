/*! \file **********************************************************************

COMPANY:                   Continental AG, A.D.C. GmbH

CPU:                       CPU-Independent

COMPONENT:                 CML (Common Math Library)

MODULNAME:                 cml_stl_vector.h

DESCRIPTION:               Vector Computations Library

AUTHOR:                    Robert Thiel / Markus Friebertshaeuser

CREATION DATE:             15.11.2012

VERSION:                   $Revision: 1.39 $

**************************************************************************** */

#ifndef CML_STL_VECTOR_H__
#define CML_STL_VECTOR_H__

#include "cml_stl_array.h"

namespace cml
{

    /// \brief Re-implementation of the standard C++ library template vector.
    /// \details Stores a list of "things" and gives the possibility to insert, append, clear.
    /// This class is derived from one dimentional array class with default EXT_MEM = false.
    /// This class supports iterators and constant iterators.
    /// It differs from the array in following ways:\n
    /// 1) allowing the elements to be inserted inbetween the array elements with insert() function.\n
    /// 2) allows CVector size to be resized by using resize() function.\n
    /// \tparam T       The type of the elements
    /// \tparam SIZE    The size of the array    
    /// \tparam EXT_MEM Flag whether the memory of the elements of the array is inside
    ///                 of this class (false) or outside of this class (true).
    ///                 Default is false, meaning internal memory.
    /// \testmethod
    /// \traceability
    template <class T, sint32 SIZE, boolean_t EXT_MEM = false >
    class CVector
        : public CArray<T, SIZE, EXT_MEM>
    {
    public:
        typedef CVector<T, SIZE, EXT_MEM>       self;   ///< Alias name for the Vector.
        typedef CArray <T, SIZE, EXT_MEM>       super;  ///< Alias name for the base class of the Vector.
        typedef sint32                          size_type; ///< Abbreviation for the signed integer type and it is used for storing array size.
        typedef typename remove_const<T>::type  type;   ///< Alias name for the type(non constant) of the CVector elements.
        typedef typename    add_const<T>::type  const_type;  ///< Alias name for the constant type of the CVector elements.
        typedef typename remove_const<T>::type& reference;  ///< Alias name for the reference to the type of the CVector elements.
        typedef typename    add_const<T>::type& const_reference;  ///< Alias name for the constant reference to the type of the CVector elements.
        typedef typename remove_const<T>::type* pointer;   ///< Alias name for the pointer to the type of the CVector elements.
        typedef typename    add_const<T>::type* const_pointer;  ///< Alias name for the constant pointer to the type of the CVector elements.
        typedef int                             difference_type;  ///< Abbreviation for the integer type and it is used for storing the difference of two pointers.
        // iterator typedefs
#ifndef NDEBUG
        typedef cml::CLinMemIt< type, false, self >  it;  ///< Alias name for the iterator to the CVector elements.
        typedef cml::CLinMemIt< type, true , self > cIt;  ///< Alias name for the constant iterator to the CVector elements.
#else
        typedef cml::CLinMemIt< type, false >  it;  ///< Alias name for the iterator to the CVector elements.
        typedef cml::CLinMemIt< type, true  > cIt;  ///< Alias name for the constant iterator to the CVector elements.
#endif
        typedef it  iterator;   ///< iterator to the CVector elements.
        typedef cIt const_iterator;   ///< constant iterator to the CVector elements.


        /// \brief Default empty constructor.
        /// \details Default empty constructor initializes vector size "m_size" to zero."m_size" is the protected data member of the CVector class.
        /// \testmethod
        /// \traceability
        CVector() : super(), m_size(0) {}

        /// \brief Constructor with reference to a non-constant external data and size. 
        /// \details template constructor that copies the given non-constant reference 
        /// non-constant external data of possibly different size (SIZE2).
        /// These reference will be passed to the base class constructor in which actual data member initialization happens.
        /// "m_size" which is the protected data member of CVector class,is initialized to zero.
        /// \tparam          SIZE2   The size of the array 
        /// \param[in]       data    Reference to the external data of SIZE2
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2 >
        explicit CVector(       type (&data)[SIZE2] ) : super(data), m_size(0) {}

        /// \brief Constructor with reference to constant external data.
        /// \details template constructor that copies the given constant reference 
        /// non-constant external data of possibly different size (SIZE2).
        /// These reference will be passed to the base class constructor as an argument, in which actual data member initialization happens.
        /// "m_size" which is the protected data member of CVector class,is initialized to zero.
        /// \tparam          SIZE2   The size of the array
        /// \param[in]       data    Reference to constant external data of SIZE2 
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2 >
        explicit CVector( const_type (&data)[SIZE2] ) : super(data), m_size(0) {}

        /// \brief constructor with reference to non-constant external data of possibly different size than this.
        /// \details template constructor that copies the given non-constant reference to
        /// non-constant external data of possibly different size (SIZE2).
        /// These reference will be passed to the base class constructor as an argument, in which actual data member initialization happens.
        /// "m_size" which is the protected data member of CVector class,is initialized to s_size which is passed as an argument along with the non-constant reference.
        /// \tparam          SIZE2     The size of the external data.
        /// \param[in]       p_data    Reference to the non-constant external data of SIZE2.
        /// \param[in]       s_size    Constant external data size.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2 >
        explicit CVector(       type (&p_data)[SIZE2], const size_type s_size ) : super(p_data), m_size(s_size) {}

        /// \brief constructor with reference to constant external data of possibly different size than this.
        /// \details template constructor that copies the given non-constant reference to
        /// constant external data of possibly different size (SIZE2).
        /// These reference will be passed to the base class constructor as an argument, in which actual data member initialization happens.
        /// "m_size" which is the protected data member of CVector class,is initialized to s_size which is passed as an argument along with the non-constant reference.
        /// \tparam          SIZE2     The size of the external data.
        /// \param[in]       p_data    Reference to constant external data of SIZE2.
        /// \param[in]       s_size    Constant size
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2 >
        explicit CVector( const_type (&p_data)[SIZE2], const size_type s_size ) : super(p_data), m_size(s_size) {}

        /// \brief constructor with constant reference to non-constant external data of possibly 
        /// different size and memory setting than this.
        /// \details Constructor takes constant reference to the external object "rhs" of CArrayStorage class type with non-constant data of possibly 
        /// different size(SIZE2) and memory settings(EXT_MEM2) than this.This "rhs" will be passed to the base class constructor in which actual data member initialization happens.
        ///  "m_size" which is the protected data member of CVector class,is initialized to zero.
        /// \tparam          SIZE2     The size of the external data.   
        /// \tparam          EXT_MEM2  Flag whether the memory of the elements of the array is inside
        ///                            of this class (false) or outside of this class (true).
        ///                            Default is false, meaning internal memory.
        /// \param[in]       rhs       Constant reference to non-constant external data of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CVector( const CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs ) : super(rhs), m_size(0) {}

        /// \brief constructor with constant reference to constant external data of possibly 
        /// different size and memory setting than this.
        /// \details Constructor takes constant reference to the external object "rhs" of CArrayStorage class type with constant data of possibly 
        /// different size(SIZE2) and memory setting(EXT_MEM2) than this.This "rhs" will be passed to the base class constructor in which actual data member initialization happens.
        ///  "m_size" which is the protected data member of CVector class,is initialized to zero.
        /// \tparam          SIZE2     The size of the external data.    
        /// \tparam          EXT_MEM2  Flag whether the memory of the elements of the array is inside
        ///                            of this class (false) or outside of this class (true).
        ///                            Default is false, meaning internal memory.
        /// \param[in]       rhs       Constant reference to constant external data of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CVector( const CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs ) : super(rhs), m_size(0) {}

        /// \brief constructor with non-constant reference to non-constant external data of possibly 
        /// different size and memory setting than this.
        /// \details Constructor takes non-constant reference to the external object "rhs" of CArrayStorage class type with non-constant data of possibly 
        /// different size(SIZE2) and memory setting(EXT_MEM2) than this.This "rhs" will be passed to the base class constructor in which actual data member initialization happens.
        ///  "m_size" which is the protected data member of CVector class,is initialized to zero.
        /// \tparam          SIZE2     The size of the external data.
        /// \tparam          EXT_MEM2  Flag whether the memory of the elements of the array is inside
        ///                            of this class (false) or outside of this class (true).
        ///                            Default is false, meaning internal memory.
        /// \param[in]       rhs       Non-constant reference to non-constant external data of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CVector( CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs ) : super(rhs), m_size(0) {}

        /// \brief constructor with non-constant reference to constant external data of possibly 
        /// different size and memory setting than this.
        /// \details Constructor takes non-constant reference to the external object "rhs" of CArrayStorage class type with constant data of possibly 
        /// different size(SIZE2) and memory setting(EXT_MEM2) than this.This "rhs" will be passed to the base class constructor in which actual data member initialization happens.
        ///  "m_size" which is the protected data member of CVector class,is initialized to zero.
        /// \tparam          SIZE2     The size of the external data.  
        /// \tparam          EXT_MEM2  Flag whether the memory of the elements of the array is inside
        ///                            of this class (false) or outside of this class (true).
        ///                            Default is false, meaning internal memory.
        /// \param[in]       rhs       Non-constant reference to constant external data of SIZE2.
        /// \testmethod
        /// \traceability
        template< sint32 SIZE2, boolean_t EXT_MEM2 >
        explicit CVector( CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs ) : super(rhs), m_size(0) {}

        /// \brief assignment operator overloaded function.
        /// \details Copy external identical constant reference non-constant data of identical size 
        /// to the internal storage.This function calls base class assignment operator overloading function with object "rhs" as an argument.\n
        /// Assigns "m_size" which is the protected data member of CVector class with the size of "rhs".\n
        /// This function returns the reference to the calling object.\n
        /// This is not automatically generated by templated version 
        /// according to Misra rule 14-5-3.
        /// \param[in]       rhs    Constant reference to external data of identical size.
        /// \return          Reference to this pointer.
        /// \testmethod
        /// \traceability
        self& operator=(const self& rhs)
        {
            super::operator=(rhs);
            m_size = rhs.size();
            return *this;
        }

        /// \brief assignment operator overloaded template function with non-constant data.
        /// \details Makes a copy of constant reference non-constant external data of possibly 
        /// different memory settings to internal storage.
        /// \details Constructor takes constant reference to the external object "rhs" of CVector class type with non-constant data of possibly 
        /// different memory setting(EXT_MEM2) than this.This "rhs" will be passed as an argument to the base class assignment operator overloading function.
        /// "m_size" which is the protected data member of CVector class  will be assigned with the size of "rhs".\n
        /// This function returns the reference to the calling object.\n
        /// \tparam          EXT_MEM2  Flag whether the memory of the elements of the vector is inside
        ///                            of this class (false) or outside of this class (true).
        ///                            Default is false, meaning internal memory.
        /// \param[in]       rhs       Reference to non-constant external data of identical size.
        /// \return          Reference to this pointer.
        /// \testmethod
        /// \traceability
        template< boolean_t EXT_MEM2 >
        self& operator=(const CVector<      type, SIZE, EXT_MEM2>& rhs)
        {
            super::operator=(rhs);
            m_size = rhs.size();
            return *this;
        }

        /// \brief assignment operator overloaded template function with constant data.
        /// \details Constructor takes constant reference to the external object "rhs" of CVector class type with constant data of possibly 
        /// different memory setting(EXT_MEM2) than this.This "rhs" will be passed as an argument to the base class assignment operator overloading function.
        /// "m_size" which is the protected data member of CVector class  will be assigned with the size of "rhs".\n
        /// This function returns the reference to the calling object.\n
        /// \tparam          EXT_MEM2  Flag whether the memory of the elements of the vector is inside
        ///                            of this class (false) or outside of this class (true).
        ///                            Default is false, meaning internal memory.
        /// \param[in]       rhs       Reference to constant external data of identical size.
        /// \return          Reference to this pointer.
        /// \testmethod
        /// \traceability
        template< boolean_t EXT_MEM2 >
        self& operator=(const CVector<const_type, SIZE, EXT_MEM2>& rhs)
        {
            super::operator=(rhs);
            m_size = rhs.size();
            return *this;
        }

        /// \brief Clear the vector.
        /// \details Clear the vector by setting "m_size" to zero but memory will not be cleared.
        /// \return          void 
        /// \testmethod
        /// \traceability
        void clear()
        {
            m_size = 0;
        }

        // This is only required for TI-Compiler to be able to compile
        // PRQA S 2524 5
        // date: 2015-21-07, reviewer: Markus Friebertshaeuser, reason:
        // QAC Bug, since this using declaration is within the class scope.
        // The according MISRA rule 7-3-6 states: "using-directives and using-declarations
        // (EXCLUDING CLASS SCOPE OR FUNCTION SCOPE USING-DECLARATIONS) shall not be used in header files."
        using super::max_size;
        // End of section required for TI-Compiler

        /// \brief Return number of elements in the vector.
        /// \details Return number of elements in the array(m_size) with constant object type.
        /// In this member function, no member data is modified.
        /// \return          Number of elements in the Array
        /// \testmethod
        /// \traceability
        size_type size() const
        {
            return m_size;
        }

        /// \brief Check whether the vector list is empty or not with constant object type.
        /// \details If m_size is 0,this function returns true or it will return false.
        /// In this member function, no member data is modified.
        /// \return          Return 1 if vector list is empty, 0 if not 
        /// \testmethod
        /// \traceability
        boolean_t empty() const
        {
            return (m_size == 0);
        }

        /// \brief Check whether the vector list is full or not with constant object type.
        /// \details If m_size is greaterthan or equal to SIZE,this function returns true or it will return false.
        /// In this member function, no member data is modified.
        /// \return          Return 1 if vector list is full, 0 if not 
        /// \testmethod
        /// \traceability
        boolean_t full() const
        {
            return (m_size >= SIZE);
        }

        /// \brief Returns the reference current last element of the vector.
        /// \details This function calls index operator overloading function with the argument m_size-1 which returns the reference to the current last element of the vector.
        /// \return          Reference to current last element of the vector 
        /// \testmethod
        /// \traceability
        reference back()
        {
            return operator[](size()-1);
        }

        /// \brief Returns the constant reference to the current last element of the vector.
        /// \details This function calls index operator overloading function with the argument m_size-1 which returns the constant reference to the current last element of the vector.
        /// \return          Constant reference to current last element of the vector 
        /// \testmethod
        /// \traceability
        const_reference back() const
        {
            return operator[](size()-1);
        }
        /// \brief Resizes the vector to new size.
        /// \details Resizes the vector to new size and fills the remaining elements with constant value.
        /// This function takes constant reference to new size (sz) and Constant reference to value (c) to be filled as arguments.
        /// If m_size is less than the new size(sz) then it fills the new locations (sz-m_size) with the value (c) using fill() function."m_size" is the size of the vector and sz is the new size.
        /// Then m_size is updated with new size(sz).
        /// \attention size should be less than or equal to SIZE.Otherwise behaviour is undefined.
        /// \param[in]       sz    Constant reference to new constant size of the vector.
        /// \param[in]       c     Constant reference to value to be filled.
        /// \return          None
        /// \testmethod
        /// \traceability
        void resize( const size_type& sz, const_reference c = type() )
        {
            assert(sz <= SIZE);
            if (m_size < sz)
            {
                std::fill(&m_data[m_size], &m_data[sz], c);
            }
            m_size = sz;
        }

        /// \brief Resizes the vector to new size without initialization.
        /// \details Resizes the vector to new size by assigning new size(sz) to existing size m_size without initialization.
        /// \attention size should be less than or equal to SIZE.Otherwise behaviour is undefined.
        /// \param[in]       sz    Constant reference to new size of the vector.
        /// \return          None  
        /// \testmethod
        /// \traceability
        void resize_uninitialized ( const size_type& sz )
        {
            assert(sz <= SIZE);
            m_size = sz;
        }

        /// \brief Assign value given number of times in a new, cleared vector.        
        /// \details Function fill() will be called and filled "n" locations with the value "u" and vector size m_size will be updated with "n".
        /// Any previously containing data is lost.
        /// \attention size should be less than or equal to SIZE.Otherwise behaviour is undefined.
        /// \param[in]       n     Number of times the value to be filled.
        /// \param[in]       u     Constant reference to the value to be filled.
        /// \return          None 
        /// \testmethod
        /// \traceability
        void assign(const size_type n, const_reference u)
        {
            assert(n <= SIZE);
            if(n>0)
            std::fill(&operator[](0), &operator[](n-1)+1, u);
            m_size = n;
        }

        /// \brief Append input element at the end of vector.
        /// \details This function increaments the vector size and calls index operator overloading function which returns reference.
        /// Returned reference will be assigned with "x" which is a constant reference to the value to be filled.\n
        /// This function returns void.
        /// \attention size should be less than SIZE.Otherwise behaviour is undefined.
        /// \param[in]       x     Constant reference to value to be filled.
        /// \return          None  
        /// \testmethod
        /// \traceability
        void push_back(const_reference x)
        {
            assert (size() < SIZE);
            ++m_size;
            operator[](m_size - 1) = x;
        }

        /// \brief Enlarge the vector by one and give back the new element.
        /// \details This function increaments the vector size and calls index operator overloading function with argument (m_size-1).
        /// This function returns the reference to the new element after push back.
        /// \attention size should be less than SIZE.Otherwise behaviour is undefined.
        /// \return          Reference to new element after push back.
        /// \testmethod
        /// \traceability
        reference push_back()
        {
            assert (size() < SIZE);
            ++m_size;
            return operator[](m_size - 1);
        }
        /// \brief Delete the last element in vector.
        /// \details Delete the last element in vector by decrementing the vector size (m_size).But memory will not be cleared.
        /// \attention vector size should be greater than zero.Otherwise behaviour is undefined.
        /// \return          void 
        /// \testmethod
        /// \traceability
        void pop_back()
        {
            assert (size() > 0);
            --m_size;
        }
        /// \brief Delete the last given number of elements in vector.
        /// \details Delete the last given number of elements in vector by decrementing the vector size (m_size).But memory will not be cleared.
        /// \attention vector size should be greater than or equal to n.Otherwise behaviour is undefined.
        /// \param[in]       n    Number of elements to be deleted.
        /// \return          None  
        /// \testmethod
        /// \traceability
        void pop_back(size_type n)
        {
            assert (size() >= n);
            m_size -= n;
        }
        /// \brief Insert an element at given position.
        /// \details Insert an element at given position, by pushing the next elements to the higher position.
        /// It returns the iterator to the inserted element.Memory is not cleared.
        /// \attention new size should be less than max_size(SIZE) and position should be within vector boundary.Otherwise behaviour is undefined.
        /// \param[in]       position    Constant iterator reference to position of the element.
        /// \param[in]       p           Constant reference to value to be inserted.
        /// \return          Iterator to the position of inserted element 
        /// \testmethod
        /// \traceability
        it insert(const cIt& position, const_reference p)
        {
            //check if array has enough space
            assert ( ( size()    <  max_size() )
                &&     ( position  >= begin()    )
                &&     ( position  <= end()      ) );

            // increment size of the list
            // invalidates all iterators!
            ++m_size;

            // move all following elements 1 position to the right
            it i = end().operator-(1);
            for(; i.operator>(position); --i)
            {
                *i = i[-1];
            }
            // write value to new position
            *i = p;

            return i;
        }

        /// \brief Insert elements from iterator first to last.
        /// \details Elements starting at iterator "position" will be inserted from iterator first to last, by pushing the next 
        /// elements to the higher position.and the vector size (m_size) will be incremented by (last - first).
        /// \attention new size should be less than max_size and position should be within vector boundary.Otherwise behaviour is undefined.
        /// \tparam          InputIterator  Iterator to the input vector.
        /// \param[in]       position       Iterator to the start position of the elements to be inserted.
        /// \param[in]       first          Iterartor to the first element to be inserted.
        /// \param[in]       last           Iterartor to the last element to be inserted.
        /// \return          None 
        /// \testmethod
        /// \traceability
        template <class InputIterator>
        void insert (it position, InputIterator first, InputIterator last)
        {
            const difference_type numInsertElements = last - first;

            //check if array has enough space
            assert ( ( size() + numInsertElements <= max_size() )
                &&     ( position  >= begin()    )
                &&     ( position  <= end()      ) );

            // increment size of the list
            // invalidates all iterators!
            m_size += numInsertElements;

            // move all following elements numInsertElements positions to the right
            it i = end().operator-(1);
            for(; i.operator>(position.operator+(numInsertElements-1)); --i)
            {
                *i = i[-numInsertElements];
            }
            // write values to new position
            for (sint32 k=0; k<numInsertElements; k++)
            {
                position[k] = *first;
                ++first;
            }
        }
        /// \brief Delete element from the position of the vector.
        /// \details Deletes element at given position of the vector and move back the next 
        /// elements to the previous position.vector size (m_size) will be decremented by 1.\n
        /// This function returns iterator to the position of the deleted element. 
        /// \attention size should be greater than zero and position should be within the vector boundary.Otherwise behaviour is undefined.
        /// \param[in]       position    Constant iterator reference to position of the element to be deleted.
        /// \return          Iterator to the position of the deleted element. 
        /// \testmethod
        /// \traceability
        it erase(const cIt& position)
        {
            //check if array has enough space
            assert ( ( size()    >  0       )
                &&     ( position  >= begin() )
                &&     ( position  <  end()   ) );

            // move all following elements 1 position to the right
            difference_type idxStart = position - begin();
            difference_type idxEnd   = static_cast<difference_type>(m_size) - 1;
            for(difference_type i = idxStart; i < idxEnd; ++i)
            {
                operator[](i) = operator[](i+1);
            }

            // decrement size of the list
            // invalidates all iterators!
            --m_size;

            return begin() + idxStart;
        }

#ifndef NDEBUG
        /// \brief Returns the element at given position.
        /// \attention  position should be inside of the vector.
        /// \param[in]       position    Constant position of the element 
        /// \return          Reference to the vector element at given position 
        /// \testmethod
        /// \traceability
        reference operator[](const size_type position)
        {
            //make sure position is between limits - otherwise return zero's element
            assert(position >= 0 && position < size());
            return m_data[position];
        }

        /// \brief Returns a constant reference to the element at given position.
        /// \attention  position should be inside of the vector.
        /// \param[in]       position    Constant position of the element 
        /// \return          Constant reference to the vector element at given position
        /// \testmethod
        /// \traceability
        const_reference operator[](const size_type position) const
        {
            assert(position >= 0 && position < size());
            return m_data[position];
        }

        /// \brief Returns a reference of the element at position.
        /// \param[in]       position    Constant position of the element 
        /// \return          Reference to the vector element at given position 
        /// \testmethod
        /// \traceability
        reference       at(const size_type position)       { return operator[](position); }

        /// \brief Returns a constant reference of the element at given position.
        /// \param[in]       position    Constant position of the element 
        /// \return          Constant reference to the vector element at given position 
        /// \testmethod
        /// \traceability
        const_reference at(const size_type position) const { return operator[](position); }

        /// \brief Returns a reference of the first element.
        /// \return          Reference to the vector element at first position 
        /// \testmethod
        /// \traceability
        reference       front()       { return operator[](0); }

        /// \brief Constant member function which returns a constant reference 
        /// of the first element.
        /// \return          Constant reference of vector element at first position 
        /// \testmethod
        /// \traceability
        const_reference front() const { return operator[](0); }

        /// \brief Returns an iterator to the begin of the vector.
        /// \details Returns an iterator to the begin of the vector and In debug case, it is ensured via assert that the array 
        /// bounds are never exceeded
        /// \return          An iterator to the begin of the vector
        /// \testmethod
        /// \traceability
        it  begin()        { return it (&m_data[0], this); }

        /// \brief Constant member function which returns a constant iterator to the 
        /// begin of the vector.
        /// \return          A constant iterator to the begin of the vector
        /// \testmethod
        /// \traceability
        cIt begin()  const { return cIt(&m_data[0], this); }

        /// \brief Constant member function which returns a constant iterator 
        /// to the begin of the vector.
        /// \return          A constant iterator to the begin of the vector
        /// \testmethod
        /// \traceability
        cIt cbegin() const { return cIt(&m_data[0], this); }

        /// \brief Returns an iterator to the position after the end of the vector.
        /// \return          An iterator to the position after the end of the vector.
        /// \testmethod
        /// \traceability
        it  end()        { return it (&m_data[size()], this); }

        /// \brief Constant member function which returns a constant iterator 
        /// to the position after the end of the vector.
        /// \return          A constant iterator to the position after the end of the vector.
        /// \testmethod
        /// \traceability
        cIt end()  const { return cIt(&m_data[size()], this); }

        /// \brief Constant member function which returns a constant iterator 
        /// to the position after the end of the vector.
        /// \return          A constant iterator to the position after the end of the vector.
        /// \testmethod
        /// \traceability
        cIt cend() const { return cIt(&m_data[size()], this); }


#else //#ifndef NDEBUG
        // import functionality
        // PRQA S 2524 10
        // date: 2015-21-07, reviewer: Markus Friebertshaeuser, reason:
        // QAC Bug, since this using declaration is within the class scope.
        // The according MISRA rule 7-3-6 states: "using-directives and using-declarations
        // (EXCLUDING CLASS SCOPE OR FUNCTION SCOPE USING-DECLARATIONS) shall not be used in header files."
        using super::operator[];  ///< Base class index operator overloading function.
        using super::at;  ///< Base class at() function.
        using super::front;   ///< Base class front() function.

        using super::begin;  ///< Base class begin() function.
        using super::cbegin; ///< Base class cbegin() function.

        /// \brief Returns an iterator to the position after the end of the vector.
        /// \param[in]       None
        /// \return          An iterator to the position after the end of the vector.
        /// \testmethod
        /// \traceability
        it  end()        { return it (&m_data[size()]); }

        /// \brief Returns a constant iterator to the position after the end of the 
        /// vector with constant object type.              
        /// \param[in]       None
        /// \return          A constant iterator to the position after the end of the vector.
        /// \testmethod
        /// \traceability
        cIt end()  const { return cIt(&m_data[size()]); }

        /// \brief Returns a constant iterator to the position after the end of the 
        /// constant vector with constant object type.                               
        /// \param[in]       None
        /// \return          A constant iterator to the position after the end of the vector.
        /// \testmethod
        /// \traceability
        cIt cend() const { return cIt(&m_data[size()]); }
#endif //#ifndef NDEBUG

    protected:
        size_type m_size;  ///< size of the vector which can grow or shrink dynamically.
        // This is only required for TI-Compiler to be able to compile
        // PRQA S 2524 5
        // date: 2015-21-07, reviewer: Markus Friebertshaeuser, reason:
        // QAC Bug, since this using declaration is within the class scope.
        // The according MISRA rule 7-3-6 states: "using-directives and using-declarations
        // (EXCLUDING CLASS SCOPE OR FUNCTIN SCOPE USING-DECLARATIONS) shall not be used in header files."
        using super::m_data;  ///< protected data element of the CVector base class.
        // End of section required for TI-Compiler

    private:
        //Prevent from being used
        void fill(const_reference val);
    };
}

#endif //CML_STL_VECTOR_H__

