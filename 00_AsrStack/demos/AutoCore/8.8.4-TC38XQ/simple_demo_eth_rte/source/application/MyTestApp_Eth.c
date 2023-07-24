/**
 * \file
 *
 * \brief Autosar ApplTemplates
 *
 * This file contains the implementation of the Autosar
 * module ApplTemplates.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2011 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/
#include <TSAutosar.h>
#include <Base_Modules.h>
#include <Eth.h>
#include <EthIf.h>

/*defines for RGMII TRCV initialization Board 2.0 version */
#define RTL8211F_PHY_ID1          (0x001cU)      /* PHY_ID1 for RTL8211F */
#define RTL8211F_PHY_ID2          (0xc916U)      /* PHY_ID2 for RTL8211F */
#define MII_PHYSID1               0x02  /* PHYS ID 1                   */
#define MII_PHYSID2               0x03  /* PHYS ID 2                   */
#define MII_BMCR                  0x00  /* Basic mode control register */
#define BMCR_RESET                0x8000  /* Reset to default state      */
#define PHY_READ_DELAY                          (500U)
#define RTL8211F_PAGE_SELECT                    0x1f
#define BMCR_SPEED100            0x1000  /* MSB of Speed (100)         */
#define BMCR_FULLDPLX             0x0100  /* Full duplex                 */
#define RTL8211F_PHY_STATUS                     0x1a
#define RTL8211F_PHYSTAT_LINK                   0x0004
#define ETH_PHY_INIT_DURATION                   (2000U)
#define RTL8211F_TX_DELAY                       0x100

/*==================[macro definitions]======================================*/
FUNC(void, EBTEST_APPL_CODE) TestMII(void);
FUNC(void, EBTEST_APPL_CODE) TestRGMII_Init(void);
/*==================[internal data]==========================================*/
/* insert by hege8402 */
uint16 PhyReg[32],PhyReg1[32];
static boolean EthTrcv_TransceiverInitialized = FALSE;

static uint32 Eth_lDelay1(uint32 delay)
{
	while (delay--);
	return delay;
}

/* PHY Reset */
void local_GETH_PHY_Reset(uint8 phy_addr)
{
  uint16 reg_bmcr;

  /* Reset PHY*/
  Eth_17_GEthMac_ReadMii(0, 1, MII_BMCR, &reg_bmcr);
  reg_bmcr |= BMCR_RESET;
  Eth_17_GEthMac_WriteMii(0, 1, MII_BMCR, reg_bmcr);

  /* Wait for the reset to complete */
  do
  {
    Eth_17_GEthMac_ReadMii(0, 1, MII_BMCR, &reg_bmcr);
  } while ((reg_bmcr & BMCR_RESET) != 0);
}

/*==================[external function definitions]==========================*/

#define EBSTUBS_START_SEC_APPL_CODE
#include <EBStubs_MemMap.h>

FUNC(void, EBSTUBS_APPL_CODE) TestMII(void)
{
  /* Eth_ConfigType   ethDummy; */
	int i;
	
	if (!EthTrcv_TransceiverInitialized)
	{
	
		/* BEGIN: Initialization of the Eth transiver since there is no own module! */
		/*       this should be done after the Eth_ControllerInit calll!            */

		/* Set Reset Flag */
		Eth_17_GEthMac_WriteMii(0,0,0x00,0x9040);
		
		while (1 == 1)
		{
      		/* Wait until the Trcv was resetted */
			Eth_17_GEthMac_ReadMii((uint8)0,(uint8)0,(uint8)0x00, &PhyReg[0]);
    
			if ((PhyReg[0] & (1 << 15)) != 0)
				break;                    
		}

		for(i=0;i < 32;i++)
		{		 	
			Eth_17_GEthMac_ReadMii((uint8)0,(uint8)0,(uint8)i,&PhyReg[i]);	
		}	
		Eth_17_GEthMac_WriteMii(0,0,0x17,0xF702);
		Eth_17_GEthMac_WriteMii(0,0,0x13,0x0001);   /* Bit12: TxOff should be 0 */
		Eth_17_GEthMac_WriteMii(0,0,0x14,0x8006);   /* 0x8004 ?*/
		Eth_17_GEthMac_WriteMii(0,0,0x00,(0x2100));
		for(i=0;i < 32;i++)
		{		 	
			Eth_17_GEthMac_ReadMii((uint8)0,(uint8)0,(uint8)i,&PhyReg1[i]);	
		}
 
		while (1 == 1)
		{
			Eth_17_GEthMac_ReadMii((uint8)0,(uint8)0,(uint8)0x01,&PhyReg[0]);
    
			if ((PhyReg[0] & (1 << 2)) != 0)
				break;                    
		}

		Eth_lDelay1(0x03FFFFFF);
		/* Eth_lDelay1(0xFFFFFFFF); */
		/* Eth_lDelay1(0xFFFFFFFF); */
		/* END:  */
		EthTrcv_TransceiverInitialized = TRUE;
	}
   }
FUNC(void, EBSTUBS_APPL_CODE) TestRGMII_Init(void)
{
	
uint16 phy_id1 = 0;
uint16 phy_id2 = 0;
uint16 reg_value = 0;
uint16 val = 0;

  do
  {
    /* Check Device Identification. */
    Eth_17_GEthMac_ReadMii(0, 1, MII_PHYSID1, &phy_id1);
    Eth_17_GEthMac_ReadMii(0, 1, MII_PHYSID2, &phy_id2);
  } while((phy_id1 != RTL8211F_PHY_ID1) && (phy_id2 != RTL8211F_PHY_ID2));

  local_GETH_PHY_Reset(1);
  Eth_lDelay1(PHY_READ_DELAY);

  Eth_17_GEthMac_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0xa43);
  Eth_17_GEthMac_ReadMii(0, 1, 0x19, &reg_value);
 
  reg_value |= 0x1;
  Eth_17_GEthMac_WriteMii(0, 1, 0x19, reg_value);
  Eth_17_GEthMac_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0x0);

  /* A PHY reset should be issued after setting this bits in PHYCR2 */
  local_GETH_PHY_Reset(1);
  Eth_lDelay1(PHY_READ_DELAY);

  Eth_17_GEthMac_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0xd08);
  Eth_17_GEthMac_ReadMii(0, 1, 0x11, &reg_value);

  /* Adding TX-delay for RGMII mode*/
  {
    reg_value |= RTL8211F_TX_DELAY;
  }

  Eth_17_GEthMac_WriteMii(0, 1, 0x11, reg_value);
  /* restore to default page 0 */
  Eth_17_GEthMac_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0x0);

  /* Disable green Ethernet */
  Eth_17_GEthMac_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0xa43);
  Eth_17_GEthMac_WriteMii(0, 1, 27, 0x8011);
  Eth_17_GEthMac_WriteMii(0, 1, 28, 0x573f);
  Eth_17_GEthMac_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0x0);

  /* Set green LED for Link, yellow LED for Active */
  Eth_17_GEthMac_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0xd04);
  Eth_17_GEthMac_WriteMii(0, 1, 0x10, 0x617f);
  Eth_17_GEthMac_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0x0);
  reg_value = 0U;

  reg_value |= BMCR_SPEED100;

  reg_value |= BMCR_FULLDPLX;

  Eth_17_GEthMac_WriteMii(0, 1, MII_BMCR, reg_value);

  do
  {
    Eth_lDelay1(PHY_READ_DELAY);
    /*Link Speed status */
    Eth_17_GEthMac_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0xa43);
    Eth_17_GEthMac_ReadMii(0, 1, RTL8211F_PHY_STATUS, &val);
    Eth_17_GEthMac_WriteMii(0, 1, RTL8211F_PAGE_SELECT, 0);
  } while((val & RTL8211F_PHYSTAT_LINK) != 0x0004);

  /*Delay added since ETh_init takes time to stabilize */
  Eth_lDelay1(ETH_PHY_INIT_DURATION);
}

/*==================[interrupt handlers]=====================================*/

#define EBSTUBS_STOP_SEC_APPL_CODE
#include <EBStubs_MemMap.h>

/*==================[end of file]============================================*/