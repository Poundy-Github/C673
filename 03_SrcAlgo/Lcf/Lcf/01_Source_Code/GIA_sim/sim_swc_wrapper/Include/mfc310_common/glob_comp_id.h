/*! \file ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                ARS301

  CPU:                    Freescale MPC5674F

  COMPONENT:              MEAS

  MODULENAME:             glob_comp_id.h

  DESCRIPTION:         	  Definition of component identifiers 
                          Project independent definition of component identifiers
                          and further component related information.

  AUTHOR:                 Matthias Limbrunner (b-plus GmbH)

  CREATION DATE:          11.09.2007

  VERSION:                $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                $Log: glob_comp_id.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:24:42CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_common/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:35:39CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_common/project.pj
  CHANGES:                Revision 1.1 2014/03/13 15:11:14CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_common/project.pj
  CHANGES:                Revision 1.14 2012/09/27 20:24:04CEST Muench-EXT, Marc (uidt4601) 
  CHANGES:                Added COMP_ID_TSA;
  CHANGES:                --- Added comments ---  uidt4601 [Sep 27, 2012 8:24:08 PM CEST]
  CHANGES:                Change Package : 160818:1 http://mks-psad:7002/im/viewissue?selection=160818
  CHANGES:                Revision 1.13 2012/09/04 13:52:09CEST Wolf-EXT, Severin (uidu1890) 
  CHANGES:                added defines COMP_ID_MAP and COMP_ID_ALDW
  CHANGES:                --- Added comments ---  uidu1890 [Sep 4, 2012 1:52:13 PM CEST]
  CHANGES:                Change Package : 158033:1 http://mks-psad:7002/im/viewissue?selection=158033
  CHANGES:                Revision 1.12 2011/07/20 13:34:30CEST Limbrunner-EXT, Matthias (x-limbrunnem) 
  CHANGES:                Moved HEAT to address range 0x200Exxxx (function master)
  CHANGES:                --- Added comments ---  x-limbrunnem [Jul 20, 2011 1:34:31 PM CEST]
  CHANGES:                Change Package : 72310:1 http://mks-psad:7002/im/viewissue?selection=72310
  CHANGES:                Revision 1.11 2011/06/22 10:59:54CEST Limbrunner Matthias (x-limbrunnem) (x-limbrunnem) 
  CHANGES:                Removed conflict with algo_glob.h
  CHANGES:                --- Added comments ---  x-limbrunnem [Jun 22, 2011 10:59:55 AM CEST]
  CHANGES:                Change Package : 67084:1 http://mks-psad:7002/im/viewissue?selection=67084
  CHANGES:                Revision 1.10 2011/06/22 10:55:48CEST Limbrunner Matthias (x-limbrunnem) (x-limbrunnem) 
  CHANGES:                Removed unused virtual address ranges
  CHANGES:                Added address ranges for PPAR and FEE
  CHANGES:                --- Added comments ---  x-limbrunnem [Jun 22, 2011 10:55:49 AM CEST]
  CHANGES:                Change Package : 67084:1 http://mks-psad:7002/im/viewissue?selection=67084
  CHANGES:                Revision 1.9 2011/06/15 19:04:37CEST Limbrunner Matthias (x-limbrunnem) (x-limbrunnem) 
  CHANGES:                Reserved address range 0x800d.xxxx for MON
  CHANGES:                Moved ACTL to address range 0x8012.xxxx
  CHANGES:                --- Added comments ---  x-limbrunnem [Jun 15, 2011 7:04:37 PM CEST]
  CHANGES:                Change Package : 66734:4 http://mks-psad:7002/im/viewissue?selection=66734
  CHANGES:                Revision 1.8 2011/04/29 10:06:42CEST Limbrunner Matthias (x-limbrunnem) (x-limbrunnem) 
  CHANGES:                Added IDs and reserved address ranges for HLA segmentation and HLA icon
  CHANGES:                --- Added comments ---  x-limbrunnem [Apr 29, 2011 10:06:43 AM CEST]
  CHANGES:                Change Package : 64277:1 http://mks-psad:7002/im/viewissue?selection=64277
  CHANGES:                Revision 1.7 2011/04/06 20:27:59CEST Limbrunner Matthias (x-limbrunnem) (x-limbrunnem) 
  CHANGES:                Added component ID for image control adapter
  CHANGES:                --- Added comments ---  x-limbrunnem [Apr 6, 2011 8:27:59 PM CEST]
  CHANGES:                Change Package : 60026:10 http://mks-psad:7002/im/viewissue?selection=60026
  CHANGES:                Revision 1.6 2011/03/17 13:23:12CET Limbrunner Matthias (x-limbrunnem) (x-limbrunnem) 
  CHANGES:                Added ID for preview
  CHANGES:                --- Added comments ---  x-limbrunnem [Mar 17, 2011 1:23:12 PM CET]
  CHANGES:                Change Package : 60026:5 http://mks-psad:7002/im/viewissue?selection=60026
  CHANGES:                Revision 1.5 2011/01/26 18:35:49CET Matthias Limbrunner (x-limbrunnem) 
  CHANGES:                Added component ID for camera blockage algo
  CHANGES:                --- Added comments ---  x-limbrunnem [Jan 26, 2011 6:35:49 PM CET]
  CHANGES:                Change Package : 57907:2 http://mks-psad:7002/im/viewissue?selection=57907
  CHANGES:                Revision 1.4 2010/11/23 15:04:15CET Perske Lars (uidk7799) (uidk7799) 
  CHANGES:                Aded COMP_ID_LD
  CHANGES:                --- Added comments ---  uidk7799 [Nov 23, 2010 3:04:15 PM CET]
  CHANGES:                Change Package : 55515:1 http://mks-psad:7002/im/viewissue?selection=55515
  CHANGES:                Revision 1.3 2010/10/26 17:19:26CEST Perske Lars (uidk7799) (uidk7799) 
  CHANGES:                Added COMP_ID_VDY_ADAPT with new address range
  CHANGES:                --- Added comments ---  uidk7799 [Oct 26, 2010 5:19:26 PM CEST]
  CHANGES:                Change Package : 52444:1 http://mks-psad:7002/im/viewissue?selection=52444
  CHANGES:                Revision 1.2 2010/10/21 19:12:09CEST Perske Lars (uidk7799) (uidk7799) 
  CHANGES:                Added MCU ROI
  CHANGES:                --- Added comments ---  uidk7799 [Oct 21, 2010 7:12:09 PM CEST]
  CHANGES:                Change Package : 52444:1 http://mks-psad:7002/im/viewissue?selection=52444
  CHANGES:                Revision 1.1 2010/09/30 18:58:05CEST Johann Fuehrmann (x-fuehrmannj) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/PROJECTS/MFC300/05_Software/MCU/04_Engineering/01_Source_Code/SW/project.pj
  CHANGES:                Revision 1.2.1.2 2010/06/17 11:47:00CEST lperske 
  CHANGES:                Added HEAT
  CHANGES:                --- Added comments ---  lperske [2010/06/17 09:47:00Z]
  CHANGES:                Change Package : 44455:1 http://LISS014:6001/im/viewissue?selection=44455
  CHANGES:                Revision 1.2.1.1 2010/05/05 17:47:11CEST Lars Perske (lperske) 
  CHANGES:                Exchanged ARS components MAZ and MEL by by MFC CCC and IA
  CHANGES:                --- Added comments ---  lperske [2010/05/05 15:47:12Z]
  CHANGES:                Change Package : 38903:1 http://LISS014:6001/im/viewissue?selection=38903
  CHANGES:                Revision 1.2 2010/04/14 16:57:33CEST Lars Perske (lperske) 
  CHANGES:                Added IA as comp
  CHANGES:                --- Added comments ---  lperske [2010/04/14 14:57:33Z]
  CHANGES:                Change Package : 38903:1 http://LISS014:6001/im/viewissue?selection=38903
  CHANGES:                Revision 1.1 2010/02/25 20:48:17CET Uwe-Jürgen Zunker (uzunker) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/PROJECTS/ARS301/05_Software/04_Engineering/01_Source_Code/SW/project.pj

*****************************************************************************/
#ifndef GLOB_COMP_ID_INCLUDED
#define GLOB_COMP_ID_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  GUIDLINE for new MeasFreezeDataMTS function
*****************************************************************************/
/*
  Guidline for the use of the new MeasFreezeDataMTS function.

  1) before each function cycle must call the function "void MEASStartFuncCycle(MEASFuncID_t FuncID)"
      - FuncID is equal to the glob_comp_id in the following table
     Wiht this function the counter of the MTS is incremented.

  2) new MEASFreezeDataMTS function which is to call:
       MEASFreezeDataMTS(MEASInfo_t *Info,pui32_t MeasDataMTS, NULL);
  
  More Information for the MEASFreezeDataMTS function:

  1) MEASInfo_t *Info
 	      typedef struct
			  {
			    ui32_t VirtualAddress;               ==>  Location of data in virtual address space
			    ui32_t Length;                       ==>  Length of data in bytes
			    MEASFuncID_t         FuncID;         ==> Identifier of data source, see glob_comp_id
			    MEASFuncChannelID_t  FuncChannelID;  ==> Data classification (e.g. input, output), see 
                                                   Information for MTS and simulation in the glob_comp_id
			  }MEASInfo_t;
     
     ==> the struct mus be "const static", because the meas has an optimize access.
         For the meas means there are no unnecessary runing time and there are no deficit in the memory.

  2) FuncID
        FuncID = Glob_Comp_ID of the component, see in the following table

  3) FuncChannelID
        Special configuration for simulation, see at the end of this file.
        There are general configuration for simulation, all components can manage this by himself,
        if they need his own configuration.

        attention:
          --> last version of MTS doesn´t supported this function
          --> for the meas component connoted this there are a workaround for the use the new MeasFreezeDataMTS
          --> no adaptation, if the MTS supported the function, all adaption is in the meas component

  4) virtual address define the structure of the data which will be send and set by a doxygen command.
          --> "@VADDR:0x05000900"      <==>  virtual address for MTS

  5) configuration of the cycle ID, by a doxygen command.
          --> "@cycleid cycleid_60"   <==>  "ARSMainCycle 60"
          --> no "@cycleid"           <==>  "ARSMainCycle 20" (DEFAULT)
*/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
/* Component ID and virtual address range used by measurement */
#define COMP_ID_NULL      0   /* Reserved: Do not use */

/* Function Master */
/* Start: 0x2000.0000 */
/*      Component         ID  |   Master virtual address range        |   Slave virtual address range   |   Info  */
/*----------------------------------------------------------------------------------------------------------------*/
#define COMP_ID_TP        1u       /* 0x2000.0000 <--> 0x2000.ffff     |                                 |*/
#define COMP_ID_VDY       2u       /* 0x2001.0000 <--> 0x2001.ffff     |                                 |*/
#define COMP_ID_FCT       3u       /* 0x2002.0000 <--> 0x2002.ffff     |                                 |*/
#define COMP_ID_YR        4u       /* 0x2003.0000 <--> 0x2003.ffff     |                                 |*/
#define COMP_ID_SLAF      5u       /* 0x2004.0000 <--> 0x2004.ffff     |                                 |  SLAF (reserved range 16kB 0x20040000--0x20043FFF)*/
#define COMP_ID_CALI      6u       /* 0x2005.0000 <--> 0x2005.ffff     |                                 |*/
#define COMP_ID_HLA       7u       /* 0x2006.0000 <--> 0x2006.ffff     |                                 |*/
#define COMP_ID_LR        8u       /* 0x2007.0000 <--> 0x2007.ffff     |                                 |*/
#define COMP_ID_LD        9u       /* 0x2008.0000 <--> 0x2008.ffff     |                                 |*/
#define COMP_ID_GB        10u      /* 0x2009.0000 <--> 0x2009.ffff     |                                 |*/
#define COMP_ID_PV        11u      /* 0x200a.0000 <--> 0x200a.ffff     |                                 |*/
#define COMP_ID_ICA       12u      /* 0x200b.0000 <--> 0x200b.ffff     |                                 |*/
#define COMP_ID_HLA_SEG   13u      /* 0x200c.0000 <--> 0x200c.ffff     |                                 |*/
#define COMP_ID_HLA_ICON  14u      /* 0x200d.0000 <--> 0x200d.ffff     |                                 |*/
#define COMP_ID_HEAT      15u      /* 0x200e.0000 <--> 0x200e.ffff     |                                 |*/
#define COMP_ID_FREE_8    16u      /* 0x200f.0000 <--> 0x200f.ffff     |                                 |*/
/*ISF   COMP_ID_LSP       17u         0x2010.0000 <--> 0x2010.9050     |                                 |*/
#define COMP_ID_VDY_ADAPT 18u      /* 0x2030.0000 <--> 0x203f.ffff     |                                 |*/
#define COMP_ID_MAP       19u
#define COMP_ID_TSA       20u
#define COMP_ID_ALDW      21u

/* Function Slave */
/* Start: 0x0600.0000 */
/*      Component         ID  |   Master virtual address range        |   Slave virtual address range   |   Info  */
/*----------------------------------------------------------------------------------------------------------------*/
#define COMP_ID_RSP       64      /*                                  |   0x0600.0000 <--> 0x06ff.ffff  |*/
#define COMP_ID_RHC       65      /*                                  |   0x0700.0000 <--> 0x070f.ffff  |*/
#define COMP_ID_SR        66      /*                                  |   0x0710.0000 <--> 0x072f.ffff  |  SLA reserved range 2MB 0x0710.0000 - 0x072f.ffff (including SR and SLAF) */

/* Function Simulation */
/* Start: 0x7000.0000 */
/*      Component         ID  |   Master virtual address range        |   Slave virtual address range   |   Info  */
/*----------------------------------------------------------------------------------------------------------------*/
/* Simulation                     /* 0x7000.0000 <--> 0x7fff.ffff     |                                 |*/

/* Framesoftware */
/* Master start:  0x8000.0000 */
/* Slave start:   0x8080.0000 */
/*      Component         ID  |   Master virtual address range        |   Slave virtual address range   |   Info  */
/*----------------------------------------------------------------------------------------------------------------*/
#define COMP_ID_SYS       128     /* 0x8000.0000 <--> 0x8000.ffff     |   0x8080.0000 <--> 0x8080.ffff  |*/
                                  /* 0x800c.2008 <--> 0x800c.2fff     |   0x8085.2000 <--> 0x8085.ffff  |*/
                                  /* 0x800e.1000 <--> 0x800e.1fff     |                                 |*/
#define COMP_ID_OS        129     /* 0x8001.0000 <--> 0x8001.ffff     |                                 |*/
#define COMP_ID_NVM       130     /* 0x8002.0000 <--> 0x8002.ffff     |                                 |*/
#define COMP_ID_HAL       131     /* 0x8003.0000 <--> 0x8003.ffff     |                                 |*/
#define COMP_ID_IPC       132     /* 0x8004.0000 <--> 0x8004.ffff     |   0x8086.1000 <--> 0x8087.0fff  |*/
#define COMP_ID_MEAS      133     /* 0x8005.0000 <--> 0x8005.ffff     |   0x8085.0000 <--> 0x8085.1fff  |*/
#define COMP_ID_CCC       134     /* 0x8006.0000 <--> 0x8006.0fff     |                                 |*/
#define COMP_ID_IA        135     /* 0x8006.1000 <--> 0x8006.ffff     |                                 |*/
#define COMP_ID_CAN       136     /* 0x8007.0000 <--> 0x8007.ffff     |                                 |*/
#define COMP_ID_XCP       137     /* 0x8008.0000 <--> 0x8008.ffff     |                                 |*/
#define COMP_ID_CM        138     /* 0x8009.0000 <--> 0x8009.ffff     |                                 |*/
#define COMP_ID_ROI_MCU   139     /* 0x800a.0000 <--> 0x800b.ffff     |                                 |*/
#define COMP_ID_DEM       140     /* 0x800c.0000 <--> 0x800c.2007     |                                 |*/
                                  /* 0x800c.8000 <--> 0x800c.ffff     |                                 |*/
#define COMP_ID_FIM       141     /* 0x800c.0000 <--> 0x800c.2007     |                                 |*/
                                  /* 0x800c.8000 <--> 0x800c.ffff     |                                 |*/
#define COMP_ID_MON       142     /* 0x800d.0000 <--> 0x800d.ffff     |   0x8086.0000 <--> 0x8086.0fff  |*/
#define COMP_ID_FPGA      143     /* 0x800e.0000 <--> 0x800e.ffff     |                                 |*/
#define COMP_ID_DIAG      144     /* 0x800f.0000 <--> 0x800f.ffff     |                                 |*/
#define COMP_ID_FREE_10   145     /* 0x8010.0000 <--> 0x8010.ffff     |                                 |*/
#define COMP_ID_FREE_11   146     /* 0x8011.0000 <--> 0x8011.ffff     |                                 |*/
#define COMP_ID_ACTL      147     /* 0x8012.0000 <--> 0x8012.ffff     |                                 |*/
#define COMP_ID_PPAR      148     /* 0x8013.0000 <--> 0x8013.ffff     |                                 |*/
#define COMP_ID_FEE       149     /* 0x8014.0000 <--> 0x8014.ffff     |                                 |*/


/* Framesoftware DSP */
/* Start: 0x8090.0000 */
/*      Component         ID  |   DSP virtual address range           | Info  */
/*----------------------------------------------------------------------------*/
#define COMP_ID_CCDC              /* 0x8090.0000 <--> 0x8090.ffff     |*/
#define COMP_ID_ROI               /* 0x8091.0000 <--> 0x8091.ffff     |*/
#define COMP_ID_FREE_12           /* 0x8092.0000 <--> 0x8092.ffff     |*/
#define COMP_ID_FREE_13           /* 0x8093.0000 <--> 0x8093.ffff     |*/
#define COMP_ID_FREE_14           /* 0x8094.0000 <--> 0x8094.ffff     |*/
#define COMP_ID_IC                /* 0x8095.0000 <--> 0x8095.ffff     |*/


/* NVM */
/* this range is reserved */
/*      Component         ID  |   Master virtual address range        |   Slave virtual address range   |   Info  */
/*----------------------------------------------------------------------------------------------------------------*/
/* NVM                            /* 0x0090.0000 <--> 0x0090.ffff     |                                 |  the range is not to use */


/* Information for MTS and simulation */
/* Definition of function channel IDs for MEASInfo_t */
#define CHAN_ID_OUTPUT    0
#define CHAN_ID_INPUT     1
#define CHAN_ID_ADJUST    2
#define CHAN_ID_INTERNAL  3


/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTIONS 
*****************************************************************************/

#endif /* #define GLOB_COMP_ID_INCLUDED */
