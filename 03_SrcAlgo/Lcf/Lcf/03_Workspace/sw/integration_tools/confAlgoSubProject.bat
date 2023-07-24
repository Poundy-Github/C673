@echo off
:: This script re-configures the algo sub-projects.
:: Using the script asumes that you know what you are doing. 

:: (C) 2014 - ADC Lindau GERMANY
:: Author: Frank Sautter-Steisslinger
:: Version: 1.0  Script generation
::          1.1  Moved to Mainstream                        17.01.2017    Magnus Baur
::          1.2  First working version in Mainstream        17.01.2017    Magnus Baur
::          1.3  Fixed a problem with mingw console output  20.01.2017    Magnus Baur


:: Make sure changes to environment variables are only local do not affect the calling command line
setlocal EnableDelayedExpansion
set ANSWER=n
set alLabel=noLabel
set numberFormat=0
set project=
set algoLabel=

:: Store current working directory, so we can CD back in case of an error
set INITIAL_WD=%CD%

:: Change working directory to the directory where this script is stored. This allows invoking
:: this script from any directory without CD'ing into the batch file's home directory
cd %~dp0
set CURRENT_WD=%CD%

:: Read input option
:optionsloop
if "%1" == "p" (
  if "%2%"=="n" (
    echo.
    echo Error: Please specify the product ID with a parameter to the "p" argument
    echo        ie. confAlgoSubProject.bat p mfs430bw16
    exit /b
  ) else if "%2%"=="" (
    echo.
    echo Error: Please specify the product ID with a parameter to the "p" argument
    echo        ie. confAlgoSubProject.bat p mfs430bw16
    exit /b
  ) else (
    set project=%2
  )
)
if "%1"=="n" (
  set numberFormat=1
  )
if "%1" == "a" (
  if "%2%"=="n" (
    echo.
    echo Error: Please specify the Algo Label with a parameter to the "a" argument
    echo        ie. confAlgoSubProject.bat p mfs430bw16 a AL_MFS
    exit /b
  ) else if "%2%"=="p" (
    echo.
    echo Error: Please specify the Algo Label with a parameter to the "a" argument
    echo        ie. confAlgoSubProject.bat p mfs430bw16 a AL_MFS
    exit /b
  ) else if "%2%"=="" (
    echo.
    echo Error: Please specify the Algo Label with a parameter to the "a" argument
    echo        ie. confAlgoSubProject.bat p mfs430bw16 a AL_MFS
    exit /b
  ) else (
    set algoLabel=%2
  )
)
 
:: Shift next command option and do the loop again until all options are processed
shift
if "%1" == "" goto optionsend
goto optionsloop
:optionsend

:: If now project was defined asume that is G11
if "%project%" == "" set project=algo
:: If no algo label was defined try to take it from the project
if "%algoLabel%" == "" (
    call :UCase project:~5 algoLabel
)

echo.
echo This script will re-configure the algo sub-projects.
echo.

if %numberFormat% == 1 (
  :: Ask for part of the ID to exchange
  echo Use checkpoint ID to reconfigure the project
  echo Enter old part of CP ID: 
  set /p oldCPID=
  echo Enter new part of CP ID:
  set /p newCPID=
) else (
  :: Ask for algo checkpoint label to be configured
  echo Enter the algo label to be configured: 
  set /p alLabel=
)

echo.
echo Extracting current algo configuration ...
echo.

cd ..\..\..\00_Projects\%project%\Algo
for /f "delims=)" %%j in ('"si viewproject --no sources\project.pj"') do set cpSource=%%j 
set cpSource=%cpSource:*(=%
cd sources
for /f "tokens=12" %%j in ('si viewprojecthistory --rfilter=range:"%cpSource%"') do set lbSource=%%j
if %numberFormat% == 1 (
  set hiSource=!cpSource:%oldCPID%=%newCPID%!
) else (
  for /f "delims=	" %%j in ('si viewprojecthistory^|findstr %alLabel%') do (
      if not defined hiSource (
      set hiSource=%%j
    ) else (
      set hiSource=%%j
      echo --- Error: Label not definite. Cross check in MKS. ---
    )
  )
)
echo Algo Source CP:   %lbSource%   %cpSource%	will be re-configured to: %hiSource%
cd %CURRENT_WD%

cd ..\..\..\00_Projects\%project%\Algo
for /f "delims=)" %%j in ('"si viewproject --no include\project.pj"') do set cpInclude=%%j 
set cpInclude=%cpInclude:*(=%
cd include
for /f "tokens=12" %%j in ('si viewprojecthistory --rfilter=range:"%cpInclude%"') do set lbInclude=%%j
if %numberFormat% == 1 (
  set hiInclude=!cpInclude:%oldCPID%=%newCPID%!
) else (
  for /f "delims=	" %%j in ('si viewprojecthistory^|findstr %alLabel%') do (
    if not defined hiInclude (
      set hiInclude=%%j
    ) else (
      set hiInclude=%%j
      echo --- Error: Label not definite. Cross check in MKS. ---
    )
  )
)
echo Algo Include CP:  %lbInclude%   %cpInclude%	will be re-configured to: %hiInclude%
cd %CURRENT_WD%

cd ..\..\..\00_Projects\%project%\Algo
for /f "delims=)" %%j in ('"si viewproject --no ti_arp32\project.pj"') do set cpEVE=%%j 
set cpEVE=%cpEVE:*(=%
cd ti_arp32
for /f "tokens=12" %%j in ('si viewprojecthistory --rfilter=range:"%cpEVE%"') do set lbEVE=%%j
if %numberFormat% == 1 (
  set hiEVE=!cpEVE:%oldCPID%=%newCPID%!
) else (
  for /f "delims=	" %%j in ('si viewprojecthistory^|findstr %alLabel%') do (
    if not defined hiEVE (
      set hiEVE=%%j
    ) else (
      set hiEVE=%%j
      echo --- Error: Label not definite. Cross check in MKS. ---
    )
  )
)
echo Algo EVE CP:      %lbEVE%   %cpEVE%	will be re-configured to: %hiEVE%
cd %CURRENT_WD%

cd ..\..\..\00_Projects\%project%\Algo
for /f "delims=)" %%j in ('"si viewproject --no ti_c66xx\project.pj"') do set cpDSP=%%j 
set cpDSP=%cpDSP:*(=%
cd ti_c66xx
for /f "tokens=12" %%j in ('si viewprojecthistory --rfilter=range:"%cpDSP%"') do set lbDSP=%%j
if %numberFormat% == 1 (
  set hiDSP=!cpDSP:%oldCPID%=%newCPID%!
) else (
  for /f "delims=	" %%j in ('si viewprojecthistory^|findstr %alLabel%') do (
    if not defined hiDSP (
      set hiDSP=%%j
    ) else (
      set hiDSP=%%j
      echo --- Error: Label not definite. Cross check in MKS. ---
    )
  )
)
echo Algo DSP CP:      %lbDSP%   %cpDSP%	will be re-configured to: %hiDSP%
cd %CURRENT_WD%

cd ..\..\..\00_Projects\%project%\Algo
for /f "delims=)" %%j in ('"si viewproject --no ti_cortex_a15\project.pj"') do set cpCortex=%%j 
set cpCortex=%cpCortex:*(=%
cd ti_cortex_a15
for /f "tokens=12" %%j in ('si viewprojecthistory --rfilter=range:"%cpCortex%"') do set lbCortex=%%j
if %numberFormat% == 1 (
  set hiCortex=!cpCortex:%oldCPID%=%newCPID%!
) else (
  for /f "delims=	" %%j in ('si viewprojecthistory^|findstr %alLabel%') do (
    if not defined hiCortex (
      set hiCortex=%%j
    ) else (
      set hiCortex=%%j
      echo --- Error: Label not definite. Cross check in MKS. ---
    )
  )
)
echo Algo CA8 CP:      %lbCortex%   %cpCortex%	will be re-configured to: %hiCortex%
cd %CURRENT_WD%


:reconfigure
echo.
echo Do you want to reconfigure the the Algo-CP? [yn](n): 
SET /P ANSWER=
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
	cd ..\..\..\00_Projects\%project%\Algo
	si configuresubproject --changePackageId=!changePID! --type=build -r %hiSource% sources/project.pj
	cd %CURRENT_WD%
	
	cd ..\..\..\00_Projects\%project%\Algo
	si configuresubproject --changePackageId=!changePID! --type=build -r %hiInclude% include/project.pj
	cd %CURRENT_WD%
	
	cd ..\..\..\00_Projects\%project%\Algo
	si configuresubproject --changePackageId=!changePID! --type=build -r %hiEVE% ti_arp32/project.pj
	cd %CURRENT_WD%

    cd ..\..\..\00_Projects\%project%\Algo
    si configuresubproject --changePackageId=!changePID! --type=build -r %hiDSP% ti_c66xx/project.pj
    cd %CURRENT_WD%

	cd ..\..\..\00_Projects\%project%\Algo
	si configuresubproject --changePackageId=!changePID! --type=build -r %hiCortex% ti_cortex_a15/project.pj
	cd %CURRENT_WD%

	:reconfdone
	echo.
	echo Reconfigure done!
	)

echo.

ENDLOCAL & SET changePID=%changePID%
GOTO:EOF


:LCase
:UCase
:: Converts to upper/lower case variable contents
:: Syntax: CALL :UCase _VAR1 _VAR2
:: Syntax: CALL :LCase _VAR1 _VAR2
:: _VAR1 = Variable NAME whose VALUE is to be converted to upper/lower case
:: _VAR2 = NAME of variable to hold the converted value
:: Note: Use variable NAMES in the CALL, not values (pass "by reference")

SET _UCase=A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
SET _LCase=a b c d e f g h i j k l m n o p q r s t u v w x y z
SET _Lib_UCase_Tmp=!%1!
IF /I "%0"==":UCase" SET _Abet=%_UCase%
IF /I "%0"==":LCase" SET _Abet=%_LCase%
FOR %%Z IN (%_Abet%) DO SET _Lib_UCase_Tmp=!_Lib_UCase_Tmp:%%Z=%%Z!
:: Put AL_ in front of the search string and just use 6 characters
SET %2=AL_%_Lib_UCase_Tmp:~0,6%
GOTO:EOF