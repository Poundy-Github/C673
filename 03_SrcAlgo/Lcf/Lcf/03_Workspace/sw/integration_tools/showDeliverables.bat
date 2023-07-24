@echo off
:: This script re-configures the algo sub-projects.
:: Using the script asumes that you know what you are doing. 

:: (C) 2014 - ADC Lindau GERMANY
:: Author: Frank Sautter-Steisslinger
:: Version: 1.0  Script generation


:: Make sure changes to environment variables are only local do not affect the calling command line
setlocal EnableDelayedExpansion
set ANSWER=n
set alLabel=noLabel
set numberFormat=0
set project=
set algoLabel=
set lbSource=
set cpSource=

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

if "%1" == "" (
  echo.
  echo Error: Please specify the product ID with a parameter to the "p" argument
  echo        ie. confAlgoSubProject.bat p mfs430bw16
  exit /b
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
    call :UCase project:~0 algoLabel
)

echo.
echo This script shows the configured deliversbles of project: %project%
echo.

if "%project%" == "mfs430bw16" (
  set deliverable[0]=FPGA
  set deliverable[1]=M11_BLUP
  set deliverable[2]=M11_APPL
  set deliverable[3]=GD_A2L
  set deliverable[4]=NVM_Clear
  set deliverable[5]=NVM_Default
  set deliverable[6]=PDX
  set deliverable[7]=PPAR
) else if "%project%" == "mfc4t0" (
  set deliverable[0]=M11_APPL
  set deliverable[1]=M11_BRES
  set deliverable[2]=M11_VBLUP
  set deliverable[3]=M11_VFBL
  set deliverable[4]=PPAR
) else if "%project%" == "mfl420mi16" (
  set deliverable[0]=APAR
  set deliverable[1]=M11_APPL
  set deliverable[2]=M11_BLUP_Upgrade
  set deliverable[3]=M11_BLUP
  set deliverable[4]=M11_BRES
  set deliverable[5]=M11_VFBL
  set deliverable[6]=NVM_Clear
  set deliverable[7]=PPAR
) else if "%project%" == "mfl420si16" (
  set deliverable[0]=APAR
  set deliverable[1]=M11_APPL
  set deliverable[2]=M11_BLUP_Upgrade
  set deliverable[3]=M11_BLUP
  set deliverable[4]=M11_BRES
  set deliverable[5]=M11_VFBL
  set deliverable[6]=NVM_Clear
  set deliverable[7]=PPAR
) 

cd ..\..\..\..\..\04_Engineering\05_Deliverables

for /F "tokens=2 delims==" %%s in ('set deliverable[') do (

  cd %project%
  for /f "delims=)" %%j in ('si viewproject --no %%s\project.pj') do (
    set cpSource=%%j
    set cpSource=!cpSource:*(=!
    )
    
  cd %%s
  for /f "tokens=11" %%j in ('si viewprojecthistory --rfilter=range:"!cpSource!"') do (
    if "!lbSource!"=="" set lbSource=%%j
  )
 
  set subName=%%s:  ............................
  set subName=!subName:~0,22!
  set lbSource=!lbSource!  ............................
  set lbSource=!lbSource:~0,51!
  
  echo !subName!  !lbSource!  !cpSource!
 
  set lbSource=
  set cpSource=
  cd ..\..
)

cd %CURRENT_WD%

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
SET %2=_%_Lib_UCase_Tmp:~0,10%
GOTO:EOF