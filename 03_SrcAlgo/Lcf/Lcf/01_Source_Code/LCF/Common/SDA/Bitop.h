/*~A*/
/*~+:VM Header*/
/* Used UML Profile version  */
/* ## Module Header Start [cbd33bc0-71a5-4af6-b470-cee9204176dc] */
/****************************************************************************

COPYRIGHT (C) $Date: 2019/07/03 13:45:16CEST $
$CompanyInfo: CONFIDENTIAL AND PROPRIETARY PROPERTY OF CONTINENTAL AG , A.D.C. GmbH  -  ALL RIGHTS RESERVED $
ALL RIGHTS RESERVED.

The reproduction, transmission or use of this document or its contents is
not permitted without express written authority.
Offenders will be liable for damages. All rights, including rights created
by patent grant or registration of a utility model or design, are reserved.
---------------------------------------------------------------------------

$Log: Bitop.h  $
Revision 1.3 2019/07/03 13:45:16CEST Nastasa, Elena (uidt4846) 
Update SDA Library files
Revision 1.1 2018/07/24 16:48:49CEST Ammermueller Martin (uidv5342) (uidv5342) 
Initial revision
Member added to project /ES/1T/0C/SDA/SDA_Source/SDA_Toolboxes/ACG/Libraries/bitop/Src/3_2_0/project.pj
Revision 1.10 2018/04/02 04:28:17CEST Angadi Hampa (uidu8151) (uidu8151) 
8197480 : FS_0G01_TC3XX_ANSI_BITOP_3.2.0
Revision 1.9 2018/03/06 07:47:44CET Angadi Hampa (uidu8151) (uidu8151) 
RO : 8197480 : MISRA2012 ANSI VERSIONS
Revision 1.8 2017/10/04 07:28:33CEST Angadi Hampa (uidu8151) (uidu8151) 
Bitop : LINT MISRA2012 for ANSI
Revision 1.7 2016/04/25 08:08:53CEST Adinarayanagowda Pruthviraj (uidp1961) (uidp1961) 
RO:4258741: Change_bit_of
Revision 1.6 2016/02/12 06:50:03CET Angadi Hampa (uidu8151) (uidu8151)
After addition of macro : READ_BIT_OF_LF_UX
Revision 1.5 2015/12/16 12:22:28CET Angadi Hampa (uidu8151) (uidu8151)
__CLZ removal
Revision 1.4 2015/12/16 05:15:06CET Angadi Hampa (uidu8151) (uidu8151)
Comment Removal
Revision 1.3 2015/12/15 05:17:33CET Angadi Hampa (uidu8151) (uidu8151)
RO : 3550590 : After Review
Revision 1.2 2015/11/30 05:02:02CET Angadi Hampa (uidu8151) (uidu8151)
RO : 3550590 ; BITOP: Create ANSI Version; Initial Archive
Revision 1.1 2015/11/23 12:25:02CET Ganesh Sumangala (uidu8725) (uidu8725)
Initial revision
Member added to project /ES/FS/0A/bsw/stdlib-ansi/bitop/pd_tc2xx/i/project.pj
Revision 1.7 2015/11/02 10:03:05CET Ganesh Sumangala (uidu8725) (uidu8725)
RO : 2874843 : Merge EMS2 and EMS3 Bitop versions.
reveiw update
Revision 1.6 2015/10/16 11:54:46CEST Angadi Hampa (uidu8151) (uidu8151)
RO 2874843 : FS_0G01_TC2XX_BITOP_3.0.0 ; EMS2 - EMS3 merging.
Revision 1.5 2014/07/21 08:03:36CEST Angadi Hampa (uidu8151) (uidu8151)
Ro 1024103: Initial checkpoints : Design Document update & Lint correction
Revision 1.4 2014/02/06 11:50:21CET Angadi Hampa (uidu8151) (uidu8151)
RO:1084686 FS_0G01_TC2XX_BITOP_120 ; Lint removal
Revision 1.3 2013/08/23 08:13:29CEST Angadi Hampa (uidu8151) (uidu8151)
for release RO 377174: FS_0G01_TC2XX_BITOP_100
Revision 1.2 2013/08/23 06:55:10CEST Angadi Hampa (uidu8151) (uidu8151)
Member renamed from bitop.h_code to bitop_main.h in project /ES/FS/0A/bsw/stdlib/bitop/pd_tc2xx/i/project.pj.
Revision 1.1 2013/08/05 13:51:19CEST Angadi Hampa (uidu8151) (uidu8151)
Initial revision
Member added to project /ES/FS/0D/bsw/stdlib/tc2xx/bitop/src_pd/i/project.pj
Revision 1.1 2013/04/04 10:46:52CEST Grabow Marcus (uid08755) (uid08755)
Initial revision
Member added to project /ES/FS/1T/03/UML_Development/DevelopmentSpace/Appl_Uml_ToolBox/Exporters/Uml_Exporter_C/Data/project.pj
Revision 1.1 2013/03/20 08:07:52CET Grabow Marcus (uid08755) (uid08755)
Initial revision
Member added to project /ES/FS/1T/03/UML_Development/DevelopmentSpace/Appl_Uml_ToolBox/Exporters/Uml_Exporter_C/Core/Data/project.pj
Revision 1.3 2012/01/17 10:50:32CET Grabow Marcus (uid08755) (uid08755)
-
Revision 1.2 2011/03/10 12:17:55CET Grabow Marcus (uid08755) (uid08755)
-

 ****************************************************************************/
/* ## Module Header End [14003d31-a23b-4097-958b-8f7204bc869d] */

/*~E*/
#ifndef BITOP_H
#define BITOP_H


#include "powersar_addon_types.h" //ElNa, include needed header
#include "Platform_Types.h"  // 2021.11.12
#include "iopt_memmap.h"


/*~A*/
/*~+:LINT Supressions*/
/*lint --e{9033} */
/*lint --e{9034} */
/*lint --e{9030} */
/*lint --e{838} */
/*~E*/
/*~A*/
/*~+:Macro Definitions*/
#define BIT_POS_0                                        (1)           /**< Macros for the different powers of 2 (0 to 31) */
#define BIT_POS_1                                        (2)
#define BIT_POS_2                                        (4)
#define BIT_POS_3                                        (8)
#define BIT_POS_4                                        (16)
#define BIT_POS_5                                        (32)
#define BIT_POS_6                                        (64)
#define BIT_POS_7                                        (128)
#define BIT_POS_8                                        (256)
#define BIT_POS_9                                        (512)
#define BIT_POS_10                                       (1024)
#define BIT_POS_11                                       (2048)
#define BIT_POS_12                                       (4096)
#define BIT_POS_13                                       (8192)
#define BIT_POS_14                                       (16384)
#define BIT_POS_15                                       ((uint16)32768)
#define BIT_POS_16                                       ((uint32)65536)
#define BIT_POS_17                                       ((uint32)131072)
#define BIT_POS_18                                       ((uint32)262144)
#define BIT_POS_19                                       ((uint32)524288)
#define BIT_POS_20                                       ((uint32)1048576)
#define BIT_POS_21                                       ((uint32)2097152)
#define BIT_POS_22                                       ((uint32)4194304)
#define BIT_POS_23                                       ((uint32)8388608)
#define BIT_POS_24                                       ((uint32)16777216)
#define BIT_POS_25                                       ((uint32)33554432)
#define BIT_POS_26                                       ((uint32)67108864)
#define BIT_POS_27                                       ((uint32)134217728)
#define BIT_POS_28                                       ((uint32)268435456)
#define BIT_POS_29                                       ((uint32)536870912)
#define BIT_POS_30                                       ((uint32)1073741824)
#define BIT_POS_31                                       (2147483648U)

#define GET_BIT_OF_LF_UX(LF,POSITION,UX)                 (flag_get_##UX##_u8((LF),(uint8)(POSITION)))
#define READ_BIT_OF_LF_UX(LF,POSITION,UX)                GET_BIT_OF_LF_UX(LF,POSITION,UX)
/**< Get specific LF Bit position
@param lf  : bitfield with length ux
@param position  : 0..7 (for u8 lf), 0..15 (for u16 lf), 0..31 (for u32 lf), 0..63 (for u64 lf)
@param ux  : u8, u16, u32, u64 */
#define SET_BIT_OF_LF_UX(LF, POSITION, UX)               \
		(                                                              \
				LF = UX##_set_flag_u8((LF), (uint8)(POSITION))   \
		)
/**< Set of specific LF Bit position
@param lf  : bitfield with length ux
@param position  : 0..7 (for u8 lf), 0..15 (for u16 lf), 0..31 (for u32 lf), 0..63 (for u64 lf)
@param ux  : u8, u16, u32, u64 */
#define WRITE_BIT_OF_LF_UX(L,P,T)                        SET_BIT_OF_LF_UX(L,P,T)
/**< This macro shall set the specific LF Bit position */
#define RESET_BIT_OF_LF_UX(LF, POSITION, UX)             \
		(                                                              \
				LF = UX##_clear_flag_u8((LF), (uint8)(POSITION))  \
		)
/**< Reset of specific LF Bit position
@param lf  : bitfield with length ux
@param position  : 0..7 (for u8 lf), 0..15 (for u16 lf), 0..31 (for u32 lf), 0..63 (for u64 lf)
@param ux  : u8, u16, u32, u64 */
#define CHANGE_BIT_OF_LF_UX(INPUT, LF, POSITION, UX)     \
		(  \
				LF = UX##_move_flag_u8_flag((LF), (uint8)(POSITION), (flag)(INPUT))    \
		)
/**< Change of specific LF Bit position
@param input  : logical input (to set or reset the specific position of the lf)
@param lf  : bitfield with length ux
@param position  : 0..7 (for u8 lf), 0..15 (for u16 lf), 0..31 (for u32 lf), 0..63 (for u64 lf)
@param ux  : u8, u16, u32, u64
    uxx_move_flag_u8_flag(uxx val, uint8 cnt, boolean bitval) */
#define SET_MASK_OF_LF_UX(LF, MASK, UX)                  \
		(                                                              \
				LF |= ((UX)(MASK))                                      \
		)
/**< Set of specific LF mask
@param lf  : bitfield with length ux
@param mask  : bitmask
@param ux  : u8, u16, u32, u64 */
#define WRITE_MASK_OF_LF_UX(L,M,T)                       SET_MASK_OF_LF_UX(L,M,T)  /**< WRITE_MASK_OF_LF_UX (ems3): same as SET_MASK_OF_LF_UX */
#define RESET_MASK_OF_LF_UX(LF, MASK, UX)                \
		(                                                              \
				LF &= (UX##_inv_##UX((UX) (MASK) ))                     \
		)
/**< Reset of specific LF mask
@param lf  : bitfield with length ux
@param mask  : bitmask
@param ux  : u8, u16, u32, u64 */
#define CHANGE_MASK_OF_LF_UX(INPUT, LF, MASK, UX)        \
		(                                                                                        \
				((boolean)(INPUT)) ? ( LF |= (UX) (MASK) )                                :  \
						( LF &= (UX##_inv_##UX((UX) (MASK) )))                  \
		)
/**< Change of specific LF mask
@param input  : logical input (to set or reset the specific position of the lf)
@param lf  : bitfield with length ux
@param mask  : bitmask
@param ux  : u8, u16, u32, u64 */
#define CREATE_BW_8(BIT7, BIT6, BIT5, BIT4, BIT3, BIT2, BIT1, BIT0) \
		(                                                                           \
				(uint8)(                                                                     \
						(((BIT7) & 0x01) * BIT_POS_7) +                                       \
						(((BIT6) & 0x01) * BIT_POS_6) +                                       \
						(((BIT5) & 0x01) * BIT_POS_5) +                                       \
						(((BIT4) & 0x01) * BIT_POS_4) +                                       \
						(((BIT3) & 0x01) * BIT_POS_3) +                                       \
						(((BIT2) & 0x01) * BIT_POS_2) +                                       \
						(((BIT1) & 0x01) * BIT_POS_1) +                                       \
						(((BIT0) & 0x01) * BIT_POS_0)                                         \
				)                                                                     \
		)  
/**< Create bitfields out ofbooleans
@param bit7  : 7th bit of the bit field
@param bit6  : 6th bit of the bit field
@param bit5  : 5th bit of the bit field
@param bit4  : 4th bit of the bit field
@param bit3  : 3rd bit of the bit field
@param bit2  : 2nd bit of the bit field
@param bit1  : 1st bit of the bit field
@param bit0  : 0th bit of the bit field */
/*~E*/
/*~A*/
/*~+:Macro Operations*/
/* Macro operation name: GetByteAdrFromU8 */
/** Get the address of type *uint8 from type uint8

@param val input value */
/* ## Macro operation start [39f98501-9464-40d7-bc09-179b433602e7] */
#define GetByteAdrFromU8(val)  ((uint8*) &val)
/* ## Macro operation end [39f98501-9464-40d7-bc09-179b433602e7] */

/* Macro operation name: GetHByteAdrFromU16 */
/** Get the address of type *uint8 from uint16 high byte

@param val input value */
/* ## Macro operation start [20bae0ea-fa7e-4340-a6ec-ed3cef33b2eb] */
#define GetHByteAdrFromU16(val)  ( ( (uint8 *) &val ) + 1 )
/* ## Macro operation end [20bae0ea-fa7e-4340-a6ec-ed3cef33b2eb] */

/* Macro operation name: GetLByteAdrFromU16 */
/** Get the address of type *uint8 from uint16 low byte

@param val input value */
/* ## Macro operation start [8f441a49-12a2-4416-ac21-f7aa783bb6fb] */
#define GetLByteAdrFromU16(val)  ( ( (uint8 *) &val ) + 0 )
/* ## Macro operation end [8f441a49-12a2-4416-ac21-f7aa783bb6fb] */

/* Macro operation name: GetHHByteAdrFromU32 */
/** Get the address of type *uint8 from uint32 high byte of high word

@param val input value */
/* ## Macro operation start [f7389ebe-0e37-4ffd-82a3-dc0fad0cd2d6] */
#define GetHHByteAdrFromU32(val)  ( ( (uint8 *) &val ) + 3 )
/* ## Macro operation end [f7389ebe-0e37-4ffd-82a3-dc0fad0cd2d6] */

/* Macro operation name: GetHLByteAdrFromU32 */
/** Get the address of type *uint8 from uint32 low byte of high word

@param val input value */
/* ## Macro operation start [147078b1-1db5-45a7-845d-4cb130ebe95b] */
#define GetHLByteAdrFromU32(val)  ( ( (uint8 *) &val ) + 2 )
/* ## Macro operation end [147078b1-1db5-45a7-845d-4cb130ebe95b] */

/* Macro operation name: GetLHByteAdrFromU32 */
/** Get the address of type *uint8 from uv32 high byte of low word

@param val input value */
/* ## Macro operation start [16e9b4b3-8980-4e96-96cd-3506480d01b8] */
#define GetLHByteAdrFromU32(val)   ( ( (uint8 *) &val ) + 1 )
/* ## Macro operation end [16e9b4b3-8980-4e96-96cd-3506480d01b8] */

/* Macro operation name: GetLLByteAdrFromU32 */
/** Get the address of type *uint8 from uint32 low byte of low word

@param val input value */
/* ## Macro operation start [20924f60-7069-46d7-95f4-7130b9eacb80] */
#define GetLLByteAdrFromU32(val)   ( ( (uint8 *) &val ) + 0 )
/* ## Macro operation end [20924f60-7069-46d7-95f4-7130b9eacb80] */

/*~E*/
/*~A*/
/*~+:Inline Operations*/
/** This operation shall return the count of leading zeros of the given uint8 value

@param val Input value

Range:           00(H) ... FF(H)
                0 ....... 255
@return Number of leading zeros

Range:           00(H) ... 08(H)
                0 ....... 8 */

/*~A*/
/*~+:Inline Functions Declarations*/
extern uint8 u8_cntlz_u8(uint8 val);  // 2021.11.12
extern uint8 u8_cntlz_u16(uint16 val);  // 2021.11.12
extern uint8 u8_cntlz_u32(uint32 val);  // 2021.11.12
extern uint8 u8_msbpos_u8(uint8 val);  // 2021.11.12
extern uint8 u8_msbpos_u16(uint16 val);  // 2021.11.12
extern uint8 u8_msbpos_u32(uint32 val);  // 2021.11.12
extern boolean flag_get_u8_u8(uint8 val, uint8 cnt);  // 2021.11.12
extern boolean flag_get_u16_u8(uint16 val, uint8 cnt);  // 2021.11.12
extern boolean flag_get_u32_u8(uint32 val, uint8 cnt);  // 2021.11.12
extern boolean flag_get_u64_u8(uint64 val, uint8 cnt);  // 2021.11.12
extern uint8 u8_get_u16_u8(uint16 val, uint8 cnt);  // 2021.11.12
extern uint8 u8_get_u32_u8(uint32 val, uint8 cnt);  // 2021.11.12
extern uint8 u8_get_u64_u8(uint64 val, uint8 cnt);  // 2021.11.12
extern uint16 u16_get_u32_u8(uint32 val, uint8 cnt);  // 2021.11.12
extern uint16 u16_get_u64_u8(uint64 val, uint8 cnt);  // 2021.11.12
extern uint32 u32_get_u64_u8(uint64 val, uint8 cnt);  // 2021.11.12
extern uint16 u16_make_u8_u8(uint8 high, uint8 low);  // 2021.11.12
extern uint32 u32_make_u16_u16(uint16 high, uint16 low);  // 2021.11.12
extern uint64 u64_make_u32_u32(uint32 high, uint32 low);  // 2021.11.12
extern uint8 u8_lsl_u8_u8(uint8 val, uint8 cnt);  // 2021.11.12
extern uint16 u16_lsl_u16_u8(uint16 val, uint8 cnt);  // 2021.11.12
extern uint32 u32_lsl_u32_u8(uint32 val, uint8 cnt);  // 2021.11.12
extern uint64 u64_lsl_u64_u8(uint64 val, uint8 cnt);  // 2021.11.12
extern uint8 u8_lsr_u8_u8(uint8 val, uint8 cnt);  // 2021.11.12
extern uint16 u16_lsr_u16_u8(uint16 val, uint8 cnt);  // 2021.11.12
extern uint32 u32_lsr_u32_u8(uint32 val, uint8 cnt);  // 2021.11.12
extern uint64 u64_lsr_u64_u8(uint64 val, uint8 cnt);  // 2021.11.12
extern uint8 u8_inv_u8(uint8 val);  // 2021.11.12
extern uint16 u16_inv_u16(uint16 val);  // 2021.11.12
extern uint32 u32_inv_u32(uint32 val);  // 2021.11.12
extern uint64 u64_inv_u64(uint64 val);  // 2021.11.12
extern uint8 u8_bit_u8(uint8 cnt);  // 2021.11.12
extern uint16 u16_bit_u8(uint8 cnt);  // 2021.11.12
extern uint32 u32_bit_u8(uint8 cnt);  // 2021.11.12
extern uint64 u64_bit_u8(uint8 cnt);  // 2021.11.12
extern uint8 u8_set_flag_u8(uint8 val, uint8 cnt);  // 2021.11.12
extern uint16 u16_set_flag_u8(uint16 val, uint8 cnt);  // 2021.11.12
extern uint32 u32_set_flag_u8(uint32 val, uint8 cnt);  // 2021.11.12
extern uint64 u64_set_flag_u8(uint64 val, uint8 cnt);  // 2021.11.12
extern uint8 u8_clear_flag_u8(uint8 val, uint8 cnt);  // 2021.11.12
extern uint16 u16_clear_flag_u8(uint16 val, uint8 cnt);  // 2021.11.12
extern uint32 u32_clear_flag_u8(uint32 val, uint8 cnt);  // 2021.11.12
extern uint64 u64_clear_flag_u8(uint64 val, uint8 cnt);  // 2021.11.12
extern boolean flag_sr_ff_flag_flag_flag(boolean lv_in, boolean lv_set, boolean lv_rst);  // 2021.11.12
extern boolean flag_rs_ff_flag_flag_flag(boolean lv_in, boolean lv_rst, boolean lv_set);  // 2021.11.12
extern boolean flag_edge01_det_flag_flag(boolean lv_0_old, boolean lv_1_act);  // 2021.11.12
extern boolean flag_edge10_det_flag_flag(boolean lv_1_old, boolean lv_0_act);  // 2021.11.12
extern boolean flag_xor_flag_flag(boolean lv_a, boolean lv_b);  // 2021.11.12
extern uint8 u8_move_flag_u8_flag(uint8 val, uint8 cnt, boolean bitval);  // 2021.11.12
extern uint16 u16_move_flag_u8_flag(uint16 val, uint8 cnt, boolean bitval);  // 2021.11.12
extern uint32 u32_move_flag_u8_flag(uint32 val, uint8 cnt, boolean bitval);  // 2021.11.12
extern uint64 u64_move_flag_u8_flag(uint64 val, uint8 cnt, boolean bitval);  // 2021.11.12

/*~E*/

//static inline uint8 u8_cntlz_u8(uint8 val)
//{
//	/* ## Operation body start [981ea54f-c2a7-4a07-935d-d3eec00f51df] */
//	uint8 i,j,k,cnt;
//	i = val;
//	cnt = 0;
//	for (k = 1; k <= 8U; k++)
//	{
//		j = i & 0x80U;
//		if (j == 0U)
//		{
//			cnt++;
//			i = (uint8)(i << 1);
//		}
//		else
//		{
//			/*NOP*/
//		}
//	}
//	return cnt;
//
//	/* ## Operation body end [981ea54f-c2a7-4a07-935d-d3eec00f51df] */
//}


/** This operation shall return the count of leading zeros of the given uint16 value

@param val Input value

Range:	         00(H) ... FFFF(H)
  	            0 ....... 65535
@return Number of leading zeros

Range:	         00(H) ... 10(H)
  	            0 ....... 16 */


//static inline uint8 u8_cntlz_u16(uint16 val)
//{
//	/* ## Operation body start [3a68c65f-12cb-4e90-a8e5-d1fb037a308e] */
//	uint8  k,cnt;
//	uint16 i,j;
//	cnt = 0;
//	i = val;
//	for (k = 1; k <= 16U; k++)
//	{
//		j = i & 0x8000U;
//
//		if (j == 0U)
//		{
//			cnt++;
//			i = (uint16)(i << 1);
//		}
//		else
//		{
//			/* no else needed */
//		}
//	}
//	return cnt;
//
//	/* ## Operation body end [3a68c65f-12cb-4e90-a8e5-d1fb037a308e] */
//}

/** This operation shall return the count of leading zeros of the given uint32 value

@param val Input value

Range:	         00(H) ... FFFFFFFF(H)
  	            0 ....... 4294967295
@return Number of leading zeros

Range:	         00(H) ... 20(H)
  	            0 ....... 32 */

//static inline uint8 u8_cntlz_u32(uint32 val)
//{
//	/* ## Operation body start [da8bd918-8225-4cac-a462-58c0b96fc240] */
//	uint8  k,cnt;
//	uint32 i,j;
//	cnt = 0;
//	i = val;
//	for (k = 1; k <= 32U; k++)
//	{
//		j = i & 0x80000000U;
//		if (j == 0U)
//		{
//			cnt++;
//			i = i << 1;
//		}
//		else
//		{
//			/* no else needed */
//		}
//	}
//	return cnt;
//	/* ## Operation body end [da8bd918-8225-4cac-a462-58c0b96fc240] */
//}

/** This operation shall return the bit position of the MSB set plus one of the given uint8 value

@param val Input value

Range:	         00(H) ... FF(H)
  	            0 ....... 255
@return Bit position of the MSB set plus one

Range:	         00(H) ... 08(H)
  	            0 ....... 8 */

//static inline uint8 u8_msbpos_u8(uint8 val)
//{
//	/* ## Operation body start [3a49cd05-b6fd-4253-baa6-ee59227693b0] */
//	uint8 i,j,pos,temp=0;
//
//	i = val;
//	for (pos = 8; pos > 0U; pos--)
//	{
//		j = i & 0x80U;
//		if (j == 0U)
//		{
//			i = (uint8)(i << 1);
//
//		}
//		else
//		{
//			temp = pos;
//			break;
//		}
//	}
//
//	return temp;
//	/* ## Operation body end [3a49cd05-b6fd-4253-baa6-ee59227693b0] */
//}

/** This operation shall return the bit position of the MSB set plus one of the given uint16 value

@param val Input value

Range:	         00(H) ... FFFF(H)
  	            0 ....... 65535
@return Bit position of the MSB set plus one

Range:	         00(H) ... 10(H)
  	            0 ....... 16 */

//static inline uint8 u8_msbpos_u16(uint16 val)
//{
//	/* ## Operation body start [0902430b-9ee5-4937-8814-12cd11df3746] */
//	uint8  pos,temp=0;
//	uint16 i,j;
//	i = val;
//	for (pos = 16; pos > 0U; pos--)
//	{
//		j = i & 0x8000U;
//		if (j == 0U)
//		{
//			i = (uint16)(i << 1);
//		}
//		else
//		{
//			temp = pos;
//			break;
//		}
//	}
//
//	return temp;
//
//
//	/* ## Operation body end [0902430b-9ee5-4937-8814-12cd11df3746] */
//}

/** This operation shall return the bit position of the MSB set plus one of the given uint32 value

@param val Input value

Range:	         00(H) ... FFFFFFFF(H)
  	            0 ....... 4294967295
@return Bit position of the MSB set plus one

Range:	         00(H) ... 20(H)
  	            0 ....... 32 */

//static inline uint8 u8_msbpos_u32(uint32 val)
//{
//	/* ## Operation body start [a44142f3-83c0-478a-8f3f-dd5a020d815e] */
//	uint8  pos,temp=0;
//	uint32 i,j;
//
//	i = val;
//	for (pos = 32; pos > 0U; pos--)
//	{
//		j = i & 0x80000000U;
//		if (j == 0U)
//		{
//			i = i << 1;
//		}
//		else
//		{
//			temp = pos;
//			break;
//		}
//	}
//
//	return temp;
//
//
//	/* ## Operation body end [a44142f3-83c0-478a-8f3f-dd5a020d815e] */
//}

/** This operation shall return a boolean which shows whether the bit position given by 'cnt' is set or not for the uint8 value "val"

@param val Value from which a particular bit shall be extracted

Range:	         00(H) ... FF(H)
	           0 ....... 255
@param cnt Bit position which shall be extracted from 'val'

Range:	         00(H) ... FF(H)
	           0 ....... 255
@return Bit value corresponding to the position given by 'cnt'

Range:	         00(H) ... 01(H)
	            0 ....... 1 */

//static inline boolean flag_get_u8_u8(uint8 val, uint8 cnt)
//{
//	/* ## Operation body start [f0301fd6-6551-4f7b-bee7-50a060c11557] */
//	/*~T*/
//	boolean temp;
//	if (cnt < (sizeof(val)*(uint8)8))
//	{
//		temp = (boolean)((val >> cnt) & 1U);
//	}
//	else
//	{
//		temp = 0;
//	}
//	return temp;
//	/* ## Operation body end [f0301fd6-6551-4f7b-bee7-50a060c11557] */
//}

/** This operation shall return a boolean which shows whether the bit position given by 'cnt' is set or not for the uint16 value "val"

@param val Value from which a particular bit shall be extracted

Range:	         00(H) ... FFFF(H)
	           0 ....... 65535
@param cnt Bit position which shall be extracted from 'val'

Range:	         00(H) ... FF(H)
	           0 ....... 255
@return Bit value corresponding to the position given by 'cnt'

Range:	         00(H) ... 01(H)
	            0 ....... 1 */


//static inline boolean flag_get_u16_u8(uint16 val, uint8 cnt)
//{
//	/* ## Operation body start [4f0ed616-1d96-4328-badd-9a38139c0993] */
//	/*~T*/
//	boolean temp;
//	if (cnt < (sizeof(val)*(uint16)8))
//	{
//		temp =(boolean)((val >> cnt) & 1U);
//	}
//	else
//	{
//		temp =0;
//	}
//	return temp;
//	/* ## Operation body end [4f0ed616-1d96-4328-badd-9a38139c0993] */
//}
//
///** This operation shall return a boolean which shows whether the bit position given by 'cnt' is set or not for the uint32 value "val"
//
//@param val Value from which a particular bit shall be extracted
//
//Range:	         00(H) ... FFFFFFFF(H)
//	           0 ....... 4294967295
//@param cnt Bit position which shall be extracted from 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Bit value corresponding to the position given by 'cnt'
//
//Range:	         00(H) ... 01(H)
//	            0 ....... 1 */
//
//static inline boolean flag_get_u32_u8(uint32 val, uint8 cnt)
//{
//	/* ## Operation body start [8514eaba-c693-47d6-9943-830476a26f8c] */
//	/*~T*/
//	boolean temp;
//	if (cnt < (sizeof(val)*(uint8)8))
//	{
//		temp =(boolean)((val >> cnt) & (uint32)1);
//	}
//	else
//	{
//		temp = 0;
//	}
//	return temp;
//	/* ## Operation body end [8514eaba-c693-47d6-9943-830476a26f8c] */
//}
//
///** This operation shall return a boolean which shows whether the bit position given by 'cnt' is set or not for the uint64 value "val"
//
//@param val Value from which a particular bit shall be extracted
//
//Range:	         00(H) ... FFFFFFFFFFFFFFFF(H)
//	           0 ....... 18446744073709551615
//@param cnt Bit position which shall be extracted from 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Bit value corresponding to the position given by 'cnt'
//
//Range:	         00(H) ... 01(H)
//	            0 ....... 1 */
//
//static inline boolean flag_get_u64_u8(uint64 val, uint8 cnt)
//{
//	/* ## Operation body start [6ca528c3-bc88-4df6-b8ab-ea75b4b88f12] */
//	/*~T*/
//	boolean temp;
//	if (cnt < (sizeof(val)*(uint64)8))
//	{
//		temp = (boolean)((val >> cnt) & 1U);
//	}
//	else
//	{
//		temp =0;
//	}
//	return temp;
//	/* ## Operation body end [6ca528c3-bc88-4df6-b8ab-ea75b4b88f12] */
//}
//
///** This operation shall return an uint8 value which is cnt-th 8 bit wide pattern of the uint16 value "val"
//
//@param val Value from which a particular 8 bit pattern shall be extracted
//
//Range:	         00(H) ... FFFF(H)
//	           0 ....... 65535
//@param cnt 8 bit pattern position which shall be extracted from 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return value extracted from the given input value 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255 */
//
//static inline uint8 u8_get_u16_u8(uint16 val, uint8 cnt)
//{
//	/* ## Operation body start [4ce3953c-5892-4d29-a663-56d4b347d3e3] */
//	/*~T*/
//	uint8 temp;
//	if (cnt < (sizeof(val)))
//	{
//		temp = (uint8)(val >> ((cnt)*(uint8)8));
//	}
//	else
//	{
//		temp =(U8_MIN);
//	}
//	return temp;
//	/* ## Operation body end [4ce3953c-5892-4d29-a663-56d4b347d3e3] */
//}
//
///** This operation shall return an uint8 value which is cnt-th 8 bit wide pattern of the uint32 value "val"
//
//@param val Value from which a particular 8 bit pattern shall be extracted
//
//Range:	         00(H) ... FFFFFFFF(H)
//	           0 ....... 4294967295
//@param cnt 8 bit pattern position which shall be extracted from 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return value extracted from the given input value 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255 */
//
//static inline uint8 u8_get_u32_u8(uint32 val, uint8 cnt)
//{
//	/* ## Operation body start [6751d324-8729-48da-8702-72279e3fdca5] */
//	/*~T*/
//	uint8 temp;
//	if (cnt < (sizeof(val)))
//	{
//		temp = (uint8)(val >> ((cnt)*(uint8)8));
//	}
//	else
//	{
//		temp = (U8_MIN);
//	}
//	return temp;
//	/* ## Operation body end [6751d324-8729-48da-8702-72279e3fdca5] */
//}
//
///** This operation shall return an uint8 value which is cnt-th 8 bit wide pattern of the uint64 value "val"
//
//@param val Value from which a particular 8 bit pattern shall be extracted
//
//Range:	         00(H) ... FFFFFFFFFFFFFFFF(H)
//	           0 ....... 18446744073709551615
//@param cnt 8 bit pattern position which shall be extracted from 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return value extracted from the given input value 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255 */
//
//static inline uint8 u8_get_u64_u8(uint64 val, uint8 cnt)
//{
//	/* ## Operation body start [321fb0ee-63b2-435d-9241-7d771e04e2ba] */
//	/*~T*/
//	uint8 temp;
//	if (cnt < (sizeof(val)))
//	{
//		temp = (uint8)(val >> ((cnt)*(uint8)8));
//	}
//	else
//	{
//		temp = (U8_MIN);
//	}
//	return temp;
//	/* ## Operation body end [321fb0ee-63b2-435d-9241-7d771e04e2ba] */
//}
//
///** This operation shall return an uint16 value which is cnt-th 16 bit wide pattern of the uint32 value "val"
//
//@param val Value from which a particular 16 bit pattern shall be extracted
//
//Range:	         00(H) ... FFFFFFFF(H)
//	           0 ....... 4294967295
//@param cnt 16 bit pattern position which shall be extracted from 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return value extracted from the given input value 'val'
//
//Range:	         00(H) ... FFFF(H)
//	           0 ....... 65535 */
//
//static inline uint16 u16_get_u32_u8(uint32 val, uint8 cnt)
//{
//	/* ## Operation body start [6982edb9-8c7f-4335-8979-cb0ec35a86bb] */
//	/*~T*/
//	uint16 temp;
//	if (cnt < (sizeof(val)/2U))
//	{
//		temp =(uint16)(val >> ((cnt)*(uint8)16));
//	}
//	else
//	{
//		temp =(U16_MIN);
//	}
//	return temp;
//	/* ## Operation body end [6982edb9-8c7f-4335-8979-cb0ec35a86bb] */
//}
//
///** This operation shall return an uint16 value which is cnt-th 16 bit wide pattern of the uint64 value "val"
//
//@param val Value from which a particular 16 bit pattern shall be extracted
//
//Range:	         00(H) ... FFFFFFFFFFFFFFFF(H)
//	           0 ....... 18446744073709551615
//@param cnt 16 bit pattern position which shall be extracted from 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return value extracted from the given input value 'val'
//
//Range:	         00(H) ... FFFF(H)
//	           0 ....... 65535 */
//
//static inline uint16 u16_get_u64_u8(uint64 val, uint8 cnt)
//{
//	/* ## Operation body start [798f4b18-47e5-4982-80ba-99030fedcdc3] */
//	/*~T*/
//	uint16 temp;
//	if (cnt < (sizeof(val)/2U))
//	{
//		temp = (uint16)(val >> ((cnt)*(uint8)16));
//	}
//	else
//	{
//		temp =(U16_MIN);
//	}
//	return temp;
//	/* ## Operation body end [798f4b18-47e5-4982-80ba-99030fedcdc3] */
//}
//
///** This operation shall return an uint32 value which is cnt-th 32 bit wide pattern of the uint64 value "val"
//
//@param val Value from which a particular 32 bit pattern shall be extracted
//
//Range:	         00(H) ... FFFFFFFFFFFFFFFF(H)
//	           0 ....... 18446744073709551615
//@param cnt 32 bit pattern position which shall be extracted from 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return value extracted from the given input value 'val'
//
//Range:	         00(H) ... FFFFFFFF(H)
//	           0 ....... 4294967295 */
//#include "iopt_memmap.h"
//
//static inline uint32 u32_get_u64_u8(uint64 val, uint8 cnt)
//{
//	/* ## Operation body start [2dda183f-da8b-4467-9bd1-e6558e22e947] */
//	/*~T*/
//	uint32 temp;
//	if (cnt < (sizeof(val)/4U))
//	{
//		temp = (uint32)(val >> ((cnt)*(uint8)32));
//	}
//	else
//	{
//		temp =(U32_MIN);
//	}
//	return temp;
//	/* ## Operation body end [2dda183f-da8b-4467-9bd1-e6558e22e947] */
//}
//
///** This operation shall return an uint16 value which is formed by the combination of the input parameters - uint8 high and uint8 low
//
//@param high Higher 8 bit value
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@param low Lower 8 bit value
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Combined value
//
//Range:	         00(H) ... FFFF(H)
//	           0 ....... 65535 */
//#include "iopt_memmap.h"
//
//static inline uint16 u16_make_u8_u8(uint8 high, uint8 low)
//{
//	/* ## Operation body start [af569600-098b-4bae-aa2b-01c8c5a5334d] */
//	return ((uint16)(((uint32)high << 8) | (uint16)low));
//
//	/* ## Operation body end [af569600-098b-4bae-aa2b-01c8c5a5334d] */
//}
//
///** This operation shall return an uint32 value which is formed by the combination of the input parameters - uint16 high and uint16 low
//
//@param high Higher 8 bit value
//
//Range:	         00(H) ... FFFF(H)
//	           0 ....... 65535
//@param low Lower 8 bit value
//
//Range:	         00(H) ... FFFF(H)
//	           0 ....... 65535
//@return Combined value
//
//Range:	         00(H) ... FFFFFFFF(H)
//	           0 ....... 4294967295 */
//#include "iopt_memmap.h"
//
//static inline uint32 u32_make_u16_u16(uint16 high, uint16 low)
//{
//	/* ## Operation body start [901cf5c3-8e3f-43d5-bac2-e7d0bc36839b] */
//	return (((uint32)high<<16) | ((uint32)low));
//
//	/* ## Operation body end [901cf5c3-8e3f-43d5-bac2-e7d0bc36839b] */
//}
//
///** This operation shall return an uint64 value which is formed by the combination of the input parameters - uint32 high and uint32 low
//
//@param high Higher 8 bit value
//
//Range:	         00(H) ... FFFFFFFF(H)
//	           0 ....... 4294967295
//@param low Lower 8 bit value
//
//Range:	         00(H) ... FFFFFFFF(H)
//	           0 ....... 4294967295
//@return Combined value
//
//Range:	         00(H) ... FFFFFFFFFFFFFFFF(H)
//	           0 ....... 18446744073709551615 */
//#include "iopt_memmap.h"
//
//static inline uint64 u64_make_u32_u32(uint32 high, uint32 low)
//{
//	/* ## Operation body start [96f13269-f187-4d4d-99f0-e02b7de685ef] */
//	return (((uint64)high<<32) | ((uint64)low));
//
//	/* ## Operation body end [96f13269-f187-4d4d-99f0-e02b7de685ef] */
//}
//
///** This operation shall perform a logical shift left of a given uint8 value val by number of bits specified by cnt and return the shifted value. The LSB shifted shall be filled with zeros.
//i.e. (val << cnt)
//
//@param val Value to be left shifted
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@param cnt Count specifying the number of bits, the value shall be left shifted
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Left shifted value. If cnt >= 8, the operation shall return zero
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255 */
//#include "iopt_memmap.h"
//
//static inline uint8 u8_lsl_u8_u8(uint8 val, uint8 cnt)
//{
//	/*~T*/
//	uint8 temp;
//	/*~T*/
//	/* ## Operation body start [118f8772-4cf5-4483-8c9f-81954ddc9ddf] */
//	temp = (uint8)((uint32)val << cnt);
//
//	return ( (cnt < 8U) ? temp : (uint8)0 );
//
//	/* ## Operation body end [118f8772-4cf5-4483-8c9f-81954ddc9ddf] */
//}
//
///** This operation shall perform a logical shift left of a given uint16 value val by number of bits specified by cnt and return the shifted value. The LSBs shifted shall be filled with zeros.
//i.e. (val << cnt)
//
//@param val Value to be left shifted
//
//Range:	         00(H) ... FFFF(H)
//	           0 ....... 65535
//@param cnt Count specifying the number of bits, the value shall be left shifted
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Left shifted value. If cnt >= 16, the operation shall return zero
//
//Range:	         00(H) ... FFFF(H)
//	           0 ....... 65535 */
//#include "iopt_memmap.h"
//
//static inline uint16 u16_lsl_u16_u8(uint16 val, uint8 cnt)
//{
//	/*~T*/
//	uint16 temp;
//	/*~T*/
//	/* ## Operation body start [bc6c5595-6095-4859-a384-38fee9230d1c] */
//	temp = (uint16)((uint32)val << cnt);
//
//	return ( (cnt < 16U) ? temp : (uint16)0 );
//
//	/* ## Operation body end [bc6c5595-6095-4859-a384-38fee9230d1c] */
//}
//
///** This operation shall perform a logical shift left of a given uint32 value val by number of bits specified by cnt and return the shifted value. The LSBs shifted shall be filled with zeros.
//i.e. (val << cnt)
//
//@param val Value to be left shifted
//
//Range:	         00(H) ... FFFFFFFF(H)
//	           0 ....... 4294967295
//@param cnt Count specifying the number of bits, the value shall be left shifted
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Left shifted value. If cnt >= 32, the operation shall return zero
//
//Range:	         00(H) ... FFFFFFFF(H)
//	           0 ....... 4294967295 */
//#include "iopt_memmap.h"
//
//static inline uint32 u32_lsl_u32_u8(uint32 val, uint8 cnt)
//{
//	/*~T*/
//	uint32 temp;
//	/*~T*/
//	/* ## Operation body start [f22b110a-7756-4a8d-881d-b782db2dbfaa] */
//	temp = (uint32)(val << cnt);
//
//	return ( (cnt < 32U) ? temp : (uint32)0 );
//
//	/* ## Operation body end [f22b110a-7756-4a8d-881d-b782db2dbfaa] */
//}
//
///** This operation shall perform a logical shift left of a given uint64 value val by number of bits specified by cnt and return the shifted value. The LSBs shifted shall be filled with zeros.
//i.e. (val << cnt)
//
//@param val Value to be left shifted
//
//Range:	         00(H) ... FFFFFFFFFFFFFFFF(H)
//	           0 ....... 18446744073709551615
//@param cnt Count specifying the number of bits, the value shall be left shifted
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Left shifted value. If cnt >= 64, the operation shall return zero
//
//Range:	         00(H) ... FFFFFFFFFFFFFFFF(H)
//	           0 ....... 18446744073709551615 */
//#include "iopt_memmap.h"
//
//static inline uint64 u64_lsl_u64_u8(uint64 val, uint8 cnt)
//{
//	/* ## Operation body start [70bea76b-b354-48f7-bdc9-432b08f41901] */
//	/*~T*/
//	uint64 temp;
//	if (cnt < 64U)
//	{
//		temp =(val << cnt);
//	}
//	else
//	{
//		temp =(U64_MIN);
//	}
//	return temp;
//	/* ## Operation body end [70bea76b-b354-48f7-bdc9-432b08f41901] */
//}
//
///** This operation shall perform a logical shift right of a given uint8 value val by number of bits specified by cnt and return the shifted value. The MSBs shifted shall be filled with zeros.
//i.e. (val >> cnt)
//
//@param val Value to be right shifted
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@param cnt Count specifying the number of bits, the value shall be left shifted
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Right shifted value. If cnt >= 8, the operation shall return zero
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255 */
//#include "iopt_memmap.h"
//
//static inline uint8 u8_lsr_u8_u8(uint8 val, uint8 cnt)
//{
//	/* ## Operation body start [713a8c5b-3321-4d7a-8eeb-753064b7805e] */
//	val >>= cnt;
//
//	return ( (cnt < 8U) ? val : (uint8)0 );
//
//	/* ## Operation body end [713a8c5b-3321-4d7a-8eeb-753064b7805e] */
//}
//
///** This operation shall perform a logical shift right of a given uint16 value val by number of bits specified y cnt and return the shifted value. The MSBs shifted shall be filled with zeros.
//i.e. (val >> cnt)
//
//@param val Value to be right shifted
//
//Range:	         00(H) ... FFFF(H)
//	           0 ....... 65535
//@param cnt Count specifying the number of bits, the value shall be left shifted
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Right shifted value. If cnt >= 16, the operation shall return zero
//
//Range:	         00(H) ... FFFF(H)
//	           0 ....... 65535 */
//#include "iopt_memmap.h"
//
//static inline uint16 u16_lsr_u16_u8(uint16 val, uint8 cnt)
//{
//	/* ## Operation body start [d4d9fb93-d0ba-40eb-9cb4-fd890c0593da] */
//	val >>= cnt;
//
//	return ( (cnt < 16U) ? val : (uint16)0 );
//
//	/* ## Operation body end [d4d9fb93-d0ba-40eb-9cb4-fd890c0593da] */
//}
//
///** This operation shall perform a logical shift right of a given uint32 value val by number of bits specified by cnt and return the shifted value. The MSBs shifted shall be filled with zeros.
//i.e. (val >> cnt)
//
//@param val Value to be right shifted
//
//Range:	         00(H) ... FFFFFFFF(H)
//	           0 ....... 4294967295
//@param cnt Count specifying the number of bits, the value shall be left shifted
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Right shifted value. If cnt >= 32, the operation shall return zero
//
//Range:	         00(H) ... FFFFFFFF(H)
//	           0 ....... 4294967295 */
//#include "iopt_memmap.h"
//
//static inline uint32 u32_lsr_u32_u8(uint32 val, uint8 cnt)
//{
//	/* ## Operation body start [da4b8362-44b4-41f6-9ae0-4be54341ad88] */
//	val >>= cnt;
//
//	return ( (cnt < 32U) ? val : (uint32)0 );
//
//	/* ## Operation body end [da4b8362-44b4-41f6-9ae0-4be54341ad88] */
//}
//
///** This operation shall perform a logical shift right of a given uint64 value val by number of bits specified by cnt and return the shifted value. The MSBs shifted shall be filled with zeros.
//i.e. (val >> cnt)
//
//@param val Value to be right shifted
//
//Range:	         00(H) ... FFFFFFFFFFFFFFFF(H)
//	           0 ....... 18446744073709551615
//@param cnt Count specifying the number of bits, the value shall be left shifted
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Right shifted value. If cnt >= 64, the operation shall return zero
//
//Range:	         00(H) ... FFFFFFFFFFFFFFFF(H)
//	           0 ....... 18446744073709551615 */
//#include "iopt_memmap.h"
//
//static inline uint64 u64_lsr_u64_u8(uint64 val, uint8 cnt)
//{
//	/* ## Operation body start [6d387a7c-2d90-4226-8ba6-49216016a2a4] */
//	/*~T*/
//	uint64 temp;
//	if (cnt < 64U)
//	{
//		temp =(val >> cnt);
//	}
//	else
//	{
//		temp = (U64_MIN);
//	}
//	return temp;
//	/* ## Operation body end [6d387a7c-2d90-4226-8ba6-49216016a2a4] */
//}
//
///** This operation shall return the bitwise complement of the given uint8 value i.e. (~val)
//
//@param val Value to be inverted
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Bitwise complement of the given value
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255 */
//#include "iopt_memmap.h"
//
//static inline uint8 u8_inv_u8(uint8 val)
//{
//	/* ## Operation body start [f094211e-0ef2-4117-aa29-3130f5538316] */
//	uint8 temp;
//	/*~T*/
//	temp= ~val;
//	/*~T*/
//	return (uint8)(temp);
//	/*~T*/
//	/* ## Operation body end [f094211e-0ef2-4117-aa29-3130f5538316] */
//}
//
///** This operation shall return the bitwise complement of the given uint16 value i.e. (~val)
//
//@param val Value to be inverted
//
//Range:	         00(H) ... FFFF(H)
//	           0 ....... 65535
//@return Bitwise complement of the given value
//
//Range:	         00(H) ... FFFF(H)
//	           0 ....... 65535 */
//#include "iopt_memmap.h"
//
//static inline uint16 u16_inv_u16(uint16 val)
//{
//	/* ## Operation body start [16cb161a-348e-45e7-b4d4-8e4d113666e8] */
//	uint16 temp;
//	/*~T*/
//	temp= ~val;
//	/*~T*/
//	return (uint16)(temp);
//	/*~T*/
//	/* ## Operation body end [16cb161a-348e-45e7-b4d4-8e4d113666e8] */
//}
//
///** This operation shall return the bitwise complement of the given uint32 value i.e. (~val)
//
//@param val Value to be inverted
//
//Range:	         00(H) ... FFFFFFFF(H)
//	           0 ....... 4294967295
//@return Bitwise complement of the given value
//
//Range:	         00(H) ... FFFFFFFF(H)
//	           0 ....... 4294967295 */
//#include "iopt_memmap.h"
//
//static inline uint32 u32_inv_u32(uint32 val)
//{
//	/* ## Operation body start [06cf5f63-e5c8-482d-b409-ab48b1a4f40a] */
//	uint32 temp;
//	/*~T*/
//	temp= ~val;
//	/*~T*/
//	return (temp);
//	/*~T*/
//	/* ## Operation body end [06cf5f63-e5c8-482d-b409-ab48b1a4f40a] */
//}
//
///** This operation shall return the bitwise complement of the given uint64 value i.e. (~val)
//
//@param val Value to be inverted
//
//Range:	         00(H) ... FFFFFFFFFFFFFFFF(H)
//	           0 ....... 18446744073709551615
//@return Bitwise complement of the given value
//
//Range:	         00(H) ... FFFFFFFFFFFFFFFF(H)
//	           0 ....... 18446744073709551615 */
//#include "iopt_memmap.h"
//
//static inline uint64 u64_inv_u64(uint64 val)
//{
//	/* ## Operation body start [07e9538f-b650-4202-a68c-92b071910836] */
//	uint64 temp;
//	/*~T*/
//	temp= ~val;
//	/*~T*/
//	return (temp);
//	/*~T*/
//	/* ## Operation body end [07e9538f-b650-4202-a68c-92b071910836] */
//}
//
///** This operation shall create an uint8 value which has a bit pattern with only the given bit set i.e. (((uint8)1) << cnt)
//
//@param cnt count value to create the bit pattern
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Bit pattern created from given count
//
//Range:	         00(H) ... 80(H)
//	           0 ....... 128
//Actual Results: 0 or powers of 2 where power ranges from 0 to 7 */
//#include "iopt_memmap.h"
//
//static inline uint8 u8_bit_u8(uint8 cnt)
//{
//	/* ## Operation body start [f8902c3b-692d-4951-a8ad-197f7b890adf] */
//	/*~T*/
//	uint8 temp;
//	if (cnt < 8U)
//	{
//		temp =   (uint8)((1U) << cnt);
//	}
//	else
//	{
//		temp =  (U8_MIN);
//	}
//	return   temp;
//	/* ## Operation body end [f8902c3b-692d-4951-a8ad-197f7b890adf] */
//}
//
///** This operation shall create an uint16 value which has a bit pattern with only the given bit set i.e. (((uint16)1) << cnt)
//
//@param cnt count value to create the bit pattern
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Bit pattern created from given count
//
//Range:	         00(H) ... 8000(H)
//	           0 ....... 32768
//Actual Results: 0 or powers of 2 where power ranges from 0 to 15 */
//#include "iopt_memmap.h"
//
//static inline uint16 u16_bit_u8(uint8 cnt)
//{
//	/* ## Operation body start [e24bfad1-f09c-4ee8-b23a-72b2a17ad770] */
//	/*~T*/
//	uint16   temp;
//	if (cnt < 16U)
//	{
//		temp =   (uint16)((1U) << cnt);
//	}
//	else
//	{
//		temp =   (U16_MIN);
//	}
//	return   temp;
//	/* ## Operation body end [e24bfad1-f09c-4ee8-b23a-72b2a17ad770] */
//}
//
///** This operation shall create an uint32 value which has a bit pattern with only the given bit set i.e. (((uint32)1) << cnt)
//
//@param cnt count value to create the bit pattern
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Bit pattern created from given count
//
//Range:	         00(H) ... 80000000(H)
//	           0 ....... 2147483648
//Actual Results: 0 or powers of 2 where power ranges from 0 to 31 */
//#include "iopt_memmap.h"
//
//static inline uint32 u32_bit_u8(uint8 cnt)
//{
//	/* ## Operation body start [9261fcc3-922e-4637-b69c-fc473340f1f9] */
//	/*~T*/
//	uint32 temp;
//	if (cnt < 32U)
//	{
//		temp = (uint32)(1U) << cnt;
//	}
//	else
//	{
//		temp = (U32_MIN);
//	}
//	return temp;
//	/* ## Operation body end [9261fcc3-922e-4637-b69c-fc473340f1f9] */
//}
//
///** This operation shall create an uint64 value which has a bit pattern with only the given bit set i.e. (((uint64)1) << cnt)
//
//@param cnt count value to create the bit pattern
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Bit pattern created from given count
//
//Range:	         00(H) ... 8000000000000000(H)
//	          0 ....... 9223372036854775808
//Actual Results: 0 or powers of 2 where power ranges from 0 to 63 */
//#include "iopt_memmap.h"
//
//static inline uint64 u64_bit_u8(uint8 cnt)
//{
//	/* ## Operation body start [79d9c53d-1e75-438d-bc44-586827be0de5] */
//	/*~T*/
//	uint64 temp;
//	if (cnt < 64U)
//	{
//		temp = ((uint64)1) << cnt;
//	}
//	else
//	{
//		temp = (U64_MIN);
//	}
//	return temp;
//	/* ## Operation body end [79d9c53d-1e75-438d-bc44-586827be0de5] */
//}
//
///** This operation shall perform a logical set of a single bit (to a given uint8 value) on the position specified by 'cnt' and return the updated value.
//In case that cnt exceed the sizeof val it shall returned 0.
//
//@param val Input value
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@param cnt Bit position which shall be set from 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Set the value */
//#include "iopt_memmap.h"
//
//static inline uint8 u8_set_flag_u8(uint8 val, uint8 cnt)
//{
//	/* ## Operation body start [a1d14d70-4b17-4852-b533-297264f0b040] */
//	/*~T*/
//	uint8 temp;
//	if (cnt < (sizeof(val)*(uint8)8))
//	{
//		/*lint -esym(960,10.5)*/
//		temp = (uint8)((val)|((uint8)((1U) << cnt)));
//	}
//	else
//	{
//		temp = 0;
//	}
//	return temp;
//	/* ## Operation body end [a1d14d70-4b17-4852-b533-297264f0b040] */
//}
//
///** This operation shall perform a logical set of a single bit (to a given uint16 value) on the position specified by 'cnt' and return the updated value.
//In case that cnt exceed the sizeof val it shall returned 0.
//
//@param val Input value
//
//Range:	         0000(H) ... FFFF(H)
//	           0 ....... ....65535
//@param cnt Bit position which shall be set from 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Set the value */
//#include "iopt_memmap.h"
//
//static inline uint16 u16_set_flag_u8(uint16 val, uint8 cnt)
//{
//	/* ## Operation body start [2515eddb-480b-42bc-b9a9-dcab5744669e] */
//	/*~T*/
//	uint16 temp;
//	if (cnt < (sizeof(val)*(uint16)8))
//	{
//		temp = (uint16)((val)|((uint16)((1U) << cnt)));
//	}
//	else
//	{
//		temp = 0;
//	}
//	return temp;
//	/* ## Operation body end [2515eddb-480b-42bc-b9a9-dcab5744669e] */
//}
//
///** This operation shall perform a logical set of a single bit (to a given uint32 value) on the position specified by 'cnt' and return the updated value.
//In case that cnt exceed the sizeof val it shall returned 0.
//
//@param val Input value
//
//Range:	         0000(H) ... FFFFFFFF(H)
//	           0 ........... 4294967295
//@param cnt Bit position which shall be set from 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Set the value */
//#include "iopt_memmap.h"
//
//static inline uint32 u32_set_flag_u8(uint32 val, uint8 cnt)
//{
//	/* ## Operation body start [4b82791a-1112-48c1-8977-4f8751fef884] */
//	/*~T*/
//	uint32 temp;
//	if (cnt < (sizeof(val)*(uint32)8))
//	{
//		temp = (uint32)((val)|((uint32)((1U) << cnt)));
//	}
//	else
//	{
//		temp = 0;
//	}
//	return temp;
//	/* ## Operation body end [4b82791a-1112-48c1-8977-4f8751fef884] */
//}
//
///** This operation shall perform a logical set of a single bit (to a given uint64 value) on the position specified by 'cnt' and return the updated value.
//In case that cnt exceed the sizeof val it shall returned 0.
//
//@param val Input value
//
//Range:	         0000(H) ... FFFFFFFFFFFFFFFF(H)
//	           0 ....... 18446744073709551615
//@param cnt Bit position which shall be set from 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Set the value */
//#include "iopt_memmap.h"
//
//static inline uint64 u64_set_flag_u8(uint64 val, uint8 cnt)
//{
//	/* ## Operation body start [8d80ad98-5f13-45b4-8167-242418a07967] */
//	/*~T*/
//	uint64 temp;
//	if (cnt < (sizeof(val)*(uint64)8))
//	{
//		temp = (uint64)((val)|(((uint64)1) << cnt));
//	}
//	else
//	{
//		temp = 0ULL;
//	}
//	/*~T*/
//	return temp;
//	/*~T*/
//	/* ## Operation body end [8d80ad98-5f13-45b4-8167-242418a07967] */
//}
//
///** This operation shall perform a logical clear of a single bit (to a given uint8 value) on the position specified by 'cnt' and return the updated value.
//In case that cnt exceed the sizeof val it shall returned 0.
//
//@param val Input value
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@param cnt Bit position which shall be cleared from 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Clear the value */
//#include "iopt_memmap.h"
//
//static inline uint8 u8_clear_flag_u8(uint8 val, uint8 cnt)
//{
//	/* ## Operation body start [7a607892-70fd-4f45-b1fb-21d15990d9f2] */
//
//	/*~T*/
//	uint8 temp;
//	if (cnt < (sizeof(val)*(uint8)8))
//	{
//		/* cnt1 = u8_bit_u8(cnt);
//cnt2 = u8_inv_u8(cnt1);
//return (uint8)((val)&(cnt2));
//		 */
//
//
//
//		temp = ((uint8)((val)&(u8_inv_u8(u8_bit_u8(cnt)))));
//
//	}
//	else
//	{
//		temp = 0;
//	}
//	return temp;
//	/* ## Operation body end [7a607892-70fd-4f45-b1fb-21d15990d9f2] */
//}
//
///** This operation shall perform a logical clear of a single bit (to a given uint16 value) on the position specified by 'cnt' and return the updated value.
//In case that cnt exceed the sizeof val it shall returned 0.
//
//@param val Input value
//
//Range:	         0000(H) ... FFFF(H)
//	           0 ....... ....65535
//@param cnt Bit position which shall be cleared from 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Clear the value */
//#include "iopt_memmap.h"
//
//static inline uint16 u16_clear_flag_u8(uint16 val, uint8 cnt)
//{
//	/* ## Operation body start [b5676416-ffa1-4c02-ba0b-1eb017f79fc8] */
//
//	/*~T*/
//	uint16 temp;
//	if (cnt < (sizeof(val)*(uint16)8))
//	{
//
//
//		temp = (uint16)((val)&(u16_inv_u16(u16_bit_u8(cnt))));
//
//	}
//	else
//	{
//		temp = 0;
//	}
//	return temp;
//	/* ## Operation body end [b5676416-ffa1-4c02-ba0b-1eb017f79fc8] */
//}
//
///** This operation shall perform a logical clear of a single bit (to a given uint32 value) on the position specified by 'cnt' and return the updated value.
//In case that cnt exceed the sizeof val it shall returned 0.
//
//@param val Input value
//
//Range:	         0000(H) ... FFFFFFFF(H)
//	           0 ........... 4294967295
//@param cnt Bit position which shall be cleared from 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Clear the value */
//#include "iopt_memmap.h"
//
//static inline uint32 u32_clear_flag_u8(uint32 val, uint8 cnt)
//{
//	/* ## Operation body start [03f086e4-4553-4c2c-87c4-ed7af19cd8ed] */
//
//	/*~T*/
//	uint32 temp;
//	if (cnt < (sizeof(val)*(uint8)8))
//	{
//
//
//		temp = (uint32)((val)&(u32_inv_u32(u32_bit_u8(cnt))));
//
//	}
//	else
//	{
//		temp = 0;
//	}
//	return temp;
//	/* ## Operation body end [03f086e4-4553-4c2c-87c4-ed7af19cd8ed] */
//}
//
///** This operation shall perform a logical clear of a single bit (to a given uint64 value) on the position specified by 'cnt' and return the updated value.
//In case that cnt exceed the sizeof val it shall returned 0.
//
//@param val Input value
//
//Range:	         0000(H) ... FFFFFFFFFFFFFFFF(H)
//	           0 ....... 18446744073709551615
//@param cnt Bit position which shall be set from 'val'
//
//Range:	         00(H) ... FF(H)
//	           0 ....... 255
//@return Set the value */
//#include "iopt_memmap.h"
//
//static inline uint64 u64_clear_flag_u8(uint64 val, uint8 cnt)
//{
//	/* ## Operation body start [a4675c68-f088-42c8-99dd-8ffa652a8c83] */
//
//	/*~T*/
//	uint64 temp;
//	if (cnt < (sizeof(val)*(uint8)8))
//	{
//
//
//		temp = (uint64)((val)&(u64_inv_u64(u64_bit_u8(cnt))));
//	}
//	else
//	{
//		temp = 0LL;
//	}
//	/*~T*/
//	return temp;
//	/*~T*/
//	/* ## Operation body end [a4675c68-f088-42c8-99dd-8ffa652a8c83] */
//}
//
///** FLIP-FLOP with priorised SET:
//if     lv_set = 1, then return 1
//elseif lv_rst = 1, then return 0
//else   return lv_in  (state unchanged)
//
//@param lv_in Input
//
//Range:	         0 ... 1
//	           0 .......1
//@param lv_set SET boolean
//
//Range:	         0 ... 1
//	           0 .......1
//@param lv_rst RESET boolean
//
//Range:	         0 ... 1
//	           0 .......1
//@return Set the value */
//#include "iopt_memmap.h"
//
//static inline boolean flag_sr_ff_flag_flag_flag(boolean lv_in, boolean lv_set, boolean lv_rst)
//{
//	/* ## Operation body start [43cb600a-a38a-48d7-8e57-c9112f337b65] */
//	boolean resultflag;
//	if ( (uint8)lv_set != (uint8)0 )
//	{
//		resultflag = 1 ;
//	}
//	else
//	{
//		if ( (uint8)lv_rst != (uint8)0  )
//		{
//			resultflag = 0 ;
//		}
//		else
//		{
//			resultflag = lv_in ;
//		}
//	}
//	return /*lint --e(530)*/ resultflag;
//	/* ## Operation body end [43cb600a-a38a-48d7-8e57-c9112f337b65] */
//}
//
///** if     lv_rst = 1, then return 0
//    elseif lv_set = 1, then return 1
//    else   return lv_in  (state unchanged)
//
//@param lv_in Input
//
//Range:	         0 ... 1
//	           0 .......1
//@param lv_rst RESET boolean
//
//Range:	         0 ... 1
//	           0 .......1
//@param lv_set SET boolean
//
//Range:	         0 ... 1
//	           0 .......1
//@return Set the value */
//#include "iopt_memmap.h"
//
//static inline boolean flag_rs_ff_flag_flag_flag(boolean lv_in, boolean lv_rst, boolean lv_set)
//{
//	/* ## Operation body start [8d4ac6a8-2d8e-4d34-b2ed-2f24692ec582] */
//	boolean resultflag;
//	if ( (uint8)lv_rst != (uint8)0  )
//	{
//		resultflag = 0 ;
//	}
//	else
//	{
//		if ( (uint8)lv_set != (uint8)0  )
//		{
//			resultflag = 1 ;
//		}
//		else
//		{
//			resultflag = lv_in ;
//		}
//	}
//	return /*lint --e(530)*/ resultflag;
//	/* ## Operation body end [8d4ac6a8-2d8e-4d34-b2ed-2f24692ec582] */
//}
//
///** return 1, if lv_0_old = 0, and lv_1_act = 1  (rising edge detection);  otherwise 0
//
//@param lv_0_old Input : Previous value
//
//Range:	         0 ... 1
//	           0 .......1
//@param lv_1_act Range:	         0 ... 1
//	           0 .......1
//@return Set the value */
//#include "iopt_memmap.h"
//
//static inline boolean flag_edge01_det_flag_flag(boolean lv_0_old, boolean lv_1_act)
//{
//	/* ## Operation body start [82fc309d-eac0-4c4f-a1fc-9a00699047b0] */
//	boolean resultflag;
//	if ( ( ( (uint8)lv_0_old == (uint8)0 ) && ( (uint8)lv_1_act == (uint8)1 ) ) )
//	{
//		resultflag = 1 ;
//	}
//	else
//	{
//		resultflag = 0 ;
//	}
//	return resultflag ;
//	/* ## Operation body end [82fc309d-eac0-4c4f-a1fc-9a00699047b0] */
//}
//
///** return 1, if lv_1_old = 1 and lv_0_act = 0  (falling edge detection);  otherwise 0
//
//@param lv_1_old Input : Previous value
//
//Range:	         0 ... 1
//	           0 .......1
//@param lv_0_act Range:	         0 ... 1
//	           0 .......1
//@return Set the value */
//#include "iopt_memmap.h"
//
//static inline boolean flag_edge10_det_flag_flag(boolean lv_1_old, boolean lv_0_act)
//{
//	/* ## Operation body start [1dcd94d5-e71c-4ad3-aef9-d04ff983cb62] */
//	boolean resultflag;
//	if ( ( ( (uint8)lv_1_old == (uint8)1 ) && ( (uint8)lv_0_act == (uint8)0 ) ) )
//	{
//		resultflag = 1 ;
//	}
//	else
//	{
//		resultflag = 0 ;
//	}
//	return resultflag ;
//	/* ## Operation body end [1dcd94d5-e71c-4ad3-aef9-d04ff983cb62] */
//}
//
///** result = lv_a ^ lv_b ; detects if bit-values different; (rising / falling edge detection):
//
//if lv_a = 0,  lv_b = 0:   result 0
//if lv_a = 0,  lv_b = 1:   result 1
//if lv_a = 1,  lv_b = 0:   result 1
//if lv_a = 1,  lv_b = 1:   result 0
//
//@param lv_a Input A
//
//Range:	         0 ... 1
//	           0 .......1
//@param lv_b Input B
//Range:	         0 ... 1
//	           0 .......1
//@return Set the value */
//#include "iopt_memmap.h"
//
//static inline boolean flag_xor_flag_flag(boolean lv_a, boolean lv_b)
//{
//	/* ## Operation body start [00a2bc09-458b-4ee0-8ff0-61a4bd2b5bac] */
//	return ( lv_a ^ lv_b );
//	/* ## Operation body end [00a2bc09-458b-4ee0-8ff0-61a4bd2b5bac] */
//}
//
///** This operation shall perform a logical bitmove of a single bit (bitval) (to a given uint32 value) on the bitposition 'cnt', and return the updated value.
// result = val, where val[BIT.cnt] = bitval
//
//In case that cnt exceed the sizeof val it shall return 0.
//
//@param val Input value
//
//Range:           0 ... FF
//               0 ......255
//@param cnt Input count
//
//Range:           0 ... FF
//               0 ......255
//@param bitval Input Bit value
//Range:           0 ... 1
//               0 .......1
//@return Set the value */
//#include "iopt_memmap.h"
//
//static inline uint8 u8_move_flag_u8_flag(uint8 val, uint8 cnt, boolean bitval)
//{
//	/* ## Operation body start [fb223244-d066-46ca-96e5-d1c5ff39b9f6] */
//	/*~T*/
//	uint8 temp,temp2;
//	if (cnt < 8U)
//	{
//		temp2 = val & ((uint8) (~ ((uint8)(1U << cnt))));
//		temp2 = temp2 ^ ((uint8) ((uint32)bitval << cnt));
//
//		temp = temp2;
//	}
//	else
//	{
//		temp = 0;
//	}
//	return temp;
//	/* ## Operation body end [fb223244-d066-46ca-96e5-d1c5ff39b9f6] */
//}
//
///** This operation shall perform a logical bitmove of a single bit (bitval) (to a given uint32 value) on the bitposition 'cnt', and return the updated value.
// result = val, where val[BIT.cnt] = bitval
//
//In case that cnt exceed the sizeof val it shall return 0.
//
//@param val Input value
//
//Range:           0 ... FFFF
//               0 ......65535
//@param cnt Input count
//
//Range:           0 ... FF
//               0 ......255
//@param bitval Input Bit value
//Range:           0 ... 1
//               0 .......1
//@return Set the value */
//#include "iopt_memmap.h"
//
//static inline uint16 u16_move_flag_u8_flag(uint16 val, uint8 cnt, boolean bitval)
//{
//	/* ## Operation body start [0838eaa8-3fd2-45dd-a48d-261a13a2db0e] */
//	/*~T*/
//	uint16 temp,temp2;
//	if (cnt < 16U)
//	{
//		temp2 = val & ((uint16) (~ ((uint16)(0x01U << cnt))));
//		temp2 = temp2 ^ ((uint16) ((uint32)bitval << cnt));
//
//		temp = temp2;
//	}
//	else
//	{
//		temp = 0;
//	}
//	return temp;
//	/* ## Operation body end [0838eaa8-3fd2-45dd-a48d-261a13a2db0e] */
//}
//
///** This operation shall perform a logical bitmove of a single bit (bitval) (to a given uint32 value) on the bitposition 'cnt', and return the updated value.
// result = val, where val[BIT.cnt] = bitval
//
//In case that cnt exceed the sizeof val it shall return 0.
//
//@param val Input value
//
//Range:           0 ... FFFFFFFF
//               0 ......4294967295
//@param cnt Input count
//
//Range:           0 ... FF
//               0 ......255
//@param bitval Input Bit value
//Range:           0 ... 1
//               0 .......1
//@return Set the value */
//#include "iopt_memmap.h"
//
//static inline uint32 u32_move_flag_u8_flag(uint32 val, uint8 cnt, boolean bitval)
//{
//	/* ## Operation body start [870c6c0d-97dd-44a8-841a-e59f318914c6] */
//
//	/* move val into result, then store bitval in bitnumber result[.cnt] */
//	/*~T*/
//	uint32 temp,temp2;
//	if (cnt < 32U)
//	{
//		temp2 = val & ((uint32) (~ ((uint32)(0x01U << cnt))));
//		temp2 = temp2 ^ ((uint32) ((uint32)bitval << cnt));
//
//		temp = temp2;
//	}
//	else
//	{
//		temp = 0;
//	}
//	return temp;
//	/* ## Operation body end [870c6c0d-97dd-44a8-841a-e59f318914c6] */
//}
//
///** This operation shall perform a logical bitmove of a single bit (bitval) (to a given uint32 value) on the bitposition 'cnt', and return the updated value.
// result = val, where val[BIT.cnt] = bitval
//
//In case that cnt exceed the sizeof val it shall return 0.
//
//@param val Input value
//
//Range:           0000(H) ... FFFFFFFFFFFFFFFF(H)
//               0 ....... 18446744073709551615
//@param cnt Input count
//
//Range:           0 ... FF
//               0 ......255
//@param bitval Input Bit value
//Range:           0 ... 1
//               0 .......1
//@return Set the value */
//#include "iopt_memmap.h"
//
//static inline uint64 u64_move_flag_u8_flag(uint64 val, uint8 cnt, boolean bitval)
//{
//	/* ## Operation body start [0299ca45-1bd4-4984-a526-8ac74415acd2] */
//	/*~T*/
//	uint64 temp,temp2;
//	if (cnt < 64U)
//	{
//		temp2 = val & ((uint64) (~ ((uint64)((uint64)0x01ULL << cnt))));
//		temp2 = temp2 ^ ((uint64) ((uint64)bitval << cnt));
//
//		temp = temp2;
//	}
//	else
//	{
//		temp = (uint64)0;
//	}
//	return temp;
//	/* ## Operation body end [0299ca45-1bd4-4984-a526-8ac74415acd2] */
//}
//
//
///*~E*/
//#include "iopt_memmap.h"
#endif
