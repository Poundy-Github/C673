/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT

MODULNAME:                 fct_project_id.h

DESCRIPTION:               FCT types

AUTHOR:                    Gergely Ungvary

CREATION DATE:             11.09.2007

VERSION:                   $Revision: 1.7 $

LEGACY VERSION             Revision: 1.12

**************************************************************************** */
#ifndef FCT_PROJECT_ID_H
#define FCT_PROJECT_ID_H

#include  "fct_ver_custom.h"
/*****************************************************************************
  SYMBOLISCHE KONSTANTEN 
*****************************************************************************/

/*****************************************************************************
Table for setting up  Project IDs

Interpretation in HEX:
TCCC PPPP:
T    => Technology
CCC  => Customer
PPPP => Project ID

Example:
000A 0001 
T -> 0 ==> Radar    
C -> A ==> 10 (Honda)
P -> 1 ==> 1

******************************************************************************/
/*! @cond Doxygen_Suppress */
/* Values from 0 7 */
#define FCT_SW_PROJID_TECH_OFFSET (268435456)
#define FCT_SW_PROJID_RADAR       (0)   /*!< indicates radar project in Function Version Number*/
#define FCT_SW_PROJID_CAMERA      (1)
#define FCT_SW_PROJID_ADCU        (2)

  
/* Values from 0 4095 */
#define FCT_SW_PROJID_CUST_OFFSET (65536)
#define FCT_SW_PROJID_BMW         (0)   /*!< indicates BMW project in Function Version Number*/
#define FCT_SW_PROJID_MERCEDES    (1)
#define FCT_SW_PROJID_TOYOTA      (2)
#define FCT_SW_PROJID_VW          (3)
#define FCT_SW_PROJID_GM          (4)
#define FCT_SW_PROJID_FORD        (5)
#define FCT_SW_PROJID_M_LKW       (6)
#define FCT_SW_PROJID_HYUNDAI     (7)
#define FCT_SW_PROJID_MITSUBISHI  (8)
#define FCT_SW_PROJID_MAZDA       (9)
#define FCT_SW_PROJID_HONDA       (10)
#define FCT_SW_PROJID_FIAT        (11)
#define FCT_SW_PROJID_VOLVO       (12)
#define FCT_SW_PROJID_RENAULT     (13)
#define FCT_SW_PROJID_PSA         (14)
#define FCT_SW_PROJID_NISSAN      (15)
#define FCT_SW_PROJID_BASE        (16)
#define FCT_SW_PROJID_GEELY       (17)
#define FCT_SW_PROJID_TESLA       (18)
#define FCT_SW_PROJID_WABCO       (19)
#define FCT_SW_PROJID_LYNKCO      (20)
#define FCT_SW_PROJID_MOBIS       (21)
#define FCT_SW_PROJID_SAIC        (22)
#define FCT_SW_PROJID_SGMW        (23)
#define FCT_SW_PROJID_VENUCIA     (24)
#define FCT_SW_PROJID_OTHER       (4095)

/*
List for actual Projects

Radar
=========
ARS4B0        -- 0 000 0000
ARS430BW18    -- 0 000 0001
ARS4D0        -- 0 001 0000
ARS4D1        -- 0 001 0001
ARS4D2        -- 0 001 0002
ARS441DP10    -- 0 001 0003
ARS4T0        -- 0 002 0000
ARS510TA19    -- 0 002 0001
ARS410VW16    -- 0 003 0000
ARS410VW18    -- 0 003 0001
ARS410VW29    -- 0 003 0002
ARS510VW19    -- 0 003 0003
ARS4G0        -- 0 004 0000
ARS4G1        -- 0 004 0001
ARS510GM18    -- 0 004 0001
ARS4L0        -- 0 006 0000
ARS4L1        -- 0 006 0001
ARS410HI17    -- 0 007 0000
ARS410HI28    -- 0 007 0001
ARS430MI18    -- 0 008 0000
ARS510HA10    -- 0 010 0000
ARS4V0        -- 0 012 0000
ARS410RT17    -- 0 013 0000
ARS410RT28    -- 0 013 0001
ARS510RT10    -- 0 013 0002
ARS410NN16    -- 0 015 0000
ARS430NN17    -- 0 015 0001
ARS410NCAP18  -- 0 016 0000
ARS510        -- 0 016 0001
ARS410ACC400  -- 0 016 0002
ARS510ACC400  -- 0 016 0003
ARS410GY18    -- 0 017 0000
ARS410GY69    -- 0 017 0001
ARS410TL17    -- 0 018 0000
ARS430WC19    -- 0 019 0000
ARS410LO19    -- 0 020 0000
ARS410MS19    -- 0 021 0000
ARS410SC19    -- 0 022 0000
ARS410SW29    -- 0 023 0000
ARS410VA10    -- 0 024 0000
*/

#define  FCT_SW_PROJID_ARS4B0       ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_BMW       )   + 0)
#define  FCT_SW_PROJID_ARS430BW18   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_BMW       )   + 1)
#define  FCT_SW_PROJID_ARS4D0       ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_MERCEDES  )   + 0)
#define  FCT_SW_PROJID_ARS4D1       ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_MERCEDES  )   + 1)
#define  FCT_SW_PROJID_ARS4D2       ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_MERCEDES  )   + 2)
#define  FCT_SW_PROJID_ARS441DP10   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_MERCEDES  )   + 3)
#define  FCT_SW_PROJID_ARS4T0       ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_TOYOTA    )   + 0)
#define  FCT_SW_PROJID_ARS510TA19   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_TOYOTA    )   + 1)
#define  FCT_SW_PROJID_ARS410VW16   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_VW        )   + 0)
#define  FCT_SW_PROJID_ARS410VW18   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_VW        )   + 1)
#define  FCT_SW_PROJID_ARS410VW29   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_VW        )   + 2)
#define  FCT_SW_PROJID_ARS510VW19   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_VW        )   + 3)
#define  FCT_SW_PROJID_ARS4G0       ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_GM        )   + 0)
#define  FCT_SW_PROJID_ARS4G1       ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_GM        )   + 1)
#define  FCT_SW_PROJID_ARS510GM18   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_GM        )   + 2)
#define  FCT_SW_PROJID_ARS4L0       ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_M_LKW     )   + 0)
#define  FCT_SW_PROJID_ARS4L1       ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_M_LKW     )   + 1)
#define  FCT_SW_PROJID_ARS410HI17   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_HYUNDAI   )   + 0)
#define  FCT_SW_PROJID_ARS410HI28   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_HYUNDAI   )   + 1)
#define  FCT_SW_PROJID_ARS430MI18   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_MITSUBISHI)   + 0)
#define  FCT_SW_PROJID_ARS510HA10   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_HONDA     )   + 0)
#define  FCT_SW_PROJID_ARS4V0       ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_VOLVO     )   + 0)
#define  FCT_SW_PROJID_ARS410RT17   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_RENAULT   )   + 0)
#define  FCT_SW_PROJID_ARS410RT28   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_RENAULT   )   + 1)
#define  FCT_SW_PROJID_ARS510RT10   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_RENAULT   )   + 2)
#define  FCT_SW_PROJID_ARS410NN16   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_NISSAN    )   + 0)
#define  FCT_SW_PROJID_ARS430NN17   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_NISSAN    )   + 1)
#define  FCT_SW_PROJID_ARS430NCAP18 ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_BASE      )   + 0)
#define  FCT_SW_PROJID_ARS510       ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_BASE      )   + 1)
#define  FCT_SW_PROJID_ARS410ACC400 ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_BASE      )   + 2)
#define  FCT_SW_PROJID_ARS410GY18   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_GEELY     )   + 0)
#define  FCT_SW_PROJID_ARS410GY69   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_GEELY     )   + 1)
#define  FCT_SW_PROJID_ARS410TL17   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_TESLA     )   + 0)
#define  FCT_SW_PROJID_ARS430WC19   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_WABCO     )   + 0)
#define  FCT_SW_PROJID_ARS410LO19   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_LYNKCO    )   + 0)
#define  FCT_SW_PROJID_ARS410MS19   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_MOBIS     )   + 0)
#define  FCT_SW_PROJID_ARS410SC19   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_SAIC      )   + 0)
#define  FCT_SW_PROJID_ARS410SW29   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_SGMW      )   + 0)
#define  FCT_SW_PROJID_ARS410VA10   ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_RADAR) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_VENUCIA   )   + 0)
/*
Camera
==========
SMFC4B0       -- 1 000 0000
MFS430BW16    -- 1 000 0001
SRLCAM4T0     -- 1 002 0000
MFC4T0        -- 1 002 0001
MFC430H17     -- 1 007 000
MFC440GY18    -- 1 012 0001 (To clarify: GY-Project with Volvo Project ID)
MFC430NCAP18  -- 1 016 0000
MFC431        -- 1 016 0001
MFC510        -- 1 016 0002
*/
#define  FCT_SW_PROJID_SMFC4B0       ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_CAMERA) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_BMW   )  + 0)
#define  FCT_SW_PROJID_MFS430BW16    ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_CAMERA) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_BMW   )  + 1)
#define  FCT_SW_PROJID_SRLCAM4T0     ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_CAMERA) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_TOYOTA)  + 0)
#define  FCT_SW_PROJID_MFC4T0        ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_CAMERA) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_TOYOTA)  + 1)
#define  FCT_SW_PROJID_MFC430H17     ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_CAMERA) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_HYUNDAI) + 0)
#define  FCT_SW_PROJID_MFC440GY18    ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_CAMERA) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_VOLVO)   + 0)
#define  FCT_SW_PROJID_MFC430NCAP18  ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_CAMERA) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_BASE  )  + 0)
#define  FCT_SW_PROJID_MFC431        ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_CAMERA) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_BASE )   + 1)
#define  FCT_SW_PROJID_MFC510        ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_CAMERA) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_BASE )   + 2)

/*
ADCU
==========
ADC420HA10    -- 2 010 0000
*/
#define  FCT_SW_PROJID_ADC420HA10    ((FCT_SW_PROJID_TECH_OFFSET * FCT_SW_PROJID_ADCU) + (FCT_SW_PROJID_CUST_OFFSET * FCT_SW_PROJID_HONDA)   + 0)


/* Find out the Project Name from its ID */
#if ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS4B0))
#define FCT_ALL_SW_PROJECT_NAME "ARS4B0_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS430BW18))
#define FCT_ALL_SW_PROJECT_NAME "ARS430BW18_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS4D0))
#define FCT_ALL_SW_PROJECT_NAME "ARS4D0_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS4D1))
#define FCT_ALL_SW_PROJECT_NAME "ARS4D1_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS4D2))
#define FCT_ALL_SW_PROJECT_NAME "ARS4D2_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS441DP10))
#define FCT_ALL_SW_PROJECT_NAME "ARS441DP10_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS4T0))
#define FCT_ALL_SW_PROJECT_NAME "ARS4T0_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS510TA19))
#define FCT_ALL_SW_PROJECT_NAME "ARS510TA19_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410VW16))
#define FCT_ALL_SW_PROJECT_NAME "ARS410VW16_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410VW18))
#define FCT_ALL_SW_PROJECT_NAME "ARS410VW18_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410VW29))
#define FCT_ALL_SW_PROJECT_NAME "ARS410VW29_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS510VW19))
#define FCT_ALL_SW_PROJECT_NAME "ARS510VW19_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS4G0))
#define FCT_ALL_SW_PROJECT_NAME "ARS4G0_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS4G1))
#define FCT_ALL_SW_PROJECT_NAME "ARS4G1_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS510GM18))
#define FCT_ALL_SW_PROJECT_NAME "ARS510GM18_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS4L0))
#define FCT_ALL_SW_PROJECT_NAME "ARS4L0_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS4L1))
#define FCT_ALL_SW_PROJECT_NAME "ARS4L1_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410HI17))
#define FCT_ALL_SW_PROJECT_NAME "ARS410HI17_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410HI28))
#define FCT_ALL_SW_PROJECT_NAME "ARS410HI28_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS430MI18))
#define FCT_ALL_SW_PROJECT_NAME "ARS430MI18_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS510HA10))
#define FCT_ALL_SW_PROJECT_NAME "ARS510HA10_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS4V0))
#define FCT_ALL_SW_PROJECT_NAME "ARS4V0_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410RT17))
#define FCT_ALL_SW_PROJECT_NAME "ARS410RT17_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410RT28))
#define FCT_ALL_SW_PROJECT_NAME "ARS410RT28_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS510RT10))
#define FCT_ALL_SW_PROJECT_NAME "ARS510RT10_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410NN16))
#define FCT_ALL_SW_PROJECT_NAME "ARS410NN16_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS430NN17))
#define FCT_ALL_SW_PROJECT_NAME "ARS430NN17_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS430NCAP18))
#define FCT_ALL_SW_PROJECT_NAME "ARS430NCAP18_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS510))
#define FCT_ALL_SW_PROJECT_NAME "ARS510_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410ACC400))
#define FCT_ALL_SW_PROJECT_NAME "ARS410ACC400_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410GY18))
#define FCT_ALL_SW_PROJECT_NAME "ARS410GY18_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410GY69))
#define FCT_ALL_SW_PROJECT_NAME "ARS410GY69_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410TL17))
#define FCT_ALL_SW_PROJECT_NAME "ARS410TL17_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS430WC19))
#define FCT_ALL_SW_PROJECT_NAME "ARS430WC19_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410LO19))
#define FCT_ALL_SW_PROJECT_NAME "ARS410LO19_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410MS19))
#define FCT_ALL_SW_PROJECT_NAME "ARS410MS19_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410SC19))
#define FCT_ALL_SW_PROJECT_NAME "ARS410SC19_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410SW29))
#define FCT_ALL_SW_PROJECT_NAME "ARS410SW29_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ARS410VA10))
#define FCT_ALL_SW_PROJECT_NAME "ARS410VA10_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_SMFC4B0))
#define FCT_ALL_SW_PROJECT_NAME "SMFC4B0_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_MFS430BW16))
#define FCT_ALL_SW_PROJECT_NAME "MFS430BW16_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_SRLCAM4T0))
#define FCT_ALL_SW_PROJECT_NAME "SRLCAM4T0_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_MFC4T0))
#define FCT_ALL_SW_PROJECT_NAME "MFC4T0_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_MFC430H17))     
#define FCT_ALL_SW_PROJECT_NAME "MFC430H17_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_MFC440GY18))
#define FCT_ALL_SW_PROJECT_NAME "MFC440GY18_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_MFC430NCAP18))
#define FCT_ALL_SW_PROJECT_NAME "MFC430NCAP18_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_MFC431))
#define FCT_ALL_SW_PROJECT_NAME "MFC431_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_MFC510))
#define FCT_ALL_SW_PROJECT_NAME "MFC510_"
#elif ((FCTALL_SW_PROJ_ID)==(FCT_SW_PROJID_ADC420HA10))
#define FCT_ALL_SW_PROJECT_NAME "ADC420HA10_"
#else
#define FCT_ALL_SW_PROJECT_NAME "NN_"
#endif


/*! @endcond Doxygen_Suppress */
#endif
