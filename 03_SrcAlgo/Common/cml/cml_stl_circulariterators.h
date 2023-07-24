/*! \file **********************************************************************

COMPANY:                   Continental AG, A.D.C. GmbH

CPU:                       CPU-Independent

COMPONENT:                 CML (Common Math Library)

MODULNAME:                 cml_stl_cirulariterators.h

DESCRIPTION:               Iterator Library

AUTHOR:                    Purushotham Reddy / Lars Ulveland

CREATION DATE:             12.04.2017

VERSION:                   $Revision: 1.6 $

**************************************************************************** */

#ifndef CML_STL_CIR_ITERATOR_H__
#define CML_STL_CIR_ITERATOR_H__

#include <cassert>
#include <iterator>

#include "cml_stl_type_traits.h"

namespace cml
{

    /// \brief Template circular iterator base class.
    /// \details This circular iterator is used to traverse the ringbuffer container circularly.Circular memory iterator will be derived from this class.
    /// \tparam T                 The type of the element.
    /// \tparam IS_CONST_ITERATOR Flag whether the iterator is constant(true) or not(false).
    /// \tparam CONTAINER_TYPE    The type of the container
    /// \testmethod
    /// \traceability

    template<class T, boolean_t IS_CONST_ITERATOR, class CONTAINER_TYPE>
    class CCirBaseIt
    {
    public:
        typedef CCirBaseIt<T,IS_CONST_ITERATOR,CONTAINER_TYPE> self;  ///< Alias name for the base circular iterator class.
        typedef CONTAINER_TYPE                              container_type;  ///< Alias name for the container type.
        typedef typename conditional<IS_CONST_ITERATOR, typename add_const<T>::type, T>::type value_type; ///< Alias name for the type(const /non const) based on the container type(const /non const) .
        typedef value_type* pointer;  ///< Alias name for the pointer to the value_type.
        typedef value_type& reference; ///< Alias name for the reference to the value_type.
        typedef int         difference_type; ///< Abbreviation for the integer type and it is used for storing the difference of two pointers.

        /// \brief Default empty constructor.
        /// \testmethod
        /// \traceability
        CCirBaseIt () : m_p(0), m_pContainer(0) {}

        /// \brief Explicit constructor with arguments for initial memory position and  static container.
        /// \details  This function takes pointer to the container element (_p) and  pointer to the container(_pContainer) as arguments and initializes protected data members of the class .
        /// \param[in]       _p             Pointer to initial memory position  
        /// \param[in]       _pContainer    Constant pointer to static container for dynamic 
        ///                                 boundary and container equality checking
        /// \testmethod
        /// \traceability
        explicit CCirBaseIt (
            pointer               _p,           // initial memory position
            container_type* _pContainer )       // static container for dynamic boundary and container equality checking
            : m_p         ( _p )
            , m_pContainer( _pContainer )
        {}

        /// \brief Constructor with an identical iterator.
        /// \details  Constant reference to the similar object "rhs" is passed as an argument and  is used for object initialization.
        /// \param[in]       rhs    Constant reference to identical iterator. 
        /// \testmethod
        /// \traceability
        CCirBaseIt( const CCirBaseIt<T,false,container_type>& rhs )
            : m_p         ( rhs.m_p )
            , m_pContainer( rhs.m_pContainer )
        {}

        template<class, boolean_t, class>
        friend class CCirBaseIt;

        /// \brief Dereferencing of the element.
        /// \details This function returns the pointer (m_p) which is the protected member of this class.
        /// \attention  Iterators should be within the container boundary.
        /// \return          Current pointer
        /// \testmethod
        /// \traceability
        pointer operator->() const
        {
            assert ( (m_pContainer != 0)
                &&     (m_p          != 0)
                &&     ((*this) >= m_pContainer->begin())
                &&     ((*this) <  m_pContainer->end()  ) );
            return m_p;
        }

        /// \brief Indirection of the element.
        /// \details This function returns the reference to the element pointed to by the current iterator.
        /// \return             Reference to the element.
        /// \testmethod
        /// \traceability
        reference operator*() const
        {
            return *(operator->());
        }

        /// \brief Returns comparison result of two iterator objects.
        /// \details Returns comparison result of two iterator objects.
        /// True, if both object references are same else False.
        /// \attention iterator object references should be for similar memory.
        /// \tparam      IS_CONST_ITERATOR_2 Flag whether the iterator is constant or not.
        /// \param[in]       rhs    Constant reference to identical iterator object.   
        /// \return                 True, if both object references are same, else False.
        /// \testmethod
        /// \traceability
        template<boolean_t IS_CONST_ITERATOR_2>
        boolean_t operator== (const CCirBaseIt<T,IS_CONST_ITERATOR_2,CONTAINER_TYPE>& rhs) const
        {
            // check that rhs is from the same memory
            assert(m_pContainer != NULL);
            assert(m_pContainer == rhs.m_pContainer);
            return m_p == rhs.m_p;
        }

        /// \brief Returns comparison result of two iterator objects.
        /// \details Returns comparison result of two iterator objects.
        /// True, if both object references are not same, else False.
        /// \attention iterator object references should be for similar memory.
        /// \tparam      IS_CONST_ITERATOR_2 Flag whether the iterator is constant or not.
        /// \param[in] rhs   Constant reference to identical iterator object.   
        /// \return          True, if both object references are not same, else False.
        /// \testmethod
        /// \traceability
        template<boolean_t IS_CONST_ITERATOR_2>
        boolean_t operator!= (const CCirBaseIt<T,IS_CONST_ITERATOR_2,CONTAINER_TYPE>& rhs) const
        {
            // check that rhs is from the same memory
            assert(m_pContainer != NULL);
            assert(m_pContainer == rhs.m_pContainer);

            return m_p != rhs.m_p;
        }

        /// \brief Returns comparison result of two iterator objects.
        /// \details Returns comparison result of two iterator objects.
        /// True, if first iterator object reference is greater than or 
        /// equal to second, else False.
        /// \attention iterator object references should be for similar memory.
        /// \tparam      IS_CONST_ITERATOR_2 Flag whether the iterator is constant or not.
        /// \param[in] rhs   Constant reference to identical iterator object.   
        /// \return          True, if first iterator object reference is greater than or 
        ///                  equal to second, else False. 
        /// \testmethod
        /// \traceability
        template<boolean_t IS_CONST_ITERATOR_2>
        boolean_t operator>= (const CCirBaseIt<T,IS_CONST_ITERATOR_2,CONTAINER_TYPE>& rhs) const
        {
            // check that rhs is from the same memory
            assert(m_pContainer != NULL);
            assert(m_pContainer == rhs.m_pContainer);
            return m_p >= rhs.m_p;
        }

        /// \brief Returns comparison result of two iterator objects.
        /// \details Returns comparison result of two iterator objects.
        /// True, if first iterator object reference is less than or 
        /// equal to second, else False.
        /// \attention iterator object references should be for similar memory.
        /// \tparam      IS_CONST_ITERATOR_2 Flag whether the iterator is constant or not.
        /// \param[in] rhs   Constant reference to identical iterator object.   
        /// \return          True, if first iterator object reference is less than or 
        ///                  equal to second, else False.
        /// \testmethod
        /// \traceability
        template<boolean_t IS_CONST_ITERATOR_2>
        boolean_t operator<= (const CCirBaseIt<T,IS_CONST_ITERATOR_2,CONTAINER_TYPE>& rhs) const
        {
            // check that rhs is from the same memory
            assert(m_pContainer != NULL);
            assert(m_pContainer == rhs.m_pContainer);
            return m_p <= rhs.m_p;
        }

        /// \brief Returns comparison result of two iterator objects.
        /// \details Returns comparison result of two iterator objects.
        /// True, if first iterator object reference is greater than second, else False. 
        /// \attention iterator object references should be for similar memory.
        /// \tparam      IS_CONST_ITERATOR_2 Flag whether the iterator is constant or not.
        /// \param[in] rhs   Constant reference to identical iterator object.   
        /// \return          True, if first iterator object reference is greater than  
        ///                  second, else False. 
        /// \testmethod
        /// \traceability
        template<boolean_t IS_CONST_ITERATOR_2>
        boolean_t operator> (const CCirBaseIt<T,IS_CONST_ITERATOR_2,CONTAINER_TYPE>& rhs) const
        {
            // check that rhs is from the same memory
            assert(m_pContainer != NULL);
            assert(m_pContainer == rhs.m_pContainer);
            return m_p > rhs.m_p;
        }

        /// \brief Returns comparison result of two iterator objects.
        /// \details Returns comparison result of two iterator objects.
        /// True, if first iterator object reference is less than second, else False. 
        /// \attention iterator object references should be for similar memory.
        /// \tparam      IS_CONST_ITERATOR_2 Flag whether the iterator is constant or not.
        /// \param[in]  rhs  Constant reference to identical iterator object.   
        /// \return          True, if first iterator object reference is less than  
        ///                  second, else False.
        /// \testmethod
        /// \traceability
        template<boolean_t IS_CONST_ITERATOR_2>
        boolean_t operator< (const CCirBaseIt<T,IS_CONST_ITERATOR_2,CONTAINER_TYPE>& rhs) const
        {
            // check that rhs is from the same memory
            assert(m_pContainer != NULL);
            assert(m_pContainer == rhs.m_pContainer);

            return m_p < rhs.m_p;
        }

        /// \brief Returns the distance between two iterator objects.
        /// \details Returns the distance `n` in memory of two iterator objects.
        /// Where distance is defined as `n * sizeof(T)`.
        /// \attention iterator object references should be for similar memory.
        /// \tparam      IS_CONST_ITERATOR_2 Flag whether the iterator is constant or not.
        /// \param[in]       rhs   Constant reference to identical iterator object.  
        /// \return                The distance `n` in memory of two iterator objects.
        /// \testmethod
        /// \traceability
        template<boolean_t IS_CONST_ITERATOR_2>
        difference_type memory_distance(const CCirBaseIt<T,IS_CONST_ITERATOR_2,CONTAINER_TYPE>& rhs) const
        {
            // check that rhs is from the same memory
            assert(m_pContainer != NULL);
            assert(m_pContainer == rhs.m_pContainer);

            return static_cast<difference_type>(m_p - rhs.m_p);
        }

    protected:
        pointer m_p;   ///< a pointer variable of type value_type.
        container_type* m_pContainer;  ///< a pointer to the container type.
    };

    /// \brief  Generic iterator for elements in class of data type T which lie Circularly in memory.
    /// \details This circular memory iterator template class is derived from CCirBaseIt.
    /// \tparam T                 The type of the element
    /// \tparam IS_CONST_ITERATOR Flag whether the iterator is constant or not.
    /// \tparam CONTAINER_TYPE    The type of the container

    template <class T, boolean_t IS_CONST_ITERATOR, class CONTAINER_TYPE>
    class CCirMemIt : public CCirBaseIt<T,IS_CONST_ITERATOR,CONTAINER_TYPE>
    {

    public:
        typedef CCirMemIt<T,IS_CONST_ITERATOR,CONTAINER_TYPE> self;  ///< Abbreviation for the type of the class.
        typedef CCirMemIt<T,false            ,CONTAINER_TYPE> self_non_const; ///< Abbreviation for the type of the non-constant container class.
        typedef CCirBaseIt  <T,IS_CONST_ITERATOR,CONTAINER_TYPE>     super; ///< Abbreviation for the type of the base class.

        typedef          std::random_access_iterator_tag                 iterator_category;
        typedef typename remove_const<typename super::value_type>::type* pointer;  ///< Alias name for the pointer to type of the base class.
        typedef typename add_const   <typename super::value_type>::type* const_pointer; ///< Alias name for the  pointer to constant type of the base class.
        typedef typename super::pointer                                  const_noconst_pointer; ///< Alias name for the  pointer to the type of the base class.
        typedef typename super::reference                                reference; ///< Alias name for the  reference to the type of the base class.
        typedef typename super::difference_type                          difference_type;  ///< Abbreviation for the integer type and it is used for storing the difference of two pointers.

        using super::operator ->;

        /// \brief Default empty constructor.
        /// \testmethod
        /// \traceability
        CCirMemIt () : super() {}

        /// \brief Explicit constructor with pointer to the datamember and pointer to the container type as arguments.
        /// \details Explicit empty constructor with additional arguments for initial memory position(pointer to the datamember),
        ///  static container(pointer to the container type) for dynamic boundary and container equality checking.
        /// These arguments are passed to the base class constructor in which Iterator object is initialized.
        /// \param[in]       _p            Pointer to initial memory position  
        /// \param[in]       _pContainer   Constant pointer to static container for dynamic 
        ///                                boundary and container equality checking
        /// \testmethod
        /// \traceability
        explicit CCirMemIt (
            const_noconst_pointer _p,           // initial memory position
            CONTAINER_TYPE* _pContainer )       // static container for dynamic boundary and container equality checking
            : super( _p, _pContainer )
        {}

        /// \brief Explicit constructor with pointer to the datamember and const pointer to the container type as arguments.
        /// \details This constructor contains additional arguments for initial memory position (pointer to the datamember),
        ///  static container (const pointer to the container type) for dynamic boundary and container equality checking.
        /// These arguments are passed to the base class constructor in which Iterator object is initialized
        /// \param[in]       _p            Pointer to initial memory position  
        /// \param[in]       _pContainer   Constant pointer to static container for dynamic 
        ///                                boundary and container equality checking
        /// \testmethod
        /// \traceability
        explicit CCirMemIt (
            const_noconst_pointer _p,                   // initial memory position
            const CONTAINER_TYPE* _pContainer )         // static container for dynamic boundary and container equality checking
            : super( _p, (CONTAINER_TYPE*)_pContainer )
        {}

        /// \brief Explicit constructor with pointer to the datamember and pointer to the container type as arguments.
        /// \details Explicit empty constructor with additional arguments for initial memory position(pointer to the datamember),
        ///  static container(pointer to the container type) for dynamic boundary and container equality checking.
        /// These arguments are passed to the base class constructor in which Iterator object is initialized.
        /// \param[in]       _p             Pointer to initial memory position  
        /// \param[in]       _pContainer    Constant pointer to static container for dynamic 
        ///                                 boundary and container equality checking 
        /// \testmethod
        /// \traceability
        explicit CCirMemIt (
            const_noconst_pointer _p,           // initial memory position
            CONTAINER_TYPE* _pContainer,        // static container for dynamic boundary and container equality checking
            const_pointer,
            const_pointer )
            : super( _p, _pContainer )
        {}



        /// \brief Constructor with non constant container type class object of similar type as an argument.
        /// \details This constructor contains the object "rhs" as an argument which is passed to the base class constructor in which object initilization happens.
        /// \param[in]       rhs   Reference to identical iterator.
        /// \testmethod
        /// \traceability
        CCirMemIt( const self_non_const& rhs )
            : super( rhs.m_p, rhs.m_pContainer )
        {}

        template<class, boolean_t, class>
        friend class CCirMemIt;

        /// \brief Returns the element at given position 'n'.
        /// \details  Index operator overloading function which returns a reference to the element.at position n.
        /// This function internally calls the overloaded dereferencing function and the index operator overloading function of it's base class.
        /// \attention position (n) should be within the container limits and Iterator should not be null.Otherwise behaviour is undefined.
        /// \param[in]   n   Constant reference to input position.  
        /// \return          Reference to the element at given position.
        /// \testmethod
        /// \traceability
        reference operator[](const difference_type& n) const
        {
            // assert that container is inside the bounds.
            assert ( (m_pContainer != 0)
                &&     (m_p          != 0)
                &&     (self(m_p + n, m_pContainer) >= m_pContainer->begin())
                &&     (self(m_p + n, m_pContainer) <  m_pContainer->end()  ) );
            return operator->()[n];
        }

        /// \brief Pre-increament operator overloading function.
        /// \details Increments the member data pointer by 1.If the pointer is incremented when it is pointing to the last element in the container ,it will point to the first element of the container and thus the pointer interates circulary.
        /// This function returns the reference to the calling object.
        /// \return          Reference to this pointer 
        /// \testmethod
        /// \traceability
        self& operator++()
        {
            pointer p_m_data = (*m_pContainer).m_data;
            sint32 size=(*m_pContainer).max_size(); 
            m_p += 1;
            if(m_p==p_m_data+size)
                m_p=p_m_data;  
            return *this;
        }

        /// \brief Post-increament operator overloading function.
        /// \details calling object is stored in a local object and then pre-increments the calling object and returns value of the calling object which is stored in local object.
        /// \return          Value of the calling object before incrementing.
        /// \testmethod
        /// \traceability
        self operator++(difference_type)
        {
            self result(*this);
            ++(*this);
            return result;
        }

        /// \brief Pre-decreament operator overloading function.
        /// \details Decrements the member data pointer by 1.If the pointer is decremented when it is pointing to the first element in the container ,it will point to the last element of the container and thus the pointer interates circulary.
        /// This function returns the reference to the calling object.
        /// \return          Reference to the calling object.
        /// \testmethod
        /// \traceability
        self& operator--()
        {
            pointer p_m_data = m_pContainer->m_data; 
            sint32 size=(*m_pContainer).max_size(); 
            assert((m_p >= p_m_data) && (m_p <= p_m_data+size));
            m_p -= 1;
            if(m_p==p_m_data-1)
                m_p = p_m_data+size-1;
            return *this;
        }

        /// \brief Post-decreament operator overloading function.
        /// \details calling object is stored in a local object and then pre-decrements the calling object and returns value of the calling object which is stored in local object.
        /// \return          Value of the calling object before decrementing.
        /// \testmethod
        /// \traceability
        self operator--(difference_type)
        {
            self result(*this);
            --(*this);
            return result;
        }

        /// \brief Increments member data pointer by the given amount "increment".
        /// \details This function increments member data pointer by given amount "increment" and returns the reference to the calling object.
        /// After pointer increment,if it exceeds container size,it loops around and counts from the beginning of the container and thus ensures circular iteration.
        /// \param[in]       increment   Constant reference to increment value.
        /// \return          Reference to the calling object.
        /// \testmethod
        /// \traceability
        self& operator+=(const difference_type increment)
        {
            pointer p_m_data = (*m_pContainer).m_data;
            sint32  size = (*m_pContainer).max_size();
            assert((m_p >= p_m_data) && (m_p <= p_m_data+size));
            m_p=p_m_data+(m_p - p_m_data+increment)%size;
            return (*this);
        }

        /// \brief Decrements member data pointer by the given amount "decrement".
        /// \details This function decrements member data pointer by given amount "decrement" and returns the reference to the calling object.
        /// After pointer decremented,if it reaches container beginning,it loops around and counts downwords from the end of the container and thus ensures circular iteration.
        /// \param[in]       decrement   Constant reference to decrement value.  
        /// \return          Reference to the calling object.
        /// \testmethod
        /// \traceability
        self& operator-=(const difference_type decrement)
        {
            sint32 size = (*m_pContainer).max_size();
            pointer pEnd = m_pContainer->m_data + size-1;
            m_p=pEnd-((pEnd-m_p+decrement)%size);
            return (*this);
        }

        /// \brief addition operator overloading function.
        /// \details Returns a new iterator whose member data pointer is incremented by 'n' compared to current iterator.
        /// This function internally calls compound assignment operator(+=) overloaded function with 'n' as argument.
        /// \param[in]    n  Constant reference to increment value  
        /// \return          A new iterator whose member data pointer is incremented
        ///                  by n compared to current iterator. 
        /// \testmethod
        /// \traceability
        self operator+(const difference_type& n) const
        {
            CCirMemIt result(*this);
            result += n;
            return result;
        }

		/// \brief substraction operator overloading function.
        /// \details Returns a new iterator whose member data pointer is decremented by n compared to current iterator.
        /// This function internally calls compound assignment operator(-=) overloaded function with 'n' as argument.
        /// \param[in]    n  Constant reference to decrement value  
        /// \return          A new iterator whose member data pointer is decremented
        ///                  by n compared to current iterator.
        /// \testmethod
        /// \traceability
        self operator-(const difference_type& n) const
        {
            CCirMemIt result(*this);
            result -= n;
            return result;
        }

        /// \brief  Returns difference between two iterators
        /// \details Returns difference between two iterators giving the distance in memory.This function internally calls the function memory_distance() of it's base class with rhs as an argument.
        /// \tparam IS_CONST_ITERATOR2 Flag whether the iterator is constant or not.
        /// \param[in]       rhs   Constant reference to identical iterator object  
        /// \return                Difference between two iterators giving the distance in memory. 
        /// \testmethod
        /// \traceability
        template<boolean_t IS_CONST_ITERATOR2>
        difference_type operator-(const CCirMemIt<T, IS_CONST_ITERATOR2, CONTAINER_TYPE>& rhs) const
        {
            return memory_distance(rhs) / static_cast<difference_type>(1);
        }
        using super::memory_distance;

    protected:
        using super::m_p;
        using super::m_pContainer;
    };

}
#endif //CML_STL_CIR_ITERATOR_H__