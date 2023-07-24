/* ************************************************************************** *
  COMPANY:              Continental Automotive

  PROJECT:              MFC400 / MFS400 / MFL400

  CPU:                  SoC VME / SoC VH

  MODULNAME:            EDMA Service (Inline stuff)

  DESCRIPTION:          This module contains all inline stuff of the EDMA
                        service.

  CREATION DATE:        2015/02/23

  VERSION:              $Revision: 1.1 $


  CHANGES:
  ---*/ /*---
  CHANGE:               $Log: edma_service_inline.h  $
  CHANGE:               Revision 1.1 2020/05/08 04:23:35CEST Wang, Jianan02 (uia93585) (uia93585) 
  CHANGE:               Initial revision
  CHANGE:               Member added to project /ADAS/SW/Integration/RTE_RunTimeEnvironment/04_Engineering/00_Projects/MFC431VA21/common/RTE_VH/algo/project.pj
  CHANGE:               Revision 1.1 2019/04/29 10:32:43CEST Wang, Jianan02 (uia93585) (uia93585) 
  CHANGE:               Initial revision
  CHANGE:               Member added to project /ADAS/SW/Integration/RTE_RunTimeEnvironment/04_Engineering/00_Projects/MFC431VA10/common/RTE_VH/algo/project.pj
  CHANGE:               Revision 1.1 2016/11/25 12:22:14CET Baur, Magnus (uidr0839) 
  CHANGE:               Initial revision
  CHANGE:               Member added to project /ADAS/SW/Integration/RTE_RunTimeEnvironment/04_Engineering/00_Projects/MFC431/common/RTE_VH/algo/project.pj
  CHANGE:               Revision 1.5 2015/02/23 15:16:44CET Scherer, Michael (uidu3109) 
  CHANGE:               * Remove MISRA violations
  CHANGE:               - Added comments -  uidu3109 [Feb 23, 2015 3:16:45 PM CET]
  CHANGE:               Change Package : 213161:1 http://mks-psad:7002/im/viewissue?selection=213161
* *************************************************************************** */

#ifndef edma_service_H
#define edma_service_H

#ifdef __cplusplus
extern "C"
{
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

typedef struct  {
    volatile uint32 OPT;
    volatile uint32 SRC;
    volatile uint32 A_B_CNT;
    volatile uint32 DST;
    volatile uint32 SRC_DST_BIDX;
    volatile uint32 LINK_BCNTRLD;
    volatile uint32 SRC_DST_CIDX;
    volatile uint32 CCNT;
} EDMASRC_CSL_EdmaccParamentryRegs;

typedef struct {
   EDMASRC_CSL_EdmaccParamentryRegs *PaRAMEntry;  /* Startaddress of PaRAMEntry */
   volatile uint32 *shadowRegs_IPR;               /* Register for waiting EDMA is ready (Interrupt Pending Register) */
   volatile uint32 *shadowRegs_ICR;               /* Register for clearing the ready bit */
   volatile uint32 *shadowRegs_ESR;               /* Register for Triggering the EDMA by the CPU */
   uint32 TriggerMask;                            /* Mask to Trigger EDMA */
   uint32 WaitMask;                               /* Mask for Waiting EDMA is ready */
   uint32 TCC;                                    /* Transfer complete code */
   uint32 lCh;                                    /* Channel id from TI EDMA function */
   sint32 ChIndex;                                /* Channel Index from EDMA Service functions */
   uint32 Flags;                                  /* reserved */
}AS_t_EdmaHandle;

typedef enum
{
  AS_e_EDMAFLAGS_DMA,            /* Type is EDMA */
  AS_e_EDMAFLAGS_QDMA            /* Type is QDMA */
}AS_t_EdmaFlags;

#ifdef _TMS320C6X
/*----ITCCHEN Tokens----*/
#define CSL_EDMACC_OPT_ITCCHEN_DISABLE   0x00000000u
#define CSL_EDMACC_OPT_ITCCHEN_ENABLE    0x00000001u

#define CSL_EDMACC_OPT_TCCHEN_MASK       0x00400000u
#define CSL_EDMACC_OPT_TCCHEN_SHIFT      0x00000016u
#define CSL_EDMACC_OPT_TCCHEN_RESETVAL   0x00000000u

/*----TCCHEN Tokens----*/
#define CSL_EDMACC_OPT_TCCHEN_DISABLE    0x00000000u
#define CSL_EDMACC_OPT_TCCHEN_ENABLE     0x00000001u

#define CSL_EDMACC_OPT_ITCINTEN_MASK     0x00200000u
#define CSL_EDMACC_OPT_ITCINTEN_SHIFT    0x00000015u
#define CSL_EDMACC_OPT_ITCINTEN_RSTVAL   0x00000000u

/*----ITCINTEN Tokens----*/
#define CSL_EDMACC_OPT_ITCINTEN_DISABLE  0x00000000u
#define CSL_EDMACC_OPT_ITCINTEN_ENABLE   0x00000001u

#define CSL_EDMACC_OPT_TCINTEN_MASK      0x00100000u
#define CSL_EDMACC_OPT_TCINTEN_SHIFT     0x00000014u
#define CSL_EDMACC_OPT_TCINTEN_RESETVAL  0x00000000u

/*----TCINTEN Tokens----*/
#define CSL_EDMACC_OPT_TCINTEN_DISABLE   0x00000000u
#define CSL_EDMACC_OPT_TCINTEN_ENABLE    0x00000001u

#define CSL_EDMACC_OPT_WIMODE_MASK       0x00080000u
#define CSL_EDMACC_OPT_WIMODE_SHIFT      0x00000013u
#define CSL_EDMACC_OPT_WIMODE_RESETVAL   0x00000000u

/*----WIMODE Tokens----*/
#define CSL_EDMACC_OPT_WIMODE_NORMAL     0x00000000u
#define CSL_EDMACC_OPT_WIMODE_WI         0x00000001u

#define CSL_EDMACC_OPT_TCC_MASK          0x0003F000u
#define CSL_EDMACC_OPT_TCC_SHIFT         0x0000000Cu
#define CSL_EDMACC_OPT_TCC_RESETVAL      0x00000000u

#define CSL_EDMACC_OPT_TCCMODE_MASK      0x00000800u
#define CSL_EDMACC_OPT_TCCMODE_SHIFT     0x0000000Bu
#define CSL_EDMACC_OPT_TCCMODE_RESETVAL  0x00000000u

/*----TCCMODE Tokens----*/
#define CSL_EDMACC_OPT_TCCMODE_NORMAL    0x00000000u
#define CSL_EDMACC_OPT_TCCMODE_EARLY     0x00000001u

#define CSL_EDMACC_OPT_FWID_MASK         0x00000700u
#define CSL_EDMACC_OPT_FWID_SHIFT        0x00000008u
#define CSL_EDMACC_OPT_FWID_RESETVAL     0x00000000u

/*----FWID Tokens----*/
#define CSL_EDMACC_OPT_FWID_8            0x00000000u
#define CSL_EDMACC_OPT_FWID_16           0x00000001u
#define CSL_EDMACC_OPT_FWID_32           0x00000002u
#define CSL_EDMACC_OPT_FWID_64           0x00000003u
#define CSL_EDMACC_OPT_FWID_128          0x00000004u
#define CSL_EDMACC_OPT_FWID_256          0x00000005u

#define CSL_EDMACC_OPT_STATIC_MASK       0x00000008u
#define CSL_EDMACC_OPT_STATIC_SHIFT      0x00000003u
#define CSL_EDMACC_OPT_STATIC_RESETVAL   0x00000000u

/*----STATIC Tokens----*/
#define CSL_EDMACC_OPT_STATIC_NORMAL     0x00000000u
#define CSL_EDMACC_OPT_STATIC_STATIC     0x00000001u

#define CSL_EDMACC_OPT_SYNCDIM_MASK      0x00000004u
#define CSL_EDMACC_OPT_SYNCDIM_SHIFT     0x00000002u
#define CSL_EDMACC_OPT_SYNCDIM_RESETVAL  0x00000000u

/*----SYNCDIM Tokens----*/
#define CSL_EDMACC_OPT_SYNCDIM_ASYNC     0x00000000u
#define CSL_EDMACC_OPT_SYNCDIM_ABSYNC    0x00000001u

#define CSL_EDMACC_OPT_DAM_MASK          0x00000002u
#define CSL_EDMACC_OPT_DAM_SHIFT         0x00000001u
#define CSL_EDMACC_OPT_DAM_RESETVAL      0x00000000u

/*----DAM Tokens----*/
#define CSL_EDMACC_OPT_DAM_INCR          0x00000000u
#define CSL_EDMACC_OPT_DAM_FIFO          0x00000001u

#define CSL_EDMACC_OPT_SAM_MASK          0x00000001u
#define CSL_EDMACC_OPT_SAM_SHIFT         0x00000000u
#define CSL_EDMACC_OPT_SAM_RESETVAL      0x00000000u

/*----SAM Tokens----*/
#define CSL_EDMACC_OPT_SAM_INCR          0x00000000u
#define CSL_EDMACC_OPT_SAM_FIFO          0x00000001u

#define CSL_EDMACC_OPT_RESETVAL          0x00000000u

/* The Field MaKe (Raw) macro. Re-named to make it MISRA conform. */
#define CSL_FMKR_MISRA(msb, lsb, val) \
    (((val) & (((uint32)1 << ((msb) - (lsb) + (uint32)1)) - (uint32)1)) << (lsb))

/* Used for creating the options entry in the PaRAM */
#define CSL_EDMA_OPT_MAKE(itccEn,tccEn,itcintEn,tcintEn,tcc,tccMode,fwid,stat,syncDim,dam,sam) \
(uint32) (                                            \
     CSL_FMKR_MISRA((uint32)23,(uint32)23,(itccEn))   \
    |CSL_FMKR_MISRA((uint32)22,(uint32)22,(tccEn))    \
    |CSL_FMKR_MISRA((uint32)21,(uint32)21,(itcintEn)) \
    |CSL_FMKR_MISRA((uint32)20,(uint32)20,(tcintEn))  \
    |CSL_FMKR_MISRA((uint32)17,(uint32)12,(tcc))      \
    |CSL_FMKR_MISRA((uint32)11,(uint32)11,(tccMode))  \
    |CSL_FMKR_MISRA((uint32)10,(uint32)8 ,(fwid))     \
    |CSL_FMKR_MISRA((uint32)3 ,(uint32)3 ,(stat))     \
    |CSL_FMKR_MISRA((uint32)2 ,(uint32)2 ,(syncDim))  \
    |CSL_FMKR_MISRA((uint32)1 ,(uint32)1 ,(dam))      \
    |CSL_FMKR_MISRA((uint32)0 ,(uint32)0 ,(sam)) )

/* ====================================================================== */
/*                           Function prototypes                          */
/* ====================================================================== */
inline void AS_v_EdmaSubmit(const AS_t_EdmaHandle * const p_Edma);
inline void AS_v_EdmaWait(const AS_t_EdmaHandle * const p_Edma);
inline void AS_v_EdmaSetParamsCopy2D(const AS_t_EdmaHandle * const p_Edma, const void * const p_Dst, const void * const p_Src, sint16 s_DstPitch, sint16 s_SrcPitch, uint16 u_Width, uint16 u_Height);

/* ====================================================================== */
/*                           Function definitions                         */
/* ====================================================================== */
inline void AS_v_EdmaSubmit(const AS_t_EdmaHandle * const p_Edma)
{
   *p_Edma->shadowRegs_ESR = p_Edma->TriggerMask;
}

inline void AS_v_EdmaWait(const AS_t_EdmaHandle * const p_Edma)
{
  while ((*p_Edma->shadowRegs_IPR & p_Edma->WaitMask) != p_Edma->WaitMask)
  {
    /* Do Nothing. Wait for DMA completion */
  }
  *p_Edma->shadowRegs_ICR = p_Edma->WaitMask;
}

inline void AS_v_EdmaSetParamsCopy2D(const AS_t_EdmaHandle * const p_Edma, const void * const p_Dst, const void * const p_Src, sint16 s_DstPitch, sint16 s_SrcPitch, uint16 u_Width, uint16 u_Height)
{
   const uint32 tcc = p_Edma->TCC;
   uint32 optfield;
   EDMASRC_CSL_EdmaccParamentryRegs *PaRAM = p_Edma->PaRAMEntry;

   optfield = CSL_EDMA_OPT_MAKE( (uint32)CSL_EDMACC_OPT_ITCCHEN_DISABLE, \
                                 (uint32)CSL_EDMACC_OPT_TCCHEN_DISABLE,  \
                                 (uint32)CSL_EDMACC_OPT_ITCINTEN_DISABLE,\
                                 (uint32)CSL_EDMACC_OPT_TCINTEN_ENABLE,  \
                                 tcc,                                    \
                                 (uint32)CSL_EDMACC_OPT_TCCMODE_NORMAL,  \
                                 (uint32)CSL_EDMACC_OPT_FWID_32,         \
                                 (uint32)CSL_EDMACC_OPT_STATIC_STATIC,   \
                                 (uint32)CSL_EDMACC_OPT_SYNCDIM_ABSYNC,  \
                                 (uint32)CSL_EDMACC_OPT_DAM_INCR,        \
                                 (uint32)CSL_EDMACC_OPT_SAM_INCR );

   PaRAM->OPT          = optfield;
   PaRAM->SRC          = (uint32) p_Src;
   PaRAM->A_B_CNT      = ((uint32)u_Height << 16) | (uint32)u_Width;
   PaRAM->DST          = (uint32) p_Dst;
   PaRAM->SRC_DST_BIDX = ((uint32)s_DstPitch << 16) | (uint32)s_SrcPitch;
   PaRAM->LINK_BCNTRLD = 0xFFFFu;
   PaRAM->SRC_DST_CIDX = 0;
   PaRAM->CCNT         = 1;
}
#else
extern void AS_v_EdmaSubmit(AS_t_EdmaHandle *p_Edma);
extern void AS_v_EdmaWait(AS_t_EdmaHandle *p_Edma);
extern void AS_v_EdmaSetParamsCopy2D(AS_t_EdmaHandle *p_Edma, void *p_Dst, void *p_Src, sint16 s_DstPitch, sint16 s_SrcPitch, uint16 u_Width, uint16 u_Height);
#endif //##ifdef _TMS320C6X

#ifdef __cplusplus
}
#endif

#endif
