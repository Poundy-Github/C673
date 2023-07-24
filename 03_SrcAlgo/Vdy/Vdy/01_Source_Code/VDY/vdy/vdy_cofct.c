/*! \file **********************************************************************

  @defgroup CommonFunctionsUnit VDY Common Functions Unit Design
	@ingroup VDYHandCode
  @{

  $Company:			Continental AG $

  $Component:		VDY (Vehicle Dynamics Observer) $

  $Module:			vdy_cofct.c $

  @brief			This module contains the commonly used function

  $Descripion:		$
  
  $Revision: 1.17 $

  CHANGES:
  ---*/ /*---
  CHANGE:           $Log: vdy_cofct.c  $
  CHANGE:           Revision 1.17 2020/06/04 21:57:08CEST Chinnaswamy, Ramachandra (uids4735) (uids4735) 
  CHANGE:           Test Cases Links Update
  CHANGE:           Revision 1.16 2020/05/31 23:26:39CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Test Scripts Linking
  CHANGE:           Revision 1.15 2020/05/06 08:46:59CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           PRQA Template Update
  CHANGE:           Revision 1.14 2020/05/04 23:06:15CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.13 2020/04/25 22:23:08CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.12 2019/12/31 12:24:18CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC Fixes
  CHANGE:           Revision 1.11 2019/06/11 08:36:16CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAF Fixes
  CHANGE:           Revision 1.10 2019/01/31 07:25:25CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.9 2019/01/26 21:24:03CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Followed camel case convention for methods
  CHANGE:           Revision 1.8 2019/01/09 13:36:57CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design - Doors Linking
  CHANGE:           Revision 1.7 2018/12/12 06:13:10CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Design Design Update for vdy common functions
  CHANGE:           Revision 1.6 2018/12/05 10:53:17CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.5 2018/11/28 12:07:32CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.4 2018/09/12 16:23:15CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Support for courage environment
  CHANGE:           Revision 1.3 2018/09/04 12:00:06CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.2 2018/08/28 13:29:34CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Unit Design Update
  CHANGE:           Revision 1.1 2018/08/09 10:40:54CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Initial revision
  CHANGE:           Member added to project /ADAS/SW/Components/VDY_VehicleDynamics/04_Engineering/01_Source_Code/VDY/vdy/project.pj
  CHANGE:           Revision 1.17 2016/05/23 10:15:18CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Disabled unused function by VDYHistCalcSum by adding switch new switch CFG_VDY_POLYSPACE_ERROR_DISABLE'to remove polyspace red error
  CHANGE:           Revision 1.16 2015/07/30 14:07:05CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           fix for
  CHANGE:           
  CHANGE:           acellere findings from VDY
  CHANGE:           - Added comments -  uidr1340 [Jul 30, 2015 2:07:05 PM CEST]
  CHANGE:           Change Package : 335155:1 http://mks-psad:7002/im/viewissue?selection=335155
  CHANGE:           Revision 1.15 2015/07/10 14:25:32CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           QAC fix for critical and mandatory errors
  CHANGE:           --- Added comments ---  uidr1340 [Jul 10, 2015 2:25:33 PM CEST]
  CHANGE:           Change Package : 355424:1 http://mks-psad:7002/im/viewissue?selection=355424
  CHANGE:           Revision 1.14 2014/12/03 11:00:44CET Balachandra, Swathi (uidj2447) 
  CHANGE:           FIX MISRA VIOLATIONS
  CHANGE:           --- Added comments ---  uidj2447 [Dec 3, 2014 11:00:44 AM CET]
  CHANGE:           Change Package : 278585:1 http://mks-psad:7002/im/viewissue?selection=278585
  CHANGE:           Revision 1.13 2014/07/08 12:43:25CEST Wolter, Frank (wolterf) 
  CHANGE:           - removed MISRA violations
  CHANGE:           --- Added comments ---  wolterf [Jul 8, 2014 12:43:26 PM CEST]
  CHANGE:           Change Package : 247012:1 http://mks-psad:7002/im/viewissue?selection=247012
  CHANGE:           Revision 1.12 2014/04/08 14:46:01CEST Wolter, Frank (wolterf) 
  CHANGE:           - doxygen function header
  CHANGE:           - removed MISRA violations
  CHANGE:           --- Added comments ---  wolterf [Apr 8, 2014 2:46:02 PM CEST]
  CHANGE:           Change Package : 229561:1 http://mks-psad:7002/im/viewissue?selection=229561
  CHANGE:           Revision 1.11 2014/01/29 09:23:03CET Wolter, Frank (wolterf) 
  CHANGE:           Replaced check of >0 with CML macro
  CHANGE:           --- Added comments ---  wolterf [Jan 29, 2014 9:23:03 AM CET]
  CHANGE:           Change Package : 215885:1 http://mks-psad:7002/im/viewissue?selection=215885
  CHANGE:           Revision 1.10 2013/10/24 16:06:45CEST Wolter, Frank (wolterf) 
  CHANGE:           Correction of filter calculation in VDYDifferentiateCycleTime()
  CHANGE:           --- Added comments ---  wolterf [Oct 24, 2013 4:06:45 PM CEST]
  CHANGE:           Change Package : 198819:1 http://mks-psad:7002/im/viewissue?selection=198819
  CHANGE:           Revision 1.9 2013/09/26 11:48:33CEST Wolter, Frank (wolterf) 
  CHANGE:           - update code review by ICT
  CHANGE:           - Code Review #339136
  CHANGE:           - implemented QAC MISRA findings
  CHANGE:           - switched to Autosar types
  CHANGE:           - grammar/spelling corrections
  CHANGE:           --- Added comments ---  wolterf [Sep 26, 2013 11:48:33 AM CEST]
  CHANGE:           Change Package : 198819:1 http://mks-psad:7002/im/viewissue?selection=198819
  CHANGE:           

*****************************************************************************/
/* PRQA S 310 EOF */
/* date: Unknow, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301 ,working fine without any critical issue " */
 
/* PRQA S 489,491 EOF */ 
/* date: Unknow, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301 , alreay reviewed and working fine without any critical issue
 also pointer aritmetic saves runtime " */

/* PRQA S 3453 EOF */
/* date: Unknow, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301 , alreay reviewed and working fine without any critical issue " */

/* PRQA S 7013 EOF */
/* date: Unknow, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301, reducing lines of code changes component structure." */


/* QAC Level 2 Warning Suppression */
/* PRQA S 2211, 2981, 3227, 3469, 3472, 3473, 4330, 1505, 1532 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: This operation is intended */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* PRQA S 0380 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */

/* PRQA S 2824 EOF */
/* date: 2019-12-31, reviewer: Ramachandra Chinnasswamy-EXT (uids4735), reason: working fine without any critical issue */
#include "vdy.h"

#if (!CFG_VDY_FPM_754)
#include <math.h>
#endif


/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/

/// added to round a float calculation to an integer index 
#define ROUNDING_OFFSET        (0.5F)   
/// amount of bits to shift a value by 3 bytes  
#define THREE_BYTE_SHIFT       (23UL)  
/// amount of bits to shift to get the sign bit of a long value  
#define SIGN_BIT_SHIFT         (31U)   
/// bitmask to to get the sign bit of a long value  
#define SIGN_BIT_MASK          (0x7FFFFFFFU)  
/// long value of (1/2)*ln(2)  
#define HALF_OF_LN_OF_2        (0x3EB17218U)  
/// long value of (1.5)*ln(2)  
#define ONE_AND_A_HALF_OF_LN_2 (0x3F851592U)  


/*****************************************************************************
  MACROS
*****************************************************************************/

#if (CFG_VDY_FPM_754)

/* <ln_offset:+1 MISRA Rule 19.7: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */
/// Reinterpretation casts for conversion of integral types 
#define RE_INTRPR_UI32(val_)    ( *((uint32 *)&(val_)) ) 
/* #define RE_INTRPR_I32(val_)  ( *((sint32 *) &(val_)) ) */
/* <ln_offset:+1 MISRA Rule 19.7: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */
/// Reinterpretation casts for conversion of integral types 
#define RE_INTRPR_F32(val_)     ( *((float32 *) &(val_)) ) 
#endif



/*****************************************************************************
  TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  VARIABLES
*****************************************************************************/


/*****************************************************************************
  LOCAL FUNCTION PROTOTYPES
*****************************************************************************/

/* ***********************************************************************
  @fn                     vdyHistGetIndex */ /*!
  @brief                  Determination of bin index corresponding to given 
                          value

  @description            see brief description
                          Histogram pointer is linked static through macro 
                          and therefore valid at runtime

  @param[in]              hist: Histogram
  @param[in]              value: New value 
  @param[out]             hist histogram database (valid by definition at calling function)
  @return                 index

  @pre
  @post                   index has to be tested pointing to legal range
  @InOutCorrelation
	- vdyHistGetIndex
		- fidx = ((value - hist->Range[0]) * hist->InvBinWidth) + ROUNDING_OFFSET;
		- idx = (sint32) fidx;
		- decrement idx to get correctly rounded index
  		
		@startuml
		start
			:fidx = ((value - hist->Range[0]) * hist->InvBinWidth) + 0.5;
			:idx = (sint32) fidx;
			if (idx > fidx) then (YES)
				:idx = idx - 1;
			endif
			:return (idx);
		stop
		@enduml
			
		
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_cofct.c -> TEST_vdyHistGetIndex_001(), TEST_vdyHistGetIndex_002()
  @traceability			  - NA
**************************************************************************** */
STATIC_MTD sint32 vdyHistGetIndex(const VDYHistogram_t *hist, float32 value);


/* **********************************************************************
	Unit Design for vdyHistInit is found in vdy.h
**************************************************************************** */
void vdyHistInit(VDYHistogram_t *hist, float32 *range, float32 *volume, uint32 size, float32 minValue, float32 maxValue)
{
  float32  binWidth;
  uint32 binNo;
  
  hist->Mean = VDY_ZERO_F;
  hist->Dev  = VDY_ZERO_F;
  hist->Sum  = VDY_ZERO_F;

  hist->Size = size;
  
  hist->Range  = range;
  hist->Volume = volume;

  binWidth = (maxValue - minValue) / (float32) size;
  hist->InvBinWidth = VDY_ONE_F / binWidth;

  for (binNo = VDY_ZERO_U; binNo < size; binNo++)
  {
    hist->Range[binNo]  = (binWidth * ((float32)binNo + ROUNDING_OFFSET)) + minValue;
    hist->Volume[binNo] = VDY_ZERO_F;
  }

  return;
}


/* **********************************************************************
	Unit Design for vdyHistReInit is found in vdy.h
**************************************************************************** */
void vdyHistReInit(VDYHistogram_t *hist)
{
  uint32 binNo;

  hist->Mean = VDY_ZERO_F;
  hist->Dev  = VDY_ZERO_F;
  hist->Sum  = VDY_ZERO_F;

  /* step through all bins and clear their volumes */
  for (binNo = VDY_ZERO_U; binNo < hist->Size; binNo++)
  {
    hist->Volume[binNo] = VDY_ZERO_F;
  }

  return;
}


/* **********************************************************************
	Unit Design for vdyHistReduce is found in vdy.h
**************************************************************************** */
void vdyHistReduce(VDYHistogram_t *hist, float32 weight)
{
  uint32 binNo;

  for (binNo=VDY_ZERO_U; binNo<hist->Size; binNo++)
  {
    hist->Volume[binNo] *= weight;
  }

  hist->Sum *= weight;

  return;
}


/* **********************************************************************
	Unit Design for vdyHistGetIndex is found in Declaration Section
**************************************************************************** */
STATIC_MTD sint32 vdyHistGetIndex(const VDYHistogram_t *hist, float32 value)
{
  sint32 idx;
  float32 fidx;

  fidx = ((value - hist->Range[VDY_ZERO]) * hist->InvBinWidth) + ROUNDING_OFFSET;
  idx = (sint32) fidx;

  if ((float32) idx > fidx)
  {
    idx -= 1;  /* decrement to get correctly rounded index */
  }

  return idx;
}


/* **********************************************************************
	Unit Design for vdyHistAdd is found in vdy.h
**************************************************************************** */
void vdyHistAdd(VDYHistogram_t *hist, float32 value, float32 weight)
{
  sint32 idx;
  
  idx = vdyHistGetIndex(hist, value);

  if ( (CML_f_Abs(weight) > C_F32_DELTA) && (idx >= 0L) && (idx < (sint32)hist->Size))
  {
    float32 invWeight;

    invWeight = VDY_ONE_F / (weight + hist->Volume[idx]);

    hist->Range[idx] = (hist->Range[idx] * (hist->Volume[idx] * invWeight)) + ((weight * value) * invWeight);
    
    hist->Volume[idx] += weight;
    hist->Sum         += weight;
  }
  
  return;
}


/* **********************************************************************
	Unit Design for vdyHistGetVolume is found in vdy.h
**************************************************************************** */
float32 vdyHistGetVolume(const VDYHistogram_t *hist, float32 value)
{
  sint32 idx;
  float32 ret;
  
  idx = vdyHistGetIndex(hist, value);

  if ( (idx >= VDY_ZERO) && (idx < (sint32)hist->Size) )
  {
    ret = hist->Volume[idx];
  }
  else
  {
    ret = VDY_ZERO_F;    
  }
  return ret;
}


/* **********************************************************************
	Unit Design for vdyHistGetMaxBin is found in vdy.h
**************************************************************************** */
uint32 vdyHistGetMaxBin(const VDYHistogram_t *hist)
{
  uint32 idx;
  uint32 idxMax = VDY_ZERO_U;
  float32 maxBin = hist->Volume[idxMax];

  for (idx=VDY_ZERO_U; idx < hist->Size; idx++)
  {
    if (hist->Volume[idx] > maxBin)
    {
      maxBin = hist->Volume[idx];
      idxMax = idx;
    }
  }
  return idxMax;
}


/* **********************************************************************
	Unit Design for vdyHistCalcMeanDev is found in vdy.h
**************************************************************************** */
void vdyHistCalcMeanDev(VDYHistogram_t *hist)
{
  uint32 idx;
  float32  mean   = VDY_ZERO_F;
  float32  stdev  = VDY_ZERO_F;
  float32  volSum = VDY_ZERO_F;

  for (idx = VDY_ZERO_U; idx < hist->Size; idx++)
  {
    mean   += hist->Volume[idx] * hist->Range[idx];
    volSum += hist->Volume[idx];
  }

  if (CML_f_IsNonZero(volSum))
  {
    mean  /= volSum;  
  }
  else
  {
    mean = VDY_ZERO_F;
  }
  
  for (idx = VDY_ZERO_U; idx < hist->Size; idx++)
  {
    stdev += SQR(hist->Range[idx] - mean) * hist->Volume[idx];
  }
  
  if (CML_f_IsNonZero(volSum))
  {
    stdev = VDY_SQRT(stdev/volSum);
  }
  else
  {
    stdev = VDY_ZERO_F;
  }

  /* copy values to output */
  hist->Mean = mean;
  hist->Dev  = stdev;

  return;
}


/* **********************************************************************
	Unit Design for vdyHistCalcMeanCenter is found in vdy.h
**************************************************************************** */
float32 vdyHistCalcMeanCenter(const VDYHistogram_t *hist, uint32 idxCenter, uint32 width, uint32 pwr)
{
  uint32 idx, idx_start, idx_stop;
  float32  mean   = VDY_ZERO_F;
  float32  volSum = VDY_ZERO_F;

  if(idxCenter >= width)
  {
    idx_start = idxCenter - width;
  }
  else
  {
    idx_start = VDY_ZERO_U;
  }

  if ( (idxCenter + width) < hist->Size )
  {
    idx_stop = idxCenter + width;
  }
  else
  {
    idx_stop = hist->Size - VDY_ONE_U;
  }

  /* step through bins around the center */
  for (idx=idx_start; idx <= idx_stop; idx++)
  {
    const float32 preScale_c = 0.001F;  /* Prescale to avoid large values in case of power > 1 */
    float32 vol;

    vol = hist->Volume[idx] * ((pwr > VDY_ONE_U) ? (hist->Volume[idx] * preScale_c) : (float32) pwr);
    
    mean   += vol * hist->Range[idx];
    volSum += vol;
  }

  if (volSum > VDY_ZERO_F)
  {
    mean  /= volSum;  
  }
  else
  {
    mean = VDY_ZERO_F;
  }
  
  return mean;
}


/* **********************************************************************
	Unit Design for vdyHistCalcMedian is found in vdy.h
**************************************************************************** */
float32 vdyHistCalcMedian(const VDYHistogram_t *hist)
{
  uint32 idx;
  float32  median;
  float32  volSum = VDY_ZERO_F;
  float32  rank;
  float32  bwdth;
  boolean checkagain;

  /* Calculate median rank */
  rank = VDY_FIFTY_CENT * hist->Sum;
  
  /* First bin exceeding accumulated sum is median */  
  // To avoid floating point comparison in for loop Misra issue using checkagain
   checkagain = (boolean)((volSum < rank) ? TRUE : FALSE );

  for(idx = VDY_ZERO_U; (idx < hist->Size) && (checkagain == (boolean)TRUE); idx++)
  {
    volSum += hist->Volume[idx];
	checkagain = (boolean)((volSum < rank) ? TRUE : FALSE );
  }
  
  /* get median range value */
  if(idx > VDY_ZERO_U)
  {
	idx--;
  }
  median = hist->Range[idx];

  /* Determine current bin width */
  bwdth = hist->Range[idx + VDY_ONE_U] - hist->Range[idx];
  
  /* improve value by linear interpolation */
  median += (-(VDY_FIFTY_CENT) * bwdth) + ((((rank - (volSum - hist->Volume[idx])) - VDY_FIFTY_CENT) * bwdth) / hist->Volume[idx]);
  
  return (median);
}


#if ( (!defined(CFG_VDY_POLYSPACE_ERROR_DISABLE)) || (!CFG_VDY_POLYSPACE_ERROR_DISABLE) )
/* **********************************************************************
	Unit Design for vdyHistCalcSum is found in vdy.h
**************************************************************************** */
float32 vdyHistCalcSum(const VDYHistogram_t *hist)
{
  float32  sum = VDY_ZERO_F;
  uint32 idx = VDY_ZERO_U;

  while(idx < hist->Size)
  {
    sum += hist->Volume[idx];
	idx = idx + VDY_ONE_U;
  }
  return sum;
}

#endif


/* **********************************************************************
	Unit Design for vdyStatIntervalInit is found in vdy.h
**************************************************************************** */
void vdyStatIntervalInit(VDYStatInterval_t *StatInterval)
{
  StatInterval->Sum         = VDY_ZERO_F;
  StatInterval->SqSum       = VDY_ZERO_F;
  StatInterval->Volume      = VDY_ZERO_F;
  StatInterval->Mean        = VDY_ZERO_F;
  StatInterval->Dev         = VDY_ZERO_F;

  return;
}


/* **********************************************************************
	Unit Design for vdyStatIntervalInitInput is found in vdy.h
**************************************************************************** */
void vdyStatIntervalInitInput(VDYStatInterval_t *StatInterval)
{
  StatInterval->Sum         = VDY_ZERO_F;
  StatInterval->SqSum       = VDY_ZERO_F;
  StatInterval->Volume      = VDY_ZERO_F;

  return;
}


/* **********************************************************************
	Unit Design for vdyStatIntervalAdd is found in vdy.h
**************************************************************************** */
void vdyStatIntervalAdd(VDYStatInterval_t *StatInterval, float32 Value, float32 Weight)
{
  StatInterval->Sum       += Value * Weight;
  StatInterval->SqSum     += SQR(Value) * Weight;
  StatInterval->Volume    += Weight;

  return;
}


/* **********************************************************************
	Unit Design for vdyStatIntervalReduce is found in vdy.h
**************************************************************************** */
void vdyStatIntervalReduce(VDYStatInterval_t *StatInterval, float32 Factor)
{
  StatInterval->Sum       *= Factor;
  StatInterval->SqSum     *= Factor;
  StatInterval->Volume    *= Factor;

  return;
}


/* **********************************************************************
	Unit Design for vdyStatIntervalMerge is found in vdy.h
**************************************************************************** */
void vdyStatIntervalMerge(VDYStatInterval_t *StatInterval_1,  const VDYStatInterval_t *StatInterval_2 )
{
  StatInterval_1->Sum    += StatInterval_2->Sum;
  StatInterval_1->SqSum  += StatInterval_2->SqSum;
  StatInterval_1->Volume += StatInterval_2->Volume;

  return;
}


/* **********************************************************************
	Unit Design for vdyStatIntervalMeanDev is found in vdy.h
**************************************************************************** */
void vdyStatIntervalMeanDev(VDYStatInterval_t *StatInterval)
{
  float32 Varianz;

  if (CML_f_IsNonZero(StatInterval->Volume))
  {
    StatInterval->Mean = StatInterval->Sum / StatInterval->Volume;

    Varianz = (StatInterval->SqSum / StatInterval->Volume) - SQR(StatInterval->Mean);

    if((CML_f_IsNonZero(Varianz)) && (Varianz > VDY_ZERO_F))
    {
      StatInterval->Dev = VDY_SQRT(Varianz);
    }
    else
    {
      StatInterval->Dev = VDY_ZERO_F;
    }
  }
  else
  {
    StatInterval->Dev   = VDY_ZERO_F;
  }

  return;
}


/* **********************************************************************
	Unit Design for vdyStatIntervalPrealloc is found in vdy.h
**************************************************************************** */
void vdyStatIntervalPrealloc(VDYStatInterval_t *StatInterval,float32 Mean, float32 Volume, float32 Dev)
{
  /* Sum from mean with the assumption that volume equal to number */
  StatInterval->Sum  = Mean * Volume;

  /* Recalculate the square sum for standard deviation */
  StatInterval->SqSum = SQR(Dev) + SQR(Mean);
  StatInterval->SqSum = StatInterval->SqSum * Volume;

  /* Weightning is not considered */
  StatInterval->Volume = Volume;

  return;
}


/* **********************************************************************
	Unit Design for vdyHpSort is found in vdy.h
**************************************************************************** */
void vdyHpSort(uint32 no, float32 ra[])
{
  uint32 i, ir, j, k;
  float32  rra;

  if (no > 1u)
  {
    boolean finish = (boolean)FALSE;
    
    k  = no>>1uL;
    ir = no - 1u;

    while (finish == (boolean)FALSE)
    {
      if (k > 0u)
      {
        /* Still in hiring phase */
        k--;
        rra = ra[k];
      }
      else
      {
        /* In retirement-and-promotion phase    */
        rra    = ra[ir];      /*   Clear a space at end of array      */
        ra[ir] = ra[0];       /*   Retire the top of the heap into it */
		if(ir > 0u )
		{
			ir--;
		}
        if (ir == 0u)
        {    
          /*   Done with the last promotion       */
          ra[0] = rra;        /*   The least component worker of all  */
          finish = (boolean)TRUE;
        }
      }
      if (finish == (boolean)FALSE)
      {
        boolean b_Aborted = (boolean)FALSE;
        
        i = k;                  /* Whether in the hiring phase or promotion phase, we */
        j = k + k;              /* here set up to sift down element rra to its proper level */
      
        while ( (b_Aborted == (boolean)FALSE) && (j <= ir) )
        {
          if ((j < ir) && (ra[j] < ra[j+1u]))
          {
            /* Compare to the better underling */
            j++;
          }
          if (rra < ra[j])
          {
            /* Demote rra */
            ra[i] = ra[j];
            i = j;
            if (j > 0U)
            {
              j = j<<1U;
            }
            else
            {
              j = 1U;
            }
          }
          else
          {
            /* Found rra's level. Terminate the sift-down */
            b_Aborted = (boolean)TRUE;
          }
        }
        /* Put rra into its slot */
        ra[i] = rra;
      }
    }
  }
  return;
}


/* **********************************************************************
	Unit Design for vdyHpSortInd is found in vdy.h
**************************************************************************** */
void vdyHpSortInd(uint32 no, const float32 ra[], uint32 idx[])
{
  uint32 i, ir, j, k, ridx;
  
  /* Initialize index array */
  for (i=0U; i < no; i++)
  {
    idx[i] = i;
  }
  
  if (no > 1u)
  {
    boolean finish = (boolean)FALSE;
  
    k = no>>1;
    ir = no - 1u;
  
    while (finish == (boolean)FALSE)
    {
      if (k > 0u)
      {
        /* Still in hiring phase */
        k--;
        ridx = idx[k];
      }
      else
      {
        /* In retirement-and-promotion phase */
        ridx    = idx[ir];  /* Clear a space at end of array */
        idx[ir] = idx[0];   /* Retire the top of the heap into it */
		if(ir > 0u )
		{
			ir--;
		}
        if (ir == 0u)
        {
          /* Done with the last promotion */
          idx[0] = ridx;    /* The least component worker of all */
          finish = (boolean)TRUE;          
        }
      }
      if (finish == (boolean)FALSE)
      {
        boolean b_Aborted = (boolean)FALSE;
        
        i = k;                    /* Whether in the hiring phase or promotion phase, we */
        j = k + k;                /* here set up to sift down element rra to its proper level */
        while ( (b_Aborted == (boolean)FALSE) && (j <= ir) )
        {
          if ( (j < ir) && (ra[idx[j]] < ra[idx[j+1u]]) )   /* Compare to the better underling */
          {
            j++;
          }
          if (ra[ridx] < ra[idx[j]])      /* Demote rra */
          {
            idx[i] = idx[j];
            i = j;
            if (j > 0u)
            {
              j = j<<1U;
            }
            else
            {
              j = 1U;
            }
          }
          else
          {                /* Found rra's level. Terminate the sift-down */
            b_Aborted = (boolean)TRUE;
          }
        }
        /* Put rra into its slot */
        idx[i] = ridx;
      }
    }
  }
  return;
}


/* **********************************************************************
	Unit Design for vdyHpSortIndU16 is found in vdy.h
**************************************************************************** */
void vdyHpSortIndU16(uint32 no, const uint16 ra[], uint8 idx[])
{
  uint32 i, ir, j, k, ridx;
  
  /* Initialize index array */
  for (i=0U; i < no; i++)
  {
    idx[i] = (uint8) i;
  }
  
  if (no > 1u)
  {
    boolean finish = (boolean)FALSE;
  
    k = no>>1;
    ir = no - 1u;
  
    while (finish == (boolean)FALSE)
    {
      if (k > 0u)
      {
        /* Still in hiring phase */
        k--;
        ridx = idx[k];
      }
      else
      {
        /* In retirement-and-promotion phase */
        ridx    = idx[ir];  /* Clear a space at end of array */
        idx[ir] = idx[0];   /* Retire the top of the heap into it */
		if(ir > 0u)
		{
			ir--;
		}
        if (ir == 0u)
        {
          /* Done with the last promotion */
          idx[0] = (uint8) ridx;    /* The least component worker of all */
          finish = (boolean)TRUE;          
        }
      }
      if (finish == (boolean)FALSE)
      {
        boolean b_Aborted = (boolean)FALSE;
        
        i = k;                    /* Whether in the hiring phase or promotion phase, we */
        j = k + k;
        while ( (b_Aborted == (boolean)FALSE) && (j <= ir) )
        {
          if ( (j < ir) && (ra[idx[j]] < ra[idx[j+1u]]) )   /* Compare to the better underling */
          {
            j++;
          }
          if (ra[ridx] < ra[idx[j]])      /* Demote rra */
          {
            idx[i] = idx[j];
            i = j;
            if (j > 0u)
            {
              j = (j<<1U);
            }
            else
            {
              j = 1U;
            }
          }
          else
          {
            /* Found rra's level. Terminate the sift-down */
            b_Aborted = (boolean)TRUE;
          }
        }
        /* Put rra into its slot */
        idx[i] = (uint8) ridx;
      }
    }
  }
  return;
}


/* **********************************************************************
	Unit Design for vdyHpSortIndF32 is found in vdy.h
**************************************************************************** */
void vdyHpSortIndF32(uint32 no, const float32 ra[], uint8 idx[])
{
  uint32 i, ir, j, k, ridx;
  
  /* Initialize index array */
  for (i=0U; i < no; i++)
  {
    idx[i] = (uint8) i;
  }
  
  if (no > 1u)
  {
    boolean finish = (boolean)FALSE;
  
    k = no>>1;
    ir = no - 1u;
  
    while (finish == (boolean)FALSE)
    {
      if (k > 0u)
      {
        /* Still in hiring phase */
        k--;
        ridx = idx[k];
      }
      else
      {
        /* In retirement-and-promotion phase */
        ridx    = idx[ir];  /* Clear a space at end of array */
        idx[ir] = idx[0];   /* Retire the top of the heap into it */
		if(ir > 0u )
		{
			ir--;
		}
        if (ir == 0u)
        {
          /* Done with the last promotion */
          idx[0] = (uint8) ridx;    /* The least component worker of all */
          finish = (boolean)TRUE;          
        }
      }
      if (finish == (boolean)FALSE)
      {
        boolean b_abort = (boolean)FALSE;
        
        i = k;                    /* Whether in the hiring phase or promotion phase, we */
        j = k + k;
        while ( (b_abort == (boolean)FALSE) && (j <= ir) )
        {
          if ( (j < ir) && (ra[idx[j]] < ra[idx[j+1u]]) ) /* Compare to the better underling */
          {
            j++;
          }
          if (ra[ridx] < ra[idx[j]])   /* Demote rra */
          {
            idx[i] = idx[j];
            i = j;
            if (j > 0u)
            {
              j = (j<<1U);
            }
            else
            {
              j = 1U;
            }
          }
          else
          {
            /* Found rra's level. Terminate the sift-down */
            b_abort = (boolean)TRUE;
          }
        }
        /* Put rra into its slot */
        idx[i] = (uint8) ridx;
      }
    }
  }
  return;
}


/* **********************************************************************
	Unit Design for vdyDiscretize is found in vdy.h
**************************************************************************** */
float32 vdyDiscretize(float32 value, float32 interval)
{
  sint32 intValue;

  value /= interval;
  /* <ln_offset:+1 MISRA Rule 10.4: reviewer name: Jochen Spruck date: 05-10-2010 reason: For rounding from float to int a cast to int is needed */
  intValue  = ROUND_TO_INT( value );
  value  = interval * (float32) intValue;

  return (value);
}


/* **********************************************************************
	Unit Design for vdyInitCurve is found in vdy.h
**************************************************************************** */
void vdyInitCurve(VDYOutCurve_t *Course)
{
  Course->Curve     = VDY_ZERO_F;
  Course->Gradient  = VDY_ZERO_F;
  Course->Variance  = VDY_ZERO_F;

  return;
}


/* **********************************************************************
	Unit Design for vdyCalcGradient is found in vdy.h
**************************************************************************** */
fGradient_t vdyCalcGradient(float32 NewValue, float32 OldValue)
{
  fTime_t     CycleTime;
  fGradient_t Gradient;

  CycleTime = vdyGetCycleTime();

  /* Calculate gradient (cycletime cannot be zero, has been set to 20ms in that case) */
  Gradient = (NewValue - OldValue) / (CycleTime);

  return (Gradient);
}


/* **********************************************************************
	Unit Design for vdyCalcDistStblGrad is found in vdy.h
**************************************************************************** */
void vdyCalcDistStblGrad(fGradient_t GradMax, fGradient_t Grad, fGradient_t *GradAbsOld, fDistance_t *DeltaDist, fVelocity_t VehSpeed)
{
  const fTime_t     PeakFilterTime_c = VDY_ONE_F;      /* Filter time constant of peak filter */
  const fDistance_t maxDist_c        = 150.F;     /* Distance saturation value */
  fTime_t CycleTime;

  CycleTime = vdyGetCycleTime();

  /* Peak filtering of absolut gradient value  */
  if( CML_f_Abs(Grad) > *GradAbsOld )
  {
    *GradAbsOld = CML_f_Abs(Grad);
  }
  else
  {
    *GradAbsOld = VDY_IIR_FILTER(CML_f_Abs(Grad), *GradAbsOld, PeakFilterTime_c, CycleTime);
  }

  /* Test if gradient is within stable range */
  if( *GradAbsOld < GradMax )
  {
    /* If gradient is within stable range accumulate distance with saturation */
    if (*DeltaDist < maxDist_c)
    {
      *DeltaDist += VehSpeed * CycleTime;
    }
  }
  else
  {
    /* Gradient is too big i.e. instable, Reset accumulated distance */
    *DeltaDist = VDY_ZERO_F;
  }

  return;
}


/* **********************************************************************
	Unit Design for vdyCalcCycleDistance is found in vdy.h
**************************************************************************** */
fDistance_t vdyCalcCycleDistance(fVelocity_t VehSpeed)
{
  fTime_t     CycleTime;            /* Cycle time */
  fDistance_t CicDist;              /* Driven Distance [m] */

  CycleTime = vdyGetCycleTime();

  CicDist = CycleTime * VehSpeed;

  return (CicDist);
}


/* **********************************************************************
	Unit Design for vdyLFunction is found in vdy.h
**************************************************************************** */
float32 vdyLFunction(float32 Input, float32 InputMin,float32 InputMax,  float32 OutputMin,float32 OutputMax)
{
  float32  Output;        /*  Omax -------/=== */
  float32  Gradient;      /*             /|    */
  float32  Section;       /*            / |    */
                          /*           /  |    */
                          /*          /   |    */
                          /*  Omin ==/    |    */
                          /*         |    |    */
                          /*        Imin Imax  */


  Gradient = (OutputMax-OutputMin)/(InputMax-InputMin);  /* slope            */
  Section  = OutputMin - (Gradient * InputMin);          /* y-axis intercept */

  Output = (Gradient * Input) + Section;                 /* Linear equation */

  /* Limit values */
  if (OutputMin < OutputMax)
  {                                                        /*     /-- */
    Output = MINMAX_FLOAT(OutputMin, OutputMax, Output);         /* --/     */
  }
  else
  {                                                        /* --\    */
    Output = MINMAX_FLOAT(OutputMax, OutputMin, Output);         /*    \-- */
  }
  return (Output);
}


/* **********************************************************************
	Unit Design for vdyLinInterp1 is found in vdy.h
**************************************************************************** */
float32 vdyLinInterp1(const float32 *xn, const float32 *yn, const uint32 num, float32 xi)
{
  uint32 ni;
  float32 yi;  
  
  /* find range on x-axis */  
  ni = VDY_ONE_U;
  
  /* PRQA S 3350 EOF */
  /* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: Functional Safe */
  while ( (ni < num) && (xi > *xn) )
  {
    xn++; 
    yn++;
    ni++;
  }   
 
  /* calculate y */
  if(ni > VDY_ONE_U)
  { 
    float32  x2;
    float32  y2;  
    float32  x1;
    float32  y1;

    /* take current table position and previous table position for interpolation */
    x1 = *(xn - 1UL);
    y1 = *(yn - 1UL);
    
    x2 = *(xn);
    y2 = *(yn);    

    if (x1 < x2)
    {
      if( xi < x2 )
      {
        /* interpolation */
        yi = ((( xi - x1) * (y2 - y1)) / (x2 - x1)) + y1;
      }
      else
      {
        /* if x > current (last) table position use last y value from table */
        yi = y2;
      } 
    }
    else
    {
      yi = y1;
    }
  }
  else
  {
    /*if x was smaller than than first value in table --> take first y value from table*/
    yi = *(yn);
  }
  return yi;  
}


/* **********************************************************************
	Unit Design for vdyFilterCycleTime is found in vdy.h
**************************************************************************** */
float32 vdyFilterCycleTime(float32 New, float32 Old, fTime_t TimeConst)
{
  fTime_t CycleTime;
  float32   Value;

  CycleTime = vdyGetCycleTime();

  Value = VDY_IIR_FILTER(New, Old, TimeConst, CycleTime);

  return(Value);
}


/* **********************************************************************
	Unit Design for vdyDifferentiateCycleTime is found in vdy.h
**************************************************************************** */
float32 vdyDifferentiateCycleTime(float32 newIn, float32 oldIn, float32 oldOut, fTime_t TimeConst)
{
  fTime_t CycleTime;
  float32   Value;

  /* Get cycle time */
  CycleTime = vdyGetCycleTime();

  /* Calculate new filter output */
  Value = CycleTime + TimeConst;
  if (CML_f_IsNonZero(Value) && (Value > VDY_ZERO_F))
  {
    Value = (VDY_ONE_F / Value) * ( (newIn - oldIn) + (TimeConst * oldOut));
  }
  else
  {
    Value = oldOut;  /* use old value if new value cannot be calculated */
  }

  return(Value);
}


/* **********************************************************************
	Unit Design for vdyFilterOffset is found in vdy.h
**************************************************************************** */
float32 vdyFilterOffset(float32 newin, float32 oldflt, float32 fconst)
{
  float32 coeff;
  float32 fltVal;
  
  coeff = VDY_ONE_F - VDY_EXP(-fconst);

  fltVal = oldflt + (coeff * (newin - oldflt));

  return fltVal;
}


/* **********************************************************************
	Unit Design for vdyCheckCurve is found in vdy.h
**************************************************************************** */
VDYCrvStatus_t vdyCheckCurve(const VDYOutCurve_t *Course, fCurve_t MaxCurve, fQuality_t MinQuality)
{
  VDYCrvStatus_t Status;               /* Output status */

  if(Course->Variance >= MinQuality)
  {
    /* Curve has sufficient quality for range test */
    if (CML_f_Abs(Course->Curve) <= MaxCurve )
    {
      Status = (VDYCrvStatus_t) VDY_CRV_OK;      /* Curvature within limit */
    }
    else
    {
      Status = (VDYCrvStatus_t) VDY_CRV_NOTOK;   /* Curvature outside the limit */
    }
  }
  else
  {
    /* Insufficient quality  */
    Status = (VDYCrvStatus_t) VDY_CRV_DONT_KNOW;
  }
  return (Status);
}


/* **********************************************************************
	Unit Design for vdyGetCurveDir is found in vdy.h
**************************************************************************** */
VDYCrvDirStatus_t vdyGetCurveDir(const VDYOutCurve_t *Course, fCurve_t ThrdCurve, fQuality_t MinQuality)
{
  VDYCrvDirStatus_t Status;               /* Direction output value */

  if (Course->Variance >= MinQuality)
  {
    /* Curve has sufficient quality for direction decision */
    if (Course->Curve < -ThrdCurve )
    {
      Status = (VDYCrvDirStatus_t) CRV_DIR_RIGHT;
    }
    else if (Course->Curve > ThrdCurve)
    {
      Status = (VDYCrvDirStatus_t) CRV_DIR_LEFT;
    }
    else
    {
      Status = (VDYCrvDirStatus_t) CRV_DIR_STRAIGHT;
    }
  }
  else
  {
    Status = (VDYCrvDirStatus_t) CRV_DIR_DONT_KNOW;  /* insufficient quality */
  }
  return (Status);
}


/* **********************************************************************
	Unit Design for vdyFormatCurve is found in vdy.h
**************************************************************************** */
void vdyFormatCurve(fCurve_t *Curve)
{
  if(  CML_f_Abs(*Curve) < (VDY_ONE_F / VDY_MAX_RADIUS))
  {
    *Curve = VDY_ZERO_F;
  }
  else if( *Curve > (VDY_ONE_F / VDY_MIN_RADIUS) )
  {
     *Curve = VDY_ONE_F / VDY_MIN_RADIUS;
  }
  else if( *Curve < (-(VDY_ONE_F) / VDY_MIN_RADIUS) )
  {
     *Curve = -(VDY_ONE_F) / VDY_MIN_RADIUS;
  }
  else
  {
    /* do nothing */
  }
  return;
}


/* **********************************************************************
	Unit Design for vdyCurveToRadius is found in vdy.h
**************************************************************************** */
void vdyCurveToRadius(fCurve_t Curve, fRadius_t *Radius)
{
  if( CML_f_Abs(Curve) < (VDY_ONE_F/VDY_MAX_RADIUS))
  {
    /* Absolute curvature below minimum zero threshold value */
    *Radius = VDY_ZERO_F;
  }
  else if( Curve > (VDY_ONE_F/VDY_MIN_RADIUS) )
  {
    /* Curvature above pos. maximum threshold value */
    *Radius = VDY_MIN_RADIUS;
  }
  else if( Curve < (-(VDY_ONE_F)/VDY_MIN_RADIUS) )
  {
    /* Curvature below neg. maximum threshold value */
    *Radius = -VDY_MIN_RADIUS;
  }
  else
  {
    *Radius = VDY_ONE_F / Curve;
  }
  return;
}


#if (CFG_VDY_FPM_754)
/* **********************************************************************
	Unit Design for vdyInvSqrt is found in vdy.h
**************************************************************************** */
float32 vdyInvSqrt(float32 x)
{
  float32  xhalf = VDY_FIFTY_CENT * x;
  uint32 uiVal;
  /* <ln_offset:+1 MISRA Rule 11.4: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */
  uiVal = RE_INTRPR_UI32(x);         /* Get bits of floating value MISRA Rule 1.2: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */
  uiVal = VDY_MAGIC_NUM - (uiVal >> VDY_ONE_U); /* Gives initial guess y0 with magic number */
  /* <ln_offset:+1 MISRA Rule 11.4: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */
  x     = RE_INTRPR_F32(uiVal);      /* Convert bits back to float  MISRA Rule 1.2: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */

  x *= (VDY_ONE_FIFTY_CENT - (xhalf*x*x));         /* Newton steps, repeating increases accuracy */
  x *= (VDY_ONE_FIFTY_CENT - (xhalf*x*x));
  x *= (VDY_ONE_FIFTY_CENT - (xhalf*x*x));
  
  return x;
}


/* **********************************************************************
	Unit Design for vdySqrt is found in vdy.h
**************************************************************************** */
float32 vdySqrt(float32 x)
{
  uint32 uiVal;

  /* <ln_offset:+1 MISRA Rule 11.4: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */
  uiVal = (RE_INTRPR_UI32(x) >> THREE_BYTE_SHIFT) & VDY_MAX_U; /*  MISRA Rule 1.2: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */

  if (VDY_ZERO_U == uiVal)
  {
    x = VDY_ZERO_F;
  }
  else
  {
    x *= vdyInvSqrt(x);
  }
  return x;
}


/* **********************************************************************
	Unit Design for vdyExp is found in vdy.h
**************************************************************************** */
float32 vdyExp(float32 x) 
{
  float32 y, i2k_2;           /* Function result value */
  sint32 i2k = 0;     /* Integer part for two base exponent */
  sint32 xsb;          /* Sign bit: xsb=0 -> x>=0, xsb=1 -> x<0 */
  uint32 uiVal, xsb_2;        /* Integer interpretation of float value */

  /* Reinterprete value as Dword */
  /* <ln_offset:+1 MISRA Rule 11.4: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */
  uiVal = RE_INTRPR_UI32(x); /* MISRA Rule 1.2: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */

  /* PRQA S 2985 EOF */
  /* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: This operation is intended */
  xsb_2 = ((uiVal >> SIGN_BIT_SHIFT) & VDY_ONE_U);   /* extract sign bit of input value MISRA Rule 10.3: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */
  xsb = (sint32)xsb_2;
  uiVal &= SIGN_BIT_MASK;             /* remove sign bit x = |x| */

  /*  Reduce x to an r so that |r| <= 0.5*ln2 ~ 0.3465735903F. Given x, 
      find r and integer k such that x = k*ln2 + r,  |r| <= 0.5*ln2. */

  /* Test if argument is outside the desired reduction range */
  if( uiVal > HALF_OF_LN_OF_2 )     /* |x| > 0.5*ln2 */
  {
    /* Natural logarithm of 2 as high and low value to increase accuracy for both sign. */
    const float32 ln2HiPrt_c[VDY_TWO] = { +6.9313812256e-01F, -6.9313812256e-01F };
    const float32 ln2LoPrt_c[VDY_TWO] = { +9.0580006145e-06F, -9.0580006145e-06F };

    float32 hi = VDY_ZERO_F;  /* High part of reduced value */
    float32 lo = VDY_ZERO_F;  /* Low part of reduced value */

    if ( uiVal < ONE_AND_A_HALF_OF_LN_2 )      /* |x| < 1.5 * ln2 */
    {
      /*  Simple reduction via addition or substraction */
      hi = x - ln2HiPrt_c[xsb]; 
      lo = ln2LoPrt_c[xsb]; 
      i2k = 1 - (xsb + xsb);
    } 
    else
    {
      /* Complete reduction is necessary */
      const float32 invln2_c  = 1.4426950216F; /* 1/ln2 */
      const float32 halF_c[VDY_TWO] = {0.5F,-0.5F};  
      
      /* Reduce to 0..ln2 and shift to -0.5*ln2 .. +0.5*ln2 */
      /* <ln_offset:+1 MISRA Rule 10.4: reviewer name: Jochen Spruck date: 05-10-2010 reason: For rounding from float to int a cast to int is needed */
	  i2k_2 = (invln2_c*x) + halF_c[xsb];
      i2k  =  (sint32)i2k_2 ;
      hi = x - ( ((float32)i2k) * ln2HiPrt_c[0]);
      lo = ((float32)i2k) * ln2LoPrt_c[0];
    }
    x  = hi - lo;  /* Combine both parts */
  }
  else
  {
    /* Input argument is already within reduction range.  */
    i2k = 0;
  }

  /* x is now in primary range */
  { /*  Approximation of exp(r) by a polynom on the interval [-0.34658,+0.34658] */
    const float32 a1_c = 0.0013793724F;  
    const float32 a2_c = 0.0083682816F;  
    const float32 a3_c = 0.0416686266F;  
    const float32 a4_c = 0.1666652424F;  
    const float32 a5_c = 0.4999999297F;
    
    /* Calculate polynom with horner schema */
    y = (((((((((((x*a1_c) + a2_c)*x) + a3_c)*x) + a4_c)*x) + a5_c)*x) + VDY_ONE_F)*x) + VDY_ONE_F;
  }
    
  /*  Scale back to obtain exp(x) = 2^k * exp(r) */
  /* <ln_offset:+1 MISRA Rule 11.4: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */
  uiVal = RE_INTRPR_UI32(y); /* MISRA Rule 1.2: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */
  /* <ln_offset:+1 MISRA Rule 11.4: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */
  uiVal += (  (RE_INTRPR_UI32(i2k)) << VDY_TWENTY_THREE_U);
  /* <ln_offset:+1 MISRA Rule 11.4: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */
  y = RE_INTRPR_F32(uiVal);  /* MISRA Rule 1.2: reviewer name: Jochen Spruck date: 11-11-2010 reason: proven in use */

  return y;
}

#endif

/** @} */ 
/* EOF */
