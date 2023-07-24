/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF (Lateral Control Functions)

  MODULNAME:                 LCFERR_SenCustom.c

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.3 $


  ---*/ /*---
  CHANGES:                   $Log: LCFERR_SenCustom.c  $
  CHANGES:                   Revision 1.3 2020/11/05 03:48:08CET Bi, Zhongyan (uib56412) (uib56412) 
  CHANGES:                   update the max counter for alive check
  CHANGES:                   Revision 1.2 2020/08/26 08:26:53CEST Hu, Xiaohui02 (uib56746) (uib56746) 
  CHANGES:                   Update P_ERRIOSEN_EnableChecks_btf = 0xFE and some max value to 3
  CHANGES:                   Revision 1.6 2020/08/25 05:46:01CEST Hu, Xiaohui02 (uib56746) (uib56746) 
  CHANGES:                   Update P_ERRIOSEN_EnableChecks_btf=0xFE and some max value to 3
  CHANGES:                   Revision 1.5 2019/11/27 08:18:48CET Grosu, George (uidl9584) 
  CHANGES:                   Adapt for CarMaker tests
  CHANGES:                   Revision 1.4 2019/11/26 15:23:45CET Grosu, George (uidl9584) 
  CHANGES:                   bring TA19 changes to trunk
  CHANGES:                   Revision 1.3 2019/05/30 13:15:25CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Correct wrapers for ports checks and HLA
  CHANGES:                   Revision 1.2 2019/04/10 04:18:45CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.3 2019/03/24 09:16:22CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   1st check-in of files from AuxCodeGen 4.0
  CHANGES:                   Revision 1.18 2019/03/22 15:18:51CET Grosu, George (uidl9584) 
  CHANGES:                   review update
  CHANGES:                   Revision 1.17 2019/03/13 12:58:45CET Grosu, George (uidl9584) 
  CHANGES:                   Silent LCFERR
  CHANGES:                   Revision 1.16 2019/02/19 13:10:15CET Grosu, George (uidl9584) 
  CHANGES:                   add Intertask errors. Use algo signal names
  CHANGES:                   Revision 1.15 2019/02/04 16:40:41CET Grosu, George (uidl9584) 
  CHANGES:                   Update LCF_ERR tables
  CHANGES:                   Revision 1.14 2019/01/31 09:17:07CET Grosu, George (uidl9584) 
  CHANGES:                   Add range checks
  CHANGES:                   Revision 1.13 2018/11/15 08:40:20CET Grosu, George (uidl9584) 
  CHANGES:                   ERR: Add Local Freze Frames for Allive checks
  CHANGES:                   ERR: Temporary: No Dem Event for aalive checks
  CHANGES:                   Revision 1.12 2018/11/03 07:39:56CET Grosu, George (uidl9584) 
  CHANGES:                   Move lcf_sen_iface.h back to 01_SourceCode - step 2
  CHANGES:                   Revision 1.11 2018/11/03 06:33:06CET Grosu, George (uidl9584) 
  CHANGES:                   Move lcf_sen_iface.h back to 01_SourceCode - step1
  CHANGES:                   Revision 1.10 2018/10/03 08:57:00CEST Grosu, George (uidl9584) 
  CHANGES:                   Include lcf_sen_iface.h from new location
  CHANGES:                   Revision 1.9 2018/10/02 14:43:26CEST Grosu, George (uidl9584) 
  CHANGES:                   temporary step to move lcf_sen_iface.h
  CHANGES:                   Revision 1.8 2018/09/26 12:27:57CEST Grosu, George (uidl9584) 
  CHANGES:                   Inhibit for the momment
  CHANGES:                   Revision 1.7 2018/09/14 16:16:16CEST Grosu, George (uidl9584) 
  CHANGES:                   Split naming for Error Handler
  CHANGES:                   Revision 1.6 2018/09/11 16:19:19CEST Grosu, George (uidl9584) 
  CHANGES:                   Update error handler
  CHANGES:                   Revision 1.5 2018/08/05 18:08:20CEST Grosu, George (uidl9584) 
  CHANGES:                   Add debug signals
  CHANGES:                   Revision 1.4 2018/05/25 08:07:50CEST Grosu, George (uidl9584) 
  CHANGES:                   update LCFERR
  CHANGES:                   Revision 1.3 2018/05/24 13:06:16CEST Grosu, George (uidl9584) 
  CHANGES:                   Update LCFERR
  CHANGES:                   Revision 1.2 2018/05/23 12:54:47CEST Grosu, George (uidl9584) 
  CHANGES:                   Update LCFERR
  CHANGES:                   Revision 1.1 2018/05/22 16:35:02CEST Grosu, George (uidl9584) 
  CHANGES:                   Reorder files

**************************************************************************** */

/* avoid double inclusion */
#ifndef C_LCFERR_SenCustom_
#define C_LCFERR_SenCustom_

#include "LCFSEN/LCFSEN_data.h"
#include "LCFERR_SenCustom.h"

/* Data Types */

/* configuraiton table for DEM Events */
const uint8 S_ERRSEN_DemArray[C_ERRSEN_DemArraySize] = {
    0x01, /* LCF_SEN_FUSI_ERROR -> ERRSEN_enFUSI */
    0x02, /* LCF_SEN_SERVICE_ERROR -> ERRSEN_enSERVICE */
    0x04, /* LCF_SEN_INTERNAL_ERROR -> ERRSEN_enINTERNAL */
    0x08, /* LCF_SEN_BUS_DATA_ERROR -> ERRSEN_enBUS */
    0x00, /* No DEM event */
    0x00  /* No DEM event */
};

const uint16 S_ERRSEN_DemEvents[C_ERRSEN_NumberOfDemEvents] =
{
    LCF_SEN_FUSI_ERROR, /* ERRSEN_enFUSI */
    LCF_SEN_SERVICE_ERROR, /* ERRSEN_enSERVICE */
    LCF_SEN_INTERNAL_ERROR, /* ERRSEN_enINTERNAL */
    LCF_SEN_BUS_DATA_ERROR /* ERRSEN_enBUS */
};

const LCFERR_ActionTableType_t S_ERRSEN_ActionTable[C_ERRSEN_NumOfActions] = 
{
   {0x00000, ERRSEN_srNoAction},          /* ERRSEN_enNoAction   */
   {0x00001, ERRSEN_srActDegrTJA_LC},     /* ERRSEN_enActDegrTJA_LC */
   {0x00002, ERRSEN_srActDegrLDP},        /* ERRSEN_enActDegrLDP */
   {0x00004, ERRSEN_srActDegrRDP},        /* ERRSEN_enActDegrRDP */
   {0x00008, ERRSEN_srActDegrLDW},        /* ERRSEN_enActDegrLDW */
   {0x00010, ERRSEN_srActDegrTJA_OF},     /* ERRSEN_enActDegrTJA_OF */
   {0x00020, ERRSEN_srActDegrRDW},        /* ERRSEN_enActDegrRDW */
   {0x00040, ERRSEN_srActDegrLDPOC},      /* ERRSEN_enActDegrLDPOC */
   {0x00080, ERRSEN_srActDegrLDWOC},      /* ERRSEN_enActDegrLDWOC */
   {0x00100, ERRSEN_srActDegrALCA},       /* ERRSEN_enActDegrALCA */
   {0x00200, ERRSEN_srActDegrSALC},       /* ERRSEN_enActDegrSALC */
   {0x00400, ERRSEN_srActDegrAOLC},       /* ERRSEN_enActDegrAOLC */
   {0x00800, ERRSEN_srActDegrALL},        /* ERRSEN_enActDegrALL */
   {0x01000, ERRSEN_srActTempErr},        /* ERRSEN_enActTempErr */
   {0x02000, ERRSEN_srActSenOutInvalid},  /* ERRSEN_enActSenOutInv */
   {0x04000, ERRSEN_srActSen2VehInvalid}, /* ERRSEN_enActSen2VehInv */
   {0x08000, ERRSEN_srActPermErr},        /* ERRSEN_enActPermErr */
   {0x10000, ERRSEN_srActRedAvail},       /* ERRSEN_enActRedAvail */
   {0x20000, ERRSEN_srActDegrALLActRedAvail} /* ERRSEN_enActDegrALLActRedAvail */
   
};

/* Errors */
const ERRSEN_ErrCfgType_t S_ERRSEN_ConfigTable[C_ERRSEN_NumOfErrors] = 
{
{(uint8)ERRSEN_enInputsDegradation,0x0010,1,1,3,0,(uint8)ERRSEN_enERRIOSen,0x00000001,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrTJA_LC,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x0011,1,1,3,0,(uint8)ERRSEN_enERRIOSen,0x00000002,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrLDP,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x0012,1,1,3,0,(uint8)ERRSEN_enERRIOSen,0x00000004,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrRDP,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x0013,1,1,3,0,(uint8)ERRSEN_enERRIOSen,0x00000008,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrLDW,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x0014,1,1,3,0,(uint8)ERRSEN_enERRIOSen,0x00000010,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrTJA_OF,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x0015,1,1,3,0,(uint8)ERRSEN_enERRIOSen,0x00000020,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrRDW,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x0016,1,1,3,0,(uint8)ERRSEN_enERRIOSen,0x00000040,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrLDPOC,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x0017,1,1,3,0,(uint8)ERRSEN_enERRIOSen,0x00000080,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrLDWOC,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x0018,1,1,3,0,(uint8)ERRSEN_enERRIOSen,0x00000100,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrALCA,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x0019,1,1,3,0,(uint8)ERRSEN_enERRIOSen,0x00000200,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrSALC,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x001A,1,1,3,0,(uint8)ERRSEN_enERRIOSen,0x00000400,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrAOLC,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enRangeCheckFailure,0x00E0,1,1,3,0,(uint8)ERRSEN_enRangeCheck,0x00000001,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrTJA_LC,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enRangeCheckFailure,0x00E1,1,1,3,0,(uint8)ERRSEN_enRangeCheck,0x00000002,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrLDP,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enRangeCheckFailure,0x00E2,1,1,3,0,(uint8)ERRSEN_enRangeCheck,0x00000004,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrRDP,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enRangeCheckFailure,0x00E3,1,1,3,0,(uint8)ERRSEN_enRangeCheck,0x00000008,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrLDW,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enRangeCheckFailure,0x00E4,1,1,3,0,(uint8)ERRSEN_enRangeCheck,0x00000010,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrTJA_OF,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enRangeCheckFailure,0x00E5,1,1,3,0,(uint8)ERRSEN_enRangeCheck,0x00000020,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrRDW,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enRangeCheckFailure,0x00E6,1,1,3,0,(uint8)ERRSEN_enRangeCheck,0x00000040,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrLDPOC,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enRangeCheckFailure,0x00E7,1,1,3,0,(uint8)ERRSEN_enRangeCheck,0x00000080,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrLDWOC,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enRangeCheckFailure,0x00E8,1,1,3,0,(uint8)ERRSEN_enRangeCheck,0x00000100,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrALCA,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enRangeCheckFailure,0x00E9,1,1,3,0,(uint8)ERRSEN_enRangeCheck,0x00000200,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrSALC,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enRangeCheckFailure,0x00EA,1,1,3,0,(uint8)ERRSEN_enRangeCheck,0x00000400,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrAOLC,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enArchPortStructure,0x0020,1,1,3,0,(uint8)ERRSEN_enSENWrapper,0x00000007,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActTempErr,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x0021,1,1,4,0,(uint8)ERRSEN_enSENWrapper,0x00000008,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActTempErr,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x0022,1,1,4,0,(uint8)ERRSEN_enSENWrapper,0x00000010,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActTempErr,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x0023,1,1,4,0,(uint8)ERRSEN_enSENWrapper,0x00000020,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActTempErr,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x0024,1,1,4,0,(uint8)ERRSEN_enSENWrapper,0x00000040,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActTempErr,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x0025,1,1,4,0,(uint8)ERRSEN_enSENWrapper,0x00000080,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActTempErr,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x0026,1,1,4,0,(uint8)ERRSEN_enSENWrapper,0x00000100,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActTempErr,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x0027,1,1,4,0,(uint8)ERRSEN_enSENWrapper,0x00000200,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActTempErr,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x0028,1,1,4,0,(uint8)ERRSEN_enSENWrapper,0x00000400,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActTempErr,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x0029,1,1,4,0,(uint8)ERRSEN_enSENWrapper,0x00000800,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActTempErr,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x002A,1,1,4,0,(uint8)ERRSEN_enSENWrapper,0x00001000,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActTempErr,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x002B,1,1,4,0,(uint8)ERRSEN_enSENWrapper,0x00002000,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActTempErr,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x002C,1,1,4,0,(uint8)ERRSEN_enSENWrapper,0x00004000,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActTempErr,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x002D,1,1,4,0,(uint8)ERRSEN_enSENWrapper,0x00008000,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActTempErr,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x002E,1,1,3,0,(uint8)ERRSEN_enSENWrapper,0x1FFF0000,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActTempErr,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enArchPortStructure,0x002F,1,1,3,0,(uint8)ERRSEN_enSENWrapper,0x20000000,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActTempErr,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x0030,1,1,1,0,(uint8)ERRSEN_enERRIOAllive,0x00000001,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrALLActRedAvail,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x0031,1,1,1,0,(uint8)ERRSEN_enERRIOAllive,0x00000002,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrALLActRedAvail,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enArchPortStructure,0x0032,1,1,1,0,(uint8)ERRSEN_enERRIOAllive,0x00000004,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrALLActRedAvail,ERRSEN_enNoAction,ERRSEN_enFUSI},
{(uint8)ERRSEN_enInternalErrors,0x0040,1,1,3,0,(uint8)ERRSEN_enABPR,0x00000001,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrALL,ERRSEN_enNoAction,ERRSEN_enINTERNAL},
{(uint8)ERRSEN_enInternalErrors,0x0050,1,1,3,0,(uint8)ERRSEN_enCTRSC,0x00000001,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrALL,ERRSEN_enNoAction,ERRSEN_enINTERNAL},
{(uint8)ERRSEN_enInternalErrors,0x0060,1,1,3,0,(uint8)ERRSEN_enLDPOCSA,0x00000001,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrLDPOC,ERRSEN_enNoAction,ERRSEN_enINTERNAL},
{(uint8)ERRSEN_enInternalErrors,0x0070,1,1,3,0,(uint8)ERRSEN_enLDPSA,0x00000001,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrLDP,ERRSEN_enNoAction,ERRSEN_enINTERNAL},
{(uint8)ERRSEN_enInternalErrors,0x0080,1,1,3,0,(uint8)ERRSEN_enMDCTR,0x00000001,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrALL,ERRSEN_enNoAction,ERRSEN_enINTERNAL},
{(uint8)ERRSEN_enInternalErrors,0x0090,1,1,3,0,(uint8)ERRSEN_enODPR,0x00000001,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrTJA_OF,ERRSEN_enNoAction,ERRSEN_enINTERNAL},
{(uint8)ERRSEN_enInternalErrors,0x00A0,1,1,3,0,(uint8)ERRSEN_enRDPSA,0x00000001,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrRDP,ERRSEN_enNoAction,ERRSEN_enINTERNAL},
{(uint8)ERRSEN_enInternalErrors,0x00B0,1,1,3,0,(uint8)ERRSEN_enTJASA,0x00000001,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrTJA_LC,ERRSEN_enNoAction,ERRSEN_enINTERNAL},
{(uint8)ERRSEN_enInternalErrors,0x00C0,1,1,3,0,(uint8)ERRSEN_enVDPR,0x00000001,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrALL,ERRSEN_enNoAction,ERRSEN_enINTERNAL},
{(uint8)ERRSEN_enInputsDegradation,0x00D0,1,1,3,0,(uint8)ERRSEN_enVehTask,0x00000001,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrTJA_LC,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x00D1,1,1,3,0,(uint8)ERRSEN_enVehTask,0x00000002,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrLDP,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x00D2,1,1,3,0,(uint8)ERRSEN_enVehTask,0x00000004,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrRDP,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x00D3,1,1,3,0,(uint8)ERRSEN_enVehTask,0x00000008,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrLDW,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x00D4,1,1,3,0,(uint8)ERRSEN_enVehTask,0x00000010,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrTJA_OF,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x00D5,1,1,3,0,(uint8)ERRSEN_enVehTask,0x00000020,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrRDW,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x00D6,1,1,3,0,(uint8)ERRSEN_enVehTask,0x00000040,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrLDPOC,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x00D7,1,1,3,0,(uint8)ERRSEN_enVehTask,0x00000080,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrLDWOC,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x00D8,1,1,3,0,(uint8)ERRSEN_enVehTask,0x00000100,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrALCA,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x00D9,1,1,3,0,(uint8)ERRSEN_enVehTask,0x00000200,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrSALC,ERRSEN_enNoAction,ERRSEN_enNoDemEvent},
{(uint8)ERRSEN_enInputsDegradation,0x00DA,1,1,3,0,(uint8)ERRSEN_enVehTask,0x00000400,LCFERR_REST_IMMEDIATELY,ERRSEN_enNoAction,ERRSEN_enNoAction,ERRSEN_enActDegrAOLC,ERRSEN_enNoAction,ERRSEN_enNoDemEvent}

};

/* Parameters */
#if ((defined PC_SIM) && (!defined CM_SIM))
volatile uint8 P_ERRIOSEN_EnableChecks_btf = 0x00u;
#else
volatile uint8 P_ERRIOSEN_EnableChecks_btf = 0xFEu;/* ERRIO_CHECK_ NORM = 0x01, VEHDYN = 0x02, VEHSIGADD = 0x04, VEHSIGMAIN = 0x08, SIGHEADER = 0x10 , ALLIVE = 0x20 */
#endif

/* Actions */
void ERRSEN_srNoAction(void)
{
    /* Do nothing for this action */
}

void ERRSEN_srActDegrTJA_LC(void)
{
    SET_ERRIOSEN_ErrStateArray(LCF_ERRHNDL_TJA_LC, LCF_IS_ERROR);
}

void ERRSEN_srActDegrLDP(void)
{
	SET_ERRIOSEN_ErrStateArray(LCF_ERRHNDL_LDP, LCF_IS_ERROR);
}

void ERRSEN_srActDegrRDP(void)
{
	SET_ERRIOSEN_ErrStateArray(LCF_ERRHNDL_RDP, LCF_IS_ERROR);
}

void ERRSEN_srActDegrLDW(void)
{
	SET_ERRIOSEN_ErrStateArray(LCF_ERRHNDL_LDW, LCF_IS_ERROR);
}

void ERRSEN_srActDegrTJA_OF(void)
{
	SET_ERRIOSEN_ErrStateArray(LCF_ERRHNDL_TJA_OF, LCF_IS_ERROR);
}

void ERRSEN_srActDegrRDW(void)
{
	SET_ERRIOSEN_ErrStateArray(LCF_ERRHNDL_RDW, LCF_IS_ERROR);
}

void ERRSEN_srActDegrLDPOC(void)
{
	SET_ERRIOSEN_ErrStateArray(LCF_ERRHNDL_LDPOC, LCF_IS_ERROR);
}

void ERRSEN_srActDegrLDWOC(void)
{
	SET_ERRIOSEN_ErrStateArray(LCF_ERRHNDL_LDWOC, LCF_IS_ERROR);
}

void ERRSEN_srActDegrALCA(void)
{
	SET_ERRIOSEN_ErrStateArray(LCF_ERRHNDL_ALCA, LCF_IS_ERROR);
}

void ERRSEN_srActDegrSALC(void)
{
	SET_ERRIOSEN_ErrStateArray(LCF_ERRHNDL_SALC, LCF_IS_ERROR);
}

void ERRSEN_srActDegrAOLC(void)
{
	SET_ERRIOSEN_ErrStateArray(LCF_ERRHNDL_AOLC, LCF_IS_ERROR);
}

void ERRSEN_srActDegrALL(void)
{
	uint8 i;
	for(i=0;i<(uint8)ERRIOSEN_CHECKED_FUNCTIONS_NO;i++)
	{
		SET_ERRIOSEN_ErrStateArray(i, LCF_IS_ERROR);
	}
}

void ERRSEN_srActTempErr(void)
{
    /* Set state to Temp Error */
    if(pLcfSenProPorts != NULL)
    {
		SET_S_LCFSND_SenAlgoCompState(COMP_STATE_TEMPORARY_ERROR);
    }
}

void ERRSEN_srActRedAvail(void)
{
    /* Set state to Temp Error */
    if(pLcfSenProPorts != NULL)
    {
		SET_S_LCFSND_SenAlgoCompState(COMP_STATE_REDUCED_AVAILABILITY);
    }
}



void ERRSEN_srActPermErr(void)
{
	/* Transmit to Veh the disaster */
	SET_ERRIOSEN_ErrStateArray(LCF_ERRHNDL_LATDMC, LCF_IS_ERROR);
    /* Set state to Temp Error */
    if(pLcfSenProPorts != NULL)
    {
		SET_S_LCFSND_SenAlgoCompState(COMP_STATE_PERMANENT_ERROR);
    }
}
 
void ERRSEN_srActDegrALLActRedAvail(void)
{
    ERRSEN_srActDegrALL();
	ERRSEN_srActRedAvail();
}
 

void ERRSEN_srActSenOutInvalid(void)
{
    /* Set state to Temp Error */
    if(pLcfSenProPorts != NULL)
    {
        if(pLcfSenProPorts->pLcfSenOutputData != NULL)
        {
			SET_S_LCFSND_SenOutSigStatus(AL_SIG_STATE_INVALID);
            /* L3D_ALGO)21733 : if an output is Invalid, then component state is TempError */
            ERRSEN_srActTempErr();
        }
    }
}

void ERRSEN_srActSen2VehInvalid(void)
{
    /* Set state to Temp Error */
    if(pLcfSenProPorts != NULL)
    {
        if(pLcfSenProPorts->pLcfSenOutputToVehData != NULL)
        {
			SET_S_LCFSND_Sen2VehSigStatus(AL_SIG_STATE_INVALID);
            /* L3D_ALGO)21733 : if an output is Invalid, then component state is TempError */
            ERRSEN_srActTempErr();
        }
    }
}


void LCFERR_SenSetSilentEventStatus(uint16 event, uint8 status)
{
	/* PRQA S 2981 1 */
	uint8 DemEvents = 0u;
	switch(event)
	{
		case LCF_SEN_FUSI_ERROR:
		{
			DemEvents = 1;
			break;
		}
		case LCF_SEN_SERVICE_ERROR:
		{
			DemEvents = 2;
			break;
		}
		case LCF_SEN_INTERNAL_ERROR:
		{
			DemEvents = 4;
			break;
		}
		case LCF_SEN_BUS_DATA_ERROR:
		{
			DemEvents = 8;
			break;
		}
		default:
		{
			DemEvents = 16;
			break;
		}
	}
	if(status == (uint8)DEM_EVENT_STATUS_FAILED)
	{
		S_D_LCFERR_DemEvents_btf |= DemEvents;
	}
	else
	{
		S_D_LCFERR_DemEvents_btf &= ~DemEvents;
	}
}

void ERRSEN_CustomErrReaction(void)
{
#if LCFERR_SEN_SILENT == 1
	SET_S_LCFSND_SenAlgoCompState(0);
	SET_S_LCFSND_SenOutSigStatus(0);
	SET_S_LCFSND_Sen2VehSigStatus(0);
#endif

}



#endif /* C_LCFERR_SenCustom_ */
