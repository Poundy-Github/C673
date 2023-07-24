@echo off

REM ***************************************************************************************************
REM  COMPANY: Continental AG, ADAS, A.D.C. GmbH
REM  PROJECT: ETK/SCT_Sconstools
REM  COMPONENT: scons_common_scripts
REM  FILE NAME: batch\scons_qac_ti_cortex_a8_analyze_file.bat
REM  DESCRIPTION: Batch file in order to run a QAC analysis on only a single source file, executed from Visual Studio.
REM  INITIAL AUTHOR: Fischer-EXT, Andre (uidg5297)
REM  CREATION DATE: 2015/11/11

REM  LAST CHANGE:      $Date: 2021/12/13 19:04:59CET $
REM                    $Author: Wang, David (Wangd3) $

REM  CURRENT VERSION:  $Revision: 1.1 $
REM #############################################################################
REM  CHANGES:                   $Log: scons_qac_ti_cortex_a8_analyze_file.bat  $
REM  CHANGES:                   Revision 1.1 2021/12/13 19:04:59CET Wang, David (Wangd3) 
REM  CHANGES:                   Initial revision
REM  CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/batch/project.pj
REM  CHANGES:                   Revision 1.2 2015/06/26 13:30:34CEST uidr0826 
REM  CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
REM  CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 1:30:34 PM CEST]
REM  CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

REM ***************************************************************************************************

REM get component name
for %%I in ( %1 ) do (
set component=%%~nI
)
pushd ..\..\..\..\03_Workspace\algo\%component%
REM call scons with file to be analyzed
call scons.bat build_from_ide=1 %component%_qac_ti_cortex_a8 qac_source=%2
popd