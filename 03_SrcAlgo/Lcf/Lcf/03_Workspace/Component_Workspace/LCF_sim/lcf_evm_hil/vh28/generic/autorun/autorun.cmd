@echo off
REM test
setlocal

set timecode=%date%_%time%
set timecode=%timecode: =%
set timecode=%timecode::=%
set timecode=%timecode:/=%
set timecode=%timecode:.=%
set timecode=%timecode:,=%

set currentPath=%~dp0

set simPath=%~dp0\..\..\..\..\
cd %simPath%
dir *_evm_hil. /B > modname.txt
set /P mn= < modname.txt
del modname.txt /F
set mn=%mn:_evm_hil=%
echo %mn%
cd %currentPath%

set logfolder=..\..\..\..\..\..\..\04_Build\algo\%mn%\logs\
set logfilename=%logfolder%autorun_%timecode%.log
if not exist %logfolder% mkdir %logfolder%
call ..\..\..\..\..\..\..\02_Development_Tools\movpy\movpy.exe autorun.py | ..\..\..\..\..\..\..\02_Development_Tools\scons_tools\gnutools\tee.exe %logfilename%

endlocal

echo on
