#ifndef CML_STL_MEMORY_h__
#define CML_STL_MEMORY_h__

#include "cml_stl_type_traits.h"
#include "glob_type.h"
#include <cassert>

namespace cml
{
    /// \brief template class for smart pointer.
    /// \details Makes a c++-language pointer smarter by checking the validity of the memory
    ///  pointed to in debug mode. No performance drawback in release mode, though.
    /// \tparam T       The type of the value
    /// \testmethod
    /// \traceability
    template < typename T >
    class checked_ptr
    {
    private:
        /// \brief Own type with const data type.
        /// \details It appends constant qualifier to the type "T".Will be used to compare a pointer to it's const version.
        /// @see operator==()
        /// @see operator!=()
        typedef checked_ptr<typename add_const<T>::type> const_self;

        /// \brief Own type with non const data type.
        /// \details It removes the constant qualifier from the type "T".It Will be used to compare us to our non-const version and to copy-construct us from our non-const version.
        /// @see operator==()
        /// @see operator!=()
        /// @see checked_ptr(const non_const_self&)
        typedef checked_ptr<typename remove_const<T>::type> non_const_self;

    public:
        typedef T           value_type;  ///< Alias name for the class template element.
        typedef value_type* pointer;  ///< Alias name for the pointer to the value_type.
        typedef value_type& reference;  ///< Alias name for the reference to the value_type.

        /// \brief Default empty constructor
        /// \testmethod
        /// \traceability
        checked_ptr ()
#ifndef NDEBUG
            : m_p(NULL)
#endif
        {}
                
        /// \brief Explicit one element constructor.
        /// \details It takes pointer "_p" as an argument and assigned to m_p which is a pointer and protected member of this class.
        /// \param[in] _p    Pointer to init value
        /// \testmethod
        /// \traceability
        explicit checked_ptr (pointer _p)
            : m_p( _p )
        {}
                
        /// \brief Copy constructor for non-const to const checked_ptr.
        /// \details It takes constant reference to an object "rhs" as an argument and initializes the pointer (m_p) which is protected data member of this class.
        /// \param[in] rhs : Reference to identical value
        /// \testmethod
        /// \traceability
        checked_ptr( const non_const_self& rhs )
            : m_p( rhs.m_p )
        {}

        /// const and non-const checked_ptr must be friends
        template<typename>
        friend class checked_ptr;
        
        /// \brief assignment operator overloading function.
        /// \details Copies the input pointer to the pointer(protected data member) of the calling object.
        /// \param[in] p  Constant pointer to the input value
        /// \return       None
        /// \testmethod
        /// \traceability
        void operator= ( const pointer& p )
        {
            m_p = p;
        }
                
        /// \brief Dereferencing of the checked pointer objects.
        /// \details This function returns the pointer which is the protected data member of the object.
        /// \return             Pointer to the checked pointer objects.
        /// \testmethod
        /// \traceability
        pointer operator->() const
        {
            assert ( m_p != NULL );
            return m_p;
        }

        /// \brief Indirection of the checked pointer objects.
        /// \details This function returns the reference to the element pointed to by checked pointer object.
        /// \return             Reference to the checked pointer objects. 
        /// \testmethod
        /// \traceability
        reference operator*() const
        {
            return *(operator->());
        }
        
        /// \brief Returns comparison result of two checked pointer objects.
        /// \details This function takes  constant reference to the object  "rhs" which points to constant element type.
        ///  This function returns True, if both object references are same, else False.
        /// \param[in]    rhs  Constant reference to identical pointer object.
        /// \return            True, if both object references are same, else False.
        /// \testmethod
        /// \traceability
        boolean_t operator== (const const_self& rhs) const
        {
            return m_p == rhs.m_p;
        }

        /// \brief Returns comparison result of two checked pointer objects.
        /// \details This function takes  constant reference to the object "rhs" which points to non constant element type.
        ///  This function returns True, if both object references are same, else False.
        /// \param[in]    rhs  Constant reference to identical pointer object.		
        /// \return            True, if both object references are same, else False.
        /// \testmethod
        /// \traceability
        boolean_t operator== (const non_const_self& rhs) const
        {
            return m_p == rhs.m_p;
        }

        /// \brief Returns comparison result of two checked pointer objects.
        /// \details This function takes  constant reference to the object "rhs" which points to constant element type.
        ///  This function returns True, if both object references are not same, else False.
        /// \param[in]    rhs  Constant reference to identical pointer object.
        /// \return            True, if both object references are not same, else False.
        /// \testmethod
        /// \traceability
        boolean_t operator!= (const const_self& rhs) const
        {
            return m_p != rhs.m_p;
        }

        /// \brief Returns comparison result of two checked pointer objects.
        /// \details This function takes  constant reference to the object "rhs" which points to non constant element type.
        /// This function returns True, if both object references are not same, else False.
        /// \param[in]    rhs  Constant reference to identical pointer object.
        /// \return            True, if both object references are not same, else False.
        /// \testmethod
        /// \traceability
        boolean_t operator!= (const non_const_self& rhs) const
        {
            return m_p != rhs.m_p;
        }


    protected:
        pointer m_p; ///< pointer to the value type."T" of the template parameter.
    }; //End of cml namespace
}

#endif // CML_STL_MEMORY_h__
