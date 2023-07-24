/* ======================================================================== */
/*  TEXAS INSTRUMENTS, INC.                                                 */
/*                                                                          */
/*  NAME                                                                    */
/*      c_macros.h                                                          */
/*                                                                          */
/*  Provides support for initializing EVE parameter registers for           */
/*  C-callable vector core code.                                            */
/*                                                                          */
/*  Declare global variables unsigned int, offset = 0; in your code         */
/*  to use the macros.                                                      */
/*                                                                          */
/*                                                                          */
/* ------------------------------------------------------------------------ */
/*          Copyright (C) 2010 Texas Instruments, Incorporated.             */
/*                          All Rights Reserved.                            */
/* ======================================================================== */

#include <arp32.h>

#define NO_SAT           0
#define SYMM             1
#define ASYMM            2
#define S4PARAM          3
#define SYMM32           4
#define ASYMM32          5
                         
#define NO_RND           0
#define RND              1
#define TRU              2
#define LSH              3
                         
#define NO_CIRC          0
#define CIRC_1K          1
#define CIRC_2K          2
#define CIRC_4K          3
#define CIRC_8K          4
#define CIRC_16K         5
#define CIRC_32K         6
                         
#define WBUF_VCOP        1
#define WBUF_SYST        0
#define IBUFHB_VCOP      1
#define IBUFHB_SYST      0
#define IBUFHA_VCOP      1
#define IBUFHA_SYST      0
#define IBUFLB_VCOP      1
#define IBUFLB_SYST      0
#define IBUFLA_VCOP      1
#define IBUFLA_SYST      0

#define FLAT_MEM_VIEW    0
#define ALIAS_128K_VIEW  1

#define MEM_BUF_VIEW      0x40080020
#define MEM_BUF_SWITCH    0x40080024


/*-----------------------------------------------------------------------*/
/* This macro decides which buffers belong to the System (T16/DMA)       */
/* and which belong to VCOP. A value of '1' in the buffer locations      */
/* implies the buffer is owned by the VCOP, a value of '0' means the     */
/* buffer is owned by the System.                                        */
/*-----------------------------------------------------------------------*/

static inline void VCOP_BUF_SWITCH_SET (unsigned int WBUF, unsigned int IBUFHB, unsigned int IBUFHA, unsigned int IBUFLB, unsigned int IBUFLA)
{
        *(volatile unsigned int *)(MEM_BUF_SWITCH) = ((WBUF << 16) | (IBUFHB << 12) | (IBUFHA << 8) | (IBUFLB << 4) | (IBUFLA));
}

/*-----------------------------------------------------------------------*/
/* This macro merely toggles all the values around effecting a context   */
/* switch between the VCOP and System buffers. This is useful when       */
/* communicating with DMA and ping-pong buffering is needed.             */
/* This also eleminates the need to remember which buffer belonged to    */
/* whom prior to switching.                                              */
/*-----------------------------------------------------------------------*/

static inline void VCOP_BUF_SWITCH_TOGGLE () // does not otggle work buffer
{
    *(volatile unsigned int *)(MEM_BUF_SWITCH) = ((*(volatile unsigned int *)(MEM_BUF_SWITCH)) ^ 0x1111);
}
	
/*-----------------------------------------------------------------------*/
/* This macr0 sets the memory view to be either FLAT_MEM_VIEW or the     */
/* ALIAS_128K_VIEW. FLAT_MEM_VIEW is what T16 see always. The ALIAS_128K */
/* _VIEW has the IBUFLB and IBUFHB aliased with IBUFLA and IBUFHA.       */
/*-----------------------------------------------------------------------*/

static inline void VCOP_SET_MEM_VIEW (unsigned int VIEW)
{
	*(volatile unsigned int *)(MEM_BUF_VIEW) = VIEW;
}

/*-----------------------------------------------------------------------*/
/* Global VCOP synch. helper function.                                   */
/*-----------------------------------------------------------------------*/

static inline void vcop_synch()
{
    asm ("  VWDONE  ");
}

	
/*-----------------------------------------------------------------------*/
/* This macro initializes the pregs' offset to 0.                        */
/*-----------------------------------------------------------------------*/

#define WPREG_INIT() {offset = 0;}

/*-----------------------------------------------------------------------*/
/* This macro helps initialize a parameter register with a 32-bit        */
/* address value.                                                        */
/*-----------------------------------------------------------------------*/

#define WPREG32(ptr)  {                                                                                     \
	                  pregs[offset++] = (unsigned short) ((unsigned int) (ptr) & 0x0000FFFF);               \
                          pregs[offset++] = (unsigned short) (((unsigned int) (ptr) >> 16) & 0x0000FFFF);   \
	              }


/*-----------------------------------------------------------------------*/
/* This macro helps initialize a parameter register with a value which   */
/* is a sum of an immediate value and a 32-bit address value giving an   */
/* giving an 'offset' from that particular address.                      */
/*-----------------------------------------------------------------------*/

#define WPREGL32(ptr, imm)  {                                                                    \
	                       temp = (unsigned int) (ptr) + imm;                                    \
	                       pregs[offset++] = (unsigned short) (temp & 0x0000FFFF);               \
                               pregs[offset++] = (unsigned short) ((temp >> 16) & 0x0000FFFF);   \
	                    }


/*-----------------------------------------------------------------------*/
/* This macro helps setup the circular buffer address for a parameter    */
/* register.                                                             */
/*-----------------------------------------------------------------------*/

#define WPREGCIRC32(ptr, circ) {                                                                                            \
	                                   temp = (unsigned int) (ptr);                                                      \
	                                   pregs[offset++] = (unsigned short) (temp & 0x0000FFFF);                              \
                                           pregs[offset++] = (unsigned short) (((temp + (circ << 20)) >> 16) & 0x0000FFFF); \
                               }


/*-----------------------------------------------------------------------*/
/* This macro helps setup an offset from a address as a new circular     */
/* buffer address.                                                       */
/*-----------------------------------------------------------------------*/

#define WPREGCIRCL32(ptr, imm1, circ) {                                                                                     \
	                                   temp = (unsigned int) (ptr) + imm;                                                   \
	                                   pregs[offset++] = (unsigned short) (temp & 0x0000FFFF);                              \
                                           pregs[offset++] = (unsigned short) (((temp + (circ << 20)) >> 16) & 0x0000FFFF); \
	                              }


/*-----------------------------------------------------------------------*/
/* This macro helps initialize a parameter register with a 16-bit value. */
/*-----------------------------------------------------------------------*/

#define WPREG16(val) pregs[offset++] = val;


/*-----------------------------------------------------------------------*/
/* This macro helps initialize a parameter register with a 16-bit value. */
/* It also returns the offset into the 'pregs' array for that particular */
/* value. This is very useful for returning the location of the          */
/* saturation parameters which is needed by the WPREG_RNDMS_SATMP macro  */
/* to set the value of 'prm'.                                            */
/*-----------------------------------------------------------------------*/

#define WPREG16_RETOFST(val, ofst) {               \
	ofst = offset + 2;                             \
	pregs[offset++]  = val;                        \
}


/*-----------------------------------------------------------------------*/
/* This macro helps setup the round mode along with the shift amount.    */
/* The three modes are NO_RND = no rounding, RND = rounding and          */
/* TRU = truncation.                                                     */
/*-----------------------------------------------------------------------*/

#define WPREG_RNDMS(rnd_mode, rnd_shift)  pregs[offset++] = ((rnd_mode << 5) | (rnd_shift << 0));

/*-----------------------------------------------------------------------*/
/* This macro helps setup the round mode, shift amount and saturation    */
/* mode and parameters as well.                                          */
/* The saturation modes are: NO_SAT, SYMM, ASYMM, S4PARAM, SYMM32 and    */
/* ASYMM32. For details look at the latest EVE Spec.                     */
/*-----------------------------------------------------------------------*/

#define WPREG_RNDMS_SATMP(rnd_mode, rnd_shift, sat_mode, prm) pregs[offset++] = ((sat_mode << 13) | (prm << 7) | (rnd_mode << 5) | (rnd_shift << 0));
