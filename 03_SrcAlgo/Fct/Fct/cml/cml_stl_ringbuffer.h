/*! \file **********************************************************************

COMPANY:                   Continental AG, A.D.C. GmbH

CPU:                       CPU-Independent

COMPONENT:                 CML (Common Math Library)

MODULNAME:                 cml_stl_ringbuffer.h

DESCRIPTION:               Ringbuffer Library

AUTHOR:                    Purushotham Reddy / Lars Ulveland

CREATION DATE:             12.04.2017

VERSION:                   $Revision: 1.6 $

**************************************************************************** */
#ifndef CML_STL_RINGBUFF_H__
#define CML_STL_RINGBUFF_H__

#include "cml_stl_circulariterators.h"
#include "cml_stl_array.h"
#include "glob_type.h"
#include <algorithm>
#include <cstring>

namespace cml
{
    /// \brief Class implementing a ring buffer of SIZE elements with dynamic array usage.
    /// \details The ring buffer is increasing dynamically its size until the size reaches SIZE.
    /// Afterwards it overwrites the oldest element in the buffer.
    /// \tparam T       The type of the elements
    /// \tparam SIZE    The size of the underlying array
    /// \tparam EXT_MEM Flag whether the memory of the elements of the array is inside
    ///                 of this class (false) or outside of this class (true).
    ///                 Default is false, meaning internal memory.
	/// \testmethod
	/// \traceability
    template < class T, sint32 SIZE, bool EXT_MEM = false >
    class CRingBuffer : public cml::CArrayStorage<T, SIZE, EXT_MEM>
    {
    public:
        typedef CRingBuffer<T, SIZE, EXT_MEM>        self;  ///< Alias name for the CRingBuffer class.
        typedef cml::CArrayStorage<T, SIZE, EXT_MEM> super; ///< Base class of this CRingBuffer template.
        typedef sint32                               size_type; ///< Abbreviation for the signed integer type and it is used for storing CRingBuffer size.
        typedef typename cml::remove_const<T>::type  type; ///< Alias name for the type(non constant) of the CRingBuffer elements.
        typedef typename    cml::add_const<T>::type  const_type;  ///< Alias name for the constant type of the CRingBuffer elements.
        typedef typename cml::remove_const<T>::type& reference;   ///< Alias name for the reference to the type of the CRingBuffer elements.
        typedef typename    cml::add_const<T>::type& const_reference;   ///< Alias name for the constant reference to the type of the CRingBuffer elements.

        template<class,boolean_t,class>
        friend class CCirMemIt;

        typedef cml::CCirMemIt< type, false, self >  it;  ///< Alias name for the circular iterator to the CRingBuffer elements.
        typedef cml::CCirMemIt< type, true, self >  c_it;  ///< Alias name for the constant circular iterator to the CRingBuffer elements.

        /// \brief Default empty constructor.
        /// \details It initializes it's data members to zero.
        /// \testmethod
        /// \traceability
        CRingBuffer() : super(), m_size(0), m_nextPosition(0) {}

        /// \brief Constructor with reference to array of possibly different size than this.
        /// \details  template constructor that copies the given non-constant reference 
        /// non-constant data of possibly different size (SIZE2) to the ringbuffer.
        /// non-constant reference to non-constant data will be passed to the base class constructor in which data member initialization happens.
        /// This will also initializes the CRingBuffer class data members m_size and m_nextPosition.
        /// \tparam          SIZE2         The size of the array
        /// \param[in]       data          Reference to the data of SIZE2
        /// \param[in]       rb_size       Constant size
        /// \param[in]       NextPosition Constant position of the next element to insert

        template< sint32 SIZE2 >
        explicit CRingBuffer( type (&data)[SIZE2], const size_type rb_size = 0, const size_type NextPosition = 0 ) : super(data), m_size(rb_size), m_nextPosition(NextPosition) {}

        /// \brief Constructor with reference to constant array of possibly different size than this.
        /// \details  template constructor that copies the given non-constant reference 
        /// constant data of possibly different size (SIZE2) to the ringbuffer.
        /// non-constant reference to constant data will be passed to the base class constructor in which data member initialization happens.
        /// This will also initializes the CRingBuffer class data members m_size and m_nextPosition.
        /// \tparam          SIZE2         The size of the array
        /// \param[in]       data          Reference to constant external data of SIZE2
        /// \param[in]       rb_size       Constant size
        /// \param[in]       NextPosition  Constant position of the next element to insert
        template< sint32 SIZE2 >
        explicit CRingBuffer( const_type (&data)[SIZE2], const size_type rb_size = 0, const size_type NextPosition = 0 ) : super(data), m_size(rb_size), m_nextPosition(NextPosition) {}

        /// \brief Constructor with a constant CArrayStorage object of data and possibly different size and EXT_MEM setting.
        /// \details  template copy constructor that copies or attaches constant reference to the CArrayStorage object 
        /// with non-constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the ringbuffer.
        /// constant reference to the CArrayStorage object rhs will be passed to the base class constructor in which data member initialization happens.
        /// This will also initializes the CRingBuffer class data members m_size and m_nextPosition.
        /// \tparam          SIZE2         The size of the array
        /// \tparam          EXT_MEM2      Flag whether the memory of the elements of the array is inside
        ///                                of this class (false) or outside of this class (true).
        ///                                Default is false, meaning internal memory.
        /// \param[in]       rhs           Reference to constant external CArrayStorage data of SIZE2
        /// \param[in]       rb_size       Constant size
        /// \param[in]       NextPosition  Constant position of the next element to insert
        template< sint32 SIZE2, bool EXT_MEM2 >
        explicit CRingBuffer( const cml::CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs, const size_type rb_size = 0, const size_type NextPosition = 0 ) : super(rhs), m_size(rb_size), m_nextPosition(NextPosition) {}

        /// \brief Constructor with a constant CArrayStorage object of constant data and possibly different size and EXT_MEM setting.
        /// \details  template copy constructor that copies or attaches constant reference to the CArrayStorage object 
        /// with constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the ringbuffer.
        /// constant reference to the CArrayStorage object rhs will be passed to the base class constructor in which data member initialization happens.
        /// This will also initializes the CRingBuffer class data members m_size and m_nextPosition.
        /// \tparam          SIZE2         The size of the array
        /// \tparam          EXT_MEM2      Flag whether the memory of the elements of the array is inside
        ///                                of this class (false) or outside of this class (true).
        ///                                Default is false, meaning internal memory.
        /// \param[in]       rhs           Reference to the constant external CArrayStorage data of SIZE2
        /// \param[in]       rb_size         Constant size
        /// \param[in]       NextPosition Constant position of the next element to insert
        template< sint32 SIZE2, bool EXT_MEM2 >
        explicit CRingBuffer( const cml::CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs, const size_type rb_size = 0, const size_type NextPosition = 0 ) : super(rhs), m_size(rb_size), m_nextPosition(NextPosition) {}

        /// \brief Constructor with a CArrayStorage object of data and possibly different size and EXT_MEM setting.
        /// \details  template copy constructor that copies or attaches non-constant reference to the CArrayStorage object 
        /// with non-constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the ringbuffer.
        /// non-constant reference to the CArrayStorage object rhs will be passed to the base class constructor in which data member initialization happens.
        /// This will also initializes the CRingBuffer class data members m_size and m_nextPosition.
        /// \tparam          SIZE2         The size of the array
        /// \tparam          EXT_MEM2      Flag whether the memory of the elements of the array is inside
        ///                                of this class (false) or outside of this class (true).
        ///                                Default is false, meaning internal memory.
        /// \param[in]       rhs           Reference to external CArrayStorage data of SIZE2
        /// \param[in]       rb_size         Constant size
        /// \param[in]       NextPosition Constant position of the next element to insert
        template< sint32 SIZE2, bool EXT_MEM2 >
        explicit CRingBuffer( cml::CArrayStorage<      type, SIZE2, EXT_MEM2>& rhs, const size_type rb_size = 0, const size_type NextPosition = 0 ) : super(rhs), m_size(rb_size), m_nextPosition(NextPosition) {}

        /// \brief Constructor with a CArrayStorage object of constant data and possibly different size and EXT_MEM setting.
        /// \details  template copy constructor that copies or attaches non-constant reference to the CArrayStorage object 
        /// with constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the ringbuffer.
        /// non-constant reference to the CArrayStorage object rhs will be passed to the base class constructor in which data member initialization happens.
        /// This will also initializes the CRingBuffer class data members m_size and m_nextPosition.
        /// \tparam          SIZE2         The size of the array
        /// \tparam          EXT_MEM2      Flag whether the memory of the elements of the array is inside
        ///                                of this class (false) or outside of this class (true).
        ///                                Default is false, meaning internal memory.
        /// \param[in]       rhs           Reference to the external CArrayStorage data of SIZE2
        /// \param[in]       rb_size         Constant size
        /// \param[in]       NextPosition Constant position of the next element to insert
        template< sint32 SIZE2, bool EXT_MEM2 >
        explicit CRingBuffer( cml::CArrayStorage<const_type, SIZE2, EXT_MEM2>& rhs, const size_type rb_size = 0, const size_type NextPosition = 0 ) : super(rhs), m_size(rb_size), m_nextPosition(NextPosition) {}

        /// \brief Constructor with a constant CRingBuffer object of data and possibly different size and EXT_MEM setting.
        /// \details  template copy constructor that copies or attaches constant reference to the CRingBuffer object 
        /// with non-constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the ringbuffer.
        /// constant reference to the CRingBuffer object rhs will be passed to the base class constructor in which data member initialization happens.
        /// This will also initializes the CRingBuffer class data members m_size and m_nextPosition with m_size and m_nextPosition of the object rhs.
        /// \tparam          SIZE2     The size of the array
        /// \tparam          EXT_MEM2  Flag whether the memory of the elements of the array is inside
        ///                            of this class (false) or outside of this class (true).
        ///                            Default is false, meaning internal memory.
        /// \param[in]       rhs       Reference to constant external CArrayStorage data of SIZE2
        template< sint32 SIZE2, bool EXT_MEM2 >
        explicit CRingBuffer( const CRingBuffer<      type, SIZE2, EXT_MEM2>& rhs ) : super(rhs), m_size(rhs.size()), m_nextPosition(rhs.nextPosition()) {}

        /// \brief Constructor with a CRingBuffer object of data and possibly different size and EXT_MEM setting.
        /// \details  template copy constructor that copies or attaches reference to the CRingBuffer object 
        /// with non-constant data of possibly different size(SIZE2) and memory specializations(EXT_MEM2) to the ringbuffer.
        /// non-constant reference to the CRingBuffer object rhs will be passed to the base class constructor in which data member initialization happens.
        /// This will also initializes the CRingBuffer class data members m_size and m_nextPosition with m_size and m_nextPosition of the object rhs.
        /// \tparam          SIZE2     The size of the array
        /// \tparam          EXT_MEM2  Flag whether the memory of the elements of the array is inside
        ///                            of this class (false) or outside of this class (true).
        ///                            Default is false, meaning internal memory.
        /// \param[in]       rhs       Reference to external CArrayStorage data of SIZE2
        template< sint32 SIZE2, bool EXT_MEM2 >
        explicit CRingBuffer( CRingBuffer<      type, SIZE2, EXT_MEM2>& rhs ) : super(rhs), m_size(rhs.size()), m_nextPosition(rhs.nextPosition()) {}

        /// \brief Returns the iterator to the nextPosition in the ring buffer.
        /// \details This function returns an iterator to the next position in the ringbuffer at which new element can be inserted.
        /// \return Iterator to the nextPosition in the ring buffer..
        it  it_nextPosition()    { return it (&m_data[m_nextPosition],this); } 


        /// \brief Returns the iterator to the current first element of the ring buffer.
        /// \details This function returns an iterator to the most recently updated element of the ring buffer. 
        /// \return Iterator to the most recent updated element of the ring buffer.
        it  cir_begin()    { return it (&m_data[(m_nextPosition + SIZE - 1)%SIZE],this); }

        /// \brief Returns the iterator to the last / oldest element in the ring buffer.
        /// \details This function returns an iterator  to the oldest element of the ring buffer.
        /// \return   Iterator  to the oldest element of the ring buffer.
        it  cir_end()        { return it (&m_data[(m_nextPosition + SIZE - size())%SIZE],this); }

        /// \brief Returns the constant iterator to the current first element of the ring buffer.
        /// \details  This function returns constant iterator to the most recently updated element of the ring buffer.
        /// \return Constant iterator to the most recent updated element of the ring buffer.
        c_it  cir_cbegin()  const  { return c_it (&m_data[(m_nextPosition + SIZE - 1)%SIZE],this); }

        /// \brief Returns the constant iterator to the last / oldest element in the ring buffer.
        /// \details This function returns constant iterator  to the oldest element of the ring buffer.
        /// \return   Constant iterator  to the oldest element of the ring buffer.
        c_it cir_cend()  const { return c_it(&m_data[(m_nextPosition + SIZE - size())%SIZE],this); }

        /// \brief Returns an iterator to the beginning of the underlying array..
        /// In debug case, it is ensured via assert that the array
        /// bounds are never exceeded.
        /// \details This function returns an iterator to the beginning of the underlying array.
        /// \return     Returns an iterator to the beginning of the underlying array.
        it  begin()    { return it (&m_data[0],this); }

        /// \brief Returns an iterator to the position after the end of the underlying array.
        /// In debug case, it is ensured via assert that the array
        /// bounds are never exceeded.
        /// \details This function returns an iterator to the position after the end of the underlying array.
        /// \return          Returns an iterator to the position after the end of the underlying array.
        it  end()        { return it (&m_data[SIZE],this); }

        /// \brief Returns a constant iterator to the beginning of the underlying array.
        /// In debug case, it is ensured via assert that the array
        /// bounds are never exceeded.
        /// \details This function returns a constant iterator to the beginning of the underlying array.
        /// \return    Returns a constant iterator to the beginning of the underlying array.
        c_it  cbegin()  const  { return c_it (&m_data[0],this); }

        /// \brief Returns a constant iterator to the position after the the end of the underlying array.
        /// In debug case, it is ensured via assert that the array
        /// bounds are never exceeded.
        /// \details This function returns a constant iterator to the position after the end of the underlying array.
        /// \return          Returns a constant iterator to the position after the the end of the underlying array.
        c_it cend()  const { return c_it(&m_data[SIZE],this); }


        /// \brief Assignment operator overloading function which always makes a copy of the data and never attaches.
        /// \details This function copies external identical object to the calling object.m_size and  m_nextPosition of the external object is assigned to the calling objects m_size and  m_nextPosition respectively.
        /// this function internally calls base class assignment operator overloading function with object "rhs" as an argument.
        /// This function returns the reference to the calling object.
        /// \param[in]       rhs    Reference to external constant data buffer of identical size
        /// \return          Reference to this pointer
        self& operator=(const self& rhs)
        {
            super::operator=(rhs);
            m_size         = rhs.size();
            m_nextPosition = rhs.nextPosition();
            return *this;
        }

        /// \brief  template assignment operator overloading function with non-constant data.
        /// \details copy external identical constant reference non-constant data of identical size(SIZE) and memory specializations(EXT_MEM2) to the ring buffer.
        /// This function calls base class assignment operator overloading function with object "rhs" as an argument.
        /// m_size and  m_nextPosition of the external object rhs is assigned to the calling object's m_size and  m_nextPosition respectively.
        /// This function returns the reference to the calling object.
        /// \tparam          EXT_MEM2  Flag whether the memory of the elements of the array is inside
        ///                            of this class (false) or outside of this class (true).
        ///                            Default is false, meaning internal memory.
        /// \param[in]       rhs       Constant reference to external RingBuffer with non-constant data  of identical size
        /// \return          Reference to this pointer.
        template< bool EXT_MEM2 >
        self& operator=(const CRingBuffer<      type, SIZE, EXT_MEM2>& rhs)
        {
            super::operator=(rhs);
            m_size         = rhs.size();
            m_nextPosition = rhs.nextPosition();
            return *this;
        }


        /// \brief Clears the ring buffer by setting size to zero.
        /// \details This function clears the ring buffer by setting m_size and m_nextPosition to zero.But memory is not cleared.
        void clear()
        {
            m_size         = 0;
            m_nextPosition = 0;
        }

        using super::max_size;

        /// \brief Function returning number of elements in the underlying array.
        /// \details Constant member function returning current number of elements in the ring buffer.In this member function, no member data is modified.
        /// \return Number of elements in the array
        size_type size() const
        {
            return m_size;
        }

        /// \brief Function returning the position in the underlying array where the next element will be inserted.
        /// \details Constant member function returning current position for the next element to insert in the ring buffer.
        /// In this member function, no member data is modified.
        /// \return Number of elements in the array
        size_type nextPosition() const
        {
            return m_nextPosition;
        }

        /// \brief function to check whether the ring buffer is empty or not.
        /// \details This function is a constant member function to check whether the ring buffer is empty or not.
        /// If m_size is zero this function returns true or false.In this member function, no member data is modified.
        /// \return Return true if vector list is empty, false if not.
        bool empty() const
        {
            return (m_size == 0);
        }

        /// \brief function to check whether the ring buffer is full or not.
        /// \details This function is a constant member function to check whether the ring buffer is full or not.
        /// In this member function, no member data is modified.
        /// \return Return true if vector list is empty, false if not.
        bool full() const
        {
            return (m_size >= SIZE);
        }

        /// \brief This function returns the reference to the current first element of the ring buffer.
        /// \details This function returns the reference to the most recently updated element of the ring buffer.
        /// \return Reference to most recent updated element of the ring buffer.
        reference front()
        {
            return operator[](0);
        }

        /// \brief This function returns the constant reference to the current first element of the ring buffer.
        /// \details This function is a constant member function returning constant reference to
        /// the most recently updated element of the ring buffer.
        /// \return Constant reference to most recent updated element of the ring buffer.
        const_reference front() const
        {
            return operator[](0);
        }

        /// \brief This function returns the reference to the current last / oldest element in the ring buffer.
        /// \details This function returns the reference to the oldest element in the ring buffer.
        /// \return Reference to oldest element in the ring buffer.
        reference back()
        {
            return operator[](size() - 1);
        }

        /// \brief function returns the constant reference to the last / oldest element in the ring buffer
        /// \details  This function is a constant member function returning constant reference to the  oldest element of the ring buffer.
        /// \return Constant reference to oldest element of the ring buffer
        const_reference back() const
        {
            return operator[](size() - 1);
        }

        /// \brief This function returns the reference to the element at given position.
        /// \details The element at position 0 is the recently added element and size-1 is the oldest element in the ring buffer.
        /// \attention  Caller should ensure that the position is inside of the array boundary.
        /// \param[in] position Constant position of the element
        /// \return      Reference to the array element at given position
        reference operator[](const size_type position)
        {
            assert((position >= 0) && (position < size()));
            assert(position <= (m_nextPosition + (SIZE -1)));
            return m_data[(m_nextPosition + (SIZE - 1) - position)%SIZE];
        }

        /// \brief This function returns a constant reference to the element at given position.
        /// \details The element at position 0 is the recently added element and size-1 is the oldest element in the ring buffer.
        /// \attention  Caller should ensure that the position is inside of the array boundary.
        /// \param[in] position Constant position of the element
        /// \return             Constant reference to the array element at given position
        const_reference operator[](const size_type position) const
        {
            assert((position >= 0) && (position < size()));
            assert(position <= (m_nextPosition + (SIZE -1)));
            return m_data[(m_nextPosition + (SIZE - 1) - position)%SIZE];
        }

        /// \brief This function appends input element at the end of ring buffer.
        /// \details This function pushes the elements into the ring buffer till the size reaches the ringbuffer size (SIZE) after that it overwrites the oldest element.
        /// \attention Caller must ensure that the size is less than SIZE and position of next element to insert is smaller or equal to current size.
        /// \param[in] x Constant reference to value to be filled.
        void push_back(const_reference x)
        {
            assert(size() <= SIZE);
            assert(m_nextPosition <= size());
            if(!full())
            {
                ++m_size;
            }
            ++m_nextPosition;
            m_nextPosition = m_nextPosition%SIZE;
            front() = x;
        }

        /// \brief This function returns the reference to the next element to overwrite.
        /// \details Enlarges the ring buffer if necessary and gives back the reference to the new element. If the buffer is full it gives back a reference to the oldest element.
        /// \attention Caller must ensure that the size is less than SIZE and position of next element to insert is smaller or equal to current size.
        /// \return Reference to new element after push back
        reference push_back()
        {
            assert(size() <= SIZE);
            assert(m_nextPosition <= size());
            if(!full())
            {
                ++m_size;
            }
            ++m_nextPosition;
            m_nextPosition = m_nextPosition%SIZE;
            return front();
        }

    private:
        size_type m_nextPosition; ///< Index of the last inserted element.
        size_type m_size;         ///< Current used size of the ring buffer whose maximum size is "SIZE".

    protected:
        using super::m_data;
    };
}
#endif //CML_STL_RINGBUFF_H__
