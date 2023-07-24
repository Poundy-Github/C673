@echo off
SETLOCAL ENABLEDELAYEDEXPANSION 

if "%1" == "quiet" (
	set _QUIET=1
)

rem Keep track of whether any tools were installed.  If they were then we will delete the entire contents of
rem the 04_Engineering\04_Build\out directory to ensure that there are no compatibility problems between
rem files compiled with the old version of the tools -vs- the new version of the tools
set _INSTALLED=0
set _version=
set version_file_path=

rem Set paths
set SRC_DIR=%2
set DST_DIR=%3

rem Replace / by \
set SRC_DIR=%SRC_DIR:/=\%
set DST_DIR=%DST_DIR:/=\%

rem Change working directory to the directory that contains this file and then back to the S00_ALL root
pushd %~dp0%\..\..\..\..

rem Check to see if Python is already installed and if so, use it
if exist c:\Tools\python\2.7.10 (
	set PYTHON=c:\Tools\python\2.7.10\python.exe
) else (
	rem Python is not installed.  Check to see if l: is mounted and if so use it to install Python.
	rem If it is not then fall back to a UNC path but display a warning to the user
	if exist "l:\" (
		set L_DRIVE=l:\
	) else (
		echo Warning: Please mount a tools drive as l: using a share that is geographically
		echo          close to your location, or copying tools can be very slow.  No l:
		echo          drive is currently mounted so defaulting to using the Ulm tools drive
		echo          at \\cw01.contiwan.com\root\loc\ulm2\didt6402\SW-DevTools.
		echo.
		pause

		set L_DRIVE=\\cw01.contiwan.com\root\loc\ulm2\didt6402\SW-DevTools\
	)

	rem Use python from the appropriate l: drive
	set PYTHON=!L_DRIVE!python\2.7\python.exe
)

rem Install all base and project specific tools into c:\Tools
%PYTHON% 04_Engineering\03_Workspace\sw\preprocess\activate_project.py

rem Change working directory back to the directory that contains this file
cd %~dp0%

rem --- Extract SYS/BIOS, XDCTools etc. if required ---

(
  if not exist %DST_DIR% (
	  mkdir %DST_DIR%
  )
  cd %DST_DIR%
)


rem edma3_lld
set version_file_path=%SRC_DIR%\ti_tools\edma3_lld\version.txt
if exist %version_file_path% ( 
	set /p _version= <%version_file_path% 
) else (
	echo %version_file_path% not found
	pause
)
if not exist edma3_lld\TI_TOOLS_EDMA3_LLD_02.11.14.19_INT-1.txt (
	echo Installing EDMA3_LLD...
	if exist edma3_lld (
		rd /q /s edma3_lld
	)
	if %_version% == edma3_lld-02.11.14.19 (
		%SRC_DIR%\utils\7za.exe x %SRC_DIR%\ti_tools\edma3_lld\edma3_lld.7z > nul
	) else (
		echo Version number missmatch!!
		pause 
	)
	if ERRORLEVEL 1 exit /b 1
	set _INSTALLED=1
) else (
	if "%_QUIET%" == "" echo EDMA3_LLD is already present - not installing
)

rem evestarterware
set version_file_path=%SRC_DIR%\ti_tools\evestarterware\version.txt
if exist %version_file_path% ( 
	set /p _version= <%version_file_path% 
) else (
	echo %version_file_path% not found
	pause
)
if not exist evestarterware\TI_TOOLS_STARTERWARE_01_07_00_00_INT-1.txt (
	echo Installing EVE Starterware...
	if exist evestarterware (
		rd /q /s evestarterware
	)
	if %_version% == evestarterware-01.07.00.00 (	
		%SRC_DIR%\utils\7za.exe x %SRC_DIR%\ti_tools\evestarterware\evestarterware.7z > nul
	) else (
		echo Version number missmatch!!
		pause 
	)
	if ERRORLEVEL 1 exit /b 1
	set _INSTALLED=1
) else (
	if "%_QUIET%" == "" echo EVE Starterware is already present - not installing
)

rem starterware
set version_file_path=%SRC_DIR%\ti_tools\starterware\version.txt
if exist %version_file_path% ( 
	set /p _version= <%version_file_path% 
) else (
	echo %version_file_path% not found
	pause
)
if not exist starterware\TI_TOOLS_STARTERWARE_01_04_00_10_INT-5.txt (
	echo Installing Starterware...
	if exist starterware (
		rd /q /s starterware
	)
	if %_version% == 01_04_00_10 (
	  %SRC_DIR%\utils\7za.exe x %SRC_DIR%\ti_tools\starterware\starterware.7z > nul
	) else (
		echo Version number missmatch!!
		pause 
	)
	if ERRORLEVEL 1 exit /b 1
	set _INSTALLED=1
) else (
	if "%_QUIET%" == "" echo Starterware is already present - not installing
)



rem If any new tools were installed then force a recompile of the entire project
if %_INSTALLED% == 1 (
	cd ..
	echo Deleting output directory to force rebuild
	if exist out rd /q /s out
)

popd

set _INSTALLED=
set _QUIET=
