@echo off
:: Note: Project setup - user make environment
goto Pre_Build_Process
:Pre_Build_End
:: set PROJECT_ROOT to the current project directory (relative to location of this batch file, converted to absolute path)
for /f %%i in ("%~dp0..") do set PROJECT_ROOT=%%~fi

:: Call the optional launch_cfg.bat
:: This file contains TARGET, DERIVATE, TRESOS_BASE, and TOOLPATH_COMPILER.
:: These variables can also be provided as environment variables.
if exist "%~dp0launch_cfg.bat" call %~dp0launch_cfg
if exist "%TRESOS_BASE%\..\launch_cfg_user.bat" call %TRESOS_BASE%\..\launch_cfg_user

:: check, if the path variables for PROJECT_ROOT is set
if not defined TRESOS_BASE goto missing_TRESOS_BASE
if not exist "%TRESOS_BASE%" goto missing_TRESOS_BASE
if not exist "%PLUGINS_BASE%" goto missing_PLUGINS_BASE
:: add %TRESOS_BASE%\bin to path
set PATH=%PATH%;%TRESOS_BASE%\bin;

:: ensure working directory is util folder of current project directory (location of this batch file)
cd /D "%~dp0%"
set EXIT_CODE=0

:: check for command line parameters
if [%1]==[] goto interactive
if [%1]==[/c] goto call_command_c
if [%1]==[make] goto call_batch
if [%~x1]==[.bat] goto call_batch

:call_command
:: invoke command and terminate
cmd /c %*
set EXIT_CODE=%ERRORLEVEL%
goto finish

:call_command_c
:: invoke command and terminate
cmd %*
set EXIT_CODE=%ERRORLEVEL%
goto finish

:call_batch
:: invoke batch and terminate
call %*
set EXIT_CODE=%ERRORLEVEL%
goto finish

:interactive
:: start interactive command shell and display make rules
cmd /k make show_rules
goto :eof

:: The variable TRESOS_BASE was not specified
:missing_TRESOS_BASE
echo.
echo    The variable TRESOS_BASE was not set correctly:
echo    %TRESOS_BASE%.
echo    Please specify this variable manually by editing
echo    the batch file 'launch_cfg.bat'.
echo.
set EXIT_CODE=1
if [%1]==[] pause
goto :finish

:: The path given by PLUGINS_BASE does not exist
:missing_PLUGINS_BASE
echo.
echo    The variable PLUGINS_BASE was not set correctly:
echo    %PLUGINS_BASE%.
echo    Please specify this variable manually by editing
echo    the batch file 'launch_cfg.bat'.
echo.
set EXIT_CODE=1
if [%1]==[] pause

:Pre_Build_Process
echo.
echo ======================================================================================================================
echo                              Pre-Build Process Start
echo ======================================================================================================================
echo.
echo  /-----------------------------------------------------------------------------------/
echo  /  CAUTION: pyyaml lib required                                                     /
echo  /-----------------------------------------------------------------------------------/
echo  /  CAUTION: DO NOT CHANGE the order of the tool generators in Pre-Build Process     /
echo  /-----------------------------------------------------------------------------------/
echo  /  CAUTION: Launch.bat MUST be clicked after every EB Tresos generate               /
echo  /-----------------------------------------------------------------------------------/
echo  /  Pre-Build Process will take less than 2 minutes.                                 /
echo  /  Please be patient.                                                               /
echo  /-----------------------------------------------------------------------------------/
timeout 10
echo.
echo ======================================================================================================================
echo                              Pre-Build Process - Rta Tools - Phase 1/3 - RtaTaskLutGenerator                        
echo ======================================================================================================================
cd "..\..\06_Tools\05_RtaTools\RtaTaskIdLutGenerator"
if exist "GenerateRtaTaskIdLut.bat" call GenerateRtaTaskIdLut.bat -r ..\..\.. ..\Config\TaskIdLutGenerator_InputCfg.yaml 
cd "..\..\..\01_AsrConfig\util"

echo.
echo ======================================================================================================================
echo                              Pre-Build Process - Rta Tools - Phase 2/3 - RteStandardRtaInstrGenerator                 
echo ======================================================================================================================
echo If you want to enable/disable tasks/runnable to measure, call the batch file from CMD,
echo using the command of RteStandardRtaInstrGenerator in launch.bat with -g at the end to open GUI.
echo Don not forget to push all generated files in tool to save the configuration.
cd "..\..\06_Tools\05_RtaTools\RteStandardRtaInstrGenerator"
if exist "GenerateRteStandardRtaInstrumentation.bat" call GenerateRteStandardRtaInstrumentation.bat -r ..\..\.. ..\Config\RteStandardRtaInstrGenerator_InputCfg.yaml 
cd "..\..\..\01_AsrConfig\util"

echo.
echo ======================================================================================================================
echo                              Pre-Build Process - Pdo Tool                                         
echo ======================================================================================================================
cd "..\..\06_Tools\03_PdoTool"
if exist "RunPdoTool.bat" call RunPdoTool.bat
cd "..\..\01_AsrConfig\util"

echo.
echo ======================================================================================================================
echo                              Pre-Build Process - Swc Tool                                         
echo ======================================================================================================================
cd "..\..\06_Tools\04_SwccliTool\SoftwareContainerTool_tsf_3_5"
if exist "MFC5J3_MCU_SWC_Generator.bat" call MFC5J3_MCU_SWC_Generator.bat
cd "..\..\..\01_AsrConfig\util"

echo.
echo ======================================================================================================================
echo                              Pre-Build Process - Rta Tools - Phase 3/3 - RtaXmlGenerator                               
echo ======================================================================================================================
cd "..\..\06_Tools\05_RtaTools\RtaXmlGenerator"
if exist "GenerateRtaConfigXmls.bat" call GenerateRtaConfigXmls.bat ..\Config\RtaXmlGenerator_InputCfg.yaml -r ..\..\.. -p ..\..\.. -i ..\..\.. -o ..\..\..
if exist ..\..\..\05_Output\rta_xml\*.log copy ..\..\..\05_Output\rta_xml\*.log ..\..\..\02_SrcAppl\MeasServ\Rta\02_Config\GenData\
if exist ..\..\..\05_Output\rta_xml\*.log del ..\..\..\05_Output\rta_xml\*.log
cd "..\..\..\01_AsrConfig\util"

echo.
if not exist ..\..\02_SrcAppl\MeasServ\Rta\02_Config\GenData\Intermediate md ..\..\02_SrcAppl\MeasServ\Rta\02_Config\GenData\Intermediate
if exist ..\..\02_SrcAppl\MeasServ\Rta\02_Config\GenData\__pycache__ rd /s/q ..\..\02_SrcAppl\MeasServ\Rta\02_Config\GenData\__pycache__
copy ..\..\02_SrcAppl\MeasServ\Rta\02_Config\GenData\*.log ..\..\02_SrcAppl\MeasServ\Rta\02_Config\GenData\Intermediate\
del ..\..\02_SrcAppl\MeasServ\Rta\02_Config\GenData\*.log

@REM echo.
@REM echo ======================================================================================================================
@REM echo                              Pre-Build Process - Copy Rte_Type.h to MTS workspace
@REM echo ======================================================================================================================
@REM cd "..\output\generated\include"
@REM if exist Rte_Type.h copy Rte_Type.h ..\..\..\..\02_MFC5J3_C385_Transfer2Mts\01_TransfertoMts\ 
@REM cd "..\..\..\util"

echo ======================================================================================================================
echo                              Pre-Build Process Finish.
echo.
echo                              Output path:
echo                                           01_AsrConfig\output\generated\include
echo                                           01_AsrConfig\output\generated\src
echo                                           02_SrcAppl\MeasServ\Rta\02_Config\GenData
echo                                           05_Output\pdo
echo                                           05_Output\rta_xml
@REM echo                                           02_MFC5J3_C385_Transfer2Mts\01_TransfertoMts
echo ======================================================================================================================
timeout 3
goto Pre_Build_End

:finish
exit /B %EXIT_CODE%
