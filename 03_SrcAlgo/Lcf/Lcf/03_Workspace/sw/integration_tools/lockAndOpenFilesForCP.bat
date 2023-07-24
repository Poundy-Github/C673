@echo off
:: This script checks out the needed files for a SoC checkpoint
:: Using the script asumes that you know what you are doing. 

:: (C) 2014 - ADC Lindau GERMANY
:: Author: Frank Sautter-Steisslinger
:: Version: 1.0  Script generation							23.06.2015    Frank Sautter-Steisslinger
::          1.1  Moved to Mainstream                        17.01.2017    Magnus Baur
::          1.2  First working version in Mainstream        17.01.2017    Magnus Baur
::          1.3  Fixed a problem with mingw console output  20.01.2017    Magnus Baur


:: Make sure changes to environment variables are only local do not affect the calling command line
setlocal EnableDelayedExpansion
set project=

:: Store current working directory, so we can CD back in case of an error
set INITIAL_WD=%CD%

:: Change working directory to the directory where this script is stored. This allows invoking
:: this script from any directory without CD'ing into the batch file's home directory
cd %~dp0
set CURRENT_WD=%CD%

:: Read input option
:optionsloop
if "%1" == "" (
  echo.
  echo Error: Please specify the product ID with a parameter to the "p" argument
  echo        ie. lockFilesForCP.bat p mfs430bw16
  exit /b
)

if "%1" == "p" (
  if "%2%"=="" (
    echo.
    echo Error: Please specify the product ID with a parameter to the "p" argument
    echo        ie. lockFilesForCP.bat p mfs430bw16
    exit /b
  ) else (
    set project=%2
  )
)

:: Shift next command option and do the loop again until all options are processed
shift
if "%1" == "" goto optionsend
goto optionsloop
:optionsend

:: CP IDs to be used
echo.
si viewcps
echo.
echo Enter the Change Package ID to be used [%changePID%]: 
set /p changePID=

if "%changePID%" == "" (
    echo.
    echo Error: Please select the CP ID to be used
    exit /b
  )


cd %CURRENT_WD%
cd ..\..\..\..\..\06_Deliverables\DPU\
:: Checkout A2L, MOT, 7z and sdl files and whatever is available
si lock --changePackageId=%changePID% --lockType=exclusive %project%_PR_soc_rel.a2l
si lock --changePackageId=%changePID% --lockType=exclusive %project%_SOC_rel.mot
si lock --changePackageId=%changePID% --lockType=exclusive out_%project%.7z
si lock --changePackageId=%changePID% --lockType=exclusive %project%_SOC_rel.sdl
if exist "%project%_soc_abs.mot" (
	:: Checkout mot file with absolute addresses
	si lock --changePackageId=%changePID% --lockType=exclusive %project%_soc_abs.mot
)
if exist "checkout_latest_%project%_checkpoint.bat" (
	:: Checkout script for auto checkout
	si lock --changePackageId=%changePID% --lockType=exclusive checkout_latest_%project%_checkpoint.bat
	if exist "C:\Program Files (x86)\Notepad++\notepad++.exe" start "" /MAX "C:\Program Files (x86)\Notepad++\notepad++.exe" checkout_latest_%project%_checkpoint.bat
	if exist "C:\LegacyApp\Notepad++\notepad++.exe" start "" /MAX "C:\LegacyApp\Notepad++\notepad++.exe" checkout_latest_%project%_checkpoint.bat
)
if exist "%project%_MemoryMapAnalyser.xlsm" (
	:: Checkout MemoryMap Analyser file
	si lock --changePackageId=%changePID% --lockType=exclusive %project%_MemoryMapAnalyser.xlsm
	start "" /MAX "%project%_MemoryMapAnalyser.xlsm"
)


rem cd %CURRENT_WD%\..\..\..\..\07_Documentation\
rem if exist "doc_%project%.7z" (
rem     si lock --changePackageId=%changePID% --lockType=exclusive doc_%project%.7z
rem )


:: Checkout cfg_buildinfo and gen_buildinfo header file
cd %CURRENT_WD%
cd ..\..\..\00_Projects\%project%
si lock --changePackageId=%changePID% --lockType=exclusive cfg_buildinfo.h
si lock --changePackageId=%changePID% --lockType=exclusive gen_buildinfo.h
if exist "C:\Program Files (x86)\Notepad++\notepad++.exe" start "" /MAX "C:\Program Files (x86)\Notepad++\notepad++.exe" cfg_buildinfo.h
if exist "C:\LegacyApp\Notepad++\notepad++.exe" start "" /MAX "C:\LegacyApp\Notepad++\notepad++.exe" cfg_buildinfo.h

cd %INITIAL_WD%

ENDLOCAL & SET changePID=%changePID%