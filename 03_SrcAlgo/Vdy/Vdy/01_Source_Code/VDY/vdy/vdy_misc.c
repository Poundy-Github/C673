/*! \file **********************************************************************

  @defgroup VDYMiscFunctions VDY Misc Module Unit Design
	@ingroup VDYHandCode
  @{
	  
  $Company:			Continental AG $

  $Component:		VDY (Vehicle Dynamics Observer) $

  $Module:			vdy_misc.c $

  @brief 			This module contains misc functions used by VDY like mem_cpy, mem_set and matrix multiplication
  
  $Descripion:		$
	  
  $Revision: 1.4 $

  CHANGES:
  ---*/ /*---
  CHANGE:           $Log: vdy_misc.c  $
  CHANGE:           Revision 1.4 2020/04/25 22:23:11CEST Chinnaswamy, Ramachandra (uids4735) (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.3 2019/12/31 12:24:15CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC Fixes
  CHANGE:           Revision 1.2 2019/06/19 12:20:26CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAF Fixes

*****************************************************************************/
/* PRQA S 0380, 2211, 2824, 3212, 3227, 3673, 3677 EOF */
/* date: 2019-06-18, reviewer: Ramachandra Chinnasswamy-EXT (uids4735), reason: working fine without any critical issue */
#include "vdy.h"

#define CML_RESTRICT

static void CML_memcpy_s(void* CML_RESTRICT dst_ptr, uint32 u_max_len, 
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
//    assert((src_ptr != NULL) || (dst_ptr != NULL) || (u_count < u_max_len));//Removed by Mingfen

    /* Count, number of bytes to be copied. Word blockwise copy is done.
     * WORD_SIZE is considered to be 32 bits.
     */
    for(u_ByteCount = u_count ; u_ByteCount >= 4u; u_ByteCount -= 4u)
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

static void CML_memset_s(void* src_ptr, uint32 u_max_len, uint8 u_val, uint32 u_count)
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
//    assert((src_ptr != NULL) || (u_count < u_max_len));//Removed by Mingfen
    
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
      for(u_ByteCount = u_count ; u_ByteCount >= 4u; u_ByteCount -= 4u)
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
  @fn     vdy_memset_s                                     */ /*!
				    
  @brief            Set memory of a input source.
                    wrapper for CML_memset_s
  @post             src_ptr will be overwritten        
  @globals          No global data used in this function.
				    
  @description      This function sets memory block pointed by source pointer.
                    The memory is set with value which would be of a byte length, 
                    for a predefined size, size should not exceed the maximum length of 
                    memory block to be set. 
                    
  @InOutCorrelation 
  				                        
  @param[in]        u_val : Value to be set to the memory.                    [Full range of uint8]
  @param[in]        u_size : Length of the source memory.(in bytes)           [Full range of uint32]
                    
  @param[in, out]   src_ptr : Block of memory to be filled with 'u_val'       [Valid pointer pointing to a memory block]
				    
  @return           void

				    
  @author           Sanjiv Singh
				    
  @testmethod       Module testing.     
				    
  @traceability     doors://RBGS854A:40000/?version=2&prodID=0&view=00000001&urn=urn:telelogic::1-503e822e5ec3651e-O-10964-0003c62b
*****************************************************************************/
void vdy_memset_s(void* src_ptr, uint8 u_val, uint32 u_size)
{
	memset(src_ptr,u_val,u_size);

//   (void)CML_memset_s( src_ptr,u_size,u_val,u_size);
}

/********************************************************************************
  @fn			     vdy_memcpy_s                                     *//*!
				    
  @brief            Copy memory from source location to destination location.
                    wrapper for CML_memcpy_s
  @post             dst_ptr will be overwritten        
  @globals          No global data used in this function.
				    
  @description      This function copies memory block pointed by source pointer to destination.
                    Size of the destination pointer should be equal to number of bytes to be copied.
                    
  @InOutCorrelation 
  				                        
  @param[in]        src_ptr : Block of memory to be copied.                   [Valid pointer pointing to a memory block]
  @param[in]        u_size : Length of the source memory.(in bytes)           [Full range of uint32]
                      				    
  @param[out]       dst_ptr : Block of memory to be copied to.                [Valid pointer pointing to a memory block]
				    
  @return           void
				    

				    
  @author           Sanjiv Singh
				    
  @testmethod       Module testing.     
*****************************************************************************/
void vdy_memcpy_s(void* dst_ptr,const void* src_ptr, uint32 u_size)
{
	memcpy(dst_ptr,src_ptr,u_size);

//  (void)CML_memcpy_s(dst_ptr, u_size ,src_ptr, u_size);
}

/*****************************************************************************
  @fn			     vdy_matrix_multiplication                                     *//*!
				    
  @brief            VDY Matrix Multiplication For Two Inputs as per Matlab.
    
				    
  @description      The below matrix multilplication logic is implemented only for matlab auto generated inputs and outputs. Matlab generates the matrix inputs in a single 
                    dimensional array format, with the transposed input. So here, VDY is using one property of matrix multplication:

					(A*B)'  =  B' * A'
                    Matlab is already generating the trasposed input, so no need to transpose the input matrix, just multiply the matrices in format : B' * A'. 
                    
  @InOutCorrelation 
  				                        
  @param[in]        matrix_A[]: Matrix A
  @param[in]        matrix_B[]: Matrix B
  @param[in]        col_A_dim: Matrix A Column Size
  @param[in]        row_A_dim: Matrix A Row Size
  @param[in]        col_B_dim: Matrix  Column Size
                                        
  @param[in, out]   matrix_BxA[]: Multiplied Matrix A_B

  @return           uint8 ret_value;		    
  @author           Asang Singh
				    
  @testmethod       Module testing.     
*****************************************************************************/
 
  uint8 vdy_matrix_multiplication(float32 matrix_A[], float32 matrix_B[], float32 matrix_BxA[], uint8 col_A_dim, uint8 row_A_dim, uint8 col_B_dim)
{
	uint8 ret_value;
	uint8 i, j, k;
	float32 mat_BxA;
	
	ret_value = TRUE;
	
	if((matrix_BxA != matrix_A) && (matrix_BxA != matrix_B))
	{
		for(i = 0u ; i < col_B_dim ; i++)
		{
			const uint16 col_A = (uint16)i * (uint16)col_A_dim;
			const uint16 col_AxB = (uint16)i * (uint16)row_A_dim;
			
			for(j = 0; j < row_A_dim ; j++)
			{
				mat_BxA = VDY_ZERO_F;
				
				for(k = 0; k < col_A_dim; k++)
				{
					mat_BxA += matrix_B[col_A + k] * matrix_A[j + (k * row_A_dim)];
				
				}
				
				matrix_BxA[j + col_AxB] = mat_BxA;
			
			}
		}
	}
	else
	{
		ret_value = FALSE;
	}

	return ret_value;
}


/** @} */ 
/* EOF */
