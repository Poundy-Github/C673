/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_fct

  MODULNAME:            sim_adapter_fct.cpp

  DESCRIPTION:          

  AUTHOR:               Ovidiu Raicu

  CREATION DATE:        23.03.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_adapter_main.cpp  $
  CHANGES:              Revision 1.1 2021/12/13 17:20:12CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:14:44CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/project.pj
  CHANGES:              Revision 1.49 2017/03/23 13:02:42CET Cretu, Teodora (CretuT) 
  CHANGES:              Add map for "DWInputCustom"
  CHANGES:              Revision 1.48 2017/03/22 12:46:43CET Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:              [ARS5xx/SRR5xx]  Remove unused b_Changed flag from interface to RHC
  CHANGES:              Revision 1.47 2017/03/22 12:02:37CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Minor corrections
  CHANGES:              Revision 1.46 2017/01/24 14:58:14CET Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:              - Add "frsBSWCtrlData_t" adapter for FRS
  CHANGES:              - Add map for "RSP_t_ClusterListFS"
  CHANGES:              - Add map for "RSP_t_ClusterListNS"
  CHANGES:              - Add map for "ALN_AzimuthCorrection"
  CHANGES:              Revision 1.45 2017/01/13 13:30:28CET Cretu, Teodora (CretuT) 
  CHANGES:              Add Init_Road adapter for RT28
  CHANGES:              Revision 1.44 2016/10/17 11:51:52CEST Kubera, David (kuberad) 
  CHANGES:              + add #include "sim_conv_em_objectlist_base_cam.h" (EUNCAP18)
  CHANGES:              Revision 1.42 2016/05/30 15:38:20CEST Kubera, David (kuberad) 
  CHANGES:              extend sim-adapter for renault project:
  CHANGES:              add camera object list from Valeo (Mobileye) camera
  CHANGES:              Revision 1.41 2016/04/27 14:34:23CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              AL_CRT_ARS400_01.01.48_INT-1
  CHANGES:              Revision 1.40 2016/02/16 07:42:35CET Schluttig, Jakob (uidv7098) 
  CHANGES:              + aln_siminit
  CHANGES:              Revision 1.39 2016/01/14 07:29:23CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + em\sim_conv_em_objectlist_mcam_tja.cpp/h
  CHANGES:              Revision 1.38 2015/10/13 16:19:20CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + sim_conv_head_input_generic.cpp/h
  CHANGES:              --- Added comments ---  berndtt1 [Oct 14, 2015 8:35:14 AM CEST]
  CHANGES:              Change Package : 385987:1 http://mks-psad:7002/im/viewissue?selection=385987
  CHANGES:              Revision 1.37 2015/07/07 13:58:40CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + preclusterlistheader
  CHANGES:              --- Added comments ---  berndtt1 [Jul 7, 2015 1:59:30 PM CEST]
  CHANGES:              Change Package : 352029:1 http://mks-psad:7002/im/viewissue?selection=352029
  CHANGES:              Revision 1.36 2015/06/24 07:26:37CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + #include "sim_conv_rsp1_noise.h"
  CHANGES:              --- Added comments ---  berndtt1 [Jun 24, 2015 10:46:37 AM CEST]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.35 2015/05/22 11:08:44CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + dtbremsung
  CHANGES:              --- Added comments ---  berndtt1 [May 29, 2015 10:12:26 AM CEST]
  CHANGES:              Change Package : 276620:4 http://mks-psad:7002/im/viewissue?selection=276620
  CHANGES:              Revision 1.34 2015/02/26 07:03:57CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + sim_conv_em_objectlist_custom.cpp
  CHANGES:              + sim_conv_perfdegr.cpp
  CHANGES:              --- Added comments ---  berndtt1 [Feb 26, 2015 9:56:55 AM CET]
  CHANGES:              Change Package : 276620:4 http://mks-psad:7002/im/viewissue?selection=276620
  CHANGES:              Revision 1.33 2015/01/30 11:12:50CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + awv adapter
  CHANGES:              --- Added comments ---  berndtt1 [Feb 17, 2015 1:29:16 PM CET]
  CHANGES:              Change Package : 276620:4 http://mks-psad:7002/im/viewissue?selection=276620
  CHANGES:              Revision 1.32 2015/01/27 09:27:03CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + sim_conv_productionparameter
  CHANGES:              --- Added comments ---  berndtt1 [Jan 27, 2015 10:28:33 AM CET]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.31 2014/12/12 11:28:54CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + sim_adapter_cfg.h
  CHANGES:              --- Added comments ---  berndtt1 [Dec 12, 2014 11:30:49 AM CET]
  CHANGES:              Change Package : 221167:44 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.30 2014/12/09 17:46:10CET Ungvary, Gergely (ungvaryg) 
  CHANGES:              Add VehSig conversion class needed by FCT
  CHANGES:              --- Added comments ---  ungvaryg [Dec 9, 2014 5:46:10 PM CET]
  CHANGES:              Change Package : 286888:1 http://mks-psad:7002/im/viewissue?selection=286888
  CHANGES:              Revision 1.29 2014/12/09 16:20:44CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + CConvEmObjectListCamVW Adapter
  CHANGES:              --- Added comments ---  berndtt1 [Dec 9, 2014 5:40:15 PM CET]
  CHANGES:              Change Package : 221167:43 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.28 2014/12/05 10:41:24CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + NaviInputData adapter
  CHANGES:              --- Added comments ---  berndtt1 [Dec 5, 2014 10:42:06 AM CET]
  CHANGES:              Change Package : 221167:17 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.27 2014/12/02 10:02:58CET Schluttig, Jakob (uidv7098) 
  CHANGES:              added ALN_Monitoring twice with different adapter name as used in FCT Simulator
  CHANGES:              --- Added comments ---  uidv7098 [Dec 2, 2014 10:02:58 AM CET]
  CHANGES:              Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
  CHANGES:              Revision 1.26 2014/10/09 14:44:56CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + m_ConvName2FactMap["FCTVehCustomInput_t"] = CreateFCTVehCustomInputConvClass;
  CHANGES:              --- Added comments ---  berndtt1 [Oct 9, 2014 4:27:41 PM CEST]
  CHANGES:              Change Package : 270187:1 http://mks-psad:7002/im/viewissue?selection=270187
  CHANGES:              Revision 1.25 2014/10/07 09:17:09CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + rsp2_noise.cpp/h
  CHANGES:              --- Added comments ---  berndtt1 [Oct 7, 2014 12:40:02 PM CEST]
  CHANGES:              Change Package : 221167:34 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.24 2014/09/29 15:30:39CEST Schluttig, Jakob (uidv7098) 
  CHANGES:              added converter for "ALN_Monitoring_t" ; sorted includes
  CHANGES:              --- Added comments ---  uidv7098 [Sep 29, 2014 3:30:39 PM CEST]
  CHANGES:              Change Package : 264784:1 http://mks-psad:7002/im/viewissue?selection=264784
  CHANGES:              Revision 1.23 2014/09/03 15:45:31CEST Sinnstein, Simon (uidw0203) 
  CHANGES:              Add adapter for FCTVehCustomInput Port
  CHANGES:              --- Added comments ---  uidw0203 [Sep 3, 2014 3:45:32 PM CEST]
  CHANGES:              Change Package : 198893:2 http://mks-psad:7002/im/viewissue?selection=198893
  CHANGES:              Revision 1.22 2014/08/21 07:48:21CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Adaption of RSP1_Nacom
  CHANGES:              --- Added comments ---  berndtt1 [Aug 22, 2014 5:04:06 PM CEST]
  CHANGES:              Change Package : 221167:28 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.21 2014/05/19 10:43:47CEST Stolle, Ulf Eike (uidv1902) 
  CHANGES:              add RoadBeamList and RSP1_syncref adapter
  CHANGES:              --- Added comments ---  uidv1902 [May 19, 2014 10:43:48 AM CEST]
  CHANGES:              Change Package : 226364:3 http://mks-psad:7002/im/viewissue?selection=226364
  CHANGES:              Revision 1.20 2014/05/08 09:16:02CEST Schluttig, Jakob (uidv7098) 
  CHANGES:              added ALN_t_NVM adapter
  CHANGES:              --- Added comments ---  uidv7098 [May 8, 2014 9:16:03 AM CEST]
  CHANGES:              Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
  CHANGES:              Revision 1.19 2014/04/24 19:00:46CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Add MFC4T0 MCAM conversion class
  CHANGES:              --- Added comments ---  ungvaryg [Apr 24, 2014 7:00:46 PM CEST]
  CHANGES:              Change Package : 228642:1 http://mks-psad:7002/im/viewissue?selection=228642
  CHANGES:              Revision 1.18 2014/04/11 12:43:03CEST Diewald, Fabian (uidt8878) 
  CHANGES:              added ALN_SimInitMon adapter
  CHANGES:              --- Added comments ---  uidt8878 [Apr 11, 2014 12:43:03 PM CEST]
  CHANGES:              Change Package : 230351:2 http://mks-psad:7002/im/viewissue?selection=230351
  CHANGES:              Revision 1.17 2014/03/27 17:58:53CET Ungvary, Gergely (ungvaryg) 
  CHANGES:              Add alternative spellings for data types as modified by MFC4xx (to be able to use same sim_swc_fct.cpp revision)
  CHANGES:              --- Added comments ---  ungvaryg [Mar 27, 2014 5:58:54 PM CET]
  CHANGES:              Change Package : 227793:1 http://mks-psad:7002/im/viewissue?selection=227793
  CHANGES:              Revision 1.16 2014/03/14 09:41:07CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + sim_conv_aln_syncref.cpp/h
  CHANGES:              --- Added comments ---  berndtt1 [Mar 14, 2014 9:42:29 AM CET]
  CHANGES:              Change Package : 221167:2 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.15 2014/03/13 11:26:57CET Ungvary, Gergely (ungvaryg) 
  CHANGES:              Split ARS4B0 SCAM/ARS4T0 MCAM type names for conversion classes (do not use SCAM conversion class for Toyota)
  CHANGES:              --- Added comments ---  ungvaryg [Mar 13, 2014 11:26:57 AM CET]
  CHANGES:              Change Package : 224959:2 http://mks-psad:7002/im/viewissue?selection=224959
  CHANGES:              Revision 1.14 2014/01/30 15:22:30CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              Add VehDyn_t and VehPar_t 
  CHANGES:              cause they are renamed in VDY simulator
  CHANGES:              --- Added comments ---  berndtt1 [Jan 30, 2014 3:42:57 PM CET]
  CHANGES:              Change Package : 208935:13 http://mks-psad:7002/im/viewissue?selection=208935
  CHANGES:              Revision 1.13 2014/01/09 15:30:29CET Both, Jens (uidg3187) 
  CHANGES:              Add LongCtrlInput adapter class
  CHANGES:              --- Added comments ---  uidg3187 [Jan 9, 2014 3:30:29 PM CET]
  CHANGES:              Change Package : 207936:1 http://mks-psad:7002/im/viewissue?selection=207936
  CHANGES:              Revision 1.12 2013/10/31 15:29:12CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              Added sim_conv_em_objectlist_scam.cpp/h
  CHANGES:              --- Added comments ---  berndtt1 [Nov 4, 2013 8:05:45 AM CET]
  CHANGES:              Change Package : 193430:6 http://mks-psad:7002/im/viewissue?selection=193430
  CHANGES:              Revision 1.11 2013/10/22 15:02:27CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Added ALNAzimuthCorrection
  CHANGES:              --- Added comments ---  berndtt1 [Oct 22, 2013 3:04:22 PM CEST]
  CHANGES:              Change Package : 193430:4 http://mks-psad:7002/im/viewissue?selection=193430
  CHANGES:              Revision 1.10 2013/10/02 17:23:32CEST Olejua Ortiz-EXT, Manuel Leonardo (uidv5395) 
  CHANGES:              Added FCTSenErrorOut, VdyErrors and VdyCtrlData
  CHANGES:              --- Added comments ---  uidv5395 [Oct 2, 2013 5:23:32 PM CEST]
  CHANGES:              Change Package : 192960:4 http://mks-psad:7002/im/viewissue?selection=192960
  CHANGES:              Revision 1.9 2013/09/19 15:23:32CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Added new converter sim_conv_aln_rtebswout
  CHANGES:              --- Added comments ---  berndtt1 [Sep 19, 2013 3:30:55 PM CEST]
  CHANGES:              Change Package : 193430:1 http://mks-psad:7002/im/viewissue?selection=193430
  CHANGES:              Revision 1.8 2013/09/16 15:56:34CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Added interface_rsp_specbeamcmplxlist and sim_conv_rsp_specbeamcmplxlist
  CHANGES:              --- Added comments ---  berndtt1 [Sep 18, 2013 4:53:15 PM CEST]
  CHANGES:              Change Package : 193430:1 http://mks-psad:7002/im/viewissue?selection=193430
  CHANGES:              Revision 1.7 2013/08/29 09:37:15CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Added adapter for aln, em, rhc and rsp
  CHANGES:              AlnRteBswInput, BSW_EMCtrlData, RHC_BSWIn, RSP_InputActl
  CHANGES:              --- Added comments ---  berndtt1 [Aug 30, 2013 4:49:44 PM CEST]
  CHANGES:              Change Package : 176344:14 http://mks-psad:7002/im/viewissue?selection=176344
  CHANGES:              Revision 1.6 2013/08/02 19:19:03CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Add VehDyn/VehPar/RHC Adj HW Cfg/RSP2 Cluster list adapter classes
  CHANGES:              --- Added comments ---  ungvaryg [Aug 2, 2013 7:19:03 PM CEST]
  CHANGES:              Change Package : 190143:3 http://mks-psad:7002/im/viewissue?selection=190143
  CHANGES:              Revision 1.5 2013/06/26 10:02:02CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Add conversion class for BSW_s_AlgoParameters
  CHANGES:              --- Added comments ---  ungvaryg [Jun 26, 2013 10:02:02 AM CEST]
  CHANGES:              Change Package : 179559:3 http://mks-psad:7002/im/viewissue?selection=179559
  CHANGES:              Revision 1.4 2013/06/19 16:54:58CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Add conversion class for curve observer initialization data
  CHANGES:              --- Added comments ---  ungvaryg [Jun 19, 2013 4:54:58 PM CEST]
  CHANGES:              Change Package : 179559:3 http://mks-psad:7002/im/viewissue?selection=179559
  CHANGES:              Revision 1.3 2013/05/21 18:02:44CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Add preliminary FCT conversion classes (currenly only copies of last ARS3xx conversion class)
  CHANGES:              --- Added comments ---  ungvaryg [May 21, 2013 6:02:45 PM CEST]
  CHANGES:              Change Package : 172401:1 http://mks-psad:7002/im/viewissue?selection=172401
  CHANGES:              Revision 1.2 2013/03/28 15:14:50CET Kaelberer, Stephan (uidu2442) 
  CHANGES:              added factory for RSP_PreClusterList
  CHANGES:              --- Added comments ---  uidu2442 [Mar 28, 2013 3:14:50 PM CET]
  CHANGES:              Change Package : 172401:2 http://mks-psad:7002/im/viewissue?selection=172401
  CHANGES:              Revision 1.1 2013/02/07 13:55:57CET Ungvary, Gergely (ungvaryg) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/project.pj
  CHANGES:              Revision 1.11 2012/01/16 09:35:32CET Apel, Norman (apeln) 
  CHANGES:              add new Port for SimInit of CPTrajState
  CHANGES:              --- Added comments ---  apeln [Jan 16, 2012 9:35:33 AM CET]
  CHANGES:              Change Package : 93699:1 http://mks-psad:7002/im/viewissue?selection=93699
  CHANGES:              Revision 1.10 2011/06/27 12:00:00CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Add ALN_S_Monitoring_t conversion class implementation
  CHANGES:              --- Added comments ---  ungvaryg [Jun 27, 2011 12:00:01 PM CEST]
  CHANGES:              Change Package : 69654:1 http://mks-psad:7002/im/viewissue?selection=69654
  CHANGES:              Revision 1.9 2011/04/13 18:00:56CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Add support for adapter class for BSW algo parameters
  CHANGES:              --- Added comments ---  ungvaryg [Apr 13, 2011 6:00:56 PM CEST]
  CHANGES:              Change Package : 63692:1 http://mks-psad:7002/im/viewissue?selection=63692
  CHANGES:              Revision 1.8 2011/03/22 09:51:49CET Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Add factory function for ME input data
  CHANGES:              --- Added comments ---  ungvaryg [Mar 22, 2011 9:51:49 AM CET]
  CHANGES:              Change Package : 59359:3 http://mks-psad:7002/im/viewissue?selection=59359
  CHANGES:              Revision 1.7 2011/03/02 16:44:04CET Thomas Diepolder (diepoldert) 
  CHANGES:              "head input custom" and "dim_input_custom" interface added
  CHANGES:              --- Added comments ---  diepoldert [Mar 2, 2011 4:44:05 PM CET]
  CHANGES:              Change Package : 59660:2 http://mks-psad:7002/im/viewissue?selection=59660
  CHANGES:              Revision 1.6 2010/10/09 11:35:37CEST Gergely Ungvary (ungvaryg) 
  CHANGES:              Update name of RSP context data adapter class due to sharing of converter class between EM & FCT (minimize necessary
  CHANGES:              effort to maintain adapters, do code adaption only once)
  CHANGES:              --- Added comments ---  ungvaryg [Oct 9, 2010 11:35:38 AM CEST]
  CHANGES:              Change Package : 52823:2 http://mks-psad:7002/im/viewissue?selection=52823
  CHANGES:              Revision 1.5 2010/10/08 12:44:15CEST Gergely Ungvary (ungvaryg) 
  CHANGES:              Add curve observer initialization converter class
  CHANGES:              Modify to use map and factor methods for each port
  CHANGES:              --- Added comments ---  ungvaryg [Oct 8, 2010 12:44:15 PM CEST]
  CHANGES:              Change Package : 48401:1 http://mks-psad:7002/im/viewissue?selection=48401
  CHANGES:              Revision 1.4 2010/07/23 13:53:29CEST Mihai Anghel (anghelm) 
  CHANGES:              created converter for "EM_COD_Output" and "EM_CLD_Output"
  CHANGES:              --- Added comments ---  AnghelM [Jul 23, 2010 1:53:29 PM CEST]
  CHANGES:              Change Package : 47849:1 http://mks-psad:7002/im/viewissue?selection=47849
  CHANGES:              Revision 1.3 2010/06/16 15:36:50CEST gungvary 
  CHANGES:              Add FCTCustomInput conversion adapter & a map for looking up names to factory functions for conversion classes
  CHANGES:              --- Added comments ---  gungvary [2010/06/16 13:36:50Z]
  CHANGES:              Change Package : 39685:3 http://LISS014:6001/im/viewissue?selection=39685
  CHANGES:              Revision 1.2 2010/06/09 08:15:04CEST Ovidiu Raicu (oraicu) 
  CHANGES:              Added DimInputGeneric conversion.
  CHANGES:              Updated path's to rte folders.
  CHANGES:              --- Added comments ---  oraicu [2010/06/09 06:15:05Z]
  CHANGES:              Change Package : 45328:1 http://LISS014:6001/im/viewissue?selection=45328
  CHANGES:              Revision 1.1 2010/03/26 09:56:39CET Ovidiu Raicu (oraicu) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/03_Workspace/algo/fct_sim/fct_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "stdafx.h"
#include "sim_adapter_cfg.h"
#include "sim_adapter_main.h"

#include "sim_conv_rhc_adj_hw_config.h"
#include "sim_conv_rhc_bswin.h"

#include "sim_conv_FPGA_StaticPeakList.h"

#include "sim_conv_rsp_inputactl.h"
#include "sim_conv_rsp1_preclusterlist.h"
#include "sim_conv_rsp1_preclusterlistheader.h"
#include "sim_conv_rsp1_roadbeamlist.h"
#include "sim_conv_rsp1_syncref.h"
#include "sim_conv_rsp1_nacom.h"
#include "sim_conv_rsp1_noise.h"
#include "sim_conv_rsp_specbeamcmplxlist.h"
#include "sim_conv_rsp1_peaklist.h"

#include "sim_conv_rsp2_clusterlist.h"
#include "sim_conv_rsp2_noise.h"

#include "sim_conv_vdy_input_data_veh_sig.h"
#include "sim_conv_VdyCtrlData.h"
#include "sim_conv_vdyerrors.h"
#include "sim_conv_veh_dyn.h"
#include "sim_conv_veh_par.h"

#include "sim_conv_aln_rtebswin.h"
#include "sim_conv_aln_rtebswout.h"
#include "sim_conv_aln_azimuthcorrection.h"
#include "sim_conv_aln_syncref.h"
#include "sim_conv_aln_siminitmon.h"
#include "sim_conv_aln_siminit.h"
#include "sim_conv_aln_monitoring.h"
#include "sim_conv_aln_rtenvm.h"
#include "sim_conv_aln_rtereqhwconfig.h"

#include "sim_conv_em_bswemctrldata.h"
#include "sim_conv_em_objectlist_cam_vw.h"
#include "sim_conv_em_objectlist_scam.h"
#include "sim_conv_em_objectlist_mcam.h"
#include "sim_conv_em_objectlist_mcam_rt.h"
#include "sim_conv_em_objectlist_mcam_tja.h"
#include "sim_conv_em_objectlist_base_cam.h"
#include "sim_conv_productionparameter.h"

#include "sim_conv_bswalgo_param.h"

#include "sim_conv_acc_lever.h"
#include "sim_conv_long_ctrl_input.h"
#include "sim_conv_road.h"
#include "sim_conv_cp_traj_state.h"
#include "sim_conv_dim_input_custom.h"
#include "sim_conv_dim_input_generic.h"
#include "sim_conv_head_input_custom.h"
#include "sim_conv_head_input_generic.h"
#include "sim_conv_fct_cam_lane_input_data.h"
#include "sim_conv_fct_custom_input.h"
#include "sim_conv_si_curveobs_init.h"
#include "sim_conv_fct_sen_error_out.h"
#include "sim_conv_fct_veh_custom_input.h"
#include "sim_conv_navi_input_data.h"
#include "sim_conv_DW_input_custom.h"

#include "sim_conv_awvw_dtkodierungfkt.h"
#include "sim_conv_fahrpedalwert.h"
#include "sim_conv_dtkvpar.h"
#include "sim_conv_dtffipar.h"
#include "sim_conv_em_objectlist_custom.h"
#include "sim_conv_perfdegr.h"
#include "sim_conv_bremsung.h"

#include "sim_conv_frs_frsbswctrldata.h"

//
// Internal hidden class providing factory of conversion instances
//
class CSimAdapterMain::__CSimAdapterFactory
{
  typedef IConverter* (*tpfConverterFactory)(void);
  typedef std::map<std::string, tpfConverterFactory> tConvNameToFactoryMap;

  tConvNameToFactoryMap m_ConvName2FactMap;
public:
  __CSimAdapterFactory(void)
  {
    m_ConvName2FactMap["FPGA_StaticPeakList"]   = CreateFPGAStaticPeakListConvClass;
    m_ConvName2FactMap["RSP_PreClusterList"]    = CreateRSP1PreClusterListConvClass;
    m_ConvName2FactMap["RSP_PreClusterListHead"]= CreateRSP1PreClusterListHeaderConvClass;
    // FCT conversion classes
    m_ConvName2FactMap["AccLeverInput"]         = CreateAccLeverConvClass;
    m_ConvName2FactMap["AccLeverInput_t"]       = CreateAccLeverConvClass;
    m_ConvName2FactMap["LongCtrlInput"]         = CreateLongCtrlInputConvClass;
    m_ConvName2FactMap["LongCtrlInput_t"]       = CreateLongCtrlInputConvClass;
    m_ConvName2FactMap["FctVehCustomInput"]     = CreateFCTVehCustomInputConvClass;
    m_ConvName2FactMap["FCTVehCustomInput_t"]   = CreateFCTVehCustomInputConvClass;
    m_ConvName2FactMap["Init_Road"]             = CreateRoadConvInstance;
    m_ConvName2FactMap["Init_Road_t"]           = CreateRoadConvInstance;
    // @todo: add FCTCtrlData_t, EM_t_GenObjectList, EM_t_ObjectList_Custom, EM_t_ARSObjectList, EM_t_CamObjectList,
    // MovingObjectTraces_t, ObjectTraceList_t, PerfDegr_t, PerfDegrExtInput_t, FCTAccPickupRange_t,
    // acc_output_data_t
    m_ConvName2FactMap["SICPStateInit"]         = CreateCpTrajStateConvInstance;
    m_ConvName2FactMap["DIMInputCustom"]        = CreateDimInputCustomConvInstance;
    m_ConvName2FactMap["DIMInputCustom_t"]      = CreateDimInputCustomConvInstance;
    m_ConvName2FactMap["DIMInputGeneric"]       = CreateDimInputGenericConvInstance;
    m_ConvName2FactMap["DIMInputGeneric_t"]     = CreateDimInputGenericConvInstance;
    m_ConvName2FactMap["HEADInputCustom"]       = CreateHeadInputCustomConvInstance;
    m_ConvName2FactMap["HEADInputCustom_t"]     = CreateHeadInputCustomConvInstance;
    m_ConvName2FactMap["HEADInputGeneric"]      = CreateHeadInputGenericConvInstance;
    m_ConvName2FactMap["HEADInputGeneric_t"]    = CreateHeadInputGenericConvInstance;
    // @todo: HEADInputGeneric_t
    m_ConvName2FactMap["FCTCustomInput"]        = CreateFctCustomInputConvInstance;
    m_ConvName2FactMap["FCTCustomInput_t"]      = CreateFctCustomInputConvInstance;
    m_ConvName2FactMap["SICurveObsInit"]        = CreateSICuveObsInitConvInstance;
    m_ConvName2FactMap["BSWAlgoParameters"]     = CreateBswAlgoParamConverter;
    m_ConvName2FactMap["BSW_s_AlgoParameters_t"]= CreateBswAlgoParamConverter;
    m_ConvName2FactMap["FctSenErrorOut"]        = CreateFctSenErrorOutConvInstance;
    m_ConvName2FactMap["FCTSenErrorOut_t"]      = CreateFctSenErrorOutConvInstance;
    m_ConvName2FactMap["t_NaviInputData"]       = CreateNaviInputDataConvInstance;
    m_ConvName2FactMap["t_CamLaneInputData"]    = CreateFctCamLaneInputDataConvInstance;
    m_ConvName2FactMap["DWInputCustom"]         = CreateDWInputCustomConvClass;
    m_ConvName2FactMap["FCTDWInputCustom_t"]    = CreateDWInputCustomConvClass;
    // VDY conversion classes
    m_ConvName2FactMap["VehSig"]                = CreateVehSigConvClass;
    m_ConvName2FactMap["VehSig_t"]              = CreateVehSigConvClass;
    m_ConvName2FactMap["VehDyn"]                = CreateVehDynConvClass;
    m_ConvName2FactMap["VehDyn_t"]              = CreateVehDynConvClass;
    m_ConvName2FactMap["VehPar"]                = CreateVehParConvClass;
    m_ConvName2FactMap["VehPar_t"]              = CreateVehParConvClass;
    m_ConvName2FactMap["VdyErrors"]             = CreateVdyErrorsConvClass;
    m_ConvName2FactMap["VdyCtrlData"]           = CreateVdyCtrlDataConvClass;
    // RSP1 conversion classes
    m_ConvName2FactMap["RSPNacom"]              = CreateRSPNacomConvClass;
    m_ConvName2FactMap["RSP1_t_Noise"]          = CreateRSP1NoiseConvClass;
    m_ConvName2FactMap["RSP_t_PeakList"]        = CreateRsp1PeakListConvInstance;
    // RSP2 conversion classes
    m_ConvName2FactMap["RSPClusterListFar"]     = CreateRsp2CluListConvClass;
    m_ConvName2FactMap["RSP_t_ClusterListFS"]   = CreateRsp2CluListConvClass;
    m_ConvName2FactMap["RSPClusterListNear"]    = CreateRsp2CluListConvClass;
    m_ConvName2FactMap["RSP_t_ClusterListNS"]   = CreateRsp2CluListConvClass;
    m_ConvName2FactMap["RSP_InputActl"]         = CreateRspInputActlConvClass;
    m_ConvName2FactMap["RSP_SpecBeamCmplxList"] = CreateRSPSpecBeamCmplxListConvClass;
    m_ConvName2FactMap["RSP_RoadBeam"]          = CreateRsp1RoadBeamListConvClass;
    m_ConvName2FactMap["RSP1_SyncRef"]          = CreateRsp1SyncRefConvClass;
    m_ConvName2FactMap["RSP2_t_Noise"]          = CreateRSP2NoiseConvClass;
    // RHC conversion classes
    m_ConvName2FactMap["RHC_t_AdjHwConfig"]     = CreateRhcAdjHwConfigConvClass;
    m_ConvName2FactMap["RHCAdjHwConfigFar"]     = CreateRhcAdjHwConfigConvClass;
    m_ConvName2FactMap["RHCAdjHwConfigNear"]    = CreateRhcAdjHwConfigConvClass;
    m_ConvName2FactMap["RHC_BSWIn"]             = CreateRhcBswInConvClass;
    // ALN conversion classes
    m_ConvName2FactMap["AlnRteBswInput"]        = CreateAlnRteBswInConvClass;
    m_ConvName2FactMap["AlnRteBswOutput"]       = CreateAlnBswOutConvClass;
    m_ConvName2FactMap["ALNAzimuthCorrection"]  = CreateAlnAzimuthCorrectionConvClass;
    m_ConvName2FactMap["ALN_AzimuthCorrection"] = CreateAlnAzimuthCorrectionConvClass;
    m_ConvName2FactMap["ALN_SM_t_SyncRef"]      = CreateAlnSyncRefConvClass;
    m_ConvName2FactMap["ALN_SimInitMon"]        = CreateAlnSimInitMonConvClass;
    m_ConvName2FactMap["ALN_SimInit"]           = CreateAlnSimInitConvClass;
    m_ConvName2FactMap["ALN_t_Nvm"]             = CreateAlnRteNvmConvClass;
    m_ConvName2FactMap["ALNRteMonitoring"]      = CreateAlnMonitoringConvClass;
    m_ConvName2FactMap["ALN_S_Monitoring_t"]    = CreateAlnMonitoringConvClass;
    m_ConvName2FactMap["ALN_RteReqHwConfig"]    = CreateAlnRteReqHwConfigConvClass;

    // EM conversion classes
    m_ConvName2FactMap["BSW_EMCtrlData"]        = CreateBswEmCtrlDataConvClass;
    m_ConvName2FactMap["EMB0_t_ObjectList_SCAM"]= CreateEmObjectListScamConvClass;
    m_ConvName2FactMap["EMT0_t_ObjectList_MCAM"]= CreateEmObjectListMcamConvClass;
    m_ConvName2FactMap["EMRT_t_ObjectList_MCAM"]= CreateEmObjectListMcamRtConvClass;
    m_ConvName2FactMap["EMVW_t_ObjectList_CAM"] = CreateEmObjectListCamVWConvClass;
    m_ConvName2FactMap["EMTJA_t_ObjectList_MCAM"]= CreateEmObjectListMcamTJAConvClass;
    m_ConvName2FactMap["EM_t_BaseObjectList_CAM"]= CreateEmObjectListBaseCamConvClass;
    m_ConvName2FactMap["Production_Par"]        = CreateProductionparameterConvClass;

    // AWV conversion classes
    m_ConvName2FactMap["DTKodierungFKT"]        = CreateAwvwDtKodierungFktConvClass;
    m_ConvName2FactMap["Fahrpedalwert"]         = CreateFahrpedalwertConvClass;
    m_ConvName2FactMap["DTKvPar"]               = CreateDTKvParConvClass;
    m_ConvName2FactMap["DTFfiPar"]              = CreateDTFfiParConvClass;
    m_ConvName2FactMap["EMCustomObjectList"]    = CreateEmObjectlistCustomConvClass;
    m_ConvName2FactMap["EMPerformanceDegr"]     = CreatePerfDegrConvClass;
    m_ConvName2FactMap["DTBremsung"]            = CreateDTBremsungConvClass;
    
    // FRS conversion classes
    m_ConvName2FactMap["frsBSWCtrlData_t"]      = CreateFRSBswCtrlDataConvClass;
  };

  ~__CSimAdapterFactory(void)
  {
    m_ConvName2FactMap.clear();
  };

  IConverter* CreateConverterInstance(const char* szTypeName) const
  {
    tConvNameToFactoryMap::const_iterator it = m_ConvName2FactMap.find(szTypeName);
    if ((it != m_ConvName2FactMap.end()) && (it->second != NULL))
    {
      return it->second();
    }
    return NULL;
  };
};

// The singleton instance of the factory
CSimAdapterMain::__CSimAdapterFactory CSimAdapterMain::m_InternFactory;

/* class methods ----------------------------------------------------------- */

/* **************************************************************************** 
  Functionname:     CSimAdapterMain                      */ /*!  
  @brief            Constructor for main simulation adapter class
                    This class acts as a factory for the adapters of the
                    individual ports

  @author           Gergely Ungvary
**************************************************************************** */

CSimAdapterMain::CSimAdapterMain(void)
{
}


CSimAdapterMain::~CSimAdapterMain(void)
{
}

IConverter* CSimAdapterMain::CreateConverterInstance(const char* szTypeName)
{
  return m_InternFactory.CreateConverterInstance(szTypeName);
}

/* ------------------------------------------------------------------------ */
/* EoF */
