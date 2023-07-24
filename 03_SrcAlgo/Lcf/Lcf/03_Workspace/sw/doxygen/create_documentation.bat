@echo off

rem  Example command for for using create document:
rem  -> create_documentation.bat p hfl130 ia

:: Make sure changes to environment variables are only local do not affect the calling command line
setlocal EnableDelayedExpansion
set project=

REM get script path
set scriptPath=%~dp0

REM get current directory
set currDir= %cd%

REM switch to script path
cd %scriptPath%


:: Read input option
:optionsloop
if "%1" == "" (
  echo.
  echo Error: Please specify the product ID with a parameter to the "p" argument
  echo        ie. lockFilesForCP.bat p mfs430bw16 SoC
  exit /b
)

if "%1" == "p" (
  if "%2%"=="" (
    echo.
    echo Error: Please specify the product ID with a parameter to the "p" argument
    echo        ie. lockFilesForCP.bat p mfs430bw16 SoC
    exit /b
  ) else (
    set PROJECT=%2
  )
)

if defined PROJECT (
if "%3%"=="" (
  echo.
  echo Error: Please specify the component ie. FF, IPC etc.
  echo 		  or SoC for complete documentation
  exit /b
) else (
  SET COMPONENT=%3
  goto generate
)
)

:: Shift next command option and do the loop again until all options are processed
shift
if "%1" == "" goto optionsend
goto optionsloop
:optionsend
 
 
:generate
 
REM Doxygen configuration
set doxy_conf=process.doxy
REM Doxygen execution path
SET DOXYGEN_EXE=C:\Tools\doxygen\1.8.11\doxygen_1.8.11\bin\doxygen.exe
REM Graphviz execution path
SET GRAPHVIZ_DOT=C:\Tools\doxygen\1.8.11\graphviz_2.38\bin\dot.exe

REM Make doc dir in 04_Build
if not exist ..\..\..\04_Build\doc\%PROJECT%\%COMPONENT% mkdir ..\..\..\04_Build\doc\%PROJECT%\%COMPONENT%
	
REM remeber start time. Note that we don't look at the date, so this
REM calculation won't work right if the program run spans local midnight.
set t0=%time: =0%

REM Generate documentation
call %DOXYGEN_EXE% %doxy_conf%

REM Capture the end time before doing anything else
set t=%time: =0%

REM make t0 into a scaler in 100ths of a second, being careful not 
REM to let SET/A misinterpret 08 and 09 as octal
set /a h=1%t0:~0,2%-100
set /a m=1%t0:~3,2%-100
set /a s=1%t0:~6,2%-100
set /a c=1%t0:~9,2%-100
set /a starttime = %h% * 360000 + %m% * 6000 + 100 * %s% + %c%

REM make t into a scaler in 100ths of a second
set /a h=1%t:~0,2%-100
set /a m=1%t:~3,2%-100
set /a s=1%t:~6,2%-100
set /a c=1%t:~9,2%-100
set /a endtime = %h% * 360000 + %m% * 6000 + 100 * %s% + %c%

REM runtime in 100ths is now just end - start
set /a runtime = %endtime% - %starttime%
set runtime = %s%.%c%
set /a runtime = %runtime% / 1000

echo Started at %t0%
echo Ran for %runtime% second(s)

:Ende

REM switch back to original path
cd %currDir%