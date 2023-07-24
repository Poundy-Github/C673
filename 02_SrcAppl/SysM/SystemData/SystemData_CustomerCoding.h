/**
 * \file SystemData_CustomerCoding.h
 *
 * \brief  SystemData
 *
 * \version
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2023.01.22			Jinlong Zhang			Init version
 *
 *
 */
#ifndef _ESM_CUSTOMERCODING_H_
#define _ESM_CUSTOMERCODING_H_ //PRQA S 0602,0603

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */
#include "Cdm_Cfg.h"

/*==================[macros definitions]====================================*/
#define SYS_GET_FLAG_MASK(FlagId)    ((uint32) 1 << ((FlagId) % 32U))

#define SYS_IS_FLAG_SET(FlagMask, BitArray, BitArrayType)     ((((BitArray) & (BitArrayType)(FlagMask)) != 0U ) ? TRUE : FALSE)

#define SYS_CLEAR_FLAG(FlagMask, BitArray, BitArrayType)      ((BitArray) &= (BitArrayType)(~(FlagMask)))

#define SYS_SET_FLAG(FlagMask, BitArray, BitArrayType)   ((BitArray) |= (BitArrayType)(FlagMask))

/***************************************************************************/
/* Control bits for masking (OEM )******************************************/
/***************************************************************************/
#define SYS_AEB_FUNCT_BITMASK             (0x00000001)    /*! \brief Bitmask: AEB (Bit 0)*/
#define SYS_ACC_FUNCT_BITMASK             (0x00000002)    /*! \brief Bitmask: ACC (Bit 1)*/
#define SYS_LCF_FUNCT_BITMASK             (0x00000004)    /*! \brief Bitmask: LCF (Bit 2)*/
#define SYS_ELK_FUNCT_BITMASK             (0x00000008)    /*! \brief Bitmask: ELK (Bit 3)*/
#define SYS_HLA_FUNCT_BITMASK             (0x00000010)    /*! \brief Bitmask: HLA (Bit 4)*/
#define SYS_TSA_FUNCT_BITMASK             (0x00000020)    /*! \brief Bitmask: HLA (Bit 5)*/
#define SYS_BIT6_FUNCT_BITMASK            (0x00000040)    /*! \brief Bitmask: xxx (Bit 6)*/
#define SYS_BIT7_FUNCT_BITMASK            (0x00000080)    /*! \brief Bitmask: xxx (Bit 7)*/
#define SYS_BIT8_FUNCT_BITMASK            (0x00000100)    /*! \brief Bitmask: xxx (Bit 8)*/ 
#define SYS_BIT9_FUNCT_BITMASK            (0x00000200)    /*! \brief Bitmask: xxx (Bit 9)*/
#define SYS_BIT10_FUNCT_BITMASK           (0x00000400)    /*! \brief Bitmask: xxx (Bit 10)*/
#define SYS_BIT11_FUNCT_BITMASK           (0x00000800)    /*! \brief Bitmask: xxx (Bit 11)*/
#define SYS_BIT12_FUNCT_BITMASK           (0x00001000)    /*! \brief Bitmask: xxx (Bit 12)*/
#define SYS_BIT13_FUNCT_BITMASK           (0x00002000)    /*! \brief Bitmask: xxx (Bit 13)*/
#define SYS_BIT14_FUNCT_BITMASK           (0x00004000)    /*! \brief Bitmask: xxx (Bit 14)*/
#define SYS_BIT15_FUNCT_BITMASK           (0x00008000)    /*! \brief Bitmask: xxx (Bit 15)*/
#define SYS_BIT16_FUNCT_BITMASK           (0x00010000)    /*! \brief Bitmask: xxx (Bit 16)*/
#define SYS_BIT17_FUNCT_BITMASK           (0x00020000)    /*! \brief Bitmask: xxx (Bit 17)*/
#define SYS_BIT18_FUNCT_BITMASK           (0x00040000)    /*! \brief Bitmask: xxx (Bit 18)*/
#define SYS_BIT19_FUNCT_BITMASK           (0x00080000)    /*! \brief Bitmask: xxx (Bit 19)*/
#define SYS_PERCEPTION_FUNCT_BITMASK      (0x00100000)    /*! \brief Bitmask: PERCEPTION (Bit 20)*/
#define SYS_FUNSION_FUNCT_BITMASK         (0x00200000)    /*! \brief Bitmask: FUNSION (Bit 21)*/
#define SYS_MED_FUNCT_BITMASK             (0x00400000)    /*! \brief Bitmask: MED (Bit 22)*/
#define SYS_SED_FUNCT_BITMASK             (0x00800000)    /*! \brief Bitmask: SED (Bit 23)*/
#define SYS_CSL_FUNCT_BITMASK             (0x01000000)    /*! \brief Bitmask: CSL (Bit 24)*/
#define SYS_XCP_FUNCT_BITMASK             (0x02000000)    /*! \brief Bitmask: XCP (Bit 25)*/
#define SYS_MTS_FUNCT_BITMASK             (0x04000000)    /*! \brief Bitmask: MTS (Bit 26)*/
#define SYS_DBM_FUNCT_BITMASK             (0x08000000)    /*! \brief Bitmask: DBM (Bit 27)*/
#define SYS_PRT_FUNCT_BITMASK             (0x10000000)    /*! \brief Bitmask: PRT (Bit 28)*/
#define SYS_FIT_FUNCT_BITMASK             (0x20000000)    /*! \brief Bitmask: FIT (Bit 29)*/
#define SYS_RTM_FUNCT_BITMASK             (0x40000000)    /*! \brief Bitmask: RTM (Bit 30)*/    
#define SYS_FIM_FUNCT_BITMASK             (0x80000000)    /*! \brief Bitmask: FIM (Bit 31)*/

/***************************************************************************/
/* Start bits for all cusotomer functions activation ***********************/
/***************************************************************************/
#define SYS_MASK_STARTPOS_AEB                   (0)   /*! \brief Startbit: AEB */
#define SYS_MASK_STARTPOS_ACC                   (1)   /*! \brief Startbit: ACC */
#define SYS_MASK_STARTPOS_LCF                   (2)   /*! \brief Startbit: LCF */
#define SYS_MASK_STARTPOS_ELK                   (3)   /*! \brief Startbit: ELK */
#define SYS_MASK_STARTPOS_HLA                   (4)   /*! \brief Startbit: HLA */
#define SYS_MASK_STARTPOS_TSA                   (5)   /*! \brief Startbit: TSA */
#define SYS_MASK_STARTPOS_PERCEPTION            (20)  /*! \brief Startbit: Perception */
#define SYS_MASK_STARTPOS_FUNSION               (21)  /*! \brief Startbit: Funsion */
#define SYS_MASK_STARTPOS_MED                   (22)  /*! \brief Startbit: Med */
#define SYS_MASK_STARTPOS_SED                   (23)  /*! \brief Startbit: Sed */
#define SYS_MASK_STARTPOS_CSL                   (24)  /*! \brief Startbit: CSL(Communication State Control) */
#define SYS_MASK_STARTPOS_XCP                   (25)  /*! \brief Startbit: XCP */
#define SYS_MASK_STARTPOS_MTS                   (26)  /*! \brief Startbit: MTS */
#define SYS_MASK_STARTPOS_DBM                   (27)  /*! \brief Startbit: DBM(Debug Message) */
#define SYS_MASK_STARTPOS_PRT                   (28)  /*! \brief Startbit: PRT(Uart Printf) */
#define SYS_MASK_STARTPOS_FIT                   (29)  /*! \brief Startbit: FIT(Fault Injection) */
#define SYS_MASK_STARTPOS_RTM                   (30)  /*! \brief Startbit: RTM(Runtime Measurement) */
#define SYS_MASK_STARTPOS_FIM                   (31)  /*! \brief Startbit: FIM(Function Inhibit) */


/***************************************************************************/
/* Control makros for cusotomer functions activation ***********************/
/***************************************************************************/

#define SYS_AEB_FUNCT_ACTIVATED                  (0 != (SYS_AEB_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE()))

#define SYS_ACC_FUNCT_ACTIVATED                  (0 != (SYS_ACC_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE()))

#define SYS_LCF_FUNCT_ACTIVATED                  (0 != (SYS_LCF_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE())) 

#define SYS_ELK_FUNCT_ACTIVATED                  (0 != (SYS_ELK_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE()))  

#define SYS_HLA_FUNCT_ACTIVATED                  (0 != (SYS_HLA_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE())) 

#define SYS_TSA_FUNCT_ACTIVATED                  (0 != (SYS_TSA_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE())) 

#define SYS_PERCEPTION_FUNCT_ACTIVATED           (0 != (SYS_PERCEPTION_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE())) 

#define SYS_FUNSION_FUNCT_ACTIVATED              (0 != (SYS_FUNSION_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE()))

#define SYS_MED_FUNCT_ACTIVATED                  (0 != (SYS_MED_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE()))

#define SYS_SED_FUNCT_ACTIVATED                  (0 != (SYS_SED_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE()))

#define SYS_CSL_FUNCT_ACTIVATED                  (0 != (SYS_CSL_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE()))

#define SYS_XCP_FUNCT_ACTIVATED                  (0 != (SYS_XCP_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE()))

#define SYS_MTS_FUNCT_ACTIVATED                  (0 != (SYS_MTS_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE()))

#define SYS_DBM_FUNCT_ACTIVATED                  (0 != (SYS_DBM_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE()))

#define SYS_PRT_FUNCT_ACTIVATED                  (0 != (SYS_PRT_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE()))

#define SYS_FIT_FUNCT_ACTIVATED                  (0 != (SYS_FIT_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE()))

#define SYS_RTM_FUNCT_ACTIVATED                  (0 != (SYS_RTM_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE()))

#define SYS_FIM_FUNCT_ACTIVATED                  (0 != (SYS_FIM_FUNCT_BITMASK  & GET_CDM_CUSTOMER_CODE()))

/***************************************************************************/
/* Control makros to Wirte cusotomer functions value ***********************/
/***************************************************************************/
/*! \ brief Change value:  set MED function to OFF*/
#define WR_MED_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_MED_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_MED);/*new value */\
    }
/*! \ brief Change value:  set MED function to ON*/
#define WR_MED_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_MED_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_MED);/*new value */\
    }

/*! \ brief Change value:  set SED function to OFF*/
#define WR_SED_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_SED_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_SED);/*new value */\
    }
/*! \ brief Change value:  set SED function to ON*/
#define WR_SED_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_SED_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_SED);/*new value */\
    }

/*! \ brief Change value:  set AEB function to OFF*/
#define WR_AEB_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_AEB_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_AEB);/*new value */\
    }
/*! \ brief Change value:  set AEB function to ON*/
#define WR_AEB_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_AEB_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_AEB);/*new value */\
    }

/*! \ brief Change value:  set ACC function to OFF*/
#define WR_ACC_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_ACC_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_ACC);/*new value */\
    }
/*! \ brief Change value:  set ACC function to ON*/
#define WR_ACC_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_ACC_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_ACC);/*new value */\
    }

/*! \ brief Change value:  set LCF function to OFF*/
#define WR_LCF_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_LCF_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_LCF);/*new value */\
    }
/*! \ brief Change value:  set LCF function to ON*/
#define WR_LCF_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_LCF_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_LCF);/*new value */\
    }

/*! \ brief Change value:  set ELK function to OFF*/
#define WR_ELK_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_ELK_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_ELK);/*new value */\
    }
/*! \ brief Change value:  set ELK function to ON*/
#define WR_ELK_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_ELK_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_ELK);/*new value */\
    }

/*! \ brief Change value:  set HLA function to OFF*/
#define WR_HLA_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_HLA_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_HLA);/*new value */\
    }
/*! \ brief Change value:  set HLA function to ON*/
#define WR_HLA_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_HLA_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_HLA);/*new value */\
    }
	
/*! \ brief Change value:  set TSA function to OFF*/
#define WR_TSA_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_TSA_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_TSA);/*new value */\
    }
/*! \ brief Change value:  set TSA function to ON*/
#define WR_TSA_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_TSA_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_TSA);/*new value */\
   }
   
/*! \ brief Change value:  set Perception function to OFF*/
#define WR_PERCEPTION_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_PERCEPTION_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_PERCEPTION);/*new value */\
    }
/*! \ brief Change value:  set Perception function to ON*/
#define WR_PERCEPTION_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_PERCEPTION_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_PERCEPTION);/*new value */\
    }	
	
/*! \ brief Change value:  set Funsion function to OFF*/
#define WR_FUNSION_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_FUNSION_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_FUNSION);/*new value */\
    }
/*! \ brief Change value:  set Funsion function to ON*/
#define WR_FUNSION_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_FUNSION_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_FUNSION);/*new value */\
    }
	
/*! \ brief Change value:  set CSL function to OFF*/
#define WR_CSL_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_CSL_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_CSL);/*new value */\
    }
/*! \ brief Change value:  set CSL function to ON*/
#define WR_CSL_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_CSL_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_CSL);/*new value */\
    }	
	
/*! \ brief Change value:  set XCP function to OFF*/
#define WR_XCP_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_XCP_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_XCP);/*new value */\
    }
/*! \ brief Change value:  set XCP function to ON*/
#define WR_XCP_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_XCP_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_XCP);/*new value */\
    }
	
/*! \ brief Change value:  set MTS function to OFF*/
#define WR_MTS_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_MTS_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_MTS);/*new value */\
    }
/*! \ brief Change value:  set MTS function to ON*/
#define WR_MTS_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_MTS_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_MTS);/*new value */\
    }
	
/*! \ brief Change value:  set DBM function to OFF*/
#define WR_DBM_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_DBM_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_DBM);/*new value */\
    }
/*! \ brief Change value:  set DBM function to ON*/
#define WR_DBM_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_DBM_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_DBM);/*new value */\
    }
	
/*! \ brief Change value:  set PRT function to OFF*/
#define WR_PRT_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_PRT_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_PRT);/*new value */\
    }
/*! \ brief Change value:  set PRT function to ON*/
#define WR_PRT_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_PRT_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_PRT);/*new value */\
    }	
	
/*! \ brief Change value:  set FIT function to OFF*/
#define WR_FIT_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_FIT_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_FIT);/*new value */\
    }
/*! \ brief Change value:  set FIT function to ON*/
#define WR_FIT_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_FIT_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_FIT);/*new value */\
    }		

/*! \ brief Change value:  set RTM function to OFF*/
#define WR_RTM_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_RTM_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_RTM);/*new value */\
    }
/*! \ brief Change value:  set RTM function to ON*/
#define WR_RTM_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_RTM_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_RTM);/*new value */\
    }	
	
/*! \ brief Change value:  set FIM function to OFF*/
#define WR_FIM_FUNCT_NOT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_FIM_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)0 << SYS_MASK_STARTPOS_FIM);/*new value */\
    }
/*! \ brief Change value:  set FIM function to ON*/
#define WR_FIM_FUNCT_ACTIVATED \
    {\
        (GET_CDM_CUSTOMER_CODE()) &= (~((uint32)SYS_FIM_FUNCT_BITMASK)); /*Set it to proper back*/ \
        (GET_CDM_CUSTOMER_CODE()) |= (uint32)((uint32)1 << SYS_MASK_STARTPOS_FIM);/*new value */\
    }		
	
	
/*==================[type definitions]=======================================*/



/*==================[external constants declarations]========================*/


/*==================[external data declarations]=============================*/


/*==================[external function declarations]=========================*/


#endif /*_ESM_CUSTOMERCODING_H_*/






























