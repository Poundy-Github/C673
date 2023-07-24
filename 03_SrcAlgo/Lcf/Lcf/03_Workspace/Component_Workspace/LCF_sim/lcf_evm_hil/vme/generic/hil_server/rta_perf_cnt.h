#ifndef __RTA_PERF_CNT_H__
#define __RTA_PERF_CNT_H__

// VISION HIGH TEST -> C66XX | CortexM4 | CortexA15
// GCC defines __ARM_ARCH_7A__ for both CA15 and CA8.
// For CA15 __ARM_ARCH_EXT_IDIV__ is defined additionally.
#if defined(_TMS320C6600) | defined(__TI_ARM_V7M4__) | (defined(__ARM_ARCH_7A__) & defined(__ARM_ARCH_EXT_IDIV__))
#define RTA_TARGET_VISION_HIGH
#endif

#define REG_BASE_DDR0 (0x4C000000)

/* the counter values are multiplied by this factor in MTS */
#define PERF_CNT_SCALING_FACTOR   2

typedef struct
{
  uint8 a_Reserved_00_54[0x54];

  union {
    struct {
      uint32 u_PrOldCount      : 8;
      uint32 u_CosCount2       : 8;
      uint32 u_CosCount1       : 8;
      uint32 u_Reserved_24_31  : 8;
    } fields;
    uint32 raw;
  } pbbpr;

  uint8 a_Reserved_58_80[0x28];

  uint32 u_PerfCnt1;
  uint32 u_PerfCnt2;

  union {
    struct {
      uint32 u_Cntr1Cfg        : 4;
      uint32 a_Reserved0       : 11;
      uint32 u_Cntr1MConnIdEn  : 1;
      uint32 u_Cntr2Cfg        : 4;
      uint32 a_Reserved1       : 11;
      uint32 u_Cntr2MConnIdEn  : 1;
    } fields;
    uint32 raw;
  } perfCntCfg;

  union {
    struct {
      uint32 u_Reserved0 : 8;
      uint32 u_MConnId1  : 8;
      uint32 u_Reserved1 : 8;
      uint32 u_MConnId2  : 8;
    } fields;
    uint32 raw;
  } perfCntSel;

  uint8 a_Reserved1[0x70];

  union {
    struct {
      uint32 u_Prio0Cos : 2;
      uint32 u_Prio1Cos : 2;
      uint32 u_Prio2Cos : 2;
      uint32 u_Prio3Cos : 2;
      uint32 u_Prio4Cos : 2;
      uint32 u_Prio5Cos : 2;
      uint32 u_Prio6Cos : 2;
      uint32 u_Prio7Cos : 2;
      uint32 u_Reserved : 15;
      uint32 u_PriCosMapEn : 1;
    } fields;
    uint32 raw;
  } prioCosMap;

  union {
    struct {
      uint32 u_Msk3Cos1      : 2;
      uint32 u_ConnId3Cos1   : 8;
      uint32 u_Msk2Cos1      : 2;
      uint32 u_ConnId2Cos1   : 8;
      uint32 u_Msk1Cos1      : 3;
      uint32 u_ConnId1Cos1   : 8;
      uint32 u_ConnCos1MapEn : 1;
    } fields;
    uint32 raw;
  } connIdCos1Map;

  union {
    struct {
      uint32 u_Msk3Cos2      : 2;
      uint32 u_ConnId3Cos2   : 8;
      uint32 u_Msk2Cos2      : 2;
      uint32 u_ConnId2Cos2   : 8;
      uint32 u_Msk1Cos2      : 3;
      uint32 u_ConnId1Cos2   : 8;
      uint32 u_ConnCos2MapEn : 1;
    } fields;
    uint32 raw;
  } connIdCos2Map;
} SdRamCtrlRegs_t;


typedef enum
{
#ifdef RTA_TARGET_VISION_HIGH
  DDRCTRL_MCONNID_CORTEX_A15         = 0x00,
  DDRCTRL_MCONNID_CS_DAP             = 0x10,
  DDRCTRL_MCONNID_IEEE1500_2_OCP     = 0x14,
  DDRCTRL_MCONNID_DSP1_MDMA          = 0x20,
  DDRCTRL_MCONNID_DSP1_CFG           = 0x24,
  DDRCTRL_MCONNID_DSP1_DMA           = 0x28,
  DDRCTRL_MCONNID_DSP2_MDMA          = 0x2C,
  DDRCTRL_MCONNID_DSP2_CFG           = 0x30,
  DDRCTRL_MCONNID_DSP2_DMA           = 0x34,
  DDRCTRL_MCONNID_IVA_ICONT1         = 0x3A,
  DDRCTRL_MCONNID_EVE1_P1            = 0x42,
  DDRCTRL_MCONNID_EVE2_P1            = 0x46,
  DDRCTRL_MCONNID_IPU1               = 0x60,
  DDRCTRL_MCONNID_IPU2               = 0x64,
  DDRCTRL_MCONNID_SDMA_RD            = 0x68,
  DDRCTRL_MCONNID_SDMA_WR            = 0x6A,
  DDRCTRL_MCONNID_EDMA_TC1_WR        = 0x70,
  DDRCTRL_MCONNID_EDMA_TC1_RD        = 0x72,
  DDRCTRL_MCONNID_EDMA_TC2_WR        = 0x74,
  DDRCTRL_MCONNID_EDMA_TC2_RD        = 0x76,
  DDRCTRL_MCONNID_DSS                = 0x80,
  DDRCTRL_MCONNID_MLB                = 0x84,
  DDRCTRL_MCONNID_MMU1               = 0x86,
  DDRCTRL_MCONNID_PCIE_SS1           = 0x88,
  DDRCTRL_MCONNID_PCIE_SS2           = 0x8C,
  DDRCTRL_MCONNID_MMU2               = 0x8E,
  DDRCTRL_MCONNID_VIP1_P1            = 0x90,
  DDRCTRL_MCONNID_VIP1_P2            = 0x92,
  DDRCTRL_MCONNID_VIP2_P1            = 0x94,
  DDRCTRL_MCONNID_VIP2_P2            = 0x96,
  DDRCTRL_MCONNID_VIP3_P1            = 0x98,
  DDRCTRL_MCONNID_VIP3_P2            = 0x9A,
  DDRCTRL_MCONNID_VPE_P1             = 0x9C,
  DDRCTRL_MCONNID_VPE_P2             = 0x9E,
  DDRCTRL_MCONNID_MMC1               = 0xA0,
  DDRCTRL_MCONNID_GPU_P1             = 0xA2,
  DDRCTRL_MCONNID_MMC2               = 0xA4,
  DDRCTRL_MCONNID_GPU_P2             = 0xA6,
  DDRCTRL_MCONNID_BB2D_P1            = 0xA8,
  DDRCTRL_MCONNID_BB2D_P2            = 0xAA,
  DDRCTRL_MCONNID_GMAC_SW            = 0xAC,
  DDRCTRL_MCONNID_USB4               = 0xB0,
  DDRCTRL_MCONNID_USB1               = 0xB4,
  DDRCTRL_MCONNID_USB2               = 0xB8,
  DDRCTRL_MCONNID_USB3               = 0xBC,
  DDRCTRL_MCONNID_SATA               = 0xCC,
  DDRCTRL_MCONNID_EVE1_P2            = 0xD2,
  DDRCTRL_MCONNID_EVE2_P2            = 0xD6,
#else
  // VISION_MID_EVE
  DDRCTRL_MCONNID_CORTEX_A8          = 0x00,
  DDRCTRL_MCONNID_DSP                = 0x20,
  DDRCTRL_MCONNID_DSP_CFG            = 0x24,
  DDRCTRL_MCONNID_MMU                = 0x28, // <<-- DSP !!
  DDRCTRL_MCONNID_MEDIA_CONTROLLER   = 0x38,
  DDRCTRL_MCONNID_SEC_M3             = 0x50,
  DDRCTRL_MCONNID_TPTC0_RD           = 0x60,
  DDRCTRL_MCONNID_TPTC0_WR           = 0x64,
  DDRCTRL_MCONNID_TPTC1_RD           = 0x68,
  DDRCTRL_MCONNID_TPTC1_WR           = 0x6C,
  DDRCTRL_MCONNID_TPTC2_RD           = 0x70,
  DDRCTRL_MCONNID_TPTC2_WR           = 0x74,
  DDRCTRL_MCONNID_TPTC3_RD           = 0x78,
  DDRCTRL_MCONNID_TPTC3_WR           = 0x7C,
  DDRCTRL_MCONNID_SGX                = 0x80,
  DDRCTRL_MCONNID_HDVPSS1            = 0x90,
  DDRCTRL_MCONNID_HDVPSS2            = 0x94,
  DDRCTRL_MCONNID_HDVICP             = 0xA0, // <<-- EVE
  DDRCTRL_MCONNID_ISS                = 0xB0,
  DDRCTRL_MCONNID_3PSW               = 0xC0,
  DDRCTRL_MCONNID_FDIF               = 0xC4,
  DDRCTRL_MCONNID_USB1               = 0xD0,
  DDRCTRL_MCONNID_USB2               = 0xD4,
  DDRCTRL_MCONNID_PATA               = 0xE0,
  DDRCTRL_MCONNID_SATA               = 0xE4,
  DDRCTRL_MCONNID_PCIE               = 0xE8,
#endif
  DDRCTRL_MCONNID__ALL__             = 0xFFFF // Special value which means 'ALL' masters
} SdRamCtrlMConnId_t;

typedef enum
{
  DDRCTRL_CNTRX_CFG_TOTAL_ACCESSES  = 0,
  DDRCTRL_CNTRX_CFG_TOTAL_ACTIVATES = 1,
  DDRCTRL_CNTRX_CFG_TOTAL_READS     = 2,
  DDRCTRL_CNTRX_CFG_TOTAL_WRITES    = 3
} SdRamCtrlCntrCfg_t;
    
typedef struct
{
  SdRamCtrlCntrCfg_t Config;   /* Performance counter configuration */
  SdRamCtrlMConnId_t MConnId;  /* Master Connection ID for Performance Counter */
} SdRamCtrlPerfCntCfg_t;

enum
{
  PERF_COUNT_DISABLE   = 0,
  PERF_COUNT_ENABLE    = 1
};

enum
{
  PERF_COUNT1          = 0,
  PERF_COUNT2          = 1,
  PERF_COUNT_NUMBER_OF = 2
};

#endif
