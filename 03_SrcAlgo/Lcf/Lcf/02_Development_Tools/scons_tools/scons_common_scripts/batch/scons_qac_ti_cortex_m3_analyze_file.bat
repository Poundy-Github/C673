@echo off

REM ***************************************************************************************************
REM  COMPANY: Continental AG, ADAS, A.D.C. GmbH
REM  PROJECT: ETK/SCT_Sconstools
REM  COMPONENT: scons_common_scripts
REM  FILE NAME: batch\scons_qac_ti_cortex_m3_analyze_file.bat
REM  DESCRIPTION: Batch file in order to run a QAC analysis on only a single source file, executed from Visual Studio.
REM  INITIAL AUTHOR: Singh, Vishal (uidj9083)
REM  CREATION DATE: 2015/09/30

REM  LAST CHANGE:      $Date: 2021/12/13 19:05:00CET $
REM                    $Author: Wang, David (Wangd3) $

REM  CURRENT VERSION:  $Revision: 1.1 $
REM #############################################################################
REM  CHANGES:                   $Log: scons_qac_ti_cortex_m3_analyze_file.bat  $
REM  CHANGES:                   Revision 1.1 2021/12/13 19:05:00CET Wang, David (Wangd3) 
REM  CHANGES:                   Initial revision
REM  CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/batch/project.pj
REM  CHANGES:                   Revision 1.1 2015/09/30 07:40:41CEST Singh, Vishal (uidj9083) 
REM  CHANGES:                   Initial revision
REM  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/SCT_Sconstools/scons_common_scripts/batch/project.pj


REM ***************************************************************************************************

REM get component name
for %%I in ( %1 ) do (
set component=%%~nI
)
pushd ..\..\..\..\03_Workspace\algo\%component%
REM call scons with file to be analyzed
call scons.bat build_from_ide=1 %component%_qac_ti_cortex_m3 qac_source=%2
popd