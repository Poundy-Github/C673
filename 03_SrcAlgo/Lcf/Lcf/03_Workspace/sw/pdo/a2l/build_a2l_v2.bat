@echo off

rem setlocal
setlocal enabledelayedexpansion

:: Set default values meaning MFC400 stuff is active
set PAUSE=1
set PRODUCT=0

:optionsloop
if "%1" == "nopause" set PAUSE=0
if "%1" == "help" (
  echo.
  echo Script options are   nopause         Does not pause at the end
  echo                      mfc431          Build SDL file for mfc431
  echo                      mfc430hi17      Build SDL file for mfc430hi17
  echo                      hfl110          Build SDL file for hfl110
  echo                      hfl110ta10      Build SDL file for hfl110ta10
  echo                      ars441          Build SDL file for ARS441
  goto EXIT_NOPAUSE
)
if "%1" == "p" (
  if not "%2" == "" (
    set PRODUCT=%2
  ) else (
  echo.
    echo Error: Please specify the product ID with as a parameter to the "p" argument
    echo        ie. sw_build.bat p mfc431
  goto EXIT_NOPAUSE
    )
)

rem shift next command option and do the loop again until all options are processed 
shift
if "%1" == "" goto optionsend
goto optionsloop
:optionsend

set PROJECT_NAME=%PRODUCT%
set APP_PROJECT_NAME=%PRODUCT%
if "%PRODUCT:~0,6%" == "mfc431" (
  set SOCTYPE=high
  set MFC431=1
) else if "%PRODUCT:~0,6%" == "ars441" (
  set SOCTYPE=low
  set MFC431=0
) else if "%PRODUCT:~0,6%" == "hfl110" (
  set SOCTYPE=high
  set MFC431=1
) else (
  exit /b
)


set PROJECT_ROOT=..\..\..\..\..
set PDO_PATH=c:\tools\pdo\2.16.1.1
set PDO_TOOL=%PDO_PATH%\Pdo_tool.exe
set PDO_SCAN=%PDO_PATH%\Pdo_scan.exe
set PDO_TMP_DIR=%PROJECT_ROOT%\04_Engineering\04_build\a2l\
set LOGFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%APP_PROJECT_NAME%_SOC.a2l.log

set PERL=c:\tools\perl\v5.6\bin\perl.exe
set PYTHON_PATH=c:\tools\python\2.7.10
set PYTHON=%PYTHON_PATH%\python.exe
set PDO_RLST=%PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\readLstFile.py

set PDOHEADER_CONFIG_FILE=%PDO_TMP_DIR%\target_headerFile.cfg
set PDOCINPUT_FILE=%PDO_TMP_DIR%\compiler_input.cfg
set PDODEFINE_FILE=%PDO_TMP_DIR%\compiler_defines.cfg

set LOGFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_soc.a2l.log

set BUILD_MODE=release
set TARGET= arm-m_0 dsp_0 dsp_1  
if "%SOCTYPE%" == "high" (
	set TARGET=%TARGET% arm-a_0 arm-m_1 eve_0 eve_1
)

if "%PRODUCT:~0,6%" == %mfc431% (

  rem ===  MFC431 config is here ===
set INCLUDES=-I %PROJECT_ROOT%\04_Engineering\04_Build\tools\bios\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\Tools\ti_bios\6.41.01.36\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\tools\gcc_arm\4.7_2012q4\lib\gcc\arm-none-eabi\4.7.3\include

set DEFINES=-D A2L_CFG_ARS441=0 -D A2L_CFG_MFC431=1 -D A2L_CFG_HFL110=0 -DUSE_OLD_ADC_CODING_STYLE_TYPEDEFS

  rem ) %mfc431%
)

if "%PRODUCT:~0,6%" == "hfl110" (

  rem ===  HFL110 config is here ===
  	
set INCLUDES=-I %PROJECT_ROOT%\04_Engineering\04_Build\tools\arm\include ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\bios\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\Tools\ti_bios\6.41.01.36\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\tools\gcc_arm\4.7_2012q4\lib\gcc\arm-none-eabi\4.7.3\include
  
set DEFINES=-D A2L_CFG_ARS441=0 -D A2L_CFG_MFC431=0 -D A2L_CFG_HFL110=1 -DUSE_OLD_ADC_CODING_STYLE_TYPEDEFS

)

if "%PROJECT_NAME:~0,6%" == "ars441" (

  rem ===  ars441 config is here ===

set INCLUDES=-I %PROJECT_ROOT%\04_Engineering\04_Build\tools\bios\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\Tools\ti_bios\6.41.01.36\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\tools\gcc_arm\4.7_2012q4\lib\gcc\arm-none-eabi\4.7.3\include
  
set DEFINES=-D A2L_CFG_ARS441=1 -D A2L_CFG_MFC431=0 -D A2L_CFG_HFL110=0 -DUSE_OLD_ADC_CODING_STYLE_TYPEDEFS
  rem ) ars441
)

rem Convert map files into PDO confirm map file including address offset for (GD) XCP 
echo.
echo Converting map files
pushd .


echo %TARGET%

for %%a in (%TARGET%) do (
	if "%%a" == "arm-a_0" (
		%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\GCC_mapconv.pl ^
 %PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\%BUILD_MODE%_%%a\%%a.map ^
 %PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\%BUILD_MODE%_%%a\%%a-modified.map ^
 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x8FFFFFFF 0x20000000
	) else (
		%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl ^
 %PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\%BUILD_MODE%_%%a\%%a.map ^
 %PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\%BUILD_MODE%_%%a\%%a-modified.map ^
 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x8FFFFFFF 0x20000000
	)
)

if NOT exist %PROJECT_ROOT%\04_Engineering\04_Build\a2l (
	mkdir %PROJECT_ROOT%\04_Engineering\04_Build\a2l
)

echo "###### Load CFile Source, Define and Header List from lst File ######" > %LOGFILE%
for %%a in (%TARGET%) do (
	 set CMD=%PYTHON% %PDO_RLST% %PROJECT_ROOT%\04_Engineering\04_build\out\%APP_PROJECT_NAME%\%BUILD_MODE%_%%a\%%a.lst -i %PDO_TMP_DIR%\%%a_hFile.cfg -c %PDO_TMP_DIR%\%%a_cFile.txt -d %PDO_TMP_DIR%\%%a_dFile.cfg -S 
REM	 echo !CMD!
	%PYTHON% %PDO_RLST% %PROJECT_ROOT%\04_Engineering\04_build\out\%APP_PROJECT_NAME%\%BUILD_MODE%_%%a\%%a.lst -i %PDO_TMP_DIR%\%%a_hFile.cfg -c %PDO_TMP_DIR%\%%a_cFile.txt -d %PDO_TMP_DIR%\%%a_dFile.cfg
)

rem set logfile
if exist %LOGFILE% (
del %LOGFILE%
)


rem =================== ALL CORE MAP, DAT AND A2L FILES ======================================================

for %%a in (%TARGET%) do (
	set CMD=%PDO_SCAN% -c %%a_pdo_cmt.cfg -c %PDO_TMP_DIR%\%%a_hFile.cfg %DEFINES% dummy_%%a.c -o %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a.dat  >> %LOGFILE% 2>&1
REM	echo  !CMD!
	REM %PDO_SCAN% -c %%a_pdo_cmt.cfg -c %PDO_TMP_DIR%\%%a_hFile.cfg %DEFINES% dummy_%%a.c -o %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a.dat  >> %LOGFILE% 2>&1
	echo %%a >> %LOGFILE% 
	%PDO_SCAN% -c arm_m3_pdo_cmt.cfg -c %PDO_TMP_DIR%\%%a_hFile.cfg -I "C:\tools\gcc_arm\4.7_2012q4\lib\gcc\arm-none-eabi\4.7.3\include" -I "%PROJECT_ROOT%\04_Engineering\04_Build\tools\bios\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include" -I "C:\Tools\ti_bios\6.41.01.36\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include" ^ %DEFINES% @%PDO_TMP_DIR%\%%a_cFile.txt -o %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a.dat  >> %LOGFILE% 2>&1
)


if ERRORLEVEL 0 goto PDO_MERGE
echo ERROR running PDOScan!
goto EXIT



:PDO_MERGE
echo.
echo Merge core DAT files with single core map files
rem Generate DAT file including map information
echo. DPU cores
for %%a in (%TARGET%) do (
	if EXIST %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a.dat (
REM		echo %PDO_TOOL% %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a.dat -c %PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\%BUILD_MODE%_%%a\%%a-modified.map  -f xmldat1.0 -o %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a_map.dat 
		%PDO_TOOL% %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a.dat -c %PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\%BUILD_MODE%_%%a\%%a-modified.map  -f xmldat1.0 -o %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a_map.dat >> %LOGFILE% 2>&1
	)
)

if ERRORLEVEL 0 goto PDOSCAN_OK
echo ERROR running PDOTool merge!
goto EXIT


:PDOSCAN_OK
rem echo PDOSCAN_OK
rem Generate A2L from DAT


echo.  
echo Generate A2L files for the single cores
for %%a in (%TARGET%) do (
	if EXIST %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a.dat (
	REM echo. %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a_map.a2l 
    echo %PDO_TOOL% %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a_map.dat -f asap2 --config pdo_tool_cfg_soc_%%a_a2l.cfg -o %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a_map.a2l
	%PDO_TOOL% %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a_map.dat -f asap2 --config pdo_tool_cfg_soc_%%a_a2l.cfg -o %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a_map.a2l >> %LOGFILE% 2>&1
	)
)

if ERRORLEVEL 0 goto PDOTOOL_OK
echo ERROR running PDOTool!
goto EXIT


:PDOTOOL_OK
echo.  
echo Merge All core A2L files to one single A2L file
pushd.

for %%a in (%TARGET%) do (
	set ALL_A2L=!ALL_A2L! %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a_map.a2l
REM	echo !ALL_A2L!
)
	
REM echo %PERL% merge_a2l_files.pl %PROJECT_NAME% !ALL_A2L! 
%PERL% merge_a2l_files.pl %PROJECT_NAME% !ALL_A2L! 

popd

echo. 
echo Copy combined A2L File
copy %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\%PROJECT_NAME%_PR_soc_rel.a2l ^ %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_PR_soc_rel.a2l
del %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\%PROJECT_NAME%_PR_soc_rel.a2l


:EXIT
rem Delete temporary files

for %%a in (%TARGET%) do (
	rem Delete out/modified map files
	del %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a.dat
	rem Delete merged core dat files containing map information
	del %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a_map.dat
	rem Delete core A2L files
	del %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_%%a_map.a2l
	
	del %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%%a_cFile.txt
	del %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%%a_dFile.cfg
	del %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%%a_hFile.cfg
)

if %PAUSE% == 0 goto EXIT_NOPAUSE:
pause
:EXIT_NOPAUSE
