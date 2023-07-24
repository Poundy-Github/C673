/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_memory.h

  DESCRIPTION:               Memory related operations

  AUTHOR:                    Jeevan Kotre

  CREATION DATE:             21.03.2018

  VERSION:                   $Revision: 1.8.1.2 $
   
  ---*/ /*---
  CHANGES:                   $Log: cml_memory.h  $
  CHANGES:                   Revision 1.8.1.2 2019/06/24 12:31:18CEST Reddy, Purushothama (uid33569) 
  CHANGES:                   updated with QAF warnings handled.
  CHANGES:                   Revision 1.8.1.1 2019/05/27 11:08:49CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   MFC431TA19: QAF L4 fixes added
  CHANGES:                   Revision 1.8 2018/04/13 10:55:39CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Identations of comments have been fixed.
  CHANGES:                   Revision 1.7 2018/04/10 07:28:25CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Updated with fix for warnings causing build fail in devgate.
  CHANGES:                   Revision 1.6 2018/04/09 13:01:06CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Moved definitions from cml_memory.c to cml_memory.h
  CHANGES:                   Revision 1.5 2018/03/29 07:33:13CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Moved definitions of memory implementations from header to cml_memory.c file.
  CHANGES:                   Revision 1.3 2018/03/28 10:32:07CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Updated code with changes, QAC warnings have been corrected.
  CHANGES:                   Revision 1.2 2018/03/27 10:52:45CEST Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Implementations of cml_memset and cml_memcpy functions.
  
**************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#ifndef CML_MEMORY_INCLUDED
#define CML_MEMORY_INCLUDED

/*****************************************************************************
 (SYMBOLIC) CONSTANTS
*****************************************************************************/

#define WORD_SIZE 4U
#define BYTE_SIZE 8U

        
/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_memory.h is discouraged. Will be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef CML_EXT_INCLUDED */

/* PRQA S 0388 6 */
/* Deactivate QAF warning 0388, Date: 2019-06-18; Reviewer: uid33569;  
   Reason: The warning says nesting level exceeds 15, but this can not be avoided here. 
   There is no risk in suppressing this warning as per our analysis. */
#include "cml_ext.h"

/* Deactivate QA-C warnings 0491, 0492; Reviewer: Purushotham/Jeevan/Hari; Date: 28.03.2018; 
   Reason: Memcpy and memset functions need pointer arithmetics and ensured safety as 
   no unauthorised access of memory with this pointers in this functions.
   Review-ID: 5625844 */
/* PRQA S 0491 EOF */
/* PRQA S 0492 EOF */ 


/********************************************************************************
  Functionname:    CML_memcpy_s                                     *//*!

  \brief           Copy memory from source location to destination location.

  \description     This function copies memory block pointed by source pointer to destination.
                   Size of the destination pointer should be equal to number of bytes to be copied.
                   
  \InOutCorrelation
  
  \attention       
                   NOTE: Word size should be 32 bits.
                   CAUTION: src_ptr should be a valid address.
                            dst_ptr should be a valid address.
                            u_max_len would be checked against u_count only in debug mode, 
                            no checks are made in release mode.
                   
  \param[in]       src_ptr : Block of memory to be copied.                      [Valid pointer pointing to a memory block]
                   u_max_len : Length of the source memory.(in bytes)           [Full range of uint32]
                   u_count : number of bytes of memory to be copied in the memory. [Full range of uint32, should be less than u_max_len]
  
  \param[out]      dst_ptr : Block of memory to be copied to.                   [Valid pointer pointing to a memory block]

  \return          void

  \author          Jeevan Kotre

  \testmethod      

  \traceability    
*****************************************************************************/
/* PRQA S 3240,  3219, 3480 6 */
/* Deactivate QAF warning 3240, 3480, 3219 Date: 2019-06-14; Reviewer: uid33569;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler dependent */
CML_INLINE void CML_memcpy_s(void* CML_RESTRICT dst_ptr, uint32 u_max_len, 
                            const void* CML_RESTRICT src_ptr, uint32 u_count)
{
    uint32 u_Index = 0;
    /* u_max_len has been initialised to u_ByteCount avoid warnings in release  
     * mode. As CML_ASSERT is inactive in release mode, avoiding 'unreferenced 
     * formal parameter' warning.
     */
    uint32 u_ByteCount = u_max_len;                                         
    sint32* Dest_ptr = (sint32*)dst_ptr;
    const sint32* Src_ptr = (const sint32*)src_ptr;
    
    /* assert if memcpy not possible
     */
    CML_ASSERT((src_ptr != NULL) || (dst_ptr != NULL) || (u_count < u_max_len));

    /* Count, number of bytes to be copied. Word blockwise copy is done.
     * WORD_SIZE is considered to be 32 bits.
     */
    for(u_ByteCount = u_count ; u_ByteCount >= WORD_SIZE; u_ByteCount -= WORD_SIZE)
    {
      Dest_ptr[u_Index] = Src_ptr[u_Index];
      u_Index++;
    }
/* PRQA S 1843 5 */
/* Deactivate QAC warning 1843 Date: 2019-06-17; Reviewer: uid33569;
   Reason: There is no risk in violating this rule  */
    if(u_ByteCount != 0) 
    {           
      const sint8* p_uSrc = (const sint8*) (&Src_ptr[u_Index]);
      sint8* p_uDst = (sint8*) (&Dest_ptr[u_Index]);
    
      for(u_Index = 0; u_Index < u_ByteCount ; u_Index++)
      {
        p_uDst[u_Index] = p_uSrc[u_Index];
      }
    }
}


/********************************************************************************
  Functionname:    CML_memcpyAlign_s                                     *//*!

  \brief           Copy memory from source location to destination location.

  \description     This function copies aligned memory block pointed by source pointer to aligned destination memory.
                   Size of the destination pointer should be equal to number of bytes to be copied.
                   
  \InOutCorrelation
  
  \attention       
                   NOTE: Word size should be 32 bits.
                   CAUTION: p_src should be a valid address.
                            p_dst should be a valid address.
                            u_max_len would be checked against u_count only in debug mode, 
                            no checks are made in release mode.
                   
  \param[in]       p_src : Block of memory to be copied.                        [Valid sint32 pointer pointing to a memory block]
                   u_max_len : Length of the source memory.(in bytes)           [Full range of uint32]
                   u_count : number of bytes of memory to be copied(in bytes). [Full range of uint32, should be less than u_max_len]
  
  \param[out]      p_dst : Block of memory to be copied to.                     [Valid sint32 pointer pointing to a memory block]

  \return          void

  \author          Jeevan Kotre

  \testmethod      

  \traceability    
*****************************************************************************/
/* PRQA S 3240, 3219, 3480 6 */
/* Deactivate QAF warning 3240 , 3480, 3219 Date: 2019-06-14; Reviewer: uid33569;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler dependent */
CML_INLINE void CML_memcpyAlign_s(sint32* CML_RESTRICT p_dst, uint32 u_max_len,
                              const sint32* CML_RESTRICT p_src, uint32 u_count)
{  
   uint32 u_Index = 0;
   /* u_max_len has been initialised to u_ByteCount avoid warnings in release  
    * mode. As CML_ASSERT is inactive in release mode, avoiding 'unreferenced 
    * formal parameter' warning.
    */
   uint32 u_ByteCount = u_max_len;
   
    /* assert if memcpy not possible
     */
   CML_ASSERT((p_src != NULL) || (p_dst != NULL) || (u_count < u_max_len)); 
   
   /* Count, number of bytes to be copied. Word blockwise copy is done.
    * WORD_SIZE is considered to be 32 bits.
    */
   for(u_ByteCount = u_count ; u_ByteCount >= WORD_SIZE; u_ByteCount -= WORD_SIZE)
   {
     p_dst[u_Index] = p_src[u_Index];
     u_Index++;
   }
}

/*****************************************************************************
  Functionname:    CML_memset_s                                     *//*!

  \brief           Set memory of a input source.

  \description     This function sets memory block pointed by source pointer.
                   The memory is set with value which would be of a byte length, 
                   for a predefined size, size should not exceed the maximum length of 
                   memory block to be set. 
                   
  \InOutCorrelation
  
  \attention       
                   NOTE: Word size should be 32 bits.
                   CAUTION: src_ptr should be a valid address.
                   u_max_len would be checked against u_count only in debug mode,
                   no checks are made in release mode.
                   
  \param[in]
                   u_val : Value to be set to the memory.                       [Full range of uint8]
                   u_max_len : Length of the source memory.(in bytes)           [Full range of uint32]
                   u_count : number of bytes of memory to be set in the memory(in bytes). [Full range of uint32, should be less than u_max_len]
  
  \param[in, out]  src_ptr : Block of memory to be filled with 'u_val'.         [Valid pointer pointing to a memory block]

  \return          void

  \author          Jeevan Kotre

  \testmethod      

  \traceability    
*****************************************************************************/
/* PRQA S 3240, 3219, 3480 6 */
/* Deactivate QAF warning 3240, 3480, 3219 Date: 2019-06-14; Reviewer: uid33569;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler dependent */
CML_INLINE void CML_memset_s(void* src_ptr, uint32 u_max_len, uint8 u_val, uint32 u_count)
{
    uint32 u_Index = 0;
    /* u_max_len has been initialised to u_ByteCount avoid warnings in release  
    * mode. As CML_ASSERT is inactive in release mode, avoiding 'unreferenced 
    * formal parameter' warning.
    */
    uint32 u_ByteCount = u_max_len;
    
    /* Typecast void pointer as a signed integer pointer.
    */
    uint32* Dest_ptr = (uint32*)src_ptr;
/* PRQA S 3004 4 */
/* Deactivate QAC warning 3004 Date: 2019-06-17; Reviewer: uid33569;
   Reason: There is no risk in violating this rule  */
    uint8* p_uDst = NULL;
    uint32 u_tmpVal;

    /* src_ptr is checked for valid address,
     * number of wordsize should not exceed the maximum length of the source address
     * assert if memset not possible                                                                       
     */                                                                     
    CML_ASSERT((src_ptr != NULL) || (u_count < u_max_len));
    {
      /* Done for the purpose of distribution of uint8 to uint32
       */
/* PRQA S 1840 10 */
/* Deactivate QAC warning 1840 Date: 2019-06-17; Reviewer: uid33569;
   Reason: There is no risk in violating this rule  */
      u_tmpVal =  (uint32)u_val * 0x01010101;                                                 
      
      /* Count, number of bytes to be copied. Word blockwise copy is done.
       * WORD_SIZE is considered to be 32 bits.
       */
      for(u_ByteCount = u_count ; u_ByteCount >= WORD_SIZE; u_ByteCount -= WORD_SIZE)
      {
        Dest_ptr[u_Index] = u_tmpVal;                                       
        u_Index++;
      }

      /* unaligned bytes, bytewise memset shall be called to set the remaining bytes.
       */
/* PRQA S 1843 5 */
/* Deactivate QAC warning 1843 Date: 2019-06-17; Reviewer: uid33569;
   Reason: There is no risk in violating this rule  */
      if(u_ByteCount != 0)                                                  
      {   
        p_uDst = (uint8*)(&Dest_ptr[u_Index]);
      
        for(u_Index = 0; u_Index < u_ByteCount ; u_Index++)
        {
          p_uDst[u_Index] = u_val;
        }
      }
    }
}

/*****************************************************************************
  Functionname:    CML_memsetAlign_s                                     *//*!

  \brief           Set memory of a input source.

  \description     This function sets aligned memory block pointed by source pointer.
                   The aligned memory is set with value which would be of a byte length, 
                   for a predefined size, size should not exceed the maximum lenght of 
                   memory block to be set. 
                   
  \InOutCorrelation
  
  \attention       
                   NOTE: Word size should be 32 bits.
                   CAUTION: p_src should be a valid address.
                   u_max_len would be checked against u_count only in debug mode,
                    no checks are made in release mode.
                   
  \param[in]
                   u_val : Value to be set to the memory.                       [Full range of uint8]
                   u_max_len : Length of the source memory.(in bytes)           [Full range of uint32]
                   u_count : number of bytes of memory to be set in the memory(in bytes). [Full range of uint32, should be less than u_max_len]
  
  \param[in, out]  p_src : Block of memory to be filled with 'u_val'.           [Valid pointer pointing to a memory block]

  \return          void

  \author          Jeevan Kotre

  \testmethod      

  \traceability    
*****************************************************************************/
/* PRQA S 3240, 3219, 3480 6 */
/* Deactivate QAF warning 3240, 3480, 3219 Date: 2019-06-14; Reviewer: uid33569;   
   Reason: Macro CML_INLINE used to handle inline keyword, which is compiler dependent */
CML_INLINE void CML_memsetAlign_s(uint32* p_src, uint32 u_max_len, uint8 u_val,
                                                               uint32 u_count)
{
    uint32 u_Index = 0;
    /* u_max_len has been initialised to u_ByteCount avoid warnings in release  
    * mode. As CML_ASSERT is inactive in release mode, avoiding 'unreferenced 
    * formal parameter' warning.
    */
    uint32 u_ByteCount = u_max_len;
    uint32 u_tmpVal;

    /* src_ptr is checked for valid address,
     * number of wordsize should not exceed the maximum length of the source address
     * assert if memset not possible                                                                       
     */  
    CML_ASSERT((p_src != NULL) || (u_count < u_max_len));         

    {
      /* Done for the purpose of distribution of uint8 to uint32
       */
/* PRQA S 1840 10 */
/* Deactivate QAC warning 1840 Date: 2019-06-17; Reviewer: uid33569;
   Reason: There is no risk in violating this rule  */
      u_tmpVal =  (uint32)u_val * 0x01010101;

      /* Count, number of bytes to be copied. Word blockwise copy is done.
       * WORD_SIZE is considered to be 32 bits.
       */
      for(u_ByteCount = u_count ; u_ByteCount >= WORD_SIZE; u_ByteCount -= WORD_SIZE)
      {
        p_src[u_Index] = u_tmpVal;
        u_Index++;
      }
    }
}

#endif  /* #ifndef CML_MEMORY_INCLUDED */
