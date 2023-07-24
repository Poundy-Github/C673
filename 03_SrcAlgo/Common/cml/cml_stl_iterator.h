/*! \file **********************************************************************

COMPANY:                   Continental AG, A.D.C. GmbH

CPU:                       CPU-Independent

COMPONENT:                 CML (Common Math Library)

MODULNAME:                 cml_stl_iterator.h

DESCRIPTION:               Iterator Library

AUTHOR:                    Christian Exner / Markus Friebertshaeuser

CREATION DATE:             15.11.2012

VERSION:                   $Revision: 1.40 $

**************************************************************************** */

#ifndef CML_STL_ITERATOR_H__
#define CML_STL_ITERATOR_H__

#include <cassert>
#include <iterator>

#include "cml_stl_type_traits.h"

namespace cml
{
    /// \brief Template iterator base class.
    /// \details This iterator is used to traverse the containers like arrays,vectors etc.
    /// \tparam T                 The type of the element
    /// \tparam IS_CONST_ITERATOR Flag whether the iterator is constant or not.
    /// \tparam CONTAINER_TYPE    The type of the container
    /// \testmethod
    /// \traceability

#ifndef NDEBUG
    template<class T, boolean_t IS_CONST_ITERATOR, class CONTAINER_TYPE>
#else
    template<class T, boolean_t IS_CONST_ITERATOR>
#endif
    class CBaseIt
    {
    public:
#ifndef NDEBUG
        typedef CBaseIt<T,IS_CONST_ITERATOR,CONTAINER_TYPE> self;  ///< Alias name for the base iterator class.
        typedef CONTAINER_TYPE                              container_type;   ///< Alias name for the container type.
#else
        typedef CBaseIt<T,IS_CONST_ITERATOR>                self;   ///< Alias name for the base iterator class.
#endif

        typedef typename conditional<IS_CONST_ITERATOR, typename add_const<T>::type, T>::type value_type; ///< Alias name for the type(const /non const) based on the container type(const /non const) .
        typedef value_type* pointer;  ///< Alias name for the pointer to the value_type.
        typedef value_type& reference; ///< Alias name for the reference to the value_type.
        typedef int         difference_type; ///< Abbreviation for the integer type and it is used for storing the difference of two pointers.

#ifndef NDEBUG

        /// \brief Default empty constructor.
        /// \testmethod
        /// \traceability
        CBaseIt () : m_p(0), m_pContainer(0) {}

        /// \brief Explicit constructor.
        /// \details Explicit empty constructor with additional arguments for 
        /// initial memory position, static container for dynamic 
        /// boundary and container equality checking.
        /// \param[in]       _p             Pointer to initial memory position  
        /// \param[in]       _pContainer    Constant pointer to static container for dynamic 
        ///   			                    boundary and container equality checking
        /// \testmethod
        /// \traceability
        explicit CBaseIt (
            pointer               _p,           // initial memory position
            const container_type* _pContainer ) // static container for dynamic boundary and container equality checking
            : m_p         ( _p )
            , m_pContainer( _pContainer )
        {}

        /// \brief constructor with an identical iterator.
        /// \details Constant reference to the similar object "rhs" is passed as an argument and  is used for object initialization.
        /// \param[in]       rhs    Constant reference to identical iterator.
        /// \testmethod
        /// \traceability
        CBaseIt( const CBaseIt<T,false,container_type>& rhs )
            : m_p         ( rhs.m_p )
            , m_pContainer( rhs.m_pContainer )
        {}

#else
        /// \brief Empty constructor.
        /// \testmethod
        /// \traceability
        CBaseIt () {}
        
        /// \brief Empty constructor with additional argument for initial memory position.
        /// \details Pointer to initial memory position is passed as an argument and assigned to the internal pointer (m_p) which is protected member of this class.
        /// \param[in]       _p : Pointer to initial memory position
        /// \testmethod
        /// \traceability
        explicit CBaseIt (pointer _p)
            : m_p( _p )
        {}

        /// \brief Copy constructor that initializes the internal pointer with similar object.
        /// \details Constant reference to the similar object "rhs" is passed as an argument and  is used for initialization.
        /// \param[in]       rhs : Constant reference to identical iterator.
        /// \testmethod
        /// \traceability
        CBaseIt( const CBaseIt<T,false>& rhs )
            : m_p ( rhs.m_p )
        {}
#endif //#ifndef NDEBUG


#ifndef NDEBUG
        template<class, boolean_t, class>
#else
        template<class, boolean_t>
#endif
        friend class CBaseIt;
        
        /// \brief Dereferencing of the element.
        /// \details This function returns the pointer (m_p) which is the protected member of this class.
        /// \attention iterators should be within the container boundary and should not be null.
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
#ifndef NDEBUG
        boolean_t operator== (const CBaseIt<T,IS_CONST_ITERATOR_2,CONTAINER_TYPE>& rhs) const
#else
        boolean_t operator== (const CBaseIt<T,IS_CONST_ITERATOR_2>& rhs) const
#endif
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
#ifndef NDEBUG
        boolean_t operator!= (const CBaseIt<T,IS_CONST_ITERATOR_2,CONTAINER_TYPE>& rhs) const
#else
        boolean_t operator!= (const CBaseIt<T,IS_CONST_ITERATOR_2>& rhs) const
#endif
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
#ifndef NDEBUG
        boolean_t operator>= (const CBaseIt<T,IS_CONST_ITERATOR_2,CONTAINER_TYPE>& rhs) const
#else
        boolean_t operator>= (const CBaseIt<T,IS_CONST_ITERATOR_2>& rhs) const
#endif
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
        ///  	             equal to second, else False.
        /// \testmethod
        /// \traceability
        template<boolean_t IS_CONST_ITERATOR_2>
#ifndef NDEBUG
        boolean_t operator<= (const CBaseIt<T,IS_CONST_ITERATOR_2,CONTAINER_TYPE>& rhs) const
#else
        boolean_t operator<= (const CBaseIt<T,IS_CONST_ITERATOR_2>& rhs) const
#endif
        {
            // check that rhs is from the same memory
            assert(m_pContainer != NULL);
            assert(m_pContainer == rhs.m_pContainer);

            return m_p <= rhs.m_p;
        }

        /// \brief Returns comparison result of two iterator objects.
        /// \details Returns comparison result of two iterator objects.
        /// True, if first iterator object reference is greater than  
        /// second, else False.
        /// \attention iterator object references should be for similar memory.
        /// \tparam      IS_CONST_ITERATOR_2 Flag whether the iterator is constant or not.
        /// \param[in] rhs   Constant reference to identical iterator object.   
        /// \return          True, if first iterator object reference is greater than  
        ///                  second, else False.
        /// \testmethod
        /// \traceability
        template<boolean_t IS_CONST_ITERATOR_2>
#ifndef NDEBUG
        boolean_t operator> (const CBaseIt<T,IS_CONST_ITERATOR_2,CONTAINER_TYPE>& rhs) const
#else
        boolean_t operator> (const CBaseIt<T,IS_CONST_ITERATOR_2>& rhs) const
#endif
        {
            // check that rhs is from the same memory
            assert(m_pContainer != NULL);
            assert(m_pContainer == rhs.m_pContainer);

            return m_p > rhs.m_p;
        }

        /// \brief Returns comparison result of two iterator objects.
        /// \details Returns comparison result of two iterator objects.
        /// True, if first iterator object reference is less than  
        /// second, else False.
        /// \attention iterator object references should be for similar memory.
        /// \tparam      IS_CONST_ITERATOR_2 Flag whether the iterator is constant or not.
        /// \param[in]  rhs  Constant reference to identical iterator object.   
        /// \return          True, if first iterator object reference is less than  
        /// 				 second, else False.
        /// \testmethod
        /// \traceability
        template<boolean_t IS_CONST_ITERATOR_2>
#ifndef NDEBUG
        boolean_t operator< (const CBaseIt<T,IS_CONST_ITERATOR_2,CONTAINER_TYPE>& rhs) const
#else
        boolean_t operator< (const CBaseIt<T,IS_CONST_ITERATOR_2>& rhs) const
#endif
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
#ifndef NDEBUG
        difference_type memory_distance(const CBaseIt<T,IS_CONST_ITERATOR_2,CONTAINER_TYPE>& rhs) const
#else
        difference_type memory_distance(const CBaseIt<T,IS_CONST_ITERATOR_2>& rhs) const
#endif
        {
            // check that rhs is from the same memory
            assert(m_pContainer != NULL);
            assert(m_pContainer == rhs.m_pContainer);

            return static_cast<difference_type>(m_p - rhs.m_p);
        }

        protected:
            pointer m_p; ///< a pointer variable of type value_type.

#ifndef NDEBUG
        const container_type* m_pContainer;  ///< constant pointer to the container type.
#endif
    };
    
    /// \brief Generic iterator for elements in class of class T which lie linearly in memory.
    /// \details This linear memory iterator template class is derived from CBaseIt.
    /// \tparam T                 The type of the element
    /// \tparam IS_CONST_ITERATOR Flag whether the iterator is constant or not.
    /// \tparam CONTAINER_TYPE    The type of the container
    /// \tparam STRIDE            The stride of the container
    /// \testmethod
    /// \traceability
#ifndef NDEBUG
    template <class T, boolean_t IS_CONST_ITERATOR, class CONTAINER_TYPE, sint32 STRIDE = 1>
    class CLinMemIt : public CBaseIt<T,IS_CONST_ITERATOR,CONTAINER_TYPE>
#else
    template <class T, boolean_t IS_CONST_ITERATOR, sint32 STRIDE = 1>
    class CLinMemIt : public CBaseIt<T,IS_CONST_ITERATOR>
#endif
    {
    public:
#ifndef NDEBUG
        typedef CLinMemIt<T,IS_CONST_ITERATOR,CONTAINER_TYPE,STRIDE> self;   ///< Abbreviation for the type of the class.
        typedef CLinMemIt<T,false            ,CONTAINER_TYPE,STRIDE> self_non_const; ///< Abbreviation for the type of the non-constant container class.
        typedef CBaseIt  <T,IS_CONST_ITERATOR,CONTAINER_TYPE>        super;  ///< Abbreviation for the type of the base class.
#else
        typedef CLinMemIt<T,IS_CONST_ITERATOR,STRIDE>                self;  ///< Abbreviation for the type of the class.
        typedef CLinMemIt<T,false            ,STRIDE>                self_non_const;  ///< Abbreviation for the type of the non-constant container class.
        typedef CBaseIt  <T,IS_CONST_ITERATOR>                       super;  ///< Abbreviation for the type of the base class.
#endif

        typedef          std::random_access_iterator_tag                 iterator_category;  
        typedef typename remove_const<typename super::value_type>::type* pointer;  ///< Alias name for the pointer to type of the base class.
        typedef typename add_const   <typename super::value_type>::type* const_pointer; ///< Alias name for the  pointer to constant type of the base class.
        typedef typename super::pointer                                  const_noconst_pointer; ///< Alias name for the  constant pointer to the type of the base class.
        typedef typename super::reference                                reference;  ///< Alias name for the  reference to the type of the base class.
        typedef typename super::difference_type                          difference_type; ///< Abbreviation for the integer type and it is used for storing the difference of two pointers.

        // Begin section needed only for TI compiler
        // PRQA S 2524 5
        // date: 2015-27-07, reviewer: Markus Friebertshaeuser,
        // reason: QAC Bug, since this using declaration is within the class scope.
        //         The according MISRA rule 7-3-6 states: "using-directives and using-declarations
        //         (EXCLUDING CLASS SCOPE OR FUNCTION SCOPE USING-DECLARATIONS) shall not be used in header files.
        using super::operator ->;
        // End section needed only for TI compiler
        
#ifndef NDEBUG
        /// \brief Empty constructor.
        /// \testmethod
        /// \traceability
        CLinMemIt () : super() {}

        /// \brief Explicit constructor.
        /// \details Explicit empty constructor with additional arguments for 
        /// initial memory position, static container for dynamic 
        /// boundary and container equality checking.These arguments are passed to the base class constructor in which Iterator object is initialized.
        /// \param[in]       _p            Pointer to initial memory position  
        /// \param[in]       _pContainer   Constant pointer to static container for dynamic 
        ///								   boundary and container equality checking
        /// \testmethod
        /// \traceability
        explicit CLinMemIt (
            const_noconst_pointer _p,           // initial memory position
            const CONTAINER_TYPE* _pContainer ) // static container for dynamic boundary and container equality checking
            : super( _p, _pContainer )
        {}

        /// \brief Explicit constructor 
        /// \details This constructor contains additional arguments for 
        /// initial memory position, static container for dynamic 
        /// boundary and container equality checking.These arguments are passed to the base class constructor in which Iterator object is initialized
        /// \param[in]       _p             Pointer to initial memory position  
        /// \param[in]       _pContainer    Constant pointer to static container for dynamic 
        ///								    boundary and container equality checking
        /// \testmethod
        /// \traceability
        explicit CLinMemIt (
            const_noconst_pointer _p,           // initial memory position
            const CONTAINER_TYPE* _pContainer,  // static container for dynamic boundary and container equality checking
            const_pointer,
            const_pointer )
            : super( _p, _pContainer )
        {}

        /// \brief Explicit constructor.
        /// \details This template constructor contains constant reference to an identical object "rhs" with possibily different container type (IS_CONST_ITERATOR2) as an argument.
        ///  Object "rhs" is passed as an argument to the base class constructor in which object initilization happens.
        /// \tparam IS_CONST_ITERATOR2 Flag whether the iterator is constant or not.
        /// \param[in]       rhs   Constant reference to identical iterator.
        /// \testmethod
        /// \traceability
        template<boolean_t IS_CONST_ITERATOR2>
        explicit CLinMemIt( const CBaseIt<T,IS_CONST_ITERATOR2,CONTAINER_TYPE>& rhs )
            : super(rhs)
        {}

        /// \brief copy constructor with constant reference to non-constant identical object.
        /// \details This constructor contains the object "rhs" as an argument which is passed to the base class constructor in which object initilization happens.
        /// \param[in]       rhs   Reference to the identical iterator. 
        /// \testmethod
        /// \traceability
        CLinMemIt( const self_non_const& rhs )
            : super( rhs.m_p, rhs.m_pContainer )
        {}

#else

        /// \brief Default empty constructor. 
        /// \testmethod
        /// \traceability
        CLinMemIt () {}

        /// \brief Explicit  constructor.with constant pointer to the non constant type.
        /// \details This constructor contains constant pointer to the non constant type(_p) as an argument which is passed to the base class constructor in which object initilization happens.
        /// \param[in]       _p   Pointer to initial memory position.
        /// \testmethod
        /// \traceability
        explicit CLinMemIt (const_noconst_pointer _p) // initial memory position
            : super( _p )
        {}

        /// \brief Explicit  constructor.
        /// \details This template constructor contains constant reference to an identical object "rhs" with possibily different container type (IS_CONST_ITERATOR2) as an argument.
        ///  Object "rhs" is passed as an argument to the base class constructor in which object initilization happens.
        /// \tparam IS_CONST_ITERATOR2 Flag whether the iterator is constant or not.
        /// \param[in]       rhs   Constant reference to identical iterator.
        /// \testmethod
        /// \traceability
        template<boolean_t IS_CONST_ITERATOR2>
        explicit CLinMemIt( const CBaseIt<T,IS_CONST_ITERATOR2>& rhs )
            : super(rhs)
        {}

        /// \brief copy constructor with constant reference to non-constant identical object.
        /// \details This constructor contains the object "rhs" as an argument which is passed to the base class constructor in which object initilization happens.
        /// \param[in]       rhs   Reference to identical iterator. 
        /// \testmethod
        /// \traceability
        CLinMemIt( const self_non_const& rhs )
            : super( rhs.m_p )
        {}
#endif

#ifndef NDEBUG
        template<class, boolean_t, class, sint32>
#else
        template<class, boolean_t, sint32>
#endif
        friend class CLinMemIt;

        /// \brief Returns the element at given position 'n*STRIDE '.
        /// \details  Index operator overloading function which returns a reference to the element.at position n*STRIDE.STRIDE is the template parameter of the CBaseit class.
        /// \attention position (n* STRIDE) should be within the container limits and Iterator should not be null.Otherwise behaviour is undefined.
        /// \param[in]   n   Constant reference to input position.  
        /// \return          Reference to the element at given position.
        /// \testmethod
        /// \traceability
        reference operator[](const difference_type& n) const
        {
            // assert that container is inside the bounds.
            assert ( (m_pContainer != 0)
                &&     (m_p          != 0)
                &&     (self(m_p + n * STRIDE, m_pContainer) >= m_pContainer->begin())
                &&     (self(m_p + n * STRIDE, m_pContainer) <  m_pContainer->end()  ) );
            return operator->()[n*STRIDE];
        }

        /// \brief Pre-increament operator loading function.
        /// \details Increments the member data pointer by STRIDE.Returns the reference to the calling object.
        /// \return          Reference to this pointer 
        /// \testmethod
        /// \traceability
        self& operator++()
        {
            m_p += STRIDE;
            return *this;
        }
        /// \brief Post-increment operator loading function.
        /// \details calling object is stored in a local object and then increments member data pointer and returns value of the calling object which is stored in local object.
        /// \return          Value of the calling object before incrementing
        /// \testmethod
        /// \traceability
        self operator++(difference_type)
        {
            self result(*this);
            ++(*this);
            return result;
        }

        /// \brief Pre-decrement operator loading function.
        /// \details Decrements the member data pointer by STRIDE and returns the reference to the calling object.
        /// \return          Reference to the calling object.
        /// \testmethod
        /// \traceability
        self& operator--()
        {
            m_p -= STRIDE;
            return *this;
        }

        /// \brief Post-decrement operator overloading function.
        /// \details calling object is stored in a local object and then decrements member data pointer and returns value of the calling object which is stored in local object before decrementing.
        /// \return          Value of the calling object before decrementing 
        /// \testmethod
        /// \traceability
        self operator--(difference_type)
        {
            self result(*this);
            --(*this);
            return result;
        }

        /// \brief Increments member data pointer by increment*STRIDE.
        /// \details This function increments member data pointer by (increment*STRIDE) and returns the reference to the calling object.
        /// \param[in]       increment   Constant reference to increment value.  
        /// \return          Reference to the calling object.
        /// \testmethod
        /// \traceability
        self& operator+=(const difference_type increment)
        {
            m_p += increment * STRIDE;
            return (*this);
        }

        /// \brief Decrements member data pointer by decrement*STRIDE.
        /// \details This function decrements member data pointer by (decrement*STRIDE) and returns the reference to the calling object.
        /// \param[in]       decrement   Constant reference to decrement value.  
        /// \return          Reference to the calling object.
        /// \testmethod
        /// \traceability
        self& operator-=(const difference_type decrement)
        {
            m_p -= decrement * STRIDE;
            return (*this);
        }

        /// \brief addition operator overloading function.
        /// \details Returns a new iterator whose member data pointer is
        /// incremented by n*STRIDE compared to current iterator.
        /// \param[in]    n  Constant reference to increment value  
        /// \return          A new iterator whose member data pointer is incremented
        /// 		         by n*STRIDE compared to current iterator.
        /// \testmethod
        /// \traceability
        self operator+(const difference_type& n) const
        {
            CLinMemIt result(*this);
            result += n;
            return result;
        }

        /// \brief substraction operator overloading function.
        /// \details Returns a new iterator whose member data pointer is
        /// decremented by n*STRIDE compared to current iterator.
        /// \param[in]    n  Constant reference to decrement value  
        /// \return          A new iterator whose member data pointer is decremented
        /// 			     by n*STRIDE compared to current iterator.
        /// \testmethod
        /// \traceability
        self operator-(const difference_type& n) const
        {
            CLinMemIt result(*this);
            result -= n;
            return result;
        }

        /// \brief  Returns difference between two iterators.
        /// \details Returns difference between two iterators giving the distance in memory.This function returns the return value of the function memory_distance() with argument "rhs" divided by STRIDE.
        /// \tparam IS_CONST_ITERATOR2 Flag whether the iterator is constant or not.
        /// \param[in]       rhs   Constant reference to identical iterator object  
        /// \return                Difference between two iterators giving the distance in memory. 
        /// \testmethod
        /// \traceability
        template<boolean_t IS_CONST_ITERATOR2>
#ifndef NDEBUG
        difference_type operator-(const CLinMemIt<T, IS_CONST_ITERATOR2, CONTAINER_TYPE, STRIDE>& rhs) const
#else
        difference_type operator-(const CLinMemIt<T, IS_CONST_ITERATOR2, STRIDE>& rhs) const
#endif
        {
            return memory_distance(rhs) / static_cast<difference_type>(STRIDE);
        }

        // PRQA S 2524 13
        // date: 2015-27-07, reviewer: Markus Friebertshaeuser,
        // reason: QAC Bug, since this using declaration is within the class scope.
        //         The according MISRA rule 7-3-6 states: "using-directives and using-declarations
        //         (EXCLUDING CLASS SCOPE OR FUNCTION SCOPE USING-DECLARATIONS) shall not be used in header files.

        // Begin section only needed for TI compiler
        using super::memory_distance;

    protected:
        using super::m_p;  ///< base class's pointer to the template type "T".

#ifndef NDEBUG
        using super::m_pContainer; ///< base class's pointer to container type.
#endif
        // End section only needed for TI compiler
    };

} //End of cml namespace

#endif //CML_STL_ITERATOR_H__

