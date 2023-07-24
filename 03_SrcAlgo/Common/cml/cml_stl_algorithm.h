/*! \file **********************************************************************

COMPANY:                   Continental AG, A.D.C. GmbH

CPU:                       CPU-Independent

COMPONENT:                 CML (Common Math Library)

MODULNAME:                 cml_stl_algorithm.h

DESCRIPTION:               STL like algorithms

AUTHOR:                    Stefan Zechner

CREATION DATE:             16.10.2013

VERSION:                   $Revision: 1.20 $

**************************************************************************** */

#ifndef cml_stl_algorithm_h__
#define cml_stl_algorithm_h__

#include <algorithm>

#include "cml_stl_vector.h"

namespace cml
{
    /// \brief Partially sorts the Array of elements.
    /// \details Partially sort the Array of elements, of any type in the
    /// range based on the Pivot element(nth).
    /// Rearrange the elements in the range [first,last), in such 
    /// a way that the element at the nth position is the element 
    /// that would be in that position in a sorted sequence. 
    /// The other elements are left without any specific order, 
    /// except that none of the elements preceding nth are greater 
    /// than it, and none of the elements following it are less.\n
    /// 1) If last <=first ,then sorting is not required,so return from the function.\n
    /// 2) If last == first + 1,then only two elements to be sorted and swap the elemets and return from the function.\n
    /// 3) Calculate middle position from the first and last positions.sort the first,middle and last elements suchthat low element comes at middle.
    ///    swap the low element which is at middle now into position first+1.\n
    /// 4) Consider element at first position as pivot element.Sort the remaining array such that all the elements left to middle are less than pivot element
    ///    and all the right side elements are greater than the pivot element.\n
    /// 5) If nth element position is less than middle position then repeat the above steps from 1 to 5 for the sub array from first to middle position.
    ///    If nth element position is greater than the middle position then repeat the above steps from 1 to 5 for the sub array from middle+1 to last position.\n
    /// \tparam          RandomAccessIterator  Random access iterator to the element array
    /// \param[in,out]   first   Iterator to the start address of Array of elements 
    /// \param[in]       nth     Iterator to nth element to be identified in the Array  
    /// \param[in]       last    Iterator to the end of the Array(points to the element 
    ///                          after the last element of the Array) 
    /// \return          None 
    /// \testmethod
    /// \traceability
    template <class RandomAccessIterator>
    inline static void nth_element (RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last)
    {
        --last;
        for (;;)
        {
            if (last <= first)
            {
                /* One element only */
                return;
            }

            if (last == first + 1)
            {
                /* Two elements only */
                if (*first > *last)
                {
                    std::swap(*first, *last);
                }
                return;
            }

            /* Find median of low, middle and high items; swap into position low */
            RandomAccessIterator middle = first + (last - first) / 2;
            if (*middle > *last)    std::swap(*middle, *last);
            if (*first  > *last)    std::swap(*first,  *last);
            if (*middle > *first)   std::swap(*middle, *first);

            /* Swap low item (now in position middle) into position (low+1) */
            std::swap(*middle, *(first+1));

            /* Nibble from each end towards middle, swapping items when stuck */
            RandomAccessIterator ll = first + 1;
            RandomAccessIterator hh = last;
            for (;;)
            {
                do ll++; while (*first > *ll);
                do hh--; while (*hh    > *first);

                if (hh < ll)
                {
                    break;
                }

                std::swap(*ll, *hh);
            }

            /* Swap middle item (in position low) back into correct position */
            std::swap(*first, *hh);

            /* Re-set active partition */
            if (hh <= nth)
            {
                first = ll;
            }
            if (hh >= nth)
            {
                last = hh - 1;
            }
        }
    }
    
    /// \brief Finds out the middle element in an array of elements of any type.
    /// \details Returns element in the middle of the first and last iterators of the array as if the
    /// array of elements is sorted in ascending order.
    /// If n is Even -> (n/2)th element
    /// If n is Odd  -> (n/2 + 1)th element
    /// This function calls nth_element()  with nth element as the middle of the first and last elements of the array.
    /// \attention  argument "last" must be greater than "first".
    /// \tparam          RandomAccessIterator  Random access iterator to the element array
    /// \param[in]       first   Iterator to the start address of Array of elements 
    /// \param[in]       last    Iterator to the end of the Array(points to the element 
    ///							 after the last element of the Array)   
    /// \return          Element in the middle of first and last
    /// \testmethod
    /// \traceability
    template <class RandomAccessIterator>
    inline static typename RandomAccessIterator::value_type median (RandomAccessIterator first, RandomAccessIterator last)
    {
        assert(last - first > 0);

        RandomAccessIterator nth = first + (last - first - 1) / 2;
        nth_element(first, nth, last);

        return *nth;
    }
               
    /// \brief Partition sort the sub array elements in the range in ascending order.
    /// \details Partitions the sub-array based on the pivot element whose index is passed as an argument.Elements present in ping buffer will be sorted and placed into pong buffer.\n
    ///  Elements of ping buffer which are less than pivot element will be copied to pong buffer starting from the left position towards middle.\n
    ///  Elements which are greater than the pivotelement will be copied to pong buffer starting from the right position towards middle.\n
    ///  Finally pivot element will be placed at it's correct position (i.e it's position when the array sorted in ascending order) in both ping and pong buffers.\n
    ///  This function returns the new position of the pivotelement.
    /// \tparam          RandomAccessIterator  Random access iterator to the element array
    /// \param[out]      _pong       Partition sorted sub array of elements 
    /// \param[in]       _ping       Input subarray to be partition sorted
    /// \param[in]       left        Left Index of the current partition
    /// \param[in]       right       Right Index of the current partition
    /// \param[in]       pivotIndex  Index of the current pivot element
    /// \return          New pivot index after partitioning
    /// \testmethod
    /// \traceability
    template <class RandomAccessIterator>
    static sint32 _sort_TiOpt_partition (RandomAccessIterator _ping, RandomAccessIterator _pong, sint32 left, sint32 right, sint32 pivotIndex)
    {
#if defined(CML_USE_INTRINSICS) && defined(NDEBUG)
        typename RandomAccessIterator::value_type* restrict ping = &_ping[0];
        typename RandomAccessIterator::value_type* restrict pong = &_pong[0];
#else
        RandomAccessIterator ping = _ping;
        RandomAccessIterator pong = _pong;
#endif

        sint32 storeIndex = left;
        sint32 rightIndex = right;
        const typename RandomAccessIterator::value_type pivotValue = ping[pivotIndex];

        ping[pivotIndex] = ping[right];

        // This loop should be perfectly optimized by TI software pipelining. 
        // Check that the restrict keyword is properly set on ping and pong buffers. */
        for (sint32 i=left; i<right; i++)
        {
            if (ping[i] < pivotValue)
            {
                pong[storeIndex++] = ping[i];
            }
            else
            {
                pong[rightIndex--] = ping[i];
            }
        }

        // Copy pivotValue back into the ping and pong buffer (must be in both because it is excluded in next recursion)
        pong[storeIndex] = pivotValue;
        ping[storeIndex] = pivotValue;

        return storeIndex;
    }
     
    /// \brief Partition sort the sub array elements in the range in ascending/descending order.
    /// \details Partition sort the sub array elements in the range in  
    ///  ascending/descending order based on the given comparison function object "comp".
    ///  Partitions the sub-array based on the pivot element whose index is passed as an argument.Elements present in ping buffer will be sorted and placed into pong buffer.\n
    ///  Elements of ping buffer which are less/greater than pivot element will be copied to pong buffer starting from the left position towards middle.\n
    ///  Elements which are greater/less than the pivotelement will be copied to pong buffer starting from the right position towards middle.\n
    ///  Finally pivot element will be placed at it's correct position (i.e it's position when the array is sorted in ascending/descending order) in both ping and pong buffers.\n
    ///  This function returns the new position of the pivotelement.
    /// \tparam          RandomAccessIterator  Random access iterator to the element array
    /// \tparam          Compare               Compare function object
    /// \param[out]      _pong        Partition sorted sub array of elements 
    /// \param[in]       _ping        Input subarray to be partition sorted
    /// \param[in]       left         Left Index of the current partition
    /// \param[in]       right        Right Index of the current partition
    /// \param[in]       pivotIndex   Index of the current pivot element 
    /// \param[in]       comp         Compare function object to dynamically change the sorting direction.If "comp" is "less/greater",then array will be sorted in "ascending/decending" order.
    /// \return          New pivot index after partitioning
    /// \testmethod
    /// \traceability
    template <class RandomAccessIterator, class Compare>
    static sint32 _sort_TiOpt_partition (RandomAccessIterator _ping, RandomAccessIterator _pong, sint32 left, sint32 right, sint32 pivotIndex, Compare comp)
    {
#if defined(CML_USE_INTRINSICS) && defined(NDEBUG)
        typename RandomAccessIterator::value_type* restrict ping = &_ping[0];
        typename RandomAccessIterator::value_type* restrict pong = &_pong[0];
#else
        RandomAccessIterator ping = _ping;
        RandomAccessIterator pong = _pong;
#endif

        sint32 storeIndex = left;
        sint32 rightIndex = right;
        const typename RandomAccessIterator::value_type pivotValue = ping[pivotIndex];

        ping[pivotIndex] = ping[right];

        // This loop should be perfectly optimized by TI software pipelining. 
        // Check that the restrict keyword is properly set on ping and pong buffers. */
        for (sint32 i=left; i<right; i++)
        {
            if (comp(ping[i], pivotValue))
            {
                pong[storeIndex++] = ping[i];
            }
            else
            {
                pong[rightIndex--] = ping[i];
            }
        }

        // Copy pivotValue back into the ping and pong buffer (must be in both because it is excluded in next recursion)
        pong[storeIndex] = pivotValue;
        ping[storeIndex] = pivotValue;

        return storeIndex;
    }

    /// \brief Iteration sort the sub array elements in ascending order.
    /// \details Iteration sort the sub array elements in the range in ascending order using recursive partition sort. 
    /// This function will be called recursively to sort the left and right sub-arrays of the pivotelement.\n
    /// When right index is greater than the left index:\n
    /// 1) It calculates new pivot element "pivotIndex" as (right+left)/2.\n
    /// 2) It calls the function _sort_TiOpt_partition() ,which partially sorts the arry and places the pivot element at correct position and returns the new index (pivotNewIndex) of  pivot element.\n
    /// 3) It make a recursive call with array limits as first,pivotNewIndex-1 and pivot element index "first" as arguments.This will sort all the sub-array elements which are less than the pivot element in ascending order.\n
    /// 4) It make a recursive call with array limits as pivotNewIndex + 1, right and pivot element index "right" as arguments.This will sort all the sub-array elements which are greater than the pivot element in ascending order.\n
    /// When right <= left and depth is 1 :\n
    /// Only one element(pivotelement) will remains and it will be copied to pong buffer at pivotelement index.\n
    /// \tparam          RandomAccessIterator  Random access iterator to the element array
    /// \param[in,out]   ping    Array of elements
    /// \param[in]       pong    Scratch memory used for storing sorted elements 
    /// \param[in]       left    Left Index of the current partition
    /// \param[in]       right   Right Index of the current partition
    /// \param[in]       depth   Recursion depth
    /// \param[in]       idx     Index of the current pivot element 
    /// \return          None
    /// \testmethod
    /// \traceability
    template <class RandomAccessIterator>
    static void _sort_TiOpt_iteration (RandomAccessIterator ping, RandomAccessIterator pong, sint32 left, sint32 right, sint32 depth, sint32 idx)
    {
        if (right <= left)
        {
            // only one remaining element
            if (depth & 1)
            {
                // ping is the scratch memory now. Copy value back into the pong buffer
                pong[idx] = ping[idx];
            }
        }
        else
        {
            // Quick Sort
            const sint32 pivotIndex = (left + right) / 2;
            const sint32 pivotNewIndex = _sort_TiOpt_partition(ping, pong, left, right, pivotIndex);
            _sort_TiOpt_iteration(pong, ping, left, pivotNewIndex - 1, depth+1, left);
            _sort_TiOpt_iteration(pong, ping, pivotNewIndex + 1, right, depth+1, right);

        }
    }

    /// \brief Iteration sort the sub array elements in ascending/descending order.
    /// \details Iteration sort the sub array elements in the range in  
    /// ascending/descending order using recursive partition sort   
    /// based on the given comparison function object "comp".
    /// If comp is "less/greater",then array will be sorted in "ascending/decending" order.\n
    /// When right index is greater than the left index:\n
    /// 1) It calculates new pivot element "pivotIndex" as (right+left)/2.\n
    /// 2) It calls the function _sort_TiOpt_partition() ,which partially sorts the array in ascending/descending order and places the pivot element at correct position and returns the new index (pivotNewIndex) of  pivot element.\n
    /// 3) It make a recursive call with array limits as first,pivotNewIndex-1 and pivot element index "first" as arguments.This will sort all the sub-array elements which are less/greater than the pivot element in ascending/descending order.\n
    /// 4) It make a recursive call with array limits as pivotNewIndex + 1, right and pivot element index "right" as arguments.This will sort all the sub-array elements which are greater/less than the pivot element in descending/ascending order.\n
    /// When right <= left and depth is 1 :\n
    /// Only one element(pivotelement) will remains and it will be copied to pong buffer at pivotelement index.
    /// \tparam          RandomAccessIterator  Random access iterator to the element array
    /// \tparam          Compare               Compare function object
    /// \param[in,out]   ping    Array of elements
    /// \param[in]       pong    Scratch memory used for storing sorted elements 
    /// \param[in]       left    Left Index of the current partition
    /// \param[in]       right   Right Index of the current partition
    /// \param[in]       depth   Recursion depth
    /// \param[in]       idx     Index of the current pivot element 
    /// \param[in]       comp    Compare function object to dynamically change the sorting direction
    /// \return          None
    /// \testmethod
    /// \traceability
    template <class RandomAccessIterator, class Compare>
    static void _sort_TiOpt_iteration (RandomAccessIterator ping, RandomAccessIterator pong, sint32 left, sint32 right, sint32 depth, sint32 idx, Compare comp)
    {
        if (right <= left)
        {
            // only one remaining element
            if (depth & 1)
            {
                // ping is the scratch memory now. Copy value back into the pong buffer
                pong[idx] = ping[idx];
            }
        }
        else
        {
            // Quick Sort
            const sint32 pivotIndex = (left + right) / 2;
            const sint32 pivotNewIndex = _sort_TiOpt_partition(ping, pong, left, right, pivotIndex, comp);
            _sort_TiOpt_iteration(pong, ping, left, pivotNewIndex - 1, depth+1, left, comp);
            _sort_TiOpt_iteration(pong, ping, pivotNewIndex + 1, right, depth+1, right, comp);
        }
    }

    /// \brief Iteration sort the array elements in the range in ascending order using recursive partition sort.
    /// \details Iteration sort the array elements in the range[first,last] in ascending 
    /// order using recursive partition sort and ping , pong buffers.
    /// This quick sort implementation is using scratch memory to 
    /// enable a software pipelining optimization of the inner loop 
    /// for TI c6x platform!\n
    /// This function calls _sort_TiOpt_iteration() with the below arguments.\n
    /// 1) ping: This argument is "first" which is iterator to the first element of the sub-arry to be sorted.This is considered as ping buffer in the called function.\n
    /// 2) pong: This argument is "scratchMem" which is the iterator to the first element of the scratch memory.This is considered as pong buffer in the called function.It holds the elements of the sorted sub-array in the called function.\n
    /// 3) left: This argument is 0 indicating the index of first element of the ping buffer.\n
    /// 4) right: This argument is "last-first-1" indicating the index of last element  of the ping buffer.\n
    /// 5) depth: This argument is 0 indicating the first call to the function.This value will be increamented by 1 each time this function is called recursively.\n
    /// 6) idx: This argument is 0 indicating that the first element of ping buffer is considered as pivotelement for sorting the sub-array of the ping buffer elements.\n
    /// \tparam          RandomAccessIterator  Random access iterator to the element array
    /// \param[in,out]   first       Iterator to the start address of Array of elements 
    /// \param[in]       last        Iterator to the end of the Array(points to the element 
    ///						         after the last element of the Array!) 
    /// \param[in]       scratchMem  Iterator to the Scratch memory space required by partition sort  
    /// \return          None 
    /// \testmethod
    /// \traceability
    template <class RandomAccessIterator>
    static void sort_TiOpt (RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator scratchMem)
    {
        _sort_TiOpt_iteration(first, scratchMem, 0, last-first-1, 0, 0);
    }
    
    /// \brief Iterative sort the array elements of any type in the range.
    /// \details Iteration sort the array elements in the range in ascending/descending order using recursive partition sort based on  
    /// the given comparison function object "comp".
    /// If comp is "less/greater",then array will be sorted in "ascending/decending" order.
    /// This quick sort implementation is using scratch memory to 
    /// enable a software pipelining optimization of the inner loop 
    /// for TI c6x platform! \n
    /// This function calls _sort_TiOpt_iteration() with the below arguments: \n
    /// 1) comp: If comp is "less" or "greater",then array will be partially sorted in "ascending" or "decending" order respectively.\n
    /// 2) ping: This argument is "first" which is iterator to the first element of the sub-arry to be sorted.This is considered as ping buffer in the called function.\n
    /// 3) pong: This argument is "scratchMem" which is the iterator to the first element of the scratch memory.This is considered as pong buffer in the called function.It holds the elements of the sorted sub-array in the called function.\n
    /// 4) left: This argument is 0 indicating the index of first element of the ping buffer.\n
    /// 5) right: This argument is "last-first-1" indicating the index of last element  of the ping buffer.\n
    /// 6) depth: This argument is 0 indicating the first call to the function.This value will be increamented by 1 each time this function is called recursively.\n
    /// 7) idx: This argument is 0 indicating that the first element of ping buffer is considered as pivotelement for sorting the sub-array of the ping buffer elements.\n
    /// \tparam          RandomAccessIterator     Random access iterator to the element array
    /// \tparam          Compare                  Compare function object
    /// \param[in,out]   first       Iterator to the start address of Array of elements 
    /// \param[in]       last        Iterator to the end of the Array(points to the element 
    ///						         after the last element of the Array!) 
    /// \param[in]       scratchMem  Iterator to the Scratch memory space required by partition sort  
    /// \param[in]       comp        Compare function object to dynamically change the sorting direction
    /// \return          None	
    /// \testmethod
    /// \traceability
    template <class RandomAccessIterator, class Compare>
    static void sort_TiOpt (RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator scratchMem, Compare comp)
    {
        _sort_TiOpt_iteration(first, scratchMem, 0, last-first-1, 0, 0, comp);
    }
  
    /// \brief Iterative Quick Sort based on partitioning and Insertion sort.
    /// \details Iterative (non recursive) Quick Sort implementation.
    /// It uses Partition Sort for Larger arrays and Insertion Sort for array size less than 7.
    /// For array size less than 7 :\n
    /// It compares the current element with the largest value in the sorted array.If the current element is greater, then it leaves the element in its place and moves on to the next element else it finds its correct position in the sorted array and moves it to that position. This is done by shifting all the elements, which are larger than the current element, in the sorted array to one position ahead.
    /// For array size greater than or equal to 7 :\n
    /// Implements quick sort and partitions the array partially by choosing median of left, center, and right elements as partitioning element.\n
    /// If Sub-array which contains elements less than pivote element is larger than the sub-array with higher elements,then pointers for start and end of sub-array elements are pushed on to the stack vector and smaller sub-array will be partitioned again.\n
    /// \note
    /// 1. Requires an internal stack of 64 Size!.\n
    /// 2. Unfortunately not much faster compared to the original recursive TI implementation.\n
    /// \tparam          RandomAccessIterator     Random access iterator to the element array
    /// \param[in,out]   first   Iterator to the start address of Array of elements  
    /// \param[in]       last    Iterator to the end of the Array(points to the element 
    ///  				         after the last element of the Array!) 
    /// \return          None
    /// \testmethod
    /// \traceability
    template <class RandomAccessIterator>
    inline static void sort (RandomAccessIterator first, RandomAccessIterator last)
    {
        sint32 i;
        sint32 j;
        sint32 right = (last - first) - 1;
        sint32 left = 0;
        typename RandomAccessIterator::value_type temp;
        cml::CVector<sint32, 64> stack;   // stack contains 32 left/right values: sufficient for sorting 2^32 elements

        for (;;)
        {
            //Insertion sort when subarray small enough.
            if ( (right-left) < 7)
            {
                for (j = left+1; j <= right; j++)
                {
                    temp = first[j];
                    for (i = j-1; i >= left; i--)
                    {
                        if (first[i] < temp)
                        {
                            break;
                        }
                        first[i+1] = first[i];
                    }
                    first[i+1] = temp;
                }

                if (stack.empty()) 
                {
                    break;
                }

                //Pop stack and begin a new round of partitioning.
                right = stack.back(); stack.pop_back();
                left  = stack.back(); stack.pop_back();
            }
            else
            {
                //Choose median of left, center, and right elements as partitioning element a. Also rearrange so that a[l] <= a[l+1] <= a[ir].
                std::swap(first[(left + right) >> 1], first[left+1]);
                if (first[right] < first[left])
                {
                    std::swap(first[left], first[right]);
                }
                if (first[right] < first[left+1])
                {
                    std::swap(first[left+1], first[right]);
                }
                if (first[left+1] < first[left])
                {
                    std::swap(first[left], first[left+1]);
                }

                //Initialize pointers for partitioning.
                i = left+1;
                j = right;
                temp = first[left+1];

                //Partitioning element.
                for (;;)
                {
                    //Scan up to find element > a
                    do
                    {

                        i++;
                    }while (first[i] < temp);
                    //Scan down to find element < a
                    do
                    {
                        j--;
                    }while (temp < first[j]);
                    //Pointers crossed. Partitioning complete
                    if (j < i)
                    {
                        break;
                    }
                    //Exchange elements.
                    std::swap(first[i], first[j]);
                }

                //Insert partitioning element.
                first[left+1] = first[j];
                first[j] = temp;

                //Push pointers to larger subarray on stack, process smaller subarray immediately.
                if ( (right-i+1) >= (j-left) )
                {
                    stack.push_back(i);
                    stack.push_back(right);
                    right = j-1;
                }
                else
                {
                    stack.push_back(left);
                    stack.push_back(j-1);
                    left = i;
                }
            }
        }
    }

    /// \brief Find a value in the given range of values.
    /// \details Finds and returns an iterator to the first element in the range [first,last) that compares equal to the input value.\n
    /// If no such element is found, the function returns iterartor to last(points to the element after the last element of the Array).
    /// \tparam          InputIterator  Iterator to the element array
    /// \tparam          T              Type of the value
    /// \param[in]       first   Iterator to the start address of Array of elements 
    /// \param[in]       last    Iterator to the end of the Array(points to the element 
    ///						     after the last element of the Array!) 
    /// \param[in]       val     Reference to Value to search for in the range
    /// \return          An iterator to the element in the range that compares 
    ///				     equal to value. If no elements match, return last
    /// \testmethod
    /// \traceability
    template<class InputIterator, class T>
    static InputIterator find (InputIterator first, InputIterator last, const T& val)
    {
        while (first != last)
        {
            if (*first == val)
            {
                return first;
            }
            ++first;
        }
        return last;
    }
  
    /// \brief Return iterator to lower bound.
    /// \details Returns an iterator pointing to the first element in the 
    /// range [first, last) that is not less than the given input value.
    /// The elements in the range should be already sorted according 
    /// to this same criterion (operator <), or at least partitioned
    /// with respect to input value.
    /// \tparam          RandomAccessIterator  Random access iterator to the element array
    /// \tparam          T                     Type of the value
    /// \param[in]       first   Iterator to the start address of Array of elements 
    /// \param[in]       last    Iterator to the end of the Array(points to the element 
    ///						     after the last element of the Array!).
    /// \param[in]       val     Value of the lower bound to search for in the range.
    /// \return          An iterator to the lower bound of input value in the range.
    ///				     If all the element in the range compare less than input value, 
    ///				     the function returns last(points to the element after the last element of the Array!).
    /// \testmethod
    /// \traceability
    template <class RandomAccessIterator, class T>
    static RandomAccessIterator lower_bound (RandomAccessIterator first, RandomAccessIterator last, const T& val)
    {
        RandomAccessIterator it;
        typename RandomAccessIterator::difference_type count;
        typename RandomAccessIterator::difference_type step;
        count = last - first;
        while (count > 0)
        {
            it = first;
            step = count / 2;
            it += step;
            if (*it < val)
            {
                first = ++it;
                count -= step + 1;
            }
            else
            {
                count = step;
            }
        }
        return first;
    }

    /// \brief Implements the power of input value using a recursive template.
    /// \details Implements the power of input value using a recursive struct template.
    /// struct template has pow() as member function with argument "val" and it calls "SPow" recursively each time with POWER value lees by 1.
    /// Struct needed, because partial specialization of function is not allowed. 
    /// \tparam          POWER  Power of the input value
    /// \tparam          T      Type of the input value
    /// \param[in]       val    Value whose power to be evaluated
    /// \return          Power of the input value based on the template parameter POWER
    /// \testmethod
    /// \traceability
    template <uint32 POWER, typename T>
    struct SPow
    {
        static inline T pow(const T& val)
        {
            return val * SPow<POWER-1, T>::pow(val);
        }
    };

    /// \brief Implements the first exponent of a Real value.
    /// \details Implements the first exponent of a Real value which evaluates to 'val' always.This is given value power of 1 which is the value itself.
    /// Struct needed, because partial specialization of function is not allowed.
    /// \tparam          POWER  Power of the input value
    /// \param[in]       val    Value whose first exponent to be evaluated
    /// \return          Returns value itself, since it's a first exponent.
    /// \testmethod
    /// \traceability
    template <typename T>
    struct SPow<1U, T>
    {
        static inline T pow(const T& val)
        {
            return val;
        }
    };

    /// \brief Implements the zero exponent of a Real value.
    /// \details Implements the zero exponent of a Real value which evaluates to '1' always.This is given value power of zero which is 1.
    /// Struct needed, because partial specialization of function is 
    /// not allowed.
    /// \tparam          POWER  Power of the input value
    /// \param[in]       val    Value whose zero exponent to be evaluated
    /// \return          Returns 1 always, since it's a zero exponent
    /// \testmethod
    /// \traceability
    template <typename T>
    struct SPow<0U, T>
    {
        static inline T pow(const T& val)
        {
            return static_cast<T>(1);
        }
    };
     
    /// \brief Power function to call static method from struct.
    /// \details This power function pow() is a template function which calls the static member function pow() of template struct "SPow".
    /// \tparam          POWER  Power of the input value
    /// \tparam          T      Type of the input value
    /// \param[in]       val    Value whose power to be evaluated
    /// \return          Returns power of the val based on the template parameter POWER
    /// \testmethod
    /// \traceability
    template <uint32 POWER, typename T>
    inline static T pow(const T& val)
    {
        return SPow<POWER, T>::pow(val);
    }

    /// \brief Values will be clamped beyond MIN and MAX values.
    /// \details Limit to range using template method (equals MIN, MAX).
    /// This clamp() template function takes MIN,MAX and val as arguments.\n
    /// If "val" is less than "MIN" value or greater than MAX value,then this function returns "MIN" or "MAX" respectively otherwise returns the value itself.\n
    /// \tparam          T      Type of the input value
    /// \param[in]       min_   Reference to the MIN value 
    /// \param[in]       max_   Reference to the MAX value 
    /// \param[in]       val    Reference to the value to be clamped 
    /// \return          Value after clamping
    /// \testmethod
    /// \traceability
    template<typename T>
    inline static T clamp(const T& min_, const T& max_, const T& val)
    {
        return (val < min_) ? min_ : ((val > max_) ? max_ : val);
    }
    
    /// \brief Returns the maximum of two arguments.
    /// \details Returns the maximum of two arguments if not equal,otherwise the rhs value will be returned.
    /// \tparam          T      Type of the input value
    /// \param[in]       lhs    Reference to the left hand side value
    /// \param[in]       rhs    Reference to the right hand side value
    /// \return          Maximum value if not equal, otherwise the rhs value
    /// \testmethod
    /// \traceability
    template <typename T>
    inline static T max(const T& lhs, const T& rhs)
    {
        return ((lhs>rhs) ? lhs : rhs );
    }

    /// \brief Returns the minimum of two arguments.
    /// \details Returns the minimum of two arguments if not equal,otherwise the rhs value will be returned.
    /// \tparam          T      Type of the input value
    /// \param[in]       lhs    Reference to the left hand side value
    /// \param[in]       rhs    Reference to the right hand side value
    /// \return          Minimum value if not equal, otherwise the rhs value
    /// \testmethod
    /// \traceability
    template <typename T>
    inline static T min(const T& lhs, const T& rhs)
    {
        return ((lhs<rhs) ? lhs : rhs );
    }
  
    /// \brief Returns the sign of the given value.
    /// \details Returns the sign of the given value of any Type.
    /// Returns -1 for negative, +1 for positive and 0 if value is zero.
    /// \tparam          T      Type of the input value
    /// \param[in]       val    The value the sign is extracted from.
    /// \return          The sign of the given value.
    /// \testmethod
    /// \traceability
    template <typename T>
    inline static sint32 sgn(const T& val)
    {
        return static_cast<sint32>((static_cast<T>(0) < val)) - static_cast<sint32>((static_cast<T>(0) > val));
    }

} // End of cml namespace

#endif // cml_stl_algorithm_h__

