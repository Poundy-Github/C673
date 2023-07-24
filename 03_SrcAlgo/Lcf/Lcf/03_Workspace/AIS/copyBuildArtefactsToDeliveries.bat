@echo off
:: This script copies build artefacts from 04_Build folder to the deliverables.
:: Using the script asumes that you know what you are doing. 

:: (C) 2015 - ADC Ulm GERMANY
:: Author: Magnus Baur
:: Version: 	1.0	Script generation
::              1.1 First usable version 				                29.09.2018  Magnus Baur



:: Make sure changes to environment variables are only local do not affect the calling command line
SETLOCAL ENABLEDELAYEDEXPANSION

::copyBuildArtefactsToDeliveries.bat mfc431 Base 0
set project=%1
:: Application, Base
set projectType=%2
set debug=%3
:: Store current working directory, so we can CD back in case of an error

set STARTING_WD=%CD%
cd ..\..\..\..\06_Deliverables\M11_APPL
set deliverablesDestination=%CD%
cd %STARTING_WD%
cd ..\..\..\..\05_Testing\08_Device_Test\%projectType%\%project%\Deliverables_Debug
set debugDestination=%CD%
cd %STARTING_WD%

attrib %deliverablesDestination%\*.* -r /D /S
attrib %debugDestination%\*.* -r /D /S

cd ..\..\04_Build\out\%project%
set workingDir=%CD%

if %debug%==0 goto COPYNORMAL
if %debug%==1 goto COPYDEBUG

:COPYNORMAL
echo Copy Files to deliverables location
robocopy %workingDir% %deliverablesDestination% /E
::echo %workingDir%\*.* %deliverablesDestination% /E
goto END

:COPYDEBUG
echo Copy Files to Testing location
robocopy %workingDir% %debugDestination% /E
::echo %workingDir%\*.* %debugDestination% /E
goto END

:END
cd %STARTING_WD%
