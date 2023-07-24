         .data

NO_SAT   .set  0
SYMM     .set  1
ASYMM    .set  2
S4PARAM  .set  3
SYMM32   .set  4
ASYMM32  .set  5

NO_RND   .set  0
RNDM     .set  1
TRU      .set  2
LSH      .set  3

NO_CIRC  .set  0
CIRC_1K  .set  1
CIRC_2K  .set  2
CIRC_4K  .set  3
CIRC_8K  .set  4
CIRC_16K .set  5
CIRC_32K .set  6

FLAT_MEM_VIEW    .set  0
ALIAS_MEM_VIEW   .set  1

WBUF_VCOP        .set  1
WBUF_SYST        .set  0
IBUFHB_VCOP      .set  1
IBUFHB_SYST      .set  0
IBUFHA_VCOP      .set  1
IBUFHA_SYST      .set  0
IBUFLB_VCOP      .set  1
IBUFLB_SYST      .set  0
IBUFLA_VCOP      .set  1
IBUFLA_SYST      .set  0

MEM_BUF_VIEW     .set  0x40080020
MEM_BUF_SWITCH   .set  0x40080024


    .text

VCOP_SET_MEM_VIEW .macro VIEW
     MVK   MEM_BUF_VIEW,    R2                              ;
     MVKH  MEM_BUF_VIEW,    R2                              ; Set address of mem_buf_view
     MVK   VIEW,            R1                              ; r1 1 bit for view
     STB   R1,              *+R2[0]                         ; Store view
     .endm

VCOP_BUF_SWITCH_SET .macro wbuf, ibufhb, ibufha, ibuflb, ibufla
     VSWITCHBUF   ((wbuf << 16) | (ibufhb << 12) | (ibuflb << 8) + (ibufha << 4) + ibufla)
     .endm


WPREGCIRC32  .macro base, circ, offset
     MVK (base),    R2                                      ;
     MVKH (base + (circ << 20)),  R2                        ; Add circ, into address at bits 24..20
     STW  R2,              *R1++[1]                          ; Store
     .ENDM

WPREGCIRCL32  .macro base, imm1, circ, offset
     MVK  (base + imm1),     R2                             
     MVKH (base + imm1 + (circ << 20)),  R2                 ; Add circ, into address at bits 24..20
     STW  R2,              *R1++[1]                         ; Store
     .ENDM

WPREGL32 .macro imm0, imm1, offset               
    MVK (imm0 + imm1),  R2                                  ; Add labels
    MVKH ((imm0 + imm1)),  R2                               ; Add labels
    STW  R2,              *R1++[1]                           ; Store
   .endm

WPREG16 .macro  imm16, offset
     MVK    imm16,   R2
     STH    R2,     *R1++[1]                               ;
    .endm

WPREG32 .macro imm32, offset
     MVK    imm32, R2                                       ; lower 16-bits of imm32
     MVKH   imm32, R2                                       ; upper 16-bits of imm32
     STW    R2,    *R1++[1]                                 ;
    .endm


WPREG_RNDMS .macro rnd_mode, rnd_shift, Preg
     MVK    ((rnd_mode << 5) | (rnd_shift << 0)),    R2        ;
     STH    R2,    *R1++[1]                                    ;   
    .endm

WPREG_RNDMS_SATMP .macro rnd_mode, rnd_shift, sat_mode,prm, Preg
     MVK   ((sat_mode << 13) | (prm << 7) | (rnd_mode << 5) | (rnd_shift << 0)),  R2
     STH   R2,     *R1++[1]              
    .endm

WPREG_INIT .macro 
     MVK               _pregs,        R0                    ; set up param_regs
     MVKH              _pregs,        R0                    ;
     MV                R0,            R1                    ; copy r0 to r1
    .endm
