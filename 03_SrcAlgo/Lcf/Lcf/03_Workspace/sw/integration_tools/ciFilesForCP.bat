@echo off
:: This script checks in the needed files for a SoC checkpoint.
:: Files fust be in state modified.
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
set ANSWER=n

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

rem echo.
rem SET /P ANSWER=Have you already updated MemoryMap_Analyser xls sheet? [yn](n): 
rem if %ANSWER%==n (
rem    echo.
rem    echo Error: Please updated MemoryMap_Analyser xls sheet
rem    exit /b
rem  )

echo.
echo Enter the description for the check in [%descriptText%]: 
set /p descriptText=
if "%descriptText%" == "" (
    echo.
    echo Error: Please enter a description
    exit /b
  )

for /f "tokens=1,2 delims= " %%a in ("%descriptText%") do set labelText=%%a
echo.
echo Check In with description:             "%descriptText%"
echo Files will get the following label:    "%labelText%"
echo.

set ANSWER=n
echo Do you want to check in now? [yn](n): 
set /P ANSWER=
if %ANSWER%==y (

	:: CP IDs to be used
	echo.
	si viewcps
	echo.
	echo Enter the Change Package ID to be used [%changePID%]: 
	set /p changePID=

	if "!changePID!"=="" (
		echo.
		echo Error: Please select the CP ID to be used
		exit /b
	)

	echo.
	:: Check in MemoryMap Analyser file
rem	cd ..\..\..\..\..\03_Design\01_Supporting_Documents
rem	si ci --changePackageId=!changePID! --description="%descriptText%" MFC400_MemoryMap_Analyser_%project%.xlsm
rem	si updaterevision --changePackageId=!changePID! --revision=:working MFC400_MemoryMap_Analyser_%project%.xlsm
rem	si addlabel --label="%labelText%" MFC400_MemoryMap_Analyser_%project%.xlsm

	:: Check in A2L file
	cd %CURRENT_WD%
	cd ..\..\..\..\..\06_Deliverables\DPU\
	si ci --changePackageId=!changePID! --description="%descriptText%" %project%_PR_soc_rel.a2l
	si updaterevision --changePackageId=!changePID! --revision=:working %project%_PR_soc_rel.a2l
	si addlabel --label="%labelText%" %project%_PR_soc_rel.a2l
	
	:: Check in MOT files
	si ci --changePackageId=!changePID! --description="%descriptText%" %project%_soc_abs.mot
	si updaterevision --changePackageId=!changePID! --revision=:working %project%_soc_abs.mot
	si addlabel --label="%labelText%" %project%_soc_abs.mot

	si ci --changePackageId=!changePID! --description="%descriptText%" %project%_SOC_rel.mot
	si updaterevision --changePackageId=!changePID! --revision=:working %project%_SOC_rel.mot
	si addlabel --label="%labelText%" %project%_SOC_rel.mot

	:: Check in 7z file
	si ci --changePackageId=!changePID! --description="%descriptText%" out_%project%.7z
	si updaterevision --changePackageId=!changePID! --revision=:working out_%project%.7z
	si addlabel --label="%labelText%" out_%project%.7z

	:: Check in SDL file
	si ci --changePackageId=!changePID! --description="%descriptText%" %project%_SOC_rel.sdl
	si updaterevision --changePackageId=!changePID! --revision=:working %project%_SOC_rel.sdl
	si addlabel --label="%labelText%" %project%_SOC_rel.sdl

	:: Check in checkkout script
	si ci --changePackageId=!changePID! --description="%descriptText%" checkout_latest_%project%_checkpoint.bat
	si updaterevision --changePackageId=!changePID! --revision=:working checkout_latest_%project%_checkpoint.bat
	si addlabel --label="%labelText%" checkout_latest_%project%_checkpoint.bat

	:: Check in memory map analyser
	si ci --changePackageId=!changePID! --description="%descriptText%" %project%_MemoryMapAnalyser.xlsm
	si updaterevision --changePackageId=!changePID! --revision=:working %project%_MemoryMapAnalyser.xlsm
	si addlabel --label="%labelText%" %project%_MemoryMapAnalyser.xlsm
	
rem    cd %CURRENT_WD%\..\..\..\..\07_Documentation\
rem    if exist "doc_%project%.7z" (
rem        si lock --changePackageId=%changePID% --lockType=exclusive doc_%project%.7z
rem        si ci --changePackageId=!changePID! --description="%descriptText%" doc_%project%.7z
rem        si updaterevision --changePackageId=!changePID! --revision=:working doc_%project%.7z
rem        si addlabel --label="%labelText%" doc_%project%.7z
rem    )

	:: Check In cfg_buildinfo and gen_buildinfo header file
	cd %CURRENT_WD%
	cd ..\..\..\00_Projects\%project%
	si ci --changePackageId=!changePID! --description="%descriptText%" cfg_buildinfo.h
	si updaterevision --changePackageId=!changePID! --revision=:working cfg_buildinfo.h
	si addlabel --label="%labelText%" cfg_buildinfo.h

	si ci --changePackageId=!changePID! --description="%descriptText%" gen_buildinfo.h
	si updaterevision --changePackageId=!changePID! --revision=:working gen_buildinfo.h
	si addlabel --label="%labelText%" gen_buildinfo.h
  
	echo.
	echo Check In done!
	)

echo.

ENDLOCAL & SET changePID=%changePID%& SET descriptText=%descriptText%& SET labelText=%labelText%
