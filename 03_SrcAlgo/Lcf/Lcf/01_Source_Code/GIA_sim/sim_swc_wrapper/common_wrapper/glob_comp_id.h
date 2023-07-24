/*! \file ********************************************************************

  COMPANY:                Continental, ADAS, A.D.C. GmbH

  PROJECT:                All

  MODULENAME:             glob_comp_id.h

  DESCRIPTION:         	  Definition of component identifiers 
                          Project independent definition of component identifiers
                          and further component related information.

  CREATION DATE:          11.09.2007

  VERSION:                $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                $Log: glob_comp_id.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:22:59CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/common_wrapper/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:34:40CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/common_wrapper/project.pj
  CHANGES:                Revision 1.35 2014/03/05 13:40:17CET spruckj 
  CHANGES:                Add camera main cylces
  CHANGES:                - Added comments -  spruckj [Mar 5, 2014 1:40:18 PM CET]
  CHANGES:                Change Package : 196584:4 http://mks-psad:7002/im/viewissue?selection=196584
  CHANGES:                Revision 1.34 2014/03/03 11:27:43CET Scherf, Steffen (uidu8201) 
  CHANGES:                added COMP_ID_ADPVDY
  CHANGES:                --- Added comments ---  uidu8201 [Mar 3, 2014 11:27:43 AM CET]
  CHANGES:                Change Package : 158949:8 http://mks-psad:7002/im/viewissue?selection=158949
  CHANGES:                Revision 1.33 2014/02/06 15:47:43CET Limbrunner-EXT, Matthias (x-limbrunnem) 
  CHANGES:                Added customer cycle IDs 37,38,39
  CHANGES:                --- Added comments ---  x-limbrunnem [Feb 6, 2014 3:47:44 PM CET]
  CHANGES:                Change Package : 209664:1 http://mks-psad:7002/im/viewissue?selection=209664
  CHANGES:                Revision 1.32 2014/01/27 17:38:32CET Scherf, Steffen (uidu8201) 
  CHANGES:                added comp_id_rahe
  CHANGES:                --- Added comments ---  uidu8201 [Jan 27, 2014 5:38:32 PM CET]
  CHANGES:                Change Package : 158949:8 http://mks-psad:7002/im/viewissue?selection=158949
  CHANGES:                Revision 1.31 2014/01/16 08:35:11CET Sautter-Steisslinger, Frank (uidw0362) 
  CHANGES:                Removed DEM task IDs since they are not used.
  CHANGES:                --- Added comments ---  uidw0362 [Jan 16, 2014 8:35:11 AM CET]
  CHANGES:                Change Package : 173705:82 http://mks-psad:7002/im/viewissue?selection=173705
  CHANGES:                Revision 1.30 2014/01/10 13:28:45CET Spruck, Jochen (spruckj) 
  CHANGES:                Add sr task and component id's for A and B part
  CHANGES:                --- Added comments ---  spruckj [Jan 10, 2014 1:28:46 PM CET]
  CHANGES:                Change Package : 196584:4 http://mks-psad:7002/im/viewissue?selection=196584
  CHANGES:                Revision 1.29 2014/01/09 14:05:17CET Spruck, Jochen (spruckj) 
  CHANGES:                Add cycle id 118 for crls camer rain light sensor and meas freeze address range 0x3150 0000 - 0x314f ffff
  CHANGES:                --- Added comments ---  spruckj [Jan 9, 2014 2:05:17 PM CET]
  CHANGES:                Change Package : 196584:4 http://mks-psad:7002/im/viewissue?selection=196584
  CHANGES:                Revision 1.28 2014/01/07 09:40:34CET Spruck, Jochen (spruckj) 
  CHANGES:                Add additional customer comp and task id's 30 - 36
  CHANGES:                --- Added comments ---  spruckj [Jan 7, 2014 9:40:35 AM CET]
  CHANGES:                Change Package : 196584:4 http://mks-psad:7002/im/viewissue?selection=196584
  CHANGES:                Revision 1.27 2013/12/17 16:09:55CET Spruck, Jochen (spruckj) 
  CHANGES:                Add task id's for some missing sw cores
  CHANGES:                #define TASK_ID_S16       135U
  CHANGES:                #define TASK_ID_S17       136U
  CHANGES:                #define TASK_ID_S27       137U
  CHANGES:                --- Added comments ---  spruckj [Dec 17, 2013 4:09:55 PM CET]
  CHANGES:                Change Package : 196584:4 http://mks-psad:7002/im/viewissue?selection=196584
  CHANGES:                Revision 1.26 2013/12/17 11:06:48CET Scherf, Steffen (uidu8201) 
  CHANGES:                renamed TASK Ids for ARS400
  CHANGES:                --- Added comments ---  uidu8201 [Dec 17, 2013 11:06:48 AM CET]
  CHANGES:                Change Package : 158949:8 http://mks-psad:7002/im/viewissue?selection=158949
  CHANGES:                Revision 1.25 2013/11/25 11:30:59CET Scherf, Steffen (uidu8201) 
  CHANGES:                added COMP_ID_RTA
  CHANGES:                --- Added comments ---  uidu8201 [Nov 25, 2013 11:31:00 AM CET]
  CHANGES:                Change Package : 158949:3 http://mks-psad:7002/im/viewissue?selection=158949
  CHANGES:                Revision 1.24 2013/11/07 09:52:38CET Sauter, Michael (sauterm) 
  CHANGES:                add component-id for RfCom
  CHANGES:                --- Added comments ---  sauterm [Nov 7, 2013 9:52:38 AM CET]
  CHANGES:                Change Package : 196136:6 http://mks-psad:7002/im/viewissue?selection=196136
  CHANGES:                Revision 1.23 2013/10/28 17:23:30CET Sautter-Steisslinger, Frank (uidw0362) 
  CHANGES:                Added DEM tasks
  CHANGES:                --- Added comments ---  uidw0362 [Oct 28, 2013 5:23:30 PM CET]
  CHANGES:                Change Package : 173705:41 http://mks-psad:7002/im/viewissue?selection=173705
  CHANGES:                Revision 1.22 2013/10/19 14:10:14CEST Banduka, Bojan (uid07813) 
  CHANGES:                [mod] visual merger, which has been already done
  CHANGES:                --- Added comments ---  uid07813 [Oct 19, 2013 2:10:14 PM CEST]
  CHANGES:                Change Package : 202364:1 http://mks-psad:7002/im/viewissue?selection=202364
  CHANGES:                Revision 1.21 2013/10/19 14:03:09CEST Banduka, Bojan (uid07813) 
  CHANGES:                [mod] Task ID -> Fex Control 112
  CHANGES:                --- Added comments ---  uid07813 [Oct 19, 2013 2:03:09 PM CEST]
  CHANGES:                Change Package : 202364:1 http://mks-psad:7002/im/viewissue?selection=202364
  CHANGES:                Revision 1.20.1.1 2013/10/08 16:05:14CEST Lancea, Laurentiu (uid95977) 
  CHANGES:                Updates for MFC400:
  CHANGES:                 - added ID for HEAT component
  CHANGES:                 - renamed COMP_ID_MEAS_MF
  CHANGES:                --- Added comments ---  uid95977 [Oct 8, 2013 4:05:14 PM CEST]
  CHANGES:                Change Package : 190219:1 http://mks-psad:7002/im/viewissue?selection=190219
  CHANGES:                Revision 1.20 2013/10/08 15:31:12CEST Scherf, Steffen (uidu8201) 
  CHANGES:                updated some IDs for the ARS400 project
  CHANGES:                --- Added comments ---  uidu8201 [Oct 8, 2013 3:31:13 PM CEST]
  CHANGES:                Change Package : 158949:3 http://mks-psad:7002/im/viewissue?selection=158949
  CHANGES:                Revision 1.19 2013/09/19 09:19:50CEST Sauter, Michael (sauterm) 
  CHANGES:                add id for peaklist
  CHANGES:                --- Added comments ---  sauterm [Sep 19, 2013 9:19:50 AM CEST]
  CHANGES:                Change Package : 196182:1 http://mks-psad:7002/im/viewissue?selection=196182
  CHANGES:                Revision 1.18 2013/09/18 16:07:35CEST Sauter, Michael (sauterm) 
  CHANGES:                add task id for sw and dsp
  CHANGES:                --- Added comments ---  sauterm [Sep 18, 2013 4:07:36 PM CEST]
  CHANGES:                Change Package : 196182:1 http://mks-psad:7002/im/viewissue?selection=196182
  CHANGES:                Revision 1.17 2013/09/17 08:40:37CEST Spruck, Jochen (spruckj) 
  CHANGES:                Add component id for PFC
  CHANGES:                --- Added comments ---  spruckj [Sep 17, 2013 8:40:37 AM CEST]
  CHANGES:                Change Package : 196584:1 http://mks-psad:7002/im/viewissue?selection=196584
  CHANGES:                Revision 1.16 2013/09/02 11:56:49CEST Frey, Thomas04 (uidv8881) 
  CHANGES:                remove duplicate defines (redefined in rta_conf.h)
  CHANGES:                --- Added comments ---  uidv8881 [Sep 2, 2013 11:56:49 AM CEST]
  CHANGES:                Change Package : 181559:1 http://mks-psad:7002/im/viewissue?selection=181559
  CHANGES:                Revision 1.15 2013/08/15 13:32:40CEST Weissmueller, Thomas (uidt3974) 
  CHANGES:                Added TASK_ID_GS_STEREO = 75
  CHANGES:                --- Added comments ---  uidt3974 [Aug 15, 2013 1:32:41 PM CEST]
  CHANGES:                Change Package : 194155:1 http://mks-psad:7002/im/viewissue?selection=194155
  CHANGES:                Revision 1.14 2013/08/13 14:46:37CEST Spruck, Jochen (spruckj) 
  CHANGES:                - Add ipc task id
  CHANGES:                - correct merge from michael
  CHANGES:                --- Added comments ---  spruckj [Aug 13, 2013 2:46:37 PM CEST]
  CHANGES:                Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:                Revision 1.13 2013/08/09 11:06:39CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                merged with ARS400
  CHANGES:                --- Added comments ---  eisenacherm [Aug 9, 2013 11:06:39 AM CEST]
  CHANGES:                Change Package : 180551:1 http://mks-psad:7002/im/viewissue?selection=180551
  CHANGES:                Revision 1.12 2013/07/18 17:51:01CEST Spruck, Jochen (spruckj) 
  CHANGES:                change vodca virtual address range from 0x3120.0000 <--> 0x312f.ffff to 0x3130.0000 <--> 0x313f.ffff
  CHANGES:                --- Added comments ---  spruckj [Jul 18, 2013 5:51:01 PM CEST]
  CHANGES:                Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:                Revision 1.11 2013/07/18 13:51:49CEST Stura, Georg (uidv7871) 
  CHANGES:                Frame SW definitions moved to RTA_conf.h
  CHANGES:                --- Added comments ---  uidv7871 [Jul 18, 2013 1:51:50 PM CEST]
  CHANGES:                Change Package : 182407:1 http://mks-psad:7002/im/viewissue?selection=182407
  CHANGES:                Revision 1.10 2013/07/11 13:36:35CEST Spruck, Jochen (spruckj) 
  CHANGES:                Add Vodca component
  CHANGES:                --- Added comments ---  spruckj [Jul 11, 2013 1:36:35 PM CEST]
  CHANGES:                Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:                Revision 1.9 2013/07/03 09:42:16CEST Stura, Georg (uidv7871) 
  CHANGES:                Task ID added for Frame SW
  CHANGES:                --- Added comments ---  uidv7871 [Jul 3, 2013 9:42:16 AM CEST]
  CHANGES:                Change Package : 176636:1 http://mks-psad:7002/im/viewissue?selection=176636
  CHANGES:                Revision 1.8 2013/07/01 15:56:57CEST Stura, Georg (uidv7871) 
  CHANGES:                New task ID's added for RTA
  CHANGES:                --- Added comments ---  uidv7871 [Jul 1, 2013 3:56:57 PM CEST]
  CHANGES:                Change Package : 176636:1 http://mks-psad:7002/im/viewissue?selection=176636
  CHANGES:                Revision 1.7 2013/06/28 16:11:02CEST Stura, Georg (uidv7871) 
  CHANGES:                Frame software task ID added for RTA task switch
  CHANGES:                --- Added comments ---  uidv7871 [Jun 28, 2013 4:11:02 PM CEST]
  CHANGES:                Change Package : 176636:1 http://mks-psad:7002/im/viewissue?selection=176636
  CHANGES:                Revision 1.6 2013/06/27 13:07:53CEST Weissmueller, Thomas (uidt3974) 
  CHANGES:                Added COMP_ID_SW_PCIE
  CHANGES:                --- Added comments ---  uidt3974 [Jun 27, 2013 1:07:54 PM CEST]
  CHANGES:                Change Package : 182423:2 http://mks-psad:7002/im/viewissue?selection=182423
  CHANGES:                Revision 1.5 2013/06/26 09:48:44CEST Stura, Georg (uidv7871) 
  CHANGES:                Added first COMP ID in the Framesoftware for the RTA usage
  CHANGES:                --- Added comments ---  uidv7871 [Jun 26, 2013 9:48:44 AM CEST]
  CHANGES:                Change Package : 176636:1 http://mks-psad:7002/im/viewissue?selection=176636
  CHANGES:                Revision 1.4 2013/06/18 10:32:50CEST Spruck, Jochen (spruckj) 
  CHANGES:                Update HLA address range
  CHANGES:                --- Added comments ---  spruckj [Jun 18, 2013 10:32:50 AM CEST]
  CHANGES:                Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:                Revision 1.3 2013/06/06 11:14:12CEST Spruck, Jochen (spruckj) 
  CHANGES:                Add memo comp and task id
  CHANGES:                --- Added comments ---  spruckj [Jun 6, 2013 11:14:13 AM CEST]
  CHANGES:                Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:                Revision 1.2 2013/06/04 10:39:50CEST Spruck, Jochen (spruckj) 
  CHANGES:                Add global sheduler component
  CHANGES:                --- Added comments ---  spruckj [Jun 4, 2013 10:39:51 AM CEST]
  CHANGES:                Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:                Revision 1.1 2013/05/16 14:00:46CEST Spruck, Jochen (spruckj) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/ACI_AlgoCommonInterfaces/01_Source_Code/common/project.pj


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
#ifndef COMP_ID_NULL
/* Component ID and virtual address range used by measurement */
#define COMP_ID_NULL      0   /* Reserved: Do not use */

/* Alogrithm */
/* Start: 0x2000.0000 */
/*      Component         ID    |     virtual address range            |   Info  */
/*----------------------------------------------------------------------------------------------------------------*/
#define COMP_ID_TP        1U       /* 0x2000.0000 <--> 0x2000.ffff     |   */
#define COMP_ID_VDY       2U       /* 0x2001.0000 <--> 0x2001.ffff     |   */
#define COMP_ID_FCT       3U       /* 0x2002.0000 <--> 0x2002.ffff     |   extended range 0x2020.0000 <--> 0x202f.ffff             */
#define COMP_ID_YR        4U       /* 0x2003.0000 <--> 0x2003.ffff     |   extended range 0x2030.0000 <--> 0x203f.ffff             */
#define COMP_ID_SLAF      5U       /* 0x2004.0000 <--> 0x2004.ffff     |   SLAF (reserved range 16kB 0x20040000--0x20043FFF)*/
#define COMP_ID_CALI      6U       /* 0x2005.0000 <--> 0x2005.ffff     |   */
#define COMP_ID_HLA       7U       /* 0x2006.0000 <--> 0x2006.ffff     |   extended range 0x3120.0000 <--> 0x312F.FFFF             */
#define COMP_ID_MAP       8U       /* 0x2007.0000 <--> 0x2007.ffff     |   */
#define COMP_ID_LR        9U       /* 0x2008.0000 <--> 0x2008.ffff     |   */
#define COMP_ID_FREE_2    10U      /* 0x2009.0000 <--> 0x2009.ffff     |   */
#define COMP_ID_FREE_3    11U      /* 0x200a.0000 <--> 0x200a.ffff     |   */
#define COMP_ID_IC        12U      /* 0x200b.0000 <--> 0x200b.ffff     |   */
#define COMP_ID_FREE_5    13U      /* 0x200c.0000 <--> 0x200c.ffff     |   */
#define COMP_ID_FREE_6    14U      /* 0x200d.0000 <--> 0x200d.ffff     |   */
#define COMP_ID_FREE_7    15U      /* 0x200e.0000 <--> 0x200e.ffff     |   */
#define COMP_ID_FREE_8    16U      /* 0x200f.0000 <--> 0x200f.ffff     |   */
#define COMP_ID_FCT60     18U      /* 0x2011.0000 <--> 0x201f.ffff     |   */
#define COMP_ID_ALN       19U
#define COMP_ID_CUST_0    30U      /* tbd */
#define COMP_ID_CUST_1    31U      /* tbd */
#define COMP_ID_CUST_2    32U      /* tbd */
#define COMP_ID_CUST_3    33U      /* tbd */
#define COMP_ID_CUST_4    34U      /* tbd */
#define COMP_ID_CUST_5    35U      /* tbd */
#define COMP_ID_CUST_6    36U      /* tbd */
#define COMP_ID_CUST_7    37U      /* tbd */
#define COMP_ID_CUST_8    38U      /* tbd */
#define COMP_ID_CUST_9    39U      /* tbd */
#define COMP_ID_ADC       62U      /* 0x20A0.0000 <--> 0x20Ef.ffff	   */
#define COMP_ID_ADC_EXT   63U      /* 0x20F0.0000 <--> 0x20Ff.ffff     |   */
#define COMP_ID_RSP       64U      /* 0x2040.0000 <--> 0x2040.ffff     |   */
#define COMP_ID_RHC       65U      /* 0x2041.0000 <--> 0x2041.ffff     |   */
#define COMP_ID_EM        67U      /* 0x2010.0000 <--> 0x201f.ffff     |   */
#define COMP_ID_RSP1      COMP_ID_RSP
#define COMP_ID_RSP2      68u
#define COMP_ID_RHC1      COMP_ID_RHC
#define COMP_ID_RHC2      69u

/* mono camera components */
#define COMP_ID_CIPP      70U      /* 0x3050.0000 <--> 0x305f.ffff     |   */
#define COMP_ID_CB        71U      /* 0x2009.0000 <--> 0x200f.ffff     |   */
#define COMP_ID_ECM       72U      /* 0x30f0.0000 <--> 0x30ff.ffff     |   */

#define COMP_ID_GS        74U      /* 0x3110.0000 <--> 0x311f.ffff     |   */

#define COMP_ID_LD        75U      /* 0x30e0.0000 <--> 0x30ef.ffff     |   */
#define COMP_ID_ALDW      76U      /* 0x2020.0000 <--> 0x202f.ffff     |   */

#define COMP_ID_SR        80U      /* 0x2042.0000 <--> 0x2042.ffff     | extended range 0x30D00000 <--> 0x30DFFFFF |  SLA reserved range 2MB 0x0710.0000 - 0x072f.ffff (including SR and SLAF) */
#define COMP_ID_TSA       81U      /* 0x2004.0000 <--> 0x2004.ffff     |   */
#define COMP_ID_SR_A      82U      /* same as COMP_ID_SR */
#define COMP_ID_SR_B      83U      /* same as COMP_ID_SR */

#define COMP_ID_MEMO      85U      /* 0x30b0.0000 <--> 0x30bf.ffff     |   */
#define COMP_ID_PFC       86U      /* 0x3140.0000 <--> 0x314f.ffff     |   */

/* stereo camera components */
#define COMP_ID_FEX       100U      /* 0x3060.0000 <--> 0x306F.ffff    |   */
#define COMP_ID_SIB       101U      /* 0x30a0.0000 <--> 0x30af.ffff    |   */
#define COMP_ID_FSD       102U      /* 0x3070.0000 <--> 0x307f.ffff    |   */
#define COMP_ID_FTRC      103U      /* 0x3100.0000 <--> 0x310f.ffff    |   */
#define COMP_ID_EMO       104U      /* 0x30b0.0000 <--> 0x30bf.ffff    |   */

#define COMP_ID_GEN       105U      /* 0x3010.0000 <--> 0x301f.ffff    |   */
#define COMP_ID_PED       106U      /* 0x3020.0000 <--> 0x302f.ffff    |   */
#define COMP_ID_VCL       107U      /* 0x3040.0000 <--> 0x304f.ffff    |   */
#define COMP_ID_PC        108U      /* 0x3030.0000 <--> 0x303f.ffff    |   */

#define COMP_ID_VODCA     111U      /* 0x3130.0000 <--> 0x313f.ffff    |   */

#define COMP_ID_SAC       112U      /* 0x3090.0000 <--> 0x309f.ffff    |   */

#define COMP_ID_PV        114U      /* 0x3080.0000 <--> 0x308f.ffff    |   */

#define COMP_ID_SCB       117U      /* 0x3408.0000 <--> 0x3408.ffff    |   */

#define COMP_ID_CRLS      118U      /* 0x3150.0000 <--> 0x315f.ffff    |   */

/* srl components range 130U - 139U */
#define COMP_ID_SRL       130U      /* 0x4000.8000 <--> 0x4000.FFFF    |   */


/* Framesoftware */
/* 0x80000000 - 0x81FFFFFF  MC			31 MB */
/* 0x82000000 - 0x83FFFFFF  SOC1		31 MB */
/* 0x84000000 - 0x85FFFFFF  SOC2		31 MB */
/* start:  0x8000.0000 */
/*      Component         ID  |      virtual address range            |   Info  */
/*----------------------------------------------------------------------------------------------------------------*/
#define COMP_ID_SYS       128     /* 0x8000.0000 <--> 0x8000.ffff     |   */
                                  /* 0x800c.2008 <--> 0x800c.2fff     |   */
                                  /* 0x800e.1000 <--> 0x800e.1fff     |   */
#define COMP_ID_OS        129     /* 0x8001.0000 <--> 0x8001.ffff     |    not used */
#define COMP_ID_NVM       130     /* 0x8002.0000 <--> 0x8002.ffff     |    not used */
#define COMP_ID_HAL       131     /* 0x8003.0000 <--> 0x8003.ffff     |    not used */
#define COMP_ID_IPC       132     /* 0x8004.0000 <--> 0x8004.ffff     |    not used */
#define COMP_ID_MEAS_MF   133     /* 0x8005.0000 <--> 0x8005.ffff     |   */
#define COMP_ID_HEAT      134     /* 0x8006.0000 <--> 0x8006.0fff     |   */
#define COMP_ID_MEL       135     /* 0x8006.1000 <--> 0x8006.ffff     |   */
#define COMP_ID_CAN       136     /* 0x8007.0000 <--> 0x8007.ffff     |   */
#define COMP_ID_XCP       137     /* 0x8008.0000 <--> 0x8008.ffff     |    not used */
#define COMP_ID_CM        138     /* 0x8009.0000 <--> 0x8009.ffff     |    not used */
#define COMP_ID_VDATA     139     /* 0x800a.0000 <--> 0x800b.ffff     |    not used */
#define COMP_ID_DEM       140     /* 0x800c.0000 <--> 0x800c.2007     |   */
                                  /* 0x800c.8000 <--> 0x800c.ffff     |   */
#define COMP_ID_FIM       141     /* 0x800c.0000 <--> 0x800c.2007     |    not used */
                                  /* 0x800c.8000 <--> 0x800c.ffff     |   */
#define COMP_ID_MON       142     /* 0x800d.0000 <--> 0x800d.0fff     |   */
#define COMP_ID_ACTL      143     /* 0x800d.1000 <--> 0x800d.ffff     |   */
#define COMP_ID_FPGA      144     /* 0x800e.2000 <--> 0x800e.ffff     |    not used */
#define COMP_ID_DIAG      145     /* 0x800f.0000 <--> 0x800f.3fff     |   */
#define COMP_ID_RFCOM     146     /* 0x800f.4000 <--> 0x800f.7fff     |   */
#define COMP_ID_RTA       147     /* 0x800f.8000 <--> 0x8010.7fff     |   */
#define COMP_ID_RAHE      148     /* 0x8010.8000 <--> 0x8010.ffff     |   */
#define COMP_ID_ADPVDY    149     /* 0x8020.0000 <--> 0x8020.ffff     |   */


/* Do not exceed the 8-bit data space of 255!! */

/* Information for MTS and simulation */
/* Definition of function channel IDs for MEASInfo_t */
#define CHAN_ID_OUTPUT    0
#define CHAN_ID_INPUT     1
#define CHAN_ID_ADJUST    2
#define CHAN_ID_INTERNAL  3

#endif


/* ******************************************************************************
 *   remapped function id for mts protocol v2.0
 * ******************************************************************************
 */

#define MTS_FUNC_ID_TP 			COMP_ID_TP
#define MTS_FUNC_ID_VDY    		COMP_ID_VDY
#define MTS_FUNC_ID_FCT    		COMP_ID_FCT
#define MTS_FUNC_ID_YR    		COMP_ID_YR
#define MTS_FUNC_ID_SLAF    	COMP_ID_SLAF
#define MTS_FUNC_ID_CALI    	COMP_ID_CALI
#define MTS_FUNC_ID_HLA    		COMP_ID_HLA
#define MTS_FUNC_ID_MAP    		COMP_ID_MAP
#define MTS_FUNC_ID_LR    		COMP_ID_LR
#define MTS_FUNC_ID_FREE_2    	COMP_ID_FREE_2
#define MTS_FUNC_ID_FREE_3    	COMP_ID_FREE_3
#define MTS_FUNC_ID_IC    		COMP_ID_IC
#define MTS_FUNC_ID_FREE_5    	COMP_ID_FREE_5
#define MTS_FUNC_ID_FREE_6    	COMP_ID_FREE_6
#define MTS_FUNC_ID_FREE_7    	COMP_ID_FREE_7
#define MTS_FUNC_ID_FREE8    	COMP_ID_FREE_8
#define MTS_FUNC_ID_FCT60    	COMP_ID_FCT60
#define MTS_FUNC_ID_RSP    		COMP_ID_RSP
#define MTS_FUNC_ID_RHC    		COMP_ID_RHC

#define MTS_FUNC_ID_EM  		COMP_ID_EM

#define MTS_FUNC_ID_ADC        	COMP_ID_ADC
#define MTS_FUNC_ID_ADC_EXT    	COMP_ID_ADC_EXT

/* mono camera components */
#define MTS_FUNC_ID_CIPP    	COMP_ID_CIPP
#define MTS_FUNC_ID_CB    		COMP_ID_CB
#define MTS_FUNC_ID_ECM    		COMP_ID_ECM

#define MTS_FUNC_ID_GS     		COMP_ID_GS

#define MTS_FUNC_ID_LD     		COMP_ID_LD
#define MTS_FUNC_ID_ALDW     	COMP_ID_ALDW

#define MTS_FUNC_ID_SR      	COMP_ID_SR
#define MTS_FUNC_ID_TSA      	COMP_ID_TSA

#define MTS_FUNC_ID_MEMO    	COMP_ID_MEMO

/* stereo camera components */
#define MTS_FUNC_ID_FEX        	COMP_ID_FEX
#define MTS_FUNC_ID_SIB        	COMP_ID_SIB
#define MTS_FUNC_ID_FSD        	COMP_ID_FSD
#define MTS_FUNC_ID_FTRC        COMP_ID_FTRC
#define MTS_FUNC_ID_EMO        	COMP_ID_EMO

#define MTS_FUNC_ID_GEN        	COMP_ID_GEN
#define MTS_FUNC_ID_PED        	COMP_ID_PED
#define MTS_FUNC_ID_VCL        	COMP_ID_VCL
#define MTS_FUNC_ID_PC        	COMP_ID_PC

#define MTS_FUNC_ID_VODCA   	COMP_ID_VODCA

#define MTS_FUNC_ID_SAC     	COMP_ID_SAC

#define MTS_FUNC_ID_PV        	COMP_ID_PV

#define MTS_FUNC_ID_SCB    		COMP_ID_SCB


#define MTS_FUNC_ID_SRL    		COMP_ID_SRL

#define MTS_FUNC_ID_SYS   		COMP_ID_SYS

#define MTS_FUNC_ID_OS      	COMP_ID_OS
#define MTS_FUNC_ID_NVM      	COMP_ID_NVM
#define MTS_FUNC_ID_HAL      	COMP_ID_HAL
#define MTS_FUNC_ID_IPC      	COMP_ID_IPC
#define MTS_FUNC_ID_MTS      	COMP_ID_MEAS_MF  /* renamed */
#define MTS_FUNC_ID_HEAT      	COMP_ID_HEAT
#define MTS_FUNC_ID_MEL      	COMP_ID_MEL   /* obsolete */
#define MTS_FUNC_ID_CAN      	COMP_ID_CAN
#define MTS_FUNC_ID_XCP      	COMP_ID_XCP
#define MTS_FUNC_ID_CM      	COMP_ID_CM
#define MTS_FUNC_ID_VDATA      	COMP_ID_VDATA
#define MTS_FUNC_ID_DEM      	COMP_ID_DEM
             
#define MTS_FUNC_ID_FIM      	COMP_ID_FIM
            
#define MTS_FUNC_ID_MON      	COMP_ID_MON
#define MTS_FUNC_ID_SCTL      	COMP_ID_ACTL   /* renamed */
#define MTS_FUNC_ID_FPGA      	COMP_ID_FPGA
#define MTS_FUNC_ID_DIAG      	COMP_ID_DIAG


#define MTS_FUNC_ID_SW_GEN_ADAPT_ALGO_EXEC      COMP_ID_SW_GEN_ADAPT_ALGO_EXEC
#define MTS_FUNC_ID_SW_PCIE                     COMP_ID_SW_PCIE

/* ******************************************************************************
 *    remapped function end
 * ******************************************************************************
 */

#ifndef TASK_ID_NULL
/* TaskID, former CycleID, TaskID and Cycle ID are equivalent */
#define TASK_ID_NULL      0   /* Reserved: Do not use */

/* SRL Task ID's range 10U - 19U */
#define TASK_ID_SRL       10U


#define TASK_ID_VDY       20U
#define TASK_ID_FCT       21U
#define TASK_ID_ALDW      22U

#define TASK_ID_CUST_0    30U
#define TASK_ID_CUST_1    31U
#define TASK_ID_CUST_2    32U
#define TASK_ID_CUST_3    33U
#define TASK_ID_CUST_4    34U
#define TASK_ID_CUST_5    35U
#define TASK_ID_CUST_6    36U
#define TASK_ID_CUST_7    37U
#define TASK_ID_CUST_8    38U
#define TASK_ID_CUST_9    39U

#define TASK_ID_VEHICLE      40U
#define TASK_ID_EVEN_MAIN    41U
#define TASK_ID_ODD_MAIN     42U
#define TASK_ID_ODD_CLASSIC  43U
#define TASK_ID_ODD_MOD      44U
#define TASK_ID_STEREO_MAIN  45U
#define TASK_ID_STEREO_PV    46U
#define TASK_ID_STEREO_RECT  47U
#define TASK_ID_CLASSIFIERS  48U

#define TASK_ID_LD        49U
#define TASK_ID_SR        50U
#define TASK_ID_MAP       54U

#define TASK_ID_RHC       60U
#define TASK_ID_RSP       60U
#define TASK_ID_ALN       60U
#define TASK_ID_EM        60U


#define TASK_ID_IMAGE     60U

#define TASK_ID_RSP1      61U

/* mono camera components */
#define TASK_ID_CIPP      61U
#define TASK_ID_CB        62U
#define TASK_ID_ECM       63U
#define TASK_ID_IC        64U
#define TASK_ID_HLA       65U
#define TASK_ID_TSA       66U
#define TASK_ID_SAC       68U
#define TASK_ID_FPGA      69U
#define TASK_ID_CEM       70U
#define TASK_ID_PV        71U
#define TASK_ID_FCT60     72U
#define TASK_ID_SCB       73U
#define TASK_ID_GS        74U
#define TASK_ID_GS_STEREO 75U

#define TASK_ID_SR_A      82U
#define TASK_ID_SR_B      83U

#define TASK_ID_MEMO      85U
#define TASK_ID_PFC       86U

/* stereo camera components */
#define TASK_ID_FEX       100U
#define TASK_ID_SIB       101U
#define TASK_ID_FSD       102U
#define TASK_ID_FTRC      103U
#define TASK_ID_EMO       104U
#define TASK_ID_GEN       105U
#define TASK_ID_PED       106U
#define TASK_ID_VCL       107U
#define TASK_ID_PC        108U

#define TASK_ID_VODCA     111U
#define TASK_ID_FEXCONTROL	112U

#define TASK_ID_CRLS      118U

/* Framesoftware task id */
#define TASK_ID_M11       130U
#define TASK_ID_M12       131U
#define TASK_ID_IPC       132U

#define TASK_ID_S16       135U
#define TASK_ID_S17       136U
#define TASK_ID_S27       137U

#define TASK_ID_S11       140U
#define TASK_ID_S12       141U
#define TASK_ID_S13       142U
#define TASK_ID_S14       143U
#define TASK_ID_S15       144U

#define TASK_ID_S21       145U
#define TASK_ID_S22       146U
#define TASK_ID_S23       147U
#define TASK_ID_S24       148U
#define TASK_ID_S25       149U

/* NOT NOT USE            160 and higher */
/* The TASK_ID starting with 160 are assigned to the frame SW */
/* There are defined in rta_conf.h file */

/* ARS400/SRR300 TASKs */
#define TASK_ID_SW_RCC                      200U  /* Do not use this one for ARS400 platform */
#define TASK_ID_SW_COM                      201U  /* Do not use this one for ARS400 platform */
#define TASK_ID_SW_BSW                      202U  /* Do not use this one for ARS400 platform */
#define TASK_ID_SW_MTS                      TASK_ID_SW_MEAS /* renamed */ /* Do not use this one for ARS400 platform */

#define TASK_ID_ALGO_RAW_DATA_CYCLE         204U
#define TASK_ID_ALGO_DATA_PROC_CYCLE        205U
#define TASK_ID_ALGO_RHC_CYCLE              206U
#define TASK_ID_ALGO_VEH_CYCLE              207U
#define TASK_ID_ALGO_SEN_CYCLE              208U
#define TASK_ID_SW_EVERY_10MS               209U
#define TASK_ID_SW_EVERY_20MS               210U
#define TASK_ID_SW_RADAR_CYCLE              211U
#define TASK_ID_ALGO_PEAK_LIST              212U
#define TASK_ID_DSP                         213U
#define TASK_ID_SW_EVERY_100MS              214U   /* Reserved, not yet supported by the ARS400 devices! */
#define TASK_ID_SW_EVERY_10S                215U   /* Reserved, not yet supported by the ARS400 devices! */
#define TASK_ID_SW_06                       216U   /* Reserved, not yet supported by the ARS400 devices! */


#define TASK_ID_UNKNOWN      255U /* Error: If this ID is seen in RTA then there are missing ID's */
/* Do not exceed the 8-bit data space of 255!! */



#endif

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTIONS 
*****************************************************************************/

#endif /* #define GLOB_COMP_ID_INCLUDED */
