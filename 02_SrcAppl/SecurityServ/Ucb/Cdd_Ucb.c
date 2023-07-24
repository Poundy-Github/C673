
#include "Cdd_Ucb.h"
#include "IfxDmu_reg.h"
#include "Ifx_Ssw_Infra.h"
#include "IfxStm_reg.h"
#include "verify.h"
#include "Dsm_Main.h"

#define IfxScuWdt_getSafetyWatchdogPassword Ifx_Ssw_getSafetyWatchdogPassword
#define IfxScuWdt_clearSafetyEndinit        Ifx_Ssw_clearSafetyEndinit
#define IfxScuWdt_setSafetyEndinit          Ifx_Ssw_setSafetyEndinit
//#define IfxFlash_disableWriteProtection     Ucb_IfxFlash_disableWriteProtection
//#define IfxFlash_enterPageMode              Ucb_Fls_lEnterPageMode

#define UCB_STATIC                          static
#define UCB_STATIC_INLINE                   static inline


#define UCB_BMHD0_ORIG_ADDR_START           (0xAF400000)
#define UCB_BMHD1_ORIG_ADDR_START           (0xAF400200)
#define UCB_BMHD2_ORIG_ADDR_START           (0xAF400400)
#define UCB_BMHD3_ORIG_ADDR_START           (0xAF400600)
#define UCB_DBG_ORIG_ADDR_START             (0xAF402400)


#define UCB_DMU_HF_PROCONDBG                ((volatile Ifx_DMU_HF_PROCONDBG*)(volatile void*)&(DMU_HF_PROCONDBG))
#define UCB_DMU_HF_CONFIRM1                 ((volatile Ifx_DMU_HF_CONFIRM1*)(volatile void*)&(DMU_HF_CONFIRM1))
#define UCB_DMU_SP_PROCONHSM                    ((volatile Ifx_DMU_SP_PROCONHSM*)(volatile void*)&(DMU_SP_PROCONHSM))
#define UCB_DBG_ORIG_PROCONDBG              ((volatile Ifx_DMU_HF_PROCONDBG*)(volatile void*)&(UCB_DBG_ORIG_ADDR_START))
#define UCB_LOCK                            (1u)
#define UCB_UNLOCK                          (0u)
#define UCB_RETY_CNT_MAX                    (2u)
#define UCB_DBG_REG_DEFAULT_VALUE           (0u)
#define UCB_DBG_REG_DBGIFLOCK_VALUE         (0x00000002)


/*DFLASH base/start address*/
#define UCB_DMU_BASE_ADDRESS                ((uint32)(0xAF000000U))
#define UCB_DF0_UCB_BASE_ADDRESS            ((uint32)(0xAF400000U))

#define UCB_CYCLE_5554                      ((uint32)(0x00005554U))
#define UCB_CYCLE_AAA8                      ((uint32)(0x0000AAA8U))
#define UCB_CYCLE_55F0                      ((uint32)(0x000055F0U))
#define UCB_CYCLE_AA50                      ((uint32)(0x0000AA50U))
#define UCB_CYCLE_AA58                      ((uint32)(0x0000AA58U))
#define UCB_CYCLE_553C                      ((uint32)(0x0000553CU))

/*DFLASH PFLASH write protection register offset address*/
#define UCB_PROCONPp0                       ((uint32)(0x00002000U))
#define UCB_PROCONPp1                       ((uint32)(0x00002004U))
#define UCB_PROCONPp2                       ((uint32)(0x00002008U))
#define UCB_PROCONPp3                       ((uint32)(0x0000200CU))
#define UCB_PROCONPp4                       ((uint32)(0x00002010U))
#define UCB_PROCONPp5                       ((uint32)(0x00002014U))

#define UCB_MASK_HIGHER4_NIBBLES            ((uint32)0xFFFF0000U)
#define POSITION_0                          ((uint32)0)
/* Dflash busy status */
#define UCB_FLS_D0BUSY                      (0x00000001U)
/* Operational error */
#define UCB_FLS_OPER_ERROR                  (0x00000001U)


#define UCB_VALUE_80                        ((uint32)(0x00000080U))
#define UCB_VALUE_F0                        ((uint32)(0x000000F0U))
#define UCB_VALUE_A0                        ((uint32)(0x000000A0U))
#define UCB_VALUE_5D                        ((uint32)(0x0000005DU))
#define UCB_VALUE_A6                        ((uint32)(0x000000A6U))
#define UCB_VALUE_00                        ((uint32)(0x00000000U))
#define UCB_VALUE_FA                        ((uint32)(0x000000FAU))
#define UCB_VALUE_50                        ((uint32)(0x00000050U))
#define UCB_VALUE_70                        ((uint32)(0x00000070U))
#define UCB_VALUE_CC                        ((uint32)(0x000000CCU))
#define UCB_VALUE_AA                        ((uint32)(0x000000AAU))
#define UCB_VALUE_60                        ((uint32)(0x00000060U))
#define UCB_VALUE_14                        ((uint32)(0x00000014U))
#define UCB_VALUE_11                        ((uint32)(0x00000011U))/*xx11H for UCB17 = UCB_DFLASH_ORIG and UCB25 = UCB_DFLASH_COPY*/
#define UCB_VALUE_12                        ((uint32)(0x00000012U))/*xx12H for UCB18 = UCB_DBG_ORIG and UCB26 = UCB_DBG_COPY*/
#define UCB_VALUE_20                        ((uint32)(0x00000020U))/*xx20H for UCB16 and UCB24 to disable global read and write protection */
#define UCB_VALUE_F5                        ((uint32)(0x000000F5U))
#define UCB_VALUE_FF_NONE                   ((uint32)(0x000000FFU))/*no exit*/

/*  number of ucb sector   */
#define UCB_DFLASH_NUM_UCB_SECTORS          (48u)
/*UCB18 (UCB_DBG)*/
#define UCB_DFLASH_UCB_DBG_UCB18            (18u)
/*UCB26 (UCB_DBG_COPY)*/
#define UCB_DFLASH_UCB_DBG_COPY_UCB26       (26u)

#define UCB_CONFIRMATION_UNLOCKED           (0x43211234u)
#define UCB_CONFIRMATION_CONFIRMED          (0x57b5327fu)

#define UCB_MEMORY_INIT_DEGIFLOCK           (1u)
#define UCB_MEMORY_INIT_DEGIFUNLOCK         (2u)

/*whether need password to disable protect*/
#define UCB_DIS_PROTECTION_BY_PASSWORD      (1u)
#define UCB_DIS_PROTECTION_NO_PASSWORD      (0u)

#define UCB_BLOCK_SIZE_6                    (6u)
#define UCB_BLOCK_SIZE_2                    (2u)
#define UCB_BLOCK_SIZE_12                   (12u)
#define UCB_BLOCK_SIZE_8                   (8u)


UCB_STATIC uint8 g_UcbDBGIFLockState = 0xFFu;
UCB_STATIC uint8 g_UcbDBGConfirmState = 0xFFu;
UCB_STATIC uint8 g_UcbErrorValue=0u;
#if (UCB_DBG_PASSWORD_CONST_SWITCH == STD_OFF)
UCB_STATIC uint8 g_u8UcbDBGIFLockPassword_input[32u];
UCB_STATIC uint8 g_u8UcbDBGIFLockPassword_output[32u];
UCB_STATIC uint32 g_u32UcbDBGIFLockPassword[8u];
UCB_STATIC Ucb_DFlashData_Type Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[UCB_BLOCK_SIZE_6];
UCB_STATIC Ucb_DFlashData_Type Ucb_DFLASH0_UCB26_DBG_COPY_Lock[UCB_BLOCK_SIZE_6];
#endif
uint8 g_UcbPFlashIFLockState =0x00u;
uint8 g_UcbOTPLockState =0x00u;

const Ucb_DFlashData_Type Ucb_DFLASH0_UCB17_DFLASH_ORIG_Lock[UCB_BLOCK_SIZE_6]=
{
	{	// PROCONUSR(Single/complesens)  + PROCONDF (Focus on this part)
		0xAF402200,
		0x00000000,	
		0x80000000,
	},	
	{	// PW0-1
		0xAF402300,
		0x00000000,
		0x00000000,
	},
	{	// PW2-3
		0xAF402308,
		0x00000000,
		0x00000000,
	},
	{   //PW4-5
		0xAF402310,
		0x00000000,
		0x00000000,
	},
	{   //PW6-7
		0xAF402318,
		0x00000000,
		0x00000000,
	},
	
	{	// Confirmation Code
		0xAF4023F0,
		UCB_CONFIRMATION_CONFIRMED,
		0x0,
	}
};
const Ucb_DFlashData_Type Ucb_DFLASH0_UCB25_DFLASH_COPY_Lock[UCB_BLOCK_SIZE_6]=
{
	{	// PROCONUSR(Single/complesens)  + PROCONDF (Focus on this part)
		0xAF403200,
		0x00000000,	
		0x80000000,
	},	
	{	// PW0-1
		0xAF403300,
		0x00000000,	
		0x1,
	},
	{	// PW2-3
		0xAF403308,
		0x00000002,	
		0x00000003,	
	},
	{   //PW4-5
		0xAF403310,
		0x00000004,	
		0x00000005,	
	},
	{   //PW6-7
		0xAF403318,
		0x00000006,
		0x00000007,
	},
	
	{	// Confirmation Code
		0xAF4033F0,
		UCB_CONFIRMATION_CONFIRMED,
		0x0,
	}    
};
const Ucb_DFlashData_Type Ucb_DFLASH0_UCB19_HSM_ORIG_Lock[UCB_BLOCK_SIZE_2]=
{
    {	// DMU_SP_PROCONHSM 
		0xAF402600,
		0x00000001,	
		0x00000000,
	},	
	{	// Confirmation Code
		0xAF4027F0,
		UCB_CONFIRMATION_CONFIRMED,
		0x0,
	}
};
const Ucb_DFlashData_Type Ucb_DFLASH0_UCB27_HSM_COPY_Lock[UCB_BLOCK_SIZE_2]=
{
	{	// DMU_SP_PROCONHSM 
		0xAF403600,
		0x00000001,	
		0x00000000,
	},	
	{	// Confirmation Code
		0xAF4037F0,
		UCB_CONFIRMATION_CONFIRMED,
		0x00000000,
	}
};


const Ucb_IfxFlash_flashSectorType Ucb_dFlashTableUcbSectorAddr[UCB_DFLASH_NUM_UCB_SECTORS] = 
{
    {0xAF400000, 0xAF4001FF},   //UCB0
    {0xAF400200, 0xAF4003FF},   //UCB1
    {0xAF400400, 0xAF4005FF},   //UCB2
    {0xAF400600, 0xAF4007FF},   //UCB3
    {0xAF400800, 0xAF4009FF},   //UCB4
    {0xAF400A00, 0xAF400BFF},   //UCB5
    {0xAF400C00, 0xAF400DFF},   //UCB6
    {0xAF400E00, 0xAF400FFF},   //UCB7
    {0xAF401000, 0xAF4011FF},   //UCB8
    {0xAF401200, 0xAF4013FF},   //UCB9
    {0xAF401400, 0xAF4015FF},   //UCB10
    {0xAF401600, 0xAF4017FF},   //UCB11
    {0xAF401800, 0xAF4019FF},   //UCB12
    {0xAF401A00, 0xAF401BFF},   //UCB13
    {0xAF401C00, 0xAF401DFF},   //UCB14
    {0xAF401E00, 0xAF401FFF},   //UCB15
    {0xAF402000, 0xAF4021FF},   //UCB16
    {0xAF402200, 0xAF4023FF},   //UCB17
    {0xAF402400, 0xAF4025FF},   //UCB18
    {0xAF402600, 0xAF4027FF},   //UCB19
    {0xAF402800, 0xAF4029FF},   //UCB20
    {0xAF402A00, 0xAF402BFF},   //UCB21
    {0xAF402C00, 0xAF402DFF},   //UCB22
    {0xAF402E00, 0xAF402FFF},   //UCB23
    {0xAF403000, 0xAF4031FF},   //UCB24
    {0xAF403200, 0xAF4033FF},   //UCB25
    {0xAF403400, 0xAF4035FF},   //UCB26
    {0xAF403600, 0xAF4037FF},   //UCB27
    {0xAF403800, 0xAF4039FF},   //UCB28
    {0xAF403A00, 0xAF403BFF},   //UCB29
    {0xAF403C00, 0xAF403DFF},   //UCB30
    {0xAF403E00, 0xAF403FFF},   //UCB31
    {0xAF404000, 0xAF4041FF},   //UCB32
    {0xAF404200, 0xAF4043FF},   //UCB33
    {0xAF404400, 0xAF4045FF},   //UCB34
    {0xAF404600, 0xAF4047FF},   //UCB35
    {0xAF404800, 0xAF4049FF},   //UCB36
    {0xAF404A00, 0xAF404BFF},   //UCB37
    {0xAF404C00, 0xAF404DFF},   //UCB38
    {0xAF404E00, 0xAF404FFF},   //UCB39
    {0xAF405000, 0xAF4051FF},   //UCB40
    {0xAF405200, 0xAF4053FF},   //UCB41
    {0xAF405400, 0xAF4055FF},   //UCB42
    {0xAF405600, 0xAF4057FF},   //UCB43
    {0xAF405800, 0xAF4059FF},   //UCB44
    {0xAF405A00, 0xAF405BFF},   //UCB45
    {0xAF405C00, 0xAF405DFF},   //UCB46
    {0xAF405E00, 0xAF405FFF}   //UCB47
};

//PFlash access protect enable
Ucb_DFlashData_Type DFLASH0_UCB16_Lock[12] =
{
    {	// PROCONPp0
        0xAF402000,
        0x00FF0000,	 //write protection S16-S23
        0x0,
	},
    {	// PROCONPp1
        0xAF402004,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp2
        0xAF402008,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp3
        0xAF40200C,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp4
        0xAF402010,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp5
        0xAF402014,
        0x00000000,	
        0x0,
	},
	{	// PROCONPF 
		0xAF4020C0,
		0x80000000,	
		0x0,
	},
	{	// PW0-1
		0xAF402100,
        UCB_PFlash_PASSWARD_PW0,
        UCB_PFlash_PASSWARD_PW1,
	},
	{	// PW2-3
		0xAF402108,
        UCB_PFlash_PASSWARD_PW2,
        UCB_PFlash_PASSWARD_PW3,
	},
	{//PW4-5
		0xAF402110,
        UCB_PFlash_PASSWARD_PW4,
        UCB_PFlash_PASSWARD_PW5,
	},
	{//PW6-7
		0xAF402118,
        UCB_PFlash_PASSWARD_PW6,
        UCB_PFlash_PASSWARD_PW7,
	},
	{	// Confirmation Code
		0xAF4021F0,
		UCB_CONFIRMATION_UNLOCKED,	//0x43211234,	//0x57B5327F
		0x0,
	}
};


//PFlash access protect disable
const Ucb_DFlashData_Type DFLASH0_UCB16_Unlock[12] =
{
    {	// PROCONPp0
        0xAF402000,
        0x00000000,	//Disable write protection S16-S23
        0x0,
	},
    {	// PROCONPp1
        0xAF402004,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp2
        0xAF402008,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp3
        0xAF40200C,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp4
        0xAF402010,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp5
        0xAF402014,
        0x00000000,	
        0x0,
	},
	{	// PROCONPF 
		0xAF4020C0,
		0x00000000,	
		0x0,
	},
	{	// PW0-1
		0xAF402100,
        UCB_PFlash_PASSWARD_PW0,
        UCB_PFlash_PASSWARD_PW1,
	},
	{	// PW2-3
		0xAF402108,
        UCB_PFlash_PASSWARD_PW2,
        UCB_PFlash_PASSWARD_PW3,
	},
	{//PW4-5
		0xAF402110,
        UCB_PFlash_PASSWARD_PW4,
        UCB_PFlash_PASSWARD_PW5,
	},
	{//PW6-7
		0xAF402118,
        UCB_PFlash_PASSWARD_PW6,
        UCB_PFlash_PASSWARD_PW7,
	},
	{	// Confirmation Code
		0xAF4021F0,
		UCB_CONFIRMATION_UNLOCKED,	//0x43211234,	//0x57B5327F
		0x0,
	}
};

//PFlash access protect enable - Copy part
const Ucb_DFlashData_Type DFLASH0_UCB24_Lock[12] =
{
    {	// PROCONPp0
        0xAF403000,
        0x000F0000,	
        0x0,
	},
    {	// PROCONPp1
        0xAF403004,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp2
        0xAF403008,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp3
        0xAF40300C,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp4
        0xAF403010,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp5
        0xAF403014,
        0x00000000,	
        0x0,
	},
	{	// PROCONPF 
		0xAF4030C0,
		0x80000000,	
		0x0,
	},
	{	// PW0-1
		0xAF403100,
        UCB_PFlash_PASSWARD_PW0,
        UCB_PFlash_PASSWARD_PW1,
	},
	{	// PW2-3
		0xAF403108,
        UCB_PFlash_PASSWARD_PW2,
        UCB_PFlash_PASSWARD_PW3,
	},
	{//PW4-5
		0xAF403110,
        UCB_PFlash_PASSWARD_PW4,
        UCB_PFlash_PASSWARD_PW5,
	},
	{//PW6-7
		0xAF403118,
        UCB_PFlash_PASSWARD_PW6,
        UCB_PFlash_PASSWARD_PW7,
	},
	{	// Confirmation Code
		0xAF4031F0,
		UCB_CONFIRMATION_UNLOCKED,	//0x43211234,	//0x57B5327F
		0x0,
	}
};

//PFlash access protect disable - Copy part
const Ucb_DFlashData_Type DFLASH0_UCB24_Unlock[12] =
{
    {	// PROCONPp0
        0xAF403000,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp1
        0xAF403004,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp2
        0xAF403008,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp3
        0xAF40300C,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp4
        0xAF403010,
        0x00000000,	
        0x0,
	},
    {	// PROCONPp5
        0xAF403014,
        0x00000000,	
        0x0,
	},
	{	// PROCONPF 
		0xAF4030C0,
		0x00000000,	
		0x0,
	},
	{	// PW0-1
		0xAF403100,
        UCB_PFlash_PASSWARD_PW0,
        UCB_PFlash_PASSWARD_PW1,
	},
	{	// PW2-3
		0xAF403108,
        UCB_PFlash_PASSWARD_PW2,
        UCB_PFlash_PASSWARD_PW3,
	},
	{//PW4-5
		0xAF403110,
        UCB_PFlash_PASSWARD_PW4,
        UCB_PFlash_PASSWARD_PW5,
	},
	{//PW6-7
		0xAF403118,
        UCB_PFlash_PASSWARD_PW6,
        UCB_PFlash_PASSWARD_PW7,
	},
	{	// Confirmation Code
		0xAF4031F0,
		UCB_CONFIRMATION_UNLOCKED,	//0x43211234,	//0x57B5327F
		0x0,
	}
};

//OTP Origin protect enable 
Ucb_DFlashData_Type DFLASH0_UCB32_Lock[8] =
{
    {	// PROCONOTPp0
        0xAF404000,
        0x00FF0000,	 //enable OTP protection S16-S23
        0x0,
	},
    {	// PROCONOTPp1
        0xAF404004,
        0x00000000,	
        0x0,
	},
    {	// PROCONOTPp2
        0xAF404008,
        0x00000000,	
        0x0,
	},
    {	// PROCONOTPp3
        0xAF40400C,
        0x00000000,	
        0x0,
	},
    {	// PROCONOTPp4
        0xAF404010,
        0x00000000,	
        0x0,
	},
    {	// PROCONOTPp5
        0xAF404014,
        0x00000000,	
        0x0,
	},
	{	// PROCONTP 
		0xAF4041E8,
		0x00000000,	
		0x0,
	},
	{	// Confirmation Code
		0xAF4041F0,
		UCB_CONFIRMATION_UNLOCKED,	//0x43211234,	//0x57B5327F
		0x0,
	}
};

//OTP Origin protect disable 
Ucb_DFlashData_Type DFLASH0_UCB32_unLock[8] =
{
    {	// PROCONOTPp0
        0xAF404000,
        0x00000000,	 //enable OTP protection S16-S23
        0x0,
	},
    {	// PROCONOTPp1
        0xAF404004,
        0x00000000,	
        0x0,
	},
    {	// PROCONOTPp2
        0xAF404008,
        0x00000000,	
        0x0,
	},
    {	// PROCONOTPp3
        0xAF40400C,
        0x00000000,	
        0x0,
	},
    {	// PROCONOTPp4
        0xAF404010,
        0x00000000,	
        0x0,
	},
    {	// PROCONOTPp5
        0xAF404014,
        0x00000000,	
        0x0,
	},
	{	// PROCONTP 
		0xAF4041E8,
		0x00000000,	
		0x0,
	},
	{	// Confirmation Code
		0xAF4041F0,
		UCB_CONFIRMATION_UNLOCKED,	//0x43211234,	//0x57B5327F
		0x0,
	}
};

//OTP Copy protect enable
Ucb_DFlashData_Type DFLASH0_UCB40_Lock[8] =
{
    {	// PROCONOTPp0
        0xAF405000,
        0x00FF0000,	 //enable OTP protection S16-S23
        0x0,
	},
    {	// PROCONOTPp1
        0xAF405004,
        0x00000000,	
        0x0,
	},
    {	// PROCONOTPp2
        0xAF405008,
        0x00000000,	
        0x0,
	},
    {	// PROCONOTPp3
        0xAF40500C,
        0x00000000,	
        0x0,
	},
    {	// PROCONOTPp4
        0xAF405010,
        0x00000000,	
        0x0,
	},
    {	// PROCONOTPp5
        0xAF405014,
        0x00000000,	
        0x0,
	},
	{	// PROCONTP 
		0xAF4051E8,
		0x00000000,	
		0x0,
	},
	{	// Confirmation Code
		0xAF4051F0,
		UCB_CONFIRMATION_UNLOCKED,	//0x43211234,	//0x57B5327F
		0x0,
	}
};

//OTP Copy protect disable
Ucb_DFlashData_Type DFLASH0_UCB40_unLock[8] =
{
    {	// PROCONOTPp0
        0xAF405000,
        0x00FF0000,	 //enable OTP protection S16-S23
        0x0,
	},
    {	// PROCONOTPp1
        0xAF405004,
        0x00000000,	
        0x0,
	},
    {	// PROCONOTPp2
        0xAF405008,
        0x00000000,	
        0x0,
	},
    {	// PROCONOTPp3
        0xAF40500C,
        0x00000000,	
        0x0,
	},
    {	// PROCONOTPp4
        0xAF405010,
        0x00000000,	
        0x0,
	},
    {	// PROCONOTPp5
        0xAF405014,
        0x00000000,	
        0x0,
	},
	{	// PROCONTP 
		0xAF4051E8,
		0x00000000,	
		0x0,
	},
	{	// Confirmation Code
		0xAF4051F0,
		UCB_CONFIRMATION_UNLOCKED,	//0x43211234,	//0x57B5327F
		0x0,
	}
};


UCB_STATIC_INLINE void Ucb_Fls_lCycle553C(const uint32 Address, const uint32 Data)
{
    uint32 StartAddress;
    StartAddress = ((Address) & UCB_MASK_HIGHER4_NIBBLES) + UCB_CYCLE_553C;
    *((uint32*)StartAddress) = Data;
    DSYNC();
    return;
}

UCB_STATIC_INLINE void Ucb_Fls_lCycle5554(const uint32 Address, const uint32 Data)
{
    uint32 StartAddress;
    StartAddress = ((Address) & UCB_MASK_HIGHER4_NIBBLES) + UCB_CYCLE_5554;
    *((uint32*)StartAddress) = Data;
    DSYNC();
    return;
}

UCB_STATIC_INLINE void Ucb_Fls_lCycleAAA8(const uint32 Address, const uint32 Data)
{
  uint32 StartAddress;
  StartAddress = ((Address) & UCB_MASK_HIGHER4_NIBBLES) + UCB_CYCLE_AAA8;
  *((uint32*)StartAddress) = Data;
  DSYNC();
  return;
}

UCB_STATIC_INLINE void Ucb_Fls_lCycleAA50(const uint32 Address, const uint32 Data)
{
  uint32 StartAddress;
  StartAddress = ((Address) & UCB_MASK_HIGHER4_NIBBLES) + UCB_CYCLE_AA50;
  *((uint32*)StartAddress) = Data;
  DSYNC();
  return;
}

UCB_STATIC_INLINE void Ucb_Fls_lCycleAA58(const uint32 Address, const uint32 Data)
{
  uint32 StartAddress;
  StartAddress = ((Address) & UCB_MASK_HIGHER4_NIBBLES) + UCB_CYCLE_AA58;
  *((uint32*)StartAddress) = Data;
  DSYNC();
  return;
}


/*UCB Disable UCB18_ORI and UCB26_COPY write protection*/
UCB_STATIC void Ucb_Fls_DisableWriteProtection(const uint32 UcId, const uint32 *const PW)
{
    uint8 i=0;
    /*reset to read , end page mode*/
    Ucb_Fls_lCycle5554( UCB_DMU_BASE_ADDRESS,UCB_VALUE_F0);/*Unnecessary operation to avoid some unexpected situations*/

    /*xx11H for UCB17 = UCB_DFLASH_ORIG and UCB25 = UCB_DFLASH_COPY*/
    /*xx12H for UCB18 = UCB_DBG_ORIG and UCB26 = UCB_DBG_COPY*/
    Ucb_Fls_lCycle553C(UCB_DMU_BASE_ADDRESS,UcId);
    for(i=0;i<8u;i++)
    {
        Ucb_Fls_lCycle553C(UCB_DMU_BASE_ADDRESS,PW[i]);
    }
    while ((DMU_HF_STATUS.U & 0xFF) != 0); //Wait Flash is not busy

}

/*UCB Resume write protection*/
UCB_STATIC void Ucb_Fls_ResumeWriteProtection(IfxFlash_UcbType UCB)
{
    Ucb_Fls_lCycle5554(UCB_DMU_BASE_ADDRESS,UCB);/*xxF5 Resume Protection*/
    while ((DMU_HF_STATUS.U & 0xFF) != 0); //Wait Flash is not busy
}


UCB_STATIC void Ucb_Fls_EraseSector(uint32 EraseAddress)
{
    uint32 StartAddress = UCB_DMU_BASE_ADDRESS;

    /* cycle 1 */
    Ucb_Fls_lCycleAA50(StartAddress, EraseAddress);
    /* cycle 2 */
    Ucb_Fls_lCycleAA58(StartAddress, 1u);
    /* cycle 3 */
    Ucb_Fls_lCycleAAA8(StartAddress, UCB_VALUE_80);
    /* cycle 4 */
    Ucb_Fls_lCycleAAA8(StartAddress, UCB_VALUE_50);

}

UCB_STATIC uint32 Ucb_Fls_HwBusyCheck(uint32 FlashType)
{
    uint32 RetVal;

    RetVal = ((uint32)DMU_HF_STATUS.U & FlashType);
    
    return RetVal;/*0:not busy,1:busy*/
}


UCB_STATIC void Ucb_Fls_WaitUnBusy(uint32 FlashType)
{
    uint32 OperStatusChk = 0u;
    uint32 RetVal = 0u;
    uint32 cnt = 0;

    do
    {
        //Ucb_Timer_Delayus(1u);
        cnt++;
        RetVal = Ucb_Fls_HwBusyCheck(FlashType);/*0:not busy,1:busy*/
        OperStatusChk = ((uint32)DMU_HF_ERRSR.U & UCB_FLS_OPER_ERROR);/*0:no error,1:failure*/
    } while((RetVal != 0U) && (OperStatusChk != 1U) && (cnt<=UCB_DELAY_WAIT_UNBUSY_MAX));

    if((OperStatusChk == 1U) || (cnt>UCB_DELAY_WAIT_UNBUSY_MAX))
    {
        g_UcbErrorValue |= 1u<<1u;
    }

}


UCB_STATIC void Ucb_Fls_lLoadPage(const uint32 Address,uint32 WordL, uint32 WordU)
{
    volatile uint32* StartAddress=(volatile uint32 *)(((Address) & UCB_MASK_HIGHER4_NIBBLES) + UCB_CYCLE_55F0);

    *StartAddress = WordL;
    DSYNC();
    *(StartAddress + 1) = WordU;
    DSYNC();
}



UCB_STATIC void Ucb_Fls_lEnterPageMode(const uint32 Address, const uint32 Data)
{
    uint32 StartAddress;

    StartAddress = ((Address) & UCB_MASK_HIGHER4_NIBBLES) + UCB_CYCLE_5554;
    *((uint32*)StartAddress) = Data;
    DSYNC();
}

UCB_STATIC void Ucb_Fls_WritePage(uint32 PageAddr)
{
    uint32 StartAddress = UCB_DMU_BASE_ADDRESS;

    /* cycle 1 */
    Ucb_Fls_lCycleAA50(StartAddress,PageAddr);
    /* cycle 2 */
    Ucb_Fls_lCycleAA58(StartAddress,UCB_VALUE_00);
    /* cycle 3 */
    Ucb_Fls_lCycleAAA8(StartAddress,UCB_VALUE_A0);
    /* cycle 4 */
    Ucb_Fls_lCycleAAA8(StartAddress,UCB_VALUE_AA);
}


UCB_STATIC void Ucb_CalDBGIFLockPassword()
{
    /*get password from 8010 service*/
    Dsm_v_LockJTAGPassword(g_u8UcbDBGIFLockPassword_input);
    
    /*cal password by aes*/
    
    (void)mbedtls_aes_encrypt_ecb_256(Ucb_DBG_EcuKey, g_u8UcbDBGIFLockPassword_input, g_u8UcbDBGIFLockPassword_output);
    
    for(uint8 i=0u;i<8u;i++)
    {
        g_u32UcbDBGIFLockPassword[i]=((g_u8UcbDBGIFLockPassword_output[i]<<24u)&0xFF000000u) + ((g_u8UcbDBGIFLockPassword_output[i+1u]<<16u)&0x00FF0000) + \
                                ((g_u8UcbDBGIFLockPassword_output[i+2u]<<8u)&0x0000FF00u) + ((g_u8UcbDBGIFLockPassword_output[i+3u]<<0u)&0x000000FFu);
    }
    
}

UCB_STATIC void Ucb_InitMemory(uint8 Flag)
{
    switch(Flag)
    {
        case 1u:
        {
            Ucb_CalDBGIFLockPassword();
            {   // PROCONDBG
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[0].pageaddr= 0xAF402400;
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[0].data32L = 0x00000003;
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[0].data32H = 0x0;
            }
            {
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[1u].pageaddr= 0xAF402500;
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[1u].data32L = g_u32UcbDBGIFLockPassword[0u];   
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[1u].data32H = g_u32UcbDBGIFLockPassword[1u];
            }
            {   
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[2u].pageaddr= 0xAF402508;
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[2u].data32L = g_u32UcbDBGIFLockPassword[2u];   
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[2u].data32H = g_u32UcbDBGIFLockPassword[3u];   
            }
            {
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[3u].pageaddr= 0xAF402510;
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[3u].data32L = g_u32UcbDBGIFLockPassword[4u];
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[3u].data32H = g_u32UcbDBGIFLockPassword[5u];
            }
            {
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[4u].pageaddr= 0xAF402518;
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[4u].data32L = g_u32UcbDBGIFLockPassword[6u];
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[4u].data32H = g_u32UcbDBGIFLockPassword[7u];
            }
            
            {   // Confirmation Code
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[5u].pageaddr= 0xAF4025F0;
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[5u].data32L = UCB_CONFIRMATION_CONFIRMED;
                Ucb_DFLASH0_UCB18_DBG_ORIG_Lock[5u].data32H = 0x0;
            }
            
            {   // PROCONDBG
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[0].pageaddr = 0xAF403400;
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[0].data32L  = 0x00000003;
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[0].data32H  = 0x0;
            }
            {
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[1u].pageaddr = 0xAF403500;
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[1u].data32L  = g_u32UcbDBGIFLockPassword[0u];   
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[1u].data32H  = g_u32UcbDBGIFLockPassword[1u];  
            }
            {   
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[2u].pageaddr= 0xAF403508;
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[2u].data32L = g_u32UcbDBGIFLockPassword[2u];  
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[2u].data32H = g_u32UcbDBGIFLockPassword[3u];     
            }
            {
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[3u].pageaddr = 0xAF403510;
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[3u].data32L  = g_u32UcbDBGIFLockPassword[4u];   
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[3u].data32H  = g_u32UcbDBGIFLockPassword[5u];   
            }
            {
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[4u].pageaddr= 0xAF403518;
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[4u].data32L = g_u32UcbDBGIFLockPassword[6u];   
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[4u].data32H = g_u32UcbDBGIFLockPassword[7u];   
            }
            
            {   // Confirmation Code
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[5u].pageaddr = 0xAF4035F0;
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[5u].data32L  = UCB_CONFIRMATION_CONFIRMED;
                Ucb_DFLASH0_UCB26_DBG_COPY_Lock[5u].data32H  = 0x0;
            }
            
        };break;
        default:break;
    }

}

UCB_STATIC FUNC(void, CDD_UCB_CODE) CDD_Ucb_WriteUcbDate (const Ucb_DFlashData_Type *const DFlashData,const uint32 UcId,const uint8 Size)
{
    uint16 WdgPw=0u;
    uint8 Page=0u;
    //uint32 EraseAddres = Ucb_dFlashTableUcbSectorAddr[num].start;
    uint32 EraseAddres = DFlashData->pageaddr;/*erase start addr = page start addr*/
    
    if(UcId != UCB_VALUE_FF_NONE)
    {
        /*1\ disable protection*/
        #if (UCB_DBG_PASSWORD_CONST_SWITCH == STD_ON)
        Ucb_Fls_DisableWriteProtection(UcId,Ucb_DBG_Password);
        #else
        Ucb_Fls_DisableWriteProtection(UcId,g_u32UcbDBGIFLockPassword);
        #endif
    }
    /*2\ get Safety Watchdog Password*/
    WdgPw = IfxScuWdt_getSafetyWatchdogPassword();
    
    /*3\ erase data flash */
    IfxScuWdt_clearSafetyEndinit(WdgPw);
    /*Sector Addr:UCBx(0-47) start address*/
    Ucb_Fls_EraseSector(EraseAddres);
    IfxScuWdt_setSafetyEndinit(WdgPw);

    /*4\ wait until unbusy */
    Ucb_Fls_WaitUnBusy(UCB_FLS_D0BUSY);

    for (Page = 0; Page < Size; ++Page)
    {
        /*5\ Enter Page Mode*/
        Ucb_Fls_lEnterPageMode(UCB_DMU_BASE_ADDRESS,UCB_VALUE_5D);/*The “y” can be “0H” for selecting the PFLASH or “DH” to select the DFLASH.*/
        /*6\ wait until unbusy */
        Ucb_Fls_WaitUnBusy(UCB_FLS_D0BUSY);
        /*7\ Load Page */
        Ucb_Fls_lLoadPage(UCB_DMU_BASE_ADDRESS, DFlashData[Page].data32L, DFlashData[Page].data32H);
        
        /*8\ write page */
        IfxScuWdt_clearSafetyEndinit(WdgPw);
        Ucb_Fls_WritePage(DFlashData[Page].pageaddr);
        IfxScuWdt_setSafetyEndinit(WdgPw);

        /*9\ wait until unbusy */
        Ucb_Fls_WaitUnBusy(UCB_FLS_D0BUSY);
    }

}

/***********************************************extern function*******************************************************/

FUNC(uint8, CDD_UCB_CODE) CDD_Ucb_GetDBGIFLockState (void)
{
    g_UcbDBGIFLockState  = ((UCB_DMU_HF_PROCONDBG->B.DBGIFLCK  == 1u)?1u:0u);/*Debug is locked.*/
    g_UcbDBGIFLockState &= ((UCB_DMU_HF_PROCONDBG->B.OCDSDIS   == 1u)?1u:0u);/*OCDS lock is locked.*/
    g_UcbDBGIFLockState &= ((UCB_DMU_SP_PROCONHSM->B.HSMDBGDIS == 1u)?1u:0u);/*HSM debug is disabled.*/
    g_UcbDBGIFLockState &= ((UCB_DMU_SP_PROCONHSM->B.DBGIFLCK  == 0u)?1u:0u);/*HSM Debug Interface is unlocked.*/
    return g_UcbDBGIFLockState;

}

FUNC(uint8, CDD_UCB_CODE) CDD_Ucb_GetDBGConfirmState(void)
{
    g_UcbDBGConfirmState  = ((UCB_DMU_HF_CONFIRM1->B.PROINDBGO == 2u)?1u:0u);/*CONFIRMED.*/
    g_UcbDBGConfirmState &= ((UCB_DMU_HF_CONFIRM1->B.PROINHSMO == 2u)?1u:0u);/*CONFIRMED.*/
    g_UcbDBGConfirmState &= ((UCB_DMU_HF_CONFIRM1->B.PROINDBGC == 0u)?1u:0u);/*UNREAD*/
    g_UcbDBGConfirmState &= ((UCB_DMU_HF_CONFIRM1->B.PROINHSMC == 0u)?1u:0u);/*UNREAD*/
    return g_UcbDBGConfirmState;

}

/*get PFLASH lock state*/
FUNC(uint8, CDD_UCB_CODE) CDD_Ucb_GetPFlashIFLockState (void)
{
    g_UcbPFlashIFLockState = DMU_HP_PROCONP00.B.S16L;
    // g_UcbPFlashIFLockState = (DMU_HF_PROCONPF.U >> 16);
    return g_UcbPFlashIFLockState;

}
/*Get OTP lock state*/
/*get PFLASH lock state*/
FUNC(uint8, CDD_UCB_CODE) CDD_Ucb_GetOTPLockState (void)
{
    // g_UcbPFlashIFLockState = DMU_HP_PROCONP00.B.S16L;
    g_UcbOTPLockState = DMU_HP_PROCONOTP00.B.S16ROM;
    return g_UcbOTPLockState;
}

/*lock DBG interface by UCB18_ORI and UCB26_copy*/
 FUNC(void, CDD_UCB_CODE) CDD_Ucb_ReqDBGIFLock (void)
{
    uint8 cnt=0;
    
    /*init memory*/
    Ucb_InitMemory(UCB_MEMORY_INIT_DEGIFLOCK);
    
    /*while( (UCB_LOCK != CDD_Ucb_GetDBGIFLockState()) && ( cnt < UCB_RETY_CNT_MAX) )*/
    {
        CDD_Ucb_WriteUcbDate(Ucb_DFLASH0_UCB18_DBG_ORIG_Lock,UCB_VALUE_12,UCB_BLOCK_SIZE_6);
        CDD_Ucb_WriteUcbDate(Ucb_DFLASH0_UCB26_DBG_COPY_Lock,UCB_VALUE_12,UCB_BLOCK_SIZE_6);
        /*CDD_Ucb_WriteUcbDate(Ucb_DFLASH0_UCB17_DFLASH_ORIG_Lock,UCB_VALUE_11,UCB_BLOCK_SIZE_6);
        CDD_Ucb_WriteUcbDate(Ucb_DFLASH0_UCB25_DFLASH_COPY_Lock,UCB_VALUE_11,UCB_BLOCK_SIZE_6);*/
        CDD_Ucb_WriteUcbDate(Ucb_DFLASH0_UCB19_HSM_ORIG_Lock,UCB_VALUE_FF_NONE,UCB_BLOCK_SIZE_2);
        CDD_Ucb_WriteUcbDate(Ucb_DFLASH0_UCB27_HSM_COPY_Lock,UCB_VALUE_FF_NONE,UCB_BLOCK_SIZE_2);
        cnt++;
    }

    if(cnt >= UCB_RETY_CNT_MAX)
    {
        g_UcbErrorValue |=1u<<2u;
    }
    
    
}


/*lock PFLASH interface by UCB16_ORI and UCB24_copy*/
 FUNC(void, CDD_UCB_CODE) CDD_Ucb_ReqPFlashIFLock (void)
{
    uint8 cnt=0;
    
    /*while( (UCB_LOCK != CDD_Ucb_GetDBGIFLockState()) && ( cnt < UCB_RETY_CNT_MAX) )*/
    {
        // CDD_Ucb_SetPFlashLockState(DFLASH0_UCB16_Lock);
        // CDD_Ucb_SetPFlashLockState(DFLASH0_UCB24_Lock);
        CDD_Ucb_WriteUcbDate(DFLASH0_UCB16_Lock,UCB_VALUE_20,UCB_BLOCK_SIZE_12);
        CDD_Ucb_WriteUcbDate(DFLASH0_UCB24_Lock,UCB_VALUE_20,UCB_BLOCK_SIZE_12);
        cnt++;
    }

    if(cnt >= UCB_RETY_CNT_MAX)
    {
        g_UcbErrorValue |=1u<<2u;
    }
    
}

/*unlock PFLASH interface by UCB16_ORI and UCB24_copy*/
 FUNC(void, CDD_UCB_CODE) CDD_Ucb_ReqPFlashIFUnLock (void)
{
    uint8 cnt=0;
    
    /*while( (UCB_LOCK != CDD_Ucb_GetDBGIFLockState()) && ( cnt < UCB_RETY_CNT_MAX) )*/
    {
        // CDD_Ucb_SetPFlashLockState(DFLASH0_UCB16_Unlock);
        // CDD_Ucb_SetPFlashLockState(DFLASH0_UCB24_Unlock);
        CDD_Ucb_WriteUcbDate(DFLASH0_UCB16_Unlock,UCB_VALUE_20,UCB_BLOCK_SIZE_12);
        CDD_Ucb_WriteUcbDate(DFLASH0_UCB24_Unlock,UCB_VALUE_20,UCB_BLOCK_SIZE_12);
        cnt++;
    }

    if(cnt >= UCB_RETY_CNT_MAX)
    {
        g_UcbErrorValue |=1u<<2u;
    }
    
}

/*Enable OTP interface by UCB32_ORI and UCB40_copy*/
 FUNC(void, CDD_UCB_CODE) CDD_Ucb_ReqOTPIFLock (void)
{
    // CDD_Ucb_SetOTPLockState(DFLASH0_UCB32_Lock);
    // CDD_Ucb_SetOTPLockState(DFLASH0_UCB40_Lock);
    CDD_Ucb_WriteUcbDate(DFLASH0_UCB32_Lock,UCB_VALUE_FF_NONE,UCB_BLOCK_SIZE_8);
    CDD_Ucb_WriteUcbDate(DFLASH0_UCB40_Lock,UCB_VALUE_FF_NONE,UCB_BLOCK_SIZE_8);
}


