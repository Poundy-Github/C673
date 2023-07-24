-e      _reset_handler
-stack  0x2000
-heap   0x1000

MEMORY
{
    PAGE 0:
      VECMEM          : origin=0x80000000 length=0x00000100
      CMDMEM          : origin=0x80000100 length=0x00001000
      EXTMEM          : origin=0x80001100 length=0x00026f00
      DDR3_SHARED_EVE : origin=0x81030000 length=0x00fd0000

    PAGE 1:
      DATMEM          : origin=0x40020000 length=0x6000
      DATMEM_SCRATCH  : origin=0x40026000 length=0x2000     /* Algo is only allowed to take 0x2000 Bytes as scratch buf on ARP's DMEM */
      WMEM            : origin=0x40040000 length=0x7E00     /* Only 31.5 kB usable instead of 32kB due to HW bug */
      IMEMLA          : origin=0x40050000 length=0x4000
      IMEMHA          : origin=0x40054000 length=0x4000
      IMEMLB          : origin=0x40070000 length=0x4000
      IMEMHB          : origin=0x40074000 length=0x4000
      GEM0_L2_MEM     : origin=0x40800000 length=0x8000     /* Exactly what does this refer to? Does it exist on VisionMidEve?*/
      EXTDMEM         : origin=0x80030000 length=0x1000000
#ifdef AL_ETK_EVMHIL_VME
      /* VME scratchbuffer */
      EVE_OCMC1       : origin=0x400C0000 length=0x400      /* OCMC scratch buffer   1 KiB => use EVE internal OCMC RAM on VisionMidEve */
      EVE_OCMC2       : origin=0x400C0400 length=0x3A000    /* OCMC scratch buffer 232 KiB => use EVE internal OCMC RAM on VisionMidEve */
#else
      /* VH28 scratchbuffer */
      L3MEM_OCMC3_1   : origin=0x40500000 length=0x400      /* OCMC scratch buffer   1 KiB => use on-chip L3 OCMC3 RAM on VisionHigh */
      L3MEM_OCMC3_2   : origin=0x40500400 length=0x3A000    /* OCMC scratch buffer 232 KiB => use on-chip L3 OCMC3 RAM on VisionHigh */
#endif
      L3MEM           : origin=0x40300000 length=0x100000
}


SECTIONS
{
  .intvecs      > VECMEM  PAGE 0
  .inthandler   > CMDMEM  PAGE 0
  .exitlocation > CMDMEM  PAGE 0

  .text > EXTMEM   PAGE 0
  {
    *(.text)
  }

  GROUP
  {
      .bss            /* This order facilitates a single segment for */
      .data           /* GDP-relative addressing                     */
      .rodata
  }>DATMEM PAGE 1

  .const       > DATMEM  PAGE 1
  .cint        > DATMEM  PAGE 1
  .stack       > DATMEM  PAGE 1
  .sysmem      > DATMEM  PAGE 1
  .cinit       > DATMEM  PAGE 1
  .cio         > DATMEM  PAGE 1
  .far         > DATMEM  PAGE 1
  .fardata     > DATMEM  PAGE 1
  .init_array  > DATMEM  PAGE 1
  
  DDR_MEM      > EXTDMEM PAGE 1
  DDR3_MEM     > EXTDMEM PAGE 1
   
  /* Scratchbuffers, which are shared for all algos. */
  ALGO_SCRATCHBUFF_DMEM     > DATMEM_SCRATCH PAGE 1
  ALGO_SCRATCHBUFF_WMEM     > WMEM      PAGE 1
  ALGO_SCRATCHBUFF_IMEM_LA  > IMEMLA    PAGE 1
  ALGO_SCRATCHBUFF_IMEM_HA  > IMEMHA    PAGE 1
  ALGO_SCRATCHBUFF_IMEM_LB  > IMEMLB    PAGE 1
  ALGO_SCRATCHBUFF_IMEM_HB  > IMEMHB    PAGE 1
  ALGO_SCRATCHBUFF_DDR      > EXTDMEM   PAGE 1

#ifdef AL_ETK_EVMHIL_VME
  /* VME scratchbuffer */
  ALGO_SCRATCHBUFF_OCMC_EVE > EVE_OCMC2  PAGE 1
#else
  /* VH28 scratchbuffer */
  ALGO_SCRATCHBUFF_OCMC_EVE > L3MEM_OCMC3_2  PAGE 1
#endif
  
  ALGO_STATICDATA_DDR       > EXTDMEM   PAGE 1
  .vcop_parameter_block     > WMEM      PAGE 1
  
  res_set_sect              > DDR3_SHARED_EVE PAGE 0
}
