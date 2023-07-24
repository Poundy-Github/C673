/*! \file **********************************************************************

COMPANY:                   Continental AG, A.D.C. GmbH

CPU:                       CPU-Independent

COMPONENT:                 CML (Common Math Library)

MODULNAME:                 cml_stl_list.h

DESCRIPTION:               STL like container list

AUTHOR:                    Stefan Zechner

CREATION DATE:             20.09.2013

VERSION:                   $Revision: 1.22 $

**************************************************************************** */

#ifndef CML_STL_LIST_H__
#define CML_STL_LIST_H__

#include "cml_stl_vector.h"
#include "cml_stl_array.h"
#include "cml_stl_iterator.h"

namespace cml
{

    /// \brief ListNode is the base element of the double linked list.
    /// \details ListNode is a structure with below data members:\n
    ///  "data": This holds the data in a node of a linkedlist.\n
    ///  "itPrev": Iterator to previous node in the linkedlist \n
    ///  "itNext": Iterator to next node in the linkedlist \n
    /// \tparam T                 The type of the elements
    /// \tparam CONTAINER_SIZE    The size of the container
    /// \testmethod
    /// \traceability
    
#ifndef NDEBUG
    template <class T, sint32 CONTAINER_SIZE>
#else
    template <class T>
#endif
    struct ListNode
    {
#ifndef NDEBUG
        typedef ListNode< T, CONTAINER_SIZE >                          self;  ///< Abbreviation for the type of the structure.
        typedef CBaseIt < self, false, CArray< self, CONTAINER_SIZE> > iterator; ///< Alias name for the base iterator for the container array of ListNodes and size of CONTAINER_SIZE.
#else
        typedef ListNode< T >           self;   ///< Abbreviation for the type of the structure.
        typedef CBaseIt < self, false > iterator;   ///< Alias name for the base iterator for the container array of ListNodes and size of CONTAINER_SIZE.
#endif

        typedef typename remove_const<T>::type value_type;  ///< Alias name for the type(non constant) of the ListNode structure element.

        value_type data;  ///< data is of value_type(non constant) of the ListNode structure.

        iterator itPrev;  ///< Iterator to the previous node.
        iterator itNext;  ///< Iterator to the next node.
    };

    // Forward declaration the container class CList
    template <class T, sint32 SIZE>
    class CList;

    /// \brief CBidirectionalIt is the bi-directional iterator to the double linked list
    /// \details Bi-directional iterator can traverse the double liked list in both the directions.
    /// \tparam T                     The type of the elements
    /// \tparam IS_CONST_ITERATOR     Flag whether the iterator is of constant type (true) 
    ///                               or non constant (false).
    ///                               Default is false, meaning non constant.
    /// \tparam CONTAINER_TYPE        The type of the container
    /// \testmethod
    /// \traceability

#ifndef NDEBUG
    template <class T, boolean_t IS_CONST_ITERATOR, class CONTAINER_TYPE>
#else
    template <class T, boolean_t IS_CONST_ITERATOR>
#endif
    class CBidirectionalIt
    {
    public:

#ifndef NDEBUG
        typedef CBidirectionalIt < T             , IS_CONST_ITERATOR, CONTAINER_TYPE > self;  ///< Abbreviation for the type of the class.
        typedef CBidirectionalIt < T             , false            , CONTAINER_TYPE > self_non_const; ///< Abbreviation for the non-constant iterator type of the class.
        typedef ListNode         < T             , CONTAINER_TYPE::MAX_SIZE          > list_node_type; ///< Abbreviation for the ListNode with size of maximum size of the container type.
        typedef CBaseIt          < list_node_type, IS_CONST_ITERATOR, CONTAINER_TYPE > list_node_iterator; ///< Abbreviation for the iterator of list node type.
#else
        typedef CBidirectionalIt < T             , IS_CONST_ITERATOR > self;   ///< Abbreviation for the type of the class.
        typedef CBidirectionalIt < T             , false             > self_non_const;  ///< Abbreviation for the non-constant iterator type of the class.
        typedef ListNode         < T                                 > list_node_type;  ///< Abbreviation for the ListNode with size of maximum size of the container type.
        typedef CBaseIt          < list_node_type, IS_CONST_ITERATOR > list_node_iterator;  ///< Abbreviation for the iterator of list node type.
#endif

        typedef typename conditional<IS_CONST_ITERATOR, typename add_const<T>::type, T>::type value_type; ///< value_type is constant type or non-constant type basd on the Iterator is is constant or non-constant.
        typedef value_type* pointer; ///< Abbreviation for the pointer to the value_type.
        typedef value_type& reference;  ///< Abbreviation for the reference to the value_type.

        typedef int difference_type;  ///< Abbreviation for the integer type and it is used for storing the difference of two pointers.

        typedef std::bidirectional_iterator_tag iterator_category;

        /// The const variant needs access to non-const protected member data
        /// Hence, allow self_const access to us
        /// Theoretically, this should be a specialized template to <T,true>, but TI-compiler does not understand
#ifndef NDEBUG
        template<class T2, boolean_t IS_CONST_ITERATOR_2, class CONTAINER_TYPE_2>
#else
        template<class T2, boolean_t IS_CONST_ITERATOR_2>
#endif
        friend class cml::CBidirectionalIt;

        /// The class CList needs to be able to access the node directly
        template<class, sint32>
        friend class CList;

        /// \brief Default empty constructor
        /// \testmethod
        /// \traceability
        CBidirectionalIt () {}

        /// \brief Constructor with reference to an iterator.
        /// \details This function takes "_rhs" which is a constant reference and is used to initialize the data member "m_itNode" of the present class.
        /// \param[in] _rhs    Constant reference to identical iterator.
        /// \testmethod
        /// \traceability
        CBidirectionalIt ( const self_non_const&     _rhs    ) : m_itNode(_rhs.m_itNode) {}

        /// \brief Template constructor with reference to an iterator.
        /// \details This template constructor initializes the data member "m_itNode" with the constant reference to the base iterator CBaseIt.
        /// \tparam    IS_CONST_ITERATOR_2   Flag whether the iterator is of constant type (true) 
        ///                                  or non constant (false).
        ///                                  Default is false, meaning non constant.
        /// \param[in] _itNode               Constant reference to base iterator
        /// \testmethod
        /// \traceability
        template<boolean_t IS_CONST_ITERATOR_2>
#ifndef NDEBUG
        CBidirectionalIt ( const CBaseIt< list_node_type, IS_CONST_ITERATOR_2, CONTAINER_TYPE >& _itNode )
#else
        CBidirectionalIt ( const CBaseIt< list_node_type, IS_CONST_ITERATOR_2                 >& _itNode )
#endif
            : m_itNode(_itNode) {}

        /// \brief Indirection of the element.
        /// \details This function returns the reference to the data of the node in the linked list.
        /// \return             Reference to the element.
        /// \testmethod
        /// \traceability
        reference operator*() const
        {
            return m_itNode->data;
        }

        /// \brief Dereferencing of the element.
        /// \details This function returns pointer to the element.
        /// \return             Pointer to the element.
        /// \testmethod
        /// \traceability
        pointer operator->() const 
        {
            return &operator*();
        }

        /// \brief Increments member data pointer to next element(pre-increment).
        /// \details This function Increments member data pointer of the calling object to next element(pre-increment) and returns the reference to the calling object.
        /// \return             Returns the reference to the calling object.
        /// \testmethod
        /// \traceability
        self& operator++()
        {
            m_itNode = m_itNode->itNext;
            return *this;
        }

        /// \brief Increments member data pointer to next element(post-increment).
        /// \details calling object is stored in a local object and then increments member data pointer of the calling object to next element and returns the calling object which is stored in local object.
        /// \return             Returns the calling object before incrementing.
        /// \testmethod
        /// \traceability
        self operator++(difference_type)
        {
            self result(*this);
            m_itNode = m_itNode->itNext;
            return result;
        }

        /// \brief Decrements member data pointer to previous element(pre-decrement).
        /// \details This function Decrements member data pointer of the calling object to previous element(pre-decrement) and returns the reference to the calling object.
        /// \return             Returns  the calling object.
        /// \testmethod
        /// \traceability
        self& operator--()
        {
            m_itNode = m_itNode->itPrev;
            return *this;
        }

        /// \brief Decrements member data pointer to previous element(post-decrement).
        /// \details calling object is stored in a local object and then decrements member data pointer of the calling object to previous element and returns the calling object which is stored in local object.
        /// \return             Returns  the calling object.
        /// \testmethod
        /// \traceability
        self operator--(difference_type)
        {
            self result(*this);
            m_itNode = m_itNode->itPrev;
            return result;
        }

        /// \brief Returns comparison result of two list objects.
        /// \details this function compares the calling object list and the list "rhs" for equality and returns True, if both list objects are  same reference else False.
        /// \param[in]    rhs   Constant reference to identical iterator.		
        /// \return             True, if both list objects are same reference else False.
        /// \testmethod
        /// \traceability
        boolean_t operator== (const self& rhs) const
        {
            return m_itNode.operator==(rhs.m_itNode);
        }

        /// \brief Returns comparison result of list objects.
        /// \details this function compares the calling object list and the list "rhs" for inequality and returns True, if both list objects are not same reference else False.
        /// \param[in]    rhs   Constant reference to identical iterator.		
        /// \return             True, if both list objects are not same reference else False.
        /// \testmethod
        /// \traceability
        boolean_t operator!= (const self& rhs) const
        {
            return m_itNode.operator!=(rhs.m_itNode);
        }

    protected:
        list_node_iterator m_itNode; ///< m_itNode is of type CBaseIt template whose type is of list_node_type.
    };


    /// \brief The container class CList.
    /// \tparam T       The type of the elements
    /// \tparam SIZE    The size of the container
    /// \testmethod
    /// \traceability
    template <class T, sint32 SIZE>
    class CList
    {
    public:

        enum { MAX_SIZE = SIZE   ///< the number of elements the container can store.
             };  
                
        enum { CAPACITY = SIZE+1  ///< the number of elements the container has reserved internally.
             };  

        typedef sint32 size_type;

        typedef typename remove_const<T>::type  type;    ///< Alias name for the type of the List elements.
        typedef typename    add_const<T>::type  const_type;  ///< Alias name for the type(non constant) of the List elements.
        typedef typename remove_const<T>::type& reference;  ///< Alias name for the reference of the List element. 
        typedef typename    add_const<T>::type& const_reference;  ///< Alias name for the constant reference of the List element. 
        typedef typename remove_const<T>::type* pointer;  ///< Alias name for the pointer to the List element. 
        typedef typename    add_const<T>::type* const_pointer;  ///< Alias name for the constant pointer to the List element. 

        typedef int difference_type;  ///< Abbreviation for the integer type and it is used for storing the difference of two pointers.

        // iterator typedefs
#ifndef NDEBUG
        typedef CBidirectionalIt <type, false, CArray<ListNode<type, CAPACITY>, CAPACITY> >  it; ///< Alias name for the bidirectional iterator to the array of ListNode.
        typedef CBidirectionalIt <type, true , CArray<ListNode<type, CAPACITY>, CAPACITY> > cIt; ///< Alias name for the constant bidirectional iterator to the array of ListNode.
#else
        typedef CBidirectionalIt <type, false>  it;   ///< Alias name for the bidirectional iterator to the array of ListNode.
        typedef CBidirectionalIt <type, true > cIt;   ///< Alias name for the constant bidirectional iterator to the array of ListNode.
#endif
        typedef it  iterator;   ///< bidirectional iterator type.
        typedef cIt const_iterator;  ///< constant bidirectional iterator type.

        /// \brief Default constructor which puts all nodes into the idle list.
        /// \details this function calls another function clear() which puts all nodes into the idle list.
        /// \testmethod
        /// \traceability
        CList ()
        {
            clear();
        }

        /// \brief Copy constructor with consatnt reference to an iterator as an argument , copies rhs to the calling object.
        /// \details this function calls assignment operator overloading function with argument "rhs", which copies rhs to the calling object.
        /// \param[in] rhs    Constant reference to identical iterator
        /// \testmethod
        /// \traceability
        explicit CList( const CList& rhs )
        {
            operator=(rhs);
        }

        /// \brief Assignement operator overloading function which makes a copy of the data.
        /// \details This function first clears the calling list object and then copies all the elements of the list "rhs" 
        /// into the calling object list with push_back() function.
        /// This function returns Reference to the calling object.
        /// \attention This is a quite expensive operation for this container because
        /// full regeneration of the list is required
        /// \param[in] rhs      Constant reference to identical iterator.		
        /// \return             Reference to the calling object.
        /// \testmethod
        /// \traceability
        CList& operator=(const CList& rhs)
        {
            clear();
            for (const_iterator iter = rhs.begin(); iter.operator !=(rhs.end()); ++iter)
            {
                push_back(*iter);
            }
            return *this;
        }

        /// \brief clears the list
        /// \details This function set's all Next and Prev Pointers to begin address, and puts them in idle mode.	
        /// \return             void.
        /// \testmethod
        /// \traceability
        void clear()
        {
            // the first node is reserved as the end of the linked list (in order to avoid a lot of checks whether previous or next node exist)
            m_listNodes[0].itNext = m_listNodes.begin();
            m_listNodes[0].itPrev = m_listNodes.begin();

            // put all nodes into the idle list
            m_idleListNodes.clear();
            for (typename ListNodeArray::iterator iter = m_listNodes.begin()+1; iter.operator!=(m_listNodes.end()); ++iter)
            {
                m_idleListNodes.push_back(iter);
            }
        }

        /// \brief Returns size of the ListNode.
        /// \details This function returns the difference of SIZE and the size of idle list node.
        /// \attention size should be greater than idle list node size.
        /// \return             Returns size of ListNode.
        /// \testmethod
        /// \traceability
        size_type size() const
        {
            assert (SIZE >= m_idleListNodes.size());
            return (SIZE - m_idleListNodes.size());
        }

        /// \brief Checks if list is empty.
        /// \details This function checks for the equality of the first and last iterators and returns true if they are equal else false.
        /// \return             Returns True if list is empty, else False.
        /// \testmethod
        /// \traceability
        boolean_t empty() const
        {
            return begin().operator==(end());
        }

        /// \brief Checks if ListNodes array is full.
        /// \details If idle list node is empty then list node is considered full.This function true if If idle list node is empty else false.
        /// \return             Returns True if list is full, else False.
        /// \testmethod
        /// \traceability
        boolean_t full() const
        {
            return (m_idleListNodes.empty());
        }

        /// \brief Returns reference to the first element of the list.
        /// \details This function calls begin() to get the iterator to the first element and dereferences it to get the first element.
        /// \return             Reference to first element of the list.
        /// \testmethod
        /// \traceability
        reference front()
        {
            return *begin();
        }

        /// \brief Returns constant reference to first element of the list.
        /// \details This function calls begin() to get the iterator to the first element and dereferences it to get the first element.
        /// \return             Constant reference to first element of the list.
        /// \testmethod
        /// \traceability
        const_reference front() const
        {
            return *begin();
        }

        /// \brief Returns reference to last element of the list.
        /// \details This function calls end() function , decrements the returned iterator and dereferences it to get the last element.
        /// \return             Reference to last element of the list.
        /// \testmethod
        /// \traceability
        reference back()
        {
            return *(--end());
        }

        /// \brief Returns constant reference to last element of the list.
        /// \details This function calls end() function , decrements the returned iterator and dereferences it to get the last element.
        /// \return             Constant reference to last element of the list.
        /// \testmethod
        /// \traceability
        const_reference back() const
        {
            return *(--end());
        }

        /// \brief Sets reference to input element and inserts element at first position.
        /// \details This function calls another function push_front() which returns reference to the element to be inserted in the list.
        /// \param[in]    x     Constant reference to input element.
        /// \return             None
        /// \testmethod
        /// \traceability
        void push_front(const_reference x)
        {
            push_front() = x;
        }

        /// \brief Inserts element at first position of array and returns reference to it.
        /// \details This function dereferences the return value of inset() function with iterator to the first element as an argument.
        /// This function returns reference to the element inserted.
        /// \return             Reference to element inserted.
        /// \testmethod
        /// \traceability
        reference push_front()
        {
            return *insert(begin());
        }

        /// \brief Sets reference to input element and inserts element at last position.
        /// \details This function calls another function push_back() which returns reference to the element to be inserted in the list.
        /// \param[in]   x      Constant reference to input element.
        /// \return             void
        /// \testmethod
        /// \traceability
        void push_back(const_reference x)
        {
            push_back() = x;
        }

        /// \brief Inserts element at last position and returns reference of last element.
        /// \details This function dereferences the return value of inset() function with iterator to the one past last element as an argument.
        /// \return             Reference to element inserted.
        /// \testmethod
        /// \traceability
        reference push_back()
        {
            return *insert(end());
        }

        /// \brief Erases the first element.
        /// \details This function calls erase() function with iterator to the first element as an argument.
        /// \return             void
        /// \testmethod
        /// \traceability
        void pop_front()
        {
            erase(begin());
        }

        /// \brief Erases the last element.
        /// \details This function calls erase() with iterator to the last element as an argument.
        /// \return             void
        /// \testmethod
        /// \traceability
        void pop_back()
        {
            erase(--end());
        }

        /// \brief Inserts new element at position with input value.
        /// \details This function calls another variant of insert() function which creates and inserts a node at given position.Then it copies the input value to the new node.
        /// \param[in]  position  Position of the element
        /// \param[in]  x         Constant reference to the element
        /// \return               Returns new iterator
        /// \testmethod
        /// \traceability
        iterator insert(iterator position, const_reference x)
        {
            iterator itNewNode = insert(position);
            *itNewNode = x;
            return itNewNode;
        }

        /// \brief Inserts new Node at given position. 
        /// \details This function  inserts a new node at the given position.Returns the iterator to the new node.
        /// \attention size of idle list node should be greater than 0.
        /// \param[in]  position  Position of the element
        /// \return               Returns new iterator
        /// \testmethod
        /// \traceability
        iterator insert(iterator position)
        {
            assert (m_idleListNodes.size() > 0);

            typename ListNodeArray::iterator::super itNewNode = m_idleListNodes.back();
            m_idleListNodes.pop_back();

            itNewNode->itPrev = position.m_itNode->itPrev;
            itNewNode->itNext = position.m_itNode;

            itNewNode->itPrev->itNext = itNewNode;
            itNewNode->itNext->itPrev = itNewNode;

            return iterator(itNewNode);
        }

        /// \brief Erases iterator at position.
        /// \details This function erases a node at the given position.
        /// \attention position must be within the range.
        /// \param[in]  position  Position of the element
        /// \return               Returns new iterator
        /// \testmethod
        /// \traceability
        iterator erase(iterator position)
        {
            assert(position != end());

            position.m_itNode->itPrev->itNext = position.m_itNode->itNext;
            position.m_itNode->itNext->itPrev = position.m_itNode->itPrev;
            m_idleListNodes.push_back(position.m_itNode);

            return (iterator(position.m_itNode->itNext));
        }

        /// \brief Erases elements from first to last.
        /// \details This function erases all the elements in the list and returns an iterator to the last.
        /// \param[in]  first  Iterator to the first element
        /// \param[in]  last   Iterator to the last element
        /// \return            Returns iterator to last
        /// \testmethod
        /// \traceability
        iterator erase(iterator first, iterator last)
        {
            while (first.operator!=(last))
            {
                first = erase(first);
            }
            return last;
        }

        /// \brief Returns an iterator to the beginning of the list.
        /// \return            Iterator to the beginning of the list
        /// \testmethod
        /// \traceability
        iterator begin()
        {
            return iterator(m_listNodes[0].itNext);
        }

        /// \brief Returns a constant iterator to the beginning of the list.
        /// \return            Constant iterator to the beginning of the list
        /// \testmethod
        /// \traceability
        const_iterator begin() const
        {
            return const_iterator(m_listNodes[0].itNext);
        }

        /// \brief Returns an iterator to the position after the end of the list.
        /// \return            Iterator to the position after the end of the list
        /// \testmethod
        /// \traceability
        iterator end()
        {
            return iterator(m_listNodes.begin());
        }

        /// \brief Returns a constant iterator to the position after the end of the list.
        /// \return            Constant iterator to the position after the end of the list
        /// \testmethod
        /// \traceability
        const_iterator end() const
        {
            return const_iterator(m_listNodes.begin());
        }

    protected:

#ifndef NDEBUG
        typedef CArray<ListNode<type, CAPACITY>, CAPACITY> ListNodeArray;   ///< Alias name for the array of ListNode.
#else
        typedef CArray<ListNode<type>, CAPACITY> ListNodeArray;   ///< Alias name for the array of ListNode.
#endif
        typedef CVector<typename ListNodeArray::iterator::super, SIZE> IdleListNodeVector;  ///< Alias name for the vector of iterators to the ListNode.

        ListNodeArray      m_listNodes;   ///< Type of the list node array.
        IdleListNodeVector m_idleListNodes;   ///< Type of the IdleListNodeVector.

    };
}

#endif //CML_STL_LIST_H__
