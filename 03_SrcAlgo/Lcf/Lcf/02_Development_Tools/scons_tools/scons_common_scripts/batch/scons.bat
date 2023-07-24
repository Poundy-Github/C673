@echo off

REM ***************************************************************************************************
REM  COMPANY: Continental AG, ADAS, A.D.C. GmbH
REM  PROJECT: ETK/SCT_Sconstools
REM  COMPONENT: scons_common_scripts
REM  FILE NAME: batch\scons.bat
REM  DESCRIPTION: Call scons to execute main script SConstruct.
REM  INITIAL AUTHOR: Fischer-EXT, Andre (uidg5297)
REM  CREATION DATE: 2015/10/08

REM  LAST CHANGE:      $Date: 2021/12/13 19:05:01CET $
REM                    $Author: Wang, David (Wangd3) $

REM  CURRENT VERSION:  $Revision: 1.1 $
REM #############################################################################
REM  CHANGES:                   $Log: scons.bat  $
REM  CHANGES:                   Revision 1.1 2021/12/13 19:05:01CET Wang, David (Wangd3) 
REM  CHANGES:                   Initial revision
REM  CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/batch/project.pj
REM  CHANGES:                   Revision 1.23 2017/07/18 14:01:23CEST Bhagawati, Tridip (uidr2134) 
REM  CHANGES:                   Updated
REM  CHANGES:                   Revision 1.22 2017/07/14 12:32:44CEST Bhagawati, Tridip (uidr2134) 
REM  CHANGES:                   [GenScons] Add 'project' parameter in Scons build command for mainstream projects to choose which project to build
REM  CHANGES:                   Revision 1.21 2017/03/30 13:50:51CEST Singh, Vishal (uidj9083) 
REM  CHANGES:                   Update for new attrib option
REM  CHANGES:                   Revision 1.20 2016/03/04 10:11:51CET Bhagawati, Tridip (uidr2134) 
REM  CHANGES:                   Error and Warnings summary report to be provide in build log for the scons targets
REM  CHANGES:                   Revision 1.19 2015/09/23 16:28:19CEST Fischer-EXT, Andre (uidg5297) 
REM  CHANGES:                   comment call of extraction batch file for ti-tools compared to revision 1.17
REM  CHANGES:                   - Added comments -  uidg5297 [Sep 23, 2015 4:28:20 PM CEST]
REM  CHANGES:                   Change Package : 379758:1 http://mks-psad:7002/im/viewissue?selection=379758
REM  CHANGES:                   Revision 1.17 2015/06/26 13:11:50CEST Palanisamy-EXT, Lenin (uidr0826) 
REM  CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
REM  CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 1:11:50 PM CEST]
REM  CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

REM ***************************************************************************************************


if "%~1"=="/?" goto help
if "%~1"=="-?" goto help
if "%~1"=="/h" goto help
if "%~1"=="-h" goto help
if "%~1"=="/help" goto help
if "%~1"=="-help" goto help


REM Unzip all zipped tools from ti_tools...
REM call ..\..\..\02_Development_Tools\ti_tools\unzip_tools\unzip_tools.bat

set SCONS_ERRORLEVEL=
setlocal
set PYTHONPATH=""
set PYTHONSTARTUP=""
set PATH="%PATH%";..\..\..\02_Development_Tools\movpy

REM Copy shared scons scripts to the locations defined in sonscript_setup_config.scfg 
..\..\..\02_Development_Tools\movpy\movpy.exe ..\..\..\02_Development_Tools\scons_tools\scons_adas_extensions\sconscript_setup.py 2>&1 | ..\..\..\02_Development_Tools\scons_tools\gnutools\tee.exe sconsbuild.log
REM Execute scons script, save returned error level to errorlevel.txt, and redirect scons output to tee.exe for build log.
(..\..\..\02_Development_Tools\movpy\movpy.exe ..\..\..\02_Development_Tools\scons_tools\scons\scons.py %* & call echo %%^^ERRORLEVEL%%>errorlevel.txt) 2>&1 | ..\..\..\02_Development_Tools\scons_tools\gnutools\tee.exe -a sconsbuild.log

if "%1"=="-c" if "%2"=="" (del .sconsign.dblite)
if "%1"=="-C" if "%2"=="" (del .sconsign.dblite)

endlocal

REM Read the returned errorlevel in errorlevel.txt
set /p SCONS_ERRORLEVEL=<errorlevel.txt

REM Return to original path
cd %oriPath%

if NOT "%COMSPEC%" == "%SystemRoot%\system32\cmd.exe" goto returncode
if errorlevel 9009 echo you do not have python in your PATH
goto endscons

:returncode
exit /B %SCONS_ERRORLEVEL%

:help
echo.
echo Help
echo ====
echo scons.bat [-c ^| -j N ^| -? ^| /? ^| define=define1,define2 ^| verbose ^| install_to_deliverables_dir ^| TARGET]
echo.
echo -c        Clean all targets
echo -j N      Multicore build, whereat N is the amount of threads (e.g. scons.bat -j 4)
echo -? or /?  This help output
echo define=   Pass preprocessor define. Separate define with comma. 
echo           Example : define=define1,define2
echo verbose   verbose=0: displays only reduced build commands (default)
echo           verbose=1: displays full build commands
echo install_to_deliverables_dir=	Pass variant name.
echo		   Example : install_to_deliverables_dir=variant
echo no_err_warning    no_err_warning=1: displays total num of errors and warnings
echo                   no_err_warning=0: (default)
echo no_attrib no_attrib=1: disable launch of attrib.exe on read only directories
echo           no_attrib=0: (default)
echo project   project=Pass base/application project name.
echo           Example : project='MFCxxxccyy'
echo TARGET    One of the following targets:
echo.
REM Check if aliases.txt already exists
if not exist aliases.txt goto create_help
REM Check if aliases.txt is up to date
set file1=aliases.txt
set file2=sconstruct_config.scfg
set file3=sconstruct_temp
set sconstruct=..\..\..\02_Development_Tools\scons_tools\scons_common_scripts\sconstruct\SConstruct
REM Checking any file is updated in scons_tools 
 
if exist %sconstruct% (
copy %sconstruct% %file3% > nul
for /F %%i in ('dir %file1% %file2% %file3% /B /O:D ^| more +1') do set _NEWEST=%%i
del /F %file3% > nul
) else (
for /F %%i in ('dir %file1% %file2% /B /O:D ^| more +1') do set _NEWEST=%%i
)
if not %_NEWEST%==%file1% goto create_help
goto display_help

:create_help
REM Execute scons in order to create aliases.txt
echo          ...  Alias-list is not found or not up to date  ...
echo          ...             Reading SConscripts             ...
echo.
..\..\..\02_Development_Tools\movpy\movpy.exe ..\..\..\02_Development_Tools\scons_tools\scons_adas_extensions\sconscript_setup.py
..\..\..\02_Development_Tools\movpy\movpy.exe ..\..\..\02_Development_Tools\scons_tools\scons\scons.py no_target 2>nul  1>nul
goto display_help

:display_help
REM Display aliases.txt and finish help menu
if exist aliases.txt (
type aliases.txt
echo.
echo           If desired and applicable, please build TARGET_VARIANT, e.g. xxx_algo_release.
goto display_qac_help
) else (
echo.
echo Error: An older GenericScons version seems to be used.
echo        Help menu cannot be displayed.
)

:display_qac_help
echo ====
echo Usage of QAC(PP) via scons:
echo ====
echo scons.bat [qac_source=files ^| qac_options=options ^| qar_format=format] qac target
echo .
echo qac_source    Pass individual files to be analyzed, separate files with comma, e.g.
echo               qac_source=D:\sandboxes\CIPP\04_Engineering\01_Source_Code\algo\cipp\cipp_main.cpp
echo qac_options   Pass additional qac options, separate with comma, e.g.
echo               qac_options=-disp,-su=3
echo qar_format    Pass desired format of compliance report, either
echo               qar_format=html    or    qar_format=xhtml
echo qac_target    See target list above.  

:endscons
call :returncode %SCONS_ERRORLEVEL%
