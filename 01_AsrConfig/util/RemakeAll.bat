@ECHO OFF

:: Call the optional launch_cfg.bat
:: This file contains TARGET, DERIVATE, TRESOS_BASE, and TOOLPATH_COMPILER.
:: These variables can also be provided as environment variables.
IF "%TARGET%"=="" SET TARGET=TRICORE
IF "%DERIVATE%"=="" SET DERIVATE=TC38XQ
IF "%TOOLCHAIN%"=="" SET TOOLCHAIN=tasking
IF [%TOOLPATH_COMPILER%]==[] SET TOOLPATH_COMPILER=%TASKING_TriCore_v6_3r1%
IF [%PROJECT_BASE%]==[] SET PROJECT_BASE=..\..\
IF [%TRESOS_BASE%]==[] SET TRESOS_BASE=..\..\00_AsrStack
IF [%PLUGINS_BASE%]==[] set PLUGINS_BASE=%TRESOS_BASE%\plugins
IF [%TRACE32_PATH%]==[] set TRACE32_PATH=D:\00_software\07_T32_2.4.48
IF [%DEBUG_OPT_FILE%]==[] set DEBUG_OPT_FILE = -s ..\TC38X_TriCore_Debug.cmm ..\output\bin\$(PROJECT).$(ABS_FILE_SUFFIX)
IF [%TOOLPATH_PYTHON_EXE%]==[] SET TOOLPATH_PYTHON_EXE=%Python3_exe%

:: SWC Maker
goto Pre_Build_Process
:Pre_Build_End

:: set PROJECT_ROOT to the current project directory (relative to location of this batch file, converted to absolute path)
for /f %%i in ("%~dp0..") do set PROJECT_ROOT=%%~fi

:: add %TRESOS_BASE%\bin to path
set PATH=%PATH%;%TRESOS_BASE%\bin;

:: set path of make executable
SET MAKE_EXE=%PLUGINS_BASE%\Make_TS_TxDxM4I0R0\tools\GNU_Make\make.exe

SET MAKE_OPTIONS=
:: a user makefile is specified
IF "%1"=="-f" GOTO call_make
:: no user makefile is specified, use default file
SET MAKE_OPTIONS=-f %PROJECT_BASE%/04_Script/02_Make/Makefile.mak
GOTO call_make


:call_make
:: make clean
%MAKE_EXE% SHELL=cmd.exe %MAKE_OPTIONS% "clean"

:: make -j
%MAKE_EXE% SHELL=cmd.exe %MAKE_OPTIONS% "-j20"

Goto finish

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


exit /B
