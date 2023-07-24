/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_em

  MODULNAME:            sim_conv_veh_dyn.cpp

  DESCRIPTION:          

  AUTHOR:               Ovidiu Raicu

  CREATION DATE:        23.03.2010

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_veh_dyn.cpp  $
  CHANGES:              Revision 1.1 2021/12/13 17:21:55CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/vdy/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:43CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/vdy/project.pj
  CHANGES:              Revision 1.33.1.19 2016/10/12 06:43:39CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              added handling for VehDyn interface version 9  for ARS510
  CHANGES:              Revision 1.33.1.18 2016/07/19 08:20:15CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Modified State's copying for ARS510
  CHANGES:              Revision 1.33.1.17 2016/07/15 12:44:14CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              added handling for VehDyn interface version 9
  CHANGES:                for ARS510
  CHANGES:              Revision 1.33.1.16 2015/12/14 14:04:40CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              Conversion of V8 with size 172
  CHANGES:              Revision 1.33.1.15 2015/08/12 10:49:35CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + Conversion V7 with size from V6
  CHANGES:              + Conversion V6 with size from V7 (V6_2)
  CHANGES:              * Fixed compiler warning
  CHANGES:              - Added comments -  berndtt1 [Aug 12, 2015 11:06:05 AM CEST]
  CHANGES:              Change Package : 221167:51 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.33.1.14 2015/04/14 09:33:25CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + conversion V8 to V6
  CHANGES:              --- Added comments ---  berndtt1 [Apr 14, 2015 9:35:30 AM CEST]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.33.1.13 2015/04/01 06:44:34CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              * removing of tabs
  CHANGES:              --- Added comments ---  berndtt1 [Apr 1, 2015 6:47:22 AM CEST]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.33.1.12 2015/03/31 18:16:06CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:              added handling for VehDyn interface version 8
  CHANGES:              --- Added comments ---  eisenacherm [Mar 31, 2015 6:16:06 PM CEST]
  CHANGES:              Change Package : 320951:6 http://mks-psad:7002/im/viewissue?selection=320951
  CHANGES:              Revision 1.33.1.11 2015/02/19 09:39:48CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + Conversion V7 (V6_2) to V6 (for AWV)
  CHANGES:              --- Added comments ---  berndtt1 [Feb 19, 2015 9:41:08 AM CET]
  CHANGES:              Change Package : 276620:4 http://mks-psad:7002/im/viewissue?selection=276620
  CHANGES:              Revision 1.33.1.10 2015/01/30 09:58:25CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              VehDynV6_2 works now with updated version number (=7)
  CHANGES:              --- Added comments ---  berndtt1 [Jan 30, 2015 10:01:33 AM CET]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.33.1.9 2015/01/27 13:29:41CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              Added VehDynV6_2 with size 172 and not updated version number (=6)
  CHANGES:              --- Added comments ---  berndtt1 [Jan 27, 2015 1:41:15 PM CET]
  CHANGES:              Change Package : 221167:45 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.33.1.8 2014/10/30 17:54:18CET Manea, Gabriela (ManeaG) 
  CHANGES:              Changed Convertor Type Name to VehDyn_t  . Change needed in order to connect the Plugins request port with VDY provide port .
  CHANGES:              --- Added comments ---  ManeaG [Oct 30, 2014 5:54:22 PM CET]
  CHANGES:              Change Package : 263320:1 http://mks-psad:7002/im/viewissue?selection=263320
  CHANGES:              Revision 1.33.1.7 2014/02/25 16:36:56CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + Conversion from V6 to V5
  CHANGES:              --- Added comments ---  berndtt1 [Feb 25, 2014 4:38:13 PM CET]
  CHANGES:              Change Package : 221167:1 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.33.1.6 2014/02/03 11:00:52CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              Corrected conversion of I/O states
  CHANGES:              --- Added comments ---  berndtt1 [Feb 3, 2014 11:17:53 AM CET]
  CHANGES:              Change Package : 208935:13 http://mks-psad:7002/im/viewissue?selection=208935
  CHANGES:              Revision 1.33.1.5 2014/01/30 14:17:58CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              Added support for VehDyn V6
  CHANGES:              --- Added comments ---  berndtt1 [Jan 30, 2014 2:27:09 PM CET]
  CHANGES:              Change Package : 208935:13 http://mks-psad:7002/im/viewissue?selection=208935
  CHANGES:              Revision 1.33.1.4 2014/01/29 10:11:34CET Friebertshaeuser, Markus (uidt0551) 
  CHANGES:              Corrected merge
  CHANGES:              --- Added comments ---  uidt0551 [Jan 29, 2014 10:11:34 AM CET]
  CHANGES:              Merge from head
  CHANGES:              --- Added comments ---  uidt0551 [Jan 29, 2014 10:05:46 AM CET]
  CHANGES:              Change Package : 199714:3 http://mks-psad:7002/im/viewissue?selection=199714
  CHANGES:              Revision 1.35 2014/01/28 15:48:18CET Wolter, Frank (wolterf) 
  CHANGES:              Added support for VehDyn V6
  CHANGES:              --- Added comments ---  wolterf [Jan 28, 2014 3:48:19 PM CET]
  CHANGES:              Change Package : 208447:1 http://mks-psad:7002/im/viewissue?selection=208447
  CHANGES:              Revision 1.34 2013/12/17 13:27:51CET Friebertshaeuser, Markus (uidt0551) 
  CHANGES:              Correct handling of PPort of type reference
  CHANGES:              --- Added comments ---  uidt0551 [Dec 17, 2013 1:27:52 PM CET]
  CHANGES:              Change Package : 203467:1 http://mks-psad:7002/im/viewissue?selection=203467
  CHANGES:              Revision 1.34 2013/12/17 13:27:51CET Friebertshaeuser, Markus (uidt0551) 
  CHANGES:              Correct handling of PPort of type reference
  CHANGES:              --- Added comments ---  uidt0551 [Dec 17, 2013 1:27:52 PM CET]
  CHANGES:              Change Package : 203467:1 http://mks-psad:7002/im/viewissue?selection=203467
  CHANGES:              Revision 1.33.1.2 2013/12/12 15:38:36CET Schutsch-EXT, Julian (uidg2542) 
  CHANGES:              vdy tchar update
  CHANGES:              --- Added comments ---  uidg2542 [Dec 12, 2013 3:38:36 PM CET]
  CHANGES:              Change Package : 204135:1 http://mks-psad:7002/im/viewissue?selection=204135
  CHANGES:              Revision 1.33.1.1 2013/08/07 10:39:05CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Simplified VehDyn/VehPar adapter version, where only factory function is exposed via header file (complete implementation
  CHANGES:              hidden in cpp file, making modification of single file necessary when support for new interface version becomes necessary)
  CHANGES:              Note: incompatible change to old versions as respective classes (CConvVehDyn, CConvVehPar) no longer declared by header
  CHANGES:              file. This is the price to pay for information hiding (if the class is exposed via header, then the header always needs to be modified
  CHANGES:              for new conversions)
  CHANGES:              --- Added comments ---  ungvaryg [Aug 7, 2013 10:39:05 AM CEST]
  CHANGES:              Change Package : 190143:3 http://mks-psad:7002/im/viewissue?selection=190143
  CHANGES:              Revision 1.33 2013/06/27 12:58:21CEST Zechner, Stefan (uidt9253) 
  CHANGES:              - check input pointer pPPortData for NULL
  CHANGES:              --- Added comments ---  uidt9253 [Jun 27, 2013 12:58:22 PM CEST]
  CHANGES:              Change Package : 162889:30 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.32 2013/02/06 12:59:44CET Spruck, Jochen (spruckj) 
  CHANGES:              Add vdy offsets adapter to semo adapter, and use const vars instead of defines in interface namespaces
  CHANGES:              --- Added comments ---  spruckj [Feb 6, 2013 12:59:44 PM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.31 2013/01/18 17:44:22CET Exner, Christian (uidt8578) 
  CHANGES:              - fixed warning on typecast and unused parameter
  CHANGES:              --- Added comments ---  uidt8578 [Jan 18, 2013 5:44:22 PM CET]
  CHANGES:              Change Package : 162889:12 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.30 2013/01/18 15:31:41CET Spruck, Jochen (spruckj) 
  CHANGES:              Bug fix V5 conversion
  CHANGES:              --- Added comments ---  spruckj [Jan 18, 2013 3:31:41 PM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.29 2013/01/17 09:43:43CET Spruck, Jochen (spruckj) 
  CHANGES:              Update adapter
  CHANGES:              --- Added comments ---  spruckj [Jan 17, 2013 9:43:44 AM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.28 2013/01/16 13:06:04CET Spruck, Jochen (spruckj) 
  CHANGES:              Rename namespaces, because of conflicts
  CHANGES:              --- Added comments ---  spruckj [Jan 16, 2013 1:06:05 PM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.27 2013/01/16 11:36:31CET Spruck, Jochen (spruckj) 
  CHANGES:              Update VehSig VehPar and VehDyn adapter modules regarding mfc400 changes
  CHANGES:              --- Added comments ---  spruckj [Jan 16, 2013 11:36:32 AM CET]
  CHANGES:              Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
  CHANGES:              Revision 1.26 2012/11/21 15:23:16CET Manea, Gabriela (ManeaG) 
  CHANGES:              Add new vdy vehdyn version to vdy sim adapter
  CHANGES:              --- Added comments ---  ManeaG [Nov 21, 2012 3:23:24 PM CET]
  CHANGES:              Change Package : 166725:1 http://mks-psad:7002/im/viewissue?selection=166725
  CHANGES:              Revision 1.25 2012/06/18 16:00:08CEST Apel, Norman (apeln) 
  CHANGES:              - add init of VehDynVx in order to get rid of SIL SIL issues with padbytes
  CHANGES:              --- Added comments ---  apeln [Jun 18, 2012 4:00:08 PM CEST]
  CHANGES:              Change Package : 105503:1 http://mks-psad:7002/im/viewissue?selection=105503
  CHANGES:              Revision 1.24 2012/04/02 13:06:20CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              * pDestVeh->Longitudinal.VeloCorr.corrVar = pInput->Longitudinal.VeloCorr.corrVelo; --> ...corrVar
  CHANGES:              + Transfer of pDestVeh->Legacy.... if possible. If not then "= 0"
  CHANGES:              --- Added comments ---  berndtt1 [Apr 2, 2012 2:14:29 PM CEST]
  CHANGES:              Change Package : 102413:1 http://mks-psad:7002/im/viewissue?selection=102413
  CHANGES:              Revision 1.23 2012/02/16 15:37:10CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              * updated in InitDefaultVehDynV3() version number of VehDynV3 from 2 to 3
  CHANGES:              --- Added comments ---  berndtt1 [Feb 16, 2012 3:41:32 PM CET]
  CHANGES:              Change Package : 97762:1 http://mks-psad:7002/im/viewissue?selection=97762
  CHANGES:              Revision 1.22 2011/12/16 15:10:21CET Sachs, Martin (sachsm) 
  CHANGES:              Version info is missing in the version sturct
  CHANGES:              --- Added comments ---  sachsm [Dec 16, 2011 3:10:22 PM CET]
  CHANGES:              Change Package : 92154:1 http://mks-psad:7002/im/viewissue?selection=92154
  CHANGES:              Revision 1.21 2011/12/08 17:04:28CET Spruck, Jochen (spruckj) 
  CHANGES:              Add new vdy vehdyn version to vdy sim adapter
  CHANGES:              --- Added comments ---  spruckj [Dec 8, 2011 5:04:32 PM CET]
  CHANGES:              Change Package : 90999:1 http://mks-psad:7002/im/viewissue?selection=90999
  CHANGES:              Revision 1.20 2011/06/30 10:19:33CEST Sachs Martin (sachsm) (sachsm) 
  CHANGES:              fix RSPInputVdata for measurements of April 2009, due to error in pdo
  CHANGES:              --- Added comments ---  sachsm [Jun 30, 2011 10:19:33 AM CEST]
  CHANGES:              Change Package : 71262:1 http://mks-psad:7002/im/viewissue?selection=71262
  CHANGES:              Revision 1.19 2011/06/21 10:51:22CEST Eisenacher Michael (eisenacherm) (eisenacherm) 
  CHANGES:              workaround for recordings with wrongly generated cdl (size 140 instead of 144)
  CHANGES:              --- Added comments ---  eisenacherm [Jun 21, 2011 10:51:22 AM CEST]
  CHANGES:              Change Package : 69670:1 http://mks-psad:7002/im/viewissue?selection=69670
  CHANGES:              Revision 1.18 2011/04/26 09:53:42CEST Spruck Jochen (spruckj) (spruckj) 
  CHANGES:              Add reference port support for VehDyn ports
  CHANGES:              --- Added comments ---  spruckj [Apr 26, 2011 9:53:42 AM CEST]
  CHANGES:              Change Package : 65146:1 http://mks-psad:7002/im/viewissue?selection=65146
  CHANGES:              Revision 1.17 2011/04/14 10:48:38CEST Ungvary Gergely (ungvaryg) (ungvaryg) 
  CHANGES:              Add include of stdafx.h : the macro CONV_I32VERSION_TO_TUPPLE(x) has been moved there (since used by multiple
  CHANGES:              adapter classes). Note: to use this new revision you have to make sure that the given macro is directly or indirectly (through
  CHANGES:              sub-includes) available by including 'stdafx.h'.
  CHANGES:              --- Added comments ---  ungvaryg [Apr 14, 2011 10:48:38 AM CEST]
  CHANGES:              Change Package : 63692:1 http://mks-psad:7002/im/viewissue?selection=63692
  CHANGES:              Revision 1.16 2011/04/05 12:52:06CEST Eisenacher Michael (eisenacherm) (eisenacherm) 
  CHANGES:              corrVeloVar, maxVelo, minVelo, Accel, varAccel, Curve, Curve.varC0, YawRate and YawRate.Variance to conversion from ARS300 to ARS301
  CHANGES:              --- Added comments ---  eisenacherm [Apr 5, 2011 12:52:07 PM CEST]
  CHANGES:              Change Package : 63537:1 http://mks-psad:7002/im/viewissue?selection=63537
  CHANGES:              Revision 1.15 2011/01/24 14:26:49CET Spruck Jochen (spruckj) (spruckj) 
  CHANGES:              RSP VDATA input data bug fix
  CHANGES:              --- Added comments ---  spruckj [Jan 24, 2011 2:26:49 PM CET]
  CHANGES:              Change Package : 57482:1 http://mks-psad:7002/im/viewissue?selection=57482
  CHANGES:              Revision 1.14 2010/12/06 09:39:06CET Jochen Spruck (spruckj) 
  CHANGES:              Remove some Sil-Sil findings
  CHANGES:              --- Added comments ---  spruckj [Dec 6, 2010 9:39:06 AM CET]
  CHANGES:              Change Package : 51886:1 http://mks-psad:7002/im/viewissue?selection=51886
  CHANGES:              Revision 1.13 2010/11/29 17:33:17CET Jochen Spruck (spruckj) 
  CHANGES:              Use general VehPar adater in the rsp adater, merge the RSPInputVDATA to the general VehPar adapter
  CHANGES:              --- Added comments ---  spruckj [Nov 29, 2010 5:33:17 PM CET]
  CHANGES:              Change Package : 51886:1 http://mks-psad:7002/im/viewissue?selection=51886
  CHANGES:              Revision 1.12 2010/11/25 17:33:01CET Jochen Spruck (spruckj) 
  CHANGES:              smr sim adapter update to vdy version 03.01.00
  CHANGES:              --- Added comments ---  spruckj [Nov 25, 2010 5:33:01 PM CET]
  CHANGES:              Change Package : 55693:2 http://mks-psad:7002/im/viewissue?selection=55693
  CHANGES:              Revision 1.11 2010/11/24 09:47:42CET Jochen Spruck (spruckj) 
  CHANGES:              Simulation adapter
  CHANGES:              veh dyn, veh par, veh sig and vdy nvm data adapter bug fix for ARS300 data
  CHANGES:              --- Added comments ---  spruckj [Nov 24, 2010 9:47:43 AM CET]
  CHANGES:              Change Package : 51886:1 http://mks-psad:7002/im/viewissue?selection=51886
  CHANGES:              Revision 1.10 2010/11/23 10:25:50CET Jochen Spruck (spruckj) 
  CHANGES:              Merge the rsp VDATA input adaption to the general veh dyn adapter
  CHANGES:              --- Added comments ---  spruckj [Nov 23, 2010 10:25:50 AM CET]
  CHANGES:              Change Package : 51886:1 http://mks-psad:7002/im/viewissue?selection=51886
  CHANGES:              Revision 1.9 2010/11/22 17:24:17CET Jochen Spruck (spruckj) 
  CHANGES:              Update vdy adpter,
  CHANGES:              use the general adater for the interface VehDyn interface,
  CHANGES:              and merge the adaption of the old vdy interface to this adapter
  CHANGES:              --- Added comments ---  spruckj [Nov 22, 2010 5:24:17 PM CET]
  CHANGES:              Change Package : 51886:1 http://mks-psad:7002/im/viewissue?selection=51886
  CHANGES:              Revision 1.8 2010/11/19 12:21:08CET Gergely Ungvary (ungvaryg) 
  CHANGES:              Add input value modifications previously found in sim_swc_em_process_call.cpp with configuration switch CFG_TPW_INPUT_VALUE_MODIFY
  CHANGES:              (The switch can be used to find the locations where values are modified)
  CHANGES:              --- Added comments ---  ungvaryg [Nov 19, 2010 12:21:09 PM CET]
  CHANGES:              Change Package : 54752:1 http://mks-psad:7002/im/viewissue?selection=54752
  CHANGES:              Revision 1.7 2010/11/19 11:04:27CET Gergely Ungvary (ungvaryg) 
  CHANGES:              Modify class to allow conversion class use by simulators that do not properly specify the request port version number (i.e.: 0)
  CHANGES:              --- Added comments ---  ungvaryg [Nov 19, 2010 11:04:27 AM CET]
  CHANGES:              Change Package : 54752:1 http://mks-psad:7002/im/viewissue?selection=54752
  CHANGES:              Revision 1.6 2010/11/18 19:15:41CET Gergely Ungvary (ungvaryg) 
  CHANGES:              Rewrite adapters for forward/backward compatibility
  CHANGES:              Clean up several unclean/problematic code parts (better transparancy of what adapter is doing, which
  CHANGES:              buffers it's using)
  CHANGES:              Remove overcomplicated CDataBuffer use (not needed anyway, hard to debug etc.)
  CHANGES:              --- Added comments ---  ungvaryg [Nov 18, 2010 7:15:41 PM CET]
  CHANGES:              Change Package : 54725:1 http://mks-psad:7002/im/viewissue?selection=54725
  CHANGES:              Revision 1.5 2010/09/16 15:15:16CEST Jochen Spruck (spruckj) 
  CHANGES:              Bug fix of tpw input adapter for version 09 and ARS350 07
  CHANGES:              wrong version was used to check if the it is the right input twp_input version
  CHANGES:              --- Added comments ---  spruckj [Sep 16, 2010 3:15:17 PM CEST]
  CHANGES:              Change Package : 46866:1 http://mks-psad:7002/im/viewissue?selection=46866
  CHANGES:              Revision 1.4 2010/07/22 13:12:18CEST Jochen Spruck (spruckj) 
  CHANGES:              Update veh dyn adapter, now adapat also the VehDyn stucts to VehDyn not only TPWInput
  CHANGES:              Update veh par adapter, now  adapt also the VehPyr sturcts to VehPar ont only form TPWInput
  CHANGES:              --- Added comments ---  spruckj [Jul 22, 2010 1:12:18 PM CEST]
  CHANGES:              Change Package : 46866:1 http://mks-psad:7002/im/viewissue?selection=46866
  CHANGES:              Revision 1.3 2010/04/21 16:20:22CEST oraicu 
  CHANGES:              Added ARS35x specific structures.
  CHANGES:              --- Added comments ---  oraicu [2010/04/21 14:20:22Z]
  CHANGES:              Change Package : 39644:2 http://LISS014:6001/im/viewissue?selection=39644
  CHANGES:              Revision 1.2 2010/04/20 14:59:38CEST ffoelster 
  CHANGES:              BugFix: Due to an error in the CDL compiler the size of TPWinput V10 might be given as 253 instead of 256 in CDL
  CHANGES:              --- Added comments ---  ffoelster [2010/04/20 12:59:38Z]
  CHANGES:              Change Package : 41450:1 http://LISS014:6001/im/viewissue?selection=41450
  CHANGES:              Revision 1.1 2010/04/07 10:08:20CEST Ovidiu Raicu (oraicu) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/EM_EnvironmentModel/04_Engineering/03_Workspace/algo/em_sim/em_adapt/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_veh_dyn.h"
#include "sim_adapter_ext.h"
#include "sim_versioninfo_impl.h"
//#include "interfacetpwinput.h"
#include "interfacevehdyn.h"


// Configuration define enabling modification of input values. These modifiers were formerly found
// in sim_swc_em_process_call.cpp, and modify overwrite some input fields depending on the TPW version
// being wrapped. This clearly does not belong in a simulator, thus it was moved here in switchable
// form, since no description about the intention/background is available. (That way the switches can
// be easily used to find where data is modified)
#define CFG_TPW_INPUT_VALUE_MODIFY      1

#define VDY_VELO_CORR_QUAL_EEPROM_V1toV8          (0u)
#define VDY_VELO_CORR_QUAL_RANGE_NVERIFIED_V1toV8 (1u)
#define VDY_VELO_CORR_QUAL_RANGE_VERIFIED_V1toV8  (2u)
#define VDY_VELO_CORR_QUAL_SNA_V1toV8             (3u)
#define VDY_NO_VELO_CORR_V9                       (0u)
#define VDY_VELO_CORR_QUAL_EEPROM_V9              (1u)
#define VDY_VELO_CORR_QUAL_RANGE_NVERIFIED_V9     (2u)
#define VDY_VELO_CORR_QUAL_RANGE_VERIFIED_V9      (3u)
#define VDY_VELO_CORR_QUAL_SNA_V9                 (4u)

/* Byte position typedef VehDynStatePos_t */
// Old (See also interfacevehdyn.h)
#define VDY_SOUT_POS_CURVE_V1toV8  0U
#define VDY_SOUT_POS_YWR_V1toV8    1U
#define VDY_SOUT_POS_DRCRV_V1toV8  2U
#define VDY_SOUT_POS_VEL_V1toV8    3U
#define VDY_SOUT_POS_ACCEL_V1toV8  4U
#define VDY_SOUT_POS_MSTAT_V1toV8  5U
#define VDY_SOUT_POS_VCORR_V1toV8  6U
#define VDY_SOUT_POS_SSA_V1toV8    7U
#define VDY_SOUT_POS_LATACC_V1toV8 8U
#define VDY_SOUT_POS_MAX_V1toV8    12U

// New (ARS5xx)
#define VDY_SOUT_POS_VELOCITY_V9 0U
#define VDY_SOUT_POS_ACCEL_V9 1U
#define VDY_SOUT_POS_YAWRATE_V9 2U
#define VDY_SOUT_POS_CURVE_V9 3U
#define VDY_SOUT_POS_DRVINTCURVE_V9 4U
#define VDY_SOUT_POS_LATERALACCEL_V9 5U
#define VDY_SOUT_POS_SLIPANGLE_V9 6U
#define VDY_SOUT_POS_MOTIONSTATE_V9 7U
#define VDY_SOUT_POS_MAX_V9 8U


class CConvVehDyn : public CSimConverterBase
{

  // the list of dependency names used inside by the converter
  /*
  static const char* DEP_NAMES[];
  */

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    // add new dependencies here
    DEP_COUNT
  };

  VehDynV0::VehDyn_t    m_VehDynV0;
  VehDynV1::VehDyn_t    m_VehDynV1;
  VehDynV2::VehDyn_t    m_VehDynV2;
  VehDynV3::VehDyn_t    m_VehDynV3;
  VehDynV5::VehDyn_t    m_VehDynV5;
  VehDynV6::VehDyn_t    m_VehDynV6;
  VehDynV6_2::VehDyn_t  m_VehDynV6_2;
  VehDynV8::VehDyn_t    m_VehDynV8;
  VehDynV9::VehDyn_t    m_VehDynV9;
  VehDynV32::VehDyn_t   m_VehDynV32;

  bool PortSupported(SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo = NULL) const;
  void InitDefaultVehDynV0(VehDynV0::VehDyn_t * const pDestVeh);
  void InitDefaultVehDynV1(VehDynV1::VehDyn_t * const pDestVeh);
  void InitDefaultVehDynV2(VehDynV2::VehDyn_t * const pDestVeh);
  void InitDefaultVehDynV3(VehDynV3::VehDyn_t * const pDestVeh);
  void InitDefaultVehDynV5(VehDynV5::VehDyn_t * const pDestVeh);
  void InitDefaultVehDynV6(VehDynV6::VehDyn_t * const pDestVeh);
  void InitDefaultVehDynV6_2(VehDynV6_2::VehDyn_t * const pDestVeh);
  void InitDefaultVehDynV8(VehDynV8::VehDyn_t * const pDestVeh);
  void InitDefaultVehDynV9(VehDynV9::VehDyn_t * const pDestVeh);
  void InitDefaultVehDynV32(VehDynV32::VehDyn_t * const pDestVeh);

  bool DecodeTPW(VehDynV2::VehDyn_t * const pDestVeh, unsigned long ulPPortSize, const void * pPPortData);
  bool DecodeRSPInputVDATA(VehDynV2::VehDyn_t * const pVehDyn, SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const void * const pPPortData);
  bool DecodeVDYOutput(VehDynV2::VehDyn_t * const pVehDyn, SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const void * const pPPortData);
  void ConvertToVehDynV0(VehDynV0::VehDyn_t * const pDestVeh, const VehDynV1::VehDyn_t * const pInput);
  void ConvertToVehDynV0(VehDynV0::VehDyn_t * const pDestVeh, const VehDynV2::VehDyn_t * const pInput);
  void ConvertToVehDynV0(VehDynV0::VehDyn_t * const pDestVeh, const VehDynV3::VehDyn_t * const pInput);
  void ConvertToVehDynV1(VehDynV1::VehDyn_t * const pDestVeh, const VehDynV0::VehDyn_t * const pInput);
  void ConvertToVehDynV1(VehDynV1::VehDyn_t * const pDestVeh, const VehDynV2::VehDyn_t * const pInput);
  void ConvertToVehDynV1(VehDynV1::VehDyn_t * const pDestVeh, const VehDynV3::VehDyn_t * const pInput);
  void ConvertToVehDynV2(VehDynV2::VehDyn_t * const pDestVeh, const VehDynV0::VehDyn_t * const pInput);
  void ConvertToVehDynV2(VehDynV2::VehDyn_t * const pDestVeh, const VehDynV1::VehDyn_t * const pInput);
  void ConvertToVehDynV2(VehDynV2::VehDyn_t * const pDestVeh, const VehDynV3::VehDyn_t * const pInput);
  void ConvertToVehDynV3(VehDynV3::VehDyn_t * const pDestVeh, const VehDynV0::VehDyn_t * const pInput);
  void ConvertToVehDynV3(VehDynV3::VehDyn_t * const pDestVeh, const VehDynV1::VehDyn_t * const pInput);
  void ConvertToVehDynV3(VehDynV3::VehDyn_t * const pDestVeh, const VehDynV2::VehDyn_t * const pInput);

  void ConvertToVehDynV5(VehDynV5::VehDyn_t * const pDestVeh, const VehDynV3::VehDyn_t * const pInput);
  void ConvertToVehDynV3(VehDynV3::VehDyn_t * const pDestVeh, const VehDynV5::VehDyn_t * const pInput);
  void ConvertToVehDynV5(VehDynV5::VehDyn_t * const pDestVeh, const VehDynV6::VehDyn_t * const pInput);

  void ConvertToVehDynV6(VehDynV6::VehDyn_t * const pDestVeh, const VehDynV5::VehDyn_t * const pInput);
  void ConvertToVehDynV6(VehDynV6::VehDyn_t * const pDestVeh, const VehDynV6_2::VehDyn_t * const pInput);
  void ConvertToVehDynV6(VehDynV6::VehDyn_t * const pDestVeh, const VehDynV8::VehDyn_t * const pInput);

  void ConvertToVehDynV6_2(VehDynV6_2::VehDyn_t * const pDestVeh, const VehDynV6::VehDyn_t * const pInput);

  void ConvertToVehDynV8_7(VehDynV6_2::VehDyn_t * const pDestVeh, const VehDynV8::VehDyn_t * const pInput);
  void ConvertToVehDynV8(VehDynV8::VehDyn_t * const pDestVeh, const VehDynV6_2::VehDyn_t * const pInput);
  void ConvertToVehDynV8(VehDynV8::VehDyn_t * const pDestVeh, const VehDynV9::VehDyn_t * const pInput);

  void ConvertToVehDynV9(VehDynV9::VehDyn_t * const pDestVeh, const VehDynV8::VehDyn_t * const pInput);
  void ConvertToVehDynV9(VehDynV9::VehDyn_t * const pDestVeh, const VehDynV6_2::VehDyn_t * const pInput);

  void ConvertToVehDynV32(VehDynV32::VehDyn_t * const pDestVeh, const VehDynV8::VehDyn_t * const pInput);
  void ConvertToVehDynV32(VehDynV32::VehDyn_t * const pDestVeh, const VehDynV6_2::VehDyn_t * const pInput);

  uint8 ConvertIOState(unsigned int position, unsigned long* pInputstate);
  unsigned long CConvVehDyn::ConvertIOState(unsigned int position, uint8 ui8Inputstate);

  unsigned char ConvertVelocityCorrectionQuality(unsigned char VeloCorr_corrQual);
  unsigned char ConvertVeloCorr_corrQual(unsigned char VelocityCorrectionQuality);
  void ConvertPosOfStates(VehDynV9::State_array_t &Dest, const VehDynV6::State_array_t &Src);
  void ConvertPosOfStates(VehDynV6::State_array_t &Dest, const VehDynV9::State_array_t &Src);

public:

  static const TCHAR* GetConverterTypeName()
  {
    return _T("VehDyn_t");
  }
  static const TCHAR* GetConverterTypeName2()
  {
    // TODO: REMOVE THIS STATIC FUNCTION!!!! It is completely useless. If a single
    // conversion class is capable of converting TPWInput and VehDyn, then it is
    // completely unnecessary to be able to reference the same class by two different
    // names! Remove references to port type "TPWInput_VehDyn" from EM simulator!!!!
    return _T("TPWInput_VehDyn");
  }

  CConvVehDyn(void);
  virtual ~CConvVehDyn(void);

  const TCHAR* GetTypeName()
  {
    return GetConverterTypeName();
  }

  void Destroy()
  {
    delete this;
  }

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_VALUE_FROM_PPORT - when the conversion is not implemented here
   *                                  and the value from Provide Port must be used
   */
  long ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo,
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize);

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
   *                                            and the default value from Request Port must be used
   */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    void** pDefaultData, unsigned long& ulDefaultSize);

protected:

  // used to check if an unversioned PPort is compatible with a certain version of RPort
  bool IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize);

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo);
private:

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl V0_VER_INFO;
  static CVersionInfoImpl V1_VER_INFO;
  static CVersionInfoImpl V2_VER_INFO;
  static CVersionInfoImpl V3_VER_INFO;
  static CVersionInfoImpl V4_VER_INFO;
  static CVersionInfoImpl V5_VER_INFO;
  static CVersionInfoImpl V6_VER_INFO;
  static CVersionInfoImpl V7_VER_INFO;
  static CVersionInfoImpl V8_VER_INFO;
  static CVersionInfoImpl V9_VER_INFO;
  static CVersionInfoImpl V32_VER_INFO;

  enum eTPWInputVersions
  {
    TPW_INPUT_V6          = 0,
    TPW_INPUT_V7_8        = 1,
    TPW_INPUT_V9          = 2,
    TPW_INPUT_V10         = 3,
    TPW_INPUT_V10_253byte = 4, /* TPWInputVersion V10 with erroneous size in CDL 253bytes instead of 256bytes due to wrong byte alignment */
    TPW_INPUT_V11         = 5,
    TPW_INPUT_V6_350      = 6,
    TPW_INPUT_V7_350      = 7,
    TPW_INPUT_VERSION_COUNT
  };
  static const unsigned long SUPPORTED_SIZE[TPW_INPUT_VERSION_COUNT];

  enum RSP_INPUT_VDATA
  {
    RSP_INPUT_VDATA_IV2       = 0,
    RSP_INPUT_VDATA_IV3       = 1,
    RSP_INPUT_VDATA_IV4       = 2,
    RSP_INPUT_VDATA_IV5       = 3,
    RSP_INPUT_VDATA_IV6       = 4,
    RSP_INPUT_VDATA_IV7       = 5,
    RSP_INPUT_VDATA_IV7_2     = 6,
    RSP_INPUT_VDATA_IV8       = 7,
    RSP_INPUT_VDATA_IVL       = 8,
    RSP_INPUT_VDATA_VER_COUNT
  };
  static unsigned long SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_VER_COUNT];

  enum eVersions
  {
    VDY_OUT_V1 = 0,
    VDY_OUT_V2,
    VDY_OUT_V3,
    VDY_OUT_COUNT
  };
  static unsigned long SUPPORTED_SIZE_VDY_OUTPUT[VDY_OUT_COUNT];

  enum eVehDynInputVersions
  {
    VEHDYN_INPUT_V0         = 0,
    VEHDYN_INPUT_V1         = 1,
    VEHDYN_INPUT_V2         = 2,
    VEHDYN_INPUT_V3         = 3,
    VEHDYN_INPUT_V4         = 4,
    VEHDYN_INPUT_V5         = 5,
    VEHDYN_INPUT_V6         = 6,
    VEHDYN_INPUT_V6_2       = 7,
    VEHDYN_INPUT_V7         = 8,
    VEHDYN_INPUT_V8         = 9,
    VEHDYN_INPUT_V9         = 10,
    VEHDYN_INPUT_V32        = 11,
    VEHDYN_INPUT_VERSION_COUNT
  };
  static const unsigned long VEHDYN_SUPPORTED_SIZE[VEHDYN_INPUT_VERSION_COUNT];

  static CVersionInfoImpl * const VEHDYN_VERSION_NUMBERS[VEHDYN_INPUT_VERSION_COUNT];

  static const uint32 DefaultStateWord;

};

CVersionInfoImpl  CConvVehDyn::BASE_VERSION(0, 0, 0);
CVersionInfoImpl  CConvVehDyn::V0_VER_INFO(0, 0, 0);
CVersionInfoImpl  CConvVehDyn::V1_VER_INFO(0, 0, 1);
CVersionInfoImpl  CConvVehDyn::V2_VER_INFO(0, 0, 2);
CVersionInfoImpl  CConvVehDyn::V3_VER_INFO(0, 0, 3);
CVersionInfoImpl  CConvVehDyn::V4_VER_INFO(0, 0, 4);
CVersionInfoImpl  CConvVehDyn::V5_VER_INFO(0, 0, 5);
CVersionInfoImpl  CConvVehDyn::V6_VER_INFO(0, 0, 6);
CVersionInfoImpl  CConvVehDyn::V7_VER_INFO(0, 0, 7);
CVersionInfoImpl  CConvVehDyn::V8_VER_INFO(0, 0, 8);
CVersionInfoImpl  CConvVehDyn::V9_VER_INFO(0, 0, 9);
CVersionInfoImpl  CConvVehDyn::V32_VER_INFO(0, 0, 32);

const unsigned long CConvVehDyn::SUPPORTED_SIZE[CConvVehDyn::TPW_INPUT_VERSION_COUNT]=
{
  sizeof(TPW_DYN_300::TPWInput_V6_t),
  sizeof(TPW_DYN_300::TPWInput_8_7_t),
  sizeof(TPW_DYN_300::TPWInput_V9_t),
  sizeof(TPW_DYN_300::TPWInput_V10_t),
  sizeof(TPW_DYN_300::TPWInput_V10_t)-3, // Due to an error in the CDL compiler the size of V10 might be set to 253
  sizeof(TPW_DYN_300::TPWInput_V11_t),
  sizeof(TPW_DYN_300::TPWInput_V6_ARS350_t),
  sizeof(TPW_DYN_300::TPWInput_V7_ARS350_t)
};

unsigned long CConvVehDyn::SUPPORTED_SIZE_RSP_INPUT_VDATA[CConvVehDyn::RSP_INPUT_VDATA_VER_COUNT] =
{
  sizeof(RSP_DYN_300::RSPInputVData_t_IV2),
  sizeof(RSP_DYN_300::RSPInputVData_t_IV3),
  sizeof(RSP_DYN_300::RSPInputVData_t_IV4),
  sizeof(RSP_DYN_300::RSPInputVData_t_IV5),
  sizeof(RSP_DYN_300::RSPInputVData_t_IV6),
  sizeof(RSP_DYN_300::RSPInputVData_t_IV7),
  (sizeof(RSP_DYN_300::RSPInputVData_t_IV7)+2u),
  sizeof(RSP_DYN_300::RSPInputVData_t_IV8),
  sizeof(RSP_DYN_300::RSPInputVData_t_IVL),
};

unsigned long CConvVehDyn::SUPPORTED_SIZE_VDY_OUTPUT[CConvVehDyn::VDY_OUT_COUNT] =
{
  sizeof(VDY_DYN_300::VDYOutputData_v1_t),
  sizeof(VDY_DYN_300::VDYOutputData_v2_t),
  sizeof(VDY_DYN_300::VDYOutputData_v3_t),
};

const unsigned long CConvVehDyn::VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_VERSION_COUNT]=
{
  sizeof(VehDynV0::VehDyn_t),
  sizeof(VehDynV1::VehDyn_t),
  sizeof(VehDynV2::VehDyn_t),
  sizeof(VehDynV3::VehDyn_t),
  sizeof(VehDynV3::VehDyn_t),
  sizeof(VehDynV5::VehDyn_t),
  sizeof(VehDynV6::VehDyn_t),
  sizeof(VehDynV6_2::VehDyn_t),
  sizeof(VehDynV6_2::VehDyn_t),
  sizeof(VehDynV8::VehDyn_t),
  sizeof(VehDynV9::VehDyn_t),
  sizeof(VehDynV32::VehDyn_t)
};

CVersionInfoImpl * const CConvVehDyn::VEHDYN_VERSION_NUMBERS[VEHDYN_INPUT_VERSION_COUNT]=
{
  &V0_VER_INFO,
  &V1_VER_INFO,
  &V2_VER_INFO,
  &V3_VER_INFO,
  &V4_VER_INFO,
  &V5_VER_INFO,
  &V6_VER_INFO,
  &V6_VER_INFO,
  &V7_VER_INFO,
  &V8_VER_INFO,
  &V9_VER_INFO,
  &V32_VER_INFO
};

const uint32 CConvVehDyn::DefaultStateWord  = 0xAAAAAAAAuL; // 0xAAAAAAAA = all signals VDY_IO_STATE_NOTAVAIL, 0x55555555 = all signals VDY_IO_STATE_INVALID

CConvVehDyn::CConvVehDyn(void)
: CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT),
m_VehDynV0(), m_VehDynV1(), m_VehDynV2()
{
}

CConvVehDyn::~CConvVehDyn(void)
{
}

bool CConvVehDyn::PortSupported(SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo) const
{
  bool bResult = false;
  unsigned int i;

  // VehDyn_t to VehDyn_t conversion
  for (i=0;(i<CConvVehDyn::VEHDYN_INPUT_VERSION_COUNT) && (!bResult);i++)
  {
    if ((ePortType == simOPAQUE_t) && ((ulPortSize == VEHDYN_SUPPORTED_SIZE[i]) || ( (i == VEHDYN_INPUT_V2) && (ulPortSize == VEHDYN_SUPPORTED_SIZE[i]-4) ) ))
    {
      // Check if version information is compatible - with extra care for simulators that
      // do not set the version number at all...
      if ((pPortVersionInfo == NULL) || (pPortVersionInfo->Equals(VEHDYN_VERSION_NUMBERS[i])) || (pPortVersionInfo->Equals(&BASE_VERSION)))
      {
        bResult = true;
      }
    }
  }
  // old TPW input conversion
  for (i=0;(i<CConvVehDyn::TPW_INPUT_VERSION_COUNT) && (!bResult);i++)
  {
    bResult |= ((ePortType == simOPAQUE_t) && (ulPortSize == SUPPORTED_SIZE[i]) && ((pPortVersionInfo == NULL) || (BASE_VERSION.Equals(pPortVersionInfo))));
  }
  // old RSP VDATA input conversion
  for (i=0;(i<CConvVehDyn::RSP_INPUT_VDATA_VER_COUNT) && (!bResult);i++)
  {
    bResult |= ((ePortType == simOPAQUE_t) && (ulPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[i]) && ((pPortVersionInfo == NULL) || (BASE_VERSION.Equals(pPortVersionInfo))));
  }
  // old vdy input conversion
  for (i=0;(i<CConvVehDyn::VDY_OUT_COUNT) && (!bResult);i++)
  {
    bResult |= ((ePortType == simOPAQUE_t) && (ulPortSize == SUPPORTED_SIZE_VDY_OUTPUT[i]) && ((pPortVersionInfo == NULL) || (BASE_VERSION.Equals(pPortVersionInfo))));
  }
  return bResult;
}

void CConvVehDyn::InitDefaultVehDynV0(VehDynV0::VehDyn_t * const pDestVeh)
{
  // Initialize output buffer (making dummy updates of cycle counter and time stamp)
  const uint32 DummyTimeStamp = 0;
  memset(pDestVeh, 0, sizeof(*pDestVeh));
  pDestVeh->TimeStamp       = DummyTimeStamp;
  pDestVeh->Version         = 0;
  pDestVeh->State[0]        = DefaultStateWord;
  pDestVeh->State[1]        = DefaultStateWord;
}

void CConvVehDyn::InitDefaultVehDynV1(VehDynV1::VehDyn_t * const pDestVeh)
{
  // Initialize output buffer (making dummy updates of cycle counter and time stamp)
  const uint32 DummyTimeStamp = 0;
  memset(pDestVeh, 0, sizeof(*pDestVeh));
  pDestVeh->uiVersionNumber = 1u;
  pDestVeh->TimeStamp       = DummyTimeStamp;
  pDestVeh->State[0]        = DefaultStateWord;
  pDestVeh->State[1]        = DefaultStateWord;
}

void CConvVehDyn::InitDefaultVehDynV2(VehDynV2::VehDyn_t * const pDestVeh)
{
  // Initialize output buffer (making dummy updates of cycle counter and time stamp)
  const VehDynV2::AlgoDataTimeStamp_t DummyTimeStamp = 0;
  const VehDynV2::AlgoCycleCounter_t DummyCycleCounter = 0U;
  memset(pDestVeh, 0, sizeof(*pDestVeh));
  pDestVeh->uiVersionNumber = 2u;
  pDestVeh->uiTimeStamp     = DummyTimeStamp;
  pDestVeh->uiCycleCounter  = DummyCycleCounter;
  pDestVeh->State[0]        = DefaultStateWord;
  pDestVeh->State[1]        = DefaultStateWord;
}

void CConvVehDyn::InitDefaultVehDynV3(VehDynV3::VehDyn_t * const pDestVeh)
{
  // Initialize output buffer (making dummy updates of cycle counter and time stamp)
  const VehDynV3::AlgoDataTimeStamp_t DummyTimeStamp = 0;
  const VehDynV3::AlgoCycleCounter_t DummyCycleCounter = 0U;
  memset(pDestVeh, 0, sizeof(*pDestVeh));
  pDestVeh->uiVersionNumber = 3u;
  pDestVeh->uiTimeStamp     = DummyTimeStamp;
  pDestVeh->uiCycleCounter  = DummyCycleCounter;
  pDestVeh->State[0]        = DefaultStateWord;
  pDestVeh->State[1]        = DefaultStateWord;
}

void CConvVehDyn::InitDefaultVehDynV5(VehDynV5::VehDyn_t * const pDestVeh)
{
  // Initialize output buffer (making dummy updates of cycle counter and time stamp)
  const VehDynV5::AlgoDataTimeStamp_t DummyTimeStamp   = 0;
  const VehDynV5::AlgoCycleCounter_t DummyCycleCounter = 0U;
  memset(pDestVeh, 0, sizeof(*pDestVeh));
  pDestVeh->uiVersionNumber = 5u;
  pDestVeh->sSignalHeader.uiTimeStamp          = DummyTimeStamp;
  pDestVeh->sSignalHeader.uiMeasurementCounter = 0U;
  pDestVeh->sSignalHeader.uiCycleCounter       = DummyCycleCounter;
  pDestVeh->sSignalHeader.eSigStatus           = VehDynV5::AL_SIG_STATE_INVALID;

  pDestVeh->State[0]        = DefaultStateWord;
  pDestVeh->State[1]        = DefaultStateWord;
}


void CConvVehDyn::InitDefaultVehDynV6(VehDynV6::VehDyn_t * const pDestVeh)
{
  // Initialize output buffer
  memset(pDestVeh, 0, sizeof(*pDestVeh));
  pDestVeh->uiVersionNumber = 6u;
  memset(pDestVeh->State, 15, sizeof(pDestVeh->State));
}

void CConvVehDyn::InitDefaultVehDynV6_2(VehDynV6_2::VehDyn_t * const pDestVeh)
{
  // Initialize output buffer
  memset(pDestVeh, 0, sizeof(*pDestVeh));
  pDestVeh->uiVersionNumber = 6u;
  memset(pDestVeh->State, 15, sizeof(pDestVeh->State));
}

void CConvVehDyn::InitDefaultVehDynV8(VehDynV8::VehDyn_t * const pDestVeh)
{
  // Initialize output buffer
  memset(pDestVeh, 0, sizeof(*pDestVeh));
  pDestVeh->uiVersionNumber = 8u;
  memset(pDestVeh->State, 15, sizeof(pDestVeh->State));
}

void CConvVehDyn::InitDefaultVehDynV9(VehDynV9::VehDyn_t * const pDestVeh)
{
  // Initialize output buffer
  memset(pDestVeh, 0, sizeof(*pDestVeh));
  pDestVeh->uiVersionNumber = 9u;
  memset(pDestVeh->State, 15, sizeof(pDestVeh->State));
}

void CConvVehDyn::InitDefaultVehDynV32(VehDynV32::VehDyn_t * const pDestVeh)
{
  // Initialize output buffer
  memset(pDestVeh, 0, sizeof(*pDestVeh));
  pDestVeh->uiVersionNumber = 32u;
  memset(pDestVeh->State, 15, sizeof(pDestVeh->State));
}


bool CConvVehDyn::DecodeTPW(VehDynV2::VehDyn_t * const pDestVeh, unsigned long ulPPortSize, const void * pPPortData)
{
  bool bRet;
  const float DEFAULT_CURVE_VARIANCE    = 0.0f;

  // This method always tries to decode the TPWinput data provided into the
  // latest VehDyn_t structure (a member variable of the class). This in turn
  // can then be converted using other conversion routines between different
  // versions. (The goal is minimizing effort needed: have a single TPW->VehDyn_t
  // conversion & reuse the other VehDyn_t -> VehDyn_t conversions)
  if (ulPPortSize > 4)
  {
#if (CFG_TPW_INPUT_VALUE_MODIFY)
    // Create a backup of the VehDyn structure to be able to manipulate values
    // back to last cycle's value if signal states are set to invalid
    const VehDynV2::VehDyn_t VehDynBackup = *pDestVeh;
#endif
    // The first four bytes of TPW is always the version
    const uint32 tpw_version = *reinterpret_cast<const uint32*>(pPPortData);
    // Initialize output buffer (making dummy updates of cycle counter and time stamp)
    const VehDynV2::AlgoDataTimeStamp_t DummyTimeStamp = pDestVeh->uiTimeStamp + 60;
    const VehDynV2::AlgoCycleCounter_t DummyCycleCounter = pDestVeh->uiCycleCounter + 3;
    memset(pDestVeh, 0, sizeof(*pDestVeh));
    pDestVeh->uiVersionNumber = 2u;
    pDestVeh->uiTimeStamp     = DummyTimeStamp;
    pDestVeh->uiCycleCounter  = DummyCycleCounter;
    // Helper variable for I/O state
    VDY_DYN_300::VDYIoState_t sig_state;
    // Now branch according to TPWinput version
    if ((tpw_version == 6) && (ulPPortSize == SUPPORTED_SIZE[CConvVehDyn::TPW_INPUT_V6]))
    {
      const TPW_DYN_300::TPWInput_V6_t * const pInput = reinterpret_cast<const TPW_DYN_300::TPWInput_V6_t*>(pPPortData);

      // Go through signals in the order they are declared in VehDyn_t
      // Fill longitudinal signals
      pDestVeh->Longitudinal.MotVar.Velocity        = pInput->TPWMeasVehicleSpeed;
      pDestVeh->Longitudinal.MotVar.Accel           = pInput->TPWMeasEgoAcceleration;
      pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->TPWMeasVehicleSpeedVar;
      pDestVeh->Longitudinal.MotVar.varAccel        = pInput->TPWMeasEgoAccelerationVar;
      pDestVeh->Longitudinal.VeloCorr.corrFact      = 0.f;
      pDestVeh->Longitudinal.VeloCorr.corrVar       = 0.f;
      pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->TPWMeasVehicleSpeedCorrected;
      pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->TPWMeasVehicleSpeedCorrectedVar;
      pDestVeh->Longitudinal.VeloCorr.minVelo       = 0.f;
      pDestVeh->Longitudinal.VeloCorr.maxVelo       = 0.f;
      pDestVeh->Longitudinal.AccelCorr.corrAccel    = 0.f;
      pDestVeh->Longitudinal.AccelCorr.corrAccelVar = 0.f;
      // Yaw rate
      pDestVeh->Lateral.YawRate.YawRate   = pInput->EstYawRate;
      pDestVeh->Lateral.YawRate.Variance  = pInput->EstYawRateVariance;
      pDestVeh->Lateral.YawRate.Quality   = pInput->QualityYawRate;
      // Set curvature
      pDestVeh->Lateral.Curve.Curve     = pInput->CurveStandard;
      pDestVeh->Lateral.Curve.C1        = 0.f;
      pDestVeh->Lateral.Curve.Gradient  = pInput->GradientStandard;
      pDestVeh->Lateral.Curve.varC0     = DEFAULT_CURVE_VARIANCE;
      pDestVeh->Lateral.Curve.varC1     = DEFAULT_CURVE_VARIANCE;
      pDestVeh->Lateral.Curve.Quality   = pInput->QualityStandard;
      // Driver intented curvature
      pDestVeh->Lateral.DrvIntCurve.Curve       = pInput->DrvIntCrv;
      pDestVeh->Lateral.DrvIntCurve.Variance    = pInput->DrvIntCrvVariance;
      pDestVeh->Lateral.DrvIntCurve.Gradient    = pInput->DrvIntCrvGrad;
      // Lateral acceleration
      pDestVeh->Lateral.Accel.LatAccel    = 0.f;
      pDestVeh->Lateral.Accel.Variance    = 0.f;
      // Side slip angle
      pDestVeh->Lateral.SlipAngle.SideSlipAngle = pInput->SideSlipAngle;
      pDestVeh->Lateral.SlipAngle.Variance      = pInput->SideSlipAngleVariance;
      // Motion state
      pDestVeh->MotionState.MotState    = pInput->MotionStates;
      pDestVeh->MotionState.Confidence  = pInput->MotionStatesConfidence;
      // Legacy
      pDestVeh->Legacy.YawRateMaxJitter = 0.f;
      pDestVeh->Legacy.bStandStill      = (pInput->MotionStates == VDY_LONG_MOT_STATE_STDST);
      // Set signal states
      sig_state = (pInput->SignalStateDynVehCourseCurve)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_CURVE, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateDynEstYawrate)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_YWR, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateDynDrvrIntStrAngle)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_DRCRV, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateVehicleSpeed)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_VEL, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateDynLongVehAccel)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_ACCEL, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateDynStandStill)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_MSTAT, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateDynVehicleSpeedCorrected)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_VCORR, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateSideSlipAngle)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_SSA, sig_state, pDestVeh->State);
      sig_state = (true)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_LATACC, sig_state, pDestVeh->State);

      // Set return value to success
      bRet = true;
    }
    else if (((tpw_version == 7) || (tpw_version == 8)) && (ulPPortSize == SUPPORTED_SIZE[CConvVehDyn::TPW_INPUT_V7_8]))
    {
      const TPW_DYN_300::TPWInput_8_7_t * const pInput = reinterpret_cast<const TPW_DYN_300::TPWInput_8_7_t*>(pPPortData);

      // Go through signals in the order they are declared in VehDyn_t
      // Fill longitudinal signals
      pDestVeh->Longitudinal.MotVar.Velocity        = pInput->TPWMeasVehicleSpeed;
      pDestVeh->Longitudinal.MotVar.Accel           = pInput->TPWMeasEgoAcceleration;
      pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->TPWMeasVehicleSpeedVar;
      pDestVeh->Longitudinal.MotVar.varAccel        = pInput->TPWMeasEgoAccelerationVar;
      pDestVeh->Longitudinal.VeloCorr.corrFact      = 0.f;
      pDestVeh->Longitudinal.VeloCorr.corrVar       = 0.f;
      pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->TPWMeasVehicleSpeedCorrected;
      pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->TPWMeasVehicleSpeedCorrectedVar;
      pDestVeh->Longitudinal.VeloCorr.minVelo       = 0.f;
      pDestVeh->Longitudinal.VeloCorr.maxVelo       = 0.f;
      pDestVeh->Longitudinal.AccelCorr.corrAccel    = 0.f;
      pDestVeh->Longitudinal.AccelCorr.corrAccelVar = 0.f;
      // Yaw rate
      pDestVeh->Lateral.YawRate.YawRate   = pInput->YawRate.YawRate;
      pDestVeh->Lateral.YawRate.Variance  = pInput->YawRate.Variance;
      pDestVeh->Lateral.YawRate.Quality   = pInput->YawRate.Quality;
      // Set curvature
      pDestVeh->Lateral.Curve.Curve     = pInput->CurveStandard.Curve;
      pDestVeh->Lateral.Curve.C1        = 0.f;
      pDestVeh->Lateral.Curve.Gradient  = pInput->CurveStandard.Gradient;
      pDestVeh->Lateral.Curve.varC0     = pInput->CurveStandard.Variance;
      pDestVeh->Lateral.Curve.varC1     = DEFAULT_CURVE_VARIANCE;
      pDestVeh->Lateral.Curve.Quality   = pInput->CurveStandard.Quality;
      // Driver intented curvature
      pDestVeh->Lateral.DrvIntCurve.Curve       = pInput->DrvIntCrv.Curve;
      pDestVeh->Lateral.DrvIntCurve.Variance    = pInput->DrvIntCrv.Variance;
      pDestVeh->Lateral.DrvIntCurve.Gradient    = pInput->DrvIntCrv.Gradient;
      // Lateral acceleration
      pDestVeh->Lateral.Accel.LatAccel    = 0.f;
      pDestVeh->Lateral.Accel.Variance    = 0.f;
      // Side slip angle
      pDestVeh->Lateral.SlipAngle.SideSlipAngle = pInput->SideSlipAngle;
      pDestVeh->Lateral.SlipAngle.Variance      = pInput->SideSlipAngleVariance;
      // Motion state
      pDestVeh->MotionState.MotState    = pInput->MotionStates;
      pDestVeh->MotionState.Confidence  = pInput->MotionStatesConfidence;
      // Legacy
      pDestVeh->Legacy.YawRateMaxJitter = 0.f;
      pDestVeh->Legacy.bStandStill      = (pInput->MotionStates == VDY_LONG_MOT_STATE_STDST);
      // Set signal states
      sig_state = (pInput->SignalState.DynVehCourseCurve)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_CURVE, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynEstYawrate)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_YWR, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynDrvrIntStrAngle)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_DRCRV, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateVehicleSpeed)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_VEL, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynLongVehAccel)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_ACCEL, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynStandStill)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_MSTAT, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynVehicleSpeedCorrected)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_VCORR, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateSideSlipAngle)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_SSA, sig_state, pDestVeh->State);
      sig_state = (true)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_LATACC, sig_state, pDestVeh->State);

      // Set return value to success
      bRet = true;
    }
    else if ((tpw_version == 9) && (ulPPortSize == SUPPORTED_SIZE[CConvVehDyn::TPW_INPUT_V9]))
    {
      const TPW_DYN_300::TPWInput_V9_t * const pInput = reinterpret_cast<const TPW_DYN_300::TPWInput_V9_t*>(pPPortData);

      // Go through signals in the order they are declared in VehDyn_t
      // Fill longitudinal signals
      pDestVeh->Longitudinal.MotVar.Velocity        = pInput->TPWMeasVehicleSpeed;
      pDestVeh->Longitudinal.MotVar.Accel           = pInput->TPWMeasEgoAcceleration;
      pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->TPWMeasVehicleSpeedVar;
      pDestVeh->Longitudinal.MotVar.varAccel        = pInput->TPWMeasEgoAccelerationVar;
      pDestVeh->Longitudinal.VeloCorr.corrFact      = 0.f;
      pDestVeh->Longitudinal.VeloCorr.corrVar       = 0.f;
      pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->TPWMeasVehicleSpeedCorrected;
      pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->TPWMeasVehicleSpeedCorrectedVar;
      pDestVeh->Longitudinal.VeloCorr.minVelo       = 0.f;
      pDestVeh->Longitudinal.VeloCorr.maxVelo       = 0.f;
      pDestVeh->Longitudinal.AccelCorr.corrAccel    = 0.f;
      pDestVeh->Longitudinal.AccelCorr.corrAccelVar = 0.f;
      // Yaw rate
      pDestVeh->Lateral.YawRate.YawRate   = pInput->YawRate.YawRate;
      pDestVeh->Lateral.YawRate.Variance  = pInput->YawRate.Variance;
      pDestVeh->Lateral.YawRate.Quality   = pInput->YawRate.Quality;
      // Set curvature
      pDestVeh->Lateral.Curve.Curve     = pInput->CurveStandard.Curve;
      pDestVeh->Lateral.Curve.C1        = 0.f;
      pDestVeh->Lateral.Curve.Gradient  = pInput->CurveStandard.Gradient;
      pDestVeh->Lateral.Curve.varC0     = pInput->CurveStandard.Variance;
      pDestVeh->Lateral.Curve.varC1     = DEFAULT_CURVE_VARIANCE;
      pDestVeh->Lateral.Curve.Quality   = pInput->CurveStandard.Quality;
      // Driver intented curvature
      pDestVeh->Lateral.DrvIntCurve.Curve       = pInput->DrvIntCrv.Curve;
      pDestVeh->Lateral.DrvIntCurve.Variance    = pInput->DrvIntCrv.Variance;
      pDestVeh->Lateral.DrvIntCurve.Gradient    = pInput->DrvIntCrv.Gradient;
      // Lateral acceleration
      pDestVeh->Lateral.Accel.LatAccel    = 0.f;
      pDestVeh->Lateral.Accel.Variance    = 0.f;
      // Side slip angle
      pDestVeh->Lateral.SlipAngle.SideSlipAngle = pInput->SideSlipAngle;
      pDestVeh->Lateral.SlipAngle.Variance      = pInput->SideSlipAngleVariance;
      // Motion state
      pDestVeh->MotionState.MotState    = pInput->MotionStates;
      pDestVeh->MotionState.Confidence  = pInput->MotionStatesConfidence;
      // Legacy
      pDestVeh->Legacy.YawRateMaxJitter = 0.f;
      pDestVeh->Legacy.bStandStill      = (pInput->MotionStates == VDY_LONG_MOT_STATE_STDST);
      // Set signal states
      sig_state = (pInput->SignalState.DynVehCourseCurve)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_CURVE, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynEstYawrate)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_YWR, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynDrvrIntStrAngle)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_DRCRV, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateVehicleSpeed)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_VEL, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynLongVehAccel)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_ACCEL, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynStandStill)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_MSTAT, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynVehicleSpeedCorrected)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_VCORR, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateSideSlipAngle)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_SSA, sig_state, pDestVeh->State);
      sig_state = (true)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_LATACC, sig_state, pDestVeh->State);

      // Set return value to success
      bRet = true;
    }
    else if ((tpw_version == 10) && ((ulPPortSize == SUPPORTED_SIZE[CConvVehDyn::TPW_INPUT_V10]) || (ulPPortSize == SUPPORTED_SIZE[CConvVehDyn::TPW_INPUT_V10_253byte])))
    {
      const TPW_DYN_300::TPWInput_V10_t * const pInput = reinterpret_cast<const TPW_DYN_300::TPWInput_V10_t*>(pPPortData);

      // Go through signals in the order they are declared in VehDyn_t
      // Fill longitudinal signals
      pDestVeh->Longitudinal.MotVar.Velocity        = pInput->TPWMeasVehicleSpeed;
      pDestVeh->Longitudinal.MotVar.Accel           = pInput->TPWMeasEgoAcceleration;
      pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->TPWMeasVehicleSpeedVar;
      pDestVeh->Longitudinal.MotVar.varAccel        = pInput->TPWMeasEgoAccelerationVar;
      pDestVeh->Longitudinal.VeloCorr.corrFact      = 0.f;
      pDestVeh->Longitudinal.VeloCorr.corrVar       = 0.f;
      pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->TPWMeasVehicleSpeedCorrected;
      pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->TPWMeasVehicleSpeedCorrectedVar;
      pDestVeh->Longitudinal.VeloCorr.minVelo       = 0.f;
      pDestVeh->Longitudinal.VeloCorr.maxVelo       = 0.f;
      pDestVeh->Longitudinal.AccelCorr.corrAccel    = 0.f;
      pDestVeh->Longitudinal.AccelCorr.corrAccelVar = 0.f;
      // Yaw rate
      pDestVeh->Lateral.YawRate.YawRate   = pInput->YawRate.YawRate;
      pDestVeh->Lateral.YawRate.Variance  = pInput->YawRate.Variance;
      pDestVeh->Lateral.YawRate.Quality   = pInput->YawRate.Quality;
      // Set curvature
      pDestVeh->Lateral.Curve.Curve     = pInput->CurveStandard.Curve;
      pDestVeh->Lateral.Curve.C1        = 0.f;
      pDestVeh->Lateral.Curve.Gradient  = pInput->CurveStandard.Gradient;
      pDestVeh->Lateral.Curve.varC0     = pInput->CurveStandard.Variance;
      pDestVeh->Lateral.Curve.varC1     = DEFAULT_CURVE_VARIANCE;
      pDestVeh->Lateral.Curve.Quality   = pInput->CurveStandard.Quality;
      // Driver intented curvature
      pDestVeh->Lateral.DrvIntCurve.Curve       = pInput->DrvIntCrv.Curve;
      pDestVeh->Lateral.DrvIntCurve.Variance    = pInput->DrvIntCrv.Variance;
      pDestVeh->Lateral.DrvIntCurve.Gradient    = pInput->DrvIntCrv.Gradient;
      // Lateral acceleration
      pDestVeh->Lateral.Accel.LatAccel    = 0.f;
      pDestVeh->Lateral.Accel.Variance    = 0.f;
      // Side slip angle
      pDestVeh->Lateral.SlipAngle.SideSlipAngle = pInput->SideSlipAngle;
      pDestVeh->Lateral.SlipAngle.Variance      = pInput->SideSlipAngleVariance;
      // Motion state
      pDestVeh->MotionState.MotState    = pInput->MotionStates;
      pDestVeh->MotionState.Confidence  = pInput->MotionStatesConfidence;
      // Legacy
      pDestVeh->Legacy.YawRateMaxJitter = 0.f;
      pDestVeh->Legacy.bStandStill      = (pInput->MotionStates == VDY_LONG_MOT_STATE_STDST);
      // Set signal states
      sig_state = (pInput->SignalState.DynVehCourseCurve)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_CURVE, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynEstYawrate)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_YWR, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynDrvrIntStrAngle)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_DRCRV, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateVehicleSpeed)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_VEL, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynLongVehAccel)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_ACCEL, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynStandStill)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_MSTAT, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynVehicleSpeedCorrected)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_VCORR, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateSideSlipAngle)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_SSA, sig_state, pDestVeh->State);
      sig_state = (true)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_LATACC, sig_state, pDestVeh->State);

      // Set return value to success
      bRet = true;
    }
    else if ((tpw_version == 11) && (ulPPortSize == SUPPORTED_SIZE[CConvVehDyn::TPW_INPUT_V11]))
    {
      const TPW_DYN_300::TPWInput_V11_t * const pInput = reinterpret_cast<const TPW_DYN_300::TPWInput_V11_t*>(pPPortData);

      // Go through signals in the order they are declared in VehDyn_t
      // Fill longitudinal signals
      pDestVeh->Longitudinal.MotVar.Velocity        = pInput->TPWMeasVehicleSpeed;
      pDestVeh->Longitudinal.MotVar.Accel           = pInput->TPWMeasEgoAcceleration;
      pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->TPWMeasVehicleSpeedVar;
      pDestVeh->Longitudinal.MotVar.varAccel        = pInput->TPWMeasEgoAccelerationVar;
      pDestVeh->Longitudinal.VeloCorr.corrFact      = 0.f;
      pDestVeh->Longitudinal.VeloCorr.corrVar       = 0.f;
      pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->TPWMeasVehicleSpeedCorrected;
      pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->TPWMeasVehicleSpeedCorrectedVar;
      pDestVeh->Longitudinal.VeloCorr.minVelo       = 0.f;
      pDestVeh->Longitudinal.VeloCorr.maxVelo       = 0.f;
      pDestVeh->Longitudinal.AccelCorr.corrAccel    = 0.f;
      pDestVeh->Longitudinal.AccelCorr.corrAccelVar = 0.f;
      // Yaw rate
      pDestVeh->Lateral.YawRate.YawRate   = pInput->YawRate.YawRate;
      pDestVeh->Lateral.YawRate.Variance  = pInput->YawRate.Variance;
      pDestVeh->Lateral.YawRate.Quality   = pInput->YawRate.Quality;
      // Set curvature
      pDestVeh->Lateral.Curve.Curve     = pInput->CurveStandard.Curve;
      pDestVeh->Lateral.Curve.C1        = 0.f;
      pDestVeh->Lateral.Curve.Gradient  = pInput->CurveStandard.Gradient;
      pDestVeh->Lateral.Curve.varC0     = pInput->CurveStandard.Variance;
      pDestVeh->Lateral.Curve.varC1     = DEFAULT_CURVE_VARIANCE;
      pDestVeh->Lateral.Curve.Quality   = pInput->CurveStandard.Quality;
      // Driver intented curvature
      pDestVeh->Lateral.DrvIntCurve.Curve       = pInput->DrvIntCrv.Curve;
      pDestVeh->Lateral.DrvIntCurve.Variance    = pInput->DrvIntCrv.Variance;
      pDestVeh->Lateral.DrvIntCurve.Gradient    = pInput->DrvIntCrv.Gradient;
      // Lateral acceleration
      pDestVeh->Lateral.Accel.LatAccel    = 0.f;
      pDestVeh->Lateral.Accel.Variance    = 0.f;
      // Side slip angle
      pDestVeh->Lateral.SlipAngle.SideSlipAngle = pInput->SideSlipAngle;
      pDestVeh->Lateral.SlipAngle.Variance      = pInput->SideSlipAngleVariance;
      // Motion state
      pDestVeh->MotionState.MotState    = pInput->MotionStates;
      pDestVeh->MotionState.Confidence  = pInput->MotionStatesConfidence;
      // Legacy
      pDestVeh->Legacy.YawRateMaxJitter = 0.f;
      pDestVeh->Legacy.bStandStill      = (pInput->MotionStates == VDY_LONG_MOT_STATE_STDST);
      // Set signal states
      sig_state = (pInput->SignalState.DynVehCourseCurve)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_CURVE, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynEstYawrate)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_YWR, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynDrvrIntStrAngle)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_DRCRV, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateVehicleSpeed)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_VEL, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynLongVehAccel)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_ACCEL, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynStandStill)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_MSTAT, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalState.DynVehicleSpeedCorrected)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_VCORR, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateSideSlipAngle)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_SSA, sig_state, pDestVeh->State);
      sig_state = (true)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_LATACC, sig_state, pDestVeh->State);

      // Set return value to success
      bRet = true;
    }
    else if ((tpw_version == 6) && (ulPPortSize == SUPPORTED_SIZE[CConvVehDyn::TPW_INPUT_V6_350]))
    {
      const TPW_DYN_300::TPWInput_V6_ARS350_t * const pInput = reinterpret_cast<const TPW_DYN_300::TPWInput_V6_ARS350_t*>(pPPortData);

      // Go through signals in the order they are declared in VehDyn_t
      // Fill longitudinal signals
      pDestVeh->Longitudinal.MotVar.Velocity        = pInput->TPWMeasVehicleSpeed;
      pDestVeh->Longitudinal.MotVar.Accel           = pInput->TPWMeasEgoAcceleration;
      pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->TPWMeasVehicleSpeedVar;
      pDestVeh->Longitudinal.MotVar.varAccel        = pInput->TPWMeasEgoAccelerationVar;
      pDestVeh->Longitudinal.VeloCorr.corrFact      = 0.f;
      pDestVeh->Longitudinal.VeloCorr.corrVar       = 0.f;
      pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->TPWMeasVehicleSpeedCorrected;
      pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->TPWMeasVehicleSpeedCorrectedVar;
      pDestVeh->Longitudinal.VeloCorr.minVelo       = 0.f;
      pDestVeh->Longitudinal.VeloCorr.maxVelo       = 0.f;
      pDestVeh->Longitudinal.AccelCorr.corrAccel    = 0.f;
      pDestVeh->Longitudinal.AccelCorr.corrAccelVar = 0.f;
      // Yaw rate
      pDestVeh->Lateral.YawRate.YawRate   = pInput->EstYawRate;
      pDestVeh->Lateral.YawRate.Variance  = pInput->EstYawRateVariance;
      pDestVeh->Lateral.YawRate.Quality   = pInput->QualityYawRate;
      // Set curvature
      pDestVeh->Lateral.Curve.Curve     = pInput->CurveStandard;
      pDestVeh->Lateral.Curve.C1        = 0.f;
      pDestVeh->Lateral.Curve.Gradient  = pInput->GradientStandard;
      pDestVeh->Lateral.Curve.varC0     = DEFAULT_CURVE_VARIANCE;
      pDestVeh->Lateral.Curve.varC1     = DEFAULT_CURVE_VARIANCE;
      pDestVeh->Lateral.Curve.Quality   = pInput->QualityStandard;
      // Driver intented curvature
      pDestVeh->Lateral.DrvIntCurve.Curve       = pInput->DrvIntCrv;
      pDestVeh->Lateral.DrvIntCurve.Variance    = pInput->DrvIntCrvVariance;
      pDestVeh->Lateral.DrvIntCurve.Gradient    = pInput->DrvIntCrvGrad;
      // Lateral acceleration
      pDestVeh->Lateral.Accel.LatAccel    = 0.f;
      pDestVeh->Lateral.Accel.Variance    = 0.f;
      // Side slip angle
      pDestVeh->Lateral.SlipAngle.SideSlipAngle = pInput->SideSlipAngle;
      pDestVeh->Lateral.SlipAngle.Variance      = pInput->SideSlipAngleVariance;
      // Motion state
      pDestVeh->MotionState.MotState    = pInput->MotionStates;
      pDestVeh->MotionState.Confidence  = pInput->MotionStatesConfidence;
      // Legacy
      pDestVeh->Legacy.YawRateMaxJitter = 0.f;
      pDestVeh->Legacy.bStandStill      = (pInput->MotionStates == VDY_LONG_MOT_STATE_STDST);
      // Set signal states
      sig_state = (pInput->SignalStateDynVehCourseCurve)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_CURVE, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateDynEstYawrate)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_YWR, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateDynDrvrIntStrAngle)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_DRCRV, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateVehicleSpeed)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_VEL, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateDynLongVehAccel)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_ACCEL, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateDynStandStill)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_MSTAT, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateDynVehicleSpeedCorrected)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_VCORR, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateSideSlipAngle)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_SSA, sig_state, pDestVeh->State);
      sig_state = (true)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_LATACC, sig_state, pDestVeh->State);

      // Set return value to success
      bRet = true;
    }
    else if ((tpw_version == 7) && (ulPPortSize == SUPPORTED_SIZE[CConvVehDyn::TPW_INPUT_V7_350]))
    {
      const TPW_DYN_300::TPWInput_V7_ARS350_t * const pInput = reinterpret_cast<const TPW_DYN_300::TPWInput_V7_ARS350_t*>(pPPortData);

      // Go through signals in the order they are declared in VehDyn_t
      // Fill longitudinal signals
      pDestVeh->Longitudinal.MotVar.Velocity        = pInput->TPWMeasVehicleSpeed;
      pDestVeh->Longitudinal.MotVar.Accel           = pInput->TPWMeasEgoAcceleration;
      pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->TPWMeasVehicleSpeedVar;
      pDestVeh->Longitudinal.MotVar.varAccel        = pInput->TPWMeasEgoAccelerationVar;
      pDestVeh->Longitudinal.VeloCorr.corrFact      = 0.f;
      pDestVeh->Longitudinal.VeloCorr.corrVar       = 0.f;
      pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->TPWMeasVehicleSpeedCorrected;
      pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->TPWMeasVehicleSpeedCorrectedVar;
      pDestVeh->Longitudinal.VeloCorr.minVelo       = 0.f;
      pDestVeh->Longitudinal.VeloCorr.maxVelo       = 0.f;
      pDestVeh->Longitudinal.AccelCorr.corrAccel    = 0.f;
      pDestVeh->Longitudinal.AccelCorr.corrAccelVar = 0.f;
      // Yaw rate
      pDestVeh->Lateral.YawRate.YawRate   = pInput->EstYawRate;
      pDestVeh->Lateral.YawRate.Variance  = pInput->EstYawRateVariance;
      pDestVeh->Lateral.YawRate.Quality   = pInput->QualityYawRate;
      // Set curvature
      pDestVeh->Lateral.Curve.Curve     = pInput->CurveStandard;
      pDestVeh->Lateral.Curve.C1        = 0.f;
      pDestVeh->Lateral.Curve.Gradient  = pInput->GradientStandard;
      pDestVeh->Lateral.Curve.varC0     = DEFAULT_CURVE_VARIANCE;
      pDestVeh->Lateral.Curve.varC1     = DEFAULT_CURVE_VARIANCE;
      pDestVeh->Lateral.Curve.Quality   = pInput->QualityStandard;
      // Driver intented curvature
      pDestVeh->Lateral.DrvIntCurve.Curve       = pInput->DrvIntCrv;
      pDestVeh->Lateral.DrvIntCurve.Variance    = pInput->DrvIntCrvVariance;
      pDestVeh->Lateral.DrvIntCurve.Gradient    = pInput->DrvIntCrvGrad;
      // Lateral acceleration
      pDestVeh->Lateral.Accel.LatAccel    = 0.f;
      pDestVeh->Lateral.Accel.Variance    = 0.f;
      // Side slip angle
      pDestVeh->Lateral.SlipAngle.SideSlipAngle = pInput->SideSlipAngle;
      pDestVeh->Lateral.SlipAngle.Variance      = pInput->SideSlipAngleVariance;
      // Motion state
      pDestVeh->MotionState.MotState    = pInput->MotionStates;
      pDestVeh->MotionState.Confidence  = pInput->MotionStatesConfidence;
      // Legacy
      pDestVeh->Legacy.YawRateMaxJitter = 0.f;
      pDestVeh->Legacy.bStandStill      = (pInput->MotionStates == VDY_LONG_MOT_STATE_STDST);
      // Set signal states
      sig_state = (pInput->SignalStateDynVehCourseCurve)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_CURVE, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateDynEstYawrate)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_YWR, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateDynDrvrIntStrAngle)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_DRCRV, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateVehicleSpeed)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_VEL, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateDynLongVehAccel)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_ACCEL, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateDynStandStill)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_MSTAT, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateDynVehicleSpeedCorrected)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_VCORR, sig_state, pDestVeh->State);
      sig_state = (pInput->SignalStateSideSlipAngle)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_SSA, sig_state, pDestVeh->State);
      sig_state = (true)?(VDY_IO_STATE_VALID):(VDY_IO_STATE_INVALID);
      VDY_SET_IO_STATE(VDY_SOUT_POS_LATACC, sig_state, pDestVeh->State);

      // Set return value to success
      bRet = true;
    }
    else
    {
      // May be TPW, but we don't support it's version
      bRet = false;
    }
#if (CFG_TPW_INPUT_VALUE_MODIFY)
    if (bRet)
    {
      switch (tpw_version)
      {
      case 5:
        pDestVeh->Longitudinal.MotVar.varAccel      = 0.f;
        pDestVeh->Longitudinal.VeloCorr.corrVeloVar = 0.f;
        pDestVeh->Lateral.YawRate.Quality           = 1.f;
        pDestVeh->Lateral.Curve.Quality             = 1.f;
        sig_state = VDY_IO_STATE_VALID;
        VDY_SET_IO_STATE(VDY_SOUT_POS_ACCEL, sig_state, pDestVeh->State);
        VDY_SET_IO_STATE(VDY_SOUT_POS_VCORR, sig_state, pDestVeh->State);
        VDY_SET_IO_STATE(VDY_SOUT_POS_YWR, sig_state, pDestVeh->State);
        VDY_SET_IO_STATE(VDY_SOUT_POS_CURVE, sig_state, pDestVeh->State);
        VDY_SET_IO_STATE(VDY_SOUT_POS_DRCRV, sig_state, pDestVeh->State);
        VDY_SET_IO_STATE(VDY_SOUT_POS_MSTAT, sig_state, pDestVeh->State);
        break;
      case 6:
        pDestVeh->Lateral.YawRate.Quality   = 1.f;
        pDestVeh->Lateral.Curve.Quality     = 1.f;
        break;
      }
      // Evaluate signal states and restore previous values when signal states invalid
      if (VDY_GET_IO_STATE(VDY_SOUT_POS_CURVE, pDestVeh->State) != VDY_IO_STATE_VALID)
      {
        pDestVeh->Lateral.Curve = VehDynBackup.Lateral.Curve;
      }
      if (VDY_GET_IO_STATE(VDY_SOUT_POS_YWR, pDestVeh->State) != VDY_IO_STATE_VALID)
      {
        pDestVeh->Lateral.YawRate = VehDynBackup.Lateral.YawRate;
      }
      if (VDY_GET_IO_STATE(VDY_SOUT_POS_DRCRV, pDestVeh->State) != VDY_IO_STATE_VALID)
      {
        pDestVeh->Lateral.DrvIntCurve = VehDynBackup.Lateral.DrvIntCurve;
      }
      if (VDY_GET_IO_STATE(VDY_SOUT_POS_SSA, pDestVeh->State) != VDY_IO_STATE_VALID)
      {
        pDestVeh->Lateral.SlipAngle = VehDynBackup.Lateral.SlipAngle;
      }
      if (VDY_GET_IO_STATE(VDY_SOUT_POS_VEL, pDestVeh->State) != VDY_IO_STATE_VALID)
      {
        pDestVeh->Longitudinal.MotVar.Velocity    = VehDynBackup.Longitudinal.MotVar.Velocity;
        pDestVeh->Longitudinal.MotVar.varVelocity = VehDynBackup.Longitudinal.MotVar.varVelocity;
      }
      if (VDY_GET_IO_STATE(VDY_SOUT_POS_ACCEL, pDestVeh->State) != VDY_IO_STATE_VALID)
      {
        pDestVeh->Longitudinal.MotVar.Accel     = VehDynBackup.Longitudinal.MotVar.Accel;
        pDestVeh->Longitudinal.MotVar.varAccel  = VehDynBackup.Longitudinal.MotVar.varAccel;
      }
      if (VDY_GET_IO_STATE(VDY_SOUT_POS_MSTAT, pDestVeh->State) != VDY_IO_STATE_VALID)
      {
        pDestVeh->MotionState = VehDynBackup.MotionState;
      }
      if (VDY_GET_IO_STATE(VDY_SOUT_POS_VCORR, pDestVeh->State) != VDY_IO_STATE_VALID)
      {
        pDestVeh->Longitudinal.VeloCorr = VehDynBackup.Longitudinal.VeloCorr;
      }
      // When moving reverse negate the corrected velocity and acceleration, if the
      // velocity isn't already negative
      if (pDestVeh->MotionState.MotState == VDY_LONG_MOT_STATE_MOVE_RWD)
      {
        if (pDestVeh->Longitudinal.VeloCorr.corrVelo > 0)
        {
          pDestVeh->Longitudinal.VeloCorr.corrVelo    = -pDestVeh->Longitudinal.VeloCorr.corrVelo;
          pDestVeh->Longitudinal.AccelCorr.corrAccel  = -pDestVeh->Longitudinal.AccelCorr.corrAccel;
        }
      }
    }
#endif
  }
  else
  {
    // Data too short (4 bytes only), can not be TPWinput
    bRet = false;
  }
  return bRet;
}

bool CConvVehDyn::DecodeVDYOutput(VehDynV2::VehDyn_t * const pVehDyn, SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const void * const pPPortData)
{
  bool bRet = false;

  // VDYinput can be decoded if the type is opaque and at least the 4 byte
  // version number is decodable
  if ((ePPortType == simOPAQUE_t) && (ulPPortSize > 4))
  {
    // const uint32 vdy_version = *reinterpret_cast<const uint32*>(pPPortData);
    // Initialize default values
    InitDefaultVehDynV2(pVehDyn);

    if (ulPPortSize == SUPPORTED_SIZE_VDY_OUTPUT[CConvVehDyn::VDY_OUT_V1])
    {
      const VDY_DYN_300::VDYOutputData_v1_t* const pTyped = reinterpret_cast< const VDY_DYN_300::VDYOutputData_v1_t*>(pPPortData);
      pVehDyn->Longitudinal.MotVar.Velocity = pTyped->MotVar.Velocity;
      pVehDyn->Longitudinal.VeloCorr.corrVelo = pTyped->VelocityCorr.corrVelo;
      pVehDyn->Longitudinal.MotVar.Accel = pTyped->MotVar.Accel;

      bRet = true;
    }
    else if (ulPPortSize == SUPPORTED_SIZE_VDY_OUTPUT[CConvVehDyn::VDY_OUT_V2])
    {
      const VDY_DYN_300::VDYOutputData_v2_t* const pTyped = reinterpret_cast<const VDY_DYN_300::VDYOutputData_v2_t*>(pPPortData);
      pVehDyn->Longitudinal.MotVar.Velocity = pTyped->MotVar.Velocity;
      pVehDyn->Longitudinal.VeloCorr.corrVelo = pTyped->VelocityCorr.corrVelo;
      pVehDyn->Longitudinal.MotVar.Accel = pTyped->MotVar.Accel;

      bRet = true;
    }
    else if (ulPPortSize == SUPPORTED_SIZE_VDY_OUTPUT[CConvVehDyn::VDY_OUT_V3])
    {
      const VDY_DYN_300::VDYOutputData_v3_t* const pTyped = reinterpret_cast<const VDY_DYN_300::VDYOutputData_v3_t*>(pPPortData);
      pVehDyn->Longitudinal.MotVar.Velocity = pTyped->MotVar.Velocity;
      pVehDyn->Longitudinal.VeloCorr.corrVelo = pTyped->VelocityCorr.corrVelo;
      pVehDyn->Longitudinal.MotVar.Accel = pTyped->MotVar.Accel;

      bRet = true;
    }
    else
    {
      bRet = false;
    }
  }
  else
  {
    bRet = false;
  }
  return bRet;
}

bool CConvVehDyn::DecodeRSPInputVDATA(VehDynV2::VehDyn_t * const pVehDyn, SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const void * const pPPortData)
{
  bool bRet = false;
  unsigned int  *pInterfVer;
  // VDYinput can be decoded if the type is opaque and at least the 4 byte
  // version number is decodable
  if ((ePPortType == simOPAQUE_t) && (ulPPortSize > 4))
  {
    // const uint32 vdy_version = *reinterpret_cast<const uint32*>(pPPortData);
    // Initialize default values
    InitDefaultVehDynV2(pVehDyn);

    pInterfVer = (unsigned int*) pPPortData;

    if (*pInterfVer == 2u) //( ulPPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_IV2] )
    {
      const RSP_DYN_300::RSPInputVData_t_IV2* const pTyped     = (const RSP_DYN_300::RSPInputVData_t_IV2*) pPPortData;

      pVehDyn->uiVersionNumber                    = pTyped->InterfaceVersion;
      pVehDyn->Longitudinal.VeloCorr.corrVelo     = pTyped->VehicleSpeedCorr;
      pVehDyn->Longitudinal.VeloCorr.corrVeloVar  = pTyped->VehicleSpeedCorrVar;
      pVehDyn->Longitudinal.VeloCorr.maxVelo      = pTyped->VehicleSpeedCorrMax;
      pVehDyn->Longitudinal.VeloCorr.minVelo      = pTyped->VehicleSpeedCorrMin;
      pVehDyn->Longitudinal.MotVar.Accel          = pTyped->VehicleLongAccel;
      pVehDyn->Longitudinal.MotVar.varAccel       = pTyped->VehicleLongAccelVar;
      pVehDyn->Lateral.Curve.Curve                = pTyped->Curve.Curve;

      switch (pTyped->MotionState)
      {
      case RSP_M_STATE_REV:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_RWD;
        break;
      case RSP_M_STATE_FWD:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
        break;
      case RSP_M_STATE_STDSTL:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_STDST;
        break;
      case RSP_M_STATE_UNCLEAR:
      default:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE;
        break;
      }
      pVehDyn->MotionState.Confidence  = pTyped->MotionStateConf;

      bRet = true;
    }
    else if(*pInterfVer == 3u) //( ulPPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_IV3] )
    {
      RSP_DYN_300::RSPInputVData_t_IV3* pTyped                 = (RSP_DYN_300::RSPInputVData_t_IV3*) pPPortData;
      pVehDyn->uiVersionNumber                    = pTyped->InterfaceVersion;
      pVehDyn->Longitudinal.VeloCorr.corrVelo     = pTyped->VehicleSpeedCorr;
      pVehDyn->Longitudinal.VeloCorr.corrVeloVar  = pTyped->VehicleSpeedCorrVar;
      pVehDyn->Longitudinal.VeloCorr.maxVelo      = pTyped->VehicleSpeedCorrMax;
      pVehDyn->Longitudinal.VeloCorr.minVelo      = pTyped->VehicleSpeedCorrMin;
      pVehDyn->Longitudinal.MotVar.Accel          = pTyped->VehicleLongAccel;
      pVehDyn->Longitudinal.MotVar.varAccel       = pTyped->VehicleLongAccelVar;
      pVehDyn->Lateral.Curve.Curve                = pTyped->Curve.Curve;

      switch (pTyped->MotionState)
      {
      case RSP_M_STATE_REV:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_RWD;
        break;
      case RSP_M_STATE_FWD:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
        break;
      case RSP_M_STATE_STDSTL:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_STDST;
        break;
      case RSP_M_STATE_UNCLEAR:
      default:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE;
        break;
      }
      pVehDyn->MotionState.Confidence  = pTyped->MotionStateConf;

      bRet = true;
    }
    else if(*pInterfVer == 4u) //( ulPPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_IV4] )
    {
      RSP_DYN_300::RSPInputVData_t_IV4* pTyped                 = (RSP_DYN_300::RSPInputVData_t_IV4*) pPPortData;
      pVehDyn->uiVersionNumber                    = pTyped->InterfaceVersion;
      pVehDyn->Longitudinal.VeloCorr.corrVelo     = pTyped->VehicleSpeedCorr;
      pVehDyn->Longitudinal.VeloCorr.corrVeloVar  = pTyped->VehicleSpeedCorrVar;
      pVehDyn->Longitudinal.VeloCorr.maxVelo      = pTyped->VehicleSpeedCorrMax;
      pVehDyn->Longitudinal.VeloCorr.minVelo      = pTyped->VehicleSpeedCorrMin;
      pVehDyn->Longitudinal.MotVar.Accel          = pTyped->VehicleLongAccel;
      pVehDyn->Longitudinal.MotVar.varAccel       = pTyped->VehicleLongAccelVar;
      pVehDyn->Lateral.Curve.Curve                = pTyped->Curve.Curve;
      pVehDyn->Lateral.Curve.varC0                = pTyped->Curve.Variance;
      pVehDyn->Lateral.YawRate.YawRate            = pTyped->YawRate.YawRate;
      pVehDyn->Lateral.YawRate.Variance           = pTyped->YawRate.Variance;

      switch (pTyped->MotionState)
      {
      case RSP_M_STATE_REV:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_RWD;
        break;
      case RSP_M_STATE_FWD:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
        break;
      case RSP_M_STATE_STDSTL:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_STDST;
        break;
      case RSP_M_STATE_UNCLEAR:
      default:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE;
        break;
      }
      pVehDyn->MotionState.Confidence  = pTyped->MotionStateConf;

      bRet = true;
    }
    else if(*pInterfVer == 5u) //( ulPPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_IV5] )
    {
      RSP_DYN_300::RSPInputVData_t_IV5* pTyped                 = (RSP_DYN_300::RSPInputVData_t_IV5*) pPPortData;
      pVehDyn->uiVersionNumber                    = pTyped->InterfaceVersion;
      pVehDyn->Longitudinal.VeloCorr.corrVelo     = pTyped->VehicleSpeedCorr;
      pVehDyn->Longitudinal.VeloCorr.corrVeloVar  = pTyped->VehicleSpeedCorrVar;
      pVehDyn->Longitudinal.VeloCorr.maxVelo      = pTyped->VehicleSpeedCorrMax;
      pVehDyn->Longitudinal.VeloCorr.minVelo      = pTyped->VehicleSpeedCorrMin;
      pVehDyn->Longitudinal.MotVar.Accel          = pTyped->VehicleLongAccel;
      pVehDyn->Longitudinal.MotVar.varAccel       = pTyped->VehicleLongAccelVar;
      pVehDyn->Lateral.Curve.Curve                = pTyped->Curve.Curve;
      pVehDyn->Lateral.Curve.varC0                = pTyped->Curve.Variance;
      pVehDyn->Lateral.YawRate.YawRate            = pTyped->YawRate.YawRate;
      pVehDyn->Lateral.YawRate.Variance           = pTyped->YawRate.Variance;

      switch (pTyped->MotionState)
      {
      case RSP_M_STATE_REV:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_RWD;
        break;
      case RSP_M_STATE_FWD:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
        break;
      case RSP_M_STATE_STDSTL:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_STDST;
        break;
      case RSP_M_STATE_UNCLEAR:
      default:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE;
        break;
      }
      pVehDyn->MotionState.Confidence  = pTyped->MotionStateConf;

      bRet = true;
    }
    else if (*pInterfVer == 6u) //( ulPPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_IV6] )
    {
      RSP_DYN_300::RSPInputVData_t_IV6* pTyped                 = (RSP_DYN_300::RSPInputVData_t_IV6*) pPPortData;
      pVehDyn->uiVersionNumber                    = pTyped->InterfaceVersion;
      pVehDyn->Longitudinal.VeloCorr.corrVelo     = pTyped->VehicleSpeedCorr;
      pVehDyn->Longitudinal.VeloCorr.corrVeloVar  = pTyped->VehicleSpeedCorrVar;
      pVehDyn->Longitudinal.VeloCorr.maxVelo      = pTyped->VehicleSpeedCorrMax;
      pVehDyn->Longitudinal.VeloCorr.minVelo      = pTyped->VehicleSpeedCorrMin;
      pVehDyn->Longitudinal.MotVar.Accel          = pTyped->VehicleLongAccel;
      pVehDyn->Longitudinal.MotVar.varAccel       = pTyped->VehicleLongAccelVar;
      pVehDyn->Lateral.Curve.Curve                = pTyped->Curve.Curve;
      pVehDyn->Lateral.Curve.varC0                = pTyped->Curve.Variance;
      pVehDyn->Lateral.YawRate.YawRate            = pTyped->YawRate.Vehicle.YawRate;
      pVehDyn->Lateral.YawRate.Variance           = pTyped->YawRate.Vehicle.Variance;
      pVehDyn->Lateral.YawRate.Quality            = pTyped->YawRate.Vehicle.Quality;

      switch (pTyped->MotionState)
      {
      case RSP_M_STATE_REV:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_RWD;
        break;
      case RSP_M_STATE_FWD:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
        break;
      case RSP_M_STATE_STDSTL:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_STDST;
        break;
      case RSP_M_STATE_UNCLEAR:
      default:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE;
        break;
      }
      pVehDyn->MotionState.Confidence  = pTyped->MotionStateConf;

      bRet = true;
    }
    else if (*pInterfVer == 7u)//(ulPPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_IV7] )
    {
      RSP_DYN_300::RSPInputVData_t_IV7* pTyped                 = (RSP_DYN_300::RSPInputVData_t_IV7*) pPPortData;
      pVehDyn->uiVersionNumber                    = pTyped->InterfaceVersion;
      pVehDyn->Longitudinal.VeloCorr.corrVelo     = pTyped->VehicleSpeedCorr;
      pVehDyn->Longitudinal.VeloCorr.corrVeloVar  = pTyped->VehicleSpeedCorrVar;
      pVehDyn->Longitudinal.VeloCorr.maxVelo      = pTyped->VehicleSpeedCorrMax;
      pVehDyn->Longitudinal.VeloCorr.minVelo      = pTyped->VehicleSpeedCorrMin;
      pVehDyn->Longitudinal.MotVar.Accel          = pTyped->VehicleLongAccel;
      pVehDyn->Longitudinal.MotVar.varAccel       = pTyped->VehicleLongAccelVar;
      pVehDyn->Lateral.Curve.Curve                = pTyped->Curve.Curve;
      pVehDyn->Lateral.Curve.varC0                = pTyped->Curve.Variance;
      pVehDyn->Lateral.YawRate.YawRate            = pTyped->YawRate.Vehicle.YawRate;
      pVehDyn->Lateral.YawRate.Variance           = pTyped->YawRate.Vehicle.Variance;
      pVehDyn->Lateral.YawRate.Quality            = pTyped->YawRate.Vehicle.Quality;

      switch (pTyped->MotionState)
      {
      case RSP_M_STATE_REV:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_RWD;
        break;
      case RSP_M_STATE_FWD:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
        break;
      case RSP_M_STATE_STDSTL:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_STDST;
        break;
      case RSP_M_STATE_UNCLEAR:
      default:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE;
        break;
      }
      pVehDyn->MotionState.Confidence  = pTyped->MotionStateConf;

      bRet = true;
    }
    else if (*pInterfVer == 8u) //( ulPPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_IV8] )
    {
      RSP_DYN_300::RSPInputVData_t_IV8* pTyped                 = (RSP_DYN_300::RSPInputVData_t_IV8*) pPPortData;
      pVehDyn->uiVersionNumber                    = pTyped->InterfaceVersion;
      pVehDyn->Longitudinal.VeloCorr.corrVelo     = pTyped->VehicleSpeedCorr;
      pVehDyn->Longitudinal.VeloCorr.corrVeloVar  = pTyped->VehicleSpeedCorrVar;
      pVehDyn->Longitudinal.VeloCorr.maxVelo      = pTyped->VehicleSpeedCorrMax;
      pVehDyn->Longitudinal.VeloCorr.minVelo      = pTyped->VehicleSpeedCorrMin;
      pVehDyn->Longitudinal.MotVar.Accel          = pTyped->VehicleLongAccel;
      pVehDyn->Longitudinal.MotVar.varAccel       = pTyped->VehicleLongAccelVar;
      pVehDyn->Lateral.Curve.Curve                = pTyped->Curve.Curve;
      pVehDyn->Lateral.Curve.varC0                = pTyped->Curve.Variance;
      pVehDyn->Lateral.YawRate.YawRate            = pTyped->YawRate.Vehicle.YawRate;
      pVehDyn->Lateral.YawRate.Variance           = pTyped->YawRate.Vehicle.Variance;
      pVehDyn->Lateral.YawRate.Quality            = pTyped->YawRate.Vehicle.Quality;

      switch (pTyped->MotionState)
      {
      case RSP_M_STATE_REV:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_RWD;
        break;
      case RSP_M_STATE_FWD:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
        break;
      case RSP_M_STATE_STDSTL:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_STDST;
        break;
      case RSP_M_STATE_UNCLEAR:
      default:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE;
        break;
      }
      pVehDyn->MotionState.Confidence  = pTyped->MotionStateConf;

      bRet = true;
    }
    else if( ulPPortSize == SUPPORTED_SIZE_RSP_INPUT_VDATA[RSP_INPUT_VDATA_IVL] )
    {
      RSP_DYN_300::RSPInputVData_t_IVL* pTyped                 = (RSP_DYN_300::RSPInputVData_t_IVL*) pPPortData;
      pVehDyn->uiVersionNumber                    = pTyped->InterfaceVersion;
      pVehDyn->Longitudinal.VeloCorr.corrVelo     = pTyped->VData.VehicleSpeedCorr;
      pVehDyn->Longitudinal.VeloCorr.corrVeloVar  = pTyped->VData.VehicleSpeedCorrVar;
      pVehDyn->Longitudinal.VeloCorr.maxVelo      = pTyped->VData.VehicleSpeedCorrMax;
      pVehDyn->Longitudinal.VeloCorr.minVelo      = pTyped->VData.VehicleSpeedCorrMin;
      pVehDyn->Longitudinal.MotVar.Accel          = pTyped->VData.VehicleLongAccel;
      pVehDyn->Longitudinal.MotVar.varAccel       = pTyped->VData.VehicleLongAccelVar;
      pVehDyn->Lateral.Curve.Curve                = pTyped->VData.Curve.Curve;
      pVehDyn->Lateral.Curve.varC0                = pTyped->VData.Curve.Variance;
      pVehDyn->Lateral.YawRate.YawRate            = pTyped->VData.YawRate.Vehicle.YawRate;
      pVehDyn->Lateral.YawRate.Variance           = pTyped->VData.YawRate.Vehicle.Variance;
      pVehDyn->Lateral.YawRate.Quality            = pTyped->VData.YawRate.Vehicle.Quality;

      switch (pTyped->VData.MotionState)
      {
      case RSP_M_STATE_REV:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_RWD;
        break;
      case RSP_M_STATE_FWD:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE_FWD;
        break;
      case RSP_M_STATE_STDSTL:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_STDST;
        break;
      case RSP_M_STATE_UNCLEAR:
      default:
        pVehDyn->MotionState.MotState = VDY_LONG_MOT_STATE_MOVE;
        break;
      }
      pVehDyn->MotionState.Confidence  = pTyped->VData.MotionStateConf;

      bRet = true;
    }
    else
    {
      bRet = false;
    }
  }
  else
  {
    bRet = false;
  }
  return bRet;

}
void CConvVehDyn::ConvertToVehDynV0(VehDynV0::VehDyn_t * const pDestVeh, const VehDynV1::VehDyn_t * const pInput)
{
  InitDefaultVehDynV0(pDestVeh);
  pDestVeh->TimeStamp       = pInput->TimeStamp;
  pDestVeh->Version         = 0;
  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;
  pDestVeh->Legacy.SenYawRate.YawRate           = 0.F;
  pDestVeh->Legacy.SenYawRate.Variance          = 0.F;
  pDestVeh->Legacy.SenYawRate.Quality           = 0.F;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->State[0]                            = pInput->State[0];
  pDestVeh->State[1]                            = pInput->State[1];
  pDestVeh->States.bVelocityX                   = pInput->States.bVelocityX;
  pDestVeh->States.bVelocityXCorr               = pInput->States.bVelocityXCorr;
  pDestVeh->States.bAccelY                      = pInput->States.bAccelY;
  pDestVeh->States.bAccelX                      = pInput->States.bAccelX;
  pDestVeh->States.bAccelXCorr                  = pInput->States.bAccelXCorr;
  pDestVeh->States.bYawRate                     = pInput->States.bYawRate;
  pDestVeh->States.bSenYawRate                  = pInput->States.bSenYawRate;
  pDestVeh->States.bCurve                       = pInput->States.bCurve;
  pDestVeh->States.bDrvIntCurve                 = pInput->States.bDrvIntCurve;
  pDestVeh->States.bSideSlipAngle               = pInput->States.bSideSlipAngle;
  pDestVeh->States.bMotionState                 = pInput->States.bMotionState;
}

void CConvVehDyn::ConvertToVehDynV0(VehDynV0::VehDyn_t * const pDestVeh, const VehDynV2::VehDyn_t * const pInput)
{
  InitDefaultVehDynV0(pDestVeh);
  pDestVeh->TimeStamp       = pInput->uiTimeStamp;
  pDestVeh->Version         = 0;
  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;
  pDestVeh->Legacy.SenYawRate.YawRate           = 0.F;
  pDestVeh->Legacy.SenYawRate.Variance          = 0.F;
  pDestVeh->Legacy.SenYawRate.Quality           = 0.F;
  pDestVeh->State[0]                            = pInput->State[0];
  pDestVeh->State[1]                            = pInput->State[1];
  pDestVeh->States.bVelocityX                   = (VDY_GET_IO_STATE(VDY_SOUT_POS_VEL, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bVelocityXCorr               = (VDY_GET_IO_STATE(VDY_SOUT_POS_VCORR, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bAccelY                      = (VDY_GET_IO_STATE(VDY_SOUT_POS_LATACC, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bAccelX                      = (VDY_GET_IO_STATE(VDY_SOUT_POS_ACCEL, pInput->State) == VDY_IO_STATE_VALID);
  // Acceleration X corrected not available seperately in states array
  pDestVeh->States.bAccelXCorr                  = (VDY_GET_IO_STATE(VDY_SOUT_POS_VCORR, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bYawRate                     = (VDY_GET_IO_STATE(VDY_SOUT_POS_YWR, pInput->State) == VDY_IO_STATE_VALID);
  // Note: SenYawRate not available seperately in states array
  pDestVeh->States.bSenYawRate                  = (VDY_GET_IO_STATE(VDY_SOUT_POS_YWR, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bCurve                       = (VDY_GET_IO_STATE(VDY_SOUT_POS_CURVE, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bDrvIntCurve                 = (VDY_GET_IO_STATE(VDY_SOUT_POS_DRCRV, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bSideSlipAngle               = (VDY_GET_IO_STATE(VDY_SOUT_POS_SSA, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bMotionState                 = (VDY_GET_IO_STATE(VDY_SOUT_POS_MSTAT, pInput->State) == VDY_IO_STATE_VALID);
}

void CConvVehDyn::ConvertToVehDynV0(VehDynV0::VehDyn_t * const pDestVeh, const VehDynV3::VehDyn_t * const pInput)
{
  InitDefaultVehDynV0(pDestVeh);
  pDestVeh->TimeStamp       = pInput->uiTimeStamp;
  pDestVeh->Version         = 0;
  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;
  pDestVeh->Legacy.SenYawRate.YawRate           = 0.F;
  pDestVeh->Legacy.SenYawRate.Variance          = 0.F;
  pDestVeh->Legacy.SenYawRate.Quality           = 0.F;
  pDestVeh->State[0]                            = pInput->State[0];
  pDestVeh->State[1]                            = pInput->State[1];
  pDestVeh->States.bVelocityX                   = (VDY_GET_IO_STATE(VDY_SOUT_POS_VEL, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bVelocityXCorr               = (VDY_GET_IO_STATE(VDY_SOUT_POS_VCORR, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bAccelY                      = (VDY_GET_IO_STATE(VDY_SOUT_POS_LATACC, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bAccelX                      = (VDY_GET_IO_STATE(VDY_SOUT_POS_ACCEL, pInput->State) == VDY_IO_STATE_VALID);
  // Acceleration X corrected not available seperately in states array
  pDestVeh->States.bAccelXCorr                  = (VDY_GET_IO_STATE(VDY_SOUT_POS_VCORR, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bYawRate                     = (VDY_GET_IO_STATE(VDY_SOUT_POS_YWR, pInput->State) == VDY_IO_STATE_VALID);
  // Note: SenYawRate not available seperately in states array
  pDestVeh->States.bSenYawRate                  = (VDY_GET_IO_STATE(VDY_SOUT_POS_YWR, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bCurve                       = (VDY_GET_IO_STATE(VDY_SOUT_POS_CURVE, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bDrvIntCurve                 = (VDY_GET_IO_STATE(VDY_SOUT_POS_DRCRV, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bSideSlipAngle               = (VDY_GET_IO_STATE(VDY_SOUT_POS_SSA, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bMotionState                 = (VDY_GET_IO_STATE(VDY_SOUT_POS_MSTAT, pInput->State) == VDY_IO_STATE_VALID);
}

void CConvVehDyn::ConvertToVehDynV1(VehDynV1::VehDyn_t * const pDestVeh, const VehDynV0::VehDyn_t * const pInput)
{
  InitDefaultVehDynV1(pDestVeh);
  pDestVeh->uiVersionNumber = 1u;
  pDestVeh->TimeStamp       = pInput->TimeStamp;
  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;
  pDestVeh->State[0]                            = pInput->State[0];
  pDestVeh->State[1]                            = pInput->State[1];
  pDestVeh->States.bVelocityX                   = pInput->States.bVelocityX;
  pDestVeh->States.bVelocityXCorr               = pInput->States.bVelocityXCorr;
  pDestVeh->States.bAccelY                      = pInput->States.bAccelY;
  pDestVeh->States.bAccelX                      = pInput->States.bAccelX;
  pDestVeh->States.bAccelXCorr                  = pInput->States.bAccelXCorr;
  pDestVeh->States.bYawRate                     = pInput->States.bYawRate;
  pDestVeh->States.bSenYawRate                  = pInput->States.bSenYawRate;
  pDestVeh->States.bCurve                       = pInput->States.bCurve;
  pDestVeh->States.bDrvIntCurve                 = pInput->States.bDrvIntCurve;
  pDestVeh->States.bSideSlipAngle               = pInput->States.bSideSlipAngle;
  pDestVeh->States.bMotionState                 = pInput->States.bMotionState;
}

void CConvVehDyn::ConvertToVehDynV1(VehDynV1::VehDyn_t * const pDestVeh, const VehDynV2::VehDyn_t * const pInput)
{
  InitDefaultVehDynV1(pDestVeh);
  pDestVeh->uiVersionNumber = 1u;
  pDestVeh->TimeStamp       = pInput->uiTimeStamp;
  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;
  pDestVeh->State[0]                            = pInput->State[0];
  pDestVeh->State[1]                            = pInput->State[1];
  pDestVeh->States.bVelocityX                   = (VDY_GET_IO_STATE(VDY_SOUT_POS_VEL, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bVelocityXCorr               = (VDY_GET_IO_STATE(VDY_SOUT_POS_VCORR, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bAccelY                      = (VDY_GET_IO_STATE(VDY_SOUT_POS_LATACC, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bAccelX                      = (VDY_GET_IO_STATE(VDY_SOUT_POS_ACCEL, pInput->State) == VDY_IO_STATE_VALID);
  // Acceleration X corrected not available seperately in states array
  pDestVeh->States.bAccelXCorr                  = (VDY_GET_IO_STATE(VDY_SOUT_POS_VCORR, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bYawRate                     = (VDY_GET_IO_STATE(VDY_SOUT_POS_YWR, pInput->State) == VDY_IO_STATE_VALID);
  // Note: SenYawRate not available seperately in states array
  pDestVeh->States.bSenYawRate                  = (VDY_GET_IO_STATE(VDY_SOUT_POS_YWR, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bCurve                       = (VDY_GET_IO_STATE(VDY_SOUT_POS_CURVE, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bDrvIntCurve                 = (VDY_GET_IO_STATE(VDY_SOUT_POS_DRCRV, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bSideSlipAngle               = (VDY_GET_IO_STATE(VDY_SOUT_POS_SSA, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bMotionState                 = (VDY_GET_IO_STATE(VDY_SOUT_POS_MSTAT, pInput->State) == VDY_IO_STATE_VALID);
}

void CConvVehDyn::ConvertToVehDynV1(VehDynV1::VehDyn_t * const pDestVeh, const VehDynV3::VehDyn_t * const pInput)
{
  InitDefaultVehDynV1(pDestVeh);
  pDestVeh->uiVersionNumber = 1u;
  pDestVeh->TimeStamp       = pInput->uiTimeStamp;
  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;
  pDestVeh->State[0]                            = pInput->State[0];
  pDestVeh->State[1]                            = pInput->State[1];
  pDestVeh->States.bVelocityX                   = (VDY_GET_IO_STATE(VDY_SOUT_POS_VEL, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bVelocityXCorr               = (VDY_GET_IO_STATE(VDY_SOUT_POS_VCORR, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bAccelY                      = (VDY_GET_IO_STATE(VDY_SOUT_POS_LATACC, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bAccelX                      = (VDY_GET_IO_STATE(VDY_SOUT_POS_ACCEL, pInput->State) == VDY_IO_STATE_VALID);
  // Acceleration X corrected not available seperately in states array
  pDestVeh->States.bAccelXCorr                  = (VDY_GET_IO_STATE(VDY_SOUT_POS_VCORR, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bYawRate                     = (VDY_GET_IO_STATE(VDY_SOUT_POS_YWR, pInput->State) == VDY_IO_STATE_VALID);
  // Note: SenYawRate not available seperately in states array
  pDestVeh->States.bSenYawRate                  = (VDY_GET_IO_STATE(VDY_SOUT_POS_YWR, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bCurve                       = (VDY_GET_IO_STATE(VDY_SOUT_POS_CURVE, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bDrvIntCurve                 = (VDY_GET_IO_STATE(VDY_SOUT_POS_DRCRV, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bSideSlipAngle               = (VDY_GET_IO_STATE(VDY_SOUT_POS_SSA, pInput->State) == VDY_IO_STATE_VALID);
  pDestVeh->States.bMotionState                 = (VDY_GET_IO_STATE(VDY_SOUT_POS_MSTAT, pInput->State) == VDY_IO_STATE_VALID);
}

void CConvVehDyn::ConvertToVehDynV2(VehDynV2::VehDyn_t * const pDestVeh, const VehDynV0::VehDyn_t * const pInput)
{
  InitDefaultVehDynV2(pDestVeh);
  pDestVeh->uiVersionNumber = 2u;
  pDestVeh->uiTimeStamp     = (VehDynV2::AlgoDataTimeStamp_t)pInput->TimeStamp;
  pDestVeh->uiCycleCounter  = 0;
  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;
  pDestVeh->State[0]                            = pInput->State[0];
  pDestVeh->State[1]                            = pInput->State[1];
}

void CConvVehDyn::ConvertToVehDynV2(VehDynV2::VehDyn_t * const pDestVeh, const VehDynV1::VehDyn_t * const pInput)
{
  InitDefaultVehDynV2(pDestVeh);
  pDestVeh->uiVersionNumber = 2u;
  pDestVeh->uiTimeStamp     = (VehDynV2::AlgoDataTimeStamp_t)pInput->TimeStamp;
  pDestVeh->uiCycleCounter  = 0;
  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;
  pDestVeh->State[0]                            = pInput->State[0];
  pDestVeh->State[1]                            = pInput->State[1];
}

void CConvVehDyn::ConvertToVehDynV2(VehDynV2::VehDyn_t * const pDestVeh, const VehDynV3::VehDyn_t * const pInput)
{
  InitDefaultVehDynV2(pDestVeh);
  pDestVeh->uiVersionNumber = 2u;
  pDestVeh->uiTimeStamp                         = pInput->uiTimeStamp;
  pDestVeh->uiCycleCounter                      = pInput->uiCycleCounter;
  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;
  pDestVeh->State[0]                            = pInput->State[0];
  pDestVeh->State[1]                            = pInput->State[1];
}

void CConvVehDyn::ConvertToVehDynV3(VehDynV3::VehDyn_t * const pDestVeh, const VehDynV0::VehDyn_t * const pInput)
{
  InitDefaultVehDynV3(pDestVeh);
  pDestVeh->uiVersionNumber = 3u;
  pDestVeh->uiTimeStamp     = (VehDynV3::AlgoDataTimeStamp_t)pInput->TimeStamp;
  pDestVeh->uiCycleCounter  = 0;
  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.VeloCorr.corrQual      = 0U;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;
  pDestVeh->State[0]                            = pInput->State[0];
  pDestVeh->State[1]                            = pInput->State[1];
}

void CConvVehDyn::ConvertToVehDynV3(VehDynV3::VehDyn_t * const pDestVeh, const VehDynV1::VehDyn_t * const pInput)
{
  InitDefaultVehDynV3(pDestVeh);
  pDestVeh->uiVersionNumber = 3u;
  pDestVeh->uiTimeStamp     = (VehDynV3::AlgoDataTimeStamp_t)pInput->TimeStamp;
  pDestVeh->uiCycleCounter  = 0;
  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.VeloCorr.corrQual      = 0U;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;
  pDestVeh->State[0]                            = pInput->State[0];
  pDestVeh->State[1]                            = pInput->State[1];
}

void CConvVehDyn::ConvertToVehDynV3(VehDynV3::VehDyn_t * const pDestVeh, const VehDynV2::VehDyn_t * const pInput)
{
  InitDefaultVehDynV3(pDestVeh);
  pDestVeh->uiVersionNumber = 3u;
  pDestVeh->uiTimeStamp                         = pInput->uiTimeStamp;
  pDestVeh->uiCycleCounter                      = pInput->uiCycleCounter;
  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.VeloCorr.corrQual      = 0U;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;
  pDestVeh->State[0]                            = pInput->State[0];
  pDestVeh->State[1]                            = pInput->State[1];
}

void CConvVehDyn::ConvertToVehDynV5(VehDynV5::VehDyn_t * const pDestVeh, const VehDynV3::VehDyn_t * const pInput)
{
  InitDefaultVehDynV5(pDestVeh);
  pDestVeh->uiVersionNumber                     = 5u;
  pDestVeh->sSignalHeader.uiTimeStamp           = pInput->uiTimeStamp;
  pDestVeh->sSignalHeader.uiMeasurementCounter  = pInput->uiCycleCounter;
  pDestVeh->sSignalHeader.uiCycleCounter        = 0U;
  pDestVeh->sSignalHeader.eSigStatus            = VehDynV5::AL_SIG_STATE_OK;

  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.VeloCorr.corrQual      = pInput->Longitudinal.VeloCorr.corrQual;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;
  pDestVeh->State[0]                            = pInput->State[0];
  pDestVeh->State[1]                            = pInput->State[1];
}

void CConvVehDyn::ConvertToVehDynV3(VehDynV3::VehDyn_t * const pDestVeh, const VehDynV5::VehDyn_t * const pInput)
{
  InitDefaultVehDynV3(pDestVeh);
  pDestVeh->uiVersionNumber                     = 3u;
  pDestVeh->uiTimeStamp                         = static_cast<VehDynV3::AlgoDataTimeStamp_t>(pInput->sSignalHeader.uiTimeStamp);
  pDestVeh->uiCycleCounter                      = pInput->sSignalHeader.uiMeasurementCounter;
  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.VeloCorr.corrQual      = pInput->Longitudinal.VeloCorr.corrQual;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;
  pDestVeh->State[0]                            = pInput->State[0];
  pDestVeh->State[1]                            = pInput->State[1];
}

void CConvVehDyn::ConvertToVehDynV5(VehDynV5::VehDyn_t * const pDestVeh, const VehDynV6::VehDyn_t * const pInput)
{
  InitDefaultVehDynV5(pDestVeh);
  pDestVeh->uiVersionNumber                     = 5u;
  pDestVeh->sSignalHeader.uiTimeStamp           = pInput->sSigHeader.uiTimeStamp;
  pDestVeh->sSignalHeader.uiMeasurementCounter  = pInput->sSigHeader.uiMeasurementCounter;
  pDestVeh->sSignalHeader.uiCycleCounter        = pInput->sSigHeader.uiCycleCounter;
  pDestVeh->sSignalHeader.eSigStatus            = pInput->sSigHeader.eSigStatus;

  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.VeloCorr.corrQual      = pInput->Longitudinal.VeloCorr.corrQual;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;
  pDestVeh->State[0]                            = 0L;
  for (unsigned int i=0; i<VehDynV6::VEH_DYN_SOUT_POS_MAX; i++)
  {
    pDestVeh->State[0] |= ConvertIOState(2*i, pInput->State[i]);
  }
  pDestVeh->State[1]                            = 0L;
}

void CConvVehDyn::ConvertToVehDynV6(VehDynV6::VehDyn_t * const pDestVeh, const VehDynV5::VehDyn_t * const pInput)
{
  uint16 i;

  InitDefaultVehDynV6(pDestVeh);
  // version number is set in init method
  pDestVeh->sSigHeader.uiTimeStamp           = pInput->sSignalHeader.uiTimeStamp;
  pDestVeh->sSigHeader.uiMeasurementCounter  = pInput->sSignalHeader.uiMeasurementCounter;
  pDestVeh->sSigHeader.uiCycleCounter        = pInput->sSignalHeader.uiCycleCounter;
  pDestVeh->sSigHeader.eSigStatus            = pInput->sSignalHeader.eSigStatus;

  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.VeloCorr.corrQual      = pInput->Longitudinal.VeloCorr.corrQual;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.Curve.CrvError              = 0.0F;
  pDestVeh->Lateral.Curve.CrvConf               = 0U;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;

  for (i=0; i<VehDynV6::VEH_DYN_SOUT_POS_MAX; i++)
  {
    pDestVeh->State[i]          = ConvertIOState(2*i, (unsigned long *)pInput->State);
  }
}

void CConvVehDyn::ConvertToVehDynV6(VehDynV6::VehDyn_t * const pDestVeh, const VehDynV6_2::VehDyn_t * const pInput)
{
  uint16 i;

  InitDefaultVehDynV6(pDestVeh);
  // version number is set in init method
  pDestVeh->sSigHeader                          = pInput->sSigHeader;

  pDestVeh->Longitudinal                        = pInput->Longitudinal;
  pDestVeh->Lateral.YawRate                     = pInput->Lateral.YawRate;
  //pDestVeh->Lateral.OffCompStWheelAngle         = 0.0F;
  pDestVeh->Lateral.Curve                       = pInput->Lateral.Curve;
  pDestVeh->Lateral.DrvIntCurve                 = pInput->Lateral.DrvIntCurve;
  pDestVeh->Lateral.Accel                       = pInput->Lateral.Accel;
  pDestVeh->Lateral.SlipAngle                   = pInput->Lateral.SlipAngle;
  pDestVeh->MotionState                         = pInput->MotionState;
  pDestVeh->Legacy                              = pInput->Legacy;

  for (i=0; i<VehDynV6::VEH_DYN_SOUT_POS_MAX; i++)
  {
    pDestVeh->State[i]                          = pInput->State[i];
  }
}

void CConvVehDyn::ConvertToVehDynV6(VehDynV6::VehDyn_t * const pDestVeh, const VehDynV8::VehDyn_t * const pInput)
{
  uint16 i;

  InitDefaultVehDynV6(pDestVeh);
  // version number is set in init method
  pDestVeh->sSigHeader                          = pInput->sSigHeader;

  pDestVeh->Longitudinal.AccelCorr              = pInput->Longitudinal.AccelCorr;
  pDestVeh->Longitudinal.MotVar                 = pInput->Longitudinal.MotVar;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrQual      = pInput->Longitudinal.VeloCorr.corrQual;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Lateral.YawRate                     = pInput->Lateral.YawRate;
  //pDestVeh->Lateral.OffCompStWheelAngle         = 0.0F;
  pDestVeh->Lateral.Curve                       = pInput->Lateral.Curve;
  pDestVeh->Lateral.DrvIntCurve                 = pInput->Lateral.DrvIntCurve;
  pDestVeh->Lateral.Accel                       = pInput->Lateral.Accel;
  pDestVeh->Lateral.SlipAngle                   = pInput->Lateral.SlipAngle;
  pDestVeh->MotionState                         = pInput->MotionState;
  pDestVeh->Legacy                              = pInput->Legacy;

  for (i=0; i<VehDynV6::VEH_DYN_SOUT_POS_MAX; i++)
  {
    pDestVeh->State[i]                          = pInput->State[i];
  }
}

void CConvVehDyn::ConvertToVehDynV6_2(VehDynV6_2::VehDyn_t * const pDestVeh, const VehDynV6::VehDyn_t * const pInput)
{
  uint16 i;

  InitDefaultVehDynV6_2(pDestVeh);
  // version number is set in init method
  pDestVeh->sSigHeader.uiTimeStamp              = pInput->sSigHeader.uiTimeStamp;
  pDestVeh->sSigHeader.uiMeasurementCounter     = pInput->sSigHeader.uiMeasurementCounter;
  pDestVeh->sSigHeader.uiCycleCounter           = pInput->sSigHeader.uiCycleCounter;
  pDestVeh->sSigHeader.eSigStatus               = pInput->sSigHeader.eSigStatus;

  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.VeloCorr.corrQual      = pInput->Longitudinal.VeloCorr.corrQual;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.OffCompStWheelAngle         = 0.0F;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.Curve.CrvError              = pInput->Lateral.Curve.CrvError;
  pDestVeh->Lateral.Curve.CrvConf               = pInput->Lateral.Curve.CrvConf;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;

  for (i=0; i<VehDynV6::VEH_DYN_SOUT_POS_MAX; i++)
  {
    pDestVeh->State[i]                          = pInput->State[i];
  }
}

void CConvVehDyn::ConvertToVehDynV8_7(VehDynV6_2::VehDyn_t * const pDestVeh, const VehDynV8::VehDyn_t * const pInput)
{
  uint16 i;

  InitDefaultVehDynV6_2(pDestVeh);
  pDestVeh->uiVersionNumber                     = 7u;
  pDestVeh->sSigHeader.uiTimeStamp           = pInput->sSigHeader.uiTimeStamp;
  pDestVeh->sSigHeader.uiMeasurementCounter  = pInput->sSigHeader.uiMeasurementCounter;
  pDestVeh->sSigHeader.uiCycleCounter        = pInput->sSigHeader.uiCycleCounter;
  pDestVeh->sSigHeader.eSigStatus            = pInput->sSigHeader.eSigStatus;

  pDestVeh->Longitudinal.MotVar.Velocity        = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel           = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity     = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel        = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact      = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar       = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo      = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar   = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo       = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo       = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.VeloCorr.corrQual      = pInput->Longitudinal.VeloCorr.corrQual;
  pDestVeh->Longitudinal.AccelCorr.corrAccel    = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate             = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance            = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality             = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.OffCompStWheelAngle         = pInput->Lateral.OffCompStWheelAngle;
  pDestVeh->Lateral.Curve.Curve                 = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                    = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient              = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                 = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                 = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality               = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.Curve.CrvError              = pInput->Lateral.Curve.CrvError;
  pDestVeh->Lateral.Curve.CrvConf               = pInput->Lateral.Curve.CrvConf;
  pDestVeh->Lateral.DrvIntCurve.Curve           = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance        = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient        = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel              = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance              = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle     = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance          = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence              = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter             = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                  = pInput->Legacy.bStandStill;
  pDestVeh->State[0]                            = 0xFFL;
  for (i=0; i<VehDynV6::VEH_DYN_SOUT_POS_MAX; i++)
  {
    pDestVeh->State[i]                          = pInput->State[i];
  }
}


void CConvVehDyn::ConvertToVehDynV8(VehDynV8::VehDyn_t * const pDestVeh, const VehDynV6_2::VehDyn_t * const pInput)
{
  uint16 i;

  InitDefaultVehDynV8(pDestVeh);
  // version number is set in init method
  pDestVeh->sSigHeader.uiTimeStamp           = pInput->sSigHeader.uiTimeStamp;
  pDestVeh->sSigHeader.uiMeasurementCounter  = pInput->sSigHeader.uiMeasurementCounter;
  pDestVeh->sSigHeader.uiCycleCounter        = pInput->sSigHeader.uiCycleCounter;
  pDestVeh->sSigHeader.eSigStatus            = pInput->sSigHeader.eSigStatus;

  pDestVeh->Longitudinal.MotVar.Velocity            = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel               = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity         = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel            = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VeloCorr.corrFact          = pInput->Longitudinal.VeloCorr.corrFact;
  pDestVeh->Longitudinal.VeloCorr.corrVar           = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo          = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar       = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.VeloCorr.minVelo           = pInput->Longitudinal.VeloCorr.minVelo;
  pDestVeh->Longitudinal.VeloCorr.maxVelo           = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.VeloCorr.corrQual          = pInput->Longitudinal.VeloCorr.corrQual;
  pDestVeh->Longitudinal.VeloCorr.bRollerTestBench  = 0;
  pDestVeh->Longitudinal.AccelCorr.corrAccel        = pInput->Longitudinal.AccelCorr.corrAccel;
  pDestVeh->Longitudinal.AccelCorr.corrAccelVar     = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate                 = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance                = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.YawRate.Quality                 = pInput->Lateral.YawRate.Quality;
  pDestVeh->Lateral.OffCompStWheelAngle             = pInput->Lateral.OffCompStWheelAngle;
  pDestVeh->Lateral.Curve.Curve                     = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.C1                        = pInput->Lateral.Curve.C1;
  pDestVeh->Lateral.Curve.Gradient                  = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                     = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.varC1                     = pInput->Lateral.Curve.varC1;
  pDestVeh->Lateral.Curve.Quality                   = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.Curve.CrvError                  = pInput->Lateral.Curve.CrvError;
  pDestVeh->Lateral.Curve.CrvConf                   = pInput->Lateral.Curve.CrvConf;
  pDestVeh->Lateral.DrvIntCurve.Curve               = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance            = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient            = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel                  = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance                  = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle         = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance              = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                    = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence                  = pInput->MotionState.Confidence;
  pDestVeh->Legacy.YawRateMaxJitter                 = pInput->Legacy.YawRateMaxJitter;
  pDestVeh->Legacy.bStandStill                      = pInput->Legacy.bStandStill;

  for (i=0; i<VehDynV8::VEH_DYN_SOUT_POS_MAX; i++)
  {
    pDestVeh->State[i]          = pInput->State[i];
  }
}

void CConvVehDyn::ConvertToVehDynV8(VehDynV8::VehDyn_t * const pDestVeh, const VehDynV9::VehDyn_t * const pInput)
{
  InitDefaultVehDynV8(pDestVeh);
  // version number is set in init method
  pDestVeh->sSigHeader.uiTimeStamp           = pInput->sSigHeader.uiTimeStamp;
  pDestVeh->sSigHeader.uiMeasurementCounter  = pInput->sSigHeader.uiMeasurementCounter;
  pDestVeh->sSigHeader.uiCycleCounter        = pInput->sSigHeader.uiCycleCounter;
  pDestVeh->sSigHeader.eSigStatus            = pInput->sSigHeader.eSigStatus;

  pDestVeh->Longitudinal.MotVar.Velocity            = pInput->Longitudinal.Velocity;
  pDestVeh->Longitudinal.MotVar.Accel               = pInput->Longitudinal.Accel;
  pDestVeh->Longitudinal.MotVar.varVelocity         = pInput->Longitudinal.varVelocity;
  pDestVeh->Longitudinal.MotVar.varAccel            = pInput->Longitudinal.varAccel;
  //pDestVeh->Longitudinal.VeloCorr.corrFact          = pInput->Longitudinal.VeloCorr.corrFact;
  //pDestVeh->Longitudinal.VeloCorr.corrVar           = pInput->Longitudinal.VeloCorr.corrVar;
  pDestVeh->Longitudinal.VeloCorr.corrVelo          = pInput->Longitudinal.Velocity;
  pDestVeh->Longitudinal.VeloCorr.corrVeloVar       = pInput->Longitudinal.varVelocity;
  //pDestVeh->Longitudinal.VeloCorr.minVelo           = pInput->Longitudinal.VeloCorr.minVelo;
  //pDestVeh->Longitudinal.VeloCorr.maxVelo           = pInput->Longitudinal.VeloCorr.maxVelo;
  pDestVeh->Longitudinal.VeloCorr.corrQual = ConvertVeloCorr_corrQual(pInput->Longitudinal.VelocityCorrectionQuality);
  pDestVeh->Longitudinal.VeloCorr.bRollerTestBench  = 0;
  //pDestVeh->Longitudinal.AccelCorr.corrAccel        = pInput->Longitudinal.AccelCorr.corrAccel;
  //pDestVeh->Longitudinal.AccelCorr.corrAccelVar     = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate                 = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance                = pInput->Lateral.YawRate.Variance;
  //pDestVeh->Lateral.YawRate.Quality                 = pInput->Lateral.YawRate.Quality;
  //pDestVeh->Lateral.OffCompStWheelAngle             = pInput->Lateral.OffCompStWheelAngle;
  pDestVeh->Lateral.Curve.Curve                     = pInput->Lateral.Curve.Curve;
  //pDestVeh->Lateral.Curve.C1                        = pInput->Lateral.Curve.C1;
  //pDestVeh->Lateral.Curve.Gradient                  = pInput->Lateral.Curve.Gradient;
  pDestVeh->Lateral.Curve.varC0                     = pInput->Lateral.Curve.VarCurve;
  //pDestVeh->Lateral.Curve.varC1                     = pInput->Lateral.Curve.varC1;
  //pDestVeh->Lateral.Curve.Quality                   = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.Curve.CrvError                  = pInput->Lateral.Curve.CrvError;
  pDestVeh->Lateral.Curve.CrvConf                   = pInput->Lateral.Curve.CrvConf;
  pDestVeh->Lateral.DrvIntCurve.Curve               = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance            = pInput->Lateral.DrvIntCurve.Variance;
  //pDestVeh->Lateral.DrvIntCurve.Gradient            = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel                  = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance                  = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle         = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance              = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState                    = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence                  = pInput->MotionState.Confidence;
  //pDestVeh->Legacy.YawRateMaxJitter                 = pInput->Legacy.YawRateMaxJitter;
  //pDestVeh->Legacy.bStandStill                      = pInput->Legacy.bStandStill;
  ConvertPosOfStates(pDestVeh->State, pInput->State);
}

void CConvVehDyn::ConvertToVehDynV9(VehDynV9::VehDyn_t * const pDestVeh, const VehDynV8::VehDyn_t * const pInput)
{
  InitDefaultVehDynV9(pDestVeh);
  // version number is set in init method
  pDestVeh->sSigHeader.uiTimeStamp           = pInput->sSigHeader.uiTimeStamp;
  pDestVeh->sSigHeader.uiMeasurementCounter  = pInput->sSigHeader.uiMeasurementCounter;
  pDestVeh->sSigHeader.uiCycleCounter        = pInput->sSigHeader.uiCycleCounter;
  pDestVeh->sSigHeader.eSigStatus            = pInput->sSigHeader.eSigStatus;

  pDestVeh->Longitudinal.Velocity            = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.Accel               = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.varVelocity         = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.varAccel            = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VelocityCorrectionQuality = ConvertVelocityCorrectionQuality(pInput->Longitudinal.VeloCorr.corrQual);
  pDestVeh->Lateral.YawRate.YawRate          = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance         = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.Curve.Curve              = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.VarCurve           = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.CrvError           = pInput->Lateral.Curve.CrvError;
  pDestVeh->Lateral.Curve.CrvConf            = pInput->Lateral.Curve.CrvConf;
  pDestVeh->Lateral.DrvIntCurve.Curve        = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance     = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.Accel.LatAccel           = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance           = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle  = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance       = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState             = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence           = (unsigned char) pInput->MotionState.Confidence;
  pDestVeh->MotionState.bRollerTestBench     = pInput->Longitudinal.VeloCorr.bRollerTestBench;
  ConvertPosOfStates(pDestVeh->State, pInput->State);
}

void CConvVehDyn::ConvertToVehDynV9(VehDynV9::VehDyn_t * const pDestVeh, const VehDynV6_2::VehDyn_t * const pInput)
{
  InitDefaultVehDynV9(pDestVeh);
  // version number is set in init method
  pDestVeh->sSigHeader.uiTimeStamp           = pInput->sSigHeader.uiTimeStamp;
  pDestVeh->sSigHeader.uiMeasurementCounter  = pInput->sSigHeader.uiMeasurementCounter;
  pDestVeh->sSigHeader.uiCycleCounter        = pInput->sSigHeader.uiCycleCounter;
  pDestVeh->sSigHeader.eSigStatus            = pInput->sSigHeader.eSigStatus;

  //pDestVeh->Longitudinal.Velocity            = pInput->Longitudinal.MotVar.Velocity;
  pDestVeh->Longitudinal.Velocity            = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.Accel               = pInput->Longitudinal.MotVar.Accel;
  //pDestVeh->Longitudinal.varVelocity         = pInput->Longitudinal.MotVar.varVelocity;
  pDestVeh->Longitudinal.varVelocity         = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.varAccel            = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VelocityCorrectionQuality = ConvertVelocityCorrectionQuality(pInput->Longitudinal.VeloCorr.corrQual);
  //pDestVeh->Longitudinal.VeloCorr.corrFact          = pInput->Longitudinal.VeloCorr.corrFact;
  //pDestVeh->Longitudinal.VeloCorr.corrVar           = pInput->Longitudinal.VeloCorr.corrVar;
  //pDestVeh->Longitudinal.VeloCorr.corrVelo          = pInput->Longitudinal.VeloCorr.corrVelo;
  //pDestVeh->Longitudinal.VeloCorr.corrVeloVar       = pInput->Longitudinal.VeloCorr.corrVeloVar;
  //pDestVeh->Longitudinal.VeloCorr.minVelo           = pInput->Longitudinal.VeloCorr.minVelo;
  //pDestVeh->Longitudinal.VeloCorr.maxVelo           = pInput->Longitudinal.VeloCorr.maxVelo;
  //pDestVeh->Longitudinal.VeloCorr.corrQual          = pInput->Longitudinal.VeloCorr.corrQual;
  //pDestVeh->Longitudinal.VeloCorr.bRollerTestBench  = 0;
  //pDestVeh->Longitudinal.AccelCorr.corrAccel        = pInput->Longitudinal.AccelCorr.corrAccel;
  //pDestVeh->Longitudinal.AccelCorr.corrAccelVar     = pInput->Longitudinal.AccelCorr.corrAccelVar;
  pDestVeh->Lateral.YawRate.YawRate          = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance         = pInput->Lateral.YawRate.Variance;
  //pDestVeh->Lateral.YawRate.Quality          = pInput->Lateral.YawRate.Quality;
  //pDestVeh->Lateral.OffCompStWheelAngle      = pInput->Lateral.OffCompStWheelAngle;
  pDestVeh->Lateral.Curve.Curve              = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.VarCurve           = pInput->Lateral.Curve.varC0;
  //pDestVeh->Lateral.Curve.C1                 = pInput->Lateral.Curve.C1;
  //pDestVeh->Lateral.Curve.Gradient           = pInput->Lateral.Curve.Gradient;
  //pDestVeh->Lateral.Curve.varC0              = pInput->Lateral.Curve.varC0;
  //pDestVeh->Lateral.Curve.varC1              = pInput->Lateral.Curve.varC1;
  //pDestVeh->Lateral.Curve.Quality            = pInput->Lateral.Curve.Quality;
  pDestVeh->Lateral.Curve.CrvError           = pInput->Lateral.Curve.CrvError;
  pDestVeh->Lateral.Curve.CrvConf            = pInput->Lateral.Curve.CrvConf;
  pDestVeh->Lateral.DrvIntCurve.Curve        = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance     = pInput->Lateral.DrvIntCurve.Variance;
  //pDestVeh->Lateral.DrvIntCurve.Gradient     = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel           = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance           = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle  = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance       = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState             = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence           = (unsigned char) pInput->MotionState.Confidence;
  pDestVeh->MotionState.bRollerTestBench     = 0;
  //pDestVeh->Legacy.YawRateMaxJitter          = pInput->Legacy.YawRateMaxJitter;
  //pDestVeh->Legacy.bStandStill               = pInput->Legacy.bStandStill;
  ConvertPosOfStates(pDestVeh->State, pInput->State);
}

void CConvVehDyn::ConvertToVehDynV32(VehDynV32::VehDyn_t * const pDestVeh, const VehDynV8::VehDyn_t * const pInput)
{
  InitDefaultVehDynV32(pDestVeh);
  // version number is set in init method
  pDestVeh->sSigHeader                       = pInput->sSigHeader;
  pDestVeh->Longitudinal.Velocity            = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.Accel               = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.varVelocity         = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.varAccel            = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VelocityCorrectionQuality = ConvertVelocityCorrectionQuality(pInput->Longitudinal.VeloCorr.corrQual);
  pDestVeh->Lateral.YawRate.YawRate          = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance         = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.Curve.Curve              = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.VarCurve           = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.CrvError           = pInput->Lateral.Curve.CrvError;
  pDestVeh->Lateral.Curve.CrvConf            = pInput->Lateral.Curve.CrvConf;
  pDestVeh->Lateral.DrvIntCurve.Curve        = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance     = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient     = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel           = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance           = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle  = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance       = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState             = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence           = (unsigned char) pInput->MotionState.Confidence;
  pDestVeh->MotionState.bRollerTestBench     = pInput->Longitudinal.VeloCorr.bRollerTestBench;
  ConvertPosOfStates(pDestVeh->State, pInput->State);
}

void CConvVehDyn::ConvertToVehDynV32(VehDynV32::VehDyn_t * const pDestVeh, const VehDynV6_2::VehDyn_t * const pInput)
{
  InitDefaultVehDynV32(pDestVeh);
  // version number is set in init method
  pDestVeh->sSigHeader                       = pInput->sSigHeader;
  pDestVeh->Longitudinal.Velocity            = pInput->Longitudinal.VeloCorr.corrVelo;
  pDestVeh->Longitudinal.Accel               = pInput->Longitudinal.MotVar.Accel;
  pDestVeh->Longitudinal.varVelocity         = pInput->Longitudinal.VeloCorr.corrVeloVar;
  pDestVeh->Longitudinal.varAccel            = pInput->Longitudinal.MotVar.varAccel;
  pDestVeh->Longitudinal.VelocityCorrectionQuality = ConvertVelocityCorrectionQuality(pInput->Longitudinal.VeloCorr.corrQual);
  pDestVeh->Lateral.YawRate.YawRate          = pInput->Lateral.YawRate.YawRate;
  pDestVeh->Lateral.YawRate.Variance         = pInput->Lateral.YawRate.Variance;
  pDestVeh->Lateral.Curve.Curve              = pInput->Lateral.Curve.Curve;
  pDestVeh->Lateral.Curve.VarCurve           = pInput->Lateral.Curve.varC0;
  pDestVeh->Lateral.Curve.CrvError           = pInput->Lateral.Curve.CrvError;
  pDestVeh->Lateral.Curve.CrvConf            = pInput->Lateral.Curve.CrvConf;
  pDestVeh->Lateral.DrvIntCurve.Curve        = pInput->Lateral.DrvIntCurve.Curve;
  pDestVeh->Lateral.DrvIntCurve.Variance     = pInput->Lateral.DrvIntCurve.Variance;
  pDestVeh->Lateral.DrvIntCurve.Gradient     = pInput->Lateral.DrvIntCurve.Gradient;
  pDestVeh->Lateral.Accel.LatAccel           = pInput->Lateral.Accel.LatAccel;
  pDestVeh->Lateral.Accel.Variance           = pInput->Lateral.Accel.Variance;
  pDestVeh->Lateral.SlipAngle.SideSlipAngle  = pInput->Lateral.SlipAngle.SideSlipAngle;
  pDestVeh->Lateral.SlipAngle.Variance       = pInput->Lateral.SlipAngle.Variance;
  pDestVeh->MotionState.MotState             = pInput->MotionState.MotState;
  pDestVeh->MotionState.Confidence           = (unsigned char) pInput->MotionState.Confidence;
  pDestVeh->MotionState.bRollerTestBench     = 0;
  ConvertPosOfStates(pDestVeh->State, pInput->State);
}


long CConvVehDyn::ConvertData( SimPortDataTypes_t /*eRPortType*/, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
                               SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
                               void *pPPortData,
                               void **pOutData, unsigned long &ulOutSize)
{
  long lRet;
  if ( ( ((ePPortType == simOPAQUE_t) && (ulPPortSize > 4)) || (ePPortType == simREFERENCE_t) ) && (pPPortData != NULL))
  {
    const uint32 version = GetRteInterfaceVersion(ePPortType,ulPPortSize,pPPortData);

    const CVersionInfoImpl ProvidePortVersionInfo(CONV_I32VERSION_TO_TUPPLE(version));


    // First check for complete match of request/provide port. Always accept this as direct match
    // only start evaluating data if no direct copy possible
    if ((ulPPortSize == ulRPortSize) && ((pProvidePortVersionInfo == NULL) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo)))
      && (ProvidePortVersionInfo.Equals(&requestPortVersionInfo)))
    {
      // Port types sizes and versions match, we can directly use the input data
      *pOutData = pPPortData;
      ulOutSize = ulPPortSize;
      lRet = SIM_ERR_OK;
    }
    else
    {
      // version 32 is used in DLL
      if (    (ulRPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V32])
           && (requestPortVersionInfo.Equals(&V32_VER_INFO))   )
      {
        // This branch is for conversion to VehDyn_t version 32
        if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V32]) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V32_VER_INFO))) &&
          ((ProvidePortVersionInfo.Equals(&V32_VER_INFO))))
        {
          // Provide port sizes match and versions are either V32_VER_INFO
          // Forward the data directly:
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 8
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V8])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V8_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V8_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V8_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V8_VER_INFO))))
        {
          ConvertToVehDynV32(&m_VehDynV32, reinterpret_cast<const VehDynV8::VehDyn_t*>(pPPortData));
          *pOutData = &m_VehDynV32;
          ulOutSize = sizeof(m_VehDynV32);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 7 (6_2)
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V7])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V7_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V6_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V7_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V6_VER_INFO))))
        {
          ConvertToVehDynV32(&m_VehDynV32, reinterpret_cast<const VehDynV6_2::VehDyn_t*>(pPPortData));
          *pOutData = &m_VehDynV32;
          ulOutSize = sizeof(m_VehDynV32);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 6 and 7 (with structure of 6)
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V6])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V6_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V7_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V8_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V6_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V7_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V8_VER_INFO)))   )
        {
          ConvertToVehDynV6_2(&m_VehDynV6_2, reinterpret_cast<const VehDynV6::VehDyn_t*>(pPPortData));
          //ConvertToVehDynV8(&m_VehDynV8, &m_VehDynV6_2);
          //ConvertToVehDynV32(&m_VehDynV32, &m_VehDynV8);
          // Direct conversion to improve speed:
          ConvertToVehDynV32(&m_VehDynV32, &m_VehDynV6_2);
          *pOutData = &m_VehDynV32;
          ulOutSize = sizeof(m_VehDynV32);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 5
        else if (    (ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V5])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V5_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V5_VER_INFO)))   )
        {
          ConvertToVehDynV6(&m_VehDynV6, reinterpret_cast<const VehDynV5::VehDyn_t*>(pPPortData));
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          ConvertToVehDynV32(&m_VehDynV32, &m_VehDynV6_2);
          *pOutData = &m_VehDynV32;
          ulOutSize = sizeof(m_VehDynV32);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion to VehDyn_t version 3
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V3]) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V3_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V4_VER_INFO))) &&
          ((ProvidePortVersionInfo.Equals(&V3_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V4_VER_INFO))))
        {
          ConvertToVehDynV5(&m_VehDynV5, reinterpret_cast<const VehDynV3::VehDyn_t*>(pPPortData));
          ConvertToVehDynV6(&m_VehDynV6, &m_VehDynV5);
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          ConvertToVehDynV32(&m_VehDynV32, &m_VehDynV6_2);
          *pOutData = &m_VehDynV32;
          ulOutSize = sizeof(m_VehDynV32);
          lRet = SIM_ERR_OK;
        }
        // Check if provide port size corresponds to version 2 of VehDyn_t struct & either no provide port
        // version info available, or the version is 1
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V2]) && ((pProvidePortVersionInfo == NULL) || (V2_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V2_VER_INFO)))
        {
          ConvertToVehDynV3(&m_VehDynV3, reinterpret_cast<const VehDynV2::VehDyn_t*>(pPPortData));
          ConvertToVehDynV5(&m_VehDynV5, &m_VehDynV3);
          ConvertToVehDynV6(&m_VehDynV6, &m_VehDynV5);
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          ConvertToVehDynV32(&m_VehDynV32, &m_VehDynV6_2);
          *pOutData = &m_VehDynV32;
          ulOutSize = sizeof(m_VehDynV32);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V1]) && ((pProvidePortVersionInfo == NULL) || (V1_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V1_VER_INFO)))
        {
          ConvertToVehDynV2(&m_VehDynV2, reinterpret_cast<const VehDynV1::VehDyn_t*>(pPPortData));
          ConvertToVehDynV3(&m_VehDynV3, &m_VehDynV2);
          ConvertToVehDynV5(&m_VehDynV5, &m_VehDynV3);
          ConvertToVehDynV6(&m_VehDynV6, &m_VehDynV5);
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          ConvertToVehDynV32(&m_VehDynV32, &m_VehDynV6_2);
          *pOutData = &m_VehDynV32;
          ulOutSize = sizeof(m_VehDynV32);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V0]) && ((pProvidePortVersionInfo == NULL) || (V0_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V0_VER_INFO)))
        {
          ConvertToVehDynV1(&m_VehDynV1, reinterpret_cast<const VehDynV0::VehDyn_t*>(pPPortData));
          ConvertToVehDynV2(&m_VehDynV2, &m_VehDynV1);
          ConvertToVehDynV3(&m_VehDynV3, &m_VehDynV2);
          ConvertToVehDynV5(&m_VehDynV5, &m_VehDynV3);
          ConvertToVehDynV6(&m_VehDynV6, &m_VehDynV5);
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          ConvertToVehDynV32(&m_VehDynV32, &m_VehDynV6_2);
          *pOutData = &m_VehDynV32;
          ulOutSize = sizeof(m_VehDynV32);
          lRet = SIM_ERR_OK;
        }
        else
        {
          lRet = SIM_ERR_NO_CONVERSION;
        }
      }
      // version 9 is used in DLL
      else if ((ulRPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V9])
           &&  (requestPortVersionInfo.Equals(&V9_VER_INFO)))
      {
        // This branch is for conversion to VehDyn_t version 9
        if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V9]) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V9_VER_INFO))) &&
          ((ProvidePortVersionInfo.Equals(&V9_VER_INFO))))
        {
          // Provide port sizes match and versions are either V9_VER_INFO
          // Forward the data directly:
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 8
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V8])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V8_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V8_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V8_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V8_VER_INFO))))
        {
          ConvertToVehDynV9(&m_VehDynV9, reinterpret_cast<const VehDynV8::VehDyn_t*>(pPPortData));
          *pOutData = &m_VehDynV9;
          ulOutSize = sizeof(m_VehDynV9);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 7 (6_2)
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V7])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V7_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V6_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V7_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V6_VER_INFO))))
        {
          ConvertToVehDynV9(&m_VehDynV9, reinterpret_cast<const VehDynV6_2::VehDyn_t*>(pPPortData));
          *pOutData = &m_VehDynV9;
          ulOutSize = sizeof(m_VehDynV9);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 6 and 7 (with structure of 6)
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V6])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V6_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V7_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V8_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V6_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V7_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V8_VER_INFO)))   )
        {
          ConvertToVehDynV6_2(&m_VehDynV6_2, reinterpret_cast<const VehDynV6::VehDyn_t*>(pPPortData));
          //ConvertToVehDynV8(&m_VehDynV8, &m_VehDynV6_2);
          //ConvertToVehDynV9(&m_VehDynV9, &m_VehDynV8);
          // Direct conversion to improve speed:
          ConvertToVehDynV9(&m_VehDynV9, &m_VehDynV6_2);
          *pOutData = &m_VehDynV9;
          ulOutSize = sizeof(m_VehDynV9);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 5
        else if (    (ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V5])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V5_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V5_VER_INFO)))   )
        {
          ConvertToVehDynV6(&m_VehDynV6, reinterpret_cast<const VehDynV5::VehDyn_t*>(pPPortData));
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          ConvertToVehDynV9(&m_VehDynV9, &m_VehDynV6_2);
          *pOutData = &m_VehDynV9;
          ulOutSize = sizeof(m_VehDynV9);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion to VehDyn_t version 3
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V3]) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V3_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V4_VER_INFO))) &&
          ((ProvidePortVersionInfo.Equals(&V3_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V4_VER_INFO))))
        {
          ConvertToVehDynV5(&m_VehDynV5, reinterpret_cast<const VehDynV3::VehDyn_t*>(pPPortData));
          ConvertToVehDynV6(&m_VehDynV6, &m_VehDynV5);
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          ConvertToVehDynV9(&m_VehDynV9, &m_VehDynV6_2);
          *pOutData = &m_VehDynV9;
          ulOutSize = sizeof(m_VehDynV9);
          lRet = SIM_ERR_OK;
        }
        // Check if provide port size corresponds to version 2 of VehDyn_t struct & either no provide port
        // version info available, or the version is 1
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V2]) && ((pProvidePortVersionInfo == NULL) || (V2_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V2_VER_INFO)))
        {
          ConvertToVehDynV3(&m_VehDynV3, reinterpret_cast<const VehDynV2::VehDyn_t*>(pPPortData));
          ConvertToVehDynV5(&m_VehDynV5, &m_VehDynV3);
          ConvertToVehDynV6(&m_VehDynV6, &m_VehDynV5);
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          ConvertToVehDynV9(&m_VehDynV9, &m_VehDynV6_2);
          *pOutData = &m_VehDynV9;
          ulOutSize = sizeof(m_VehDynV9);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V1]) && ((pProvidePortVersionInfo == NULL) || (V1_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V1_VER_INFO)))
        {
          ConvertToVehDynV2(&m_VehDynV2, reinterpret_cast<const VehDynV1::VehDyn_t*>(pPPortData));
          ConvertToVehDynV3(&m_VehDynV3, &m_VehDynV2);
          ConvertToVehDynV5(&m_VehDynV5, &m_VehDynV3);
          ConvertToVehDynV6(&m_VehDynV6, &m_VehDynV5);
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          ConvertToVehDynV9(&m_VehDynV9, &m_VehDynV6_2);
          *pOutData = &m_VehDynV9;
          ulOutSize = sizeof(m_VehDynV9);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V0]) && ((pProvidePortVersionInfo == NULL) || (V0_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V0_VER_INFO)))
        {
          ConvertToVehDynV1(&m_VehDynV1, reinterpret_cast<const VehDynV0::VehDyn_t*>(pPPortData));
          ConvertToVehDynV2(&m_VehDynV2, &m_VehDynV1);
          ConvertToVehDynV3(&m_VehDynV3, &m_VehDynV2);
          ConvertToVehDynV5(&m_VehDynV5, &m_VehDynV3);
          ConvertToVehDynV6(&m_VehDynV6, &m_VehDynV5);
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          ConvertToVehDynV9(&m_VehDynV9, &m_VehDynV6_2);
          *pOutData = &m_VehDynV9;
          ulOutSize = sizeof(m_VehDynV9);
          lRet = SIM_ERR_OK;
        }
        else
        {
          lRet = SIM_ERR_NO_CONVERSION;
        }
      }
      // version 8 is used in DLL
      else if ((ulRPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V8])
           &&  (requestPortVersionInfo.Equals(&V8_VER_INFO))   )
      {
        // This branch is for conversion to VehDyn_t version 8
        if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V8]) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V8_VER_INFO))) &&
          ((ProvidePortVersionInfo.Equals(&V8_VER_INFO))))
        {
          // Provide port sizes match and versions are either V8_VER_INFO
          // Forward the data directly:
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 9
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V9])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V9_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V9_VER_INFO))))
        {
          ConvertToVehDynV8(&m_VehDynV8, reinterpret_cast<const VehDynV9::VehDyn_t*>(pPPortData));
          *pOutData = &m_VehDynV8;
          ulOutSize = sizeof(m_VehDynV8);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 7 (6_2)
        else if (    (ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V7])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V7_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V6_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V7_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V6_VER_INFO))))
        {
          ConvertToVehDynV8(&m_VehDynV8, reinterpret_cast<const VehDynV6_2::VehDyn_t*>(pPPortData));
          *pOutData = &m_VehDynV8;
          ulOutSize = sizeof(m_VehDynV8);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 6 and 7 (with structure of 6)
        else if (    (ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V6])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V6_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V7_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V8_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V6_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V7_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V8_VER_INFO)))   )
        {
          ConvertToVehDynV6_2(&m_VehDynV6_2, reinterpret_cast<const VehDynV6::VehDyn_t*>(pPPortData));
          ConvertToVehDynV8(&m_VehDynV8, &m_VehDynV6_2);
          *pOutData = &m_VehDynV8;
          ulOutSize = sizeof(m_VehDynV8);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 5
        else if (    (ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V5])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V5_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V5_VER_INFO)))   )
        {
          ConvertToVehDynV6(&m_VehDynV6, reinterpret_cast<const VehDynV5::VehDyn_t*>(pPPortData));
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          ConvertToVehDynV8(&m_VehDynV8, &m_VehDynV6_2);
          *pOutData = &m_VehDynV8;
          ulOutSize = sizeof(m_VehDynV8);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion to VehDyn_t version 3
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V3]) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V3_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V4_VER_INFO))) &&
          ((ProvidePortVersionInfo.Equals(&V3_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V4_VER_INFO))))
        {
          ConvertToVehDynV5(&m_VehDynV5, reinterpret_cast<const VehDynV3::VehDyn_t*>(pPPortData));
          ConvertToVehDynV6(&m_VehDynV6, &m_VehDynV5);
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          ConvertToVehDynV8(&m_VehDynV8, &m_VehDynV6_2);
          *pOutData = &m_VehDynV8;
          ulOutSize = sizeof(m_VehDynV8);
          lRet = SIM_ERR_OK;
        }
        // Check if provide port size corresponds to version 2 of VehDyn_t struct & either no provide port
        // version info available, or the version is 1
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V2]) && ((pProvidePortVersionInfo == NULL) || (V2_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V2_VER_INFO)))
        {
          ConvertToVehDynV3(&m_VehDynV3, reinterpret_cast<const VehDynV2::VehDyn_t*>(pPPortData));
          ConvertToVehDynV5(&m_VehDynV5, &m_VehDynV3);
          ConvertToVehDynV6(&m_VehDynV6, &m_VehDynV5);
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          ConvertToVehDynV8(&m_VehDynV8, &m_VehDynV6_2);
          *pOutData = &m_VehDynV8;
          ulOutSize = sizeof(m_VehDynV8);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V1]) && ((pProvidePortVersionInfo == NULL) || (V1_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V1_VER_INFO)))
        {
          ConvertToVehDynV2(&m_VehDynV2, reinterpret_cast<const VehDynV1::VehDyn_t*>(pPPortData));
          ConvertToVehDynV3(&m_VehDynV3, &m_VehDynV2);
          ConvertToVehDynV5(&m_VehDynV5, &m_VehDynV3);
          ConvertToVehDynV6(&m_VehDynV6, &m_VehDynV5);
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          ConvertToVehDynV8(&m_VehDynV8, &m_VehDynV6_2);
          *pOutData = &m_VehDynV8;
          ulOutSize = sizeof(m_VehDynV8);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V0]) && ((pProvidePortVersionInfo == NULL) || (V0_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V0_VER_INFO)))
        {
          ConvertToVehDynV1(&m_VehDynV1, reinterpret_cast<const VehDynV0::VehDyn_t*>(pPPortData));
          ConvertToVehDynV2(&m_VehDynV2, &m_VehDynV1);
          ConvertToVehDynV3(&m_VehDynV3, &m_VehDynV2);
          ConvertToVehDynV5(&m_VehDynV5, &m_VehDynV3);
          ConvertToVehDynV6(&m_VehDynV6, &m_VehDynV5);
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          ConvertToVehDynV8(&m_VehDynV8, &m_VehDynV6_2);
          *pOutData = &m_VehDynV8;
          ulOutSize = sizeof(m_VehDynV8);
          lRet = SIM_ERR_OK;
        }
        else
        {
          lRet = SIM_ERR_NO_CONVERSION;
        }
      }
      // version 6 (and version 7!) is used in DLL and size of VehDynV6_2
      else if (    (ulRPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V6_2]) // or VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V7] which are equal
           && (requestPortVersionInfo.Equals(&V6_VER_INFO) || requestPortVersionInfo.Equals(&V7_VER_INFO)))
      {
        // This branch is for VehDyn V6_2 and the versions don't match
        if (ulPPortSize == ulRPortSize)
        {
          // Port types sizes, we can directly use the input data
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 9
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V9])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V9_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V9_VER_INFO))))
        {
          ConvertToVehDynV8(&m_VehDynV8, reinterpret_cast<const VehDynV9::VehDyn_t*>(pPPortData));
          ConvertToVehDynV8_7(&m_VehDynV6_2, &m_VehDynV8);
          *pOutData = &m_VehDynV6_2;
          ulOutSize = sizeof(m_VehDynV6_2);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 8
        else if (    (ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V8])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V8_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V8_VER_INFO)))   )
        {
          ConvertToVehDynV8_7(&m_VehDynV6_2, reinterpret_cast<const VehDynV8::VehDyn_t*>(pPPortData));
          *pOutData = &m_VehDynV6_2;
          ulOutSize = sizeof(m_VehDynV6_2);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 6
        else if (    (ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V6])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V6_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V6_VER_INFO)))   )
        {
          ConvertToVehDynV6_2(&m_VehDynV6_2, reinterpret_cast<const VehDynV6::VehDyn_t*>(pPPortData));
          *pOutData = &m_VehDynV6_2;
          ulOutSize = sizeof(m_VehDynV6_2);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 5
        else if (    (ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V5])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V5_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V5_VER_INFO)))   )
        {
          ConvertToVehDynV6(&m_VehDynV6, reinterpret_cast<const VehDynV5::VehDyn_t*>(pPPortData));
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          *pOutData = &m_VehDynV6_2;
          ulOutSize = sizeof(m_VehDynV6_2);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 3
        else if (    (ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V3])
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V3_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V4_VER_INFO)))
                  && ((ProvidePortVersionInfo.Equals(&V3_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V4_VER_INFO)))   )
        {
          ConvertToVehDynV5(&m_VehDynV5, reinterpret_cast<const VehDynV3::VehDyn_t*>(pPPortData));
          ConvertToVehDynV6(&m_VehDynV6, &m_VehDynV5);
          ConvertToVehDynV6_2(&m_VehDynV6_2, &m_VehDynV6);
          *pOutData = &m_VehDynV6_2;
          ulOutSize = sizeof(m_VehDynV6_2);
          lRet = SIM_ERR_OK;
        }
        else
        {
          lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
        }
      }
      // version 6 is used in DLL and size of VehDynV6
      else if (    (ulRPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V6])
                && (requestPortVersionInfo.Equals(&V6_VER_INFO)))
      {
        // This branch is for conversion from VehDyn_t version 9
        if (    (ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V9])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V9_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V9_VER_INFO))))
        {
          ConvertToVehDynV8(&m_VehDynV8, reinterpret_cast<const VehDynV9::VehDyn_t*>(pPPortData));
          ConvertToVehDynV6(&m_VehDynV6, &m_VehDynV8);
          *pOutData = &m_VehDynV6;
          ulOutSize = sizeof(m_VehDynV6);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 8
        else if (    (ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V8])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V8_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V8_VER_INFO))))
        {
          ConvertToVehDynV6(&m_VehDynV6, reinterpret_cast<const VehDynV8::VehDyn_t*>(pPPortData));
          *pOutData = &m_VehDynV6;
          ulOutSize = sizeof(m_VehDynV6);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 7 (V6_2)
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V7])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V7_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V7_VER_INFO)))   )
        {
          ConvertToVehDynV6(&m_VehDynV6, reinterpret_cast<const VehDynV6_2::VehDyn_t*>(pPPortData));
          *pOutData = &m_VehDynV6;
          ulOutSize = sizeof(m_VehDynV6);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 5
        else if (    (ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V5])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V5_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V5_VER_INFO)))   )
        {
          ConvertToVehDynV6(&m_VehDynV6, reinterpret_cast<const VehDynV5::VehDyn_t*>(pPPortData));
          *pOutData = &m_VehDynV6;
          ulOutSize = sizeof(m_VehDynV6);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion from VehDyn_t version 3
        else if (    (ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V3])
                  && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V3_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V4_VER_INFO)))
                  && ((ProvidePortVersionInfo.Equals(&V3_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V4_VER_INFO)))   )
        {
          ConvertToVehDynV5(&m_VehDynV5, reinterpret_cast<const VehDynV3::VehDyn_t*>(pPPortData));
          ConvertToVehDynV6(&m_VehDynV6, &m_VehDynV5);
          *pOutData = &m_VehDynV6;
          ulOutSize = sizeof(m_VehDynV6);
          lRet = SIM_ERR_OK;
        }
        else
        {
          lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
        }
      }
      else if ((ulRPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V5]) &&
        (requestPortVersionInfo.Equals(&V5_VER_INFO)))
      {
        if (    (ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V6])
             && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V6_VER_INFO)))
             && ((ProvidePortVersionInfo.Equals(&V6_VER_INFO))))
        {
          ConvertToVehDynV5(&m_VehDynV5, reinterpret_cast<const VehDynV6::VehDyn_t*>(pPPortData));
          *pOutData = &m_VehDynV5;
          ulOutSize = sizeof(m_VehDynV5);
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion to VehDyn_t version 5
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V5]) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V5_VER_INFO))) &&
          ((ProvidePortVersionInfo.Equals(&V5_VER_INFO))))
        {
          // Provide port sizes match and versions are either V5_VER_INFO
          // Forward the data directly:
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_OK;
        }
        // This branch is for conversion to VehDyn_t version 3
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V3]) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V3_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V4_VER_INFO))) &&
          ((ProvidePortVersionInfo.Equals(&V3_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V4_VER_INFO))))
        {
          ConvertToVehDynV5(&m_VehDynV5, reinterpret_cast<const VehDynV3::VehDyn_t*>(pPPortData));
          *pOutData = &m_VehDynV5;
          ulOutSize = sizeof(m_VehDynV5);
          lRet = SIM_ERR_OK;
        }
        // Check if provide port size corresponds to version 2 of VehDyn_t struct & either no provide port
        // version info available, or the version is 1
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V2]) && ((pProvidePortVersionInfo == NULL) || (V2_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V2_VER_INFO)))
        {
          ConvertToVehDynV3(&m_VehDynV3, reinterpret_cast<const VehDynV2::VehDyn_t*>(pPPortData));
          ConvertToVehDynV5(&m_VehDynV5, &m_VehDynV3);
          *pOutData = &m_VehDynV5;
          ulOutSize = sizeof(m_VehDynV5);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V1]) && ((pProvidePortVersionInfo == NULL) || (V1_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V1_VER_INFO)))
        {
          ConvertToVehDynV2(&m_VehDynV2, reinterpret_cast<const VehDynV1::VehDyn_t*>(pPPortData));
          ConvertToVehDynV3(&m_VehDynV3, &m_VehDynV2);
          ConvertToVehDynV5(&m_VehDynV5, &m_VehDynV3);
          *pOutData = &m_VehDynV5;
          ulOutSize = sizeof(m_VehDynV5);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V0]) && ((pProvidePortVersionInfo == NULL) || (V0_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V0_VER_INFO)))
        {
          ConvertToVehDynV1(&m_VehDynV1, reinterpret_cast<const VehDynV0::VehDyn_t*>(pPPortData));
          ConvertToVehDynV2(&m_VehDynV2, &m_VehDynV1);
          ConvertToVehDynV3(&m_VehDynV3, &m_VehDynV2);
          ConvertToVehDynV5(&m_VehDynV5, &m_VehDynV3);
          *pOutData = &m_VehDynV5;
          ulOutSize = sizeof(m_VehDynV5);
          lRet = SIM_ERR_OK;
        }
        else
        {
          lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
        }
      }
      // Some conversion is needed, first level branching based on request port size/version
      // Check if destination is V3 version. It is so if the size of the request port equals the V3
      // size & the the request port version is V3 (also handle special case when no version information
      // is provided for the request port, ie.: version number is zero)
      // In addition the request port version V4 is handled like the V3 version!!!!
      else if ((ulRPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V3]) &&
        ((requestPortVersionInfo.Equals(&V3_VER_INFO)) || (requestPortVersionInfo.Equals(&V0_VER_INFO))|| (requestPortVersionInfo.Equals(&V4_VER_INFO))))
      {
        // This branch is for conversion to VehDyn_t version 3
        VehDynV3::VehDyn_t * const pDestVeh = &m_VehDynV3;
        if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V3]) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V3_VER_INFO)) || (pProvidePortVersionInfo->Equals(&V4_VER_INFO))) &&
          ((ProvidePortVersionInfo.Equals(&V3_VER_INFO)) || (ProvidePortVersionInfo.Equals(&V4_VER_INFO))))
        {
          // Provide port sizes match and versions are either V3_VER_INFO or V4_VER_INFO, which are identical
          // Forward the data directly:
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_OK;
        }
        // Check if provide port size corresponds to version 2 of VehDyn_t struct & either no provide port
        // version info available, or the version is 1
        if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V5]) &&
          ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&V5_VER_INFO))) &&
          ((ProvidePortVersionInfo.Equals(&V5_VER_INFO))))
        {
          ConvertToVehDynV3(&m_VehDynV3, reinterpret_cast<const VehDynV5::VehDyn_t*>(pPPortData));
          *pOutData = &m_VehDynV3;
          ulOutSize = sizeof(m_VehDynV3);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V2]) && ((pProvidePortVersionInfo == NULL) || (V2_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V2_VER_INFO)))
        {
          const VehDynV2::VehDyn_t * const pInput = reinterpret_cast<const VehDynV2::VehDyn_t*>(pPPortData);
          // Call helper method to perform conversion
          ConvertToVehDynV3(pDestVeh, pInput);
          *pOutData = pDestVeh;
          ulOutSize = sizeof(*pDestVeh);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V1]) && ((pProvidePortVersionInfo == NULL) || (V1_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V1_VER_INFO)))
        {
          const VehDynV1::VehDyn_t * const pInput = reinterpret_cast<const VehDynV1::VehDyn_t*>(pPPortData);
          // Call helper method to perform conversion
          ConvertToVehDynV3(pDestVeh, pInput);
          *pOutData = pDestVeh;
          ulOutSize = sizeof(*pDestVeh);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V0]) && ((pProvidePortVersionInfo == NULL) || (V0_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V0_VER_INFO)))
        {
          const VehDynV0::VehDyn_t * const pInput = reinterpret_cast<const VehDynV0::VehDyn_t*>(pPPortData);
          // Call helper method to perform conversion
          ConvertToVehDynV3(pDestVeh, pInput);
          *pOutData = pDestVeh;
          ulOutSize = sizeof(*pDestVeh);
          lRet = SIM_ERR_OK;
        }
        else
        {
          // This branch is for conversion to VehDyn_t version 2
          VehDynV2::VehDyn_t * const pDestVehV2 = &m_VehDynV2;
          // Try decoding as old TPWinput structure
          if (DecodeTPW(pDestVehV2, ulPPortSize, pPPortData))
          {
            ConvertToVehDynV3(pDestVeh,pDestVehV2);
            *pOutData = pDestVeh;
            ulOutSize = sizeof(*pDestVeh);
            lRet = SIM_ERR_OK;
          }
          // Try decoding as old VDYOutput structure
          else if (DecodeVDYOutput(pDestVehV2, ePPortType, ulPPortSize, pPPortData))
          {
            ConvertToVehDynV3(pDestVeh,pDestVehV2);
            *pOutData = pDestVeh;
            ulOutSize = sizeof(*pDestVeh);
            lRet = SIM_ERR_OK;
          }
          // Try decoding as old RSPVDATAInput structure
          else if (DecodeRSPInputVDATA(pDestVehV2, ePPortType, ulPPortSize, pPPortData))
          {
            ConvertToVehDynV3(pDestVeh,pDestVehV2);
            *pOutData = pDestVeh;
            ulOutSize = sizeof(*pDestVeh);
            lRet = SIM_ERR_OK;
          }
          else
          {
            *pOutData = pPPortData;
            ulOutSize = ulPPortSize;
            lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
          }
        }
      }
      // Check if destination port is V2 version.
      else if ((ulRPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V2]) && ((requestPortVersionInfo.Equals(&V2_VER_INFO)) || (requestPortVersionInfo.Equals(&V0_VER_INFO))))
      {
        // This branch is for conversion to VehDyn_t version 2
        VehDynV2::VehDyn_t * const pDestVeh = &m_VehDynV2;
        // Check if provide port size corresponds to version 1 of VehDyn_t struct & either no provide port
        // version info available, or the version is 1
        if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V3]) &&
      ((pProvidePortVersionInfo == NULL) || (V3_VER_INFO.Equals(pProvidePortVersionInfo))||(V4_VER_INFO.Equals(pProvidePortVersionInfo))) &&
      ((ProvidePortVersionInfo.Equals(&V3_VER_INFO))||(ProvidePortVersionInfo.Equals(&V4_VER_INFO))))
        {
          const VehDynV3::VehDyn_t * const pInput = reinterpret_cast<const VehDynV3::VehDyn_t*>(pPPortData);
          // Call helper method to perform conversion
          ConvertToVehDynV2(pDestVeh, pInput);
          *pOutData = pDestVeh;
          ulOutSize = sizeof(*pDestVeh);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V1]) && ((pProvidePortVersionInfo == NULL) || (V1_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V1_VER_INFO)))
        {
          const VehDynV1::VehDyn_t * const pInput = reinterpret_cast<const VehDynV1::VehDyn_t*>(pPPortData);
          // Call helper method to perform conversion
          ConvertToVehDynV2(pDestVeh, pInput);
          *pOutData = pDestVeh;
          ulOutSize = sizeof(*pDestVeh);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V0]) && ((pProvidePortVersionInfo == NULL) || (V0_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V0_VER_INFO)))
        {
          const VehDynV0::VehDyn_t * const pInput = reinterpret_cast<const VehDynV0::VehDyn_t*>(pPPortData);
          // Call helper method to perform conversion
          ConvertToVehDynV2(pDestVeh, pInput);
          *pOutData = pDestVeh;
          ulOutSize = sizeof(*pDestVeh);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V2]-4) && ((pProvidePortVersionInfo == NULL) || (V0_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V2_VER_INFO)))
        {
          *pOutData = pPPortData;
          ulOutSize = ulPPortSize;
          lRet = SIM_ERR_OK;
        }
        else
        {
          // Try decoding as old TPWinput structure
          if (DecodeTPW(pDestVeh, ulPPortSize, pPPortData))
          {
            *pOutData = pDestVeh;
            ulOutSize = sizeof(*pDestVeh);
            lRet = SIM_ERR_OK;
          }
          // Try decoding as old VDYOutput structure
          else if (DecodeVDYOutput(pDestVeh, ePPortType, ulPPortSize, pPPortData))
          {
            *pOutData = pDestVeh;
            ulOutSize = sizeof(*pDestVeh);
            lRet = SIM_ERR_OK;
          }
          // Try decoding as old RSPVDATAInput structure
          else if (DecodeRSPInputVDATA(pDestVeh, ePPortType, ulPPortSize, pPPortData))
          {
            *pOutData = pDestVeh;
            ulOutSize = sizeof(*pDestVeh);
            lRet = SIM_ERR_OK;
          }
          else
          {
            *pOutData = pPPortData;
            ulOutSize = ulPPortSize;
            lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
          }
        }
      }
      // Check if destination port is V1 version.
      else if ((ulRPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V1]) && ((requestPortVersionInfo.Equals(&V1_VER_INFO)) || (requestPortVersionInfo.Equals(&V0_VER_INFO))))
      {
        // This branch is for conversion to VehDyn_t version 1
        VehDynV1::VehDyn_t * const pDestVeh = &m_VehDynV1;
        // Next check if port size is version 2 struct size and no version info available, or explicit version
        // equals the version 2 of the structure
        if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V3]) &&
       ((pProvidePortVersionInfo == NULL) || (V3_VER_INFO.Equals(pProvidePortVersionInfo))||(V4_VER_INFO.Equals(pProvidePortVersionInfo)))&&
       ((ProvidePortVersionInfo.Equals(&V3_VER_INFO))||(ProvidePortVersionInfo.Equals(&V4_VER_INFO))))
        {
          const VehDynV3::VehDyn_t * const pInput = reinterpret_cast<const VehDynV3::VehDyn_t*>(pPPortData);
          // Call helper method to perform conversion
          ConvertToVehDynV1(pDestVeh, pInput);
          *pOutData = pDestVeh;
          ulOutSize = sizeof(*pDestVeh);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V2]) && ((pProvidePortVersionInfo == NULL) || (V2_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V2_VER_INFO)))
        {
          const VehDynV2::VehDyn_t * const pInput = reinterpret_cast<const VehDynV2::VehDyn_t*>(pPPortData);
          // Call helper method to perform conversion
          ConvertToVehDynV1(pDestVeh, pInput);
          *pOutData = pDestVeh;
          ulOutSize = sizeof(*pDestVeh);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V0]) && ((pProvidePortVersionInfo == NULL) || (V0_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V0_VER_INFO)))
        {
          const VehDynV0::VehDyn_t * const pInput = reinterpret_cast<const VehDynV0::VehDyn_t *>(pPPortData);
          // Call helper method to perform conversion
          ConvertToVehDynV1(pDestVeh, pInput);
          *pOutData = pDestVeh;
          ulOutSize = sizeof(*pDestVeh);
          lRet = SIM_ERR_OK;
        }
        else
        {
          // Try decoding as old TPWinput structure
          if (DecodeTPW(&m_VehDynV2, ulPPortSize, pPPortData))
          {
            ConvertToVehDynV1(pDestVeh, &m_VehDynV2);
            *pOutData = pDestVeh;
            ulOutSize = sizeof(*pDestVeh);
            lRet = SIM_ERR_OK;
          }
          // Try decoding as old VDYOutput structure
          else if (DecodeVDYOutput(&m_VehDynV2, ePPortType, ulPPortSize, pPPortData))
          {
            ConvertToVehDynV1(pDestVeh, &m_VehDynV2);
            *pOutData = pDestVeh;
            ulOutSize = sizeof(*pDestVeh);
            lRet = SIM_ERR_OK;
          }
          // Try decoding as old RSPVDATAInput structure
          else if (DecodeRSPInputVDATA(&m_VehDynV2, ePPortType, ulPPortSize, pPPortData))
          {
            ConvertToVehDynV1(pDestVeh, &m_VehDynV2);
            *pOutData = pDestVeh;
            ulOutSize = sizeof(*pDestVeh);
            lRet = SIM_ERR_OK;
          }
          else
          {
            *pOutData = pPPortData;
            ulOutSize = ulPPortSize;
            lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
          }
        }
      }
      // Check if destination port is V0 version
      else if ((ulRPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V0]) && (requestPortVersionInfo.Equals(&V0_VER_INFO)))
      {
        VehDynV0::VehDyn_t * const pDestVeh = &m_VehDynV0;
        if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V3]) &&
       ((pProvidePortVersionInfo == NULL) || (V3_VER_INFO.Equals(pProvidePortVersionInfo))|| (V4_VER_INFO.Equals(pProvidePortVersionInfo ))) &&
       ((ProvidePortVersionInfo.Equals(&V3_VER_INFO))||(ProvidePortVersionInfo.Equals(&V4_VER_INFO))))
        {
          const VehDynV3::VehDyn_t * const pInput = reinterpret_cast<const VehDynV3::VehDyn_t*>(pPPortData);
          // Call helper method to perform conversion
          ConvertToVehDynV0(pDestVeh, pInput);
          *pOutData = pDestVeh;
          ulOutSize = sizeof(*pDestVeh);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V2]) && ((pProvidePortVersionInfo == NULL) || (V2_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V2_VER_INFO)))
        {
          const VehDynV2::VehDyn_t * const pInput = reinterpret_cast<const VehDynV2::VehDyn_t*>(pPPortData);
          // Call helper method to perform conversion
          ConvertToVehDynV0(pDestVeh, pInput);
          *pOutData = pDestVeh;
          ulOutSize = sizeof(*pDestVeh);
          lRet = SIM_ERR_OK;
        }
        else if ((ulPPortSize == VEHDYN_SUPPORTED_SIZE[CConvVehDyn::VEHDYN_INPUT_V1]) && ((pProvidePortVersionInfo == NULL) || (V1_VER_INFO.Equals(pProvidePortVersionInfo))) && (ProvidePortVersionInfo.Equals(&V1_VER_INFO)))
        {
          const VehDynV1::VehDyn_t * const pInput = reinterpret_cast<const VehDynV1::VehDyn_t*>(pPPortData);
          // Call helper method to perform conversion
          ConvertToVehDynV0(pDestVeh, pInput);
          *pOutData = pDestVeh;
          ulOutSize = sizeof(*pDestVeh);
          lRet = SIM_ERR_OK;
        }
        else
        {
          // Try decoding as old TPWinput structure
          if (DecodeTPW(&m_VehDynV2, ulPPortSize, pPPortData))
          {
            ConvertToVehDynV0(pDestVeh, &m_VehDynV2);
            *pOutData = pDestVeh;
            ulOutSize = sizeof(*pDestVeh);
            lRet = SIM_ERR_OK;
          }
          // Try decoding as old VDYOutput structure
          else if (DecodeVDYOutput(&m_VehDynV2, ePPortType, ulPPortSize, pPPortData))
          {
            ConvertToVehDynV0(pDestVeh, &m_VehDynV2);
            *pOutData = pDestVeh;
            ulOutSize = sizeof(*pDestVeh);
            lRet = SIM_ERR_OK;
          }
          // Try decoding as old RSPVDATAInput structure
          else if (DecodeRSPInputVDATA(&m_VehDynV2, ePPortType, ulPPortSize, pPPortData))
          {
            ConvertToVehDynV0(pDestVeh, &m_VehDynV2);
            *pOutData = pDestVeh;
            ulOutSize = sizeof(*pDestVeh);
            lRet = SIM_ERR_OK;
          }
          else
          {
            *pOutData = pPPortData;
            ulOutSize = ulPPortSize;
            lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
          }
        }
      }
      // All conversion attempts fail
      else
      {
        *pOutData = pPPortData;
        ulOutSize = ulPPortSize;
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
  }
  else
  {
    lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  }

  return lRet;
}

/** returns:
*   SIM_ERR_OK - when this value can be used
*   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
*   and the default value from Request Port must be used
*/
long CConvVehDyn::GetDefaultValue(
                                  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
                                  void** pDefaultData, unsigned long& ulDefaultSize)
{
  long lRet;

  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(m_VehDynV32)) && (requestPortVersionInfo.Equals(&V32_VER_INFO)))
    {
      InitDefaultVehDynV32(&m_VehDynV32);
      *pDefaultData = &m_VehDynV32;
      ulDefaultSize = sizeof(m_VehDynV32);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehDynV9)) && (requestPortVersionInfo.Equals(&V9_VER_INFO)))
    {
      InitDefaultVehDynV9(&m_VehDynV9);
      *pDefaultData = &m_VehDynV9;
      ulDefaultSize = sizeof(m_VehDynV9);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehDynV8)) && (requestPortVersionInfo.Equals(&V8_VER_INFO)))
    {
      InitDefaultVehDynV8(&m_VehDynV8);
      *pDefaultData = &m_VehDynV8;
      ulDefaultSize = sizeof(m_VehDynV8);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehDynV6_2)) && (requestPortVersionInfo.Equals(&V6_VER_INFO)))
    {
      InitDefaultVehDynV6_2(&m_VehDynV6_2);
      *pDefaultData = &m_VehDynV6_2;
      ulDefaultSize = sizeof(m_VehDynV6_2);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehDynV6)) && (requestPortVersionInfo.Equals(&V6_VER_INFO)))
    {
      InitDefaultVehDynV6(&m_VehDynV6);
      *pDefaultData = &m_VehDynV6;
      ulDefaultSize = sizeof(m_VehDynV6);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehDynV5)) && (requestPortVersionInfo.Equals(&V5_VER_INFO)))
    {
      InitDefaultVehDynV5(&m_VehDynV5);
      *pDefaultData = &m_VehDynV5;
      ulDefaultSize = sizeof(m_VehDynV5);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehDynV3)) && (requestPortVersionInfo.Equals(&V3_VER_INFO)))
    {
      InitDefaultVehDynV3(&m_VehDynV3);
      *pDefaultData = &m_VehDynV3;
      ulDefaultSize = sizeof(m_VehDynV3);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehDynV2)) && (requestPortVersionInfo.Equals(&V2_VER_INFO)))
    {
      InitDefaultVehDynV2(&m_VehDynV2);
      *pDefaultData = &m_VehDynV2;
      ulDefaultSize = sizeof(m_VehDynV2);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehDynV1)) && (requestPortVersionInfo.Equals(&V1_VER_INFO)))
    {
      InitDefaultVehDynV1(&m_VehDynV1);
      *pDefaultData = &m_VehDynV1;
      ulDefaultSize = sizeof(m_VehDynV1);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_VehDynV0)) && (requestPortVersionInfo.Equals(&V0_VER_INFO)))
    {
      InitDefaultVehDynV0(&m_VehDynV0);
      *pDefaultData = &m_VehDynV0;
      ulDefaultSize = sizeof(m_VehDynV0);
      lRet = SIM_ERR_OK;
    }
    else
    {
      lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
    }
  }
  else
  {
    lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  }
  return lRet;
}


uint8 CConvVehDyn::ConvertIOState(unsigned int position, unsigned long* pInputstate)
{
  uint8 outputstate;
  uint8 inputstate;

  inputstate = VDY_GET_IO_STATE(position, pInputstate);

  if (inputstate == VDY_IO_STATE_VALID)
  {
    outputstate = VehDynV6::VEH_DYN_IO_STATE_VALID;
  }
  else if (inputstate == VDY_IO_STATE_NOTAVAIL)
  {
    outputstate = VehDynV6::VEH_DYN_IO_STATE_NOTAVAIL;
  }
  else if (inputstate == VDY_IO_STATE_INIT)
  {
    outputstate = VehDynV6::VEH_DYN_IO_STATE_INIT;
  }
  else
  {
    outputstate = VehDynV6::VEH_DYN_IO_STATE_INVALID;
  }

  return outputstate;
}


unsigned long CConvVehDyn::ConvertIOState(unsigned int position, uint8 ui8Inputstate)
{
  uint8 inputstate;
  unsigned long outputstate = 0;

  if (ui8Inputstate == VehDynV6::VEH_DYN_IO_STATE_VALID)
  {
    inputstate = VDY_IO_STATE_VALID;
  }
  else if (ui8Inputstate == VehDynV6::VEH_DYN_IO_STATE_NOTAVAIL)
  {
    inputstate = VDY_IO_STATE_NOTAVAIL;
  }
  else if (ui8Inputstate == VehDynV6::VEH_DYN_IO_STATE_INIT)
  {
    inputstate = VDY_IO_STATE_INIT;
  }
  else
  {
    inputstate = VDY_IO_STATE_INVALID;
  }

  outputstate = VDY_SET_IO_STATE(position, inputstate, &outputstate);

  return outputstate;
}

unsigned char CConvVehDyn::ConvertVelocityCorrectionQuality(unsigned char VeloCorr_corrQual)
{
  unsigned char retVal = 0;
  switch (VeloCorr_corrQual)
  {
  case VDY_VELO_CORR_QUAL_EEPROM_V1toV8:
    retVal = VDY_VELO_CORR_QUAL_EEPROM_V9;
    break;
  case VDY_VELO_CORR_QUAL_RANGE_NVERIFIED_V1toV8:
    retVal = VDY_VELO_CORR_QUAL_RANGE_NVERIFIED_V9;
    break;
  case VDY_VELO_CORR_QUAL_RANGE_VERIFIED_V1toV8:
    retVal = VDY_VELO_CORR_QUAL_RANGE_VERIFIED_V9;
    break;
  case VDY_VELO_CORR_QUAL_SNA_V1toV8:
    retVal = VDY_VELO_CORR_QUAL_SNA_V9;
    break;
  default:
    break;
  }
  return retVal;
}

unsigned char CConvVehDyn::ConvertVeloCorr_corrQual(unsigned char VelocityCorrectionQuality)
{
  unsigned char retVal = 0;
  switch (VelocityCorrectionQuality)
  {
  case VDY_VELO_CORR_QUAL_EEPROM_V9:
    retVal = VDY_VELO_CORR_QUAL_EEPROM_V1toV8;
    break;
  case VDY_VELO_CORR_QUAL_RANGE_NVERIFIED_V9:
    retVal = VDY_VELO_CORR_QUAL_RANGE_NVERIFIED_V1toV8;
    break;
  case VDY_VELO_CORR_QUAL_RANGE_VERIFIED_V9:
    retVal = VDY_VELO_CORR_QUAL_RANGE_VERIFIED_V1toV8;
    break;
  case VDY_VELO_CORR_QUAL_SNA_V9:
    retVal = VDY_VELO_CORR_QUAL_SNA_V1toV8;
    break;
  default:
    break;
  }
  return retVal;
}

void CConvVehDyn::ConvertPosOfStates(VehDynV9::State_array_t &Dest, const VehDynV6::State_array_t &Src)
{
  Dest[VDY_SOUT_POS_VELOCITY_V9]     = Src[VDY_SOUT_POS_VEL_V1toV8];
  Dest[VDY_SOUT_POS_ACCEL_V9]        = Src[VDY_SOUT_POS_ACCEL_V1toV8];
  Dest[VDY_SOUT_POS_YAWRATE_V9]      = Src[VDY_SOUT_POS_YWR_V1toV8];
  Dest[VDY_SOUT_POS_CURVE_V9]        = Src[VDY_SOUT_POS_CURVE_V1toV8];
  Dest[VDY_SOUT_POS_DRVINTCURVE_V9]  = Src[VDY_SOUT_POS_DRCRV_V1toV8];
  Dest[VDY_SOUT_POS_LATERALACCEL_V9] = Src[VDY_SOUT_POS_LATACC_V1toV8];
  Dest[VDY_SOUT_POS_SLIPANGLE_V9]    = Src[VDY_SOUT_POS_SSA_V1toV8];
  Dest[VDY_SOUT_POS_MOTIONSTATE_V9]  = Src[VDY_SOUT_POS_MSTAT_V1toV8];
}

void CConvVehDyn::ConvertPosOfStates(VehDynV6::State_array_t &Dest, const VehDynV9::State_array_t &Src)
{
  Dest[VDY_SOUT_POS_VEL_V1toV8]    = Src[VDY_SOUT_POS_VELOCITY_V9];
  Dest[VDY_SOUT_POS_ACCEL_V1toV8]  = Src[VDY_SOUT_POS_ACCEL_V9];
  Dest[VDY_SOUT_POS_YWR_V1toV8]    = Src[VDY_SOUT_POS_YAWRATE_V9];
  Dest[VDY_SOUT_POS_CURVE_V1toV8]  = Src[VDY_SOUT_POS_CURVE_V9];
  Dest[VDY_SOUT_POS_DRCRV_V1toV8]  = Src[VDY_SOUT_POS_DRVINTCURVE_V9];
  Dest[VDY_SOUT_POS_LATACC_V1toV8] = Src[VDY_SOUT_POS_LATERALACCEL_V9];
  Dest[VDY_SOUT_POS_SSA_V1toV8]    = Src[VDY_SOUT_POS_SLIPANGLE_V9];
  Dest[VDY_SOUT_POS_MSTAT_V1toV8]  = Src[VDY_SOUT_POS_MOTIONSTATE_V9];
}


// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvVehDyn::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Always allow same type/size ports to be bound together
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize))
  {
    bResult = true;
  }
  else if (ePPortType == simREFERENCE_t)
  {
    bResult = PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo);
  }
  else
  {
    bResult = (PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo) && PortSupported(ePPortType, ulPPortSize));
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvVehDyn::AreVersionsCompatible(
                                        SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
                                        SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
{
  bool bResult = false;
  // Always allow same type/size ports to be bound together
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && (providePortVersionInfo.Equals(&requestPortVersionInfo)))
  {
    bResult = true;
  }
  else if (ePPortType == simREFERENCE_t)
  {
    bResult = PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo);
  }
  else
  {
    // Ports are different: conversion necessary and possible if provide & request port known
    bResult = PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo) && PortSupported(ePPortType, ulPPortSize, &providePortVersionInfo);
  }
  return bResult;
}

//
// Factory function for creating converter instances
//
IConverter * CreateVehDynConvClass(void)
{
  return new CConvVehDyn();
}
